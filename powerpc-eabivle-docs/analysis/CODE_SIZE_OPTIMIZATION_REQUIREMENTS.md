# Code Size Optimization Requirements for PowerPC VLE

## Current Status

**Status**: 🚧 (30%, 56h)  
**Goal**: Achieve 20-30% code size reduction promised by VLE specification

### What Exists

1. **PPCVLEOpt Pass** (`llvm/lib/Target/PowerPC/PPCVLEOpt.cpp`)
   - Post-register-allocation pass that converts standard PowerPC to VLE
   - Supports: load/store, arithmetic, compare, logical, shift operations
   - **Limitation**: Runs too late (after RA), only handles physical registers

2. **VLE Instruction Definitions** (`PPCInstrVLE.td`)
   - All 16-bit VLE instructions (se_ prefix) defined
   - All 32-bit VLE instructions (e_ prefix) defined
   - Pattern matching for DAG selection partially implemented

3. **Register Constraints**
   - 16-bit VLE instructions can only use registers R0-R7 (3-bit encoding)
   - 32-bit VLE instructions can use all 32 registers (5-bit encoding)

## What Needs to Be Implemented

### 1. Cost Model for Instruction Selection ⚠️ CRITICAL

**Priority**: HIGH  
**Impact**: Core functionality - instruction selector won't prefer VLE without this

#### Problem
The instruction selection process (DAG-to-DAG selection) doesn't know that VLE instructions are smaller. It needs a cost model to prefer:
- 16-bit VLE instructions (2 bytes) over standard PowerPC (4 bytes)
- 32-bit VLE instructions (4 bytes) when they're equivalent to standard PowerPC

#### Implementation Tasks

**A. Add Code Size Cost to TargetTransformInfo**

```cpp
// File: llvm/lib/Target/PowerPC/PPCTargetTransformInfo.cpp
// Method: getUserCost()

// Add VLE-aware code size calculation:
if (CostKind == TTI::TCK_CodeSize && ST->hasVLE()) {
  // Check if instruction has a VLE equivalent
  if (hasVLE16Equivalent(U)) {
    return 2; // 16-bit VLE = 2 bytes
  } else if (hasVLE32Equivalent(U)) {
    return 4; // 32-bit VLE = 4 bytes
  } else {
    return 4; // Standard PowerPC = 4 bytes
  }
}
```

**B. Implement Instruction Cost Queries**

Create helper functions to determine VLE availability:
- `hasVLE16Equivalent()` - Check if 16-bit VLE form exists
- `hasVLE32Equivalent()` - Check if 32-bit VLE form exists
- `canUseVLE16()` - Check register/immediate constraints for 16-bit

**C. Add Cost to Instruction Patterns in TableGen**

Currently in `PPCInstrVLE.td`, instructions are defined but don't indicate size preference:

```tablegen
// Need to add code size hints:
def SE_ADDI : SE_FORM2<...> {
  let CodeSize = 2;  // 16-bit instruction
}

def E_ADD : EVXForm<...> {
  let CodeSize = 4;  // 32-bit instruction
}
```

**Files to Modify**:
- `llvm/lib/Target/PowerPC/PPCTargetTransformInfo.cpp`
- `llvm/lib/Target/PowerPC/PPCTargetTransformInfo.h`
- `llvm/lib/Target/PowerPC/PPCInstrVLE.td`

---

### 2. Early Register Allocation Hints for VLE

**Priority**: HIGH  
**Impact**: Enables more 16-bit VLE instructions by preferring R0-R7

#### Problem
Register allocator doesn't know that using R0-R7 enables 16-bit VLE instructions. It allocates registers arbitrarily, missing opportunities for code size reduction.

#### Implementation Tasks

**A. Add Register Preference Interface**

```cpp
// File: llvm/lib/Target/PowerPC/PPCRegisterInfo.cpp
// Add to PPCRegisterInfo class:

unsigned getRegPressureLimit(const TargetRegisterClass *RC,
                             MachineFunction &MF) const override {
  // For VLE targets optimizing for size, prefer R0-R7
  if (STI->hasVLE() && 
      (MF.getFunction().optForSize() || STI->isTargetEABIVLE())) {
    if (RC == &PPC::GPRCRegClass) {
      // Reserve R0-R7 for VLE opportunities
      return 8; // Prefer allocating to first 8 registers
    }
  }
  return TargetRegisterInfo::getRegPressureLimit(RC, MF);
}
```

**B. Register Allocation Hints in Instruction Selection**

When generating DAG nodes for operations that could use VLE:
- Mark virtual registers with hints to prefer R0-R7
- Add target-specific hints to MachineRegisterInfo

**C. Implement VLE-Aware Register Allocation Pass**

