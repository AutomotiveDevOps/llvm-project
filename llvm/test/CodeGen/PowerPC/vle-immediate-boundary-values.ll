; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test VLE immediate boundary values comprehensively.
; Ensure correct encoding at all boundary conditions without silent truncation.
; Reference: VLEPIM Section 4.3, PPCInstrVLE.td

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test all s6imm boundary values
define i32 @test_all_s6imm_boundaries(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_all_s6imm_boundaries
; Test minimum: -32
  %v1 = add i32 %a, -32
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, -32
; Test -1
  %v2 = add i32 %v1, -1
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, -1
; Test 0
  %v3 = add i32 %v2, 0
; Test 31
  %v4 = add i32 %v3, 31
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 31
; Test -33 (should NOT fit)
  %v5 = add i32 %v4, -33
; CHECK: e_addi {{r[0-9]+}}, {{r[0-9]+}}, -33
  ret i32 %v5
}

; Test all u5imm boundary values
define i32 @test_all_u5imm_boundaries(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_all_u5imm_boundaries
; Test minimum: 0
  %v1 = and i32 %a, 0
; Test 31
  %v2 = and i32 %a, 31
; CHECK: se_andi {{r[0-7]}}, {{r[0-7]}}, 31
; Test 32 (should NOT fit)
  %v3 = and i32 %a, 32
; CHECK: e_andi {{r[0-9]+}}, {{r[0-9]+}}, 32
  ret i32 %v3
}

; Test all u7imm boundary values
define i32 @test_all_u7imm_boundaries(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_all_u7imm_boundaries
; Test minimum: 0
  %v1 = add i32 %a, 0
; Test 127
  %v2 = add i32 %v1, 127
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 127
; Test 128 (should NOT fit)
  %v3 = add i32 %v2, 128
; CHECK: e_addi {{r[0-9]+}}, {{r[0-9]+}}, 128
  ret i32 %v3
}

; Test shift boundary values (u5imm: 0-31)
define i32 @test_shift_boundaries(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_shift_boundaries
; Test 0
  %v1 = shl i32 %a, 0
; Test 31
  %v2 = shl i32 %a, 31
; CHECK: se_slwi {{r[0-7]}}, {{r[0-7]}}, 31
; Test 32 (should NOT fit)
  %v3 = shl i32 %a, 32
; CHECK: e_slwi {{r[0-9]+}}, {{r[0-9]+}}, 32
  ret i32 %v3
}

; Test compare boundary values (s6imm: -32 to 31)
define i32 @test_compare_boundaries(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_compare_boundaries
; Test -32
  %cmp1 = icmp eq i32 %a, -32
  %v1 = select i1 %cmp1, i32 1, i32 0
; Test 31
  %cmp2 = icmp eq i32 %a, 31
  %v2 = select i1 %cmp2, i32 1, i32 0
; Test -33 (should NOT fit in s6imm, may need 32-bit)
  %cmp3 = icmp eq i32 %a, -33
  %v3 = select i1 %cmp3, i32 1, i32 0
  %result = add i32 %v1, %v2
  %result2 = add i32 %result, %v3
  ret i32 %result2
}

