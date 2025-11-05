#!/usr/bin/env python3
"""
Extract VLE instruction encoding information from Core Reference Manuals.

This script searches for VLE instruction encoding formats in the extracted
documentation and generates a structured encoding reference.
"""

import re
from pathlib import Path
from typing import Dict, List, Tuple, Optional

DOCS_ROOT = Path(__file__).parent.parent / "e200_core_reference_extracted"

def find_vle_instruction_encodings() -> Dict[str, Dict]:
    """
    Search for VLE instruction encoding information in documentation files.
    
    Returns:
        Dictionary mapping instruction mnemonics to encoding information
    """
    encodings: Dict[str, Dict] = {}
    
    # Search patterns for instruction encoding formats
    patterns = [
        # Look for instruction format diagrams
        (r'e_(\w+)\s+.*?bits?\s+(\d+)[-–](\d+).*?(\d+)[-–](\d+)', re.IGNORECASE),
        # Look for opcode specifications
        (r'e_(\w+).*?opcode.*?(\d+).*?0x([0-9A-Fa-f]+)', re.IGNORECASE),
        # Look for instruction format tables
        (r'e_(\w+).*?Primary.*?Opcode.*?(\d+)', re.IGNORECASE),
    ]
    
    # Files to search
    search_files = [
        DOCS_ROOT / "vlepim" / "00_Full_Manual.txt",
        DOCS_ROOT / "vlepim" / "Chapter_03.txt",
        DOCS_ROOT / "vlepem" / "00_Full_Manual.txt",
        DOCS_ROOT / "erefrm" / "00_Full_Manual.txt",
        DOCS_ROOT / "z759" / "00_Full_Manual.txt",
        DOCS_ROOT / "z760" / "00_Full_Manual.txt",
    ]
    
    for file_path in search_files:
        if not file_path.exists():
            continue
            
        print(f"Searching {file_path.name}...")
        try:
            with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                content = f.read()
                
                # Look for known VLE instructions
                vle_instructions = [
                    'e_addi', 'e_addic', 'e_andi', 'e_ori', 'e_xori', 'e_subfic',
                    'e_b', 'e_bl', 'e_bc', 'e_bcl',
                    'e_cmpi', 'e_cmpli', 'e_cmp16i',
                    'e_lbzu', 'e_lhzu', 'e_lwzu', 'e_stbu', 'e_sthu', 'e_stwu',
                ]
                
                for instr in vle_instructions:
                    if instr.lower() in content.lower():
                        # Extract context around the instruction
                        pattern = rf'{re.escape(instr)}.*?(?:\n.*?){{0,20}}'
                        matches = re.finditer(pattern, content, re.IGNORECASE | re.MULTILINE)
                        
                        for match in matches:
                            context = match.group(0)
                            
                            # Look for opcode information
                            opcode_match = re.search(r'opcode.*?(\d+)|0x([0-9A-Fa-f]+).*?opcode', context, re.IGNORECASE)
                            if opcode_match:
                                if instr not in encodings:
                                    encodings[instr] = {
                                        'opcode': opcode_match.group(1) or opcode_match.group(2),
                                        'sources': []
                                    }
                                encodings[instr]['sources'].append(str(file_path.name))
                                
        except Exception as e:
            print(f"Error processing {file_path}: {e}")
            continue
    
    return encodings

def main() -> None:
    """Main extraction function."""
    print("Extracting VLE instruction encoding information...")
    print("=" * 70)
    
    encodings = find_vle_instruction_encodings()
    
    # Output results
    output_file = DOCS_ROOT / "VLE_ENCODING_EXTRACTED.txt"
    with open(output_file, 'w') as f:
        f.write("VLE Instruction Encoding Information\n")
        f.write("=" * 70 + "\n\n")
        f.write(f"Found {len(encodings)} instructions with encoding information.\n\n")
        
        for instr, info in sorted(encodings.items()):
            f.write(f"{instr}:\n")
            f.write(f"  Opcode: {info.get('opcode', 'Unknown')}\n")
            f.write(f"  Sources: {', '.join(info.get('sources', []))}\n")
            f.write("\n")
    
    print(f"\nExtraction complete. Results written to {output_file}")
    print(f"Found encoding information for {len(encodings)} instructions.")

if __name__ == "__main__":
    main()

