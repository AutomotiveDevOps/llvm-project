; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test displacement range constraints for VLE store instructions.
; SE_STB/SE_STH use u4imm (0-15), SE_STW uses u5imm (0-31).
; Large displacements should use 32-bit E_* forms or standard PowerPC instructions.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.2.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test byte store displacement boundaries
define void @test_stb_boundary_u4imm(i8* %base, i32 %val1, i32 %val2) optsize minsize {
entry:
; CHECK-LABEL: @test_stb_boundary_u4imm
; Displacement 15 (max u4imm) should use SE_STB
  %ptr1 = getelementptr inbounds i8, i8* %base, i32 15
  %trunc1 = trunc i32 %val1 to i8
  store i8 %trunc1, i8* %ptr1, align 1
; CHECK: se_stb {{r[0-7]}}, 15, {{r[0-7]}}
; Displacement 16 (outside u4imm) should use E_STB or standard stb
  %ptr2 = getelementptr inbounds i8, i8* %base, i32 16
  %trunc2 = trunc i32 %val2 to i8
  store i8 %trunc2, i8* %ptr2, align 1
; CHECK-NOT: se_stb {{r[0-7]}}, 16
  ret void
}

; Test halfword store displacement boundaries
define void @test_sth_boundary_u4imm(i16* %base, i32 %val1, i32 %val2) optsize minsize {
entry:
; CHECK-LABEL: @test_sth_boundary_u4imm
; Displacement 14 (max valid u4imm for halfword, must be even) should use SE_STH
  %ptr1 = getelementptr inbounds i16, i16* %base, i32 7
  %trunc1 = trunc i32 %val1 to i16
  store i16 %trunc1, i16* %ptr1, align 2
; CHECK: se_sth {{r[0-7]}}, 14, {{r[0-7]}}
; Displacement 16 (outside u4imm) should use E_STH or standard sth
  %ptr2 = getelementptr inbounds i16, i16* %base, i32 8
  %trunc2 = trunc i32 %val2 to i16
  store i16 %trunc2, i16* %ptr2, align 2
; CHECK-NOT: se_sth {{r[0-7]}}, 16
  ret void
}

; Test word store displacement boundaries
define void @test_stw_boundary_u5imm(i32* %base, i32 %val1, i32 %val2) optsize minsize {
entry:
; CHECK-LABEL: @test_stw_boundary_u5imm
; Displacement 31 (max u5imm) should use SE_STW
  %base8 = bitcast i32* %base to i8*
  %ptr1 = getelementptr inbounds i8, i8* %base8, i32 31
  %ptr1_32 = bitcast i8* %ptr1 to i32*
  store i32 %val1, i32* %ptr1_32, align 1
; CHECK: se_stw {{r[0-7]}}, 31, {{r[0-7]}}
; Displacement 32 (outside u5imm) should use E_STW or standard stw
  %ptr2 = getelementptr inbounds i32, i32* %base, i32 8
  store i32 %val2, i32* %ptr2, align 4
; CHECK-NOT: se_stw {{r[0-7]}}, 32
  ret void
}

