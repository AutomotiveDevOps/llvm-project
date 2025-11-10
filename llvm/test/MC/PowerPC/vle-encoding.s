# RUN: llvm-mc -triple powerpc-none-eabivle -mcpu=e200z0 -show-encoding %s | FileCheck %s
# RUN: llvm-mc -triple powerpc-none-eabivle -mcpu=e200z0 -filetype=obj -o %t.o %s
# RUN: llvm-objdump -d -r %t.o | FileCheck -check-prefix=CHECK-OBJ %s

# Test VLE instruction encoding for e200 cores
# This test verifies that VLE instructions assemble correctly and produce
# the expected binary encodings.

#===----------------------------------------------------------------------===//
# VLE Arithmetic Instructions (SCI8 Format)
#===----------------------------------------------------------------------===//

# e_addi: Add Scaled Immediate
# CHECK: e_addi r3, r4, 5                    # encoding: [0x18,0x83,0x00,0x05]
        e_addi r3, r4, 5

# CHECK: e_addi r0, r0, 0                    # encoding: [0x18,0x00,0x00,0x00]
        e_addi r0, r0, 0

# CHECK: e_addi r31, r31, 255                # encoding: [0x18,0xff,0x00,0xff]
        e_addi r31, r31, 255

# e_addic: Add Scaled Immediate Carrying
# CHECK: e_addic r3, r4, 10                  # encoding: [0x19,0x83,0x00,0x0a]
        e_addic r3, r4, 10

# e_subfic: Subtract From Scaled Immediate Carrying
# CHECK: e_subfic r3, r4, 20                 # encoding: [0x1b,0x83,0x00,0x14]
        e_subfic r3, r4, 20

# e_subi: Subtract Scaled Immediate
# CHECK: e_subi r10, r10, 1                  # encoding: [0x1a,0xaa,0x00,0x01]
        e_subi r10, r10, 1

#===----------------------------------------------------------------------===//
# VLE Logical Instructions (SCI8 Format)
#===----------------------------------------------------------------------===//

# e_andi: AND Immediate
# CHECK: e_andi r3, r4, 0xff                 # encoding: [0x1c,0x83,0x00,0xff]
        e_andi r3, r4, 0xff

# CHECK: e_andi r5, r5, 0x00                 # encoding: [0x1c,0xa5,0x00,0x00]
        e_andi r5, r5, 0x00

# e_ori: OR Immediate
# CHECK: e_ori r3, r4, 0x55                   # encoding: [0x1d,0x83,0x00,0x55]
        e_ori r3, r4, 0x55

# e_xori: XOR Immediate
# CHECK: e_xori r3, r4, 0xaa                 # encoding: [0x1e,0x83,0x00,0xaa]
        e_xori r3, r4, 0xaa

#===----------------------------------------------------------------------===//
# VLE Load Instructions (D Format)
#===----------------------------------------------------------------------===//

# e_lbz: Load Byte and Zero
# CHECK: e_lbz r3, 0(r4)                      # encoding: [0x88,0x64,0x00,0x00]
        e_lbz r3, 0(r4)

# CHECK: e_lbz r5, 31(r6)                     # encoding: [0x88,0xa6,0x00,0x1f]
        e_lbz r5, 31(r6)

# e_lhz: Load Halfword and Zero
# CHECK: e_lhz r3, 0(r4)                      # encoding: [0xa8,0x64,0x00,0x00]
        e_lhz r3, 0(r4)

# CHECK: e_lhz r7, 30(r8)                     # encoding: [0xa8,0xe8,0x00,0x1e]
        e_lhz r7, 30(r8)

# e_lwz: Load Word and Zero
# CHECK: e_lwz r3, 0(r4)                      # encoding: [0x80,0x64,0x00,0x00]
        e_lwz r3, 0(r4)

# CHECK: e_lwz r9, 16(r10)                    # encoding: [0x80,0xea,0x00,0x10]
        e_lwz r9, 16(r10)

#===----------------------------------------------------------------------===//
# VLE Store Instructions (D Format)
#===----------------------------------------------------------------------===//

# e_stb: Store Byte
# CHECK: e_stb r3, 0(r4)                      # encoding: [0x98,0x64,0x00,0x00]
        e_stb r3, 0(r4)

# CHECK: e_stb r5, 31(r6)                     # encoding: [0x98,0xa6,0x00,0x1f]
        e_stb r5, 31(r6)

# e_sth: Store Halfword
# CHECK: e_sth r3, 0(r4)                      # encoding: [0xb8,0x64,0x00,0x00]
        e_sth r3, 0(r4)

# CHECK: e_sth r7, 30(r8)                     # encoding: [0xb8,0xe8,0x00,0x1e]
        e_sth r7, 30(r8)

# e_stw: Store Word
# CHECK: e_stw r3, 0(r4)                     # encoding: [0x90,0x64,0x00,0x00]
        e_stw r3, 0(r4)

# CHECK: e_stw r3, 16(r4)                    # encoding: [0x90,0x64,0x00,0x10]
        e_stw r3, 16(r4)

#===----------------------------------------------------------------------===//
# VLE Load/Store with Update (D8 Format)
#===----------------------------------------------------------------------===//

