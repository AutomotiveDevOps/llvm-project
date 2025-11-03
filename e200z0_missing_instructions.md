# E200Z0 Missing Instructions Report

## Summary

- **Expected Instructions**: 452
- **Implemented in LLVM**: 445
- **Missing Instructions**: 13
- **Coverage**: 98.5%

## Missing Instructions by Category

### Fixed-Point (4)

- `and`
- `ehpriv`
- `sradi`
- `to`

### Load/Store (4)

- `mulhd`
- `mulhdu`
- `mulhw`
- `mulhwu`

### SPE (2)

- `evlddepx`
- `evstddepx`

### VLE (3)

- `e_or2i`
- `e_or2is`
- `e_sc`

