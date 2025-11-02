; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_STB, E_STH, E_STW (32-bit VLE store instructions).
; These are 32-bit VLE instructions that support larger displacements than 16-bit forms.
; Format: e_stb rS, d(rA), e_sth rS, d(rA), e_stw rS, d(rA).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.2.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_STB (32-bit store byte)
define void @test_e_stb(i8* %base, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_e_stb
; CHECK: e_stb {{r[0-9]+}}, 150, {{r[0-9]+}}
; Large displacement should use E_STB (32-bit form)
  %ptr = getelementptr inbounds i8, i8* %base, i32 150
  %trunc = trunc i32 %val to i8
  store i8 %trunc, i8* %ptr, align 1
  ret void
}

; Test E_STH (32-bit store halfword)
define void @test_e_sth(i16* %base, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_e_sth
; CHECK: e_sth {{r[0-9]+}}, 300, {{r[0-9]+}}
; Large displacement should use E_STH (32-bit form)
  %ptr = getelementptr inbounds i16, i16* %base, i32 150
  %trunc = trunc i32 %val to i16
  store i16 %trunc, i16* %ptr, align 2
  ret void
}

; Test E_STW (32-bit store word)
define void @test_e_stw(i32* %base, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_e_stw
; CHECK: e_stw {{r[0-9]+}}, 500, {{r[0-9]+}}
; Large displacement should use E_STW (32-bit form)
  %ptr = getelementptr inbounds i32, i32* %base, i32 125
  store i32 %val, i32* %ptr, align 4
  ret void
}

; Test that small displacements may prefer 16-bit forms when optimizing for size
define void @test_e_store_small_displacement(i32* %base, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_e_store_small_displacement
; Small displacements should prefer SE_STW (16-bit) over E_STW (32-bit) with -Oz
; CHECK: se_stw
; CHECK-NOT: e_stw
  store i32 %val, i32* %base, align 4
  ret void
}

