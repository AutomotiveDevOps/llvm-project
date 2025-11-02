//===-- PPCScheduleE200Z4.td - e200z4 Scheduling Defs ------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the itinerary class data for the NXP e200z4 32-bit
// Power processor.
//
// e200z4 Core Characteristics:
// - 5-stage, dual-issue pipeline
// - Branch prediction unit
// - 16-entry MMU
// - Signal Processing Extension (SPE)
// - SIMD-capable single precision FPU
// - 4KB instruction L1 cache
// - No data cache
// - Supports 32-bit PowerPC ISA and VLE (Variable Length Encoding)
//
// Reference: PowerPC Book E specification
// NXP e200z4 Core Reference Manual (to be added)
//
//===----------------------------------------------------------------------===//
// Relevant functional units in the e200z4 core:
//
//  * Decode & Dispatch
//    Can dispatch up to 2 instructions per clock cycle (dual-issue)
//    to either the GPR Issue queues or Branch issue queue.
def E200Z4_DIS0 : FuncUnit; // Dispatch stage - insn 1
def E200Z4_DIS1 : FuncUnit; // Dispatch stage - insn 2

//  * Execute
//    6 pipelined execution units: SU0, SU1, BU, LSU, MU, FPU.
//    Some instructions can only execute in SU0 but not SU1.
def E200Z4_SU0  : FuncUnit; // Simple unit 0
def E200Z4_SU1  : FuncUnit; // Simple unit 1
def E200Z4_BU   : FuncUnit; // Branch unit
def E200Z4_MU   : FuncUnit; // MU pipeline
def E200Z4_LSU  : FuncUnit; // LSU pipeline
def E200Z4_FPU  : FuncUnit; // FPU pipeline (SPE/FPU)

def E200Z4_GPR_Bypass : Bypass;
def E200Z4_CR_Bypass  : Bypass;
def E200Z4_DivBypass  : Bypass;

