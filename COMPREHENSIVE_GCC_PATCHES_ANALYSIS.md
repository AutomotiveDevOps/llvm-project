# Comprehensive GCC Patches Re-Analysis for ELe200 Cores

**Date:** 2024
**Objective:** Ensure all features from GCC toolchain patches for ELe200 cores are implemented in LLVM/Clang, prioritized from reference materials (VLEPIM, ISA) rather than GCC implementation.

## Executive Summary

This analysis systematically reviews all GCC toolchain patches applied for ELe200 cores and compares them against:
1. Reference materials (VLEPIM Chapter 2, E200 core manuals)
2. Current LLVM/Clang implementation
3. End-to-end compilation requirements (source → .o → .elf → .bin/.hex)

**Key Finding:** Significant discrepancies exist between VLEPIM relocation numbering (216-232) and LLVM's implementation (253-267). Additionally, many VLEPIM-specified relocations are missing from LLVM, and some GCC-specific extensions exist that may need evaluation.

---

## Patch Inventory

### Binutils Patches (12 files)
- `bin.2-28-aeabi-binutils` - AEABI support
- `bin.2-28-aeabi-common` - AEABI common definitions
- `bin.2-28-booke2vle-binutils` - BookE to VLE translation
- `bin.2-28-efs2` - EFS2 support
- `bin.2-28-fix_wait` - Fix wait functionality
- `bin.2-28-plt` - PLT and VLE PLT support
- `bin.2-28-spe2-binutils` - SPE2 binutils support
- `bin.2-28-spe2-common` - SPE2 common definitions
- `bin.2-28-vle-binutils` - Core VLE binutils support
- `bin.2-28-vle-common` - VLE common definitions (BFD, opcodes)
- `bin.2-28-vleHyp` - VLE hypervisor support

### GCC Patches (50+ files)
**VLE Core:**
- `gcc.vle_494` - Core VLE support for GCC 4.9.4
- `gcc.vle_LSP_49x` - LSP (Low Signal Processing) instructions (6714+ lines)
- `gcc.vle_spe2` - SPE2 instruction support
- `gcc.vle_short_double` - Short double support
- `gcc.create_maeabi` - AEABI target creation
- `gcc.aeabi-49x` - AEABI support

**Optimizations and Fixes:**
- Multiple optimization and bugfix patches (40+ files)

### GDB Patches (7 files)
- `gdb.7-8-2-vle` - Core VLE debugger support
- `gdb.7-8-2-vle-aeabi` - VLE AEABI debugger support
- `gdb.7-8-2-vle-e200-sprs` - E200 SPR support
- `gdb.7-8-2-vle-fix-pr16084` - Bugfix
- `gdb.7-8-2-vle-opcodes-disasm` - VLE disassembly
- `gdb.7-8-2-vle-opcodes-lsp-spe2` - LSP/SPE2 disassembly

### Runtime Libraries
- glibc patches (30+ files) - Runtime library optimizations
- newlib patches (10+ files) - Embedded C library support

---

## Critical Analysis: Relocations

### Reference: VLEPIM Table 2-4

VLEPIM specifies relocation types 216-232 with the following definitions:

| Relocation | VLEPIM Value | Field | Calculation | LLVM Value | LLVM Status |
|------------|--------------|-------|-------------|------------|-------------|
| R_PPC_VLE_REL8 | 216 | bdh8 | (S + A - P) >> 1 | 253 | ✅ Present |
| R_PPC_VLE_REL15 | 217 | bdh15 | (S + A - P) >> 1 | 254 | ✅ Present |
| R_PPC_VLE_REL24 | 218 | bdh24 | (S + A - P) >> 1 | 255 | ✅ Present |
| R_PPC_VLE_LO16A | 219 | split16a | #lo(S + A) | **MISSING** | ❌ |
| R_PPC_VLE_LO16D | 220 | split16d | #lo(S + A) | **MISSING** | ❌ |
| R_PPC_VLE_HI16A | 221 | split16a | #hi(S + A) | **MISSING** | ❌ |
| R_PPC_VLE_HI16D | 222 | split16d | #hi(S + A) | **MISSING** | ❌ |
| R_PPC_VLE_HA16A | 223 | split16a | #ha(S + A) | **MISSING** | ❌ |
| R_PPC_VLE_HA16D | 224 | split16d | #ha(S + A) | **MISSING** | ❌ |
| R_PPC_VLE_SDA21 | 225 | low21/split20 | Y \|\| (X + A) | **MISSING** | ❌ |
| R_PPC_VLE_SDA21_LO | 226 | low21/split20 | Y \|\| #lo(X + A) | **MISSING** | ❌ |
| R_PPC_VLE_SDAREL_LO16A | 227 | split16a | #lo(X + A) | **MISSING** | ❌ |
| R_PPC_VLE_SDAREL_LO16D | 228 | split16d | #lo(X + A) | **MISSING** | ❌ |
| R_PPC_VLE_SDAREL_HI16A | 229 | split16a | #hi(X + A) | **MISSING** | ❌ |
| R_PPC_VLE_SDAREL_HI16D | 230 | split16d | #hi(X + A) | **MISSING** | ❌ |
| R_PPC_VLE_SDAREL_HA16A | 231 | split16a | #ha(X + A) | **MISSING** | ❌ |
| R_PPC_VLE_SDAREL_HA16D | 232 | split16d | #ha(X + A) | **MISSING** | ❌ |

