# VLE Cost Model Testing - Quick Start Guide

## Answer: Yes, you can do atomic testing on a single file!

## Quickest Way to Test

### Method 1: Direct `opt` command

```bash
# Navigate to your build directory
cd /projects/llvm-project/build

# Test with VLE enabled
bin/opt < ../powerpc-eabivle-docs/analysis/test_vle_cost_simple.ll \
  -cost-model -cost-kind=code-size -analyze \
  -mtriple=powerpc-none-eabivle | grep "Cost Model"
```

### Method 2: Use the test script

```bash
cd /projects/llvm-project
./powerpc-eabivle-docs/analysis/test_vle_cost.sh
```

### Method 3: Run the official test file

```bash
cd /projects/llvm-project
llvm/utils/lit/lit.py -sv llvm/test/Analysis/CostModel/PowerPC/vle-cost-size.ll
```

## Test Files Created

1. **`llvm/test/Analysis/CostModel/PowerPC/vle-cost-size.ll`**
   - Comprehensive test with FileCheck assertions
   - Can be run with `lit.py` or `opt` directly

2. **`powerpc-eabivle-docs/analysis/test_vle_cost_simple.ll`**
   - Simple standalone test file for manual inspection
   - Good for quick iteration

3. **`powerpc-eabivle-docs/analysis/test_vle_cost.sh`**
   - Automated test script comparing VLE vs non-VLE costs

## What Gets Tested

The cost model tests verify that:

- ✅ Small immediates (-32 to 31) get cost **2** (16-bit VLE)
- ✅ Operations with VLE equivalents get lower costs
- ✅ Large immediates get cost **4** (standard PowerPC)
- ✅ Non-VLE operations maintain standard costs

## Testing Your Cost Model Changes

### Workflow

1. **Edit the cost model**: `llvm/lib/Target/PowerPC/PPCTargetTransformInfo.cpp`
2. **Rebuild**: `cd build && ninja opt` (or `make opt`)
3. **Test**: Run one of the methods above
4. **Iterate**: Refine cost values and test again

### Example: Testing a new cost algorithm

```bash
# 1. Create a minimal test file (test.ll)
cat > test.ll << 'EOF'
target triple = "powerpc-none-eabivle"
define i32 @test(i32 %a) {
  %r = add i32 %a, i32 10
  ret i32 %r
}
EOF

# 2. Test current behavior
build/bin/opt < test.ll -cost-model -cost-kind=code-size -analyze \
  -mtriple=powerpc-none-eabivle

# 3. Modify PPCTargetTransformInfo.cpp::getUserCost()

# 4. Rebuild
cd build && ninja opt && cd ..

# 5. Test again and compare results
build/bin/opt < test.ll -cost-model -cost-kind=code-size -analyze \
  -mtriple=powerpc-none-eabivle
```

## Understanding the Output

### Expected Output with VLE

```
Cost Model: Found an estimated cost of 2 for instruction: %r = add i32 %a, i32 10
```

### Expected Output without VLE

```
Cost Model: Found an estimated cost of 4 for instruction: %r = add i32 %a, i32 10
```

### Cost Values

- **2 bytes**: 16-bit VLE instruction (e.g., `se_addi`)
- **3 bytes**: 32-bit VLE instruction (heuristic to encourage VLE selection)
- **4 bytes**: Standard PowerPC instruction

## Finding the Best Algorithm

Since there's a $1M prize for the smallest binary, you'll want to:

1. **Test different cost values**: Try 1, 2, 2.5, 3, 4 and measure actual binary size
2. **Compare actual instruction selection**: Use `llc -mtriple=powerpc-none-eabivle -filetype=asm` to see what instructions are actually selected
3. **Measure binary size**: Compile to object files and measure `.text` section size
4. **Iterate**: Refine cost model based on actual code size results

### Measuring Actual Binary Size

```bash
# Compile to assembly to see selected instructions
llc -mtriple=powerpc-none-eabivle -mattr=+vle test.ll -o test.s

# Compile to object file
llc -mtriple=powerpc-none-eabivle -mattr=+vle test.ll -filetype=obj -o test.o

# Measure text section size
objdump -h test.o | grep .text
# Or use:
size test.o
```

## Current Cost Model Implementation

The current implementation in `PPCTargetTransformInfo.cpp` (lines 243-308):

- Returns **2 bytes** when immediate fits VLE ranges and operation has VLE equivalent
- Returns **3 bytes** as heuristic for operations with VLE equivalents but unclear if 16-bit form is usable
- Returns **4 bytes** for standard PowerPC instructions

**Key limitation**: The cost model can't check register constraints (R0-R7) at IR level, so it uses heuristics.

## Next Steps for Optimization

1. **Refine immediate range detection**: Ensure all VLE immediate ranges are covered
2. **Improve heuristics**: Better estimation of 16-bit vs 32-bit VLE feasibility
3. **Add more operation types**: Extend to more instruction patterns
4. **Profile-guided**: Use actual code size measurements to tune costs
5. **Instruction selection integration**: Ensure cost model values actually influence DAG-to-DAG selection

## Files to Reference

- **Implementation**: `llvm/lib/Target/PowerPC/PPCTargetTransformInfo.cpp:243-308`
- **Test file**: `llvm/test/Analysis/CostModel/PowerPC/vle-cost-size.ll`
- **Documentation**: `powerpc-eabivle-docs/analysis/VLE_COST_MODEL_TESTING.md`
- **Requirements**: `powerpc-eabivle-docs/analysis/CODE_SIZE_OPTIMIZATION_REQUIREMENTS.md`

## Tips

- Start with simple test cases (add with small immediate)
- Compare VLE vs non-VLE to see the difference
- Use `-debug-only=ppctti` for detailed debug output
- Test boundary values (-32, -33, 31, 32, 127, 128)
- Measure actual binary sizes to validate cost model effectiveness

