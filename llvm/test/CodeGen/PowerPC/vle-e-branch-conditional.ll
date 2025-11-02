; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test 32-bit E-form conditional branch instructions.
; Tests E_BC, E_BCL, E_BCCTR, E_BCLR, E_BCTRL, E_BCLRL for extended displacement.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.4.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_BC conditional branch
define i32 @test_e_bc(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_bc
; CHECK: e_cmpwi
; CHECK: e_bc
; Conditional branch with extended displacement should use E_BC
  %cmp = icmp sgt i32 %a, 100
  br i1 %cmp, label %if_large, label %if_small

if_large:
  ret i32 1

if_small:
  ret i32 0
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

