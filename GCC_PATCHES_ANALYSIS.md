# GCC Tooling Patches Analysis for ELe200 Cores

## Executive Summary

This document analyzes the GCC tooling patches applied for ELe200 cores (PowerPC VLE architecture) and compares them against the current LLVM implementation to identify missing features.

## Patch Files Analyzed

### Binutils Patches
- `bin.2-28-vle-binutils` - VLE binutils support
- `bin.2-28-vle-common` - VLE common support (BFD, opcodes)

### GCC Patches
- `gcc.vle_494` - VLE support for GCC 4.9.4
- `gcc.vle_LSP_49x` - LSP (Low Signal Processing) instruction support
- `gcc.vle_spe2` - SPE2 instruction support

## Key Features Added by GCC Patches

### 1. Missing Relocations

#### R_PPC_VLE_ADDR20 (Relocation Type 233)
**Status: ❌ MISSING in LLVM**

This relocation is used for the `e_li` split20 format, which encodes a 20-bit immediate value across non-contiguous instruction fields:
- Bits 17-20: Top 4 bits of value
- Bits 11-15: Next 5 bits of value  
- Bits 21-31: Final 11 bits of value

**GCC Patch Implementation:**
```c
HOWTO (R_PPC_VLE_ADDR20,	/* type */
       16,			/* rightshift */
       2,			/* size (0 = byte, 1 = short, 2 = long) */
       20,			/* bitsize */
       FALSE,			/* pc_relative */
       0,			/* bitpos */
       complain_overflow_dont, /* complain_on_overflow */
       bfd_elf_generic_reloc,	/* special_function */
       "R_PPC_VLE_ADDR20",	/* name */
       FALSE,			/* partial_inplace */
       0,			/* src_mask */
       0x1f07ff,		/* dst_mask */
       FALSE),			/* pcrel_offset */

static void
ppc_elf_vle_split20 (bfd *output_bfd, bfd_byte *loc, bfd_vma value)
{
  unsigned int insn;
  
  insn = bfd_get_32 (output_bfd, loc);
  /* We have an li20 field, bits 17..20, 11..15, 21..31.  */
  /* Top 4 bits of value to 17..20.  */
  insn |= (value & 0xf0000) >> 5;
  /* Next 5 bits of the value to 11..15.  */
  insn |= (value & 0xf800) << 5;
  /* And the final 11 bits of the value to bits 21 to 31.  */
  insn |= value & 0x7ff;
  bfd_put_32 (output_bfd, insn, loc);
}
```

**LLVM Status:** This relocation type is NOT defined in `llvm/include/llvm/BinaryFormat/ELFRelocs/PowerPC.def`

#### R_PPC_VLE_RELAX (Relocation Type 51)
**Status: ❌ MISSING in LLVM**

This relocation is used internally by the linker for VLE branch relaxation. It indicates that a stub entry should be inserted at this location.

**GCC Patch Implementation:**
- Added `R_PPC_VLE_RELAX` to relocation enum
- Handled in `ppc_elf_relax_section` for branch distance overflow
- Used to mark locations where VLE stub entries are needed

**LLVM Status:** This relocation type is NOT defined in LLVM relocation definitions.

### 2. VLE Stub Entry Support

**Status: ❌ MISSING in LLVM**

The GCC patches add VLE-specific stub entries that differ from regular PowerPC stubs:

**GCC Patch Implementation:**
```c
typedef enum ppc_target_stub_entry_type
  {
    stub_entry_type_ppc = 0,
    stub_entry_type_vle
  }
ppc_target_stub_entry_type;

/* Keep the same size as stub_entry */
static const int stub_entry_vle[] =
  {
    0x7180e000, /* e_lis 12,xxx@ha */
    0x1d8c0000, /* e_add16i 12,12,xxx@l */
    0x7d8903a6, /* mtctr 12 */
    0x00064400, /* se_bctr, se_nop (size padding) */
  };
```

**Key Differences:**
- Uses `e_lis` instead of `lis` (VLE-encoded)
- Uses `e_add16i` instead of `addi` (VLE-encoded)
- Final instruction is `se_bctr` (16-bit VLE branch) with padding

**LLVM Status:** No VLE-specific stub entries found in LLVM linker implementation.

### 3. VLE Section Flags

**Status: ⚠️ PARTIALLY IMPLEMENTED**

**GCC Patch Implementation:**
- `SHF_PPC_VLE` (0x10000000) - Section header flag
- `SEC_PPC_VLE` - BFD section flag (aliased to SEC_TIC54X_BLOCK)
- Section flag parsing and handling in `ppc_elf_section_flags`
- Support in objdump, readelf, and gas

**LLVM Status:**
- `SHF_PPC_VLE` is referenced in documentation and scripts
- Found in `clang/tools/generate-ppc-linker-script.py`
- Need to verify full linker support for setting/checking this flag

### 4. LSP (Low Signal Processing) Instructions

**Status: ❌ MISSING in LLVM**

The GCC patches add extensive LSP instruction support:
- `PPC_OPCODE_LSP` flag (0x8000000000000000ull)
- Hundreds of LSP instructions (zvaddih, zvsplatih, zvdotph*, etc.)
- LSP-specific operand encodings (EVUIMM_2_EX0, EVUIMM_4_EX0, etc.)
- Even register constraints (RD_EVEN, RS_EVEN)
- Complete MD file with 6714+ lines defining LSP instruction patterns

