/**
 * Simple test file to verify R0-R7 register allocation for VLE instructions.
 * 
 * Compile with:
 *   clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz -S vle-reg-alloc-test.c
 * 
 * Check output for:
 *   - 16-bit VLE instructions (se_addi, se_add, se_subi, etc.)
 *   - Registers R0-R7 being used in those instructions
 * 
 * To verify register allocation is working:
 *   grep "se_" vle-reg-alloc-test.s | grep -E "r[0-7]"
 * 
 * Should see multiple 16-bit VLE instructions using R0-R7 registers.
 */

// Test 1: Simple add immediate - should use se_addi with R0-R7
int test_addi(int a) {
    return a + 10;  // Small immediate, should use se_addi
}

// Test 2: Register-register add - should use se_add if both in R0-R7
int test_add(int a, int b) {
    return a + b;  // Should prefer se_add with R0-R7
}

// Test 3: Multiple operations - tests register pressure handling
int test_multiple_ops(int a, int b, int c) {
    int tmp1 = a + 5;      // se_addi
    int tmp2 = tmp1 + b;   // se_add
    return tmp2 - 3;       // se_subi
}

// Test 4: Load/store operations
int test_load_store(int *ptr, int val) {
    *ptr = val;            // se_stw with R0-R7 base
    return *ptr;           // se_lwz with R0-R7 base
}

