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
// NXP Document Number E200Z7CRM (Rev. 2, 2012), specifically the e200z760n3
// variant.
//
// NOTE: This scheduling model is validated against the e200z760n3 manual,
// but is compatible with e200z759n3 variant as both share the same core
// microarchitecture (dual-issue in-order e200z7 Book E cores). Differences
// between variants are primarily in documentation detail and device
// integration (e.g., MMU scale), not in instruction timing or scheduling
// behavior.
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

// Bypass paths model register forwarding in the pipeline.
// GPR_Bypass: General-purpose register bypass (EX to EX forwarding for integer operations)
// CR_Bypass: Condition register bypass (CR field forwarding)
// SPE_Bypass: Signal Processing Engine bypass (SPE result forwarding for vector operations)
// FPR_Bypass: Floating-point register bypass (FPU result forwarding)
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
                                   InstrStage<15, [E200Z7_ALU0]>],
                                  [19, 1, 1], // Latency = 15 (worst case), Repeat rate = 15
                                  // Manual (E200Z7CRM Ch. 4, Table 4-3): 4-15 cycles (data dependent, worst case 15)
                                  // Manual (E200Z7CRM Ch. 4.2.1): Blocking divide, pipeline unavailable during execution
                                  [E200Z7_GPR_Bypass,
                                   E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntMulHW,    [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0], 0>,
                                   InstrStage<1, [E200Z7_ALU0, E200Z7_MUL]>,
                                   InstrStage<3, [E200Z7_MUL]>],
                                  [7, 1, 1], // Latency = 4 (record form), Result data = 3 cycles
                                  // Manual (E200Z7CRM Ch. 4, Table 4-3): 3 cycles for result data, 4 cycles for record form conditions
                                  // Manual (E200Z7CRM Ch. 4.2.1): Throughput = 1 per cycle
                                  [E200Z7_GPR_Bypass,
                                   E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntMulHWU,   [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0], 0>,
                                   InstrStage<1, [E200Z7_ALU0, E200Z7_MUL]>,
                                   InstrStage<3, [E200Z7_MUL]>],
                                  [7, 1, 1], // Latency = 4 (record form), Result data = 3 cycles
                                  // Manual (E200Z7CRM Ch. 4, Table 4-3): 3 cycles for result data, 4 cycles for record form conditions
                                  [E200Z7_GPR_Bypass,
                                   E200Z7_GPR_Bypass, E200Z7_GPR_Bypass]>,
  InstrItinData<IIC_IntMulLI,    [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0], 0>,
                                   InstrStage<1, [E200Z7_ALU0, E200Z7_MUL]>,
                                   InstrStage<3, [E200Z7_MUL]>],
                                  [7, 1, 1], // Latency = 4 (record form), Result data = 3 cycles
                                  // Manual (E200Z7CRM Ch. 4, Table 4-3): 3 cycles for result data, 4 cycles for record form conditions
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
                                  [6, 1, 1], // Latency = 3, Repeat rate = 1
                                  // Manual (E200Z7CRM Ch. 4, Table 4-3): 3 cycles latency, 1 cycle throughput
                                  // Manual (E200Z7CRM Ch. 4.2.2): Loads execute with maximum throughput of 1 per cycle
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
  // FPU add/sub operations: efsadd, efssub, efdadd, efdsub - 4 cycle latency, can pair with ALU
  InstrItinData<IIC_FPAddSub,    [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0, E200Z7_DIS1], 0>,
                                   InstrStage<1, [E200Z7_SPE], 0>,
                                   InstrStage<3, [E200Z7_SPE]>],
                                  [8, 1, 1, 1], // Latency = 4, Repeat rate = 1
                                  // Manual (E200Z7CRM Ch. 4, Table 4-3): EFPU add/sub/compare/multiply/MAC = 4 cycles latency
                                  // Manual (E200Z7CRM Ch. 4.2.3): Maximum throughput of 1 per cycle
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
  // FPU divide: efsdiv, efddiv - 9 cycle latency, blocking, cannot pair
  InstrItinData<IIC_FPDivS,      [InstrStage<1, [E200Z7_FETCH], 0>,
                                   InstrStage<1, [E200Z7_DIS0], 0>,
                                   InstrStage<1, [E200Z7_SPE], 0>,
                                   InstrStage<9, [E200Z7_SPE]>],
                                  [13, 1, 1, 1], // Latency = 9, Repeat rate = 9
                                  // Manual (E200Z7CRM Ch. 4, Table 4-3): EFPU divide = 9 cycles latency
                                  // Manual (E200Z7CRM Ch. 4.2.3): Blocking divide, pipeline unavailable during execution
                                  [E200Z7_FPR_Bypass,
                                   E200Z7_FPR_Bypass, E200Z7_FPR_Bypass]>
]>;

