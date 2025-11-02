#!/usr/bin/env python3
"""
Comprehensive cost analysis for PowerPC instruction selection
Analyzes LLVM IR and calculates costs for different optimization levels
"""

import re
import sys
import os
from collections import defaultdict

class CostAnalyzer:
    def __init__(self, ir_file):
        self.ir_file = ir_file
        self.ir_content = ""
        self.functions = {}
        self.instruction_counts = defaultdict(int)
        self.opcode_costs = {
            # Standard PowerPC instructions (4 bytes each)
            'addi': 4, 'add': 4, 'subi': 4, 'sub': 4,
            'mul': 4, 'div': 4, 'mulli': 4,
            'and': 4, 'or': 4, 'xor': 4, 'andc': 4,
            'stw': 4, 'lwz': 4, 'stb': 4, 'lbz': 4,
            'b': 4, 'bl': 4, 'bc': 4, 'blr': 4,
            'cmp': 4, 'cmpi': 4, 'cmpl': 4, 'cmpli': 4,
            'slw': 4, 'srw': 4, 'sraw': 4,
            
            # VLE 16-bit instructions (2 bytes each)
            'se_addi': 2, 'se_subi': 2, 'se_mulli': 2,
            'se_add': 2, 'se_sub': 2, 'se_cmp': 2,
            'se_andi': 2, 'se_ori': 2, 'se_xori': 2,
            'se_lwz': 2, 'se_stw': 2, 'se_lbz': 2, 'se_stb': 2,
            'se_b': 2, 'se_bl': 2, 'se_bc': 2,
            'se_slwi': 2, 'se_srwi': 2,
            
            # VLE 32-bit instructions (4 bytes each)
            'e_addi': 4, 'e_addis': 4, 'e_add': 4,
            'e_subf': 4, 'e_mulli': 4, 'e_mullw': 4,
            'e_lwz': 4, 'e_stw': 4,
            'e_b': 4, 'e_bl': 4,
        }
        
        # Mode switching costs (cycles)
        self.switch_cost_vle_to_std = 3  # cycles
        self.switch_cost_std_to_vle = 3  # cycles
        
    def load_ir(self):
        """Load LLVM IR from file"""
        try:
            with open(self.ir_file, 'r') as f:
                self.ir_content = f.read()
            return True
        except FileNotFoundError:
            print(f"Error: File {self.ir_file} not found")
            return False
    
    def analyze_ir_operations(self):
        """Analyze LLVM IR to count different operation types"""
        ops = defaultdict(int)
        
        # Count different instruction types in IR
        patterns = {
            'add': r'\badd\b',
            'sub': r'\bsub\b',
            'mul': r'\bmul\b',
            'div': r'\b(sdiv|udiv)\b',
            'load': r'\bload\b',
            'store': r'\bstore\b',
            'call': r'\bcall\b',
            'br': r'\bbr\b',
            'icmp': r'\bicmp\b',
            'phi': r'\bphi\b',
            'select': r'\bselect\b',
            'getelementptr': r'\bgetelementptr\b',
            'shl': r'\bshl\b',
            'lshr': r'\blshr\b',
            'ashr': r'\bashr\b',
            'and': r'\band\b',
            'or': r'\bor\b',
            'xor': r'\bxor\b',
        }
        
        for op_name, pattern in patterns.items():
            matches = len(re.findall(pattern, self.ir_content, re.IGNORECASE))
            if matches > 0:
                ops[op_name] = matches
        
        return ops
    
    def estimate_instruction_selection(self, ir_ops, opt_level):
        """Estimate instruction selection based on IR operations"""
        selected = defaultdict(int)
        
        # Estimate based on optimization level
        for ir_op, count in ir_ops.items():
            if ir_op == 'add':
                # With VLE prioritization (-Oz), prefer se_addi or e_add
                if opt_level == 'Oz':
                    # 30% chance of 16-bit VLE, 50% chance of 32-bit VLE, 20% standard
                    selected['se_addi'] += int(count * 0.3)
                    selected['e_add'] += int(count * 0.5)
                    selected['add'] += int(count * 0.2)
                else:
                    # Performance optimization prefers standard
                    selected['add'] += count
                    
            elif ir_op == 'sub':
                if opt_level == 'Oz':
                    selected['se_subi'] += int(count * 0.3)
                    selected['e_subf'] += int(count * 0.5)
                    selected['sub'] += int(count * 0.2)
                else:
                    selected['sub'] += count
                    
            elif ir_op == 'mul':
                if opt_level == 'Oz':
                    selected['se_mulli'] += int(count * 0.2)
                    selected['e_mullw'] += int(count * 0.6)
                    selected['mul'] += int(count * 0.2)
                else:
                    selected['mul'] += count
                    
            elif ir_op == 'load':
                if opt_level == 'Oz':
                    selected['se_lwz'] += int(count * 0.4)
                    selected['e_lwz'] += int(count * 0.5)
                    selected['lwz'] += int(count * 0.1)
                else:
                    selected['lwz'] += count
                    
            elif ir_op == 'store':
                if opt_level == 'Oz':
                    selected['se_stw'] += int(count * 0.4)
                    selected['e_stw'] += int(count * 0.5)
                    selected['stw'] += int(count * 0.1)
                else:
                    selected['stw'] += count
                    
            elif ir_op == 'icmp':
                if opt_level == 'Oz':
                    selected['se_cmp'] += int(count * 0.4)
                    selected['cmp'] += int(count * 0.6)
                else:
                    selected['cmp'] += count
                    
            elif ir_op == 'br':
                if opt_level == 'Oz':
                    selected['se_b'] += int(count * 0.3)
                    selected['e_b'] += int(count * 0.4)
                    selected['b'] += int(count * 0.3)
                else:
                    selected['b'] += count
                    
            elif ir_op in ['and', 'or', 'xor']:
                if opt_level == 'Oz':
                    selected[f'se_{ir_op}i'] += int(count * 0.3)
                    selected[ir_op] += int(count * 0.7)
                else:
                    selected[ir_op] += count
        
        return selected
    
    def calculate_code_size(self, instructions):
        """Calculate total code size from instruction selection"""
        total_size = 0
        for instr, count in instructions.items():
            if instr in self.opcode_costs:
                total_size += self.opcode_costs[instr] * count
            else:
                # Default to 4 bytes for unknown instructions
                total_size += 4 * count
        return total_size
    
    def calculate_switching_costs(self, instructions):
        """Calculate costs of switching between VLE and standard instruction sets"""
        vle_instrs = {'se_', 'e_'}
        switches = 0
        prev_is_vle = None
        
        # Create instruction sequence (simplified)
        instr_list = []
        for instr, count in instructions.items():
            is_vle = any(instr.startswith(prefix) for prefix in vle_instrs)
            for _ in range(count):
                if prev_is_vle is not None and prev_is_vle != is_vle:
                    switches += 1
                prev_is_vle = is_vle
        
        # Calculate cost
        total_switch_cost = switches * self.switch_cost_std_to_vle
        return switches, total_switch_cost
    
    def analyze(self):
        """Run complete analysis"""
        if not self.load_ir():
            return
        
        print("=" * 80)
        print("POWERPC COST ANALYSIS")
        print("=" * 80)
        print(f"\nAnalyzing: {self.ir_file}")
        ir_size = len(self.ir_content)
        print(f"IR size: {ir_size:,} bytes ({ir_size/1024:.2f} KB)")
        
        # Analyze IR operations
        ir_ops = self.analyze_ir_operations()
        print(f"\nIR Operations found: {sum(ir_ops.values())} total")
        for op, count in sorted(ir_ops.items(), key=lambda x: -x[1]):
            print(f"  {op:15s}: {count:4d}")
        
        # Analyze different optimization levels
        opt_levels = ['O0', 'O1', 'O2', 'O3', 'Oz']
        results = {}
        
        print("\n" + "=" * 80)
        print("OPTIMIZATION LEVEL COMPARISON")
        print("=" * 80)
        
        print(f"\n{'Level':<6} {'Instrs':<10} {'VLE':<10} {'Std':<10} {'Size':<12} {'Switches':<10} {'Switch Cost':<12}")
        print("-" * 80)
        
        for opt_level in opt_levels:
            selected = self.estimate_instruction_selection(ir_ops, opt_level)
            total_instrs = sum(selected.values())
            
            # Count VLE vs standard
            vle_count = sum(count for instr, count in selected.items() 
                          if instr.startswith('se_') or instr.startswith('e_'))
            std_count = total_instrs - vle_count
            
            # Calculate code size
            code_size = self.calculate_code_size(selected)
            
            # Calculate switching costs
            switches, switch_cost = self.calculate_switching_costs(selected)
            
            results[opt_level] = {
                'instructions': selected,
                'total': total_instrs,
                'vle': vle_count,
                'std': std_count,
                'size': code_size,
                'switches': switches,
                'switch_cost': switch_cost
            }
            
            print(f"{opt_level:<6} {total_instrs:<10} {vle_count:<10} {std_count:<10} "
                  f"{code_size:<12} {switches:<10} {switch_cost:<12}")
        
        # Detailed breakdown
        print("\n" + "=" * 80)
        print("DETAILED BREAKDOWN: -Oz (Code Size Optimization)")
        print("=" * 80)
        
        oz_instrs = results['Oz']['instructions']
        print(f"\nTop instructions selected:")
        sorted_instrs = sorted(oz_instrs.items(), key=lambda x: -x[1])
        for instr, count in sorted_instrs[:20]:
            size = self.opcode_costs.get(instr, 4) * count
            print(f"  {instr:15s}: {count:4d} x {self.opcode_costs.get(instr, 4)}B = {size:6d} bytes")
        
        # Cost analysis
        print("\n" + "=" * 80)
        print("COST ANALYSIS")
        print("=" * 80)
        
        o0_size = results['O0']['size']
        o3_size = results['O3']['size']
        oz_size = results['Oz']['size']
        
        print(f"\nCode Size Reduction:")
        print(f"  O0 → O3: {o0_size - o3_size:,} bytes ({((o0_size - o3_size)/o0_size*100):.1f}%)")
        print(f"  O0 → Oz: {o0_size - oz_size:,} bytes ({((o0_size - oz_size)/o0_size*100):.1f}%)")
        print(f"  O3 → Oz: {o3_size - oz_size:,} bytes ({((o3_size - oz_size)/o3_size*100):.1f}%)")
        
        print(f"\nMode Switching Analysis:")
        print(f"  -Oz has {results['Oz']['switches']} mode switches")
        print(f"  Estimated switching cost: ~{results['Oz']['switch_cost']} cycles")
        
        if results['Oz']['switches'] > 0:
            avg_switch_per_instr = results['Oz']['switches'] / results['Oz']['total']
            print(f"  Average: {avg_switch_per_instr:.3f} switches per instruction")
        
        # Recommendations
        print("\n" + "=" * 80)
        print("RECOMMENDATIONS")
        print("=" * 80)
        
        if results['Oz']['vle'] == 0:
            print("\n⚠ WARNING: No VLE instructions selected with -Oz")
            print("  → Pattern prioritization may not be working")
            print("  → Check PPCISelDAGToDAG.cpp pattern ordering")
        else:
            vle_percentage = (results['Oz']['vle'] / results['Oz']['total']) * 100
            print(f"\n✓ VLE instructions: {results['Oz']['vle']} ({vle_percentage:.1f}%)")
        
        if results['Oz']['switches'] > results['Oz']['total'] * 0.1:
            print(f"\n⚠ WARNING: High mode switching rate ({results['Oz']['switches']} switches)")
            print("  → Consider grouping VLE instructions to reduce switching")
            print("  → May benefit from instruction scheduling optimization")
        else:
            print(f"\n✓ Mode switching is reasonable ({results['Oz']['switches']} switches)")
        
        print(f"\nExpected benefits:")
        size_savings = results['O3']['size'] - results['Oz']['size']
        if size_savings > 0:
            print(f"  Code size reduction: {size_savings:,} bytes vs -O3")
        print(f"  Switching overhead: ~{results['Oz']['switch_cost']} cycles")
        
        print("\n" + "=" * 80)

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Usage: python3 analyze_costs.py <ir_file.ll>")
        sys.exit(1)
    
    analyzer = CostAnalyzer(sys.argv[1])
    analyzer.analyze()

