//===-- PPCScheduleE200Z4.td - e200z4 Scheduling Defs ---*- tablegen -*-===//
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
// All information is derived from the "e200z4 Power Architecture Core
// Reference Manual", NXP Document Number e200z4RM, Rev. 0, 10/2009.
//
//===----------------------------------------------------------------------===//
// Relevant functional units in the NXP e200z4 core:
//
//  * Fetch & Decode
//    Dual-issue in-order processor with 5-stage pipeline:
//    IF (Instruction Fetch), ID (Instruction Decode), EX (Execute),
//    MEM (Memory), WB (Write Back)
//    Can dispatch up to 2 instructions per clock cycle (dual-issue)
//
def E200Z4_FETCH : FuncUnit; // Instruction fetch stage
def E200Z4_DECODE : FuncUnit; // Instruction decode stage
def E200Z4_EX     : FuncUnit; // Execute stage
def E200Z4_MEM    : FuncUnit; // Memory stage
def E200Z4_WB     : FuncUnit; // Write back stage

//  * Dispatch (Dual-issue)
//    Two dispatch ports for dual-issue capability
def E200Z4_DIS0   : FuncUnit; // Dispatch port 0 (instruction 1)
def E200Z4_DIS1   : FuncUnit; // Dispatch port 1 (instruction 2)

//  * Execute
//    Multiple execution units: SU0, SU1, BU, LSU, MU, FPU/SPE
//    Some instructions can only execute in SU0 but not SU1
def E200Z4_SU0    : FuncUnit; // Simple unit 0
def E200Z4_SU1    : FuncUnit; // Simple unit 1 (limited instructions)
def E200Z4_ALU    : FuncUnit; // Integer ALU (alias for SU0)
def E200Z4_BU     : FuncUnit; // Branch unit
def E200Z4_LSU    : FuncUnit; // Load/store unit
def E200Z4_MUL    : FuncUnit; // Multiply unit
def E200Z4_FPU    : FuncUnit; // FPU pipeline (SPE-capable)
def E200Z4_SPE    : FuncUnit; // Signal Processing Extension unit
def E200Z4_ICache : FuncUnit; // Instruction cache (affects fetch timing)

// Bypass paths model register forwarding in the pipeline.
// GPR_Bypass: General-purpose register bypass (EX to EX forwarding for integer operations)
// CR_Bypass: Condition register bypass (CR field forwarding)
// SPE_Bypass: Signal Processing Engine bypass (SPE result forwarding for vector/FPU operations)
def E200Z4_GPR_Bypass : Bypass;
def E200Z4_CR_Bypass  : Bypass;
def E200Z4_SPE_Bypass : Bypass;

