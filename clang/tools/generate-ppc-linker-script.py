#!/usr/bin/env python3
"""
PowerPC Embedded Linker Script Generator

Generates linker scripts for PowerPC embedded targets (e200 cores) based on
MCU-specific memory configurations. Supports standard PowerPC and VLE modes.

Usage:
    generate-ppc-linker-script.py --mcu <mcu> [options] -o <output.ld>

Example:
    generate-ppc-linker-script.py --mcu mpc5748g -o linker.ld
    generate-ppc-linker-script.py --mcu mpc5643l --mixed-vle-booke -o linker.ld
"""

import argparse
import sys
from typing import Dict, List, Optional

# Predefined MCU configurations
MCU_CONFIGS = {
    "mpc5643l": {
        "flash_base": 0x00000000,
        "flash_size": 512 * 1024,  # 512K
        "flash_rchw": {"org": 0x00000000, "len": 0x08},
        "ram_base": 0x40000000,
        "ram_size": 128 * 1024,  # 128K
        "text_start": 0x1000,
        "has_local_dmem": False,
    },
    "mpc5646c": {
        "flash_base": 0x00000000,
        "flash_size": 1000 * 1024,  # 1000K
        "flash_rchw": {"org": 0x00000000, "len": 0x08},
        "ram_base": 0x40000000,
        "ram_size": 128 * 1024,  # 128K
        "text_start": 0x1000,
        "has_local_dmem": False,
    },
    "mpc5748g": {
        "flash_base": 0x1000000,
        "flash_size": 2048 * 1024,  # 2048K
        "flash_rchw": {"org": 0x00FA0000, "len": 0x4},
        "cpu0_reset_vec": {"org": 0x00FA0004, "len": 0x4},
        "ram_base": 0x40000000,
        "ram_size": 384 * 1024,  # 384K
        "text_start": 0x1000000,
        "has_local_dmem": True,
        "local_dmem_base": 0x50800000,
        "local_dmem_size": 64 * 1024,  # 64K
    },
    "mpc5744p": {
        "flash_base": 0x1000000,
        "flash_size": 1024 * 1024,  # 1024K
        "flash_rchw": {"org": 0x00FA0000, "len": 0x4},
        "cpu0_reset_vec": {"org": 0x00FA0004, "len": 0x4},
        "ram_base": 0x40000000,
        "ram_size": 426 * 1024,  # 426K
        "text_start": 0x1000000,
        "has_local_dmem": True,
        "local_dmem_base": 0x50800000,
        "local_dmem_size": 64 * 1024,  # 64K
    },
    "mpc5775k": {
        "flash_base": 0x1000000,
        "flash_size": 2048 * 1024,  # 2048K
        "flash_rchw": {"org": 0x00FA0000, "len": 0x4},
        "cpu0_reset_vec": {"org": 0x00FA0004, "len": 0x4},
        "ram_base": 0x40000000,
        "ram_size": 384 * 1024,  # 384K
        "text_start": 0x1000000,
        "has_local_dmem": True,
        "local_dmem_base": 0x50800000,
        "local_dmem_size": 64 * 1024,  # 64K
    },
}


def format_size(size: int) -> str:
    """Format size as K/M suffix or hex."""
    if size % (1024 * 1024) == 0:
        return f"{size // (1024 * 1024)}M"
    elif size % 1024 == 0:
        return f"{size // 1024}K"
    else:
        return hex(size)


def format_addr(addr: int) -> str:
    """Format address as hex."""
    return hex(addr)


