; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_DIVW (32-bit Divide Word Signed) instruction selection.
; E_DIVW performs signed division: rD = rA / rB (signed).
; Format: e_divw rD, rA, rB. This is a 32-bit VLE instruction.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.5

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_DIVW signed division
define i32 @test_e_divw(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_divw
; CHECK: e_divw {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; Signed division should use E_DIVW
  %result = sdiv i32 %a, %b
  ret i32 %result
}

; Test E_DIVW with constant divisor
define i32 @test_e_divw_const(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_divw_const
; CHECK: e_divw {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; Constant divisor should use E_DIVW after loading constant
  %result = sdiv i32 %a, 10
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

