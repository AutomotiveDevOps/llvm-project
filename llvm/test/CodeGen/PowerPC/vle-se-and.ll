; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test SE_AND, SE_AND_rec (16-bit AND) instruction selection.
; SE_AND performs bitwise AND: rD = rA & rB.
; Format: se_and rD, rA, rB. Requires all registers in R0-R7 range.
; SE_AND_rec also sets condition codes (record form).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_AND basic operation
define i32 @test_se_and(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_and
; CHECK: se_and {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; With R0-R7 registers, should use SE_AND (16-bit)
  %result = and i32 %a, %b
  ret i32 %result
}

