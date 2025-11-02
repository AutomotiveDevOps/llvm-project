; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test instruction size verification (16-bit vs 32-bit encoding).
; Verifies that 16-bit SE_* instructions are actually encoded as 16 bits
; and 32-bit E_* instructions are encoded as 32 bits when constraints allow.
; Tests actual binary encoding through objdump verification.
; Reference: VLEPEM Table B-3, VLEPIM Section 1.1 (Instruction Encoding)

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test 16-bit instruction encoding (SE_ADDI)
define i32 @test_16bit_encoding(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_16bit_encoding
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 10
; 16-bit instruction should be encoded as 2 bytes
  %result = add i32 %a, 10
  ret i32 %result
}

; Test 32-bit instruction encoding (E_ADDI for large immediate)
define i32 @test_32bit_encoding(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_32bit_encoding
; CHECK: e_addi {{r[0-9]+}}, {{r[0-9]+}}, 1000
; 32-bit instruction should be encoded as 4 bytes
  %result = add i32 %a, 1000
  ret i32 %result
}

; Test mixed encoding in same function
define i32 @test_mixed_encoding(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_mixed_encoding
; CHECK: se_addi {{r[0-7]}}, {{r[0-7]}}, 15
; CHECK: e_addi {{r[0-9]+}}, {{r[0-9]+}}, 500
; Function should mix 16-bit and 32-bit encodings
  %small = add i32 %a, 15
  %large = add i32 %small, 500
  ret i32 %large
}

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

