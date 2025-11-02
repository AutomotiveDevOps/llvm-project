; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle < %s | FileCheck %s --check-prefix=NOOPT

; Test that register allocation prefers R0-R7 for VLE-eligible operations
; when optimizing for code size (-Oz). This enables 16-bit VLE instructions
; which require 3-bit register encoding (R0-R7).

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-f128:128:128-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test 1: Simple add with immediate that can use se_addi (16-bit)
; With -Oz, register allocator should prefer R0-R7 to enable 16-bit encoding
define i32 @test_addi_small(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_addi_small
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 10
; Verify that 16-bit se_addi is used (requires R0-R7)
  %result = add i32 %a, 10
  ret i32 %result
}

; Test 2: Register-register add that can use se_add (16-bit) if both registers are R0-R7
define i32 @test_add_regs(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_add_regs
; CHECK: se_add {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; Verify that 16-bit se_add is used when all registers are in R0-R7
  %result = add i32 %a, %b
  ret i32 %result
}

; Test 3: Multiple operations to test register pressure handling
; With proper R0-R7 preference, multiple 16-bit instructions should be generated
define i32 @test_multiple_ops(i32 %a, i32 %b, i32 %c) optsize minsize {
entry:
; CHECK-LABEL: @test_multiple_ops
; CHECK-DAG: se_addi {{r[0-7]}}, {{r[0-7]}}, 5
; CHECK-DAG: se_add {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; CHECK-DAG: se_subi {{r[0-7]}}, {{r[0-7]}}, 3
; Multiple operations should still prefer R0-R7
  %add1 = add i32 %a, 5
  %add2 = add i32 %add1, %b
  %result = sub i32 %add2, 3
  ret i32 %result
}

; Test 4: Without optimization flags, should still work but may not prefer R0-R7 as aggressively
define i32 @test_addi_noopt(i32 %a) {
entry:
; NOOPT-LABEL: @test_addi_noopt
; NOOPT: addi {{r[0-9]+}}, {{r[0-9]+}}, 10
; Without -Oz, may use standard addi or may still use se_addi if lucky
  %result = add i32 %a, 10
  ret i32 %result
}

; Test 5: Store operation that can use se_stw with R0-R7 base register
define void @test_store_r0_r7(i32* %ptr, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_store_r0_r7
; CHECK: se_stw {{r[0-7]}}, 0, {{r[0-7]}}
; Store with R0-R7 base register enables 16-bit se_stw
  store i32 %val, i32* %ptr
  ret void
}

; Test 6: Load operation that can use se_lwz with R0-R7 base register
define i32 @test_load_r0_r7(i32* %ptr) optsize minsize {
entry:
; CHECK-LABEL: @test_load_r0_r7
; CHECK: se_lwz {{r[0-7]}}, 0, {{r[0-7]}}
; Load with R0-R7 base register enables 16-bit se_lwz
  %val = load i32, i32* %ptr
  ret i32 %val
}

