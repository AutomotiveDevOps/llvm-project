#!/usr/bin/env python3
"""
Compare Power ISA 2.07 + e200 manual specifications vs LLVM implementation
to identify missing instructions.

This script:
1. Loads Power ISA 2.07 instruction set
2. Filters by e200 core unsupported instructions from manuals
3. Compares against LLVM implementation
4. Identifies missing instructions per core
"""

import re
from pathlib import Path
from typing import Dict, List, Set, Tuple
from collections import defaultdict


def load_powerisa_instructions() -> Set[str]:
    """Load Power ISA 2.07 instruction set."""
    file_path = Path('powerisa_v2_07_instruction_set.txt')
    
    if not file_path.exists():
        print(f"Warning: {file_path} not found")
        return set()
    
    instructions = set()
    with open(file_path, 'r', encoding='utf-8') as f:
        for line in f:
            line = line.strip()
            if line and not line.startswith('#'):
                # First word is mnemonic
                mnemonic = line.split()[0].lower().strip()
                if mnemonic:
                    instructions.add(mnemonic)
    
    print(f"Loaded {len(instructions)} Power ISA 2.07 instructions")
    return instructions


def load_e200_unsupported(core_name: str) -> Set[str]:
    """Load unsupported instructions for an e200 core from manual extraction."""
    # From e200_manual_instructions_extracted.txt
    file_path = Path('e200_manual_instructions_extracted.txt')
    
    if not file_path.exists():
        return set()
    
    unsupported = set()
    with open(file_path, 'r', encoding='utf-8') as f:
        content = f.read()
        
        # Find section for this core
        core_section_pattern = rf'### {core_name.upper()}.*?\n\nUnsupported Instructions.*?\n(.*?)(?=\n\n|###|$)'
        match = re.search(core_section_pattern, content, re.DOTALL)
        
        if match:
            section = match.group(1)
            # Extract instruction names (lines starting with "  - ")
            for line in section.split('\n'):
                if line.strip().startswith('- '):
                    inst = line.strip()[2:].strip().lower()
                    # Filter out false positives
                    if inst and len(inst) >= 2 and len(inst) <= 15 and \
                       re.match(r'^[a-z][a-z0-9_]*$', inst) and \
                       inst not in ['string', 'supported', 'unsupported', 'these', 'the']:
                        unsupported.add(inst)
    
    # Add known unsupported instructions manually (from manual Chapter 3)
    known_unsupported = {
        'e200z0': {'lswi', 'lswx', 'stswi', 'stswx', 'mfapidi', 'mfdcrx', 'mtdcrx'},
        'e200z3': {'lswi', 'lswx', 'stswi', 'stswx', 'mfapidi', 'mfdcrx', 'mtdcrx', 'mcrfs', 'mffs'},
        'e200z4': {'lswi', 'lswx', 'stswi', 'stswx', 'mfapidi', 'mfdcrx', 'mtdcrx', 'mcrfs', 'mffs'},
        'e200z6': {'lbarx', 'lharx', 'mfapidi', 'mfdcrx', 'mtdcrx'},
        'e200z7': {'lbarx', 'lharx', 'mfapidi', 'mfdcrx', 'mtdcrx'},
    }
    
    if core_name in known_unsupported:
        unsupported.update(known_unsupported[core_name])
    
    return unsupported


def load_llvm_instructions() -> Set[str]:
    """Load LLVM-implemented instructions from existing inventory."""
    instructions = set()
    
    # Try multiple sources
    files_to_try = [
        'llvm_ppc_instruction_list.txt',
        'llvm_ppc_instructions_by_book.txt',
    ]
    
    for file_path_str in files_to_try:
        file_path = Path(file_path_str)
        if file_path.exists():
            with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                for line in f:
                    line = line.strip()
                    # Skip headers and empty lines
                    if line and not line.startswith('=') and not line.startswith('-') and \
                       not 'instructions' in line.lower() and len(line) < 50:
                        # Extract mnemonic (usually first word, lowercase)
                        words = line.split()
                        if words:
                            mnemonic = words[0].lower().strip()
                            # Filter to valid instruction names
                            if re.match(r'^[a-z][a-z0-9_]{1,15}$', mnemonic):
                                instructions.add(mnemonic)
    
    print(f"Loaded {len(instructions)} LLVM instructions")
    return instructions


def normalize_instruction(mnemonic: str) -> str:
    """Normalize instruction mnemonic for comparison."""
    # Remove record bit indicator
    mnemonic = re.sub(r'\.$', '', mnemonic.lower())
    # Remove common suffixes that don't change base instruction
    mnemonic = re.sub(r'[48]$', '', mnemonic)  # ADD4, ADD8 -> add
    return mnemonic


def categorize_instruction(mnemonic: str) -> str:
    """Categorize instruction by type."""
    mnemonic_lower = mnemonic.lower()
    
    if mnemonic_lower.startswith('e_') or mnemonic_lower.startswith('se_'):
        return 'VLE'
    elif mnemonic_lower.startswith('ef') or mnemonic_lower.startswith('ev'):
        return 'SPE'
    elif mnemonic_lower.startswith('v') and len(mnemonic_lower) > 1:
        return 'Vector/Altivec'
    elif any(fp in mnemonic_lower for fp in ['fadd', 'fsub', 'fmul', 'fdiv', 'fabs', 'fneg']):
        return 'Floating-Point'
    elif any(mem in mnemonic_lower for mem in ['load', 'store', 'lw', 'sw', 'lb', 'sb', 'lh', 'sh']):
        return 'Load/Store'
    elif any(branch in mnemonic_lower for branch in ['b', 'branch', 'jump', 'ret']):
        return 'Branch'
    elif 'sync' in mnemonic_lower or 'barrier' in mnemonic_lower:
        return 'Memory Barrier'
    elif 'dcb' in mnemonic_lower or 'icb' in mnemonic_lower or 'tlb' in mnemonic_lower:
        return 'Cache/TLB'
    elif 'spr' in mnemonic_lower or 'mf' in mnemonic_lower or 'mt' in mnemonic_lower:
        return 'SPR Access'
    else:
        return 'Fixed-Point'


