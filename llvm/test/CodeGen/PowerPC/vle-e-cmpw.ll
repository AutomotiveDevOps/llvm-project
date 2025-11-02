; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_CMPW (32-bit Compare Word) instruction selection.
; E_CMPW compares two registers: CR = (rA ? rB) signed comparison.
; Format: e_cmpw rA, rB. Supports all registers (not limited to R0-R7).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.5.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_CMPW signed comparison
define i1 @test_e_cmpw(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_cmpw
; CHECK: e_cmpw {{r[0-9]+}}, {{r[0-9]+}}
; CHECK: bc
; Signed compare with extended registers should use E_CMPW
  %cmp = icmp sgt i32 %a, %b
  ret i1 %cmp
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

