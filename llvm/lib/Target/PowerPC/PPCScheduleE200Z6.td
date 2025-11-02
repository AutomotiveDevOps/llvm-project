//===-- PPCScheduleE200Z6.td - e200z6 Scheduling Defs ---*- tablegen -*-===//
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
// All information is derived from the "e200z6 Core Reference Manual".
// Note: This model has been corrected to reflect single-issue behavior
// (previously incorrectly modeled as dual-issue).
//
//===----------------------------------------------------------------------===//
// Relevant functional units in the NXP e200z6 core:
//
//  * Fetch & Decode
//    Single-issue in-order processor with 7-stage pipeline:
//    IF1, IF2 (Instruction Fetch stages), ID (Instruction Decode), 
//    EX (Execute), MEM (Memory), WB1, WB2 (Write Back stages)
//    Note: e200z6 has a 7-stage pipeline with unified 32KB L1 cache
//
def E200Z6_FETCH : FuncUnit; // Instruction fetch stage
def E200Z6_DECODE : FuncUnit; // Instruction decode stage
def E200Z6_EX     : FuncUnit; // Execute stage
def E200Z6_MEM    : FuncUnit; // Memory stage
def E200Z6_WB     : FuncUnit; // Write back stage

//  * Execute
//    Single execution unit for integer operations, branch unit, LSU, and FPU.
//    e200z6 has FPU support with unified cache (32KB L1)
//    Resource sharing constraints:
//    - Single-issue processor: Only one instruction executes per cycle
//    - MUL, FPU, and LSU share execution resources and cannot execute simultaneously
//    - ALU operations can execute concurrently with other units when supported
//    - Branch unit operates independently but still subject to single-issue constraint
def E200Z6_ALU    : FuncUnit; // Integer ALU
def E200Z6_BU     : FuncUnit; // Branch unit
def E200Z6_LSU    : FuncUnit; // Load/store unit (shares execution resources with MUL/FPU)
def E200Z6_MUL    : FuncUnit; // Multiply unit (shares execution resources with FPU/LSU)
def E200Z6_FPU    : FuncUnit; // Floating-point unit (shares execution resources with MUL/LSU)

// Bypass paths model register forwarding in the pipeline.
// GPR_Bypass: General-purpose register bypass (EX to EX forwarding for integer operations)
// CR_Bypass: Condition register bypass (CR field forwarding)
// FPR_Bypass: Floating-point register bypass (FPU result forwarding)
def E200Z6_GPR_Bypass : Bypass;
def E200Z6_CR_Bypass  : Bypass;
def E200Z6_FPR_Bypass : Bypass;

