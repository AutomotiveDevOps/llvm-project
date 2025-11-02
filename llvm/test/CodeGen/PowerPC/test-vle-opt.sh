#!/bin/bash
# Quick test script for PPCVLEOpt pass
# Usage: ./test-vle-opt.sh <input.c|input.ll|input.mir>

set -e

# Default values
TARGET="powerpc-none-eabivle"
CPU="e200z4"
PASS="ppc-vle-opt"

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

if [ $# -eq 0 ]; then
    echo "Usage: $0 <input.c|input.ll|input.mir>"
    echo ""
    echo "This script tests the PPCVLEOpt pass in isolation."
    echo "It automatically converts C/LLVM IR to MIR and tests the pass."
    exit 1
fi

INPUT="$1"
BASENAME="${INPUT%.*}"
EXT="${INPUT##*.}"

echo -e "${YELLOW}Testing PPCVLEOpt pass on: ${INPUT}${NC}"

# Step 1: Convert to MIR if needed
if [ "$EXT" = "c" ] || [ "$EXT" = "cpp" ] || [ "$EXT" = "cc" ]; then
    echo "  [1/3] Converting C/C++ to LLVM IR..."
    if ! clang -target ${TARGET} -mcpu=${CPU} -mvle -Oz -S -emit-llvm \
         "${INPUT}" -o "${BASENAME}.ll" 2>/dev/null; then
        echo -e "${RED}Error: Failed to compile C/C++ to LLVM IR${NC}"
        echo "       Make sure clang is built and in PATH"
        exit 1
    fi
    INPUT="${BASENAME}.ll"
    EXT="ll"
fi

if [ "$EXT" = "ll" ]; then
    echo "  [2/3] Converting LLVM IR to MIR (after register allocation)..."
    if ! llc -mtriple=${TARGET} -mcpu=${CPU} -mvle -Oz \
         -stop-after=greedy -simplify-mir \
         "${INPUT}" -o "${BASENAME}.mir" 2>/dev/null; then
        echo -e "${RED}Error: Failed to convert LLVM IR to MIR${NC}"
        echo "       Make sure llc is built and in PATH"
        exit 1
    fi
    INPUT="${BASENAME}.mir"
fi

# Step 2: Run the pass
echo "  [3/3] Running ppc-vle-opt pass..."
OUTPUT="${BASENAME}_output.mir"
if ! llc -run-pass=${PASS} -mtriple=${TARGET} -mcpu=${CPU} -mvle \
     -verify-machineinstrs "${INPUT}" -o "${OUTPUT}" 2>&1; then
    echo -e "${RED}Error: Pass execution failed${NC}"
    exit 1
fi

# Step 3: Show diff
echo ""
echo -e "${GREEN}✓ Pass completed successfully!${NC}"
echo ""
echo "Comparing before and after:"
echo "============================"
if command -v diff >/dev/null 2>&1; then
    diff -u "${INPUT}" "${OUTPUT}" || true
else
    echo "diff command not found. Output saved to: ${OUTPUT}"
fi

# Step 4: Show statistics if available
echo ""
echo "Statistics:"
echo "==========="
if llc -run-pass=${PASS} -mtriple=${TARGET} -mcpu=${CPU} -mvle \
    -stats "${INPUT}" -o /dev/null 2>&1 | grep -i "vle" > /dev/null; then
    llc -run-pass=${PASS} -mtriple=${TARGET} -mcpu=${CPU} -mvle \
        -stats "${INPUT}" -o /dev/null 2>&1 | grep -i "vle" || echo "No statistics available"
fi

echo ""
echo -e "${GREEN}Output saved to: ${OUTPUT}${NC}"
echo ""
echo "Quick checks:"
echo "  - Look for SE_* instructions (16-bit VLE)"
echo "  - Check that R8+ registers don't convert"
echo "  - Verify immediate values are in range"

