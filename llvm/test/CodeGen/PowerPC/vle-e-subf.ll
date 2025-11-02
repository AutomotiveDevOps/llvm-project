; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test E_SUBF (32-bit VLE Subtract From) instruction selection.
; E_SUBF performs subtraction: rD = rB - rA (note: operands are reversed).
; Format: e_subf rD, rA, rB. Supports all registers.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_SUBF basic operation
define i32 @test_e_subf(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_subf
; CHECK: e_subf {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; Subtraction with extended registers should use E_SUBF
  %result = sub i32 %b, %a
  ret i32 %result
}

