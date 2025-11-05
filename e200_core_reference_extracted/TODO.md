# e200 Compiler Implementation TODO

## Status Legend
- ⬜ Not Started
- 🔄 In Progress
- ✅ Completed
- ⏭️ Skipped/Deferred

---

## Phase 1: Critical Blocking Issues (MVP)

### Instruction Selection Patterns
- [⬜] Add Selection DAG patterns for E_ADDI
- [⬜] Add Selection DAG patterns for E_ADDIC
- [⬜] Add Selection DAG patterns for E_SUBFIC
- [⬜] Add Selection DAG patterns for E_ANDI
- [⬜] Add Selection DAG patterns for E_ORI
- [⬜] Add Selection DAG patterns for E_XORI
- [⬜] Add Selection DAG patterns for E_LBZU
- [⬜] Add Selection DAG patterns for E_LHZU
- [⬜] Add Selection DAG patterns for E_LWZU
- [⬜] Add Selection DAG patterns for E_STBU
- [⬜] Add Selection DAG patterns for E_STHU
- [⬜] Add Selection DAG patterns for E_STWU
- [⬜] Add Selection DAG patterns for E_BC
- [⬜] Add Selection DAG patterns for E_BCL
- [⬜] Verify instruction selector chooses VLE instructions over standard PowerPC

### SCI8 Scaling Logic
- [⬜] Extract SCI8 scaling algorithm from Core Reference Manuals
- [⬜] Implement F field calculation in encoder
- [⬜] Implement SCL field calculation in encoder
- [⬜] Update VLE_SCI8Form_RTRA to use scaling logic
- [⬜] Update VLE_SCI8Form_RSRA to use scaling logic
- [⬜] Test scaling with various immediate values

### Unconditional Branch Instructions
- [✅] Extract encoding for e_b (32-bit form) from Core Reference Manuals - Primary opcode 30, BD24 format (bits 7-30), LK=0
- [✅] Extract encoding for e_bl (32-bit form) from Core Reference Manuals - Primary opcode 30, BD24 format (bits 7-30), LK=1
- [⬜] Extract encoding for e_b (16-bit form) from Core Reference Manuals
- [⬜] Extract encoding for e_bl (16-bit form) from Core Reference Manuals
- [⬜] Define VLE_BForm_16bit class for 16-bit branches
- [✅] Define VLE_BD24Form class for 32-bit branches
- [✅] Implement E_B (unconditional branch)
- [✅] Implement E_BL (branch and link)
- [⬜] Add Selection DAG patterns for branches

---

## Phase 2: Essential VLE Instructions

### Basic Load/Store (No Update) (CRITICAL - Used in startup code)
- [⬜] Extract encoding for e_lbz from Core Reference Manuals
- [⬜] Extract encoding for e_lhz from Core Reference Manuals
- [⬜] Extract encoding for e_lwz from Core Reference Manuals
- [⬜] Extract encoding for e_stb from Core Reference Manuals
- [⬜] Extract encoding for e_sth from Core Reference Manuals
- [🔄] Extract encoding for e_stw from Core Reference Manuals - Used in startup.S
- [⬜] Define VLE load format class (non-update)
- [⬜] Define VLE store format class (non-update)
- [⬜] Implement E_LBZ
- [⬜] Implement E_LHZ
- [⬜] Implement E_LWZ
- [⬜] Implement E_STB
- [⬜] Implement E_STH
- [⬜] Implement E_STW (CRITICAL - startup code uses: e_stw r3, 0x10(r4))
- [⬜] Add Selection DAG patterns for load/store without update

### Load/Store Algebraic
- [⬜] Extract encoding for e_lha from Core Reference Manuals
- [⬜] Extract encoding for e_lhau from Core Reference Manuals
- [⬜] Implement E_LHA
- [⬜] Implement E_LHAU
- [⬜] Add Selection DAG patterns

### Load/Store Multiple (CRITICAL - Used in startup code)
- [⬜] Extract encoding for e_lmw from Core Reference Manuals
- [🔄] Extract encoding for e_stmw from Core Reference Manuals - Used in startup.S for SRAM init
- [⬜] Define VLE_LMW format class
- [⬜] Define VLE_STMW format class
- [⬜] Implement E_LMW
- [⬜] Implement E_STMW (CRITICAL - startup code uses: e_stmw r0,0(r5))
- [⬜] Add Selection DAG patterns
- [⬜] Test with function prologue/epilogue

