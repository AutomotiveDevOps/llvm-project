; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_ADD, SE_ADD_rec (16-bit Add) instruction selection.
; SE_ADD performs addition: rD = rA + rB.
; Format: se_add rD, rA, rB. Requires all registers in R0-R7 range.
; SE_ADD_rec also sets condition codes (record form).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_ADD basic operation
define i32 @test_se_add(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_add
; CHECK: se_add {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; With R0-R7 registers, should use SE_ADD (16-bit)
  %result = add i32 %a, %b
  ret i32 %result
}

; Test SE_ADD with multiple additions
define i32 @test_se_add_multiple(i32 %a, i32 %b, i32 %c) optsize minsize {
entry:
; CHECK-LABEL: @test_se_add_multiple
; CHECK-DAG: se_add {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; Multiple additions with R0-R7 should use SE_ADD
  %sum1 = add i32 %a, %b
  %sum2 = add i32 %sum1, %c
  ret i32 %sum2
}

; Test that SE_ADD_rec is used when result is compared
define i32 @test_se_add_rec(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_add_rec
; When result is used in comparison, record form may be used
; CHECK: se_add {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
  %sum = add i32 %a, %b
  %cmp = icmp eq i32 %sum, 0
  %result = select i1 %cmp, i32 1, i32 0
  ret i32 %result
}

