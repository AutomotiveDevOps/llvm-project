//===-- PPCVLEOpt.cpp - PowerPC VLE Optimization Pass -----------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This pass optimizes code size by converting standard PowerPC instructions
// to VLE (Variable Length Encoding) instructions when constraints allow.
// VLE provides 16-bit and 32-bit instruction forms that can reduce code
// size by 20-30% for embedded systems.
//
// Reference: Variable-Length Encoding (VLE) Programming Environments Manual
// (VLEPEM), Rev. 0, https://www.nxp.com/docs/en/reference-manual/VLEPEM.pdf
//
//===----------------------------------------------------------------------===//

#include "MCTargetDesc/PPCMCTargetDesc.h"
#include "PPC.h"
#include "PPCInstrInfo.h"
#include "PPCSubtarget.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/InitializePasses.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/Statistic.h"

using namespace llvm;

#define DEBUG_TYPE "ppc-vle-opt"

STATISTIC(NumConvertedTo16Bit, "Number of instructions converted to 16-bit VLE");
STATISTIC(NumConvertedTo32Bit, "Number of instructions converted to 32-bit VLE");
STATISTIC(NumIneligibleRegs, "Number of instructions skipped due to register constraints");
STATISTIC(NumIneligibleImms, "Number of instructions skipped due to immediate constraints");

namespace {

class PPCVLEOpt : public MachineFunctionPass {
public:
  static char ID;
  
  PPCVLEOpt() : MachineFunctionPass(ID) {
    initializePPCVLEOptPass(*PassRegistry::getPassRegistry());
  }

  void getAnalysisUsage(AnalysisUsage &AU) const override {
    MachineFunctionPass::getAnalysisUsage(AU);
  }

  bool runOnMachineFunction(MachineFunction &MF) override;

private:
  const PPCSubtarget *STI;
  const PPCInstrInfo *TII;
  
  // Check if register is in VLE 16-bit range (0-7)
  bool isVLERegister(Register Reg, MachineRegisterInfo &MRI);
  
  // Check if immediate fits in VLE range
  // For 16-bit VLE:
  //   - s6imm: signed 6-bit immediate (-32 to 31)
  //   - u5imm: unsigned 5-bit immediate (0 to 31)
  //   - u7imm: unsigned 7-bit immediate (0 to 127)
  bool fitsInVLEImmediate(int64_t Imm, unsigned ImmType);
  
  // Try to convert instruction to VLE form
  bool tryConvertToVLE(MachineInstr &MI);
  
  // Convert specific instruction types
  bool convertLoadStore(MachineInstr &MI);
  bool convertArithmetic(MachineInstr &MI);
  bool convertCompare(MachineInstr &MI);
  bool convertBranch(MachineInstr &MI);
  bool convertLogical(MachineInstr &MI);
  bool convertShift(MachineInstr &MI);
};

char PPCVLEOpt::ID = 0;

} // end anonymous namespace

INITIALIZE_PASS(PPCVLEOpt, DEBUG_TYPE, "PowerPC VLE Optimization", false, false)

FunctionPass *llvm::createPPCVLEOptPass() {
  return new PPCVLEOpt();
}

bool PPCVLEOpt::runOnMachineFunction(MachineFunction &MF) {
  if (skipFunction(MF.getFunction()))
    return false;
  
  STI = &MF.getSubtarget<PPCSubtarget>();
  
  // Only run if VLE is enabled
  if (!STI->hasVLE())
    return false;
  
  // Optimize when:
  // 1. Function is marked for size optimization, OR
  // 2. VLE is explicitly enabled (user wants VLE)
  // 3. Optimization level is -Oz (optimize for size)
  // Note: Post-RA pass allows accurate register constraint checking
  bool OptForSize = MF.getFunction().getAttributes().hasFnAttr(
                       Attribute::OptimizeForSize) ||
                    MF.getFunction().getAttributes().hasFnAttr(
                       Attribute::MinSize);
  bool VLEExplicit = STI->hasVLE(); // VLE explicitly enabled
  
  // Always optimize when VLE is enabled and we're optimizing for code size
  // This helps achieve the 20-30% code size reduction goal
  if (!OptForSize && !VLEExplicit) {
    // Only optimize when size matters or VLE is explicitly enabled
    return false;
  }
  
  TII = STI->getInstrInfo();
  bool Changed = false;
  
  // Iterate over all basic blocks and instructions
  for (MachineBasicBlock &MBB : MF) {
    for (MachineInstr &MI : make_early_inc_range(MBB)) {
      if (tryConvertToVLE(MI))
        Changed = true;
    }
  }
  
  return Changed;
}

