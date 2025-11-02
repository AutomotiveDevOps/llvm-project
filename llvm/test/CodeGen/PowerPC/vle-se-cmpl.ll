; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_CMPL (16-bit Compare Logical Register) instruction selection.
; SE_CMPL compares two registers logically (unsigned): CR = (rA ? rB) unsigned.
; Format: se_cmpl rA, rB. Sets condition codes for unsigned comparison.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.5.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_CMPL unsigned comparison
define i1 @test_se_cmpl(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_cmpl
; CHECK: se_cmpl {{r[0-7]}}, {{r[0-7]}}
; CHECK: bc
; Unsigned compare should use SE_CMPL
  %cmp = icmp ult i32 %a, %b
  ret i1 %cmp
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

