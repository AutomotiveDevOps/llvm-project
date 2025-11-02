; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_BLT (16-bit Branch if Less Than) instruction selection.
; SE_BLT branches if rA < 0 (signed): if (rA < 0) then branch.
; Format: se_blt rA, BD8. BD8 is 8-bit signed displacement.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.4.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_BLT
define i32 @test_se_blt(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_blt
; CHECK: se_blt {{r[0-7]}},
; Branch if less than should use SE_BLT
  %cmp = icmp slt i32 %a, 0
  br i1 %cmp, label %if_negative, label %if_nonnegative

if_negative:
  ret i32 -1

if_nonnegative:
  ret i32 %a
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

