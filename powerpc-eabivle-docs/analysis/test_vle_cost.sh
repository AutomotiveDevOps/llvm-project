#!/bin/bash
# Quick test script for VLE cost model
# Usage: ./test_vle_cost.sh [test_file.ll]

set -e

# Configuration
PROJECT_ROOT="/projects/llvm-project"
BUILD_DIR="${PROJECT_ROOT}/build"
TEST_FILE="${1:-${PROJECT_ROOT}/llvm/test/Analysis/CostModel/PowerPC/vle-cost-size.ll}"

# Colors for output
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}=== VLE Cost Model Test ===${NC}"
echo "Test file: ${TEST_FILE}"
echo ""

if [ ! -f "${TEST_FILE}" ]; then
    echo "Error: Test file not found: ${TEST_FILE}"
    exit 1
fi

OPT_BIN="${BUILD_DIR}/bin/opt"
if [ ! -f "${OPT_BIN}" ]; then
    echo "Error: opt not found at ${OPT_BIN}"
    echo "Please build LLVM first: cd build && ninja opt"
    exit 1
fi

echo -e "${GREEN}=== With VLE enabled (powerpc-none-eabivle) ===${NC}"
${OPT_BIN} < "${TEST_FILE}" \
    -cost-model -cost-kind=code-size -analyze \
    -mtriple=powerpc-none-eabivle 2>&1 | \
    grep --color=never "Cost Model" | head -20

echo ""
echo -e "${GREEN}=== Without VLE (baseline - powerpc-none-unknown) ===${NC}"
${OPT_BIN} < "${TEST_FILE}" \
    -cost-model -cost-kind=code-size -analyze \
    -mtriple=powerpc-none-unknown 2>&1 | \
    grep --color=never "Cost Model" | head -20

echo ""
echo -e "${BLUE}=== Test Complete ===${NC}"

