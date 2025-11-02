; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_MULLW (32-bit Multiply Word) instruction selection.
; E_MULLW performs signed multiplication: rD = (rA * rB)[31:0].
; Format: e_mullw rD, rA, rB. This is a 32-bit VLE instruction.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.4

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_MULLW basic multiplication
define i32 @test_e_mullw(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_mullw
; CHECK: e_mullw {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; Multiply word should use E_MULLW
  %result = mul i32 %a, %b
  ret i32 %result
}

; Test E_MULLW with constant multiplier
define i32 @test_e_mullw_const(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_mullw_const
; CHECK: e_mullw {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; Constant multiplier should still use E_MULLW if constant doesn't fit immediate
  %result = mul i32 %a, 100
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