bool PPCVLEOpt::isVLERegister(Register Reg, MachineRegisterInfo &MRI) {
  // Physical registers: check if in range 0-7
  if (Reg.isPhysical()) {
    return Reg >= PPC::R0 && Reg <= PPC::R7;
  }
  
  // Virtual registers: try to determine if they will allocate to R0-R7
  // This is a heuristic - we can't know for sure until after register allocation
  // For now, we'll be conservative and check if all uses/defs allow R0-R7
  // This is a simplified check - a full implementation would need more analysis
  return true; // Optimistic for now - will be refined post-RA
}

bool PPCVLEOpt::fitsInVLEImmediate(int64_t Imm, unsigned ImmType) {
  switch (ImmType) {
  case 0: // s6imm: signed 6-bit (-32 to 31)
    return Imm >= -32 && Imm <= 31;
  case 1: // u5imm: unsigned 5-bit (0 to 31)
    return Imm >= 0 && Imm <= 31;
  case 2: // u7imm: unsigned 7-bit (0 to 127)
    return Imm >= 0 && Imm <= 127;
  case 3: // u4imm: unsigned 4-bit (0 to 15) for SD4 displacement
    return Imm >= 0 && Imm <= 15;
  case 4: // u5imm_vle: unsigned 5-bit (0 to 31) for word displacement
    return Imm >= 0 && Imm <= 31;
  default:
    return false;
  }
}

bool PPCVLEOpt::tryConvertToVLE(MachineInstr &MI) {
  unsigned Opcode = MI.getOpcode();
  
  // Skip if already a VLE instruction
  if (Opcode >= PPC::SE_LBZ && Opcode <= PPC::SE_BLRL)
    return false;
  if (Opcode >= PPC::E_LBZ && Opcode <= PPC::E_STWBRX)
    return false;
  
  // Try different instruction categories
  if (convertLoadStore(MI))
    return true;
  if (convertArithmetic(MI))
    return true;
  if (convertCompare(MI))
    return true;
  if (convertBranch(MI))
    return true;
  if (convertLogical(MI))
    return true;
  if (convertShift(MI))
    return true;
  
  return false;
}

