; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test VLE register boundary constraints (R0-R7 vs R8-R31).
; 16-bit VLE instructions require registers in R0-R7 range (3-bit encoding).
; Verify correct instruction selection based on register allocation.
; Reference: PPCVLEOpt.cpp:isVLE16Register, VLEPIM Section 4.3

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test that R0-R7 usage enables 16-bit instructions
define i32 @test_r0_r7_enables_16bit(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_r0_r7_enables_16bit
; CHECK: se_add {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; With R0-R7 registers, should use se_add (16-bit)
  %result = add i32 %a, %b
  ret i32 %result
}

; Test that immediate fits but register doesn't - should still attempt optimization
define i32 @test_register_constraint_priority(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_register_constraint_priority
; With -Oz, register allocator should prefer R0-R7 for se_addi
  %result = add i32 %a, 15
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 15
  ret i32 %result
}

; Test load with R0-R7 base register
define i32 @test_load_r0_r7_base(i32* %ptr) optsize minsize {
entry:
; CHECK-LABEL: @test_load_r0_r7_base
; CHECK: se_lwz {{r[0-7]}}, 0({{r[0-7]}})
; Load with R0-R7 base register should use se_lwz (16-bit)
  %val = load i32, i32* %ptr
  ret i32 %val
}

; Test store with R0-R7 base register
define void @test_store_r0_r7_base(i32* %ptr, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_store_r0_r7_base
; CHECK: se_stw {{r[0-7]}}, 0({{r[0-7]}})
; Store with R0-R7 base register should use se_stw (16-bit)
  store i32 %val, i32* %ptr
  ret void
}

; Test that high register pressure may force R8+ usage
define i32 @test_high_register_pressure(i32 %a, i32 %b, i32 %c, i32 %d, i32 %e, i32 %f, i32 %g, i32 %h, i32 %i, i32 %j) optsize minsize {
entry:
; CHECK-LABEL: @test_high_register_pressure
; With many live values, some may need R8+
; This may affect whether se_* or e_* instructions are used
  %v1 = add i32 %a, %b
  %v2 = add i32 %c, %d
  %v3 = add i32 %e, %f
  %v4 = add i32 %g, %h
  %v5 = add i32 %i, %j
  %s1 = add i32 %v1, %v2
  %s2 = add i32 %v3, %v4
  %s3 = add i32 %s1, %s2
  %result = add i32 %s3, %v5
  ret i32 %result
}

; Test register spilling doesn't break VLE constraints
define i32 @test_spilling_doesnt_break(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_spilling_doesnt_break
; Even with spilling, R0-R7 should be preferred for VLE instructions
  %v1 = add i32 %a, 1
  %v2 = add i32 %v1, 2
  %v3 = add i32 %v2, 3
  %v4 = add i32 %v3, 4
  %v5 = add i32 %v4, 5
  %v6 = add i32 %v5, 6
  %v7 = add i32 %v6, 7
  %v8 = add i32 %v7, 8
  %v9 = add i32 %v8, 9
  %result = add i32 %v9, 10
  ret i32 %result
}

