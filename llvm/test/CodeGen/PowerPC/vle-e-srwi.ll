; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_SRWI (32-bit Shift Right Word Immediate) instruction selection.
; E_SRWI performs logical right shift by immediate: rD = rA >> SH (0-31).
; Format: e_srwi rD, rA, SH. Supports all registers, SH in u5imm range.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.8.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_SRWI with immediate shift
define i32 @test_e_srwi(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_srwi
; CHECK: e_srwi {{r[0-9]+}}, {{r[0-9]+}}, 4
; Shift right immediate should use E_SRWI
  %result = lshr i32 %a, 4
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

