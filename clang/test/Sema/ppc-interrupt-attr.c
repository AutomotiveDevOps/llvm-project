// RUN: %clang_cc1 -triple powerpc-unknown-unknown -fsyntax-only -verify %s
// RUN: %clang_cc1 -triple powerpc-unknown-unknown -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-IR

// Valid interrupt handler
__attribute__((interrupt)) void valid_handler(void) {}
// CHECK-IR: attributes #0 = { {{.*}}"interrupt"="standard"{{.*}} }

// Error: has return value
__attribute__((interrupt)) int invalid_return(void) { return 0; } // expected-warning {{PowerPC 'interrupt' attribute only applies to functions that have a 'void' return type}}

// Error: has parameters
__attribute__((interrupt)) void invalid_params(int x) {} // expected-warning {{PowerPC 'interrupt' attribute only applies to functions that have no parameters}}

// Valid with interrupt type
__attribute__((interrupt("critical"))) void critical_handler(void) {}
// CHECK-IR: attributes #2 = { {{.*}}"interrupt"="critical"{{.*}} }

__attribute__((interrupt("external"))) void external_handler(void) {}
// CHECK-IR: attributes #3 = { {{.*}}"interrupt"="external"{{.*}} }

// Valid: standard (default)
__attribute__((interrupt("standard"))) void standard_handler(void) {}
// CHECK-IR: attributes #4 = { {{.*}}"interrupt"="standard"{{.*}} }

// Error: unknown interrupt type
__attribute__((interrupt("unknown"))) void bad_handler(void) {} // expected-warning {{'interrupt' attribute argument not supported: 'unknown'}}

