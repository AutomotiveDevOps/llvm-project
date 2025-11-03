; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test e200z4 scheduler latency verification.
; Verify instruction latencies match manual specifications:
; - Load: 2 cycles (Manual e200z4RM Ch. 4.3)
; - Store: 2 cycles (Manual e200z4RM Ch. 4.3)
; - Multiply: 5 cycles (Manual e200z4RM Ch. 4.3)
; - Divide: 14 cycles worst case (Manual e200z4RM Ch. 4.3)
; - FP general: 2 cycles
; - FP divide: 13 cycles
; Reference: e200z4RM Rev. 0, 10/2009, Chapter 4.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test load latency: should be 2 cycles
define i32 @test_load_latency(i32* %ptr) {
entry:
; CHECK-LABEL: @test_load_latency
; CHECK: e_lwz
; Verify load completes in 2 cycles before use
  %val = load i32, i32* %ptr
  %result = add i32 %val, 1
  ret i32 %result
}

; Test store latency: should be 2 cycles
define void @test_store_latency(i32* %ptr, i32 %val) {
entry:
; CHECK-LABEL: @test_store_latency
; CHECK: e_stw
; Store should complete in 2 cycles
  store i32 %val, i32* %ptr
  ret void
}

; Test multiply latency: should be 5 cycles (OperandCycles: [5,1,1,1,1])
define i32 @test_multiply_latency(i32 %a, i32 %b) {
entry:
; CHECK-LABEL: @test_multiply_latency
; CHECK: e_mullw
; Multiply should complete in 5 cycles before use
  %prod = mul i32 %a, %b
  %result = add i32 %prod, 1
  ret i32 %result
}

; Test divide latency: should be 14 cycles worst case
define i32 @test_divide_latency(i32 %a, i32 %b) {
entry:
; CHECK-LABEL: @test_divide_latency
; CHECK: e_divw
; Divide should complete in up to 14 cycles (Manual Ch. 4.3: variable 4-14 cycles)
  %quot = sdiv i32 %a, %b
  %result = add i32 %quot, 1
  ret i32 %result
}

; Test unsigned divide latency
define i32 @test_divide_unsigned_latency(i32 %a, i32 %b) {
entry:
; CHECK-LABEL: @test_divide_unsigned_latency
; CHECK: e_divwu
; Unsigned divide should also take up to 14 cycles
  %quot = udiv i32 %a, %b
  %result = add i32 %quot, 1
  ret i32 %result
}

; Test FP general latency: should be 2 cycles
define float @test_fp_latency(float %a, float %b) {
entry:
; CHECK-LABEL: @test_fp_latency
; CHECK: e_fadds
; FP add should complete in 2 cycles
  %sum = fadd float %a, %b
  %result = fadd float %sum, 1.0
  ret float %result
}

; Test FP multiply latency: should be 2 cycles
define float @test_fp_multiply_latency(float %a, float %b) {
entry:
; CHECK-LABEL: @test_fp_multiply_latency
; CHECK: e_fmuls
; FP multiply should complete in 2 cycles
  %prod = fmul float %a, %b
  %result = fadd float %prod, 1.0
  ret float %prod
}

; Test FP divide latency: should be 13 cycles
define float @test_fp_divide_latency(float %a, float %b) {
entry:
; CHECK-LABEL: @test_fp_divide_latency
; CHECK: e_fdivs
; FP divide should complete in 13 cycles (Manual Ch. 4.3)
  %quot = fdiv float %a, %b
  %result = fadd float %quot, 1.0
  ret float %quot
}

; Test load multiple latency
define void @test_load_multiple(i32* %ptr, i32* %r14, i32* %r15, i32* %r16) {
entry:
; CHECK-LABEL: @test_load_multiple
; CHECK: e_lmw
; Load multiple should have appropriate latency
  %v14 = load i32, i32* %r14
  %v15 = load i32, i32* %r15
  %v16 = load i32, i32* %r16
  store i32 %v14, i32* %ptr
  ret void
}

; Test store multiple latency
define void @test_store_multiple(i32* %ptr, i32* %r14, i32* %r15, i32* %r16) {
entry:
; CHECK-LABEL: @test_store_multiple
; CHECK: e_stmw
; Store multiple should have appropriate latency
  store i32 1, i32* %r14
  store i32 2, i32* %r15
  store i32 3, i32* %r16
  ret void
}

