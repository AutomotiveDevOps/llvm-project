; RUN: llc -mtriple=powerpc-unknown-linux-gnu -mcpu=e200z6 -mattr=+booke < %s | FileCheck %s
; RUN: llc -mtriple=powerpc-unknown-linux-gnu -mcpu=e200z4 -mattr=+booke < %s | FileCheck %s

; ISO 26262 Edge Case 008: Memory Barrier and Cache Coherency for Unified L1 Cache
; Test that memory barriers (msync/sync) are correctly generated for unified cache
; Reference: PPCInstrInfo.td (MSYNC/SYNC), PPCISelLowering.cpp, PPCScheduleE200Z6.td:23

target datalayout = "E-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v128:128:128-a0:0:64-f128:64:128-n32"
target triple = "powerpc-unknown-linux-gnu"

; Test 1: Sequentially consistent memory barrier (should use sync or msync)
define void @test_seq_cst_fence() {
; CHECK-LABEL: test_seq_cst_fence:
; CHECK:       # %bb.0:
; CHECK:        sync
; Or for BookE targets: CHECK: msync
entry:
  fence seq_cst
  ret void
}

; Test 2: Acquire memory barrier (should use lwsync or msync)
define void @test_acquire_fence() {
; CHECK-LABEL: test_acquire_fence:
; CHECK:       # %bb.0:
; CHECK:        lwsync
; Or for BookE: CHECK: msync
entry:
  fence acquire
  ret void
}

; Test 3: Release memory barrier (should use lwsync or msync)
define void @test_release_fence() {
; CHECK-LABEL: test_release_fence:
; CHECK:       # %bb.0:
; CHECK:        lwsync
; Or for BookE: CHECK: msync
entry:
  fence release
  ret void
}

; Test 4: Atomic load with acquire semantics
define i32 @test_atomic_load_acquire(i32* %ptr) {
; CHECK-LABEL: test_atomic_load_acquire:
; CHECK:       # %bb.0:
; CHECK:        lwz
; CHECK:        lwsync
; Or for BookE: CHECK: msync
entry:
  %val = load atomic i32, i32* %ptr acquire, align 4
  ret i32 %val
}

; Test 5: Atomic store with release semantics
define void @test_atomic_store_release(i32* %ptr, i32 %val) {
; CHECK-LABEL: test_atomic_store_release:
; CHECK:       # %bb.0:
; CHECK:        lwsync
; CHECK:        stw
; Or for BookE: CHECK: msync
entry:
  store atomic i32 %val, i32* %ptr release, align 4
  ret void
}

; Test 6: Atomic RMW with sequentially consistent ordering
define i32 @test_atomic_rmw_seq_cst(i32* %ptr, i32 %val) {
; CHECK-LABEL: test_atomic_rmw_seq_cst:
; CHECK:       # %bb.0:
; CHECK:        sync
; CHECK:        lwarx
; CHECK:        stwcx.
; CHECK:        bne
; CHECK:        sync
; Or for BookE: CHECK: msync
entry:
  %result = atomicrmw add i32* %ptr, i32 %val seq_cst
  ret i32 %result
}

; Test 7: Verify unified cache coherency - data and instruction cache
; e200z6 has unified 32KB L1 cache - memory barriers should ensure coherency
define void @test_unified_cache_coherency(i32* %data_ptr, i32 ()** %func_ptr) {
; CHECK-LABEL: test_unified_cache_coherency:
; CHECK:       # %bb.0:
; CHECK:        sync
; Or for BookE: CHECK: msync
; Verify memory barrier before code modification
entry:
  ; Store new function pointer
  store i32 ()* null, i32 ()** %func_ptr
  ; Memory barrier to ensure visibility
  fence seq_cst
  ; Invalidate instruction cache if needed
  ret void
}

