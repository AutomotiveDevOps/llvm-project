# Testing VLE Register Allocation (R0-R7 Preference)

This document explains how to test whether register allocation is properly preferring R0-R7 registers for 16-bit VLE instructions.

## Problem

16-bit VLE instructions can only use registers R0-R7 (3-bit encoding). The register allocator needs to know to prefer these registers for VLE-eligible operations, especially when optimizing for code size (`-Oz`).

## Test Files

### 1. LLVM IR Test (`vle-reg-alloc-r0-r7.ll`)

This is a comprehensive LLVM IR test file that verifies register allocation using FileCheck patterns.

**Run the test:**
```bash
cd /projects/llvm-project
llvm-lit llvm/test/CodeGen/PowerPC/vle-reg-alloc-r0-r7.ll
```

**What it tests:**
- Simple add immediate (`se_addi`) with R0-R7 preference
- Register-register add (`se_add`) with R0-R7 preference
- Multiple operations to test register pressure handling
- Load/store operations with R0-R7 base registers
- Comparison with non-optimized builds

**Expected behavior:**
- With `-Oz -mvle`, should see 16-bit VLE instructions (`se_addi`, `se_add`, etc.) using R0-R7 registers
- Without `-Oz`, may still generate VLE but less aggressively

### 2. C Source Test (`vle-reg-alloc-test.c`)

A simple C file for quick manual testing and iteration.

**Compile to assembly:**
```bash
clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz -S vle-reg-alloc-test.c
```

**Check for R0-R7 usage in 16-bit VLE instructions:**
```bash
grep "se_" vle-reg-alloc-test.s | grep -E "r[0-7]"
```

**Expected output:**
Should see multiple lines like:
```
se_addi    r3, r3, 10
se_add     r3, r3, r4
se_subi    r3, r3, 3
```

**Verify 16-bit encoding:**
```bash
# Check instruction size in object file
clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz -c vle-reg-alloc-test.c
llvm-objdump -d vle-reg-alloc-test.o | grep -E "se_|e_"
```

## Manual Testing Workflow

1. **Make changes to `PPCRegisterInfo.cpp`** (or related files)

2. **Run the LLVM IR test:**
   ```bash
   llvm-lit llvm/test/CodeGen/PowerPC/vle-reg-alloc-r0-r7.ll -v
   ```

3. **If test fails, debug with C file:**
   ```bash
   cd llvm/test/CodeGen/PowerPC
   clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz -S vle-reg-alloc-test.c
   cat vle-reg-alloc-test.s
   ```

4. **Compare with and without -Oz:**
   ```bash
   # With -Oz (should prefer R0-R7)
   clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz -S vle-reg-alloc-test.c -o with-oz.s
   
   # Without -Oz (may not prefer R0-R7)
   clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -S vle-reg-alloc-test.c -o without-oz.s
   
   # Compare
   diff -u without-oz.s with-oz.s
   ```

## What to Look For

### Good Signs (Register Allocation Working):
- ✅ 16-bit VLE instructions (`se_addi`, `se_add`, `se_subi`, etc.) present
- ✅ Registers R0-R7 being used in those instructions
- ✅ More 16-bit instructions with `-Oz` than without
- ✅ Instruction size reduction when R0-R7 are used

### Bad Signs (Register Allocation Not Working):
- ❌ Only 32-bit instructions (`e_add`, `addi`, `add`) even with `-Oz`
- ❌ Registers R8-R31 used in operations that could be 16-bit VLE
- ❌ No difference between `-Oz` and non-optimized builds
- ❌ Large code size despite VLE being enabled

## Key Implementation Points

The register allocation hint is in `PPCRegisterInfo.cpp::getRegPressureLimit()`:

```cpp
if (Subtarget.hasVLE() && 
    (MF.getFunction().optForSize() || MF.getFunction().hasMinSize())) {
  return 30 - FP - DefaultSafety; // Encourage R0-R7 usage
}
```

This reduces register pressure limit from 32 to 30, encouraging the allocator to prefer lower registers (R0-R7).

## Troubleshooting

If the test fails:

1. **Check if VLE is enabled:**
   ```bash
   llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle --version
   ```

2. **Verify instruction selector is choosing VLE patterns:**
   Add `-debug` flag and look for VLE instruction selection:
   ```bash
   llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz -debug < test.ll 2>&1 | grep -i vle
   ```

3. **Check register allocation decisions:**
   Use `-print-reg-pressure` to see register allocation:
   ```bash
   llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz -print-reg-pressure < test.ll
   ```

4. **Verify Post-RA pass is running:**
   The `PPCVLEOpt` pass should convert instructions to VLE after register allocation.
   Check if it's running and what it's doing:
   ```bash
   llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz -debug-pass=Structure < test.ll
   ```

## References

- `llvm/lib/Target/PowerPC/PPCRegisterInfo.cpp` - Register allocation hints
- `llvm/lib/Target/PowerPC/PPCVLEOpt.cpp` - Post-RA VLE optimization
- `llvm/lib/Target/PowerPC/PPCInstrVLE.td` - VLE instruction definitions

