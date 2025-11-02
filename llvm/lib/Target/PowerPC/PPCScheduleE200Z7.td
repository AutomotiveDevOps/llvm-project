//===-- PPCScheduleE200Z7.td - e200z7 Scheduling Defs ---*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the itinerary class data for the NXP e200z7 32-bit
// Power processor.
//
// All information is derived from the "e200z7 Core Reference Manual",
// NXP Document Number E200Z7CRM.
//
//===----------------------------------------------------------------------===//
// Relevant functional units in the NXP e200z7 core:
//
//  * Fetch & Decode
//    Dual-issue in-order processor. Can issue up to 2 instructions per cycle
//    following pairing rules.
//
def E200Z7_FETCH : FuncUnit; // Instruction fetch stage
def E200Z7_DIS0   : FuncUnit; // Dispatch stage - instruction 0
def E200Z7_DIS1   : FuncUnit; // Dispatch stage - instruction 1

//  * Execute
//    Two integer ALU units, branch unit, SPE/FPU unit, and LSU.
//    Dual-issue pairing rules:
//    - Integer ALU + Integer ALU
//    - Integer ALU + Branch (if branch is second)
//    - Integer ALU + LSU (load/store as second)
//    - Integer ALU + SPE/FPU (if FPU is second)
//    - SPE/FPU instructions can pair with ALU (FPU second)
//    - Some instructions are restricted to ALU0 only
//
def E200Z7_ALU0   : FuncUnit; // Integer ALU 0
def E200Z7_ALU1   : FuncUnit; // Integer ALU 1
def E200Z7_BU     : FuncUnit; // Branch unit
def E200Z7_SPE    : FuncUnit; // Signal Processing Engine / FPU unit
def E200Z7_LSU    : FuncUnit; // Load/store unit
def E200Z7_MUL    : FuncUnit; // Multiply unit (in ALU0)

def E200Z7_GPR_Bypass : Bypass;
def E200Z7_CR_Bypass  : Bypass;
def E200Z7_SPE_Bypass : Bypass;
def E200Z7_FPR_Bypass : Bypass;

