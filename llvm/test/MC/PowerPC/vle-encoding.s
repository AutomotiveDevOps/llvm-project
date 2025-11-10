# RUN: llvm-mc -triple powerpc-unknown-none-eabivle --show-encoding %s | FileCheck -check-prefix=CHECK %s
# RUN: llvm-mc -triple powerpc-unknown-none-eabivle -filetype=obj -o %t.o %s
# RUN: llvm-objdump -d -r %t.o | FileCheck -check-prefix=CHECK-DISASM %s

# Test VLE instruction encoding and disassembly
# This test verifies that VLE instructions can be assembled and disassembled correctly
#
# Note: VLE assembler parser support may not be fully implemented yet (Phase 4.1).
# This test file documents the expected encodings and will validate them once
# parser support is complete. The encodings are calculated from PPCInstrVLE.td
# instruction format definitions.

#===----------------------------------------------------------------------===//
# VLE Branch Instructions
#===----------------------------------------------------------------------===//

# CHECK: e_b target                        # encoding: [0x78,0x00,0x00,0x00]
# CHECK-NEXT:                               #   fixup A - offset: 0, value: target, kind: fixup_ppc_br24
            e_b target

# CHECK: e_bl target                       # encoding: [0x78,0x00,0x00,0x01]
# CHECK-NEXT:                               #   fixup A - offset: 0, value: target, kind: fixup_ppc_br24
            e_bl target

# CHECK: e_bc 0, 2, target                 # encoding: [0x7a,0x82,0x00,0x00]
# CHECK-NEXT:                               #   fixup A - offset: 0, value: target, kind: fixup_ppc_br15
            e_bc 0, 2, target

# CHECK: e_bcl 0, 2, target                # encoding: [0x7a,0x82,0x00,0x01]
# CHECK-NEXT:                               #   fixup A - offset: 0, value: target, kind: fixup_ppc_br15
            e_bcl 0, 2, target

#===----------------------------------------------------------------------===//
# VLE Arithmetic Instructions
#===----------------------------------------------------------------------===//

# CHECK: e_addi r3, r4, 0                  # encoding: [0x18,0x64,0x80,0x00]
            e_addi r3, r4, 0

# CHECK: e_addi r5, r6, 255                # encoding: [0x18,0xa6,0x80,0xff]
            e_addi r5, r6, 255

# CHECK: e_subi r3, r4, 0                  # encoding: [0x18,0x64,0xa0,0x00]
            e_subi r3, r4, 0

# CHECK: e_subi r10, r10, 1                # encoding: [0x19,0x4a,0xa0,0x01]
            e_subi r10, r10, 1

# CHECK: e_addic r3, r4, 0                 # encoding: [0x18,0x64,0x90,0x00]
            e_addic r3, r4, 0

# CHECK: e_subfic r3, r4, 0                # encoding: [0x18,0x64,0xb0,0x00]
            e_subfic r3, r4, 0

#===----------------------------------------------------------------------===//
# VLE Logical Instructions
#===----------------------------------------------------------------------===//

# CHECK: e_andi r3, r4, 0                  # encoding: [0x18,0x83,0xc0,0x00]
            e_andi r3, r4, 0

# CHECK: e_andi r5, r6, 255                # encoding: [0x18,0xa5,0xc0,0xff]
            e_andi r5, r6, 255

# CHECK: e_ori r3, r4, 0                   # encoding: [0x18,0x83,0xd0,0x00]
            e_ori r3, r4, 0

# CHECK: e_ori r5, r6, 255                 # encoding: [0x18,0xa5,0xd0,0xff]
            e_ori r5, r6, 255

# CHECK: e_xori r3, r4, 0                   # encoding: [0x18,0x83,0xe0,0x00]
            e_xori r3, r4, 0

# CHECK: e_xori r5, r6, 255                # encoding: [0x18,0xa5,0xe0,0xff]
            e_xori r5, r6, 255

#===----------------------------------------------------------------------===//
# VLE Load/Store Instructions (D-Form)
#===----------------------------------------------------------------------===//

# CHECK: e_lbz r3, 0(r4)                   # encoding: [0x30,0x64,0x00,0x00]
            e_lbz r3, 0(r4)

# CHECK: e_lbz r5, 255(r6)                 # encoding: [0x30,0xa6,0x00,0xff]
            e_lbz r5, 255(r6)

# CHECK: e_lhz r3, 0(r4)                   # encoding: [0x58,0x64,0x00,0x00]
            e_lhz r3, 0(r4)

