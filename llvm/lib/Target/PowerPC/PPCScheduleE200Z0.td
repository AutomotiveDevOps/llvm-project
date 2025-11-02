//===-- PPCScheduleE200Z0.td - e200z0 Scheduling Defs ---*- tablegen -*-===//
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
// All information is derived from the "e200z0 Core Reference Manual",
// NXP Document Number E200Z0CRM.
//
//===----------------------------------------------------------------------===//
// Relevant functional units in the NXP e200z0 core:
//
//  * Fetch & Decode
//    Single-issue in-order processor with 5-stage pipeline:
//    IF (Instruction Fetch), ID (Instruction Decode), EX (Execute),
//    MEM (Memory), WB (Write Back)
//
def E200Z0_FETCH : FuncUnit; // Instruction fetch stage
def E200Z0_DECODE : FuncUnit; // Instruction decode stage
def E200Z0_EX     : FuncUnit; // Execute stage
def E200Z0_MEM    : FuncUnit; // Memory stage
def E200Z0_WB     : FuncUnit; // Write back stage

//  * Execute
//    Single execution unit for integer operations, branch unit, and LSU.
def E200Z0_ALU    : FuncUnit; // Integer ALU
def E200Z0_BU     : FuncUnit; // Branch unit
def E200Z0_LSU    : FuncUnit; // Load/store unit
def E200Z0_MUL    : FuncUnit; // Multiply unit

def E200Z0_GPR_Bypass : Bypass;
def E200Z0_CR_Bypass  : Bypass;

