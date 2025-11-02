; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_CMPWI (32-bit Compare Word Immediate) instruction selection.
; E_CMPWI compares register with signed immediate: CR = (rA ? SIMM) signed.
; Format: e_cmpwi rA, SIMM. SIMM is 16-bit signed immediate.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.5.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_CMPWI signed comparison
define i1 @test_e_cmpwi(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_cmpwi
; CHECK: e_cmpwi {{r[0-9]+}}, 100
; CHECK: bc
; Signed compare immediate should use E_CMPWI
  %cmp = icmp sgt i32 %a, 100
  ret i1 %cmp
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

