//===-- PPCInstrVLE.td - PowerPC VLE Instruction Definitions ---*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file describes the Variable Length Encoding (VLE) instructions for
// PowerPC embedded processors (e200 series). VLE instructions can be either
// 16-bit (SE_* prefix) or 32-bit (E_* prefix) forms.
//
//===----------------------------------------------------------------------===//

include "PPCInstrFormats.td"
include "PPCInstrInfo.td"

//===----------------------------------------------------------------------===//
// Immediate Range Predicates and Operands for VLE Instructions
//===----------------------------------------------------------------------===//

// s6imm: 6-bit signed immediate (-32 to 31, inclusive)
// Used for: se_addi, se_subi, se_cmpi, se_lwz, se_stw displacement
// Boundary values: -32 (minimum), 31 (maximum), 0 (zero)
// Note: Values outside this range must use 32-bit E_* forms or materialize in register
def s6imm_pred : PatLeaf<(imm), [{
  int64_t Imm = N->getSExtValue();
  // Explicit boundary checks: -32 <= Imm <= 31 (6-bit signed: -32 to 31 inclusive)
  // Boundary values explicitly tested to prevent off-by-one errors
  return Imm >= -32 && Imm <= 31;
}]>;

// u5imm_vle: 5-bit unsigned immediate (0 to 31, inclusive)
// Used for: shift amounts (se_slwi, se_srwi, se_srawi), 
//           logical operations (se_andi, se_ori, se_xori with small masks)
// Boundary values: 0 (minimum), 31 (maximum)
// Note: u5imm already exists in PPCInstrInfo.td as an Operand type with parser/printer support.
// This predicate version is for pattern matching in instruction selection.
def u5imm_vle_pred : PatLeaf<(imm), [{
  int64_t Imm = N->getSExtValue();
  // Explicit boundary checks: 0 <= Imm <= 31 (5-bit unsigned: 0 to 31 inclusive)
  // Boundary values explicitly tested to prevent off-by-one errors
  return Imm >= 0 && Imm <= 31;
}]>;

// u7imm_vle: 7-bit unsigned immediate (0 to 127, inclusive)
// Used for: se_li (load immediate), se_addi with extended range
// Boundary values: 0 (minimum), 127 (maximum)
// Note: u7imm already exists in PPCInstrInfo.td as an Operand type with parser/printer support.
// This predicate version is for pattern matching in instruction selection.
def u7imm_vle_pred : PatLeaf<(imm), [{
  int64_t Imm = N->getSExtValue();
  // Explicit boundary checks: 0 <= Imm <= 127 (7-bit unsigned: 0 to 127 inclusive)
  // Boundary value 127 explicitly tested to prevent off-by-one errors
  // Note: Value 128 must use 32-bit form or materialize in register
  return Imm >= 0 && Imm <= 127;
}]>;

// u4imm_vle: 4-bit unsigned immediate (0 to 15, inclusive)
// Used for: memory displacements in some 16-bit VLE instructions
// Boundary values: 0 (minimum), 15 (maximum)
// Note: u4imm already exists in PPCInstrInfo.td as an Operand type with parser/printer support.
// This predicate version is for pattern matching in instruction selection.
def u4imm_vle_pred : PatLeaf<(imm), [{
  int64_t Imm = N->getSExtValue();
  // Explicit boundary checks: 0 <= Imm <= 15 (4-bit unsigned: 0 to 15 inclusive)
  // Boundary value 15 explicitly tested to prevent off-by-one errors
  // Note: Value 16 must use wider displacement form or 32-bit instruction
  return Imm >= 0 && Imm <= 15;
}]>;

// Additional predicates for common immediate ranges used in VLE instructions

// immSExt6: Alias for s6imm (6-bit sign-extended immediate)
// Provides standard naming convention matching PowerPC immediate patterns
// This is an alias for s6imm_pred for use in patterns requiring standard naming
def immSExt6 : PatLeaf<(imm), [{
  int64_t Imm = N->getSExtValue();
  // 6-bit signed immediate: -32 to 31 (same as s6imm_pred)
  return Imm >= -32 && Imm <= 31;
}]>;

