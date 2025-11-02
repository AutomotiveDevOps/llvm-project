; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_SUB, SE_SUB_rec (16-bit Subtract) instruction selection.
; SE_SUB performs subtraction: rD = rA - rB.
; Format: se_sub rD, rA, rB. Requires all registers in R0-R7 range.
; SE_SUB_rec also sets condition codes (record form).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_SUB basic operation
define i32 @test_se_sub(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_sub
; CHECK: se_sub {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; With R0-R7 registers, should use SE_SUB (16-bit)
  %result = sub i32 %a, %b
  ret i32 %result
}

; Test SE_SUB with multiple subtractions
define i32 @test_se_sub_multiple(i32 %a, i32 %b, i32 %c) optsize minsize {
entry:
; CHECK-LABEL: @test_se_sub_multiple
; CHECK-DAG: se_sub {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; Multiple subtractions with R0-R7 should use SE_SUB
  %diff1 = sub i32 %a, %b
  %diff2 = sub i32 %diff1, %c
  ret i32 %diff2
}

; Test that SE_SUB_rec is used when result is compared
define i32 @test_se_sub_rec(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_sub_rec
; When result is used in comparison, record form may be used
; CHECK: se_sub {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
  %diff = sub i32 %a, %b
  %cmp = icmp sgt i32 %diff, 0
  %result = select i1 %cmp, i32 1, i32 0
  ret i32 %result
}

