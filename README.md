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

[![OpenSSF Scorecard](https://api.securityscorecards.dev/projects/github.com/llvm/llvm-project/badge)](https://securityscorecards.dev/viewer/?uri=github.com/llvm/llvm-project)
[![OpenSSF Best Practices](https://www.bestpractices.dev/projects/8273/badge)](https://www.bestpractices.dev/projects/8273)
[![libc++](https://github.com/llvm/llvm-project/actions/workflows/libcxx-build-and-test.yaml/badge.svg?branch=main&event=schedule)](https://github.com/llvm/llvm-project/actions/workflows/libcxx-build-and-test.yaml?query=event%3Aschedule)

Welcome to the LLVM project!

This repository contains the source code for LLVM, a toolkit for the
construction of highly optimized compilers, optimizers, and run-time
environments.

The LLVM project has multiple components. The core of the project is
itself called "LLVM". This contains all of the tools, libraries, and header
files needed to process intermediate representations and convert them into
object files. Tools include an assembler, disassembler, bitcode analyzer, and
bitcode optimizer.

C-like languages use the [Clang](https://clang.llvm.org/) frontend. This
component compiles C, C++, Objective-C, and Objective-C++ code into LLVM bitcode
-- and from there into object files, using LLVM.

Other components include:
the [libc++ C++ standard library](https://libcxx.llvm.org),
the [LLD linker](https://lld.llvm.org), and more.

## Getting the Source Code and Building LLVM

Consult the
[Getting Started with LLVM](https://llvm.org/docs/GettingStarted.html#getting-the-source-code-and-building-llvm)
page for information on building and running LLVM.

For information on how to contribute to the LLVM project, please take a look at
the [Contributing to LLVM](https://llvm.org/docs/Contributing.html) guide.

## Getting in touch

Join the [LLVM Discourse forums](https://discourse.llvm.org/), [Discord
chat](https://discord.gg/xS7Z362),
[LLVM Office Hours](https://llvm.org/docs/GettingInvolved.html#office-hours) or
[Regular sync-ups](https://llvm.org/docs/GettingInvolved.html#online-sync-ups).

The LLVM project has adopted a [code of conduct](https://llvm.org/docs/CodeOfConduct.html) for
participants to all modes of communication within the project.
