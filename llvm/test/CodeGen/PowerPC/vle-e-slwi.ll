; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_SLWI (32-bit Shift Left Word Immediate) instruction selection.
; E_SLWI performs left shift by immediate: rD = rA << SH (0-31).
; Format: e_slwi rD, rA, SH. Supports all registers, SH in u5imm range.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.8.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_SLWI with immediate shift
define i32 @test_e_slwi(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_slwi
; CHECK: e_slwi {{r[0-9]+}}, {{r[0-9]+}}, 8
; Shift left immediate should use E_SLWI
  %result = shl i32 %a, 8
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

