#!/bin/bash
# Demonstration script showing how to test PPCVLEOpt pass
# This shows the expected workflow even if tools aren't built yet

set -e

echo "========================================="
echo "PPCVLEOpt Pass Testing Demonstration"
echo "========================================="
echo ""

TEST_DIR="/projects/llvm-project/llvm/test/CodeGen/PowerPC"
cd "${TEST_DIR}"

echo "Step 1: Create a simple C test file"
echo "-----------------------------------"
cat > test_demo.c << 'EOF'
int test_load(int *base) {
    return base[5];  // Offset 20
}
EOF
echo "Created: test_demo.c"
echo ""

echo "Step 2: Convert to LLVM IR"
echo "-------------------------"
echo "Command: clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz \\"
echo "                -S -emit-llvm test_demo.c -o test_demo.ll"
echo ""
if command -v clang >/dev/null 2>&1; then
    if clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz \
        -S -emit-llvm test_demo.c -o test_demo.ll 2>&1; then
        echo "✓ Successfully created test_demo.ll"
        echo ""
        echo "LLVM IR content (first 20 lines):"
        head -20 test_demo.ll
    else
        echo "⚠ clang command failed (might not support PowerPC target)"
    fi
else
    echo "⚠ clang not found in PATH"
fi
echo ""

echo "Step 3: Generate MIR after register allocation"
echo "-----------------------------------------------"
echo "Command: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz \\"
echo "             -stop-after=greedy -simplify-mir test_demo.ll -o test_demo.mir"
echo ""

if command -v llc >/dev/null 2>&1; then
    if llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz \
        -stop-after=greedy -simplify-mir test_demo.ll -o test_demo.mir 2>&1; then
        echo "✓ Successfully created test_demo.mir"
        echo ""
        echo "MIR content (showing key parts):"
        grep -A 5 "body:" test_demo.mir | head -10 || cat test_demo.mir | head -30
    else
        echo "⚠ llc command failed or not built"
    fi
else
    echo "⚠ llc not found - you'll need to build LLVM first"
    echo ""
    echo "Expected MIR would contain:"
    echo "  - Physical registers (e.g., \$r3, \$r4)"
    echo "  - LBZ instruction: \$r4 = LBZ \$r3, 20"
fi
echo ""

echo "Step 4: Run PPCVLEOpt pass in isolation"
echo "--------------------------------------"
echo "Command: llc -run-pass=ppc-vle-opt -mtriple=powerpc-none-eabivle \\"
echo "             -mcpu=e200z4 -mvle -verify-machineinstrs \\"
echo "             test_demo.mir -o test_demo_output.mir"
echo ""

if command -v llc >/dev/null 2>&1 && [ -f test_demo.mir ]; then
    if llc -run-pass=ppc-vle-opt -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle \
        -verify-machineinstrs test_demo.mir -o test_demo_output.mir 2>&1; then
        echo "✓ Pass executed successfully"
        echo ""
        echo "Before (test_demo.mir):"
        grep "LBZ\|SE_LBZ" test_demo.mir || echo "  (no LBZ found)"
        echo ""
        echo "After (test_demo_output.mir):"
        grep "LBZ\|SE_LBZ" test_demo_output.mir || echo "  (no LBZ found)"
        echo ""
        echo "Difference:"
        diff -u test_demo.mir test_demo_output.mir 2>/dev/null | head -20 || echo "  (no diff tool or files missing)"
    else
        echo "⚠ llc -run-pass failed (pass might not be registered or MIR invalid)"
    fi
else
    echo "⚠ Cannot run - llc not found or MIR not generated"
    echo ""
    echo "Expected behavior:"
    echo "  - If register is R0-R7 AND offset <= 15: LBZ → SE_LBZ"
    echo "  - If register is R8+ OR offset > 15: LBZ stays as LBZ"
fi
echo ""

echo "Step 5: View statistics"
echo "---------------------"
echo "Command: llc -run-pass=ppc-vle-opt -mtriple=powerpc-none-eabivle \\"
echo "             -mcpu=e200z4 -mvle -stats test_demo.mir -o /dev/null 2>&1 | grep -i vle"
echo ""

if command -v llc >/dev/null 2>&1 && [ -f test_demo.mir ]; then
    STATS=$(llc -run-pass=ppc-vle-opt -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle \
        -stats test_demo.mir -o /dev/null 2>&1 | grep -i vle || true)
    if [ -n "$STATS" ]; then
        echo "$STATS"
    else
        echo "  (no statistics output)"
    fi
else
    echo "⚠ Cannot run statistics"
fi
echo ""

echo "========================================="
echo "Testing the existing comprehensive test file"
echo "========================================="
echo ""

if [ -f ppc-vle-opt-test.mir ]; then
    echo "Running: llvm-lit ppc-vle-opt-test.mir"
    echo ""
    
    if command -v llvm-lit >/dev/null 2>&1; then
        llvm-lit ppc-vle-opt-test.mir 2>&1 | head -30
    elif command -v llc >/dev/null 2>&1; then
        echo "Running manual test with llc:"
        llc -run-pass=ppc-vle-opt -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle \
            -verify-machineinstrs ppc-vle-opt-test.mir -o ppc-vle-opt-test-output.mir 2>&1
        
        if [ -f ppc-vle-opt-test-output.mir ]; then
            echo ""
            echo "Key conversions found:"
            grep -c "SE_LBZ\|SE_ADDI\|SE_ADD\|SE_STW\|SE_CMPI" ppc-vle-opt-test-output.mir || echo "  (none found)"
        fi
    else
        echo "⚠ Cannot run test - llvm-lit and llc not found"
        echo ""
        echo "The test file contains 8 test cases:"
        echo "  1. test_vle_load_eligible - R3, offset 10 → SE_LBZ"
        echo "  2. test_vle_load_ineligible_reg - R8, offset 10 → stays LBZ"
        echo "  3. test_vle_load_ineligible_imm - R5, offset 20 → stays LBZ"
        echo "  4. test_vle_addi_eligible - R1, imm 15 → SE_ADDI"
        echo "  5. test_vle_addi_ineligible_imm - R2, imm 50 → stays ADDI"
        echo "  6. test_vle_add_eligible - R4+R5 → SE_ADD"
        echo "  7. test_vle_store_eligible - R3+R7, offset 20 → SE_STW"
        echo "  8. test_vle_cmpi_eligible - R6, imm 10 → SE_CMPI"
    fi
else
    echo "⚠ Test file ppc-vle-opt-test.mir not found"
fi

echo ""
echo "========================================="
echo "Summary: Testing Limitations"
echo "========================================="
echo ""
echo "The pass has 3 key limitations you can test:"
echo ""
echo "1. POST-RA LIMITATION: Only sees physical registers"
echo "   - Test: Verify pass only converts when it sees R0-R7"
echo "   - Cannot test with virtual registers (they're gone by now)"
echo ""
echo "2. REGISTER RANGE: Only handles R0-R7"
echo "   - Test: R8+ registers → no conversion"
echo "   - Example: R10 load → stays as LBZ, not SE_LBZ"
echo ""
echo "3. NO REALLOCATION: Cannot change register assignments"
echo "   - Test: Instruction with R10 cannot be 'fixed' to use R3"
echo "   - Pass can only convert if registers already in range"
echo ""
echo "========================================="

