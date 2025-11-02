// RUN: %clang_cc1 -triple powerpc-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -triple powerpc64-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-PPC64
// RUN: %clang_cc1 -triple powerpc64le-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-PPC64

__attribute__((interrupt)) void test_generic_interrupt() {
  // CHECK: define void @test_generic_interrupt() [[GENERIC_ATTR:#[0-9]+]]
  // CHECK-PPC64: define void @test_generic_interrupt() [[GENERIC_ATTR:#[0-9]+]]
}

__attribute__((interrupt("critical"))) void test_critical_interrupt() {
  // CHECK: define void @test_critical_interrupt() [[CRITICAL_ATTR:#[0-9]+]]
  // CHECK-PPC64: define void @test_critical_interrupt() [[CRITICAL_ATTR:#[0-9]+]]
}

__attribute__((interrupt("external"))) void test_external_interrupt() {
  // CHECK: define void @test_external_interrupt() [[EXTERNAL_ATTR:#[0-9]+]]
  // CHECK-PPC64: define void @test_external_interrupt() [[EXTERNAL_ATTR:#[0-9]+]]
}

// CHECK: attributes [[GENERIC_ATTR]] = { {{.*}} "interrupt"
// CHECK: attributes [[CRITICAL_ATTR]] = { {{.*}} "interrupt"="critical"
// CHECK: attributes [[EXTERNAL_ATTR]] = { {{.*}} "interrupt"="external"

// CHECK-PPC64: attributes [[GENERIC_ATTR]] = { {{.*}} "interrupt"
// CHECK-PPC64: attributes [[CRITICAL_ATTR]] = { {{.*}} "interrupt"="critical"
// CHECK-PPC64: attributes [[EXTERNAL_ATTR]] = { {{.*}} "interrupt"="external"

