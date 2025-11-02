; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test SE_XOR (16-bit XOR) instruction selection.
; SE_XOR performs bitwise XOR: rD = rA ^ rB.
; Format: se_xor rD, rA, rB. Requires all registers in R0-R7 range.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_XOR basic operation
define i32 @test_se_xor(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_xor
; CHECK: se_xor {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; With R0-R7 registers, should use SE_XOR (16-bit)
  %result = xor i32 %a, %b
  ret i32 %result
}

