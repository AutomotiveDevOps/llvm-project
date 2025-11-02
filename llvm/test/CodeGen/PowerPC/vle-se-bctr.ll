; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_BCTR (16-bit Branch to Count Register) instruction selection.
; SE_BCTR branches via count register: PC = CTR.
; Format: se_bctr. Used for indirect calls and computed jumps.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.4.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_BCTR via indirect call
define i32 @test_se_bctr(i32 (i32)* %func, i32 %arg) optsize minsize {
entry:
; CHECK-LABEL: @test_se_bctr
; CHECK: se_bctr
; Indirect call should use SE_BCTR
  %result = call i32 %func(i32 %arg)
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

