# Quick Testing Guide for PPCVLEOpt Pass

This guide shows how to do **atomic testing** of the `PPCVLEOpt.cpp` pass on a single file to test its effectiveness.

## The Problem: Post-RA Limitations

The `PPCVLEOpt` pass has these limitations that you can test:

1. **Runs after register allocation** - Only sees physical registers
2. **Only handles R0-R7** - Cannot convert instructions using R8-R31
3. **Cannot reallocate registers** - Misses opportunities where register renaming could enable 16-bit VLE

## Quick Test Workflow

### Step 1: Create a Simple Test Case

Create a minimal C file to test specific scenarios:

```c
// test_single.c
int test_load_r3(int *base) {
    return base[5];  // Uses R3 as base, offset 20
}
```

### Step 2: Generate MIR After Register Allocation

```bash
# Compile to LLVM IR
clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz \
    -S -emit-llvm test_single.c -o test_single.ll

# Stop after register allocation (greedy allocator)
llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz \
    -stop-after=greedy -simplify-mir test_single.ll -o test_single.mir
```

### Step 3: Test the Pass in Isolation

```bash
# Run ONLY the ppc-vle-opt pass on your MIR file
llc -run-pass=ppc-vle-opt \
    -mtriple=powerpc-none-eabivle \
    -mcpu=e200z4 \
    -mvle \
    -verify-machineinstrs \
    test_single.mir \
    -o test_single_output.mir
```

### Step 4: Inspect Results

```bash
# Compare before and after
diff -u test_single.mir test_single_output.mir

# Or view side-by-side
vimdiff test_single.mir test_single_output.mir
```

## Testing Specific Limitations

### Test 1: Register Range Limitation (R0-R7 vs R8+)

Create a minimal MIR file manually:

```mir
---
name: test_reg_range
alignment: 4
tracksRegLiveness: true
body: |
  bb.0:
    liveins: $r3      # R3 is in range (0-7)
    $r4 = LBZ $r3, 10, implicit-def $rm
    BLR implicit $lr, implicit $rm, implicit $r4
...
---
name: test_reg_range_bad
alignment: 4
tracksRegLiveness: true
body: |
  bb.0:
    liveins: $r10     # R10 is OUT of range (8-31)
    $r4 = LBZ $r10, 10, implicit-def $rm
    BLR implicit $lr, implicit $rm, implicit $r4
...
```

Test it:
```bash
llc -run-pass=ppc-vle-opt -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle \
    test_reg_range.mir -o - | grep -E "SE_LBZ|LBZ"
```

**Expected**: First function converts to `SE_LBZ`, second stays as `LBZ`

### Test 2: Immediate Value Limitation

Test that immediate values must fit constraints:

```mir
---
name: test_imm_eligible
body: |
  bb.0:
    liveins: $r3
    $r4 = ADDI $r3, 15, implicit-def $rm    # 15 fits in s6imm (-32 to 31)
    BLR implicit $lr, implicit $rm, implicit $r4
...
---
name: test_imm_ineligible  
body: |
  bb.0:
    liveins: $r3
    $r4 = ADDI $r3, 50, implicit-def $rm    # 50 exceeds s6imm max of 31
    BLR implicit $lr, implicit $rm, implicit $r4
...
```

### Test 3: No Register Reallocation

Create a case where the pass CANNOT improve because registers are wrong:

```mir
---
name: test_no_realloc
body: |
  bb.0:
    liveins: $r10     # Wrong register - pass cannot fix this
    $r4 = LBZ $r10, 10, implicit-def $rm
    BLR implicit $lr, implicit $rm, implicit $r4
...
```

**Expected**: Pass does NOT convert (demonstrates limitation #3)

## Debugging Pass Behavior

### Enable Debug Output

```bash
llc -run-pass=ppc-vle-opt -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle \
    -debug-only=ppc-vle-opt test_single.mir -o - 2>&1 | head -50
```

### View Statistics

```bash
llc -run-pass=ppc-vle-opt -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle \
    -stats test_single.mir -o - 2>&1 | grep -i vle
```

This shows:
- `NumConvertedTo16Bit`: How many instructions were converted
- `NumIneligibleRegs`: How many skipped due to register constraints
- `NumIneligibleImms`: How many skipped due to immediate constraints

## Using the Existing Test File

The comprehensive test file is already available:

```bash
# Run all test cases
cd llvm/test/CodeGen/PowerPC
llvm-lit ppc-vle-opt-test.mir

# Or manually with FileCheck
llc -run-pass=ppc-vle-opt -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle \
    -verify-machineinstrs ppc-vle-opt-test.mir -o - | FileCheck ppc-vle-opt-test.mir
```

## One-Liner Quick Test

For rapid iteration on a single instruction pattern:

```bash
# Generate MIR → Test pass → View diff
clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz -S -emit-llvm test.c -o test.ll && \
llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz -stop-after=greedy -simplify-mir test.ll -o test.mir && \
llc -run-pass=ppc-vle-opt -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle test.mir -o test_out.mir && \
diff -u test.mir test_out.mir
```

## Key Takeaways

1. **Use `-run-pass=ppc-vle-opt`** to test ONLY this pass in isolation
2. **Requires MIR format** (machine IR after register allocation)
3. **Use `-stop-after=greedy`** to capture state after RA but before VLE opt
4. **Physical registers must be in range R0-R7** for conversion
5. **Immediate values must fit constraints** (varies by instruction type)

## Finding Pass Names

If you need to find exact pass names:

```bash
# List all passes in pipeline
llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz \
    -debug-pass=Structure test.ll -o /dev/null 2>&1 | grep -i vle
```

## Next Steps for Improvement

To address the limitations, consider:

1. **Pre-RA Analysis Pass**: Hint register allocator to prefer R0-R7
2. **Post-RA Register Renaming**: Rename registers to enable more conversions
3. **Register Allocator Integration**: Modify allocator to prioritize VLE opportunities

See `powerpc-eabivle-docs/analysis/` for detailed analysis.