### GCC Patch Extensions (Not in VLEPIM)

| Relocation | GCC Value | Purpose | LLVM Status |
|------------|-----------|---------|-------------|
| R_PPC_VLE_ADDR20 | 233 | e_li split20 format | ❌ **MISSING** |
| R_PPC_VLE_PLTREL24 | 53 | VLE PLT relative branch | ❌ **MISSING** |

### LLVM Implementation Discrepancies

**Value Assignment Mismatch:**
- VLEPIM specifies values 216-232 for VLE relocations
- LLVM uses values 253-267 (different numbering scheme)
- **Issue:** This may cause incompatibility with standard tooling expecting VLEPIM values

**Missing Relocations (Critical):**
1. **Split16 variants (LO16A/D, HI16A/D, HA16A/D)** - Required for VLE instruction encoding
   - LLVM has ADDR16_LO/HI/HA but not the split16a/split16d variants
   - **Impact:** Cannot properly encode split immediate fields in VLE instructions

2. **SDA21 relocations** - Required for small data area support
   - **Impact:** Cannot use small data area optimization for VLE code

3. **SDAREL split16 variants** - Required for SDA relative addressing
   - **Impact:** Missing SDA relative addressing modes

4. **R_PPC_VLE_ADDR20** - For e_li split20 encoding
   - GCC patch implements `ppc_elf_vle_split20()` function
   - **Impact:** Cannot encode 20-bit immediates in e_li instructions

5. **R_PPC_VLE_PLTREL24** - VLE-specific PLT relocation
   - **Impact:** PLT calls in VLE code may not work correctly

---

## Section and Program Header Flags

### SHF_PPC_VLE (0x10000000)

**VLEPIM Specification:**
- Section header flag marking sections containing VLE instructions
- Must be set for all sections with VLE code
- Linker must keep VLE sections separate from Book E sections

**GCC Patch Implementation:**
- Assembler: `.section` directive accepts 'v' flag (`ppc_elf_section_letter`)
- BFD: `SEC_PPC_VLE` flag (aliased to `SEC_TIC54X_BLOCK`)
- Linker: `ppc_elf_section_flags()` reads SHF_PPC_VLE from input
- `ppc_elf_fake_sections()` sets SHF_PPC_VLE in output
- objdump/readelf: Display 'V' flag for VLE sections

**LLVM Status:**
- ⚠️ **PARTIALLY IMPLEMENTED**
- Referenced in `clang/tools/generate-ppc-linker-script.py`
- **Missing:**
  - Assembler directive support for setting flag
  - LLVM MC section flag setting for VLE sections
  - Linker verification/validation of flag
  - Full propagation through toolchain

### PF_PPC_VLE (0x10000000)

**VLEPIM Specification:**
- Program header flag marking segments containing VLE code
- Must be set when segment contains VLE sections
- Error if PF_PPC_VLE set but sections don't have SHF_PPC_VLE

**GCC Patch Implementation:**
- Not explicitly found in patches (may be implicit)

**LLVM Status:**
- ❌ **NOT IMPLEMENTED**
- No program header flag handling found

---

## VLE Stub Entries

**Status:** ✅ **RECENTLY IMPLEMENTED**