### Compare Instructions
- [⬜] Extract encoding for e_cmpi from Core Reference Manuals
- [⬜] Extract encoding for e_cmpli from Core Reference Manuals
- [⬜] Extract encoding for e_cmp16i from Core Reference Manuals
- [⬜] Extract encoding for e_cmpl16i from Core Reference Manuals
- [⬜] Extract encoding for e_cmph16i from Core Reference Manuals
- [⬜] Extract encoding for e_cmphl16i from Core Reference Manuals
- [⬜] Extract encoding for e_cmph from Core Reference Manuals
- [⬜] Extract encoding for e_cmphl from Core Reference Manuals
- [⬜] Define VLE compare format classes
- [⬜] Implement E_CMPI
- [⬜] Implement E_CMPLI
- [⬜] Implement E_CMP16I
- [⬜] Implement E_CMPL16I
- [⬜] Implement E_CMPH16I
- [⬜] Implement E_CMPHL16I
- [⬜] Implement E_CMPH
- [⬜] Implement E_CMPHL
- [⬜] Add Selection DAG patterns for compares

### Condition Register Instructions
- [⬜] Extract encoding for e_crand from Core Reference Manuals
- [⬜] Extract encoding for e_crandc from Core Reference Manuals
- [⬜] Extract encoding for e_creqv from Core Reference Manuals
- [⬜] Extract encoding for e_crnand from Core Reference Manuals
- [⬜] Extract encoding for e_crnor from Core Reference Manuals
- [⬜] Extract encoding for e_cror from Core Reference Manuals
- [⬜] Extract encoding for e_crorc from Core Reference Manuals
- [⬜] Extract encoding for e_crxor from Core Reference Manuals
- [⬜] Define VLE CR format class
- [⬜] Implement E_CRAND
- [⬜] Implement E_CRANDC
- [⬜] Implement E_CREQV
- [⬜] Implement E_CRNAND
- [⬜] Implement E_CRNOR
- [⬜] Implement E_CROR
- [⬜] Implement E_CRORC
- [⬜] Implement E_CRXOR
- [⬜] Add Selection DAG patterns

### Move Instructions (CRITICAL - Used in startup code)
- [🔄] Extract encoding for e_li from Core Reference Manuals - Used extensively in startup.S
- [🔄] Extract encoding for e_lis from Core Reference Manuals - Used in startup.S
- [⬜] Extract encoding for e_mcrf from Core Reference Manuals
- [⬜] Extract encoding for e_or2i from Core Reference Manuals - Used in startup.S
- [⬜] Define VLE move format classes
- [⬜] Implement E_LI (CRITICAL - startup code uses: e_li r0, 0 through e_li r31, 0)
- [⬜] Implement E_LIS (CRITICAL - startup code uses: e_lis r4, 0xFC05, etc.)
- [⬜] Implement E_OR2I (CRITICAL - startup code uses: e_or2i r4, 0x0000, etc.)
- [⬜] Implement E_MCRF
- [⬜] Add Selection DAG patterns

### Multiply Instructions
- [⬜] Extract encoding for e_mulli from Core Reference Manuals
- [⬜] Extract encoding for e_mull2i from Core Reference Manuals
- [⬜] Define VLE multiply format classes
- [⬜] Implement E_MULLI
- [⬜] Implement E_MULL2I
- [⬜] Add Selection DAG patterns

### Rotate/Shift Instructions (CRITICAL - Used in startup code)
- [⬜] Extract encoding for e_rlw from Core Reference Manuals
- [⬜] Extract encoding for e_rlwi from Core Reference Manuals
- [⬜] Extract encoding for e_rlwimi from Core Reference Manuals
- [⬜] Extract encoding for e_rlwinm from Core Reference Manuals
- [⬜] Extract encoding for e_slwi from Core Reference Manuals
- [🔄] Extract encoding for e_srwi from Core Reference Manuals - Used in startup.S: e_srwi r5, r5, 0x7
- [⬜] Define VLE rotate/shift format classes
- [⬜] Implement E_RLW
- [⬜] Implement E_RLWI
- [⬜] Implement E_RLWIMI
- [⬜] Implement E_RLWINM
- [⬜] Implement E_SLWI
- [⬜] Implement E_SRWI (CRITICAL - startup code uses this)
- [⬜] Add Selection DAG patterns

