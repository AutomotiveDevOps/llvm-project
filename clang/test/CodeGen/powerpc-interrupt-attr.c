// RUN: %clang_cc1 -triple powerpc-unknown-unknown -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-STD
// RUN: %clang_cc1 -triple powerpc-none-eabivle -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-VLE
// RUN: %clang_cc1 -triple powerpc-none-elf -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-E200

// Verify that interrupt attribute is correctly emitted to LLVM IR for all PowerPC targets

// Standard interrupt handler
__attribute__((interrupt)) void standard_handler(void) {
  // CHECK-STD: define void @standard_handler() [[STD_ATTR:#[0-9]+]]
  // CHECK-VLE: define void @standard_handler() [[STD_ATTR:#[0-9]+]]
  // CHECK-E200: define void @standard_handler() [[STD_ATTR:#[0-9]+]]
}

// Critical interrupt handler
__attribute__((interrupt("critical"))) void critical_handler(void) {
  // CHECK-STD: define void @critical_handler() [[CRIT_ATTR:#[0-9]+]]
  // CHECK-VLE: define void @critical_handler() [[CRIT_ATTR:#[0-9]+]]
  // CHECK-E200: define void @critical_handler() [[CRIT_ATTR:#[0-9]+]]
}

// External interrupt handler
__attribute__((interrupt("external"))) void external_handler(void) {
  // CHECK-STD: define void @external_handler() [[EXT_ATTR:#[0-9]+]]
  // CHECK-VLE: define void @external_handler() [[EXT_ATTR:#[0-9]+]]
  // CHECK-E200: define void @external_handler() [[EXT_ATTR:#[0-9]+]]
}

// Test that non-interrupt functions don't have the attribute
void normal_function(void) {
  // CHECK-STD: define void @normal_function() [[NORM_ATTR:#[0-9]+]]
  // CHECK-VLE: define void @normal_function() [[NORM_ATTR:#[0-9]+]]
  // CHECK-E200: define void @normal_function() [[NORM_ATTR:#[0-9]+]]
}

// CHECK-STD: attributes [[STD_ATTR]] = { {{.*}} "interrupt"="standard" {{.*}} }
// CHECK-STD: attributes [[CRIT_ATTR]] = { {{.*}} "interrupt"="critical" {{.*}} }
// CHECK-STD: attributes [[EXT_ATTR]] = { {{.*}} "interrupt"="external" {{.*}} }
// CHECK-STD: attributes [[NORM_ATTR]] = { {{.*}} }
// CHECK-STD-NOT: attributes [[NORM_ATTR]] = { {{.*}} "interrupt"

// CHECK-VLE: attributes [[STD_ATTR]] = { {{.*}} "interrupt"="standard" {{.*}} }
// CHECK-VLE: attributes [[CRIT_ATTR]] = { {{.*}} "interrupt"="critical" {{.*}} }
// CHECK-VLE: attributes [[EXT_ATTR]] = { {{.*}} "interrupt"="external" {{.*}} }
// CHECK-VLE: attributes [[NORM_ATTR]] = { {{.*}} }
// CHECK-VLE-NOT: attributes [[NORM_ATTR]] = { {{.*}} "interrupt"

// CHECK-E200: attributes [[STD_ATTR]] = { {{.*}} "interrupt"="standard" {{.*}} }
// CHECK-E200: attributes [[CRIT_ATTR]] = { {{.*}} "interrupt"="critical" {{.*}} }
// CHECK-E200: attributes [[EXT_ATTR]] = { {{.*}} "interrupt"="external" {{.*}} }
// CHECK-E200: attributes [[NORM_ATTR]] = { {{.*}} }
// CHECK-E200-NOT: attributes [[NORM_ATTR]] = { {{.*}} "interrupt"

