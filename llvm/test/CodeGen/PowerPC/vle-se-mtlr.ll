; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_MTLR (16-bit Move To Link Register) instruction selection.
; SE_MTLR moves value to link register: LR = rA.
; Format: se_mtlr rA. Requires register in R0-R7 range.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.6.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_MTLR (set link register)
define void @test_se_mtlr(i32 %addr) optsize minsize {
entry:
; CHECK-LABEL: @test_se_mtlr
; CHECK: se_mtlr {{r[0-7]}}
; Move to link register should use SE_MTLR
  call void @llvm.ppc.mtlr(i32 %addr)
  ret void
}

declare void @llvm.ppc.mtlr(i32)

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

