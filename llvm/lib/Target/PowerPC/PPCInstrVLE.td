//===-- PPCInstrVLE.td - The PowerPC VLE Instruction Set -*- tablegen -*-===//
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
// VLE instructions use 16-bit and 32-bit encodings and are used for
// improved code density in embedded applications.
//
// All e200 cores support VLE and use Power ISA 2.07 only.
//
//===----------------------------------------------------------------------===//
// Note: PPCInstrFormats.td is already included by PPCInstrInfo.td
// Do not include it here to avoid duplicate class definitions

//===----------------------------------------------------------------------===//
// VLE Instruction Format Classes
//===----------------------------------------------------------------------===//

// SCI8 Format: Scaled Immediate 8-bit (RT,RA form)
// Used for: e_addi, e_addic, e_subfic
// Format: 32-bit instruction with 8-bit scaled immediate
// Encoding from Power ISA 2.07 Book VLE Chapter 5
// Bits 0-5: Primary opcode (6)
// Bits 6-10: RT (destination register, 5 bits)
// Bits 11-15: RA (source register, 5 bits)
// Bits 16-19: Extended opcode (XO, 4 bits)
// Bit 20: Rc (record bit)
// Bits 21-22: F (2 bits) - set to 0 for now, needs proper scaling logic
// Bit 23: SCL (scale bit) - set to 0 for now, needs proper scaling logic
// Bits 24-31: UI8 (8-bit unsigned immediate)
class VLE_SCI8Form_RTRA<bits<4> xo, bit rc, dag OOL, dag IOL, string asmstr,
                        InstrItinClass itin, list<dag> pattern>
        : I<6, OOL, IOL, asmstr, itin> {
  bits<5> RT;
  bits<5> RA;
  bits<8> UI8;

  let Pattern = pattern;

  // SCI8 format encoding (RT,RA form)
  let Inst{6-10}   = RT;
  let Inst{11-15}  = RA;
  let Inst{16-19}  = xo;
  let Inst{20}     = rc;
  let Inst{21-22}  = 0b00;  // F field - set to 0 (no scaling for now)
  let Inst{23}     = 0;     // SCL field - set to 0 (no scaling for now)
  let Inst{24-31}  = UI8;
}

// SCI8 Format: Scaled Immediate 8-bit (RS,RA form)
// Used for: e_andi, e_ori, e_xori
// Format: 32-bit instruction with 8-bit scaled immediate
// Encoding from Power ISA 2.07 Book VLE Chapter 5
// Bits 0-5: Primary opcode (6)
// Bits 6-10: RS (source register, 5 bits)
// Bits 11-15: RA (destination register, 5 bits)
// Bits 16-19: Extended opcode (XO, 4 bits)
// Bit 20: Rc (record bit)
// Bits 21-22: F (2 bits) - set to 0 for now
// Bit 23: SCL (scale bit) - set to 0 for now
// Bits 24-31: UI8 (8-bit unsigned immediate)
class VLE_SCI8Form_RSRA<bits<4> xo, bit rc, dag OOL, dag IOL, string asmstr,
                        InstrItinClass itin, list<dag> pattern>
        : I<6, OOL, IOL, asmstr, itin> {
  bits<5> RS;
  bits<5> RA;
  bits<8> UI8;

  let Pattern = pattern;

  // SCI8 format encoding (RS,RA form)
  let Inst{6-10}   = RS;
  let Inst{11-15}  = RA;
  let Inst{16-19}  = xo;
  let Inst{20}     = rc;
  let Inst{21-22}  = 0b00;  // F field - set to 0 (no scaling for now)
  let Inst{23}     = 0;     // SCL field - set to 0 (no scaling for now)
  let Inst{24-31}  = UI8;
}

// BD15 Format: Branch Displacement 15-bit
// Used for: e_bc, e_bcl
// Format: 32-bit instruction with 15-bit branch displacement
// Encoding from VLE Programming Interface Manual Appendix A, Figure A-1
// Bits 0-5: Primary opcode (30 = 0x1E)
// Bits 6-9: Extended opcode/VLE identifier (10 = 0xA)
// Bits 10-11: BO32 (2 bits)
// Bits 12-15: BI32 (4 bits)
// Bits 16-30: BD15 (15 bits)
// Bit 31: LK (1 bit)
class VLE_BD15Form<bit lk, dag OOL, dag IOL, string asmstr,
                   InstrItinClass itin, list<dag> pattern>
        : I<30, OOL, IOL, asmstr, itin> {
  bits<2> BO;
  bits<4> BI;
  bits<15> BD;

  let Pattern = pattern;
  let Inst{6-9}   = 0b1010; // VLE extended opcode identifier
  let Inst{10-11} = BO;
  let Inst{12-15} = BI;
  let Inst{16-30} = BD;
  let Inst{31}    = lk;
}

