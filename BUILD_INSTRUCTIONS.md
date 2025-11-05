# LLVM Build Instructions for PowerPC e200 Embedded Toolchain

This document provides step-by-step instructions for building LLVM with Clang and LLD for PowerPC e200 cores (e200z4, e200z6, e200z7) with VLE (Variable Length Encoding) support.

**Important**: This toolchain is **hyper-focused on PowerPC e200 cores only**. It targets a specific embedded architecture, similar to GCC cross-compiler toolchains for MCU families. Use system-level LLVM/clang for host-side development tools if needed.

## Prerequisites

- CMake 3.20.0 or later
- C++17 capable compiler (for building LLVM)
- Python 3 (for build scripts)
- Ninja build system (recommended) or Make

## Required LLVM Projects

For a complete embedded development toolchain, you need:

1. **clang** - C/C++ compiler frontend (REQUIRED)
2. **lld** - LLVM linker (REQUIRED)
3. **compiler-rt** - Runtime library support (REQUIRED for linking)

### Optional Projects

- **lldb** - LLVM debugger (optional, GDB is standard for embedded)
- **libcxx** - C++ standard library (optional, if using C++)
- **libcxxabi** - C++ ABI support (optional, if using C++)
- **libunwind** - Stack unwinding for exceptions (optional, if using C++ exceptions)

## CMake Configuration

### Minimal Required Setup

This configuration provides the essential tools for compiling and linking embedded applications:

```bash
cmake -S . -B build \
  -DLLVM_ENABLE_PROJECTS="clang;lld;compiler-rt" \
  -DLLVM_ENABLE_RUNTIMES="compiler-rt" \
  -DLLVM_ENABLE_LLD=ON \
  -DCMAKE_BUILD_TYPE=Release \
  -DLLVM_TARGETS_TO_BUILD="PowerPC" \
  -DLLVM_DEFAULT_TARGET_TRIPLE="powerpc-eabivle" \
  -DCMAKE_INSTALL_PREFIX=/usr/local/s32ds-power-linux/llvm-powerpc-eabivle \
  -GNinja
```

**Key Options Explained**:
- `LLVM_ENABLE_PROJECTS`: Core projects to build
- `LLVM_ENABLE_RUNTIMES`: Runtime libraries (compiler-rt is critical)
- `LLVM_ENABLE_LLD=ON`: Enable the LLD linker build
- `LLVM_TARGETS_TO_BUILD="PowerPC"`: Build ONLY PowerPC backend (e200-focused)
- `LLVM_DEFAULT_TARGET_TRIPLE="powerpc-eabivle"`: Default target architecture

### Full Embedded Toolchain (with C++ Support)

For projects using modern C++ features:

```bash
cmake -S . -B build \
  -DLLVM_ENABLE_PROJECTS="clang;lld;compiler-rt;lldb" \
  -DLLVM_ENABLE_RUNTIMES="compiler-rt;libcxx;libcxxabi;libunwind" \
  -DLLVM_ENABLE_LLD=ON \
  -DCMAKE_BUILD_TYPE=Release \
  -DLLVM_TARGETS_TO_BUILD="PowerPC" \
  -DLLVM_DEFAULT_TARGET_TRIPLE="powerpc-eabivle" \
  -DCMAKE_INSTALL_PREFIX=/usr/local/s32ds-power-linux/llvm-powerpc-eabivle \
  -GNinja
```

### Additional PowerPC VLE-Specific Flags

Add these flags for optimal e200 support:

```bash
  -DLLVM_TARGET_ARCH="PowerPC" \
  -DLLVM_ENABLE_ASSERTIONS=OFF \
  -DLLVM_ENABLE_EH=ON \
  -DLLVM_ENABLE_RTTI=ON
```

## Building

### Build Specific Targets

Build only the essential tools:

```bash
cmake --build build --target clang lld compiler-rt
```

Or build everything:

```bash
cmake --build build
```

### Parallel Builds

Use parallel builds for faster compilation:

