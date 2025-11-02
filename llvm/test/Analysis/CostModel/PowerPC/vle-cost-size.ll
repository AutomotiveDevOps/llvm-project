; RUN: opt < %s -cost-model -cost-kind=code-size -analyze -mtriple=powerpc-none-eabivle | FileCheck %s --check-prefix=VLE
; RUN: opt < %s -cost-model -cost-kind=code-size -analyze -mtriple=powerpc-none-unknown | FileCheck %s --check-prefix=NOVLE
target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-f128:128:128-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test VLE cost model for code size optimization.
; With VLE enabled, instructions that can use VLE forms should have lower cost
; when optimizing for code size.

define i32 @test_add_small_imm(i32 %a) {
entry:
  ; VLE: Cost Model: Found an estimated cost of {{[2-3]}} for instruction: %r = add i32 %a, i32 10
  ; NOVLE: Cost Model: Found an estimated cost of 4 for instruction: %r = add i32 %a, i32 10
  ; Small immediate (10) fits in s6imm (-32 to 31), can use 16-bit VLE se_addi
  %r = add i32 %a, i32 10
  ret i32 %r
}

define i32 @test_add_negative_imm(i32 %a) {
entry:
  ; VLE: Cost Model: Found an estimated cost of {{[2-3]}} for instruction: %r = add i32 %a, i32 -20
  ; NOVLE: Cost Model: Found an estimated cost of 4 for instruction: %r = add i32 %a, i32 -20
  ; Negative immediate (-20) fits in s6imm, can use 16-bit VLE
  %r = add i32 %a, i32 -20
  ret i32 %r
}

define i32 @test_add_large_imm(i32 %a) {
entry:
  ; VLE: Cost Model: Found an estimated cost of 4 for instruction: %r = add i32 %a, i32 1000
  ; NOVLE: Cost Model: Found an estimated cost of 4 for instruction: %r = add i32 %a, i32 1000
  ; Large immediate (1000) doesn't fit VLE ranges, standard PowerPC needed
  %r = add i32 %a, i32 1000
  ret i32 %r
}

define i32 @test_sub_small_imm(i32 %a) {
entry:
  ; VLE: Cost Model: Found an estimated cost of {{[2-3]}} for instruction: %r = sub i32 %a, i32 5
  ; NOVLE: Cost Model: Found an estimated cost of 4 for instruction: %r = sub i32 %a, i32 5
  ; Small immediate fits VLE constraints
  %r = sub i32 %a, i32 5
  ret i32 %r
}

define i32 @test_and_small_imm(i32 %a) {
entry:
  ; VLE: Cost Model: Found an estimated cost of {{[2-3]}} for instruction: %r = and i32 %a, i32 31
  ; NOVLE: Cost Model: Found an estimated cost of 4 for instruction: %r = and i32 %a, i32 31
  ; u5imm (0-31) can use 16-bit VLE se_andi
  %r = and i32 %a, i32 31
  ret i32 %r
}

define i32 @test_or_small_imm(i32 %a) {
entry:
  ; VLE: Cost Model: Found an estimated cost of {{[2-3]}} for instruction: %r = or i32 %a, i32 15
  ; NOVLE: Cost Model: Found an estimated cost of 4 for instruction: %r = or i32 %a, i32 15
  ; u5imm can use 16-bit VLE se_ori
  %r = or i32 %a, i32 15
  ret i32 %r
}

define i32 @test_xor_small_imm(i32 %a) {
entry:
  ; VLE: Cost Model: Found an estimated cost of {{[2-3]}} for instruction: %r = xor i32 %a, i32 7
  ; NOVLE: Cost Model: Found an estimated cost of 4 for instruction: %r = xor i32 %a, i32 7
  ; u5imm can use 16-bit VLE se_xori
  %r = xor i32 %a, i32 7
  ret i32 %r
}

define i1 @test_icmp_zero(i32 %a) {
entry:
  ; VLE: Cost Model: Found an estimated cost of {{[2-3]}} for instruction: %r = icmp eq i32 %a, i32 0
  ; NOVLE: Cost Model: Found an estimated cost of 4 for instruction: %r = icmp eq i32 %a, i32 0
  ; Zero comparison can use record-form VLE instructions
  %r = icmp eq i32 %a, i32 0
  ret i1 %r
}

define i1 @test_icmp_small_imm(i32 %a) {
entry:
  ; VLE: Cost Model: Found an estimated cost of {{[2-3]}} for instruction: %r = icmp slt i32 %a, i32 10
  ; NOVLE: Cost Model: Found an estimated cost of 4 for instruction: %r = icmp slt i32 %a, i32 10
  ; Small immediate comparison can use VLE
  %r = icmp slt i32 %a, i32 10
  ret i1 %r
}

define i32 @test_shl_small_imm(i32 %a) {
entry:
  ; VLE: Cost Model: Found an estimated cost of {{[2-3]}} for instruction: %r = shl i32 %a, i32 3
  ; NOVLE: Cost Model: Found an estimated cost of 4 for instruction: %r = shl i32 %a, i32 3
  ; Shift with small immediate can use VLE
  %r = shl i32 %a, i32 3
  ret i32 %r
}

define i32 @test_load(i32* %ptr) {
entry:
  ; VLE: Cost Model: Found an estimated cost of {{[2-4]}} for instruction: %r = load i32, i32* %ptr
  ; NOVLE: Cost Model: Found an estimated cost of 4 for instruction: %r = load i32, i32* %ptr
  ; Load can use VLE forms depending on register constraints
  %r = load i32, i32* %ptr
  ret i32 %r
}

define void @test_store(i32* %ptr, i32 %val) {
entry:
  ; VLE: Cost Model: Found an estimated cost of {{[2-4]}} for instruction: store i32 %val, i32* %ptr
  ; NOVLE: Cost Model: Found an estimated cost of 4 for instruction: store i32 %val, i32* %ptr
  ; Store can use VLE forms depending on register constraints
  store i32 %val, i32* %ptr
  ret void
}

define i32 @test_add_reg(i32 %a, i32 %b) {
entry:
  ; VLE: Cost Model: Found an estimated cost of {{[2-4]}} for instruction: %r = add i32 %a, i32 %b
  ; NOVLE: Cost Model: Found an estimated cost of 4 for instruction: %r = add i32 %a, i32 %b
  ; Register-register add can use VLE if registers are R0-R7
  %r = add i32 %a, i32 %b
  ret i32 %r
}

define i32 @test_mul(i32 %a, i32 %b) {
entry:
  ; VLE: Cost Model: Found an estimated cost of 4 for instruction: %r = mul i32 %a, i32 %b
  ; NOVLE: Cost Model: Found an estimated cost of 4 for instruction: %r = mul i32 %a, i32 %b
  ; Mul doesn't have simple VLE equivalent, standard cost
  %r = mul i32 %a, i32 %b
  ret i32 %r
}

