; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_BLR (16-bit Branch to Link Register) instruction selection.
; SE_BLR returns from function: PC = LR.
; Format: se_blr. No operands, uses link register.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.4.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_BLR (function return)
define void @test_se_blr() optsize minsize {
entry:
; CHECK-LABEL: @test_se_blr
; CHECK: se_blr
; Return from function should use SE_BLR
  ret void
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