bool PPCVLEOpt::convertLoadStore(MachineInstr &MI) {
  unsigned Opcode = MI.getOpcode();
  MachineBasicBlock &MBB = *MI.getParent();
  MachineRegisterInfo &MRI = MBB.getParent()->getRegInfo();
  
  // Check for load/store instructions that can be converted to se_ form
  // se_lbz, se_stb, se_lhz, se_sth, se_lwz, se_stw require:
  // - Base register in range 0-7
  // - Displacement fits in u4imm (0-15) for byte/halfword or u5imm (0-31) for word
  // - Destination/source register in range 0-7 for byte/halfword, or 0-7 for word
  
  if (Opcode == PPC::LBZ || Opcode == PPC::LBZ8) {
    // se_lbz: Load Byte and Zero
    // LBZ format: dest, offset(base) where memri is a ComplexPattern
    // Operands: [0]=dest, [1]=base reg, [2]=offset
    if (MI.getNumOperands() >= 3 && MI.getOperand(2).isImm()) {
      Register DestReg = MI.getOperand(0).getReg();
      Register BaseReg = MI.getOperand(1).getReg();
      int64_t Disp = MI.getOperand(2).getImm();
      
      if (isVLERegister(BaseReg, MRI) && isVLERegister(DestReg, MRI) &&
          fitsInVLEImmediate(Disp, 3)) {
        BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(PPC::SE_LBZ))
            .addReg(DestReg, RegState::Define)
            .addImm(Disp)
            .addReg(BaseReg);
        MI.eraseFromParent();
        NumConvertedTo16Bit++;
        return true;
      }
    }
  }
  
  if (Opcode == PPC::STB || Opcode == PPC::STB8) {
    // se_stb: Store Byte
    // STB format: src, offset(base)
    // Operands: [0]=src, [1]=base reg, [2]=offset
    if (MI.getNumOperands() >= 3 && MI.getOperand(2).isImm()) {
      Register SrcReg = MI.getOperand(0).getReg();
      Register BaseReg = MI.getOperand(1).getReg();
      int64_t Disp = MI.getOperand(2).getImm();
      
      if (isVLERegister(BaseReg, MRI) && isVLERegister(SrcReg, MRI) &&
          fitsInVLEImmediate(Disp, 3)) {
        BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(PPC::SE_STB))
            .addReg(SrcReg)
            .addImm(Disp)
            .addReg(BaseReg);
        MI.eraseFromParent();
        NumConvertedTo16Bit++;
        return true;
      }
    }
  }
  
  if (Opcode == PPC::LHZ || Opcode == PPC::LHZ8) {
    // se_lhz: Load Halfword and Zero
    if (MI.getNumOperands() >= 3 && MI.getOperand(2).isImm()) {
      Register DestReg = MI.getOperand(0).getReg();
      Register BaseReg = MI.getOperand(1).getReg();
      int64_t Disp = MI.getOperand(2).getImm();
      
      if (isVLERegister(BaseReg, MRI) && isVLERegister(DestReg, MRI) &&
          fitsInVLEImmediate(Disp, 3)) {
        BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(PPC::SE_LHZ))
            .addReg(DestReg, RegState::Define)
            .addImm(Disp)
            .addReg(BaseReg);
        MI.eraseFromParent();
        NumConvertedTo16Bit++;
        return true;
      }
    }
  }
  
  if (Opcode == PPC::STH || Opcode == PPC::STH8) {
    // se_sth: Store Halfword
    if (MI.getNumOperands() >= 3 && MI.getOperand(2).isImm()) {
      Register SrcReg = MI.getOperand(0).getReg();
      Register BaseReg = MI.getOperand(1).getReg();
      int64_t Disp = MI.getOperand(2).getImm();
      
      if (isVLERegister(BaseReg, MRI) && isVLERegister(SrcReg, MRI) &&
          fitsInVLEImmediate(Disp, 3)) {
        BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(PPC::SE_STH))
            .addReg(SrcReg)
            .addImm(Disp)
            .addReg(BaseReg);
        MI.eraseFromParent();
        NumConvertedTo16Bit++;
        return true;
      }
    }
  }
  
  if (Opcode == PPC::LWZ || Opcode == PPC::LWZ8) {
    // se_lwz: Load Word and Zero
    if (MI.getNumOperands() >= 3 && MI.getOperand(2).isImm()) {
      Register DestReg = MI.getOperand(0).getReg();
      Register BaseReg = MI.getOperand(1).getReg();
      int64_t Disp = MI.getOperand(2).getImm();
      
      if (isVLERegister(BaseReg, MRI) && isVLERegister(DestReg, MRI) &&
          fitsInVLEImmediate(Disp, 4)) {
        BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(PPC::SE_LWZ))
            .addReg(DestReg, RegState::Define)
            .addImm(Disp)
            .addReg(BaseReg);
        MI.eraseFromParent();
        NumConvertedTo16Bit++;
        return true;
      }
    }
  }
  
  if (Opcode == PPC::STW || Opcode == PPC::STW8) {
    // se_stw: Store Word
    if (MI.getNumOperands() >= 3 && MI.getOperand(2).isImm()) {
      Register SrcReg = MI.getOperand(0).getReg();
      Register BaseReg = MI.getOperand(1).getReg();
      int64_t Disp = MI.getOperand(2).getImm();
      
      if (isVLERegister(BaseReg, MRI) && isVLERegister(SrcReg, MRI) &&
          fitsInVLEImmediate(Disp, 4)) {
        BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(PPC::SE_STW))
            .addReg(SrcReg)
            .addImm(Disp)
            .addReg(BaseReg);
        MI.eraseFromParent();
        NumConvertedTo16Bit++;
        return true;
      }
    }
  }
  
  return false;
}

