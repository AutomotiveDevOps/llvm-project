; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_CMPLI (16-bit Compare Logical Immediate) instruction selection.
; SE_CMPLI compares register with unsigned immediate: CR = (rA ? UIMM) unsigned.
; Format: se_cmpli rA, UIMM. UIMM is 5-bit unsigned (0-31).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.5.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_CMPLI unsigned comparison
define i1 @test_se_cmpli(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_cmpli
; CHECK: se_cmpli {{r[0-7]}}, 20
; CHECK: bc
; Unsigned compare immediate should use SE_CMPLI
  %cmp = icmp ult i32 %a, 20
  ret i1 %cmp
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

