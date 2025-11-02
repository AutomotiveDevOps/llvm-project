; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test E_SUBFIC (32-bit VLE Subtract From Immediate Carrying) instruction selection.
; E_SUBFIC performs subtraction: rD = imm - rA, and sets carry bit.
; Format: e_subfic rD, rA, SIMM.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_SUBFIC basic operation
define i32 @test_e_subfic(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_subfic
; CHECK: e_subfic {{r[0-9]+}}, {{r[0-9]+}}, 100
; Subtract from immediate should use E_SUBFIC
  %result = sub i32 100, %a
  ret i32 %result
}