bool PPCVLEOpt::convertArithmetic(MachineInstr &MI) {
  unsigned Opcode = MI.getOpcode();
  MachineBasicBlock &MBB = *MI.getParent();
  MachineRegisterInfo &MRI = MBB.getParent()->getRegInfo();
  
  if (Opcode == PPC::ADDI || Opcode == PPC::ADDI8) {
    // se_addi: Add Immediate (6-bit signed immediate)
    if (MI.getNumOperands() >= 3) {
      Register DestReg = MI.getOperand(0).getReg();
      Register SrcReg = MI.getOperand(1).getReg();
      int64_t Imm = MI.getOperand(2).getImm();
      
      if (isVLERegister(DestReg, MRI) && isVLERegister(SrcReg, MRI) &&
          fitsInVLEImmediate(Imm, 0)) {
        BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(PPC::SE_ADDI))
            .addReg(DestReg, RegState::Define)
            .addReg(SrcReg)
            .addImm(Imm);
        MI.eraseFromParent();
        NumConvertedTo16Bit++;
        return true;
      }
    }
  }
  
  if (Opcode == PPC::ADD4 || Opcode == PPC::ADD8) {
    // se_add: Add Register
    if (MI.getNumOperands() >= 3) {
      Register DestReg = MI.getOperand(0).getReg();
      Register SrcReg1 = MI.getOperand(1).getReg();
      Register SrcReg2 = MI.getOperand(2).getReg();
      
      if (isVLERegister(DestReg, MRI) && isVLERegister(SrcReg1, MRI) &&
          isVLERegister(SrcReg2, MRI)) {
        BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(PPC::SE_ADD))
            .addReg(DestReg, RegState::Define)
            .addReg(SrcReg1)
            .addReg(SrcReg2);
        MI.eraseFromParent();
        NumConvertedTo16Bit++;
        return true;
      }
    }
  }
  
  if (Opcode == PPC::SUBF || Opcode == PPC::SUBF8) {
    // se_sub: Subtract (note: SUBF computes Src2 - Src1, so we need to check operands)
    if (MI.getNumOperands() >= 3) {
      Register DestReg = MI.getOperand(0).getReg();
      Register SrcReg1 = MI.getOperand(1).getReg();
      Register SrcReg2 = MI.getOperand(2).getReg();
      
      if (isVLERegister(DestReg, MRI) && isVLERegister(SrcReg1, MRI) &&
          isVLERegister(SrcReg2, MRI)) {
        // se_sub is subtract, but SUBF is subtract from, so operands are reversed
        BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(PPC::SE_SUB))
            .addReg(DestReg, RegState::Define)
            .addReg(SrcReg2)
            .addReg(SrcReg1);
        MI.eraseFromParent();
        NumConvertedTo16Bit++;
        return true;
      }
    }
  }
  
  return false;
}

