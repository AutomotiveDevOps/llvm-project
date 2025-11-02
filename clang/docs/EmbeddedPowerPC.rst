===================================================================
Embedded PowerPC e200/VLE Compilation with Clang
===================================================================

Introduction
============

This document describes how to use Clang to compile code for embedded PowerPC
e200 cores with VLE (Variable Length Encoding) support. VLE is an instruction
set extension designed specifically for embedded systems that can reduce code
size by 20-30% compared to standard PowerPC instructions.

PowerPC e200 cores are widely used in automotive, industrial, and aerospace
applications. VLE support provides 16-bit and 32-bit instruction formats,
optimized for small code footprint in resource-constrained embedded systems.

Target Triples
==============

Clang supports the following target triples for embedded PowerPC:

* ``powerpc-none-elf`` - Standard PowerPC embedded target (ELF)
* ``powerpc-none-eabivle`` - PowerPC embedded target with VLE support

The triple format is: ``<arch>-<vendor>-<os>-<abi>``

* **arch**: ``powerpc`` (32-bit PowerPC)
* **vendor**: ``none`` or omitted (unknown vendor)
* **os**: ``none`` (bare metal, no operating system)
* **abi**: ``elf`` (ELF format) or ``eabivle`` (ELF with VLE ABI)

Command-Line Options
====================

VLE Mode Control
----------------

* ``-mvle`` - Enable VLE (Variable Length Encoding) mode
* ``-mno-vle`` - Disable VLE mode (use standard PowerPC instructions)

When targeting ``powerpc-none-eabivle``, VLE mode is enabled by default.
Use ``-mno-vle`` to disable it if needed.

CPU Selection
------------

* ``-mcpu=<cpu-name>`` - Select the target CPU

Supported e200 cores:

* ``e200z0`` - 4-stage pipeline, minimal features
* ``e200z4`` - 5-stage dual-issue pipeline, SPE, FPU
* ``e200z6`` - 7-stage single-issue pipeline, FPU, unified cache

Example: ``-mcpu=e200z4``

Optimization Options
--------------------

* ``-Oz`` - Optimize for code size (recommended for VLE targets)
* ``-Os`` - Optimize for code size while balancing with speed
* ``-O2`` - Standard optimization

For embedded systems with limited flash memory, ``-Oz`` combined with ``-mvle``
provides the best code size reduction.

ABI Options
-----------

* ``-mabi=`` - Specify ABI variant (typically not needed for embedded targets)

Linker Options
--------------

* ``-T <script>`` - Specify linker script
* ``-nostartfiles`` - Do not link startup files
* ``-nostdlib`` - Do not link standard libraries
* ``--sysroot=<path>`` - Specify sysroot for libraries and headers

Example Compilation Workflow
=============================

Basic Compilation
-----------------

Compile a simple C file for PowerPC e200z4 with VLE:

.. code-block:: bash

   clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -Os \
         -c main.c -o main.o

Link to create an executable:

.. code-block:: bash

   clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -T linker_script.ld \
         -o firmware.elf main.o

Complete Example with Startup Code
-----------------------------------

1. Compile your source files:

.. code-block:: bash

   clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -Os \
         -c main.c -o main.o
   clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -Os \
         -c startup.c -o startup.o

2. Link with startup code and runtime:

.. code-block:: bash

   clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle \
         -T memory.ld -nostartfiles -nostdlib \
         -o firmware.elf startup.o main.o \
         -L/path/to/runtime -lclang_rt.builtins-powerpc

Linker Scripts
==============

Embedded projects require a linker script to define memory layout. The linker
script specifies:

* Memory regions (Flash, RAM)
* Section placement (`.text`, `.data`, `.bss`)
* Stack and heap addresses
* Entry point

Example minimal linker script (``memory.ld``):

.. code-block:: ld

   MEMORY
   {
     FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 512K
     RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 64K
   }

   ENTRY(_start)

   SECTIONS
   {
     .text : {
       *(.text.start)
       *(.text*)
     } > FLASH

     .data : {
       *(.data*)
     } > RAM AT > FLASH

     .bss : {
       *(.bss*)
     } > RAM
   }

Use the linker script with ``-T memory.ld``.

Startup Code
============

Embedded projects need startup code (often called ``crt0`` or ``startup``) to:

* Initialize the stack pointer
* Initialize `.data` section (copy from Flash to RAM)
* Zero `.bss` section
* Call constructors (for C++)
* Call ``main()``

