; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z6 -mvle -Oz < %s | FileCheck %s

; ISO 26262 Edge Case 004: VLE Register Constraint Violation (R0-R7 Requirement)
; Test that 16-bit VLE instructions (SE_*) only use registers R0-R7
; Reference: PPCInstrVLE.td:56-66, PPCRegisterInfo.td

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test 1: se_addi with immediate in range should use R0-R7
define i32 @test_se_addi_r0_r7(i32 %a) optsize minsize {
; CHECK-LABEL: test_se_addi_r0_r7:
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 10
; Verify that se_addi uses R0-R7 registers only
entry:
  %result = add i32 %a, 10
  ret i32 %result
}

; Test 2: se_add (register-register) should use R0-R7 for all operands
define i32 @test_se_add_all_r0_r7(i32 %a, i32 %b) optsize minsize {
; CHECK-LABEL: test_se_add_all_r0_r7:
; CHECK: se_add {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; All three registers should be in R0-R7 range
entry:
  %result = add i32 %a, %b
  ret i32 %result
}

; Test 3: Multiple operations should still prefer R0-R7 when possible
define i32 @test_multiple_se_ops(i32 %a, i32 %b) optsize minsize {
; CHECK-LABEL: test_multiple_se_ops:
; CHECK-DAG: se_addi {{r[0-7]}}, {{r[0-7]}}, 5
; CHECK-DAG: se_add {{r[0-7]}}, {{r[0-7]}}, {{r[0-7]}}
; CHECK-DAG: se_subi {{r[0-7]}}, {{r[0-7]}}, 3
; Multiple operations should still use R0-R7
entry:
  %add1 = add i32 %a, 5
  %add2 = add i32 %add1, %b
  %result = sub i32 %add2, 3
  ret i32 %result
}

; Test 4: se_lwz should use R0-R7 for destination and base register
define i32 @test_se_lwz_r0_r7(i32* %ptr) optsize minsize {
; CHECK-LABEL: test_se_lwz_r0_r7:
; CHECK: se_lwz {{r[0-7]}}, 0({{r[0-7]}})
; Both destination and base register should be R0-R7
entry:
  %val = load i32, i32* %ptr
  ret i32 %val
}

; Test 5: se_stw should use R0-R7 for source and base register
define void @test_se_stw_r0_r7(i32* %ptr, i32 %val) optsize minsize {
; CHECK-LABEL: test_se_stw_r0_r7:
; CHECK: se_stw {{r[0-7]}}, 0({{r[0-7]}})
; Both source and base register should be R0-R7
entry:
  store i32 %val, i32* %ptr
  ret void
}

; Test 6: When R8-R31 must be used, should NOT use 16-bit VLE instructions
; (This tests the constraint - if register allocator assigns R8-R31, se_* should not be selected)
define i32 @test_reg_pressure(i32 %a, i32 %b, i32 %c, i32 %d, i32 %e, i32 %f, i32 %g, i32 %h, i32 %i, i32 %j) optsize minsize {
; CHECK-LABEL: test_reg_pressure:
; When register pressure forces use of R8-R31, verify se_* instructions are not used inappropriately
; CHECK-NOT: se_add {{r[8-9]|r1[0-9]|r2[0-9]|r3[0-1]}}, {{r[8-9]|r1[0-9]|r2[0-9]|r3[0-1]}}, {{r[8-9]|r1[0-9]|r2[0-9]|r3[0-1]}}
entry:
  %sum1 = add i32 %a, %b
  %sum2 = add i32 %sum1, %c
  %sum3 = add i32 %sum2, %d
  %sum4 = add i32 %sum3, %e
  %sum5 = add i32 %sum4, %f
  %sum6 = add i32 %sum5, %g
  %sum7 = add i32 %sum6, %h
  %sum8 = add i32 %sum7, %i
  %result = add i32 %sum8, %j
  ret i32 %result
}

; Test 7: se_cmpi should use R0-R7
define i1 @test_se_cmpi_r0_r7(i32 %a) optsize minsize {
; CHECK-LABEL: test_se_cmpi_r0_r7:
; CHECK: se_cmpi {{r[0-7]}}, 42
entry:
  %cmp = icmp eq i32 %a, 42
  ret i1 %cmp
}

