//===-- PPCScheduleE200Z0.td - e200z0 Scheduling Defs ------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the itinerary class data for the NXP e200z0 32-bit
// Power processor.
//
// e200z0 Core Characteristics:
// - 4-stage pipeline
// - No MMU
// - No cache
// - No FPU
// - VLE-focused for smallest code size
// - Supports 32-bit PowerPC ISA and VLE (Variable Length Encoding)
//
// Reference: PowerPC Book E specification
// NXP e200z0 Core Reference Manual (to be added)
//
//===----------------------------------------------------------------------===//
// Relevant functional units in the e200z0 core:
//
//  * Decode & Dispatch
//    Single-issue pipeline (4-stage)
def E200Z0_DIS : FuncUnit; // Dispatch stage

//  * Execute
//    Simplified execution units: SU, BU, LSU, MU
def E200Z0_SU  : FuncUnit; // Simple unit
def E200Z0_BU  : FuncUnit; // Branch unit
def E200Z0_MU  : FuncUnit; // MU pipeline
def E200Z0_LSU : FuncUnit; // LSU pipeline

def E200Z0_GPR_Bypass : Bypass;
def E200Z0_CR_Bypass  : Bypass;
def E200Z0_DivBypass  : Bypass;

// e200z0 scheduling model - simplified 4-stage pipeline
// Note: This is an initial model and will need refinement based on
// actual hardware documentation and benchmarks.
def PPCE200Z0Itineraries : ProcessorItineraries<
  [E200Z0_DIS, E200Z0_SU, E200Z0_BU, E200Z0_MU, E200Z0_LSU],
  [E200Z0_CR_Bypass, E200Z0_GPR_Bypass, E200Z0_DivBypass], [
  // Basic integer operations - single-issue
  InstrItinData<IIC_IntSimple,   [InstrStage<1, [E200Z0_DIS], 0>,
                                  InstrStage<1, [E200Z0_SU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z0_GPR_Bypass,
                                  E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_IntGeneral,  [InstrStage<1, [E200Z0_DIS], 0>,
                                  InstrStage<1, [E200Z0_SU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z0_GPR_Bypass,
                                  E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_IntISEL,     [InstrStage<1, [E200Z0_DIS], 0>,
                                  InstrStage<1, [E200Z0_SU]>],
                                 [2, 1, 1], // Latency = 1
                                 [E200Z0_GPR_Bypass,
                                  E200Z0_GPR_Bypass,
                                  E200Z0_CR_Bypass]>,
  InstrItinData<IIC_IntCompare,  [InstrStage<1, [E200Z0_DIS], 0>,
                                  InstrStage<1, [E200Z0_SU]>],
                                 [3, 1], // Latency = 1 or 2
                                 [E200Z0_CR_Bypass,
                                  E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_IntDivW,     [InstrStage<1, [E200Z0_DIS], 0>,
                                  InstrStage<1, [E200Z0_MU], 0>,
                                  InstrStage<14, [E200Z0_MU]>],
                                 [16, 1], // Latency=4..35, Repeat= 4..35
                                 [E200Z0_GPR_Bypass,
                                  E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_IntMulHW,    [InstrStage<1, [E200Z0_DIS], 0>,
                                  InstrStage<4, [E200Z0_MU]>],
                                 [6, 1], // Latency = 4, Repeat rate = 1
                                 [E200Z0_GPR_Bypass,
                                  E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_IntMulHWU,   [InstrStage<1, [E200Z0_DIS], 0>,
                                  InstrStage<4, [E200Z0_MU]>],
                                 [6, 1], // Latency = 4, Repeat rate = 1
                                 [E200Z0_GPR_Bypass,
                                  E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_IntMulLI,    [InstrStage<1, [E200Z0_DIS], 0>,
                                  InstrStage<4, [E200Z0_MU]>],
                                 [6, 1], // Latency = 4, Repeat rate = 1
                                 [E200Z0_GPR_Bypass,
                                  E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_IntRotate,   [InstrStage<1, [E200Z0_DIS], 0>,
                                  InstrStage<1, [E200Z0_SU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z0_GPR_Bypass,
                                  E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_IntShift,    [InstrStage<1, [E200Z0_DIS], 0>,
                                  InstrStage<1, [E200Z0_SU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z0_GPR_Bypass,
                                  E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_IntTrapW,    [InstrStage<1, [E200Z0_DIS], 0>,
                                  InstrStage<2, [E200Z0_SU]>],
                                 [4, 1], // Latency = 2, Repeat rate = 2
                                 [E200Z0_GPR_Bypass, E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_BrB,         [InstrStage<1, [E200Z0_DIS], 0>,
                                  InstrStage<1, [E200Z0_BU]>],
                                 [2, 1], // Latency = 1
                                 [NoBypass, E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_BrCR,        [InstrStage<1, [E200Z0_DIS], 0>,
                                  InstrStage<1, [E200Z0_BU]>],
                                 [3, 1, 1], // Latency = 1
                                 [E200Z0_CR_Bypass,
                                  E200Z0_CR_Bypass]>,
  InstrItinData<IIC_BrMCR,       [InstrStage<1, [E200Z0_DIS], 0>,
                                  InstrStage<1, [E200Z0_BU]>],
                                 [3, 1], // Latency = 1
                                 [E200Z0_CR_Bypass, E200Z0_CR_Bypass]>,
  InstrItinData<IIC_BrMCRX,      [InstrStage<1, [E200Z0_DIS], 0>,
                                  InstrStage<1, [E200Z0_SU]>],
                                 [3, 1], // Latency = 1
                                 [E200Z0_CR_Bypass, E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_LdStLoad,    [InstrStage<1, [E200Z0_DIS], 0>,
                                  InstrStage<1, [E200Z0_LSU]>],
                                 [2, 1], // Latency = 1
                                 [E200Z0_GPR_Bypass, E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_LdStStore,   [InstrStage<1, [E200Z0_DIS], 0>,
                                  InstrStage<1, [E200Z0_LSU]>],
                                 [3, 1], // Latency = 1
                                 [NoBypass, E200Z0_GPR_Bypass]>
]>;

def PPCE200Z0Model : SchedMachineModel {
  let MicroOpBufferSize = 16; // Single-issue processor
  let LoadLatency = 2; // Estimated
  let MispredictPenalty = 2; // No branch prediction
  let CompleteModel = 0; // Incomplete model
  let IssueWidth = 1; // Single-issue
  let Itineraries = PPCE200Z0Itineraries;
}

