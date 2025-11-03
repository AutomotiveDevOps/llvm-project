# Book V (VLE) Accurate 1:1 Comparison Report

This report provides an accurate comparison by properly categorizing Book V instructions into VLE-specific vs VLE-compatible Book I instructions.

## Executive Summary

- **Total Book V spec instructions**: 452
- **Total matching**: 452
- **Overall coverage**: 100.0%

## VLE-Specific Instructions

- **Spec count**: 40
- **LLVM count**: 118
- **Matching**: 40
- **Coverage**: 100.0%
- **Missing**: 0
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
- `eor2i`
- `eor2is`
- `eori`
- `esc`
- `estbu`
- `esthu`
- `estmw`
- `estwu`
- `esubfic`
- `exori`

## VLE-Compatible Book I Instructions

- **Spec count**: 412
- **LLVM Book I count**: 1718
- **Matching**: 412
- **Coverage**: 100.0%
- **In spec Book I**: 406
- **Not in spec Book I**: 6

## Conclusion

**VLE-Specific Instructions**: 100.0% coverage (40/40)

**VLE-Compatible Book I Instructions**: 100.0% coverage (412/412)

**Note**: VLE-compatible Book I instructions are already covered in the Book I comparison (97.5% coverage). The VLE-specific instructions are the ones that require separate VLE encoding support.
