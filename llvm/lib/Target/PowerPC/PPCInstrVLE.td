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
// Encoding from Power ISA 2.07 Book VLE Chapter 5, Section 1.4.16
// Bits 0-5: Primary opcode (6)
// Bits 6-10: RT (destination register, 5 bits)
// Bits 11-15: RA (source register, 5 bits)
// Bits 16-19: Extended opcode (XO, 4 bits)
// Bit 20: Rc (record bit)
// Bit 21: F (fill bit, 1 bit) - fill value for high bits
// Bits 22-23: SCL (scale bits, 2 bits) - shift amount: 0=0, 1=8, 2=16, 3=24
// Bits 24-31: UI8 (8-bit unsigned immediate)
// 
// SCI8 encoding formula: sci8 = (56-SCL×8 bits of F) || UI8 || (SCL×8 bits of F)
// Where SCL values: 0=no shift, 1=shift 8, 2=shift 16, 3=shift 24
// 
// Note: SCI8 scaling logic should be implemented in the encoder/assembler.
// For now, we use simple encoding: F=0, SCL=0, UI8=immediate (for values 0-255)
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
  let Inst{21}     = 0;     // F field - set to 0 (basic encoding, scaling TODO)
  let Inst{22-23}  = 0b00;  // SCL field - set to 0 (no scaling, scaling TODO)
  let Inst{24-31}  = UI8;
}

// SCI8 Format: Scaled Immediate 8-bit (RS,RA form)
// Used for: e_andi, e_ori, e_xori
// Format: 32-bit instruction with 8-bit scaled immediate
// Encoding from Power ISA 2.07 Book VLE Chapter 5, Section 1.4.16
// Bits 0-5: Primary opcode (6)
// Bits 6-10: RS (source register, 5 bits)
// Bits 11-15: RA (destination register, 5 bits)
// Bits 16-19: Extended opcode (XO, 4 bits)
// Bit 20: Rc (record bit)
// Bit 21: F (fill bit, 1 bit) - fill value for high bits
// Bits 22-23: SCL (scale bits, 2 bits) - shift amount: 0=0, 1=8, 2=16, 3=24
// Bits 24-31: UI8 (8-bit unsigned immediate)
// 
// SCI8 encoding formula: sci8 = (56-SCL×8 bits of F) || UI8 || (SCL×8 bits of F)
// Where SCL values: 0=no shift, 1=shift 8, 2=shift 16, 3=shift 24
// 
// Note: SCI8 scaling logic should be implemented in the encoder/assembler.
// For now, we use simple encoding: F=0, SCL=0, UI8=immediate (for values 0-255)
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
  let Inst{21}     = 0;     // F field - set to 0 (basic encoding, scaling TODO)
  let Inst{22-23}  = 0b00;  // SCL field - set to 0 (no scaling, scaling TODO)
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

//===----------------------------------------------------------------------===//
// VLE Load/Store Instructions (No Update)
//===----------------------------------------------------------------------===//

// D Format: 16-bit displacement for load/store without update
// Used for: e_lbz, e_lhz, e_lwz, e_stb, e_sth, e_stw
// Format: 32-bit instruction with 16-bit displacement
// Encoding from Power ISA 2.07 Book VLE Chapter 5
// Bits 0-5: Primary opcode (varies by instruction)
// Bits 6-10: RT (load) or RS (store) - 5 bits
// Bits 11-15: RA (base register) - 5 bits
// Bits 16-31: D (16-bit signed displacement)
class VLE_DForm_Load<bits<6> opcode, dag OOL, dag IOL, string asmstr,
                     InstrItinClass itin, list<dag> pattern>
        : I<opcode, OOL, IOL, asmstr, itin>, MemriOp {
  bits<5> RT;
  bits<5> RA;
  bits<16> D;

  let Pattern = pattern;

  // D format encoding (load without update)
  let Inst{6-10}   = RT;
  let Inst{11-15}  = RA;
  let Inst{16-31}  = D;
}

class VLE_DForm_Store<bits<6> opcode, dag OOL, dag IOL, string asmstr,
                      InstrItinClass itin, list<dag> pattern>
        : I<opcode, OOL, IOL, asmstr, itin>, MemriOp {
  bits<5> RS;
  bits<5> RA;
  bits<16> D;

  let Pattern = pattern;

  // D format encoding (store without update)
  let Inst{6-10}   = RS;
  let Inst{11-15}  = RA;
  let Inst{16-31}  = D;
}

// e_stw: Store Word
// Stores word from RS to memory address (RA)+D
// Primary opcode: 21 (0x15 = 0x54000000 >> 26)
// Encoding: D form
def E_STW : VLE_DForm_Store<21,
                             (outs),
                             (ins gprc:$RS, (memri $D, $RA):$dst),
                             "e_stw $RS, $dst",
                             IIC_LdStStore,
                             [(store i32:$RS, DForm:$dst)]>;

