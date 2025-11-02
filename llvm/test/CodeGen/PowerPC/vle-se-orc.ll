; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_ORC (16-bit OR with Complement) instruction selection.
; SE_ORC performs: rD = rA | ~rB.
; Format: se_orc rD, rA, rB. Requires all registers in R0-R7 range.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_ORC operation
define i32 @test_se_orc(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_se_orc
; CHECK: se_orc {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; OR with complement should use SE_ORC
  %notb = xor i32 %b, -1
  %result = or i32 %a, %notb
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

