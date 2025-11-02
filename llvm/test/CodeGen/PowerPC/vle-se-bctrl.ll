; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_BCTRL (16-bit Branch to Count Register and Link) instruction selection.
; SE_BCTRL calls function via CTR and updates LR: PC = CTR; LR = PC+4.
; Format: se_bctrl. Used for indirect calls with link via count register.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.4.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_BCTRL via indirect call with link
define i32 @test_se_bctrl(i32 (i32)* %func, i32 %arg) optsize minsize {
entry:
; CHECK-LABEL: @test_se_bctrl
; CHECK: se_bctrl
; Indirect call with link via CTR should use SE_BCTRL
  %result = call i32 %func(i32 %arg)
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

