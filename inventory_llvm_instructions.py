#!/usr/bin/env python3
"""Catalog all instruction definitions in LLVM PowerPC backend."""

import re
import os
from collections import defaultdict
from typing import Dict, List, Set, Tuple


def extract_tablegen_definitions(file_path: str) -> List[Dict]:
    """Extract instruction definitions from TableGen files."""
    instructions = []
    
    try:
        with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
        
        # Pattern 1: def instruction_name : instruction_format { ... }
        pattern1 = r'def\s+([A-Z][A-Z0-9_]+)\s*:\s*([A-Z][A-Z0-9_]+)'
        matches = re.findall(pattern1, content)
        for mnemonic, format_class in matches:
            instructions.append({
                'mnemonic': mnemonic,
                'format': format_class,
                'file': os.path.basename(file_path),
                'type': 'def'
            })
        
        # Pattern 2: let Mnemonic = "..."
        pattern2 = r'let\s+Mnemonic\s*=\s*"([^"]+)"'
        mnemonic_matches = re.findall(pattern2, content)
        for mnemonic in mnemonic_matches:
            instructions.append({
                'mnemonic': mnemonic.upper(),
                'format': 'Unknown',
                'file': os.path.basename(file_path),
                'type': 'let_mnemonic'
            })
        
        # Pattern 3: InstrInfo instruction definitions with names
        # Pattern: def NAME : InstrInfo<...>;
        pattern3 = r'def\s+([A-Z][A-Z0-9_]+)\s*:\s*InstrInfo'
        matches = re.findall(pattern3, content)
        for name in matches:
            # Skip generic names
            if name not in ['InstrInfo', 'Instr', 'Inst']:
                instructions.append({
                    'mnemonic': name,
                    'format': 'InstrInfo',
                    'file': os.path.basename(file_path),
                    'type': 'instr_info'
                })
    
    except Exception as e:
        print(f"Error reading {file_path}: {e}")
    
    return instructions


def extract_instruction_names_from_asm(file_path: str) -> Set[str]:
    """Extract instruction names from assembly-related patterns."""
    names = set()
    
    try:
        with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
        
        # Look for patterns like "add", "addi", etc. in comments or strings
        # Pattern: instruction name (lowercase, 2-10 chars) in various contexts
        # This is less reliable but can catch aliases
        pass  # Skip for now - focus on TableGen defs
    
    except Exception:
        pass
    
    return names


