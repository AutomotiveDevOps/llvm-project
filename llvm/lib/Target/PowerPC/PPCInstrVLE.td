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
  : I<0, OOL, IOL, asmstr, itin>, Requires<[IsBookE, IsVLE]> {
  let Size = 2;  // 16-bit instructions
  let Pattern = pattern;
  let Inst{0-15} = encoding;
}

// VLE 32-bit instruction format placeholder class
// 32-bit VLE instructions (E_* prefix) typically reuse Book E opcodes
class VLE32Form<bits<6> opcode, dag OOL, dag IOL, string asmstr,
                InstrItinClass itin, list<dag> pattern>
  : I<opcode, OOL, IOL, asmstr, itin>, Requires<[IsBookE, IsVLE]> {
  let Pattern = pattern;
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
let Defs = [CR0] in
def SE_SUBF : VLE32Form<31, (outs GPRC_VLE_R0_R7:$rD),
                        (ins GPRC_VLE_R0_R7:$rA, GPRC_VLE_R0_R7:$rB),
                        "se_subf $rD, $rA, $rB", IIC_IntSimple,
                        [(set i32:$rD, (sub i32:$rB, i32:$rA))]>;
// se_subi: Subtract Immediate (16-bit)
// Constraints: R0-R7 registers, s6imm immediate (-32 to 31)
let Defs = [CR0] in
def SE_B : IForm<18, 0, 0, (outs), (ins directbrtarget:$dst),
                 "se_b $dst", IIC_BrB,
                 [(br bb:$dst)]>, Requires<[IsBookE, IsVLE]>;

// se_bc: Branch Conditional (16-bit)
let Defs = [CR0] in
def SE_BLRL : XForm_0<19, 16, (outs gprc:$lr), (ins), "se_blrl", IIC_BrB, []>,
             Requires<[IsBookE, IsVLE]>;

// se_bctr: Branch to Count Register (16-bit)
let Uses = [CTR] in
let Defs = [CR0] in
def SE_BGENI : VLE32Form<31, (outs GPRC_VLE_R0_R7:$rD),
                         (ins GPRC_VLE_R0_R7:$rS, u5imm:$sh),
                         "se_bgeni $rD, $rS, $sh", IIC_IntGeneral, []>;
// se_bmaski: Bit Mask Generate Immediate (16-bit)
// Constraints: R0-R7 registers, u5imm bit position
let Defs = [CR0] in
def SE_CMP : XForm_1<31, 0, (outs crbitrc:$crD), 
                     (ins GPRC_VLE_R0_R7:$rA, GPRC_VLE_R0_R7:$rB),
                     "se_cmp $crD, $rA, $rB", IIC_IntGeneral, []>,
            Requires<[IsBookE, IsVLE]>;

// se_cmpi: Compare Immediate (16-bit)
// Constraints: R0-R7 registers, s6imm immediate (-32 to 31)
let Defs = [CR0] in
def SE_CMPH : XForm_1<31, 64, (outs crbitrc:$crD),
                      (ins GPRC_VLE_R0_R7:$rA, GPRC_VLE_R0_R7:$rB),
                      "se_cmph $crD, $rA, $rB", IIC_IntGeneral, []>,
             Requires<[IsBookE, IsVLE]>;

// se_cmphl: Compare Halfword Logical (16-bit)
let Defs = [CR0] in
def SE_SRW : XForm_1<31, 536, (outs GPRC_VLE_R0_R7:$rD),
                     (ins GPRC_VLE_R0_R7:$rS, GPRC_VLE_R0_R7:$rB),
                     "se_srw $rD, $rS, $rB", IIC_IntGeneral,
                     [(set i32:$rD, (srl i32:$rS, i32:$rB))]>, Requires<[IsBookE, IsVLE]>;
            

// se_srwi: Shift Right Word Immediate (16-bit)
// Constraints: R0-R7 registers, u5imm shift amount (0 to 31)
let Defs = [CR0] in
def SE_MR : XForm_1<31, 444, (outs GPRC_VLE_R0_R7:$rD),
                    (ins GPRC_VLE_R0_R7:$rS),
                    "se_mr $rD, $rS", IIC_IntSimple,
                    [(set i32:$rD, i32:$rS)]>, Requires<[IsBookE, IsVLE]>;
           

// se_mflr: Move From Link Register (16-bit)
let Uses = [LR] in
let Defs = [CR0] in
def SE_MTCTR : XForm_0<31, 467, (outs), (ins GPRC_VLE_R0_R7:$rS),
                       "se_mtctr $rS", IIC_SprMTSPR, []>,
              Requires<[IsBookE, IsVLE]>;

// se_mfar: Move from Alternate Register (16-bit)
let Defs = [CR0] in
def SE_AND : XForm_1<31, 28, (outs GPRC_VLE_R0_R7:$rD),
                     (ins GPRC_VLE_R0_R7:$rA, GPRC_VLE_R0_R7:$rB),
                     "se_and $rD, $rA, $rB", IIC_IntSimple,
                     [(set i32:$rD, (and i32:$rA, i32:$rB))]>, Requires<[IsBookE, IsVLE]>;

// se_and.: AND and Record (16-bit)
let Defs = [CR0] in
def SE_OR : XForm_1<31, 444, (outs GPRC_VLE_R0_R7:$rD),
                    (ins GPRC_VLE_R0_R7:$rA, GPRC_VLE_R0_R7:$rB),
                    "se_or $rD, $rA, $rB", IIC_IntSimple,
                    [(set i32:$rD, (or i32:$rA, i32:$rB))]>, Requires<[IsBookE, IsVLE]>;
           

// se_not: NOT (16-bit)
let Defs = [CR0] in
def SE_EXTSH : XForm_1<31, 922, (outs GPRC_VLE_R0_R7:$rD),
                       (ins GPRC_VLE_R0_R7:$rS),
                       "se_extsh $rD, $rS", IIC_IntGeneral,
                       [(set i32:$rD, (sext_inreg i32:$rS, i16))]>, Requires<[IsBookE, IsVLE]>;

// se_extzb: Extend with Zeros Byte (16-bit)
let Defs = [CR0] in
def SE_RFCI : XForm_0<19, 51, (outs), (ins), "se_rfci", IIC_SprRFI, []>,
              Requires<[IsBookE, IsVLE]>;

// se_sc: System Call (16-bit)
def SE_SC : SCForm<17, 0, 0, (outs), (ins u16imm:$imm),
                   "se_sc", IIC_SprRFI,
                   []>, Requires<[IsBookE, IsVLE]>;

// e_sc: System Call (32-bit VLE)
let Defs = [CR0] in
def E_SC : SCForm<17, 1, 0, (outs), (ins i32imm:$LEV),
                  "e_sc $LEV", IIC_SprRFI, []>, Requires<[IsBookE, IsVLE]>;

//===----------------------------------------------------------------------===//
// E_ Prefix Instructions (32-bit VLE)
//===----------------------------------------------------------------------===//

// e_rfi: Return From Interrupt (32-bit VLE)
def E_RFI : XForm_0<19, 50, (outs), (ins), "e_rfi", IIC_SprRFI, []>,
            Requires<[IsBookE, IsVLE]>;

//--- Arithmetic Instructions ---

// e_add2i.: Add (2 operand) Immediate and Record CR (32-bit VLE)
def E_ADD2I_rec : DForm_2<14, (outs GPRC_VLE_R0_R7:$rD),
                          (ins GPRC_VLE_R0_R7:$rA, s6imm:$imm),
                          "e_add2i. $rD, $rA, $imm", IIC_IntSimple, []>,
                 Requires<[IsBookE, IsVLE]>, isRecordForm;

// e_add2is: Add (2 operand) Immediate Shifted (32-bit VLE)
def E_ADD2IS : DForm_2<14, (outs GPRC_VLE_R0_R7:$rD),
                       (ins GPRC_VLE_R0_R7:$rA, s6imm:$imm),
                       "e_add2is $rD, $rA, $imm", IIC_IntSimple,
                       [(set i32:$rD, (add i32:$rA, (shl i32:$imm, 1)))]>, Requires<[IsBookE, IsVLE]>;

// e_subfic: Subtract From Immediate Carrying (32-bit VLE)
let Defs = [CARRY] in
def E_SUBFIC : DForm_2<8, (outs gprc:$rD), (ins gprc:$rA, s16imm:$imm),
                       "e_subfic $rD, $rA, $imm", IIC_IntGeneral,
                       [(set i32:$rD, (subc imm32SExt16:$imm, i32:$rA))]>, Requires<[IsBookE, IsVLE]>;

// e_subfic.: Subtract From Immediate Carrying and Record (32-bit VLE)
let Defs = [CARRY, CR0] in
def E_SUBFIC_rec : DForm_2<8, (outs gprc:$rD), (ins gprc:$rA, s16imm:$imm),
                            "e_subfic. $rD, $rA, $imm", IIC_IntGeneral, []>,
                  Requires<[IsBookE, IsVLE]>, isRecordForm;

//--- Logical Instructions ---

// e_andi: AND Immediate (32-bit VLE)
def E_ANDI : DForm_4<28, (outs gprc:$dst), (ins gprc:$src1, u16imm:$src2),
                     "e_andi $dst, $src1, $src2", IIC_IntGeneral,
                     [(set i32:$dst, (and i32:$src1, immZExt16:$src2))]>, Requires<[IsBookE, IsVLE]>;

// e_andi.: AND Immediate and Record (32-bit VLE)
let Defs = [CR0] in
def E_ORI_rec : DForm_4<24, (outs gprc:$dst), (ins gprc:$src1, u16imm:$src2),
                        "e_ori. $dst, $src1, $src2", IIC_IntGeneral, []>,
               Requires<[IsBookE, IsVLE]>, isRecordForm;

// e_or2i: OR (2 operand) Immediate (32-bit VLE)
def E_OR2I : DForm_4<24, (outs GPRC_VLE_R0_R7:$dst),
                     (ins GPRC_VLE_R0_R7:$src1, u5imm:$src2),
                     "e_or2i $dst, $src1, $src2", IIC_IntGeneral,
                     [(set i32:$dst, (or i32:$src1, u5imm_vle_pred:$src2))]>, Requires<[IsBookE, IsVLE]>;

// e_or2i.: OR (2 operand) Immediate & record CR (32-bit VLE)
let Defs = [CR0] in
def E_CMPI : DForm_5<11, (outs crbitrc:$crD), (ins gprc:$rA, s16imm:$imm),
                     "e_cmpi $crD, $rA, $imm", IIC_IntGeneral>,
            Requires<[IsBookE, IsVLE]>;

// e_cmpli: Compare Logical Immediate (32-bit VLE)
let Defs = [CR0] in
def E_CMPH : XForm_1<31, 64, (outs crbitrc:$crD),
                     (ins gprc:$rA, gprc:$rB),
                     "e_cmph $crD, $rA, $rB", IIC_IntGeneral, []>,
            Requires<[IsBookE, IsVLE]>;

// e_cmph16i: Compare Halfword Immediate (32-bit VLE)
let Defs = [CR0] in
def E_RLW_rec : XForm_1<21, 0, (outs gprc:$rD), (ins gprc:$rS, gprc:$rB, u5imm:$MB, u5imm:$ME),
                        "e_rlw. $rD, $rS, $rB, $MB, $ME", IIC_IntGeneral, []>,
               Requires<[IsBookE, IsVLE]>, isRecordForm;

// e_rlwi: Rotate Left Word Immediate (32-bit VLE)
let Defs = [CR0] in
def E_SLWI_rec : XForm_1<31, 24, (outs gprc:$rD), (ins gprc:$rS, u5imm:$sh),
                          "e_slwi. $rD, $rS, $sh", IIC_IntGeneral, []>,
                Requires<[IsBookE, IsVLE]>, isRecordForm;

// e_srwi: Shift Right Word Immediate (32-bit VLE)
let Defs = [CR0] in
def E_SRWI : XForm_1<31, 536, (outs gprc:$rD), (ins gprc:$rS, u5imm:$sh),
                     "e_srwi $rD, $rS, $sh", IIC_IntGeneral,
                     [(set i32:$rD, (srl i32:$rS, u5imm:$sh))]>, Requires<[IsBookE, IsVLE]>;

// e_srwi.: Shift Right Word Immediate and record CR (32-bit VLE)
let Defs = [CR0] in
def E_SRWI_rec : XForm_1<31, 536, (outs gprc:$rD), (ins gprc:$rS, u5imm:$sh),
                          "e_srwi. $rD, $rS, $sh", IIC_IntGeneral, []>,
                Requires<[IsBookE, IsVLE]>, isRecordForm;
