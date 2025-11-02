; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_LWZ (16-bit Load Word and Zero) instruction selection.
; SE_LWZ loads a word from memory.
; Format: se_lwz rD, D5(rA) where D5 is 5-bit unsigned immediate (0-31).
; Requires R0-R7 registers and small displacement (u5imm: 0-31).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.2.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_LWZ with zero displacement
define i32 @test_lwz_zero(i32* %ptr) optsize minsize {
entry:
; CHECK-LABEL: @test_lwz_zero
; CHECK: se_lwz {{r[0-7]}}, 0, {{r[0-7]}}
; Zero displacement should use SE_LWZ
  %val = load i32, i32* %ptr, align 4
  ret i32 %val
}

; Test SE_LWZ with small positive displacement
define i32 @test_lwz_displacement(i32* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_lwz_displacement
; CHECK: se_lwz {{r[0-7]}}, 12, {{r[0-7]}}
; Displacement 12 (within u5imm range 0-31) should use SE_LWZ
  %ptr = getelementptr inbounds i32, i32* %base, i32 3
  %val = load i32, i32* %ptr, align 4
  ret i32 %val
}

; Test SE_LWZ with maximum displacement
define i32 @test_lwz_max_displacement(i32* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_lwz_max_displacement
; CHECK: se_lwz {{r[0-7]}}, 28, {{r[0-7]}}
; Maximum displacement 28 (within u5imm range, word-aligned) should use SE_LWZ
  %ptr = getelementptr inbounds i32, i32* %base, i32 7
  %val = load i32, i32* %ptr, align 4
  ret i32 %val
}

; Test SE_LWZ with maximum u5imm displacement
define i32 @test_lwz_max_u5imm(i32* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_lwz_max_u5imm
; CHECK: se_lwz {{r[0-7]}}, 31, {{r[0-7]}}
; Maximum u5imm displacement 31 should use SE_LWZ
; Note: This requires byte-level addressing, not word-indexed
  %base8 = bitcast i32* %base to i8*
  %ptr8 = getelementptr inbounds i8, i8* %base8, i32 31
  %ptr = bitcast i8* %ptr8 to i32*
  %val = load i32, i32* %ptr, align 1
  ret i32 %val
}

; Test that large displacement falls back to standard instruction
define i32 @test_lwz_large_displacement(i32* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_lwz_large_displacement
; CHECK-NOT: se_lwz
; Displacement 32 (outside u5imm range) should use standard lwz
; NOOPT-LABEL: @test_lwz_large_displacement
; NOOPT: lwz
  %ptr = getelementptr inbounds i32, i32* %base, i32 8
  %val = load i32, i32* %ptr, align 4
  ret i32 %val
}

; Test SE_LWZ with multiple loads
define i32 @test_lwz_multiple(i32* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_lwz_multiple
; CHECK-DAG: se_lwz {{r[0-7]}}, 0, {{r[0-7]}}
; CHECK-DAG: se_lwz {{r[0-7]}}, 16, {{r[0-7]}}
; Multiple word loads within range should use SE_LWZ
  %val1 = load i32, i32* %base, align 4
  %ptr2 = getelementptr inbounds i32, i32* %base, i32 4
  %val2 = load i32, i32* %ptr2, align 4
  %sum = add i32 %val1, %val2
  ret i32 %sum
}

