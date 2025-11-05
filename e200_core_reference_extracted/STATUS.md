# Extraction Status

✅ **ALL Reference Manuals Extracted**

## Extracted Manuals

| Manual | Description | Chapters | Status |
|--------|-------------|----------|--------|
| **Core Reference Manuals (CRMs)** ||||
| z0      | e200z0 Core Reference Manual | 9        | ✅ Complete |
| z1      | e200z1 Core Reference Manual | 9        | ✅ Complete |
| z3      | e200z3 Core Reference Manual | 10       | ✅ Complete |
| z4      | e200z4 Core Reference Manual | 11       | ✅ Complete |
| z759    | e200z759n3 Core Reference Manual | 15       | ✅ Complete |
| z760    | e200z760n3 Core Reference Manual | 14       | ✅ Complete |
| **Architecture Manuals** ||||
| book_e  | Book E: Enhanced PowerPC Architecture User's Manual | 12       | ✅ Complete |
| erefrm  | e200 Reference Manual (EREFRM) | 10       | ✅ Complete |
| powerisa_v2_07 | Power ISA Version 2.07 Public | 12       | ✅ Complete |
| **VLE Manuals** ||||
| vlepem  | VLE Programming Environment Manual | 3        | ✅ Complete |
| vlepim  | VLE Programming Interface Manual | 3        | ✅ Complete |

## Total Statistics

- **11 manuals** extracted
- **97+ total chapters** across all manuals
- All chapters organized by manual and chapter number
- Full manual backups available in `00_Full_Manual.txt` for each manual

## Manual Descriptions

### Core Reference Manuals (CRMs)
- **z0, z1, z3, z4, z759, z760**: Detailed processor core documentation
  - Microarchitecture (Chapter 4)
  - Register Model (Chapter 2)
  - Instruction Model (Chapter 3)
  - EFPU/SPE (Chapters 5-6)
  - Instruction Reference (Last chapter)

### Architecture Manuals
- **book_e**: Book E Enhanced PowerPC Architecture specification
- **erefrm**: e200 family reference manual with common specifications
- **powerisa_v2_07**: Power ISA Version 2.07 specification

### VLE Manuals
- **vlepem**: VLE Programming Environment Manual
- **vlepim**: VLE Programming Interface Manual

## Quick Access

```bash
# Find microarchitecture info across all CRMs
grep -i "load latency\|3 cycle" */Chapter_04.txt

# Compare instruction timing across variants
diff e200_core_reference_extracted/z4/Chapter_04.txt \
     e200_core_reference_extracted/z7*/Chapter_04.txt

# Find SPE/EFPU definitions
grep -l "SPE\|EFPU" */Chapter_0[56].txt

# Search Power ISA specification
grep -i "instruction.*format" powerisa_v2_07/Chapter_*.txt

# Find VLE encoding details
grep -i "encoding\|format" vlepem/Chapter_*.txt vlepim/Chapter_*.txt
```

## Notes

- Some chapters may have duplicates from table of contents - use larger files for actual content
- Formatting may vary from original PDF
- Page numbers are not preserved in chapter splits
- Each manual has its own directory for easy comparison
