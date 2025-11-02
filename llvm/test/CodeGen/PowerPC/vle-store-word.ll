; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_STW (16-bit Store Word) instruction selection.
; SE_STW stores a word to memory.
; Format: se_stw rS, D5(rA) where D5 is 5-bit unsigned immediate (0-31).
; Requires R0-R7 registers and small displacement (u5imm: 0-31).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.2.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_STW with zero displacement
define void @test_stw_zero(i32* %ptr, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_stw_zero
; CHECK: se_stw {{r[0-7]}}, 0, {{r[0-7]}}
; Zero displacement should use SE_STW
  store i32 %val, i32* %ptr, align 4
  ret void
}

; Test SE_STW with small positive displacement
define void @test_stw_displacement(i32* %base, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_stw_displacement
; CHECK: se_stw {{r[0-7]}}, 20, {{r[0-7]}}
; Displacement 20 (within u5imm range 0-31) should use SE_STW
  %ptr = getelementptr inbounds i32, i32* %base, i32 5
  store i32 %val, i32* %ptr, align 4
  ret void
}

; Test SE_STW with maximum displacement
define void @test_stw_max_displacement(i32* %base, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_stw_max_displacement
; CHECK: se_stw {{r[0-7]}}, 28, {{r[0-7]}}
; Maximum displacement 28 (within u5imm range, word-aligned) should use SE_STW
  %ptr = getelementptr inbounds i32, i32* %base, i32 7
  store i32 %val, i32* %ptr, align 4
  ret void
}

; Test SE_STW with maximum u5imm displacement
define void @test_stw_max_u5imm(i32* %base, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_stw_max_u5imm
; CHECK: se_stw {{r[0-7]}}, 31, {{r[0-7]}}
; Maximum u5imm displacement 31 should use SE_STW
; Note: This requires byte-level addressing, not word-indexed
  %base8 = bitcast i32* %base to i8*
  %ptr8 = getelementptr inbounds i8, i8* %base8, i32 31
  %ptr = bitcast i8* %ptr8 to i32*
  store i32 %val, i32* %ptr, align 1
  ret void
}

; Test that large displacement falls back to standard instruction
define void @test_stw_large_displacement(i32* %base, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_stw_large_displacement
; CHECK-NOT: se_stw
; Displacement 32 (outside u5imm range) should use standard stw
; NOOPT-LABEL: @test_stw_large_displacement
; NOOPT: stw
  %ptr = getelementptr inbounds i32, i32* %base, i32 8
  store i32 %val, i32* %ptr, align 4
  ret void
}

; Test SE_STW with multiple stores
define void @test_stw_multiple(i32* %base, i32 %val1, i32 %val2) optsize minsize {
entry:
; CHECK-LABEL: @test_stw_multiple
; CHECK-DAG: se_stw {{r[0-7]}}, 0, {{r[0-7]}}
; CHECK-DAG: se_stw {{r[0-7]}}, 24, {{r[0-7]}}
; Multiple word stores within range should use SE_STW
  store i32 %val1, i32* %base, align 4
  %ptr2 = getelementptr inbounds i32, i32* %base, i32 6
  store i32 %val2, i32* %ptr2, align 4
  ret void
}

