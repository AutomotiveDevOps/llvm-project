; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test SE_MFLR (16-bit Move From Link Register) instruction selection.
; SE_MFLR copies the Link Register (LR) to a general-purpose register.
; Format: se_mflr rD. Requires register in R0-R7 range.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.5.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_MFLR
define i32 @test_se_mflr() optsize minsize {
entry:
; CHECK-LABEL: @test_se_mflr
; CHECK: se_mflr {{r[0-7]}}
; Move from link register should use SE_MFLR
  %lr = call i32 @llvm.read_register.i32(metadata !0)
  ret i32 %lr
}

declare i32 @llvm.read_register.i32(metadata)

!0 = !{!"lr"}

