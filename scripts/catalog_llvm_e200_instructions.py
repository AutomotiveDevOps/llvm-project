#!/usr/bin/env python3
"""
Catalog LLVM PowerPC instruction definitions and identify which are available
for each e200 core via predicates.

This script:
1. Extracts all instruction definitions from LLVM PowerPC .td files
2. Maps LLVM instruction names to Power ISA mnemonics
3. Identifies predicates that enable/disable instructions
4. Determines which instructions are available for each e200 core
"""

import re
from pathlib import Path
from typing import Dict, List, Set, Tuple, Optional
from collections import defaultdict


def parse_predicates(instruction_block: str) -> Dict[str, bool]:
    """
    Parse predicates from an instruction definition.
    Returns dict of predicate -> True (required) or False (negated).
    """
    predicates = {}
    
    # Pattern: Predicates = [..., FeatureName, ...]
    pred_match = re.search(r'Predicates\s*=\s*\[([^\]]+)\]', instruction_block)
    if pred_match:
        pred_list = pred_match.group(1)
        # Split by comma, handle negation
        for pred in re.split(r'[,]', pred_list):
            pred = pred.strip()
            if pred.startswith('!') or pred.startswith('~'):
                pred_name = pred[1:].strip()
                predicates[pred_name] = False  # Negated
            else:
                predicates[pred.strip()] = True  # Required
    
    return predicates


def extract_instruction_definitions(file_path: Path) -> List[Dict]:
    """Extract instruction definitions from a TableGen file."""
    instructions = []
    
    if not file_path.exists():
        return instructions
    
    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    # Pattern: def INST_NAME : INST_FORMAT { ... }
    # We need to capture the full block to parse predicates
    pattern = r'def\s+([A-Z][A-Z0-9_]+)\s*:\s*([A-Z][A-Z0-9_]+)\s*\{([^}]+)\}'
    
    matches = re.finditer(pattern, content, re.MULTILINE | re.DOTALL)
    
    for match in matches:
        inst_name = match.group(1)
        inst_format = match.group(2)
        inst_block = match.group(3)
        
        # Extract mnemonic (if specified)
        mnemonic_match = re.search(r'Mnemonic\s*=\s*"([^"]+)"', inst_block)
        mnemonic = mnemonic_match.group(1).lower() if mnemonic_match else None
        
        # Extract predicates
        predicates = parse_predicates(inst_block)
        
        instructions.append({
            'llvm_name': inst_name,
            'format': inst_format,
            'isa_mnemonic': mnemonic,
            'predicates': predicates,
            'file': file_path.name,
            'full_block': inst_block[:200]  # First 200 chars for debugging
        })
    
    # Also look for simple def patterns without predicates
    simple_pattern = r'def\s+([A-Z][A-Z0-9_]+)\s*:\s*([A-Z][A-Z0-9_]+)[\s;]'
    simple_matches = re.finditer(simple_pattern, content)
    for match in simple_matches:
        inst_name = match.group(1)
        inst_format = match.group(2)
        
        # Skip if already captured
        if any(i['llvm_name'] == inst_name for i in instructions):
            continue
        
        instructions.append({
            'llvm_name': inst_name,
            'format': inst_format,
            'isa_mnemonic': None,
            'predicates': {},
            'file': file_path.name,
            'full_block': ''
        })
    
    return instructions


def map_llvm_to_isa_mnemonic(llvm_name: str, mnemonic_from_def: Optional[str] = None) -> str:
    """
    Map LLVM instruction name to Power ISA mnemonic.
    Handles naming conventions like ADD4 -> add, E_ADD -> e_add, etc.
    """
    if mnemonic_from_def:
        return mnemonic_from_def.lower()
    
    # Remove common LLVM suffixes
    name = llvm_name
    
    # Remove record bit indicator (usually last char if it's a suffix)
    # But keep if it's part of the instruction like ADD4 (which is add)
    
    # Handle VLE prefixes
    if name.startswith('E_') or name.startswith('SE_'):
        # E_ADD -> e_add, SE_LWZ -> se_lwz
        name = name.lower().replace('_', '_')
        return name.lower()
    
    # Handle common patterns
    # ADD4 -> add, ADD8 -> add (64-bit variant)
    if re.match(r'[A-Z]+[48]$', name):
        base = name[:-1].lower()
        return base
    
    # ADD -> add
    name = name.lower()
    
    # Convert underscores (internal naming) to base mnemonic
    # ADDI -> addi
    name = name.replace('_', '')
    
    return name


def check_e200_availability(instruction: Dict, e200_features: Set[str]) -> bool:
    """
    Check if an instruction is available for e200 cores.
    
    e200_features: Set of features that e200 cores have (e.g., FeatureE200, FeatureVLE, FeatureISA2_07)
    """
    predicates = instruction.get('predicates', {})
    
    # If no predicates, instruction is generally available
    if not predicates:
        # But check if instruction is explicitly excluded for e200
        # Some instructions are ISA 3.0+ only
        if 'ISA3' in instruction.get('llvm_name', '') or \
           any('ISA3' in p for p in predicates.keys()):
            return False
        return True
    
    # Check if all required predicates are in e200_features
    for pred, required in predicates.items():
        if required:
            # Required predicate must be in e200_features
            if pred not in e200_features:
                # Special cases: some predicates imply availability
                if pred in ['IsISA2_07', 'FeatureISA2_07']:
                    # ISA 2.07 is base, so if not explicitly excluded, it's available
                    continue
                return False
        else:
            # Negated predicate must NOT be in e200_features
            if pred in e200_features:
                return False
    
    return True


