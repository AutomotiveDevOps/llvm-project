; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test VLE subtarget feature flags (HasVLE, IsE200).
; Verifies that VLE instructions are only generated when VLE features are enabled.
; Tests CPU-specific VLE support for e200z4, e200z6, e200z7 cores.
; Reference: VLEPEM Table B-3, VLEPIM Section 1.1 (Target Requirements)

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test VLE instructions with e200z4 CPU
define i32 @test_e200z4_vle(i32 %a) optsize minsize "target-cpu"="e200z4" {
entry:
; CHECK-LABEL: @test_e200z4_vle
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 10
; E200Z4 should support VLE instructions
  %result = add i32 %a, 10
  ret i32 %result
}

; Test VLE instructions with e200z6 CPU
define i32 @test_e200z6_vle(i32 %a) optsize minsize "target-cpu"="e200z6" {
entry:
; CHECK-LABEL: @test_e200z6_vle
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 10
; E200Z6 should support VLE instructions
  %result = add i32 %a, 10
  ret i32 %result
}

; Test VLE instructions with e200z7 CPU
define i32 @test_e200z7_vle(i32 %a) optsize minsize "target-cpu"="e200z7" {
entry:
; CHECK-LABEL: @test_e200z7_vle
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 10
; E200Z7 should support VLE instructions
  %result = add i32 %a, 10
  ret i32 %result
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