def compare_per_core(powerisa: Set[str], llvm: Set[str], core_name: str) -> Dict:
    """Compare Power ISA 2.07 vs LLVM for a specific e200 core."""
    
    # Get unsupported instructions for this core
    unsupported = load_e200_unsupported(core_name)
    
    # Expected instruction set: Power ISA 2.07 minus unsupported
    expected = powerisa - unsupported
    
    # Normalize for comparison
    expected_normalized = {normalize_instruction(inst) for inst in expected}
    llvm_normalized = {normalize_instruction(inst) for inst in llvm}
    
    # Find missing instructions
    missing = expected_normalized - llvm_normalized
    
    # Categorize missing instructions
    missing_by_category = defaultdict(list)
    for inst in missing:
        # Find original mnemonic (non-normalized)
        original = next((i for i in expected if normalize_instruction(i) == inst), inst)
        category = categorize_instruction(original)
        missing_by_category[category].append(original)
    
    # Sort each category
    for category in missing_by_category:
        missing_by_category[category].sort()
    
    return {
        'expected_count': len(expected),
        'llvm_count': len([i for i in llvm if normalize_instruction(i) in expected_normalized]),
        'missing': sorted(missing),
        'missing_by_category': dict(missing_by_category),
        'missing_count': len(missing),
        'unsupported_count': len(unsupported)
    }


def main():
    """Main execution."""
    print("=== Comparing Power ISA 2.07 + e200 Manuals vs LLVM ===\n")
    
    # Load instruction sets
    powerisa = load_powerisa_instructions()
    llvm = load_llvm_instructions()
    
    # Compare for each e200 core
    cores = ['e200z0', 'e200z3', 'e200z4', 'e200z6', 'e200z7']
    
    all_results = {}
    
    for core_name in cores:
        print(f"\nAnalyzing {core_name}...")
        results = compare_per_core(powerisa, llvm, core_name)
        all_results[core_name] = results
        
        print(f"  Expected: {results['expected_count']} instructions")
        print(f"  Implemented in LLVM: {results['llvm_count']} instructions")
        print(f"  Missing: {results['missing_count']} instructions")
        print(f"  Unsupported (excluded): {results['unsupported_count']} instructions")
    
    # Write detailed reports
    output_dir = Path('.')
    
    for core_name, results in all_results.items():
        report_file = output_dir / f"{core_name}_missing_instructions.md"
        
        with open(report_file, 'w', encoding='utf-8') as f:
            f.write(f"# {core_name.upper()} Missing Instructions Report\n\n")
            f.write(f"## Summary\n\n")
            f.write(f"- **Expected Instructions**: {results['expected_count']}\n")
            f.write(f"- **Implemented in LLVM**: {results['llvm_count']}\n")
            f.write(f"- **Missing Instructions**: {results['missing_count']}\n")
            f.write(f"- **Coverage**: {100 * results['llvm_count'] / results['expected_count']:.1f}%\n\n")
            
            if results['missing']:
                f.write(f"## Missing Instructions by Category\n\n")
                for category in sorted(results['missing_by_category'].keys()):
                    insts = results['missing_by_category'][category]
                    f.write(f"### {category} ({len(insts)})\n\n")
                    for inst in insts:
                        f.write(f"- `{inst}`\n")
                    f.write("\n")
            else:
                f.write("## No Missing Instructions\n\n")
                f.write("All Power ISA 2.07 instructions (excluding unsupported) are implemented.\n")
        
        print(f"  Report written to: {report_file}")
    
    # Write summary report
    summary_file = output_dir / 'e200_missing_instructions_summary.md'
    with open(summary_file, 'w', encoding='utf-8') as f:
        f.write("# e200 Missing Instructions Summary\n\n")
        f.write("## Overview\n\n")
        f.write("This report identifies Power ISA 2.07 instructions that should be supported\n")
        f.write("by each e200 core (per their reference manuals) but are not yet implemented in LLVM.\n\n")
        
        f.write("## Per-Core Summary\n\n")
        for core_name in cores:
            results = all_results[core_name]
            f.write(f"### {core_name.upper()}\n\n")
            f.write(f"- Expected: {results['expected_count']} instructions\n")
            f.write(f"- Implemented: {results['llvm_count']} instructions\n")
            f.write(f"- Missing: {results['missing_count']} instructions\n")
            f.write(f"- Coverage: {100 * results['llvm_count'] / results['expected_count']:.1f}%\n\n")
        
        f.write("## Consolidated Missing Instructions\n\n")
        # Find instructions missing across multiple cores
        missing_all_cores = set()
        for core_name in cores:
            missing_all_cores.update(all_results[core_name]['missing'])
        
        if missing_all_cores:
            f.write(f"Total unique missing instructions: {len(missing_all_cores)}\n\n")
            f.write("Missing instructions:\n")
            for inst in sorted(missing_all_cores):
                # Count how many cores are missing it
                missing_cores = [cn for cn in cores if inst in all_results[cn]['missing']]
                f.write(f"- `{inst}` (missing in: {', '.join(missing_cores)})\n")
        else:
            f.write("No missing instructions found.\n")
    
    print(f"\nSummary report written to: {summary_file}")
    
    return all_results


if __name__ == '__main__':
    results = main()