Create a pre-RA pass that:
1. Identifies operations eligible for 16-bit VLE
2. Marks their registers for R0-R7 allocation
3. Provides hints to register allocator

**Files to Modify**:
- `llvm/lib/Target/PowerPC/PPCRegisterInfo.cpp`
- `llvm/lib/Target/PowerPC/PPCRegisterInfo.h`
- Create: `llvm/lib/Target/PowerPC/PPCVLERegAllocHints.cpp` (new file)

---

### 3. Instruction Selection Optimization in ISelDAGToDAG

**Priority**: HIGH  
**Impact**: Primary point where VLE instructions should be selected

#### Problem
The DAG-to-DAG instruction selector (`PPCISelDAGToDAG.cpp`) doesn't prioritize VLE instructions during pattern matching. It selects standard PowerPC instructions even when VLE equivalents are available and smaller.

#### Implementation Tasks

**A. Add VLE Pattern Priority**

Modify pattern matching to prefer VLE patterns when:
- `-Oz` optimization is enabled
- Target triple is `powerpc-none-eabivle`
- Function has `optnone` or size optimization attributes

```cpp
// File: llvm/lib/Target/PowerPC/PPCISelDAGToDAG.cpp

// In Select() method, check if we should prefer VLE:
bool PreferVLE = CurDAG->getTarget().getTargetMachine()
                   ->getOptLevel() == CodeGenOptLevel::Oz ||
                 STI->isTargetEABIVLE();

if (PreferVLE && canSelectVLE(Node)) {
  // Try VLE patterns first
  if (SelectVLE(Node, Result))
    return;
}
```

**B. Implement VLE Pattern Selection Helper**

Create `SelectVLE()` function that:
- Checks register constraints (R0-R7 for 16-bit)
- Checks immediate value constraints
- Prefers 16-bit over 32-bit when both are possible
- Falls back to standard PowerPC if VLE not possible

**C. Enhance Pattern Matching Order**

In TableGen patterns (`PPCInstrVLE.td`), ensure VLE patterns are tried before standard PowerPC patterns when code size matters.

Currently patterns might look like:
```tablegen
def : Pat<(add GPRC:$rA, imm:$imm), (ADDI GPRC:$rA, imm:$imm)>;
def : Pat<(add GPRC:$rA, imm:$imm), (SE_ADDI GPRC:$rA, imm:$imm),
          Requires<[HasVLE, RegConstraint<0,7>]>;
```

Need to ensure VLE patterns are tried first with proper constraints.

**Files to Modify**:
- `llvm/lib/Target/PowerPC/PPCISelDAGToDAG.cpp`
- `llvm/lib/Target/PowerPC/PPCISelLowering.cpp`
- `llvm/lib/Target/PowerPC/PPCInstrVLE.td`

---

### 4. Immediate Value Optimization

**Priority**: MEDIUM  
**Impact**: Enables more 16-bit VLE instructions

#### Problem
Many immediate values don't fit in VLE constraints:
- 16-bit VLE: s6imm (-32 to 31) or u5imm (0 to 31) or u7imm (0 to 127)
- Standard PowerPC: s16imm (-32768 to 32767)

When immediates are outside VLE range, we need to generate constant materialization sequences, but should still prefer VLE where possible.

#### Implementation Tasks

**A. Constant Materialization with VLE**

When materializing constants:
- Prefer VLE instructions when possible (e.g., `se_li` for small constants)
- Use sequences of VLE instructions when it reduces total code size
- Compare cost: VLE materialization vs standard PowerPC materialization

**B. Immediate Range Analysis**

Add analysis pass that:
- Identifies immediate values that can use VLE
- Suggests transformations to fit values in VLE range
- Optimizes constant pools for VLE targets

**Files to Modify**:
- `llvm/lib/Target/PowerPC/PPCISelLowering.cpp` (constant materialization)
- Create: `llvm/lib/Target/PowerPC/PPCVLEImmediateOpt.cpp` (new pass)

---

### 5. Post-RA VLE Optimization Enhancement

**Priority**: MEDIUM  
**Impact**: Catches missed opportunities after register allocation

#### Problem
The existing `PPCVLEOpt` pass has limitations:
- Only handles physical registers (runs after RA)
- Doesn't handle all instruction types
- Doesn't consider instruction sequences (could optimize multi-instruction patterns)

#### Implementation Tasks

**A. Expand PPCVLEOpt Coverage**

Add support for more instruction types:
- Branch instructions (with PC-relative offset analysis)
- Multi-instruction sequences that can be optimized
- Memory addressing modes (register+register, indexed addressing)

**B. Sequence Optimization**

Identify patterns like:
```asm
lis r3, hi16_const
ori r3, r3, lo16_const
```
→ Could become single VLE instruction if constraints allow

**C. Register Renaming Opportunities**

