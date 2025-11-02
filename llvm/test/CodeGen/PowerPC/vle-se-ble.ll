; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_BLE (16-bit Branch if Less or Equal) instruction selection.
; SE_BLE branches if rA <= 0 (signed): if (rA <= 0) then branch.
; Format: se_ble rA, BD8. BD8 is 8-bit signed displacement.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.4.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_BLE
define i32 @test_se_ble(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_ble
; CHECK: se_ble {{r[0-7]}},
; Branch if less or equal should use SE_BLE
  %cmp = icmp sle i32 %a, 0
  br i1 %cmp, label %if_nonpositive, label %if_positive

if_nonpositive:
  ret i32 -1

if_positive:
  ret i32 %a
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