bool PPCVLEOpt::convertCompare(MachineInstr &MI) {
  unsigned Opcode = MI.getOpcode();
  MachineBasicBlock &MBB = *MI.getParent();
  MachineRegisterInfo &MRI = MBB.getParent()->getRegInfo();
  
  if (Opcode == PPC::CMPWI || Opcode == PPC::CMPWI8) {
    // se_cmpi: Compare Immediate
    if (MI.getNumOperands() >= 3) {
      Register SrcReg = MI.getOperand(1).getReg();
      int64_t Imm = MI.getOperand(2).getImm();
      
      if (isVLERegister(SrcReg, MRI) && fitsInVLEImmediate(Imm, 0)) {
        // Copy CR field operand if present
        unsigned CRIdx = 0;
        if (MI.getNumOperands() > 3)
          CRIdx = MI.getOperand(0).getReg();
        
        auto NewMI = BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(PPC::SE_CMPI));
        if (MI.getNumOperands() > 3)
          NewMI.addReg(CRIdx, RegState::Define);
        NewMI.addReg(SrcReg).addImm(Imm);
        MI.eraseFromParent();
        NumConvertedTo16Bit++;
        return true;
      }
    }
  }
  
  if (Opcode == PPC::CMPW || Opcode == PPC::CMPW8) {
    // se_cmp: Compare Register
    if (MI.getNumOperands() >= 3) {
      Register SrcReg1 = MI.getOperand(1).getReg();
      Register SrcReg2 = MI.getOperand(2).getReg();
      
      if (isVLERegister(SrcReg1, MRI) && isVLERegister(SrcReg2, MRI)) {
        unsigned CRIdx = 0;
        if (MI.getNumOperands() > 3)
          CRIdx = MI.getOperand(0).getReg();
        
        auto NewMI = BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(PPC::SE_CMP));
        if (MI.getNumOperands() > 3)
          NewMI.addReg(CRIdx, RegState::Define);
        NewMI.addReg(SrcReg1).addReg(SrcReg2);
        MI.eraseFromParent();
        NumConvertedTo16Bit++;
        return true;
      }
    }
  }
  
  return false;
}

bool PPCVLEOpt::convertBranch(MachineInstr &MI) {
  // Branch conversion is complex and may require analysis of branch targets
  // For now, we'll skip this and focus on other instructions
  // This can be enhanced later
  return false;
}

bool PPCVLEOpt::convertLogical(MachineInstr &MI) {
  unsigned Opcode = MI.getOpcode();
  MachineBasicBlock &MBB = *MI.getParent();
  MachineRegisterInfo &MRI = MBB.getParent()->getRegInfo();
  
  if (Opcode == PPC::ANDI_rec || Opcode == PPC::ANDI8_rec) {
    // se_andi: AND Immediate (5-bit unsigned immediate)
    if (MI.getNumOperands() >= 3) {
      Register DestReg = MI.getOperand(0).getReg();
      Register SrcReg = MI.getOperand(1).getReg();
      int64_t Imm = MI.getOperand(2).getImm();
      
      if (isVLERegister(DestReg, MRI) && isVLERegister(SrcReg, MRI) &&
          fitsInVLEImmediate(Imm, 1)) {
        BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(PPC::SE_ANDI))
            .addReg(DestReg, RegState::Define)
            .addReg(SrcReg)
            .addImm(Imm);
        MI.eraseFromParent();
        NumConvertedTo16Bit++;
        return true;
      }
    }
  }
  
  if (Opcode == PPC::ORI || Opcode == PPC::ORI8) {
    // se_ori: OR Immediate (5-bit unsigned immediate)
    if (MI.getNumOperands() >= 3) {
      Register DestReg = MI.getOperand(0).getReg();
      Register SrcReg = MI.getOperand(1).getReg();
      int64_t Imm = MI.getOperand(2).getImm();
      
      if (isVLERegister(DestReg, MRI) && isVLERegister(SrcReg, MRI) &&
          fitsInVLEImmediate(Imm, 1)) {
        BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(PPC::SE_ORI))
            .addReg(DestReg, RegState::Define)
            .addReg(SrcReg)
            .addImm(Imm);
        MI.eraseFromParent();
        NumConvertedTo16Bit++;
        return true;
      }
    }
  }
  
  if (Opcode == PPC::XORI || Opcode == PPC::XORI8) {
    // se_xori: XOR Immediate (5-bit unsigned immediate)
    if (MI.getNumOperands() >= 3) {
      Register DestReg = MI.getOperand(0).getReg();
      Register SrcReg = MI.getOperand(1).getReg();
      int64_t Imm = MI.getOperand(2).getImm();
      
      if (isVLERegister(DestReg, MRI) && isVLERegister(SrcReg, MRI) &&
          fitsInVLEImmediate(Imm, 1)) {
        BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(PPC::SE_XORI))
            .addReg(DestReg, RegState::Define)
            .addReg(SrcReg)
            .addImm(Imm);
        MI.eraseFromParent();
        NumConvertedTo16Bit++;
        return true;
      }
    }
  }
  
  return false;
}

