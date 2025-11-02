; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_LHZ (16-bit Load Halfword and Zero) instruction selection.
; SE_LHZ loads a halfword from memory, zero-extends to 32 bits.
; Format: se_lhz rD, D4(rA) where D4 is 4-bit unsigned immediate (0-15).
; Requires R0-R7 registers and small displacement (u4imm: 0-15).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.2.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_LHZ with zero displacement
define i32 @test_lhz_zero(i16* %ptr) optsize minsize {
entry:
; CHECK-LABEL: @test_lhz_zero
; CHECK: se_lhz {{r[0-7]}}, 0, {{r[0-7]}}
; Zero displacement should use SE_LHZ
  %val = load i16, i16* %ptr, align 2
  %ext = zext i16 %val to i32
  ret i32 %ext
}

; Test SE_LHZ with small positive displacement
define i32 @test_lhz_displacement(i16* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_lhz_displacement
; CHECK: se_lhz {{r[0-7]}}, 6, {{r[0-7]}}
; Displacement 6 (within u4imm range 0-15) should use SE_LHZ
; Note: displacement is in bytes, but must be even for halfword alignment
  %ptr = getelementptr inbounds i16, i16* %base, i32 3
  %val = load i16, i16* %ptr, align 2
  %ext = zext i16 %val to i32
  ret i32 %ext
}

; Test SE_LHZ with maximum displacement
define i32 @test_lhz_max_displacement(i16* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_lhz_max_displacement
; CHECK: se_lhz {{r[0-7]}}, 14, {{r[0-7]}}
; Maximum valid displacement 14 (within u4imm range, even-aligned) should use SE_LHZ
  %ptr = getelementptr inbounds i16, i16* %base, i32 7
  %val = load i16, i16* %ptr, align 2
  %ext = zext i16 %val to i32
  ret i32 %ext
}

; Test that large displacement falls back to standard instruction
define i32 @test_lhz_large_displacement(i16* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_lhz_large_displacement
; CHECK-NOT: se_lhz
; Displacement 16 (outside u4imm range) should use standard lhz
; NOOPT-LABEL: @test_lhz_large_displacement
; NOOPT: lhz
  %ptr = getelementptr inbounds i16, i16* %base, i32 8
  %val = load i16, i16* %ptr, align 2
  %ext = zext i16 %val to i32
  ret i32 %ext
}

; Test SE_LHZ with multiple loads
define i32 @test_lhz_multiple(i16* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_lhz_multiple
; CHECK-DAG: se_lhz {{r[0-7]}}, 0, {{r[0-7]}}
; CHECK-DAG: se_lhz {{r[0-7]}}, 4, {{r[0-7]}}
; Multiple halfword loads within range should use SE_LHZ
  %val1 = load i16, i16* %base, align 2
  %ptr2 = getelementptr inbounds i16, i16* %base, i32 2
  %val2 = load i16, i16* %ptr2, align 2
  %ext1 = zext i16 %val1 to i32
  %ext2 = zext i16 %val2 to i32
  %sum = add i32 %ext1, %ext2
  ret i32 %sum
}

