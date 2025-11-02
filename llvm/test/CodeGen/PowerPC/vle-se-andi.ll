; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_ANDI (16-bit AND Immediate) instruction selection.
; SE_ANDI performs: rD = rA & UIMM.
; Format: se_andi rD, rA, UIMM. Requires registers in R0-R7, immediate 0-31 (u5imm).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_ANDI with immediate in range
define i32 @test_se_andi_small(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_andi_small
; CHECK: se_andi {{r[0-7]}}, {{r[0-7]}}, 15
; AND with small immediate should use SE_ANDI
  %result = and i32 %a, 15
  ret i32 %result
}

; Test SE_ANDI with maximum u5imm value
define i32 @test_se_andi_max(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_andi_max
; CHECK: se_andi {{r[0-7]}}, {{r[0-7]}}, 31
; Maximum u5imm value should use SE_ANDI
  %result = and i32 %a, 31
  ret i32 %result
}

; Test SE_ANDI with zero (clearing bits)
define i32 @test_se_andi_zero(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_andi_zero
; CHECK: se_andi {{r[0-7]}}, {{r[0-7]}}, 0
; AND with zero should use SE_ANDI
  %result = and i32 %a, 0
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

