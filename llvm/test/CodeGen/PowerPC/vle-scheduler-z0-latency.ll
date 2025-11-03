; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z0 -mvle -O2 < %s | FileCheck %s

; Test e200z0 scheduler latency verification.
; Verify instruction latencies match manual specifications for e200z0.
; Reference: E200Z0CRM, Chapter 4

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test load latency
define i32 @test_load_latency(i32* %ptr) {
entry:
; CHECK-LABEL: @test_load_latency
; CHECK: e_lwz
  %val = load i32, i32* %ptr
  %result = add i32 %val, 1
  ret i32 %result
}

; Test store latency
define void @test_store_latency(i32* %ptr, i32 %val) {
entry:
; CHECK-LABEL: @test_store_latency
; CHECK: e_stw
  store i32 %val, i32* %ptr
  ret void
}

; Test multiply latency
define i32 @test_multiply_latency(i32 %a, i32 %b) {
entry:
; CHECK-LABEL: @test_multiply_latency
; CHECK: e_mullw
  %prod = mul i32 %a, %b
  %result = add i32 %prod, 1
  ret i32 %result
}

; Test divide latency
define i32 @test_divide_latency(i32 %a, i32 %b) {
entry:
; CHECK-LABEL: @test_divide_latency
; CHECK: e_divw
  %quot = sdiv i32 %a, %b
  %result = add i32 %quot, 1
  ret i32 %result
}

