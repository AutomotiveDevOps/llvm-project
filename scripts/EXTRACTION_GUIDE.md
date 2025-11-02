# e200z7/e200z760 Manual Extraction Guide

This guide outlines what information needs to be extracted from the e200z7/e200z760 Core Reference Manual for LLVM implementation validation.

## Critical Information to Extract

### 1. Chapter 4: Instruction Pipeline and Execution Timing

#### Dual-Issue Pairing Rules (Table 4-1 or equivalent)
Extract the complete pairing rules table that shows:
- Which instruction types can pair together
- ALU0 vs ALU1 restrictions
- SPE/FPU pairing restrictions
- LSU pairing restrictions
- Branch instruction pairing rules
- Instructions that cannot pair

**Example format (from e200z4 manual):**
```
Instruction Type A | Instruction Type B | Can Pair? | Restrictions
ALU               | ALU               | Yes       | Different ALU (0/1)
ALU               | Branch             | Yes       | Branch must be second
ALU               | LSU                | Yes       | LSU must be second
SPE/FPU           | ALU                | Yes       | FPU must be second
...
```

#### Instruction Timing Specifications
For each instruction category, extract:
- **Latency** (cycles from issue to result available)
- **Repeat rate** (cycles between consecutive issues)
- **Pipeline stages** (which stages the instruction uses)

Key instruction categories:
1. **Integer Instructions:**
   - Simple ALU operations (add, sub, and, or, xor, etc.)
   - Compare operations
   - Multiply instructions (mulhw, mulli, mullw, etc.)
   - Divide instructions (divw, divwu, etc.)
   - Shift/rotate instructions
   - ISEL (integer select)

2. **Load/Store Instructions:**
   - Load byte/halfword/word
   - Store byte/halfword/word
   - Load/store with update
   - Indexed vs. direct addressing
   - Load latency (from issue to data available)

3. **Floating-Point Instructions (SPE/FPU):**
   - SPE single-precision (EFS* instructions)
   - SPE double-precision (EFD* instructions)
   - SPE vector operations (EV* instructions)
   - Traditional FPU operations (if supported)
   - Floating-point divide latency
   - Floating-point multiply latency
   - Conversion operations (int to float, float to int)

4. **Branch Instructions:**
   - Conditional branch latency
   - Unconditional branch latency
   - Branch misprediction penalty
   - Branch target buffer behavior

5. **Other Instructions:**
   - SPR (Special Purpose Register) access
   - Cache management instructions
   - Synchronization instructions (msync, etc.)

#### Functional Unit Specifications
Extract details about:
- **ALU0 and ALU1:**
  - Which operations are restricted to ALU0 only
  - Which operations can use either ALU
  - ALU1 limitations/restrictions

- **MUL Unit:**
  - Location (confirmed as part of ALU0)
  - Latency for different multiply types
  - Throughput

- **SPE/FPU Unit:**
  - SPE vs FPU mode differences
  - Shared resources
  - Pipeline stages

- **LSU (Load/Store Unit):**
  - Load latency
  - Store latency
  - Addressing mode differences

- **Branch Unit:**
  - Prediction mechanisms
  - Misprediction handling

#### Bypass Paths
Extract information about:
- GPR bypass (general-purpose register forwarding)
- CR bypass (condition register forwarding)
- SPE bypass (SPE result forwarding)
- FPR bypass (floating-point register forwarding)
- Bypass latency/cycles

### 2. Register File Specifications

#### SPE Register Model
- How SPE uses GPR registers (S0-S31 map to R0-R31)
- Single-precision vs double-precision register usage
- SPE accumulator behavior

#### FPU Register Model (if different from SPE)
- Dedicated FPR registers (F0-F31)
- Single vs double precision storage

### 3. Compare with Current LLVM Implementation

After extraction, compare against:

1. **PPCScheduleE200Z7.td:**
   - Verify all latency values match manual
   - Check pipeline stage modeling
   - Validate functional unit assignments

2. **PPC.td:**
   - Verify e200z7 processor features
   - Check SPE vs FPU configuration
   - Validate instruction predicates

3. **PPCSubtarget.cpp:**
   - Verify SPE/FPU mutual exclusivity logic
   - Check feature detection

## Extraction Script Usage

```bash
# If you have the PDF available:
python3 scripts/extract_e200z7_manual.py /path/to/e200z760_Core_Reference_Manual.pdf

# This will:
# 1. Extract Chapter 4 text to a .txt file
# 2. Attempt to find timing specifications
# 3. Attempt to find pairing rules
# 4. Output results for manual review
```

## Manual Review Steps

1. Open the extracted Chapter 4 text file
2. Find and document timing tables
3. Find and document pairing rules table
4. Extract exact latency values for each instruction category
5. Note any discrepancies with current LLVM code
6. Update `e200z7_manual_extracted_data.sdoc` with findings
7. Update `PPCScheduleE200Z7.td` with correct values
8. Add manual chapter/page references as comments

## Key Files to Update After Extraction

1. `llvm/lib/Target/PowerPC/PPCScheduleE200Z7.td` - Timing and pairing rules
2. `e200z7_manual_extracted_data.sdoc` - Extracted specifications
3. `llvm/lib/Target/PowerPC/PPC.td` - Processor feature flags (if needed)

## Validation Checklist

After extraction and updates:
- [ ] All instruction latencies match manual
- [ ] Dual-issue pairing rules are correct
- [ ] ALU0/ALU1 restrictions are modeled
- [ ] SPE/FPU instruction timings are correct
- [ ] Load latency matches manual
- [ ] Branch misprediction penalty is correct
- [ ] Bypass paths are correctly modeled
- [ ] Manual references added to code comments
- [ ] `CompleteModel = 1` can be set (if all validated)

