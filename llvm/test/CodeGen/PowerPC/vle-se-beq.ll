; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test SE_BEQ (16-bit branch if equal) instruction selection.
; SE_BEQ branches if condition register bit 0 (EQ) is set.
; Format: se_beq dst. Displacement is word-aligned, range -256 to +254 bytes.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.4.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_BEQ conditional branch
define i32 @test_se_beq(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_beq
  %cmp = icmp eq i32 %a, %b
  br i1 %cmp, label %equal, label %notequal
; CHECK: se_beq
equal:
  ret i32 1
notequal:
  ret i32 0
}

