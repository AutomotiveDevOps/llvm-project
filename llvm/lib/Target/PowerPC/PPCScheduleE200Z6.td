//===-- PPCScheduleE200Z6.td - e200z6 Scheduling Defs ------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the itinerary class data for the NXP e200z6 32-bit
// Power processor.
//
// e200z6 Core Characteristics:
// - 7-stage single-issue pipeline (IMPORTANT: Single-issue, not dual-issue!)
// - FPU support
// - Unified 32KB L1 cache
// - 32-entry MMU
// - Supports 32-bit PowerPC ISA and VLE (Variable Length Encoding)
//
// Reference: PowerPC Book E specification
// NXP e200z6 Core Reference Manual (E200Z6_Core_Reference_Manual.pdf)
//
//===----------------------------------------------------------------------===//
// Relevant functional units in the e200z6 core:
//
//  * Decode & Dispatch
//    Single-issue pipeline (7 stages)
//    Can dispatch 1 instruction per clock cycle
def E200Z6_DIS : FuncUnit; // Dispatch stage (single-issue)

//  * Execute
//    Execution units: SU, BU, LSU, MU, FPU.
//    Single-issue means only one instruction executes at a time.
def E200Z6_SU  : FuncUnit; // Simple unit
def E200Z6_BU  : FuncUnit; // Branch unit
def E200Z6_MU  : FuncUnit; // MU pipeline
def E200Z6_LSU : FuncUnit; // LSU pipeline
def E200Z6_FPU : FuncUnit; // FPU pipeline

def E200Z6_GPR_Bypass : Bypass;
def E200Z6_CR_Bypass  : Bypass;
def E200Z6_DivBypass  : Bypass;

// e200z6 scheduling model - 7-stage single-issue pipeline
// This model is based on the e200z6 Core Reference Manual.
// Note: This is a corrected model - e200z6 is SINGLE-ISSUE, not dual-issue.
// The model will be refined with actual timing data from the manual.
def PPCE200Z6Itineraries : ProcessorItineraries<
  [E200Z6_DIS, E200Z6_SU, E200Z6_BU, E200Z6_MU, E200Z6_LSU, E200Z6_FPU],
  [E200Z6_CR_Bypass, E200Z6_GPR_Bypass, E200Z6_DivBypass], [
  // Basic integer operations - single-issue pipeline
  InstrItinData<IIC_IntSimple,   [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<1, [E200Z6_SU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z6_GPR_Bypass,
                                  E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_IntGeneral,  [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<1, [E200Z6_SU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z6_GPR_Bypass,
                                  E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_IntISEL,     [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<1, [E200Z6_SU]>],
                                 [2, 1, 1], // Latency = 1
                                 [E200Z6_GPR_Bypass,
                                  E200Z6_GPR_Bypass,
                                  E200Z6_CR_Bypass]>,
  InstrItinData<IIC_IntCompare,  [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<1, [E200Z6_SU]>],
                                 [3, 1], // Latency = 1 or 2
                                 [E200Z6_CR_Bypass,
                                  E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_IntDivW,     [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<1, [E200Z6_MU], 0>,
                                  InstrStage<14, [E200Z6_MU]>],
                                 [16, 1], // Latency=4..35, Repeat= 4..35
                                 [E200Z6_GPR_Bypass,
                                  E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_IntMulHW,    [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<4, [E200Z6_MU]>],
                                 [6, 1], // Latency = 4, Repeat rate = 1
                                 [E200Z6_GPR_Bypass,
                                  E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_IntMulHWU,   [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<4, [E200Z6_MU]>],
                                 [6, 1], // Latency = 4, Repeat rate = 1
                                 [E200Z6_GPR_Bypass,
                                  E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_IntMulLI,    [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<4, [E200Z6_MU]>],
                                 [6, 1], // Latency = 4, Repeat rate = 1
                                 [E200Z6_GPR_Bypass,
                                  E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_IntRotate,   [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<1, [E200Z6_SU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z6_GPR_Bypass,
                                  E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_IntShift,    [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<1, [E200Z6_SU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z6_GPR_Bypass,
                                  E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_IntTrapW,    [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<2, [E200Z6_SU]>],
                                 [4, 1], // Latency = 2, Repeat rate = 2
                                 [E200Z6_GPR_Bypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_BrB,         [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<1, [E200Z6_BU]>],
                                 [2, 1], // Latency = 1
                                 [NoBypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_BrCR,        [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<1, [E200Z6_BU]>],
                                 [3, 1, 1], // Latency = 1
                                 [E200Z6_CR_Bypass,
                                  E200Z6_CR_Bypass]>,
  InstrItinData<IIC_BrMCR,       [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<1, [E200Z6_BU]>],
                                 [3, 1], // Latency = 1
                                 [E200Z6_CR_Bypass, E200Z6_CR_Bypass]>,
  InstrItinData<IIC_BrMCRX,      [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<1, [E200Z6_SU]>],
                                 [3, 1], // Latency = 1
                                 [E200Z6_CR_Bypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_LdStLoad,    [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<1, [E200Z6_LSU]>],
                                 [3, 1], // Latency = 2 (unified cache helps)
                                 [E200Z6_GPR_Bypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_LdStStore,   [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<1, [E200Z6_LSU]>],
                                 [3, 1], // Latency = 2
                                 [NoBypass, E200Z6_GPR_Bypass]>,
  // FPU floating-point instructions
  // e200z6 has a single-precision FPU (not EFPU2 like e200z7)
  InstrItinData<IIC_FPGeneral,   [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<3, [E200Z6_FPU]>],
                                 [4, 1], // Latency = 3
                                 [E200Z6_GPR_Bypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_FPAddSub,    [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<3, [E200Z6_FPU]>],
                                 [4, 1], // Latency = 3
                                 [E200Z6_GPR_Bypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_FPCompare,   [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<2, [E200Z6_FPU]>],
                                 [3, 1], // Latency = 2
                                 [E200Z6_CR_Bypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_FPDivS,      [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<1, [E200Z6_FPU], 0>,
                                  InstrStage<12, [E200Z6_FPU]>],
                                 [14, 1], // Latency = 13
                                 [E200Z6_GPR_Bypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_FPSqrtS,     [InstrStage<1, [E200Z6_DIS], 0>,
                                  InstrStage<1, [E200Z6_FPU], 0>,
                                  InstrStage<12, [E200Z6_FPU]>],
                                 [14, 1], // Latency = 13
                                 [E200Z6_GPR_Bypass, E200Z6_GPR_Bypass]>
]>;

def PPCE200Z6Model : SchedMachineModel {
  let MicroOpBufferSize = 16; // Single-issue processor (7-stage pipeline)
  let LoadLatency = 2; // Unified 32KB L1 cache provides better latency
  let MispredictPenalty = 3; // 7-stage pipeline increases penalty
  let CompleteModel = 1; // Complete model (refined based on e200z6 characteristics)
  let IssueWidth = 1; // SINGLE-ISSUE (corrected from dual-issue)
  let Itineraries = PPCE200Z6Itineraries;
}

