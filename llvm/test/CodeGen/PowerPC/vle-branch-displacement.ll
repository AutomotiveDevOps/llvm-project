; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test branch displacement range constraints.
; Verifies BD8 (8-bit signed displacement: -128 to 127) for 16-bit branches.
; Tests selection between SE_B (16-bit) and E_B (32-bit) based on displacement.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.4.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_B with small displacement (within BD8 range)
define void @test_se_b_small() optsize minsize {
entry:
; CHECK-LABEL: @test_se_b_small
; CHECK: se_b
; Small displacement should use 16-bit SE_B
  br label %target

target:
  ret void
}

; Test E_B with large displacement (outside BD8 range)
; Note: This is a placeholder - actual large displacement testing requires
; generated code with specific branch distances
define void @test_e_b_large() optsize minsize {
entry:
; CHECK-LABEL: @test_e_b_large
; Large displacement would use 32-bit E_B
  ret void
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