def PPCE200Z0Itineraries : ProcessorItineraries<
  [E200Z0_FETCH, E200Z0_DECODE, E200Z0_EX, E200Z0_MEM, E200Z0_WB,
   E200Z0_ALU, E200Z0_BU, E200Z0_LSU, E200Z0_MUL],
  [E200Z0_CR_Bypass, E200Z0_GPR_Bypass], [
  InstrItinData<IIC_IntSimple,   [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX, E200Z0_ALU]>,
                                   InstrStage<1, [E200Z0_MEM]>,
                                   InstrStage<1, [E200Z0_WB]>],
                                  [5, 1, 1, 1, 1], // Latency = 1
                                  [E200Z0_GPR_Bypass,
                                   E200Z0_GPR_Bypass, E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_IntGeneral,  [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX, E200Z0_ALU]>,
                                   InstrStage<1, [E200Z0_MEM]>,
                                   InstrStage<1, [E200Z0_WB]>],
                                  [5, 1, 1, 1, 1], // Latency = 1
                                  [E200Z0_GPR_Bypass,
                                   E200Z0_GPR_Bypass, E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_IntISEL,     [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX, E200Z0_ALU]>,
                                   InstrStage<1, [E200Z0_MEM]>,
                                   InstrStage<1, [E200Z0_WB]>],
                                  [5, 1, 1, 1, 1, 1], // Latency = 1
                                  [E200Z0_GPR_Bypass,
                                   E200Z0_GPR_Bypass, E200Z0_GPR_Bypass,
                                   E200Z0_CR_Bypass]>,
  InstrItinData<IIC_IntCompare,  [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX, E200Z0_ALU]>,
                                   InstrStage<1, [E200Z0_MEM]>,
                                   InstrStage<1, [E200Z0_WB]>],
                                  [6, 1, 1, 1, 1], // Latency = 1 or 2
                                  [E200Z0_CR_Bypass,
                                   E200Z0_GPR_Bypass, E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_IntDivW,     [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX, E200Z0_ALU], 0>,
                                   InstrStage<34, [E200Z0_EX, E200Z0_ALU]>],
                                  [38, 1, 1], // Latency = 34, Repeat rate = 34
                                  [E200Z0_GPR_Bypass,
                                   E200Z0_GPR_Bypass, E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_IntMulHW,    [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX, E200Z0_MUL]>,
                                   InstrStage<4, [E200Z0_MEM]>,
                                   InstrStage<1, [E200Z0_WB]>],
                                  [8, 1, 1, 1, 1], // Latency = 4, Repeat rate = 1
                                  [E200Z0_GPR_Bypass,
                                   E200Z0_GPR_Bypass, E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_IntMulHWU,   [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX, E200Z0_MUL]>,
                                   InstrStage<4, [E200Z0_MEM]>,
                                   InstrStage<1, [E200Z0_WB]>],
                                  [8, 1, 1, 1, 1], // Latency = 4, Repeat rate = 1
                                  [E200Z0_GPR_Bypass,
                                   E200Z0_GPR_Bypass, E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_IntMulLI,    [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX, E200Z0_MUL]>,
                                   InstrStage<4, [E200Z0_MEM]>,
                                   InstrStage<1, [E200Z0_WB]>],
                                  [8, 1, 1, 1, 1], // Latency = 4, Repeat rate = 1
                                  [E200Z0_GPR_Bypass,
                                   E200Z0_GPR_Bypass, E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_IntRotate,   [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX, E200Z0_ALU]>,
                                   InstrStage<1, [E200Z0_MEM]>,
                                   InstrStage<1, [E200Z0_WB]>],
                                  [5, 1, 1, 1, 1], // Latency = 1
                                  [E200Z0_GPR_Bypass,
                                   E200Z0_GPR_Bypass, E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_IntShift,    [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX, E200Z0_ALU]>,
                                   InstrStage<1, [E200Z0_MEM]>,
                                   InstrStage<1, [E200Z0_WB]>],
                                  [5, 1, 1, 1, 1], // Latency = 1
                                  [E200Z0_GPR_Bypass,
                                   E200Z0_GPR_Bypass, E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_IntTrapW,    [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<2, [E200Z0_EX, E200Z0_ALU]>,
                                   InstrStage<1, [E200Z0_MEM]>,
                                   InstrStage<1, [E200Z0_WB]>],
                                  [6, 1, 1, 1], // Latency = 2, Repeat rate = 2
                                  [E200Z0_GPR_Bypass, E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_BrB,         [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX, E200Z0_BU]>],
                                  [4, 1, 1], // Latency = 1
                                  [NoBypass, E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_BrCR,        [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX, E200Z0_BU]>],
                                  [4, 1, 1, 1], // Latency = 1
                                  [E200Z0_CR_Bypass,
                                   E200Z0_CR_Bypass, E200Z0_CR_Bypass]>,
  InstrItinData<IIC_BrMCR,       [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX, E200Z0_BU]>],
                                  [4, 1, 1], // Latency = 1
                                  [E200Z0_CR_Bypass, E200Z0_CR_Bypass]>,
  InstrItinData<IIC_BrMCRX,      [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX, E200Z0_ALU]>],
                                  [4, 1, 1, 1], // Latency = 1
                                  [E200Z0_CR_Bypass, E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_LdStLoad,    [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX]>,
                                   InstrStage<1, [E200Z0_MEM, E200Z0_LSU]>,
                                   InstrStage<1, [E200Z0_WB]>],
                                  [6, 1, 1, 1, 1], // Latency = 3
                                  [E200Z0_GPR_Bypass, E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_LdStLoadUpd, [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX, E200Z0_ALU], 0>,
                                   InstrStage<1, [E200Z0_MEM, E200Z0_LSU]>,
                                   InstrStage<1, [E200Z0_WB]>],
                                  [6, 1, 1, 1, 1], // Latency = 3
                                  [E200Z0_GPR_Bypass, E200Z0_GPR_Bypass],
                                  2>, // 2 micro-ops
  InstrItinData<IIC_LdStLoadUpdX,[InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX, E200Z0_ALU], 0>,
                                   InstrStage<1, [E200Z0_MEM, E200Z0_LSU]>,
                                   InstrStage<1, [E200Z0_WB]>],
                                  [6, 1, 1, 1, 1], // Latency = 3
                                  [E200Z0_GPR_Bypass, E200Z0_GPR_Bypass],
                                  2>, // 2 micro-ops
  InstrItinData<IIC_LdStStore,   [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX]>,
                                   InstrStage<1, [E200Z0_MEM, E200Z0_LSU]>],
                                  [5, 1, 1, 1], // Latency = 3
                                  [NoBypass, E200Z0_GPR_Bypass]>,
  InstrItinData<IIC_LdStSTU,     [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX, E200Z0_ALU], 0>,
                                   InstrStage<1, [E200Z0_MEM, E200Z0_LSU]>],
                                  [5, 1, 1, 1], // Latency = 3
                                  [NoBypass, E200Z0_GPR_Bypass],
                                  2>, // 2 micro-ops
  InstrItinData<IIC_LdStSTUX,    [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX, E200Z0_ALU], 0>,
                                   InstrStage<1, [E200Z0_MEM, E200Z0_LSU]>],
                                  [5, 1, 1, 1], // Latency = 3
                                  [NoBypass, E200Z0_GPR_Bypass],
                                  2>, // 2 micro-ops
  InstrItinData<IIC_SprMFSPR,    [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX, E200Z0_ALU]>,
                                   InstrStage<1, [E200Z0_MEM]>,
                                   InstrStage<1, [E200Z0_WB]>],
                                  [5, 1, 1, 1, 1], // Latency = 1, Repeat rate = 1
                                  [E200Z0_GPR_Bypass, E200Z0_CR_Bypass]>,
  InstrItinData<IIC_SprMTSPR,    [InstrStage<1, [E200Z0_FETCH], 0>,
                                   InstrStage<1, [E200Z0_DECODE], 0>,
                                   InstrStage<1, [E200Z0_EX, E200Z0_ALU]>,
                                   InstrStage<1, [E200Z0_MEM]>,
                                   InstrStage<1, [E200Z0_WB]>],
                                  [5, 1, 1, 1, 1], // Latency = 1, Repeat rate = 1
                                  [E200Z0_CR_Bypass, E200Z0_GPR_Bypass]>
]>;

// ===---------------------------------------------------------------------===//
// e200z0 machine model for scheduling and other instruction cost heuristics.

def PPCE200Z0Model : SchedMachineModel {
  let IssueWidth = 1;  // Single-issue in-order processor.
  let LoadLatency = 4; // Load-to-use latency (3 cycles + 1 for writeback).
                       // This is overriden by OperandCycles if the
                       // Itineraries are queried instead.
  let MicroOpBufferSize = 0; // In-order processor, no reorder buffer.
  let MispredictPenalty = 3;  // Branch misprediction penalty.
  let PostRAScheduler = 1;

  let CompleteModel = 0;

  let Itineraries = PPCE200Z0Itineraries;
}

