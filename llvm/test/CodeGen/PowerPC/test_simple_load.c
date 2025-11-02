// Simple test case to demonstrate PPCVLEOpt pass testing
// Tests load instruction with R0-R7 register

int test_load(int *base) {
    return base[5];  // Offset 20 (5 * 4), should use R3 as base
}

