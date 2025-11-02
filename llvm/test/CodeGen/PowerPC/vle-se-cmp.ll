; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_CMP (16-bit Compare Register) instruction selection.
; SE_CMP compares two registers: CR = (rA ? rB) signed comparison.
; Format: se_cmp rA, rB. Sets condition codes for signed comparison.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.5.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_CMP signed comparison
define i1 @test_se_cmp(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_cmp
; CHECK: se_cmp {{r[0-7]}}, {{r[0-7]}}
; CHECK: bc
; Signed compare should use SE_CMP
  %cmp = icmp slt i32 %a, %b
  ret i1 %cmp
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

