# PowerPC Linker Script Templates

This document describes the linker script generator and templates for PowerPC embedded targets.

## Generator Tool

A Python script `generate-ppc-linker-script.py` is provided to generate linker scripts for common PowerPC MCUs.

## Supported MCUs

- **mpc5643l**: 512K Flash, 128K RAM
- **mpc5646c**: 1000K Flash, 128K RAM  
- **mpc5748g**: 2048K Flash, 384K RAM + 64K Local DMEM
- **mpc5744p**: 1024K Flash, 426K RAM + 64K Local DMEM
- **mpc5775k**: 2048K Flash, 384K RAM + 64K Local DMEM

## Usage

### Basic Usage

```bash
generate-ppc-linker-script.py --mcu mpc5748g -o linker.ld
```

### Custom Heap/Stack Sizes

```bash
generate-ppc-linker-script.py --mcu mpc5748g \
    --heap-size 8192 --stack-size 16384 -o linker.ld
```

### Mixed VLE/BookE Mode

For MCUs that support both VLE and BookE instructions:

```bash
generate-ppc-linker-script.py --mcu mpc5643l \
    --mixed-vle-booke -o linker.ld
```

This creates separate `.text_vle` and `.text_booke` sections.

### Custom Memory Layout

```bash
generate-ppc-linker-script.py --mcu mpc5748g \
    --flash-base 0x1000000 --flash-size 2048K \
    --ram-base 0x40000000 --ram-size 384K -o linker.ld
```

## Linker Script Requirements

The generated linker scripts provide the following symbols that are required by the crt0 startup code:

- `__data_start__` - Start of .data section in RAM
- `__data_end__` - End of .data section in RAM  
- `__data_load__` - Load address of .data in Flash
- `__bss_start__` - Start of .bss section
- `__bss_end__` - End of .bss section
- `_stack_top` - Stack top address (optional, defaults in crt0)

These are provided through:
- `ADDR(.data)` → `__DATA_SRAM_ADDR` (can be aliased to `__data_start__`)
- `LOADADDR(.data)` → `__DATA_ROM_ADDR` (can be aliased to `__data_load__`)

## Integration with Clang

The linker script should be specified with `-T`:

```bash
clang -target powerpc-none-eabivle -mcpu=e200z4 -mvle \
    -T linker.ld -o firmware.elf main.o
```

## Template Structure

All generated linker scripts follow this structure:

1. **Entry Point**: `ENTRY(_start)`
2. **Memory Regions**: Flash and RAM definitions
3. **Sections**:
   - `.startup` - Startup code (from crt0)
   - `.core_exceptions_table` - Core exception handlers
   - `.intc_vector_table` - Interrupt controller vectors
   - `.text` - Code (or `.text_vle`/`.text_booke` for mixed mode)
   - `.rodata` - Read-only data
   - `.data` - Initialized data (loaded from Flash)
   - `.bss` - Uninitialized data
   - `.stack` - Stack and heap
4. **Symbols**: Data section addresses for startup code

## Adding New MCU Configurations

To add support for a new MCU, add an entry to `MCU_CONFIGS` in `generate-ppc-linker-script.py`:

```python
"new_mcu": {
    "flash_base": 0x00000000,
    "flash_size": 512 * 1024,
    "flash_rchw": {"org": 0x00000000, "len": 0x08},
    "ram_base": 0x40000000,
    "ram_size": 128 * 1024,
    "text_start": 0x1000,
    "has_local_dmem": False,
},
```

## Notes

- The generator creates linker scripts compatible with the default crt0 startup code
- Stack is placed in `local_dmem` if available, otherwise in `m_data`
- Heap size defaults to 0 (no heap)
- Stack size defaults to 4096 bytes

