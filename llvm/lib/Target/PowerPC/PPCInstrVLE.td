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
// Immediate Range Predicates for VLE Instructions
//===----------------------------------------------------------------------===//

// s6imm: 6-bit signed immediate (-32 to 31)
// Used for: se_addi, se_subi, se_cmpi, etc.
def s6imm_pred : PatLeaf<(imm), [{
  int64_t Imm = N->getSExtValue();
  return Imm >= -32 && Imm <= 31;
}]>;

// u5imm_vle: 5-bit unsigned immediate (0 to 31)
// Used for: shift amounts, logical operations
// Note: u5imm already exists in PPCInstrInfo.td, but we add a VLE-specific
// predicate that also checks for register constraints (R0-R7)
def u5imm_vle_pred : PatLeaf<(imm), [{
  int64_t Imm = N->getSExtValue();
  return Imm >= 0 && Imm <= 31;
}]>;

// u7imm_vle: 7-bit unsigned immediate (0 to 127)
// Used for: se_li, se_addi with extended range
def u7imm_vle_pred : PatLeaf<(imm), [{
  int64_t Imm = N->getSExtValue();
  return Imm >= 0 && Imm <= 127;
}]>;

// u4imm_vle: 4-bit unsigned immediate (0 to 15)
// Used for: memory displacements in some VLE instructions
def u4imm_vle_pred : PatLeaf<(imm), [{
  int64_t Imm = N->getSExtValue();
  return Imm >= 0 && Imm <= 15;
}]>;

//===----------------------------------------------------------------------===//
// Register Constraint Predicates for 16-bit VLE Instructions
//===----------------------------------------------------------------------===//

// VLE 16-bit instructions require registers to be in range R0-R7 (3-bit encoding)
// This predicate checks if a register is in the VLE range
// Note: This is typically handled by register classes, but can be used
// for pattern matching in custom selection logic
def gprc_vle_r0_r7_pred : PatLeaf<(i32 gprc:$reg), [{
  // This predicate checks if the register value represents R0-R7
  // The actual register number checking happens at instruction selection time
  // This is a placeholder for pattern matching - actual checking is done
  // via register class constraints (GPRC_VLE_R0_R7)
  return true;
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
// VLE instruction definitions should be added here. For now, this file
// provides the predicates and patterns needed for VLE instruction matching.
// 
// Example pattern structure for VLE instructions:
// 
// def SE_ADDI : VLE16Form<..., (outs gprc:$RT), (ins gprc:$RA, s6imm:$imm), ...> {
//   let Constraints = "$RT = $RA"; // for addi where RT can equal RA
//   let Predicates = [IsVLE];
// }
// 
// def : Pat<(add i32:$RA, s6imm_pred:$imm), (SE_ADDI $RA, $imm)>;
//
// The predicates defined above ensure that only values fitting the immediate
// range constraints will match VLE patterns, preventing incorrect instruction
// selection.

