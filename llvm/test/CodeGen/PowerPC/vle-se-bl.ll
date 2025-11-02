; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test SE_BL (16-bit branch and link) instruction selection.
; SE_BL performs function call, saving return address in LR.
; Format: se_bl dst. Displacement is word-aligned, range -256 to +254 bytes.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.4.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

declare i32 @callee(i32)

; Test SE_BL function call
define i32 @test_se_bl(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_bl
  %result = call i32 @callee(i32 %a)
; CHECK: se_bl
  ret i32 %result
}