### Additional Arithmetic Instructions
- [⬜] Extract encoding for e_add16i from Core Reference Manuals
- [⬜] Extract encoding for e_add2i from Core Reference Manuals
- [⬜] Extract encoding for e_add2is from Core Reference Manuals
- [⬜] Extract encoding for e_and2i from Core Reference Manuals
- [⬜] Extract encoding for e_and2is from Core Reference Manuals
- [🔄] Extract encoding for e_or2i from Core Reference Manuals - Used in startup.S
- [⬜] Extract encoding for e_or2is from Core Reference Manuals
- [⬜] Implement E_ADD16I
- [⬜] Implement E_ADD2I
- [⬜] Implement E_ADD2IS
- [⬜] Implement E_AND2I
- [⬜] Implement E_AND2IS
- [⬜] Implement E_OR2I (CRITICAL - startup code uses this)
- [⬜] Implement E_OR2IS
- [⬜] Add Selection DAG patterns

### System Instructions
- [⬜] Extract encoding for e_sc from Core Reference Manuals
- [⬜] Extract encoding for e_rfi from Core Reference Manuals
- [⬜] Implement E_SC
- [⬜] Implement E_RFI
- [⬜] Add Selection DAG patterns

---

## Phase 3: 16-bit VLE Instructions

### 16-bit Format Classes
- [⬜] Define VLE_16bit base format class
- [⬜] Define VLE_16bit branch format
- [⬜] Define VLE_16bit load/store format
- [⬜] Define VLE_16bit arithmetic format
- [⬜] Define VLE_16bit compare format
- [⬜] Define VLE_16bit CR format

### 16-bit Branch Instructions
- [⬜] Extract 16-bit encoding for e_b from Core Reference Manuals
- [⬜] Extract 16-bit encoding for e_bl from Core Reference Manuals
- [⬜] Extract 16-bit encoding for e_bc from Core Reference Manuals
- [⬜] Extract 16-bit encoding for e_bcl from Core Reference Manuals
- [⬜] Implement 16-bit E_B
- [⬜] Implement 16-bit E_BL
- [⬜] Implement 16-bit E_BC
- [⬜] Implement 16-bit E_BCL
- [⬜] Add instruction selection preferring 16-bit when possible

### 16-bit Load/Store Instructions
- [⬜] Extract 16-bit encoding for e_lbz from Core Reference Manuals
- [⬜] Extract 16-bit encoding for e_lhz from Core Reference Manuals
- [⬜] Extract 16-bit encoding for e_lwz from Core Reference Manuals
- [⬜] Extract 16-bit encoding for e_stb from Core Reference Manuals
- [⬜] Extract 16-bit encoding for e_sth from Core Reference Manuals
- [⬜] Extract 16-bit encoding for e_stw from Core Reference Manuals
- [⬜] Implement 16-bit load/store variants
- [⬜] Add code size optimization to prefer 16-bit

### 16-bit Arithmetic Instructions
- [⬜] Extract 16-bit encoding for e_addi from Core Reference Manuals
- [⬜] Extract 16-bit encoding for e_andi from Core Reference Manuals
- [⬜] Extract 16-bit encoding for e_ori from Core Reference Manuals
- [⬜] Extract 16-bit encoding for e_xori from Core Reference Manuals
- [⬜] Implement 16-bit arithmetic variants
- [⬜] Add code size optimization

---

## Phase 4: Instruction Selection & Optimization

### Instruction Selection Patterns
- [⬜] Review all existing VLE instructions for missing patterns
- [⬜] Add patterns for arithmetic operations
- [⬜] Add patterns for logical operations
- [⬜] Add patterns for memory operations
- [⬜] Add patterns for control flow
- [⬜] Add patterns for constant loading
- [⬜] Add patterns for compare operations
- [⬜] Verify instruction selector output

