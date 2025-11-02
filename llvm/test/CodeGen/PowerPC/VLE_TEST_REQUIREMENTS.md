# VLE Test Suite Requirements

## Current Status

The VLE test files exist in git commit `fb4f85b3b33` but are not currently in the working directory. To run the tests, you need to:

1. **Restore test files from git** (if they were deleted)
2. **Build LLVM with PowerPC target support**
3. **Ensure VLE backend support is compiled**
4. **Have llvm-lit test runner available**

## Prerequisites to Run Tests

### 1. Test Files Must Exist

The 38 test files created need to be present in `llvm/test/CodeGen/PowerPC/`:

```bash
# Check if files exist
ls llvm/test/CodeGen/PowerPC/vle-*.ll

# If missing, restore from git:
git checkout fb4f85b3b33 -- llvm/test/CodeGen/PowerPC/vle-*.ll
```

### 2. LLVM Build Requirements

The tests require:
- **PowerPC target must be enabled** in CMake build
- **VLE instruction support compiled** (HasVLE, IsE200 features)
- **llc tool built** with PowerPC backend
- **FileCheck tool built**

CMake configuration should include:
```cmake
-DLLVM_TARGETS_TO_BUILD="PowerPC"
# or
-DLLVM_TARGETS_TO_BUILD="all"
```

### 3. Target Triple Support

Tests use `powerpc-none-eabivle` target triple. Verify support:

```bash
# Check if triple is recognized
llc -mtriple=powerpc-none-eabivle -print-mtriple 2>&1

# Should NOT produce "error: unable to find target" or similar
```

### 4. Lit Test Runner

Need `llvm-lit` or `llvm-lit.py` to run tests:

```bash
# Check if lit is available
which llvm-lit
# or
python3 -m lit --version

# If not found, build it or use:
python3 llvm/utils/lit/lit.py
```

### 5. Test Configuration

The `lit.local.cfg` in `llvm/test/CodeGen/PowerPC/` checks:
```python
if not 'PowerPC' in config.root.targets:
    config.unsupported = True
```

This means PowerPC target must be in `LLVM_TARGETS_TO_BUILD`.

## Running the Tests

### Method 1: Using llvm-lit

```bash
cd /projects/llvm-project
llvm-lit llvm/test/CodeGen/PowerPC/vle-*.ll
# or specific test
llvm-lit llvm/test/CodeGen/PowerPC/vle-load-byte.ll
```

### Method 2: Using lit.py directly

```bash
python3 llvm/utils/lit/lit.py llvm/test/CodeGen/PowerPC/vle-*.ll
```

### Method 3: Run all PowerPC tests (including VLE)

```bash
llvm-lit llvm/test/CodeGen/PowerPC/
```

### Method 4: Manual testing

```bash
# Test single file
llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz \
    llvm/test/CodeGen/PowerPC/vle-load-byte.ll | \
    FileCheck llvm/test/CodeGen/PowerPC/vle-load-byte.ll
```

## Verification Steps

Before running tests, verify:

1. **Test files exist:**
   ```bash
   find llvm/test/CodeGen/PowerPC -name "vle-*.ll" | wc -l
   # Should show 38 (or more if additional files added)
   ```

2. **llc recognizes VLE triple:**
   ```bash
   llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -version
   # Should show version, not an error
   ```

3. **VLE instructions are generated:**
   ```bash
   echo 'define i32 @test(i8* %p) { %v = load i8, i8* %p; %e = zext i8 %v to i32; ret i32 %e }' | \
   llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz - | grep -i "se_lbz\|e_lbz"
   # Should show VLE instruction (if register allocation favors R0-R7)
   ```

4. **FileCheck is available:**
   ```bash
   FileCheck --version
   # Should show version
   ```

## Expected Test Results

When tests run successfully:
- Tests using `-Oz` should generate `se_*` (16-bit) instructions when registers are in R0-R7
- Tests using `-Oz` should generate `e_*` (32-bit VLE) instructions when constraints allow
- Tests using `-O2` may generate standard PowerPC instructions (which is acceptable)
- All FileCheck directives should pass

## Troubleshooting

### Issue: "unsupported" for all tests
**Cause:** PowerPC target not built or not in targets list  
**Fix:** Rebuild LLVM with `-DLLVM_TARGETS_TO_BUILD="PowerPC"`

### Issue: "unable to find target for this triple"
**Cause:** `powerpc-none-eabivle` triple not recognized  
**Fix:** Ensure PowerPC backend is built and triple parsing supports this format

### Issue: Tests fail with "se_lbz not found"
**Cause:** VLE instructions not being generated  
**Possible reasons:**
- Register allocator not preferring R0-R7 with -Oz
- VLE patterns not prioritized in instruction selection
- Subtarget features (HasVLE, IsE200) not enabled

### Issue: FileCheck errors
**Cause:** Generated assembly doesn't match CHECK directives  
**Fix:** Review generated assembly, may need to adjust CHECK patterns for actual codegen

## Next Steps

1. Restore test files if deleted:
   ```bash
   git checkout fb4f85b3b33 -- llvm/test/CodeGen/PowerPC/vle-*.ll
   ```

2. Verify build configuration includes PowerPC target

3. Run a single test to verify setup:
   ```bash
   llvm-lit llvm/test/CodeGen/PowerPC/vle-load-byte.ll -v
   ```

4. If single test passes, run all VLE tests:
   ```bash
   llvm-lit llvm/test/CodeGen/PowerPC/vle-*.ll
   ```