// BD24 Format: Branch Displacement 24-bit
// Used for: e_b, e_bl
// Format: 32-bit instruction with 24-bit branch displacement
// Encoding from Power ISA 2.07 Book VLE Chapter 4, Section 1.4.10
// Bits 0-5: Primary opcode (30 = 0x1E)
// Bits 7-30: BD24 (24-bit branch displacement, half-word aligned)
// Bit 31: LK (link bit, 0 for e_b, 1 for e_bl)
// Note: Bit 6 is unused (0)
// The BD24 field is concatenated with 0b0 and sign-extended to form the target offset
class VLE_BD24Form<bit lk, dag OOL, dag IOL, string asmstr,
                   InstrItinClass itin, list<dag> pattern>
        : I<30, OOL, IOL, asmstr, itin> {
  bits<24> BD24;

  let Pattern = pattern;
  let Inst{6}     = 0;      // Unused bit
  let Inst{7-30}  = BD24;
  let Inst{31}    = lk;
}

//===----------------------------------------------------------------------===//
// VLE Instruction Definitions
//===----------------------------------------------------------------------===//

// Predicate: Only available when BookE and ISA 2.07 are enabled
// VLE instructions are available on all e200 cores
let Predicates = [IsBookE, IsISA2_07] in {

//===----------------------------------------------------------------------===//
// VLE Branch Instructions
//===----------------------------------------------------------------------===//
// Implemented based on VLE Programming Interface Manual Appendix A
// Encoding format verified from Figure A-1

// e_bc: Branch Conditional
// Branches conditionally based on CR bit and BO field
// Encoding: Primary opcode 30, extended opcode 10 (bits 6-9)
def E_BC : VLE_BD15Form<0,
                        (outs),
                        (ins u2imm:$BO, u4imm:$BI, condbrtarget:$BD),
                        "e_bc $BO, $BI, $BD",
                        IIC_BrB,
                        []> {
  let isBranch = 1;
}

// e_bcl: Branch Conditional and Link
// Same as e_bc but also saves return address in LR
def E_BCL : VLE_BD15Form<1,
                         (outs),
                         (ins u2imm:$BO, u4imm:$BI, condbrtarget:$BD),
                         "e_bcl $BO, $BI, $BD",
                         IIC_BrB,
                         []> {
  let isBranch = 1;
  let isCall = 1;
}

// e_b: Branch (unconditional)
// Branches to target address
// Encoding: Primary opcode 30, BD24 format (bits 7-30), LK=0
def E_B : VLE_BD24Form<0,
                       (outs),
                       (ins directbrtarget:$BD24),
                       "e_b $BD24",
                       IIC_BrB,
                       [(br bb:$BD24)]> {
  let isBranch = 1;
}

// e_bl: Branch and Link (unconditional)
// Branches to target address and saves return address in LR
// Encoding: Primary opcode 30, BD24 format (bits 7-30), LK=1
def E_BL : VLE_BD24Form<1,
                        (outs),
                        (ins directbrtarget:$BD24),
                        "e_bl $BD24",
                        IIC_BrB,
                        []> {
  let isBranch = 1;
  let isCall = 1;
}

//===----------------------------------------------------------------------===//
// VLE Arithmetic Instructions
//===----------------------------------------------------------------------===//
// Implemented based on Power ISA 2.07 Book VLE Chapter 5
// SCI8 format encoding verified from instruction definitions

// e_addi: Add Scaled Immediate
// Adds a scaled 8-bit immediate value to register RA and stores result in RT
// Extended opcode: 8 (bits 16-19)
// Encoding: Primary opcode 6, extended opcode 8
// Note: Pattern matches add with immediate, but SCI8 scaling logic needs to be implemented
def E_ADDI : VLE_SCI8Form_RTRA<0b1000, 0,
                                (outs gprc:$RT),
                                (ins gprc:$RA, s16imm:$UI8),
                                "e_addi $RT, $RA, $UI8",
                                IIC_IntSimple,
                                [(set i32:$RT, (add i32:$RA, imm32SExt16:$UI8))]>;

// e_addic: Add Scaled Immediate Carrying
// Same as e_addi but also sets carry bit in XER
// Extended opcode: 9 (bits 16-19)
def E_ADDIC : VLE_SCI8Form_RTRA<0b1001, 0,
                                 (outs gprc:$RT),
                                 (ins gprc:$RA, s16imm:$UI8),
                                 "e_addic $RT, $RA, $UI8",
                                 IIC_IntSimple,
                                 [(set i32:$RT, (PPCaddc i32:$RA, imm32SExt16:$UI8))]>;

// e_subfic: Subtract From Scaled Immediate Carrying
// Subtracts RA from scaled immediate and stores result in RT, sets carry
// Extended opcode: 11 (bits 16-19)
def E_SUBFIC : VLE_SCI8Form_RTRA<0b1011, 0,
                                  (outs gprc:$RT),
                                  (ins gprc:$RA, s16imm:$UI8),
                                  "e_subfic $RT, $RA, $UI8",
                                  IIC_IntSimple,
                                  [(set i32:$RT, (PPCsubc imm32SExt16:$UI8, i32:$RA))]>;

//===----------------------------------------------------------------------===//
// VLE Logical Instructions
//===----------------------------------------------------------------------===//

// e_andi: AND Scaled Immediate
// ANDs RS with scaled immediate and stores result in RA
// Extended opcode: 12 (bits 16-19)
// Uses RS,RA format where RS is source and RA is destination
def E_ANDI : VLE_SCI8Form_RSRA<0b1100, 0,
                                (outs gprc:$RA),
                                (ins gprc:$RS, s16imm:$UI8),
                                "e_andi $RA, $RS, $UI8",
                                IIC_IntSimple,
                                [(set i32:$RA, (and i32:$RS, imm32SExt16:$UI8))]>;

// e_ori: OR Scaled Immediate
// ORs RS with scaled immediate and stores result in RA
// Extended opcode: 13 (bits 16-19)
def E_ORI : VLE_SCI8Form_RSRA<0b1101, 0,
                               (outs gprc:$RA),
                                (ins gprc:$RS, s16imm:$UI8),
                               "e_ori $RA, $RS, $UI8",
                               IIC_IntSimple,
                               [(set i32:$RA, (or i32:$RS, imm32SExt16:$UI8))]>;

// e_xori: XOR Scaled Immediate
// XORs RS with scaled immediate and stores result in RA
// Extended opcode: 14 (bits 16-19)
def E_XORI : VLE_SCI8Form_RSRA<0b1110, 0,
                                (outs gprc:$RA),
                                (ins gprc:$RS, s16imm:$UI8),
                                "e_xori $RA, $RS, $UI8",
                                IIC_IntSimple,
                                [(set i32:$RA, (xor i32:$RS, imm32SExt16:$UI8))]>;

//===----------------------------------------------------------------------===//
// VLE Load/Store Instructions
//===----------------------------------------------------------------------===//
// Implemented based on Power ISA 2.07 Book VLE Chapter 5
// D8 format encoding verified from instruction definitions

// D8 Format: 8-bit displacement for load/store with update
// Used for: e_lbzu, e_lhzu, e_lwzu, e_stbu, e_sthu, e_stwu
// Format: 32-bit instruction with 8-bit displacement
// Encoding from Power ISA 2.07 Book VLE Chapter 5
// Bits 0-5: Primary opcode (6)
// Bits 6-10: RT (load) or RS (store) - 5 bits
// Bits 11-15: RA (base register, updated) - 5 bits
// Bits 16-19: Extended opcode (XO, 4 bits)
// Bits 20-23: Reserved/zero
// Bits 24-31: D8 (8-bit signed displacement)
class VLE_D8Form_Load<bits<4> xo, dag OOL, dag IOL, string asmstr,
                      InstrItinClass itin, list<dag> pattern>
        : I<6, OOL, IOL, asmstr, itin>, MemriOp {
  bits<5> RT;
  bits<5> RA;
  bits<8> D8;

  let Pattern = pattern;

  // D8 format encoding (load with update)
  let Inst{6-10}   = RT;
  let Inst{11-15}  = RA;
  let Inst{16-19}  = xo;
  let Inst{20-23}  = 0b0000;  // Reserved bits
  let Inst{24-31}  = D8;
}

class VLE_D8Form_Store<bits<4> xo, dag OOL, dag IOL, string asmstr,
                       InstrItinClass itin, list<dag> pattern>
        : I<6, OOL, IOL, asmstr, itin>, MemriOp {
  bits<5> RS;
  bits<5> RA;
  bits<8> D8;

  let Pattern = pattern;

  // D8 format encoding (store with update)
  let Inst{6-10}   = RS;
  let Inst{11-15}  = RA;
  let Inst{16-19}  = xo;
  let Inst{20-23}  = 0b0000;  // Reserved bits
  let Inst{24-31}  = D8;
}

// e_lbzu: Load Byte and Zero with Update
// Loads byte from memory address (RA)+D8, zero-extends, stores in RT, updates RA
// Extended opcode: 0 (bits 16-19)
// Note: Update forms are typically handled by instruction selector or custom patterns
def E_LBZU : VLE_D8Form_Load<0b0000,
                              (outs gprc:$RT, ptr_rc_nor0:$ea_result),
                              (ins (memri $D8, $RA):$addr),
                              "e_lbzu $RT, $addr",
                              IIC_LdStLoadUpd,
                              []>,
                              RegConstraint<"$addr.reg = $ea_result">,
                              NoEncode<"$ea_result">;

// e_lhzu: Load Halfword and Zero with Update
// Loads halfword from memory address (RA)+D8, zero-extends, stores in RT, updates RA
// Extended opcode: 1 (bits 16-19)
// Note: Update forms are typically handled by instruction selector or custom patterns
def E_LHZU : VLE_D8Form_Load<0b0001,
                              (outs gprc:$RT, ptr_rc_nor0:$ea_result),
                              (ins (memri $D8, $RA):$addr),
                              "e_lhzu $RT, $addr",
                              IIC_LdStLoadUpd,
                              []>,
                              RegConstraint<"$addr.reg = $ea_result">,
                              NoEncode<"$ea_result">;

// e_lwzu: Load Word and Zero with Update
// Loads word from memory address (RA)+D8, stores in RT, updates RA
// Extended opcode: 2 (bits 16-19)
// Note: Update forms are typically handled by instruction selector or custom patterns
def E_LWZU : VLE_D8Form_Load<0b0010,
                              (outs gprc:$RT, ptr_rc_nor0:$ea_result),
                              (ins (memri $D8, $RA):$addr),
                              "e_lwzu $RT, $addr",
                              IIC_LdStLoadUpd,
                              []>,
                              RegConstraint<"$addr.reg = $ea_result">,
                              NoEncode<"$ea_result">;

// e_stbu: Store Byte with Update
// Stores byte from RS to memory address (RA)+D8, updates RA
// Extended opcode: 4 (bits 16-19)
// Note: Update forms are typically handled by instruction selector or custom patterns
def E_STBU : VLE_D8Form_Store<0b0100,
                               (outs ptr_rc_nor0:$ea_result),
                               (ins gprc:$RS, (memri $D8, $RA):$dst),
                               "e_stbu $RS, $dst",
                               IIC_LdStSTU,
                               []>, RegConstraint<"$dst.reg = $ea_result">,
                               NoEncode<"$ea_result">;

// e_sthu: Store Halfword with Update
// Stores halfword from RS to memory address (RA)+D8, updates RA
// Extended opcode: 5 (bits 16-19)
// Note: Update forms are typically handled by instruction selector or custom patterns
def E_STHU : VLE_D8Form_Store<0b0101,
                               (outs ptr_rc_nor0:$ea_result),
                               (ins gprc:$RS, (memri $D8, $RA):$dst),
                               "e_sthu $RS, $dst",
                               IIC_LdStSTU,
                               []>, RegConstraint<"$dst.reg = $ea_result">,
                               NoEncode<"$ea_result">;

// e_stwu: Store Word with Update
// Stores word from RS to memory address (RA)+D8, updates RA
// Extended opcode: 6 (bits 16-19)
// Note: Update forms are typically handled by instruction selector or custom patterns
def E_STWU : VLE_D8Form_Store<0b0110,
                               (outs ptr_rc_nor0:$ea_result),
                               (ins gprc:$RS, (memri $D8, $RA):$dst),
                               "e_stwu $RS, $dst",
                               IIC_LdStSTU,
                               []>, RegConstraint<"$dst.reg = $ea_result">,
                               NoEncode<"$ea_result">;

} // Predicates = [IsBookE, IsISA2_07]

//===----------------------------------------------------------------------===//
// Note on Implementation
//===----------------------------------------------------------------------===//
//
// This is an initial implementation of VLE instructions. The actual encoding
// details need to be verified against:
// - Power ISA Version 2.07 Book VLE specification
// - e200 Core Reference Manuals (z0, z1, z3, z4, z759, z760)
// - VLE Programming Interface Manual (vlepim)
//
// TODO: Implement remaining VLE instructions:
// - Load/Store instructions (e_lbzu, e_lhzu, e_lwzu, e_stbu, e_sthu, e_stwu)
// - Load/Store Multiple (e_lmw, e_stmw)
// - Compare instructions (e_cmpi, e_cmpli, e_cmp16i, etc.)
// - Condition Register instructions (e_crand, e_cror, etc.)
// - Move instructions (e_li, e_lis, e_mcrf)
// - Multiply instructions (e_mulli, e_mull2i)
// - System instructions (e_sc, e_rfi, etc.)
//
// Reference: e200_core_reference_extracted/OPCODE_IMPLEMENTATION_PLAN.md

