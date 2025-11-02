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
// Note: This file is included by PPCInstrInfo.td, which already includes
// PPCInstrFormats.td. Do not include PPCInstrInfo.td here to avoid circular
// dependencies.

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
// These are defined as PatLeaf predicates above (s6imm_pred, u5imm_vle_pred, etc.)
// and can be used directly in instruction patterns to ensure immediate values
// fit in VLE constraints before selecting 16-bit forms

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
// VLE Instruction Format Classes
//===----------------------------------------------------------------------===//

// Note: VLE instruction opcodes are placeholders and should be updated with
// exact encodings from VLEPIM.pdf. VLE instructions use different encoding
// schemes than standard PowerPC instructions.

// VLE 16-bit instruction format placeholder class
// 16-bit VLE instructions use compact encoding with 3-bit register fields (R0-R7)
class VLE16Form<bits<16> encoding, dag OOL, dag IOL, string asmstr,
                InstrItinClass itin, list<dag> pattern>
  : I<0, OOL, IOL, asmstr, itin> {
  let Size = 2;  // 16-bit instructions
  let Pattern = pattern;
  let Inst{0-15} = encoding;
  let Requires = [IsBookE, IsVLE];
}

// VLE 32-bit instruction format placeholder class
// 32-bit VLE instructions (E_* prefix) typically reuse Book E opcodes
class VLE32Form<bits<6> opcode, dag OOL, dag IOL, string asmstr,
                InstrItinClass itin, list<dag> pattern>
  : I<opcode, OOL, IOL, asmstr, itin> {
  let Pattern = pattern;
  let Requires = [IsBookE, IsVLE];
}

//===----------------------------------------------------------------------===//
// Instructions Definitions
//===----------------------------------------------------------------------===//
// VLE instruction definitions
//
// IMPORTANT: Opcodes are placeholders based on instruction semantics.
// Exact opcodes must be verified against VLEPIM.pdf encoding tables.
//
// SE_ prefix: 16-bit VLE instructions (require R0-R7 registers)
// E_ prefix: 32-bit VLE instructions

//===----------------------------------------------------------------------===//
// SE_ Prefix Instructions (16-bit VLE)
//===----------------------------------------------------------------------===//

//--- Arithmetic Instructions ---

// se_add: Add (16-bit)
// Encoding: Placeholder - verify against VLEPIM.pdf
def SE_ADD : VLE32Form<31, (outs GPRC_VLE_R0_R7:$rD), 
                       (ins GPRC_VLE_R0_R7:$rA, GPRC_VLE_R0_R7:$rB),
                       "se_add $rD, $rA, $rB", IIC_IntSimple,
                       [(set i32:$rD, (add i32:$rA, i32:$rB))]>
            Requires<[IsBookE, IsVLE]>;

// se_addi: Add Immediate (16-bit)
// Encoding: Placeholder - verify against VLEPIM.pdf
// Constraints: R0-R7 registers, s6imm immediate (-32 to 31)
def SE_ADDI : VLE32Form<14, (outs GPRC_VLE_R0_R7:$rD),
                        (ins GPRC_VLE_R0_R7:$rA, s6imm:$imm),
                        "se_addi $rD, $rA, $imm", IIC_IntSimple,
                        [(set i32:$rD, (add i32:$rA, s6imm_pred:$imm))]>
             Requires<[IsBookE, IsVLE]>;

// se_sub: Subtract (16-bit)
def SE_SUB : VLE32Form<31, (outs GPRC_VLE_R0_R7:$rD),
                       (ins GPRC_VLE_R0_R7:$rA, GPRC_VLE_R0_R7:$rB),
                       "se_sub $rD, $rA, $rB", IIC_IntSimple,
                       [(set i32:$rD, (sub i32:$rA, i32:$rB))]>
            Requires<[IsBookE, IsVLE]>;

// se_subf: Subtract From (16-bit)
def SE_SUBF : VLE32Form<31, (outs GPRC_VLE_R0_R7:$rD),
                        (ins GPRC_VLE_R0_R7:$rA, GPRC_VLE_R0_R7:$rB),
                        "se_subf $rD, $rA, $rB", IIC_IntSimple,
                        [(set i32:$rD, (sub i32:$rB, i32:$rA))]>
             Requires<[IsBookE, IsVLE]>;

// se_subi: Subtract Immediate (16-bit)
// Constraints: R0-R7 registers, s6imm immediate (-32 to 31)
def SE_SUBI : VLE32Form<8, (outs GPRC_VLE_R0_R7:$rD),
                        (ins GPRC_VLE_R0_R7:$rA, s6imm:$imm),
                        "se_subi $rD, $rA, $imm", IIC_IntSimple,
                        [(set i32:$rD, (sub i32:$rA, s6imm_pred:$imm))]>
             Requires<[IsBookE, IsVLE]>;

// se_subi.: Subtract Immediate and Record (16-bit)
let Defs = [CR0] in
def SE_SUBI_rec : VLE32Form<8, (outs GPRC_VLE_R0_R7:$rD),
                            (ins GPRC_VLE_R0_R7:$rA, s6imm:$imm),
                            "se_subi. $rD, $rA, $imm", IIC_IntSimple, []>,
                  Requires<[IsBookE, IsVLE]>, isRecordForm;

//--- Load/Store Instructions ---

// se_lbz: Load Byte and Zero (16-bit)
// Constraints: R0-R7 registers, s6imm displacement
def SE_LBZ : DForm_1<34, (outs GPRC_VLE_R0_R7:$rD), (ins memri:$src),
                     "se_lbz $rD, $src", IIC_LdStLoad,
                     [(set i32:$rD, (zextloadi8 iaddr:$src))]>
            Requires<[IsBookE, IsVLE]>, 
            RegConstraint<"$src.reg in GPRC_VLE_R0_R7">;

// se_lhz: Load Halfword and Zero (16-bit)
// Constraints: R0-R7 registers, s6imm displacement
def SE_LHZ : DForm_1<40, (outs GPRC_VLE_R0_R7:$rD), (ins memri:$src),
                     "se_lhz $rD, $src", IIC_LdStLoad,
                     [(set i32:$rD, (zextloadi16 iaddr:$src))]>
            Requires<[IsBookE, IsVLE]>,
            RegConstraint<"$src.reg in GPRC_VLE_R0_R7">;

// se_lwz: Load Word and Zero (16-bit)
// Constraints: R0-R7 registers, s6imm displacement
def SE_LWZ : DForm_1<32, (outs GPRC_VLE_R0_R7:$rD), (ins memri:$src),
                     "se_lwz $rD, $src", IIC_LdStLoad,
                     [(set i32:$rD, (load iaddr:$src))]>
            Requires<[IsBookE, IsVLE]>,
            RegConstraint<"$src.reg in GPRC_VLE_R0_R7">;

// se_li: Load Immediate (16-bit)
// Constraints: R0-R7 registers, u7imm immediate (0 to 127)
let isReMaterializable = 1, isAsCheapAsAMove = 1, isMoveImm = 1 in
def SE_LI : VLE32Form<14, (outs GPRC_VLE_R0_R7:$rD), (ins u7imm:$imm),
                      "se_li $rD, $imm", IIC_IntSimple,
                      [(set i32:$rD, u7imm_vle_pred:$imm)]>
           Requires<[IsBookE, IsVLE]>;

