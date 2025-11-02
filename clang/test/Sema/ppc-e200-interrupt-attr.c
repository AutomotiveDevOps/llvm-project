// RUN: %clang_cc1 -triple powerpc-none-eabivle -fsyntax-only -verify %s
// RUN: %clang_cc1 -triple powerpc-none-eabivle -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-VLE
// RUN: %clang_cc1 -triple powerpc-none-elf -fsyntax-only -verify %s
// RUN: %clang_cc1 -triple powerpc-none-elf -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-E200

// Test: Basic interrupt handler for e200/VLE targets
__attribute__((interrupt)) void e200_basic_handler(void) {}
// CHECK-VLE: attributes #0 = { {{.*}}"interrupt"="standard"{{.*}} }
// CHECK-E200: attributes #0 = { {{.*}}"interrupt"="standard"{{.*}} }

// Test: Critical interrupt handler
__attribute__((interrupt("critical"))) void e200_critical_handler(void) {
  // Critical interrupt handler (IVOR0)
}
// CHECK-VLE: attributes #1 = { {{.*}}"interrupt"="critical"{{.*}} }
// CHECK-E200: attributes #1 = { {{.*}}"interrupt"="critical"{{.*}} }

// Test: External interrupt handler
__attribute__((interrupt("external"))) void e200_external_handler(void) {
  // External interrupt handler (IVOR4)
}
// CHECK-VLE: attributes #2 = { {{.*}}"interrupt"="external"{{.*}} }
// CHECK-E200: attributes #2 = { {{.*}}"interrupt"="external"{{.*}} }

// Test: Standard interrupt handler (explicit)
__attribute__((interrupt("standard"))) void e200_standard_handler(void) {
  // Standard interrupt handler
}
// CHECK-VLE: attributes #3 = { {{.*}}"interrupt"="standard"{{.*}} }
// CHECK-E200: attributes #3 = { {{.*}}"interrupt"="standard"{{.*}} }

// Test: Error - non-void return type
__attribute__((interrupt)) int e200_invalid_return(void) { return 0; } // expected-warning {{PowerPC 'interrupt' attribute only applies to functions that have a 'void' return type}}

// Test: Error - has parameters
__attribute__((interrupt)) void e200_invalid_params(int x) {} // expected-warning {{PowerPC 'interrupt' attribute only applies to functions that have no parameters}}

// Test: Error - unknown interrupt type
__attribute__((interrupt("unknown"))) void e200_invalid_type(void) {} // expected-warning {{'interrupt' attribute argument not supported: 'unknown'}}

// Test: Multiple handlers with different types
__attribute__((interrupt("critical"))) void handler1(void) {}
__attribute__((interrupt("external"))) void handler2(void) {}
__attribute__((interrupt)) void handler3(void) {}
// CHECK-VLE: attributes #4 = { {{.*}}"interrupt"="critical"{{.*}} }
// CHECK-VLE: attributes #5 = { {{.*}}"interrupt"="external"{{.*}} }
// CHECK-VLE: attributes #6 = { {{.*}}"interrupt"="standard"{{.*}} }
// CHECK-E200: attributes #4 = { {{.*}}"interrupt"="critical"{{.*}} }
// CHECK-E200: attributes #5 = { {{.*}}"interrupt"="external"{{.*}} }
// CHECK-E200: attributes #6 = { {{.*}}"interrupt"="standard"{{.*}} }