**GCC Patch Implementation:**
- Added to opcodes table with `PPCLSP` flag
- Instructions like: `zvaddih`, `zvsplatih`, `zvdotphgwasmf`, `zbrminc`, `zcircinc`, etc.
- Special operand insertion functions for LSP-specific fields
- Full instruction pattern definitions in `gcc/config/rs6000/lsp.md`

**LLVM Status:**
- ❌ No LSP instruction definitions found in `PPCInstrVLE.td`
- ❌ No LSP-specific opcode flag found
- ❌ LSP instructions are NOT implemented in LLVM

### 5. VLE Split16 Fix

**Status: ❓ NEEDS VERIFICATION**

**GCC Patch Implementation:**
```c
// Changed opcode mask from 0xf300f800 to 0xfc00f800
opcode = insn & 0xfc00f800;  // Was: 0xf300f800
```

This expands the opcode recognition mask for split16 relocations.

**LLVM Status:** Need to check if this mask is used/correct in LLVM relocation handling.

### 6. SPE2 Instruction Support

**Status: ⚠️ PARTIALLY IMPLEMENTED**

The GCC patches add SPE2 builtin support with macros:
- `BU_SPE2_1`, `BU_SPE2_2`, `BU_SPE2_3`
- `BU_SPE2_E` (EVSEL), `BU_SPE2_P` (predicate)
- Hundreds of SPE2 builtin definitions
- SPE2 target macros in `e200.h`

**LLVM Status:**
- ✅ SPE2 displacement operand support found (`dispSPE2`, `spe2dis`)
- ❌ SPE2 instruction definitions not verified - need to check `PPCInstrSPE.td`
- ❌ SPE2 builtin support not found

## Relocation Comparison

### Relocations in LLVM
✅ Present:
- `R_PPC_VLE_REL8` (253)
- `R_PPC_VLE_REL15` (254)
- `R_PPC_VLE_REL24` (255)
- `R_PPC_VLE_REL32` (256)
- `R_PPC_VLE_ADDR16_LO` (257)
- `R_PPC_VLE_ADDR16_HI` (258)
- `R_PPC_VLE_ADDR16_HA` (259)
- `R_PPC_VLE_ADDR24` (260)
- `R_PPC_VLE_ADDR32` (261)
- `R_PPC_VLE_SDAREL_LO` (262)
- `R_PPC_VLE_SDAREL_HI` (263)
- `R_PPC_VLE_SDAREL_HA` (264)
- `R_PPC_VLE_SDAREL_OFF_LO` (265)
- `R_PPC_VLE_SDAREL_OFF_HI` (266)
- `R_PPC_VLE_SDAREL_OFF_HA` (267)

### Relocations Missing in LLVM
❌ Missing:
- `R_PPC_VLE_ADDR20` (233) - For e_li split20 format
- `R_PPC_VLE_RELAX` (51) - Internal relocation for branch relaxation

### Additional Relocations in GCC Patches
The patches also reference:
- `R_PPC_VLE_LO16A`, `R_PPC_VLE_LO16D` - Split16 low variants
- `R_PPC_VLE_HI16A`, `R_PPC_VLE_HI16D` - Split16 high variants  
- `R_PPC_VLE_HA16A`, `R_PPC_VLE_HA16D` - Split16 high-adjusted variants
- `R_PPC_VLE_SDA21`, `R_PPC_VLE_SDA21_LO` - Small data area relocations

**Note:** These may be aliases or alternative names for the existing relocations, or may represent additional variants not currently in LLVM.

## Branch Relaxation Support

**GCC Patch Features:**
1. VLE-specific branch distance checks
2. Support for `R_PPC_VLE_REL24`, `R_PPC_VLE_REL15`, `R_PPC_VLE_REL8`
3. VLE stub entry insertion when branch distance exceeds limits
4. Proper relocation of VLE stubs using VLE-encoded instructions

**LLVM Status:** Need to verify if LLVM linker implements:
- Branch distance checking for VLE relocations
- Stub insertion for VLE branches
- VLE-encoded stub sequences

## Recommendations

### Critical Missing Features (Must Implement)
1. **R_PPC_VLE_ADDR20 relocation** - Required for 20-bit immediate encoding in `e_li`
2. **R_PPC_VLE_RELAX relocation** - Required for branch relaxation
3. **VLE stub entries** - Required for long-distance branches in VLE code

### Important Missing Features (Should Implement)
4. **LSP instruction support** - If targeting cores with LSP capability
5. **SPE2 instruction support** - If targeting cores with SPE2 capability
6. **Full SHF_PPC_VLE section flag support** - For proper section handling

### Verification Needed
7. **VLE split16 opcode mask** - Verify correct mask (0xfc00f800)
8. **VLE relocation handling** - Ensure all split16 variants are properly handled
9. **Section flag propagation** - Verify VLE sections are correctly marked

## Next Steps

1. Verify LSP instruction definitions in LLVM
2. Check SPE2 instruction support
3. Test VLE branch relaxation in LLVM linker
4. Implement missing relocations
5. Add VLE stub entry support
6. Complete section flag support

