#!/usr/bin/env python3
"""
Extract opcodes from Core Reference Manuals and Power ISA 2.07 documentation.

This script extracts instruction mnemonics from the extracted documentation
and compares them with existing LLVM PowerPC instruction definitions.
"""

import re
import os
from pathlib import Path
from collections import defaultdict
from typing import Set, Dict, List

# Project root
PROJECT_ROOT = Path(__file__).parent.parent

# Documentation directories
DOCS_ROOT = PROJECT_ROOT / "e200_core_reference_extracted"
ISA_207_LIST = PROJECT_ROOT / "powerisa_v2_07_instruction_list.txt"
LLVM_INSTR_DIR = PROJECT_ROOT / "llvm" / "lib" / "Target" / "PowerPC"


def extract_instructions_from_isa_list(file_path: Path) -> Set[str]:
    """Extract instruction mnemonics from powerisa_v2_07_instruction_list.txt"""
    instructions = set()
    
    if not file_path.exists():
        print(f"Warning: {file_path} not found")
        return instructions
    
    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    # Pattern to match instruction mnemonics (lines starting with spaces and a word)
    # Format: "  mnemonic                Format       Category               Description"
    pattern = r'^\s+([a-z_][a-z0-9_]*)\s+[A-Z0-9]'
    
    for line in content.split('\n'):
        match = re.match(pattern, line)
        if match:
            mnemonic = match.group(1).strip()
            # Filter out common false positives
            if mnemonic and len(mnemonic) > 1 and mnemonic not in ['unknown', 'category', 'instructions']:
                instructions.add(mnemonic)
    
    return instructions