def PPCE200Z6Itineraries : ProcessorItineraries<
  [E200Z6_FETCH, E200Z6_DECODE, E200Z6_EX, E200Z6_MEM, E200Z6_WB,
   E200Z6_ALU, E200Z6_BU, E200Z6_LSU, E200Z6_MUL, E200Z6_FPU],
  [E200Z6_CR_Bypass, E200Z6_GPR_Bypass, E200Z6_FPR_Bypass], [
  InstrItinData<IIC_IntSimple,   [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX, E200Z6_ALU]>,
                                   InstrStage<1, [E200Z6_MEM]>,
                                   InstrStage<1, [E200Z6_WB]>],
                                  [5, 1, 1, 1, 1], // Latency = 1
                                  [E200Z6_GPR_Bypass,
                                   E200Z6_GPR_Bypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_IntGeneral,  [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX, E200Z6_ALU]>,
                                   InstrStage<1, [E200Z6_MEM]>,
                                   InstrStage<1, [E200Z6_WB]>],
                                  [5, 1, 1, 1, 1], // Latency = 1
                                  [E200Z6_GPR_Bypass,
                                   E200Z6_GPR_Bypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_IntISEL,     [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX, E200Z6_ALU]>,
                                   InstrStage<1, [E200Z6_MEM]>,
                                   InstrStage<1, [E200Z6_WB]>],
                                  [5, 1, 1, 1, 1, 1], // Latency = 1
                                  [E200Z6_GPR_Bypass,
                                   E200Z6_GPR_Bypass, E200Z6_GPR_Bypass,
                                   E200Z6_CR_Bypass]>,
  InstrItinData<IIC_IntCompare,  [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX, E200Z6_ALU]>,
                                   InstrStage<1, [E200Z6_MEM]>,
                                   InstrStage<1, [E200Z6_WB]>],
                                  [6, 1, 1, 1, 1], // Latency = 1 or 2
                                  [E200Z6_CR_Bypass,
                                   E200Z6_GPR_Bypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_IntDivW,     [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX, E200Z6_ALU], 0>,
                                   InstrStage<15, [E200Z6_EX, E200Z6_ALU]>],
                                  [19, 1, 1], // Latency = 16 (worst case), Repeat rate = 16
                                  // Manual: 6-16 cycles (data-dependent), worst case 16 cycles (blocking)
                                  [E200Z6_GPR_Bypass,
                                   E200Z6_GPR_Bypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_IntMulHW,    [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX, E200Z6_MUL]>,
                                   InstrStage<2, [E200Z6_MEM]>,
                                   InstrStage<1, [E200Z6_WB]>],
                                  [7, 1, 1, 1, 1], // Latency = 3, Repeat rate = 1
                                  // Manual: 3-cycle latency, 1 per cycle throughput (pipelined)
                                  [E200Z6_GPR_Bypass,
                                   E200Z6_GPR_Bypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_IntMulHWU,   [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX, E200Z6_MUL]>,
                                   InstrStage<2, [E200Z6_MEM]>,
                                   InstrStage<1, [E200Z6_WB]>],
                                  [7, 1, 1, 1, 1], // Latency = 3, Repeat rate = 1
                                  // Manual: 3-cycle latency, 1 per cycle throughput (pipelined)
                                  [E200Z6_GPR_Bypass,
                                   E200Z6_GPR_Bypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_IntMulLI,    [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX, E200Z6_MUL]>,
                                   InstrStage<2, [E200Z6_MEM]>,
                                   InstrStage<1, [E200Z6_WB]>],
                                  [7, 1, 1, 1, 1], // Latency = 3, Repeat rate = 1
                                  // Manual: 3-cycle latency, 1 per cycle throughput (pipelined)
                                  [E200Z6_GPR_Bypass,
                                   E200Z6_GPR_Bypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_IntRotate,   [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX, E200Z6_ALU]>,
                                   InstrStage<1, [E200Z6_MEM]>,
                                   InstrStage<1, [E200Z6_WB]>],
                                  [5, 1, 1, 1, 1], // Latency = 1
                                  [E200Z6_GPR_Bypass,
                                   E200Z6_GPR_Bypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_IntShift,    [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX, E200Z6_ALU]>,
                                   InstrStage<1, [E200Z6_MEM]>,
                                   InstrStage<1, [E200Z6_WB]>],
                                  [5, 1, 1, 1, 1], // Latency = 1
                                  [E200Z6_GPR_Bypass,
                                   E200Z6_GPR_Bypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_IntTrapW,    [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<2, [E200Z6_EX, E200Z6_ALU]>,
                                   InstrStage<1, [E200Z6_MEM]>,
                                   InstrStage<1, [E200Z6_WB]>],
                                  [6, 1, 1, 1], // Latency = 2, Repeat rate = 2
                                  [E200Z6_GPR_Bypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_BrB,         [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX, E200Z6_BU]>],
                                  [4, 1, 1], // Latency = 1
                                  [NoBypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_BrCR,        [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX, E200Z6_BU]>],
                                  [4, 1, 1, 1], // Latency = 1
                                  [E200Z6_CR_Bypass,
                                   E200Z6_CR_Bypass, E200Z6_CR_Bypass]>,
  InstrItinData<IIC_BrMCR,       [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX, E200Z6_BU]>],
                                  [4, 1, 1], // Latency = 1
                                  [E200Z6_CR_Bypass, E200Z6_CR_Bypass]>,
  InstrItinData<IIC_BrMCRX,      [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX, E200Z6_ALU]>],
                                  [4, 1, 1, 1], // Latency = 1
                                  [E200Z6_CR_Bypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_LdStLoad,    [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX]>,
                                   InstrStage<1, [E200Z6_MEM, E200Z6_LSU]>,
                                   InstrStage<1, [E200Z6_WB]>],
                                  [6, 1, 1, 1, 1], // Latency = 3
                                  // Manual: 3-cycle latency, 1 per cycle throughput (pipelined)
                                  [E200Z6_GPR_Bypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_LdStLoadUpd, [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX, E200Z6_ALU], 0>,
                                   InstrStage<1, [E200Z6_MEM, E200Z6_LSU]>,
                                   InstrStage<1, [E200Z6_WB]>],
                                  [6, 1, 1, 1, 1], // Latency = 3 (same as regular load)
                                  // Manual: 3-cycle latency, 1 per cycle throughput
                                  [E200Z6_GPR_Bypass, E200Z6_GPR_Bypass],
                                  2>, // 2 micro-ops
  InstrItinData<IIC_LdStLoadUpdX,[InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX, E200Z6_ALU], 0>,
                                   InstrStage<1, [E200Z6_MEM, E200Z6_LSU]>,
                                   InstrStage<1, [E200Z6_WB]>],
                                  [6, 1, 1, 1, 1], // Latency = 3 (same as regular load)
                                  // Manual: 3-cycle latency, 1 per cycle throughput
                                  [E200Z6_GPR_Bypass, E200Z6_GPR_Bypass],
                                  2>, // 2 micro-ops
  InstrItinData<IIC_LdStStore,   [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX]>,
                                   InstrStage<1, [E200Z6_MEM, E200Z6_LSU]>],
                                  [5, 1, 1, 1], // Latency = 3
                                  // Manual: 3-cycle latency, 1 per cycle throughput (pipelined)
                                  [NoBypass, E200Z6_GPR_Bypass]>,
  InstrItinData<IIC_LdStSTU,     [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX, E200Z6_ALU], 0>,
                                   InstrStage<1, [E200Z6_MEM, E200Z6_LSU]>],
                                  [5, 1, 1, 1], // Latency = 3 (same as regular store)
                                  // Manual: 3-cycle latency, 1 per cycle throughput
                                  [NoBypass, E200Z6_GPR_Bypass],
                                  2>, // 2 micro-ops
  InstrItinData<IIC_LdStSTUX,    [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX, E200Z6_ALU], 0>,
                                   InstrStage<1, [E200Z6_MEM, E200Z6_LSU]>],
                                  [5, 1, 1, 1], // Latency = 3 (same as regular store)
                                  // Manual: 3-cycle latency, 1 per cycle throughput
                                  [NoBypass, E200Z6_GPR_Bypass],
                                  2>, // 2 micro-ops
  InstrItinData<IIC_SprMFSPR,    [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX, E200Z6_ALU]>,
                                   InstrStage<1, [E200Z6_MEM]>,
                                   InstrStage<1, [E200Z6_WB]>],
                                  [5, 1, 1, 1, 1], // Latency = 1, Repeat rate = 1
                                  [E200Z6_GPR_Bypass, E200Z6_CR_Bypass]>,
  InstrItinData<IIC_SprMTSPR,    [InstrStage<1, [E200Z6_FETCH], 0>,
                                   InstrStage<1, [E200Z6_DECODE], 0>,
                                   InstrStage<1, [E200Z6_EX, E200Z6_ALU]>,
                                   InstrStage<1, [E200Z6_MEM]>,
                                   InstrStage<1, [E200Z6_WB]>],
                                  [5, 1, 1, 1, 1], // Latency = 1, Repeat rate = 1
                                  [E200Z6_CR_Bypass, E200Z6_GPR_Bypass]>
]>;

// ===---------------------------------------------------------------------===//
// e200z6 machine model for scheduling and other instruction cost heuristics.
// CORRECTED: Single-issue processor (previously incorrectly modeled as dual-issue).

def PPCE200Z6Model : SchedMachineModel {
  let IssueWidth = 1;  // Single-issue in-order processor.
                       // CORRECTED: Was incorrectly modeled as dual-issue.
  let LoadLatency = 4; // Load-to-use latency (manual: 3-cycle latency + 1 cycle writeback).
                       // Loads have 3-cycle latency with 1 per cycle throughput (pipelined).
                       // This is overriden by OperandCycles if the Itineraries are queried instead.
  let MicroOpBufferSize = 0; // In-order processor, no reorder buffer.
  let MispredictPenalty = 3;  // Branch misprediction penalty.
  let PostRAScheduler = 1;

  let CompleteModel = 0;

  let Itineraries = PPCE200Z6Itineraries;
}
