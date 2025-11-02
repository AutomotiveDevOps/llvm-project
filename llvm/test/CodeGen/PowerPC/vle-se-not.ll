; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_NOT (16-bit NOT) instruction selection.
; SE_NOT performs bitwise complement: rD = ~rA.
; Format: se_not rD, rA. Requires all registers in R0-R7 range.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_NOT basic operation
define i32 @test_se_not(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_se_not
; CHECK: se_not {{r[0-7]}}, {{r[0-7]}}
; NOT operation with R0-R7 should use SE_NOT
  %result = xor i32 %a, -1
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