// ===---------------------------------------------------------------------===//
// e200z7 machine model for scheduling and other instruction cost heuristics.
//
// DUAL-ISSUE PAIRING RULES (from E200Z7CRM manual, Chapter 4, Table 4-1, page 4-19):
// Table 4-1: Concurrent Instruction Issue Capabilities shows explicit pairing matrix:
// - Scalar integer + Scalar integer: ✓ (Excludes divide class in both slots)
// - Scalar integer + Scalar float: ✓
// - Scalar integer + Vector integer: ✓ (Excludes vector MAC/multiply with scalar multiply/divide)
// - Scalar integer + Vector float: ✓
// - Scalar float + Vector integer: ✓
// - Scalar float + Vector float: — (Cannot pair)
// - Vector integer + Vector integer: ✓ (Excludes vector MAC/multiply in both slots, or divide in both)
// - Vector integer + Vector float: ✓
// - Vector float + Vector float: — (Cannot pair)
// - Load/store can pair with most instruction types
// - Branch can pair with most instruction types
// - Special instructions cannot pair with anything
//
// Additional pairing rules (from code analysis):
//
// 1. ALU0 + ALU1: Two integer ALU instructions can pair
// 2. ALU + Branch: ALU first, branch second
// 3. ALU + LSU: ALU first, load/store second
// 4. ALU + SPE/FPU: ALU first, FPU second
// 5. SPE/FPU can pair with ALU (FPU second instruction)
// 6. Instructions restricted to ALU0 cannot pair (div, mul, trap, etc.)
//
// RESOURCE CONFLICT MODELING FOR PAIRING RESTRICTIONS:
// The scheduler relies on functional unit resource conflicts to enforce pairing rules:
// - Instructions restricted to ALU0 (divide, multiply, trap) use DIS0 only, preventing pairing
// - Single LSU unit: Prevents two load/stores from pairing
// - Single SPE/FPU unit: Used by vector/FPU operations
// - MUL unit in ALU0: Multiply instructions restricted to ALU0
//
// NOTE: Complete pairing rules table extraction needed from E200Z7CRM manual Chapter 4
// for explicit pairing matrix (similar to e200z4 Table 4-1).

def PPCE200Z7Model : SchedMachineModel {
  let IssueWidth = 2;  // Dual-issue in-order processor.
  let LoadLatency = 3; // Load-to-use latency (from fetch to data available).
                       // Manual (E200Z7CRM Ch. 4, Table 4-3): Loads (non-multiple) = 3 cycles latency
                       // Manual (E200Z7CRM Ch. 4.2.2): Loads execute with maximum throughput of 1 per cycle
                       // This is overriden by OperandCycles if the
                       // Itineraries are queried instead.
  let MicroOpBufferSize = 0; // In-order processor, no reorder buffer.
  let MispredictPenalty = 6;  // Branch misprediction penalty (worst case).
                               // Manual (E200Z7CRM Ch. 4, Table 4-3): Branch = 6/4/1 cycles
                               // Manual (E200Z7CRM Ch. 4, Table 4-3): Worst-case mispredicted branch is 6 cycles
                               // Manual (E200Z7CRM Ch. 4.3.5, Figure 4-9, 4-12): Shows 6 cycles for incorrect prediction cases
  let PostRAScheduler = 1;

  let CompleteModel = 0; // Model updated with manual timing values, but still pending full validation.
                         // Key latencies updated: divide (32→15), load (4→3), branch mispredict (3→6), FP divide (25→9)
                         // Pairing rules from Table 4-1 documented above.
                         // See e200z7_manual_extracted_data.sdoc for full extraction status and remaining validations.

  let Itineraries = PPCE200Z7Itineraries;
}

