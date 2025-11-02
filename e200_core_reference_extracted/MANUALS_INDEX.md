# Reference Manuals Index

Quick reference for all extracted manuals and their purposes.

## Core Reference Manuals (CRMs)

Detailed processor core documentation for each e200 variant:

| Variant | Chapters | Primary Use |
|---------|----------|-------------|
| z0      | 9        | Basic e200 core, minimal features |
| z1      | 9        | Enhanced e200 core |
| z3      | 10       | e200z3 with additional features |
| z4      | 11       | e200z4 with SPE/EFPU support |
| z759    | 15       | Latest z7 variant (separate SPE/EFPU) |
| z760    | 14       | z7 variant (SPE includes EFPU) |

**Key Chapters (all CRMs)**:
- Chapter 2: Register Model
- Chapter 3: Instruction Model  
- Chapter 4: Microarchitecture (instruction timing, pairing rules)
- Chapter 5: Embedded Floating-Point (EFPU/EFPU2)
- Chapter 6: Signal Processing Extension (SPE)

## Architecture Manuals

High-level architecture specifications:

### book_e
- **Book E: Enhanced PowerPC Architecture User's Manual**
- 12 chapters
- Base architecture specification
- Instruction set definitions
- Register model

### erefrm
- **e200 Reference Manual**
- 10 chapters
- Common e200 family specifications
- Shared across all e200 variants

### powerisa_v2_07
- **Power ISA Version 2.07 Public Specification**
- 12 chapters
- Complete Power ISA specification
- Instruction formats and encoding
- Register definitions

## VLE Manuals

Variable Length Encoding documentation:

### vlepem
- **VLE Programming Environment Manual**
- 3 chapters
- VLE instruction encoding
- Programming model
- Instruction formats

### vlepim
- **VLE Programming Interface Manual**
- 3 chapters
- VLE API and interfaces
- Development tools
- Compiler integration

## Quick Lookups

### Find instruction timing:
```bash
grep -i "Table.*4-3\|instruction.*timing" */Chapter_04.txt
```

### Find register definitions:
```bash
grep -i "register\|MSR\|SPR" */Chapter_02.txt
```

### Find instruction formats:
```bash
grep -i "format\|encoding" powerisa_v2_07/Chapter_*.txt
grep -i "format\|encoding" vlepem/Chapter_*.txt
```

### Compare variants:
```bash
diff z759/Chapter_05.txt z760/Chapter_05.txt  # EFPU differences
diff z4/Chapter_04.txt z7*/Chapter_04.txt      # Timing differences
```

## File Organization

Each manual directory contains:
- `00_Full_Manual.txt` - Complete manual (backup)
- `00_Overview.txt` - First 100 lines (overview)
- `Chapter_XX.txt` - Individual chapters

