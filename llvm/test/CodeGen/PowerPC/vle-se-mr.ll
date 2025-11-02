; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_MR (16-bit Move Register) instruction selection.
; SE_MR performs register copy: rD = rA.
; Format: se_mr rD, rA. Requires registers in R0-R7 range.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_MR basic operation
define i32 @test_se_mr(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_mr
; CHECK: se_mr {{r[0-7]}}, {{r[0-7]}}
; With R0-R7 registers, should use SE_MR (16-bit)
  ret i32 %a
}

; Test SE_MR with multiple moves
define i32 @test_se_mr_multiple(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_mr_multiple
; CHECK-DAG: se_mr {{r[0-7]}}, {{r[0-7]}}
; Multiple register copies with R0-R7 should use SE_MR
  %copy1 = add i32 %a, 0
  %copy2 = add i32 %b, 0
  %sum = add i32 %copy1, %copy2
  ret i32 %sum
}