### Code Size Optimizations
- [⬜] Implement pass to prefer 16-bit over 32-bit when possible
- [⬜] Implement immediate optimization for SCI8 format
- [⬜] Implement branch optimization for VLE
- [⬜] Test code size improvements

### Peephole Optimizations
- [⬜] Add patterns for combining instructions
- [⬜] Add patterns for eliminating redundant operations
- [⬜] Add patterns for optimizing immediate usage

---

## Phase 5: Assembler/Disassembler

### Assembler Support
- [⬜] Verify PPCAsmParser can parse all VLE mnemonics
- [⬜] Test assembly of each VLE instruction
- [⬜] Verify operand parsing (registers, immediates, labels)
- [⬜] Test error handling for invalid VLE syntax
- [⬜] Verify VLE instruction aliases work

### Disassembler Support
- [⬜] Verify PPCDisassembler can decode all VLE instructions
- [⬜] Test disassembly of each VLE instruction encoding
- [⬜] Verify 16-bit vs 32-bit instruction detection
- [⬜] Test round-trip: assemble -> disassemble -> verify

### Code Emitter
- [⬜] Verify PPCMCCodeEmitter handles all VLE formats
- [⬜] Test encoding of each VLE instruction
- [⬜] Verify SCI8 scaling in encoder
- [⬜] Test branch displacement encoding
- [⬜] Test immediate encoding

---

## Phase 6: Instruction Scheduling

### Scheduling Models
- [⬜] Review PPCScheduleE500.td for e200 relevance
- [⬜] Extract pipeline information from Core Reference Manuals
- [⬜] Add e200-specific scheduling model
- [⬜] Add latency information for VLE instructions
- [⬜] Add throughput information for VLE instructions
- [⬜] Add resource information (execution units)
- [⬜] Test scheduling with simple programs

### Pipeline Information
- [⬜] Extract instruction timing from Core Reference Manuals
- [⬜] Document pipeline stages for e200 cores
- [⬜] Add instruction timing annotations
- [⬜] Verify scheduling accuracy

---

## Phase 7: SPE Instructions (For SPE-enabled cores)

### EFPU Instructions
- [⬜] Review existing SPE instruction definitions
- [⬜] Extract efd* instruction encodings from Core Reference Manuals
- [⬜] Extract efs* instruction encodings from Core Reference Manuals
- [⬜] Verify feature gating for e200 cores
- [⬜] Add missing EFPU instructions
- [⬜] Add Selection DAG patterns for EFPU

### SPE Vector Instructions
- [⬜] Review existing ev* instruction definitions
- [⬜] Extract ev* instruction encodings from Core Reference Manuals
- [⬜] Verify feature gating for e200 cores
- [⬜] Add missing SPE vector instructions
- [⬜] Add Selection DAG patterns for SPE

### SPE Feature Gating
- [⬜] Verify FeatureSPE is enabled for correct e200 cores
- [⬜] Test SPE instruction availability per core
- [⬜] Verify ISA 2.07 compliance for SPE instructions

---

## Phase 8: Calling Convention & ABI

### Calling Convention
- [⬜] Review PPCFrameLowering for e200 compatibility
- [⬜] Verify register usage conventions
- [⬜] Test function prologue generation
- [⬜] Test function epilogue generation
- [⬜] Verify stack frame layout
- [⬜] Test parameter passing
- [⬜] Test return value handling

### Register Allocation
- [⬜] Verify register classes for e200
- [⬜] Test register allocation with VLE instructions
- [⬜] Verify register constraints work correctly

### ABI Compliance
- [⬜] Review e200 ABI specification (if available)
- [⬜] Verify alignment requirements
- [⬜] Test inter-operation with other toolchains

---

## Phase 9: Testing

### Unit Tests
- [⬜] Create test for each VLE instruction encoding
- [⬜] Create test for each VLE instruction disassembly
- [⬜] Create test for instruction selection patterns
- [⬜] Create test for SCI8 scaling logic
- [⬜] Create test for 16-bit vs 32-bit selection

