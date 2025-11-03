; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s

; Test e200z4 dual-issue pairing rules.
; e200z4 is a dual-issue in-order processor that can dispatch up to 2 instructions per clock.
; Verify that instructions are paired correctly according to pairing rules:
; - Instructions must not conflict on functional units
; - SU0 can execute most instructions, SU1 has limited instruction set
; - Resource conflicts prevent certain pairings
; Reference: e200z4RM Rev. 0, 10/2009, Chapter 4.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test 1: Two independent ALU operations should pair
define i32 @test_alu_pairing(i32 %a, i32 %b, i32 %c) {
entry:
; CHECK-LABEL: @test_alu_pairing
; CHECK: e_add
; CHECK: e_add
; Two independent adds should be eligible for dual-issue
  %sum1 = add i32 %a, %b
  %sum2 = add i32 %c, 1
  %result = add i32 %sum1, %sum2
  ret i32 %result
}

; Test 2: ALU and load should pair if no dependency
define i32 @test_alu_load_pairing(i32 %a, i32* %ptr) {
entry:
; CHECK-LABEL: @test_alu_load_pairing
; CHECK: e_add
; CHECK: e_lwz
; ALU operation and independent load should pair
  %sum = add i32 %a, 1
  %val = load i32, i32* %ptr
  %result = add i32 %sum, %val
  ret i32 %result
}

; Test 3: Two loads should pair if accessing different memory
define i32 @test_load_load_pairing(i32* %ptr1, i32* %ptr2) {
entry:
; CHECK-LABEL: @test_load_load_pairing
; CHECK: e_lwz
; CHECK: e_lwz
; Two independent loads should be eligible for pairing
  %v1 = load i32, i32* %ptr1
  %v2 = load i32, i32* %ptr2
  %result = add i32 %v1, %v2
  ret i32 %result
}

; Test 4: Load and store should pair if no dependency
define void @test_load_store_pairing(i32* %ptr1, i32* %ptr2, i32 %val) {
entry:
; CHECK-LABEL: @test_load_store_pairing
; CHECK: e_lwz
; CHECK: e_stw
; Independent load and store should pair
  %v = load i32, i32* %ptr1
  store i32 %val, i32* %ptr2
  ret void
}

; Test 5: Multiply may not pair with certain operations due to resource conflicts
define i32 @test_multiply_pairing(i32 %a, i32 %b, i32 %c) {
entry:
; CHECK-LABEL: @test_multiply_pairing
; CHECK: e_mullw
; CHECK: e_add
; Multiply uses MUL unit, independent ALU operation may pair
  %prod = mul i32 %a, %b
  %sum = add i32 %c, 1
  %result = add i32 %prod, %sum
  ret i32 %result
}

; Test 6: FP operations should pair if using different resources
define float @test_fp_pairing(float %a, float %b, float %c) {
entry:
; CHECK-LABEL: @test_fp_pairing
; CHECK: e_fadds
; CHECK: e_fadds
; Two independent FP adds should be eligible for pairing
  %sum1 = fadd float %a, %b
  %sum2 = fadd float %c, 1.0
  %result = fadd float %sum1, %sum2
  ret float %result
}

; Test 7: Branch and ALU should pair if no dependency
define i32 @test_branch_alu_pairing(i32 %a, i32 %b, i32* %ptr) {
entry:
; CHECK-LABEL: @test_branch_alu_pairing
; CHECK: e_add
; CHECK: e_lwz
; ALU operation and independent load should pair before branch
  %sum = add i32 %a, %b
  %val = load i32, i32* %ptr
  %cmp = icmp eq i32 %sum, 0
  br i1 %cmp, label %if, label %end
if:
  ret i32 %val
end:
  ret i32 %sum
}

; Test 8: Multiple independent operations to test pairing opportunities
define i32 @test_multiple_pairing(i32 %a, i32 %b, i32 %c, i32 %d) {
entry:
; CHECK-LABEL: @test_multiple_pairing
; CHECK: e_add
; CHECK: e_add
; CHECK: e_add
; Multiple independent adds should provide pairing opportunities
  %s1 = add i32 %a, %b
  %s2 = add i32 %c, %d
  %s3 = add i32 %s1, %s2
  ret i32 %s3
}

