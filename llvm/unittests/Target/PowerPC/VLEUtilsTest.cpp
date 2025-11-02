//===-- VLEUtilsTest.cpp - Test for PPC VLE Utils (AN4648) -----*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file tests the VLE instruction length decoding algorithm from AN4648.
//
//===----------------------------------------------------------------------===//

#include "MCTargetDesc/PPCVLEUtils.h"
#include "gtest/gtest.h"

using namespace llvm;
using namespace llvm::PPC;

namespace {

// Test cases based on AN4648 examples and VLE instruction encoding
class VLEUtilsTest : public ::testing::Test {};

// Test 32-bit VLE instruction detection according to AN4648
// The algorithm: (upper_halfword & 0x9000) == 0x1000 means 32-bit VLE
TEST_F(VLEUtilsTest, TestVLE32BitDetection) {
  // Test case: 32-bit VLE instruction where bits 31=0, 28=1
  // Example: e_add16i (opcode 0x1C000000) - upper halfword = 0x1C00
  // 0x1C00 & 0x9000 = 0x1000, so it's 32-bit VLE
  uint32_t E_ADD16I = 0x1C000000U;
  EXPECT_TRUE(isVLE32BitInstruction(E_ADD16I));

  // Test case: 32-bit VLE instruction e_li (opcode 0x70000000)
  // Upper halfword = 0x7000, 0x7000 & 0x9000 = 0x1000, so it's 32-bit VLE
  uint32_t E_LI = 0x70000000U;
  EXPECT_TRUE(isVLE32BitInstruction(E_LI));

  // Test case: 32-bit VLE instruction e_lwz (opcode 0x50000000)
  // Upper halfword = 0x5000, 0x5000 & 0x9000 = 0x1000, so it's 32-bit VLE
  uint32_t E_LWZ = 0x50000000U;
  EXPECT_TRUE(isVLE32BitInstruction(E_LWZ));

  // Test case: 16-bit VLE instruction se_addi (opcode 0x2000----)
  // Upper halfword = 0x2000, 0x2000 & 0x9000 = 0x0000 != 0x1000, so it's 16-bit
  uint32_t SE_ADDI = 0x20001234U; // Lower bits don't matter for this check
  EXPECT_FALSE(isVLE32BitInstruction(SE_ADDI));

  // Test case: 16-bit VLE instruction se_lwz (opcode 0xC000----)
  // Upper halfword = 0xC000, 0xC000 & 0x9000 = 0x8000 != 0x1000, so it's 16-bit
  uint32_t SE_LWZ = 0xC0001234U;
  EXPECT_FALSE(isVLE32BitInstruction(SE_LWZ));

  // Test case: BookE instruction (standard 32-bit, not VLE)
  // Example: addi (opcode 0x38000000 in standard PPC)
  // Upper halfword = 0x3800, 0x3800 & 0x9000 = 0x0000 != 0x1000, so not VLE32
  uint32_t ADDI = 0x38000000U;
  EXPECT_FALSE(isVLE32BitInstruction(ADDI));
}

// Test instruction encoding type determination
TEST_F(VLEUtilsTest, TestInstructionEncoding) {
  // 32-bit VLE instruction in VLE context
  uint32_t E_LI = 0x70000000U;
  EXPECT_EQ(getInstructionEncoding(E_LI, true), InstructionEncoding::VLE32);

  // 16-bit VLE instruction in VLE context
  uint32_t SE_ADDI = 0x20001234U;
  EXPECT_EQ(getInstructionEncoding(SE_ADDI, true), InstructionEncoding::VLE16);

  // Any instruction in BookE context is BookE
  EXPECT_EQ(getInstructionEncoding(E_LI, false), InstructionEncoding::BookE);
  EXPECT_EQ(getInstructionEncoding(SE_ADDI, false), InstructionEncoding::BookE);
}

// Test instruction length calculation
TEST_F(VLEUtilsTest, TestInstructionLength) {
  EXPECT_EQ(getInstructionLengthInBytes(InstructionEncoding::VLE16), 2U);
  EXPECT_EQ(getInstructionLengthInBytes(InstructionEncoding::VLE32), 4U);
  EXPECT_EQ(getInstructionLengthInBytes(InstructionEncoding::BookE), 4U);
}

// Test exception return address adjustment (AN4648 main use case)
TEST_F(VLEUtilsTest, TestExceptionReturnAddressAdjustment) {
  uint64_t ReturnAddress = 0x1000U;

  // 16-bit VLE instruction should add 2 bytes
  uint32_t SE_ADDI = 0x20001234U;
  uint64_t Adjusted16 = adjustExceptionReturnAddress(ReturnAddress, SE_ADDI, true);
  EXPECT_EQ(Adjusted16, 0x1002U);

  // 32-bit VLE instruction should add 4 bytes
  uint32_t E_LI = 0x70000000U;
  uint64_t Adjusted32 = adjustExceptionReturnAddress(ReturnAddress, E_LI, true);
  EXPECT_EQ(Adjusted32, 0x1004U);

  // BookE instruction should add 4 bytes
  uint32_t ADDI = 0x38000000U;
  uint64_t AdjustedBookE = adjustExceptionReturnAddress(ReturnAddress, ADDI, false);
  EXPECT_EQ(AdjustedBookE, 0x1004U);
}

// Test edge cases from AN4648
TEST_F(VLEUtilsTest, TestEdgeCases) {
  // Test instruction where bit 31=1, bit 28=0
  // This should not match the 32-bit VLE pattern (needs bit 31=0, bit 28=1)
  uint32_t Bit31Set = 0x80000000U;
  EXPECT_FALSE(isVLE32BitInstruction(Bit31Set));

  // Test instruction where bit 31=0, bit 28=0
  uint32_t BothZero = 0x00000000U;
  EXPECT_FALSE(isVLE32BitInstruction(BothZero));

  // Test instruction where bit 31=1, bit 28=1
  uint32_t BothOne = 0x90000000U;
  EXPECT_FALSE(isVLE32BitInstruction(BothOne)); // Need exactly 0x1000 pattern
}

// Test VLE exception syndrome utilities (VLEPEM Section 2.1.2.2)
TEST_F(VLEUtilsTest, TestExceptionSyndromeBits) {
  using namespace VLEExceptionSyndrome;

  // Test syndrome bits indicating 16-bit instruction
  // Assume bit 0 indicates length: 0 = 16-bit, 1 = 32-bit
  uint32_t Syndrome16Bit = 0x0U;  // Length bit = 0
  uint32_t LengthMask = 0x1U;      // Bit 0 indicates length

  EXPECT_FALSE(isInstruction32BitFromSyndrome(Syndrome16Bit, LengthMask));
  EXPECT_EQ(getInstructionLengthFromSyndrome(Syndrome16Bit, LengthMask), 2U);

  // Test syndrome bits indicating 32-bit instruction
  uint32_t Syndrome32Bit = 0x1U;  // Length bit = 1
  EXPECT_TRUE(isInstruction32BitFromSyndrome(Syndrome32Bit, LengthMask));
  EXPECT_EQ(getInstructionLengthFromSyndrome(Syndrome32Bit, LengthMask), 4U);

  // Test misaligned exception detection
  // 16-bit instruction at odd address (should be 2-byte aligned)
  uint64_t Misaligned16Addr = 0x1001U;  // Not 2-byte aligned
  EXPECT_TRUE(isMisalignedException(Misaligned16Addr, Syndrome16Bit, LengthMask));

  // 16-bit instruction at aligned address
  uint64_t Aligned16Addr = 0x1000U;  // 2-byte aligned
  EXPECT_FALSE(isMisalignedException(Aligned16Addr, Syndrome16Bit, LengthMask));

  // 32-bit instruction at 2-byte but not 4-byte aligned address
  uint64_t Misaligned32Addr = 0x1002U;  // 2-byte aligned but not 4-byte aligned
  EXPECT_TRUE(isMisalignedException(Misaligned32Addr, Syndrome32Bit, LengthMask));

  // 32-bit instruction at 4-byte aligned address
  uint64_t Aligned32Addr = 0x1000U;  // 4-byte aligned
  EXPECT_FALSE(isMisalignedException(Aligned32Addr, Syndrome32Bit, LengthMask));

  // Test return address adjustment using syndrome bits
  uint64_t ReturnAddr = 0x2000U;
  uint64_t Adjusted16 = adjustExceptionReturnAddressFromSyndrome(
      ReturnAddr, Syndrome16Bit, LengthMask);
  EXPECT_EQ(Adjusted16, 0x2002U);

  uint64_t Adjusted32 = adjustExceptionReturnAddressFromSyndrome(
      ReturnAddr, Syndrome32Bit, LengthMask);
  EXPECT_EQ(Adjusted32, 0x2004U);
}

} // end anonymous namespace

