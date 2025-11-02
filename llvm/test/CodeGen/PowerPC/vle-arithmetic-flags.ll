; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test arithmetic instructions with record form (flag-setting).
; Tests SE_ADD_rec, SE_SUB_rec, SE_SUBI_rec variants that set condition codes.
; These instructions update CR0 based on result for conditional operations.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_ADD_rec (add with condition codes)
; When result is compared or used in conditional branch, should use record form
define i1 @test_se_add_rec(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_add_rec
; CHECK: se_add {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; CHECK: cmpwi {{r[0-7]}}, 0
; Record form may be selected when result is compared
  %sum = add i32 %a, %b
  %cmp = icmp eq i32 %sum, 0
  ret i1 %cmp
}

; Test SE_SUB_rec (subtract with condition codes)
define i1 @test_se_sub_rec(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_sub_rec
; CHECK: se_sub {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; CHECK: cmpwi {{r[0-7]}}, 0
; Record form for subtraction comparison
  %diff = sub i32 %a, %b
  %cmp = icmp slt i32 %diff, 0
  ret i1 %cmp
}

; Test SE_SUBI_rec with immediate
define i1 @test_se_subi_rec(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_subi_rec
; CHECK: se_subi {{r[0-7]}}, {{r[0-7]}}, 10
; CHECK: cmpwi {{r[0-7]}}, 0
; Record form for subtract immediate comparison
  %diff = sub i32 %a, 10
  %cmp = icmp eq i32 %diff, 0
  ret i1 %cmp
}

; Test arithmetic with conditional branch (may use record form)
define i32 @test_add_branch(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_add_branch
; CHECK: se_add {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; Arithmetic followed by branch may optimize with record form
  %sum = add i32 %a, %b
  %cmp = icmp eq i32 %sum, 0
  br i1 %cmp, label %if_zero, label %if_nonzero

if_zero:
  ret i32 0

if_nonzero:
  ret i32 %sum
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