def PPCE200Z4Itineraries : ProcessorItineraries<
  [E200Z4_FETCH, E200Z4_DECODE, E200Z4_EX, E200Z4_MEM, E200Z4_WB,
   E200Z4_DIS0, E200Z4_DIS1, E200Z4_SU0, E200Z4_SU1, E200Z4_ALU,
   E200Z4_BU, E200Z4_LSU, E200Z4_MUL, E200Z4_FPU, E200Z4_SPE, E200Z4_ICache],
  [E200Z4_CR_Bypass, E200Z4_GPR_Bypass, E200Z4_SPE_Bypass], [
  InstrItinData<IIC_IntSimple,   [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX, E200Z4_ALU]>,
                                   InstrStage<1, [E200Z4_MEM]>,
                                   InstrStage<1, [E200Z4_WB]>],
                                  [5, 1, 1, 1, 1], // Latency = 1
                                  [E200Z4_GPR_Bypass,
                                   E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_IntGeneral,  [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX, E200Z4_ALU]>,
                                   InstrStage<1, [E200Z4_MEM]>,
                                   InstrStage<1, [E200Z4_WB]>],
                                  [5, 1, 1, 1, 1], // Latency = 1
                                  [E200Z4_GPR_Bypass,
                                   E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_IntISEL,     [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX, E200Z4_ALU]>,
                                   InstrStage<1, [E200Z4_MEM]>,
                                   InstrStage<1, [E200Z4_WB]>],
                                  [5, 1, 1, 1, 1, 1], // Latency = 1
                                  [E200Z4_GPR_Bypass,
                                   E200Z4_GPR_Bypass, E200Z4_GPR_Bypass,
                                   E200Z4_CR_Bypass]>,
  InstrItinData<IIC_IntCompare,  [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX, E200Z4_ALU]>,
                                   InstrStage<1, [E200Z4_MEM]>,
                                   InstrStage<1, [E200Z4_WB]>],
                                  [6, 1, 1, 1, 1], // Latency = 1 or 2
                                  [E200Z4_CR_Bypass,
                                   E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_IntDivW,     [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX, E200Z4_ALU], 0>,
                                   InstrStage<34, [E200Z4_EX, E200Z4_ALU]>],
                                  [38, 1, 1], // Latency = 34, Repeat rate = 34
                                  [E200Z4_GPR_Bypass,
                                   E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_IntMulHW,    [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX, E200Z4_MUL]>,
                                   InstrStage<4, [E200Z4_MEM]>,
                                   InstrStage<1, [E200Z4_WB]>],
                                  [8, 1, 1, 1, 1], // Latency = 4, Repeat rate = 1
                                  [E200Z4_GPR_Bypass,
                                   E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_IntMulHWU,   [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX, E200Z4_MUL]>,
                                   InstrStage<4, [E200Z4_MEM]>,
                                   InstrStage<1, [E200Z4_WB]>],
                                  [8, 1, 1, 1, 1], // Latency = 4, Repeat rate = 1
                                  [E200Z4_GPR_Bypass,
                                   E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_IntMulLI,    [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX, E200Z4_MUL]>,
                                   InstrStage<4, [E200Z4_MEM]>,
                                   InstrStage<1, [E200Z4_WB]>],
                                  [8, 1, 1, 1, 1], // Latency = 4, Repeat rate = 1
                                  [E200Z4_GPR_Bypass,
                                   E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_IntRotate,   [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX, E200Z4_ALU]>,
                                   InstrStage<1, [E200Z4_MEM]>,
                                   InstrStage<1, [E200Z4_WB]>],
                                  [5, 1, 1, 1, 1], // Latency = 1
                                  [E200Z4_GPR_Bypass,
                                   E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_IntShift,    [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX, E200Z4_ALU]>,
                                   InstrStage<1, [E200Z4_MEM]>,
                                   InstrStage<1, [E200Z4_WB]>],
                                  [5, 1, 1, 1, 1], // Latency = 1
                                  [E200Z4_GPR_Bypass,
                                   E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_IntTrapW,    [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<2, [E200Z4_EX, E200Z4_ALU]>,
                                   InstrStage<1, [E200Z4_MEM]>,
                                   InstrStage<1, [E200Z4_WB]>],
                                  [6, 1, 1, 1], // Latency = 2, Repeat rate = 2
                                  [E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_BrB,         [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX, E200Z4_BU]>],
                                  [4, 1, 1], // Latency = 1
                                  [NoBypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_BrCR,        [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX, E200Z4_BU]>],
                                  [4, 1, 1, 1], // Latency = 1
                                  [E200Z4_CR_Bypass,
                                   E200Z4_CR_Bypass, E200Z4_CR_Bypass]>,
  InstrItinData<IIC_BrMCR,       [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX, E200Z4_BU]>],
                                  [4, 1, 1], // Latency = 1
                                  [E200Z4_CR_Bypass, E200Z4_CR_Bypass]>,
  InstrItinData<IIC_BrMCRX,      [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX, E200Z4_ALU]>],
                                  [4, 1, 1, 1], // Latency = 1
                                  [E200Z4_CR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_LdStLoad,    [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX]>,
                                   InstrStage<1, [E200Z4_MEM, E200Z4_LSU]>,
                                   InstrStage<1, [E200Z4_WB]>],
                                  [6, 1, 1, 1, 1], // Latency = 3
                                  [E200Z4_GPR_Bypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_LdStLoadUpd, [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX, E200Z4_ALU], 0>,
                                   InstrStage<1, [E200Z4_MEM, E200Z4_LSU]>,
                                   InstrStage<1, [E200Z4_WB]>],
                                  [6, 1, 1, 1, 1], // Latency = 3
                                  [E200Z4_GPR_Bypass, E200Z4_GPR_Bypass],
                                  2>, // 2 micro-ops
  InstrItinData<IIC_LdStLoadUpdX,[InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX, E200Z4_ALU], 0>,
                                   InstrStage<1, [E200Z4_MEM, E200Z4_LSU]>,
                                   InstrStage<1, [E200Z4_WB]>],
                                  [6, 1, 1, 1, 1], // Latency = 3
                                  [E200Z4_GPR_Bypass, E200Z4_GPR_Bypass],
                                  2>, // 2 micro-ops
  InstrItinData<IIC_LdStStore,   [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX]>,
                                   InstrStage<1, [E200Z4_MEM, E200Z4_LSU]>],
                                  [5, 1, 1, 1], // Latency = 3
                                  [NoBypass, E200Z4_GPR_Bypass]>,
  InstrItinData<IIC_LdStSTU,     [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX, E200Z4_ALU], 0>,
                                   InstrStage<1, [E200Z4_MEM, E200Z4_LSU]>],
                                  [5, 1, 1, 1], // Latency = 3
                                  [NoBypass, E200Z4_GPR_Bypass],
                                  2>, // 2 micro-ops
  InstrItinData<IIC_LdStSTUX,    [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX, E200Z4_ALU], 0>,
                                   InstrStage<1, [E200Z4_MEM, E200Z4_LSU]>],
                                  [5, 1, 1, 1], // Latency = 3
                                  [NoBypass, E200Z4_GPR_Bypass],
                                  2>, // 2 micro-ops
  InstrItinData<IIC_SprMFSPR,    [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX, E200Z4_ALU]>,
                                   InstrStage<1, [E200Z4_MEM]>,
                                   InstrStage<1, [E200Z4_WB]>],
                                  [5, 1, 1, 1, 1], // Latency = 1, Repeat rate = 1
                                  [E200Z4_GPR_Bypass, E200Z4_CR_Bypass]>,
  InstrItinData<IIC_SprMTSPR,    [InstrStage<1, [E200Z4_FETCH], 0>,
                                   InstrStage<1, [E200Z4_DECODE], 0>,
                                   InstrStage<1, [E200Z4_EX, E200Z4_ALU]>,
                                   InstrStage<1, [E200Z4_MEM]>,
                                   InstrStage<1, [E200Z4_WB]>],
                                  [5, 1, 1, 1, 1], // Latency = 1, Repeat rate = 1
                                  [E200Z4_CR_Bypass, E200Z4_GPR_Bypass]>,
  // SPE instructions - cannot pair, must use DIS0 (dispatch port 0)
  // Note: DIS0 is used for e200z4 dual-issue dispatch (not ALU0 which is e200z7 terminology)
  // SPE simple operations: evaddw, evsubfw, evand, etc. - 1 cycle latency
  InstrItinData<IIC_VecGeneral,  [InstrStage<1, [E200Z4_FETCH, E200Z4_ICache], 0>,
                                   InstrStage<1, [E200Z4_DIS0], 0>,
                                   InstrStage<1, [E200Z4_SPE]>],
                                  [4, 1, 1], // Latency = 1, Repeat rate = 1
                                  [E200Z4_SPE_Bypass]>,
  // SPE complex operations: evaddsmiaaw, evsubfssiaaw, etc. - 4 cycle latency
  InstrItinData<IIC_VecComplex,  [InstrStage<1, [E200Z4_FETCH, E200Z4_ICache], 0>,
                                   InstrStage<1, [E200Z4_DIS0], 0>,
                                   InstrStage<1, [E200Z4_SPE], 0>,
                                   InstrStage<3, [E200Z4_SPE]>],
                                  [7, 1, 1], // Latency = 4, Repeat rate = 1
                                  [E200Z4_SPE_Bypass]>,
  // SPE FPU operations - cannot pair
  InstrItinData<IIC_FPGeneral,   [InstrStage<1, [E200Z4_FETCH, E200Z4_ICache], 0>,
                                   InstrStage<1, [E200Z4_DIS0], 0>,
                                   InstrStage<1, [E200Z4_SPE], 0>,
                                   InstrStage<2, [E200Z4_SPE]>],
                                  [6, 1, 1, 1], // Latency = 3, Repeat rate = 1
                                  [E200Z4_SPE_Bypass,
                                   E200Z4_SPE_Bypass, E200Z4_SPE_Bypass]>,
  InstrItinData<IIC_FPAddSub,    [InstrStage<1, [E200Z4_FETCH, E200Z4_ICache], 0>,
                                   InstrStage<1, [E200Z4_DIS0], 0>,
                                   InstrStage<1, [E200Z4_SPE], 0>,
                                   InstrStage<3, [E200Z4_SPE]>],
                                  [7, 1, 1, 1], // Latency = 4, Repeat rate = 1
                                  [E200Z4_SPE_Bypass,
                                   E200Z4_SPE_Bypass, E200Z4_SPE_Bypass]>,
  InstrItinData<IIC_FPCompare,   [InstrStage<1, [E200Z4_FETCH, E200Z4_ICache], 0>,
                                   InstrStage<1, [E200Z4_DIS0], 0>,
                                   InstrStage<1, [E200Z4_SPE], 0>,
                                   InstrStage<2, [E200Z4_SPE]>],
                                  [6, 1, 1, 1], // Latency = 3, Repeat rate = 1
                                  [E200Z4_CR_Bypass,
                                   E200Z4_SPE_Bypass, E200Z4_SPE_Bypass]>,
  InstrItinData<IIC_FPDivS,      [InstrStage<1, [E200Z4_FETCH, E200Z4_ICache], 0>,
                                   InstrStage<1, [E200Z4_DIS0], 0>,
                                   InstrStage<1, [E200Z4_SPE], 0>,
                                   InstrStage<24, [E200Z4_SPE]>],
                                  [29, 1, 1, 1], // Latency = 25, Repeat rate = 25
                                  [E200Z4_SPE_Bypass,
                                   E200Z4_SPE_Bypass, E200Z4_SPE_Bypass]>
]>;

