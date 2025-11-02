; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test displacement range constraints for VLE load instructions.
; SE_LBZ/SE_LHZ use u4imm (0-15), SE_LWZ uses u5imm (0-31).
; Large displacements should use 32-bit E_* forms or standard PowerPC instructions.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.2.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test byte load displacement boundaries
define i32 @test_lbz_boundary_u4imm(i8* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_lbz_boundary_u4imm
; Displacement 15 (max u4imm) should use SE_LBZ
  %ptr1 = getelementptr inbounds i8, i8* %base, i32 15
  %val1 = load i8, i8* %ptr1, align 1
; CHECK: se_lbz {{r[0-7]}}, 15, {{r[0-7]}}
; Displacement 16 (outside u4imm) should use E_LBZ or standard lbz
  %ptr2 = getelementptr inbounds i8, i8* %base, i32 16
  %val2 = load i8, i8* %ptr2, align 1
; CHECK-NOT: se_lbz {{r[0-7]}}, 16
  %ext1 = zext i8 %val1 to i32
  %ext2 = zext i8 %val2 to i32
  %sum = add i32 %ext1, %ext2
  ret i32 %sum
}

; Test halfword load displacement boundaries
define i32 @test_lhz_boundary_u4imm(i16* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_lhz_boundary_u4imm
; Displacement 14 (max valid u4imm for halfword, must be even) should use SE_LHZ
  %ptr1 = getelementptr inbounds i16, i16* %base, i32 7
  %val1 = load i16, i16* %ptr1, align 2
; CHECK: se_lhz {{r[0-7]}}, 14, {{r[0-7]}}
; Displacement 16 (outside u4imm) should use E_LHZ or standard lhz
  %ptr2 = getelementptr inbounds i16, i16* %base, i32 8
  %val2 = load i16, i16* %ptr2, align 2
; CHECK-NOT: se_lhz {{r[0-7]}}, 16
  %ext1 = zext i16 %val1 to i32
  %ext2 = zext i16 %val2 to i32
  %sum = add i32 %ext1, %ext2
  ret i32 %sum
}

; Test word load displacement boundaries
define i32 @test_lwz_boundary_u5imm(i32* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_lwz_boundary_u5imm
; Displacement 31 (max u5imm) should use SE_LWZ
  %base8 = bitcast i32* %base to i8*
  %ptr1 = getelementptr inbounds i8, i8* %base8, i32 31
  %ptr1_32 = bitcast i8* %ptr1 to i32*
  %val1 = load i32, i32* %ptr1_32, align 1
; CHECK: se_lwz {{r[0-7]}}, 31, {{r[0-7]}}
; Displacement 32 (outside u5imm) should use E_LWZ or standard lwz
  %ptr2 = getelementptr inbounds i32, i32* %base, i32 8
  %val2 = load i32, i32* %ptr2, align 4
; CHECK-NOT: se_lwz {{r[0-7]}}, 32
  %sum = add i32 %val1, %val2
  ret i32 %sum
}

