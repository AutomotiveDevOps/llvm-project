# PowerPC Embedded Examples

This directory contains example projects demonstrating how to use Clang to compile
embedded PowerPC e200/VLE applications.

## Overview

These examples show:
- Minimal embedded project setup
- Linker script usage
- Startup code implementation
- Integration with runtime libraries

## Examples

### simple_blink

A minimal LED blinking example demonstrating:
- Basic compilation workflow
- Linker script for embedded target
- Startup code for stack initialization

### linker_scripts

Sample linker scripts for common PowerPC e200 boards:
- Generic e200z0 (4-stage pipeline)
- Generic e200z4 (5-stage dual-issue)
- Generic e200z6 (7-stage single-issue)

### startup_code

Minimal startup code implementations:
- Basic crt0 for C programs
- Enhanced startup with data/bss initialization
- C++ startup with constructor handling

## Building Examples

### Prerequisites

- Clang with PowerPC backend support
- LLVM linker (lld) or compatible
- Target board or simulator

### Quick Start

1. Navigate to an example directory:
   ```bash
   cd simple_blink
   ```

2. Build with the provided Makefile:
   ```bash
   make
   ```

3. Verify the output:
   ```bash
   file firmware.elf
   llvm-objdump -d firmware.elf
   ```

## Documentation

For detailed information, see:
- [Clang Embedded PowerPC Guide](../../docs/EmbeddedPowerPC.rst)
- [Quick Start Guide](../../docs/EmbeddedPowerPCQuickStart.rst)

## Contributing

When adding new examples:
1. Include a README.md in the example directory
2. Provide a Makefile or CMakeLists.txt
3. Add comments explaining embedded-specific code
4. Test on actual hardware when possible

## License

These examples are provided as-is for educational purposes. Adapt as needed for
your projects.

