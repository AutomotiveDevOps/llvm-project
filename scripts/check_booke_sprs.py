#!/usr/bin/env python3
"""Check if Book E SPRs are defined in LLVM"""
import re
import sys

# Book E SPR numbers from manual (approximate - need to verify)
BOOKE_SPRS = {
    'SRR0': 26,    # Save/Restore Register 0
    'SRR1': 27,    # Save/Restore Register 1
    'CSRR0': 58,   # Critical Save/Restore Register 0
    'CSRR1': 59,   # Critical Save/Restore Register 1
    'MCSRR0': 570, # Machine Check Save/Restore Register 0
    'MCSRR1': 571, # Machine Check Save/Restore Register 1
    'IVPR': 63,    # Interrupt Vector Prefix Register
    'IVOR0': 400,  # Interrupt Vector Offset Register 0 (Critical Input)
    'IVOR1': 401,  # Interrupt Vector Offset Register 1 (Machine Check)
    'IVOR2': 402,  # Interrupt Vector Offset Register 2 (Data Storage)
    'IVOR3': 403,  # Interrupt Vector Offset Register 3 (Instruction Storage)
    'IVOR4': 404,  # Interrupt Vector Offset Register 4 (External Input)
    'IVOR5': 405,  # Interrupt Vector Offset Register 5 (Alignment)
    'IVOR6': 406,  # Interrupt Vector Offset Register 6 (Program)
    'IVOR7': 407,  # Interrupt Vector Offset Register 7 (Floating-Point Unavailable)
    'IVOR8': 408,  # Interrupt Vector Offset Register 8 (System Call)
    'IVOR9': 409,  # Interrupt Vector Offset Register 9 (Auxiliary Processor Unavailable)
    'IVOR10': 410, # Interrupt Vector Offset Register 10 (Decrementer)
    'IVOR11': 411, # Interrupt Vector Offset Register 11 (Fixed-Interval Timer)
    'IVOR12': 412, # Interrupt Vector Offset Register 12 (Watchdog Timer)
    'IVOR13': 413, # Interrupt Vector Offset Register 13 (Data TLB Error)
    'IVOR14': 414, # Interrupt Vector Offset Register 14 (Instruction TLB Error)
    'IVOR15': 415, # Interrupt Vector Offset Register 15 (Debug)
    'DEAR': 61,    # Data Exception Address Register
    'ESR': 62,     # Exception Syndrome Register
}

# Read PPCRegisterInfo.td
try:
    with open('llvm/lib/Target/PowerPC/PPCRegisterInfo.td', 'r') as f:
        content = f.read()
    
    print("Checking Book E SPR definitions:")
    print("=" * 60)
    
    missing = []
    found = []
    
    for spr_name, spr_num in BOOKE_SPRS.items():
        # Look for SPR definition with the number
        pattern1 = rf'def\s+{spr_name}\s*:\s*SPR<{spr_num}'
        pattern2 = rf'SPR<{spr_num}.*{spr_name}'
        
        if re.search(pattern1, content, re.IGNORECASE) or re.search(pattern2, content, re.IGNORECASE):
            found.append(spr_name)
            print(f"✅ {spr_name:10} (SPR {spr_num:3}) - FOUND")
        else:
            missing.append((spr_name, spr_num))
            print(f"❌ {spr_name:10} (SPR {spr_num:3}) - NOT FOUND")
    
    print(f"\nSummary: {len(found)}/{len(BOOKE_SPRS)} SPRs found")
    if missing:
        print(f"\nMissing SPRs ({len(missing)}):")
        for name, num in missing:
            print(f"  - {name} (SPR {num})")
    
except FileNotFoundError:
    print("Error: PPCRegisterInfo.td not found")
    sys.exit(1)