```bash
cmake --build build -j$(nproc)
```

## Installation

After building, install to the configured prefix:

```bash
cmake --install build
```

Or use the Debian packaging system:

```bash
cd debian
fakeroot make -f rules install
fakeroot make -f rules binary
```

## Verification

After building, verify that the executables exist:

```bash
# Check for clang (may be named clang-22)
ls -la build/bin/clang*
ls -la build/bin/clang-22

# Check for lld
ls -la build/bin/lld

# Check for compiler-rt libraries
ls -la build/lib/libclang_rt.builtins-powerpc.a
ls -la build/lib/clang/*/lib/powerpc*/
```

Test compilation:

```bash
build/bin/clang --target=powerpc-eabivle --version
build/bin/lld --version
```

## compiler-rt Requirements

**Why compiler-rt is critical**: The compiler-rt library provides runtime support functions that Clang requires for:
- 64-bit arithmetic operations on 32-bit targets
- Builtin functions (`__builtin_*`)
- Floating point conversions
- Exception handling primitives

Without compiler-rt, linking will fail with undefined symbol errors like:
- `__udivdi3`, `__umoddi3` (division/modulo)
- `__muldi3` (multiplication)
- `__ashldi3`, `__ashrdi3`, `__lshrdi3` (bit shifts)

**PowerPC e200 Support**: compiler-rt includes PowerPC-specific optimizations for e200 cores.

## Troubleshooting

### Missing clang-22 or clang executable

**Symptom**: Build completes but `clang-22` or `clang` is not in `build/bin/`

**Solution**: 
- Verify `clang` is in `LLVM_ENABLE_PROJECTS`
- Check build logs for errors
- Ensure build completed successfully: `cmake --build build --target clang`

### Missing lld executable

**Symptom**: Build completes but `lld` is not in `build/bin/`

**Solution**:
- Set `-DLLVM_ENABLE_LLD=ON` in CMake configuration
- Rebuild: `cmake --build build --target lld`

### Broken Symlinks After Installation

**Symptom**: Symlinks like `clang++ -> clang-22` are broken (pointing to non-existent files)

**Solution**:
- The `debian/rules` file now automatically fixes symlinks
- Ensure the target executable exists before packaging
- Run `debian/rules install` to regenerate symlinks

### Linking Failures with Undefined Symbols

**Symptom**: Linking fails with `undefined reference to __udivdi3` or similar

**Solution**:
- Enable compiler-rt: Add `compiler-rt` to `LLVM_ENABLE_RUNTIMES`
- Rebuild compiler-rt: `cmake --build build --target compiler-rt`
- Verify libraries: `ls -la build/lib/libclang_rt.builtins-powerpc.a`

## Integration with Existing EWL Libraries

This LLVM toolchain is designed to work with the existing Embedded Wrapper Library (EWL) located at `/usr/local/s32ds-power-linux/e200_ewl2/`.

The toolchain will:
- Use `--sysroot` to point to EWL directories
- Link against EWL libraries (libewl_c.a, etc.)
- Support EWL specs files (if clang supports `-specs=` flag)

## Target Architecture Details

**Target Triple**: `powerpc-eabivle`

**Supported Cores**:
- e200z4 (MPC5744P, etc.)
- e200z6
- e200z7

**Architecture Features**:
- Big-endian
- VLE (Variable Length Encoding) instruction set
- Hardware FPU (`-mhard-float`)
- EABI VLE calling convention

**Compiler Flags**:
```bash
--target=powerpc-eabivle
-mcpu=e200z4
-mbig
-mvle
-mregnames
-mhard-float
```

## Additional Resources

- [LLVM Getting Started Guide](https://llvm.org/docs/GettingStarted.html)
- [Clang User Manual](https://clang.llvm.org/docs/UsersManual.html)
- [LLD Linker Documentation](https://lld.llvm.org/)
- [PowerPC e200 Core Documentation](https://www.nxp.com/docs/en/reference-manual/)

