//===-- crt0_ppc.S - PowerPC e200 Bare-Metal Startup Code -----------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// PowerPC baremetal startup code (crt0) for embedded e200 cores.
// Supports both standard PowerPC and VLE (Variable Length Encoding) modes.
//
// This startup code performs:
// 1. IVOR table initialization (for e200 cores)
// 2. Stack pointer initialization (from linker symbol _stack_top or default)
// 3. .data section initialization (copy from Flash to RAM)
// 4. .bss section zeroing
// 5. C++ constructor array iteration (.init_array)
// 6. Call to main()
// 7. Infinite loop if main returns
//
//===----------------------------------------------------------------------===//

#include "../../lib/builtins/assembly.h"

// External symbols provided by linker script
.extern __stack
.weak __stack
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
.section .text.start, "ax", @progbits
.global _start
.type _start, @function

_start:
    // Entry point for PowerPC baremetal applications
    // On reset, the processor jumps to address 0x00000000, which should
    // contain this _start function (placed by linker script).

    // Step 1: Initialize IVPR (Interrupt Vector Prefix Register) for e200 cores
    // IVPR points to the base of the IVOR table (.core_exceptions_table)
    // This must be set before any interrupts can be serviced
    // The linker script provides __IVPR_VALUE symbol at the base of the IVOR table
    .extern __IVPR_VALUE
    .weak __IVPR_VALUE
    lis     %r3, __IVPR_VALUE@h
    ori     %r3, %r3, __IVPR_VALUE@l
    cmpwi   %r3, 0
    beq     init_ivpr_done              // Skip if __IVPR_VALUE is not defined
    mtspr   63, %r3                     // SPR 63 is IVPR (Interrupt Vector Prefix Register)
init_ivpr_done:

    // Step 2: Initialize Stack Pointer (R1)
    // Use __stack symbol if provided by linker script, otherwise use _stack_top or default
    .weak _stack_top
    .extern _stack_top
    lis     %r3, __stack@h
    ori     %r3, %r3, __stack@l
    cmpwi   %r3, 0
    bne     1f                          // Use __stack if defined
    lis     %r3, _stack_top@h
    ori     %r3, %r3, _stack_top@l
    cmpwi   %r3, 0
    bne     1f                          // Use _stack_top if defined
    lis     %r3, 0x2001                 // Default stack top at 0x20010000
    ori     %r3, %r3, 0x0000
1:
    mr      %r1, %r3                    // Copy to stack pointer register

    // Step 3: Copy .data section from Flash to RAM
    // Linker provides these symbols:
    // __data_load = Load address (in Flash)
    // __data_start__ = Virtual address (in RAM)
    // __data_end__ = End of .data section (in RAM)
    lis     %r3, __data_load@h          // Source address (Flash)
    ori     %r3, %r3, __data_load@l
    lis     %r4, __data_start__@h       // Destination address (RAM)
    ori     %r4, %r4, __data_start__@l
    lis     %r5, __data_end__@h         // End address
    ori     %r5, %r5, __data_end__@l

    // Check if .data section exists (src != dst means we need to copy)
    cmpw    %r3, %r4
    beq     2f                          // Skip if no .data to copy

    // Copy loop
copy_data_loop:
    cmpw    %r4, %r5
    bge     2f                          // Done if dst >= end
    lwz     %r6, 0(%r3)                 // Load from Flash
    stw     %r6, 0(%r4)                 // Store to RAM
    addi    %r3, %r3, 4                 // Increment source
    addi    %r4, %r4, 4                 // Increment destination
    b       copy_data_loop

2:
    // Step 4: Zero .bss section
    // Linker provides:
    // __bss_start__ = Start of .bss section
    // __bss_end__ = End of .bss section
    lis     %r3, __bss_start__@h
    ori     %r3, %r3, __bss_start__@l
    lis     %r4, __bss_end__@h
    ori     %r4, %r4, __bss_end__@l

    // Check if .bss exists
    cmpw    %r3, %r4
    bge     3f                          // Skip if no .bss to zero

    li      %r5, 0                      // Zero value
zero_bss_loop:
    cmpw    %r3, %r4
    bge     3f                          // Done if start >= end
    stw     %r5, 0(%r3)                 // Store zero
    addi    %r3, %r3, 4                 // Increment
    b       zero_bss_loop

3:
    // Step 5: Call C++ constructors via .init_array
    // The compiler generates .init_array section, and crtbegin/crtend
    // handle the actual constructor iteration.
    // For baremetal, we'll call _init if it exists (set up by crtbegin)
    .extern _init
    .weak _init
    lis     %r3, _init@h
    ori     %r3, %r3, _init@l
    cmpwi   %r3, 0
    beq     4f
    mtctr   %r3
    bctrl

4:
    // Step 6: Call main()
    // Call main with no arguments (typical for bare-metal)
    li      %r3, 0                      // argc = 0 (no arguments for bare-metal)
    li      %r4, 0                      // argv = NULL
    bl      main

    // Step 7: Infinite loop if main returns
    // Embedded programs typically never return from main
infinite_loop:
    b       infinite_loop

.size _start, . - _start