// se_stb: Store Byte (16-bit)
// Constraints: R0-R7 registers, s6imm displacement
def SE_STB : DForm_1<38, (outs), (ins GPRC_VLE_R0_R7:$rS, memri:$dst),
                     "se_stb $rS, $dst", IIC_LdStStore,
                     [(store (truncstorei8 GPRC_VLE_R0_R7:$rS), iaddr:$dst)]>
            Requires<[IsBookE, IsVLE]>,
            RegConstraint<"$dst.reg in GPRC_VLE_R0_R7">;

// se_sth: Store Halfword (16-bit)
// Constraints: R0-R7 registers, s6imm displacement
def SE_STH : DForm_1<44, (outs), (ins GPRC_VLE_R0_R7:$rS, memri:$dst),
                     "se_sth $rS, $dst", IIC_LdStStore,
                     [(store (truncstorei16 GPRC_VLE_R0_R7:$rS), iaddr:$dst)]>
            Requires<[IsBookE, IsVLE]>,
            RegConstraint<"$dst.reg in GPRC_VLE_R0_R7">;

// se_stw: Store Word (16-bit)
// Constraints: R0-R7 registers, s6imm displacement
def SE_STW : DForm_1<36, (outs), (ins GPRC_VLE_R0_R7:$rS, memri:$dst),
                     "se_stw $rS, $dst", IIC_LdStStore,
                     [(store GPRC_VLE_R0_R7:$rS, iaddr:$dst)]>
            Requires<[IsBookE, IsVLE]>,
            RegConstraint<"$dst.reg in GPRC_VLE_R0_R7">;

//--- Branch Instructions ---

// se_b: Branch (16-bit)
def SE_B : IForm<18, 0, 0, (outs), (ins brtarget:$dst),
                 "se_b $dst", IIC_BrUncond,
                 [(br bb:$dst)]>
          Requires<[IsBookE, IsVLE]>;

// se_bc: Branch Conditional (16-bit)
def SE_BC : BForm<16, 0, 0, (outs), (ins crbitrc:$bi, brtarget:$dst),
                  "se_bc $bi, $dst">,
            Requires<[IsBookE, IsVLE]>;

// se_bl: Branch and Link (16-bit)
def SE_BL : IForm<18, 0, 1, (outs gprc:$lr), (ins brtarget:$dst),
                  "se_bl $dst", IIC_BrUncond,
                  [(PPCcallseq_end (bb:$dst))]>
           Requires<[IsBookE, IsVLE]>, Uses<[LR]>;

// se_blr: Branch to Link Register (16-bit)
def SE_BLR : XForm_0<19, 16, (outs), (ins), "se_blr", IIC_BrUncond, []>,
            Requires<[IsBookE, IsVLE]>, Uses<[LR]>;

// se_blrl: Branch to Link Register and Link (16-bit)
def SE_BLRL : XForm_0<19, 16, (outs gprc:$lr), (ins), "se_blrl", IIC_BrUncond, []>,
             Requires<[IsBookE, IsVLE]>, Uses<[LR]>, Defs<[LR]>;

// se_bctr: Branch to Count Register (16-bit)
def SE_BCTR : XForm_0<19, 528, (outs), (ins), "se_bctr", IIC_BrUncond, []>,
             Requires<[IsBookE, IsVLE]>, Uses<[CTR]>;

// se_bctrl: Branch to Count Register & Link (16-bit)
def SE_BCTRL : XForm_0<19, 528, (outs gprc:$lr), (ins), "se_bctrl", IIC_BrUncond, []>,
              Requires<[IsBookE, IsVLE]>, Uses<[CTR]>, Defs<[LR]>;

// se_bclri: Bit Clear Immediate (16-bit)
// Constraints: R0-R7 registers, u5imm bit position (0 to 31)
def SE_BCLRI : VLE32Form<31, (outs GPRC_VLE_R0_R7:$rD),
                         (ins GPRC_VLE_R0_R7:$rS, u5imm:$sh),
                         "se_bclri $rD, $rS, $sh", IIC_IntGeneral,
                         [(set i32:$rD, (and i32:$rS, (not (shl 1, u5imm_vle_pred:$sh))))]>
              Requires<[IsBookE, IsVLE]>;

// se_bgeni: Bit Generate Immediate (16-bit)
// Constraints: R0-R7 registers, u5imm bit position
def SE_BGENI : VLE32Form<31, (outs GPRC_VLE_R0_R7:$rD),
                         (ins GPRC_VLE_R0_R7:$rS, u5imm:$sh),
                         "se_bgeni $rD, $rS, $sh", IIC_IntGeneral, []>
              Requires<[IsBookE, IsVLE]>;

// se_bmaski: Bit Mask Generate Immediate (16-bit)
// Constraints: R0-R7 registers, u5imm bit position
def SE_BMASKI : VLE32Form<31, (outs GPRC_VLE_R0_R7:$rD),
                          (ins GPRC_VLE_R0_R7:$rS, u5imm:$sh),
                          "se_bmaski $rD, $rS, $sh", IIC_IntGeneral, []>
               Requires<[IsBookE, IsVLE]>;

// se_bseti: Bit Set Immediate (16-bit)
// Constraints: R0-R7 registers, u5imm bit position
def SE_BSETI : VLE32Form<31, (outs GPRC_VLE_R0_R7:$rD),
                         (ins GPRC_VLE_R0_R7:$rS, u5imm:$sh),
                         "se_bseti $rD, $rS, $sh", IIC_IntGeneral,
                         [(set i32:$rD, (or i32:$rS, (shl 1, u5imm_vle_pred:$sh)))]>
              Requires<[IsBookE, IsVLE]>;

// se_btsti: Bit Test Immediate (16-bit)
// Constraints: R0-R7 registers, u5imm bit position
def SE_BTSTI : VLE32Form<31, (outs crbitrc:$crD), (ins GPRC_VLE_R0_R7:$rS, u5imm:$sh),
                         "se_btsti $crD, $rS, $sh", IIC_IntGeneral, []>
              Requires<[IsBookE, IsVLE]>, Defs<[CR0]>;

//--- Comparison Instructions ---

// se_cmp: Compare (16-bit)
def SE_CMP : XForm_1<31, 0, (outs crbitrc:$crD), 
                     (ins GPRC_VLE_R0_R7:$rA, GPRC_VLE_R0_R7:$rB),
                     "se_cmp $crD, $rA, $rB", IIC_IntGeneral, []>,
            Requires<[IsBookE, IsVLE]>, Defs<[CR0]>;

// se_cmpi: Compare Immediate (16-bit)
// Constraints: R0-R7 registers, s6imm immediate (-32 to 31)
def SE_CMPI : VLE32Form<11, (outs crbitrc:$crD),
                        (ins GPRC_VLE_R0_R7:$rA, s6imm:$imm),
                        "se_cmpi $crD, $rA, $imm", IIC_IntGeneral, []>
             Requires<[IsBookE, IsVLE]>, Defs<[CR0]>;