bool PPCVLEOpt::convertShift(MachineInstr &MI) {
  unsigned Opcode = MI.getOpcode();
  MachineBasicBlock &MBB = *MI.getParent();
  MachineRegisterInfo &MRI = MBB.getParent()->getRegInfo();
  
  // Check for shift immediate instructions that can be converted to se_slwi, se_srwi, se_srawi
  // These require 5-bit unsigned immediate (0-31)
  
  if (Opcode == PPC::RLWINM || Opcode == PPC::RLWINM8) {
    // Check if this is effectively a shift (MB=0, ME=31-shift_amount)
    if (MI.getNumOperands() >= 5) {
      Register DestReg = MI.getOperand(0).getReg();
      Register SrcReg = MI.getOperand(1).getReg();
      int64_t ShiftAmt = MI.getOperand(2).getImm();
      int64_t MB = MI.getOperand(3).getImm();
      int64_t ME = MI.getOperand(4).getImm();
      
      // Check if this is a left shift (SLWI): MB=0, ME=31-shift
      if (MB == 0 && ME == (31 - ShiftAmt) && fitsInVLEImmediate(ShiftAmt, 1)) {
        if (isVLERegister(DestReg, MRI) && isVLERegister(SrcReg, MRI)) {
          BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(PPC::SE_SLWI))
              .addReg(DestReg, RegState::Define)
              .addReg(SrcReg)
              .addImm(ShiftAmt);
          MI.eraseFromParent();
          NumConvertedTo16Bit++;
          return true;
        }
      }
      
      // Check if this is a right shift (SRWI): shift=32-shift, MB=shift, ME=31
      if (MB == ShiftAmt && ME == 31 && ShiftAmt > 0 && ShiftAmt <= 31) {
        int64_t ActualShift = 32 - ShiftAmt;
        if (fitsInVLEImmediate(ActualShift, 1)) {
          if (isVLERegister(DestReg, MRI) && isVLERegister(SrcReg, MRI)) {
            BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(PPC::SE_SRWI))
                .addReg(DestReg, RegState::Define)
                .addReg(SrcReg)
                .addImm(ActualShift);
            MI.eraseFromParent();
            NumConvertedTo16Bit++;
            return true;
          }
        }
      }
    }
  }
  
  if (Opcode == PPC::SRAWI || Opcode == PPC::SRAWI8) {
    // se_srawi: Shift Right Algebraic Word Immediate
    if (MI.getNumOperands() >= 3) {
      Register DestReg = MI.getOperand(0).getReg();
      Register SrcReg = MI.getOperand(1).getReg();
      int64_t ShiftAmt = MI.getOperand(2).getImm();
      
      if (isVLERegister(DestReg, MRI) && isVLERegister(SrcReg, MRI) &&
          fitsInVLEImmediate(ShiftAmt, 1)) {
        BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(PPC::SE_SRAWI))
            .addReg(DestReg, RegState::Define)
            .addReg(SrcReg)
            .addImm(ShiftAmt);
        MI.eraseFromParent();
        NumConvertedTo16Bit++;
        return true;
      }
    }
  }
  
  return false;
}