# CHECK: e_lhz r5, 255(r6)                 # encoding: [0x58,0xa6,0x00,0xff]
            e_lhz r5, 255(r6)

# CHECK: e_lwz r3, 0(r4)                   # encoding: [0x50,0x64,0x00,0x00]
            e_lwz r3, 0(r4)

# CHECK: e_lwz r5, 255(r6)                 # encoding: [0x50,0xa6,0x00,0xff]
            e_lwz r5, 255(r6)

# CHECK: e_stb r3, 0(r4)                   # encoding: [0x38,0x64,0x00,0x00]
            e_stb r3, 0(r4)

# CHECK: e_stb r5, 255(r6)                 # encoding: [0x38,0xa6,0x00,0xff]
            e_stb r5, 255(r6)

# CHECK: e_sth r3, 0(r4)                   # encoding: [0x60,0x64,0x00,0x00]
            e_sth r3, 0(r4)

# CHECK: e_sth r5, 255(r6)                 # encoding: [0x60,0xa6,0x00,0xff]
            e_sth r5, 255(r6)

# CHECK: e_stw r3, 0(r4)                   # encoding: [0x54,0x64,0x00,0x00]
            e_stw r3, 0(r4)

# CHECK: e_stw r3, 16(r4)                  # encoding: [0x54,0x64,0x00,0x10]
            e_stw r3, 16(r4)

# CHECK: e_stw r5, 255(r6)                 # encoding: [0x54,0xa6,0x00,0xff]
            e_stw r5, 255(r6)

#===----------------------------------------------------------------------===//
# VLE Load/Store Instructions (D8-Form with Update)
#===----------------------------------------------------------------------===//

# CHECK: e_lbzu r3, 0(r4)                  # encoding: [0x18,0x64,0x00,0x00]
            e_lbzu r3, 0(r4)

# CHECK: e_lhzu r3, 0(r4)                  # encoding: [0x18,0x64,0x10,0x00]
            e_lhzu r3, 0(r4)

# CHECK: e_lwzu r3, 0(r4)                  # encoding: [0x18,0x64,0x20,0x00]
            e_lwzu r3, 0(r4)

# CHECK: e_stbu r3, 0(r4)                  # encoding: [0x18,0x64,0x40,0x00]
            e_stbu r3, 0(r4)

# CHECK: e_sthu r3, 0(r4)                  # encoding: [0x18,0x64,0x50,0x00]
            e_sthu r3, 0(r4)

# CHECK: e_stwu r3, 0(r4)                  # encoding: [0x18,0x64,0x60,0x00]
            e_stwu r3, 0(r4)

#===----------------------------------------------------------------------===//
# VLE Load/Store Multiple Instructions
#===----------------------------------------------------------------------===//

# CHECK: e_lmw r0, 0(r5)                   # encoding: [0x18,0x05,0x08,0x00]
            e_lmw r0, 0(r5)

# CHECK: e_stmw r0, 0(r5)                  # encoding: [0x18,0x05,0x09,0x00]
            e_stmw r0, 0(r5)

#===----------------------------------------------------------------------===//
# VLE Immediate Load Instructions
#===----------------------------------------------------------------------===//

# CHECK: e_li r0, 0                        # encoding: [0x70,0x00,0x00,0x00]
            e_li r0, 0

# CHECK: e_li r3, 0                        # encoding: [0x70,0x60,0x00,0x00]
            e_li r3, 0

# CHECK: e_li r3, 50464                    # encoding: [0x70,0x60,0xc5,0x20]
            e_li r3, 50464

# CHECK: e_lis r4, 64517                   # encoding: [0x70,0x85,0xec,0x05]
            e_lis r4, 64517

# CHECK: e_lis r3, 65280                  # encoding: [0x70,0x60,0xef,0x00]
            e_lis r3, 65280

# CHECK: e_or2i r4, 0                      # encoding: [0x70,0x80,0xc0,0x00]
            e_or2i r4, 0

# CHECK: e_or2i r3, 266                   # encoding: [0x70,0x6a,0xc1,0x0a]
            e_or2i r3, 266

#===----------------------------------------------------------------------===//
# VLE Compare Instructions
#===----------------------------------------------------------------------===//

# CHECK: e_cmp16i r9, 0                    # encoding: [0x2d,0x20,0x00,0x00]
            e_cmp16i r9, 0

target:
            nop

