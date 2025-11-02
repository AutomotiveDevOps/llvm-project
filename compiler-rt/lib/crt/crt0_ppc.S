//===-- crt0_ppc.S - PowerPC e200 Bare-Metal Startup Code -----------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file provides bare-metal startup code for PowerPC e200 cores with
// VLE support. It includes:
// - IVOR (Interrupt Vector Offset Register) table initialization
// - Stack pointer initialization
// - BSS zeroing
// - Data section initialization
// - Constructor call setup
// - Main function invocation
//
//===----------------------------------------------------------------------===//

#include "../../lib/builtins/assembly.h"

// External symbols provided by linker script
.extern __stack
.extern __bss_start__
.extern __bss_end__
.extern __data_start__
.extern __data_end__
.extern __data_load

// External symbols for initialization
.extern __ctors_start__
.extern __ctors_end__
.extern main

//===----------------------------------------------------------------------===//
// IVOR Table Section
//===----------------------------------------------------------------------===//
// The IVOR (Interrupt Vector Offset Register) table is placed in a special
// section that the linker script places at a fixed address. Each entry is
// a 32-bit function pointer (or branch instruction) to the interrupt handler.
//
// IVOR entries for PowerPC e200:
// IVOR0  - Critical Input (non-maskable interrupt)
// IVOR1  - Machine Check
// IVOR2  - Data Storage
// IVOR3  - Instruction Storage
// IVOR4  - External Input
// IVOR5  - Alignment
// IVOR6  - Program
// IVOR7  - Floating-Point Unavailable
// IVOR8  - System Call
// IVOR9  - Auxiliary Processor Unavailable
// IVOR10 - Decrementer
// IVOR11 - Fixed Interval Timer
// IVOR12 - Watchdog Timer
// IVOR13 - Data TLB Error
// IVOR14 - Instruction TLB Error
// IVOR15 - Debug

.section .ivor_table, "a", @progbits
.align 4
.global __ivor_table_start
__ivor_table_start:

// Default interrupt handlers - branch to default handler or loop
// Users can override these by placing functions in .core_exceptions_table
// with proper weak symbols or by providing their own interrupt handlers.

// IVOR0 - Critical Interrupt (non-maskable)
.long __default_critical_handler

// IVOR1 - Machine Check
.long __default_machine_check_handler

// IVOR2 - Data Storage
.long __default_data_storage_handler

// IVOR3 - Instruction Storage
.long __default_instruction_storage_handler

// IVOR4 - External Interrupt
.long __default_external_handler

// IVOR5 - Alignment
.long __default_alignment_handler

// IVOR6 - Program
.long __default_program_handler

// IVOR7 - Floating-Point Unavailable
.long __default_fpu_unavailable_handler

// IVOR8 - System Call
.long __default_syscall_handler

// IVOR9 - Auxiliary Processor Unavailable
.long __default_apu_unavailable_handler

// IVOR10 - Decrementer
.long __default_decrementer_handler

// IVOR11 - Fixed Interval Timer
.long __default_fit_handler

// IVOR12 - Watchdog Timer
.long __default_watchdog_handler

// IVOR13 - Data TLB Error
.long __default_data_tlb_error_handler

// IVOR14 - Instruction TLB Error
.long __default_instruction_tlb_error_handler

// IVOR15 - Debug
.long __default_debug_handler

.global __ivor_table_end
__ivor_table_end:

//===----------------------------------------------------------------------===//
// Default Interrupt Handlers
//===----------------------------------------------------------------------===//
// These are weak symbols that can be overridden by user-provided handlers
// marked with __attribute__((interrupt))

.section .text
.align 4

.weak __default_critical_handler
__default_critical_handler:
    b __default_critical_handler  // Infinite loop - user should override

.weak __default_machine_check_handler
__default_machine_check_handler:
    b __default_machine_check_handler

.weak __default_data_storage_handler
__default_data_storage_handler:
    b __default_data_storage_handler

.weak __default_instruction_storage_handler
__default_instruction_storage_handler:
    b __default_instruction_storage_handler

.weak __default_external_handler
__default_external_handler:
    b __default_external_handler

.weak __default_alignment_handler
__default_alignment_handler:
    b __default_alignment_handler

.weak __default_program_handler
__default_program_handler:
    b __default_program_handler

.weak __default_fpu_unavailable_handler
__default_fpu_unavailable_handler:
    b __default_fpu_unavailable_handler

.weak __default_syscall_handler
__default_syscall_handler:
    b __default_syscall_handler

.weak __default_apu_unavailable_handler
__default_apu_unavailable_handler:
    b __default_apu_unavailable_handler

.weak __default_decrementer_handler
__default_decrementer_handler:
    b __default_decrementer_handler

.weak __default_fit_handler
__default_fit_handler:
    b __default_fit_handler

.weak __default_watchdog_handler
__default_watchdog_handler:
    b __default_watchdog_handler

.weak __default_data_tlb_error_handler
__default_data_tlb_error_handler:
    b __default_data_tlb_error_handler

.weak __default_instruction_tlb_error_handler
__default_instruction_tlb_error_handler:
    b __default_instruction_tlb_error_handler

.weak __default_debug_handler
__default_debug_handler:
    b __default_debug_handler

//===----------------------------------------------------------------------===//
// Startup Code (_start entry point)
//===----------------------------------------------------------------------===//
.section .text.startup, "ax", @progbits
.align 4
.global _start
.type _start, @function
_start:
    // Initialize stack pointer
    // Stack pointer (R1) must be initialized before any function calls
    lis r1, __stack@h
    ori r1, r1, __stack@l

    // Clear BSS section (uninitialized data)
    // This must be done before any global variables are accessed
    lis r3, __bss_start__@h
    ori r3, r3, __bss_start__@l
    lis r4, __bss_end__@h
    ori r4, r4, __bss_end__@l
    
    // Calculate size
    subf r5, r3, r4
    
    // Zero BSS if size > 0
    cmpwi r5, 0
    beq bss_done
    
    // Zero memory loop
    li r0, 0
bss_loop:
    stw r0, 0(r3)
    addi r3, r3, 4
    subi r5, r5, 4
    cmpwi r5, 0
    bgt bss_loop
    
bss_done:
    // Copy initialized data from Flash to RAM
    // Data section in RAM needs to be initialized from Flash image
    lis r3, __data_start__@h
    ori r3, r3, __data_start__@l      // RAM destination
    lis r4, __data_load@h
    ori r4, r4, __data_load@l          // Flash source
    lis r5, __data_end__@h
    ori r5, r5, __data_end__@l         // End address
    
    // Calculate size
    subf r6, r3, r5
    
    // Copy if size > 0
    cmpwi r6, 0
    beq data_done
    
data_loop:
    lwz r0, 0(r4)     // Load from Flash
    stw r0, 0(r3)      // Store to RAM
    addi r3, r3, 4
    addi r4, r4, 4
    subi r6, r6, 4
    cmpwi r6, 0
    bgt data_loop
    
data_done:
    // Call constructors (.init_array or .ctors)
    // Note: crtbegin.c handles constructor calls via __do_init
    // which is called from .init section or via .init_array
    
    // Initialize IVOR base register if needed
    // IVOR base register setup is typically done by hardware or boot code
    // but we can set it here if the IVOR table is at a known address
    // mtspr IVOR0-15 are typically set by hardware, but we verify the table
    
    // Call main function
    li r3, 0           // argc = 0 (no arguments for bare-metal)
    li r4, 0           // argv = NULL
    bl main
    
    // Main returned - enter infinite loop (bare-metal has no exit)
exit_loop:
    b exit_loop

.size _start, .-_start