# e_lbzu: Load Byte and Zero with Update
# CHECK: e_lbzu r3, 0(r4)                    # encoding: [0x8c,0x64,0x00,0x00]
        e_lbzu r3, 0(r4)

# e_lhzu: Load Halfword and Zero with Update
# CHECK: e_lhzu r3, 0(r4)                    # encoding: [0xac,0x64,0x00,0x00]
        e_lhzu r3, 0(r4)

# e_lwzu: Load Word and Zero with Update
# CHECK: e_lwzu r3, 0(r4)                    # encoding: [0x84,0x64,0x00,0x00]
        e_lwzu r3, 0(r4)

# e_stbu: Store Byte with Update
# CHECK: e_stbu r3, 0(r4)                    # encoding: [0x9c,0x64,0x00,0x00]
        e_stbu r3, 0(r4)

# e_sthu: Store Halfword with Update
# CHECK: e_sthu r3, 0(r4)                    # encoding: [0xbc,0x64,0x00,0x00]
        e_sthu r3, 0(r4)

# e_stwu: Store Word with Update
# CHECK: e_stwu r3, 0(r4)                    # encoding: [0x94,0x64,0x00,0x00]
        e_stwu r3, 0(r4)

#===----------------------------------------------------------------------===//
# VLE Load/Store Multiple Instructions
#===----------------------------------------------------------------------===//

# e_lmw: Load Multiple Word
# CHECK: e_lmw r0, 0(r5)                      # encoding: [0x18,0x00,0x00,0x00]
        e_lmw r0, 0(r5)

# e_stmw: Store Multiple Word
# CHECK: e_stmw r0, 0(r5)                     # encoding: [0x18,0x00,0x00,0x00]
        e_stmw r0, 0(r5)

#===----------------------------------------------------------------------===//
# VLE Immediate Instructions
#===----------------------------------------------------------------------===//

# e_li: Load Immediate (20-bit)
# CHECK: e_li r0, 0                          # encoding: [0x38,0x00,0x00,0x00]
        e_li r0, 0

# CHECK: e_li r3, 0xc520                      # encoding: [0x38,0x63,0xc5,0x20]
        e_li r3, 0xc520

# CHECK: e_li r31, 0                          # encoding: [0x38,0x1f,0x00,0x00]
        e_li r31, 0

# e_lis: Load Immediate Shifted (high 16 bits)
# CHECK: e_lis r4, 0xfc05                     # encoding: [0x3c,0x84,0xfc,0x05]
        e_lis r4, 0xfc05

# CHECK: e_lis r3, 0xff00                     # encoding: [0x3c,0x63,0xff,0x00]
        e_lis r3, 0xff00

# e_or2i: OR 2-operand Immediate
# CHECK: e_or2i r4, 0x0000                   # encoding: [0x30,0x84,0x00,0x00]
        e_or2i r4, 0x0000

# CHECK: e_or2i r3, 0x010a                   # encoding: [0x30,0x63,0x01,0x0a]
        e_or2i r3, 0x010a

#===----------------------------------------------------------------------===//
# VLE Branch Instructions
#===----------------------------------------------------------------------===//

# e_b: Branch (24-bit displacement)
# CHECK: e_b target                           # encoding: [0x48,0x00,A,A]
# CHECK-NEXT:                                 #   fixup A - offset: 0, value: target, kind: fixup_ppc_br24
        e_b target

# e_bl: Branch and Link (24-bit displacement)
# CHECK: e_bl target                          # encoding: [0x48,0x01,A,A]
# CHECK-NEXT:                                 #   fixup A - offset: 0, value: target, kind: fixup_ppc_br24
        e_bl target

# e_bc: Branch Conditional (15-bit displacement)
# CHECK: e_bc 4, 2, target                    # encoding: [0x40,0x82,A,A]
# CHECK-NEXT:                                 #   fixup A - offset: 0, value: target, kind: fixup_ppc_brcond15
        e_bc 4, 2, target

# e_bcl: Branch Conditional and Link (15-bit displacement)
# CHECK: e_bcl 4, 2, target                   # encoding: [0x40,0x82,A,A]
# CHECK-NEXT:                                 #   fixup A - offset: 0, value: target, kind: fixup_ppc_brcond15
        e_bcl 4, 2, target

target:
        nop

#===----------------------------------------------------------------------===//
# VLE System Instructions
#===----------------------------------------------------------------------===//

# e_rfi: Return From Interrupt
# CHECK: e_rfi                                # encoding: [0x4c,0x00,0x00,0x50]
        e_rfi

# e_sc: System Call
# CHECK: e_sc                                 # encoding: [0x44,0x00,0x00,0x02]
        e_sc

#===----------------------------------------------------------------------===//
# VLE Compare Instructions
#===----------------------------------------------------------------------===//

# e_cmp16i: Compare 16-bit Immediate
# CHECK: e_cmp16i r9, 0                       # encoding: [0x2c,0x09,0x00,0x00]
        e_cmp16i r9, 0

# CHECK: e_cmp16i r5, 100                     # encoding: [0x2c,0x05,0x00,0x64]
        e_cmp16i r5, 100

# CHECK: e_cmp16i r3, -1                      # encoding: [0x2c,0x03,0xff,0xff]
        e_cmp16i r3, -1