### Integration Tests
- [⬜] Test compilation of simple C programs
- [⬜] Test compilation of C++ programs
- [⬜] Test function calls
- [⬜] Test control flow
- [⬜] Test memory operations
- [⬜] Test arithmetic operations

### Code Generation Tests
- [⬜] Test code size with VLE instructions
- [⬜] Test code generation for different e200 cores
- [⬜] Test optimization passes
- [⬜] Test code correctness

### Assembly/Disassembly Tests
- [⬜] Test round-trip assembly/disassembly
- [⬜] Test error handling
- [⬜] Test edge cases

### Execution Tests (if simulator available)
- [⬜] Set up e200 simulator (if available)
- [⬜] Test execution of generated code
- [⬜] Verify instruction semantics

---

## Phase 10: Documentation

### Code Documentation
- [⬜] Document all VLE instruction formats
- [⬜] Document encoding algorithms
- [⬜] Document instruction selection patterns
- [⬜] Add comments to complex code

### User Documentation
- [⬜] Document e200 core support
- [⬜] Document VLE instruction usage
- [⬜] Document compiler flags for e200
- [⬜] Document limitations and known issues

### Reference Documentation
- [⬜] Create instruction reference for implemented VLE instructions
- [⬜] Document encoding formats
- [⬜] Document instruction semantics

---

## Phase 11: Linker, ELF, and Object File Support

### VLE ELF Section Support
- [⬜] Implement SHF_PPC_VLE section flag (0x1000000) in ELF support
- [⬜] Add VLE section flag detection in ObjectFile/ELF
- [⬜] Verify assembler can create VLE sections
- [⬜] Verify linker handles VLE sections correctly
- [⬜] Test with `.vle` directive in assembly files

### VLE Relocation Support
- [⬜] Implement R_PPC_VLE_REL8 (216) - 8-bit branch displacement
- [⬜] Implement R_PPC_VLE_REL15 (217) - 15-bit branch displacement  
- [⬜] Implement R_PPC_VLE_REL24 (218) - 24-bit branch displacement
- [⬜] Implement R_PPC_VLE_LO16A (219) - Low 16 bits (split16a field)
- [⬜] Implement R_PPC_VLE_LO16D (220) - Low 16 bits (split16d field)
- [⬜] Implement R_PPC_VLE_HI16A (221) - High 16 bits (split16a field)
- [⬜] Implement R_PPC_VLE_SDA21 (222) - Small data area 21-bit
- [⬜] Implement R_PPC_VLE_SDA21_LO (223) - Small data area 21-bit low
- [⬜] Test relocation handling in MC layer
- [⬜] Test relocation application in linker

### Linker Script Support
- [✅] Documented existing linker scripts in DEVKIT-Makefile
- [⬜] Verify lld can parse GNU ld linker scripts
- [⬜] Test with 57xx_flash.ld and 57xx_ram.ld
- [⬜] Test with sections.ld, mem.ld, libs.ld
- [⬜] Verify memory region definitions work
- [⬜] Verify section placement works
- [⬜] Test SDA (Small Data Area) support
- [⬜] Test _SDA_BASE_ and _SDA2_BASE_ symbols

## Phase 12: Runtime & Tools

### Runtime Libraries

### Runtime Libraries
- [⬜] Review runtime library requirements for e200
- [⬜] Test C standard library compatibility
- [⬜] Test exception handling
- [⬜] Test interrupt handling
- [⬜] Review EWL (Embedded Wrapper Library) integration
- [⬜] Test linking with EWL libraries (libewl_c.a, etc.)

### Linker Scripts
- [✅] Found linker scripts in `/projects/vle/DEVKIT-Makefile/MPC5744P/Linker_Files/` and `MPC5748G/`
- [⬜] Verify LLVM lld can parse existing linker scripts (*.ld files)
- [⬜] Test linking with 57xx_flash.ld and 57xx_ram.ld
- [⬜] Test linking with sections.ld, mem.ld, libs.ld
- [⬜] Document memory layout for each e200 core variant
- [⬜] Create linker script templates for LLVM if needed
- [⬜] Test linking with different memory configurations