def extract_from_manual_chapter(chapter_path: Path) -> Set[str]:
    """Extract instruction mnemonics from a manual chapter"""
    instructions = set()
    
    if not chapter_path.exists():
        return instructions
    
    with open(chapter_path, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    # Pattern for instruction mnemonics in documentation
    # Look for patterns like "e_addi", "add", "mulhw", etc.
    # Common instruction patterns
    patterns = [
        r'\b(e_[a-z][a-z0-9_]{2,})\b',  # VLE instructions (e_ prefix)
        r'\b([a-z]{2,}(?:[a-z]|\.|x|u|o|w|d|s|i|z|a|f|p|m|h|b|q|r|t|v|y|g|k|l|n|e|j|c|_)+)\b',  # General instructions
    ]
    
    for pattern in patterns:
        matches = re.findall(pattern, content, re.IGNORECASE)
        for match in matches:
            if isinstance(match, tuple):
                mnemonic = match[0] if match[0] else match[1]
            else:
                mnemonic = match
            # Filter out common false positives
            if (mnemonic and len(mnemonic) >= 2 and 
                mnemonic.lower() not in ['the', 'and', 'for', 'with', 'from', 'that', 'this', 
                                       'instruction', 'instructions', 'category', 'unknown']):
                instructions.add(mnemonic.lower())
    
    return instructions


def extract_from_all_manuals() -> Dict[str, Set[str]]:
    """Extract instructions from all Core Reference Manuals"""
    manual_instructions = defaultdict(set)
    
    if not DOCS_ROOT.exists():
        print(f"Warning: {DOCS_ROOT} not found")
        return manual_instructions
    
    # Core Reference Manuals
    core_manuals = ['z0', 'z1', 'z3', 'z4', 'z759', 'z760']
    
    for manual in core_manuals:
        manual_dir = DOCS_ROOT / manual
        if manual_dir.exists():
            # Check instruction reference chapters (usually last chapters)
            for chapter_file in sorted(manual_dir.glob("Chapter_*.txt")):
                chapter_instructions = extract_from_manual_chapter(chapter_file)
                if chapter_instructions:
                    manual_instructions[manual].update(chapter_instructions)
    
    # Power ISA 2.07
    powerisa_dir = DOCS_ROOT / "powerisa_v2_07"
    if powerisa_dir.exists():
        for chapter_file in sorted(powerisa_dir.glob("Chapter_*.txt")):
            chapter_instructions = extract_from_manual_chapter(chapter_file)
            if chapter_instructions:
                manual_instructions["powerisa_v2_07"].update(chapter_instructions)
    
    # VLE manuals
    for vle_manual in ['vlepim', 'vlepem']:
        vle_dir = DOCS_ROOT / vle_manual
        if vle_dir.exists():
            for chapter_file in sorted(vle_dir.glob("Chapter_*.txt")):
                chapter_instructions = extract_from_manual_chapter(chapter_file)
                if chapter_instructions:
                    manual_instructions[vle_manual].update(chapter_instructions)
    
    return manual_instructions


def extract_llvm_instructions() -> Set[str]:
    """Extract instruction definitions from LLVM .td files"""
    llvm_instructions = set()
    
    if not LLVM_INSTR_DIR.exists():
        print(f"Warning: {LLVM_INSTR_DIR} not found")
        return llvm_instructions
    
    # Pattern to match instruction definitions in TableGen files
    # Examples: "def ADDI", "def E_ADDI", "def : Pat<", etc.
    patterns = [
        r'^\s*def\s+([A-Z][A-Z0-9_]*)\s*:',  # def INSTRUCTION_NAME
        r'let\s+Name\s*=\s*"([a-z_][a-z0-9_]*)"',  # Name = "instruction_name"
    ]
    
    for td_file in LLVM_INSTR_DIR.glob("PPCInstr*.td"):
        with open(td_file, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
            for pattern in patterns:
                matches = re.findall(pattern, content, re.MULTILINE)
                for match in matches:
                    # Normalize to lowercase
                    instr = match.lower()
                    if instr and len(instr) >= 2:
                        llvm_instructions.add(instr)
    
    return llvm_instructions


def main():
    """Main extraction and comparison function"""
    print("Extracting opcodes from documentation...")
    
    # Extract from Power ISA 2.07 instruction list
    isa_207_instructions = extract_instructions_from_isa_list(ISA_207_LIST)
    print(f"Found {len(isa_207_instructions)} instructions in Power ISA 2.07 list")
    
    # Extract from all manuals
    manual_instructions = extract_from_all_manuals()
    total_manual_instructions = set()
    for manual, instructions in manual_instructions.items():
        print(f"Found {len(instructions)} instructions in {manual}")
        total_manual_instructions.update(instructions)
    
    # Combine all extracted instructions
    all_extracted = isa_207_instructions | total_manual_instructions
    print(f"\nTotal unique instructions extracted: {len(all_extracted)}")
    
    # Extract LLVM instructions
    print("\nExtracting LLVM instruction definitions...")
    llvm_instructions = extract_llvm_instructions()
    print(f"Found {len(llvm_instructions)} instruction definitions in LLVM")
    
    # Find missing instructions
    # Normalize both sets for comparison
    normalized_extracted = {instr.lower().replace('_', '') for instr in all_extracted}
    normalized_llvm = {instr.lower().replace('_', '') for instr in llvm_instructions}
    
    # This is a rough comparison - exact matching would need more sophisticated normalization
    print("\n" + "="*80)
    print("EXTRACTION COMPLETE")
    print("="*80)
    print(f"\nExtracted instructions: {len(all_extracted)}")
    print(f"LLVM definitions: {len(llvm_instructions)}")
    print("\nNote: Detailed comparison requires manual review due to naming differences")
    print("between documentation mnemonics and LLVM TableGen definitions.")
    
    # Write results
    output_file = PROJECT_ROOT / "e200_core_reference_extracted" / "extracted_opcodes.txt"
    with open(output_file, 'w') as f:
        f.write("Extracted Opcodes from Core Reference Manuals\n")
        f.write("="*80 + "\n\n")
        f.write(f"Power ISA 2.07 List: {len(isa_207_instructions)} instructions\n")
        f.write("\n".join(sorted(isa_207_instructions)))
        f.write("\n\n" + "="*80 + "\n")
        f.write("By Manual:\n\n")
        for manual, instructions in sorted(manual_instructions.items()):
            f.write(f"{manual}: {len(instructions)} instructions\n")
            f.write("\n".join(sorted(instructions)))
            f.write("\n\n")
    
    print(f"\nResults written to: {output_file}")


if __name__ == "__main__":
    main()

