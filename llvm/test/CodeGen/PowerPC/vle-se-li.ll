; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_LI (16-bit Load Immediate) instruction selection.
; SE_LI loads 7-bit unsigned immediate: rD = UIMM (0-127).
; Format: se_li rD, UIMM. Requires register in R0-R7 range.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.6.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_LI with small immediate
define i32 @test_se_li_small() optsize minsize {
entry:
; CHECK-LABEL: @test_se_li_small
; CHECK: se_li {{r[0-7]}}, 50
; Small immediate should use SE_LI
  ret i32 50
}

; Test SE_LI with maximum u7imm value
define i32 @test_se_li_max() optsize minsize {
entry:
; CHECK-LABEL: @test_se_li_max
; CHECK: se_li {{r[0-7]}}, 127
; Maximum u7imm value should use SE_LI
  ret i32 127
}

; Test SE_LI with zero
define i32 @test_se_li_zero() optsize minsize {
entry:
; CHECK-LABEL: @test_se_li_zero
; CHECK: se_li {{r[0-7]}}, 0
; Zero should use SE_LI
  ret i32 0
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