// se_cmpl: Compare Logical (16-bit)
def SE_CMPL : XForm_1<31, 32, (outs crbitrc:$crD),
                      (ins GPRC_VLE_R0_R7:$rA, GPRC_VLE_R0_R7:$rB),
                      "se_cmpl $crD, $rA, $rB", IIC_IntGeneral, []>,
             Requires<[IsBookE, IsVLE]>, Defs<[CR0]>;

// se_cmpli: Compare Logical Immediate (16-bit)
// Constraints: R0-R7 registers, u6imm immediate (0 to 63)
def SE_CMPLI : VLE32Form<10, (outs crbitrc:$crD),
                         (ins GPRC_VLE_R0_R7:$rA, u6imm:$imm),
                         "se_cmpli $crD, $rA, $imm", IIC_IntGeneral, []>
              Requires<[IsBookE, IsVLE]>, Defs<[CR0]>;

// se_cmph: Compare Halfword (16-bit)
def SE_CMPH : XForm_1<31, 64, (outs crbitrc:$crD),
                      (ins GPRC_VLE_R0_R7:$rA, GPRC_VLE_R0_R7:$rB),
                      "se_cmph $crD, $rA, $rB", IIC_IntGeneral, []>,
             Requires<[IsBookE, IsVLE]>, Defs<[CR0]>;

// se_cmphl: Compare Halfword Logical (16-bit)
def SE_CMPHL : XForm_1<31, 96, (outs crbitrc:$crD),
                       (ins GPRC_VLE_R0_R7:$rA, GPRC_VLE_R0_R7:$rB),
                       "se_cmphl $crD, $rA, $rB", IIC_IntGeneral, []>,
              Requires<[IsBookE, IsVLE]>, Defs<[CR0]>;

//--- Shift Instructions ---

// se_slw: Shift Left Word (16-bit)
def SE_SLW : XForm_1<31, 24, (outs GPRC_VLE_R0_R7:$rD),
                     (ins GPRC_VLE_R0_R7:$rS, GPRC_VLE_R0_R7:$rB),
                     "se_slw $rD, $rS, $rB", IIC_IntGeneral,
                     [(set i32:$rD, (shl i32:$rS, i32:$rB))]>
            Requires<[IsBookE, IsVLE]>;

// se_slwi: Shift Left Word Immediate (16-bit)
// Constraints: R0-R7 registers, u5imm shift amount (0 to 31)
def SE_SLWI : VLE32Form<31, (outs GPRC_VLE_R0_R7:$rD),
                        (ins GPRC_VLE_R0_R7:$rS, u5imm:$sh),
                        "se_slwi $rD, $rS, $sh", IIC_IntGeneral,
                        [(set i32:$rD, (shl i32:$rS, u5imm_vle_pred:$sh))]>
             Requires<[IsBookE, IsVLE]>;

// se_srw: Shift Right Word (16-bit)
def SE_SRW : XForm_1<31, 536, (outs GPRC_VLE_R0_R7:$rD),
                     (ins GPRC_VLE_R0_R7:$rS, GPRC_VLE_R0_R7:$rB),
                     "se_srw $rD, $rS, $rB", IIC_IntGeneral,
                     [(set i32:$rD, (srl i32:$rS, i32:$rB))]>
            Requires<[IsBookE, IsVLE]>;

// se_srwi: Shift Right Word Immediate (16-bit)
// Constraints: R0-R7 registers, u5imm shift amount (0 to 31)
def SE_SRWI : VLE32Form<31, (outs GPRC_VLE_R0_R7:$rD),
                        (ins GPRC_VLE_R0_R7:$rS, u5imm:$sh),
                        "se_srwi $rD, $rS, $sh", IIC_IntGeneral,
                        [(set i32:$rD, (srl i32:$rS, u5imm_vle_pred:$sh))]>
             Requires<[IsBookE, IsVLE]>;

// se_sraw: Shift Right Algebraic Word (16-bit)
def SE_SRAW : XForm_1<31, 792, (outs GPRC_VLE_R0_R7:$rD),
                      (ins GPRC_VLE_R0_R7:$rS, GPRC_VLE_R0_R7:$rB),
                      "se_sraw $rD, $rS, $rB", IIC_IntGeneral,
                      [(set i32:$rD, (sra i32:$rS, i32:$rB))]>
             Requires<[IsBookE, IsVLE]>;

// se_srawi: Shift Right Algebraic Word Immediate (16-bit)
// Constraints: R0-R7 registers, u5imm shift amount (0 to 31)
def SE_SRAWI : VLE32Form<31, (outs GPRC_VLE_R0_R7:$rD),
                          (ins GPRC_VLE_R0_R7:$rS, u5imm:$sh),
                          "se_srawi $rD, $rS, $sh", IIC_IntGeneral,
                          [(set i32:$rD, (sra i32:$rS, u5imm_vle_pred:$sh))]>
               Requires<[IsBookE, IsVLE]>;

//--- Move/Register Instructions ---

// se_mr: Move Register (16-bit)
// Constraints: R0-R7 registers
let isAsCheapAsAMove = 1 in
def SE_MR : XForm_1<31, 444, (outs GPRC_VLE_R0_R7:$rD),
                    (ins GPRC_VLE_R0_R7:$rS),
                    "se_mr $rD, $rS", IIC_IntSimple,
                    [(set i32:$rD, i32:$rS)]>
           Requires<[IsBookE, IsVLE]>;

// se_mflr: Move From Link Register (16-bit)
def SE_MFLR : XForm_0<31, 339, (outs GPRC_VLE_R0_R7:$rD), (ins),
                      "se_mflr $rD", IIC_SprRead, []>,
             Requires<[IsBookE, IsVLE]>, Uses<[LR]>;

// se_mtlr: Move To Link Register (16-bit)
def SE_MTLR : XForm_0<31, 467, (outs), (ins GPRC_VLE_R0_R7:$rS),
                      "se_mtlr $rS", IIC_SprWrite, []>,
             Requires<[IsBookE, IsVLE]>, Defs<[LR]>;

// se_mfctr: Move From Count Register (16-bit)
def SE_MFCTR : XForm_0<31, 339, (outs GPRC_VLE_R0_R7:$rD), (ins),
                       "se_mfctr $rD", IIC_SprRead, []>,
              Requires<[IsBookE, IsVLE]>, Uses<[CTR]>;

// se_mtctr: Move To Count Register (16-bit)
def SE_MTCTR : XForm_0<31, 467, (outs), (ins GPRC_VLE_R0_R7:$rS),
                       "se_mtctr $rS", IIC_SprWrite, []>,
              Requires<[IsBookE, IsVLE]>, Defs<[CTR]>;

// se_mfar: Move from Alternate Register (16-bit)
def SE_MFAR : XForm_0<31, 339, (outs GPRC_VLE_R0_R7:$rD), (ins),
                      "se_mfar $rD", IIC_SprRead, []>
             Requires<[IsBookE, IsVLE]>;

