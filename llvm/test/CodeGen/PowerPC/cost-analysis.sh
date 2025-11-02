#!/bin/bash
# Comprehensive cost analysis script for PowerPC instruction selection
# Tests various optimization levels and analyzes instruction mix, code size, and switching costs

set -e

TEST_DIR="/projects/llvm-project/llvm/test/CodeGen/PowerPC"
C_FILE="${TEST_DIR}/cost-analysis-test.c"
BASE_NAME="cost-analysis-test"

# Try to find clang and llc in common locations
CLANG="clang"
LLC="llc"

# Check if we're in a build directory context
if [ -f "/projects/llvm-project/build/bin/clang" ]; then
    CLANG="/projects/llvm-project/build/bin/clang"
    LLC="/projects/llvm-project/build/bin/llc"
elif [ -d "/projects/llvm-project/build" ]; then
    CLANG="/projects/llvm-project/build/bin/clang"
    LLC="/projects/llvm-project/build/bin/llc"
fi

echo "=== PowerPC Cost Analysis Test ==="
echo "C Source: ${C_FILE}"
echo "Clang: ${CLANG}"
echo "LLC: ${LLC}"
echo ""

# Check if tools exist
if ! command -v ${CLANG} &> /dev/null && [ ! -f "${CLANG}" ]; then
    echo "Warning: clang not found, trying system clang"
    CLANG="clang"
fi

if ! command -v ${LLC} &> /dev/null && [ ! -f "${LLC}" ]; then
    echo "Warning: llc not found, trying system llc"
    LLC="llc"
fi

cd "${TEST_DIR}"

# Generate LLVM IR from C
echo "=== Step 1: Generate LLVM IR ==="
IR_FILE="${BASE_NAME}.ll"
${CLANG} -target powerpc-none-eabivle -mcpu=e200z4 -mvle -S -emit-llvm \
    -o "${IR_FILE}" "${C_FILE}" 2>&1 || {
    echo "Error: Failed to generate LLVM IR"
    exit 1
}

IR_SIZE=$(wc -c < "${IR_FILE}")
echo "Generated LLVM IR: ${IR_FILE} (${IR_SIZE} bytes)"
echo ""

# Compile with different optimization levels
OPT_LEVELS=("O0" "O1" "O2" "O3" "Oz")
declare -A ASM_FILES
declare -A OBJ_FILES
declare -A CODE_SIZES
declare -A INSTR_COUNTS
declare -A VLE_INSTR_COUNTS
declare -A STD_INSTR_COUNTS

echo "=== Step 2: Compile with Different Optimization Levels ==="
for OPT in "${OPT_LEVELS[@]}"; do
    OPT_FLAG="-${OPT}"
    if [ "${OPT}" == "O0" ]; then
        OPT_FLAG="-O0"
    fi
    
    ASM_FILE="${BASE_NAME}-${OPT}.s"
    OBJ_FILE="${BASE_NAME}-${OPT}.o"
    
    echo "Compiling with ${OPT_FLAG}..."
    
    # Generate assembly
    ${LLC} -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -mattr=+vle \
        ${OPT_FLAG} -o "${ASM_FILE}" "${IR_FILE}" 2>&1 || {
        echo "Warning: Failed to generate assembly with ${OPT_FLAG}"
        continue
    }
    
    ASM_FILES["${OPT}"]="${ASM_FILE}"
    
    # Try to assemble (may fail if assembler not available, that's OK)
    if command -v powerpc-none-eabivle-as &> /dev/null || \
       command -v llvm-mc &> /dev/null; then
        if command -v llvm-mc &> /dev/null; then
            llvm-mc -triple=powerpc-none-eabivle -filetype=obj \
                -o "${OBJ_FILE}" "${ASM_FILE}" 2>/dev/null || true
        fi
    fi
    
    if [ -f "${OBJ_FILE}" ]; then
        OBJ_FILES["${OPT}"]="${OBJ_FILE}"
        CODE_SIZES["${OPT}"]=$(stat -f%z "${OBJ_FILE}" 2>/dev/null || \
                                stat -c%s "${OBJ_FILE}" 2>/dev/null || echo "0")
    fi
    
    # Count instructions
    if [ -f "${ASM_FILE}" ]; then
        INSTR_COUNTS["${OPT}"]=$(grep -cE '^\s+[a-z]' "${ASM_FILE}" || echo "0")
        VLE_INSTR_COUNTS["${OPT}"]=$(grep -cE '(se_|e_)' "${ASM_FILE}" || echo "0")
        STD_INSTR_COUNTS["${OPT}"]=$(grep -cE '(addi|add|sub|mul|div|stw|lwz|b)' "${ASM_FILE}" || echo "0")
    fi
