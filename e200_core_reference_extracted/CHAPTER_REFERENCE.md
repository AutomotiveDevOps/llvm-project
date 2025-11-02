# Chapter Quick Reference

## Most Important Chapters for LLVM Development

### Chapter 4: Microarchitecture (Both Variants)
**Files**: `z759/Chapter_04.txt`, `z760/Chapter_04.txt`
- Instruction timing tables
- Pipeline stages
- Dual-issue pairing rules
- Load/store latencies
- Branch prediction behavior

**Key Tables**:
- Instruction timing (Table 4-3 in z760)
- Concurrent instruction issue capabilities (Table 4-1 in z760)
- Pairing matrix

### Chapter 5: Embedded Floating-Point (Both Variants)
**Files**: `z759/Chapter_05.txt`, `z760/Chapter_05.txt`
- EFPU2 instruction set (z759)
- EFPU instruction set (z760)
- Floating-point instruction timings
- Register usage (GPRs for floating-point)

**Critical Difference**:
- **z759**: EFPU2 handles ALL floating-point operations
- **z760**: EFPU provides scalar floating-point (subset of SPE)

### Chapter 6: Signal Processing Extension (Both Variants)
**Files**: `z759/Chapter_06.txt`, `z760/Chapter_06.txt`
- SPE instruction set
- Fixed-point operations
- Vector operations

**Critical Difference**:
- **z759**: SPE1.1 handles ONLY fixed-point (no floating-point)
- **z760**: SPE handles fixed-point AND floating-point

### Chapter 2: Register Model (Both Variants)
**Files**: `z759/Chapter_02.txt`, `z760/Chapter_02.txt`
- Register definitions
- MSR bits (including SPE/EFPU enable bits)
- Special-purpose registers

### Chapter 3: Instruction Model (Both Variants)
**Files**: `z759/Chapter_03.txt`, `z760/Chapter_03.txt`
- Instruction formats
- VLE instruction encoding
- APU (Auxiliary Processing Unit) definitions

## Usage Examples

### Find Load Latency:
```bash
grep -i "load.*latency\|3 cycle\|three cycle" z760/Chapter_04.txt
```

### Find Instruction Timing Table:
```bash
grep -A 50 "Table.*4-3\|Table.*timing" z760/Chapter_04.txt
```

### Compare SPE Features:
```bash
grep -i "SPE.*floating\|floating.*SPE" z759/Chapter_06.txt
grep -i "SPE.*floating\|floating.*SPE" z760/Chapter_06.txt
```

### Find Pairing Rules:
```bash
grep -A 30 "concurrent.*instruction\|pairing\|dual.*issue" z760/Chapter_04.txt
```

## Chapter Sizes

### z759:
- Chapter 1: ~15KB (Overview)
- Chapter 2: ~127KB (Register Model)
- Chapter 3: ~158KB (Instruction Model)
- Chapter 4: ~65KB (Microarchitecture)
- Chapter 5: ~303KB (EFPU2)
- Chapter 6: ~373KB (SPE1.1)
- Chapter 7: ~177KB (Interrupts)
- Chapter 12: ~1.2MB (Instruction Reference - largest)

### z760:
- Chapter 4: ~71KB (Microarchitecture)
- Chapter 5: ~300KB (EFPU)
- Chapter 6: ~135KB (SPE)
- Chapter 11: ~352KB (Instruction Reference)
- Chapter 13: ~394KB (Nexus Debug)
- Chapter 14: ~357KB (Additional topics)