The GCC patches define:
```c
static const int stub_entry_vle[] = {
    0x7180e000, /* e_lis 12,xxx@ha */
    0x1d8c0000, /* e_add16i 12,12,xxx@l */
    0x7d8903a6, /* mtctr 12 */
    0x00064400, /* se_bctr, se_nop (size padding) */
};
```

**LLVM Implementation:**
- `writeVLEStub()` implemented in `lld/ELF/Thunks.cpp`
- `VLEStub` class created
- Branch relaxation for VLE relocations (REL8, REL15, REL24)
- Uses `R_PPC_VLE_RELAX` internal relocation (51)

**Verification Needed:**
- Verify `e_lis` encoding matches VLEPIM split16a format exactly
- Test stub insertion for various branch distances

---

## Instruction Support

### LSP (Low Signal Processing) Instructions

**GCC Patch:** `gcc.vle_LSP_49x` (6714+ lines)

**Features Added:**
- `PPC_OPCODE_LSP` flag (0x8000000000000000ull)
- Hundreds of LSP instructions:
  - SIMD operations: `zvaddih`, `zvsplatih`, `zvdotph*`, etc.
  - Specialized operands: `EVUIMM_2_EX0`, `EVUIMM_4_EX0`, `EVUIMM_8_EX0`
  - Even register constraints: `RD_EVEN`, `RS_EVEN`
  - Complete opcodes table in `opcodes/ppc-opc.c`

**LLVM Status:**
- ❌ **NOT IMPLEMENTED**
- No LSP instruction definitions in `PPCInstrVLE.td`
- No LSP opcode flag
- **Reference:** Need to verify against E200 core reference manuals (z0-z4, z759, z760)

### SPE2 Instructions

**GCC Patch:** `gcc.vle_spe2`

**Features Added:**
- SPE2 builtin support (`BU_SPE2_1`, `BU_SPE2_2`, `BU_SPE2_3`)
- SPE2 target macros in `e200.h`
- SPE2 displacement operands

**LLVM Status:**
- ⚠️ **PARTIALLY IMPLEMENTED**
- SPE2 displacement operands found (`dispSPE2`, `spe2dis`)
- Need to verify SPE2 instruction definitions in `PPCInstrSPE.td`
- Builtin function support not verified

---

## Binary Output Formats

### ELF Generation
**Status:** ✅ **IMPLEMENTED** (via lld)

### Binary (.bin) Conversion
**Status:** ⚠️ **NEEDS VERIFICATION**
- `llvm-objcopy` supports `--output-target=binary`
- Need to verify:
  - Works with PowerPC VLE ELF files
  - Proper section extraction
  - Address handling for VLE sections

### Intel HEX (.hex) Conversion
**Status:** ⚠️ **NEEDS VERIFICATION**
- `llvm-objcopy` supports `--output-target=ihex`
- Need to verify:
  - Address records correct
  - Checksums valid
  - VLE section handling

### Raw Section Extraction
**Status:** ⚠️ **NEEDS VERIFICATION**
- Need to test extraction of .text sections as raw binary

---

## Split Immediate Encoding

### Split20 Format (for e_li)

**VLEPIM Specification:**
- 20-bit field: bits 17-20 (top 4), 11-15 (next 5), 21-31 (final 11)
- Bits 0-5 encoded as 011100, bit 16 as 0
- Used by `R_PPC_VLE_ADDR20` relocation

**GCC Implementation:**
```c
static void ppc_elf_vle_split20 (bfd *output_bfd, bfd_byte *loc, bfd_vma value)
{
  insn |= (value & 0xf0000) >> 5;  /* Top 4 bits to 17-20 */
  insn |= (value & 0xf800) << 5;   /* Next 5 bits to 11-15 */
  insn |= value & 0x7ff;            /* Final 11 bits to 21-31 */
}
```

**LLVM Status:**
- ❌ **NOT IMPLEMENTED**
- No `R_PPC_VLE_ADDR20` relocation
- No split20 encoding function

### Split16a Format

**VLEPIM Specification:**
- 16-bit field: bits 11-15 (top 5), 21-31 (bottom 11)
- Used by LO16A, HI16A, HA16A relocations

**GCC Implementation:**
- Opcode mask changed from `0xf300f800` to `0xfc00f800`
- Function: `ppc_elf_vle_split16()`

**LLVM Status:**
- ⚠️ **NEEDS VERIFICATION**
- Need to check if opcode mask is correct
- Need to verify split16a encoding in relocation handlers

