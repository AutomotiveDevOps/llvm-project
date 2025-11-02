// Minimal C test for VLE pattern prioritization
// Compile with: clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz -S -o test.s test.c

// Test 1: Small immediate addition - should generate se_addi (16-bit)
int test_addi_small(int a) {
    return a + 15;  // Immediate fits in 5-bit signed field (-31 to 31)
}

// Test 2: Register addition - should generate e_add (32-bit VLE)
int test_add_reg(int a, int b) {
    return a + b;
}

// Test 3: Small immediate subtraction - should generate se_subi (16-bit)
int test_subi_small(int a) {
    return a - 10;  // Immediate fits in 5-bit signed field
}

// Test 4: Store - should generate se_stw (16-bit) for small offsets
void test_store_small(int *ptr, int val) {
    *ptr = val;  // Base register + offset 0
}

