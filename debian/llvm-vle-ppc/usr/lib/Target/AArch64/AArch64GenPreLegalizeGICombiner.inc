/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Global Combiner                                                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef AARCH64PRELEGALIZERCOMBINERHELPER_GENCOMBINERHELPER_DEPS
#include "llvm/ADT/SparseBitVector.h"
namespace llvm {
extern cl::OptionCategory GICombinerOptionCategory;
} // end namespace llvm
#endif // ifdef AARCH64PRELEGALIZERCOMBINERHELPER_GENCOMBINERHELPER_DEPS

#ifdef AARCH64PRELEGALIZERCOMBINERHELPER_GENCOMBINERHELPER_H
class AArch64GenPreLegalizerCombinerHelper {
  SparseBitVector<> DisabledRules;

public:
  bool parseCommandLineOption();
  bool isRuleDisabled(unsigned ID) const;
  bool setRuleDisabled(StringRef RuleIdentifier);

  bool tryCombineAll(
    GISelChangeObserver &Observer,
    MachineInstr &MI,
    MachineIRBuilder &B,
    CombinerHelper &Helper) const;
};

static Optional<uint64_t> getRuleIdxForIdentifier(StringRef RuleIdentifier) {
  uint64_t I;
  // getAtInteger(...) returns false on success
  bool Parsed = !RuleIdentifier.getAsInteger(0, I);
  if (Parsed)
    return I;

#ifndef NDEBUG
  switch (RuleIdentifier.size()) {
  default: break;
  case 9:	 // 1 string to match.
    if (memcmp(RuleIdentifier.data()+0, "copy_prop", 9) != 0)
      break;
    return 0;	 // "copy_prop"
  case 10:	 // 1 string to match.
    if (memcmp(RuleIdentifier.data()+0, "mul_to_shl", 10) != 0)
      break;
    return 1;	 // "mul_to_shl"
  case 14:	 // 1 string to match.
    if (memcmp(RuleIdentifier.data()+0, "binop_same_val", 14) != 0)
      break;
    return 14;	 // "binop_same_val"
  case 15:	 // 2 strings to match.
    switch (RuleIdentifier[0]) {
    default: break;
    case 'e':	 // 1 string to match.
      if (memcmp(RuleIdentifier.data()+1, "xtending_loads", 14) != 0)
        break;
      return 3;	 // "extending_loads"
    case 's':	 // 1 string to match.
      if (memcmp(RuleIdentifier.data()+1, "elect_same_val", 14) != 0)
        break;
      return 12;	 // "select_same_val"
    }
    break;
  case 16:	 // 1 string to match.
    if (memcmp(RuleIdentifier.data()+0, "undef_to_fp_zero", 16) != 0)
      break;
    return 5;	 // "undef_to_fp_zero"
  case 17:	 // 2 strings to match.
    switch (RuleIdentifier[0]) {
    default: break;
    case 'e':	 // 1 string to match.
      if (memcmp(RuleIdentifier.data()+1, "rase_undef_store", 16) != 0)
        break;
      return 11;	 // "erase_undef_store"
    case 'u':	 // 1 string to match.
      if (memcmp(RuleIdentifier.data()+1, "ndef_to_int_zero", 16) != 0)
        break;
      return 6;	 // "undef_to_int_zero"
    }
    break;
  case 18:	 // 1 string to match.
    if (memcmp(RuleIdentifier.data()+0, "binop_left_to_zero", 18) != 0)
      break;
    return 15;	 // "binop_left_to_zero"
  case 19:	 // 3 strings to match.
    switch (RuleIdentifier[0]) {
    default: break;
    case 'b':	 // 1 string to match.
      if (memcmp(RuleIdentifier.data()+1, "inop_right_to_zero", 18) != 0)
        break;
      return 16;	 // "binop_right_to_zero"
    case 'p':	 // 1 string to match.
      if (memcmp(RuleIdentifier.data()+1, "tr_add_immed_chain", 18) != 0)
        break;
      return 2;	 // "ptr_add_immed_chain"
    case 'r':	 // 1 string to match.
      if (memcmp(RuleIdentifier.data()+1, "ight_identity_zero", 18) != 0)
        break;
      return 13;	 // "right_identity_zero"
    }
    break;
  case 21:	 // 2 strings to match.
    switch (RuleIdentifier[0]) {
    default: break;
    case 'f':	 // 1 string to match.
      if (memcmp(RuleIdentifier.data()+1, "constant_to_constant", 20) != 0)
        break;
      return 18;	 // "fconstant_to_constant"
    case 'u':	 // 1 string to match.
      if (memcmp(RuleIdentifier.data()+1, "ndef_to_negative_one", 20) != 0)
        break;
      return 7;	 // "undef_to_negative_one"
    }
    break;
  case 22:	 // 1 string to match.
    if (memcmp(RuleIdentifier.data()+0, "propagate_undef_any_op", 22) != 0)
      break;
    return 8;	 // "propagate_undef_any_op"
  case 23:	 // 1 string to match.
    if (memcmp(RuleIdentifier.data()+0, "propagate_undef_all_ops", 23) != 0)
      break;
    return 9;	 // "propagate_undef_all_ops"
  case 26:	 // 2 strings to match.
    switch (RuleIdentifier[0]) {
    default: break;
    case 'c':	 // 1 string to match.
      if (memcmp(RuleIdentifier.data()+1, "ombine_indexed_load_store", 25) != 0)
        break;
      return 4;	 // "combine_indexed_load_store"
    case 'e':	 // 1 string to match.
      if (memcmp(RuleIdentifier.data()+1, "lide_br_by_inverting_cond", 25) != 0)
        break;
      return 17;	 // "elide_br_by_inverting_cond"
    }
    break;
  case 28:	 // 1 string to match.
    if (memcmp(RuleIdentifier.data()+0, "propagate_undef_shuffle_mask", 28) != 0)
      break;
    return 10;	 // "propagate_undef_shuffle_mask"
  }
#endif // ifndef NDEBUG

  return None;
}
bool AArch64GenPreLegalizerCombinerHelper::setRuleDisabled(StringRef RuleIdentifier) {
  std::pair<StringRef, StringRef> RangePair = RuleIdentifier.split('-');
  if (!RangePair.second.empty()) {
    const auto First = getRuleIdxForIdentifier(RangePair.first);
    const auto Last = getRuleIdxForIdentifier(RangePair.second);
    if (!First.hasValue() || !Last.hasValue())
      return false;
    if (First >= Last)
      report_fatal_error("Beginning of range should be before end of range");
    for (auto I = First.getValue(); I < Last.getValue(); ++I)
      DisabledRules.set(I);
    return true;
  } else {
    const auto I = getRuleIdxForIdentifier(RangePair.first);
    if (!I.hasValue())
      return false;
    DisabledRules.set(I.getValue());
    return true;
  }
  return false;
}
bool AArch64GenPreLegalizerCombinerHelper::isRuleDisabled(unsigned RuleID) const {
  return DisabledRules.test(RuleID);
}
#endif // ifdef AARCH64PRELEGALIZERCOMBINERHELPER_GENCOMBINERHELPER_H