// se_mtar: Move to Alternate Register (16-bit)
def SE_MTAR : XForm_0<31, 467, (outs), (ins GPRC_VLE_R0_R7:$rS),
                      "se_mtar $rS", IIC_SprWrite, []>
             Requires<[IsBookE, IsVLE]>;

// se_mullw: Multiply Low Word (16-bit)
def SE_MULLW : XForm_1<31, 235, (outs GPRC_VLE_R0_R7:$rD),
                       (ins GPRC_VLE_R0_R7:$rA, GPRC_VLE_R0_R7:$rB),
                       "se_mullw $rD, $rA, $rB", IIC_IntMul,
                       [(set i32:$rD, (mul i32:$rA, i32:$rB))]>
              Requires<[IsBookE, IsVLE]>;

//--- Logical Instructions ---

// se_and: AND (16-bit)
def SE_AND : XForm_1<31, 28, (outs GPRC_VLE_R0_R7:$rD),
                     (ins GPRC_VLE_R0_R7:$rA, GPRC_VLE_R0_R7:$rB),
                     "se_and $rD, $rA, $rB", IIC_IntSimple,
                     [(set i32:$rD, (and i32:$rA, i32:$rB))]>
            Requires<[IsBookE, IsVLE]>;

// se_and.: AND and Record (16-bit)
let Defs = [CR0] in
def SE_AND_rec : XForm_1<31, 28, (outs GPRC_VLE_R0_R7:$rD),
                         (ins GPRC_VLE_R0_R7:$rA, GPRC_VLE_R0_R7:$rB),
                         "se_and. $rD, $rA, $rB", IIC_IntSimple, []>,
                Requires<[IsBookE, IsVLE]>, isRecordForm;

// se_andc: AND with Complement (16-bit)
def SE_ANDC : XForm_1<31, 60, (outs GPRC_VLE_R0_R7:$rD),
                      (ins GPRC_VLE_R0_R7:$rA, GPRC_VLE_R0_R7:$rB),
                      "se_andc $rD, $rA, $rB", IIC_IntSimple,
                      [(set i32:$rD, (and i32:$rA, (xor i32:$rB, -1)))]>
             Requires<[IsBookE, IsVLE]>;

// se_andi: AND Immediate (16-bit)
// Constraints: R0-R7 registers, u5imm immediate (0 to 31)
def SE_ANDI : VLE32Form<28, (outs GPRC_VLE_R0_R7:$rD),
                        (ins GPRC_VLE_R0_R7:$rS, u5imm:$imm),
                        "se_andi $rD, $rS, $imm", IIC_IntGeneral,
                        [(set i32:$rD, (and i32:$rS, u5imm_vle_pred:$imm))]>
             Requires<[IsBookE, IsVLE]>;

// se_or: OR (16-bit)
def SE_OR : XForm_1<31, 444, (outs GPRC_VLE_R0_R7:$rD),
                    (ins GPRC_VLE_R0_R7:$rA, GPRC_VLE_R0_R7:$rB),
                    "se_or $rD, $rA, $rB", IIC_IntSimple,
                    [(set i32:$rD, (or i32:$rA, i32:$rB))]>
           Requires<[IsBookE, IsVLE]>;

// se_not: NOT (16-bit)
def SE_NOT : XForm_1<31, 476, (outs GPRC_VLE_R0_R7:$rD),
                     (ins GPRC_VLE_R0_R7:$rS),
                     "se_not $rD, $rS", IIC_IntSimple,
                     [(set i32:$rD, (xor i32:$rS, -1))]>
            Requires<[IsBookE, IsVLE]>;

// se_neg: Negate (16-bit)
def SE_NEG : XForm_1<31, 104, (outs GPRC_VLE_R0_R7:$rD),
                     (ins GPRC_VLE_R0_R7:$rS),
                     "se_neg $rD, $rS", IIC_IntSimple,
                     [(set i32:$rD, (neg i32:$rS))]>
            Requires<[IsBookE, IsVLE]>;

//--- Extend Instructions ---

// se_extsb: Extend Sign Byte (16-bit)
def SE_EXTSB : XForm_1<31, 954, (outs GPRC_VLE_R0_R7:$rD),
                       (ins GPRC_VLE_R0_R7:$rS),
                       "se_extsb $rD, $rS", IIC_IntGeneral,
                       [(set i32:$rD, (sext_inreg i32:$rS, i8))]>
              Requires<[IsBookE, IsVLE]>;

// se_extsh: Extend Sign Halfword (16-bit)
def SE_EXTSH : XForm_1<31, 922, (outs GPRC_VLE_R0_R7:$rD),
                       (ins GPRC_VLE_R0_R7:$rS),
                       "se_extsh $rD, $rS", IIC_IntGeneral,
                       [(set i32:$rD, (sext_inreg i32:$rS, i16))]>
              Requires<[IsBookE, IsVLE]>;

// se_extzb: Extend with Zeros Byte (16-bit)
def SE_EXTZB : XForm_1<31, 954, (outs GPRC_VLE_R0_R7:$rD),
                       (ins GPRC_VLE_R0_R7:$rS),
                       "se_extzb $rD, $rS", IIC_IntGeneral,
                       [(set i32:$rD, (and i32:$rS, 255))]>
              Requires<[IsBookE, IsVLE]>;

// se_extzh: Extend with Zeros Halfword (16-bit)
def SE_EXTZH : XForm_1<31, 922, (outs GPRC_VLE_R0_R7:$rD),
                       (ins GPRC_VLE_R0_R7:$rS),
                       "se_extzh $rD, $rS", IIC_IntGeneral,
                       [(set i32:$rD, (and i32:$rS, 65535))]>
              Requires<[IsBookE, IsVLE]>;

//--- Interrupt Instructions ---

// se_rfi: Return From Interrupt (16-bit)
def SE_RFI : XForm_0<19, 50, (outs), (ins), "se_rfi", IIC_SprRFI, []>,
            Requires<[IsBookE, IsVLE]>;

// se_rfci: Return From Critical Interrupt (16-bit)
def SE_RFCI : XForm_0<19, 51, (outs), (ins), "se_rfci", IIC_SprRFI, []>,
              Requires<[IsBookE, IsVLE]>;

// se_rfdi: Return From Debug Interrupt (16-bit)
def SE_RFDI : XForm_0<19, 52, (outs), (ins), "se_rfdi", IIC_SprRFI, []>,
              Requires<[IsBookE, IsVLE]>;

//--- Other Instructions ---

// se_illegal: Illegal (16-bit)
def SE_ILLEGAL : XForm_0<0, 0, (outs), (ins), "se_illegal", IIC_IntGeneral, []>,
                 Requires<[IsBookE, IsVLE]>, hasSideEffects<1>;

// se_isync: Instruction Synchronize (16-bit)
def SE_ISYNC : XForm_0<19, 150, (outs), (ins), "se_isync", IIC_BrUncond, []>,
              Requires<[IsBookE, IsVLE]>, hasSideEffects<1>;

