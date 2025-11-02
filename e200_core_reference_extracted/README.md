# e200z7 Manual Chapters Extracted

This directory contains chapter-by-chapter extractions from the e200z7 reference manuals.

## Directory Structure

All reference manuals have been extracted chapter-by-chapter:

```
e200_core_reference_extracted/
├── Core Reference Manuals (CRMs)
│   ├── z0/                      # e200z0 manual chapters (9 chapters)
│   ├── z1/                      # e200z1 manual chapters (9 chapters)
│   ├── z3/                      # e200z3 manual chapters (10 chapters)
│   ├── z4/                      # e200z4 manual chapters (11 chapters)
│   ├── z759/                    # e200z759n3 manual chapters (15 chapters)
│   └── z760/                    # e200z760n3 manual chapters (14 chapters)
├── Architecture Manuals
│   ├── book_e/                  # Book E Enhanced PowerPC Architecture (12 chapters)
│   ├── erefrm/                  # e200 Reference Manual (10 chapters)
│   └── powerisa_v2_07/          # Power ISA Version 2.07 (12 chapters)
└── VLE Manuals
    ├── vlepem/                  # VLE Programming Environment Manual (3 chapters)
    └── vlepim/                  # VLE Programming Interface Manual (3 chapters)
```

Each variant directory contains:
- `00_Full_Manual.txt` - Complete manual text (backup)
- `00_Overview.txt` - First 100 lines (overview)
- `Chapter_01.txt` through `Chapter_XX.txt` - Individual chapters

### Typical Chapter Structure (varies by variant):

- **Chapter 1**: Overview/Introduction
- **Chapter 2**: Register Model
- **Chapter 3**: Instruction Model
- **Chapter 4**: Microarchitecture (critical for scheduling models)
- **Chapter 5**: Embedded Floating-Point (EFPU/EFPU2)
- **Chapter 6**: Signal Processing Extension (SPE)
- **Chapter 7**: Interrupts and Exceptions
- **Chapter 8+**: Additional topics (Performance Monitor, Cache, MMU, etc.)
- **Last Chapter**: Instruction Reference (usually largest)

## Key Differences Between Variants

### z759n3 (e200z759)
- **Chapter 5**: EFPU2 (Embedded Floating-Point APU version 2)
  - Handles **all floating-point operations** (scalar and SIMD)
- **Chapter 6**: SPE1.1 (Signal Processing Extension APU version 1.1)
  - Handles **only fixed-point operations** (no floating-point)
- EFPU2 and SPE1.1 are **separate, independent** capabilities

### z760n3 (e200z760)
- **Chapter 5**: EFPU (Embedded Floating-Point Unit)
  - Scalar single-precision floating-point operations
- **Chapter 6**: SPE (Signal Processing Extension)
  - SIMD fixed-point **and** single-precision floating-point operations
- Manual states: **"The EFPU is a subset of the SPE"**
- SPE includes floating-point; EFPU is the scalar floating-point subset

## Usage

### Search for specific information:

```bash
# Search for "load latency" in z760 microarchitecture chapter
grep -i "load latency" z760/Chapter_04.txt

# Compare SPE features between variants
diff -u z759/Chapter_06.txt z760/Chapter_06.txt | head -50

# Find instruction timing tables
grep -A 20 "instruction.*timing\|Table.*timing" z760/Chapter_04.txt
```

### Chapter-Specific Lookups:

- **Microarchitecture & Timing**: `Chapter_04.txt` (both variants)
- **Floating-Point Operations**: `Chapter_05.txt` (both variants)
- **Signal Processing**: `Chapter_06.txt` (both variants)
- **Instruction Reference**: `Chapter_12.txt` (z759), varies by variant
- **Interrupts**: `Chapter_07.txt` (both variants)

## Extraction Script

All chapters were extracted using `scripts/extract_manual_chapters.py`:

```bash
# Core Reference Manuals
python3 scripts/extract_manual_chapters.py e200_core_reference/powerpc-e200z0.pdf z0
python3 scripts/extract_manual_chapters.py e200_core_reference/powerpc-e200z1.pdf z1
python3 scripts/extract_manual_chapters.py e200_core_reference/powerpc-e200z3.pdf z3
python3 scripts/extract_manual_chapters.py e200_core_reference/powerpc-e200z4.pdf z4
python3 scripts/extract_manual_chapters.py e200_core_reference/powerpc-e200z759.pdf z759
python3 scripts/extract_manual_chapters.py e200_core_reference/powerpc-e200z760n3.pdf z760

# Architecture Manuals
python3 scripts/extract_manual_chapters.py e200_core_reference/BOOK_EUM.pdf book_e
python3 scripts/extract_manual_chapters.py e200_core_reference/EREFRM.pdf erefrm
python3 scripts/extract_manual_chapters.py e200_core_reference/PowerISA_V2.07_PUBLIC.pdf powerisa_v2_07

# VLE Manuals
python3 scripts/extract_manual_chapters.py e200_core_reference/VLEPEM.pdf vlepem
python3 scripts/extract_manual_chapters.py e200_core_reference/VLEPIM.pdf vlepim
```

**Status**: ✅ All 11 reference manuals extracted

## Notes

- Some chapters may have duplicates from table of contents - use the larger files for actual content
- Formatting may vary from original PDF
- Page numbers are not preserved in chapter splits
- Full manual text is available in `00_Full_Manual.txt` for complete context

