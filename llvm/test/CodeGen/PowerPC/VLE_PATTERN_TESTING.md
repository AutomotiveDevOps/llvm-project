# VLE Pattern Prioritization Testing Guide

## Overview

This directory contains test files and tools to verify whether VLE (Variable Length Encoding) patterns are being prioritized over standard PowerPC patterns during instruction selection.

**Problem**: VLE patterns in `PPCInstrVLE.td` may not be tried before standard PowerPC patterns, even when optimizing for code size. This is noted in the TODO comment at `PPCInstrVLE.td:1756`.

## Quick Start: Standalone Testing

### Method 1: Using the Test Script (Easiest)

```bash
cd llvm/test/CodeGen/PowerPC
./test-vle-pattern-priority.sh [path-to-llc] vle-pattern-priority-test.ll
```

This script:
- Compiles with `-Oz` (code size) and `-O2` (performance)
- Compares the outputs
- Reports whether VLE instructions are being selected
- Shows file size differences

### Method 2: Direct llc Command

```bash
# Test with code size optimization (should prefer VLE)
llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -mattr=+vle -Oz \
    -o output-vle.s vle-pattern-priority-test.ll

# Check for VLE instructions
grep -E "(se_|e_)" output-vle.s
```

### Method 3: From C Source

```bash
# Compile C to assembly
clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz -S \
    -o test.s vle-pattern-priority-test.c

# Verify VLE instructions
grep -E "(se_|e_)" test.s
```

## Test Files

1. **vle-pattern-priority-test.ll**: LLVM IR test file
   - Tests `add` with small immediate → should generate `se_addi`
   - Tests `add` with registers → should generate `e_add`
   - Tests `store` → should generate `se_stw`

2. **vle-pattern-priority-test.c**: C source test file
   - Easier to modify and understand
   - Same test cases as the LLVM IR file

3. **test-vle-pattern-priority.sh**: Automated test script
   - Runs both optimization levels
   - Compares outputs
   - Provides summary

## Expected Results

### With `-Oz` (Code Size Optimization)

**Should generate:**
- `se_addi` for additions with small immediates (-31 to 31)
- `e_add` for register-to-register additions
- `se_stw` for stores with small offsets
- Other 16-bit/32-bit VLE instructions where applicable

**Why**: Code size optimization should prefer smaller VLE instructions (2-4 bytes) over standard PowerPC instructions (4 bytes).

### With `-O2` (Performance Optimization)

**May generate:**
- Standard PowerPC instructions (`addi`, `add`, `stw`)
- This is acceptable for performance optimization

**Current Problem**: Even with `-Oz`, standard instructions may be selected if VLE patterns aren't prioritized in the pattern matcher.

## Verifying the Fix

After implementing pattern prioritization in `PPCISelDAGToDAG.cpp`:

1. **Run the test**: `./test-vle-pattern-priority.sh`
2. **Check output**: Should see `se_*` and `e_*` instructions with `-Oz`
3. **Verify size**: `-Oz` output should be smaller than `-O2` output
4. **Inspect assembly**: Use `llvm-objdump` to verify instruction encodings

## Debugging Pattern Selection

To see which patterns are being tried:

```bash
# Enable instruction selection debugging
llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz \
    -debug-only=isel vle-pattern-priority-test.ll 2>&1 | \
    grep -E "(Select|VLE|pattern)" | head -50
```

## Files Involved in Fix

1. **PPCISelDAGToDAG.cpp** (`llvm/lib/Target/PowerPC/PPCISelDAGToDAG.cpp`)
   - Contains `PreferVLE` flag (line 4648)
   - Needs pattern prioritization logic

2. **PPCInstrVLE.td** (`llvm/lib/Target/PowerPC/PPCInstrVLE.td`)
   - Defines VLE instruction patterns
   - Pattern ordering may need adjustment (TODO at line 1756)

3. **PPCTargetTransformInfo.cpp**
   - May need cost model updates for VLE instructions

## Testing Workflow

1. **Before Fix**: Run test and note that standard instructions are selected even with `-Oz`
2. **Implement Fix**: Modify `PPCISelDAGToDAG.cpp` to prioritize VLE patterns
3. **After Fix**: Re-run test and verify VLE instructions are now selected
4. **Verify Size**: Check that code size actually decreases
5. **Run Full Test Suite**: `lit vle-pattern-priority-test.ll`

## Additional Notes

- VLE instructions have register constraints: 16-bit instructions can only use R0-R7
- The `PreferVLE` flag is set when `optForSize()` or `hasMinSize()` is true
- Pattern matching order in TableGen affects which patterns are tried first
- May need to adjust pattern predicates to ensure VLE patterns match before standard patterns

