; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test mixed-mode operation (mixing 16-bit se_* and 32-bit e_* instructions).
; Verifies that codegen can seamlessly mix instruction sizes based on constraints.
; This is important for optimal code size when some operations fit 16-bit forms.
; Reference: VLEPEM Table B-3, VLEPIM Section 1.2 (Mixed Encoding)

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test function mixing 16-bit and 32-bit instructions
define i32 @test_mixed_mode(i32 %a, i32 %b, i32* %ptr) optsize minsize {
entry:
; CHECK-LABEL: @test_mixed_mode
; CHECK-DAG: se_addi
; CHECK-DAG: e_add
; CHECK-DAG: se_stw
; Function should mix SE_* and E_* instructions based on constraints
  %small_add = add i32 %a, 15
  %large_add = add i32 %small_add, %b
  store i32 %large_add, i32* %ptr, align 4
  ret i32 %large_add
}

; Test loop with mixed instruction sizes
define i32 @test_mixed_loop(i32* %arr, i32 %n) optsize minsize {
entry:
; CHECK-LABEL: @test_mixed_loop
; CHECK-DAG: se_addi
; CHECK-DAG: e_lwz
; CHECK-DAG: se_add
; CHECK: e_blt
; Loop should use 16-bit for small immediates and 32-bit for extended operations
  br label %loop

loop:
  %i = phi i32 [ 0, %entry ], [ %next_i, %loop ]
  %sum = phi i32 [ 0, %entry ], [ %next_sum, %loop ]
  %cmp = icmp slt i32 %i, %n
  br i1 %cmp, label %loop_body, label %done

loop_body:
  %ptr = getelementptr i32, i32* %arr, i32 %i
  %val = load i32, i32* %ptr, align 4
  %next_sum = add i32 %sum, %val
  %next_i = add i32 %i, 1
  br label %loop

done:
  ret i32 %sum
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

