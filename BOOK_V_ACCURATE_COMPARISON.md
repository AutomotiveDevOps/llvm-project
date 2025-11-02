# Book V (VLE) Accurate 1:1 Comparison Report

This report provides an accurate comparison by properly categorizing Book V instructions into VLE-specific vs VLE-compatible Book I instructions.

## Executive Summary

- **Total Book V spec instructions**: 452
- **Total matching**: 439
- **Overall coverage**: 97.1%

## VLE-Specific Instructions

- **Spec count**: 40
- **LLVM count**: 115
- **Matching**: 37
- **Coverage**: 92.5%
- **Missing**: 3
- **Extra in LLVM**: 78 (may be newer ISA/variants)

### Matching VLE-Specific Instructions:

- `eadd2is`
- `eaddi`
- `eaddic`
- `eandi`
- `eb`
- `ebc`
- `ecmp16i`
- `ecmph16i`
- `ecmphl16i`
- `ecmpi`
- `ecmpl16i`
- `ecmpli`
- `ecrand`
- `ecrandc`
- `ecreqv`
- `ecrnand`
- `ecrnor`
- `ecror`
- `ecrorc`
- `ecrxor`
- `elbzu`
- `elhau`
- `elhzu`
- `eli`
- `elis`
- `elmw`
- `elwzu`
- `emcrf`
- `emull2i`
- `emulli`
- `eori`
- `estbu`
- `esthu`
- `estmw`
- `estwu`
- `esubfic`
- `exori`

### Missing VLE-Specific Instructions:

- `eor2i`
- `eor2is`
- `esc`

## VLE-Compatible Book I Instructions

- **Spec count**: 412
- **LLVM Book I count**: 1708
- **Matching**: 402
- **Coverage**: 97.6%
- **In spec Book I**: 406
- **Not in spec Book I**: 6

## Conclusion

**VLE-Specific Instructions**: 92.5% coverage (37/40)

**VLE-Compatible Book I Instructions**: 97.6% coverage (402/412)

**Note**: VLE-compatible Book I instructions are already covered in the Book I comparison (97.5% coverage). The VLE-specific instructions are the ones that require separate VLE encoding support.