// se_sc: System Call (16-bit)
def SE_SC : SCForm<17, 0, (outs), (ins u16imm:$imm),
                   "se_sc", IIC_Syscall,
                   [(PPCsc imm:$imm)]>
           Requires<[IsBookE, IsVLE]>, hasSideEffects<1>;

//===----------------------------------------------------------------------===//
// E_ Prefix Instructions (32-bit VLE)
//===----------------------------------------------------------------------===//

// Note: E_RFI is already defined above in the Instructions Definitions section

//--- Arithmetic Instructions ---

// e_addi: Add Immediate (32-bit VLE)
def E_ADDI : DForm_2<14, (outs gprc:$rD), (ins gprc_nor0:$rA, s16imm:$imm),
                     "e_addi $rD, $rA, $imm", IIC_IntSimple,
                     [(set i32:$rD, (add i32:$rA, imm32SExt16:$imm))]>
            Requires<[IsBookE, IsVLE]>;

// e_addi.: Add Immediate and Record (32-bit VLE)
let Defs = [CR0] in
def E_ADDI_rec : DForm_2<14, (outs gprc:$rD), (ins gprc_nor0:$rA, s16imm:$imm),
                         "e_addi. $rD, $rA, $imm", IIC_IntSimple, []>,
                Requires<[IsBookE, IsVLE]>, isRecordForm;

// e_addic: Add Immediate Carrying (32-bit VLE)
let Defs = [CARRY] in
def E_ADDIC : DForm_2<12, (outs gprc:$rD), (ins gprc:$rA, s16imm:$imm),
                      "e_addic $rD, $rA, $imm", IIC_IntGeneral,
                      [(set i32:$rD, (addc i32:$rA, imm32SExt16:$imm))]>
             Requires<[IsBookE, IsVLE]>;

// e_addic.: Add Immediate Carrying and Record (32-bit VLE)
let Defs = [CARRY, CR0] in
def E_ADDIC_rec : DForm_2<13, (outs gprc:$rD), (ins gprc:$rA, s16imm:$imm),
                          "e_addic. $rD, $rA, $imm", IIC_IntGeneral, []>,
                 Requires<[IsBookE, IsVLE]>, isRecordForm;

// e_add16i: Add Immediate (16-bit form, 32-bit VLE encoding)
def E_ADD16I : DForm_2<14, (outs GPRC_VLE_R0_R7:$rD),
                       (ins GPRC_VLE_R0_R7:$rA, s6imm:$imm),
                       "e_add16i $rD, $rA, $imm", IIC_IntSimple,
                       [(set i32:$rD, (add i32:$rA, s6imm_pred:$imm))]>
              Requires<[IsBookE, IsVLE]>;

// e_add2i.: Add (2 operand) Immediate and Record CR (32-bit VLE)
let Defs = [CR0] in
def E_ADD2I_rec : DForm_2<14, (outs GPRC_VLE_R0_R7:$rD),
                          (ins GPRC_VLE_R0_R7:$rA, s6imm:$imm),
                          "e_add2i. $rD, $rA, $imm", IIC_IntSimple, []>,
                 Requires<[IsBookE, IsVLE]>, isRecordForm;

// e_add2is: Add (2 operand) Immediate Shifted (32-bit VLE)
def E_ADD2IS : DForm_2<14, (outs GPRC_VLE_R0_R7:$rD),
                       (ins GPRC_VLE_R0_R7:$rA, s6imm:$imm),
                       "e_add2is $rD, $rA, $imm", IIC_IntSimple,
                       [(set i32:$rD, (add i32:$rA, (shl s6imm_pred:$imm, 1)))]>
              Requires<[IsBookE, IsVLE]>;

// e_subfic: Subtract From Immediate Carrying (32-bit VLE)
let Defs = [CARRY] in
def E_SUBFIC : DForm_2<8, (outs gprc:$rD), (ins gprc:$rA, s16imm:$imm),
                       "e_subfic $rD, $rA, $imm", IIC_IntGeneral,
                       [(set i32:$rD, (subc imm32SExt16:$imm, i32:$rA))]>
              Requires<[IsBookE, IsVLE]>;

// e_subfic.: Subtract From Immediate Carrying and Record (32-bit VLE)
let Defs = [CARRY, CR0] in
def E_SUBFIC_rec : DForm_2<8, (outs gprc:$rD), (ins gprc:$rA, s16imm:$imm),
                            "e_subfic. $rD, $rA, $imm", IIC_IntGeneral, []>,
                  Requires<[IsBookE, IsVLE]>, isRecordForm;

//--- Logical Instructions ---

// e_andi: AND Immediate (32-bit VLE)
def E_ANDI : DForm_4<28, (outs gprc:$dst), (ins gprc:$src1, u16imm:$src2),
                     "e_andi $dst, $src1, $src2", IIC_IntGeneral,
                     [(set i32:$dst, (and i32:$src1, immZExt16:$src2))]>
            Requires<[IsBookE, IsVLE]>;

// e_andi.: AND Immediate and Record (32-bit VLE)
let Defs = [CR0] in
def E_ANDI_rec : DForm_4<28, (outs gprc:$dst), (ins gprc:$src1, u16imm:$src2),
                         "e_andi. $dst, $src1, $src2", IIC_IntGeneral, []>,
                Requires<[IsBookE, IsVLE]>, isRecordForm;

// e_and2i.: AND (2 operand) Immediate & record CR (32-bit VLE)
let Defs = [CR0] in
def E_AND2I_rec : DForm_4<28, (outs GPRC_VLE_R0_R7:$dst),
                          (ins GPRC_VLE_R0_R7:$src1, u5imm:$src2),
                          "e_and2i. $dst, $src1, $src2", IIC_IntGeneral, []>,
                 Requires<[IsBookE, IsVLE]>, isRecordForm;

// e_and2is.: AND (2 operand) Immediate Shifted & record CR (32-bit VLE)
let Defs = [CR0] in
def E_AND2IS_rec : DForm_4<28, (outs GPRC_VLE_R0_R7:$dst),
                            (ins GPRC_VLE_R0_R7:$src1, u5imm:$src2),
                            "e_and2is. $dst, $src1, $src2", IIC_IntGeneral, []>,
                   Requires<[IsBookE, IsVLE]>, isRecordForm;

// e_ori: OR Immediate (32-bit VLE)
def E_ORI : DForm_4<24, (outs gprc:$dst), (ins gprc:$src1, u16imm:$src2),
                    "e_ori $dst, $src1, $src2", IIC_IntGeneral,
                    [(set i32:$dst, (or i32:$src1, immZExt16:$src2))]>
           Requires<[IsBookE, IsVLE]>;

// e_ori.: OR Immediate and Record (32-bit VLE)
let Defs = [CR0] in
def E_ORI_rec : DForm_4<24, (outs gprc:$dst), (ins gprc:$src1, u16imm:$src2),
                        "e_ori. $dst, $src1, $src2", IIC_IntGeneral, []>,
               Requires<[IsBookE, IsVLE]>, isRecordForm;

