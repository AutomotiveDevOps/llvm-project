//===-- PPCScheduleE200Z3.td - e200z3 Scheduling Defs ------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the itinerary class data for the NXP e200z3 32-bit
// Power processor.
//
// e200z3 Core Characteristics:
// - 5-stage single-issue pipeline
// - MMU support
// - Instruction cache support
// - No FPU (unlike e200z4/z6)
// - No SPE (Signal Processing Extension)
// - Supports 32-bit PowerPC ISA and VLE (Variable Length Encoding)
//
// Reference: PowerPC Book E specification
// NXP e200z3 Core Reference Manual (E200Z3_Core_Reference_Manual.pdf)
//
//===----------------------------------------------------------------------===//
// Relevant functional units in the e200z3 core:
//
//  * Decode & Dispatch
//    Single-issue pipeline (5-stage)
//    Can dispatch 1 instruction per clock cycle
def E200Z3_DIS : FuncUnit; // Dispatch stage (single-issue)

//  * Execute
//    Execution units: SU, BU, LSU, MU.
//    Single-issue means only one instruction executes at a time.
//    No FPU unit (unlike e200z4/z6).
def E200Z3_SU  : FuncUnit; // Simple unit
def E200Z3_BU  : FuncUnit; // Branch unit
def E200Z3_MU  : FuncUnit; // MU pipeline
def E200Z3_LSU : FuncUnit; // LSU pipeline

def E200Z3_GPR_Bypass : Bypass;
def E200Z3_CR_Bypass  : Bypass;
def E200Z3_DivBypass  : Bypass;

// e200z3 scheduling model - 5-stage single-issue pipeline
// This model is based on the e200z3 Core Reference Manual.
// The e200z3 core uses a 5-stage pipeline similar to e200z4 but is single-issue
// and lacks FPU/SPE capabilities.
def PPCE200Z3Itineraries : ProcessorItineraries<
  [E200Z3_DIS, E200Z3_SU, E200Z3_BU, E200Z3_MU, E200Z3_LSU],
  [E200Z3_CR_Bypass, E200Z3_GPR_Bypass, E200Z3_DivBypass], [
  // Basic integer operations - single-issue pipeline
  InstrItinData<IIC_IntSimple,   [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<1, [E200Z3_SU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z3_GPR_Bypass,
                                  E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_IntGeneral,  [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<1, [E200Z3_SU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z3_GPR_Bypass,
                                  E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_IntISEL,     [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<1, [E200Z3_SU]>],
                                 [2, 1, 1], // Latency = 1
                                 [E200Z3_GPR_Bypass,
                                  E200Z3_GPR_Bypass,
                                  E200Z3_CR_Bypass]>,
  InstrItinData<IIC_IntCompare,  [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<1, [E200Z3_SU]>],
                                 [3, 1], // Latency = 1 or 2
                                 [E200Z3_CR_Bypass,
                                  E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_IntDivW,     [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<1, [E200Z3_MU], 0>,
                                  InstrStage<14, [E200Z3_MU]>],
                                 [16, 1], // Latency=4..35, Repeat= 4..35
                                 [E200Z3_GPR_Bypass,
                                  E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_IntMulHW,    [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<4, [E200Z3_MU]>],
                                 [6, 1], // Latency = 4, Repeat rate = 1
                                 [E200Z3_GPR_Bypass,
                                  E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_IntMulHWU,   [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<4, [E200Z3_MU]>],
                                 [6, 1], // Latency = 4, Repeat rate = 1
                                 [E200Z3_GPR_Bypass,
                                  E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_IntMulLI,    [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<4, [E200Z3_MU]>],
                                 [6, 1], // Latency = 4, Repeat rate = 1
                                 [E200Z3_GPR_Bypass,
                                  E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_IntRotate,   [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<1, [E200Z3_SU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z3_GPR_Bypass,
                                  E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_IntShift,    [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<1, [E200Z3_SU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z3_GPR_Bypass,
                                  E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_IntTrapW,    [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<2, [E200Z3_SU]>],
                                 [3, 1], // Latency = 2
                                 [E200Z3_GPR_Bypass, E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_BrB,         [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<1, [E200Z3_BU]>],
                                 [2, 1], // Latency = 1
                                 [NoBypass, E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_BrCR,        [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<1, [E200Z3_BU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z3_CR_Bypass,
                                  E200Z3_CR_Bypass]>,
  InstrItinData<IIC_BrMCR,       [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<1, [E200Z3_BU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z3_CR_Bypass, E200Z3_CR_Bypass]>,
  InstrItinData<IIC_BrMCRX,      [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<1, [E200Z3_SU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z3_CR_Bypass, E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_LdStLoad,    [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<2, [E200Z3_LSU]>],
                                 [3, 1], // Latency = 2
                                 [E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_LdStLoadUpd, [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<2, [E200Z3_LSU]>],
                                 [3, 1, 1], // Latency = 2
                                 [E200Z3_GPR_Bypass,
                                  E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_LdStStore,   [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<1, [E200Z3_LSU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_LdStStoreUpd,[InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<1, [E200Z3_LSU]>],
                                 [2, 1, 1], // Latency = 1
                                 [E200Z3_GPR_Bypass,
                                  E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_LdStLWARX,  [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<3, [E200Z3_LSU]>],
                                 [4, 1], // Latency = 3
                                 [E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_LdStSTWCX,   [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<2, [E200Z3_LSU]>],
                                 [3, 1], // Latency = 2
                                 [E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_LdStDCBF,    [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<1, [E200Z3_LSU]>],
                                 [2, 1], // Latency = 1
                                 [NoBypass]>,
  InstrItinData<IIC_SprMFCR,     [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<1, [E200Z3_SU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_SprMFCRF,    [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<1, [E200Z3_SU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_SprMFSPR,    [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<1, [E200Z3_SU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z3_GPR_Bypass]>,
  InstrItinData<IIC_SprMTSPR,    [InstrStage<1, [E200Z3_DIS], 0>,
                                  InstrStage<1, [E200Z3_SU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z3_GPR_Bypass]>,
  // No FPU instructions - e200z3 does not have floating-point unit
]>;

def PPCE200Z3Model : SchedMachineModel {
  let IssueWidth = 1;  // Single-issue pipeline
  let MicroOpBufferSize = 0;
  let LoadLatency = 2;  // Load latency for cache
  let MispredictPenalty = 3;
  let Itineraries = PPCE200Z3Itineraries;
}

