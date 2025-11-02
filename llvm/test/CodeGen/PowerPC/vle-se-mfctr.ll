; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_MFCTR (16-bit Move From Count Register) instruction selection.
; SE_MFCTR reads count register: rD = CTR.
; Format: se_mfctr rD. Requires register in R0-R7 range.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.6.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_MFCTR (read count register)
define i32 @test_se_mfctr() optsize minsize {
entry:
; CHECK-LABEL: @test_se_mfctr
; CHECK: se_mfctr {{r[0-7]}}
; Move from count register should use SE_MFCTR
  %ctr = call i32 @llvm.ppc.mfctr()
  ret i32 %ctr
}

declare i32 @llvm.ppc.mfctr()

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