### Startup Code
- [✅] Found startup code in `/projects/vle/DEVKIT-Makefile/MPC5744P/Startup_Code/startup.S`
- [✅] Analyzed startup code - uses: e_li, e_lis, e_or2i, e_stw, e_lbzu, e_bdnz, e_beq, e_b, e_bl
- [⬜] Verify LLVM can assemble startup.S files (VLE directives: `.vle`, `.section .startup`)
- [⬜] Test startup code compilation with clang
- [⬜] Test initialization sequences
- [⬜] Verify interrupt vector setup
- [⬜] Test intc_sw_handlers.S compilation
- [⬜] Verify reset handler compilation

### VLE Section Support
- [⬜] Implement SHF_PPC_VLE section flag support (from GNU patches)
- [⬜] Verify object file section flags are correctly set
- [⬜] Test VLE section detection in objdump/readelf
- [⬜] Verify linker respects VLE sections

### ELF Relocations
- [⬜] Implement R_PPC_VLE_REL8 relocation (from linker scripts)
- [⬜] Implement R_PPC_VLE_REL15 relocation
- [⬜] Implement R_PPC_VLE_REL24 relocation
- [⬜] Implement R_PPC_VLE_LO16A relocation
- [⬜] Implement R_PPC_VLE_LO16D relocation
- [⬜] Implement R_PPC_VLE_HI16A relocation
- [⬜] Implement R_PPC_VLE_SDA21 relocation
- [⬜] Implement R_PPC_VLE_SDA21_LO relocation
- [⬜] Test relocation handling in linker

### GNU Toolchain Compatibility
- [✅] Reviewed patches in `/projects/vle/s32/ELe200/patches_applied/`
- [⬜] Document differences between GNU and LLVM implementations
- [⬜] Verify LLVM produces compatible object files
- [⬜] Test interoperability (GCC object files + LLVM linker, etc.)

---

## Phase 12: Polish & Optimization

### Performance Optimization
- [⬜] Profile code generation
- [⬜] Optimize instruction selection
- [⬜] Optimize register allocation
- [⬜] Optimize scheduling

### Code Quality
- [⬜] Review code for consistency
- [⬜] Fix any code style issues
- [⬜] Add missing error handling
- [⬜] Improve code comments

### Final Testing
- [⬜] Comprehensive test suite
- [⬜] Stress testing
- [⬜] Regression testing
- [⬜] Performance benchmarking

---

## Statistics

**Total Tasks:** ~470+
**Completed:** 11
**In Progress:** 5
**Remaining:** ~455+

### Recent Completions
- ✅ E_B and E_BL (unconditional branches) - 32-bit BD24 format
- ✅ VLE_BD24Form format class
- ✅ Analyzed startup code requirements
- ✅ Documented linker script locations
- ✅ Documented GNU toolchain patches
- ✅ Created STARTUP_CODE_REQUIREMENTS.md document
- ✅ Identified all VLE instructions used in startup.S

### Critical Path for Startup Code
To compile startup.S, need these instructions:
1. ✅ E_B, E_BL (branches)
2. ✅ E_LBZU, E_STBU, E_STWU (load/store with update)
3. ✅ E_ADDI (arithmetic)
4. ✅ E_ORI (logical)
5. ❌ E_LI, E_LIS (load immediate) - **BLOCKING**
6. ❌ E_OR2I (OR 2-operand) - **BLOCKING**
7. ❌ E_STW (store word) - **BLOCKING**
8. ❌ E_STMW (store multiple) - **BLOCKING**
9. ❌ E_SUBI (subtract immediate) - **BLOCKING**
10. ❌ E_SRWI (shift right) - **BLOCKING**
11. ❌ E_CMP16I (compare) - **BLOCKING**
12. ❌ E_BEQ, E_BNE, E_BDNZ (branches) - **BLOCKING**

**Estimated Completion:**
- MVP (Phase 1): 2-4 weeks
- Functional (Phases 1-4): 1-2 months
- Complete (All Phases): 3-6 months

---

## Notes

- All e200 cores must use Power ISA 2.07 only
- VLE instructions are available on all e200 cores
- SPE instructions are available on e200z2, z3, z4, z6, z7
- Reference Core Reference Manuals for encoding details
- Test each implementation before moving to next item

