; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_BLRL (16-bit Branch to Link Register and Link) instruction selection.
; SE_BLRL calls function via LR and updates LR: PC = LR; LR = PC+4.
; Format: se_blrl. Used for indirect calls with link.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.4.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_BLRL via indirect call with link
define i32 @test_se_blrl(i32 (i32)* %func, i32 %arg) optsize minsize {
entry:
; CHECK-LABEL: @test_se_blrl
; CHECK: se_blrl
; Indirect call with link should use SE_BLRL
  %result = call i32 %func(i32 %arg)
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

