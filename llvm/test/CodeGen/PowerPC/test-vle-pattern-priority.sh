#!/bin/bash
# Standalone test script for VLE pattern prioritization
# This script tests whether VLE patterns are selected over standard PowerPC patterns
#
# Usage: ./test-vle-pattern-priority.sh [path-to-llc] [path-to-test-file]
#
# Example: ./test-vle-pattern-priority.sh build/bin/llc vle-pattern-priority-test.ll

set -e

LLC="${1:-llc}"
TEST_FILE="${2:-vle-pattern-priority-test.ll}"

if [ ! -f "${TEST_FILE}" ]; then
    echo "Error: Test file ${TEST_FILE} not found"
    exit 1
fi

echo "Testing VLE pattern prioritization..."
echo "Using llc: ${LLC}"
echo "Test file: ${TEST_FILE}"
echo ""

# Test 1: Code size optimization (-Oz) - should prefer VLE
echo "=== Test 1: Code Size Optimization (-Oz) ==="
echo "Expected: Should generate VLE instructions (se_*, e_*)"
OUTPUT_VLE="test-output-vle.s"
${LLC} -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -mattr=+vle -Oz \
    -o "${OUTPUT_VLE}" "${TEST_FILE}" 2>&1 || echo "Warning: llc failed"

if [ -f "${OUTPUT_VLE}" ]; then
    echo "Generated assembly (${OUTPUT_VLE}):"
    VLE_COUNT=$(grep -cE "(se_|e_)" "${OUTPUT_VLE}" || echo "0")
    echo "  VLE instructions found: ${VLE_COUNT}"
    echo ""
    echo "VLE instructions in output:"
    grep -E "(se_|e_)" "${OUTPUT_VLE}" || echo "  (none found)"
    echo ""
else
    echo "Error: Failed to generate output"
fi

# Test 2: Performance optimization (-O2) - may not prefer VLE
echo "=== Test 2: Performance Optimization (-O2) ==="
echo "Expected: May generate standard PowerPC instructions"
OUTPUT_STD="test-output-std.s"
${LLC} -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -mattr=+vle -O2 \
    -o "${OUTPUT_STD}" "${TEST_FILE}" 2>&1 || echo "Warning: llc failed"

if [ -f "${OUTPUT_STD}" ]; then
    echo "Generated assembly (${OUTPUT_STD}):"
    STD_COUNT=$(grep -cE "(addi|add|stw)" "${OUTPUT_STD}" || echo "0")
    echo "  Standard instructions found: ${STD_COUNT}"
    echo ""
fi

# Comparison
if [ -f "${OUTPUT_VLE}" ] && [ -f "${OUTPUT_STD}" ]; then
    echo "=== Comparison ==="
    echo "Differences between -Oz and -O2 outputs:"
    diff -u "${OUTPUT_STD}" "${OUTPUT_VLE}" || true
    echo ""
    
    # File size comparison (rough indicator)
    SIZE_VLE=$(stat -f%z "${OUTPUT_VLE}" 2>/dev/null || stat -c%s "${OUTPUT_VLE}" 2>/dev/null || echo "0")
    SIZE_STD=$(stat -f%z "${OUTPUT_STD}" 2>/dev/null || stat -c%s "${OUTPUT_STD}" 2>/dev/null || echo "0")
    echo "Output file sizes:"
    echo "  -Oz output: ${SIZE_VLE} bytes"
    echo "  -O2 output: ${SIZE_STD} bytes"
    if [ "${SIZE_VLE}" -lt "${SIZE_STD}" ]; then
        echo "  ✓ -Oz output is smaller (expected)"
    elif [ "${SIZE_VLE}" -gt "${SIZE_STD}" ]; then
        echo "  ⚠ -Oz output is larger (unexpected - VLE should reduce code size)"
    else
        echo "  = Same size"
    fi
fi

echo ""
echo "=== Test Summary ==="
if [ -f "${OUTPUT_VLE}" ]; then
    if grep -qE "(se_|e_)" "${OUTPUT_VLE}"; then
        echo "✓ VLE instructions found in -Oz output (good)"
    else
        echo "✗ No VLE instructions found in -Oz output (pattern prioritization may not be working)"
    fi
fi

# Cleanup option
read -p "Clean up generated files? (y/N) " -n 1 -r
echo
if [[ $REPLY =~ ^[Yy]$ ]]; then
    rm -f "${OUTPUT_VLE}" "${OUTPUT_STD}"
    echo "Cleaned up test files"
fi

