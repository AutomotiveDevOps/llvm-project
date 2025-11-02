//===-- PPCVLEUtils.h - PowerPC VLE Instruction Utilities -------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file provides utility functions for decoding Variable Length Encoding
// (VLE) instruction lengths, as described in NXP Application Note AN4648:
// "VLE 16-bit and 32-bit Instruction Length Decode Algorithm"
//
// Reference: https://www.nxp.com/docs/en/application-note/AN4648.pdf
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_POWERPC_MCTARGETDESC_PPCVLEUTILS_H
#define LLVM_LIB_TARGET_POWERPC_MCTARGETDESC_PPCVLEUTILS_H

#include <cstdint>

namespace llvm {
namespace PPC {

/// Enumeration for instruction encoding types
enum class InstructionEncoding {
  BookE,   /// Standard Book E 32-bit instruction
  VLE16,   /// VLE 16-bit instruction
  VLE32    /// VLE 32-bit instruction
};

/// Determines if a VLE instruction is 16-bit or 32-bit based on AN4648 algorithm.
///
/// According to AN4648, the instruction length is determined by examining
/// bits 31 and 28 of the instruction word. The algorithm checks the upper
/// 16 bits (bits 31-16) of the instruction:
/// - If (upper_halfword & 0x9000) == 0x1000, the instruction is 32-bit
/// - Otherwise, the instruction is 16-bit
///
/// Note: This function assumes the instruction is already known to be VLE.
/// For mixed VLE/Book E systems, additional checks may be needed.
///
/// The mask 0x9000 checks:
/// - Bit 31 (mask bit 0x8000) - most significant bit of the 32-bit instruction
/// - Bit 28 (mask bit 0x1000) - bit 28 of the 32-bit instruction
///
/// \param Instruction32 The 32-bit instruction word (must be in correct
///                      byte order for the target, typically big-endian)
/// \returns true if the instruction is 32-bit, false if 16-bit
inline bool isVLE32BitInstruction(uint32_t Instruction32) {
  // According to AN4648, we check the upper 16 bits (bits 31-16) of the
  // instruction word. The assembly example does:
  //   se_lhz r4,0(r5)  # load halfword at exception address
  //   e_andi. r3,r4,0x9000  # mask bits 31 and 28
  //   e_cmpli 0x0,r3,0x1000  # compare with 0x1000
  //
  // This is equivalent to checking (Instruction32 & 0x90000000) == 0x10000000
  // when the instruction is in standard PowerPC byte order (big-endian).
  //
  // The condition means: bit 31 = 0, bit 28 = 1, which indicates 32-bit VLE
  
  // Extract upper 16 bits and apply the mask from AN4648
  uint16_t UpperHalfword = (Instruction32 >> 16) & 0xFFFF;
  return (UpperHalfword & 0x9000) == 0x1000;
}

/// Determines the encoding type and length of a PowerPC instruction.
///
/// This function implements the algorithm from AN4648 to determine whether
/// an instruction is Book E (32-bit), VLE 16-bit, or VLE 32-bit.
///
/// Note: Determining VLE vs Book E context typically requires MMU page settings
/// (MAS2[VLE] bit) or other system state information as described in AN4648.
///
/// \param Instruction32 The 32-bit instruction word (must be in correct
///                      byte order for the target)
/// \param IsVLEContext True if the instruction is known to be in a VLE context
///                     (from MMU settings, global state, etc.)
/// \returns The instruction encoding type
inline InstructionEncoding getInstructionEncoding(uint32_t Instruction32,
                                                   bool IsVLEContext) {
  if (!IsVLEContext) {
    // In a Book E context, instructions are always 32-bit
    return InstructionEncoding::BookE;
  }
  
  // In VLE context, determine if 16-bit or 32-bit using AN4648 algorithm
  // Check bits 31 and 28: (instruction & 0x90000000) == 0x10000000
  if (isVLE32BitInstruction(Instruction32)) {
    return InstructionEncoding::VLE32;
  }
  
  // If the condition is false, it's a 16-bit VLE instruction
  return InstructionEncoding::VLE16;
}

/// Gets the instruction length in bytes based on encoding type.
///
/// \param Encoding The instruction encoding type
/// \returns Instruction length in bytes (2 for VLE16, 4 for VLE32/BookE)
inline unsigned getInstructionLengthInBytes(InstructionEncoding Encoding) {
  switch (Encoding) {
  case InstructionEncoding::VLE16:
    return 2;
  case InstructionEncoding::VLE32:
  case InstructionEncoding::BookE:
    return 4;
  }
  llvm_unreachable("Unknown instruction encoding");
}

/// Calculates the adjusted return address for exception handlers.
///
/// According to AN4648, some IVORx exceptions (like IVOR1 machine check)
/// require manual adjustment of the return address in SRR0/MCSRR0 based on
/// the instruction length that caused the exception.
///
/// \param ReturnAddress The address stored in SRR0/MCSRR0 by the hardware
/// \param Instruction32 The instruction word at the exception address
/// \param IsVLEContext True if instruction is in VLE context
/// \returns The adjusted return address (ReturnAddress + instruction_length)
inline uint64_t adjustExceptionReturnAddress(uint64_t ReturnAddress,
                                              uint32_t Instruction32,
                                              bool IsVLEContext) {
  InstructionEncoding Encoding = getInstructionEncoding(Instruction32, IsVLEContext);
  unsigned Length = getInstructionLengthInBytes(Encoding);
  return ReturnAddress + Length;
}

} // end namespace PPC
} // end namespace llvm

#endif // LLVM_LIB_TARGET_POWERPC_MCTARGETDESC_PPCVLEUTILS_H