def generate_linker_script(
    mcu: str,
    heap_size: int = 0,
    stack_size: int = 4096,
    mixed_vle_booke: bool = False,
    custom_flash_base: Optional[int] = None,
    custom_flash_size: Optional[int] = None,
    custom_ram_base: Optional[int] = None,
    custom_ram_size: Optional[int] = None,
) -> str:
    """Generate a linker script for the specified MCU configuration."""
    
    if mcu.lower() not in MCU_CONFIGS:
        raise ValueError(f"Unknown MCU: {mcu}. Supported: {list(MCU_CONFIGS.keys())}")
    
    config = MCU_CONFIGS[mcu.lower()].copy()
    
    # Override with custom values if provided
    if custom_flash_base is not None:
        config["flash_base"] = custom_flash_base
    if custom_flash_size is not None:
        config["flash_size"] = custom_flash_size
    if custom_ram_base is not None:
        config["ram_base"] = custom_ram_base
    if custom_ram_size is not None:
        config["ram_size"] = custom_ram_size
    
    lines = []
    
    # Header
    lines.append("/* Entry Point */")
    lines.append("ENTRY(_start)")
    lines.append("")
    
    # Heap and stack sizes
    lines.append("/* define heap and stack size */")
    lines.append(f"__HEAP_SIZE            = {heap_size} ;")
    lines.append(f"__STACK_SIZE           = {stack_size} ;")
    lines.append("")
    
    # SRAM configuration
    lines.append(f"SRAM_SIZE =  {format_size(config['ram_size'])};")
    lines.append(f"/* Define SRAM Base Address */")
    lines.append(f"SRAM_BASE_ADDR = {format_addr(config['ram_base'])};")
    
    if config.get("has_local_dmem"):
        lines.append("")
        lines.append("/* Define CPU0 Local Data SRAM Allocation */")
        lines.append(f"LOCALDMEM_SIZE = {format_size(config['local_dmem_size'])};")
        lines.append("/* Define CPU0 Local Data SRAM Base Address */")
        lines.append(f"LOCALDMEM_BASE_ADDR = {format_addr(config['local_dmem_base'])};")
    
    lines.append("")
    lines.append("MEMORY")
    lines.append("{")
    lines.append("")
    
    # Flash regions
    if "flash_rchw" in config:
        rchw = config["flash_rchw"]
        lines.append(f"    flash_rchw : org = {format_addr(rchw['org'])},   len = {format_addr(rchw['len'])}")
    
    if "cpu0_reset_vec" in config:
        reset_vec = config["cpu0_reset_vec"]
        lines.append(f"    cpu0_reset_vec : org = {format_addr(reset_vec['org'])},   len = {format_addr(reset_vec['len'])}")
    
    # Text region
    text_start = config.get("text_start", config["flash_base"])
    if mixed_vle_booke:
        text_len = config["flash_size"] - (text_start - config["flash_base"])
        text_e_start = 0x100000  # Separate region for BookE
        text_e_len = 512 * 1024
        lines.append(f"    m_text :\torg = {format_addr(text_start)}, len = {format_size(text_len)}")
        lines.append(f"    text_e :\torg = {format_addr(text_e_start)}, len = {format_size(text_e_len)}")
    else:
        text_len = config["flash_size"] - (text_start - config["flash_base"])
        lines.append(f"    m_text :\torg = {format_addr(text_start)}, len = {format_size(text_len)}")
    
    # Data region
    lines.append(f"    m_data :\torg = {format_addr(config['ram_base'])},   len = {format_size(config['ram_size'])}")
    
    # Local DMEM if present
    if config.get("has_local_dmem"):
        lines.append(f"    local_dmem  : org = {format_addr(config['local_dmem_base'])},   len = {format_size(config['local_dmem_size'])}")
    
    lines.append("}")
    lines.append("")
    lines.append("")
    
    # SECTIONS
    lines.append("SECTIONS")
    lines.append("{")
    
    # RCHW section
    if "flash_rchw" in config:
        lines.append("    .rchw   :")
        lines.append("    {")
        lines.append("        KEEP(*(.rchw))")
        lines.append("    } > flash_rchw")
        lines.append("")
    
    # CPU0 reset vector
    if "cpu0_reset_vec" in config:
        lines.append("    .cpu0_reset_vector  :")
        lines.append("    {")
        lines.append("        KEEP(*(.cpu0_reset_vector))")
        lines.append("    } > cpu0_reset_vec")
        lines.append("")
    
    # Startup section
    lines.append("    .startup : ALIGN(0x400)")
    lines.append("    {")
    lines.append("    __start = . ;")
    lines.append("    	*(.startup)")
    lines.append("    } > m_text")
    lines.append("")
    
    # Optional SPT section (for some MCUs)
    if mcu.lower() in ["mpc5775k"]:
        lines.append("    /* SPT commands */")
        lines.append("    .spt : ALIGN(0x10)")
        lines.append("    {")
        lines.append("        *(.spt)")
        lines.append("    } > m_text")
        lines.append("")
    
    # Core exceptions table
    align = 0x1000 if config.get("has_local_dmem") else 0x1000
    lines.append(f"    .core_exceptions_table   : ALIGN({hex(align)})")
    lines.append("    {")
    lines.append("      __IVPR_VALUE = . ;")
    lines.append("      KEEP(*(.core_exceptions_table))")
    lines.append("    } > m_text")
    lines.append("")
    
    # INTC vector table
    lines.append(f"    .intc_vector_table   : ALIGN({hex(align)})")
    lines.append("    {")
    lines.append("      KEEP(*(.intc_vector_table))")
    lines.append("    } > m_text")
    
    if mixed_vle_booke:
        lines.append("")
        lines.append("    .text_booke :")
        lines.append("    {")
        lines.append("      INPUT_SECTION_FLAGS (!SHF_PPC_VLE)")
        lines.append("      *(.text*)")
        lines.append("    } > text_e")
        lines.append("")
        lines.append("    .text_vle :")
        lines.append("    { INPUT_SECTION_FLAGS (SHF_PPC_VLE)")
        lines.append("      *(.text.startup)")
        lines.append("      *(.text)")
        lines.append("      *(.text.*)")
        lines.append("      KEEP (*(.init))")
        lines.append("      KEEP (*(.fini))")
        lines.append("      . = ALIGN(16);")
        lines.append("    } > m_text       /* that will force pick VLE .text sections */")
    else:
        lines.append("")
        lines.append("    .text :")
        lines.append("    {")
        lines.append("      *(.text.startup)")
        lines.append("      *(.text)")
        lines.append("      *(.text.*)")
        lines.append("      KEEP (*(.init))")
        lines.append("      KEEP (*(.fini))")
        lines.append("      . = ALIGN(16);")
        lines.append("    } > m_text")
    
    # Standard C++ and runtime sections
    lines.extend([
        "",
        "    .ctors :",
        "    {",
        "      __CTOR_LIST__ = .;",
        "      /* gcc uses crtbegin.o to find the start of",
        "         the constructors, so we make sure it is",
        "         first.  Because this is a wildcard, it",
        "         doesn't matter if the user does not",
        "         actually link against crtbegin.o; the",
        "         linker won't look for a file to match a",
        "         wildcard.  The wildcard also means that it",
        "         doesn't matter which directory crtbegin.o",
        "         is in.  */",
        "      KEEP (*crtbegin.o(.ctors))",
        "      KEEP (*crtbegin?.o(.ctors))",
        "      /* We don't want to include the .ctor section from",
        "         from the crtend.o file until after the sorted ctors.",
        "         The .ctor section from the crtend file contains the",
        "         end of ctors marker and it must be last */",
        "      KEEP (*(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors))",
        "      KEEP (*(SORT(.ctors.*)))",
        "      KEEP (*(.ctors))",
        "      __CTOR_END__ = .;",
        "    } > m_text",
        "",
        "    .dtors :",
        "    {",
        "      __DTOR_LIST__ = .;",
        "      KEEP (*crtbegin.o(.dtors))",
        "      KEEP (*crtbegin?.o(.dtors))",
        "      KEEP (*(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors))",
        "      KEEP (*(SORT(.dtors.*)))",
        "      KEEP (*(.dtors))",
        "      __DTOR_END__ = .;",
        "    } > m_text",
        "",
        "    .preinit_array :",
        "    {",
        "      PROVIDE_HIDDEN (__preinit_array_start = .);",
        "      KEEP (*(.preinit_array*))",
        "      PROVIDE_HIDDEN (__preinit_array_end = .);",
        "    } > m_text",
        "",
        "    .init_array :",
        "    {",
        "      PROVIDE_HIDDEN (__init_array_start = .);",
        "      KEEP (*(SORT(.init_array.*)))",
        "      KEEP (*(.init_array*))",
        "      PROVIDE_HIDDEN (__init_array_end = .);",
        "    } > m_text",
        "",
        "    .fini_array :",
        "    {",
        "      PROVIDE_HIDDEN (__fini_array_start = .);",
        "      KEEP (*(SORT(.fini_array.*)))",
        "      KEEP (*(.fini_array*))",
        "      PROVIDE_HIDDEN (__fini_array_end = .);",
        "    } > m_text",
        "",
        "    .rodata :",
        "    {",
        "      *(.rodata)",
        "      *(.rodata.*)",
    ])
    
    if mcu.lower() in ["mpc5775k"]:
        lines.append("	  *(.got1)")
    
    lines.extend([
        "    } > m_text",
        "",
        "    .eh_frame_hdr : { *(.eh_frame_hdr) } > m_text",
        "    .eh_frame     : { KEEP (*(.eh_frame)) } > m_text",
        "",
        "	.data   :",
        "	{",
        "	  *(.data)",
        "	  *(.data.*)",
    ])
    
    if mcu.lower() in ["mpc5775k"]:
        lines.extend([
            "	  *(.got.plt)",
            "	  *(.got)",
            "	  *(.got2)",
            "	  *(.dynamic)",
            "	  *(.fixup)",
            "	  . = ALIGN(4);"
        ])
    
    lines.extend([
        "	}  > m_data AT>m_text",
        "",
        "    .sdata2  :",
        "	{",
        "	  *(.sdata2)",
        "	  *(.sdata2.*)",
        "	} > m_data AT>m_text",
        "",
        "	.sbss2    (NOLOAD)   :",
        "	{",
        "      /* _SDA2_BASE_ = .; */",
        "	  *(.sbss2)",
        "	  *(.sbss2.*)",
        "	} > m_data",
        "",
        "    .sdata  :",
        "	{",
        "	  *(.sdata)",
        "	  *(.sdata.*)",
        "	} > m_data AT>m_text",
        "",
        "	.bss   (NOLOAD)  :",
        "	{",
        "	  __BSS_START = .;",
        "	  *(.sbss)",
        "	  *(.sbss.*)",
        "      *(.bss)",
        "      *(.bss.*)",
        "      *(COMMON)",
        "      __BSS_END = .;",
        "    } > m_data",
        "",
        "    .stack (NOLOAD) : ALIGN(16)",
        "    {",
        "      __HEAP = . ;",
        "      PROVIDE (_end = . );",
        "      PROVIDE (end = . );",
        "      . += __HEAP_SIZE ;",
        "      __HEAP_END = . ;",
        "      _stack_end = . ;",
        "      . +=  __STACK_SIZE ;",
        "      _stack_addr = . ;",
        "      _stack_top = . ;",
        "      __SP_INIT = . ;",
    ])
    
    # Stack placement (local_dmem or m_data)
    if config.get("has_local_dmem"):
        lines.append("      . += 4;")
        lines.append("    } > local_dmem")
    else:
        lines.append("      . += 4;")
        lines.append("    } > m_data")
    
    lines.append("")
    lines.append("/*-------- LABELS USED IN CODE -------------------------------*/")
    lines.append("")
    lines.append("/* Labels for Copying Initialised Data from Flash to RAM */")
    lines.append("__DATA_SRAM_ADDR  = ADDR(.data);")
    lines.append("__SDATA_SRAM_ADDR = ADDR(.sdata);")
    lines.append("")
    lines.append("/* Aliases for crt0 compatibility */")
    lines.append("__data_start__ = __DATA_SRAM_ADDR;")
    lines.append("__data_end__  = __DATA_SRAM_ADDR + SIZEOF(.data);")
    lines.append("__data_load__ = LOADADDR(.data);")
    lines.append("__bss_start__ = __BSS_START;")
    lines.append("__bss_end__   = __BSS_END;")
    lines.append("")
    lines.append("__DATA_SIZE   = SIZEOF(.data);")
    lines.append("__SDATA_SIZE  = SIZEOF(.sdata);")
    lines.append("")
    lines.append("__DATA_ROM_ADDR  = LOADADDR(.data);")
    lines.append("__SDATA_ROM_ADDR = LOADADDR(.sdata);")
    lines.append("")
    lines.append("/* Labels Used for Initialising SRAM ECC */")
    lines.append("__SRAM_SIZE = SRAM_SIZE;")
    lines.append("__SRAM_BASE_ADDR = SRAM_BASE_ADDR;")
    
    if config.get("has_local_dmem"):
        lines.append("")
        lines.append("__LOCAL_DMEM_SIZE = LOCALDMEM_SIZE;")
        lines.append("__LOCAL_DMEM_BASE_ADDR = LOCALDMEM_BASE_ADDR;")
    
    lines.append("")
    lines.append("__BSS_SIZE    = __BSS_END - __BSS_START;")
    
    if mixed_vle_booke:
        lines.append("")
        lines.append("__SIZE_BOOKE_SECTION = SIZEOF(.text_booke);")
        lines.append("__START_BOOKE_SECTION = ADDR(.text_booke);")
    
    lines.append("")
    lines.append("}")
    lines.append("")
    
    return "\n".join(lines)