// e_or2i.: OR (2 operand) Immediate & record CR (32-bit VLE)
let Defs = [CR0] in
def E_OR2I_rec : DForm_4<24, (outs GPRC_VLE_R0_R7:$dst),
                         (ins GPRC_VLE_R0_R7:$src1, u5imm:$src2),
                         "e_or2i. $dst, $src1, $src2", IIC_IntGeneral, []>,
                Requires<[IsBookE, IsVLE]>, isRecordForm;

// e_or2is.: OR (2 operand) Immediate Shifted & record CR (32-bit VLE)
let Defs = [CR0] in
def E_OR2IS_rec : DForm_4<24, (outs GPRC_VLE_R0_R7:$dst),
                           (ins GPRC_VLE_R0_R7:$src1, u5imm:$src2),
                           "e_or2is. $dst, $src1, $src2", IIC_IntGeneral, []>,
                  Requires<[IsBookE, IsVLE]>, isRecordForm;

// e_xori: XOR Immediate (32-bit VLE)
def E_XORI : DForm_4<26, (outs gprc:$dst), (ins gprc:$src1, u16imm:$src2),
                     "e_xori $dst, $src1, $src2", IIC_IntGeneral,
                     [(set i32:$dst, (xor i32:$src1, immZExt16:$src2))]>
            Requires<[IsBookE, IsVLE]>;

// e_xori.: XOR Immediate and Record (32-bit VLE)
let Defs = [CR0] in
def E_XORI_rec : DForm_4<26, (outs gprc:$dst), (ins gprc:$src1, u16imm:$src2),
                         "e_xori. $dst, $src1, $src2", IIC_IntGeneral, []>,
                Requires<[IsBookE, IsVLE]>, isRecordForm;

//--- Branch Instructions ---

// e_b: Branch (32-bit VLE)
def E_B : IForm<18, 0, 0, (outs), (ins brtarget:$dst),
                "e_b $dst", IIC_BrUncond,
                [(br bb:$dst)]>
         Requires<[IsBookE, IsVLE]>;

// e_bc: Branch Conditional (32-bit VLE)
def E_BC : BForm<16, 0, 0, (outs), (ins crbitrc:$bi, brtarget:$dst),
                 "e_bc $bi, $dst">,
          Requires<[IsBookE, IsVLE]>;

// e_bcl: Branch Conditional & Link (32-bit VLE)
def E_BCL : BForm<16, 0, 1, (outs gprc:$lr), (ins crbitrc:$bi, brtarget:$dst),
                  "e_bcl $bi, $dst">,
           Requires<[IsBookE, IsVLE]>, Uses<[LR]>, Defs<[LR]>;

// e_bl: Branch & Link (32-bit VLE)
def E_BL : IForm<18, 0, 1, (outs gprc:$lr), (ins brtarget:$dst),
                 "e_bl $dst", IIC_BrUncond,
                 [(PPCcallseq_end (bb:$dst))]>
          Requires<[IsBookE, IsVLE]>, Uses<[LR]>, Defs<[LR]>;

//--- Comparison Instructions ---

// e_cmpi: Compare Immediate (32-bit VLE)
def E_CMPI : DForm_5<11, (outs crbitrc:$crD), (ins gprc:$rA, s16imm:$imm),
                     "e_cmpi $crD, $rA, $imm", IIC_IntGeneral, []>,
            Requires<[IsBookE, IsVLE]>, Defs<[CR0]>;

// e_cmpli: Compare Logical Immediate (32-bit VLE)
def E_CMPLI : DForm_5<10, (outs crbitrc:$crD), (ins gprc:$rA, u16imm:$imm),
                      "e_cmpli $crD, $rA, $imm", IIC_IntGeneral, []>,
             Requires<[IsBookE, IsVLE]>, Defs<[CR0]>;

// e_cmp16i: Compare Immediate (16-bit form, 32-bit VLE encoding)
def E_CMP16I : DForm_5<11, (outs crbitrc:$crD),
                       (ins GPRC_VLE_R0_R7:$rA, s6imm:$imm),
                       "e_cmp16i $crD, $rA, $imm", IIC_IntGeneral, []>,
              Requires<[IsBookE, IsVLE]>, Defs<[CR0]>;

// e_cmpl16i: Compare Logical Immediate (16-bit form, 32-bit VLE encoding)
def E_CMPL16I : DForm_5<10, (outs crbitrc:$crD),
                        (ins GPRC_VLE_R0_R7:$rA, u6imm:$imm),
                        "e_cmpl16i $crD, $rA, $imm", IIC_IntGeneral, []>,
               Requires<[IsBookE, IsVLE]>, Defs<[CR0]>;

// e_cmph: Compare Halfword (32-bit VLE)
def E_CMPH : XForm_1<31, 64, (outs crbitrc:$crD),
                     (ins gprc:$rA, gprc:$rB),
                     "e_cmph $crD, $rA, $rB", IIC_IntGeneral, []>,
            Requires<[IsBookE, IsVLE]>, Defs<[CR0]>;

// e_cmph16i: Compare Halfword Immediate (32-bit VLE)
def E_CMPH16I : DForm_5<11, (outs crbitrc:$crD),
                        (ins GPRC_VLE_R0_R7:$rA, s6imm:$imm),
                        "e_cmph16i $crD, $rA, $imm", IIC_IntGeneral, []>,
               Requires<[IsBookE, IsVLE]>, Defs<[CR0]>;

// e_cmphl: Compare Halfword Logical (32-bit VLE)
def E_CMPHL : XForm_1<31, 96, (outs crbitrc:$crD),
                      (ins gprc:$rA, gprc:$rB),
                      "e_cmphl $crD, $rA, $rB", IIC_IntGeneral, []>,
             Requires<[IsBookE, IsVLE]>, Defs<[CR0]>;

// e_cmphl16i: Compare Halfword Logical Immediate (32-bit VLE)
def E_CMPHL16I : DForm_5<10, (outs crbitrc:$crD),
                          (ins GPRC_VLE_R0_R7:$rA, u6imm:$imm),
                          "e_cmphl16i $crD, $rA, $imm", IIC_IntGeneral, []>,
                Requires<[IsBookE, IsVLE]>, Defs<[CR0]>;

//--- Condition Register Instructions ---

// e_crand: Condition Register AND (32-bit VLE)
def E_CRAND : XForm_0<19, 257, (outs crbitrc:$crD),
                      (ins crbitrc:$crA, crbitrc:$crB),
                      "e_crand $crD, $crA, $crB", IIC_IntGeneral, []>,
             Requires<[IsBookE, IsVLE]>;

// e_crandc: Condition Register AND with Complement (32-bit VLE)
def E_CRANDC : XForm_0<19, 129, (outs crbitrc:$crD),
                       (ins crbitrc:$crA, crbitrc:$crB),
                       "e_crandc $crD, $crA, $crB", IIC_IntGeneral, []>,
              Requires<[IsBookE, IsVLE]>;

// e_creqv: Condition Register Equivalent (32-bit VLE)
def E_CREQV : XForm_0<19, 289, (outs crbitrc:$crD),
                      (ins crbitrc:$crA, crbitrc:$crB),
                      "e_creqv $crD, $crA, $crB", IIC_IntGeneral, []>,
             Requires<[IsBookE, IsVLE]>;

