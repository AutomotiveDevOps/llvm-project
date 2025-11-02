; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test VLE pattern prioritization over standard PowerPC patterns.
; Verifies that VLE instructions (se_*, e_*) are selected when available
; instead of standard PowerPC instructions (add, addi, etc.).
; Tests that VLE patterns have higher priority in instruction selection.
; Reference: VLEPEM Table B-3, VLEPIM Section 1.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test VLE pattern preferred over standard addi
define i32 @test_pattern_priority(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_pattern_priority
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 15
; CHECK-NOT: addi
; VLE pattern should be selected, not standard PowerPC addi
  %result = add i32 %a, 15
  ret i32 %result
}

; Test VLE pattern preferred for load
define i32 @test_load_priority(i32* %ptr) optsize minsize {
entry:
; CHECK-LABEL: @test_load_priority
; CHECK: se_lwz {{r[0-7]}}, 0, {{r[0-7]}}
; CHECK-NOT: lwz
; VLE load pattern should be selected
  %val = load i32, i32* %ptr, align 4
  ret i32 %val
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

