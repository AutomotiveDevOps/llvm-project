# e200z759 vs e200z760: SPE and EFPU Differences

## Confirmed: Critical Architectural Difference

### z760n3 (from manual page 1-2, 3-4):
- **SPE unit**: "supporting SIMD fixed-point and single-precision floating-point operations, using the 64-bit GPR file."
- **Embedded floating-point unit (EFPU)**: "supporting scalar single-precision floating-point operations."
- **Manual explicitly states**: "The EFPU is a subset of the SPE."

**Interpretation:**
- SPE includes both fixed-point AND floating-point operations
- EFPU provides scalar floating-point operations (subset of SPE's floating-point capability)
- If you have SPE, you automatically get EFPU functionality
- SPE = fixed-point + floating-point; EFPU = scalar floating-point (subset)

### z759n3 (from manual page 23):
- **Embedded Floating-point APU (EFPU2)**: "supporting scalar and SIMD single-precision floating-point operations"
- **Signal Processing Extension (SPE1.1) APU**: "supporting SIMD fixed-point operations, using the 64-bit General Purpose Register file."

**Manual clarification (page ~24):**
- "The SPE1.1 APU supports vector instructions operating on 16 and 32-bit fixed-point data types."
- "The EFPU2 APU supports 32-bit IEEE-754 single-precision floating-point formats, and supports scalar and vector single-precision floating-point operations"

**Interpretation:**
- SPE1.1 handles ONLY fixed-point operations (no floating-point)
- EFPU2 handles ALL floating-point operations (both scalar and SIMD)
- These are SEPARATE, INDEPENDENT capabilities

## Critical Distinction

**z760n3 Architecture:**
```
SPE = {Fixed-point operations} + {Floating-point operations}
EFPU ⊆ SPE (scalar floating-point subset)
```

**z759n3 Architecture:**
```
SPE1.1 = {Fixed-point operations only}
EFPU2 = {Floating-point operations only}
SPE1.1 ∩ EFPU2 = ∅ (separate capabilities)
```

## LLVM Implementation Impact

**Current LLVM model:**
```cpp
def : ProcessorModel<"e200z7", PPCE200Z7Model,
                  [DirectiveE200Z7,
                   FeatureICBT, FeatureBookE,
                   FeatureISEL, FeatureMFTB, FeatureE200,
                   FeatureSPE, FeatureMSYNC]>;  // Uses FeatureSPE
```

**Analysis:**
- ✓ **z760n3**: `FeatureSPE` is CORRECT - SPE includes floating-point
- ⚠ **z759n3**: Should potentially use `FeatureFPU` instead, since:
  - EFPU2 is separate from SPE1.1
  - Floating-point comes from EFPU2, not SPE1.1
  - If device can have EFPU2 without SPE1.1, `FeatureSPE` would be wrong

## Questions to Resolve

1. **Are both always present?** Do z759 devices always have both SPE1.1 and EFPU2, or can they be configured independently?
2. **Device configuration**: Can a z759-based device have:
   - EFPU2 only (floating-point, no fixed-point SPE)?
   - SPE1.1 only (fixed-point, no floating-point)?
   - Both (most common)?
3. **z760 configuration**: Since "EFPU is a subset of SPE", does z760 always require SPE to enable any floating-point?

## Recommendation

1. **Extract configuration details** from z759 manual to see if SPE1.1/EFPU2 are optional
2. **Check device datasheets** (MPC5676R, etc.) to see actual configurations
3. **Consider separate processor models:**
   - `e200z759`: Use `FeatureFPU` (EFPU2 provides floating-point, separate from SPE1.1)
   - `e200z760`: Keep `FeatureSPE` (SPE includes floating-point)
   - OR: Keep single model if both always include both capabilities

## Current Status

- LLVM model is correct for **z760n3** (SPE includes floating-point)
- LLVM model **may need adjustment** for **z759n3** if devices can have EFPU2 without SPE1.1

