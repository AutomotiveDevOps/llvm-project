# The LLVM Compiler Infrastructure / PowerPC e200 Fork

> The PowerPC e200 is a family of 32-bit Power ISA microprocessor cores developed by Freescale for primary use in automotive and industrial control systems. The cores are designed to form the CPU part in system-on-a-chip (SoC) designs with speed ranging up to 600 MHz, thus making them ideal for embedded applications.
  
> The e200 core is developed from the MPC5xx family processors, which in turn is derived from the MPC8xx core in the PowerQUICC SoC processors. e200 adheres to the Power ISA v.2.03 as well as the previous Book E specification. All e200 core based microprocessors are named in the MPC55xx and MPC56xx/JPC56x scheme, not to be confused with the MPC52xx processors which is based on the PowerPC e300 core.
  
> In April 2007 Freescale and IPextreme opened up the e200 cores for licensing to other manufacturers.[1]
  
> Continental AG and Freescale are developing SPACE, a tri-core e200 based processor designed for electronic brake systems in cars.[2]
  
> STMicroelectronics and Freescale have jointly developed microcontrollers for automotive applications based on e200 in the MPC56xx/SPC56x family. 
  
>  -   https://en.wikipedia.org/wiki/PowerPC_e200

# Roadmap:

- [NXP MPC5744P](https://www.nxp.com/design/development-boards/automotive-development-platforms/mpc57xx-mcu-platforms/mpc5744p-development-board-for-functional-safety-motor-control:DEVKIT-MPC5744P).
- https://www.nxp.com/docs/en/data-sheet/MPC5744P.pdf

>> The e200z4 has a five-stage, dual-issue pipeline with a branch prediction unit, a 16 entry MMU, signal processing extension (SPE), a SIMD capable single precision FPU and a 4 Kilobyte 2/4-way set associative instruction L1 cache (Pseudo round-robin replacement algorithm). It has no data cache. It can use the complete 32-bit PowerPC ISA as well as the VLE instructions. It uses a dual 64-bit bus AMBA 2.0v6 interface. The load/store unit is pipelined, has a 2-cycle load latency and supports throughput of one load or store operation per cycle.
>> Depending on the derivative may support SPE or LSP. 

![mpc5744p_mods](mpc5744p_mods.png)
![mpc5744p_feature2](mpc5744p_feature2.png)
![safetylake_diagram.png](safetylake_diagram.png)

## Dev Platform:

- [DEVKIT MPC5744P](https://octopart.com/devkit-mpc5744p-nxp+semiconductors-82944748?r=sp)

# TODO:

- Simulink Embedded Coder Support
- Matlab packaging desired host platforms.

###

This directory and its sub-directories contain source code for LLVM,
a toolkit for the construction of highly optimized compilers,
optimizers, and run-time environments.

The README briefly describes how to get started with building LLVM.
For more information on how to contribute to the LLVM project, please
take a look at the
[Contributing to LLVM](https://llvm.org/docs/Contributing.html) guide.

## Getting Started with the LLVM System

Taken from https://llvm.org/docs/GettingStarted.html.

### Overview

Welcome to the LLVM project!

The LLVM project has multiple components. The core of the project is
itself called "LLVM". This contains all of the tools, libraries, and header
files needed to process intermediate representations and converts it into
object files.  Tools include an assembler, disassembler, bitcode analyzer, and
bitcode optimizer.  It also contains basic regression tests.

C-like languages use the [Clang](http://clang.llvm.org/) front end.  This
component compiles C, C++, Objective-C, and Objective-C++ code into LLVM bitcode
-- and from there into object files, using LLVM.

Other components include:
the [libc++ C++ standard library](https://libcxx.llvm.org),
the [LLD linker](https://lld.llvm.org), and more.

### Getting the Source Code and Building LLVM

The LLVM Getting Started documentation may be out of date.  The [Clang
Getting Started](http://clang.llvm.org/get_started.html) page might have more
accurate information.

This is an example work-flow and configuration to get and build the LLVM source:

1. Checkout LLVM (including related sub-projects like Clang):

     * ``git clone https://github.com/llvm/llvm-project.git``

     * Or, on windows, ``git clone --config core.autocrlf=false
    https://github.com/llvm/llvm-project.git``

2. Configure and build LLVM and Clang:

     * ``cd llvm-project``

     * ``mkdir build``

     * ``cd build``

     * ``cmake -G <generator> [options] ../llvm``

        Some common build system generators are:

        * ``Ninja`` --- for generating [Ninja](https://ninja-build.org)
          build files. Most llvm developers use Ninja.
        * ``Unix Makefiles`` --- for generating make-compatible parallel makefiles.
        * ``Visual Studio`` --- for generating Visual Studio projects and
          solutions.
        * ``Xcode`` --- for generating Xcode projects.

        Some Common options:

        * ``-DLLVM_ENABLE_PROJECTS='...'`` --- semicolon-separated list of the LLVM
          sub-projects you'd like to additionally build. Can include any of: clang,
          clang-tools-extra, libcxx, libcxxabi, libunwind, lldb, compiler-rt, lld,
          polly, or debuginfo-tests.

          For example, to build LLVM, Clang, libcxx, and libcxxabi, use
          ``-DLLVM_ENABLE_PROJECTS="clang;libcxx;libcxxabi"``.

        * ``-DCMAKE_INSTALL_PREFIX=directory`` --- Specify for *directory* the full
          path name of where you want the LLVM tools and libraries to be installed
          (default ``/usr/local``).

        * ``-DCMAKE_BUILD_TYPE=type`` --- Valid options for *type* are Debug,
          Release, RelWithDebInfo, and MinSizeRel. Default is Debug.

        * ``-DLLVM_ENABLE_ASSERTIONS=On`` --- Compile with assertion checks enabled
          (default is Yes for Debug builds, No for all other build types).

      * ``cmake --build . [-- [options] <target>]`` or your build system specified above
        directly.

        * The default target (i.e. ``ninja`` or ``make``) will build all of LLVM.

        * The ``check-all`` target (i.e. ``ninja check-all``) will run the
          regression tests to ensure everything is in working order.

        * CMake will generate targets for each tool and library, and most
          LLVM sub-projects generate their own ``check-<project>`` target.

        * Running a serial build will be **slow**.  To improve speed, try running a
          parallel build.  That's done by default in Ninja; for ``make``, use the option
          ``-j NNN``, where ``NNN`` is the number of parallel jobs, e.g. the number of
          CPUs you have.

      * For more information see [CMake](https://llvm.org/docs/CMake.html)

Consult the
[Getting Started with LLVM](https://llvm.org/docs/GettingStarted.html#getting-started-with-llvm)
page for detailed information on configuring and compiling LLVM. You can visit
[Directory Layout](https://llvm.org/docs/GettingStarted.html#directory-layout)
to learn about the layout of the source code tree.
