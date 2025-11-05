; Simple test file for quick VLE cost model testing
; Usage: opt < this_file.ll -cost-model -cost-kind=code-size -analyze -mtriple=powerpc-none-eabivle
target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-f128:128:128-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test case 1: Small immediate that fits s6imm (-32 to 31)
; Expected cost with VLE: 2 bytes (16-bit se_addi)
; Expected cost without VLE: 4 bytes
define i32 @test_small_imm(i32 %a) {
  %r = add i32 %a, i32 10
  ret i32 %r
}

; Test case 2: Negative immediate in s6imm range
; Expected cost with VLE: 2 bytes
define i32 @test_neg_imm(i32 %a) {
  %r = add i32 %a, i32 -20
  ret i32 %r
}

; Test case 3: Large immediate outside VLE range
; Expected cost: 4 bytes (standard PowerPC)
define i32 @test_large_imm(i32 %a) {
  %r = add i32 %a, i32 1000
  ret i32 %r
}

; Test case 4: AND with u5imm (0-31)
; Expected cost with VLE: 2 bytes (16-bit se_andi)
define i32 @test_and_imm(i32 %a) {
  %r = and i32 %a, i32 31
  ret i32 %r
}

; Test case 5: Zero comparison (record-form VLE)
; Expected cost with VLE: 2-3 bytes
define i1 @test_zero_cmp(i32 %a) {
  %r = icmp eq i32 %a, i32 0
  ret i1 %r
}

; Test case 6: Register-register operation
; Expected cost: heuristic (2-4 bytes, typically 3)
; Actual depends on register allocation (R0-R7 for 16-bit VLE)
define i32 @test_reg_reg(i32 %a, i32 %b) {
  %r = add i32 %a, i32 %b
  ret i32 %r
}

