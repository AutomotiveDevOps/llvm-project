//===-- PPCScheduleE200Z7.td - e200z7 Scheduling Defs ------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the itinerary class data for the NXP e200z7 32-bit
// Power processor (e200z759n3 variant).
//
// e200z7 Core Characteristics (based on e200z759n3 Core Reference Manual):
// - Advanced pipeline architecture
// - Dual-issue capability (similar to e200z4)
// - MMU support
// - Enhanced cache support (L1 instruction and data caches)
// - Embedded Floating-Point Unit (EFPU2) support
// - Signal Processing Extension (SPE) support
// - Supports 32-bit PowerPC ISA and VLE (Variable Length Encoding)
//
// Reference: PowerPC Book E specification
// NXP e200z759n3 Core Reference Manual, Rev. 2 (January 2015)
// https://community.nxp.com/pwmxy87654/attachments/pwmxy87654/mpc5xxx/11751/1/e200z759CRM.pdf
//
//===----------------------------------------------------------------------===//
// Relevant functional units in the e200z7 core:
//
//  * Decode & Dispatch
//    Dual-issue pipeline
//    Can dispatch up to 2 instructions per clock cycle
def E200Z7_DIS0 : FuncUnit; // Dispatch stage - insn 1
def E200Z7_DIS1 : FuncUnit; // Dispatch stage - insn 2

//  * Execute
//    Multiple pipelined execution units: SU0, SU1, BU, LSU, MU, FPU/EFPU.
//    Similar to e200z4 but with enhanced features.
def E200Z7_SU0  : FuncUnit; // Simple unit 0
def E200Z7_SU1  : FuncUnit; // Simple unit 1
def E200Z7_BU   : FuncUnit; // Branch unit
def E200Z7_MU   : FuncUnit; // MU pipeline
def E200Z7_LSU  : FuncUnit; // LSU pipeline
def E200Z7_FPU  : FuncUnit; // FPU/EFPU pipeline (SPE/EFPU2)

def E200Z7_GPR_Bypass : Bypass;
def E200Z7_CR_Bypass  : Bypass;
def E200Z7_DivBypass  : Bypass;

