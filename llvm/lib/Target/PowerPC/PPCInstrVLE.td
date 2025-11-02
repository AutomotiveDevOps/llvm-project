//===-- PPCInstrVLE.td - The PowerPC VLE Extension -*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file describes the Variable Length Encoding (VLE) extension to
// the PowerPC instruction set for e200 cores.
//
// VLE instructions can be either 16-bit or 32-bit, providing code size
// optimization for embedded systems. Typical code size reduction: 20-30%
//
// Reference: 
// - PowerPC Book E Enhanced Architecture (VLE Appendix)
// - VLE Programming Interface Manual (VLEPIM)
// - e200 Core Reference Manuals
//
// Implementation Status:
// - Instruction format definitions: IN PROGRESS
// - 16-bit VLE instructions: IN PROGRESS
// - 32-bit VLE instructions (e_ prefix): TODO
// - Instruction encoding/decoding: TODO (needs C++ support)
// - Assembler/disassembler: TODO (needs C++ support)
// - Instruction selection optimization: TODO
//
//===----------------------------------------------------------------------===//

include "PPCRegisterInfo.td"
include "PPCInstrFormats.td"

//===----------------------------------------------------------------------===//
// VLE Operand Definitions
//===----------------------------------------------------------------------===//

// 6-bit signed immediate for VLE instructions
def PPCS6ImmAsmOperand : AsmOperandClass {
  let Name = "S6Imm"; let PredicateMethod = "isS6Imm";
  let RenderMethod = "addImmOperands";
}
def s6imm : Operand<i32> {
  let PrintMethod = "printS6ImmOperand";
  let ParserMatchClass = PPCS6ImmAsmOperand;
  let DecoderMethod = "decodeSImmOperand<6>";
}

// 5-bit branch displacement (word-aligned, sign-extended, shifted by 1)
// Note: VLE branches use word-aligned offsets, so the immediate is shifted
def PPCBD5AsmOperand : AsmOperandClass {
  let Name = "BD5"; let PredicateMethod = "isBD5";
  let RenderMethod = "addBranchTargetOperands";
}
def bd5 : Operand<OtherVT> {
  let PrintMethod = "printBranchOperand";
  let ParserMatchClass = PPCBD5AsmOperand;
  let OperandType = "OPERAND_PCREL";
}

//===----------------------------------------------------------------------===//
// VLE Instruction Format Definitions
//===----------------------------------------------------------------------===//

// VLE 16-bit instruction base class
// VLE instructions use different encoding schemes than standard PowerPC
// to achieve 16-bit form. Primary opcode is in bits 0-5, with extended
// opcodes and operands packed into remaining bits.
class VLEInst16<dag outs, dag ins, string opcodestr, string argstr,
                list<dag> pattern, InstrItinClass itin>
    : Instruction {
  field bits<16> Inst;
  field bits<16> SoftFail = 0;
  let Size = 2;  // 16-bit instruction

  let Namespace = "PPC";
  let OutOperandList = outs;
  let InOperandList = ins;
  let AsmString = opcodestr # "\t" # argstr;
  let Pattern = pattern;
  let Itinerary = itin;

  // VLE flag - indicates this is a VLE instruction
  // This will need C++ support to properly track and handle
}

// SE_FORM_1: se_addi, se_subi, se_li, se_cmpi
// Format: 5-bit opcode | rD/rA | 6-bit immediate
// Opcode field in bits 0-4, register in bits 5-9, immediate in bits 10-15
class VLE_SE_FORM1<bits<5> opcode, dag outs, dag ins, string opcodestr,
                   string argstr, list<dag> pattern, InstrItinClass itin>
    : VLEInst16<outs, ins, opcodestr, argstr, pattern, itin> {
  bits<5> rD;
  bits<6> imm6;

  let Inst{0-4} = opcode;
  let Inst{5-9} = rD;
  let Inst{10-15} = imm6;
}

// SE_FORM_2: se_mr, se_cmp
// Format: 5-bit opcode | rD | rA | rB
// Opcode in bits 0-4, rD in 5-7, rA in 8-10, rB in 11-13, reserved 14-15
class VLE_SE_FORM2<bits<5> opcode, dag outs, dag ins, string opcodestr,
                   string argstr, list<dag> pattern, InstrItinClass itin>
    : VLEInst16<outs, ins, opcodestr, argstr, pattern, itin> {
  bits<3> rD;
  bits<3> rA;
  bits<3> rB;

  let Inst{0-4} = opcode;
  let Inst{5-7} = rD;
  let Inst{8-10} = rA;
  let Inst{11-13} = rB;
  let Inst{14-15} = 0; // Reserved
}

