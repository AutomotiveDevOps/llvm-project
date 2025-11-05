#!/bin/bash
#
# validate_llvm_build.sh
#
# Validates that required LLVM executables and libraries exist in the build directory
# before packaging. This script is used by debian/rules during the build process.
#
# Exit codes:
#   0 - All required items found
#   1 - Critical items missing (clang or lld)
#   2 - Warnings only (compiler-rt missing, but not critical for basic build)

set -e

BUILDDIR="${1:-build}"
ERRORS=0
WARNINGS=0

echo "Validating LLVM build in ${BUILDDIR}..."

# Check for clang executable (clang-22 or clang)
CLANG_FOUND=0
if [ -f "${BUILDDIR}/bin/clang-22" ]; then
    echo "✓ Found clang-22"
    CLANG_FOUND=1
elif [ -f "${BUILDDIR}/bin/clang" ]; then
    echo "✓ Found clang"
    CLANG_FOUND=1
fi

if [ $CLANG_FOUND -eq 0 ]; then
    echo "✗ ERROR: clang executable not found"
    echo "  Expected: ${BUILDDIR}/bin/clang or ${BUILDDIR}/bin/clang-22"
    ERRORS=$((ERRORS + 1))
fi

# Check for lld executable
if [ -f "${BUILDDIR}/bin/lld" ]; then
    echo "✓ Found lld"
else
    echo "✗ ERROR: lld executable not found"
    echo "  Expected: ${BUILDDIR}/bin/lld"
    ERRORS=$((ERRORS + 1))
fi

# Check for compiler-rt libraries (warning, not error)
COMPILER_RT_FOUND=0
if [ -d "${BUILDDIR}/lib/clang" ]; then
    # Check for PowerPC builtins
    if find "${BUILDDIR}/lib/clang" -name "libclang_rt.builtins-powerpc.a" -o \
            -name "libclang_rt.builtins-powerpc*.a" 2>/dev/null | grep -q .; then
        echo "✓ Found compiler-rt libraries"
        COMPILER_RT_FOUND=1
    fi
elif [ -f "${BUILDDIR}/lib/libclang_rt.builtins-powerpc.a" ]; then
    echo "✓ Found compiler-rt libraries"
    COMPILER_RT_FOUND=1
fi

if [ $COMPILER_RT_FOUND -eq 0 ]; then
    echo "⚠ WARNING: compiler-rt not found"
    echo "  Linking may fail with undefined symbols (__udivdi3, __muldi3, etc.)"
    echo "  Consider rebuilding with compiler-rt enabled"
    WARNINGS=$((WARNINGS + 1))
fi

# Check symlinks (if they exist, they should be valid)
echo ""
echo "Checking symlinks..."

# Check clang symlinks
for link in clang++ clang-cl clang-cpp; do
    if [ -L "${BUILDDIR}/bin/${link}" ]; then
        if [ -e "${BUILDDIR}/bin/${link}" ]; then
            echo "✓ Valid symlink: ${link}"
        else
            echo "✗ ERROR: Broken symlink: ${link}"
            ERRORS=$((ERRORS + 1))
        fi
    fi
done

# Check lld symlinks
for link in ld.lld lld-link ld64.lld wasm-ld; do
    if [ -L "${BUILDDIR}/bin/${link}" ]; then
        if [ -e "${BUILDDIR}/bin/${link}" ]; then
            echo "✓ Valid symlink: ${link}"
        else
            echo "✗ ERROR: Broken symlink: ${link}"
            ERRORS=$((ERRORS + 1))
        fi
    fi
done

# Check executables are actually executable
echo ""
echo "Checking executable permissions..."

for exe in clang clang-22 lld; do
    if [ -f "${BUILDDIR}/bin/${exe}" ]; then
        if [ -x "${BUILDDIR}/bin/${exe}" ]; then
            echo "✓ ${exe} is executable"
        else
            echo "✗ WARNING: ${exe} is not executable"
            WARNINGS=$((WARNINGS + 1))
        fi
    fi
done

# Summary
echo ""
echo "========================================"
if [ $ERRORS -eq 0 ] && [ $WARNINGS -eq 0 ]; then
    echo "✓ Validation passed: All checks passed"
    exit 0
elif [ $ERRORS -eq 0 ]; then
    echo "✓ Validation passed with warnings: ${WARNINGS} warning(s)"
    exit 0
else
    echo "✗ Validation failed: ${ERRORS} error(s), ${WARNINGS} warning(s)"
    exit 1
fi

