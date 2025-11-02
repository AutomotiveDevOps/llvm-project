; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test arithmetic overflow handling.
; Tests instructions that handle overflow conditions and extended arithmetic.
; VLE instructions handle overflow through condition codes and extended operations.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.3.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test addition with potential overflow detection
; Extended operations (E_ADDC, E_ADDE) preserve overflow information
define i32 @test_add_overflow(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_add_overflow
; CHECK: e_add {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; Standard addition - overflow sets condition codes
  %result = add i32 %a, %b
  ret i32 %result
}

; Test extended addition for 64-bit (uses carry propagation)
define i64 @test_add_64bit(i64 %a, i64 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_add_64bit
; CHECK-DAG: e_addc
; CHECK-DAG: e_adde
; 64-bit addition uses extended operations for carry
  %result = add i64 %a, %b
  ret i64 %result
}

; Test subtraction with borrow
define i64 @test_sub_64bit(i64 %a, i64 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_sub_64bit
; CHECK-DAG: e_subfc
; CHECK-DAG: e_subfe
; 64-bit subtraction uses extended operations for borrow
  %result = sub i64 %a, %b
  ret i64 %result
}

; Test multiplication that may overflow
; Multiply high instructions (E_MULHW, E_MULHWU) capture overflow
define i32 @test_mul_overflow(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_mul_overflow
; CHECK: e_mullw {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; Multiplication result may overflow 32 bits
  %result = mul i32 %a, %b
  ret i32 %result
}

; Test multiply high for overflow detection
define i32 @test_mul_high(i32 %a, i32 %b) optsize minsize {
entry:
; CHECK-LABEL: @test_mul_high
; CHECK: e_mulhw {{r[0-9]+}}, {{r[0-9]+}}, {{r[0-9]+}}
; High word of multiplication captures overflow
  %result = call i32 @llvm.ppc.mulhw.i32(i32 %a, i32 %b)
  ret i32 %result
}

declare i32 @llvm.ppc.mulhw.i32(i32, i32)

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