Minimal startup code example:

.. code-block:: c

   void _start(void) {
     // Initialize stack pointer (example address)
     asm volatile ("lis %r1, 0x2000");
     asm volatile ("ori %r1, %r1, 0x10000");

     // Copy .data section from Flash to RAM
     extern char __data_start__, __data_end__, __data_load__;
     char *src = &__data_load__;
     char *dst = &__data_start__;
     while (dst < &__data_end__) {
       *dst++ = *src++;
     }

     // Zero .bss section
     extern char __bss_start__, __bss_end__;
     char *bss = &__bss_start__;
     while (bss < &__bss_end__) {
       *bss++ = 0;
     }

     // Call main
     main();

     // Infinite loop if main returns
     while (1) { }
   }

Runtime Libraries
=================

Compiler Runtime (compiler-rt)
-------------------------------

The compiler runtime library (``libclang_rt.builtins-powerpc.a``) provides
builtin functions required by code generation. These include:

* Integer arithmetic (64-bit operations on 32-bit targets)
* Floating-point conversions
* Bit manipulation functions
* Atomic operations

Build compiler-rt for your target:

.. code-block:: bash

   cmake -DCMAKE_C_COMPILER=clang \
         -DCMAKE_C_COMPILER_TARGET=powerpc-none-eabivle \
         -DCOMPILER_RT_BAREMETAL_BUILD=ON \
         -DCOMPILER_RT_OS_DIR=baremetal \
         /path/to/compiler-rt

Link the runtime library:

.. code-block:: bash

   clang ... -L/path/to/compiler-rt/lib/baremetal \
             -lclang_rt.builtins-powerpc

C Standard Library (Optional)
------------------------------

For minimal embedded projects, you may not need a full C library. If needed,
you can use:

* **newlib** - Lightweight C library for embedded systems
* **picolibc** - Even smaller alternative
* **Custom minimal libc** - For maximum control

C++ Standard Library (Optional)
--------------------------------

For C++ projects, you can use:

* **libc++** - LLVM's C++ standard library (can be built for bare metal)

Build libc++ for bare metal:

.. code-block:: bash

   cmake -DCMAKE_CXX_COMPILER=clang++ \
         -DCMAKE_CXX_COMPILER_TARGET=powerpc-none-eabivle \
         -DLIBCXX_ENABLE_SHARED=OFF \
         -DLIBCXX_ENABLE_THREADS=OFF \
         /path/to/libcxx

Troubleshooting
===============

Common Issues
-------------

**Issue**: Linker errors for undefined symbols

**Solution**: Ensure compiler-rt is linked:

.. code-block:: bash

   -L/path/to/compiler-rt -lclang_rt.builtins-powerpc

**Issue**: Code size is too large

**Solution**: Use ``-Oz`` optimization and ``-mvle``:

.. code-block:: bash

   clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -Oz ...

**Issue**: VLE instructions not generated

**Solution**: Ensure VLE mode is enabled and target triple is correct:

.. code-block:: bash

   clang -target powerpc-none-eabivle -mvle ...

**Issue**: Startup code not executing

**Solution**: Verify linker script entry point matches your startup function
name, typically ``_start``.

**Issue**: Stack overflow

**Solution**: Ensure stack pointer is initialized in startup code to a valid
RAM address, and linker script defines sufficient stack space.

Verification
------------

Verify VLE code generation:

.. code-block:: bash

   clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -S main.c
   # Check main.s for 16-bit VLE instructions (se_* prefix)

Verify object file format:

.. code-block:: bash

   file main.o
   # Should show: ELF 32-bit MSB relocatable, PowerPC, version 1

Check binary sections:

.. code-block:: bash

   llvm-objdump -h firmware.elf
   # Verify .text, .data, .bss sections are present

Additional Resources
====================

* :doc:`CrossCompilation` - General cross-compilation guide
* :doc:`Toolchain` - Complete toolchain documentation
* PowerPC VLE Programming Interface Manual (VLEPIM)
* PowerPC Book E Enhanced Architecture specification

See Also
========

For more information on:

* Building Clang for embedded targets: :doc:`../llvm/HowToBuildPowerPCEmbedded`
* Backend implementation details: ``llvm/lib/Target/PowerPC/README_VLE.md``
* Runtime library setup: ``compiler-rt/docs/PowerPCBareMetal.rst``

