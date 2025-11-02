; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_STBU, E_STHU, E_STWU (32-bit VLE indexed/update-form store instructions).
; These instructions store to memory and update the base register with the effective address.
; Format: e_stbu rS, d(rA), e_sthu rS, d(rA), e_stwu rS, d(rA).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.2.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_STBU (32-bit store byte with update)
define void @test_e_stbu(i8* %base, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_e_stbu
; CHECK: e_stbu {{r[0-9]+}}, 80, {{r[0-9]+}}
; Update-form store byte should use E_STBU
  %ptr = getelementptr inbounds i8, i8* %base, i32 80
  %trunc = trunc i32 %val to i8
  store i8 %trunc, i8* %ptr, align 1
  ret void
}

; Test E_STHU (32-bit store halfword with update)
define void @test_e_sthu(i16* %base, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_e_sthu
; CHECK: e_sthu {{r[0-9]+}}, 160, {{r[0-9]+}}
; Update-form store halfword should use E_STHU
  %ptr = getelementptr inbounds i16, i16* %base, i32 80
  %trunc = trunc i32 %val to i16
  store i16 %trunc, i16* %ptr, align 2
  ret void
}

; Test E_STWU (32-bit store word with update)
define void @test_e_stwu(i32* %base, i32 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_e_stwu
; CHECK: e_stwu {{r[0-9]+}}, 320, {{r[0-9]+}}
; Update-form store word should use E_STWU
  %ptr = getelementptr inbounds i32, i32* %base, i32 80
  store i32 %val, i32* %ptr, align 4
  ret void
}

<<<<<<< HEAD
=======
attributes #0 = { minsize optsize "target-cpu"="e200z4" }

>>>>>>> master
