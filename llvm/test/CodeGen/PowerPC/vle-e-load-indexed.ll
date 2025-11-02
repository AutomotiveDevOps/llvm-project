; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_LBZU, E_LHZU, E_LWZU (32-bit VLE indexed/update-form load instructions).
; These instructions load from memory and update the base register with the effective address.
; Format: e_lbzu rD, d(rA), e_lhzu rD, d(rA), e_lwzu rD, d(rA).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.2.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_LBZU (32-bit load byte and zero with update)
define i32 @test_e_lbzu(i8* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_e_lbzu
; CHECK: e_lbzu {{r[0-9]+}}, 64, {{r[0-9]+}}
; Update-form load byte should use E_LBZU
  %ptr = getelementptr inbounds i8, i8* %base, i32 64
  %val = load i8, i8* %ptr, align 1
  %ext = zext i8 %val to i32
  %base.updated = getelementptr inbounds i8, i8* %base, i32 64
  %unused = ptrtoint i8* %base.updated to i32
  ret i32 %ext
}

; Test E_LHZU (32-bit load halfword and zero with update)
define i32 @test_e_lhzu(i16* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_e_lhzu
; CHECK: e_lhzu {{r[0-9]+}}, 128, {{r[0-9]+}}
; Update-form load halfword should use E_LHZU
  %ptr = getelementptr inbounds i16, i16* %base, i32 64
  %val = load i16, i16* %ptr, align 2
  %ext = zext i16 %val to i32
  ret i32 %ext
}

; Test E_LWZU (32-bit load word and zero with update)
define i32 @test_e_lwzu(i32* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_e_lwzu
; CHECK: e_lwzu {{r[0-9]+}}, 256, {{r[0-9]+}}
; Update-form load word should use E_LWZU
  %ptr = getelementptr inbounds i32, i32* %base, i32 64
  %val = load i32, i32* %ptr, align 4
  ret i32 %val
}

<<<<<<< HEAD
=======
attributes #0 = { minsize optsize "target-cpu"="e200z4" }

>>>>>>> master
