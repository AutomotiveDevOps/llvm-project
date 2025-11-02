#!/usr/bin/env python3
"""Map LLVM PowerPC instructions to Power ISA 2.07 books."""

import re
from collections import defaultdict
from typing import Dict, List, Set


def determine_book_from_llvm_instruction(mnemonic: str, file_source: str) -> str:
    """Map LLVM instruction name to Power ISA book."""
    
    mnemonic_lower = mnemonic.lower()
    
    # VLE - check file or prefix
    if 'VLE' in file_source or mnemonic_lower.startswith('e_'):
        return 'V'
    
    # SPE - check file or prefix
    if 'SPE' in file_source or mnemonic_lower.startswith('ef') or \
       mnemonic_lower.startswith('ev') or mnemonic_lower == 'brinc':
        return 'I'
    
    # DFP
    if 'DFP' in file_source or any(kw in mnemonic_lower for kw in 
                                   ['dadd', 'dsub', 'dmul', 'ddiv', 'dqua', 'dct', 'dcffix', 'dctfix']):
        return 'I'
    
    # Vector/Altivec
    if 'Altivec' in file_source or 'VSX' in file_source:
        return 'I'
    
    # HTM (Transactional Memory) - Book II
    if 'HTM' in file_source or any(kw in mnemonic_lower for kw in 
                                    ['tbegin', 'tend', 'tabort', 'tcheck', 'trechkpt', 'treclaim']):
        return 'II'
    
    # Supervisor instructions - check context
    if any(kw in mnemonic_lower for kw in ['rfid', 'hrfid', 'slbie', 'tlbie', 'mtspr', 'mfspr']):
        # Distinguish III-S vs III-E based on embedded indicators
        if 'embedded' in mnemonic_lower or 'ivor' in mnemonic_lower:
            return 'III-E'
        else:
            return 'III-S'
    
    # 64-bit - typically Book I but some may be Book III
    if '64Bit' in file_source:
        return 'I'  # Most 64-bit are Book I
    
    # Power10, MMA, Future - newer ISA, still primarily Book I
    if 'P10' in file_source or 'MMA' in file_source or 'Future' in file_source:
        return 'I'
    
    # Default to Book I (most instructions are user-level)
    if 'Info' in file_source:  # PPCInstrInfo.td
        return 'I'
    
    return 'I'


def map_llvm_instructions_to_books():
    """Map all LLVM PowerPC instructions to Power ISA books."""
    print("=== Mapping LLVM Instructions to Power ISA 2.07 Books ===\n")
    
    # Load LLVM instruction inventory (from previous analysis)
    llvm_instructions = {}
    
    instruction_files = {
        'PPCInstrInfo.td': 'Base',
        'PPCInstrAltivec.td': 'Altivec',
        'PPCInstrVSX.td': 'VSX',
        'PPCInstrSPE.td': 'SPE',
        'PPCInstrDFP.td': 'DFP',
        'PPCInstrHTM.td': 'HTM',
        'PPCInstrVLE.td': 'VLE',
        'PPCInstr64Bit.td': '64-bit',
        'PPCInstrP10.td': 'Power10',
        'PPCInstrMMA.td': 'MMA',
        'PPCInstrFuture.td': 'Future'
    }
    
    # Extract from files
    for filename, category in instruction_files.items():
        filepath = f'llvm/lib/Target/PowerPC/{filename}'
        try:
            with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
                content = f.read()
            
            # Extract instruction definitions
            pattern = r'def\s+([A-Z][A-Z0-9_]+)\s*:'
            matches = re.findall(pattern, content)
            
            for mnemonic in matches:
                book = determine_book_from_llvm_instruction(mnemonic, filename)
                llvm_instructions[mnemonic.lower()] = {
                    'mnemonic': mnemonic.lower(),
                    'original': mnemonic,
                    'file': filename,
                    'category': category,
                    'book': book
                }
            
            print(f"{filename}: {len(matches)} instructions")
        
        except FileNotFoundError:
            print(f"{filename}: Not found")
        except Exception as e:
            print(f"{filename}: Error - {e}")
    
    # Group by book
    by_book = defaultdict(list)
    for inst_data in llvm_instructions.values():
        by_book[inst_data['book']].append(inst_data)
    
    print(f"\n=== Summary by Book ===\n")
    for book in sorted(by_book.keys()):
        count = len(by_book[book])
        unique_mnemonics = len(set(inst['mnemonic'] for inst in by_book[book]))
        print(f"Book {book}: {count} definitions, {unique_mnemonics} unique mnemonics")
    
    # Save mapping
    with open('llvm_ppc_instructions_by_book.txt', 'w') as f:
        f.write("LLVM PowerPC Instructions Mapped to Power ISA 2.07 Books\n")
        f.write("=" * 70 + "\n\n")
        
        for book in sorted(by_book.keys()):
            f.write(f"\nBook {book} ({len(by_book[book])} instructions):\n")
            f.write("-" * 70 + "\n")
            for inst in sorted(by_book[book], key=lambda x: x['mnemonic']):
                f.write(f"  {inst['mnemonic']:<30} {inst['file']:<25} {inst['category']}\n")
    
    print(f"\nSaved mapping to llvm_ppc_instructions_by_book.txt")
    
    return llvm_instructions, by_book


if __name__ == '__main__':
    llvm_inst, by_book = map_llvm_instructions_to_books()
    
    # Facility breakdown
    print("\n=== Facility Breakdown ===\n")
    facilities = defaultdict(int)
    for inst_data in llvm_inst.values():
        cat = inst_data['category']
        if cat == 'Altivec' or cat == 'VSX':
            facilities['Vector/SIMD'] += 1
        elif cat == 'SPE':
            facilities['SPE'] += 1
        elif cat == 'DFP':
            facilities['DFP'] += 1
        elif cat == 'HTM':
            facilities['Transactional Memory'] += 1
        elif cat == 'VLE':
            facilities['VLE'] += 1
        else:
            facilities['Base/Other'] += 1
    
    for facility in sorted(facilities.keys()):
        print(f"{facility}: {facilities[facility]} instructions")