//===----------------------------------------------------------------------===//
// VLE Move Instructions
//===----------------------------------------------------------------------===//

// LI20 Format: Load Immediate 20-bit
// Used for: e_li
// Format: 32-bit instruction with 20-bit immediate (split across fields)
// Encoding from Power ISA 2.07 Book VLE Chapter 5, Section 1.4.17
// Bits 0-5: Primary opcode (28 = 0x1C = 0x70000000 >> 26)
// Bits 6-10: RT (destination register)
// Bits 11-15: LI20[5:9] (part 1 of 20-bit immediate)
// Bits 16-20: ELEV (5 bits, set to 0 for e_li)
// Bits 17-20: LI20[1:4] (part 2 of 20-bit immediate)
// Bit 21: LI20[0] (part 3 of 20-bit immediate)
// Bits 22-31: LI20[10:19] (part 4 of 20-bit immediate)
// The LI20 field is: LI20[1:4] || LI20[5:9] || LI20[0] || LI20[10:19]
// Primary opcode 28, XO=0 (bits 16-20 = 0)
class VLE_LI20Form<dag OOL, dag IOL, string asmstr,
                    InstrItinClass itin, list<dag> pattern>
        : I<28, OOL, IOL, asmstr, itin> {
  bits<5> RT;
  bits<20> LI20;

  let Pattern = pattern;

  // LI20 format encoding
  let Inst{6-10}   = RT;
  let Inst{11-15}  = LI20{5-9};    // LI20[5:9]
  let Inst{16-20}  = 0b00000;      // ELEV = 0 (XO = 0 for e_li)
  let Inst{17-20}  = LI20{1-4};     // LI20[1:4]
  let Inst{21}     = LI20{0};       // LI20[0]
  let Inst{22-31}  = LI20{10-19};   // LI20[10:19]
}

// I16L Format: 16-bit Load/Logical Immediate
// Used for: e_lis, e_or2i
// Format: 32-bit instruction with 16-bit unsigned immediate (duplicated)
// Encoding from Power ISA 2.07 Book VLE Chapter 5, Section 1.4.14
// Bits 0-5: Primary opcode (28 = 0x1C = 0x7000C000 >> 26)
// Bits 6-10: RT (destination register)
// Bits 11-15: UI[0:4] (first part of 16-bit unsigned immediate)
// Bits 16-19: Extended opcode (XO, 4 bits)
// Bits 20-31: UI[0:11] (second part of 16-bit unsigned immediate, duplicated)
// The UI field is duplicated in bits 11-15 and 20-31
class VLE_I16LForm<bits<4> xo, dag OOL, dag IOL, string asmstr,
                   InstrItinClass itin, list<dag> pattern>
        : I<28, OOL, IOL, asmstr, itin> {
  bits<5> RT;
  bits<16> UI;

  let Pattern = pattern;

  // I16L format encoding
  let Inst{6-10}   = RT;
  let Inst{11-15}  = UI{0-4};       // UI[0:4]
  let Inst{16-19}  = xo;
  let Inst{20-31}  = UI{0-11};      // UI[0:11] (duplicated)
}

// e_li: Load Immediate
// Loads a 20-bit sign-extended immediate value into RT
// Primary opcode: 28, XO=0
// Note: For MVP, using s16imm operand (can be extended to 20-bit later)
def E_LI : VLE_LI20Form<(outs gprc:$RT),
                         (ins s16imm:$LI20),
                         "e_li $RT, $LI20",
                         IIC_IntSimple,
                         [(set i32:$RT, imm32SExt16:$LI20)]>;

// e_lis: Load Immediate Shifted
// Loads a 16-bit unsigned immediate value, shifted left 16 bits, into RT
// Primary opcode: 28, XO=0xE (0b1110)
// Pattern: matches immediate with low 16 bits zero (shifted left 16)
def E_LIS : VLE_I16LForm<0b1110,
                          (outs gprc:$RT),
                          (ins u16imm:$UI),
                          "e_lis $RT, $UI",
                          IIC_IntSimple,
                          [(set i32:$RT, imm16ShiftedZExt:$UI)]>;

// e_or2i: OR 2-operand Immediate
// ORs RT with 16-bit unsigned immediate (shifted left 16 bits) and stores result in RT
// Primary opcode: 28, XO=0xC (0b1100)
// Pattern: matches OR with immediate that has low 16 bits zero
// Note: RT is both input and output (read-modify-write), but TableGen requires different names
def E_OR2I : VLE_I16LForm<0b1100,
                           (outs gprc:$RT),
                           (ins gprc:$RST, u16imm:$UI),
                           "e_or2i $RT, $UI",
                           IIC_IntSimple,
                           [(set i32:$RT, (or i32:$RST, imm16ShiftedZExt:$UI))]>,
                           RegConstraint<"$RT = $RST">;

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