// SE_FORM_4: se_lwz, se_stw
// Format: 5-bit opcode | rD/rS | rA | 5-bit offset
class VLE_SE_FORM4<bits<5> opcode, dag outs, dag ins, string opcodestr,
                   string argstr, list<dag> pattern, InstrItinClass itin>
    : VLEInst16<outs, ins, opcodestr, argstr, pattern, itin> {
  bits<3> rD;
  bits<3> rA;
  bits<5> D5;

  let Inst{0-4} = opcode;
  let Inst{5-7} = rD;
  let Inst{8-10} = rA;
  let Inst{11-15} = D5;
}

//===----------------------------------------------------------------------===//
// VLE Instruction Definitions - 16-bit Short Encoding (se_ prefix)
//===----------------------------------------------------------------------===//
// Note: Actual VLE opcode values need to be verified from VLEPIM
// These are placeholder opcodes based on typical VLE encoding patterns

// se_addi - Add Immediate (16-bit)
// Adds 6-bit sign-extended immediate to rA (or 0 if rA=0) and stores in rD
def SE_ADDI : VLE_SE_FORM1<0b10000,
  (outs gprc:$rD),
  (ins gprc:$rA, s6imm:$imm),
  "se_addi", "$rD, $rA, $imm",
  [(set i32:$rD, (add i32:$rA, i32:$imm))],
  IIC_IntSimple>, Requires<[HasVLE, IsE200]>;

// se_subi - Subtract Immediate (16-bit)
def SE_SUBI : VLE_SE_FORM1<0b10001,
  (outs gprc:$rD),
  (ins gprc:$rA, s6imm:$imm),
  "se_subi", "$rD, $rA, $imm",
  [(set i32:$rD, (sub i32:$rA, i32:$imm))],
  IIC_IntSimple>, Requires<[HasVLE, IsE200]>;

// se_li - Load Immediate (16-bit)
// Loads 6-bit sign-extended immediate into rD
def SE_LI : VLE_SE_FORM1<0b10010,
  (outs gprc:$rD),
  (ins s6imm:$imm),
  "se_li", "$rD, $imm",
  [(set i32:$rD, imm:$imm)],
  IIC_IntSimple>, Requires<[HasVLE, IsE200]>;

// se_mr - Move Register (16-bit)
// Moves rA to rD (uses rB=0 internally)
def SE_MR : VLE_SE_FORM2<0b10011,
  (outs gprc:$rD),
  (ins gprc:$rA),
  "se_mr", "$rD, $rA",
  [(set i32:$rD, i32:$rA)],
  IIC_IntSimple>, Requires<[HasVLE, IsE200]> {
  let rB = 0;  // Must be 0 for se_mr
}

// se_cmpi - Compare Immediate (16-bit)
def SE_CMPI : VLE_SE_FORM1<0b10100,
  (outs), (ins gprc:$rA, s6imm:$imm),
  "se_cmpi", "$rA, $imm",
  [(PPCcmpi i32:$rA, i32:$imm)],
  IIC_IntCompare>, Requires<[HasVLE, IsE200]>;

// se_cmp - Compare Register (16-bit)
def SE_CMP : VLE_SE_FORM2<0b10101,
  (outs), (ins gprc:$rA, gprc:$rB),
  "se_cmp", "$rA, $rB",
  [(PPCcmp i32:$rA, i32:$rB)],
  IIC_IntCompare>, Requires<[HasVLE, IsE200]>;

// se_lwz - Load Word and Zero (16-bit)
def SE_LWZ : VLE_SE_FORM4<0b11000,
  (outs gprc:$rD),
  (ins gprc:$rA, u5imm:$D5),
  "se_lwz", "$rD, $D5($rA)",
  [(set i32:$rD, (load (add i32:$rA, i32:$D5)))],
  IIC_LdStLoad>, Requires<[HasVLE, IsE200]>;

// se_stw - Store Word (16-bit)
def SE_STW : VLE_SE_FORM4<0b11001,
  (outs), (ins gprc:$rS, gprc:$rA, u5imm:$D5),
  "se_stw", "$rS, $D5($rA)",
  [(store i32:$rS, (add i32:$rA, i32:$D5))],
  IIC_LdStStore>, Requires<[HasVLE, IsE200]>;

//===----------------------------------------------------------------------===//
// VLE Instruction Selection Patterns
//===----------------------------------------------------------------------===//
// Note: These patterns will prefer VLE instructions when immediates fit
// in the smaller ranges. Instruction selection will need additional C++
// support to fully optimize for code size.

// TODO: Add predicates for checking immediate ranges fit in 6 bits
// TODO: Add more VLE instruction patterns
// TODO: Implement instruction selection optimization passes
// TODO: Add 32-bit VLE instructions (e_ prefix)
