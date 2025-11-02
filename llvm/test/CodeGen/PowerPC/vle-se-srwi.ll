; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_SRWI (16-bit Shift Right Word Immediate) instruction selection.
; SE_SRWI performs logical right shift: rD = rA >> SH (0-31).
; Format: se_srwi rD, rA, SH. Requires registers in R0-R7, SH in u5imm range.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.8.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_SRWI with small shift amount
define i32 @test_se_srwi(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_srwi
; CHECK: se_srwi {{r[0-7]}}, {{r[0-7]}}, 3
; Shift right immediate should use SE_SRWI
  %result = lshr i32 %a, 3
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

