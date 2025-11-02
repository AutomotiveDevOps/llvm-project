#!/usr/bin/env python3
"""Compare Power ISA 2.07 specification against LLVM implementation."""

import re
from collections import defaultdict
from typing import Dict, Set, List


def load_spec_instructions() -> Dict[str, Set[str]]:
    """Load instructions from spec extraction."""
    spec_instructions = defaultdict(set)
    
    try:
        with open('powerisa_v2_07_instruction_list.txt', 'r') as f:
            current_category = None
            for line in f:
                line = line.strip()
                if not line or line.startswith('='):
                    continue
                if line.startswith('Power ISA') or line.startswith('Note:'):
                    continue
                
                # Category header
                if '(' in line and 'instructions)' in line:
                    match = re.match(r'(.+?)\s+\(\d+\s+instructions\)', line)
                    if match:
                        current_category = match.group(1).strip()
                    continue
                
                # Instruction line
                if current_category and line and not line.startswith('-'):
                    # Extract mnemonic (first word)
                    parts = line.split()
                    if parts:
                        mnemonic = parts[0].lower()
                        if len(mnemonic) >= 2 and mnemonic.isalnum():
                            spec_instructions[current_category].add(mnemonic)
    except FileNotFoundError:
        print("Warning: spec instruction list not found, using empty set")
    
    return dict(spec_instructions)


def load_llvm_instructions() -> Dict[str, Set[str]]:
    """Load instructions from LLVM extraction."""
    llvm_instructions = defaultdict(set)
    
    try:
        with open('llvm_ppc_instruction_list.txt', 'r') as f:
            current_category = None
            for line in f:
                line = line.strip()
                if not line or line.startswith('='):
                    continue
                if line.startswith('LLVM') or line.startswith('Note:'):
                    continue
                
                # Category header
                if '(' in line and 'instructions)' in line:
                    match = re.match(r'(.+?)\s+\(\d+\s+instructions\)', line)
                    if match:
                        current_category = match.group(1).strip()
                    continue
                
                # Instruction line
                if current_category and line and not line.startswith('-'):
                    mnemonic = line.strip().lower()
                    if len(mnemonic) >= 2:
                        llvm_instructions[current_category].add(mnemonic)
    except FileNotFoundError:
        print("Warning: LLVM instruction list not found, using empty set")
    
    return dict(llvm_instructions)


def normalize_mnemonic(mnemonic: str) -> str:
    """Normalize mnemonic for comparison (remove underscores, convert to lowercase)."""
    # Remove leading/trailing underscores
    mnemonic = mnemonic.strip('_').lower()
    # Convert common patterns
    mnemonic = mnemonic.replace('_', '')
    return mnemonic


def compare_categories(spec_inst: Dict[str, Set[str]], 
                       llvm_inst: Dict[str, Set[str]]) -> Dict:
    """Compare spec and LLVM instructions by category."""
    comparison = {}
    
    # Map spec categories to LLVM categories
    category_mapping = {
        'VLE-specific': 'VLE',
        'VLE-prefixed': 'VLE',
        'SPE (Signal Processing Engine)': 'SPE',
        'SPE Floating-Point': 'SPE',
        'SPE Vector': 'SPE',
        'Category: V': 'Altivec/VMX',
        'Base (Book I)': 'Base',
        '64-bit': '64-bit',
        'HTM': 'HTM',
        'DFP': 'DFP',
    }
    
    all_spec = set()
    all_llvm = set()
    
    for spec_cat, spec_set in spec_inst.items():
        all_spec.update(spec_set)
        
        # Find corresponding LLVM category
        llvm_cat = None
        for pattern, llvm_category in category_mapping.items():
            if pattern in spec_cat:
                llvm_cat = llvm_category
                break
        
        if llvm_cat is None:
            # Try direct match
            if spec_cat in llvm_inst:
                llvm_cat = spec_cat
        
        if llvm_cat and llvm_cat in llvm_inst:
            llvm_set = llvm_inst[llvm_cat]
            
            # Normalize for comparison
            spec_normalized = {normalize_mnemonic(m) for m in spec_set}
            llvm_normalized = {normalize_mnemonic(m) for m in llvm_set}
            
            # Handle VLE prefix (e_ in spec might match E_ in LLVM)
            spec_with_prefix = set()
            llvm_with_prefix = set()
            
            for m in spec_normalized:
                if m.startswith('e_'):
                    spec_with_prefix.add(m)
                    spec_with_prefix.add(m[2:])  # Also check without prefix
                else:
                    spec_with_prefix.add(m)
                    spec_with_prefix.add('e_' + m)  # Also check with prefix
            
            for m in llvm_normalized:
                if m.startswith('e_'):
                    llvm_with_prefix.add(m)
                    llvm_with_prefix.add(m[2:])
                else:
                    llvm_with_prefix.add(m)
                    llvm_with_prefix.add('e_' + m)
            
            # Find matches and misses
            matching = spec_normalized & llvm_normalized
            spec_only = spec_normalized - llvm_normalized
            llvm_only = llvm_normalized - spec_normalized
            
            comparison[spec_cat] = {
                'llvm_category': llvm_cat,
                'spec_count': len(spec_set),
                'llvm_count': len(llvm_set),
                'matching': len(matching),
                'spec_only': len(spec_only),
                'llvm_only': len(llvm_only),
                'coverage': len(matching) / len(spec_set) * 100 if spec_set else 0,
                'sample_missing': list(spec_only)[:10],
                'sample_extra': list(llvm_only)[:10]
            }
    
    # Overall comparison
    all_spec_normalized = {normalize_mnemonic(m) for m in all_spec}
    all_llvm_normalized = {normalize_mnemonic(m) for m in all_llvm}
    
    overall_matching = all_spec_normalized & all_llvm_normalized
    
    return {
        'by_category': comparison,
        'overall': {
            'spec_total': len(all_spec),
            'llvm_total': len(all_llvm),
            'matching': len(overall_matching),
            'coverage': len(overall_matching) / len(all_spec) * 100 if all_spec else 0
        }
    }


