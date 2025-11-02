; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test SE_STH (16-bit Store Halfword) instruction selection.
; SE_STH stores the low 16 bits of a register to memory.
; Format: se_sth rS, D4(rA) where D4 is 4-bit unsigned immediate (0-15).
; Requires R0-R7 registers and small displacement (u4imm: 0-15).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.2.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test SE_STH with zero displacement
define void @test_sth_zero(i16* %ptr, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_sth_zero
; CHECK: se_sth {{r[0-7]}}, 0, {{r[0-7]}}
; Zero displacement should use SE_STH
  %trunc = trunc i32 %val to i16
  store i16 %trunc, i16* %ptr, align 2
  ret void
}

; Test SE_STH with small positive displacement
define void @test_sth_displacement(i16* %base, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_sth_displacement
; CHECK: se_sth {{r[0-7]}}, 8, {{r[0-7]}}
; Displacement 8 (within u4imm range 0-15, even-aligned) should use SE_STH
  %ptr = getelementptr inbounds i16, i16* %base, i32 4
  %trunc = trunc i32 %val to i16
  store i16 %trunc, i16* %ptr, align 2
  ret void
}

; Test SE_STH with maximum displacement
define void @test_sth_max_displacement(i16* %base, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_sth_max_displacement
; CHECK: se_sth {{r[0-7]}}, 14, {{r[0-7]}}
; Maximum valid displacement 14 (within u4imm range, even-aligned) should use SE_STH
  %ptr = getelementptr inbounds i16, i16* %base, i32 7
  %trunc = trunc i32 %val to i16
  store i16 %trunc, i16* %ptr, align 2
  ret void
}

; Test that large displacement falls back to standard instruction
define void @test_sth_large_displacement(i16* %base, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_sth_large_displacement
; CHECK-NOT: se_sth
; Displacement 16 (outside u4imm range) should use standard sth
; NOOPT-LABEL: @test_sth_large_displacement
; NOOPT: sth
  %ptr = getelementptr inbounds i16, i16* %base, i32 8
  %trunc = trunc i32 %val to i16
  store i16 %trunc, i16* %ptr, align 2
  ret void
}

; Test SE_STH with multiple stores
define void @test_sth_multiple(i16* %base, i32 %val1, i32 %val2) optsize minsize {
entry:
; CHECK-LABEL: @test_sth_multiple
; CHECK-DAG: se_sth {{r[0-7]}}, 0, {{r[0-7]}}
; CHECK-DAG: se_sth {{r[0-7]}}, 10, {{r[0-7]}}
; Multiple halfword stores within range should use SE_STH
  %trunc1 = trunc i32 %val1 to i16
  store i16 %trunc1, i16* %base, align 2
  %ptr2 = getelementptr inbounds i16, i16* %base, i32 5
  %trunc2 = trunc i32 %val2 to i16
  store i16 %trunc2, i16* %ptr2, align 2
  ret void
}