// e_crnand: Condition Register NAND (32-bit VLE)
def E_CRNAND : XForm_0<19, 225, (outs crbitrc:$crD),
                       (ins crbitrc:$crA, crbitrc:$crB),
                       "e_crnand $crD, $crA, $crB", IIC_IntGeneral, []>,
              Requires<[IsBookE, IsVLE]>;

// e_crnor: Condition Register NOR (32-bit VLE)
def E_CRNOR : XForm_0<19, 33, (outs crbitrc:$crD),
                      (ins crbitrc:$crA, crbitrc:$crB),
                      "e_crnor $crD, $crA, $crB", IIC_IntGeneral, []>,
             Requires<[IsBookE, IsVLE]>;

// e_cror: Condition Register OR (32-bit VLE)
def E_CROR : XForm_0<19, 449, (outs crbitrc:$crD),
                     (ins crbitrc:$crA, crbitrc:$crB),
                     "e_cror $crD, $crA, $crB", IIC_IntGeneral, []>,
            Requires<[IsBookE, IsVLE]>;

// e_crorc: Condition Register OR with Complement (32-bit VLE)
def E_CRORC : XForm_0<19, 417, (outs crbitrc:$crD),
                      (ins crbitrc:$crA, crbitrc:$crB),
                      "e_crorc $crD, $crA, $crB", IIC_IntGeneral, []>,
             Requires<[IsBookE, IsVLE]>;

// e_crxor: Condition Register XOR (32-bit VLE)
def E_CRXOR : XForm_0<19, 193, (outs crbitrc:$crD),
                      (ins crbitrc:$crA, crbitrc:$crB),
                      "e_crxor $crD, $crA, $crB", IIC_IntGeneral, []>,
             Requires<[IsBookE, IsVLE]>;

//--- Load Instructions ---

// e_lbz: Load Byte & Zero (32-bit VLE)
def E_LBZ : DForm_1<34, (outs gprc:$rD), (ins memri:$src),
                    "e_lbz $rD, $src", IIC_LdStLoad,
                    [(set i32:$rD, (zextloadi8 iaddr:$src))]>
           Requires<[IsBookE, IsVLE]>;

// e_lbzu: Load Byte & Zero with Update (32-bit VLE)
def E_LBZU : DForm_1<35, (outs gprc:$rD, ptr_rc_nor0:$ea_result), (ins memri:$addr),
                     "e_lbzu $rD, $addr", IIC_LdStLoadUpd, []>,
            Requires<[IsBookE, IsVLE]>, RegConstraint<"$addr.reg = $ea_result">;

// e_lha: Load Halfword Algebraic (32-bit VLE)
def E_LHA : DForm_1<42, (outs gprc:$rD), (ins memri:$src),
                     "e_lha $rD, $src", IIC_LdStLHA,
                     [(set i32:$rD, (sextloadi16 iaddr:$src))]>
            Requires<[IsBookE, IsVLE]>;

// e_lhau: Load Halfword Algebraic with Update (32-bit VLE)
def E_LHAU : DForm_1<43, (outs gprc:$rD, ptr_rc_nor0:$ea_result), (ins memri:$addr),
                     "e_lhau $rD, $addr", IIC_LdStLHAU, []>,
            Requires<[IsBookE, IsVLE]>, RegConstraint<"$addr.reg = $ea_result">;

// e_lhz: Load Halfword and Zero (32-bit VLE)
def E_LHZ : DForm_1<40, (outs gprc:$rD), (ins memri:$src),
                    "e_lhz $rD, $src", IIC_LdStLoad,
                    [(set i32:$rD, (zextloadi16 iaddr:$src))]>
           Requires<[IsBookE, IsVLE]>;

// e_lhzu: Load Halfword and Zero with Update (32-bit VLE)
def E_LHZU : DForm_1<41, (outs gprc:$rD, ptr_rc_nor0:$ea_result), (ins memri:$addr),
                     "e_lhzu $rD, $addr", IIC_LdStLoadUpd, []>,
            Requires<[IsBookE, IsVLE]>, RegConstraint<"$addr.reg = $ea_result">;

// e_lwz: Load Word and Zero (32-bit VLE)
def E_LWZ : DForm_1<32, (outs gprc:$rD), (ins memri:$src),
                    "e_lwz $rD, $src", IIC_LdStLoad,
                    [(set i32:$rD, (load iaddr:$src))]>
           Requires<[IsBookE, IsVLE]>;

// e_lwzu: Load Word and Zero with Update (32-bit VLE)
def E_LWZU : DForm_1<33, (outs gprc:$rD, ptr_rc_nor0:$ea_result), (ins memri:$addr),
                     "e_lwzu $rD, $addr", IIC_LdStLoadUpd, []>,
            Requires<[IsBookE, IsVLE]>, RegConstraint<"$addr.reg = $ea_result">;

// e_li: Load Immediate (32-bit VLE)
let isReMaterializable = 1, isAsCheapAsAMove = 1, isMoveImm = 1 in
def E_LI : DForm_2_r0<14, (outs gprc:$rD), (ins s16imm:$imm),
                      "e_li $rD, $imm", IIC_IntSimple,
                      [(set i32:$rD, imm32SExt16:$imm)]>
          Requires<[IsBookE, IsVLE]>;

// e_lis: Load Immediate Shifted (32-bit VLE)
let isReMaterializable = 1, isAsCheapAsAMove = 1, isMoveImm = 1 in
def E_LIS : DForm_2_r0<15, (outs gprc:$rD), (ins s17imm:$imm),
                       "e_lis $rD, $imm", IIC_IntSimple,
                       [(set i32:$rD, imm16ShiftedSExt:$imm)]>
           Requires<[IsBookE, IsVLE]>;

// e_lmw: Load Multiple Word (32-bit VLE)
def E_LMW : DForm_1<46, (outs), (ins gprc:$rD, memri:$src),
                    "e_lmw $rD, $src", IIC_LdStLoad, []>,
           Requires<[IsBookE, IsVLE]>, mayLoad<1>, hasSideEffects<1>;

//--- Store Instructions ---

// e_stb: Store Byte (32-bit VLE)
def E_STB : DForm_1<38, (outs), (ins gprc:$rS, memri:$dst),
                    "e_stb $rS, $dst", IIC_LdStStore,
                    [(store (truncstorei8 gprc:$rS), iaddr:$dst)]>
           Requires<[IsBookE, IsVLE]>;

// e_stbu: Store Byte with Update (32-bit VLE)
def E_STBU : DForm_1<39, (outs ptr_rc_nor0:$ea_res), (ins gprc:$rS, memri:$dst),
                     "e_stbu $rS, $dst", IIC_LdStStoreUpd, []>,
            Requires<[IsBookE, IsVLE]>, RegConstraint<"$dst.reg = $ea_res">;

// e_sth: Store Halfword (32-bit VLE)
def E_STH : DForm_1<44, (outs), (ins gprc:$rS, memri:$dst),
                    "e_sth $rS, $dst", IIC_LdStStore,
                    [(store (truncstorei16 gprc:$rS), iaddr:$dst)]>
           Requires<[IsBookE, IsVLE]>;