def analyze_ppc_instruction_files():
    """Analyze all PowerPC instruction definition files."""
    print("=== Analyzing LLVM PowerPC Instruction Files ===\n")
    
    instruction_files = [
        'llvm/lib/Target/PowerPC/PPCInstrInfo.td',
        'llvm/lib/Target/PowerPC/PPCInstrAltivec.td',
        'llvm/lib/Target/PowerPC/PPCInstrVSX.td',
        'llvm/lib/Target/PowerPC/PPCInstrSPE.td',
        'llvm/lib/Target/PowerPC/PPCInstrDFP.td',
        'llvm/lib/Target/PowerPC/PPCInstrHTM.td',
        'llvm/lib/Target/PowerPC/PPCInstrVLE.td',
        'llvm/lib/Target/PowerPC/PPCInstr64Bit.td',
        'llvm/lib/Target/PowerPC/PPCInstrP10.td',
        'llvm/lib/Target/PowerPC/PPCInstrMMA.td',
        'llvm/lib/Target/PowerPC/PPCInstrFuture.td',
        'llvm/lib/Target/PowerPC/PPCInstrFormats.td',
    ]
    
    all_instructions = []
    by_file = defaultdict(list)
    
    for file_path in instruction_files:
        if not os.path.exists(file_path):
            print(f"Warning: {file_path} not found")
            continue
        
        print(f"Analyzing {os.path.basename(file_path)}...")
        instructions = extract_tablegen_definitions(file_path)
        
        all_instructions.extend(instructions)
        by_file[os.path.basename(file_path)] = instructions
        
        print(f"  Found {len(instructions)} instruction definitions")
    
    # Remove duplicates (same mnemonic from same file)
    unique_instructions = {}
    for inst in all_instructions:
        key = (inst['mnemonic'], inst['file'])
        if key not in unique_instructions:
            unique_instructions[key] = inst
    
    print(f"\n=== Summary ===")
    print(f"Total instruction definitions: {len(all_instructions)}")
    print(f"Unique (mnemonic, file) pairs: {len(unique_instructions)}")
    
    # Count unique mnemonics (across all files)
    unique_mnemonics = set(inst['mnemonic'] for inst in all_instructions)
    print(f"Unique instruction names: {len(unique_mnemonics)}")
    
    # Group by file
    print(f"\n=== Instructions by File ===")
    for filename in sorted(by_file.keys()):
        insts = by_file[filename]
        unique_in_file = len(set(inst['mnemonic'] for inst in insts))
        print(f"{filename}: {len(insts)} definitions, {unique_in_file} unique names")
    
    # Categorize by extension
    categorized = defaultdict(set)
    for inst in all_instructions:
        filename = inst['file']
        mnemonic = inst['mnemonic']
        
        if 'VLE' in filename:
            categorized['VLE'].add(mnemonic)
        elif 'SPE' in filename:
            categorized['SPE'].add(mnemonic)
        elif 'VSX' in filename:
            categorized['VSX'].add(mnemonic)
        elif 'Altivec' in filename:
            categorized['Altivec/VMX'].add(mnemonic)
        elif 'DFP' in filename:
            categorized['DFP'].add(mnemonic)
        elif 'HTM' in filename:
            categorized['HTM'].add(mnemonic)
        elif '64Bit' in filename:
            categorized['64-bit'].add(mnemonic)
        elif 'P10' in filename:
            categorized['Power10'].add(mnemonic)
        elif 'MMA' in filename:
            categorized['MMA'].add(mnemonic)
        elif 'Future' in filename:
            categorized['Future'].add(mnemonic)
        elif 'Info' in filename:
            categorized['Base'].add(mnemonic)
        else:
            categorized['Base'].add(mnemonic)
    
    print(f"\n=== Instructions by Category ===")
    for category in sorted(categorized.keys()):
        print(f"{category}: {len(categorized[category])} unique instructions")
        # Show samples
        samples = sorted(list(categorized[category]))[:10]
        print(f"  Sample: {', '.join(samples)}")
    
    # Save results
    with open('llvm_ppc_instruction_list.txt', 'w') as f:
        f.write("LLVM PowerPC Instruction Inventory\n")
        f.write("=" * 60 + "\n\n")
        
        for category in sorted(categorized.keys()):
            f.write(f"\n{category} ({len(categorized[category])} instructions):\n")
            f.write("-" * 60 + "\n")
            for mnemonic in sorted(categorized[category]):
                f.write(f"  {mnemonic}\n")
    
    return unique_instructions, categorized


def count_instruction_variants():
    """Count instruction variants (e.g., add vs addo vs add.) in LLVM."""
    print("\n=== Counting Instruction Variants ===\n")
    
    # Read main instruction file
    try:
        with open('llvm/lib/Target/PowerPC/PPCInstrInfo.td', 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
        
        # Count "def" statements
        def_count = len(re.findall(r'^\s*def\s+', content, re.MULTILINE))
        print(f"Total 'def' statements in PPCInstrInfo.td: {def_count}")
        
        # Look for common instruction patterns
        base_instructions = {}
        patterns = [
            (r'def\s+(ADD[A-Z0-9_]*)\s*:', 'add variants'),
            (r'def\s+(SUB[A-Z0-9_]*)\s*:', 'sub variants'),
            (r'def\s+(MUL[A-Z0-9_]*)\s*:', 'mul variants'),
            (r'def\s+(DIV[A-Z0-9_]*)\s*:', 'div variants'),
        ]
        
        for pattern, name in patterns:
            matches = re.findall(pattern, content)
            if matches:
                base_instructions[name] = len(matches)
                print(f"{name}: {len(matches)}")
    
    except Exception as e:
        print(f"Error: {e}")


if __name__ == '__main__':
    unique_inst, categorized = analyze_ppc_instruction_files()
    count_instruction_variants()

