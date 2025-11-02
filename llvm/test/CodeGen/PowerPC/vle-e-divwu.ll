; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_DIVWU (32-bit Divide Word Unsigned) instruction selection.
; E_DIVWU performs unsigned division: rD = rA / rB (unsigned).
; Format: e_divwu rD, rA, rB. This is a 32-bit VLE instruction.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.5

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_DIVWU unsigned division
define i32 @test_e_divwu(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_divwu
; CHECK: e_divwu {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; Unsigned division should use E_DIVWU
  %result = udiv i32 %a, %b
  ret i32 %result
}

; Test E_DIVWU with constant divisor
define i32 @test_e_divwu_const(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_divwu_const
; CHECK: e_divwu {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; Constant divisor should use E_DIVWU after loading constant
  %result = udiv i32 %a, 16
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

