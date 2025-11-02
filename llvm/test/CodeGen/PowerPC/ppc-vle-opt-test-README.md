# PPCVLEOpt Pass Testing Guide

This document explains how to test the `PPCVLEOpt` pass in isolation to verify its effectiveness, particularly regarding post-register-allocation limitations.

## Overview

The `PPCVLEOpt` pass converts standard PowerPC instructions to VLE (Variable Length Encoding) instructions when constraints allow. The pass has the following limitations:

1. **Post-RA Pass**: Runs after register allocation, so it only sees physical registers
2. **Register Constraints**: Can only convert when registers are in R0-R7 range (16-bit VLE)
3. **No Reallocation**: Cannot reallocate registers to enable more 16-bit VLE opportunities

## Testing the Pass in Isolation

### Using the Provided Test File

The file `ppc-vle-opt-test.mir` contains several test cases that verify the pass behavior:

```bash
# Run the test
cd llvm/test/CodeGen/PowerPC
llvm-lit ppc-vle-opt-test.mir
```

Or manually:

```bash
llc -run-pass=ppc-vle-opt -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle \
    -verify-machineinstrs ppc-vle-opt-test.mir -o - | FileCheck ppc-vle-opt-test.mir
```

### Test Cases Included

1. **test_vle_load_eligible**: Load with R0-R7 and small displacement → converts to SE_LBZ
2. **test_vle_load_ineligible_reg**: Load with R8 (out of range) → remains LBZ
3. **test_vle_load_ineligible_imm**: Load with R0-R7 but large displacement → remains LBZ
4. **test_vle_addi_eligible**: ADDI with R0-R7 and small immediate → converts to SE_ADDI
5. **test_vle_addi_ineligible_imm**: ADDI with immediate too large → remains ADDI
6. **test_vle_add_eligible**: ADD with all registers in range → converts to SE_ADD
7. **test_vle_store_eligible**: Store with R0-R7 and small displacement → converts to SE_STW
8. **test_vle_cmpi_eligible**: CMPWI with R0-R7 and small immediate → converts to SE_CMPI

## Generating Your Own Test Cases

### Method 1: Generate MIR from LLVM IR

1. **Create a simple C/C++ file** that exercises the operations you want to test:

```c
// test_load.c
int test_load(int *base) {
    return base[5];  // Load from offset 20 (5 * 4)
}
```

2. **Compile to LLVM IR**:

```bash
clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz -S -emit-llvm test_load.c -o test_load.ll
```

3. **Generate MIR after register allocation**:

```bash
llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz \
    -stop-after=greedy test_load.ll -o test_load.mir
```

4. **Simplify the MIR** (remove unnecessary metadata):

```bash
llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz \
    -stop-after=greedy -simplify-mir test_load.ll -o test_load.mir
```

5. **Edit the MIR file** to:
   - Assign specific physical registers (R0-R7 for eligible cases, R8+ for ineligible)
   - Ensure immediate values are set appropriately
   - Remove unnecessary metadata

6. **Test the pass**:

```bash
llc -run-pass=ppc-vle-opt -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle \
    -verify-machineinstrs test_load.mir -o test_load_output.mir
```

7. **Verify results** using FileCheck or manual inspection:

```bash
llc -run-pass=ppc-vle-opt -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle \
    -verify-machineinstrs test_load.mir -o - | FileCheck test_load.mir
```

### Method 2: Start from LLVM IR and Use Full Pipeline

For testing the full effect including register allocation:

```bash
# Compile with specific register allocation strategy
clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz \
    -mllvm -regalloc=greedy test_load.c -S -o test_load.s

# Or with Fast allocator
clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz \
    -mllvm -regalloc=fast test_load.c -S -o test_load.s

# Inspect the assembly to see if VLE instructions were generated
cat test_load.s
```

## Finding What Pass Names to Use

To find the exact pass name and what passes run before/after:

```bash
# List all passes
llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz \
    -debug-pass=Structure test_load.ll -o /dev/null 2>&1 | grep -i vle

# Or see full pass pipeline
llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz \
    -debug-pass=Structure test_load.ll -o /dev/null
```

## Testing Limitations

To test the specific limitations mentioned:

### Limitation 1: Only Physical Registers

**Test**: Create a case where virtual registers would map to R0-R7, but the pass can't see this pre-RA:

```mir
# Before register allocation (virtual registers)
%0 = LBZ %vreg0, 10  # Can't tell if vreg0 will be R3 or R10

# After register allocation (physical registers) 
R4 = LBZ R3, 10      # Can see R3 is eligible, but too late to influence allocation
```

**Verify**: The pass only converts when it sees physical registers in R0-R7.

### Limitation 2: Cannot Reallocate Registers

**Test**: Create a case where an instruction uses R10, but could use R3:

```mir
# Instruction with R10 (ineligible)
R4 = LBZ R10, 10     # Can't convert because R10 is out of range

# Pass cannot change R10 to R3 to enable conversion
```

**Verify**: The pass doesn't change register assignments, only converts eligible instructions.

### Limitation 3: Immediate Constraints

**Test**: Verify immediate value constraints:

```mir
# Small immediate - eligible
R4 = ADDI R3, 15     # Fits in s6imm (-32 to 31) → converts to SE_ADDI

# Large immediate - ineligible  
R4 = ADDI R3, 100    # Exceeds s6imm range → remains ADDI
```

## Debugging

To see what the pass is doing:

```bash
# Run with debug output
llc -run-pass=ppc-vle-opt -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle \
    -debug-only=ppc-vle-opt test_load.mir -o - 2>&1 | head -50

# Or enable statistics
llc -run-pass=ppc-vle-opt -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle \
    -stats test_load.mir -o - 2>&1 | grep -i vle
```

## Next Steps for Improvement

If you want to address the limitations:

1. **Pre-RA Analysis**: Add a pre-RA pass that hints register allocator to prefer R0-R7
2. **Post-RA Register Renaming**: Add register renaming in post-RA to enable more conversions
3. **Cooperative Register Allocation**: Modify register allocator to prioritize VLE opportunities

See the documentation in `powerpc-eabivle-docs/analysis/` for more details.