// e_sthu: Store Halfword with Update (32-bit VLE)
def E_STHU : DForm_1<45, (outs ptr_rc_nor0:$ea_res), (ins gprc:$rS, memri:$dst),
                     "e_sthu $rS, $dst", IIC_LdStStoreUpd, []>,
            Requires<[IsBookE, IsVLE]>, RegConstraint<"$dst.reg = $ea_res">;

// e_stw: Store Word (32-bit VLE)
def E_STW : DForm_1<36, (outs), (ins gprc:$rS, memri:$dst),
                    "e_stw $rS, $dst", IIC_LdStStore,
                    [(store gprc:$rS, iaddr:$dst)]>
           Requires<[IsBookE, IsVLE]>;

// e_stwu: Store Word with Update (32-bit VLE)
def E_STWU : DForm_1<37, (outs ptr_rc_nor0:$ea_res), (ins gprc:$rS, memri:$dst),
                     "e_stwu $rS, $dst", IIC_LdStStoreUpd, []>,
            Requires<[IsBookE, IsVLE]>, RegConstraint<"$dst.reg = $ea_res">;

// e_stmw: Store Multiple Word (32-bit VLE)
def E_STMW : DForm_1<47, (outs), (ins gprc:$rS, memri:$dst),
                     "e_stmw $rS, $dst", IIC_LdStStore, []>,
            Requires<[IsBookE, IsVLE]>, mayStore<1>, hasSideEffects<1>;

//--- Rotate/Mask Instructions ---

// e_rlw: Rotate Left Word (32-bit VLE)
def E_RLW : XForm_1<21, 0, (outs gprc:$rD), (ins gprc:$rS, gprc:$rB, u5imm:$MB, u5imm:$ME),
                    "e_rlw $rD, $rS, $rB, $MB, $ME", IIC_IntGeneral, []>,
           Requires<[IsBookE, IsVLE]>;

// e_rlw.: Rotate Left Word and record CR (32-bit VLE)
let Defs = [CR0] in
def E_RLW_rec : XForm_1<21, 0, (outs gprc:$rD), (ins gprc:$rS, gprc:$rB, u5imm:$MB, u5imm:$ME),
                        "e_rlw. $rD, $rS, $rB, $MB, $ME", IIC_IntGeneral, []>,
               Requires<[IsBookE, IsVLE]>, isRecordForm;

// e_rlwi: Rotate Left Word Immediate (32-bit VLE)
def E_RLWI : XForm_1<21, 0, (outs gprc:$rD), (ins gprc:$rS, u5imm:$SH, u5imm:$MB, u5imm:$ME),
                     "e_rlwi $rD, $rS, $SH, $MB, $ME", IIC_IntGeneral, []>,
            Requires<[IsBookE, IsVLE]>;

// e_rlwi.: Rotate Left Word Immediate and record CR (32-bit VLE)
let Defs = [CR0] in
def E_RLWI_rec : XForm_1<21, 0, (outs gprc:$rD), (ins gprc:$rS, u5imm:$SH, u5imm:$MB, u5imm:$ME),
                         "e_rlwi. $rD, $rS, $SH, $MB, $ME", IIC_IntGeneral, []>,
                Requires<[IsBookE, IsVLE]>, isRecordForm;

// e_rlwimi: Rotate Left Word Immediate then Mask Insert (32-bit VLE)
def E_RLWIMI : XForm_1<20, 0, (outs gprc:$rD), (ins gprc:$rS, u5imm:$SH, u5imm:$MB, u5imm:$ME),
                       "e_rlwimi $rD, $rS, $SH, $MB, $ME", IIC_IntGeneral, []>,
              Requires<[IsBookE, IsVLE]>;

// e_rlwinm: Rotate Left Word Immediate then AND with Mask (32-bit VLE)
def E_RLWINM : XForm_1<21, 0, (outs gprc:$rD), (ins gprc:$rS, u5imm:$SH, u5imm:$MB, u5imm:$ME),
                       "e_rlwinm $rD, $rS, $SH, $MB, $ME", IIC_IntGeneral, []>,
              Requires<[IsBookE, IsVLE]>;

//--- Shift Instructions ---

// e_slwi: Shift Left Word Immediate (32-bit VLE)
def E_SLWI : XForm_1<31, 24, (outs gprc:$rD), (ins gprc:$rS, u5imm:$sh),
                     "e_slwi $rD, $rS, $sh", IIC_IntGeneral,
                     [(set i32:$rD, (shl i32:$rS, u5imm:$sh))]>
            Requires<[IsBookE, IsVLE]>;

// e_slwi.: Shift Left Word Immediate and record CR (32-bit VLE)
let Defs = [CR0] in
def E_SLWI_rec : XForm_1<31, 24, (outs gprc:$rD), (ins gprc:$rS, u5imm:$sh),
                          "e_slwi. $rD, $rS, $sh", IIC_IntGeneral, []>,
                Requires<[IsBookE, IsVLE]>, isRecordForm;

// e_srwi: Shift Right Word Immediate (32-bit VLE)
def E_SRWI : XForm_1<31, 536, (outs gprc:$rD), (ins gprc:$rS, u5imm:$sh),
                     "e_srwi $rD, $rS, $sh", IIC_IntGeneral,
                     [(set i32:$rD, (srl i32:$rS, u5imm:$sh))]>
            Requires<[IsBookE, IsVLE]>;

// e_srwi.: Shift Right Word Immediate and record CR (32-bit VLE)
let Defs = [CR0] in
def E_SRWI_rec : XForm_1<31, 536, (outs gprc:$rD), (ins gprc:$rS, u5imm:$sh),
                          "e_srwi. $rD, $rS, $sh", IIC_IntGeneral, []>,
                Requires<[IsBookE, IsVLE]>, isRecordForm;

//--- Multiply Instructions ---

// e_mulli: Multiply Immediate (32-bit VLE)
def E_MULLI : DForm_2<7, (outs gprc:$rD), (ins gprc:$rA, s16imm:$imm),
                      "e_mulli $rD, $rA, $imm", IIC_IntMulLI,
                      [(set i32:$rD, (mul i32:$rA, imm32SExt16:$imm))]>
             Requires<[IsBookE, IsVLE]>;

// e_mull2i: Multiply (2 operand) Immediate (32-bit VLE)
def E_MULL2I : DForm_2<7, (outs GPRC_VLE_R0_R7:$rD),
                       (ins GPRC_VLE_R0_R7:$rA, s6imm:$imm),
                       "e_mull2i $rD, $rA, $imm", IIC_IntMulLI,
                       [(set i32:$rD, (mul i32:$rA, s6imm_pred:$imm))]>
              Requires<[IsBookE, IsVLE]>;

//--- Other Instructions ---

// e_mcrf: Move Condition Register Field (32-bit VLE)
def E_MCRF : XForm_0<19, 0, (outs crbitrc:$crD), (ins crbitrc:$crS),
                     "e_mcrf $crD, $crS", IIC_IntGeneral, []>,
            Requires<[IsBookE, IsVLE]>;