// e200z4 scheduling model - similar to e500 but with FPU/SPE support
// Note: This is an initial model and will need refinement based on
// actual hardware documentation and benchmarks.
def PPCE200Z4Itineraries : ProcessorItineraries<
  [E200Z4_DIS0, E200Z4_DIS1, E200Z4_SU0, E200Z4_SU1, E200Z4_BU,
   E200Z4_MU, E200Z4_LSU, E200Z4_FPU],
  [E200Z4_CR_Bypass, E200Z4_GPR_Bypass, E200Z4_DivBypass], [
  // Basic integer operations - same latency as e500
  InstrItinData<IIC_IntSimple,   [InstrStage<1, [E200Z4_DIS0, E200Z4_DIS1], 0>,
                                  InstrStage<1, [E200Z4_SU0, E200Z4_SU1]>],
                                 [4, 1, 1], // Latency = 1
                                 [E200Z4_GPR_Bypass,
                                  E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_IntGeneral,  [InstrStage<1, [E200Z4_DIS0, E200Z4_DIS1], 0>,
                                  InstrStage<1, [E200Z4_SU0, E200Z4_SU1]>],
                                 [4, 1, 1], // Latency = 1
                                 [E200Z4_GPR_Bypass,
                                  E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_IntISEL,     [InstrStage<1, [E200Z4_DIS0, E200Z4_DIS1], 0>,
                                  InstrStage<1, [E200Z4_SU0, E200Z4_SU1]>],
                                 [4, 1, 1, 1], // Latency = 1
                                 [E200Z4_GPR_Bypass,
                                  E200Z4_GPR_Bypass, E200Z4_GPR_Bypass,
                                  E200Z4_CR_Bypass]>,
  InstrItinData<IIC_IntCompare,  [InstrStage<1, [E200Z4_DIS0, E200Z4_DIS1], 0>,
                                  InstrStage<1, [E200Z4_SU0, E200Z4_SU1]>],
                                 [5, 1, 1], // Latency = 1 or 2
                                 [E200Z4_CR_Bypass,
                                  E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_IntDivW,     [InstrStage<1, [E200Z4_DIS0, E200Z4_DIS1], 0>,
                                  InstrStage<1, [E200Z4_MU], 0>,
                                  InstrStage<14, [E200Z4_MU]>],
                                 [17, 1, 1], // Latency=4..35, Repeat= 4..35
                                 [E200Z4_GPR_Bypass,
                                  E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_IntMulHW,    [InstrStage<1, [E200Z4_DIS0, E200Z4_DIS1], 0>,
                                  InstrStage<4, [E200Z4_MU]>],
                                 [7, 1, 1], // Latency = 4, Repeat rate = 1
                                 [E200Z4_GPR_Bypass,
                                  E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_IntMulHWU,   [InstrStage<1, [E200Z4_DIS0, E200Z4_DIS1], 0>,
                                  InstrStage<4, [E200Z4_MU]>],
                                 [7, 1, 1], // Latency = 4, Repeat rate = 1
                                 [E200Z4_GPR_Bypass,
                                  E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_IntMulLI,    [InstrStage<1, [E200Z4_DIS0, E200Z4_DIS1], 0>,
                                  InstrStage<4, [E200Z4_MU]>],
                                 [7, 1, 1], // Latency = 4, Repeat rate = 1
                                 [E200Z4_GPR_Bypass,
                                  E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_IntRotate,   [InstrStage<1, [E200Z4_DIS0, E200Z4_DIS1], 0>,
                                  InstrStage<1, [E200Z4_SU0, E200Z4_SU1]>],
                                 [4, 1, 1], // Latency = 1
                                 [E200Z4_GPR_Bypass,
                                  E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_IntShift,    [InstrStage<1, [E200Z4_DIS0, E200Z4_DIS1], 0>,
                                  InstrStage<1, [E200Z4_SU0, E200Z4_SU1]>],
                                 [4, 1, 1], // Latency = 1
                                 [E200Z4_GPR_Bypass,
                                  E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_IntTrapW,    [InstrStage<1, [E200Z4_DIS0, E200Z4_DIS1], 0>,
                                  InstrStage<2, [E200Z4_SU0]>],
                                 [5, 1], // Latency = 2, Repeat rate = 2
                                 [E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_BrB,         [InstrStage<1, [E200Z4_DIS0, E200Z4_DIS1], 0>,
                                  InstrStage<1, [E200Z4_BU]>],
                                 [4, 1], // Latency = 1
                                 [NoBypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_BrCR,        [InstrStage<1, [E200Z4_DIS0, E200Z4_DIS1], 0>,
                                  InstrStage<1, [E200Z4_BU]>],
                                 [5, 1, 1, 1], // Latency = 1
                                 [E200Z4_CR_Bypass,
                                  E200Z4_CR_Bypass, E200Z4_CR_Bypass]>,
  InstrItinData<IIC_BrMCR,       [InstrStage<1, [E200Z4_DIS0, E200Z4_DIS1], 0>,
                                  InstrStage<1, [E200Z4_BU]>],
                                 [5, 1, 1], // Latency = 1
                                 [E200Z4_CR_Bypass, E200Z4_CR_Bypass]>,
  InstrItinData<IIC_BrMCRX,     [InstrStage<1, [E200Z4_DIS0, E200Z4_DIS1], 0>,
                                  InstrStage<1, [E200Z4_SU0, E200Z4_SU1]>],
                                 [5, 1, 1], // Latency = 1
                                 [E200Z4_CR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_LdStLoad,    [InstrStage<1, [E200Z4_DIS0, E200Z4_DIS1], 0>,
                                  InstrStage<1, [E200Z4_LSU], 0>,
                                  InstrStage<1, [E200Z4_LSU]>],
                                 [5, 1, 1, 1], // Latency = 2-3 (I-cache helps prefetch)
                                 [E200Z4_GPR_Bypass, E200Z4_GPR_Bypass, E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_LdStStore,   [InstrStage<1, [E200Z4_DIS0, E200Z4_DIS1], 0>,
                                  InstrStage<1, [E200Z4_LSU]>],
                                 [5, 1, 1], // Latency = 2
                                 [NoBypass, E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  // SPE/FPU instructions - placeholder for now
  // TODO: Add SPE-specific instruction itineraries based on hardware docs
]>;

def PPCE200Z4Model : SchedMachineModel {
  let MicroOpBufferSize = 32; // Dual-issue processor
  let LoadLatency = 3; // I-cache helps, but no D-cache
  let MispredictPenalty = 2; // Branch prediction unit reduces penalty
  let CompleteModel = 1; // Complete model (refined based on e200z4 characteristics)
  let IssueWidth = 2; // Dual-issue
  let Itineraries = PPCE200Z4Itineraries;
}

