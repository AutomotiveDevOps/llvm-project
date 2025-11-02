; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_ADDE (32-bit Add Extended) instruction selection.
; E_ADDE performs addition with extended carry: rD = rA + rB + CA.
; Format: e_adde rD, rA, rB. This is a 32-bit VLE instruction.
; Used for multi-word addition where carry from previous operation is needed.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_ADDE pattern
; Extended addition for multi-word arithmetic
define i32 @test_e_adde(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_e_adde
; CHECK: e_adde {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; Extended add should use E_ADDE for multi-word operations
  %result = add i32 %a, %b
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

