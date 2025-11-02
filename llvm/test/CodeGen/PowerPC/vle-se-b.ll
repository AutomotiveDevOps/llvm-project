; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test SE_B (16-bit unconditional branch) instruction selection.
; SE_B performs unconditional branch with 8-bit signed displacement.
; Format: se_b dst. Displacement is word-aligned, range -256 to +254 bytes.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.4.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_B forward branch
define i32 @test_se_b_forward(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_b_forward
  %cmp = icmp eq i32 %a, 0
  br i1 %cmp, label %true, label %end
; CHECK: se_b
true:
  ret i32 1
end:
  ret i32 0
}

