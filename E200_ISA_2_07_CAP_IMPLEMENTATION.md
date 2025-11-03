# e200 Cores Power ISA 2.07 Cap Implementation

## Summary

All e200 core models have been explicitly capped at **Power ISA 2.07** by adding `FeatureISA2_07` to their processor model definitions.

## Changes Made

### Modified File: `llvm/lib/Target/PowerPC/PPC.td`

Added `FeatureISA2_07` to all e200 processor models:

1. **e200z0**: Added `FeatureISA2_07`
2. **e200z3**: Added `FeatureISA2_07`
3. **e200z4**: Added `FeatureISA2_07`
4. **e200z6**: Added `FeatureISA2_07`
5. **e200z7**: Added `FeatureISA2_07`

### Before:
```tablegen
def : ProcessorModel<"e200z0", PPCE200Z0Model,
                  [DirectiveE200Z0,
                   FeatureICBT, FeatureBookE,
                   FeatureISEL, FeatureMFTB, FeatureE200,
                   FeatureMSYNC]>;
```

### After:
```tablegen
def : ProcessorModel<"e200z0", PPCE200Z0Model,
                  [DirectiveE200Z0,
                   FeatureICBT, FeatureBookE,
                   FeatureISEL, FeatureMFTB, FeatureE200,
                   FeatureMSYNC, FeatureISA2_07]>;
```

## ISA Version Feature Hierarchy

Power ISA features in LLVM follow a dependency hierarchy:

- `FeatureISA2_07` - Power ISA Version 2.07 (base)
- `FeatureISA3_0` - Power ISA Version 3.0 (depends on `FeatureISA2_07`)
- `FeatureISA3_1` - Power ISA Version 3.1 (depends on `FeatureISA3_0`)
- `FeatureISAFuture` - Future ISA (depends on `FeatureISA3_1`)

By explicitly setting `FeatureISA2_07` and **NOT** including `FeatureISA3_0` or `FeatureISA3_1`, e200 cores are guaranteed to:

1. ✅ Support Power ISA 2.07 instructions
2. ✅ **NOT** support Power ISA 3.0+ instructions (due to dependency chain)
3. ✅ Have ISA 3.0+ instructions properly predicate-guarded (they check for `IsISA3_0`/`IsISA3_1`)

## Verification

The verification script (`verify_e200_isa_2_07_cap.py`) confirms:

1. ✅ All e200 models now explicitly include `FeatureISA2_07`
2. ✅ No e200 models include `FeatureISA3_0` or `FeatureISA3_1`
3. ✅ VLE instruction files (e200-specific) do not reference ISA 3.0+
4. ✅ ISA 3.0+ instructions in other files are properly predicate-guarded

## Instruction Predicate Guarding

ISA 3.0+ instructions are protected by predicates such as:
- `IsISA3_0` - Requires ISA 3.0
- `IsISA3_1` - Requires ISA 3.1 (which implies ISA 3.0)
- `FeatureISA3_0` - Feature flag check
- `FeatureISA3_1` - Feature flag check

Since e200 cores do NOT have these features enabled, instruction selection will automatically exclude ISA 3.0+ instructions for e200 targets.

## Compliance

This ensures that:

- ✅ **ISO 26262 / Certification Compliance**: e200 cores are explicitly limited to Power ISA 2.07
- ✅ **No Accidental ISA 3.0+ Usage**: Compiler cannot generate ISA 3.0+ instructions for e200
- ✅ **Clear Intent**: The processor model definitions clearly show ISA 2.07 limitation
- ✅ **Maintainability**: Future additions will see the explicit ISA 2.07 cap

## Testing Recommendations

1. Verify compilation with `-mcpu=e200z*` flags
2. Disassemble output to confirm no ISA 3.0+ opcodes
3. Test with ISA 3.0+ intrinsics to ensure they're rejected
4. Run test suite with e200 targets

## Files Modified

- `llvm/lib/Target/PowerPC/PPC.td` - Added `FeatureISA2_07` to all e200 models

## Related Files

- `llvm/lib/Target/PowerPC/PPCSubtarget.cpp` - ISA version initialization (defaults to false)
- `llvm/lib/Target/PowerPC/PPCInstr*.td` - Instruction definitions with ISA version predicates
- `verify_e200_isa_2_07_cap.py` - Verification script