### Split16d Format

**VLEPIM Specification:**
- 16-bit field: bits 6-10 (top 5), 21-31 (bottom 11)
- Used by LO16D, HI16D, HA16D relocations

**LLVM Status:**
- ❌ **NOT IMPLEMENTED** (if different from split16a)

---

## BookE to VLE Translation

**GCC Patch:** `bin.2-28-booke2vle-binutils`

**Features:**
- `--ppc_asm_to_vle` option in assembler
- Translation hash table for converting BookE instructions to VLE
- Function: `md_assemble_via_translation()`

**LLVM Status:**
- ❌ **NOT IMPLEMENTED**
- No automatic translation from BookE to VLE
- **Impact:** Users must manually write VLE assembly

---

## Implementation Priority

### Phase 1: Critical for Basic VLE ABI Compliance (HIGH PRIORITY)

1. **R_PPC_VLE_ADDR20 relocation** (Value 233)
   - Implement in `llvm/include/llvm/BinaryFormat/ELFRelocs/PowerPC.def`
   - Implement `ppc_elf_vle_split20()` equivalent in `lld/ELF/Arch/PPC.cpp`
   - Reference: GCC patch `bin.2-28-vle-common` lines 83-97

2. **Split16 relocation variants** (Values 219-224)
   - R_PPC_VLE_LO16A, LO16D, HI16A, HI16D, HA16A, HA16D
   - Required for proper VLE instruction encoding
   - Reference: VLEPIM Table 2-4

3. **Full SHF_PPC_VLE flag support**
   - Assembler directive support (`.section` with 'v' flag)
   - LLVM MC section flag setting
   - Linker propagation and validation

4. **Verify binary/hex output conversion**
   - Test `llvm-objcopy` with VLE ELF files
   - Ensure proper address handling

### Phase 2: Complete VLE ABI Compliance (MEDIUM PRIORITY)

5. **SDA relocations** (Values 225-232)
   - R_PPC_VLE_SDA21, SDA21_LO
   - SDAREL variants (LO16A/D, HI16A/D, HA16A/D)
   - May require linker SDA base computation

6. **R_PPC_VLE_PLTREL24** (Value 53)
   - VLE-specific PLT relocation
   - Reference: GCC patch `bin.2-28-plt`

7. **PF_PPC_VLE program header flag**
   - Linker support for setting program header flags

8. **Relocation value alignment**
   - Verify if LLVM's values (253-267) vs VLEPIM (216-232) are intentional
   - Document rationale or align with VLEPIM

### Phase 3: Extended Features (LOWER PRIORITY)

9. **LSP instruction support**
   - Verify against E200 core reference manuals
   - Implement if required for target cores
   - Reference: GCC patch `gcc.vle_LSP_49x` (6714+ lines)

10. **SPE2 instruction support**
    - Complete SPE2 instruction definitions
    - Builtin function support
    - Reference: GCC patch `gcc.vle_spe2`

11. **BookE to VLE translation**
    - Optional convenience feature
    - Reference: GCC patch `bin.2-28-booke2vle-binutils`

12. **APUinfo section generation**
    - `.PPC.EMB.apuinfo` section support
    - Reference: VLEPIM Section 2.2.1

---

## Relocation Value Comparison

### VLEPIM vs LLVM vs GCC

| Relocation | VLEPIM | GCC | LLVM | Status |
|------------|--------|-----|------|--------|
| R_PPC_VLE_REL8 | 216 | - | 253 | ✅ (value mismatch) |
| R_PPC_VLE_REL15 | 217 | - | 254 | ✅ (value mismatch) |
| R_PPC_VLE_REL24 | 218 | - | 255 | ✅ (value mismatch) |
| R_PPC_VLE_REL32 | - | - | 256 | ✅ |
| R_PPC_VLE_ADDR16_LO | - | - | 257 | ✅ |
| R_PPC_VLE_ADDR16_HI | - | - | 258 | ✅ |
| R_PPC_VLE_ADDR16_HA | - | - | 259 | ✅ |
| R_PPC_VLE_ADDR24 | - | - | 260 | ✅ |
| R_PPC_VLE_ADDR32 | - | - | 261 | ✅ |
| R_PPC_VLE_SDAREL_LO | - | - | 262 | ⚠️ (name mismatch) |
| R_PPC_VLE_SDAREL_HI | - | - | 263 | ⚠️ (name mismatch) |
| R_PPC_VLE_SDAREL_HA | - | - | 264 | ⚠️ (name mismatch) |
| R_PPC_VLE_SDAREL_OFF_LO | - | - | 265 | ⚠️ (different from VLEPIM) |
| R_PPC_VLE_SDAREL_OFF_HI | - | - | 266 | ⚠️ (different from VLEPIM) |
| R_PPC_VLE_SDAREL_OFF_HA | - | - | 267 | ⚠️ (different from VLEPIM) |