#ifdef AARCH64PRELEGALIZERCOMBINERHELPER_GENCOMBINERHELPER_CPP

cl::list<std::string> AArch64PreLegalizerCombinerHelperOption(
    "aarch64prelegalizercombinerhelper-disable-rule",
    cl::desc("Disable one or more combiner rules temporarily in the AArch64PreLegalizerCombinerHelper pass"),
    cl::CommaSeparated,
    cl::Hidden,
    cl::cat(GICombinerOptionCategory));

bool AArch64GenPreLegalizerCombinerHelper::parseCommandLineOption() {
  for (const auto &Identifier : AArch64PreLegalizerCombinerHelperOption)
    if (!setRuleDisabled(Identifier))
      return false;
  return true;
}

bool AArch64GenPreLegalizerCombinerHelper::tryCombineAll(
    GISelChangeObserver &Observer,
    MachineInstr &MI,
    MachineIRBuilder &B,
    CombinerHelper &Helper) const {
  MachineBasicBlock *MBB = MI.getParent();
  MachineFunction *MF = MBB->getParent();
  MachineRegisterInfo &MRI = MF->getRegInfo();
  SmallVector<MachineInstr *, 8> MIs = { &MI };

  (void)MBB; (void)MF; (void)MRI;

  // Match data
  unsigned MatchData1;
  PtrAddChain MatchData2;
  PreferredTuple MatchData3;
  IndexedLoadStoreMatchInfo MatchData4;

  int Partition = -1;
  Partition = -1;
  switch (MIs[0]->getOpcode()) {
  case TargetOpcode::COPY: Partition = 0; break;
  case TargetOpcode::G_MUL: Partition = 1; break;
  case TargetOpcode::G_PTR_ADD: Partition = 2; break;
  case TargetOpcode::G_LOAD: Partition = 3; break;
  case TargetOpcode::G_SEXTLOAD: Partition = 4; break;
  case TargetOpcode::G_ZEXTLOAD: Partition = 5; break;
  case TargetOpcode::G_STORE: Partition = 6; break;
  case TargetOpcode::G_UITOFP: Partition = 7; break;
  case TargetOpcode::G_SITOFP: Partition = 8; break;
  case TargetOpcode::G_AND: Partition = 9; break;
  case TargetOpcode::G_OR: Partition = 10; break;
  case TargetOpcode::G_ADD: Partition = 11; break;
  case TargetOpcode::G_FPTOSI: Partition = 12; break;
  case TargetOpcode::G_FPTOUI: Partition = 13; break;
  case TargetOpcode::G_SUB: Partition = 14; break;
  case TargetOpcode::G_XOR: Partition = 15; break;
  case TargetOpcode::G_SHUFFLE_VECTOR: Partition = 16; break;
  case TargetOpcode::G_SELECT: Partition = 17; break;
  case TargetOpcode::G_SHL: Partition = 18; break;
  case TargetOpcode::G_ASHR: Partition = 19; break;
  case TargetOpcode::G_LSHR: Partition = 20; break;
  case TargetOpcode::G_SDIV: Partition = 21; break;
  case TargetOpcode::G_UDIV: Partition = 22; break;
  case TargetOpcode::G_SREM: Partition = 23; break;
  case TargetOpcode::G_UREM: Partition = 24; break;
  case TargetOpcode::G_BR: Partition = 25; break;
  case TargetOpcode::G_FCONSTANT: Partition = 26; break;
  }
  // Default case but without conflicting with potential default case in selection.
  if (Partition == -1) return false;
  if (Partition == 0 /* TargetOpcode::COPY */) {
    // Leaf name: copy_prop
    // Rule: copy_prop
    if (!isRuleDisabled(0)) {
      if (1
          && [&]() {
           return Helper.matchCombineCopy(*MIs[0]); 
          return true;
      }()) {
        Helper.applyCombineCopy(*MIs[0]); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 1 /* TargetOpcode::G_MUL */) {
    // Leaf name: mul_to_shl
    // Rule: mul_to_shl
    if (!isRuleDisabled(1)) {
      if (1
          && [&]() {
           return Helper.matchCombineMulToShl(*MIs[0], MatchData1); 
          return true;
      }()) {
        Helper.applyCombineMulToShl(*MIs[0], MatchData1); 
        return true;
      }
    }
    // Leaf name: undef_to_int_zero
    // Rule: undef_to_int_zero
    if (!isRuleDisabled(6)) {
      if (1
          && [&]() {
           return Helper.matchAnyExplicitUseIsUndef(*MIs[0]); 
          return true;
      }()) {
        Helper.replaceInstWithConstant(*MIs[0], 0); 
        return true;
      }
    }
    // Leaf name: binop_right_to_zero
    // Rule: binop_right_to_zero
    if (!isRuleDisabled(16)) {
      if (1
          && [&]() {
           return Helper.matchOperandIsZero(*MIs[0], 2); 
          return true;
      }()) {
        return Helper.replaceSingleDefInstWithOperand(*MIs[0], 2); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 2 /* TargetOpcode::G_PTR_ADD */) {
    // Leaf name: ptr_add_immed_chain
    // Rule: ptr_add_immed_chain
    if (!isRuleDisabled(2)) {
      if (1
          && [&]() {
           return Helper.matchPtrAddImmedChain(*MIs[0], MatchData2); 
          return true;
      }()) {
        Helper.applyPtrAddImmedChain(*MIs[0], MatchData2); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 3 /* TargetOpcode::G_LOAD */) {
    // Leaf name: extending_loads
    // Rule: extending_loads
    if (!isRuleDisabled(3)) {
      if (1
          && [&]() {
           return Helper.matchCombineExtendingLoads(*MIs[0], MatchData3); 
          return true;
      }()) {
        Helper.applyCombineExtendingLoads(*MIs[0], MatchData3); 
        return true;
      }
    }
    // Leaf name: combine_indexed_load_store
    // Rule: combine_indexed_load_store
    if (!isRuleDisabled(4)) {
      if (1
          && [&]() {
           return Helper.matchCombineIndexedLoadStore(*MIs[0], MatchData4); 
          return true;
      }()) {
        Helper.applyCombineIndexedLoadStore(*MIs[0], MatchData4); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 4 /* TargetOpcode::G_SEXTLOAD */) {
    // Leaf name: extending_loads
    // Rule: extending_loads
    if (!isRuleDisabled(3)) {
      if (1
          && [&]() {
           return Helper.matchCombineExtendingLoads(*MIs[0], MatchData3); 
          return true;
      }()) {
        Helper.applyCombineExtendingLoads(*MIs[0], MatchData3); 
        return true;
      }
    }
    // Leaf name: combine_indexed_load_store
    // Rule: combine_indexed_load_store
    if (!isRuleDisabled(4)) {
      if (1
          && [&]() {
           return Helper.matchCombineIndexedLoadStore(*MIs[0], MatchData4); 
          return true;
      }()) {
        Helper.applyCombineIndexedLoadStore(*MIs[0], MatchData4); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 5 /* TargetOpcode::G_ZEXTLOAD */) {
    // Leaf name: extending_loads
    // Rule: extending_loads
    if (!isRuleDisabled(3)) {
      if (1
          && [&]() {
           return Helper.matchCombineExtendingLoads(*MIs[0], MatchData3); 
          return true;
      }()) {
        Helper.applyCombineExtendingLoads(*MIs[0], MatchData3); 
        return true;
      }
    }
    // Leaf name: combine_indexed_load_store
    // Rule: combine_indexed_load_store
    if (!isRuleDisabled(4)) {
      if (1
          && [&]() {
           return Helper.matchCombineIndexedLoadStore(*MIs[0], MatchData4); 
          return true;
      }()) {
        Helper.applyCombineIndexedLoadStore(*MIs[0], MatchData4); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 6 /* TargetOpcode::G_STORE */) {
    // Leaf name: combine_indexed_load_store
    // Rule: combine_indexed_load_store
    if (!isRuleDisabled(4)) {
      if (1
          && [&]() {
           return Helper.matchCombineIndexedLoadStore(*MIs[0], MatchData4); 
          return true;
      }()) {
        Helper.applyCombineIndexedLoadStore(*MIs[0], MatchData4); 
        return true;
      }
    }
    // Leaf name: erase_undef_store
    // Rule: erase_undef_store
    if (!isRuleDisabled(11)) {
      if (1
          && [&]() {
           return Helper.matchUndefStore(*MIs[0]); 
          return true;
      }()) {
        return Helper.eraseInst(*MIs[0]); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 7 /* TargetOpcode::G_UITOFP */) {
    // Leaf name: undef_to_fp_zero
    // Rule: undef_to_fp_zero
    if (!isRuleDisabled(5)) {
      if (1
          && [&]() {
           return Helper.matchAnyExplicitUseIsUndef(*MIs[0]); 
          return true;
      }()) {
        Helper.replaceInstWithFConstant(*MIs[0], 0.0); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 8 /* TargetOpcode::G_SITOFP */) {
    // Leaf name: undef_to_fp_zero
    // Rule: undef_to_fp_zero
    if (!isRuleDisabled(5)) {
      if (1
          && [&]() {
           return Helper.matchAnyExplicitUseIsUndef(*MIs[0]); 
          return true;
      }()) {
        Helper.replaceInstWithFConstant(*MIs[0], 0.0); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 9 /* TargetOpcode::G_AND */) {
    // Leaf name: undef_to_int_zero
    // Rule: undef_to_int_zero
    if (!isRuleDisabled(6)) {
      if (1
          && [&]() {
           return Helper.matchAnyExplicitUseIsUndef(*MIs[0]); 
          return true;
      }()) {
        Helper.replaceInstWithConstant(*MIs[0], 0); 
        return true;
      }
    }
    // Leaf name: binop_same_val
    // Rule: binop_same_val
    if (!isRuleDisabled(14)) {
      if (1
          && [&]() {
           return Helper.matchBinOpSameVal(*MIs[0]); 
          return true;
      }()) {
        return Helper.replaceSingleDefInstWithOperand(*MIs[0], 1); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 10 /* TargetOpcode::G_OR */) {
    // Leaf name: undef_to_negative_one
    // Rule: undef_to_negative_one
    if (!isRuleDisabled(7)) {
      if (1
          && [&]() {
           return Helper.matchAnyExplicitUseIsUndef(*MIs[0]); 
          return true;
      }()) {
        Helper.replaceInstWithConstant(*MIs[0], -1); 
        return true;
      }
    }
    // Leaf name: right_identity_zero
    // Rule: right_identity_zero
    if (!isRuleDisabled(13)) {
      if (1
          && [&]() {
           return Helper.matchConstantOp(MIs[0]->getOperand(2), 0); 
          return true;
      }()) {
        return Helper.replaceSingleDefInstWithOperand(*MIs[0], 1); 
        return true;
      }
    }
    // Leaf name: binop_same_val
    // Rule: binop_same_val
    if (!isRuleDisabled(14)) {
      if (1
          && [&]() {
           return Helper.matchBinOpSameVal(*MIs[0]); 
          return true;
      }()) {
        return Helper.replaceSingleDefInstWithOperand(*MIs[0], 1); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 11 /* TargetOpcode::G_ADD */) {
    // Leaf name: propagate_undef_any_op
    // Rule: propagate_undef_any_op
    if (!isRuleDisabled(8)) {
      if (1
          && [&]() {
           return Helper.matchAnyExplicitUseIsUndef(*MIs[0]); 
          return true;
      }()) {
        Helper.replaceInstWithUndef(*MIs[0]); 
        return true;
      }
    }
    // Leaf name: right_identity_zero
    // Rule: right_identity_zero
    if (!isRuleDisabled(13)) {
      if (1
          && [&]() {
           return Helper.matchConstantOp(MIs[0]->getOperand(2), 0); 
          return true;
      }()) {
        return Helper.replaceSingleDefInstWithOperand(*MIs[0], 1); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 12 /* TargetOpcode::G_FPTOSI */) {
    // Leaf name: propagate_undef_any_op
    // Rule: propagate_undef_any_op
    if (!isRuleDisabled(8)) {
      if (1
          && [&]() {
           return Helper.matchAnyExplicitUseIsUndef(*MIs[0]); 
          return true;
      }()) {
        Helper.replaceInstWithUndef(*MIs[0]); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 13 /* TargetOpcode::G_FPTOUI */) {
    // Leaf name: propagate_undef_any_op
    // Rule: propagate_undef_any_op
    if (!isRuleDisabled(8)) {
      if (1
          && [&]() {
           return Helper.matchAnyExplicitUseIsUndef(*MIs[0]); 
          return true;
      }()) {
        Helper.replaceInstWithUndef(*MIs[0]); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 14 /* TargetOpcode::G_SUB */) {
    // Leaf name: propagate_undef_any_op
    // Rule: propagate_undef_any_op
    if (!isRuleDisabled(8)) {
      if (1
          && [&]() {
           return Helper.matchAnyExplicitUseIsUndef(*MIs[0]); 
          return true;
      }()) {
        Helper.replaceInstWithUndef(*MIs[0]); 
        return true;
      }
    }
    // Leaf name: right_identity_zero
    // Rule: right_identity_zero
    if (!isRuleDisabled(13)) {
      if (1
          && [&]() {
           return Helper.matchConstantOp(MIs[0]->getOperand(2), 0); 
          return true;
      }()) {
        return Helper.replaceSingleDefInstWithOperand(*MIs[0], 1); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 15 /* TargetOpcode::G_XOR */) {
    // Leaf name: propagate_undef_any_op
    // Rule: propagate_undef_any_op
    if (!isRuleDisabled(8)) {
      if (1
          && [&]() {
           return Helper.matchAnyExplicitUseIsUndef(*MIs[0]); 
          return true;
      }()) {
        Helper.replaceInstWithUndef(*MIs[0]); 
        return true;
      }
    }
    // Leaf name: right_identity_zero
    // Rule: right_identity_zero
    if (!isRuleDisabled(13)) {
      if (1
          && [&]() {
           return Helper.matchConstantOp(MIs[0]->getOperand(2), 0); 
          return true;
      }()) {
        return Helper.replaceSingleDefInstWithOperand(*MIs[0], 1); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 16 /* TargetOpcode::G_SHUFFLE_VECTOR */) {
    // Leaf name: propagate_undef_all_ops
    // Rule: propagate_undef_all_ops
    if (!isRuleDisabled(9)) {
      if (1
          && [&]() {
           return Helper.matchAllExplicitUsesAreUndef(*MIs[0]); 
          return true;
      }()) {
        Helper.replaceInstWithUndef(*MIs[0]); 
        return true;
      }
    }
    // Leaf name: propagate_undef_shuffle_mask
    // Rule: propagate_undef_shuffle_mask
    if (!isRuleDisabled(10)) {
      if (1
          && [&]() {
           return Helper.matchUndefShuffleVectorMask(*MIs[0]); 
          return true;
      }()) {
        Helper.replaceInstWithUndef(*MIs[0]); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 17 /* TargetOpcode::G_SELECT */) {
    // Leaf name: select_same_val
    // Rule: select_same_val
    if (!isRuleDisabled(12)) {
      if (1
          && [&]() {
           return Helper.matchSelectSameVal(*MIs[0]); 
          return true;
      }()) {
        return Helper.replaceSingleDefInstWithOperand(*MIs[0], 2); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 18 /* TargetOpcode::G_SHL */) {
    // Leaf name: right_identity_zero
    // Rule: right_identity_zero
    if (!isRuleDisabled(13)) {
      if (1
          && [&]() {
           return Helper.matchConstantOp(MIs[0]->getOperand(2), 0); 
          return true;
      }()) {
        return Helper.replaceSingleDefInstWithOperand(*MIs[0], 1); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 19 /* TargetOpcode::G_ASHR */) {
    // Leaf name: right_identity_zero
    // Rule: right_identity_zero
    if (!isRuleDisabled(13)) {
      if (1
          && [&]() {
           return Helper.matchConstantOp(MIs[0]->getOperand(2), 0); 
          return true;
      }()) {
        return Helper.replaceSingleDefInstWithOperand(*MIs[0], 1); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 20 /* TargetOpcode::G_LSHR */) {
    // Leaf name: right_identity_zero
    // Rule: right_identity_zero
    if (!isRuleDisabled(13)) {
      if (1
          && [&]() {
           return Helper.matchConstantOp(MIs[0]->getOperand(2), 0); 
          return true;
      }()) {
        return Helper.replaceSingleDefInstWithOperand(*MIs[0], 1); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 21 /* TargetOpcode::G_SDIV */) {
    // Leaf name: binop_left_to_zero
    // Rule: binop_left_to_zero
    if (!isRuleDisabled(15)) {
      if (1
          && [&]() {
           return Helper.matchOperandIsZero(*MIs[0], 1); 
          return true;
      }()) {
        return Helper.replaceSingleDefInstWithOperand(*MIs[0], 1); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 22 /* TargetOpcode::G_UDIV */) {
    // Leaf name: binop_left_to_zero
    // Rule: binop_left_to_zero
    if (!isRuleDisabled(15)) {
      if (1
          && [&]() {
           return Helper.matchOperandIsZero(*MIs[0], 1); 
          return true;
      }()) {
        return Helper.replaceSingleDefInstWithOperand(*MIs[0], 1); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 23 /* TargetOpcode::G_SREM */) {
    // Leaf name: binop_left_to_zero
    // Rule: binop_left_to_zero
    if (!isRuleDisabled(15)) {
      if (1
          && [&]() {
           return Helper.matchOperandIsZero(*MIs[0], 1); 
          return true;
      }()) {
        return Helper.replaceSingleDefInstWithOperand(*MIs[0], 1); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 24 /* TargetOpcode::G_UREM */) {
    // Leaf name: binop_left_to_zero
    // Rule: binop_left_to_zero
    if (!isRuleDisabled(15)) {
      if (1
          && [&]() {
           return Helper.matchOperandIsZero(*MIs[0], 1); 
          return true;
      }()) {
        return Helper.replaceSingleDefInstWithOperand(*MIs[0], 1); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 25 /* TargetOpcode::G_BR */) {
    // Leaf name: elide_br_by_inverting_cond
    // Rule: elide_br_by_inverting_cond
    if (!isRuleDisabled(17)) {
      if (1
          && [&]() {
           return Helper.matchElideBrByInvertingCond(*MIs[0]); 
          return true;
      }()) {
        Helper.applyElideBrByInvertingCond(*MIs[0]); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 26 /* TargetOpcode::G_FCONSTANT */) {
    // Leaf name: fconstant_to_constant
    // Rule: fconstant_to_constant
    if (!isRuleDisabled(18)) {
      if (1
          && [&]() {
           return matchFConstantToConstant(*MIs[0], MRI); 
          return true;
      }()) {
        applyFConstantToConstant(*MIs[0]); 
        return true;
      }
    }
    return false;
  }

  return false;
}
#endif // ifdef AARCH64PRELEGALIZERCOMBINERHELPER_GENCOMBINERHELPER_CPP