def generate_comparison_report():
    """Generate comprehensive comparison report."""
    print("=== Comparing Power ISA 2.07 vs LLVM Implementation ===\n")
    
    spec_inst = load_spec_instructions()
    llvm_inst = load_llvm_instructions()
    
    print(f"Spec categories: {len(spec_inst)}")
    print(f"LLVM categories: {len(llvm_inst)}")
    
    comparison = compare_categories(spec_inst, llvm_inst)
    
    print("\n=== Category-by-Category Comparison ===\n")
    
    for category in sorted(comparison['by_category'].keys()):
        comp = comparison['by_category'][category]
        print(f"{category}:")
        print(f"  Spec: {comp['spec_count']} instructions")
        print(f"  LLVM ({comp['llvm_category']}): {comp['llvm_count']} instructions")
        print(f"  Matching: {comp['matching']}")
        print(f"  Coverage: {comp['coverage']:.1f}%")
        if comp['spec_only'] > 0:
            print(f"  Missing from LLVM: {comp['spec_only']} instructions")
            print(f"    Sample: {', '.join(comp['sample_missing'][:5])}")
        if comp['llvm_only'] > 0:
            print(f"  Extra in LLVM: {comp['llvm_only']} instructions")
        print()
    
    print("=== Overall Summary ===\n")
    overall = comparison['overall']
    print(f"Spec total unique instructions: {overall['spec_total']}")
    print(f"LLVM total unique instructions: {overall['llvm_total']}")
    print(f"Matching instructions: {overall['matching']}")
    print(f"Overall coverage: {overall['coverage']:.1f}%")
    
    # Save report
    with open('powerisa_v2_07_completeness_report.md', 'w') as f:
        f.write("# Power ISA 2.07 Implementation Completeness Report\n\n")
        f.write("## Overview\n\n")
        f.write(f"This report compares Power ISA Version 2.07 (Book VLE) against LLVM PowerPC backend implementation.\n\n")
        f.write(f"**Note:** The available PowerISA_V2.07_PUBLIC.pdf contains Book VLE, which references ")
        f.write("instructions from Book I, II, and III-E. This analysis focuses on what's in Book VLE.\n\n")
        
        f.write("## Summary Statistics\n\n")
        f.write(f"- Spec instructions cataloged: {overall['spec_total']}\n")
        f.write(f"- LLVM instructions cataloged: {overall['llvm_total']}\n")
        f.write(f"- Matching instructions: {overall['matching']}\n")
        f.write(f"- **Coverage: {overall['coverage']:.1f}%**\n\n")
        
        f.write("## Category Breakdown\n\n")
        for category in sorted(comparison['by_category'].keys()):
            comp = comparison['by_category'][category]
            f.write(f"### {category}\n\n")
            f.write(f"- Spec: {comp['spec_count']} instructions\n")
            f.write(f"- LLVM ({comp['llvm_category']}): {comp['llvm_count']} instructions\n")
            f.write(f"- Coverage: {comp['coverage']:.1f}%\n")
            if comp['spec_only'] > 0:
                f.write(f"- Missing: {comp['spec_only']} instructions\n")
            if comp['llvm_only'] > 0:
                f.write(f"- Additional: {comp['llvm_only']} instructions (may be from newer ISA versions)\n")
            f.write("\n")
        
        f.write("## Notes\n\n")
        f.write("1. Instruction name matching accounts for case differences and VLE prefixes (e_)\n")
        f.write("2. LLVM may include instructions from Power ISA versions beyond 2.07\n")
        f.write("3. Some spec instructions may be aliases or have different names in LLVM\n")
        f.write("4. Complete Power ISA 2.07 analysis would require all books (I, II, III-S, III-E, VLE)\n")
    
    print("\nReport saved to powerisa_v2_07_completeness_report.md")


if __name__ == '__main__':
    generate_comparison_report()