done

echo ""

# Detailed analysis
echo "=== Step 3: Code Size Analysis ==="
printf "%-6s %12s %12s %12s %12s %12s\n" "Level" "IR Size" "ASM Size" "Object Size" "Instructions" "VLE Instr"
echo "--------------------------------------------------------------------------------"

for OPT in "${OPT_LEVELS[@]}"; do
    IR_S=$(echo "${IR_SIZE}" | awk '{printf "%'d", $1}')
    ASM_S="N/A"
    OBJ_S="N/A"
    INSTR="N/A"
    VLE="N/A"
    
    if [ -f "${ASM_FILES[${OPT}]}" ]; then
        ASM_S=$(wc -c < "${ASM_FILES[${OPT}]}" | awk '{printf "%'d", $1}')
    fi
    
    if [ -n "${OBJ_FILES[${OPT}]}" ] && [ -f "${OBJ_FILES[${OPT}]}" ]; then
        OBJ_S=$(echo "${CODE_SIZES[${OPT}]}" | awk '{printf "%'d", $1}')
    fi
    
    if [ -n "${INSTR_COUNTS[${OPT}]}" ]; then
        INSTR="${INSTR_COUNTS[${OPT}]}"
    fi
    
    if [ -n "${VLE_INSTR_COUNTS[${OPT}]}" ]; then
        VLE="${VLE_INSTR_COUNTS[${OPT}]}"
    fi
    
    printf "%-6s %12s %12s %12s %12s %12s\n" "${OPT}" "${IR_S}" "${ASM_S}" "${OBJ_S}" "${INSTR}" "${VLE}"
done

echo ""

# Instruction mix analysis
echo "=== Step 4: Instruction Mix Analysis ==="
for OPT in "${OPT_LEVELS[@]}"; do
    if [ -f "${ASM_FILES[${OPT}]}" ]; then
        echo ""
        echo "--- ${OPT} Optimization Level ---"
        echo "Total instructions: ${INSTR_COUNTS[${OPT}]}"
        echo "VLE instructions (se_*/e_*): ${VLE_INSTR_COUNTS[${OPT}]}"
        echo "Standard instructions: ${STD_INSTR_COUNTS[${OPT}]}"
        
        # Instruction type breakdown
        echo ""
        echo "Instruction type breakdown:"
        grep -E '^\s+[a-z]' "${ASM_FILES[${OPT}]}" | \
            sed 's/^\s*\([a-z][a-z0-9_]*\).*/\1/' | \
            sort | uniq -c | sort -rn | head -20 || echo "  (could not analyze)"
    fi
done

echo ""

# Switching cost analysis
echo "=== Step 5: Mode Switching Cost Analysis ==="
echo "Analyzing cost of switching between instruction sets..."

for OPT in "${OPT_LEVELS[@]}"; do
    if [ -f "${ASM_FILES[${OPT}]}" ]; then
        echo ""
        echo "--- ${OPT} Analysis ---"
        
        # Count mode switches (VLE to standard and vice versa)
        # This is approximated by counting transitions between VLE and non-VLE instructions
        VLE_TRANSITIONS=0
        STD_TRANSITIONS=0
        
        PREV_IS_VLE=false
        while IFS= read -r line; do
            if echo "${line}" | grep -qE '(se_|e_)'; then
                IS_VLE=true
            else
                IS_VLE=false
            fi
            
            if [ "${PREV_IS_VLE}" = true ] && [ "${IS_VLE}" = false ]; then
                ((STD_TRANSITIONS++)) || true
            elif [ "${PREV_IS_VLE}" = false ] && [ "${IS_VLE}" = true ]; then
                ((VLE_TRANSITIONS++)) || true
            fi
            
            PREV_IS_VLE="${IS_VLE}"
        done < "${ASM_FILES[${OPT}]}"
        
        TOTAL_SWITCHES=$((VLE_TRANSITIONS + STD_TRANSITIONS))
        echo "  VLE→Standard transitions: ${STD_TRANSITIONS}"
        echo "  Standard→VLE transitions: ${VLE_TRANSITIONS}"
        echo "  Total mode switches: ${TOTAL_SWITCHES}"
        
        # Estimate switching cost (each switch has overhead)
        # Conservative estimate: 2-4 cycles per switch on e200 cores
        if [ "${TOTAL_SWITCHES}" -gt 0 ]; then
            ESTIMATED_COST=$((TOTAL_SWITCHES * 3))  # 3 cycles per switch
            echo "  Estimated switching cost: ~${ESTIMATED_COST} cycles"
        fi
    fi
done

echo ""

# Comparison table
echo "=== Step 6: Optimization Comparison ==="
if [ -n "${CODE_SIZES[O0]}" ] && [ -n "${CODE_SIZES[O3]}" ]; then
    SIZE_REDUCTION=$((CODE_SIZES[O0] - CODE_SIZES[O3]))
    PERCENT_REDUCTION=$(awk "BEGIN {printf \"%.1f\", (${SIZE_REDUCTION}/${CODE_SIZES[O0]})*100}")
    echo "Code size reduction (O0 → O3): ${SIZE_REDUCTION} bytes (${PERCENT_REDUCTION}%)"
fi

if [ -n "${INSTR_COUNTS[O0]}" ] && [ -n "${INSTR_COUNTS[O3]}" ]; then
    INSTR_REDUCTION=$((INSTR_COUNTS[O0] - INSTR_COUNTS[O3]))
    PERCENT_REDUCTION=$(awk "BEGIN {printf \"%.1f\", (${INSTR_REDUCTION}/${INSTR_COUNTS[O0]})*100}")
    echo "Instruction count reduction (O0 → O3): ${INSTR_REDUCTION} instructions (${PERCENT_REDUCTION}%)"
fi

echo ""

# Summary
echo "=== Step 7: Summary & Recommendations ==="
echo ""
echo "Files generated:"
for OPT in "${OPT_LEVELS[@]}"; do
    if [ -f "${ASM_FILES[${OPT}]}" ]; then
        echo "  ${ASM_FILES[${OPT}]}"
    fi
done
echo "  ${IR_FILE}"
echo ""

echo "Key Findings:"
if [ -n "${VLE_INSTR_COUNTS[Oz]}" ] && [ "${VLE_INSTR_COUNTS[Oz]}" -gt 0 ]; then
    echo "  ✓ VLE instructions are being generated with -Oz"
else
    echo "  ✗ VLE instructions may not be prioritized (pattern selection issue)"
fi

if [ -n "${CODE_SIZES[Oz]}" ] && [ -n "${CODE_SIZES[O3]}" ]; then
    if [ "${CODE_SIZES[Oz]}" -lt "${CODE_SIZES[O3]}" ]; then
        echo "  ✓ -Oz produces smaller code than -O3 (expected)"
    else
        echo "  ⚠ -Oz code size is not smaller than -O3 (unexpected)"
    fi
fi

echo ""
echo "Analysis complete!"

