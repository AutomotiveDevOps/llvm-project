; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=NOOPT

; Test 32-bit E-form extend and count instructions.
; Tests E_EXTSB, E_EXTSH, E_CNTLZW for extended register support.
; Reference: VLEPEM Table B-3, VLEPIM Section 4.7.2

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test E_EXTSB sign extend byte
define i32 @test_e_extsb(i8 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_e_extsb
; CHECK: e_extsb {{r[0-9]+}}, {{r[0-9]+}}
; Sign extend byte with extended registers should use E_EXTSB
  %ext = sext i8 %val to i32
  ret i32 %ext
}

; Test E_EXTSH sign extend halfword
define i32 @test_e_extsh(i16 %val) optsize minsize {
entry:
; CHECK-LABEL: @test_e_extsh
; CHECK: e_extsh {{r[0-9]+}}, {{r[0-9]+}}
; Sign extend halfword with extended registers should use E_EXTSH
  %ext = sext i16 %val to i32
  ret i32 %ext
}

; Test E_CNTLZW count leading zeros word
define i32 @test_e_cntlzw(i32 %a) optsize minsize {
entry:
; CHECK-LABEL: @test_e_cntlzw
; CHECK: e_cntlzw {{r[0-9]+}}, {{r[0-9]+}}
; Count leading zeros with extended registers should use E_CNTLZW
  %count = call i32 @llvm.ctlz.i32(i32 %a, i1 false)
  ret i32 %count
}

declare i32 @llvm.ctlz.i32(i32, i1)

attributes #0 = { minsize optsize "target-cpu"="e200z4" }

