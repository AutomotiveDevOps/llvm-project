; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_BGT (16-bit Branch if Greater Than) instruction selection.
; SE_BGT branches if rA > 0 (signed): if (rA > 0) then branch.
; Format: se_bgt rA, BD8. BD8 is 8-bit signed displacement.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.4.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_BGT
define i32 @test_se_bgt(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_bgt
; CHECK: se_bgt {{r[0-7]}},
; Branch if greater than should use SE_BGT
  %cmp = icmp sgt i32 %a, 0
  br i1 %cmp, label %if_positive, label %if_nonpositive

if_positive:
  ret i32 1

if_nonpositive:
  ret i32 0
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

