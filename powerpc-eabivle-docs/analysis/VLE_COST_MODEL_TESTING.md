# VLE Cost Model Atomic Testing Guide

## Overview

This document describes how to perform atomic testing of the VLE cost model implementation in `PPCTargetTransformInfo.cpp`. Atomic testing allows you to test cost model changes in isolation without running the full LLVM test suite.

## Quick Start

### Single File Testing

The simplest way to test the cost model is using `opt` directly:

```bash
# Test with VLE enabled (powerpc-none-eabivle)
opt < test.ll -cost-model -cost-kind=code-size -analyze -mtriple=powerpc-none-eabivle

# Test without VLE (baseline comparison)
opt < test.ll -cost-model -cost-kind=code-size -analyze -mtriple=powerpc-none-unknown
```

### Using the Test File

A comprehensive test file is available at:
```
llvm/test/Analysis/CostModel/PowerPC/vle-cost-size.ll
```

Run it with:
```bash
cd /projects/llvm-project
llvm/utils/lit/lit.py -sv llvm/test/Analysis/CostModel/PowerPC/vle-cost-size.ll
```

Or manually:
```bash
cd /projects/llvm-project/build
bin/opt < ../llvm/test/Analysis/CostModel/PowerPC/vle-cost-size.ll \
  -cost-model -cost-kind=code-size -analyze -mtriple=powerpc-none-eabivle | \
  grep "Cost Model"
```

## Test File Format

Create a simple `.ll` file with your test case:

```llvm
; RUN: opt < %s -cost-model -cost-kind=code-size -analyze -mtriple=powerpc-none-eabivle | FileCheck %s
target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-f128:128:128-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

define i32 @test_add(i32 %a) {
entry:
  ; CHECK: Cost Model: Found an estimated cost of {{[2-3]}} for instruction: %r = add i32 %a, i32 10
  %r = add i32 %a, i32 10
  ret i32 %r
}
```

## Understanding Cost Values

### Expected Costs with VLE

When VLE is enabled and optimizing for code size (`-cost-kind=code-size`):

- **16-bit VLE instructions**: Cost of **2** bytes
  - Used when immediate fits in VLE ranges (s6imm: -32 to 31, u5imm: 0-31, u7imm: 0-127)
  - Requires registers R0-R7 (not directly checkable in IR, but cost model should account for it)

- **32-bit VLE instructions**: Cost of **3-4** bytes
  - Used when operation has VLE equivalent but constraints don't allow 16-bit form
  - Heuristic encourages VLE selection

- **Standard PowerPC**: Cost of **4** bytes
  - Used when no VLE equivalent exists or constraints can't be met

### Cost Model Logic

The cost model in `PPCTargetTransformInfo.cpp::getUserCost()`:

1. Checks if `CostKind == TCK_CodeSize` and VLE is enabled
2. Identifies operations with VLE equivalents (Add, Sub, And, Or, Xor, ICmp, Load, Store, Shifts)
3. Checks if immediates fit VLE ranges:
   - s6imm: -32 to 31 → Can use 16-bit VLE
   - u5imm: 0 to 31 → Can use 16-bit VLE  
   - u7imm: 0 to 127 → Can use 16-bit VLE for some operations
4. Returns appropriate cost:
   - 2 bytes if 16-bit VLE is possible
   - 3 bytes if 32-bit VLE is possible (heuristic)
   - 4 bytes for standard PowerPC

## Testing Different Scenarios

### 1. Small Immediate Values (Should use 16-bit VLE)

```llvm
; Immediate -32 to 31 (s6imm)
%r1 = add i32 %a, i32 10    ; Cost should be 2
%r2 = add i32 %a, i32 -20   ; Cost should be 2
%r3 = add i32 %a, i32 31    ; Cost should be 2
%r4 = add i32 %a, i32 -32   ; Cost should be 2

; Immediate 0-31 (u5imm)
%r5 = and i32 %a, i32 31    ; Cost should be 2
%r6 = or i32 %a, i32 15     ; Cost should be 2
```

### 2. Large Immediate Values (Should use standard PowerPC)

```llvm
%r1 = add i32 %a, i32 1000  ; Cost should be 4 (no VLE)
%r2 = add i32 %a, i32 100   ; Cost might be 3 (32-bit VLE possible)
```

### 3. Register-Only Operations

```llvm
; Register-register operations: Cost depends on register constraints
; Cost model can't know register numbers in IR, so uses heuristic (3 bytes)
%r = add i32 %a, i32 %b     ; Cost should be 2-4 (heuristic: 3)
```

### 4. Zero Comparisons

```llvm
; Zero comparisons can use record-form instructions
%r = icmp eq i32 %a, i32 0  ; Cost should be 2-3 (VLE preferred)
```

## Automated Testing Script

Create a simple script to test cost model changes:

