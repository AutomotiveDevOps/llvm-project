# Testing VLE Pattern Prioritization

This guide explains how to test whether VLE patterns are being prioritized over standard PowerPC patterns in instruction selection.

## Quick Test Method

### Standalone Testing with llc

You can test instruction selection for a single file using `llc` directly:

```bash
# Generate assembly with VLE prioritized (code size optimization)
llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -mattr=+vle -Oz \
    -o test-vle.s vle-pattern-priority-test.ll

# Generate assembly without VLE prioritization (performance optimization)
llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -mattr=+vle -O2 \
    -o test-std.s vle-pattern-priority-test.ll

# Compare the outputs
diff -u test-std.s test-vle.s
```

### Expected Behavior

With `-Oz` (code size optimization):
- Should generate `se_addi` for small immediate additions (16-bit VLE)
- Should generate `e_add` for register additions (32-bit VLE)
- Should generate `se_stw` for stores with small offsets

With `-O2` (performance optimization):
- May generate standard PowerPC instructions (`addi`, `add`, `stw`) even when VLE is available
- This is the current problem: VLE patterns aren't being prioritized

### Manual Verification

```bash
# Check for VLE instructions in the output
grep -E "(se_|e_)" test-vle.s

# Count instruction sizes (approximate)
# VLE instructions are smaller:
# - se_* instructions are 16-bit (2 bytes)
# - e_* instructions are 32-bit (4 bytes)
# - Standard PowerPC instructions are 32-bit (4 bytes)
```

## Test File Structure

The test file `vle-pattern-priority-test.ll` contains:

1. **test_addi_small**: Tests whether `add i32 %a, 15` generates `se_addi` (16-bit) or `addi` (32-bit)
2. **test_add_reg**: Tests whether `add i32 %a, %b` generates `e_add` (32-bit VLE) or `add` (32-bit standard)
3. **test_store_small**: Tests whether stores generate `se_stw` (16-bit) or `stw` (32-bit)

## Running the Full Test Suite

```bash
# From llvm/test/CodeGen/PowerPC/
lit vle-pattern-priority-test.ll
```

## Understanding the Issue

### Current Problem

The TODO comment in `PPCInstrVLE.td:1756` indicates that instruction selection optimization passes need to be implemented. Currently:

1. **Pattern Ordering**: TableGen patterns may not prioritize VLE patterns before standard PowerPC patterns
2. **Cost Model**: The instruction selector doesn't have a cost model that prefers smaller VLE instructions when optimizing for code size
3. **Pattern Matching**: Even when `PreferVLE` is true (set when `optForSize()` or `hasMinSize()`), the pattern matcher may still select standard instructions if VLE patterns are matched later

### How to Verify the Fix

After implementing pattern prioritization in `PPCISelDAGToDAG.cpp`:

1. **With -Oz**: Should see VLE instructions (`se_*`, `e_*`)
2. **Instruction Count**: VLE version should have fewer bytes (check object file size)
3. **Pattern Matching**: Use debug output to see which patterns are tried first

### Debug Output

To see pattern matching in action:

```bash
# Enable instruction selection debugging
llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz \
    -debug-only=isel vle-pattern-priority-test.ll 2>&1 | grep -i vle
```

## Files Involved

- **Test File**: `llvm/test/CodeGen/PowerPC/vle-pattern-priority-test.ll`
- **Pattern Definitions**: `llvm/lib/Target/PowerPC/PPCInstrVLE.td`
- **Instruction Selector**: `llvm/lib/Target/PowerPC/PPCISelDAGToDAG.cpp`
- **Cost Model**: `llvm/lib/Target/PowerPC/PPCTargetTransformInfo.cpp`

## Next Steps for Implementation

1. Verify VLE patterns are defined in `PPCInstrVLE.td`
2. Check pattern ordering in TableGen files
3. Implement pattern prioritization logic in `PPCISelDAGToDAG.cpp`
4. Add cost model support in `PPCTargetTransformInfo.cpp`
5. Run this test to verify the fix

