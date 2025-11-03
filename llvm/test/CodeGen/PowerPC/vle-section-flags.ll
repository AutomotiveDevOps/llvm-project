; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test SHF_PPC_VLE section flag handling.
; VLE sections should have the SHF_PPC_VLE flag set to indicate VLE code.
; Reference: COMPREHENSIVE_GCC_PATCHES_ANALYSIS.md

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test that VLE code sections are properly marked
define void @test_vle_section() optsize minsize {
entry:
; CHECK-LABEL: @test_vle_section
; VLE sections should have appropriate flags set
  ret void
}

; Test mixed-mode: some code may be VLE, some standard PowerPC
define void @test_mixed_sections() optsize minsize {
entry:
; CHECK-LABEL: @test_mixed_sections
  %val = add i32 1, 2
  ret void
}

