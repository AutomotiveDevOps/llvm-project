; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_LBZ (16-bit Load Byte and Zero) instruction selection.
; SE_LBZ loads a byte from memory, zero-extends to 32 bits.
; Format: se_lbz rD, D4(rA) where D4 is 4-bit unsigned immediate (0-15).
; Requires R0-R7 registers and small displacement (u4imm: 0-15).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.2.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_LBZ with zero displacement
define i32 @test_lbz_zero(i8* %ptr) optsize minsize {
entry:
; CHECK-LABEL: @test_lbz_zero
; CHECK: se_lbz {{r[0-7]}}, 0, {{r[0-7]}}
; Zero displacement should use SE_LBZ
  %val = load i8, i8* %ptr, align 1
  %ext = zext i8 %val to i32
  ret i32 %ext
}

; Test SE_LBZ with small positive displacement
define i32 @test_lbz_displacement(i8* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_lbz_displacement
; CHECK: se_lbz {{r[0-7]}}, 10, {{r[0-7]}}
; Displacement 10 (within u4imm range 0-15) should use SE_LBZ
  %ptr = getelementptr inbounds i8, i8* %base, i32 10
  %val = load i8, i8* %ptr, align 1
  %ext = zext i8 %val to i32
  ret i32 %ext
}

; Test SE_LBZ with maximum displacement
define i32 @test_lbz_max_displacement(i8* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_lbz_max_displacement
; CHECK: se_lbz {{r[0-7]}}, 15, {{r[0-7]}}
; Maximum displacement 15 (within u4imm range) should use SE_LBZ
  %ptr = getelementptr inbounds i8, i8* %base, i32 15
  %val = load i8, i8* %ptr, align 1
  %ext = zext i8 %val to i32
  ret i32 %ext
}

; Test that large displacement falls back to standard instruction
define i32 @test_lbz_large_displacement(i8* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_lbz_large_displacement
; CHECK-NOT: se_lbz
; Displacement 16 (outside u4imm range) should use standard lbz
; NOOPT-LABEL: @test_lbz_large_displacement
; NOOPT: lbz
  %ptr = getelementptr inbounds i8, i8* %base, i32 16
  %val = load i8, i8* %ptr, align 1
  %ext = zext i8 %val to i32
  ret i32 %ext
}

; Test SE_LBZ with multiple loads
define i32 @test_lbz_multiple(i8* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_lbz_multiple
; CHECK-DAG: se_lbz {{r[0-7]}}, 0, {{r[0-7]}}
; CHECK-DAG: se_lbz {{r[0-7]}}, 5, {{r[0-7]}}
; Multiple byte loads within range should use SE_LBZ
  %val1 = load i8, i8* %base, align 1
  %ptr2 = getelementptr inbounds i8, i8* %base, i32 5
  %val2 = load i8, i8* %ptr2, align 1
  %sum = add i32 0, %val1
  %sum2 = add i32 %sum, %val2
  ret i32 %sum2
}