// ===---------------------------------------------------------------------===//
// e200z4 machine model for scheduling and other instruction cost heuristics.
//
// DUAL-ISSUE PAIRING RULES (from e200z4RM manual, Chapter 4):
// NOTE: Exact pairing rules table needs to be extracted from manual Chapter 4.
// The scheduler does not currently enforce explicit pairing constraints.
// Known restrictions based on code comments:
// - SPE instructions cannot pair (must use DIS0 only)
// - Some instructions are restricted to SU0 only (not SU1)
// - Dispatch ports: DIS0 and DIS1 for dual-issue capability
//
// TODO: Extract complete pairing rules table from e200z4 Core Reference Manual
// Chapter 4, Section 4.X (Instruction Pipeline and Execution Timing) to:
// 1. Document which instruction types can pair
// 2. Specify exact pairing combinations
// 3. List SU0-only instruction restrictions
// 4. Model resource conflicts and pairing constraints
// 5. Set CompleteModel = 1 after validation

def PPCE200Z4Model : SchedMachineModel {
  let IssueWidth = 2;  // Dual-issue in-order processor.
  let LoadLatency = 4; // Load-to-use latency (optimistic with bypass).
                       // This is overriden by OperandCycles if the
                       // Itineraries are queried instead.
  let MicroOpBufferSize = 0; // In-order processor, no reorder buffer.
  let MispredictPenalty = 3;  // Branch misprediction penalty.
  let PostRAScheduler = 1;

  let CompleteModel = 0; // Incomplete: Missing explicit dual-issue pairing rules
                         // and resource conflict modeling. Need to extract from
                         // e200z4 Core Reference Manual Chapter 4.

  let Itineraries = PPCE200Z4Itineraries;
}
