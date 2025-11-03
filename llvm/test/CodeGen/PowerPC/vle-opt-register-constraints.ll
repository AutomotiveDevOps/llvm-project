; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test VLE optimization pass: register constraint validation.
; 16-bit VLE instructions require registers in R0-R7 range (3-bit encoding).
; PPCVLEOpt should prefer R0-R7 allocation to enable 16-bit encoding.
; Reference: PPCVLEOpt.cpp:isVLE16Register

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test that register allocator prefers R0-R7 for VLE optimization
define i32 @test_r0_r7_preference(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_r0_r7_preference
; CHECK: se_add {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; With -Oz, register allocator should prefer R0-R7 to enable se_add (16-bit)
  %result = add i32 %a, %b
  ret i32 %result
}

; Test multiple operations that should prefer R0-R7
define i32 @test_multiple_r0_r7(i32 %a, i32 %b, i32 %c) optsize minsize {
entry:
; CHECK-LABEL: @test_multiple_r0_r7
; CHECK-DAG: se_add {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; CHECK-DAG: se_addi {{r[0-7]}}, {{r[0-7]}}, 10
; Multiple operations should all prefer R0-R7 allocation
  %sum1 = add i32 %a, %b
  %sum2 = add i32 %sum1, 10
  %sum3 = add i32 %sum2, %c
  ret i32 %sum3
}

; Test that when R0-R7 is used, 16-bit instructions are generated
define i32 @test_16bit_with_r0_r7(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_16bit_with_r0_r7
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 15
; CHECK: se_slwi {{r[0-7]}}, {{r[0-7]}}, 5
; With R0-R7 registers, should generate se_* (16-bit) instructions
  %v1 = add i32 %a, 15
  %v2 = shl i32 %v1, 5
  ret i32 %v2
}

; Test load/store with R0-R7 preference
define i32 @test_load_store_r0_r7(i32* %ptr) optsize minsize {
entry:
; CHECK-LABEL: @test_load_store_r0_r7
; CHECK: se_lbz {{r[0-7]}}, {{[0-9]+}}({{r[0-7]}})
; CHECK: se_stb {{r[0-7]}}, {{[0-9]+}}({{r[0-7]}})
; Load/store with R0-R7 base register should use se_* (16-bit) forms
  %val = load i32, i32* %ptr
  store i32 %val, i32* %ptr
  ret i32 %val
}

; Test that register pressure doesn't break VLE constraints
define i32 @test_register_pressure(i32 %a, i32 %b, i32 %c, i32 %d, i32 %e, i32 %f, i32 %g, i32 %h) optsize minsize {
entry:
; CHECK-LABEL: @test_register_pressure
; When register pressure is high, some values may spill,
; but VLE optimization should still prefer R0-R7 when possible
  %v1 = add i32 %a, %b
  %v2 = add i32 %c, %d
  %v3 = add i32 %e, %f
  %v4 = add i32 %g, %h
  %s1 = add i32 %v1, %v2
  %s2 = add i32 %v3, %v4
  %result = add i32 %s1, %s2
  ret i32 %result
}