```bash
#!/bin/bash
# test_vle_cost.sh

TEST_FILE="test_vle.ll"
BUILD_DIR="/projects/llvm-project/build"

echo "Testing VLE cost model..."

echo "=== With VLE enabled ==="
${BUILD_DIR}/bin/opt < ${TEST_FILE} \
  -cost-model -cost-kind=code-size -analyze \
  -mtriple=powerpc-none-eabivle 2>&1 | grep "Cost Model"

echo ""
echo "=== Without VLE (baseline) ==="
${BUILD_DIR}/bin/opt < ${TEST_FILE} \
  -cost-model -cost-kind=code-size -analyze \
  -mtriple=powerpc-none-unknown 2>&1 | grep "Cost Model"
```

## Validation

### What to Check

1. **VLE vs Non-VLE**: Costs should be lower with VLE enabled for eligible operations
2. **Immediate Ranges**: 
   - Small immediates (-32 to 31, 0-31, 0-127) should have cost 2
   - Large immediates should have cost 4
3. **Operation Types**: Only certain operations should benefit from VLE:
   - Add, Sub, And, Or, Xor, ICmp, Load, Store, Shifts
   - Other operations (Mul, Div, etc.) should have standard cost

### Example Output

**With VLE enabled:**
```
Cost Model: Found an estimated cost of 2 for instruction: %r = add i32 %a, i32 10
Cost Model: Found an estimated cost of 4 for instruction: %r = mul i32 %a, i32 %b
```

**Without VLE:**
```
Cost Model: Found an estimated cost of 4 for instruction: %r = add i32 %a, i32 10
Cost Model: Found an estimated cost of 4 for instruction: %r = mul i32 %a, i32 %b
```

## Iterative Development

### Workflow for Cost Model Tuning

1. **Create test case**: Write a simple `.ll` file with the instruction pattern you want to test
2. **Run baseline**: Test current cost model behavior
3. **Modify cost model**: Edit `PPCTargetTransformInfo.cpp::getUserCost()`
4. **Rebuild**: `cd build && ninja opt` (or `make opt`)
5. **Test**: Run your test file again to see cost changes
6. **Iterate**: Refine cost values based on results

### Quick Rebuild

```bash
cd /projects/llvm-project/build
# If using ninja:
ninja opt

# If using make:
make opt
```

## Debugging

### Enable Debug Output

The cost model uses `DEBUG_TYPE "ppctti"`. Enable debug output:

```bash
opt < test.ll -cost-model -cost-kind=code-size -analyze \
  -mtriple=powerpc-none-eabivle -debug-only=ppctti
```

### Check TTI Implementation

Verify that the TTI wrapper is correctly calling your implementation:

```bash
opt < test.ll -cost-model -cost-kind=code-size -analyze \
  -mtriple=powerpc-none-eabivle -print-after-all 2>&1 | less
```

## Integration with Full Test Suite

Once your cost model changes are validated with atomic tests, run the full PowerPC cost model test suite:

```bash
cd /projects/llvm-project
llvm/utils/lit/lit.py -sv llvm/test/Analysis/CostModel/PowerPC/
```

## References

- **Implementation**: `llvm/lib/Target/PowerPC/PPCTargetTransformInfo.cpp`
- **Test File**: `llvm/test/Analysis/CostModel/PowerPC/vle-cost-size.ll`
- **Requirements**: `CODE_SIZE_OPTIMIZATION_REQUIREMENTS.md`
- **Cost Model Pass**: `llvm/lib/Analysis/CostModel.cpp`

## Best Practices

1. **Test incrementally**: Start with simple cases (add with small immediate) before complex ones
2. **Compare baselines**: Always test with and without VLE to see the difference
3. **Validate assumptions**: Verify that cost reductions align with actual instruction sizes
4. **Document changes**: Update test expectations when cost model logic changes
5. **Check edge cases**: Test boundary values (-32, -33, 31, 32, 127, 128, etc.)

## Example: Testing a Cost Model Change

Suppose you want to improve the cost model for `add` with u7imm (0-127):

1. Create test file `test_u7imm.ll`:
```llvm
target triple = "powerpc-none-eabivle"
define i32 @test(i32 %a) {
  %r = add i32 %a, i32 100  ; u7imm range
  ret i32 %r
}
```

2. Run baseline test:
```bash
opt < test_u7imm.ll -cost-model -cost-kind=code-size -analyze \
  -mtriple=powerpc-none-eabivle
```

3. Modify `PPCTargetTransformInfo.cpp` to handle u7imm for add/sub

4. Rebuild and test:
```bash
cd build && ninja opt
opt < test_u7imm.ll -cost-model -cost-kind=code-size -analyze \
  -mtriple=powerpc-none-eabivle
```

5. Verify cost changed from 3-4 to 2

This iterative process allows rapid testing and refinement of cost model algorithms.

