; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test 32-bit E-form branch instructions (E_B, E_BL).
; These provide extended displacement range compared to 16-bit branches.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.4.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_B unconditional branch (for large displacement)
define void @test_e_b() optsize minsize {
entry:
; CHECK-LABEL: @test_e_b
; CHECK: e_b
; Unconditional branch with large displacement should use E_B
  br label %target

target:
  ret void
}

; Test E_BL branch and link (for function calls)
define i32 @test_e_bl() optsize minsize {
entry:
; CHECK-LABEL: @test_e_bl
; CHECK: e_bl
; Branch and link should use E_BL
  %result = call i32 @helper()
  ret i32 %result
}

declare i32 @helper()

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

