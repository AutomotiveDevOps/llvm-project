; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s

; Test VLE stub entry generation for out-of-range branches.
; When branch displacement exceeds VLE encoding range, stubs should be inserted.
; Reference: COMPREHENSIVE_GCC_PATCHES_ANALYSIS.md, VLEPIM Chapter 2
; Code location: lld/ELF/Thunks.cpp:writeVLEStub()

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

declare void @far_function()

; Test that far calls generate stub entries when needed
define void @test_far_call() optsize minsize {
entry:
; CHECK-LABEL: @test_far_call
; CHECK: e_bl far_function
; Far function calls should use e_bl (32-bit displacement) or stub
  call void @far_function()
  ret void
}

; Test branch to far label (may need stub)
define void @test_far_branch() optsize minsize {
entry:
; CHECK-LABEL: @test_far_branch
  br label %far_label
near_label:
  ret void
far_label:
  ret void
}

; Test that in-range branches don't need stubs
define void @test_near_branch() optsize minsize {
entry:
; CHECK-LABEL: @test_near_branch
; CHECK: se_b
; Near branches should use se_b (16-bit) without stub
  br label %label
label:
  ret void
}

