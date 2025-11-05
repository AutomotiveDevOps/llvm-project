/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Global Combiner                                                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef AARCH64POSTLEGALIZERCOMBINERHELPER_GENCOMBINERHELPER_DEPS
#include "llvm/ADT/SparseBitVector.h"
namespace llvm {
extern cl::OptionCategory GICombinerOptionCategory;
} // end namespace llvm
#endif // ifdef AARCH64POSTLEGALIZERCOMBINERHELPER_GENCOMBINERHELPER_DEPS

#ifdef AARCH64POSTLEGALIZERCOMBINERHELPER_GENCOMBINERHELPER_H
class AArch64GenPostLegalizerCombinerHelper {
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
  case 15:	 // 1 string to match.
    if (memcmp(RuleIdentifier.data()+0, "extending_loads", 15) != 0)
      break;
    return 1;	 // "extending_loads"
  case 17:	 // 1 string to match.
    if (memcmp(RuleIdentifier.data()+0, "erase_undef_store", 17) != 0)
      break;
    return 0;	 // "erase_undef_store"
  }
#endif // ifndef NDEBUG

  return None;
}
bool AArch64GenPostLegalizerCombinerHelper::setRuleDisabled(StringRef RuleIdentifier) {
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
bool AArch64GenPostLegalizerCombinerHelper::isRuleDisabled(unsigned RuleID) const {
  return DisabledRules.test(RuleID);
}
#endif // ifdef AARCH64POSTLEGALIZERCOMBINERHELPER_GENCOMBINERHELPER_H

#ifdef AARCH64POSTLEGALIZERCOMBINERHELPER_GENCOMBINERHELPER_CPP

cl::list<std::string> AArch64PostLegalizerCombinerHelperOption(
    "aarch64postlegalizercombinerhelper-disable-rule",
    cl::desc("Disable one or more combiner rules temporarily in the AArch64PostLegalizerCombinerHelper pass"),
    cl::CommaSeparated,
    cl::Hidden,
    cl::cat(GICombinerOptionCategory));

bool AArch64GenPostLegalizerCombinerHelper::parseCommandLineOption() {
  for (const auto &Identifier : AArch64PostLegalizerCombinerHelperOption)
    if (!setRuleDisabled(Identifier))
      return false;
  return true;
}

bool AArch64GenPostLegalizerCombinerHelper::tryCombineAll(
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
  PreferredTuple MatchData1;

  int Partition = -1;
  Partition = -1;
  switch (MIs[0]->getOpcode()) {
  case TargetOpcode::G_STORE: Partition = 0; break;
  case TargetOpcode::G_LOAD: Partition = 1; break;
  case TargetOpcode::G_SEXTLOAD: Partition = 2; break;
  case TargetOpcode::G_ZEXTLOAD: Partition = 3; break;
  }
  // Default case but without conflicting with potential default case in selection.
  if (Partition == -1) return false;
  if (Partition == 0 /* TargetOpcode::G_STORE */) {
    // Leaf name: erase_undef_store
    // Rule: erase_undef_store
    if (!isRuleDisabled(0)) {
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
  if (Partition == 1 /* TargetOpcode::G_LOAD */) {
    // Leaf name: extending_loads
    // Rule: extending_loads
    if (!isRuleDisabled(1)) {
      if (1
          && [&]() {
           return Helper.matchCombineExtendingLoads(*MIs[0], MatchData1); 
          return true;
      }()) {
        Helper.applyCombineExtendingLoads(*MIs[0], MatchData1); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 2 /* TargetOpcode::G_SEXTLOAD */) {
    // Leaf name: extending_loads
    // Rule: extending_loads
    if (!isRuleDisabled(1)) {
      if (1
          && [&]() {
           return Helper.matchCombineExtendingLoads(*MIs[0], MatchData1); 
          return true;
      }()) {
        Helper.applyCombineExtendingLoads(*MIs[0], MatchData1); 
        return true;
      }
    }
    return false;
  }
  if (Partition == 3 /* TargetOpcode::G_ZEXTLOAD */) {
    // Leaf name: extending_loads
    // Rule: extending_loads
    if (!isRuleDisabled(1)) {
      if (1
          && [&]() {
           return Helper.matchCombineExtendingLoads(*MIs[0], MatchData1); 
          return true;
      }()) {
        Helper.applyCombineExtendingLoads(*MIs[0], MatchData1); 
        return true;
      }
    }
    return false;
  }

  return false;
}
#endif // ifdef AARCH64POSTLEGALIZERCOMBINERHELPER_GENCOMBINERHELPER_CPP
