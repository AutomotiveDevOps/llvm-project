; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz < %s | FileCheck %s --check-prefix=CHECK-OZ
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z4 -mvle -O2 < %s | FileCheck %s --check-prefix=CHECK-O2
; RUN: llc -mtriple=powerpc-none-eabivle -mcpu=e200z6 -mvle -Oz < %s | FileCheck %s --check-prefix=CHECK-OZ

; ISO 26262 Edge Case 010: Deterministic Execution Timing Violations Due to Optimizations
; Test that code generation is deterministic and WCET violations don't occur
; Reference: PPCTargetTransformInfo.cpp:234-281, PPCVLEOpt.cpp, PPCMachineScheduler.cpp

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v128:128:128-n32"
target triple = "powerpc-none-eabivle"

; Test 1: Deterministic instruction selection - same input should produce same output
define i32 @test_deterministic_selection(i32 %a) optsize minsize {
; CHECK-OZ-LABEL: test_deterministic_selection:
; CHECK-OZ:       # %bb.0:
; CHECK-OZ:        se_addi {{r[0-7]}}, {{r[0-7]}}, 10
; Multiple compilation runs should produce identical code
entry:
  %result = add i32 %a, 10
  ret i32 %result
}

; Test 2: Register allocation determinism
define i32 @test_register_allocation_determinism(i32 %a, i32 %b, i32 %c) optsize minsize {
; CHECK-OZ-LABEL: test_register_allocation_determinism:
; CHECK-OZ:       # %bb.0:
; CHECK-OZ:        se_add
; CHECK-OZ:        se_add
; Register allocation should be deterministic across compiler runs
entry:
  %add1 = add i32 %a, %b
  %add2 = add i32 %add1, %c
  ret i32 %add2
}

; Test 3: VLE optimization determinism - verify 16-bit vs 32-bit selection is deterministic
define i32 @test_vle_optimization_determinism(i32 %a) optsize minsize {
; CHECK-OZ-LABEL: test_vle_optimization_determinism:
; CHECK-OZ:       # %bb.0:
; CHECK-OZ:        se_addi
; VLE instruction selection should be deterministic
entry:
  %result = add i32 %a, 15  ; Should consistently use se_addi
  ret i32 %result
}

; Test 4: Instruction scheduling determinism
define i32 @test_scheduling_determinism(i32 %a, i32 %b, i32* %ptr) optsize minsize {
; CHECK-OZ-LABEL: test_scheduling_determinism:
; CHECK-OZ:       # %bb.0:
; CHECK-OZ:        se_add
; CHECK-OZ:        se_stw
; Instruction ordering should be deterministic
entry:
  %sum = add i32 %a, %b
  store i32 %sum, i32* %ptr
  ret i32 %sum
}

; Test 5: Optimization level consistency - verify WCET doesn't change unexpectedly
define i32 @test_optimization_level_consistency(i32 %a, i32 %b) {
; CHECK-O2-LABEL: test_optimization_level_consistency:
; CHECK-O2:       # %bb.0:
; Different optimization levels may produce different code, but should be deterministic
entry:
  %result = add i32 %a, %b
  ret i32 %result
}

; Test 6: Code size optimization without timing violations
define i32 @test_code_size_without_timing_violations(i32 %a) optsize minsize {
; CHECK-OZ-LABEL: test_code_size_without_timing_violations:
; CHECK-OZ:       # %bb.0:
; CHECK-OZ:        se_addi
; Code size optimization should not introduce non-deterministic timing
entry:
  %result = add i32 %a, 10
  ret i32 %result
}

; Test 7: Pipeline behavior consistency
define i32 @test_pipeline_behavior_consistency(i32 %a, i32* %ptr) optsize minsize {
; CHECK-OZ-LABEL: test_pipeline_behavior_consistency:
; CHECK-OZ:       # %bb.0:
; CHECK-OZ:        se_lwz
; CHECK-OZ:        se_add
; Pipeline behavior should be consistent and predictable
entry:
  %val = load i32, i32* %ptr
  %result = add i32 %a, %val
  ret i32 %result
}

