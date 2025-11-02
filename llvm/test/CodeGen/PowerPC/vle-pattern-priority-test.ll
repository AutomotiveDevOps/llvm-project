; Test file to verify VLE pattern prioritization in instruction selection
; This tests whether VLE patterns are tried before standard PowerPC patterns
;
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -mattr=+vle -Oz < %s | FileCheck %s --check-prefix=CHECK-VLE
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -mattr=+vle -O2 < %s | FileCheck %s --check-prefix=CHECK-STD

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test case 1: Add immediate that should prefer 16-bit VLE se_addi
; If VLE patterns are prioritized, this should generate se_addi (2 bytes) instead of addi (4 bytes)
define i32 @test_addi_small(i32 %a) #0 {
entry:
  ; Small immediate (-31 to 31) fits in 5-bit signed field of se_addi
  %result = add i32 %a, 15
  ret i32 %result
}
; CHECK-VLE-LABEL: test_addi_small:
; CHECK-VLE: se_addi
; CHECK-STD-LABEL: test_addi_small:
; CHECK-STD-NOT: se_addi

; Test case 2: Add that should prefer 32-bit VLE e_add over standard add
define i32 @test_add_reg(i32 %a, i32 %b) #0 {
entry:
  %result = add i32 %a, %b
  ret i32 %result
}
; CHECK-VLE-LABEL: test_add_reg:
; CHECK-VLE: e_add
; CHECK-STD-LABEL: test_add_reg:
; CHECK-STD-NOT: e_add

; Test case 3: Store with small offset - should prefer 16-bit VLE se_stw
define void @test_store_small(i32* %ptr, i32 %val) #0 {
entry:
  ; Small offset (0-3) fits in 2-bit field of se_stw
  store i32 %val, i32* %ptr, align 4
  ret void
}
; CHECK-VLE-LABEL: test_store_small:
; CHECK-VLE: se_stw
; CHECK-STD-LABEL: test_store_small:
; CHECK-STD-NOT: se_stw

; Attributes to enable code size optimization
attributes #0 = { minsize optsize "target-cpu"="e200z4" }

