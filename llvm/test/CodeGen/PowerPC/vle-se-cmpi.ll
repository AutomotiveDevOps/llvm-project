; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test SE_CMPI (16-bit Compare Immediate) instruction selection.
; SE_CMPI compares register with signed immediate and sets condition register.
; Format: se_cmpi crD, rA, SIMM where SIMM is 6-bit signed (-32 to 31).
; Requires registers in R0-R7 range and immediate in s6imm range.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_CMPI with immediate in range
define i32 @test_se_cmpi(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_cmpi
; CHECK: se_cmpi {{r[0-7]}}, 15
; Compare with immediate in s6imm range should use SE_CMPI
  %cmp = icmp eq i32 %a, 15
  %result = zext i1 %cmp to i32
  ret i32 %result
}