def main():
    parser = argparse.ArgumentParser(
        description="Generate PowerPC embedded linker scripts",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  # Generate for MPC5748G
  %(prog)s --mcu mpc5748g -o linker.ld
  
  # Generate with custom heap/stack sizes
  %(prog)s --mcu mpc5643l --heap-size 1024 --stack-size 8192 -o linker.ld
  
  # Generate for mixed VLE/BookE mode
  %(prog)s --mcu mpc5643l --mixed-vle-booke -o linker.ld
  
  # Generate with custom memory layout
  %(prog)s --mcu mpc5748g --flash-base 0x1000000 --flash-size 2048K \\
           --ram-base 0x40000000 --ram-size 384K -o linker.ld
        """
    )
    
    parser.add_argument(
        "--mcu",
        required=True,
        choices=list(MCU_CONFIGS.keys()),
        help="MCU model (e.g., mpc5748g, mpc5643l)",
    )
    
    parser.add_argument(
        "-o", "--output",
        required=True,
        help="Output linker script file",
    )
    
    parser.add_argument(
        "--heap-size",
        type=int,
        default=0,
        help="Heap size in bytes (default: 0)",
    )
    
    parser.add_argument(
        "--stack-size",
        type=int,
        default=4096,
        help="Stack size in bytes (default: 4096)",
    )
    
    parser.add_argument(
        "--mixed-vle-booke",
        action="store_true",
        help="Enable mixed VLE/BookE mode (separate text sections)",
    )
    
    parser.add_argument(
        "--flash-base",
        type=lambda x: int(x, 0),  # Support hex (0x...) and decimal
        help="Custom flash base address (hex or decimal)",
    )
    
    parser.add_argument(
        "--flash-size",
        type=lambda x: int(x.replace("K", "*1024").replace("M", "*1024*1024") if any(c in x for c in "KM") else x, 0),
        help="Custom flash size (supports K/M suffix or bytes)",
    )
    
    parser.add_argument(
        "--ram-base",
        type=lambda x: int(x, 0),
        help="Custom RAM base address (hex or decimal)",
    )
    
    parser.add_argument(
        "--ram-size",
        type=lambda x: int(x.replace("K", "*1024").replace("M", "*1024*1024") if any(c in x for c in "KM") else x, 0),
        help="Custom RAM size (supports K/M suffix or bytes)",
    )
    
    args = parser.parse_args()
    
    try:
        script = generate_linker_script(
            mcu=args.mcu,
            heap_size=args.heap_size,
            stack_size=args.stack_size,
            mixed_vle_booke=args.mixed_vle_booke,
            custom_flash_base=args.flash_base,
            custom_flash_size=args.flash_size,
            custom_ram_base=args.ram_base,
            custom_ram_size=args.ram_size,
        )
        
        with open(args.output, "w") as f:
            f.write(script)
        
        print(f"Generated linker script: {args.output}", file=sys.stderr)
        
    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)


if __name__ == "__main__":
    main()