// uimm6: 6-bit unsigned immediate (0 to 63, inclusive) - predicate version
// Used for: extended immediate ranges in some VLE instructions
// Note: u6imm already exists in PPCInstrInfo.td as an Operand type with parser/printer support.
def uimm6_pred : PatLeaf<(imm), [{
  int64_t Imm = N->getSExtValue();
  // 6-bit unsigned immediate: 0 to 63
  return Imm >= 0 && Imm <= 63;
}]>;

//===----------------------------------------------------------------------===//
// Register Constraint Predicates for 16-bit VLE Instructions
//===----------------------------------------------------------------------===//

// VLE 16-bit instructions require registers to be in range R0-R7 (3-bit encoding)
// This predicate checks if a register is in the VLE range
// Used for pattern matching when selecting 16-bit VLE instruction forms
def gprc_vle_r0_r7_pred : PatLeaf<(i32 gprc:$reg), [{
  // N is the SDValue for the register operand
  if (N.getOpcode() != ISD::Register)
    return false;
  
  unsigned Reg = cast<RegisterSDNode>(N.getNode())->getReg();
  const TargetRegisterInfo *TRI = CurDAG->getSubtarget().getRegisterInfo();
  
  // Check if register is in GPRC_VLE_R0_R7 register class (R0-R7)
  // Physical registers: Check if it's R0-R7 (PPC::R0 through PPC::R7)
  if (Register::isPhysicalRegister(Reg)) {
    return Reg >= PPC::R0 && Reg <= PPC::R7;
  }
  
  // For virtual registers, check if they can be assigned to GPRC_VLE_R0_R7
  const TargetRegisterClass *VLE_R0_R7 = &PPC::GPRC_VLE_R0_R7RegClass;
  const TargetRegisterClass *RegRC = TRI->getRegClass(Reg);
  return RegRC == VLE_R0_R7 || TRI->hasSuperClass(VLE_R0_R7, RegRC);
}]>;

//===----------------------------------------------------------------------===//
// Helper Patterns for VLE Instruction Selection
//===----------------------------------------------------------------------===//

// Pattern fragments for VLE immediate checking
// These can be used in instruction patterns to ensure immediate values
// fit in VLE constraints before selecting 16-bit forms

def vle_s6imm : PatFrag<(ops node:$imm), (imm), [{
  int64_t Imm = (cast<ConstantSDNode>(N->getOperand(0))->getSExtValue());
  return Imm >= -32 && Imm <= 31;
}]>;

def vle_u5imm : PatFrag<(ops node:$imm), (imm), [{
  int64_t Imm = (cast<ConstantSDNode>(N->getOperand(0))->getSExtValue());
  return Imm >= 0 && Imm <= 31;
}]>;

def vle_u7imm : PatFrag<(ops node:$imm), (imm), [{
  int64_t Imm = (cast<ConstantSDNode>(N->getOperand(0))->getSExtValue());
  return Imm >= 0 && Imm <= 127;
}]>;

//===----------------------------------------------------------------------===//
// VLE Register Class for 16-bit Instructions
//===----------------------------------------------------------------------===//
// Register class that only includes R0-R7 for 16-bit VLE instructions
// This register class should be used in VLE instruction definitions to
// ensure proper register constraint checking at TableGen level
//
// Note: The actual register allocation preference for R0-R7 is handled
// in PPCRegisterInfo.td via alternative allocation orders

//===----------------------------------------------------------------------===//
// Instructions Definitions
//===----------------------------------------------------------------------===//
// VLE instruction definitions

// e_rfi: Return From Interrupt (VLE 32-bit form)
// VLE equivalent of RFI instruction for interrupt handler returns
// Encoding: Same as RFI (XForm opcode 19, extended opcode 50)
// but requires VLE mode
def E_RFI : XForm_0<19, 50, (outs), (ins), "e_rfi", IIC_SprRFI, []>,
            Requires<[IsBookE, IsVLE]>;