**Note:** VLEPIM specifies SDAREL_LO16A/D, HI16A/D, HA16A/D (split16 variants), not the OFF variants in LLVM.

---

## End-to-End Compilation Test Plan

### Test Case 1: Basic VLE Compilation
```bash
# Compile
clang -target powerpc-eabivle -mvle -c test.c -o test.o

# Verify object file
llvm-readelf -h test.o
llvm-objdump -d test.o

# Link
lld -m elf32ppc test.o -o test.elf

# Verify ELF
llvm-readelf -S test.elf | grep VLE

# Convert to binary
llvm-objcopy --output-target=binary test.elf test.bin

# Convert to hex
llvm-objcopy --output-target=ihex test.elf test.hex
```

### Test Case 2: Relocation Verification
- Test each VLE relocation type
- Verify encoding matches VLEPIM specifications
- Check split immediate field encoding

### Test Case 3: Stub Entry Verification
- Create code with out-of-range branches
- Verify stub insertion
- Verify stub encoding matches GCC implementation

---

## Recommendations

### Immediate Actions Required

1. **Align relocation values with VLEPIM** OR document why LLVM uses different values
2. **Implement missing split16 relocations** (LO16A/D, HI16A/D, HA16A/D)
3. **Implement R_PPC_VLE_ADDR20** for e_li split20 encoding
4. **Complete SHF_PPC_VLE flag support** throughout toolchain
5. **Verify binary/hex output** conversion works correctly

### Medium-Term Actions

6. Implement SDA relocations if small data area optimization is needed
7. Add PF_PPC_VLE program header flag support
8. Verify/test LSP and SPE2 support requirements

### Long-Term Considerations

9. Evaluate need for BookE to VLE translation
10. Consider APUinfo section generation
11. Document any LLVM-specific deviations from VLEPIM

---

## Files to Modify

### Relocations
- `llvm/include/llvm/BinaryFormat/ELFRelocs/PowerPC.def` - Add missing relocations
- `lld/ELF/Arch/PPC.cpp` - Implement relocation handlers
- `llvm/lib/Target/PowerPC/MCTargetDesc/PPCELFObjectWriter.cpp` - Verify relocation emission
- `llvm/lib/Target/PowerPC/AsmParser/PPCAsmParser.cpp` - Relocation parsing

### Section Flags
- `llvm/lib/MC/MCObjectFileInfo.cpp` - Section flag handling
- `llvm/lib/MC/MCAssembler.cpp` - Section flag setting
- `llvm/lib/MC/MCParser/AsmParser.cpp` - `.section` directive parsing
- `lld/ELF/InputFiles.cpp` - Section flag reading
- `lld/ELF/Writer.cpp` - Section flag writing
- `llvm/tools/llvm-objcopy/` - Flag preservation

### Instructions
- `llvm/lib/Target/PowerPC/PPCInstrVLE.td` - VLE instruction definitions
- `llvm/lib/Target/PowerPC/PPCInstrInfo.td` - Instruction info
- `clang/lib/CodeGen/TargetInfo.cpp` - Builtin functions

### Binary Output
- `llvm/tools/llvm-objcopy/` - Binary/hex format support
- Test cases for VLE ELF conversion

---

## Conclusion

The LLVM/Clang toolchain has basic VLE support but is missing critical relocations and features required for full VLEPIM ABI compliance. The most critical gaps are:

1. Missing split16 relocation variants (affects instruction encoding)
2. Missing R_PPC_VLE_ADDR20 (affects e_li instruction)
3. Incomplete SHF_PPC_VLE flag support (affects section identification)
4. Missing SDA relocations (affects small data area optimization)
5. Relocation value mismatch with VLEPIM (may affect compatibility)

Priority should be given to implementing the missing relocations and completing section flag support to achieve VLEPIM ABI compliance.
