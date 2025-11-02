; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_CMPLWI (32-bit Compare Logical Word Immediate) instruction selection.
; E_CMPLWI compares register with unsigned immediate: CR = (rA ? UIMM) unsigned.
; Format: e_cmplwi rA, UIMM. UIMM is 16-bit unsigned immediate.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.5.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_CMPLWI unsigned comparison
define i1 @test_e_cmplwi(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_cmplwi
; CHECK: e_cmplwi {{r[0-9]+}}, 200
; CHECK: bc
; Unsigned compare immediate should use E_CMPLWI
  %cmp = icmp ugt i32 %a, 200
  ret i1 %cmp
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

