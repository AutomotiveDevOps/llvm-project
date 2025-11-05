===================================================================
How To Build Clang for PowerPC Embedded Targets
===================================================================

Introduction
============

This document describes how to build Clang with support for PowerPC embedded
targets, specifically PowerPC e200 cores with VLE (Variable Length Encoding)
support.

Prerequisites
=============

* CMake 3.13.4 or later
* Python 3.6 or later
* C++ compiler (GCC or Clang)
* Ninja (recommended) or Make

Basic Build
===========

Configure CMake with PowerPC backend enabled:

.. code-block:: bash

   cmake -G Ninja \
         -DLLVM_TARGETS_TO_BUILD="PowerPC" \
         -DCMAKE_BUILD_TYPE=Release \
         -DLLVM_ENABLE_PROJECTS="clang;lld" \
         ../llvm

   ninja

This builds Clang with PowerPC backend support, including VLE instruction
support.

Building with compiler-rt
==========================

To build compiler-rt builtins for PowerPC bare-metal targets:

1. First build Clang and LLVM as above

2. Configure compiler-rt for PowerPC bare-metal:

.. code-block:: bash

   cmake -G Ninja \
         -DCMAKE_C_COMPILER=/path/to/clang \
         -DCMAKE_C_COMPILER_TARGET=powerpc-none-eabivle \
         -DCOMPILER_RT_BAREMETAL_BUILD=ON \
         -DCOMPILER_RT_OS_DIR=baremetal \
         -DCOMPILER_RT_DEFAULT_TARGET_ONLY=ON \
         /path/to/compiler-rt

   ninja

This builds ``libclang_rt.builtins-powerpc.a`` for embedded targets.

CMake Cache Configuration
==========================

For easier configuration, you can create a CMake cache file similar to
``clang/cmake/caches/BaremetalARM.cmake``:

Create ``clang/cmake/caches/BaremetalPowerPC.cmake``:

.. code-block:: cmake

   set(LLVM_TARGETS_TO_BUILD PowerPC CACHE STRING "")

   # Builtins for PowerPC embedded targets
   set(LLVM_BUILTIN_TARGETS "powerpc-none-elf;powerpc-none-eabivle" CACHE STRING "Builtin Targets")

   # powerpc-none-elf configuration
   set(BUILTINS_powerpc-none-elf_CMAKE_SYSROOT ${BAREMETAL_POWERPC_SYSROOT} CACHE STRING "powerpc-none-elf Sysroot")
   set(BUILTINS_powerpc-none-elf_CMAKE_SYSTEM_NAME Generic CACHE STRING "powerpc-none-elf System Name")
   set(BUILTINS_powerpc-none-elf_COMPILER_RT_BAREMETAL_BUILD ON CACHE BOOL "powerpc-none-elf Baremetal build")
   set(BUILTINS_powerpc-none-elf_COMPILER_RT_OS_DIR "baremetal" CACHE STRING "powerpc-none-elf os dir")

   # powerpc-none-eabivle configuration (with VLE)
   set(BUILTINS_powerpc-none-eabivle_CMAKE_SYSROOT ${BAREMETAL_POWERPC_SYSROOT} CACHE STRING "powerpc-none-eabivle Sysroot")
   set(BUILTINS_powerpc-none-eabivle_CMAKE_SYSTEM_NAME Generic CACHE STRING "powerpc-none-eabivle System Name")
   set(BUILTINS_powerpc-none-eabivle_COMPILER_RT_BAREMETAL_BUILD ON CACHE BOOL "powerpc-none-eabivle Baremetal build")
   set(BUILTINS_powerpc-none-eabivle_COMPILER_RT_OS_DIR "baremetal" CACHE STRING "powerpc-none-eabivle os dir")
   set(BUILTINS_powerpc-none-eabivle_CMAKE_C_FLAGS "-mvle" CACHE STRING "powerpc-none-eabivle C Flags")
   set(BUILTINS_powerpc-none-eabivle_CMAKE_ASM_FLAGS "-mvle" CACHE STRING "powerpc-none-eabivle ASM Flags")

   set(LLVM_INSTALL_TOOLCHAIN_ONLY ON CACHE BOOL "")
   set(LLVM_TOOLCHAIN_TOOLS
     dsymutil
     llc
     llvm-ar
     llvm-cxxfilt
     llvm-nm
     llvm-objdump
     llvm-strings
     llvm-size
     CACHE STRING "")

Use it with:

.. code-block:: bash

   cmake -C ../clang/cmake/caches/BaremetalPowerPC.cmake \
         -DBAREMETAL_POWERPC_SYSROOT=/path/to/sysroot \
         -G Ninja ../llvm

Testing the Build
=================

Verify Clang can target PowerPC embedded:

.. code-block:: bash

   ./bin/clang --version
   ./bin/clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -print-supported-cpus

Test compilation:

.. code-block:: bash

   echo "int main() { return 0; }" > test.c
   ./bin/clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle -c test.c -o test.o
   file test.o
   # Should show: ELF 32-bit MSB relocatable, PowerPC

Installation
============

Install to a directory:

.. code-block:: bash

   cmake -DCMAKE_INSTALL_PREFIX=/path/to/install \
         -P cmake_install.cmake

Or use ninja:

.. code-block:: bash

   ninja install

Troubleshooting
===============

**Error**: PowerPC backend not found

**Solution**: Ensure ``-DLLVM_TARGETS_TO_BUILD="PowerPC"`` includes PowerPC.

**Error**: VLE instructions not generated

**Solution**: Verify backend was built with VLE support and use ``-mvle`` flag.

**Error**: compiler-rt build fails

**Solution**: Ensure target triple matches exactly: ``powerpc-none-eabivle`` or
``powerpc-none-elf``.

See Also
========

* :doc:`HowToCrossCompileLLVM` - General cross-compilation guide
* :doc:`../clang/EmbeddedPowerPC` - Using Clang for embedded PowerPC
* :doc:`HowToCrossCompileBuiltinsOnArm` - Similar guide for ARM

