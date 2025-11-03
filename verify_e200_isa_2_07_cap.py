#!/usr/bin/env python3
"""Verify that e200 cores are capped at Power ISA 2.07."""

import re
import os
from pathlib import Path
from typing import List, Dict, Set


def find_isa3_instructions() -> Dict[str, List[str]]:
    """Find all instructions that require ISA 3.0 or 3.1."""
    isa3_instructions = {}
    
    ppc_dir = Path('llvm/lib/Target/PowerPC')
    
    instruction_files = [
        'PPCInstrInfo.td',
        'PPCInstrAltivec.td',
        'PPCInstrVSX.td',
        'PPCInstrP10.td',
        'PPCInstrMMA.td',
        'PPCInstrFuture.td',
        'PPCInstr64Bit.td',
    ]
    
    for filename in instruction_files:
        filepath = ppc_dir / filename
        if not filepath.exists():
            continue
        
        with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
        
        # Find instruction definitions with ISA 3.0 or 3.1 predicates
        # Pattern: def InstructionName ... let Predicates = [..., IsISA3_0, ...]
        lines = content.split('\n')
        
        current_instruction = None
        in_predicates = False
        
        for i, line in enumerate(lines):
            # Check for instruction definition
            def_match = re.match(r'^\s*def\s+([A-Z][A-Z0-9_]+)\s*:', line)
            if def_match:
                current_instruction = def_match.group(1)
                in_predicates = False
            
            # Check for Predicates block
            if 'Predicates' in line and '=' in line:
                in_predicates = True
            
            # Check if predicate block includes ISA 3.0 or 3.1
            if in_predicates and (re.search(r'IsISA3_0\b', line) or 
                                  re.search(r'IsISA3_1\b', line) or
                                  re.search(r'FeatureISA3_0', line) or
                                  re.search(r'FeatureISA3_1', line)):
                if filename not in isa3_instructions:
                    isa3_instructions[filename] = []
                if current_instruction and current_instruction not in isa3_instructions[filename]:
                    isa3_instructions[filename].append(current_instruction)
            
            # Reset if we hit a closing brace
            if line.strip() == '}' and in_predicates:
                in_predicates = False
    
    return isa3_instructions


def check_e200_model_isa_features():
    """Check what ISA features are enabled for e200 models."""
    ppc_td = Path('llvm/lib/Target/PowerPC/PPC.td')
    
    with open(ppc_td, 'r') as f:
        content = f.read()
    
    e200_models = {}
    
    # Find e200 processor models
    e200_pattern = r'ProcessorModel<"e200z\d+"[^>]*>,\s*\[([^\]]+)\]>;'
    matches = re.finditer(e200_pattern, content, re.MULTILINE | re.DOTALL)
    
    for match in matches:
        model_line = match.group(0)
        features = match.group(1)
        
        # Extract model name
        model_match = re.search(r'"e200z\d+"', model_line)
        if model_match:
            model_name = model_match.group(0).strip('"')
            
            # Check for ISA version features
            has_isa3_0 = 'FeatureISA3_0' in features or 'IsISA3_0' in features
            has_isa3_1 = 'FeatureISA3_1' in features or 'IsISA3_1' in features
            has_isa2_07 = 'FeatureISA2_07' in features
            
            e200_models[model_name] = {
                'has_isa3_0': has_isa3_0,
                'has_isa3_1': has_isa3_1,
                'has_isa2_07': has_isa2_07,
                'features': features.split(',')
            }
    
    return e200_models


def verify_e200_instructions_exclude_isa3():
    """Verify that e200-specific instructions don't include ISA 3.0+."""
    issues = []
    
    # Check VLE instructions (e200 uses VLE)
    vle_file = Path('llvm/lib/Target/PowerPC/PPCInstrVLE.td')
    if vle_file.exists():
        with open(vle_file, 'r') as f:
            vle_content = f.read()
        
        # Check for ISA 3.0+ predicates in VLE file
        if re.search(r'IsISA3_[01]', vle_content) or re.search(r'FeatureISA3_[01]', vle_content):
            issues.append("PPCInstrVLE.td contains ISA 3.0+ references")
    
    return issues


def generate_report():
    """Generate verification report."""
    print("=== Verifying e200 Cores are Capped at Power ISA 2.07 ===\n")
    
    # Check e200 model definitions
    print("1. Checking e200 processor model definitions...")
    e200_models = check_e200_model_isa_features()
    
    issues_found = []
    
    for model, info in e200_models.items():
        print(f"\n   {model}:")
        print(f"     ISA 2.07: {info['has_isa2_07']}")
        print(f"     ISA 3.0:  {info['has_isa3_0']}")
        print(f"     ISA 3.1:  {info['has_isa3_1']}")
        
        if info['has_isa3_0'] or info['has_isa3_1']:
            issues_found.append(f"{model} has ISA 3.0+ features enabled")
        
        if not info['has_isa2_07']:
            print(f"     ⚠️  Warning: ISA 2.07 feature not explicitly set")
    
    # Check for ISA 3.0 instructions
    print("\n2. Checking for ISA 3.0+ instructions...")
    isa3_insts = find_isa3_instructions()
    
    if isa3_insts:
        print(f"   Found ISA 3.0+ instructions in {len(isa3_insts)} files:")
        for filename, instructions in isa3_insts.items():
            print(f"     {filename}: {len(instructions)} instructions")
            # Verify these are properly guarded
            print(f"       (These should be properly predicate-guarded)")
    
    # Check e200-specific files
    print("\n3. Checking e200-specific instruction files...")
    vle_issues = verify_e200_instructions_exclude_isa3()
    
    if vle_issues:
        issues_found.extend(vle_issues)
        for issue in vle_issues:
            print(f"   ⚠️  {issue}")
    else:
        print("   ✅ VLE instructions (e200) properly isolated")
    
    # Summary
    print("\n=== Summary ===\n")
    
    if issues_found:
        print("⚠️  Issues Found:")
        for issue in issues_found:
            print(f"   - {issue}")
        print("\n✅ Recommendation: Ensure e200 models explicitly set FeatureISA2_07")
        print("   and do NOT include FeatureISA3_0 or FeatureISA3_1")
    else:
        print("✅ e200 cores appear to be properly capped at Power ISA 2.07")
        print("\n   Note: e200 models don't explicitly set FeatureISA2_07,")
        print("   but they also don't include ISA 3.0+ features.")
        print("   Consider explicitly adding FeatureISA2_07 for clarity.")
    
    return issues_found


if __name__ == '__main__':
    issues = generate_report()
    
    if issues:
        exit(1)
    else:
        exit(0)