def get_e200_core_features() -> Dict[str, Set[str]]:
    """Get feature sets for each e200 core."""
    # Based on PPC.td processor model definitions
    # This is a simplified mapping - actual features come from processor model
    return {
        'e200z0': {
            'FeatureE200', 'FeatureVLE', 'FeatureISA2_07', 'FeatureICBT',
            'FeatureBookE', 'FeatureISEL', 'FeatureMFTB', 'FeatureMSYNC'
        },
        'e200z3': {
            'FeatureE200', 'FeatureVLE', 'FeatureISA2_07', 'FeatureICBT',
            'FeatureBookE', 'FeatureISEL', 'FeatureMFTB', 'FeatureMSYNC'
        },
        'e200z4': {
            'FeatureE200', 'FeatureVLE', 'FeatureISA2_07', 'FeatureICBT',
            'FeatureBookE', 'FeatureISEL', 'FeatureMFTB', 'FeatureMSYNC',
            'FeatureSPE', 'FeatureFPU'
        },
        'e200z6': {
            'FeatureE200', 'FeatureVLE', 'FeatureISA2_07', 'FeatureICBT',
            'FeatureBookE', 'FeatureISEL', 'FeatureMFTB', 'FeatureMSYNC',
            'FeatureSPE', 'FeatureFPU'
        },
        'e200z7': {
            'FeatureE200', 'FeatureVLE', 'FeatureISA2_07', 'FeatureICBT',
            'FeatureBookE', 'FeatureISEL', 'FeatureMFTB', 'FeatureMSYNC',
            'FeatureSPE', 'FeatureFPU'
        },
    }


def catalog_all_instructions() -> Dict[str, List[Dict]]:
    """Catalog all instructions from LLVM PowerPC backend."""
    base_dir = Path('.')
    ppc_dir = base_dir / 'llvm' / 'lib' / 'Target' / 'PowerPC'
    
    instruction_files = [
        'PPCInstrInfo.td',
        'PPCInstrVLE.td',
        'PPCInstrSPE.td',
        'PPCInstrAltivec.td',
        'PPCInstrVSX.td',
        'PPCInstr64Bit.td',
        'PPCInstrDFP.td',
        'PPCInstrHTM.td',
        'PPCInstrP10.td',
        'PPCInstrMMA.td',
        'PPCInstrFuture.td',
    ]
    
    all_instructions = []
    by_file = defaultdict(list)
    
    print("=== Cataloging LLVM PowerPC Instructions ===\n")
    
    for filename in instruction_files:
        file_path = ppc_dir / filename
        if file_path.exists():
            print(f"Reading {filename}...")
            insts = extract_instruction_definitions(file_path)
            all_instructions.extend(insts)
            by_file[filename] = insts
            print(f"  Found {len(insts)} instruction definitions")
        else:
            print(f"  Warning: {filename} not found")
    
    print(f"\nTotal instructions found: {len(all_instructions)}")
    
    return {
        'all': all_instructions,
        'by_file': dict(by_file)
    }


def analyze_e200_availability(catalog: Dict) -> Dict[str, Dict[str, List[str]]]:
    """Analyze which instructions are available for each e200 core."""
    e200_features = get_e200_core_features()
    
    results = {}
    
    for core_name, features in e200_features.items():
        print(f"\nAnalyzing {core_name} availability...")
        available = []
        
        for inst in catalog['all']:
            # Map to ISA mnemonic
            isa_mnemonic = map_llvm_to_isa_mnemonic(
                inst['llvm_name'],
                inst.get('isa_mnemonic')
            )
            
            # Check availability
            if check_e200_availability(inst, features):
                available.append(isa_mnemonic)
        
        results[core_name] = {
            'available': sorted(set(available)),
            'count': len(set(available))
        }
        print(f"  {results[core_name]['count']} instructions available")
    
    return results


def main():
    """Main execution."""
    # Catalog all instructions
    catalog = catalog_all_instructions()
    
    # Analyze e200 availability
    e200_availability = analyze_e200_availability(catalog)
    
    # Write results
    output_dir = Path('.')
    output_file = output_dir / 'llvm_e200_instructions_catalog.txt'
    
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write("LLVM PowerPC Instructions - e200 Core Availability\n")
        f.write("=" * 80 + "\n\n")
        
        for core_name, availability in e200_availability.items():
            f.write(f"\n### {core_name.upper()}\n\n")
            f.write(f"Available Instructions ({availability['count']} total):\n")
            f.write("-" * 80 + "\n")
            for inst in availability['available'][:100]:  # First 100
                f.write(f"  {inst}\n")
            if len(availability['available']) > 100:
                f.write(f"  ... and {len(availability['available']) - 100} more\n")
    
    print(f"\nCatalog written to: {output_file}")
    print(f"Total LLVM instructions: {len(catalog['all'])}")
    
    return catalog, e200_availability


if __name__ == '__main__':
    catalog, availability = main()

