/*
 * Comprehensive cost analysis test for PowerPC instruction selection
 * Tests: vectorization, arithmetic, memory ops, control flow, mixed workloads
 * Size: ~1KB of source code with realistic patterns
 */

#define SIZE 256
#define ITERATIONS 1000

// Vector dot product - tests SIMD/vectorization
int vector_dot_product(int *a, int *b, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

// Matrix multiplication - tests nested loops and memory access patterns
void matrix_multiply(int *A, int *B, int *C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += A[i * n + k] * B[k * n + j];
            }
            C[i * n + j] = sum;
        }
    }
}

// Mixed arithmetic operations - tests instruction selection variety
int arithmetic_mix(int x, int y, int z) {
    int a = x + y;           // Addition
    int b = a - z;           // Subtraction
    int c = b * 3;           // Multiplication by constant
    int d = c / 2;           // Division
    int e = d & 0xFF;        // Bitwise AND
    int f = e | 0x100;       // Bitwise OR
    int g = f ^ 0x55;        // Bitwise XOR
    int h = g << 2;          // Left shift
    int i = h >> 1;          // Right shift
    return i;
}

// Memory intensive operations - tests load/store patterns
void memory_operations(int *src, int *dst, int count) {
    for (int i = 0; i < count; i++) {
        int val = src[i];
        val = val * 2 + 1;   // Process
        dst[i] = val;
    }
}

// Conditional operations - tests branch prediction and selects
int conditional_operations(int a, int b, int c) {
    int result = 0;
    if (a > b) {
        result = a + c;
    } else {
        result = b - c;
    }
    
    // Ternary-like operations
    int x = (a > 0) ? a : -a;
    int y = (b < 0) ? b * 2 : b / 2;
    
    return result + x + y;
}

// Loop with multiple operations - tests optimization and unrolling
int loop_optimization_test(int *data, int len) {
    int sum = 0;
    int product = 1;
    int max_val = data[0];
    int min_val = data[0];
    
    for (int i = 1; i < len; i++) {
        sum += data[i];
        product *= data[i];
        if (data[i] > max_val) max_val = data[i];
        if (data[i] < min_val) min_val = data[i];
    }
    
    return (sum + product) / (max_val - min_val + 1);
}

// Function calls and recursion - tests call overhead
int recursive_sum(int n) {
    if (n <= 0) return 0;
    return n + recursive_sum(n - 1);
}

// Array processing with stride - tests memory access patterns
void strided_access(int *array, int stride, int count) {
    for (int i = 0; i < count * stride; i += stride) {
        array[i] = array[i] * 2 + 1;
    }
}

// Complex conditional with bit manipulation
int bit_manipulation(int value) {
    // Count set bits (popcount-like)
    int count = 0;
    int temp = value;
    while (temp) {
        count += temp & 1;
        temp >>= 1;
    }
    
    // Find highest set bit
    int highest = 0;
    temp = value;
    while (temp > 1) {
        highest++;
        temp >>= 1;
    }
    
    return count * highest;
}

// Main test harness - exercises all functions
int main() {
    int array_a[SIZE];
    int array_b[SIZE];
    int array_c[SIZE * SIZE];
    int result = 0;
    
    // Initialize arrays
    for (int i = 0; i < SIZE; i++) {
        array_a[i] = i;
        array_b[i] = SIZE - i;
    }
    
    // Run all tests
    result += vector_dot_product(array_a, array_b, SIZE);
    matrix_multiply(array_a, array_b, array_c, 16);
    result += arithmetic_mix(100, 200, 50);
    memory_operations(array_a, array_b, SIZE);
    result += conditional_operations(10, 20, 5);
    result += loop_optimization_test(array_a, SIZE);
    result += recursive_sum(100);
    strided_access(array_a, 4, SIZE / 4);
    result += bit_manipulation(0xABCDEF);
    
    return result;
}

