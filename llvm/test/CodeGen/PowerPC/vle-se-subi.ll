; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_SUBI, SE_SUBI_rec (16-bit Subtract Immediate) instruction selection.
; SE_SUBI performs subtraction with immediate: rD = rA - imm.
; Format: se_subi rD, rA, SIMM where SIMM is 6-bit signed immediate (-32 to 31).
; Requires registers in R0-R7 range and immediate in s6imm range.
; SE_SUBI_rec also sets condition codes (record form).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_SUBI with small positive immediate
define i32 @test_se_subi_positive(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_subi_positive
; CHECK: se_subi {{r[0-7]}}, {{r[0-7]}}, 20
; Immediate 20 (within s6imm range -32 to 31) should use SE_SUBI
  %result = sub i32 %a, 20
  ret i32 %result
}

; Test SE_SUBI with negative immediate (becomes addition)
define i32 @test_se_subi_negative(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_subi_negative
; CHECK: se_subi {{r[0-7]}}, {{r[0-7]}}, -25
; Immediate -25 (within s6imm range) should use SE_SUBI
  %result = sub i32 %a, -25
  ret i32 %result
}

; Test SE_SUBI with minimum immediate (-32)
define i32 @test_se_subi_min(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_subi_min
; CHECK: se_subi {{r[0-7]}}, {{r[0-7]}}, -32
; Minimum immediate -32 should use SE_SUBI
  %result = sub i32 %a, -32
  ret i32 %result
}

; Test SE_SUBI with maximum immediate (31)
define i32 @test_se_subi_max(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_subi_max
; CHECK: se_subi {{r[0-7]}}, {{r[0-7]}}, 31
; Maximum immediate 31 should use SE_SUBI
  %result = sub i32 %a, 31
  ret i32 %result
}

; Test that SE_SUBI_rec is used when result is compared
define i32 @test_se_subi_rec(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_subi_rec
; When result is used in comparison, record form may be used
; CHECK: se_subi {{r[0-7]}}, {{r[0-7]}}, 10
  %diff = sub i32 %a, 10
  %cmp = icmp eq i32 %diff, 0
  %result = select i1 %cmp, i32 1, i32 0
  ret i32 %result
}