def PPCE200Z7Itineraries : ProcessorItineraries<
  [E200Z7_FETCH, E200Z7_DIS0, E200Z7_DIS1, E200Z7_ALU0, E200Z7_ALU1,
   E200Z7_BU, E200Z7_SPE, E200Z7_LSU, E200Z7_MUL],
  [E200Z7_CR_Bypass, E200Z7_GPR_Bypass, E200Z7_SPE_Bypass, E200Z7_FPR_Bypass], [
  InstrItinData<IIC_IntSimple,   [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                   InstrStage<1, [E200Z7_ALU0, E200Z7_ALU1]>],
                                  [4, 1, 1], // Latency = 1
                                  [E200Z7_GPR_Bypass,
                                   E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntGeneral,  [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                   InstrStage<1, [E200Z7_ALU0, E200Z7_ALU1]>],
                                  [4, 1, 1], // Latency = 1
                                  [E200Z7_GPR_Bypass,
                                   E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntISEL,     [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                   InstrStage<1, [E200Z7_ALU0, E200Z7_ALU1]>],
                                  [4, 1, 1, 1], // Latency = 1
                                  [E200Z7_GPR_Bypass,
                                   E200Z7_GPR_Bypass, E200Z7_GPR_Bypass,
                                   E200Z7_CR_Bypass]>,
  InstrItinData<IIC_IntCompare,  [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                   InstrStage<1, [E200Z7_ALU0, E200Z7_ALU1]>],
                                  [5, 1, 1], // Latency = 1 or 2
                                  [E200Z7_CR_Bypass,
                                   E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntDivW,     [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0], 0>,
                                   InstrStage<1, [E200Z7_ALU0], 0>,
                                   InstrStage<32, [E200Z7_ALU0]>],
                                  [36, 1, 1], // Latency = 32, Repeat rate = 32
                                  [E200Z7_GPR_Bypass,
                                   E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntMulHW,    [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0], 0>,
                                   InstrStage<1, [E200Z7_ALU0, E200Z7_MUL]>,
                                   InstrStage<3, [E200Z7_MUL]>],
                                  [7, 1, 1], // Latency = 4, Repeat rate = 1
                                  [E200Z7_GPR_Bypass,
                                   E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntMulHWU,   [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0], 0>,
                                   InstrStage<1, [E200Z7_ALU0, E200Z7_MUL]>,
                                   InstrStage<3, [E200Z7_MUL]>],
                                  [7, 1, 1], // Latency = 4, Repeat rate = 1
                                  [E200Z7_GPR_Bypass,
                                   E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntMulLI,    [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0], 0>,
                                   InstrStage<1, [E200Z7_ALU0, E200Z7_MUL]>,
                                   InstrStage<3, [E200Z7_MUL]>],
                                  [7, 1, 1], // Latency = 4, Repeat rate = 1
                                  [E200Z7_GPR_Bypass,
                                   E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntRotate,   [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                   InstrStage<1, [E200Z7_ALU0, E200Z7_ALU1]>],
                                  [4, 1, 1], // Latency = 1
                                  [E200Z7_GPR_Bypass,
                                   E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntShift,    [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                   InstrStage<1, [E200Z7_ALU0, E200Z7_ALU1]>],
                                  [4, 1, 1], // Latency = 1
                                  [E200Z7_GPR_Bypass,
                                   E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntTrapW,    [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0], 0>,
                                   InstrStage<2, [E200Z7_ALU0]>],
                                  [5, 1, 1], // Latency = 2, Repeat rate = 2
                                  [E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_BrB,         [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                   InstrStage<1, [E200Z7_BU]>],
                                  [4, 1, 1], // Latency = 1
                                  [NoBypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_BrCR,        [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                   InstrStage<1, [E200Z7_BU]>],
                                  [4, 1, 1, 1], // Latency = 1
                                  [E200Z7_CR_Bypass,
                                   E200Z7_CR_Bypass, E200Z7_CR_Bypass]>,
  InstrItinData<IIC_BrMCR,       [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                   InstrStage<1, [E200Z7_BU]>],
                                  [4, 1, 1], // Latency = 1
                                  [E200Z7_CR_Bypass, E200Z7_CR_Bypass]>,
  InstrItinData<IIC_BrMCRX,      [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                   InstrStage<1, [E200Z7_ALU0, E200Z7_ALU1]>],
                                  [4, 1, 1, 1], // Latency = 1
                                  [E200Z7_CR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_LdStLoad,    [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                   InstrStage<1, [E200Z7_LSU]>],
                                  [6, 1, 1], // Latency = 3
                                  [E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_LdStLoadUpd, [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0], 0>,
                                   InstrStage<1, [E200Z7_ALU0], 0>,
                                   InstrStage<1, [E200Z7_LSU]>],
                                  [6, 1, 1], // Latency = 3
                                  [E200Z7_GPR_Bypass, E200Z7_GPR_Bypass],
                                  2>, // 2 micro-ops
  InstrItinData<IIC_LdStLoadUpdX,[InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0], 0>,
                                   InstrStage<1, [E200Z7_ALU0], 0>,
                                   InstrStage<1, [E200Z7_LSU]>],
                                  [6, 1, 1], // Latency = 3
                                  [E200Z7_GPR_Bypass, E200Z7_GPR_Bypass],
                                  2>, // 2 micro-ops
  InstrItinData<IIC_LdStStore,   [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                   InstrStage<1, [E200Z7_LSU]>],
                                  [5, 1, 1], // Latency = 3
                                  [NoBypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_LdStSTU,     [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0], 0>,
                                   InstrStage<1, [E200Z7_ALU0], 0>,
                                   InstrStage<1, [E200Z7_LSU]>],
                                  [5, 1, 1], // Latency = 3
                                  [NoBypass, E200Z7_GPR_Bypass],
                                  2>, // 2 micro-ops
  InstrItinData<IIC_LdStSTUX,    [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0], 0>,
                                   InstrStage<1, [E200Z7_ALU0], 0>,
                                   InstrStage<1, [E200Z7_LSU]>],
                                  [5, 1, 1], // Latency = 3
                                  [NoBypass, E200Z7_GPR_Bypass],
                                  2>, // 2 micro-ops
  // SPE/FPU instructions - can pair with ALU (FPU second)
  // SPE simple operations: evaddw, evsubfw, evand, etc. - 1 cycle latency, can pair
  InstrItinData<IIC_VecGeneral,  [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                   InstrStage<1, [E200Z7_SPE]>],
                                  [5, 1, 1], // Latency = 1, Repeat rate = 1
                                  [E200Z7_SPE_Bypass]>,
  // SPE complex operations: evaddsmiaaw, evsubfssiaaw, etc. - 4 cycle latency, cannot pair
  InstrItinData<IIC_VecComplex,  [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0], 0>,
                                   InstrStage<1, [E200Z7_SPE], 0>,
                                   InstrStage<3, [E200Z7_SPE]>],
                                  [7, 1, 1], // Latency = 4, Repeat rate = 1
                                  [E200Z7_SPE_Bypass]>,
  // FPU general operations: efsadd, efssub, etc. - 3 cycle latency, can pair with ALU
  InstrItinData<IIC_FPGeneral,   [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                   InstrStage<1, [E200Z7_SPE], 0>,
                                   InstrStage<2, [E200Z7_SPE]>],
                                  [7, 1, 1, 1], // Latency = 3, Repeat rate = 1
                                  [E200Z7_FPR_Bypass,
                                   E200Z7_FPR_Bypass, E200Z7_FPR_Bypass]>,
  // FPU add/sub operations: efsadd, efssub - 4 cycle latency, can pair with ALU
  InstrItinData<IIC_FPAddSub,    [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                   InstrStage<1, [E200Z7_SPE], 0>,
                                   InstrStage<3, [E200Z7_SPE]>],
                                  [8, 1, 1, 1], // Latency = 4, Repeat rate = 1
                                  [E200Z7_FPR_Bypass,
                                   E200Z7_FPR_Bypass, E200Z7_FPR_Bypass]>,
  // FPU compare operations: efscmp* - 3 cycle latency, can pair with ALU
  InstrItinData<IIC_FPCompare,   [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                   InstrStage<1, [E200Z7_SPE], 0>,
                                   InstrStage<2, [E200Z7_SPE]>],
                                  [7, 1, 1, 1], // Latency = 3, Repeat rate = 1
                                  [E200Z7_CR_Bypass,
                                   E200Z7_FPR_Bypass, E200Z7_FPR_Bypass]>,
  // FPU divide: efsdiv - 25 cycle latency, cannot pair
  InstrItinData<IIC_FPDivS,      [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0], 0>,
                                   InstrStage<1, [E200Z7_SPE], 0>,
                                   InstrStage<24, [E200Z7_SPE]>],
                                  [29, 1, 1, 1], // Latency = 25, Repeat rate = 25
                                  [E200Z7_FPR_Bypass,
                                   E200Z7_FPR_Bypass, E200Z7_FPR_Bypass]>
]>;

// ===---------------------------------------------------------------------===//
// e200z7 machine model for scheduling and other instruction cost heuristics.
// Dual-issue pairing rules:
// 1. ALU0 + ALU1: Two integer ALU instructions can pair
// 2. ALU + Branch: ALU first, branch second
// 3. ALU + LSU: ALU first, load/store second
// 4. ALU + SPE/FPU: ALU first, FPU second
// 5. SPE/FPU can pair with ALU (FPU second instruction)
// 6. Instructions restricted to ALU0 cannot pair (div, mul, trap, etc.)

def PPCE200Z7Model : SchedMachineModel {
  let IssueWidth = 2;  // Dual-issue in-order processor.
  let LoadLatency = 4; // Load-to-use latency (optimistic with bypass).
                       // This is overriden by OperandCycles if the
                       // Itineraries are queried instead.
  let MicroOpBufferSize = 0; // In-order processor, no reorder buffer.
  let MispredictPenalty = 3;  // Branch misprediction penalty.
  let PostRAScheduler = 1;

  let CompleteModel = 0;

  let Itineraries = PPCE200Z7Itineraries;
}

