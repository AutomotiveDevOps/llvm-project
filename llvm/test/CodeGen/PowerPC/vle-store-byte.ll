; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_STB (16-bit Store Byte) instruction selection.
; SE_STB stores the low 8 bits of a register to memory.
; Format: se_stb rS, D4(rA) where D4 is 4-bit unsigned immediate (0-15).
; Requires R0-R7 registers and small displacement (u4imm: 0-15).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.2.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_STB with zero displacement
define void @test_stb_zero(i8* %ptr, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_stb_zero
; CHECK: se_stb {{r[0-7]}}, 0, {{r[0-7]}}
; Zero displacement should use SE_STB
  %trunc = trunc i32 %val to i8
  store i8 %trunc, i8* %ptr, align 1
  ret void
}

; Test SE_STB with small positive displacement
define void @test_stb_displacement(i8* %base, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_stb_displacement
; CHECK: se_stb {{r[0-7]}}, 12, {{r[0-7]}}
; Displacement 12 (within u4imm range 0-15) should use SE_STB
  %ptr = getelementptr inbounds i8, i8* %base, i32 12
  %trunc = trunc i32 %val to i8
  store i8 %trunc, i8* %ptr, align 1
  ret void
}

; Test SE_STB with maximum displacement
define void @test_stb_max_displacement(i8* %base, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_stb_max_displacement
; CHECK: se_stb {{r[0-7]}}, 15, {{r[0-7]}}
; Maximum displacement 15 (within u4imm range) should use SE_STB
  %ptr = getelementptr inbounds i8, i8* %base, i32 15
  %trunc = trunc i32 %val to i8
  store i8 %trunc, i8* %ptr, align 1
  ret void
}

; Test that large displacement falls back to standard instruction
define void @test_stb_large_displacement(i8* %base, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_stb_large_displacement
; CHECK-NOT: se_stb
; Displacement 16 (outside u4imm range) should use standard stb
; NOOPT-LABEL: @test_stb_large_displacement
; NOOPT: stb
  %ptr = getelementptr inbounds i8, i8* %base, i32 16
  %trunc = trunc i32 %val to i8
  store i8 %trunc, i8* %ptr, align 1
  ret void
}

; Test SE_STB with multiple stores
define void @test_stb_multiple(i8* %base, i32 %val1, i32 %val2) optsize minsize {
entry:
; CHECK-LABEL: @test_stb_multiple
; CHECK-DAG: se_stb {{r[0-7]}}, 0, {{r[0-7]}}
; CHECK-DAG: se_stb {{r[0-7]}}, 8, {{r[0-7]}}
; Multiple byte stores within range should use SE_STB
  %trunc1 = trunc i32 %val1 to i8
  store i8 %trunc1, i8* %base, align 1
  %ptr2 = getelementptr inbounds i8, i8* %base, i32 8
  %trunc2 = trunc i32 %val2 to i8
  store i8 %trunc2, i8* %ptr2, align 1
  ret void
}

