; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test E_LBZ, E_LHZ, E_LHA, E_LWZ (32-bit VLE load instructions).
; These are 32-bit VLE instructions that support larger displacements than 16-bit forms.
; Format: e_lbz rD, d(rA), e_lhz rD, d(rA), e_lha rD, d(rA), e_lwz rD, d(rA).
; Reference: VLEPEM Table B-3, VLEPIM Section 4.2.1

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_LBZ (32-bit load byte and zero)
define i32 @test_e_lbz(i8* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_e_lbz
; CHECK: e_lbz {{r[0-9]+}}, 100, {{r[0-9]+}}
; Large displacement should use E_LBZ (32-bit form)
  %ptr = getelementptr inbounds i8, i8* %base, i32 100
  %val = load i8, i8* %ptr, align 1
  %ext = zext i8 %val to i32
  ret i32 %ext
}

; Test E_LHZ (32-bit load halfword and zero)
define i32 @test_e_lhz(i16* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_e_lhz
; CHECK: e_lhz {{r[0-9]+}}, 200, {{r[0-9]+}}
; Large displacement should use E_LHZ (32-bit form)
  %ptr = getelementptr inbounds i16, i16* %base, i32 100
  %val = load i16, i16* %ptr, align 2
  %ext = zext i16 %val to i32
  ret i32 %ext
}

; Test E_LHA (32-bit load halfword algebraic/signed)
define i32 @test_e_lha(i16* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_e_lha
; CHECK: e_lha {{r[0-9]+}}, 200, {{r[0-9]+}}
; Signed halfword load should use E_LHA (32-bit form)
  %ptr = getelementptr inbounds i16, i16* %base, i32 100
  %val = load i16, i16* %ptr, align 2
  %ext = sext i16 %val to i32
  ret i32 %ext
}

; Test E_LWZ (32-bit load word and zero)
define i32 @test_e_lwz(i32* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_e_lwz
; CHECK: e_lwz {{r[0-9]+}}, 400, {{r[0-9]+}}
; Large displacement should use E_LWZ (32-bit form)
  %ptr = getelementptr inbounds i32, i32* %base, i32 100
  %val = load i32, i32* %ptr, align 4
  ret i32 %val
}

; Test that small displacements may prefer 16-bit forms when optimizing for size
define i32 @test_e_load_small_displacement(i32* %base) optsize minsize {
entry:
; CHECK-LABEL: @test_e_load_small_displacement
; Small displacements should prefer SE_LWZ (16-bit) over E_LWZ (32-bit) with -Oz
; CHECK: se_lwz
; CHECK-NOT: e_lwz
  %val = load i32, i32* %base, align 4
  ret i32 %val
}

<<<<<<< HEAD
=======
attributes #0 = { minsize optsize "target-cpu"="e200z4" }

>>>>>>> master