After RA, if we have instructions using R8-R31 that could be VLE16 if moved to R0-R7:
- Check if we can rename registers
- Evaluate cost: rename cost vs code size savings
- Apply when beneficial

**Files to Modify**:
- `llvm/lib/Target/PowerPC/PPCVLEOpt.cpp` (expand functionality)

---

### 6. Profile-Guided Code Size Optimization

**Priority**: LOW  
**Impact**: Advanced optimization for maximum code size reduction

#### Problem
Without profile data, we can't know which code paths are hot. We optimize everything equally, but for code size we should:
- Prefer VLE for cold paths (rarely executed)
- May accept slightly larger hot paths if cold paths benefit significantly

#### Implementation Tasks

**A. PGO Integration**

- Use PGO data to identify hot/cold regions
- Apply aggressive VLE optimization to cold code
- Balance hot path performance vs cold path code size

**Files to Create**:
- `llvm/lib/Target/PowerPC/PPCVLEPGO.cpp` (new pass)

---

### 7. Instruction Alignment Optimization

**Priority**: LOW  
**Impact**: Marginal code size improvement

#### Problem
VLE instructions have variable length (16-bit or 32-bit). Alignment requirements can waste bytes.

#### Implementation Tasks

**A. Smart Alignment**

- Don't align unnecessarily when it wastes space
- Pack 16-bit VLE instructions efficiently
- Minimize padding in instruction streams

---

## Implementation Priority

### Phase 1: Critical Foundation (Must Have)
1. ✅ Cost model for instruction selection
2. ✅ Early register allocation hints
3. ✅ ISelDAGToDAG VLE prioritization

**Expected Impact**: 15-20% code size reduction

### Phase 2: Enhancement (Should Have)
4. ✅ Immediate value optimization
5. ✅ Enhanced post-RA optimization

**Expected Impact**: Additional 5-10% code size reduction

### Phase 3: Advanced (Nice to Have)
6. Profile-guided optimization
7. Instruction alignment optimization

**Expected Impact**: Additional 2-5% code size reduction

---

## Testing Requirements

### Unit Tests
- Cost model returns correct sizes for VLE vs standard
- Register hints work correctly
- Instruction selection prefers VLE when appropriate

### Integration Tests
- Code size benchmarks comparing:
  - Before optimization vs after
  - VLE vs standard PowerPC
  - Different optimization levels (-O0, -Os, -Oz)

### Test Cases
Create test programs that:
- Use R0-R7 registers → should use 16-bit VLE
- Use R8-R31 registers → should use 32-bit VLE
- Use large immediates → should use standard PowerPC
- Mix of all above → should optimize appropriately

---

## Code Size Metrics

### Target Metrics (from VLEPEM)
- **Goal**: 20-30% code size reduction
- **16-bit VLE instructions**: 50% size reduction vs standard (2 bytes vs 4 bytes)
- **32-bit VLE instructions**: Same size as standard, but may have other benefits

### Measurement
Track code size metrics:
- Total .text section size
- Average instruction size
- Percentage of VLE instructions (16-bit vs 32-bit vs standard)
- Code size reduction percentage

---

## Related Files and References

### Key Files to Modify
- `llvm/lib/Target/PowerPC/PPCTargetTransformInfo.cpp` - Cost model
- `llvm/lib/Target/PowerPC/PPCRegisterInfo.cpp` - Register hints
- `llvm/lib/Target/PowerPC/PPCISelDAGToDAG.cpp` - Instruction selection
- `llvm/lib/Target/PowerPC/PPCInstrVLE.td` - Instruction patterns
- `llvm/lib/Target/PowerPC/PPCVLEOpt.cpp` - Post-RA optimization
- `llvm/lib/Target/PowerPC/PPCISelLowering.cpp` - Constant materialization

### Reference Documents
- `../implementation/VLEPEM_IMPLEMENTATION_ASSESSMENT.md` - Current status
- `../implementation/README_VLE_STATUS.md` - Feature status
- VLEPEM (Variable-Length Encoding Programming Environments Manual) - Specification

### Similar Implementations
- ARM Thumb instruction selection (similar 16-bit/32-bit encoding)
- RISC-V compressed instruction support (C extension)

---

## Summary

To achieve the 20-30% code size reduction promised by VLE, the following must be implemented:

1. **Cost Model** - Tell instruction selector that VLE is smaller
2. **Register Hints** - Prefer R0-R7 allocation for VLE-eligible operations
3. **Pattern Prioritization** - Try VLE patterns before standard PowerPC
4. **Enhanced Post-RA Pass** - Catch missed opportunities
5. **Immediate Optimization** - Maximize use of VLE immediate ranges

The foundation (items 1-3) is critical and must be implemented first. Items 4-5 enhance the optimization. Advanced features (PGO, alignment) provide marginal additional benefits.