// e200z7 scheduling model - dual-issue pipeline with EFPU2/SPE support
// This model is based on the e200z759n3 Core Reference Manual.
// The e200z7 core is similar to e200z4 but with enhanced features including
// EFPU2 (Embedded Floating-Point Unit 2) and improved cache architecture.
def PPCE200Z7Itineraries : ProcessorItineraries<
  [E200Z7_DIS0, E200Z7_DIS1, E200Z7_SU0, E200Z7_SU1, E200Z7_BU,
   E200Z7_MU, E200Z7_LSU, E200Z7_FPU],
  [E200Z7_CR_Bypass, E200Z7_GPR_Bypass, E200Z7_DivBypass], [
  // Basic integer operations - dual-issue capable
  InstrItinData<IIC_IntSimple,   [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<1, [E200Z7_SU0, E200Z7_SU1]>],
                                 [4, 1, 1], // Latency = 1
                                 [E200Z7_GPR_Bypass,
                                  E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntGeneral,  [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<1, [E200Z7_SU0, E200Z7_SU1]>],
                                 [4, 1, 1], // Latency = 1
                                 [E200Z7_GPR_Bypass,
                                  E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntISEL,     [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<1, [E200Z7_SU0, E200Z7_SU1]>],
                                 [4, 1, 1, 1], // Latency = 1
                                 [E200Z7_GPR_Bypass,
                                  E200Z7_GPR_Bypass, E200Z7_GPR_Bypass,
                                  E200Z7_CR_Bypass]>,
  InstrItinData<IIC_IntCompare,  [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<1, [E200Z7_SU0, E200Z7_SU1]>],
                                 [5, 1, 1], // Latency = 1 or 2
                                 [E200Z7_CR_Bypass,
                                  E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntDivW,     [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<1, [E200Z7_MU], 0>,
                                  InstrStage<14, [E200Z7_MU]>],
                                 [17, 1, 1], // Latency=4..35, Repeat= 4..35
                                 [E200Z7_GPR_Bypass,
                                  E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntMulHW,    [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<4, [E200Z7_MU]>],
                                 [7, 1, 1], // Latency = 4, Repeat rate = 1
                                 [E200Z7_GPR_Bypass,
                                  E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntMulHWU,   [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<4, [E200Z7_MU]>],
                                 [7, 1, 1], // Latency = 4, Repeat rate = 1
                                 [E200Z7_GPR_Bypass,
                                  E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntMulLI,    [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<4, [E200Z7_MU]>],
                                 [7, 1, 1], // Latency = 4, Repeat rate = 1
                                 [E200Z7_GPR_Bypass,
                                  E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntRotate,   [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<1, [E200Z7_SU0, E200Z7_SU1]>],
                                 [4, 1, 1], // Latency = 1
                                 [E200Z7_GPR_Bypass,
                                  E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntShift,    [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<1, [E200Z7_SU0, E200Z7_SU1]>],
                                 [4, 1, 1], // Latency = 1
                                 [E200Z7_GPR_Bypass,
                                  E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntTrapW,    [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<2, [E200Z7_SU0, E200Z7_SU1]>],
                                 [5, 1, 1], // Latency = 2
                                 [E200Z7_GPR_Bypass, E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_BrB,         [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<1, [E200Z7_BU]>],
                                 [4, 1, 1], // Latency = 1
                                 [NoBypass, E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_BrCR,        [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<1, [E200Z7_BU]>],
                                 [4, 1, 1], // Latency = 1
                                 [E200Z7_CR_Bypass,
                                  E200Z7_CR_Bypass, E200Z7_CR_Bypass]>,
  InstrItinData<IIC_BrMCR,       [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<1, [E200Z7_BU]>],
                                 [4, 1, 1], // Latency = 1
                                 [E200Z7_CR_Bypass, E200Z7_CR_Bypass, E200Z7_CR_Bypass]>,
  InstrItinData<IIC_BrMCRX,      [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<1, [E200Z7_SU0, E200Z7_SU1]>],
                                 [4, 1, 1], // Latency = 1
                                 [E200Z7_CR_Bypass, E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_LdStLoad,    [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<2, [E200Z7_LSU]>],
                                 [5, 1, 1], // Latency = 2
                                 [E200Z7_GPR_Bypass, E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_LdStLoadUpd, [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<2, [E200Z7_LSU]>],
                                 [5, 1, 1, 1], // Latency = 2
                                 [E200Z7_GPR_Bypass,
                                  E200Z7_GPR_Bypass, E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_LdStStore,   [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<1, [E200Z7_LSU]>],
                                 [4, 1, 1], // Latency = 1
                                 [E200Z7_GPR_Bypass, E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_LdStStoreUpd,[InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<1, [E200Z7_LSU]>],
                                 [4, 1, 1, 1], // Latency = 1
                                 [E200Z7_GPR_Bypass,
                                  E200Z7_GPR_Bypass, E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_LdStLWARX,  [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<3, [E200Z7_LSU]>],
                                 [6, 1, 1], // Latency = 3
                                 [E200Z7_GPR_Bypass, E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_LdStSTWCX,   [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<2, [E200Z7_LSU]>],
                                 [5, 1, 1], // Latency = 2
                                 [E200Z7_GPR_Bypass, E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_LdStDCBF,    [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<1, [E200Z7_LSU]>],
                                 [4, 1, 1], // Latency = 1
                                 [NoBypass, NoBypass, NoBypass]>,
  InstrItinData<IIC_SprMFCR,     [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<1, [E200Z7_SU0, E200Z7_SU1]>],
                                 [4, 1, 1], // Latency = 1
                                 [E200Z7_GPR_Bypass, E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_SprMFCRF,    [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<1, [E200Z7_SU0, E200Z7_SU1]>],
                                 [4, 1, 1], // Latency = 1
                                 [E200Z7_GPR_Bypass, E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_SprMFSPR,    [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<1, [E200Z7_SU0, E200Z7_SU1]>],
                                 [4, 1, 1], // Latency = 1
                                 [E200Z7_GPR_Bypass, E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_SprMTSPR,    [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<1, [E200Z7_SU0, E200Z7_SU1]>],
                                 [4, 1, 1], // Latency = 1
                                 [E200Z7_GPR_Bypass, E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  // SPE/EFPU2 floating-point instructions
  // EFPU2 provides enhanced floating-point capabilities compared to e200z4
  InstrItinData<IIC_FPGeneral,   [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<3, [E200Z7_FPU]>],
                                 [6, 1, 1], // Latency = 3
                                 [E200Z7_GPR_Bypass, E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_FPAddSub,    [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<3, [E200Z7_FPU]>],
                                 [6, 1, 1], // Latency = 3
                                 [E200Z7_GPR_Bypass, E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_FPCompare,   [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<2, [E200Z7_FPU]>],
                                 [5, 1, 1], // Latency = 2
                                 [E200Z7_CR_Bypass, E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_FPDivS,      [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<1, [E200Z7_FPU], 0>,
                                  InstrStage<12, [E200Z7_FPU]>],
                                 [15, 1, 1], // Latency = 13
                                 [E200Z7_GPR_Bypass, E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_FPSqrtS,     [InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                  InstrStage<1, [E200Z7_FPU], 0>,
                                  InstrStage<12, [E200Z7_FPU]>],
                                 [15, 1, 1], // Latency = 13
                                 [E200Z7_GPR_Bypass, E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>
]>;

def PPCE200Z7Model : SchedMachineModel {
  let IssueWidth = 2;  // Dual-issue pipeline
  let MicroOpBufferSize = 0;
  let LoadLatency = 2;  // Load latency with L1 cache
  let MispredictPenalty = 3;
  let Itineraries = PPCE200Z7Itineraries;
}

