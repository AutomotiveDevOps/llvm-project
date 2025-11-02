; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test SE_OR (16-bit OR) instruction selection.
; SE_OR performs bitwise OR: rD = rA | rB.
; Format: se_or rD, rA, rB. Requires all registers in R0-R7 range.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_OR basic operation
define i32 @test_se_or(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_or
; CHECK: se_or {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; With R0-R7 registers, should use SE_OR (16-bit)
  %result = or i32 %a, %b
  ret i32 %result
}

