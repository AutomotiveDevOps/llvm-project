/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Assembly Matcher Source Fragment                                           *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_ASSEMBLER_HEADER
#undef GET_ASSEMBLER_HEADER
  // This should be included into the middle of the declaration of
  // your subclasses implementation of MCTargetAsmParser.
  FeatureBitset ComputeAvailableFeatures(const FeatureBitset& FB) const;
  void convertToMCInst(unsigned Kind, MCInst &Inst, unsigned Opcode,
                       const OperandVector &Operands);
  void convertToMapAndConstraints(unsigned Kind,
                           const OperandVector &Operands) override;
  unsigned MatchInstructionImpl(const OperandVector &Operands,
                                MCInst &Inst,
                                uint64_t &ErrorInfo,
                                FeatureBitset &MissingFeatures,
                                bool matchingInlineAsm,
                                unsigned VariantID = 0);
  unsigned MatchInstructionImpl(const OperandVector &Operands,
                                MCInst &Inst,
                                uint64_t &ErrorInfo,
                                bool matchingInlineAsm,
                                unsigned VariantID = 0) {
    FeatureBitset MissingFeatures;
    return MatchInstructionImpl(Operands, Inst, ErrorInfo, MissingFeatures,
                                matchingInlineAsm, VariantID);
  }

#endif // GET_ASSEMBLER_HEADER_INFO


#ifdef GET_OPERAND_DIAGNOSTIC_TYPES
#undef GET_OPERAND_DIAGNOSTIC_TYPES

#endif // GET_OPERAND_DIAGNOSTIC_TYPES


#ifdef GET_REGISTER_MATCHER
#undef GET_REGISTER_MATCHER

// Bits for subtarget features that participate in instruction matching.
enum SubtargetFeatureBits : uint8_t {
};

#endif // GET_REGISTER_MATCHER


#ifdef GET_SUBTARGET_FEATURE_NAME
#undef GET_SUBTARGET_FEATURE_NAME

// User-level names for subtarget features that participate in
// instruction matching.
static const char *getSubtargetFeatureName(uint64_t Val) {
  return "(unknown)";
}

#endif // GET_SUBTARGET_FEATURE_NAME


#ifdef GET_MATCHER_IMPLEMENTATION
#undef GET_MATCHER_IMPLEMENTATION

static void applyMnemonicAliases(StringRef &Mnemonic, const FeatureBitset &Features, unsigned VariantID) {
  switch (VariantID) {
    case 0:
      switch (Mnemonic.size()) {
      default: break;
      case 5:	 // 1 string to match.
        if (memcmp(Mnemonic.data()+0, "cntlz", 5) != 0)
          break;
        Mnemonic = "cntlzw";	 // "cntlz"
        return;
      case 6:	 // 1 string to match.
        if (memcmp(Mnemonic.data()+0, "cntlz.", 6) != 0)
          break;
        Mnemonic = "cntlzw.";	 // "cntlz."
        return;
      }
    break;
  }
  switch (Mnemonic.size()) {
  default: break;
  case 5:	 // 1 string to match.
    if (memcmp(Mnemonic.data()+0, "cntlz", 5) != 0)
      break;
    Mnemonic = "cntlzw";	 // "cntlz"
    return;
  case 6:	 // 1 string to match.
    if (memcmp(Mnemonic.data()+0, "cntlz.", 6) != 0)
      break;
    Mnemonic = "cntlzw.";	 // "cntlz."
    return;
  }
}

enum {
  Tie0_1_1,
};

static const uint8_t TiedAsmOperandTable[][3] = {
  /* Tie0_1_1 */ { 0, 1, 1 },
};

namespace {
enum OperatorConversionKind {
  CVT_Done,
  CVT_Reg,
  CVT_Tied,
  CVT_95_addRegG8RCOperands,
  CVT_95_addTLSRegOperands,
  CVT_95_addRegGPRCOperands,
  CVT_95_addRegGPRCNoR0Operands,
  CVT_95_addS16ImmOperands,
  CVT_95_addImmOperands,
  CVT_95_addU16ImmOperands,
  CVT_95_addBranchTargetOperands,
  CVT_95_addRegCRBITRCOperands,
  CVT_imm_95_3,
  CVT_imm_95_2,
  CVT_imm_95_0,
  CVT_95_addRegVRRCOperands,
  CVT_imm_95_8,
  CVT_imm_95_10,
  CVT_imm_95_76,
  CVT_regCR0,
  CVT_95_addRegCRRCOperands,
  CVT_imm_95_79,
  CVT_imm_95_78,
  CVT_imm_95_4,
  CVT_imm_95_7,
  CVT_imm_95_6,
  CVT_imm_95_44,
  CVT_imm_95_47,
  CVT_imm_95_46,
  CVT_imm_95_36,
  CVT_imm_95_39,
  CVT_imm_95_38,
  CVT_imm_95_12,
  CVT_imm_95_15,
  CVT_imm_95_14,
  CVT_imm_95_68,
  CVT_imm_95_71,
  CVT_imm_95_70,
  CVT_imm_95_100,
  CVT_imm_95_103,
  CVT_imm_95_102,
  CVT_imm_95_108,
  CVT_imm_95_111,
  CVT_imm_95_110,
  CVT_imm_95_31,
  CVT_95_addRegGxRCNoR0Operands,
  CVT_95_addRegGxRCOperands,
  CVT_regR0,
  CVT_95_addRegSPERCOperands,
  CVT_95_addRegSPE4RCOperands,
  CVT_95_addRegF4RCOperands,
  CVT_95_addRegF8RCOperands,
  CVT_95_addRegG8RCNoX0Operands,
  CVT_regCR0EQ,
  CVT_regCR0GT,
  CVT_regCR0LT,
  CVT_regZERO8,
  CVT_regZERO,
  CVT_imm_95_1,
  CVT_95_addRegVFRCOperands,
  CVT_95_addRegVSFRCOperands,
  CVT_95_addRegVSSRCOperands,
  CVT_95_addRegVSRCOperands,
  CVT_imm_95_29,
  CVT_imm_95_280,
  CVT_imm_95_128,
  CVT_imm_95_129,
  CVT_imm_95_130,
  CVT_imm_95_131,
  CVT_imm_95_132,
  CVT_imm_95_133,
  CVT_imm_95_134,
  CVT_imm_95_135,
  CVT_imm_95_28,
  CVT_imm_95_19,
  CVT_imm_95_537,
  CVT_imm_95_539,
  CVT_imm_95_541,
  CVT_imm_95_543,
  CVT_imm_95_536,
  CVT_imm_95_538,
  CVT_imm_95_540,
  CVT_imm_95_542,
  CVT_imm_95_1018,
  CVT_imm_95_981,
  CVT_imm_95_22,
  CVT_imm_95_17,
  CVT_imm_95_18,
  CVT_imm_95_980,
  CVT_imm_95_529,
  CVT_imm_95_531,
  CVT_imm_95_533,
  CVT_imm_95_535,
  CVT_imm_95_528,
  CVT_imm_95_530,
  CVT_imm_95_532,
  CVT_imm_95_534,
  CVT_imm_95_1019,
  CVT_95_addCRBitMaskOperands,
  CVT_imm_95_48,
  CVT_imm_95_287,
  CVT_imm_95_5,
  CVT_imm_95_25,
  CVT_imm_95_512,
  CVT_imm_95_272,
  CVT_imm_95_273,
  CVT_imm_95_274,
  CVT_imm_95_275,
  CVT_imm_95_260,
  CVT_imm_95_261,
  CVT_imm_95_262,
  CVT_imm_95_263,
  CVT_imm_95_26,
  CVT_imm_95_27,
  CVT_imm_95_990,
  CVT_imm_95_991,
  CVT_imm_95_268,
  CVT_imm_95_988,
  CVT_imm_95_989,
  CVT_imm_95_269,
  CVT_imm_95_986,
  CVT_imm_95_255,
  CVT_imm_95_284,
  CVT_imm_95_285,
  CVT_regX0,
  CVT_95_addRegQFRCOperands,
  CVT_95_addRegQSRCOperands,
  CVT_95_addRegQBRCOperands,
  CVT_imm_95_9,
  CVT_imm_95_13,
  CVT_imm_95_20,
  CVT_imm_95_16,
  CVT_imm_95_24,
  CVT_NUM_CONVERTERS
};

enum InstructionConversionKind {
  Convert__RegG8RC1_0__RegG8RC1_1__TLSReg1_2,
  Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2,
  Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3,
  Convert__RegGPRC1_0__RegGPRCNoR01_1__S16Imm1_2,
  Convert__RegGPRC1_0__RegGPRC1_1__S16Imm1_2,
  Convert__RegGPRC1_1__RegGPRC1_2__S16Imm1_3,
  Convert__RegGPRC1_0__RegGPRCNoR01_1__S17Imm1_2,
  Convert__RegGPRC1_0__RegGPRC1_1,
  Convert__RegGPRC1_1__RegGPRC1_2,
  Convert__RegG8RC1_0__Imm1_1,
  Convert__RegGPRC1_1__RegGPRC1_2__U16Imm1_3,
  Convert_NoOperands,
  Convert__DirectBr1_0,
  Convert__U5Imm1_0__RegCRBITRC1_1__CondBr1_2,
  Convert__U5Imm1_1__ATBitsAsHint1_0__RegCRBITRC1_2__CondBr1_3,
  Convert__U5Imm1_0__imm_95_3__RegCRBITRC1_1__CondBr1_2,
  Convert__U5Imm1_0__imm_95_2__RegCRBITRC1_1__CondBr1_2,
  Convert__U5Imm1_0__RegCRBITRC1_1__imm_95_0,
  Convert__U5Imm1_0__RegCRBITRC1_1__Imm1_2,
  Convert__RegVRRC1_1__RegVRRC1_2__U1Imm1_3,
  Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3,
  Convert__RegVRRC1_1__RegVRRC1_2,
  Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__U1Imm1_4,
  Convert__CondBr1_0,
  Convert__imm_95_0__RegCRBITRC1_0__CondBr1_1,
  Convert__imm_95_0__RegCRBITRC1_0__imm_95_0,
  Convert__imm_95_8__RegCRBITRC1_0__CondBr1_1,
  Convert__imm_95_8__RegCRBITRC1_0__imm_95_0,
  Convert__imm_95_2__RegCRBITRC1_0__CondBr1_1,
  Convert__imm_95_2__RegCRBITRC1_0__imm_95_0,
  Convert__imm_95_10__RegCRBITRC1_0__CondBr1_1,
  Convert__imm_95_10__RegCRBITRC1_0__imm_95_0,
  Convert__imm_95_76__regCR0__CondBr1_0,
  Convert__imm_95_76__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_79__regCR0__CondBr1_0,
  Convert__imm_95_79__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_78__regCR0__CondBr1_0,
  Convert__imm_95_78__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_76__regCR0,
  Convert__imm_95_76__RegCRRC1_0,
  Convert__imm_95_79__regCR0,
  Convert__imm_95_79__RegCRRC1_0,
  Convert__imm_95_78__regCR0,
  Convert__imm_95_78__RegCRRC1_0,
  Convert__imm_95_4__RegCRBITRC1_0__CondBr1_1,
  Convert__imm_95_7__RegCRBITRC1_0__CondBr1_1,
  Convert__imm_95_6__RegCRBITRC1_0__CondBr1_1,
  Convert__imm_95_4__RegCRBITRC1_0__imm_95_0,
  Convert__imm_95_7__RegCRBITRC1_0__imm_95_0,
  Convert__imm_95_6__RegCRBITRC1_0__imm_95_0,
  Convert__imm_95_4__regCR0__CondBr1_0,
  Convert__imm_95_4__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_7__regCR0__CondBr1_0,
  Convert__imm_95_7__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_6__regCR0__CondBr1_0,
  Convert__imm_95_6__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_4__regCR0,
  Convert__imm_95_4__RegCRRC1_0,
  Convert__imm_95_7__regCR0,
  Convert__imm_95_7__RegCRRC1_0,
  Convert__imm_95_6__regCR0,
  Convert__imm_95_6__RegCRRC1_0,
  Convert__imm_95_44__regCR0__CondBr1_0,
  Convert__imm_95_44__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_47__regCR0__CondBr1_0,
  Convert__imm_95_47__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_46__regCR0__CondBr1_0,
  Convert__imm_95_46__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_44__regCR0,
  Convert__imm_95_44__RegCRRC1_0,
  Convert__imm_95_47__regCR0,
  Convert__imm_95_47__RegCRRC1_0,
  Convert__imm_95_46__regCR0,
  Convert__imm_95_46__RegCRRC1_0,
  Convert__DirectBr1_0__Imm1_1,
  Convert__imm_95_36__regCR0__CondBr1_0,
  Convert__imm_95_36__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_39__regCR0__CondBr1_0,
  Convert__imm_95_39__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_38__regCR0__CondBr1_0,
  Convert__imm_95_38__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_36__regCR0,
  Convert__imm_95_36__RegCRRC1_0,
  Convert__imm_95_39__regCR0,
  Convert__imm_95_39__RegCRRC1_0,
  Convert__imm_95_38__regCR0,
  Convert__imm_95_38__RegCRRC1_0,
  Convert__imm_95_12__regCR0__CondBr1_0,
  Convert__imm_95_12__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_15__regCR0__CondBr1_0,
  Convert__imm_95_15__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_14__regCR0__CondBr1_0,
  Convert__imm_95_14__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_12__regCR0,
  Convert__imm_95_12__RegCRRC1_0,
  Convert__imm_95_15__regCR0,
  Convert__imm_95_15__RegCRRC1_0,
  Convert__imm_95_14__regCR0,
  Convert__imm_95_14__RegCRRC1_0,
  Convert__imm_95_68__regCR0__CondBr1_0,
  Convert__imm_95_68__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_71__regCR0__CondBr1_0,
  Convert__imm_95_71__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_70__regCR0__CondBr1_0,
  Convert__imm_95_70__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_68__regCR0,
  Convert__imm_95_68__RegCRRC1_0,
  Convert__imm_95_71__regCR0,
  Convert__imm_95_71__RegCRRC1_0,
  Convert__imm_95_70__regCR0,
  Convert__imm_95_70__RegCRRC1_0,
  Convert__imm_95_100__regCR0__CondBr1_0,
  Convert__imm_95_100__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_103__regCR0__CondBr1_0,
  Convert__imm_95_103__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_102__regCR0__CondBr1_0,
  Convert__imm_95_102__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_100__regCR0,
  Convert__imm_95_100__RegCRRC1_0,
  Convert__imm_95_103__regCR0,
  Convert__imm_95_103__RegCRRC1_0,
  Convert__imm_95_102__regCR0,
  Convert__imm_95_102__RegCRRC1_0,
  Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2,
  Convert__imm_95_108__regCR0__CondBr1_0,
  Convert__imm_95_108__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_111__regCR0__CondBr1_0,
  Convert__imm_95_111__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_110__regCR0__CondBr1_0,
  Convert__imm_95_110__RegCRRC1_0__CondBr1_1,
  Convert__imm_95_108__regCR0,
  Convert__imm_95_108__RegCRRC1_0,
  Convert__imm_95_111__regCR0,
  Convert__imm_95_111__RegCRRC1_0,
  Convert__imm_95_110__regCR0,
  Convert__imm_95_110__RegCRRC1_0,
  Convert__imm_95_12__RegCRBITRC1_0__CondBr1_1,
  Convert__imm_95_15__RegCRBITRC1_0__CondBr1_1,
  Convert__imm_95_14__RegCRBITRC1_0__CondBr1_1,
  Convert__imm_95_12__RegCRBITRC1_0__imm_95_0,
  Convert__imm_95_15__RegCRBITRC1_0__imm_95_0,
  Convert__imm_95_14__RegCRBITRC1_0__imm_95_0,
  Convert__RegG8RC1_0__RegG8RC1_1__imm_95_0__U6Imm1_2,
  Convert__RegG8RC1_0__RegGPRC1_1__imm_95_0__U6Imm1_2,
  Convert__RegG8RC1_1__RegG8RC1_2__imm_95_0__U6Imm1_3,
  Convert__RegG8RC1_0__RegG8RC1_1__U6Imm1_2__U6Imm1_3,
  Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4,
  Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2__U5Imm1_3,
  Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4,
  Convert__RegG8RC1_0__RegG8RC1_1__imm_95_0__U5Imm1_2__imm_95_31,
  Convert__RegGPRC1_0__RegGPRC1_1__imm_95_0__U5Imm1_2__imm_95_31,
  Convert__RegG8RC1_1__RegG8RC1_2__imm_95_0__U5Imm1_3__imm_95_31,
  Convert__RegGPRC1_1__RegGPRC1_2__imm_95_0__U5Imm1_3__imm_95_31,
  Convert__RegG8RC1_0__RegG8RC1_1__U6Imm1_2,
  Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3,
  Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2,
  Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3,
  Convert__RegCRRC1_0__RegGPRC1_2__RegGPRC1_3,
  Convert__RegCRRC1_0__RegG8RC1_2__RegG8RC1_3,
  Convert__regCR0__RegG8RC1_0__RegG8RC1_1,
  Convert__RegCRRC1_0__RegG8RC1_1__RegG8RC1_2,
  Convert__regCR0__RegG8RC1_0__S16Imm1_1,
  Convert__RegCRRC1_0__RegG8RC1_1__S16Imm1_2,
  Convert__RegCRBITRC1_0__RegG8RC1_1__RegG8RC1_2,
  Convert__RegCRRC1_0__RegGPRC1_2__S16Imm1_3,
  Convert__RegCRRC1_0__RegG8RC1_2__S16Imm1_3,
  Convert__regCR0__RegG8RC1_0__U16Imm1_1,
  Convert__RegCRRC1_0__RegG8RC1_1__U16Imm1_2,
  Convert__RegCRRC1_0__RegGPRC1_2__U16Imm1_3,
  Convert__RegCRRC1_0__RegG8RC1_2__U16Imm1_3,
  Convert__regCR0__RegGPRC1_0__RegGPRC1_1,
  Convert__RegCRRC1_0__RegGPRC1_1__RegGPRC1_2,
  Convert__regCR0__RegGPRC1_0__U16Imm1_1,
  Convert__RegCRRC1_0__RegGPRC1_1__U16Imm1_2,
  Convert__RegCRBITRC1_0__U1Imm1_1__RegG8RC1_2__RegG8RC1_3,
  Convert__regCR0__RegGPRC1_0__S16Imm1_1,
  Convert__RegCRRC1_0__RegGPRC1_1__S16Imm1_2,
  Convert__RegG8RC1_0__RegG8RC1_1,
  Convert__RegG8RC1_1__RegG8RC1_2,
  Convert__RegGPRC1_0__RegGPRC1_1__U1Imm1_2,
  Convert__RegCRBITRC1_0__RegCRBITRC1_1__RegCRBITRC1_2,
  Convert__RegCRBITRC1_0__RegCRBITRC1_0__RegCRBITRC1_0,
  Convert__RegCRBITRC1_0__RegCRBITRC1_1__RegCRBITRC1_1,
  Convert__RegGxRCNoR01_0__RegGxRC1_1,
  Convert__U5Imm1_2__RegGxRCNoR01_0__RegGxRC1_1,
  Convert__RegGxRCNoR01_0__RegGxRC1_1__U5Imm1_2,
  Convert__RegGxRCNoR01_1__RegGxRC1_2__U5Imm1_0,
  Convert__regR0__regR0,
  Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3,
  Convert__U5Imm1_0,
  Convert__U5Imm1_2__RegGPRC1_0__RegGPRC1_1,
  Convert__RegSPERC1_0__RegSPERC1_1,
  Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2,
  Convert__RegSPERC1_0__RegSPE4RC1_1,
  Convert__RegSPERC1_0__RegGPRC1_1,
  Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2,
  Convert__RegGPRC1_0__RegSPERC1_1,
  Convert__RegSPE4RC1_0__RegSPE4RC1_1,
  Convert__RegSPE4RC1_0__RegSPE4RC1_1__RegSPE4RC1_2,
  Convert__RegSPE4RC1_0__RegSPERC1_1,
  Convert__RegSPE4RC1_0__RegGPRC1_1,
  Convert__RegCRRC1_0__RegSPE4RC1_1__RegSPE4RC1_2,
  Convert__RegGPRC1_0__RegSPE4RC1_1,
  Convert__RegSPERC1_0__RegSPERC1_2__U5Imm1_1,
  Convert__RegSPERC1_0__DispSPE81_1__RegGxRCNoR01_2,
  Convert__RegSPERC1_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__RegSPERC1_0__DispSPE21_1__RegGxRCNoR01_2,
  Convert__RegSPERC1_0__DispSPE41_1__RegGxRCNoR01_2,
  Convert__RegSPERC1_0__RegGPRC1_1__RegGPRC1_2,
  Convert__RegSPERC1_0__RegSPERC1_1__U5Imm1_2,
  Convert__RegSPERC1_1__RegSPERC1_2__RegSPERC1_3__imm_95_0,
  Convert__RegSPERC1_0__S5Imm1_1,
  Convert__RegSPERC1_0__U5Imm1_1__RegSPERC1_2,
  Convert__RegF4RC1_0__RegF4RC1_1,
  Convert__RegF4RC1_1__RegF4RC1_2,
  Convert__RegF8RC1_0__RegF8RC1_1__RegF8RC1_2,
  Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3,
  Convert__RegF4RC1_0__RegF4RC1_1__RegF4RC1_2,
  Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3,
  Convert__RegF8RC1_0__RegF8RC1_1,
  Convert__RegF8RC1_1__RegF8RC1_2,
  Convert__RegF4RC1_0__RegF8RC1_1,
  Convert__RegF4RC1_1__RegF8RC1_2,
  Convert__RegCRRC1_0__RegF4RC1_1__RegF4RC1_2,
  Convert__RegF8RC1_0__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3,
  Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4,
  Convert__RegF4RC1_0__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3,
  Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4,
  Convert__RegF4RC1_0__RegF8RC1_1__RegF4RC1_2__RegF4RC1_3,
  Convert__RegF4RC1_1__RegF8RC1_2__RegF4RC1_3__RegF4RC1_4,
  Convert__RegCRRC1_0__RegF8RC1_1__RegF8RC1_2,
  Convert__RegCRRC1_0__RegF8RC1_1,
  Convert__U4Imm1_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__U4Imm1_1__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__RegGPRC1_0__RegGPRCNoR01_1__RegGPRC1_2__RegCRBITRC1_3,
  Convert__RegG8RC1_0__RegG8RCNoX01_1__RegG8RC1_2__regCR0EQ,
  Convert__RegGPRC1_0__RegGPRCNoR01_1__RegGPRC1_2__regCR0EQ,
  Convert__RegG8RC1_0__RegG8RCNoX01_1__RegG8RC1_2__regCR0GT,
  Convert__RegGPRC1_0__RegGPRCNoR01_1__RegGPRC1_2__regCR0GT,
  Convert__RegG8RC1_0__RegG8RCNoX01_1__RegG8RC1_2__regCR0LT,
  Convert__RegGPRC1_0__RegGPRCNoR01_1__RegGPRC1_2__regCR0LT,
  Convert__RegGPRC1_0__DispRI1_1__RegGxRCNoR01_2,
  Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__RegGPRC1_0__imm_95_0__DispRI1_1__RegGxRCNoR01_2,
  Convert__RegGPRC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__RegG8RC1_0__RegGxRCNoR01_1__TLSReg1_2,
  Convert__RegG8RC1_0__DispRIX1_1__RegGxRCNoR01_2,
  Convert__RegG8RC1_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__RegG8RC1_0__RegG8RC1_1__U5Imm1_2,
  Convert__RegG8RC1_0__imm_95_0__DispRIX1_1__RegGxRCNoR01_2,
  Convert__RegG8RC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__RegF8RC1_0__DispRI1_1__RegGxRCNoR01_2,
  Convert__RegF8RC1_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__RegF8RC1_0__imm_95_0__DispRI1_1__RegGxRCNoR01_2,
  Convert__RegF8RC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__RegF4RC1_0__DispRI1_1__RegGxRCNoR01_2,
  Convert__RegF4RC1_0__imm_95_0__DispRI1_1__RegGxRCNoR01_2,
  Convert__RegF4RC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__RegF4RC1_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__RegG8RC1_0__regZERO8__S16Imm1_1,
  Convert__RegGPRC1_0__S16Imm1_1,
  Convert__RegGPRC1_0__regZERO__S16Imm1_1,
  Convert__RegG8RC1_0__regZERO8__S17Imm1_1,
  Convert__RegGPRC1_0__S17Imm1_1,
  Convert__RegGPRC1_0__regZERO__S17Imm1_1,
  Convert__RegG8RC1_0__imm_95_0,
  Convert__RegVRRC1_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__imm_95_1,
  Convert__RegSPE4RC1_0__DispRI1_1__RegGxRCNoR01_2,
  Convert__RegSPE4RC1_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__RegVFRC1_0__DispRIX1_1__RegGxRCNoR01_2,
  Convert__RegVSFRC1_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__RegVSSRC1_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__RegVSRC1_0__DispRIX161_1__RegGxRCNoR01_2,
  Convert__RegVSRC1_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__RegVSRC1_0__Imm1_1__RegG8RC1_2,
  Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3,
  Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3,
  Convert__imm_95_0,
  Convert__RegCRRC1_0__RegCRRC1_1,
  Convert__RegCRRC1_0,
  Convert__RegGPRC1_0__imm_95_29,
  Convert__RegGPRC1_0__imm_95_280,
  Convert__RegGPRC1_0__U10Imm1_1__imm_95_0,
  Convert__RegGPRC1_0__imm_95_128,
  Convert__RegGPRC1_0__imm_95_129,
  Convert__RegGPRC1_0__imm_95_130,
  Convert__RegGPRC1_0__imm_95_131,
  Convert__RegGPRC1_0__imm_95_132,
  Convert__RegGPRC1_0__imm_95_133,
  Convert__RegGPRC1_0__imm_95_134,
  Convert__RegGPRC1_0__imm_95_135,
  Convert__RegGPRC1_0__imm_95_28,
  Convert__RegGPRC1_0,
  Convert__RegGPRC1_0__imm_95_19,
  Convert__RegGPRC1_0__imm_95_537,
  Convert__RegGPRC1_0__imm_95_539,
  Convert__RegGPRC1_0__imm_95_541,
  Convert__RegGPRC1_0__imm_95_543,
  Convert__RegGPRC1_0__imm_95_536,
  Convert__RegGPRC1_0__imm_95_538,
  Convert__RegGPRC1_0__imm_95_540,
  Convert__RegGPRC1_0__imm_95_542,
  Convert__RegGPRC1_0__imm_95_1018,
  Convert__RegGPRC1_0__Imm1_1,
  Convert__RegGPRC1_0__imm_95_981,
  Convert__RegGPRC1_0__imm_95_22,
  Convert__RegGPRC1_0__imm_95_17,
  Convert__RegGPRC1_0__imm_95_18,
  Convert__RegGPRC1_0__imm_95_980,
  Convert__RegG8RC1_0__RegF8RC1_1,
  Convert__RegGPRC1_0__RegF8RC1_1,
  Convert__RegF8RC1_0,
  Convert__RegF8RC1_1,
  Convert__RegF8RC1_0__U3Imm1_1,
  Convert__RegF8RC1_0__U2Imm1_1,
  Convert__RegGPRC1_0__imm_95_529,
  Convert__RegGPRC1_0__imm_95_531,
  Convert__RegGPRC1_0__imm_95_533,
  Convert__RegGPRC1_0__imm_95_535,
  Convert__RegGPRC1_0__imm_95_528,
  Convert__RegGPRC1_0__imm_95_530,
  Convert__RegGPRC1_0__imm_95_532,
  Convert__RegGPRC1_0__imm_95_534,
  Convert__RegGPRC1_0__imm_95_1019,
  Convert__RegGPRC1_0__CRBitMask1_1,
  Convert__RegGPRC1_0__imm_95_48,
  Convert__RegGPRC1_0__imm_95_287,
  Convert__RegGPRC1_0__imm_95_5,
  Convert__RegGPRC1_0__imm_95_4,
  Convert__RegGPRC1_0__imm_95_25,
  Convert__RegGPRC1_0__imm_95_512,
  Convert__RegGPRC1_0__imm_95_272,
  Convert__RegGPRC1_0__imm_95_273,
  Convert__RegGPRC1_0__imm_95_274,
  Convert__RegGPRC1_0__imm_95_275,
  Convert__RegGPRC1_0__imm_95_260,
  Convert__RegGPRC1_0__imm_95_261,
  Convert__RegGPRC1_0__imm_95_262,
  Convert__RegGPRC1_0__imm_95_263,
  Convert__RegGPRC1_0__U4Imm1_1,
  Convert__RegGPRC1_0__imm_95_26,
  Convert__RegGPRC1_0__imm_95_27,
  Convert__RegGPRC1_0__imm_95_990,
  Convert__RegGPRC1_0__imm_95_991,
  Convert__RegGPRC1_0__imm_95_268,
  Convert__RegGPRC1_0__imm_95_988,
  Convert__RegGPRC1_0__imm_95_989,
  Convert__RegGPRC1_0__imm_95_269,
  Convert__RegGPRC1_0__imm_95_986,
  Convert__RegG8RC1_0__RegVRRC1_1,
  Convert__RegGPRC1_0__RegVRRC1_1,
  Convert__RegVRRC1_0,
  Convert__RegG8RC1_0__RegVSFRC1_1,
  Convert__RegG8RC1_0__RegVSRC1_1,
  Convert__RegGPRC1_0__RegVSFRC1_1,
  Convert__RegGPRC1_0__imm_95_1,
  Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_1,
  Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_1,
  Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_2,
  Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_2,
  Convert__imm_95_29__RegGPRC1_0,
  Convert__imm_95_280__RegGPRC1_0,
  Convert__imm_95_28__RegGPRC1_0,
  Convert__imm_95_255__RegG8RC1_0,
  Convert__imm_95_255__RegGPRC1_0,
  Convert__Imm1_0__RegGPRC1_1,
  Convert__imm_95_19__RegGPRC1_0,
  Convert__imm_95_537__RegGPRC1_1,
  Convert__imm_95_539__RegGPRC1_1,
  Convert__imm_95_541__RegGPRC1_1,
  Convert__imm_95_543__RegGPRC1_1,
  Convert__imm_95_536__RegGPRC1_1,
  Convert__imm_95_538__RegGPRC1_1,
  Convert__imm_95_540__RegGPRC1_1,
  Convert__imm_95_542__RegGPRC1_1,
  Convert__imm_95_1018__RegGPRC1_0,
  Convert__RegGPRC1_1__Imm1_0,
  Convert__imm_95_981__RegGPRC1_0,
  Convert__imm_95_22__RegGPRC1_0,
  Convert__imm_95_17__RegGPRC1_0,
  Convert__imm_95_18__RegGPRC1_0,
  Convert__imm_95_980__RegGPRC1_0,
  Convert__RegF8RC1_0__RegG8RC1_1,
  Convert__RegF8RC1_0__RegGPRC1_1,
  Convert__Imm1_0__RegF8RC1_1__imm_95_0__imm_95_0,
  Convert__Imm1_1__RegF8RC1_2__imm_95_0__imm_95_0,
  Convert__Imm1_0__RegF8RC1_1__Imm1_2__Imm1_3,
  Convert__Imm1_1__RegF8RC1_2__Imm1_3__Imm1_4,
  Convert__RegCRRC1_0__Imm1_1__imm_95_0,
  Convert__RegCRRC1_1__Imm1_2__imm_95_0,
  Convert__RegCRRC1_0__Imm1_1__Imm1_2,
  Convert__RegCRRC1_1__Imm1_2__Imm1_3,
  Convert__imm_95_529__RegGPRC1_1,
  Convert__imm_95_531__RegGPRC1_1,
  Convert__imm_95_533__RegGPRC1_1,
  Convert__imm_95_535__RegGPRC1_1,
  Convert__imm_95_528__RegGPRC1_1,
  Convert__imm_95_530__RegGPRC1_1,
  Convert__imm_95_532__RegGPRC1_1,
  Convert__imm_95_534__RegGPRC1_1,
  Convert__imm_95_1019__RegGPRC1_0,
  Convert__RegGPRC1_0__imm_95_0,
  Convert__CRBitMask1_0__RegGPRC1_1,
  Convert__imm_95_48__RegGPRC1_0,
  Convert__imm_95_25__RegGPRC1_0,
  Convert__imm_95_512__RegGPRC1_0,
  Convert__imm_95_272__RegGPRC1_1,
  Convert__imm_95_273__RegGPRC1_1,
  Convert__imm_95_274__RegGPRC1_1,
  Convert__imm_95_275__RegGPRC1_1,
  Convert__imm_95_260__RegGPRC1_1,
  Convert__imm_95_261__RegGPRC1_1,
  Convert__imm_95_262__RegGPRC1_1,
  Convert__imm_95_263__RegGPRC1_1,
  Convert__imm_95_272__RegGPRC1_0,
  Convert__imm_95_273__RegGPRC1_0,
  Convert__imm_95_274__RegGPRC1_0,
  Convert__imm_95_275__RegGPRC1_0,
  Convert__imm_95_260__RegGPRC1_0,
  Convert__imm_95_261__RegGPRC1_0,
  Convert__imm_95_262__RegGPRC1_0,
  Convert__imm_95_263__RegGPRC1_0,
  Convert__RegGPRC1_1__U4Imm1_0,
  Convert__imm_95_26__RegGPRC1_0,
  Convert__imm_95_27__RegGPRC1_0,
  Convert__imm_95_990__RegGPRC1_0,
  Convert__imm_95_991__RegGPRC1_0,
  Convert__imm_95_988__RegGPRC1_0,
  Convert__imm_95_284__RegGPRC1_0,
  Convert__imm_95_989__RegGPRC1_0,
  Convert__imm_95_285__RegGPRC1_0,
  Convert__imm_95_986__RegGPRC1_0,
  Convert__RegVRRC1_0__RegG8RC1_1,
  Convert__RegVRRC1_0__RegGPRC1_1,
  Convert__RegVSFRC1_0__RegG8RC1_1,
  Convert__RegVSRC1_0__RegG8RCNoX01_1__RegG8RC1_2,
  Convert__RegVSFRC1_0__RegGPRC1_1,
  Convert__RegVSRC1_0__RegGPRC1_1,
  Convert__imm_95_1__RegGPRC1_0,
  Convert__regR0__regR0__imm_95_0,
  Convert__regX0__regX0__imm_95_0,
  Convert__RegGPRC1_0__RegGPRC1_1__U16Imm1_2,
  Convert__RegGPRC1_0__ImmZero1_1__S34Imm1_2,
  Convert__RegGPRC1_0__RegGPRC1_1__S34Imm1_2,
  Convert__RegGPRC1_1__RegGPRC1_2__U1Imm1_3,
  Convert__RegGPRC1_0__DispRI341_1__ImmZero1_2,
  Convert__RegGPRC1_0__DispRI341_1__RegGxRCNoR01_2,
  Convert__RegG8RC1_0__DispRI341_1__ImmZero1_2,
  Convert__RegG8RC1_0__DispRI341_1__RegGxRCNoR01_2,
  Convert__RegF8RC1_0__DispRI341_1__ImmZero1_2,
  Convert__RegF8RC1_0__DispRI341_1__RegGxRCNoR01_2,
  Convert__RegF4RC1_0__DispRI341_1__ImmZero1_2,
  Convert__RegF4RC1_0__DispRI341_1__RegGxRCNoR01_2,
  Convert__RegGPRC1_0__S34Imm1_1,
  Convert__RegVFRC1_0__DispRI341_1__ImmZero1_2,
  Convert__RegVFRC1_0__DispRI341_1__RegGxRCNoR01_2,
  Convert__RegVSRC1_0__DispRI341_1__ImmZero1_2,
  Convert__RegVSRC1_0__DispRI341_1__RegGxRCNoR01_2,
  Convert__imm_95_2,
  Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_2__U2Imm1_3,
  Convert__RegQFRC1_0__RegQFRC1_1__U2Imm1_2,
  Convert__RegQFRC1_0__RegQFRC1_1,
  Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_2,
  Convert__RegQSRC1_0__RegQSRC1_1__RegQSRC1_2,
  Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_1,
  Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_4,
  Convert__RegQBRC1_0__RegQBRC1_0__RegQBRC1_0__imm_95_0,
  Convert__RegQBRC1_0__RegQFRC1_1__RegQFRC1_2,
  Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_1__imm_95_5,
  Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_9,
  Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__U12Imm1_3,
  Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3,
  Convert__RegQSRC1_0__RegQSRC1_1__RegQSRC1_2__RegQSRC1_3,
  Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_14,
  Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_8,
  Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_1__imm_95_10,
  Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_7,
  Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_13,
  Convert__RegQSRC1_0__RegQFRC1_1,
  Convert__RegQFRC1_0__RegQBRC1_1__RegQFRC1_3__RegQFRC1_2,
  Convert__RegQBRC1_0__RegQBRC1_0__RegQBRC1_0__imm_95_15,
  Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_3__RegQFRC1_2,
  Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_6,
  Convert__RegQFRC1_0__U12Imm1_1,
  Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__RegQFRC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__RegQSRC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__imm_95_0__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__imm_95_0__RegQSRC1_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__U1Imm1_0,
  Convert__RegG8RC1_0__RegG8RC1_1__RegGPRC1_2__U6Imm1_3,
  Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3__U6Imm1_4,
  Convert__RegG8RC1_0__Tie0_1_1__RegG8RC1_1__U6Imm1_2__U6Imm1_3,
  Convert__RegG8RC1_1__Tie0_1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4,
  Convert__RegG8RC1_0__RegG8RC1_1__U5Imm1_2__Imm1_3,
  Convert__RegG8RC1_1__RegG8RC1_2__U5Imm1_3__Imm1_4,
  Convert__RegGPRC1_0__Tie0_1_1__RegGPRC1_1__U5Imm1_2__U5Imm1_3__U5Imm1_4,
  Convert__RegGPRC1_1__Tie0_1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4__U5Imm1_5,
  Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2__U5Imm1_3__U5Imm1_4,
  Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4__U5Imm1_5,
  Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4,
  Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3__U5Imm1_4__U5Imm1_5,
  Convert__RegG8RC1_0__RegG8RC1_1__RegGPRC1_2__imm_95_0,
  Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3__imm_95_0,
  Convert__RegG8RC1_0__RegG8RC1_1__U6Imm1_2__imm_95_0,
  Convert__RegG8RC1_0__RegGPRC1_1__U6Imm1_2__imm_95_0,
  Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__imm_95_0,
  Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2__imm_95_0__imm_95_31,
  Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2__imm_95_0__imm_95_31,
  Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3__imm_95_0__imm_95_31,
  Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3__imm_95_0__imm_95_31,
  Convert__RegG8RC1_0__RegG8RC1_1__U5Imm1_2__imm_95_0__imm_95_31,
  Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2__imm_95_0__imm_95_31,
  Convert__RegG8RC1_1__RegG8RC1_2__U5Imm1_3__imm_95_0__imm_95_31,
  Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__imm_95_0__imm_95_31,
  Convert__Imm1_0,
  Convert__RegGPRC1_0__RegCRRC1_1,
  Convert__RegG8RC1_0__RegG8RC1_1__RegGPRC1_2,
  Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3,
  Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__imm_95_0__RegGPRC1_0__DispRI1_1__RegGxRCNoR01_2,
  Convert__imm_95_0__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__RegG8RC1_1__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__imm_95_0__RegG8RC1_0__DispRIX1_1__RegGxRCNoR01_2,
  Convert__imm_95_0__RegG8RC1_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__imm_95_0__RegF8RC1_0__DispRI1_1__RegGxRCNoR01_2,
  Convert__imm_95_0__RegF8RC1_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__imm_95_0__RegF4RC1_0__DispRI1_1__RegGxRCNoR01_2,
  Convert__imm_95_0__RegF4RC1_0__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__RegG8RC1_0__RegG8RC1_2__RegG8RC1_1,
  Convert__RegGPRC1_0__RegGPRC1_2__RegGPRC1_1,
  Convert__RegG8RC1_1__RegG8RC1_3__RegG8RC1_2,
  Convert__RegGPRC1_1__RegGPRC1_3__RegGPRC1_2,
  Convert__RegG8RC1_0__S16Imm1_1,
  Convert__RegGPRC1_1,
  Convert__U5Imm1_1__RegGPRC1_2__RegGPRC1_3,
  Convert__U5Imm1_1__RegGPRC1_2__U5Imm1_3,
  Convert__U1Imm1_1,
  Convert__U5Imm1_0__RegG8RC1_1__RegG8RC1_2,
  Convert__imm_95_4__RegG8RC1_0__RegG8RC1_1,
  Convert__imm_95_4__RegG8RC1_0__S16Imm1_1,
  Convert__imm_95_12__RegG8RC1_0__RegG8RC1_1,
  Convert__imm_95_12__RegG8RC1_0__S16Imm1_1,
  Convert__imm_95_8__RegG8RC1_0__RegG8RC1_1,
  Convert__imm_95_8__RegG8RC1_0__S16Imm1_1,
  Convert__U5Imm1_0__RegG8RC1_1__S16Imm1_2,
  Convert__imm_95_20__RegG8RC1_0__RegG8RC1_1,
  Convert__imm_95_20__RegG8RC1_0__S16Imm1_1,
  Convert__imm_95_5__RegG8RC1_0__RegG8RC1_1,
  Convert__imm_95_5__RegG8RC1_0__S16Imm1_1,
  Convert__imm_95_1__RegG8RC1_0__RegG8RC1_1,
  Convert__imm_95_1__RegG8RC1_0__S16Imm1_1,
  Convert__imm_95_6__RegG8RC1_0__RegG8RC1_1,
  Convert__imm_95_6__RegG8RC1_0__S16Imm1_1,
  Convert__imm_95_2__RegG8RC1_0__RegG8RC1_1,
  Convert__imm_95_2__RegG8RC1_0__S16Imm1_1,
  Convert__imm_95_16__RegG8RC1_0__RegG8RC1_1,
  Convert__imm_95_16__RegG8RC1_0__S16Imm1_1,
  Convert__imm_95_24__RegG8RC1_0__RegG8RC1_1,
  Convert__imm_95_24__RegG8RC1_0__S16Imm1_1,
  Convert__imm_95_31__RegG8RC1_0__RegG8RC1_1,
  Convert__imm_95_31__RegG8RC1_0__S16Imm1_1,
  Convert__regR0__RegGPRC1_0,
  Convert__RegGPRC1_1__RegGPRC1_0,
  Convert__RegGPRC1_0__RegGPRC1_1__Imm1_2,
  Convert__RegGPRC1_0__RegGPRC1_1__imm_95_0,
  Convert__RegGPRC1_0__RegGPRC1_1__imm_95_1,
  Convert__imm_95_31__regR0__regR0,
  Convert__U5Imm1_0__RegGPRC1_1__RegGPRC1_2,
  Convert__imm_95_4__RegGPRC1_0__RegGPRC1_1,
  Convert__imm_95_4__RegGPRC1_0__S16Imm1_1,
  Convert__imm_95_12__RegGPRC1_0__RegGPRC1_1,
  Convert__imm_95_12__RegGPRC1_0__S16Imm1_1,
  Convert__imm_95_8__RegGPRC1_0__RegGPRC1_1,
  Convert__imm_95_8__RegGPRC1_0__S16Imm1_1,
  Convert__U5Imm1_0__RegGPRC1_1__S16Imm1_2,
  Convert__imm_95_20__RegGPRC1_0__RegGPRC1_1,
  Convert__imm_95_20__RegGPRC1_0__S16Imm1_1,
  Convert__imm_95_5__RegGPRC1_0__RegGPRC1_1,
  Convert__imm_95_5__RegGPRC1_0__S16Imm1_1,
  Convert__imm_95_1__RegGPRC1_0__RegGPRC1_1,
  Convert__imm_95_1__RegGPRC1_0__S16Imm1_1,
  Convert__imm_95_6__RegGPRC1_0__RegGPRC1_1,
  Convert__imm_95_6__RegGPRC1_0__S16Imm1_1,
  Convert__imm_95_2__RegGPRC1_0__RegGPRC1_1,
  Convert__imm_95_2__RegGPRC1_0__S16Imm1_1,
  Convert__imm_95_16__RegGPRC1_0__RegGPRC1_1,
  Convert__imm_95_16__RegGPRC1_0__S16Imm1_1,
  Convert__imm_95_24__RegGPRC1_0__RegGPRC1_1,
  Convert__imm_95_24__RegGPRC1_0__S16Imm1_1,
  Convert__imm_95_31__RegGPRC1_0__RegGPRC1_1,
  Convert__imm_95_31__RegGPRC1_0__S16Imm1_1,
  Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2,
  Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3,
  Convert__RegVRRC1_0__U5Imm1_2__RegVRRC1_1,
  Convert__RegVRRC1_0__RegVRRC1_1,
  Convert__RegVRRC1_0__U4Imm1_2__RegVRRC1_1,
  Convert__RegG8RC1_0__RegG8RC1_1__RegVRRC1_2,
  Convert__RegVRRC1_0__Tie0_1_1__U4Imm1_2__RegVRRC1_1,
  Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_1,
  Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__Tie0_1_1,
  Convert__RegVRRC1_0__RegVRRC1_1__U1Imm1_2__U4Imm1_3,
  Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__U4Imm1_3,
  Convert__RegVRRC1_0__S5Imm1_1,
  Convert__RegVSFRC1_0__RegVSFRC1_1,
  Convert__RegVSFRC1_0__RegVSFRC1_1__RegVSFRC1_2,
  Convert__RegVSSRC1_0__RegVSSRC1_1__RegVSSRC1_2,
  Convert__RegVSRC1_0__RegVSFRC1_1__RegVSFRC1_2,
  Convert__RegCRRC1_0__RegVSFRC1_1__RegVSFRC1_2,
  Convert__RegCRRC1_0__RegVRRC1_1__RegVRRC1_2,
  Convert__RegVRRC1_0__RegVFRC1_1,
  Convert__RegVSRC1_0__RegVSSRC1_1,
  Convert__RegVFRC1_0__RegVRRC1_1,
  Convert__RegVSSRC1_0__RegVSRC1_1,
  Convert__RegVSSRC1_0__RegVSFRC1_1,
  Convert__RegVSRC1_0__RegG8RC1_1__RegG8RC1_2,
  Convert__RegVRRC1_0__RegVRRC1_1__RegVSFRC1_2,
  Convert__RegVSFRC1_0__Tie0_1_1__RegVSFRC1_1__RegVSFRC1_2,
  Convert__RegVSSRC1_0__Tie0_1_1__RegVSSRC1_1__RegVSSRC1_2,
  Convert__RegVRRC1_0__Tie0_1_1__RegVRRC1_1__RegVRRC1_2,
  Convert__RegVSSRC1_0__RegVSSRC1_1,
  Convert__RegVRRC1_1__U1Imm1_0__RegVRRC1_2__U2Imm1_3,
  Convert__RegCRRC1_0__RegVSFRC1_1,
  Convert__RegCRRC1_0__U7Imm1_2__RegVSFRC1_1,
  Convert__RegCRRC1_0__U7Imm1_2__RegVRRC1_1,
  Convert__RegVSRC1_0__RegVSRC1_1,
  Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2,
  Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3,
  Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__RegVSRC1_2,
  Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_1,
  Convert__RegCRRC1_0__RegVSRC1_1__RegVSRC1_2,
  Convert__RegCRRC1_0__RegVSRC1_1,
  Convert__RegVSRC1_0__U7Imm1_2__RegVSRC1_1,
  Convert__RegVSFRC1_0__RegVSRC1_1__U4Imm1_2,
  Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__U4Imm1_2,
  Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2__imm_95_0,
  Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2__imm_95_3,
  Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2__U2Imm1_3,
  Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3,
  Convert__RegVSRC1_0__RegVSFRC1_1__imm_95_0,
  Convert__RegVSRC1_0__RegVSFRC1_1__imm_95_3,
  Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_1__imm_95_0,
  Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_1__imm_95_3,
  Convert__RegVSRC1_0__U8Imm1_1,
  Convert__RegVSRC1_0__RegVSRC1_1__U2Imm1_2,
  Convert__RegVSRC1_0__RegVSFRC1_1__imm_95_2,
  Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_1__imm_95_2,
  CVT_NUM_SIGNATURES
};

} // end anonymous namespace

static const uint8_t ConversionTable[CVT_NUM_SIGNATURES][13] = {
  // Convert__RegG8RC1_0__RegG8RC1_1__TLSReg1_2
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addTLSRegOperands, 3, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addRegGPRCOperands, 4, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRCNoR01_1__S16Imm1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCNoR0Operands, 2, CVT_95_addS16ImmOperands, 3, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRC1_1__S16Imm1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addS16ImmOperands, 3, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__S16Imm1_3
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addS16ImmOperands, 4, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRCNoR01_1__S17Imm1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCNoR0Operands, 2, CVT_95_addS16ImmOperands, 3, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRC1_1
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_Done },
  // Convert__RegG8RC1_0__Imm1_1
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__U16Imm1_3
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addU16ImmOperands, 4, CVT_Done },
  // Convert_NoOperands
  { CVT_Done },
  // Convert__DirectBr1_0
  { CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__U5Imm1_0__RegCRBITRC1_1__CondBr1_2
  { CVT_95_addImmOperands, 1, CVT_95_addRegCRBITRCOperands, 2, CVT_95_addBranchTargetOperands, 3, CVT_Done },
  // Convert__U5Imm1_1__ATBitsAsHint1_0__RegCRBITRC1_2__CondBr1_3
  { CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 1, CVT_95_addRegCRBITRCOperands, 3, CVT_95_addBranchTargetOperands, 4, CVT_Done },
  // Convert__U5Imm1_0__imm_95_3__RegCRBITRC1_1__CondBr1_2
  { CVT_95_addImmOperands, 1, CVT_imm_95_3, 0, CVT_95_addRegCRBITRCOperands, 2, CVT_95_addBranchTargetOperands, 3, CVT_Done },
  // Convert__U5Imm1_0__imm_95_2__RegCRBITRC1_1__CondBr1_2
  { CVT_95_addImmOperands, 1, CVT_imm_95_2, 0, CVT_95_addRegCRBITRCOperands, 2, CVT_95_addBranchTargetOperands, 3, CVT_Done },
  // Convert__U5Imm1_0__RegCRBITRC1_1__imm_95_0
  { CVT_95_addImmOperands, 1, CVT_95_addRegCRBITRCOperands, 2, CVT_imm_95_0, 0, CVT_Done },
  // Convert__U5Imm1_0__RegCRBITRC1_1__Imm1_2
  { CVT_95_addImmOperands, 1, CVT_95_addRegCRBITRCOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegVRRC1_1__RegVRRC1_2__U1Imm1_3
  { CVT_95_addRegVRRCOperands, 2, CVT_95_addRegVRRCOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3
  { CVT_95_addRegVRRCOperands, 2, CVT_95_addRegVRRCOperands, 3, CVT_95_addRegVRRCOperands, 4, CVT_Done },
  // Convert__RegVRRC1_1__RegVRRC1_2
  { CVT_95_addRegVRRCOperands, 2, CVT_95_addRegVRRCOperands, 3, CVT_Done },
  // Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__U1Imm1_4
  { CVT_95_addRegVRRCOperands, 2, CVT_95_addRegVRRCOperands, 3, CVT_95_addRegVRRCOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__CondBr1_0
  { CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_0__RegCRBITRC1_0__CondBr1_1
  { CVT_imm_95_0, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_0__RegCRBITRC1_0__imm_95_0
  { CVT_imm_95_0, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__imm_95_8__RegCRBITRC1_0__CondBr1_1
  { CVT_imm_95_8, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_8__RegCRBITRC1_0__imm_95_0
  { CVT_imm_95_8, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__imm_95_2__RegCRBITRC1_0__CondBr1_1
  { CVT_imm_95_2, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_2__RegCRBITRC1_0__imm_95_0
  { CVT_imm_95_2, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__imm_95_10__RegCRBITRC1_0__CondBr1_1
  { CVT_imm_95_10, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_10__RegCRBITRC1_0__imm_95_0
  { CVT_imm_95_10, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__imm_95_76__regCR0__CondBr1_0
  { CVT_imm_95_76, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_76__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_76, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_79__regCR0__CondBr1_0
  { CVT_imm_95_79, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_79__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_79, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_78__regCR0__CondBr1_0
  { CVT_imm_95_78, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_78__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_78, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_76__regCR0
  { CVT_imm_95_76, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_76__RegCRRC1_0
  { CVT_imm_95_76, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_79__regCR0
  { CVT_imm_95_79, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_79__RegCRRC1_0
  { CVT_imm_95_79, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_78__regCR0
  { CVT_imm_95_78, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_78__RegCRRC1_0
  { CVT_imm_95_78, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_4__RegCRBITRC1_0__CondBr1_1
  { CVT_imm_95_4, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_7__RegCRBITRC1_0__CondBr1_1
  { CVT_imm_95_7, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_6__RegCRBITRC1_0__CondBr1_1
  { CVT_imm_95_6, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_4__RegCRBITRC1_0__imm_95_0
  { CVT_imm_95_4, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__imm_95_7__RegCRBITRC1_0__imm_95_0
  { CVT_imm_95_7, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__imm_95_6__RegCRBITRC1_0__imm_95_0
  { CVT_imm_95_6, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__imm_95_4__regCR0__CondBr1_0
  { CVT_imm_95_4, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_4__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_4, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_7__regCR0__CondBr1_0
  { CVT_imm_95_7, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_7__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_7, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_6__regCR0__CondBr1_0
  { CVT_imm_95_6, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_6__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_6, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_4__regCR0
  { CVT_imm_95_4, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_4__RegCRRC1_0
  { CVT_imm_95_4, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_7__regCR0
  { CVT_imm_95_7, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_7__RegCRRC1_0
  { CVT_imm_95_7, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_6__regCR0
  { CVT_imm_95_6, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_6__RegCRRC1_0
  { CVT_imm_95_6, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_44__regCR0__CondBr1_0
  { CVT_imm_95_44, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_44__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_44, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_47__regCR0__CondBr1_0
  { CVT_imm_95_47, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_47__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_47, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_46__regCR0__CondBr1_0
  { CVT_imm_95_46, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_46__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_46, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_44__regCR0
  { CVT_imm_95_44, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_44__RegCRRC1_0
  { CVT_imm_95_44, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_47__regCR0
  { CVT_imm_95_47, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_47__RegCRRC1_0
  { CVT_imm_95_47, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_46__regCR0
  { CVT_imm_95_46, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_46__RegCRRC1_0
  { CVT_imm_95_46, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__DirectBr1_0__Imm1_1
  { CVT_95_addBranchTargetOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__imm_95_36__regCR0__CondBr1_0
  { CVT_imm_95_36, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_36__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_36, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_39__regCR0__CondBr1_0
  { CVT_imm_95_39, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_39__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_39, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_38__regCR0__CondBr1_0
  { CVT_imm_95_38, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_38__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_38, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_36__regCR0
  { CVT_imm_95_36, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_36__RegCRRC1_0
  { CVT_imm_95_36, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_39__regCR0
  { CVT_imm_95_39, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_39__RegCRRC1_0
  { CVT_imm_95_39, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_38__regCR0
  { CVT_imm_95_38, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_38__RegCRRC1_0
  { CVT_imm_95_38, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_12__regCR0__CondBr1_0
  { CVT_imm_95_12, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_12__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_12, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_15__regCR0__CondBr1_0
  { CVT_imm_95_15, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_15__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_15, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_14__regCR0__CondBr1_0
  { CVT_imm_95_14, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_14__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_14, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_12__regCR0
  { CVT_imm_95_12, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_12__RegCRRC1_0
  { CVT_imm_95_12, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_15__regCR0
  { CVT_imm_95_15, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_15__RegCRRC1_0
  { CVT_imm_95_15, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_14__regCR0
  { CVT_imm_95_14, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_14__RegCRRC1_0
  { CVT_imm_95_14, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_68__regCR0__CondBr1_0
  { CVT_imm_95_68, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_68__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_68, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_71__regCR0__CondBr1_0
  { CVT_imm_95_71, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_71__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_71, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_70__regCR0__CondBr1_0
  { CVT_imm_95_70, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_70__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_70, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_68__regCR0
  { CVT_imm_95_68, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_68__RegCRRC1_0
  { CVT_imm_95_68, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_71__regCR0
  { CVT_imm_95_71, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_71__RegCRRC1_0
  { CVT_imm_95_71, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_70__regCR0
  { CVT_imm_95_70, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_70__RegCRRC1_0
  { CVT_imm_95_70, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_100__regCR0__CondBr1_0
  { CVT_imm_95_100, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_100__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_100, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_103__regCR0__CondBr1_0
  { CVT_imm_95_103, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_103__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_103, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_102__regCR0__CondBr1_0
  { CVT_imm_95_102, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_102__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_102, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_100__regCR0
  { CVT_imm_95_100, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_100__RegCRRC1_0
  { CVT_imm_95_100, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_103__regCR0
  { CVT_imm_95_103, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_103__RegCRRC1_0
  { CVT_imm_95_103, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_102__regCR0
  { CVT_imm_95_102, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_102__RegCRRC1_0
  { CVT_imm_95_102, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_Done },
  // Convert__imm_95_108__regCR0__CondBr1_0
  { CVT_imm_95_108, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_108__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_108, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_111__regCR0__CondBr1_0
  { CVT_imm_95_111, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_111__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_111, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_110__regCR0__CondBr1_0
  { CVT_imm_95_110, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_110__RegCRRC1_0__CondBr1_1
  { CVT_imm_95_110, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_108__regCR0
  { CVT_imm_95_108, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_108__RegCRRC1_0
  { CVT_imm_95_108, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_111__regCR0
  { CVT_imm_95_111, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_111__RegCRRC1_0
  { CVT_imm_95_111, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_110__regCR0
  { CVT_imm_95_110, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_110__RegCRRC1_0
  { CVT_imm_95_110, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_12__RegCRBITRC1_0__CondBr1_1
  { CVT_imm_95_12, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_15__RegCRBITRC1_0__CondBr1_1
  { CVT_imm_95_15, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_14__RegCRBITRC1_0__CondBr1_1
  { CVT_imm_95_14, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_12__RegCRBITRC1_0__imm_95_0
  { CVT_imm_95_12, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__imm_95_15__RegCRBITRC1_0__imm_95_0
  { CVT_imm_95_15, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__imm_95_14__RegCRBITRC1_0__imm_95_0
  { CVT_imm_95_14, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RC1_1__imm_95_0__U6Imm1_2
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_imm_95_0, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegG8RC1_0__RegGPRC1_1__imm_95_0__U6Imm1_2
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_imm_95_0, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__imm_95_0__U6Imm1_3
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_imm_95_0, 0, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RC1_1__U6Imm1_2__U6Imm1_3
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2__U5Imm1_3
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RC1_1__imm_95_0__U5Imm1_2__imm_95_31
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_imm_95_0, 0, CVT_95_addImmOperands, 3, CVT_imm_95_31, 0, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRC1_1__imm_95_0__U5Imm1_2__imm_95_31
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_imm_95_0, 0, CVT_95_addImmOperands, 3, CVT_imm_95_31, 0, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__imm_95_0__U5Imm1_3__imm_95_31
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_imm_95_0, 0, CVT_95_addImmOperands, 4, CVT_imm_95_31, 0, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__imm_95_0__U5Imm1_3__imm_95_31
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_imm_95_0, 0, CVT_95_addImmOperands, 4, CVT_imm_95_31, 0, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RC1_1__U6Imm1_2
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegCRRC1_0__RegGPRC1_2__RegGPRC1_3
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegGPRCOperands, 3, CVT_95_addRegGPRCOperands, 4, CVT_Done },
  // Convert__RegCRRC1_0__RegG8RC1_2__RegG8RC1_3
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegG8RCOperands, 3, CVT_95_addRegG8RCOperands, 4, CVT_Done },
  // Convert__regCR0__RegG8RC1_0__RegG8RC1_1
  { CVT_regCR0, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__RegCRRC1_0__RegG8RC1_1__RegG8RC1_2
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_Done },
  // Convert__regCR0__RegG8RC1_0__S16Imm1_1
  { CVT_regCR0, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__RegCRRC1_0__RegG8RC1_1__S16Imm1_2
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addS16ImmOperands, 3, CVT_Done },
  // Convert__RegCRBITRC1_0__RegG8RC1_1__RegG8RC1_2
  { CVT_95_addRegCRBITRCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_Done },
  // Convert__RegCRRC1_0__RegGPRC1_2__S16Imm1_3
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegGPRCOperands, 3, CVT_95_addS16ImmOperands, 4, CVT_Done },
  // Convert__RegCRRC1_0__RegG8RC1_2__S16Imm1_3
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegG8RCOperands, 3, CVT_95_addS16ImmOperands, 4, CVT_Done },
  // Convert__regCR0__RegG8RC1_0__U16Imm1_1
  { CVT_regCR0, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addU16ImmOperands, 2, CVT_Done },
  // Convert__RegCRRC1_0__RegG8RC1_1__U16Imm1_2
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addU16ImmOperands, 3, CVT_Done },
  // Convert__RegCRRC1_0__RegGPRC1_2__U16Imm1_3
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegGPRCOperands, 3, CVT_95_addU16ImmOperands, 4, CVT_Done },
  // Convert__RegCRRC1_0__RegG8RC1_2__U16Imm1_3
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegG8RCOperands, 3, CVT_95_addU16ImmOperands, 4, CVT_Done },
  // Convert__regCR0__RegGPRC1_0__RegGPRC1_1
  { CVT_regCR0, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__RegCRRC1_0__RegGPRC1_1__RegGPRC1_2
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_Done },
  // Convert__regCR0__RegGPRC1_0__U16Imm1_1
  { CVT_regCR0, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addU16ImmOperands, 2, CVT_Done },
  // Convert__RegCRRC1_0__RegGPRC1_1__U16Imm1_2
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addU16ImmOperands, 3, CVT_Done },
  // Convert__RegCRBITRC1_0__U1Imm1_1__RegG8RC1_2__RegG8RC1_3
  { CVT_95_addRegCRBITRCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addRegG8RCOperands, 4, CVT_Done },
  // Convert__regCR0__RegGPRC1_0__S16Imm1_1
  { CVT_regCR0, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__RegCRRC1_0__RegGPRC1_1__S16Imm1_2
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addS16ImmOperands, 3, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RC1_1
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRC1_1__U1Imm1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegCRBITRC1_0__RegCRBITRC1_1__RegCRBITRC1_2
  { CVT_95_addRegCRBITRCOperands, 1, CVT_95_addRegCRBITRCOperands, 2, CVT_95_addRegCRBITRCOperands, 3, CVT_Done },
  // Convert__RegCRBITRC1_0__RegCRBITRC1_0__RegCRBITRC1_0
  { CVT_95_addRegCRBITRCOperands, 1, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addRegCRBITRCOperands, 1, CVT_Done },
  // Convert__RegCRBITRC1_0__RegCRBITRC1_1__RegCRBITRC1_1
  { CVT_95_addRegCRBITRCOperands, 1, CVT_95_addRegCRBITRCOperands, 2, CVT_95_addRegCRBITRCOperands, 2, CVT_Done },
  // Convert__RegGxRCNoR01_0__RegGxRC1_1
  { CVT_95_addRegGxRCNoR0Operands, 1, CVT_95_addRegGxRCOperands, 2, CVT_Done },
  // Convert__U5Imm1_2__RegGxRCNoR01_0__RegGxRC1_1
  { CVT_95_addImmOperands, 3, CVT_95_addRegGxRCNoR0Operands, 1, CVT_95_addRegGxRCOperands, 2, CVT_Done },
  // Convert__RegGxRCNoR01_0__RegGxRC1_1__U5Imm1_2
  { CVT_95_addRegGxRCNoR0Operands, 1, CVT_95_addRegGxRCOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegGxRCNoR01_1__RegGxRC1_2__U5Imm1_0
  { CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__regR0__regR0
  { CVT_regR0, 0, CVT_regR0, 0, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addRegG8RCOperands, 4, CVT_Done },
  // Convert__U5Imm1_0
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__U5Imm1_2__RegGPRC1_0__RegGPRC1_1
  { CVT_95_addImmOperands, 3, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__RegSPERC1_0__RegSPERC1_1
  { CVT_95_addRegSPERCOperands, 1, CVT_95_addRegSPERCOperands, 2, CVT_Done },
  // Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2
  { CVT_95_addRegSPERCOperands, 1, CVT_95_addRegSPERCOperands, 2, CVT_95_addRegSPERCOperands, 3, CVT_Done },
  // Convert__RegSPERC1_0__RegSPE4RC1_1
  { CVT_95_addRegSPERCOperands, 1, CVT_95_addRegSPE4RCOperands, 2, CVT_Done },
  // Convert__RegSPERC1_0__RegGPRC1_1
  { CVT_95_addRegSPERCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegSPERCOperands, 2, CVT_95_addRegSPERCOperands, 3, CVT_Done },
  // Convert__RegGPRC1_0__RegSPERC1_1
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegSPERCOperands, 2, CVT_Done },
  // Convert__RegSPE4RC1_0__RegSPE4RC1_1
  { CVT_95_addRegSPE4RCOperands, 1, CVT_95_addRegSPE4RCOperands, 2, CVT_Done },
  // Convert__RegSPE4RC1_0__RegSPE4RC1_1__RegSPE4RC1_2
  { CVT_95_addRegSPE4RCOperands, 1, CVT_95_addRegSPE4RCOperands, 2, CVT_95_addRegSPE4RCOperands, 3, CVT_Done },
  // Convert__RegSPE4RC1_0__RegSPERC1_1
  { CVT_95_addRegSPE4RCOperands, 1, CVT_95_addRegSPERCOperands, 2, CVT_Done },
  // Convert__RegSPE4RC1_0__RegGPRC1_1
  { CVT_95_addRegSPE4RCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__RegCRRC1_0__RegSPE4RC1_1__RegSPE4RC1_2
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegSPE4RCOperands, 2, CVT_95_addRegSPE4RCOperands, 3, CVT_Done },
  // Convert__RegGPRC1_0__RegSPE4RC1_1
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegSPE4RCOperands, 2, CVT_Done },
  // Convert__RegSPERC1_0__RegSPERC1_2__U5Imm1_1
  { CVT_95_addRegSPERCOperands, 1, CVT_95_addRegSPERCOperands, 3, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__RegSPERC1_0__DispSPE81_1__RegGxRCNoR01_2
  { CVT_95_addRegSPERCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegSPERC1_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_95_addRegSPERCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegSPERC1_0__DispSPE21_1__RegGxRCNoR01_2
  { CVT_95_addRegSPERCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegSPERC1_0__DispSPE41_1__RegGxRCNoR01_2
  { CVT_95_addRegSPERCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegSPERC1_0__RegGPRC1_1__RegGPRC1_2
  { CVT_95_addRegSPERCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_Done },
  // Convert__RegSPERC1_0__RegSPERC1_1__U5Imm1_2
  { CVT_95_addRegSPERCOperands, 1, CVT_95_addRegSPERCOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegSPERC1_1__RegSPERC1_2__RegSPERC1_3__imm_95_0
  { CVT_95_addRegSPERCOperands, 2, CVT_95_addRegSPERCOperands, 3, CVT_95_addRegSPERCOperands, 4, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegSPERC1_0__S5Imm1_1
  { CVT_95_addRegSPERCOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__RegSPERC1_0__U5Imm1_1__RegSPERC1_2
  { CVT_95_addRegSPERCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegSPERCOperands, 3, CVT_Done },
  // Convert__RegF4RC1_0__RegF4RC1_1
  { CVT_95_addRegF4RCOperands, 1, CVT_95_addRegF4RCOperands, 2, CVT_Done },
  // Convert__RegF4RC1_1__RegF4RC1_2
  { CVT_95_addRegF4RCOperands, 2, CVT_95_addRegF4RCOperands, 3, CVT_Done },
  // Convert__RegF8RC1_0__RegF8RC1_1__RegF8RC1_2
  { CVT_95_addRegF8RCOperands, 1, CVT_95_addRegF8RCOperands, 2, CVT_95_addRegF8RCOperands, 3, CVT_Done },
  // Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3
  { CVT_95_addRegF8RCOperands, 2, CVT_95_addRegF8RCOperands, 3, CVT_95_addRegF8RCOperands, 4, CVT_Done },
  // Convert__RegF4RC1_0__RegF4RC1_1__RegF4RC1_2
  { CVT_95_addRegF4RCOperands, 1, CVT_95_addRegF4RCOperands, 2, CVT_95_addRegF4RCOperands, 3, CVT_Done },
  // Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3
  { CVT_95_addRegF4RCOperands, 2, CVT_95_addRegF4RCOperands, 3, CVT_95_addRegF4RCOperands, 4, CVT_Done },
  // Convert__RegF8RC1_0__RegF8RC1_1
  { CVT_95_addRegF8RCOperands, 1, CVT_95_addRegF8RCOperands, 2, CVT_Done },
  // Convert__RegF8RC1_1__RegF8RC1_2
  { CVT_95_addRegF8RCOperands, 2, CVT_95_addRegF8RCOperands, 3, CVT_Done },
  // Convert__RegF4RC1_0__RegF8RC1_1
  { CVT_95_addRegF4RCOperands, 1, CVT_95_addRegF8RCOperands, 2, CVT_Done },
  // Convert__RegF4RC1_1__RegF8RC1_2
  { CVT_95_addRegF4RCOperands, 2, CVT_95_addRegF8RCOperands, 3, CVT_Done },
  // Convert__RegCRRC1_0__RegF4RC1_1__RegF4RC1_2
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegF4RCOperands, 2, CVT_95_addRegF4RCOperands, 3, CVT_Done },
  // Convert__RegF8RC1_0__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3
  { CVT_95_addRegF8RCOperands, 1, CVT_95_addRegF8RCOperands, 2, CVT_95_addRegF8RCOperands, 3, CVT_95_addRegF8RCOperands, 4, CVT_Done },
  // Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4
  { CVT_95_addRegF8RCOperands, 2, CVT_95_addRegF8RCOperands, 3, CVT_95_addRegF8RCOperands, 4, CVT_95_addRegF8RCOperands, 5, CVT_Done },
  // Convert__RegF4RC1_0__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3
  { CVT_95_addRegF4RCOperands, 1, CVT_95_addRegF4RCOperands, 2, CVT_95_addRegF4RCOperands, 3, CVT_95_addRegF4RCOperands, 4, CVT_Done },
  // Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4
  { CVT_95_addRegF4RCOperands, 2, CVT_95_addRegF4RCOperands, 3, CVT_95_addRegF4RCOperands, 4, CVT_95_addRegF4RCOperands, 5, CVT_Done },
  // Convert__RegF4RC1_0__RegF8RC1_1__RegF4RC1_2__RegF4RC1_3
  { CVT_95_addRegF4RCOperands, 1, CVT_95_addRegF8RCOperands, 2, CVT_95_addRegF4RCOperands, 3, CVT_95_addRegF4RCOperands, 4, CVT_Done },
  // Convert__RegF4RC1_1__RegF8RC1_2__RegF4RC1_3__RegF4RC1_4
  { CVT_95_addRegF4RCOperands, 2, CVT_95_addRegF8RCOperands, 3, CVT_95_addRegF4RCOperands, 4, CVT_95_addRegF4RCOperands, 5, CVT_Done },
  // Convert__RegCRRC1_0__RegF8RC1_1__RegF8RC1_2
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegF8RCOperands, 2, CVT_95_addRegF8RCOperands, 3, CVT_Done },
  // Convert__RegCRRC1_0__RegF8RC1_1
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegF8RCOperands, 2, CVT_Done },
  // Convert__U4Imm1_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_95_addImmOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__U4Imm1_1__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_95_addRegGxRCOperands, 4, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRCNoR01_1__RegGPRC1_2__RegCRBITRC1_3
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCNoR0Operands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addRegCRBITRCOperands, 4, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RCNoX01_1__RegG8RC1_2__regCR0EQ
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCNoX0Operands, 2, CVT_95_addRegG8RCOperands, 3, CVT_regCR0EQ, 0, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRCNoR01_1__RegGPRC1_2__regCR0EQ
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCNoR0Operands, 2, CVT_95_addRegGPRCOperands, 3, CVT_regCR0EQ, 0, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RCNoX01_1__RegG8RC1_2__regCR0GT
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCNoX0Operands, 2, CVT_95_addRegG8RCOperands, 3, CVT_regCR0GT, 0, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRCNoR01_1__RegGPRC1_2__regCR0GT
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCNoR0Operands, 2, CVT_95_addRegGPRCOperands, 3, CVT_regCR0GT, 0, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RCNoX01_1__RegG8RC1_2__regCR0LT
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCNoX0Operands, 2, CVT_95_addRegG8RCOperands, 3, CVT_regCR0LT, 0, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRCNoR01_1__RegGPRC1_2__regCR0LT
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCNoR0Operands, 2, CVT_95_addRegGPRCOperands, 3, CVT_regCR0LT, 0, CVT_Done },
  // Convert__RegGPRC1_0__DispRI1_1__RegGxRCNoR01_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_0__DispRI1_1__RegGxRCNoR01_2
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_0, 0, CVT_95_addS16ImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_0, 0, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegG8RC1_0__RegGxRCNoR01_1__TLSReg1_2
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addTLSRegOperands, 3, CVT_Done },
  // Convert__RegG8RC1_0__DispRIX1_1__RegGxRCNoR01_2
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegG8RC1_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RC1_1__U5Imm1_2
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegG8RC1_0__imm_95_0__DispRIX1_1__RegGxRCNoR01_2
  { CVT_95_addRegG8RCOperands, 1, CVT_imm_95_0, 0, CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegG8RC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_95_addRegG8RCOperands, 1, CVT_imm_95_0, 0, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegF8RC1_0__DispRI1_1__RegGxRCNoR01_2
  { CVT_95_addRegF8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegF8RC1_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_95_addRegF8RCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegF8RC1_0__imm_95_0__DispRI1_1__RegGxRCNoR01_2
  { CVT_95_addRegF8RCOperands, 1, CVT_imm_95_0, 0, CVT_95_addS16ImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegF8RC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_95_addRegF8RCOperands, 1, CVT_imm_95_0, 0, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegF4RC1_0__DispRI1_1__RegGxRCNoR01_2
  { CVT_95_addRegF4RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegF4RC1_0__imm_95_0__DispRI1_1__RegGxRCNoR01_2
  { CVT_95_addRegF4RCOperands, 1, CVT_imm_95_0, 0, CVT_95_addS16ImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegF4RC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_95_addRegF4RCOperands, 1, CVT_imm_95_0, 0, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegF4RC1_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_95_addRegF4RCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegG8RC1_0__regZERO8__S16Imm1_1
  { CVT_95_addRegG8RCOperands, 1, CVT_regZERO8, 0, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__RegGPRC1_0__S16Imm1_1
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__RegGPRC1_0__regZERO__S16Imm1_1
  { CVT_95_addRegGPRCOperands, 1, CVT_regZERO, 0, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__RegG8RC1_0__regZERO8__S17Imm1_1
  { CVT_95_addRegG8RCOperands, 1, CVT_regZERO8, 0, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__RegGPRC1_0__S17Imm1_1
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__RegGPRC1_0__regZERO__S17Imm1_1
  { CVT_95_addRegGPRCOperands, 1, CVT_regZERO, 0, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__RegG8RC1_0__imm_95_0
  { CVT_95_addRegG8RCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegVRRC1_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__imm_95_1
  { CVT_imm_95_1, 0, CVT_Done },
  // Convert__RegSPE4RC1_0__DispRI1_1__RegGxRCNoR01_2
  { CVT_95_addRegSPE4RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegSPE4RC1_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_95_addRegSPE4RCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegVFRC1_0__DispRIX1_1__RegGxRCNoR01_2
  { CVT_95_addRegVFRCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegVSFRC1_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_95_addRegVSFRCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegVSSRC1_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_95_addRegVSSRCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegVSRC1_0__DispRIX161_1__RegGxRCNoR01_2
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegVSRC1_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegVSRC1_0__Imm1_1__RegG8RC1_2
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addRegG8RCOperands, 4, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addRegGPRCOperands, 4, CVT_Done },
  // Convert__imm_95_0
  { CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegCRRC1_0__RegCRRC1_1
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegCRRCOperands, 2, CVT_Done },
  // Convert__RegCRRC1_0
  { CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_29
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_29, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_280
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_280, 0, CVT_Done },
  // Convert__RegGPRC1_0__U10Imm1_1__imm_95_0
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addImmOperands, 2, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_128
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_128, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_129
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_129, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_130
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_130, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_131
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_131, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_132
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_132, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_133
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_133, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_134
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_134, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_135
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_135, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_28
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_28, 0, CVT_Done },
  // Convert__RegGPRC1_0
  { CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_19
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_19, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_537
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_537, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_539
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_539, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_541
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_541, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_543
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_543, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_536
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_536, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_538
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_538, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_540
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_540, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_542
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_542, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_1018
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_1018, 0, CVT_Done },
  // Convert__RegGPRC1_0__Imm1_1
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_981
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_981, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_22
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_22, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_17
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_17, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_18
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_18, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_980
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_980, 0, CVT_Done },
  // Convert__RegG8RC1_0__RegF8RC1_1
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegF8RCOperands, 2, CVT_Done },
  // Convert__RegGPRC1_0__RegF8RC1_1
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegF8RCOperands, 2, CVT_Done },
  // Convert__RegF8RC1_0
  { CVT_95_addRegF8RCOperands, 1, CVT_Done },
  // Convert__RegF8RC1_1
  { CVT_95_addRegF8RCOperands, 2, CVT_Done },
  // Convert__RegF8RC1_0__U3Imm1_1
  { CVT_95_addRegF8RCOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__RegF8RC1_0__U2Imm1_1
  { CVT_95_addRegF8RCOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_529
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_529, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_531
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_531, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_533
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_533, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_535
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_535, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_528
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_528, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_530
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_530, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_532
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_532, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_534
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_534, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_1019
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_1019, 0, CVT_Done },
  // Convert__RegGPRC1_0__CRBitMask1_1
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addCRBitMaskOperands, 2, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_48
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_48, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_287
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_287, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_5
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_5, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_4
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_4, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_25
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_25, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_512
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_512, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_272
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_272, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_273
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_273, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_274
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_274, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_275
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_275, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_260
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_260, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_261
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_261, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_262
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_262, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_263
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_263, 0, CVT_Done },
  // Convert__RegGPRC1_0__U4Imm1_1
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_26
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_26, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_27
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_27, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_990
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_990, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_991
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_991, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_268
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_268, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_988
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_988, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_989
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_989, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_269
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_269, 0, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_986
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_986, 0, CVT_Done },
  // Convert__RegG8RC1_0__RegVRRC1_1
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegVRRCOperands, 2, CVT_Done },
  // Convert__RegGPRC1_0__RegVRRC1_1
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegVRRCOperands, 2, CVT_Done },
  // Convert__RegVRRC1_0
  { CVT_95_addRegVRRCOperands, 1, CVT_Done },
  // Convert__RegG8RC1_0__RegVSFRC1_1
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegVSFRCOperands, 2, CVT_Done },
  // Convert__RegG8RC1_0__RegVSRC1_1
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_Done },
  // Convert__RegGPRC1_0__RegVSFRC1_1
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegVSFRCOperands, 2, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_1
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_1, 0, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_1
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_1
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_2
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addRegG8RCOperands, 3, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_2
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addRegGPRCOperands, 3, CVT_Done },
  // Convert__imm_95_29__RegGPRC1_0
  { CVT_imm_95_29, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_280__RegGPRC1_0
  { CVT_imm_95_280, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_28__RegGPRC1_0
  { CVT_imm_95_28, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_255__RegG8RC1_0
  { CVT_imm_95_255, 0, CVT_95_addRegG8RCOperands, 1, CVT_Done },
  // Convert__imm_95_255__RegGPRC1_0
  { CVT_imm_95_255, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__Imm1_0__RegGPRC1_1
  { CVT_95_addImmOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_19__RegGPRC1_0
  { CVT_imm_95_19, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_537__RegGPRC1_1
  { CVT_imm_95_537, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_539__RegGPRC1_1
  { CVT_imm_95_539, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_541__RegGPRC1_1
  { CVT_imm_95_541, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_543__RegGPRC1_1
  { CVT_imm_95_543, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_536__RegGPRC1_1
  { CVT_imm_95_536, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_538__RegGPRC1_1
  { CVT_imm_95_538, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_540__RegGPRC1_1
  { CVT_imm_95_540, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_542__RegGPRC1_1
  { CVT_imm_95_542, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_1018__RegGPRC1_0
  { CVT_imm_95_1018, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__RegGPRC1_1__Imm1_0
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__imm_95_981__RegGPRC1_0
  { CVT_imm_95_981, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_22__RegGPRC1_0
  { CVT_imm_95_22, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_17__RegGPRC1_0
  { CVT_imm_95_17, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_18__RegGPRC1_0
  { CVT_imm_95_18, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_980__RegGPRC1_0
  { CVT_imm_95_980, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__RegF8RC1_0__RegG8RC1_1
  { CVT_95_addRegF8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__RegF8RC1_0__RegGPRC1_1
  { CVT_95_addRegF8RCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__Imm1_0__RegF8RC1_1__imm_95_0__imm_95_0
  { CVT_95_addImmOperands, 1, CVT_95_addRegF8RCOperands, 2, CVT_imm_95_0, 0, CVT_imm_95_0, 0, CVT_Done },
  // Convert__Imm1_1__RegF8RC1_2__imm_95_0__imm_95_0
  { CVT_95_addImmOperands, 2, CVT_95_addRegF8RCOperands, 3, CVT_imm_95_0, 0, CVT_imm_95_0, 0, CVT_Done },
  // Convert__Imm1_0__RegF8RC1_1__Imm1_2__Imm1_3
  { CVT_95_addImmOperands, 1, CVT_95_addRegF8RCOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__Imm1_1__RegF8RC1_2__Imm1_3__Imm1_4
  { CVT_95_addImmOperands, 2, CVT_95_addRegF8RCOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__RegCRRC1_0__Imm1_1__imm_95_0
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addImmOperands, 2, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegCRRC1_1__Imm1_2__imm_95_0
  { CVT_95_addRegCRRCOperands, 2, CVT_95_addImmOperands, 3, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegCRRC1_0__Imm1_1__Imm1_2
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegCRRC1_1__Imm1_2__Imm1_3
  { CVT_95_addRegCRRCOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__imm_95_529__RegGPRC1_1
  { CVT_imm_95_529, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_531__RegGPRC1_1
  { CVT_imm_95_531, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_533__RegGPRC1_1
  { CVT_imm_95_533, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_535__RegGPRC1_1
  { CVT_imm_95_535, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_528__RegGPRC1_1
  { CVT_imm_95_528, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_530__RegGPRC1_1
  { CVT_imm_95_530, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_532__RegGPRC1_1
  { CVT_imm_95_532, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_534__RegGPRC1_1
  { CVT_imm_95_534, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_1019__RegGPRC1_0
  { CVT_imm_95_1019, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__RegGPRC1_0__imm_95_0
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__CRBitMask1_0__RegGPRC1_1
  { CVT_95_addCRBitMaskOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_48__RegGPRC1_0
  { CVT_imm_95_48, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_25__RegGPRC1_0
  { CVT_imm_95_25, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_512__RegGPRC1_0
  { CVT_imm_95_512, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_272__RegGPRC1_1
  { CVT_imm_95_272, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_273__RegGPRC1_1
  { CVT_imm_95_273, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_274__RegGPRC1_1
  { CVT_imm_95_274, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_275__RegGPRC1_1
  { CVT_imm_95_275, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_260__RegGPRC1_1
  { CVT_imm_95_260, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_261__RegGPRC1_1
  { CVT_imm_95_261, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_262__RegGPRC1_1
  { CVT_imm_95_262, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_263__RegGPRC1_1
  { CVT_imm_95_263, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_272__RegGPRC1_0
  { CVT_imm_95_272, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_273__RegGPRC1_0
  { CVT_imm_95_273, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_274__RegGPRC1_0
  { CVT_imm_95_274, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_275__RegGPRC1_0
  { CVT_imm_95_275, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_260__RegGPRC1_0
  { CVT_imm_95_260, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_261__RegGPRC1_0
  { CVT_imm_95_261, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_262__RegGPRC1_0
  { CVT_imm_95_262, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_263__RegGPRC1_0
  { CVT_imm_95_263, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__RegGPRC1_1__U4Imm1_0
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__imm_95_26__RegGPRC1_0
  { CVT_imm_95_26, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_27__RegGPRC1_0
  { CVT_imm_95_27, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_990__RegGPRC1_0
  { CVT_imm_95_990, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_991__RegGPRC1_0
  { CVT_imm_95_991, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_988__RegGPRC1_0
  { CVT_imm_95_988, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_284__RegGPRC1_0
  { CVT_imm_95_284, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_989__RegGPRC1_0
  { CVT_imm_95_989, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_285__RegGPRC1_0
  { CVT_imm_95_285, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_986__RegGPRC1_0
  { CVT_imm_95_986, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__RegVRRC1_0__RegG8RC1_1
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__RegVRRC1_0__RegGPRC1_1
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__RegVSFRC1_0__RegG8RC1_1
  { CVT_95_addRegVSFRCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__RegVSRC1_0__RegG8RCNoX01_1__RegG8RC1_2
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegG8RCNoX0Operands, 2, CVT_95_addRegG8RCOperands, 3, CVT_Done },
  // Convert__RegVSFRC1_0__RegGPRC1_1
  { CVT_95_addRegVSFRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__RegVSRC1_0__RegGPRC1_1
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_1__RegGPRC1_0
  { CVT_imm_95_1, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__regR0__regR0__imm_95_0
  { CVT_regR0, 0, CVT_regR0, 0, CVT_imm_95_0, 0, CVT_Done },
  // Convert__regX0__regX0__imm_95_0
  { CVT_regX0, 0, CVT_regX0, 0, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRC1_1__U16Imm1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addU16ImmOperands, 3, CVT_Done },
  // Convert__RegGPRC1_0__ImmZero1_1__S34Imm1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRC1_1__S34Imm1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__U1Imm1_3
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegGPRC1_0__DispRI341_1__ImmZero1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegGPRC1_0__DispRI341_1__RegGxRCNoR01_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegG8RC1_0__DispRI341_1__ImmZero1_2
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegG8RC1_0__DispRI341_1__RegGxRCNoR01_2
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegF8RC1_0__DispRI341_1__ImmZero1_2
  { CVT_95_addRegF8RCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegF8RC1_0__DispRI341_1__RegGxRCNoR01_2
  { CVT_95_addRegF8RCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegF4RC1_0__DispRI341_1__ImmZero1_2
  { CVT_95_addRegF4RCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegF4RC1_0__DispRI341_1__RegGxRCNoR01_2
  { CVT_95_addRegF4RCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegGPRC1_0__S34Imm1_1
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__RegVFRC1_0__DispRI341_1__ImmZero1_2
  { CVT_95_addRegVFRCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegVFRC1_0__DispRI341_1__RegGxRCNoR01_2
  { CVT_95_addRegVFRCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegVSRC1_0__DispRI341_1__ImmZero1_2
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegVSRC1_0__DispRI341_1__RegGxRCNoR01_2
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__imm_95_2
  { CVT_imm_95_2, 0, CVT_Done },
  // Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_2__U2Imm1_3
  { CVT_95_addRegQFRCOperands, 1, CVT_95_addRegQFRCOperands, 2, CVT_95_addRegQFRCOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegQFRC1_0__RegQFRC1_1__U2Imm1_2
  { CVT_95_addRegQFRCOperands, 1, CVT_95_addRegQFRCOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegQFRC1_0__RegQFRC1_1
  { CVT_95_addRegQFRCOperands, 1, CVT_95_addRegQFRCOperands, 2, CVT_Done },
  // Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_2
  { CVT_95_addRegQFRCOperands, 1, CVT_95_addRegQFRCOperands, 2, CVT_95_addRegQFRCOperands, 3, CVT_Done },
  // Convert__RegQSRC1_0__RegQSRC1_1__RegQSRC1_2
  { CVT_95_addRegQSRCOperands, 1, CVT_95_addRegQSRCOperands, 2, CVT_95_addRegQSRCOperands, 3, CVT_Done },
  // Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_1
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 3, CVT_imm_95_1, 0, CVT_Done },
  // Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_4
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 3, CVT_imm_95_4, 0, CVT_Done },
  // Convert__RegQBRC1_0__RegQBRC1_0__RegQBRC1_0__imm_95_0
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegQBRC1_0__RegQFRC1_1__RegQFRC1_2
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQFRCOperands, 2, CVT_95_addRegQFRCOperands, 3, CVT_Done },
  // Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_1__imm_95_5
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 2, CVT_imm_95_5, 0, CVT_Done },
  // Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_9
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 3, CVT_imm_95_9, 0, CVT_Done },
  // Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__U12Imm1_3
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3
  { CVT_95_addRegQFRCOperands, 1, CVT_95_addRegQFRCOperands, 2, CVT_95_addRegQFRCOperands, 3, CVT_95_addRegQFRCOperands, 4, CVT_Done },
  // Convert__RegQSRC1_0__RegQSRC1_1__RegQSRC1_2__RegQSRC1_3
  { CVT_95_addRegQSRCOperands, 1, CVT_95_addRegQSRCOperands, 2, CVT_95_addRegQSRCOperands, 3, CVT_95_addRegQSRCOperands, 4, CVT_Done },
  // Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_14
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 3, CVT_imm_95_14, 0, CVT_Done },
  // Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_8
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 3, CVT_imm_95_8, 0, CVT_Done },
  // Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_1__imm_95_10
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 2, CVT_imm_95_10, 0, CVT_Done },
  // Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_7
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 3, CVT_imm_95_7, 0, CVT_Done },
  // Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_13
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 3, CVT_imm_95_13, 0, CVT_Done },
  // Convert__RegQSRC1_0__RegQFRC1_1
  { CVT_95_addRegQSRCOperands, 1, CVT_95_addRegQFRCOperands, 2, CVT_Done },
  // Convert__RegQFRC1_0__RegQBRC1_1__RegQFRC1_3__RegQFRC1_2
  { CVT_95_addRegQFRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQFRCOperands, 4, CVT_95_addRegQFRCOperands, 3, CVT_Done },
  // Convert__RegQBRC1_0__RegQBRC1_0__RegQBRC1_0__imm_95_15
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 1, CVT_imm_95_15, 0, CVT_Done },
  // Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_3__RegQFRC1_2
  { CVT_95_addRegQFRCOperands, 1, CVT_95_addRegQFRCOperands, 2, CVT_95_addRegQFRCOperands, 4, CVT_95_addRegQFRCOperands, 3, CVT_Done },
  // Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_6
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 3, CVT_imm_95_6, 0, CVT_Done },
  // Convert__RegQFRC1_0__U12Imm1_1
  { CVT_95_addRegQFRCOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_95_addRegQFRCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegQFRC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_95_addRegQFRCOperands, 1, CVT_imm_95_0, 0, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegQSRC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_95_addRegQSRCOperands, 1, CVT_imm_95_0, 0, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__imm_95_0__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_imm_95_0, 0, CVT_95_addRegQFRCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__imm_95_0__RegQSRC1_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_imm_95_0, 0, CVT_95_addRegQSRCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__U1Imm1_0
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RC1_1__RegGPRC1_2__U6Imm1_3
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3__U6Imm1_4
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addRegGPRCOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__RegG8RC1_0__Tie0_1_1__RegG8RC1_1__U6Imm1_2__U6Imm1_3
  { CVT_95_addRegG8RCOperands, 1, CVT_Tied, Tie0_1_1, CVT_95_addRegG8RCOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegG8RC1_1__Tie0_1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4
  { CVT_95_addRegG8RCOperands, 2, CVT_Tied, Tie0_1_1, CVT_95_addRegG8RCOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RC1_1__U5Imm1_2__Imm1_3
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__U5Imm1_3__Imm1_4
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__RegGPRC1_0__Tie0_1_1__RegGPRC1_1__U5Imm1_2__U5Imm1_3__U5Imm1_4
  { CVT_95_addRegGPRCOperands, 1, CVT_Tied, Tie0_1_1, CVT_95_addRegGPRCOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__RegGPRC1_1__Tie0_1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4__U5Imm1_5
  { CVT_95_addRegGPRCOperands, 2, CVT_Tied, Tie0_1_1, CVT_95_addRegGPRCOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_95_addImmOperands, 6, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2__U5Imm1_3__U5Imm1_4
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4__U5Imm1_5
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_95_addImmOperands, 6, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3__U5Imm1_4__U5Imm1_5
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addRegGPRCOperands, 4, CVT_95_addImmOperands, 5, CVT_95_addImmOperands, 6, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RC1_1__RegGPRC1_2__imm_95_0
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3__imm_95_0
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addRegGPRCOperands, 4, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RC1_1__U6Imm1_2__imm_95_0
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addImmOperands, 3, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegG8RC1_0__RegGPRC1_1__U6Imm1_2__imm_95_0
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addImmOperands, 3, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__imm_95_0
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addImmOperands, 4, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2__imm_95_0__imm_95_31
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_imm_95_0, 0, CVT_imm_95_31, 0, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2__imm_95_0__imm_95_31
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_imm_95_0, 0, CVT_imm_95_31, 0, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3__imm_95_0__imm_95_31
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addRegG8RCOperands, 4, CVT_imm_95_0, 0, CVT_imm_95_31, 0, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3__imm_95_0__imm_95_31
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addRegGPRCOperands, 4, CVT_imm_95_0, 0, CVT_imm_95_31, 0, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RC1_1__U5Imm1_2__imm_95_0__imm_95_31
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addImmOperands, 3, CVT_imm_95_0, 0, CVT_imm_95_31, 0, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2__imm_95_0__imm_95_31
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addImmOperands, 3, CVT_imm_95_0, 0, CVT_imm_95_31, 0, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__U5Imm1_3__imm_95_0__imm_95_31
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addImmOperands, 4, CVT_imm_95_0, 0, CVT_imm_95_31, 0, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__imm_95_0__imm_95_31
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addImmOperands, 4, CVT_imm_95_0, 0, CVT_imm_95_31, 0, CVT_Done },
  // Convert__Imm1_0
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__RegGPRC1_0__RegCRRC1_1
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegCRRCOperands, 2, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RC1_1__RegGPRC1_2
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addRegGPRCOperands, 4, CVT_Done },
  // Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_95_addRegGxRCOperands, 4, CVT_Done },
  // Convert__imm_95_0__RegGPRC1_0__DispRI1_1__RegGxRCNoR01_2
  { CVT_imm_95_0, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__imm_95_0__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_imm_95_0, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegG8RC1_1__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_95_addRegGxRCOperands, 4, CVT_Done },
  // Convert__imm_95_0__RegG8RC1_0__DispRIX1_1__RegGxRCNoR01_2
  { CVT_imm_95_0, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__imm_95_0__RegG8RC1_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_imm_95_0, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__imm_95_0__RegF8RC1_0__DispRI1_1__RegGxRCNoR01_2
  { CVT_imm_95_0, 0, CVT_95_addRegF8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__imm_95_0__RegF8RC1_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_imm_95_0, 0, CVT_95_addRegF8RCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__imm_95_0__RegF4RC1_0__DispRI1_1__RegGxRCNoR01_2
  { CVT_imm_95_0, 0, CVT_95_addRegF4RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__imm_95_0__RegF4RC1_0__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_imm_95_0, 0, CVT_95_addRegF4RCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RC1_2__RegG8RC1_1
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 3, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRC1_2__RegGPRC1_1
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 3, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_3__RegG8RC1_2
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 4, CVT_95_addRegG8RCOperands, 3, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_3__RegGPRC1_2
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 4, CVT_95_addRegGPRCOperands, 3, CVT_Done },
  // Convert__RegG8RC1_0__S16Imm1_1
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__RegGPRC1_1
  { CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__U5Imm1_1__RegGPRC1_2__RegGPRC1_3
  { CVT_95_addImmOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addRegGPRCOperands, 4, CVT_Done },
  // Convert__U5Imm1_1__RegGPRC1_2__U5Imm1_3
  { CVT_95_addImmOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__U1Imm1_1
  { CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__U5Imm1_0__RegG8RC1_1__RegG8RC1_2
  { CVT_95_addImmOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_Done },
  // Convert__imm_95_4__RegG8RC1_0__RegG8RC1_1
  { CVT_imm_95_4, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_4__RegG8RC1_0__S16Imm1_1
  { CVT_imm_95_4, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_12__RegG8RC1_0__RegG8RC1_1
  { CVT_imm_95_12, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_12__RegG8RC1_0__S16Imm1_1
  { CVT_imm_95_12, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_8__RegG8RC1_0__RegG8RC1_1
  { CVT_imm_95_8, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_8__RegG8RC1_0__S16Imm1_1
  { CVT_imm_95_8, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__U5Imm1_0__RegG8RC1_1__S16Imm1_2
  { CVT_95_addImmOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addS16ImmOperands, 3, CVT_Done },
  // Convert__imm_95_20__RegG8RC1_0__RegG8RC1_1
  { CVT_imm_95_20, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_20__RegG8RC1_0__S16Imm1_1
  { CVT_imm_95_20, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_5__RegG8RC1_0__RegG8RC1_1
  { CVT_imm_95_5, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_5__RegG8RC1_0__S16Imm1_1
  { CVT_imm_95_5, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_1__RegG8RC1_0__RegG8RC1_1
  { CVT_imm_95_1, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_1__RegG8RC1_0__S16Imm1_1
  { CVT_imm_95_1, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_6__RegG8RC1_0__RegG8RC1_1
  { CVT_imm_95_6, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_6__RegG8RC1_0__S16Imm1_1
  { CVT_imm_95_6, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_2__RegG8RC1_0__RegG8RC1_1
  { CVT_imm_95_2, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_2__RegG8RC1_0__S16Imm1_1
  { CVT_imm_95_2, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_16__RegG8RC1_0__RegG8RC1_1
  { CVT_imm_95_16, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_16__RegG8RC1_0__S16Imm1_1
  { CVT_imm_95_16, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_24__RegG8RC1_0__RegG8RC1_1
  { CVT_imm_95_24, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_24__RegG8RC1_0__S16Imm1_1
  { CVT_imm_95_24, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_31__RegG8RC1_0__RegG8RC1_1
  { CVT_imm_95_31, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_31__RegG8RC1_0__S16Imm1_1
  { CVT_imm_95_31, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__regR0__RegGPRC1_0
  { CVT_regR0, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_0
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRC1_1__Imm1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRC1_1__imm_95_0
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegGPRC1_0__RegGPRC1_1__imm_95_1
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_imm_95_1, 0, CVT_Done },
  // Convert__imm_95_31__regR0__regR0
  { CVT_imm_95_31, 0, CVT_regR0, 0, CVT_regR0, 0, CVT_Done },
  // Convert__U5Imm1_0__RegGPRC1_1__RegGPRC1_2
  { CVT_95_addImmOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_Done },
  // Convert__imm_95_4__RegGPRC1_0__RegGPRC1_1
  { CVT_imm_95_4, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_4__RegGPRC1_0__S16Imm1_1
  { CVT_imm_95_4, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_12__RegGPRC1_0__RegGPRC1_1
  { CVT_imm_95_12, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_12__RegGPRC1_0__S16Imm1_1
  { CVT_imm_95_12, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_8__RegGPRC1_0__RegGPRC1_1
  { CVT_imm_95_8, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_8__RegGPRC1_0__S16Imm1_1
  { CVT_imm_95_8, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__U5Imm1_0__RegGPRC1_1__S16Imm1_2
  { CVT_95_addImmOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addS16ImmOperands, 3, CVT_Done },
  // Convert__imm_95_20__RegGPRC1_0__RegGPRC1_1
  { CVT_imm_95_20, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_20__RegGPRC1_0__S16Imm1_1
  { CVT_imm_95_20, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_5__RegGPRC1_0__RegGPRC1_1
  { CVT_imm_95_5, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_5__RegGPRC1_0__S16Imm1_1
  { CVT_imm_95_5, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_1__RegGPRC1_0__RegGPRC1_1
  { CVT_imm_95_1, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_1__RegGPRC1_0__S16Imm1_1
  { CVT_imm_95_1, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_6__RegGPRC1_0__RegGPRC1_1
  { CVT_imm_95_6, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_6__RegGPRC1_0__S16Imm1_1
  { CVT_imm_95_6, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_2__RegGPRC1_0__RegGPRC1_1
  { CVT_imm_95_2, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_2__RegGPRC1_0__S16Imm1_1
  { CVT_imm_95_2, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_16__RegGPRC1_0__RegGPRC1_1
  { CVT_imm_95_16, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_16__RegGPRC1_0__S16Imm1_1
  { CVT_imm_95_16, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_24__RegGPRC1_0__RegGPRC1_1
  { CVT_imm_95_24, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_24__RegGPRC1_0__S16Imm1_1
  { CVT_imm_95_24, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_31__RegGPRC1_0__RegGPRC1_1
  { CVT_imm_95_31, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_31__RegGPRC1_0__S16Imm1_1
  { CVT_imm_95_31, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addRegVRRCOperands, 2, CVT_95_addRegVRRCOperands, 3, CVT_Done },
  // Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addRegVRRCOperands, 2, CVT_95_addRegVRRCOperands, 3, CVT_95_addRegVRRCOperands, 4, CVT_Done },
  // Convert__RegVRRC1_0__U5Imm1_2__RegVRRC1_1
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addImmOperands, 3, CVT_95_addRegVRRCOperands, 2, CVT_Done },
  // Convert__RegVRRC1_0__RegVRRC1_1
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addRegVRRCOperands, 2, CVT_Done },
  // Convert__RegVRRC1_0__U4Imm1_2__RegVRRC1_1
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addImmOperands, 3, CVT_95_addRegVRRCOperands, 2, CVT_Done },
  // Convert__RegG8RC1_0__RegG8RC1_1__RegVRRC1_2
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addRegVRRCOperands, 3, CVT_Done },
  // Convert__RegVRRC1_0__Tie0_1_1__U4Imm1_2__RegVRRC1_1
  { CVT_95_addRegVRRCOperands, 1, CVT_Tied, Tie0_1_1, CVT_95_addImmOperands, 3, CVT_95_addRegVRRCOperands, 2, CVT_Done },
  // Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_1
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addRegVRRCOperands, 2, CVT_95_addRegVRRCOperands, 2, CVT_Done },
  // Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__Tie0_1_1
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addRegVRRCOperands, 2, CVT_95_addRegVRRCOperands, 3, CVT_Tied, Tie0_1_1, CVT_Done },
  // Convert__RegVRRC1_0__RegVRRC1_1__U1Imm1_2__U4Imm1_3
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addRegVRRCOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__U4Imm1_3
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addRegVRRCOperands, 2, CVT_95_addRegVRRCOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegVRRC1_0__S5Imm1_1
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__RegVSFRC1_0__RegVSFRC1_1
  { CVT_95_addRegVSFRCOperands, 1, CVT_95_addRegVSFRCOperands, 2, CVT_Done },
  // Convert__RegVSFRC1_0__RegVSFRC1_1__RegVSFRC1_2
  { CVT_95_addRegVSFRCOperands, 1, CVT_95_addRegVSFRCOperands, 2, CVT_95_addRegVSFRCOperands, 3, CVT_Done },
  // Convert__RegVSSRC1_0__RegVSSRC1_1__RegVSSRC1_2
  { CVT_95_addRegVSSRCOperands, 1, CVT_95_addRegVSSRCOperands, 2, CVT_95_addRegVSSRCOperands, 3, CVT_Done },
  // Convert__RegVSRC1_0__RegVSFRC1_1__RegVSFRC1_2
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSFRCOperands, 2, CVT_95_addRegVSFRCOperands, 3, CVT_Done },
  // Convert__RegCRRC1_0__RegVSFRC1_1__RegVSFRC1_2
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegVSFRCOperands, 2, CVT_95_addRegVSFRCOperands, 3, CVT_Done },
  // Convert__RegCRRC1_0__RegVRRC1_1__RegVRRC1_2
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegVRRCOperands, 2, CVT_95_addRegVRRCOperands, 3, CVT_Done },
  // Convert__RegVRRC1_0__RegVFRC1_1
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addRegVFRCOperands, 2, CVT_Done },
  // Convert__RegVSRC1_0__RegVSSRC1_1
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSSRCOperands, 2, CVT_Done },
  // Convert__RegVFRC1_0__RegVRRC1_1
  { CVT_95_addRegVFRCOperands, 1, CVT_95_addRegVRRCOperands, 2, CVT_Done },
  // Convert__RegVSSRC1_0__RegVSRC1_1
  { CVT_95_addRegVSSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_Done },
  // Convert__RegVSSRC1_0__RegVSFRC1_1
  { CVT_95_addRegVSSRCOperands, 1, CVT_95_addRegVSFRCOperands, 2, CVT_Done },
  // Convert__RegVSRC1_0__RegG8RC1_1__RegG8RC1_2
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_Done },
  // Convert__RegVRRC1_0__RegVRRC1_1__RegVSFRC1_2
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addRegVRRCOperands, 2, CVT_95_addRegVSFRCOperands, 3, CVT_Done },
  // Convert__RegVSFRC1_0__Tie0_1_1__RegVSFRC1_1__RegVSFRC1_2
  { CVT_95_addRegVSFRCOperands, 1, CVT_Tied, Tie0_1_1, CVT_95_addRegVSFRCOperands, 2, CVT_95_addRegVSFRCOperands, 3, CVT_Done },
  // Convert__RegVSSRC1_0__Tie0_1_1__RegVSSRC1_1__RegVSSRC1_2
  { CVT_95_addRegVSSRCOperands, 1, CVT_Tied, Tie0_1_1, CVT_95_addRegVSSRCOperands, 2, CVT_95_addRegVSSRCOperands, 3, CVT_Done },
  // Convert__RegVRRC1_0__Tie0_1_1__RegVRRC1_1__RegVRRC1_2
  { CVT_95_addRegVRRCOperands, 1, CVT_Tied, Tie0_1_1, CVT_95_addRegVRRCOperands, 2, CVT_95_addRegVRRCOperands, 3, CVT_Done },
  // Convert__RegVSSRC1_0__RegVSSRC1_1
  { CVT_95_addRegVSSRCOperands, 1, CVT_95_addRegVSSRCOperands, 2, CVT_Done },
  // Convert__RegVRRC1_1__U1Imm1_0__RegVRRC1_2__U2Imm1_3
  { CVT_95_addRegVRRCOperands, 2, CVT_95_addImmOperands, 1, CVT_95_addRegVRRCOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegCRRC1_0__RegVSFRC1_1
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegVSFRCOperands, 2, CVT_Done },
  // Convert__RegCRRC1_0__U7Imm1_2__RegVSFRC1_1
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addImmOperands, 3, CVT_95_addRegVSFRCOperands, 2, CVT_Done },
  // Convert__RegCRRC1_0__U7Imm1_2__RegVRRC1_1
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addImmOperands, 3, CVT_95_addRegVRRCOperands, 2, CVT_Done },
  // Convert__RegVSRC1_0__RegVSRC1_1
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_Done },
  // Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 3, CVT_Done },
  // Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3
  { CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 3, CVT_95_addRegVSRCOperands, 4, CVT_Done },
  // Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__RegVSRC1_2
  { CVT_95_addRegVSRCOperands, 1, CVT_Tied, Tie0_1_1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 3, CVT_Done },
  // Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_1
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 2, CVT_Done },
  // Convert__RegCRRC1_0__RegVSRC1_1__RegVSRC1_2
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 3, CVT_Done },
  // Convert__RegCRRC1_0__RegVSRC1_1
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_Done },
  // Convert__RegVSRC1_0__U7Imm1_2__RegVSRC1_1
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addImmOperands, 3, CVT_95_addRegVSRCOperands, 2, CVT_Done },
  // Convert__RegVSFRC1_0__RegVSRC1_1__U4Imm1_2
  { CVT_95_addRegVSFRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__U4Imm1_2
  { CVT_95_addRegVSRCOperands, 1, CVT_Tied, Tie0_1_1, CVT_95_addRegVSRCOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2__imm_95_0
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 3, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2__imm_95_3
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 3, CVT_imm_95_3, 0, CVT_Done },
  // Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2__U2Imm1_3
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 3, CVT_95_addRegVSRCOperands, 4, CVT_Done },
  // Convert__RegVSRC1_0__RegVSFRC1_1__imm_95_0
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSFRCOperands, 2, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegVSRC1_0__RegVSFRC1_1__imm_95_3
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSFRCOperands, 2, CVT_imm_95_3, 0, CVT_Done },
  // Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_1__imm_95_0
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 2, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_1__imm_95_3
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 2, CVT_imm_95_3, 0, CVT_Done },
  // Convert__RegVSRC1_0__U8Imm1_1
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__RegVSRC1_0__RegVSRC1_1__U2Imm1_2
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegVSRC1_0__RegVSFRC1_1__imm_95_2
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSFRCOperands, 2, CVT_imm_95_2, 0, CVT_Done },
  // Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_1__imm_95_2
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 2, CVT_imm_95_2, 0, CVT_Done },
};

void PPCAsmParser::
convertToMCInst(unsigned Kind, MCInst &Inst, unsigned Opcode,
                const OperandVector &Operands) {
  assert(Kind < CVT_NUM_SIGNATURES && "Invalid signature!");
  const uint8_t *Converter = ConversionTable[Kind];
  unsigned OpIdx;
  Inst.setOpcode(Opcode);
  for (const uint8_t *p = Converter; *p; p+= 2) {
    OpIdx = *(p + 1);
    switch (*p) {
    default: llvm_unreachable("invalid conversion entry!");
    case CVT_Reg:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegOperands(Inst, 1);
      break;
    case CVT_Tied: {
      assert(OpIdx < (size_t)(std::end(TiedAsmOperandTable) -
                          std::begin(TiedAsmOperandTable)) &&
             "Tied operand not found");
      unsigned TiedResOpnd = TiedAsmOperandTable[OpIdx][0];
      if (TiedResOpnd != (uint8_t) -1)
        Inst.addOperand(Inst.getOperand(TiedResOpnd));
      break;
    }
    case CVT_95_addRegG8RCOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegG8RCOperands(Inst, 1);
      break;
    case CVT_95_addTLSRegOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addTLSRegOperands(Inst, 1);
      break;
    case CVT_95_addRegGPRCOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegGPRCOperands(Inst, 1);
      break;
    case CVT_95_addRegGPRCNoR0Operands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegGPRCNoR0Operands(Inst, 1);
      break;
    case CVT_95_addS16ImmOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addS16ImmOperands(Inst, 1);
      break;
    case CVT_95_addImmOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addImmOperands(Inst, 1);
      break;
    case CVT_95_addU16ImmOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addU16ImmOperands(Inst, 1);
      break;
    case CVT_95_addBranchTargetOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addBranchTargetOperands(Inst, 1);
      break;
    case CVT_95_addRegCRBITRCOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegCRBITRCOperands(Inst, 1);
      break;
    case CVT_imm_95_3:
      Inst.addOperand(MCOperand::createImm(3));
      break;
    case CVT_imm_95_2:
      Inst.addOperand(MCOperand::createImm(2));
      break;
    case CVT_imm_95_0:
      Inst.addOperand(MCOperand::createImm(0));
      break;
    case CVT_95_addRegVRRCOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegVRRCOperands(Inst, 1);
      break;
    case CVT_imm_95_8:
      Inst.addOperand(MCOperand::createImm(8));
      break;
    case CVT_imm_95_10:
      Inst.addOperand(MCOperand::createImm(10));
      break;
    case CVT_imm_95_76:
      Inst.addOperand(MCOperand::createImm(76));
      break;
    case CVT_regCR0:
      Inst.addOperand(MCOperand::createReg(PPC::CR0));
      break;
    case CVT_95_addRegCRRCOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegCRRCOperands(Inst, 1);
      break;
    case CVT_imm_95_79:
      Inst.addOperand(MCOperand::createImm(79));
      break;
    case CVT_imm_95_78:
      Inst.addOperand(MCOperand::createImm(78));
      break;
    case CVT_imm_95_4:
      Inst.addOperand(MCOperand::createImm(4));
      break;
    case CVT_imm_95_7:
      Inst.addOperand(MCOperand::createImm(7));
      break;
    case CVT_imm_95_6:
      Inst.addOperand(MCOperand::createImm(6));
      break;
    case CVT_imm_95_44:
      Inst.addOperand(MCOperand::createImm(44));
      break;
    case CVT_imm_95_47:
      Inst.addOperand(MCOperand::createImm(47));
      break;
    case CVT_imm_95_46:
      Inst.addOperand(MCOperand::createImm(46));
      break;
    case CVT_imm_95_36:
      Inst.addOperand(MCOperand::createImm(36));
      break;
    case CVT_imm_95_39:
      Inst.addOperand(MCOperand::createImm(39));
      break;
    case CVT_imm_95_38:
      Inst.addOperand(MCOperand::createImm(38));
      break;
    case CVT_imm_95_12:
      Inst.addOperand(MCOperand::createImm(12));
      break;
    case CVT_imm_95_15:
      Inst.addOperand(MCOperand::createImm(15));
      break;
    case CVT_imm_95_14:
      Inst.addOperand(MCOperand::createImm(14));
      break;
    case CVT_imm_95_68:
      Inst.addOperand(MCOperand::createImm(68));
      break;
    case CVT_imm_95_71:
      Inst.addOperand(MCOperand::createImm(71));
      break;
    case CVT_imm_95_70:
      Inst.addOperand(MCOperand::createImm(70));
      break;
    case CVT_imm_95_100:
      Inst.addOperand(MCOperand::createImm(100));
      break;
    case CVT_imm_95_103:
      Inst.addOperand(MCOperand::createImm(103));
      break;
    case CVT_imm_95_102:
      Inst.addOperand(MCOperand::createImm(102));
      break;
    case CVT_imm_95_108:
      Inst.addOperand(MCOperand::createImm(108));
      break;
    case CVT_imm_95_111:
      Inst.addOperand(MCOperand::createImm(111));
      break;
    case CVT_imm_95_110:
      Inst.addOperand(MCOperand::createImm(110));
      break;
    case CVT_imm_95_31:
      Inst.addOperand(MCOperand::createImm(31));
      break;
    case CVT_95_addRegGxRCNoR0Operands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegGxRCNoR0Operands(Inst, 1);
      break;
    case CVT_95_addRegGxRCOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegGxRCOperands(Inst, 1);
      break;
    case CVT_regR0:
      Inst.addOperand(MCOperand::createReg(PPC::R0));
      break;
    case CVT_95_addRegSPERCOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegSPERCOperands(Inst, 1);
      break;
    case CVT_95_addRegSPE4RCOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegSPE4RCOperands(Inst, 1);
      break;
    case CVT_95_addRegF4RCOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegF4RCOperands(Inst, 1);
      break;
    case CVT_95_addRegF8RCOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegF8RCOperands(Inst, 1);
      break;
    case CVT_95_addRegG8RCNoX0Operands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegG8RCNoX0Operands(Inst, 1);
      break;
    case CVT_regCR0EQ:
      Inst.addOperand(MCOperand::createReg(PPC::CR0EQ));
      break;
    case CVT_regCR0GT:
      Inst.addOperand(MCOperand::createReg(PPC::CR0GT));
      break;
    case CVT_regCR0LT:
      Inst.addOperand(MCOperand::createReg(PPC::CR0LT));
      break;
    case CVT_regZERO8:
      Inst.addOperand(MCOperand::createReg(PPC::ZERO8));
      break;
    case CVT_regZERO:
      Inst.addOperand(MCOperand::createReg(PPC::ZERO));
      break;
    case CVT_imm_95_1:
      Inst.addOperand(MCOperand::createImm(1));
      break;
    case CVT_95_addRegVFRCOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegVFRCOperands(Inst, 1);
      break;
    case CVT_95_addRegVSFRCOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegVSFRCOperands(Inst, 1);
      break;
    case CVT_95_addRegVSSRCOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegVSSRCOperands(Inst, 1);
      break;
    case CVT_95_addRegVSRCOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegVSRCOperands(Inst, 1);
      break;
    case CVT_imm_95_29:
      Inst.addOperand(MCOperand::createImm(29));
      break;
    case CVT_imm_95_280:
      Inst.addOperand(MCOperand::createImm(280));
      break;
    case CVT_imm_95_128:
      Inst.addOperand(MCOperand::createImm(128));
      break;
    case CVT_imm_95_129:
      Inst.addOperand(MCOperand::createImm(129));
      break;
    case CVT_imm_95_130:
      Inst.addOperand(MCOperand::createImm(130));
      break;
    case CVT_imm_95_131:
      Inst.addOperand(MCOperand::createImm(131));
      break;
    case CVT_imm_95_132:
      Inst.addOperand(MCOperand::createImm(132));
      break;
    case CVT_imm_95_133:
      Inst.addOperand(MCOperand::createImm(133));
      break;
    case CVT_imm_95_134:
      Inst.addOperand(MCOperand::createImm(134));
      break;
    case CVT_imm_95_135:
      Inst.addOperand(MCOperand::createImm(135));
      break;
    case CVT_imm_95_28:
      Inst.addOperand(MCOperand::createImm(28));
      break;
    case CVT_imm_95_19:
      Inst.addOperand(MCOperand::createImm(19));
      break;
    case CVT_imm_95_537:
      Inst.addOperand(MCOperand::createImm(537));
      break;
    case CVT_imm_95_539:
      Inst.addOperand(MCOperand::createImm(539));
      break;
    case CVT_imm_95_541:
      Inst.addOperand(MCOperand::createImm(541));
      break;
    case CVT_imm_95_543:
      Inst.addOperand(MCOperand::createImm(543));
      break;
    case CVT_imm_95_536:
      Inst.addOperand(MCOperand::createImm(536));
      break;
    case CVT_imm_95_538:
      Inst.addOperand(MCOperand::createImm(538));
      break;
    case CVT_imm_95_540:
      Inst.addOperand(MCOperand::createImm(540));
      break;
    case CVT_imm_95_542:
      Inst.addOperand(MCOperand::createImm(542));
      break;
    case CVT_imm_95_1018:
      Inst.addOperand(MCOperand::createImm(1018));
      break;
    case CVT_imm_95_981:
      Inst.addOperand(MCOperand::createImm(981));
      break;
    case CVT_imm_95_22:
      Inst.addOperand(MCOperand::createImm(22));
      break;
    case CVT_imm_95_17:
      Inst.addOperand(MCOperand::createImm(17));
      break;
    case CVT_imm_95_18:
      Inst.addOperand(MCOperand::createImm(18));
      break;
    case CVT_imm_95_980:
      Inst.addOperand(MCOperand::createImm(980));
      break;
    case CVT_imm_95_529:
      Inst.addOperand(MCOperand::createImm(529));
      break;
    case CVT_imm_95_531:
      Inst.addOperand(MCOperand::createImm(531));
      break;
    case CVT_imm_95_533:
      Inst.addOperand(MCOperand::createImm(533));
      break;
    case CVT_imm_95_535:
      Inst.addOperand(MCOperand::createImm(535));
      break;
    case CVT_imm_95_528:
      Inst.addOperand(MCOperand::createImm(528));
      break;
    case CVT_imm_95_530:
      Inst.addOperand(MCOperand::createImm(530));
      break;
    case CVT_imm_95_532:
      Inst.addOperand(MCOperand::createImm(532));
      break;
    case CVT_imm_95_534:
      Inst.addOperand(MCOperand::createImm(534));
      break;
    case CVT_imm_95_1019:
      Inst.addOperand(MCOperand::createImm(1019));
      break;
    case CVT_95_addCRBitMaskOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addCRBitMaskOperands(Inst, 1);
      break;
    case CVT_imm_95_48:
      Inst.addOperand(MCOperand::createImm(48));
      break;
    case CVT_imm_95_287:
      Inst.addOperand(MCOperand::createImm(287));
      break;
    case CVT_imm_95_5:
      Inst.addOperand(MCOperand::createImm(5));
      break;
    case CVT_imm_95_25:
      Inst.addOperand(MCOperand::createImm(25));
      break;
    case CVT_imm_95_512:
      Inst.addOperand(MCOperand::createImm(512));
      break;
    case CVT_imm_95_272:
      Inst.addOperand(MCOperand::createImm(272));
      break;
    case CVT_imm_95_273:
      Inst.addOperand(MCOperand::createImm(273));
      break;
    case CVT_imm_95_274:
      Inst.addOperand(MCOperand::createImm(274));
      break;
    case CVT_imm_95_275:
      Inst.addOperand(MCOperand::createImm(275));
      break;
    case CVT_imm_95_260:
      Inst.addOperand(MCOperand::createImm(260));
      break;
    case CVT_imm_95_261:
      Inst.addOperand(MCOperand::createImm(261));
      break;
    case CVT_imm_95_262:
      Inst.addOperand(MCOperand::createImm(262));
      break;
    case CVT_imm_95_263:
      Inst.addOperand(MCOperand::createImm(263));
      break;
    case CVT_imm_95_26:
      Inst.addOperand(MCOperand::createImm(26));
      break;
    case CVT_imm_95_27:
      Inst.addOperand(MCOperand::createImm(27));
      break;
    case CVT_imm_95_990:
      Inst.addOperand(MCOperand::createImm(990));
      break;
    case CVT_imm_95_991:
      Inst.addOperand(MCOperand::createImm(991));
      break;
    case CVT_imm_95_268:
      Inst.addOperand(MCOperand::createImm(268));
      break;
    case CVT_imm_95_988:
      Inst.addOperand(MCOperand::createImm(988));
      break;
    case CVT_imm_95_989:
      Inst.addOperand(MCOperand::createImm(989));
      break;
    case CVT_imm_95_269:
      Inst.addOperand(MCOperand::createImm(269));
      break;
    case CVT_imm_95_986:
      Inst.addOperand(MCOperand::createImm(986));
      break;
    case CVT_imm_95_255:
      Inst.addOperand(MCOperand::createImm(255));
      break;
    case CVT_imm_95_284:
      Inst.addOperand(MCOperand::createImm(284));
      break;
    case CVT_imm_95_285:
      Inst.addOperand(MCOperand::createImm(285));
      break;
    case CVT_regX0:
      Inst.addOperand(MCOperand::createReg(PPC::X0));
      break;
    case CVT_95_addRegQFRCOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegQFRCOperands(Inst, 1);
      break;
    case CVT_95_addRegQSRCOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegQSRCOperands(Inst, 1);
      break;
    case CVT_95_addRegQBRCOperands:
      static_cast<PPCOperand&>(*Operands[OpIdx]).addRegQBRCOperands(Inst, 1);
      break;
    case CVT_imm_95_9:
      Inst.addOperand(MCOperand::createImm(9));
      break;
    case CVT_imm_95_13:
      Inst.addOperand(MCOperand::createImm(13));
      break;
    case CVT_imm_95_20:
      Inst.addOperand(MCOperand::createImm(20));
      break;
    case CVT_imm_95_16:
      Inst.addOperand(MCOperand::createImm(16));
      break;
    case CVT_imm_95_24:
      Inst.addOperand(MCOperand::createImm(24));
      break;
    }
  }
}

void PPCAsmParser::
convertToMapAndConstraints(unsigned Kind,
                           const OperandVector &Operands) {
  assert(Kind < CVT_NUM_SIGNATURES && "Invalid signature!");
  unsigned NumMCOperands = 0;
  const uint8_t *Converter = ConversionTable[Kind];
  for (const uint8_t *p = Converter; *p; p+= 2) {
    switch (*p) {
    default: llvm_unreachable("invalid conversion entry!");
    case CVT_Reg:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("r");
      ++NumMCOperands;
      break;
    case CVT_Tied:
      ++NumMCOperands;
      break;
    case CVT_95_addRegG8RCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addTLSRegOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegGPRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegGPRCNoR0Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addS16ImmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addImmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addU16ImmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addBranchTargetOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegCRBITRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_95_3:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_2:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_0:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_95_addRegVRRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_95_8:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_10:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_76:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_regCR0:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_95_addRegCRRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_95_79:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_78:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_4:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_7:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_6:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_44:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_47:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_46:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_36:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_39:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_38:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_12:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_15:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_14:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_68:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_71:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_70:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_100:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_103:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_102:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_108:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_111:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_110:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_31:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_95_addRegGxRCNoR0Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegGxRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_regR0:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_95_addRegSPERCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegSPE4RCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegF4RCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegF8RCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegG8RCNoX0Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_regCR0EQ:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_regCR0GT:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_regCR0LT:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_regZERO8:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_regZERO:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_imm_95_1:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_95_addRegVFRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegVSFRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegVSSRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegVSRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_95_29:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_280:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_128:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_129:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_130:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_131:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_132:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_133:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_134:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_135:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_28:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_19:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_537:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_539:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_541:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_543:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_536:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_538:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_540:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_542:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_1018:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_981:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_22:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_17:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_18:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_980:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_529:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_531:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_533:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_535:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_528:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_530:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_532:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_534:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_1019:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_95_addCRBitMaskOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_95_48:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_287:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_5:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_25:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_512:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_272:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_273:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_274:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_275:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_260:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_261:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_262:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_263:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_26:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_27:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_990:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_991:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_268:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_988:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_989:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_269:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_986:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_255:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_284:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_285:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_regX0:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_95_addRegQFRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegQSRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegQBRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_95_9:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_13:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_20:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_16:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_24:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    }
  }
}

namespace {

/// MatchClassKind - The kinds of classes which participate in
/// instruction matching.
enum MatchClassKind {
  InvalidMatchClass = 0,
  OptionalMatchClass = 1,
  MCK__DOT_, // '.'
  MCK_0, // '0'
  MCK_1, // '1'
  MCK_2, // '2'
  MCK_3, // '3'
  MCK_4, // '4'
  MCK_5, // '5'
  MCK_6, // '6'
  MCK_7, // '7'
  MCK_crD, // 'crD'
  MCK_LAST_TOKEN = MCK_crD,
  MCK_CTRRC, // register class 'CTRRC'
  MCK_CTRRC8, // register class 'CTRRC8'
  MCK_VRSAVERC, // register class 'VRSAVERC'
  MCK_CARRYRC, // register class 'CARRYRC'
  MCK_Reg13, // derived register class
  MCK_Reg8, // derived register class
  MCK_Reg2, // derived register class
  MCK_Reg11, // derived register class
  MCK_Reg5, // derived register class
  MCK_CRRC, // register class 'CRRC'
  MCK_GPRC_VLE_R0_R7, // register class 'GPRC_VLE_R0_R7'
  MCK_Reg27, // derived register class
  MCK_Reg21, // derived register class
  MCK_Reg15, // derived register class
  MCK_Reg23, // derived register class
  MCK_Reg19, // derived register class
  MCK_Reg14, // derived register class
  MCK_CRBITRC, // register class 'CRBITRC'
  MCK_F4RC, // register class 'F4RC,F8RC'
  MCK_QSRC, // register class 'QSRC,QBRC,QFRC'
  MCK_SPERC, // register class 'SPERC'
  MCK_VFRC, // register class 'VFRC'
  MCK_VRRC, // register class 'VRRC'
  MCK_VSLRC, // register class 'VSLRC'
  MCK_Reg10, // derived register class
  MCK_Reg4, // derived register class
  MCK_Reg26, // derived register class
  MCK_Reg18, // derived register class
  MCK_G8RC, // register class 'G8RC'
  MCK_G8RC_NOX0, // register class 'G8RC_NOX0'
  MCK_GPRC, // register class 'GPRC'
  MCK_GPRC_NOR0, // register class 'GPRC_NOR0'
  MCK_VSRC, // register class 'VSRC'
  MCK_VSSRC, // register class 'VSSRC,VSFRC'
  MCK_SPILLTOVSRRC, // register class 'SPILLTOVSRRC'
  MCK_LAST_REGISTER = MCK_SPILLTOVSRRC,
  MCK_Imm, // user defined class 'ImmAsmOperand'
  MCK_ATBitsAsHint, // user defined class 'PPCATBitsAsHintAsmOperand'
  MCK_CRBitMask, // user defined class 'PPCCRBitMaskOperand'
  MCK_CondBr, // user defined class 'PPCCondBrAsmOperand'
  MCK_DirectBr, // user defined class 'PPCDirectBrAsmOperand'
  MCK_DispRI34, // user defined class 'PPCDispRI34Operand'
  MCK_DispRI, // user defined class 'PPCDispRIOperand'
  MCK_DispRIX16, // user defined class 'PPCDispRIX16Operand'
  MCK_DispRIX, // user defined class 'PPCDispRIXOperand'
  MCK_DispSPE2, // user defined class 'PPCDispSPE2Operand'
  MCK_DispSPE4, // user defined class 'PPCDispSPE4Operand'
  MCK_DispSPE8, // user defined class 'PPCDispSPE8Operand'
  MCK_ImmZero, // user defined class 'PPCImmZeroAsmOperand'
  MCK_RegCRBITRC, // user defined class 'PPCRegCRBITRCAsmOperand'
  MCK_RegCRRC, // user defined class 'PPCRegCRRCAsmOperand'
  MCK_RegF4RC, // user defined class 'PPCRegF4RCAsmOperand'
  MCK_RegF8RC, // user defined class 'PPCRegF8RCAsmOperand'
  MCK_RegG8RC, // user defined class 'PPCRegG8RCAsmOperand'
  MCK_RegG8RCNoX0, // user defined class 'PPCRegG8RCNoX0AsmOperand'
  MCK_RegGPRC, // user defined class 'PPCRegGPRCAsmOperand'
  MCK_RegGPRCNoR0, // user defined class 'PPCRegGPRCNoR0AsmOperand'
  MCK_RegGxRCNoR0, // user defined class 'PPCRegGxRCNoR0Operand'
  MCK_RegGxRC, // user defined class 'PPCRegGxRCOperand'
  MCK_RegQBRC, // user defined class 'PPCRegQBRCAsmOperand'
  MCK_RegQFRC, // user defined class 'PPCRegQFRCAsmOperand'
  MCK_RegQSRC, // user defined class 'PPCRegQSRCAsmOperand'
  MCK_RegSPE4RC, // user defined class 'PPCRegSPE4RCAsmOperand'
  MCK_RegSPERC, // user defined class 'PPCRegSPERCAsmOperand'
  MCK_RegSPILLTOVSRRC, // user defined class 'PPCRegSPILLTOVSRRCAsmOperand'
  MCK_RegVFRC, // user defined class 'PPCRegVFRCAsmOperand'
  MCK_RegVRRC, // user defined class 'PPCRegVRRCAsmOperand'
  MCK_RegVSFRC, // user defined class 'PPCRegVSFRCAsmOperand'
  MCK_RegVSRC, // user defined class 'PPCRegVSRCAsmOperand'
  MCK_RegVSSRC, // user defined class 'PPCRegVSSRCAsmOperand'
  MCK_S16Imm, // user defined class 'PPCS16ImmAsmOperand'
  MCK_S17Imm, // user defined class 'PPCS17ImmAsmOperand'
  MCK_S34Imm, // user defined class 'PPCS34ImmAsmOperand'
  MCK_S5Imm, // user defined class 'PPCS5ImmAsmOperand'
  MCK_S6Imm, // user defined class 'PPCS6ImmAsmOperand'
  MCK_TLSReg, // user defined class 'PPCTLSRegOperand'
  MCK_U10Imm, // user defined class 'PPCU10ImmAsmOperand'
  MCK_U12Imm, // user defined class 'PPCU12ImmAsmOperand'
  MCK_U16Imm, // user defined class 'PPCU16ImmAsmOperand'
  MCK_U1Imm, // user defined class 'PPCU1ImmAsmOperand'
  MCK_U2Imm, // user defined class 'PPCU2ImmAsmOperand'
  MCK_U3Imm, // user defined class 'PPCU3ImmAsmOperand'
  MCK_U4Imm, // user defined class 'PPCU4ImmAsmOperand'
  MCK_U5Imm, // user defined class 'PPCU5ImmAsmOperand'
  MCK_U6Imm, // user defined class 'PPCU6ImmAsmOperand'
  MCK_U7Imm, // user defined class 'PPCU7ImmAsmOperand'
  MCK_U8Imm, // user defined class 'PPCU8ImmAsmOperand'
  NumMatchClassKinds
};

} // end anonymous namespace

static unsigned getDiagKindFromRegisterClass(MatchClassKind RegisterClass) {
  return MCTargetAsmParser::Match_InvalidOperand;
}

static MatchClassKind matchTokenString(StringRef Name) {
  switch (Name.size()) {
  default: break;
  case 1:	 // 9 strings to match.
    switch (Name[0]) {
    default: break;
    case '.':	 // 1 string to match.
      return MCK__DOT_;	 // "."
    case '0':	 // 1 string to match.
      return MCK_0;	 // "0"
    case '1':	 // 1 string to match.
      return MCK_1;	 // "1"
    case '2':	 // 1 string to match.
      return MCK_2;	 // "2"
    case '3':	 // 1 string to match.
      return MCK_3;	 // "3"
    case '4':	 // 1 string to match.
      return MCK_4;	 // "4"
    case '5':	 // 1 string to match.
      return MCK_5;	 // "5"
    case '6':	 // 1 string to match.
      return MCK_6;	 // "6"
    case '7':	 // 1 string to match.
      return MCK_7;	 // "7"
    }
    break;
  case 3:	 // 1 string to match.
    if (memcmp(Name.data()+0, "crD", 3) != 0)
      break;
    return MCK_crD;	 // "crD"
  }
  return InvalidMatchClass;
}

/// isSubclass - Compute whether \p A is a subclass of \p B.
static bool isSubclass(MatchClassKind A, MatchClassKind B) {
  if (A == B)
    return true;

  switch (A) {
  default:
    return false;

  case MCK_Reg13:
    switch (B) {
    default: return false;
    case MCK_Reg11: return true;
    case MCK_Reg14: return true;
    case MCK_SPERC: return true;
    }

  case MCK_Reg8:
    switch (B) {
    default: return false;
    case MCK_Reg5: return true;
    case MCK_Reg10: return true;
    case MCK_G8RC: return true;
    case MCK_G8RC_NOX0: return true;
    case MCK_SPILLTOVSRRC: return true;
    }

  case MCK_Reg2:
    switch (B) {
    default: return false;
    case MCK_GPRC_VLE_R0_R7: return true;
    case MCK_Reg4: return true;
    case MCK_GPRC: return true;
    case MCK_GPRC_NOR0: return true;
    }

  case MCK_Reg11:
    return B == MCK_SPERC;

  case MCK_Reg5:
    switch (B) {
    default: return false;
    case MCK_G8RC: return true;
    case MCK_SPILLTOVSRRC: return true;
    }

  case MCK_GPRC_VLE_R0_R7:
    return B == MCK_GPRC;

  case MCK_Reg27:
    switch (B) {
    default: return false;
    case MCK_VSLRC: return true;
    case MCK_Reg26: return true;
    case MCK_VSRC: return true;
    }

  case MCK_Reg21:
    return B == MCK_QSRC;

  case MCK_Reg15:
    switch (B) {
    default: return false;
    case MCK_F4RC: return true;
    case MCK_Reg18: return true;
    case MCK_VSSRC: return true;
    case MCK_SPILLTOVSRRC: return true;
    }

  case MCK_Reg23:
    switch (B) {
    default: return false;
    case MCK_VRRC: return true;
    case MCK_Reg26: return true;
    case MCK_VSRC: return true;
    }

  case MCK_Reg19:
    switch (B) {
    default: return false;
    case MCK_VFRC: return true;
    case MCK_Reg18: return true;
    case MCK_VSSRC: return true;
    case MCK_SPILLTOVSRRC: return true;
    }

  case MCK_Reg14:
    return B == MCK_SPERC;

  case MCK_F4RC:
    return B == MCK_VSSRC;

  case MCK_VFRC:
    return B == MCK_VSSRC;

  case MCK_VRRC:
    return B == MCK_VSRC;

  case MCK_VSLRC:
    return B == MCK_VSRC;

  case MCK_Reg10:
    switch (B) {
    default: return false;
    case MCK_G8RC: return true;
    case MCK_G8RC_NOX0: return true;
    case MCK_SPILLTOVSRRC: return true;
    }

  case MCK_Reg4:
    switch (B) {
    default: return false;
    case MCK_GPRC: return true;
    case MCK_GPRC_NOR0: return true;
    }

  case MCK_Reg26:
    return B == MCK_VSRC;

  case MCK_Reg18:
    switch (B) {
    default: return false;
    case MCK_VSSRC: return true;
    case MCK_SPILLTOVSRRC: return true;
    }

  case MCK_G8RC:
    return B == MCK_SPILLTOVSRRC;
  }
}

static unsigned validateOperandClass(MCParsedAsmOperand &GOp, MatchClassKind Kind) {
  PPCOperand &Operand = (PPCOperand&)GOp;
  if (Kind == InvalidMatchClass)
    return MCTargetAsmParser::Match_InvalidOperand;

  if (Operand.isToken() && Kind <= MCK_LAST_TOKEN)
    return isSubclass(matchTokenString(Operand.getToken()), Kind) ?
             MCTargetAsmParser::Match_Success :
             MCTargetAsmParser::Match_InvalidOperand;

  switch (Kind) {
  default: break;
  // 'Imm' class
  case MCK_Imm: {
    DiagnosticPredicate DP(Operand.isImm());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'ATBitsAsHint' class
  case MCK_ATBitsAsHint: {
    DiagnosticPredicate DP(Operand.isATBitsAsHint());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'CRBitMask' class
  case MCK_CRBitMask: {
    DiagnosticPredicate DP(Operand.isCRBitMask());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'CondBr' class
  case MCK_CondBr: {
    DiagnosticPredicate DP(Operand.isCondBr());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'DirectBr' class
  case MCK_DirectBr: {
    DiagnosticPredicate DP(Operand.isDirectBr());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'DispRI34' class
  case MCK_DispRI34: {
    DiagnosticPredicate DP(Operand.isS34Imm());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'DispRI' class
  case MCK_DispRI: {
    DiagnosticPredicate DP(Operand.isS16Imm());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'DispRIX16' class
  case MCK_DispRIX16: {
    DiagnosticPredicate DP(Operand.isS16ImmX16());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'DispRIX' class
  case MCK_DispRIX: {
    DiagnosticPredicate DP(Operand.isS16ImmX4());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'DispSPE2' class
  case MCK_DispSPE2: {
    DiagnosticPredicate DP(Operand.isU6ImmX2());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'DispSPE4' class
  case MCK_DispSPE4: {
    DiagnosticPredicate DP(Operand.isU7ImmX4());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'DispSPE8' class
  case MCK_DispSPE8: {
    DiagnosticPredicate DP(Operand.isU8ImmX8());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'ImmZero' class
  case MCK_ImmZero: {
    DiagnosticPredicate DP(Operand.isImmZero());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegCRBITRC' class
  case MCK_RegCRBITRC: {
    DiagnosticPredicate DP(Operand.isCRBitNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegCRRC' class
  case MCK_RegCRRC: {
    DiagnosticPredicate DP(Operand.isCCRegNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegF4RC' class
  case MCK_RegF4RC: {
    DiagnosticPredicate DP(Operand.isRegNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegF8RC' class
  case MCK_RegF8RC: {
    DiagnosticPredicate DP(Operand.isRegNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegG8RC' class
  case MCK_RegG8RC: {
    DiagnosticPredicate DP(Operand.isRegNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegG8RCNoX0' class
  case MCK_RegG8RCNoX0: {
    DiagnosticPredicate DP(Operand.isRegNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegGPRC' class
  case MCK_RegGPRC: {
    DiagnosticPredicate DP(Operand.isRegNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegGPRCNoR0' class
  case MCK_RegGPRCNoR0: {
    DiagnosticPredicate DP(Operand.isRegNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegGxRCNoR0' class
  case MCK_RegGxRCNoR0: {
    DiagnosticPredicate DP(Operand.isRegNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegGxRC' class
  case MCK_RegGxRC: {
    DiagnosticPredicate DP(Operand.isRegNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegQBRC' class
  case MCK_RegQBRC: {
    DiagnosticPredicate DP(Operand.isRegNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegQFRC' class
  case MCK_RegQFRC: {
    DiagnosticPredicate DP(Operand.isRegNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegQSRC' class
  case MCK_RegQSRC: {
    DiagnosticPredicate DP(Operand.isRegNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegSPE4RC' class
  case MCK_RegSPE4RC: {
    DiagnosticPredicate DP(Operand.isRegNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegSPERC' class
  case MCK_RegSPERC: {
    DiagnosticPredicate DP(Operand.isRegNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegSPILLTOVSRRC' class
  case MCK_RegSPILLTOVSRRC: {
    DiagnosticPredicate DP(Operand.isVSRegNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegVFRC' class
  case MCK_RegVFRC: {
    DiagnosticPredicate DP(Operand.isRegNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegVRRC' class
  case MCK_RegVRRC: {
    DiagnosticPredicate DP(Operand.isRegNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegVSFRC' class
  case MCK_RegVSFRC: {
    DiagnosticPredicate DP(Operand.isVSRegNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegVSRC' class
  case MCK_RegVSRC: {
    DiagnosticPredicate DP(Operand.isVSRegNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'RegVSSRC' class
  case MCK_RegVSSRC: {
    DiagnosticPredicate DP(Operand.isVSRegNumber());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'S16Imm' class
  case MCK_S16Imm: {
    DiagnosticPredicate DP(Operand.isS16Imm());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'S17Imm' class
  case MCK_S17Imm: {
    DiagnosticPredicate DP(Operand.isS17Imm());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'S34Imm' class
  case MCK_S34Imm: {
    DiagnosticPredicate DP(Operand.isS34Imm());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'S5Imm' class
  case MCK_S5Imm: {
    DiagnosticPredicate DP(Operand.isS5Imm());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'S6Imm' class
  case MCK_S6Imm: {
    DiagnosticPredicate DP(Operand.isS6Imm());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'TLSReg' class
  case MCK_TLSReg: {
    DiagnosticPredicate DP(Operand.isTLSReg());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'U10Imm' class
  case MCK_U10Imm: {
    DiagnosticPredicate DP(Operand.isU10Imm());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'U12Imm' class
  case MCK_U12Imm: {
    DiagnosticPredicate DP(Operand.isU12Imm());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'U16Imm' class
  case MCK_U16Imm: {
    DiagnosticPredicate DP(Operand.isU16Imm());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'U1Imm' class
  case MCK_U1Imm: {
    DiagnosticPredicate DP(Operand.isU1Imm());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'U2Imm' class
  case MCK_U2Imm: {
    DiagnosticPredicate DP(Operand.isU2Imm());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'U3Imm' class
  case MCK_U3Imm: {
    DiagnosticPredicate DP(Operand.isU3Imm());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'U4Imm' class
  case MCK_U4Imm: {
    DiagnosticPredicate DP(Operand.isU4Imm());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'U5Imm' class
  case MCK_U5Imm: {
    DiagnosticPredicate DP(Operand.isU5Imm());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'U6Imm' class
  case MCK_U6Imm: {
    DiagnosticPredicate DP(Operand.isU6Imm());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'U7Imm' class
  case MCK_U7Imm: {
    DiagnosticPredicate DP(Operand.isU7Imm());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  // 'U8Imm' class
  case MCK_U8Imm: {
    DiagnosticPredicate DP(Operand.isU8Imm());
    if (DP.isMatch())
      return MCTargetAsmParser::Match_Success;
    break;
    }
  } // end switch (Kind)

  if (Operand.isReg()) {
    MatchClassKind OpKind;
    switch (Operand.getReg()) {
    default: OpKind = InvalidMatchClass; break;
    case PPC::R0: OpKind = MCK_GPRC_VLE_R0_R7; break;
    case PPC::R1: OpKind = MCK_Reg2; break;
    case PPC::R2: OpKind = MCK_Reg2; break;
    case PPC::R3: OpKind = MCK_Reg2; break;
    case PPC::R4: OpKind = MCK_Reg2; break;
    case PPC::R5: OpKind = MCK_Reg2; break;
    case PPC::R6: OpKind = MCK_Reg2; break;
    case PPC::R7: OpKind = MCK_Reg2; break;
    case PPC::R8: OpKind = MCK_Reg4; break;
    case PPC::R9: OpKind = MCK_Reg4; break;
    case PPC::R10: OpKind = MCK_Reg4; break;
    case PPC::R11: OpKind = MCK_Reg4; break;
    case PPC::R12: OpKind = MCK_Reg4; break;
    case PPC::R13: OpKind = MCK_Reg4; break;
    case PPC::R14: OpKind = MCK_Reg4; break;
    case PPC::R15: OpKind = MCK_Reg4; break;
    case PPC::R16: OpKind = MCK_Reg4; break;
    case PPC::R17: OpKind = MCK_Reg4; break;
    case PPC::R18: OpKind = MCK_Reg4; break;
    case PPC::R19: OpKind = MCK_Reg4; break;
    case PPC::R20: OpKind = MCK_Reg4; break;
    case PPC::R21: OpKind = MCK_Reg4; break;
    case PPC::R22: OpKind = MCK_Reg4; break;
    case PPC::R23: OpKind = MCK_Reg4; break;
    case PPC::R24: OpKind = MCK_Reg4; break;
    case PPC::R25: OpKind = MCK_Reg4; break;
    case PPC::R26: OpKind = MCK_Reg4; break;
    case PPC::R27: OpKind = MCK_Reg4; break;
    case PPC::R28: OpKind = MCK_Reg4; break;
    case PPC::R29: OpKind = MCK_Reg4; break;
    case PPC::R30: OpKind = MCK_Reg4; break;
    case PPC::R31: OpKind = MCK_Reg4; break;
    case PPC::X0: OpKind = MCK_Reg5; break;
    case PPC::X1: OpKind = MCK_Reg8; break;
    case PPC::X2: OpKind = MCK_Reg8; break;
    case PPC::X3: OpKind = MCK_Reg8; break;
    case PPC::X4: OpKind = MCK_Reg8; break;
    case PPC::X5: OpKind = MCK_Reg8; break;
    case PPC::X6: OpKind = MCK_Reg8; break;
    case PPC::X7: OpKind = MCK_Reg8; break;
    case PPC::X8: OpKind = MCK_Reg10; break;
    case PPC::X9: OpKind = MCK_Reg10; break;
    case PPC::X10: OpKind = MCK_Reg10; break;
    case PPC::X11: OpKind = MCK_Reg10; break;
    case PPC::X12: OpKind = MCK_Reg10; break;
    case PPC::X13: OpKind = MCK_Reg10; break;
    case PPC::X14: OpKind = MCK_Reg10; break;
    case PPC::X15: OpKind = MCK_Reg10; break;
    case PPC::X16: OpKind = MCK_Reg10; break;
    case PPC::X17: OpKind = MCK_Reg10; break;
    case PPC::X18: OpKind = MCK_Reg10; break;
    case PPC::X19: OpKind = MCK_Reg10; break;
    case PPC::X20: OpKind = MCK_Reg10; break;
    case PPC::X21: OpKind = MCK_Reg10; break;
    case PPC::X22: OpKind = MCK_Reg10; break;
    case PPC::X23: OpKind = MCK_Reg10; break;
    case PPC::X24: OpKind = MCK_Reg10; break;
    case PPC::X25: OpKind = MCK_Reg10; break;
    case PPC::X26: OpKind = MCK_Reg10; break;
    case PPC::X27: OpKind = MCK_Reg10; break;
    case PPC::X28: OpKind = MCK_Reg10; break;
    case PPC::X29: OpKind = MCK_Reg10; break;
    case PPC::X30: OpKind = MCK_Reg10; break;
    case PPC::X31: OpKind = MCK_Reg10; break;
    case PPC::S0: OpKind = MCK_Reg11; break;
    case PPC::S1: OpKind = MCK_Reg13; break;
    case PPC::S2: OpKind = MCK_Reg13; break;
    case PPC::S3: OpKind = MCK_Reg13; break;
    case PPC::S4: OpKind = MCK_Reg13; break;
    case PPC::S5: OpKind = MCK_Reg13; break;
    case PPC::S6: OpKind = MCK_Reg13; break;
    case PPC::S7: OpKind = MCK_Reg13; break;
    case PPC::S8: OpKind = MCK_Reg14; break;
    case PPC::S9: OpKind = MCK_Reg14; break;
    case PPC::S10: OpKind = MCK_Reg14; break;
    case PPC::S11: OpKind = MCK_Reg14; break;
    case PPC::S12: OpKind = MCK_Reg14; break;
    case PPC::S13: OpKind = MCK_Reg14; break;
    case PPC::S14: OpKind = MCK_Reg14; break;
    case PPC::S15: OpKind = MCK_Reg14; break;
    case PPC::S16: OpKind = MCK_Reg14; break;
    case PPC::S17: OpKind = MCK_Reg14; break;
    case PPC::S18: OpKind = MCK_Reg14; break;
    case PPC::S19: OpKind = MCK_Reg14; break;
    case PPC::S20: OpKind = MCK_Reg14; break;
    case PPC::S21: OpKind = MCK_Reg14; break;
    case PPC::S22: OpKind = MCK_Reg14; break;
    case PPC::S23: OpKind = MCK_Reg14; break;
    case PPC::S24: OpKind = MCK_Reg14; break;
    case PPC::S25: OpKind = MCK_Reg14; break;
    case PPC::S26: OpKind = MCK_Reg14; break;
    case PPC::S27: OpKind = MCK_Reg14; break;
    case PPC::S28: OpKind = MCK_Reg14; break;
    case PPC::S29: OpKind = MCK_Reg14; break;
    case PPC::S30: OpKind = MCK_Reg14; break;
    case PPC::S31: OpKind = MCK_Reg14; break;
    case PPC::F0: OpKind = MCK_Reg15; break;
    case PPC::F1: OpKind = MCK_Reg15; break;
    case PPC::F2: OpKind = MCK_Reg15; break;
    case PPC::F3: OpKind = MCK_Reg15; break;
    case PPC::F4: OpKind = MCK_Reg15; break;
    case PPC::F5: OpKind = MCK_Reg15; break;
    case PPC::F6: OpKind = MCK_Reg15; break;
    case PPC::F7: OpKind = MCK_Reg15; break;
    case PPC::F8: OpKind = MCK_Reg15; break;
    case PPC::F9: OpKind = MCK_Reg15; break;
    case PPC::F10: OpKind = MCK_Reg15; break;
    case PPC::F11: OpKind = MCK_Reg15; break;
    case PPC::F12: OpKind = MCK_Reg15; break;
    case PPC::F13: OpKind = MCK_Reg15; break;
    case PPC::F14: OpKind = MCK_F4RC; break;
    case PPC::F15: OpKind = MCK_F4RC; break;
    case PPC::F16: OpKind = MCK_F4RC; break;
    case PPC::F17: OpKind = MCK_F4RC; break;
    case PPC::F18: OpKind = MCK_F4RC; break;
    case PPC::F19: OpKind = MCK_F4RC; break;
    case PPC::F20: OpKind = MCK_F4RC; break;
    case PPC::F21: OpKind = MCK_F4RC; break;
    case PPC::F22: OpKind = MCK_F4RC; break;
    case PPC::F23: OpKind = MCK_F4RC; break;
    case PPC::F24: OpKind = MCK_F4RC; break;
    case PPC::F25: OpKind = MCK_F4RC; break;
    case PPC::F26: OpKind = MCK_F4RC; break;
    case PPC::F27: OpKind = MCK_F4RC; break;
    case PPC::F28: OpKind = MCK_F4RC; break;
    case PPC::F29: OpKind = MCK_F4RC; break;
    case PPC::F30: OpKind = MCK_F4RC; break;
    case PPC::F31: OpKind = MCK_F4RC; break;
    case PPC::VF0: OpKind = MCK_Reg19; break;
    case PPC::VF1: OpKind = MCK_Reg19; break;
    case PPC::VF2: OpKind = MCK_Reg19; break;
    case PPC::VF3: OpKind = MCK_Reg19; break;
    case PPC::VF4: OpKind = MCK_Reg19; break;
    case PPC::VF5: OpKind = MCK_Reg19; break;
    case PPC::VF6: OpKind = MCK_Reg19; break;
    case PPC::VF7: OpKind = MCK_Reg19; break;
    case PPC::VF8: OpKind = MCK_Reg19; break;
    case PPC::VF9: OpKind = MCK_Reg19; break;
    case PPC::VF10: OpKind = MCK_Reg19; break;
    case PPC::VF11: OpKind = MCK_Reg19; break;
    case PPC::VF12: OpKind = MCK_Reg19; break;
    case PPC::VF13: OpKind = MCK_Reg19; break;
    case PPC::VF14: OpKind = MCK_Reg19; break;
    case PPC::VF15: OpKind = MCK_Reg19; break;
    case PPC::VF16: OpKind = MCK_Reg19; break;
    case PPC::VF17: OpKind = MCK_Reg19; break;
    case PPC::VF18: OpKind = MCK_Reg19; break;
    case PPC::VF19: OpKind = MCK_Reg19; break;
    case PPC::VF20: OpKind = MCK_VFRC; break;
    case PPC::VF21: OpKind = MCK_VFRC; break;
    case PPC::VF22: OpKind = MCK_VFRC; break;
    case PPC::VF23: OpKind = MCK_VFRC; break;
    case PPC::VF24: OpKind = MCK_VFRC; break;
    case PPC::VF25: OpKind = MCK_VFRC; break;
    case PPC::VF26: OpKind = MCK_VFRC; break;
    case PPC::VF27: OpKind = MCK_VFRC; break;
    case PPC::VF28: OpKind = MCK_VFRC; break;
    case PPC::VF29: OpKind = MCK_VFRC; break;
    case PPC::VF30: OpKind = MCK_VFRC; break;
    case PPC::VF31: OpKind = MCK_VFRC; break;
    case PPC::QF0: OpKind = MCK_Reg21; break;
    case PPC::QF1: OpKind = MCK_Reg21; break;
    case PPC::QF2: OpKind = MCK_Reg21; break;
    case PPC::QF3: OpKind = MCK_Reg21; break;
    case PPC::QF4: OpKind = MCK_Reg21; break;
    case PPC::QF5: OpKind = MCK_Reg21; break;
    case PPC::QF6: OpKind = MCK_Reg21; break;
    case PPC::QF7: OpKind = MCK_Reg21; break;
    case PPC::QF8: OpKind = MCK_Reg21; break;
    case PPC::QF9: OpKind = MCK_Reg21; break;
    case PPC::QF10: OpKind = MCK_Reg21; break;
    case PPC::QF11: OpKind = MCK_Reg21; break;
    case PPC::QF12: OpKind = MCK_Reg21; break;
    case PPC::QF13: OpKind = MCK_Reg21; break;
    case PPC::QF14: OpKind = MCK_QSRC; break;
    case PPC::QF15: OpKind = MCK_QSRC; break;
    case PPC::QF16: OpKind = MCK_QSRC; break;
    case PPC::QF17: OpKind = MCK_QSRC; break;
    case PPC::QF18: OpKind = MCK_QSRC; break;
    case PPC::QF19: OpKind = MCK_QSRC; break;
    case PPC::QF20: OpKind = MCK_QSRC; break;
    case PPC::QF21: OpKind = MCK_QSRC; break;
    case PPC::QF22: OpKind = MCK_QSRC; break;
    case PPC::QF23: OpKind = MCK_QSRC; break;
    case PPC::QF24: OpKind = MCK_QSRC; break;
    case PPC::QF25: OpKind = MCK_QSRC; break;
    case PPC::QF26: OpKind = MCK_QSRC; break;
    case PPC::QF27: OpKind = MCK_QSRC; break;
    case PPC::QF28: OpKind = MCK_QSRC; break;
    case PPC::QF29: OpKind = MCK_QSRC; break;
    case PPC::QF30: OpKind = MCK_QSRC; break;
    case PPC::QF31: OpKind = MCK_QSRC; break;
    case PPC::V0: OpKind = MCK_Reg23; break;
    case PPC::V1: OpKind = MCK_Reg23; break;
    case PPC::V2: OpKind = MCK_Reg23; break;
    case PPC::V3: OpKind = MCK_Reg23; break;
    case PPC::V4: OpKind = MCK_Reg23; break;
    case PPC::V5: OpKind = MCK_Reg23; break;
    case PPC::V6: OpKind = MCK_Reg23; break;
    case PPC::V7: OpKind = MCK_Reg23; break;
    case PPC::V8: OpKind = MCK_Reg23; break;
    case PPC::V9: OpKind = MCK_Reg23; break;
    case PPC::V10: OpKind = MCK_Reg23; break;
    case PPC::V11: OpKind = MCK_Reg23; break;
    case PPC::V12: OpKind = MCK_Reg23; break;
    case PPC::V13: OpKind = MCK_Reg23; break;
    case PPC::V14: OpKind = MCK_Reg23; break;
    case PPC::V15: OpKind = MCK_Reg23; break;
    case PPC::V16: OpKind = MCK_Reg23; break;
    case PPC::V17: OpKind = MCK_Reg23; break;
    case PPC::V18: OpKind = MCK_Reg23; break;
    case PPC::V19: OpKind = MCK_Reg23; break;
    case PPC::V20: OpKind = MCK_VRRC; break;
    case PPC::V21: OpKind = MCK_VRRC; break;
    case PPC::V22: OpKind = MCK_VRRC; break;
    case PPC::V23: OpKind = MCK_VRRC; break;
    case PPC::V24: OpKind = MCK_VRRC; break;
    case PPC::V25: OpKind = MCK_VRRC; break;
    case PPC::V26: OpKind = MCK_VRRC; break;
    case PPC::V27: OpKind = MCK_VRRC; break;
    case PPC::V28: OpKind = MCK_VRRC; break;
    case PPC::V29: OpKind = MCK_VRRC; break;
    case PPC::V30: OpKind = MCK_VRRC; break;
    case PPC::V31: OpKind = MCK_VRRC; break;
    case PPC::VSL0: OpKind = MCK_Reg27; break;
    case PPC::VSL1: OpKind = MCK_Reg27; break;
    case PPC::VSL2: OpKind = MCK_Reg27; break;
    case PPC::VSL3: OpKind = MCK_Reg27; break;
    case PPC::VSL4: OpKind = MCK_Reg27; break;
    case PPC::VSL5: OpKind = MCK_Reg27; break;
    case PPC::VSL6: OpKind = MCK_Reg27; break;
    case PPC::VSL7: OpKind = MCK_Reg27; break;
    case PPC::VSL8: OpKind = MCK_Reg27; break;
    case PPC::VSL9: OpKind = MCK_Reg27; break;
    case PPC::VSL10: OpKind = MCK_Reg27; break;
    case PPC::VSL11: OpKind = MCK_Reg27; break;
    case PPC::VSL12: OpKind = MCK_Reg27; break;
    case PPC::VSL13: OpKind = MCK_Reg27; break;
    case PPC::VSL14: OpKind = MCK_VSLRC; break;
    case PPC::VSL15: OpKind = MCK_VSLRC; break;
    case PPC::VSL16: OpKind = MCK_VSLRC; break;
    case PPC::VSL17: OpKind = MCK_VSLRC; break;
    case PPC::VSL18: OpKind = MCK_VSLRC; break;
    case PPC::VSL19: OpKind = MCK_VSLRC; break;
    case PPC::VSL20: OpKind = MCK_VSLRC; break;
    case PPC::VSL21: OpKind = MCK_VSLRC; break;
    case PPC::VSL22: OpKind = MCK_VSLRC; break;
    case PPC::VSL23: OpKind = MCK_VSLRC; break;
    case PPC::VSL24: OpKind = MCK_VSLRC; break;
    case PPC::VSL25: OpKind = MCK_VSLRC; break;
    case PPC::VSL26: OpKind = MCK_VSLRC; break;
    case PPC::VSL27: OpKind = MCK_VSLRC; break;
    case PPC::VSL28: OpKind = MCK_VSLRC; break;
    case PPC::VSL29: OpKind = MCK_VSLRC; break;
    case PPC::VSL30: OpKind = MCK_VSLRC; break;
    case PPC::VSL31: OpKind = MCK_VSLRC; break;
    case PPC::ZERO: OpKind = MCK_GPRC_NOR0; break;
    case PPC::ZERO8: OpKind = MCK_G8RC_NOX0; break;
    case PPC::FP: OpKind = MCK_Reg4; break;
    case PPC::FP8: OpKind = MCK_Reg10; break;
    case PPC::BP: OpKind = MCK_Reg4; break;
    case PPC::BP8: OpKind = MCK_Reg10; break;
    case PPC::CR0LT: OpKind = MCK_CRBITRC; break;
    case PPC::CR0GT: OpKind = MCK_CRBITRC; break;
    case PPC::CR0EQ: OpKind = MCK_CRBITRC; break;
    case PPC::CR0UN: OpKind = MCK_CRBITRC; break;
    case PPC::CR1LT: OpKind = MCK_CRBITRC; break;
    case PPC::CR1GT: OpKind = MCK_CRBITRC; break;
    case PPC::CR1EQ: OpKind = MCK_CRBITRC; break;
    case PPC::CR1UN: OpKind = MCK_CRBITRC; break;
    case PPC::CR2LT: OpKind = MCK_CRBITRC; break;
    case PPC::CR2GT: OpKind = MCK_CRBITRC; break;
    case PPC::CR2EQ: OpKind = MCK_CRBITRC; break;
    case PPC::CR2UN: OpKind = MCK_CRBITRC; break;
    case PPC::CR3LT: OpKind = MCK_CRBITRC; break;
    case PPC::CR3GT: OpKind = MCK_CRBITRC; break;
    case PPC::CR3EQ: OpKind = MCK_CRBITRC; break;
    case PPC::CR3UN: OpKind = MCK_CRBITRC; break;
    case PPC::CR4LT: OpKind = MCK_CRBITRC; break;
    case PPC::CR4GT: OpKind = MCK_CRBITRC; break;
    case PPC::CR4EQ: OpKind = MCK_CRBITRC; break;
    case PPC::CR4UN: OpKind = MCK_CRBITRC; break;
    case PPC::CR5LT: OpKind = MCK_CRBITRC; break;
    case PPC::CR5GT: OpKind = MCK_CRBITRC; break;
    case PPC::CR5EQ: OpKind = MCK_CRBITRC; break;
    case PPC::CR5UN: OpKind = MCK_CRBITRC; break;
    case PPC::CR6LT: OpKind = MCK_CRBITRC; break;
    case PPC::CR6GT: OpKind = MCK_CRBITRC; break;
    case PPC::CR6EQ: OpKind = MCK_CRBITRC; break;
    case PPC::CR6UN: OpKind = MCK_CRBITRC; break;
    case PPC::CR7LT: OpKind = MCK_CRBITRC; break;
    case PPC::CR7GT: OpKind = MCK_CRBITRC; break;
    case PPC::CR7EQ: OpKind = MCK_CRBITRC; break;
    case PPC::CR7UN: OpKind = MCK_CRBITRC; break;
    case PPC::CR0: OpKind = MCK_CRRC; break;
    case PPC::CR1: OpKind = MCK_CRRC; break;
    case PPC::CR2: OpKind = MCK_CRRC; break;
    case PPC::CR3: OpKind = MCK_CRRC; break;
    case PPC::CR4: OpKind = MCK_CRRC; break;
    case PPC::CR5: OpKind = MCK_CRRC; break;
    case PPC::CR6: OpKind = MCK_CRRC; break;
    case PPC::CR7: OpKind = MCK_CRRC; break;
    case PPC::CTR: OpKind = MCK_CTRRC; break;
    case PPC::CTR8: OpKind = MCK_CTRRC8; break;
    case PPC::VRSAVE: OpKind = MCK_VRSAVERC; break;
    case PPC::XER: OpKind = MCK_CARRYRC; break;
    case PPC::CARRY: OpKind = MCK_CARRYRC; break;
    }
    return isSubclass(OpKind, Kind) ? (unsigned)MCTargetAsmParser::Match_Success :
                                      getDiagKindFromRegisterClass(Kind);
  }

  if (Kind > MCK_LAST_TOKEN && Kind <= MCK_LAST_REGISTER)
    return getDiagKindFromRegisterClass(Kind);

  return MCTargetAsmParser::Match_InvalidOperand;
}

#ifndef NDEBUG
const char *getMatchClassName(MatchClassKind Kind) {
  switch (Kind) {
  case InvalidMatchClass: return "InvalidMatchClass";
  case OptionalMatchClass: return "OptionalMatchClass";
  case MCK__DOT_: return "MCK__DOT_";
  case MCK_0: return "MCK_0";
  case MCK_1: return "MCK_1";
  case MCK_2: return "MCK_2";
  case MCK_3: return "MCK_3";
  case MCK_4: return "MCK_4";
  case MCK_5: return "MCK_5";
  case MCK_6: return "MCK_6";
  case MCK_7: return "MCK_7";
  case MCK_crD: return "MCK_crD";
  case MCK_CTRRC: return "MCK_CTRRC";
  case MCK_CTRRC8: return "MCK_CTRRC8";
  case MCK_VRSAVERC: return "MCK_VRSAVERC";
  case MCK_CARRYRC: return "MCK_CARRYRC";
  case MCK_Reg13: return "MCK_Reg13";
  case MCK_Reg8: return "MCK_Reg8";
  case MCK_Reg2: return "MCK_Reg2";
  case MCK_Reg11: return "MCK_Reg11";
  case MCK_Reg5: return "MCK_Reg5";
  case MCK_CRRC: return "MCK_CRRC";
  case MCK_GPRC_VLE_R0_R7: return "MCK_GPRC_VLE_R0_R7";
  case MCK_Reg27: return "MCK_Reg27";
  case MCK_Reg21: return "MCK_Reg21";
  case MCK_Reg15: return "MCK_Reg15";
  case MCK_Reg23: return "MCK_Reg23";
  case MCK_Reg19: return "MCK_Reg19";
  case MCK_Reg14: return "MCK_Reg14";
  case MCK_CRBITRC: return "MCK_CRBITRC";
  case MCK_F4RC: return "MCK_F4RC";
  case MCK_QSRC: return "MCK_QSRC";
  case MCK_SPERC: return "MCK_SPERC";
  case MCK_VFRC: return "MCK_VFRC";
  case MCK_VRRC: return "MCK_VRRC";
  case MCK_VSLRC: return "MCK_VSLRC";
  case MCK_Reg10: return "MCK_Reg10";
  case MCK_Reg4: return "MCK_Reg4";
  case MCK_Reg26: return "MCK_Reg26";
  case MCK_Reg18: return "MCK_Reg18";
  case MCK_G8RC: return "MCK_G8RC";
  case MCK_G8RC_NOX0: return "MCK_G8RC_NOX0";
  case MCK_GPRC: return "MCK_GPRC";
  case MCK_GPRC_NOR0: return "MCK_GPRC_NOR0";
  case MCK_VSRC: return "MCK_VSRC";
  case MCK_VSSRC: return "MCK_VSSRC";
  case MCK_SPILLTOVSRRC: return "MCK_SPILLTOVSRRC";
  case MCK_Imm: return "MCK_Imm";
  case MCK_ATBitsAsHint: return "MCK_ATBitsAsHint";
  case MCK_CRBitMask: return "MCK_CRBitMask";
  case MCK_CondBr: return "MCK_CondBr";
  case MCK_DirectBr: return "MCK_DirectBr";
  case MCK_DispRI34: return "MCK_DispRI34";
  case MCK_DispRI: return "MCK_DispRI";
  case MCK_DispRIX16: return "MCK_DispRIX16";
  case MCK_DispRIX: return "MCK_DispRIX";
  case MCK_DispSPE2: return "MCK_DispSPE2";
  case MCK_DispSPE4: return "MCK_DispSPE4";
  case MCK_DispSPE8: return "MCK_DispSPE8";
  case MCK_ImmZero: return "MCK_ImmZero";
  case MCK_RegCRBITRC: return "MCK_RegCRBITRC";
  case MCK_RegCRRC: return "MCK_RegCRRC";
  case MCK_RegF4RC: return "MCK_RegF4RC";
  case MCK_RegF8RC: return "MCK_RegF8RC";
  case MCK_RegG8RC: return "MCK_RegG8RC";
  case MCK_RegG8RCNoX0: return "MCK_RegG8RCNoX0";
  case MCK_RegGPRC: return "MCK_RegGPRC";
  case MCK_RegGPRCNoR0: return "MCK_RegGPRCNoR0";
  case MCK_RegGxRCNoR0: return "MCK_RegGxRCNoR0";
  case MCK_RegGxRC: return "MCK_RegGxRC";
  case MCK_RegQBRC: return "MCK_RegQBRC";
  case MCK_RegQFRC: return "MCK_RegQFRC";
  case MCK_RegQSRC: return "MCK_RegQSRC";
  case MCK_RegSPE4RC: return "MCK_RegSPE4RC";
  case MCK_RegSPERC: return "MCK_RegSPERC";
  case MCK_RegSPILLTOVSRRC: return "MCK_RegSPILLTOVSRRC";
  case MCK_RegVFRC: return "MCK_RegVFRC";
  case MCK_RegVRRC: return "MCK_RegVRRC";
  case MCK_RegVSFRC: return "MCK_RegVSFRC";
  case MCK_RegVSRC: return "MCK_RegVSRC";
  case MCK_RegVSSRC: return "MCK_RegVSSRC";
  case MCK_S16Imm: return "MCK_S16Imm";
  case MCK_S17Imm: return "MCK_S17Imm";
  case MCK_S34Imm: return "MCK_S34Imm";
  case MCK_S5Imm: return "MCK_S5Imm";
  case MCK_S6Imm: return "MCK_S6Imm";
  case MCK_TLSReg: return "MCK_TLSReg";
  case MCK_U10Imm: return "MCK_U10Imm";
  case MCK_U12Imm: return "MCK_U12Imm";
  case MCK_U16Imm: return "MCK_U16Imm";
  case MCK_U1Imm: return "MCK_U1Imm";
  case MCK_U2Imm: return "MCK_U2Imm";
  case MCK_U3Imm: return "MCK_U3Imm";
  case MCK_U4Imm: return "MCK_U4Imm";
  case MCK_U5Imm: return "MCK_U5Imm";
  case MCK_U6Imm: return "MCK_U6Imm";
  case MCK_U7Imm: return "MCK_U7Imm";
  case MCK_U8Imm: return "MCK_U8Imm";
  case NumMatchClassKinds: return "NumMatchClassKinds";
  }
  llvm_unreachable("unhandled MatchClassKind!");
}

#endif // NDEBUG
FeatureBitset PPCAsmParser::
ComputeAvailableFeatures(const FeatureBitset& FB) const {
  FeatureBitset Features;
  return Features;
}

static bool checkAsmTiedOperandConstraints(const PPCAsmParser&AsmParser,
                               unsigned Kind,
                               const OperandVector &Operands,
                               uint64_t &ErrorInfo) {
  assert(Kind < CVT_NUM_SIGNATURES && "Invalid signature!");
  const uint8_t *Converter = ConversionTable[Kind];
  for (const uint8_t *p = Converter; *p; p+= 2) {
    switch (*p) {
    case CVT_Tied: {
      unsigned OpIdx = *(p+1);
      assert(OpIdx < (size_t)(std::end(TiedAsmOperandTable) -
                              std::begin(TiedAsmOperandTable)) &&
             "Tied operand not found");
      unsigned OpndNum1 = TiedAsmOperandTable[OpIdx][1];
      unsigned OpndNum2 = TiedAsmOperandTable[OpIdx][2];
      if (OpndNum1 != OpndNum2) {
        auto &SrcOp1 = Operands[OpndNum1];
        auto &SrcOp2 = Operands[OpndNum2];
        if (SrcOp1->isReg() && SrcOp2->isReg()) {
          if (!AsmParser.regsEqual(*SrcOp1, *SrcOp2)) {
            ErrorInfo = OpndNum2;
            return false;
          }
        }
      }
      break;
    }
    default:
      break;
    }
  }
  return true;
}

static const char *const MnemonicTable =
    "\003add\004addc\005addco\004adde\005addeo\004addi\005addic\005addis\005"
    "addme\006addmeo\004addo\007addpcis\005addze\006addzeo\003and\004andc\004"
    "andi\005andis\004attn\001b\002ba\002bc\003bc+\003bc-\003bca\004bca+\004"
    "bca-\005bcctr\006bcctrl\006bcdcfn\007bcdcfsq\006bcdcfz\010bcdcpsgn\006b"
    "cdctn\007bcdctsq\006bcdctz\004bcds\tbcdsetsgn\005bcdsr\010bcdtrunc\005b"
    "cdus\tbcdutrunc\003bcl\004bcl+\004bcl-\004bcla\005bcla+\005bcla-\004bcl"
    "r\005bclrl\004bctr\005bctrl\004bdnz\005bdnz+\005bdnz-\005bdnza\006bdnza"
    "+\006bdnza-\005bdnzf\006bdnzfa\006bdnzfl\007bdnzfla\007bdnzflr\010bdnzf"
    "lrl\005bdnzl\006bdnzl+\006bdnzl-\006bdnzla\007bdnzla+\007bdnzla-\006bdn"
    "zlr\007bdnzlr+\007bdnzlr-\007bdnzlrl\010bdnzlrl+\010bdnzlrl-\005bdnzt\006"
    "bdnzta\006bdnztl\007bdnztla\007bdnztlr\010bdnztlrl\003bdz\004bdz+\004bd"
    "z-\004bdza\005bdza+\005bdza-\004bdzf\005bdzfa\005bdzfl\006bdzfla\006bdz"
    "flr\007bdzflrl\004bdzl\005bdzl+\005bdzl-\005bdzla\006bdzla+\006bdzla-\005"
    "bdzlr\006bdzlr+\006bdzlr-\006bdzlrl\007bdzlrl+\007bdzlrl-\004bdzt\005bd"
    "zta\005bdztl\006bdztla\006bdztlr\007bdztlrl\003beq\004beq+\004beq-\004b"
    "eqa\005beqa+\005beqa-\006beqctr\007beqctr+\007beqctr-\007beqctrl\010beq"
    "ctrl+\010beqctrl-\004beql\005beql+\005beql-\005beqla\006beqla+\006beqla"
    "-\005beqlr\006beqlr+\006beqlr-\006beqlrl\007beqlrl+\007beqlrl-\002bf\003"
    "bf+\003bf-\003bfa\004bfa+\004bfa-\005bfctr\006bfctr+\006bfctr-\006bfctr"
    "l\007bfctrl+\007bfctrl-\003bfl\004bfl+\004bfl-\004bfla\005bfla+\005bfla"
    "-\004bflr\005bflr+\005bflr-\005bflrl\006bflrl+\006bflrl-\003bge\004bge+"
    "\004bge-\004bgea\005bgea+\005bgea-\006bgectr\007bgectr+\007bgectr-\007b"
    "gectrl\010bgectrl+\010bgectrl-\004bgel\005bgel+\005bgel-\005bgela\006bg"
    "ela+\006bgela-\005bgelr\006bgelr+\006bgelr-\006bgelrl\007bgelrl+\007bge"
    "lrl-\003bgt\004bgt+\004bgt-\004bgta\005bgta+\005bgta-\006bgtctr\007bgtc"
    "tr+\007bgtctr-\007bgtctrl\010bgtctrl+\010bgtctrl-\004bgtl\005bgtl+\005b"
    "gtl-\005bgtla\006bgtla+\006bgtla-\005bgtlr\006bgtlr+\006bgtlr-\006bgtlr"
    "l\007bgtlrl+\007bgtlrl-\002bl\003bla\003ble\004ble+\004ble-\004blea\005"
    "blea+\005blea-\006blectr\007blectr+\007blectr-\007blectrl\010blectrl+\010"
    "blectrl-\004blel\005blel+\005blel-\005blela\006blela+\006blela-\005blel"
    "r\006blelr+\006blelr-\006blelrl\007blelrl+\007blelrl-\003blr\004blrl\003"
    "blt\004blt+\004blt-\004blta\005blta+\005blta-\006bltctr\007bltctr+\007b"
    "ltctr-\007bltctrl\010bltctrl+\010bltctrl-\004bltl\005bltl+\005bltl-\005"
    "bltla\006bltla+\006bltla-\005bltlr\006bltlr+\006bltlr-\006bltlrl\007blt"
    "lrl+\007bltlrl-\003bne\004bne+\004bne-\004bnea\005bnea+\005bnea-\006bne"
    "ctr\007bnectr+\007bnectr-\007bnectrl\010bnectrl+\010bnectrl-\004bnel\005"
    "bnel+\005bnel-\005bnela\006bnela+\006bnela-\005bnelr\006bnelr+\006bnelr"
    "-\006bnelrl\007bnelrl+\007bnelrl-\003bng\004bng+\004bng-\004bnga\005bng"
    "a+\005bnga-\006bngctr\007bngctr+\007bngctr-\007bngctrl\010bngctrl+\010b"
    "ngctrl-\004bngl\005bngl+\005bngl-\005bngla\006bngla+\006bngla-\005bnglr"
    "\006bnglr+\006bnglr-\006bnglrl\007bnglrl+\007bnglrl-\003bnl\004bnl+\004"
    "bnl-\004bnla\005bnla+\005bnla-\006bnlctr\007bnlctr+\007bnlctr-\007bnlct"
    "rl\010bnlctrl+\010bnlctrl-\004bnll\005bnll+\005bnll-\005bnlla\006bnlla+"
    "\006bnlla-\005bnllr\006bnllr+\006bnllr-\006bnllrl\007bnllrl+\007bnllrl-"
    "\003bns\004bns+\004bns-\004bnsa\005bnsa+\005bnsa-\006bnsctr\007bnsctr+\007"
    "bnsctr-\007bnsctrl\010bnsctrl+\010bnsctrl-\004bnsl\005bnsl+\005bnsl-\005"
    "bnsla\006bnsla+\006bnsla-\005bnslr\006bnslr+\006bnslr-\006bnslrl\007bns"
    "lrl+\007bnslrl-\003bnu\004bnu+\004bnu-\004bnua\005bnua+\005bnua-\006bnu"
    "ctr\007bnuctr+\007bnuctr-\007bnuctrl\010bnuctrl+\010bnuctrl-\004bnul\005"
    "bnul+\005bnul-\005bnula\006bnula+\006bnula-\005bnulr\006bnulr+\006bnulr"
    "-\006bnulrl\007bnulrl+\007bnulrl-\006bpermd\005brinc\003bso\004bso+\004"
    "bso-\004bsoa\005bsoa+\005bsoa-\006bsoctr\007bsoctr+\007bsoctr-\007bsoct"
    "rl\010bsoctrl+\010bsoctrl-\004bsol\005bsol+\005bsol-\005bsola\006bsola+"
    "\006bsola-\005bsolr\006bsolr+\006bsolr-\006bsolrl\007bsolrl+\007bsolrl-"
    "\002bt\003bt+\003bt-\003bta\004bta+\004bta-\005btctr\006btctr+\006btctr"
    "-\006btctrl\007btctrl+\007btctrl-\003btl\004btl+\004btl-\004btla\005btl"
    "a+\005btla-\004btlr\005btlr+\005btlr-\005btlrl\006btlrl+\006btlrl-\003b"
    "un\004bun+\004bun-\004buna\005buna+\005buna-\006bunctr\007bunctr+\007bu"
    "nctr-\007bunctrl\010bunctrl+\010bunctrl-\004bunl\005bunl+\005bunl-\005b"
    "unla\006bunla+\006bunla-\005bunlr\006bunlr+\006bunlr-\006bunlrl\007bunl"
    "rl+\007bunlrl-\007clrbhrb\006clrldi\010clrlsldi\010clrlslwi\006clrlwi\006"
    "clrrdi\006clrrwi\003cmp\004cmpb\004cmpd\005cmpdi\006cmpeqb\004cmpi\004c"
    "mpl\005cmpld\006cmpldi\005cmpli\005cmplw\006cmplwi\005cmprb\004cmpw\005"
    "cmpwi\006cntlzd\006cntlzw\006cnttzd\006cnttzw\004copy\ncopy_first\010cp"
    "_abort\005crand\006crandc\005crclr\005creqv\006crmove\006crnand\005crno"
    "r\005crnot\004cror\005crorc\005crset\005crxor\004darn\004dcba\004dcbf\006"
    "dcbfep\005dcbfl\006dcbflp\004dcbi\005dcbst\007dcbstep\004dcbt\006dcbtct"
    "\006dcbtds\006dcbtep\006dcbtst\010dcbtstct\010dcbtstds\010dcbtstep\007d"
    "cbtstt\005dcbtt\004dcbz\006dcbzep\005dcbzl\007dcbzlep\005dccci\003dci\004"
    "divd\005divde\006divdeo\006divdeu\007divdeuo\005divdo\005divdu\006divdu"
    "o\004divw\005divwe\006divweo\006divweu\007divweuo\005divwo\005divwu\006"
    "divwuo\003dss\006dssall\003dst\005dstst\006dststt\004dstt\006efdabs\006"
    "efdadd\006efdcfs\007efdcfsf\007efdcfsi\010efdcfsid\007efdcfuf\007efdcfu"
    "i\010efdcfuid\010efdcmpeq\010efdcmpgt\010efdcmplt\007efdctsf\007efdctsi"
    "\tefdctsidz\010efdctsiz\007efdctuf\007efdctui\tefdctuidz\010efdctuiz\006"
    "efddiv\006efdmul\007efdnabs\006efdneg\006efdsub\010efdtsteq\010efdtstgt"
    "\010efdtstlt\006efsabs\006efsadd\006efscfd\007efscfsf\007efscfsi\007efs"
    "cfuf\007efscfui\010efscmpeq\010efscmpgt\010efscmplt\007efsctsf\007efsct"
    "si\010efsctsiz\007efsctuf\007efsctui\010efsctuiz\006efsdiv\006efsmul\007"
    "efsnabs\006efsneg\006efssub\010efststeq\010efststgt\010efststlt\005eiei"
    "o\003eqv\005evabs\007evaddiw\013evaddsmiaaw\013evaddssiaaw\013evaddumia"
    "aw\013evaddusiaaw\006evaddw\005evand\006evandc\007evcmpeq\010evcmpgts\010"
    "evcmpgtu\010evcmplts\010evcmpltu\010evcntlsw\010evcntlzw\007evdivws\007"
    "evdivwu\005eveqv\007evextsb\007evextsh\007evfsabs\007evfsadd\010evfscfs"
    "f\010evfscfsi\010evfscfuf\010evfscfui\tevfscmpeq\tevfscmpgt\tevfscmplt\010"
    "evfsctsf\010evfsctsi\tevfsctsiz\010evfsctui\007evfsdiv\007evfsmul\010ev"
    "fsnabs\007evfsneg\007evfssub\tevfststeq\tevfststgt\tevfststlt\005evldd\006"
    "evlddx\005evldh\006evldhx\005evldw\006evldwx\013evlhhesplat\014evlhhesp"
    "latx\014evlhhossplat\015evlhhossplatx\014evlhhousplat\015evlhhousplatx\006"
    "evlwhe\007evlwhex\007evlwhos\010evlwhosx\007evlwhou\010evlwhoux\nevlwhs"
    "plat\013evlwhsplatx\nevlwwsplat\013evlwwsplatx\tevmergehi\013evmergehil"
    "o\tevmergelo\013evmergelohi\013evmhegsmfaa\013evmhegsmfan\013evmhegsmia"
    "a\013evmhegsmian\013evmhegumiaa\013evmhegumian\010evmhesmf\tevmhesmfa\013"
    "evmhesmfaaw\013evmhesmfanw\010evmhesmi\tevmhesmia\013evmhesmiaaw\013evm"
    "hesmianw\010evmhessf\tevmhessfa\013evmhessfaaw\013evmhessfanw\013evmhes"
    "siaaw\013evmhessianw\010evmheumi\tevmheumia\013evmheumiaaw\013evmheumia"
    "nw\013evmheusiaaw\013evmheusianw\013evmhogsmfaa\013evmhogsmfan\013evmho"
    "gsmiaa\013evmhogsmian\013evmhogumiaa\013evmhogumian\010evmhosmf\tevmhos"
    "mfa\013evmhosmfaaw\013evmhosmfanw\010evmhosmi\tevmhosmia\013evmhosmiaaw"
    "\013evmhosmianw\010evmhossf\tevmhossfa\013evmhossfaaw\013evmhossfanw\013"
    "evmhossiaaw\013evmhossianw\010evmhoumi\tevmhoumia\013evmhoumiaaw\013evm"
    "houmianw\013evmhousiaaw\013evmhousianw\005evmra\010evmwhsmf\tevmwhsmfa\010"
    "evmwhsmi\tevmwhsmia\010evmwhssf\tevmwhssfa\010evmwhumi\tevmwhumia\013ev"
    "mwlsmiaaw\013evmwlsmianw\013evmwlssiaaw\013evmwlssianw\010evmwlumi\tevm"
    "wlumia\013evmwlumiaaw\013evmwlumianw\013evmwlusiaaw\013evmwlusianw\007e"
    "vmwsmf\010evmwsmfa\tevmwsmfaa\tevmwsmfan\007evmwsmi\010evmwsmia\tevmwsm"
    "iaa\tevmwsmian\007evmwssf\010evmwssfa\tevmwssfaa\tevmwssfan\007evmwumi\010"
    "evmwumia\tevmwumiaa\tevmwumian\006evnand\005evneg\005evnor\004evor\005e"
    "vorc\005evrlw\006evrlwi\006evrndw\005evsel\005evslw\006evslwi\tevsplatf"
    "i\010evsplati\007evsrwis\007evsrwiu\006evsrws\006evsrwu\006evstdd\007ev"
    "stddx\006evstdh\007evstdhx\006evstdw\007evstdwx\007evstwhe\010evstwhex\007"
    "evstwho\010evstwhox\007evstwwe\010evstwwex\007evstwwo\010evstwwox\014ev"
    "subfsmiaaw\014evsubfssiaaw\014evsubfumiaaw\014evsubfusiaaw\007evsubfw\010"
    "evsubifw\005evxor\006extldi\006extlwi\006extrdi\006extrwi\005extsb\005e"
    "xtsh\005extsw\010extswsli\004fabs\004fadd\005fadds\005fcfid\006fcfids\006"
    "fcfidu\007fcfidus\005fcmpu\006fcpsgn\005fctid\006fctidu\007fctiduz\006f"
    "ctidz\005fctiw\006fctiwu\007fctiwuz\006fctiwz\004fdiv\005fdivs\005fmadd"
    "\006fmadds\003fmr\005fmsub\006fmsubs\004fmul\005fmuls\005fnabs\004fneg\006"
    "fnmadd\007fnmadds\006fnmsub\007fnmsubs\003fre\004fres\004frim\004frin\004"
    "frip\004friz\004frsp\007frsqrte\010frsqrtes\004fsel\005fsqrt\006fsqrts\004"
    "fsub\005fsubs\005ftdiv\006ftsqrt\005hrfid\004icbi\006icbiep\005icblc\005"
    "icblq\004icbt\006icbtls\005iccci\003ici\006inslwi\006insrdi\006insrwi\004"
    "isel\006iseleq\006iselgt\006isellt\005isync\002la\005lbarx\005lbepx\003"
    "lbz\006lbzcix\004lbzu\005lbzux\004lbzx\002ld\005ldarx\004ldat\005ldbrx\005"
    "ldcix\004ldmx\003ldu\004ldux\003ldx\003lfd\006lfdepx\004lfdu\005lfdux\004"
    "lfdx\006lfiwax\006lfiwzx\003lfs\004lfsu\005lfsux\004lfsx\003lha\005lhar"
    "x\004lhau\005lhaux\004lhax\005lhbrx\005lhepx\003lhz\006lhzcix\004lhzu\005"
    "lhzux\004lhzx\002li\003lis\003lmw\004lnia\004lswi\005lvebx\005lvehx\005"
    "lvewx\004lvsl\004lvsr\003lvx\004lvxl\003lwa\005lwarx\004lwat\005lwaux\004"
    "lwax\005lwbrx\005lwepx\006lwsync\003lwz\006lwzcix\004lwzu\005lwzux\004l"
    "wzx\004lxsd\005lxsdx\007lxsibzx\007lxsihzx\007lxsiwax\007lxsiwzx\005lxs"
    "sp\006lxsspx\003lxv\007lxvb16x\006lxvd2x\006lxvdsx\006lxvh8x\004lxvl\005"
    "lxvll\006lxvw4x\006lxvwsx\004lxvx\006maddhd\007maddhdu\006maddld\004mba"
    "r\004mcrf\005mcrfs\006mcrxrx\005mfamr\005mfasr\007mfbhrbe\005mfbr0\005m"
    "fbr1\005mfbr2\005mfbr3\005mfbr4\005mfbr5\005mfbr6\005mfbr7\006mfcfar\004"
    "mfcr\005mfctr\005mfdar\007mfdbatl\007mfdbatu\006mfdccr\005mfdcr\006mfde"
    "ar\005mfdec\006mfdscr\007mfdsisr\005mfesr\006mffprd\007mffprwz\004mffs\010"
    "mffscdrn\tmffscdrni\006mffsce\007mffscrn\010mffscrni\005mffsl\007mfibat"
    "l\007mfibatu\006mficcr\004mflr\005mfmsr\006mfocrf\005mfpid\005mfpmr\005"
    "mfpvr\006mfrtcl\006mfrtcu\006mfsdr1\tmfspefscr\005mfspr\006mfsprg\007mf"
    "sprg0\007mfsprg1\007mfsprg2\007mfsprg3\007mfsprg4\007mfsprg5\007mfsprg6"
    "\007mfsprg7\004mfsr\006mfsrin\006mfsrr0\006mfsrr1\006mfsrr2\006mfsrr3\004"
    "mftb\006mftbhi\005mftbl\006mftblo\005mftbu\005mftcr\005mfvrd\010mfvrsav"
    "e\006mfvrwz\006mfvscr\006mfvsrd\007mfvsrld\007mfvsrwz\005mfxer\005modsd"
    "\005modsw\005modud\005moduw\002mr\007msgsync\005msync\005mtamr\005mtasr"
    "\005mtbr0\005mtbr1\005mtbr2\005mtbr3\005mtbr4\005mtbr5\005mtbr6\005mtbr"
    "7\006mtcfar\004mtcr\005mtcrf\005mtctr\005mtdar\007mtdbatl\007mtdbatu\006"
    "mtdccr\005mtdcr\006mtdear\005mtdec\006mtdscr\007mtdsisr\005mtesr\006mtf"
    "prd\007mtfprwa\007mtfprwz\006mtfsb0\006mtfsb1\005mtfsf\006mtfsfi\007mti"
    "batl\007mtibatu\006mticcr\004mtlr\005mtmsr\006mtmsrd\006mtocrf\005mtpid"
    "\005mtpmr\006mtsdr1\tmtspefscr\005mtspr\006mtsprg\007mtsprg0\007mtsprg1"
    "\007mtsprg2\007mtsprg3\007mtsprg4\007mtsprg5\007mtsprg6\007mtsprg7\004m"
    "tsr\006mtsrin\006mtsrr0\006mtsrr1\006mtsrr2\006mtsrr3\006mttbhi\005mttb"
    "l\006mttblo\005mttbu\005mttcr\005mtvrd\010mtvrsave\006mtvrwa\006mtvrwz\006"
    "mtvscr\006mtvsrd\007mtvsrdd\007mtvsrwa\007mtvsrws\007mtvsrwz\005mtxer\005"
    "mulhd\006mulhdu\005mulhw\006mulhwu\005mulld\006mulldo\005mulli\005mullw"
    "\006mullwo\004nand\003nap\003neg\004nego\003nop\003nor\003not\002or\003"
    "orc\003ori\004oris\005paddi\005paste\npaste_last\004plbz\003pld\004plfd"
    "\004plfs\004plha\004plhz\003pli\004plwa\004plwz\005plxsd\006plxssp\004p"
    "lxv\007popcntb\007popcntd\007popcntw\004pstb\004pstd\005pstfd\005pstfs\004"
    "psth\004pstw\006pstxsd\007pstxssp\005pstxv\007ptesync\010qvaligni\tqves"
    "plati\006qvfabs\006qvfadd\007qvfadds\006qvfand\007qvfandc\007qvfcfid\010"
    "qvfcfids\010qvfcfidu\tqvfcfidus\006qvfclr\010qvfcmpeq\010qvfcmpgt\010qv"
    "fcmplt\010qvfcpsgn\007qvfctfb\007qvfctid\010qvfctidu\tqvfctiduz\010qvfc"
    "tidz\007qvfctiw\010qvfctiwu\tqvfctiwuz\010qvfctiwz\006qvfequ\nqvflogica"
    "l\007qvfmadd\010qvfmadds\005qvfmr\007qvfmsub\010qvfmsubs\006qvfmul\007q"
    "vfmuls\007qvfnabs\007qvfnand\006qvfneg\010qvfnmadd\tqvfnmadds\010qvfnms"
    "ub\tqvfnmsubs\006qvfnor\006qvfnot\005qvfor\006qvforc\007qvfperm\005qvfr"
    "e\006qvfres\006qvfrim\006qvfrin\006qvfrip\006qvfriz\006qvfrsp\tqvfrsqrt"
    "e\nqvfrsqrtes\006qvfsel\006qvfset\006qvfsub\007qvfsubs\tqvftstnan\010qv"
    "fxmadd\tqvfxmadds\007qvfxmul\010qvfxmuls\006qvfxor\014qvfxxcpnmadd\015q"
    "vfxxcpnmadds\tqvfxxmadd\nqvfxxmadds\013qvfxxnpmadd\014qvfxxnpmadds\006q"
    "vgpci\010qvlfcdux\tqvlfcduxa\007qvlfcdx\010qvlfcdxa\010qvlfcsux\tqvlfcs"
    "uxa\007qvlfcsx\010qvlfcsxa\007qvlfdux\010qvlfduxa\006qvlfdx\007qvlfdxa\010"
    "qvlfiwax\tqvlfiwaxa\010qvlfiwzx\tqvlfiwzxa\007qvlfsux\010qvlfsuxa\006qv"
    "lfsx\007qvlfsxa\010qvlpcldx\010qvlpclsx\010qvlpcrdx\010qvlpcrsx\tqvstfc"
    "dux\nqvstfcduxa\nqvstfcduxi\013qvstfcduxia\010qvstfcdx\tqvstfcdxa\tqvst"
    "fcdxi\nqvstfcdxia\tqvstfcsux\nqvstfcsuxa\nqvstfcsuxi\013qvstfcsuxia\010"
    "qvstfcsx\tqvstfcsxa\tqvstfcsxi\nqvstfcsxia\010qvstfdux\tqvstfduxa\tqvst"
    "fduxi\nqvstfduxia\007qvstfdx\010qvstfdxa\010qvstfdxi\tqvstfdxia\010qvst"
    "fiwx\tqvstfiwxa\010qvstfsux\tqvstfsuxa\tqvstfsuxi\nqvstfsuxia\007qvstfs"
    "x\010qvstfsxa\010qvstfsxi\tqvstfsxia\004rfci\004rfdi\005rfebb\003rfi\005"
    "rfmci\005rldcl\005rldcr\005rldic\006rldicl\006rldicr\006rldimi\006rlwim"
    "i\006rlwinm\005rlwnm\005rotld\006rotldi\005rotlw\006rotlwi\006rotrdi\006"
    "rotrwi\002sc\004setb\006slbfee\005slbia\005slbie\006slbieg\007slbmfee\007"
    "slbmfev\006slbmte\007slbsync\003sld\004sldi\003slw\004slwi\004srad\005s"
    "radi\004sraw\005srawi\003srd\004srdi\003srw\004srwi\003stb\006stbcix\005"
    "stbcx\006stbepx\004stbu\005stbux\004stbx\003std\005stdat\006stdbrx\006s"
    "tdcix\005stdcx\004stdu\005stdux\004stdx\004stfd\007stfdepx\005stfdu\006"
    "stfdux\005stfdx\006stfiwx\004stfs\005stfsu\006stfsux\005stfsx\003sth\006"
    "sthbrx\006sthcix\005sthcx\006sthepx\004sthu\005sthux\004sthx\004stmw\004"
    "stop\005stswi\006stvebx\006stvehx\006stvewx\004stvx\005stvxl\003stw\005"
    "stwat\006stwbrx\006stwcix\005stwcx\006stwepx\004stwu\005stwux\004stwx\005"
    "stxsd\006stxsdx\007stxsibx\007stxsihx\007stxsiwx\006stxssp\007stxsspx\004"
    "stxv\010stxvb16x\007stxvd2x\007stxvh8x\005stxvl\006stxvll\007stxvw4x\005"
    "stxvx\003sub\004subc\004subf\005subfc\006subfco\005subfe\006subfeo\006s"
    "ubfic\006subfme\007subfmeo\005subfo\006subfze\007subfzeo\004subi\005sub"
    "ic\005subis\007subpcis\004sync\006tabort\010tabortdc\ttabortdci\010tabo"
    "rtwc\ttabortwci\006tbegin\006tcheck\002td\004tdeq\005tdeqi\004tdge\005t"
    "dgei\004tdgt\005tdgti\003tdi\004tdle\005tdlei\005tdlge\006tdlgei\005tdl"
    "gt\006tdlgti\005tdlle\006tdllei\005tdllt\006tdllti\005tdlng\006tdlngi\005"
    "tdlnl\006tdlnli\004tdlt\005tdlti\004tdne\005tdnei\004tdng\005tdngi\004t"
    "dnl\005tdnli\003tdu\004tdui\004tend\007tendall\005tlbia\005tlbie\006tlb"
    "iel\007tlbivax\005tlbld\005tlbli\005tlbre\007tlbrehi\007tlbrelo\005tlbs"
    "x\007tlbsync\005tlbwe\007tlbwehi\007tlbwelo\004trap\010trechkpt\010trec"
    "laim\007tresume\003tsr\010tsuspend\002tw\004tweq\005tweqi\004twge\005tw"
    "gei\004twgt\005twgti\003twi\004twle\005twlei\005twlge\006twlgei\005twlg"
    "t\006twlgti\005twlle\006twllei\005twllt\006twllti\005twlng\006twlngi\005"
    "twlnl\006twlnli\004twlt\005twlti\004twne\005twnei\004twng\005twngi\004t"
    "wnl\005twnli\003twu\004twui\007vabsdub\007vabsduh\007vabsduw\007vaddcuq"
    "\007vaddcuw\010vaddecuq\010vaddeuqm\006vaddfp\007vaddsbs\007vaddshs\007"
    "vaddsws\007vaddubm\007vaddubs\007vaddudm\007vadduhm\007vadduhs\007vaddu"
    "qm\007vadduwm\007vadduws\004vand\005vandc\006vavgsb\006vavgsh\006vavgsw"
    "\006vavgub\006vavguh\006vavguw\007vbpermd\007vbpermq\005vcfsx\005vcfux\007"
    "vcipher\013vcipherlast\005vclzb\005vclzd\005vclzh\010vclzlsbb\005vclzw\007"
    "vcmpbfp\010vcmpeqfp\010vcmpequb\010vcmpequd\010vcmpequh\010vcmpequw\010"
    "vcmpgefp\010vcmpgtfp\010vcmpgtsb\010vcmpgtsd\010vcmpgtsh\010vcmpgtsw\010"
    "vcmpgtub\010vcmpgtud\010vcmpgtuh\010vcmpgtuw\007vcmpneb\007vcmpneh\007v"
    "cmpnew\010vcmpnezb\010vcmpnezh\010vcmpnezw\006vctsxs\006vctuxs\005vctzb"
    "\005vctzd\005vctzh\010vctzlsbb\005vctzw\004veqv\010vexptefp\tvextractd\n"
    "vextractub\nvextractuh\nvextractuw\010vextsb2d\010vextsb2w\010vextsh2d\010"
    "vextsh2w\010vextsw2d\010vextublx\010vextubrx\010vextuhlx\010vextuhrx\010"
    "vextuwlx\010vextuwrx\005vgbbd\010vinsertb\010vinsertd\010vinserth\010vi"
    "nsertw\007vlogefp\007vmaddfp\006vmaxfp\006vmaxsb\006vmaxsd\006vmaxsh\006"
    "vmaxsw\006vmaxub\006vmaxud\006vmaxuh\006vmaxuw\tvmhaddshs\nvmhraddshs\006"
    "vminfp\006vminsb\006vminsd\006vminsh\006vminsw\006vminub\006vminud\006v"
    "minuh\006vminuw\tvmladduhm\003vmr\006vmrgew\006vmrghb\006vmrghh\006vmrg"
    "hw\006vmrglb\006vmrglh\006vmrglw\006vmrgow\010vmsummbm\010vmsumshm\010v"
    "msumshs\010vmsumubm\010vmsumudm\010vmsumuhm\010vmsumuhs\tvmul10cuq\nvmu"
    "l10ecuq\tvmul10euq\010vmul10uq\007vmulesb\007vmulesh\007vmulesw\007vmul"
    "eub\007vmuleuh\007vmuleuw\007vmulosb\007vmulosh\007vmulosw\007vmuloub\007"
    "vmulouh\007vmulouw\007vmuluwm\005vnand\010vncipher\014vncipherlast\005v"
    "negd\005vnegw\010vnmsubfp\004vnor\004vnot\003vor\004vorc\005vperm\006vp"
    "ermr\010vpermxor\005vpkpx\007vpksdss\007vpksdus\007vpkshss\007vpkshus\007"
    "vpkswss\007vpkswus\007vpkudum\007vpkudus\007vpkuhum\007vpkuhus\007vpkuw"
    "um\007vpkuwus\007vpmsumb\007vpmsumd\007vpmsumh\007vpmsumw\010vpopcntb\010"
    "vpopcntd\010vpopcnth\010vpopcntw\007vprtybd\007vprtybq\007vprtybw\005vr"
    "efp\005vrfim\005vrfin\005vrfip\005vrfiz\004vrlb\004vrld\006vrldmi\006vr"
    "ldnm\004vrlh\004vrlw\006vrlwmi\006vrlwnm\tvrsqrtefp\005vsbox\004vsel\nv"
    "shasigmad\nvshasigmaw\003vsl\004vslb\004vsld\006vsldoi\004vslh\004vslo\004"
    "vslv\004vslw\006vspltb\006vsplth\010vspltisb\010vspltish\010vspltisw\006"
    "vspltw\003vsr\005vsrab\005vsrad\005vsrah\005vsraw\004vsrb\004vsrd\004vs"
    "rh\004vsro\004vsrv\004vsrw\007vsubcuq\007vsubcuw\010vsubecuq\010vsubeuq"
    "m\006vsubfp\007vsubsbs\007vsubshs\007vsubsws\007vsububm\007vsububs\007v"
    "subudm\007vsubuhm\007vsubuhs\007vsubuqm\007vsubuwm\007vsubuws\010vsum2s"
    "ws\010vsum4sbs\010vsum4shs\010vsum4ubs\007vsumsws\007vupkhpx\007vupkhsb"
    "\007vupkhsh\007vupkhsw\007vupklpx\007vupklsb\007vupklsh\007vupklsw\004v"
    "xor\004wait\010waitimpl\007waitrsv\005wrtee\006wrteei\004xnop\003xor\004"
    "xori\005xoris\007xsabsdp\007xsabsqp\007xsadddp\007xsaddqp\010xsaddqpo\007"
    "xsaddsp\txscmpeqdp\nxscmpexpdp\nxscmpexpqp\txscmpgedp\txscmpgtdp\010xsc"
    "mpodp\010xscmpoqp\010xscmpudp\010xscmpuqp\txscpsgndp\txscpsgnqp\010xscv"
    "dphp\010xscvdpqp\010xscvdpsp\txscvdpspn\nxscvdpsxds\nxscvdpsxws\nxscvdp"
    "uxds\nxscvdpuxws\010xscvhpdp\010xscvqpdp\txscvqpdpo\txscvqpsdz\txscvqps"
    "wz\txscvqpudz\txscvqpuwz\010xscvsdqp\010xscvspdp\txscvspdpn\txscvsxddp\t"
    "xscvsxdsp\010xscvudqp\txscvuxddp\txscvuxdsp\007xsdivdp\007xsdivqp\010xs"
    "divqpo\007xsdivsp\010xsiexpdp\010xsiexpqp\txsmaddadp\txsmaddasp\txsmadd"
    "mdp\txsmaddmsp\010xsmaddqp\txsmaddqpo\010xsmaxcdp\007xsmaxdp\010xsmaxjd"
    "p\010xsmincdp\007xsmindp\010xsminjdp\txsmsubadp\txsmsubasp\txsmsubmdp\t"
    "xsmsubmsp\010xsmsubqp\txsmsubqpo\007xsmuldp\007xsmulqp\010xsmulqpo\007x"
    "smulsp\010xsnabsdp\010xsnabsqp\007xsnegdp\007xsnegqp\nxsnmaddadp\nxsnma"
    "ddasp\nxsnmaddmdp\nxsnmaddmsp\txsnmaddqp\nxsnmaddqpo\nxsnmsubadp\nxsnms"
    "ubasp\nxsnmsubmdp\nxsnmsubmsp\txsnmsubqp\nxsnmsubqpo\006xsrdpi\007xsrdp"
    "ic\007xsrdpim\007xsrdpip\007xsrdpiz\006xsredp\006xsresp\006xsrqpi\007xs"
    "rqpix\007xsrqpxp\005xsrsp\nxsrsqrtedp\nxsrsqrtesp\010xssqrtdp\010xssqrt"
    "qp\txssqrtqpo\010xssqrtsp\007xssubdp\007xssubqp\010xssubqpo\007xssubsp\010"
    "xstdivdp\txstsqrtdp\txststdcdp\txststdcqp\txststdcsp\010xsxexpdp\010xsx"
    "expqp\010xsxsigdp\010xsxsigqp\007xvabsdp\007xvabssp\007xvadddp\007xvadd"
    "sp\txvcmpeqdp\txvcmpeqsp\txvcmpgedp\txvcmpgesp\txvcmpgtdp\txvcmpgtsp\tx"
    "vcpsgndp\txvcpsgnsp\010xvcvdpsp\nxvcvdpsxds\nxvcvdpsxws\nxvcvdpuxds\nxv"
    "cvdpuxws\010xvcvhpsp\010xvcvspdp\010xvcvsphp\nxvcvspsxds\nxvcvspsxws\nx"
    "vcvspuxds\nxvcvspuxws\txvcvsxddp\txvcvsxdsp\txvcvsxwdp\txvcvsxwsp\txvcv"
    "uxddp\txvcvuxdsp\txvcvuxwdp\txvcvuxwsp\007xvdivdp\007xvdivsp\010xviexpd"
    "p\010xviexpsp\txvmaddadp\txvmaddasp\txvmaddmdp\txvmaddmsp\007xvmaxdp\007"
    "xvmaxsp\007xvmindp\007xvminsp\007xvmovdp\007xvmovsp\txvmsubadp\txvmsuba"
    "sp\txvmsubmdp\txvmsubmsp\007xvmuldp\007xvmulsp\010xvnabsdp\010xvnabssp\007"
    "xvnegdp\007xvnegsp\nxvnmaddadp\nxvnmaddasp\nxvnmaddmdp\nxvnmaddmsp\nxvn"
    "msubadp\nxvnmsubasp\nxvnmsubmdp\nxvnmsubmsp\006xvrdpi\007xvrdpic\007xvr"
    "dpim\007xvrdpip\007xvrdpiz\006xvredp\006xvresp\006xvrspi\007xvrspic\007"
    "xvrspim\007xvrspip\007xvrspiz\nxvrsqrtedp\nxvrsqrtesp\010xvsqrtdp\010xv"
    "sqrtsp\007xvsubdp\007xvsubsp\010xvtdivdp\010xvtdivsp\txvtsqrtdp\txvtsqr"
    "tsp\txvtstdcdp\txvtstdcsp\010xvxexpdp\010xvxexpsp\010xvxsigdp\010xvxsig"
    "sp\005xxbrd\005xxbrh\005xxbrq\005xxbrw\013xxextractuw\txxinsertw\006xxl"
    "and\007xxlandc\006xxleqv\007xxlnand\006xxlnor\005xxlor\006xxlorc\006xxl"
    "xor\007xxmrghd\007xxmrghw\007xxmrgld\007xxmrglw\006xxperm\010xxpermdi\007"
    "xxpermr\005xxsel\007xxsldwi\007xxspltd\010xxspltib\007xxspltw\007xxswap"
    "d";

// Feature bitsets.
enum : uint8_t {
  AMFBS_None,
};

static constexpr FeatureBitset FeatureBitsets[] = {
  {}, // AMFBS_None
};

namespace {
  struct MatchEntry {
    uint16_t Mnemonic;
    uint16_t Opcode;
    uint16_t ConvertFn;
    uint8_t RequiredFeaturesIdx;
    uint8_t Classes[6];
    StringRef getMnemonic() const {
      return StringRef(MnemonicTable + Mnemonic + 1,
                       MnemonicTable[Mnemonic]);
    }
  };

  // Predicate for searching for an opcode.
  struct LessOpcode {
    bool operator()(const MatchEntry &LHS, StringRef RHS) {
      return LHS.getMnemonic() < RHS;
    }
    bool operator()(StringRef LHS, const MatchEntry &RHS) {
      return LHS < RHS.getMnemonic();
    }
    bool operator()(const MatchEntry &LHS, const MatchEntry &RHS) {
      return LHS.getMnemonic() < RHS.getMnemonic();
    }
  };
} // end anonymous namespace

static const MatchEntry MatchTable0[] = {
  { 0 /* add */, PPC::ADD8TLS_, Convert__RegG8RC1_0__RegG8RC1_1__TLSReg1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_TLSReg }, },
  { 0 /* add */, PPC::ADD4, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 0 /* add */, PPC::ADD4_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4 /* addc */, PPC::ADDC, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4 /* addc */, PPC::ADDC_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9 /* addco */, PPC::ADDCO, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9 /* addco */, PPC::ADDCO_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 15 /* adde */, PPC::ADDE, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 15 /* adde */, PPC::ADDE_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 20 /* addeo */, PPC::ADDEO, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 20 /* addeo */, PPC::ADDEO_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 26 /* addi */, PPC::ADDI, Convert__RegGPRC1_0__RegGPRCNoR01_1__S16Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRCNoR0, MCK_S16Imm }, },
  { 31 /* addic */, PPC::ADDIC, Convert__RegGPRC1_0__RegGPRC1_1__S16Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_S16Imm }, },
  { 31 /* addic */, PPC::ADDIC_rec, Convert__RegGPRC1_1__RegGPRC1_2__S16Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_S16Imm }, },
  { 37 /* addis */, PPC::ADDIS, Convert__RegGPRC1_0__RegGPRCNoR01_1__S17Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRCNoR0, MCK_S17Imm }, },
  { 43 /* addme */, PPC::ADDME, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 43 /* addme */, PPC::ADDME_rec, Convert__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 49 /* addmeo */, PPC::ADDMEO, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 49 /* addmeo */, PPC::ADDMEO_rec, Convert__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 56 /* addo */, PPC::ADD4O, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 56 /* addo */, PPC::ADD4O_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 61 /* addpcis */, PPC::ADDPCIS, Convert__RegG8RC1_0__Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_Imm }, },
  { 69 /* addze */, PPC::ADDZE, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 69 /* addze */, PPC::ADDZE_rec, Convert__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 75 /* addzeo */, PPC::ADDZEO, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 75 /* addzeo */, PPC::ADDZEO_rec, Convert__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 82 /* and */, PPC::AND, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 82 /* and */, PPC::AND_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 86 /* andc */, PPC::ANDC, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 86 /* andc */, PPC::ANDC_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 91 /* andi */, PPC::ANDI_rec, Convert__RegGPRC1_1__RegGPRC1_2__U16Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U16Imm }, },
  { 96 /* andis */, PPC::ANDIS_rec, Convert__RegGPRC1_1__RegGPRC1_2__U16Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U16Imm }, },
  { 102 /* attn */, PPC::ATTN, Convert_NoOperands, AMFBS_None, {  }, },
  { 107 /* b */, PPC::B, Convert__DirectBr1_0, AMFBS_None, { MCK_DirectBr }, },
  { 109 /* ba */, PPC::BA, Convert__DirectBr1_0, AMFBS_None, { MCK_DirectBr }, },
  { 112 /* bc */, PPC::gBC, Convert__U5Imm1_0__RegCRBITRC1_1__CondBr1_2, AMFBS_None, { MCK_U5Imm, MCK_RegCRBITRC, MCK_CondBr }, },
  { 112 /* bc */, PPC::gBCat, Convert__U5Imm1_1__ATBitsAsHint1_0__RegCRBITRC1_2__CondBr1_3, AMFBS_None, { MCK_ATBitsAsHint, MCK_U5Imm, MCK_RegCRBITRC, MCK_CondBr }, },
  { 115 /* bc+ */, PPC::gBCat, Convert__U5Imm1_0__imm_95_3__RegCRBITRC1_1__CondBr1_2, AMFBS_None, { MCK_U5Imm, MCK_RegCRBITRC, MCK_CondBr }, },
  { 119 /* bc- */, PPC::gBCat, Convert__U5Imm1_0__imm_95_2__RegCRBITRC1_1__CondBr1_2, AMFBS_None, { MCK_U5Imm, MCK_RegCRBITRC, MCK_CondBr }, },
  { 123 /* bca */, PPC::gBCA, Convert__U5Imm1_0__RegCRBITRC1_1__CondBr1_2, AMFBS_None, { MCK_U5Imm, MCK_RegCRBITRC, MCK_CondBr }, },
  { 123 /* bca */, PPC::gBCAat, Convert__U5Imm1_1__ATBitsAsHint1_0__RegCRBITRC1_2__CondBr1_3, AMFBS_None, { MCK_ATBitsAsHint, MCK_U5Imm, MCK_RegCRBITRC, MCK_CondBr }, },
  { 127 /* bca+ */, PPC::gBCAat, Convert__U5Imm1_0__imm_95_3__RegCRBITRC1_1__CondBr1_2, AMFBS_None, { MCK_U5Imm, MCK_RegCRBITRC, MCK_CondBr }, },
  { 132 /* bca- */, PPC::gBCAat, Convert__U5Imm1_0__imm_95_2__RegCRBITRC1_1__CondBr1_2, AMFBS_None, { MCK_U5Imm, MCK_RegCRBITRC, MCK_CondBr }, },
  { 137 /* bcctr */, PPC::gBCCTR, Convert__U5Imm1_0__RegCRBITRC1_1__imm_95_0, AMFBS_None, { MCK_U5Imm, MCK_RegCRBITRC }, },
  { 137 /* bcctr */, PPC::gBCCTR, Convert__U5Imm1_0__RegCRBITRC1_1__Imm1_2, AMFBS_None, { MCK_U5Imm, MCK_RegCRBITRC, MCK_Imm }, },
  { 143 /* bcctrl */, PPC::gBCCTRL, Convert__U5Imm1_0__RegCRBITRC1_1__imm_95_0, AMFBS_None, { MCK_U5Imm, MCK_RegCRBITRC }, },
  { 143 /* bcctrl */, PPC::gBCCTRL, Convert__U5Imm1_0__RegCRBITRC1_1__Imm1_2, AMFBS_None, { MCK_U5Imm, MCK_RegCRBITRC, MCK_Imm }, },
  { 150 /* bcdcfn */, PPC::BCDCFN_rec, Convert__RegVRRC1_1__RegVRRC1_2__U1Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_U1Imm }, },
  { 157 /* bcdcfsq */, PPC::BCDCFSQ_rec, Convert__RegVRRC1_1__RegVRRC1_2__U1Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_U1Imm }, },
  { 165 /* bcdcfz */, PPC::BCDCFZ_rec, Convert__RegVRRC1_1__RegVRRC1_2__U1Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_U1Imm }, },
  { 172 /* bcdcpsgn */, PPC::BCDCPSGN_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 181 /* bcdctn */, PPC::BCDCTN_rec, Convert__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC }, },
  { 188 /* bcdctsq */, PPC::BCDCTSQ_rec, Convert__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC }, },
  { 196 /* bcdctz */, PPC::BCDCTZ_rec, Convert__RegVRRC1_1__RegVRRC1_2__U1Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_U1Imm }, },
  { 203 /* bcds */, PPC::BCDS_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__U1Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_U1Imm }, },
  { 208 /* bcdsetsgn */, PPC::BCDSETSGN_rec, Convert__RegVRRC1_1__RegVRRC1_2__U1Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_U1Imm }, },
  { 218 /* bcdsr */, PPC::BCDSR_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__U1Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_U1Imm }, },
  { 224 /* bcdtrunc */, PPC::BCDTRUNC_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__U1Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_U1Imm }, },
  { 233 /* bcdus */, PPC::BCDUS_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 239 /* bcdutrunc */, PPC::BCDUTRUNC_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 249 /* bcl */, PPC::gBCL, Convert__U5Imm1_0__RegCRBITRC1_1__CondBr1_2, AMFBS_None, { MCK_U5Imm, MCK_RegCRBITRC, MCK_CondBr }, },
  { 249 /* bcl */, PPC::gBCLat, Convert__U5Imm1_1__ATBitsAsHint1_0__RegCRBITRC1_2__CondBr1_3, AMFBS_None, { MCK_ATBitsAsHint, MCK_U5Imm, MCK_RegCRBITRC, MCK_CondBr }, },
  { 253 /* bcl+ */, PPC::gBCLat, Convert__U5Imm1_0__imm_95_3__RegCRBITRC1_1__CondBr1_2, AMFBS_None, { MCK_U5Imm, MCK_RegCRBITRC, MCK_CondBr }, },
  { 258 /* bcl- */, PPC::gBCLat, Convert__U5Imm1_0__imm_95_2__RegCRBITRC1_1__CondBr1_2, AMFBS_None, { MCK_U5Imm, MCK_RegCRBITRC, MCK_CondBr }, },
  { 263 /* bcla */, PPC::gBCLA, Convert__U5Imm1_0__RegCRBITRC1_1__CondBr1_2, AMFBS_None, { MCK_U5Imm, MCK_RegCRBITRC, MCK_CondBr }, },
  { 263 /* bcla */, PPC::gBCLAat, Convert__U5Imm1_1__ATBitsAsHint1_0__RegCRBITRC1_2__CondBr1_3, AMFBS_None, { MCK_ATBitsAsHint, MCK_U5Imm, MCK_RegCRBITRC, MCK_CondBr }, },
  { 268 /* bcla+ */, PPC::gBCLAat, Convert__U5Imm1_0__imm_95_3__RegCRBITRC1_1__CondBr1_2, AMFBS_None, { MCK_U5Imm, MCK_RegCRBITRC, MCK_CondBr }, },
  { 274 /* bcla- */, PPC::gBCLAat, Convert__U5Imm1_0__imm_95_2__RegCRBITRC1_1__CondBr1_2, AMFBS_None, { MCK_U5Imm, MCK_RegCRBITRC, MCK_CondBr }, },
  { 280 /* bclr */, PPC::gBCLR, Convert__U5Imm1_0__RegCRBITRC1_1__imm_95_0, AMFBS_None, { MCK_U5Imm, MCK_RegCRBITRC }, },
  { 280 /* bclr */, PPC::gBCLR, Convert__U5Imm1_0__RegCRBITRC1_1__Imm1_2, AMFBS_None, { MCK_U5Imm, MCK_RegCRBITRC, MCK_Imm }, },
  { 285 /* bclrl */, PPC::gBCLRL, Convert__U5Imm1_0__RegCRBITRC1_1__imm_95_0, AMFBS_None, { MCK_U5Imm, MCK_RegCRBITRC }, },
  { 285 /* bclrl */, PPC::gBCLRL, Convert__U5Imm1_0__RegCRBITRC1_1__Imm1_2, AMFBS_None, { MCK_U5Imm, MCK_RegCRBITRC, MCK_Imm }, },
  { 291 /* bctr */, PPC::BCTR, Convert_NoOperands, AMFBS_None, {  }, },
  { 296 /* bctrl */, PPC::BCTRL, Convert_NoOperands, AMFBS_None, {  }, },
  { 302 /* bdnz */, PPC::BDNZ, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 307 /* bdnz+ */, PPC::BDNZp, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 313 /* bdnz- */, PPC::BDNZm, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 319 /* bdnza */, PPC::BDNZA, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 325 /* bdnza+ */, PPC::BDNZAp, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 332 /* bdnza- */, PPC::BDNZAm, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 339 /* bdnzf */, PPC::gBC, Convert__imm_95_0__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 345 /* bdnzfa */, PPC::gBCA, Convert__imm_95_0__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 352 /* bdnzfl */, PPC::gBCL, Convert__imm_95_0__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 359 /* bdnzfla */, PPC::gBCLA, Convert__imm_95_0__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 367 /* bdnzflr */, PPC::gBCLR, Convert__imm_95_0__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 375 /* bdnzflrl */, PPC::gBCLRL, Convert__imm_95_0__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 384 /* bdnzl */, PPC::BDNZL, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 390 /* bdnzl+ */, PPC::BDNZLp, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 397 /* bdnzl- */, PPC::BDNZLm, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 404 /* bdnzla */, PPC::BDNZLA, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 411 /* bdnzla+ */, PPC::BDNZLAp, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 419 /* bdnzla- */, PPC::BDNZLAm, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 427 /* bdnzlr */, PPC::BDNZLR, Convert_NoOperands, AMFBS_None, {  }, },
  { 434 /* bdnzlr+ */, PPC::BDNZLRp, Convert_NoOperands, AMFBS_None, {  }, },
  { 442 /* bdnzlr- */, PPC::BDNZLRm, Convert_NoOperands, AMFBS_None, {  }, },
  { 450 /* bdnzlrl */, PPC::BDNZLRL, Convert_NoOperands, AMFBS_None, {  }, },
  { 458 /* bdnzlrl+ */, PPC::BDNZLRLp, Convert_NoOperands, AMFBS_None, {  }, },
  { 467 /* bdnzlrl- */, PPC::BDNZLRLm, Convert_NoOperands, AMFBS_None, {  }, },
  { 476 /* bdnzt */, PPC::gBC, Convert__imm_95_8__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 482 /* bdnzta */, PPC::gBCA, Convert__imm_95_8__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 489 /* bdnztl */, PPC::gBCL, Convert__imm_95_8__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 496 /* bdnztla */, PPC::gBCLA, Convert__imm_95_8__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 504 /* bdnztlr */, PPC::gBCLR, Convert__imm_95_8__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 512 /* bdnztlrl */, PPC::gBCLRL, Convert__imm_95_8__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 521 /* bdz */, PPC::BDZ, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 525 /* bdz+ */, PPC::BDZp, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 530 /* bdz- */, PPC::BDZm, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 535 /* bdza */, PPC::BDZA, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 540 /* bdza+ */, PPC::BDZAp, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 546 /* bdza- */, PPC::BDZAm, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 552 /* bdzf */, PPC::gBC, Convert__imm_95_2__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 557 /* bdzfa */, PPC::gBCA, Convert__imm_95_2__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 563 /* bdzfl */, PPC::gBCL, Convert__imm_95_2__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 569 /* bdzfla */, PPC::gBCLA, Convert__imm_95_2__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 576 /* bdzflr */, PPC::gBCLR, Convert__imm_95_2__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 583 /* bdzflrl */, PPC::gBCLRL, Convert__imm_95_2__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 591 /* bdzl */, PPC::BDZL, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 596 /* bdzl+ */, PPC::BDZLp, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 602 /* bdzl- */, PPC::BDZLm, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 608 /* bdzla */, PPC::BDZLA, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 614 /* bdzla+ */, PPC::BDZLAp, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 621 /* bdzla- */, PPC::BDZLAm, Convert__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 628 /* bdzlr */, PPC::BDZLR, Convert_NoOperands, AMFBS_None, {  }, },
  { 634 /* bdzlr+ */, PPC::BDZLRp, Convert_NoOperands, AMFBS_None, {  }, },
  { 641 /* bdzlr- */, PPC::BDZLRm, Convert_NoOperands, AMFBS_None, {  }, },
  { 648 /* bdzlrl */, PPC::BDZLRL, Convert_NoOperands, AMFBS_None, {  }, },
  { 655 /* bdzlrl+ */, PPC::BDZLRLp, Convert_NoOperands, AMFBS_None, {  }, },
  { 663 /* bdzlrl- */, PPC::BDZLRLm, Convert_NoOperands, AMFBS_None, {  }, },
  { 671 /* bdzt */, PPC::gBC, Convert__imm_95_10__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 676 /* bdzta */, PPC::gBCA, Convert__imm_95_10__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 682 /* bdztl */, PPC::gBCL, Convert__imm_95_10__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 688 /* bdztla */, PPC::gBCLA, Convert__imm_95_10__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 695 /* bdztlr */, PPC::gBCLR, Convert__imm_95_10__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 702 /* bdztlrl */, PPC::gBCLRL, Convert__imm_95_10__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 710 /* beq */, PPC::BCC, Convert__imm_95_76__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 710 /* beq */, PPC::BCC, Convert__imm_95_76__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 714 /* beq+ */, PPC::BCC, Convert__imm_95_79__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 714 /* beq+ */, PPC::BCC, Convert__imm_95_79__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 719 /* beq- */, PPC::BCC, Convert__imm_95_78__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 719 /* beq- */, PPC::BCC, Convert__imm_95_78__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 724 /* beqa */, PPC::BCCA, Convert__imm_95_76__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 724 /* beqa */, PPC::BCCA, Convert__imm_95_76__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 729 /* beqa+ */, PPC::BCCA, Convert__imm_95_79__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 729 /* beqa+ */, PPC::BCCA, Convert__imm_95_79__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 735 /* beqa- */, PPC::BCCA, Convert__imm_95_78__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 735 /* beqa- */, PPC::BCCA, Convert__imm_95_78__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 741 /* beqctr */, PPC::BCCCTR, Convert__imm_95_76__regCR0, AMFBS_None, {  }, },
  { 741 /* beqctr */, PPC::BCCCTR, Convert__imm_95_76__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 748 /* beqctr+ */, PPC::BCCCTR, Convert__imm_95_79__regCR0, AMFBS_None, {  }, },
  { 748 /* beqctr+ */, PPC::BCCCTR, Convert__imm_95_79__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 756 /* beqctr- */, PPC::BCCCTR, Convert__imm_95_78__regCR0, AMFBS_None, {  }, },
  { 756 /* beqctr- */, PPC::BCCCTR, Convert__imm_95_78__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 764 /* beqctrl */, PPC::BCCCTRL, Convert__imm_95_76__regCR0, AMFBS_None, {  }, },
  { 764 /* beqctrl */, PPC::BCCCTRL, Convert__imm_95_76__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 772 /* beqctrl+ */, PPC::BCCCTRL, Convert__imm_95_79__regCR0, AMFBS_None, {  }, },
  { 772 /* beqctrl+ */, PPC::BCCCTRL, Convert__imm_95_79__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 781 /* beqctrl- */, PPC::BCCCTRL, Convert__imm_95_78__regCR0, AMFBS_None, {  }, },
  { 781 /* beqctrl- */, PPC::BCCCTRL, Convert__imm_95_78__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 790 /* beql */, PPC::BCCL, Convert__imm_95_76__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 790 /* beql */, PPC::BCCL, Convert__imm_95_76__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 795 /* beql+ */, PPC::BCCL, Convert__imm_95_79__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 795 /* beql+ */, PPC::BCCL, Convert__imm_95_79__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 801 /* beql- */, PPC::BCCL, Convert__imm_95_78__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 801 /* beql- */, PPC::BCCL, Convert__imm_95_78__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 807 /* beqla */, PPC::BCCLA, Convert__imm_95_76__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 807 /* beqla */, PPC::BCCLA, Convert__imm_95_76__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 813 /* beqla+ */, PPC::BCCLA, Convert__imm_95_79__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 813 /* beqla+ */, PPC::BCCLA, Convert__imm_95_79__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 820 /* beqla- */, PPC::BCCLA, Convert__imm_95_78__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 820 /* beqla- */, PPC::BCCLA, Convert__imm_95_78__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 827 /* beqlr */, PPC::BCCLR, Convert__imm_95_76__regCR0, AMFBS_None, {  }, },
  { 827 /* beqlr */, PPC::BCCLR, Convert__imm_95_76__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 833 /* beqlr+ */, PPC::BCCLR, Convert__imm_95_79__regCR0, AMFBS_None, {  }, },
  { 833 /* beqlr+ */, PPC::BCCLR, Convert__imm_95_79__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 840 /* beqlr- */, PPC::BCCLR, Convert__imm_95_78__regCR0, AMFBS_None, {  }, },
  { 840 /* beqlr- */, PPC::BCCLR, Convert__imm_95_78__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 847 /* beqlrl */, PPC::BCCLRL, Convert__imm_95_76__regCR0, AMFBS_None, {  }, },
  { 847 /* beqlrl */, PPC::BCCLRL, Convert__imm_95_76__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 854 /* beqlrl+ */, PPC::BCCLRL, Convert__imm_95_79__regCR0, AMFBS_None, {  }, },
  { 854 /* beqlrl+ */, PPC::BCCLRL, Convert__imm_95_79__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 862 /* beqlrl- */, PPC::BCCLRL, Convert__imm_95_78__regCR0, AMFBS_None, {  }, },
  { 862 /* beqlrl- */, PPC::BCCLRL, Convert__imm_95_78__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 870 /* bf */, PPC::gBC, Convert__imm_95_4__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 873 /* bf+ */, PPC::gBC, Convert__imm_95_7__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 877 /* bf- */, PPC::gBC, Convert__imm_95_6__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 881 /* bfa */, PPC::gBCA, Convert__imm_95_4__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 885 /* bfa+ */, PPC::gBCA, Convert__imm_95_7__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 890 /* bfa- */, PPC::gBCA, Convert__imm_95_6__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 895 /* bfctr */, PPC::gBCCTR, Convert__imm_95_4__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 901 /* bfctr+ */, PPC::gBCCTR, Convert__imm_95_7__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 908 /* bfctr- */, PPC::gBCCTR, Convert__imm_95_6__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 915 /* bfctrl */, PPC::gBCCTRL, Convert__imm_95_4__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 922 /* bfctrl+ */, PPC::gBCCTRL, Convert__imm_95_7__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 930 /* bfctrl- */, PPC::gBCCTRL, Convert__imm_95_6__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 938 /* bfl */, PPC::gBCL, Convert__imm_95_4__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 942 /* bfl+ */, PPC::gBCL, Convert__imm_95_7__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 947 /* bfl- */, PPC::gBCL, Convert__imm_95_6__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 952 /* bfla */, PPC::gBCLA, Convert__imm_95_4__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 957 /* bfla+ */, PPC::gBCLA, Convert__imm_95_7__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 963 /* bfla- */, PPC::gBCLA, Convert__imm_95_6__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 969 /* bflr */, PPC::gBCLR, Convert__imm_95_4__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 974 /* bflr+ */, PPC::gBCLR, Convert__imm_95_7__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 980 /* bflr- */, PPC::gBCLR, Convert__imm_95_6__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 986 /* bflrl */, PPC::gBCLRL, Convert__imm_95_4__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 992 /* bflrl+ */, PPC::gBCLRL, Convert__imm_95_7__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 999 /* bflrl- */, PPC::gBCLRL, Convert__imm_95_6__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 1006 /* bge */, PPC::BCC, Convert__imm_95_4__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1006 /* bge */, PPC::BCC, Convert__imm_95_4__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1010 /* bge+ */, PPC::BCC, Convert__imm_95_7__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1010 /* bge+ */, PPC::BCC, Convert__imm_95_7__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1015 /* bge- */, PPC::BCC, Convert__imm_95_6__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1015 /* bge- */, PPC::BCC, Convert__imm_95_6__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1020 /* bgea */, PPC::BCCA, Convert__imm_95_4__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1020 /* bgea */, PPC::BCCA, Convert__imm_95_4__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1025 /* bgea+ */, PPC::BCCA, Convert__imm_95_7__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1025 /* bgea+ */, PPC::BCCA, Convert__imm_95_7__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1031 /* bgea- */, PPC::BCCA, Convert__imm_95_6__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1031 /* bgea- */, PPC::BCCA, Convert__imm_95_6__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1037 /* bgectr */, PPC::BCCCTR, Convert__imm_95_4__regCR0, AMFBS_None, {  }, },
  { 1037 /* bgectr */, PPC::BCCCTR, Convert__imm_95_4__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1044 /* bgectr+ */, PPC::BCCCTR, Convert__imm_95_7__regCR0, AMFBS_None, {  }, },
  { 1044 /* bgectr+ */, PPC::BCCCTR, Convert__imm_95_7__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1052 /* bgectr- */, PPC::BCCCTR, Convert__imm_95_6__regCR0, AMFBS_None, {  }, },
  { 1052 /* bgectr- */, PPC::BCCCTR, Convert__imm_95_6__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1060 /* bgectrl */, PPC::BCCCTRL, Convert__imm_95_4__regCR0, AMFBS_None, {  }, },
  { 1060 /* bgectrl */, PPC::BCCCTRL, Convert__imm_95_4__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1068 /* bgectrl+ */, PPC::BCCCTRL, Convert__imm_95_7__regCR0, AMFBS_None, {  }, },
  { 1068 /* bgectrl+ */, PPC::BCCCTRL, Convert__imm_95_7__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1077 /* bgectrl- */, PPC::BCCCTRL, Convert__imm_95_6__regCR0, AMFBS_None, {  }, },
  { 1077 /* bgectrl- */, PPC::BCCCTRL, Convert__imm_95_6__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1086 /* bgel */, PPC::BCCL, Convert__imm_95_4__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1086 /* bgel */, PPC::BCCL, Convert__imm_95_4__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1091 /* bgel+ */, PPC::BCCL, Convert__imm_95_7__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1091 /* bgel+ */, PPC::BCCL, Convert__imm_95_7__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1097 /* bgel- */, PPC::BCCL, Convert__imm_95_6__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1097 /* bgel- */, PPC::BCCL, Convert__imm_95_6__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1103 /* bgela */, PPC::BCCLA, Convert__imm_95_4__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1103 /* bgela */, PPC::BCCLA, Convert__imm_95_4__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1109 /* bgela+ */, PPC::BCCLA, Convert__imm_95_7__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1109 /* bgela+ */, PPC::BCCLA, Convert__imm_95_7__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1116 /* bgela- */, PPC::BCCLA, Convert__imm_95_6__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1116 /* bgela- */, PPC::BCCLA, Convert__imm_95_6__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1123 /* bgelr */, PPC::BCCLR, Convert__imm_95_4__regCR0, AMFBS_None, {  }, },
  { 1123 /* bgelr */, PPC::BCCLR, Convert__imm_95_4__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1129 /* bgelr+ */, PPC::BCCLR, Convert__imm_95_7__regCR0, AMFBS_None, {  }, },
  { 1129 /* bgelr+ */, PPC::BCCLR, Convert__imm_95_7__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1136 /* bgelr- */, PPC::BCCLR, Convert__imm_95_6__regCR0, AMFBS_None, {  }, },
  { 1136 /* bgelr- */, PPC::BCCLR, Convert__imm_95_6__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1143 /* bgelrl */, PPC::BCCLRL, Convert__imm_95_4__regCR0, AMFBS_None, {  }, },
  { 1143 /* bgelrl */, PPC::BCCLRL, Convert__imm_95_4__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1150 /* bgelrl+ */, PPC::BCCLRL, Convert__imm_95_7__regCR0, AMFBS_None, {  }, },
  { 1150 /* bgelrl+ */, PPC::BCCLRL, Convert__imm_95_7__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1158 /* bgelrl- */, PPC::BCCLRL, Convert__imm_95_6__regCR0, AMFBS_None, {  }, },
  { 1158 /* bgelrl- */, PPC::BCCLRL, Convert__imm_95_6__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1166 /* bgt */, PPC::BCC, Convert__imm_95_44__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1166 /* bgt */, PPC::BCC, Convert__imm_95_44__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1170 /* bgt+ */, PPC::BCC, Convert__imm_95_47__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1170 /* bgt+ */, PPC::BCC, Convert__imm_95_47__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1175 /* bgt- */, PPC::BCC, Convert__imm_95_46__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1175 /* bgt- */, PPC::BCC, Convert__imm_95_46__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1180 /* bgta */, PPC::BCCA, Convert__imm_95_44__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1180 /* bgta */, PPC::BCCA, Convert__imm_95_44__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1185 /* bgta+ */, PPC::BCCA, Convert__imm_95_47__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1185 /* bgta+ */, PPC::BCCA, Convert__imm_95_47__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1191 /* bgta- */, PPC::BCCA, Convert__imm_95_46__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1191 /* bgta- */, PPC::BCCA, Convert__imm_95_46__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1197 /* bgtctr */, PPC::BCCCTR, Convert__imm_95_44__regCR0, AMFBS_None, {  }, },
  { 1197 /* bgtctr */, PPC::BCCCTR, Convert__imm_95_44__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1204 /* bgtctr+ */, PPC::BCCCTR, Convert__imm_95_47__regCR0, AMFBS_None, {  }, },
  { 1204 /* bgtctr+ */, PPC::BCCCTR, Convert__imm_95_47__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1212 /* bgtctr- */, PPC::BCCCTR, Convert__imm_95_46__regCR0, AMFBS_None, {  }, },
  { 1212 /* bgtctr- */, PPC::BCCCTR, Convert__imm_95_46__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1220 /* bgtctrl */, PPC::BCCCTRL, Convert__imm_95_44__regCR0, AMFBS_None, {  }, },
  { 1220 /* bgtctrl */, PPC::BCCCTRL, Convert__imm_95_44__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1228 /* bgtctrl+ */, PPC::BCCCTRL, Convert__imm_95_47__regCR0, AMFBS_None, {  }, },
  { 1228 /* bgtctrl+ */, PPC::BCCCTRL, Convert__imm_95_47__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1237 /* bgtctrl- */, PPC::BCCCTRL, Convert__imm_95_46__regCR0, AMFBS_None, {  }, },
  { 1237 /* bgtctrl- */, PPC::BCCCTRL, Convert__imm_95_46__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1246 /* bgtl */, PPC::BCCL, Convert__imm_95_44__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1246 /* bgtl */, PPC::BCCL, Convert__imm_95_44__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1251 /* bgtl+ */, PPC::BCCL, Convert__imm_95_47__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1251 /* bgtl+ */, PPC::BCCL, Convert__imm_95_47__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1257 /* bgtl- */, PPC::BCCL, Convert__imm_95_46__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1257 /* bgtl- */, PPC::BCCL, Convert__imm_95_46__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1263 /* bgtla */, PPC::BCCLA, Convert__imm_95_44__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1263 /* bgtla */, PPC::BCCLA, Convert__imm_95_44__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1269 /* bgtla+ */, PPC::BCCLA, Convert__imm_95_47__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1269 /* bgtla+ */, PPC::BCCLA, Convert__imm_95_47__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1276 /* bgtla- */, PPC::BCCLA, Convert__imm_95_46__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1276 /* bgtla- */, PPC::BCCLA, Convert__imm_95_46__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1283 /* bgtlr */, PPC::BCCLR, Convert__imm_95_44__regCR0, AMFBS_None, {  }, },
  { 1283 /* bgtlr */, PPC::BCCLR, Convert__imm_95_44__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1289 /* bgtlr+ */, PPC::BCCLR, Convert__imm_95_47__regCR0, AMFBS_None, {  }, },
  { 1289 /* bgtlr+ */, PPC::BCCLR, Convert__imm_95_47__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1296 /* bgtlr- */, PPC::BCCLR, Convert__imm_95_46__regCR0, AMFBS_None, {  }, },
  { 1296 /* bgtlr- */, PPC::BCCLR, Convert__imm_95_46__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1303 /* bgtlrl */, PPC::BCCLRL, Convert__imm_95_44__regCR0, AMFBS_None, {  }, },
  { 1303 /* bgtlrl */, PPC::BCCLRL, Convert__imm_95_44__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1310 /* bgtlrl+ */, PPC::BCCLRL, Convert__imm_95_47__regCR0, AMFBS_None, {  }, },
  { 1310 /* bgtlrl+ */, PPC::BCCLRL, Convert__imm_95_47__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1318 /* bgtlrl- */, PPC::BCCLRL, Convert__imm_95_46__regCR0, AMFBS_None, {  }, },
  { 1318 /* bgtlrl- */, PPC::BCCLRL, Convert__imm_95_46__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1326 /* bl */, PPC::BL, Convert__DirectBr1_0, AMFBS_None, { MCK_DirectBr }, },
  { 1326 /* bl */, PPC::BL8_TLS_, Convert__DirectBr1_0__Imm1_1, AMFBS_None, { MCK_DirectBr, MCK_Imm }, },
  { 1329 /* bla */, PPC::BLA, Convert__DirectBr1_0, AMFBS_None, { MCK_DirectBr }, },
  { 1333 /* ble */, PPC::BCC, Convert__imm_95_36__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1333 /* ble */, PPC::BCC, Convert__imm_95_36__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1337 /* ble+ */, PPC::BCC, Convert__imm_95_39__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1337 /* ble+ */, PPC::BCC, Convert__imm_95_39__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1342 /* ble- */, PPC::BCC, Convert__imm_95_38__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1342 /* ble- */, PPC::BCC, Convert__imm_95_38__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1347 /* blea */, PPC::BCCA, Convert__imm_95_36__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1347 /* blea */, PPC::BCCA, Convert__imm_95_36__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1352 /* blea+ */, PPC::BCCA, Convert__imm_95_39__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1352 /* blea+ */, PPC::BCCA, Convert__imm_95_39__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1358 /* blea- */, PPC::BCCA, Convert__imm_95_38__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1358 /* blea- */, PPC::BCCA, Convert__imm_95_38__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1364 /* blectr */, PPC::BCCCTR, Convert__imm_95_36__regCR0, AMFBS_None, {  }, },
  { 1364 /* blectr */, PPC::BCCCTR, Convert__imm_95_36__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1371 /* blectr+ */, PPC::BCCCTR, Convert__imm_95_39__regCR0, AMFBS_None, {  }, },
  { 1371 /* blectr+ */, PPC::BCCCTR, Convert__imm_95_39__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1379 /* blectr- */, PPC::BCCCTR, Convert__imm_95_38__regCR0, AMFBS_None, {  }, },
  { 1379 /* blectr- */, PPC::BCCCTR, Convert__imm_95_38__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1387 /* blectrl */, PPC::BCCCTRL, Convert__imm_95_36__regCR0, AMFBS_None, {  }, },
  { 1387 /* blectrl */, PPC::BCCCTRL, Convert__imm_95_36__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1395 /* blectrl+ */, PPC::BCCCTRL, Convert__imm_95_39__regCR0, AMFBS_None, {  }, },
  { 1395 /* blectrl+ */, PPC::BCCCTRL, Convert__imm_95_39__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1404 /* blectrl- */, PPC::BCCCTRL, Convert__imm_95_38__regCR0, AMFBS_None, {  }, },
  { 1404 /* blectrl- */, PPC::BCCCTRL, Convert__imm_95_38__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1413 /* blel */, PPC::BCCL, Convert__imm_95_36__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1413 /* blel */, PPC::BCCL, Convert__imm_95_36__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1418 /* blel+ */, PPC::BCCL, Convert__imm_95_39__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1418 /* blel+ */, PPC::BCCL, Convert__imm_95_39__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1424 /* blel- */, PPC::BCCL, Convert__imm_95_38__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1424 /* blel- */, PPC::BCCL, Convert__imm_95_38__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1430 /* blela */, PPC::BCCLA, Convert__imm_95_36__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1430 /* blela */, PPC::BCCLA, Convert__imm_95_36__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1436 /* blela+ */, PPC::BCCLA, Convert__imm_95_39__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1436 /* blela+ */, PPC::BCCLA, Convert__imm_95_39__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1443 /* blela- */, PPC::BCCLA, Convert__imm_95_38__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1443 /* blela- */, PPC::BCCLA, Convert__imm_95_38__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1450 /* blelr */, PPC::BCCLR, Convert__imm_95_36__regCR0, AMFBS_None, {  }, },
  { 1450 /* blelr */, PPC::BCCLR, Convert__imm_95_36__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1456 /* blelr+ */, PPC::BCCLR, Convert__imm_95_39__regCR0, AMFBS_None, {  }, },
  { 1456 /* blelr+ */, PPC::BCCLR, Convert__imm_95_39__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1463 /* blelr- */, PPC::BCCLR, Convert__imm_95_38__regCR0, AMFBS_None, {  }, },
  { 1463 /* blelr- */, PPC::BCCLR, Convert__imm_95_38__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1470 /* blelrl */, PPC::BCCLRL, Convert__imm_95_36__regCR0, AMFBS_None, {  }, },
  { 1470 /* blelrl */, PPC::BCCLRL, Convert__imm_95_36__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1477 /* blelrl+ */, PPC::BCCLRL, Convert__imm_95_39__regCR0, AMFBS_None, {  }, },
  { 1477 /* blelrl+ */, PPC::BCCLRL, Convert__imm_95_39__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1485 /* blelrl- */, PPC::BCCLRL, Convert__imm_95_38__regCR0, AMFBS_None, {  }, },
  { 1485 /* blelrl- */, PPC::BCCLRL, Convert__imm_95_38__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1493 /* blr */, PPC::BLR, Convert_NoOperands, AMFBS_None, {  }, },
  { 1497 /* blrl */, PPC::BLRL, Convert_NoOperands, AMFBS_None, {  }, },
  { 1502 /* blt */, PPC::BCC, Convert__imm_95_12__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1502 /* blt */, PPC::BCC, Convert__imm_95_12__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1506 /* blt+ */, PPC::BCC, Convert__imm_95_15__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1506 /* blt+ */, PPC::BCC, Convert__imm_95_15__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1511 /* blt- */, PPC::BCC, Convert__imm_95_14__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1511 /* blt- */, PPC::BCC, Convert__imm_95_14__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1516 /* blta */, PPC::BCCA, Convert__imm_95_12__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1516 /* blta */, PPC::BCCA, Convert__imm_95_12__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1521 /* blta+ */, PPC::BCCA, Convert__imm_95_15__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1521 /* blta+ */, PPC::BCCA, Convert__imm_95_15__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1527 /* blta- */, PPC::BCCA, Convert__imm_95_14__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1527 /* blta- */, PPC::BCCA, Convert__imm_95_14__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1533 /* bltctr */, PPC::BCCCTR, Convert__imm_95_12__regCR0, AMFBS_None, {  }, },
  { 1533 /* bltctr */, PPC::BCCCTR, Convert__imm_95_12__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1540 /* bltctr+ */, PPC::BCCCTR, Convert__imm_95_15__regCR0, AMFBS_None, {  }, },
  { 1540 /* bltctr+ */, PPC::BCCCTR, Convert__imm_95_15__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1548 /* bltctr- */, PPC::BCCCTR, Convert__imm_95_14__regCR0, AMFBS_None, {  }, },
  { 1548 /* bltctr- */, PPC::BCCCTR, Convert__imm_95_14__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1556 /* bltctrl */, PPC::BCCCTRL, Convert__imm_95_12__regCR0, AMFBS_None, {  }, },
  { 1556 /* bltctrl */, PPC::BCCCTRL, Convert__imm_95_12__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1564 /* bltctrl+ */, PPC::BCCCTRL, Convert__imm_95_15__regCR0, AMFBS_None, {  }, },
  { 1564 /* bltctrl+ */, PPC::BCCCTRL, Convert__imm_95_15__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1573 /* bltctrl- */, PPC::BCCCTRL, Convert__imm_95_14__regCR0, AMFBS_None, {  }, },
  { 1573 /* bltctrl- */, PPC::BCCCTRL, Convert__imm_95_14__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1582 /* bltl */, PPC::BCCL, Convert__imm_95_12__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1582 /* bltl */, PPC::BCCL, Convert__imm_95_12__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1587 /* bltl+ */, PPC::BCCL, Convert__imm_95_15__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1587 /* bltl+ */, PPC::BCCL, Convert__imm_95_15__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1593 /* bltl- */, PPC::BCCL, Convert__imm_95_14__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1593 /* bltl- */, PPC::BCCL, Convert__imm_95_14__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1599 /* bltla */, PPC::BCCLA, Convert__imm_95_12__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1599 /* bltla */, PPC::BCCLA, Convert__imm_95_12__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1605 /* bltla+ */, PPC::BCCLA, Convert__imm_95_15__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1605 /* bltla+ */, PPC::BCCLA, Convert__imm_95_15__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1612 /* bltla- */, PPC::BCCLA, Convert__imm_95_14__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1612 /* bltla- */, PPC::BCCLA, Convert__imm_95_14__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1619 /* bltlr */, PPC::BCCLR, Convert__imm_95_12__regCR0, AMFBS_None, {  }, },
  { 1619 /* bltlr */, PPC::BCCLR, Convert__imm_95_12__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1625 /* bltlr+ */, PPC::BCCLR, Convert__imm_95_15__regCR0, AMFBS_None, {  }, },
  { 1625 /* bltlr+ */, PPC::BCCLR, Convert__imm_95_15__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1632 /* bltlr- */, PPC::BCCLR, Convert__imm_95_14__regCR0, AMFBS_None, {  }, },
  { 1632 /* bltlr- */, PPC::BCCLR, Convert__imm_95_14__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1639 /* bltlrl */, PPC::BCCLRL, Convert__imm_95_12__regCR0, AMFBS_None, {  }, },
  { 1639 /* bltlrl */, PPC::BCCLRL, Convert__imm_95_12__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1646 /* bltlrl+ */, PPC::BCCLRL, Convert__imm_95_15__regCR0, AMFBS_None, {  }, },
  { 1646 /* bltlrl+ */, PPC::BCCLRL, Convert__imm_95_15__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1654 /* bltlrl- */, PPC::BCCLRL, Convert__imm_95_14__regCR0, AMFBS_None, {  }, },
  { 1654 /* bltlrl- */, PPC::BCCLRL, Convert__imm_95_14__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1662 /* bne */, PPC::BCC, Convert__imm_95_68__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1662 /* bne */, PPC::BCC, Convert__imm_95_68__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1666 /* bne+ */, PPC::BCC, Convert__imm_95_71__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1666 /* bne+ */, PPC::BCC, Convert__imm_95_71__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1671 /* bne- */, PPC::BCC, Convert__imm_95_70__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1671 /* bne- */, PPC::BCC, Convert__imm_95_70__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1676 /* bnea */, PPC::BCCA, Convert__imm_95_68__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1676 /* bnea */, PPC::BCCA, Convert__imm_95_68__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1681 /* bnea+ */, PPC::BCCA, Convert__imm_95_71__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1681 /* bnea+ */, PPC::BCCA, Convert__imm_95_71__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1687 /* bnea- */, PPC::BCCA, Convert__imm_95_70__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1687 /* bnea- */, PPC::BCCA, Convert__imm_95_70__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1693 /* bnectr */, PPC::BCCCTR, Convert__imm_95_68__regCR0, AMFBS_None, {  }, },
  { 1693 /* bnectr */, PPC::BCCCTR, Convert__imm_95_68__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1700 /* bnectr+ */, PPC::BCCCTR, Convert__imm_95_71__regCR0, AMFBS_None, {  }, },
  { 1700 /* bnectr+ */, PPC::BCCCTR, Convert__imm_95_71__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1708 /* bnectr- */, PPC::BCCCTR, Convert__imm_95_70__regCR0, AMFBS_None, {  }, },
  { 1708 /* bnectr- */, PPC::BCCCTR, Convert__imm_95_70__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1716 /* bnectrl */, PPC::BCCCTRL, Convert__imm_95_68__regCR0, AMFBS_None, {  }, },
  { 1716 /* bnectrl */, PPC::BCCCTRL, Convert__imm_95_68__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1724 /* bnectrl+ */, PPC::BCCCTRL, Convert__imm_95_71__regCR0, AMFBS_None, {  }, },
  { 1724 /* bnectrl+ */, PPC::BCCCTRL, Convert__imm_95_71__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1733 /* bnectrl- */, PPC::BCCCTRL, Convert__imm_95_70__regCR0, AMFBS_None, {  }, },
  { 1733 /* bnectrl- */, PPC::BCCCTRL, Convert__imm_95_70__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1742 /* bnel */, PPC::BCCL, Convert__imm_95_68__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1742 /* bnel */, PPC::BCCL, Convert__imm_95_68__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1747 /* bnel+ */, PPC::BCCL, Convert__imm_95_71__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1747 /* bnel+ */, PPC::BCCL, Convert__imm_95_71__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1753 /* bnel- */, PPC::BCCL, Convert__imm_95_70__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1753 /* bnel- */, PPC::BCCL, Convert__imm_95_70__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1759 /* bnela */, PPC::BCCLA, Convert__imm_95_68__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1759 /* bnela */, PPC::BCCLA, Convert__imm_95_68__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1765 /* bnela+ */, PPC::BCCLA, Convert__imm_95_71__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1765 /* bnela+ */, PPC::BCCLA, Convert__imm_95_71__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1772 /* bnela- */, PPC::BCCLA, Convert__imm_95_70__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1772 /* bnela- */, PPC::BCCLA, Convert__imm_95_70__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1779 /* bnelr */, PPC::BCCLR, Convert__imm_95_68__regCR0, AMFBS_None, {  }, },
  { 1779 /* bnelr */, PPC::BCCLR, Convert__imm_95_68__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1785 /* bnelr+ */, PPC::BCCLR, Convert__imm_95_71__regCR0, AMFBS_None, {  }, },
  { 1785 /* bnelr+ */, PPC::BCCLR, Convert__imm_95_71__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1792 /* bnelr- */, PPC::BCCLR, Convert__imm_95_70__regCR0, AMFBS_None, {  }, },
  { 1792 /* bnelr- */, PPC::BCCLR, Convert__imm_95_70__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1799 /* bnelrl */, PPC::BCCLRL, Convert__imm_95_68__regCR0, AMFBS_None, {  }, },
  { 1799 /* bnelrl */, PPC::BCCLRL, Convert__imm_95_68__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1806 /* bnelrl+ */, PPC::BCCLRL, Convert__imm_95_71__regCR0, AMFBS_None, {  }, },
  { 1806 /* bnelrl+ */, PPC::BCCLRL, Convert__imm_95_71__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1814 /* bnelrl- */, PPC::BCCLRL, Convert__imm_95_70__regCR0, AMFBS_None, {  }, },
  { 1814 /* bnelrl- */, PPC::BCCLRL, Convert__imm_95_70__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1822 /* bng */, PPC::BCC, Convert__imm_95_36__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1822 /* bng */, PPC::BCC, Convert__imm_95_36__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1826 /* bng+ */, PPC::BCC, Convert__imm_95_39__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1826 /* bng+ */, PPC::BCC, Convert__imm_95_39__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1831 /* bng- */, PPC::BCC, Convert__imm_95_38__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1831 /* bng- */, PPC::BCC, Convert__imm_95_38__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1836 /* bnga */, PPC::BCCA, Convert__imm_95_36__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1836 /* bnga */, PPC::BCCA, Convert__imm_95_36__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1841 /* bnga+ */, PPC::BCCA, Convert__imm_95_39__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1841 /* bnga+ */, PPC::BCCA, Convert__imm_95_39__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1847 /* bnga- */, PPC::BCCA, Convert__imm_95_38__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1847 /* bnga- */, PPC::BCCA, Convert__imm_95_38__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1853 /* bngctr */, PPC::BCCCTR, Convert__imm_95_36__regCR0, AMFBS_None, {  }, },
  { 1853 /* bngctr */, PPC::BCCCTR, Convert__imm_95_36__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1860 /* bngctr+ */, PPC::BCCCTR, Convert__imm_95_39__regCR0, AMFBS_None, {  }, },
  { 1860 /* bngctr+ */, PPC::BCCCTR, Convert__imm_95_39__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1868 /* bngctr- */, PPC::BCCCTR, Convert__imm_95_38__regCR0, AMFBS_None, {  }, },
  { 1868 /* bngctr- */, PPC::BCCCTR, Convert__imm_95_38__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1876 /* bngctrl */, PPC::BCCCTRL, Convert__imm_95_36__regCR0, AMFBS_None, {  }, },
  { 1876 /* bngctrl */, PPC::BCCCTRL, Convert__imm_95_36__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1884 /* bngctrl+ */, PPC::BCCCTRL, Convert__imm_95_39__regCR0, AMFBS_None, {  }, },
  { 1884 /* bngctrl+ */, PPC::BCCCTRL, Convert__imm_95_39__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1893 /* bngctrl- */, PPC::BCCCTRL, Convert__imm_95_38__regCR0, AMFBS_None, {  }, },
  { 1893 /* bngctrl- */, PPC::BCCCTRL, Convert__imm_95_38__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1902 /* bngl */, PPC::BCCL, Convert__imm_95_36__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1902 /* bngl */, PPC::BCCL, Convert__imm_95_36__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1907 /* bngl+ */, PPC::BCCL, Convert__imm_95_39__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1907 /* bngl+ */, PPC::BCCL, Convert__imm_95_39__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1913 /* bngl- */, PPC::BCCL, Convert__imm_95_38__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1913 /* bngl- */, PPC::BCCL, Convert__imm_95_38__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1919 /* bngla */, PPC::BCCLA, Convert__imm_95_36__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1919 /* bngla */, PPC::BCCLA, Convert__imm_95_36__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1925 /* bngla+ */, PPC::BCCLA, Convert__imm_95_39__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1925 /* bngla+ */, PPC::BCCLA, Convert__imm_95_39__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1932 /* bngla- */, PPC::BCCLA, Convert__imm_95_38__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1932 /* bngla- */, PPC::BCCLA, Convert__imm_95_38__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1939 /* bnglr */, PPC::BCCLR, Convert__imm_95_36__regCR0, AMFBS_None, {  }, },
  { 1939 /* bnglr */, PPC::BCCLR, Convert__imm_95_36__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1945 /* bnglr+ */, PPC::BCCLR, Convert__imm_95_39__regCR0, AMFBS_None, {  }, },
  { 1945 /* bnglr+ */, PPC::BCCLR, Convert__imm_95_39__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1952 /* bnglr- */, PPC::BCCLR, Convert__imm_95_38__regCR0, AMFBS_None, {  }, },
  { 1952 /* bnglr- */, PPC::BCCLR, Convert__imm_95_38__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1959 /* bnglrl */, PPC::BCCLRL, Convert__imm_95_36__regCR0, AMFBS_None, {  }, },
  { 1959 /* bnglrl */, PPC::BCCLRL, Convert__imm_95_36__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1966 /* bnglrl+ */, PPC::BCCLRL, Convert__imm_95_39__regCR0, AMFBS_None, {  }, },
  { 1966 /* bnglrl+ */, PPC::BCCLRL, Convert__imm_95_39__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1974 /* bnglrl- */, PPC::BCCLRL, Convert__imm_95_38__regCR0, AMFBS_None, {  }, },
  { 1974 /* bnglrl- */, PPC::BCCLRL, Convert__imm_95_38__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 1982 /* bnl */, PPC::BCC, Convert__imm_95_4__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1982 /* bnl */, PPC::BCC, Convert__imm_95_4__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1986 /* bnl+ */, PPC::BCC, Convert__imm_95_7__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1986 /* bnl+ */, PPC::BCC, Convert__imm_95_7__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1991 /* bnl- */, PPC::BCC, Convert__imm_95_6__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1991 /* bnl- */, PPC::BCC, Convert__imm_95_6__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 1996 /* bnla */, PPC::BCCA, Convert__imm_95_4__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 1996 /* bnla */, PPC::BCCA, Convert__imm_95_4__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2001 /* bnla+ */, PPC::BCCA, Convert__imm_95_7__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2001 /* bnla+ */, PPC::BCCA, Convert__imm_95_7__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2007 /* bnla- */, PPC::BCCA, Convert__imm_95_6__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2007 /* bnla- */, PPC::BCCA, Convert__imm_95_6__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2013 /* bnlctr */, PPC::BCCCTR, Convert__imm_95_4__regCR0, AMFBS_None, {  }, },
  { 2013 /* bnlctr */, PPC::BCCCTR, Convert__imm_95_4__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2020 /* bnlctr+ */, PPC::BCCCTR, Convert__imm_95_7__regCR0, AMFBS_None, {  }, },
  { 2020 /* bnlctr+ */, PPC::BCCCTR, Convert__imm_95_7__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2028 /* bnlctr- */, PPC::BCCCTR, Convert__imm_95_6__regCR0, AMFBS_None, {  }, },
  { 2028 /* bnlctr- */, PPC::BCCCTR, Convert__imm_95_6__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2036 /* bnlctrl */, PPC::BCCCTRL, Convert__imm_95_4__regCR0, AMFBS_None, {  }, },
  { 2036 /* bnlctrl */, PPC::BCCCTRL, Convert__imm_95_4__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2044 /* bnlctrl+ */, PPC::BCCCTRL, Convert__imm_95_7__regCR0, AMFBS_None, {  }, },
  { 2044 /* bnlctrl+ */, PPC::BCCCTRL, Convert__imm_95_7__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2053 /* bnlctrl- */, PPC::BCCCTRL, Convert__imm_95_6__regCR0, AMFBS_None, {  }, },
  { 2053 /* bnlctrl- */, PPC::BCCCTRL, Convert__imm_95_6__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2062 /* bnll */, PPC::BCCL, Convert__imm_95_4__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2062 /* bnll */, PPC::BCCL, Convert__imm_95_4__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2067 /* bnll+ */, PPC::BCCL, Convert__imm_95_7__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2067 /* bnll+ */, PPC::BCCL, Convert__imm_95_7__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2073 /* bnll- */, PPC::BCCL, Convert__imm_95_6__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2073 /* bnll- */, PPC::BCCL, Convert__imm_95_6__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2079 /* bnlla */, PPC::BCCLA, Convert__imm_95_4__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2079 /* bnlla */, PPC::BCCLA, Convert__imm_95_4__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2085 /* bnlla+ */, PPC::BCCLA, Convert__imm_95_7__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2085 /* bnlla+ */, PPC::BCCLA, Convert__imm_95_7__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2092 /* bnlla- */, PPC::BCCLA, Convert__imm_95_6__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2092 /* bnlla- */, PPC::BCCLA, Convert__imm_95_6__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2099 /* bnllr */, PPC::BCCLR, Convert__imm_95_4__regCR0, AMFBS_None, {  }, },
  { 2099 /* bnllr */, PPC::BCCLR, Convert__imm_95_4__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2105 /* bnllr+ */, PPC::BCCLR, Convert__imm_95_7__regCR0, AMFBS_None, {  }, },
  { 2105 /* bnllr+ */, PPC::BCCLR, Convert__imm_95_7__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2112 /* bnllr- */, PPC::BCCLR, Convert__imm_95_6__regCR0, AMFBS_None, {  }, },
  { 2112 /* bnllr- */, PPC::BCCLR, Convert__imm_95_6__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2119 /* bnllrl */, PPC::BCCLRL, Convert__imm_95_4__regCR0, AMFBS_None, {  }, },
  { 2119 /* bnllrl */, PPC::BCCLRL, Convert__imm_95_4__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2126 /* bnllrl+ */, PPC::BCCLRL, Convert__imm_95_7__regCR0, AMFBS_None, {  }, },
  { 2126 /* bnllrl+ */, PPC::BCCLRL, Convert__imm_95_7__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2134 /* bnllrl- */, PPC::BCCLRL, Convert__imm_95_6__regCR0, AMFBS_None, {  }, },
  { 2134 /* bnllrl- */, PPC::BCCLRL, Convert__imm_95_6__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2142 /* bns */, PPC::BCC, Convert__imm_95_100__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2142 /* bns */, PPC::BCC, Convert__imm_95_100__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2146 /* bns+ */, PPC::BCC, Convert__imm_95_103__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2146 /* bns+ */, PPC::BCC, Convert__imm_95_103__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2151 /* bns- */, PPC::BCC, Convert__imm_95_102__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2151 /* bns- */, PPC::BCC, Convert__imm_95_102__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2156 /* bnsa */, PPC::BCCA, Convert__imm_95_100__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2156 /* bnsa */, PPC::BCCA, Convert__imm_95_100__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2161 /* bnsa+ */, PPC::BCCA, Convert__imm_95_103__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2161 /* bnsa+ */, PPC::BCCA, Convert__imm_95_103__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2167 /* bnsa- */, PPC::BCCA, Convert__imm_95_102__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2167 /* bnsa- */, PPC::BCCA, Convert__imm_95_102__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2173 /* bnsctr */, PPC::BCCCTR, Convert__imm_95_100__regCR0, AMFBS_None, {  }, },
  { 2173 /* bnsctr */, PPC::BCCCTR, Convert__imm_95_100__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2180 /* bnsctr+ */, PPC::BCCCTR, Convert__imm_95_103__regCR0, AMFBS_None, {  }, },
  { 2180 /* bnsctr+ */, PPC::BCCCTR, Convert__imm_95_103__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2188 /* bnsctr- */, PPC::BCCCTR, Convert__imm_95_102__regCR0, AMFBS_None, {  }, },
  { 2188 /* bnsctr- */, PPC::BCCCTR, Convert__imm_95_102__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2196 /* bnsctrl */, PPC::BCCCTRL, Convert__imm_95_100__regCR0, AMFBS_None, {  }, },
  { 2196 /* bnsctrl */, PPC::BCCCTRL, Convert__imm_95_100__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2204 /* bnsctrl+ */, PPC::BCCCTRL, Convert__imm_95_103__regCR0, AMFBS_None, {  }, },
  { 2204 /* bnsctrl+ */, PPC::BCCCTRL, Convert__imm_95_103__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2213 /* bnsctrl- */, PPC::BCCCTRL, Convert__imm_95_102__regCR0, AMFBS_None, {  }, },
  { 2213 /* bnsctrl- */, PPC::BCCCTRL, Convert__imm_95_102__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2222 /* bnsl */, PPC::BCCL, Convert__imm_95_100__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2222 /* bnsl */, PPC::BCCL, Convert__imm_95_100__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2227 /* bnsl+ */, PPC::BCCL, Convert__imm_95_103__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2227 /* bnsl+ */, PPC::BCCL, Convert__imm_95_103__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2233 /* bnsl- */, PPC::BCCL, Convert__imm_95_102__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2233 /* bnsl- */, PPC::BCCL, Convert__imm_95_102__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2239 /* bnsla */, PPC::BCCLA, Convert__imm_95_100__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2239 /* bnsla */, PPC::BCCLA, Convert__imm_95_100__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2245 /* bnsla+ */, PPC::BCCLA, Convert__imm_95_103__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2245 /* bnsla+ */, PPC::BCCLA, Convert__imm_95_103__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2252 /* bnsla- */, PPC::BCCLA, Convert__imm_95_102__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2252 /* bnsla- */, PPC::BCCLA, Convert__imm_95_102__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2259 /* bnslr */, PPC::BCCLR, Convert__imm_95_100__regCR0, AMFBS_None, {  }, },
  { 2259 /* bnslr */, PPC::BCCLR, Convert__imm_95_100__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2265 /* bnslr+ */, PPC::BCCLR, Convert__imm_95_103__regCR0, AMFBS_None, {  }, },
  { 2265 /* bnslr+ */, PPC::BCCLR, Convert__imm_95_103__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2272 /* bnslr- */, PPC::BCCLR, Convert__imm_95_102__regCR0, AMFBS_None, {  }, },
  { 2272 /* bnslr- */, PPC::BCCLR, Convert__imm_95_102__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2279 /* bnslrl */, PPC::BCCLRL, Convert__imm_95_100__regCR0, AMFBS_None, {  }, },
  { 2279 /* bnslrl */, PPC::BCCLRL, Convert__imm_95_100__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2286 /* bnslrl+ */, PPC::BCCLRL, Convert__imm_95_103__regCR0, AMFBS_None, {  }, },
  { 2286 /* bnslrl+ */, PPC::BCCLRL, Convert__imm_95_103__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2294 /* bnslrl- */, PPC::BCCLRL, Convert__imm_95_102__regCR0, AMFBS_None, {  }, },
  { 2294 /* bnslrl- */, PPC::BCCLRL, Convert__imm_95_102__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2302 /* bnu */, PPC::BCC, Convert__imm_95_100__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2302 /* bnu */, PPC::BCC, Convert__imm_95_100__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2306 /* bnu+ */, PPC::BCC, Convert__imm_95_103__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2306 /* bnu+ */, PPC::BCC, Convert__imm_95_103__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2311 /* bnu- */, PPC::BCC, Convert__imm_95_102__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2311 /* bnu- */, PPC::BCC, Convert__imm_95_102__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2316 /* bnua */, PPC::BCCA, Convert__imm_95_100__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2316 /* bnua */, PPC::BCCA, Convert__imm_95_100__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2321 /* bnua+ */, PPC::BCCA, Convert__imm_95_103__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2321 /* bnua+ */, PPC::BCCA, Convert__imm_95_103__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2327 /* bnua- */, PPC::BCCA, Convert__imm_95_102__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2327 /* bnua- */, PPC::BCCA, Convert__imm_95_102__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2333 /* bnuctr */, PPC::BCCCTR, Convert__imm_95_100__regCR0, AMFBS_None, {  }, },
  { 2333 /* bnuctr */, PPC::BCCCTR, Convert__imm_95_100__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2340 /* bnuctr+ */, PPC::BCCCTR, Convert__imm_95_103__regCR0, AMFBS_None, {  }, },
  { 2340 /* bnuctr+ */, PPC::BCCCTR, Convert__imm_95_103__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2348 /* bnuctr- */, PPC::BCCCTR, Convert__imm_95_102__regCR0, AMFBS_None, {  }, },
  { 2348 /* bnuctr- */, PPC::BCCCTR, Convert__imm_95_102__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2356 /* bnuctrl */, PPC::BCCCTRL, Convert__imm_95_100__regCR0, AMFBS_None, {  }, },
  { 2356 /* bnuctrl */, PPC::BCCCTRL, Convert__imm_95_100__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2364 /* bnuctrl+ */, PPC::BCCCTRL, Convert__imm_95_103__regCR0, AMFBS_None, {  }, },
  { 2364 /* bnuctrl+ */, PPC::BCCCTRL, Convert__imm_95_103__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2373 /* bnuctrl- */, PPC::BCCCTRL, Convert__imm_95_102__regCR0, AMFBS_None, {  }, },
  { 2373 /* bnuctrl- */, PPC::BCCCTRL, Convert__imm_95_102__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2382 /* bnul */, PPC::BCCL, Convert__imm_95_100__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2382 /* bnul */, PPC::BCCL, Convert__imm_95_100__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2387 /* bnul+ */, PPC::BCCL, Convert__imm_95_103__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2387 /* bnul+ */, PPC::BCCL, Convert__imm_95_103__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2393 /* bnul- */, PPC::BCCL, Convert__imm_95_102__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2393 /* bnul- */, PPC::BCCL, Convert__imm_95_102__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2399 /* bnula */, PPC::BCCLA, Convert__imm_95_100__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2399 /* bnula */, PPC::BCCLA, Convert__imm_95_100__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2405 /* bnula+ */, PPC::BCCLA, Convert__imm_95_103__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2405 /* bnula+ */, PPC::BCCLA, Convert__imm_95_103__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2412 /* bnula- */, PPC::BCCLA, Convert__imm_95_102__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2412 /* bnula- */, PPC::BCCLA, Convert__imm_95_102__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2419 /* bnulr */, PPC::BCCLR, Convert__imm_95_100__regCR0, AMFBS_None, {  }, },
  { 2419 /* bnulr */, PPC::BCCLR, Convert__imm_95_100__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2425 /* bnulr+ */, PPC::BCCLR, Convert__imm_95_103__regCR0, AMFBS_None, {  }, },
  { 2425 /* bnulr+ */, PPC::BCCLR, Convert__imm_95_103__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2432 /* bnulr- */, PPC::BCCLR, Convert__imm_95_102__regCR0, AMFBS_None, {  }, },
  { 2432 /* bnulr- */, PPC::BCCLR, Convert__imm_95_102__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2439 /* bnulrl */, PPC::BCCLRL, Convert__imm_95_100__regCR0, AMFBS_None, {  }, },
  { 2439 /* bnulrl */, PPC::BCCLRL, Convert__imm_95_100__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2446 /* bnulrl+ */, PPC::BCCLRL, Convert__imm_95_103__regCR0, AMFBS_None, {  }, },
  { 2446 /* bnulrl+ */, PPC::BCCLRL, Convert__imm_95_103__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2454 /* bnulrl- */, PPC::BCCLRL, Convert__imm_95_102__regCR0, AMFBS_None, {  }, },
  { 2454 /* bnulrl- */, PPC::BCCLRL, Convert__imm_95_102__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2462 /* bpermd */, PPC::BPERMD, Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 2469 /* brinc */, PPC::BRINC, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 2475 /* bso */, PPC::BCC, Convert__imm_95_108__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2475 /* bso */, PPC::BCC, Convert__imm_95_108__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2479 /* bso+ */, PPC::BCC, Convert__imm_95_111__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2479 /* bso+ */, PPC::BCC, Convert__imm_95_111__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2484 /* bso- */, PPC::BCC, Convert__imm_95_110__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2484 /* bso- */, PPC::BCC, Convert__imm_95_110__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2489 /* bsoa */, PPC::BCCA, Convert__imm_95_108__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2489 /* bsoa */, PPC::BCCA, Convert__imm_95_108__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2494 /* bsoa+ */, PPC::BCCA, Convert__imm_95_111__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2494 /* bsoa+ */, PPC::BCCA, Convert__imm_95_111__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2500 /* bsoa- */, PPC::BCCA, Convert__imm_95_110__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2500 /* bsoa- */, PPC::BCCA, Convert__imm_95_110__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2506 /* bsoctr */, PPC::BCCCTR, Convert__imm_95_108__regCR0, AMFBS_None, {  }, },
  { 2506 /* bsoctr */, PPC::BCCCTR, Convert__imm_95_108__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2513 /* bsoctr+ */, PPC::BCCCTR, Convert__imm_95_111__regCR0, AMFBS_None, {  }, },
  { 2513 /* bsoctr+ */, PPC::BCCCTR, Convert__imm_95_111__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2521 /* bsoctr- */, PPC::BCCCTR, Convert__imm_95_110__regCR0, AMFBS_None, {  }, },
  { 2521 /* bsoctr- */, PPC::BCCCTR, Convert__imm_95_110__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2529 /* bsoctrl */, PPC::BCCCTRL, Convert__imm_95_108__regCR0, AMFBS_None, {  }, },
  { 2529 /* bsoctrl */, PPC::BCCCTRL, Convert__imm_95_108__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2537 /* bsoctrl+ */, PPC::BCCCTRL, Convert__imm_95_111__regCR0, AMFBS_None, {  }, },
  { 2537 /* bsoctrl+ */, PPC::BCCCTRL, Convert__imm_95_111__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2546 /* bsoctrl- */, PPC::BCCCTRL, Convert__imm_95_110__regCR0, AMFBS_None, {  }, },
  { 2546 /* bsoctrl- */, PPC::BCCCTRL, Convert__imm_95_110__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2555 /* bsol */, PPC::BCCL, Convert__imm_95_108__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2555 /* bsol */, PPC::BCCL, Convert__imm_95_108__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2560 /* bsol+ */, PPC::BCCL, Convert__imm_95_111__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2560 /* bsol+ */, PPC::BCCL, Convert__imm_95_111__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2566 /* bsol- */, PPC::BCCL, Convert__imm_95_110__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2566 /* bsol- */, PPC::BCCL, Convert__imm_95_110__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2572 /* bsola */, PPC::BCCLA, Convert__imm_95_108__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2572 /* bsola */, PPC::BCCLA, Convert__imm_95_108__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2578 /* bsola+ */, PPC::BCCLA, Convert__imm_95_111__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2578 /* bsola+ */, PPC::BCCLA, Convert__imm_95_111__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2585 /* bsola- */, PPC::BCCLA, Convert__imm_95_110__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2585 /* bsola- */, PPC::BCCLA, Convert__imm_95_110__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2592 /* bsolr */, PPC::BCCLR, Convert__imm_95_108__regCR0, AMFBS_None, {  }, },
  { 2592 /* bsolr */, PPC::BCCLR, Convert__imm_95_108__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2598 /* bsolr+ */, PPC::BCCLR, Convert__imm_95_111__regCR0, AMFBS_None, {  }, },
  { 2598 /* bsolr+ */, PPC::BCCLR, Convert__imm_95_111__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2605 /* bsolr- */, PPC::BCCLR, Convert__imm_95_110__regCR0, AMFBS_None, {  }, },
  { 2605 /* bsolr- */, PPC::BCCLR, Convert__imm_95_110__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2612 /* bsolrl */, PPC::BCCLRL, Convert__imm_95_108__regCR0, AMFBS_None, {  }, },
  { 2612 /* bsolrl */, PPC::BCCLRL, Convert__imm_95_108__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2619 /* bsolrl+ */, PPC::BCCLRL, Convert__imm_95_111__regCR0, AMFBS_None, {  }, },
  { 2619 /* bsolrl+ */, PPC::BCCLRL, Convert__imm_95_111__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2627 /* bsolrl- */, PPC::BCCLRL, Convert__imm_95_110__regCR0, AMFBS_None, {  }, },
  { 2627 /* bsolrl- */, PPC::BCCLRL, Convert__imm_95_110__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2635 /* bt */, PPC::gBC, Convert__imm_95_12__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 2638 /* bt+ */, PPC::gBC, Convert__imm_95_15__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 2642 /* bt- */, PPC::gBC, Convert__imm_95_14__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 2646 /* bta */, PPC::gBCA, Convert__imm_95_12__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 2650 /* bta+ */, PPC::gBCA, Convert__imm_95_15__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 2655 /* bta- */, PPC::gBCA, Convert__imm_95_14__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 2660 /* btctr */, PPC::gBCCTR, Convert__imm_95_12__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 2666 /* btctr+ */, PPC::gBCCTR, Convert__imm_95_15__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 2673 /* btctr- */, PPC::gBCCTR, Convert__imm_95_14__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 2680 /* btctrl */, PPC::gBCCTRL, Convert__imm_95_12__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 2687 /* btctrl+ */, PPC::gBCCTRL, Convert__imm_95_15__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 2695 /* btctrl- */, PPC::gBCCTRL, Convert__imm_95_14__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 2703 /* btl */, PPC::gBCL, Convert__imm_95_12__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 2707 /* btl+ */, PPC::gBCL, Convert__imm_95_15__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 2712 /* btl- */, PPC::gBCL, Convert__imm_95_14__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 2717 /* btla */, PPC::gBCLA, Convert__imm_95_12__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 2722 /* btla+ */, PPC::gBCLA, Convert__imm_95_15__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 2728 /* btla- */, PPC::gBCLA, Convert__imm_95_14__RegCRBITRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_CondBr }, },
  { 2734 /* btlr */, PPC::gBCLR, Convert__imm_95_12__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 2739 /* btlr+ */, PPC::gBCLR, Convert__imm_95_15__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 2745 /* btlr- */, PPC::gBCLR, Convert__imm_95_14__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 2751 /* btlrl */, PPC::gBCLRL, Convert__imm_95_12__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 2757 /* btlrl+ */, PPC::gBCLRL, Convert__imm_95_15__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 2764 /* btlrl- */, PPC::gBCLRL, Convert__imm_95_14__RegCRBITRC1_0__imm_95_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 2771 /* bun */, PPC::BCC, Convert__imm_95_108__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2771 /* bun */, PPC::BCC, Convert__imm_95_108__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2775 /* bun+ */, PPC::BCC, Convert__imm_95_111__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2775 /* bun+ */, PPC::BCC, Convert__imm_95_111__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2780 /* bun- */, PPC::BCC, Convert__imm_95_110__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2780 /* bun- */, PPC::BCC, Convert__imm_95_110__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2785 /* buna */, PPC::BCCA, Convert__imm_95_108__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2785 /* buna */, PPC::BCCA, Convert__imm_95_108__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2790 /* buna+ */, PPC::BCCA, Convert__imm_95_111__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2790 /* buna+ */, PPC::BCCA, Convert__imm_95_111__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2796 /* buna- */, PPC::BCCA, Convert__imm_95_110__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2796 /* buna- */, PPC::BCCA, Convert__imm_95_110__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2802 /* bunctr */, PPC::BCCCTR, Convert__imm_95_108__regCR0, AMFBS_None, {  }, },
  { 2802 /* bunctr */, PPC::BCCCTR, Convert__imm_95_108__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2809 /* bunctr+ */, PPC::BCCCTR, Convert__imm_95_111__regCR0, AMFBS_None, {  }, },
  { 2809 /* bunctr+ */, PPC::BCCCTR, Convert__imm_95_111__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2817 /* bunctr- */, PPC::BCCCTR, Convert__imm_95_110__regCR0, AMFBS_None, {  }, },
  { 2817 /* bunctr- */, PPC::BCCCTR, Convert__imm_95_110__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2825 /* bunctrl */, PPC::BCCCTRL, Convert__imm_95_108__regCR0, AMFBS_None, {  }, },
  { 2825 /* bunctrl */, PPC::BCCCTRL, Convert__imm_95_108__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2833 /* bunctrl+ */, PPC::BCCCTRL, Convert__imm_95_111__regCR0, AMFBS_None, {  }, },
  { 2833 /* bunctrl+ */, PPC::BCCCTRL, Convert__imm_95_111__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2842 /* bunctrl- */, PPC::BCCCTRL, Convert__imm_95_110__regCR0, AMFBS_None, {  }, },
  { 2842 /* bunctrl- */, PPC::BCCCTRL, Convert__imm_95_110__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2851 /* bunl */, PPC::BCCL, Convert__imm_95_108__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2851 /* bunl */, PPC::BCCL, Convert__imm_95_108__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2856 /* bunl+ */, PPC::BCCL, Convert__imm_95_111__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2856 /* bunl+ */, PPC::BCCL, Convert__imm_95_111__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2862 /* bunl- */, PPC::BCCL, Convert__imm_95_110__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2862 /* bunl- */, PPC::BCCL, Convert__imm_95_110__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2868 /* bunla */, PPC::BCCLA, Convert__imm_95_108__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2868 /* bunla */, PPC::BCCLA, Convert__imm_95_108__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2874 /* bunla+ */, PPC::BCCLA, Convert__imm_95_111__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2874 /* bunla+ */, PPC::BCCLA, Convert__imm_95_111__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2881 /* bunla- */, PPC::BCCLA, Convert__imm_95_110__regCR0__CondBr1_0, AMFBS_None, { MCK_CondBr }, },
  { 2881 /* bunla- */, PPC::BCCLA, Convert__imm_95_110__RegCRRC1_0__CondBr1_1, AMFBS_None, { MCK_RegCRRC, MCK_CondBr }, },
  { 2888 /* bunlr */, PPC::BCCLR, Convert__imm_95_108__regCR0, AMFBS_None, {  }, },
  { 2888 /* bunlr */, PPC::BCCLR, Convert__imm_95_108__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2894 /* bunlr+ */, PPC::BCCLR, Convert__imm_95_111__regCR0, AMFBS_None, {  }, },
  { 2894 /* bunlr+ */, PPC::BCCLR, Convert__imm_95_111__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2901 /* bunlr- */, PPC::BCCLR, Convert__imm_95_110__regCR0, AMFBS_None, {  }, },
  { 2901 /* bunlr- */, PPC::BCCLR, Convert__imm_95_110__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2908 /* bunlrl */, PPC::BCCLRL, Convert__imm_95_108__regCR0, AMFBS_None, {  }, },
  { 2908 /* bunlrl */, PPC::BCCLRL, Convert__imm_95_108__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2915 /* bunlrl+ */, PPC::BCCLRL, Convert__imm_95_111__regCR0, AMFBS_None, {  }, },
  { 2915 /* bunlrl+ */, PPC::BCCLRL, Convert__imm_95_111__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2923 /* bunlrl- */, PPC::BCCLRL, Convert__imm_95_110__regCR0, AMFBS_None, {  }, },
  { 2923 /* bunlrl- */, PPC::BCCLRL, Convert__imm_95_110__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 2931 /* clrbhrb */, PPC::CLRBHRB, Convert_NoOperands, AMFBS_None, {  }, },
  { 2939 /* clrldi */, PPC::RLDICL, Convert__RegG8RC1_0__RegG8RC1_1__imm_95_0__U6Imm1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 2939 /* clrldi */, PPC::RLDICL_32_64, Convert__RegG8RC1_0__RegGPRC1_1__imm_95_0__U6Imm1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegGPRC, MCK_U6Imm }, },
  { 2939 /* clrldi */, PPC::RLDICL_rec, Convert__RegG8RC1_1__RegG8RC1_2__imm_95_0__U6Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 2946 /* clrlsldi */, PPC::CLRLSLDI, Convert__RegG8RC1_0__RegG8RC1_1__U6Imm1_2__U6Imm1_3, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 2946 /* clrlsldi */, PPC::CLRLSLDI_rec, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 2955 /* clrlslwi */, PPC::CLRLSLWI, Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2__U5Imm1_3, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 2955 /* clrlslwi */, PPC::CLRLSLWI_rec, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 2964 /* clrlwi */, PPC::RLWINM8, Convert__RegG8RC1_0__RegG8RC1_1__imm_95_0__U5Imm1_2__imm_95_31, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U5Imm }, },
  { 2964 /* clrlwi */, PPC::RLWINM, Convert__RegGPRC1_0__RegGPRC1_1__imm_95_0__U5Imm1_2__imm_95_31, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 2964 /* clrlwi */, PPC::RLWINM8_rec, Convert__RegG8RC1_1__RegG8RC1_2__imm_95_0__U5Imm1_3__imm_95_31, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U5Imm }, },
  { 2964 /* clrlwi */, PPC::RLWINM_rec, Convert__RegGPRC1_1__RegGPRC1_2__imm_95_0__U5Imm1_3__imm_95_31, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 2971 /* clrrdi */, PPC::CLRRDI, Convert__RegG8RC1_0__RegG8RC1_1__U6Imm1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 2971 /* clrrdi */, PPC::CLRRDI_rec, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 2978 /* clrrwi */, PPC::CLRRWI, Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 2978 /* clrrwi */, PPC::CLRRWI_rec, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 2985 /* cmp */, PPC::CMPW, Convert__RegCRRC1_0__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK_RegCRRC, MCK_0, MCK_RegGPRC, MCK_RegGPRC }, },
  { 2985 /* cmp */, PPC::CMPD, Convert__RegCRRC1_0__RegG8RC1_2__RegG8RC1_3, AMFBS_None, { MCK_RegCRRC, MCK_1, MCK_RegG8RC, MCK_RegG8RC }, },
  { 2989 /* cmpb */, PPC::CMPB, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 2994 /* cmpd */, PPC::CMPD, Convert__regCR0__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 2994 /* cmpd */, PPC::CMPD, Convert__RegCRRC1_0__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 2999 /* cmpdi */, PPC::CMPDI, Convert__regCR0__RegG8RC1_0__S16Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_S16Imm }, },
  { 2999 /* cmpdi */, PPC::CMPDI, Convert__RegCRRC1_0__RegG8RC1_1__S16Imm1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegG8RC, MCK_S16Imm }, },
  { 3005 /* cmpeqb */, PPC::CMPEQB, Convert__RegCRBITRC1_0__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK_RegCRBITRC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3012 /* cmpi */, PPC::CMPWI, Convert__RegCRRC1_0__RegGPRC1_2__S16Imm1_3, AMFBS_None, { MCK_RegCRRC, MCK_0, MCK_RegGPRC, MCK_S16Imm }, },
  { 3012 /* cmpi */, PPC::CMPDI, Convert__RegCRRC1_0__RegG8RC1_2__S16Imm1_3, AMFBS_None, { MCK_RegCRRC, MCK_1, MCK_RegG8RC, MCK_S16Imm }, },
  { 3017 /* cmpl */, PPC::CMPLW, Convert__RegCRRC1_0__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK_RegCRRC, MCK_0, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3017 /* cmpl */, PPC::CMPLD, Convert__RegCRRC1_0__RegG8RC1_2__RegG8RC1_3, AMFBS_None, { MCK_RegCRRC, MCK_1, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3022 /* cmpld */, PPC::CMPLD, Convert__regCR0__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 3022 /* cmpld */, PPC::CMPLD, Convert__RegCRRC1_0__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3028 /* cmpldi */, PPC::CMPLDI, Convert__regCR0__RegG8RC1_0__U16Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_U16Imm }, },
  { 3028 /* cmpldi */, PPC::CMPLDI, Convert__RegCRRC1_0__RegG8RC1_1__U16Imm1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegG8RC, MCK_U16Imm }, },
  { 3035 /* cmpli */, PPC::CMPLWI, Convert__RegCRRC1_0__RegGPRC1_2__U16Imm1_3, AMFBS_None, { MCK_RegCRRC, MCK_0, MCK_RegGPRC, MCK_U16Imm }, },
  { 3035 /* cmpli */, PPC::CMPLDI, Convert__RegCRRC1_0__RegG8RC1_2__U16Imm1_3, AMFBS_None, { MCK_RegCRRC, MCK_1, MCK_RegG8RC, MCK_U16Imm }, },
  { 3041 /* cmplw */, PPC::CMPLW, Convert__regCR0__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 3041 /* cmplw */, PPC::CMPLW, Convert__RegCRRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3047 /* cmplwi */, PPC::CMPLWI, Convert__regCR0__RegGPRC1_0__U16Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_U16Imm }, },
  { 3047 /* cmplwi */, PPC::CMPLWI, Convert__RegCRRC1_0__RegGPRC1_1__U16Imm1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegGPRC, MCK_U16Imm }, },
  { 3054 /* cmprb */, PPC::CMPRB, Convert__RegCRBITRC1_0__U1Imm1_1__RegG8RC1_2__RegG8RC1_3, AMFBS_None, { MCK_RegCRBITRC, MCK_U1Imm, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3060 /* cmpw */, PPC::CMPW, Convert__regCR0__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 3060 /* cmpw */, PPC::CMPW, Convert__RegCRRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3065 /* cmpwi */, PPC::CMPWI, Convert__regCR0__RegGPRC1_0__S16Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S16Imm }, },
  { 3065 /* cmpwi */, PPC::CMPWI, Convert__RegCRRC1_0__RegGPRC1_1__S16Imm1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegGPRC, MCK_S16Imm }, },
  { 3071 /* cntlzd */, PPC::CNTLZD, Convert__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 3071 /* cntlzd */, PPC::CNTLZD_rec, Convert__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3078 /* cntlzw */, PPC::CNTLZW8, Convert__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 3078 /* cntlzw */, PPC::CNTLZW, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 3078 /* cntlzw */, PPC::CNTLZW, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 3078 /* cntlzw */, PPC::CNTLZW8_rec, Convert__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3078 /* cntlzw */, PPC::CNTLZW_rec, Convert__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3078 /* cntlzw */, PPC::CNTLZW_rec, Convert__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3085 /* cnttzd */, PPC::CNTTZD, Convert__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 3085 /* cnttzd */, PPC::CNTTZD_rec, Convert__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3092 /* cnttzw */, PPC::CNTTZW, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 3092 /* cnttzw */, PPC::CNTTZW_rec, Convert__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3099 /* copy */, PPC::CP_COPYx, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 3099 /* copy */, PPC::CP_COPY, Convert__RegGPRC1_0__RegGPRC1_1__U1Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U1Imm }, },
  { 3104 /* copy_first */, PPC::CP_COPY_FIRST, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 3115 /* cp_abort */, PPC::CP_ABORT, Convert_NoOperands, AMFBS_None, {  }, },
  { 3124 /* crand */, PPC::CRAND, Convert__RegCRBITRC1_0__RegCRBITRC1_1__RegCRBITRC1_2, AMFBS_None, { MCK_RegCRBITRC, MCK_RegCRBITRC, MCK_RegCRBITRC }, },
  { 3130 /* crandc */, PPC::CRANDC, Convert__RegCRBITRC1_0__RegCRBITRC1_1__RegCRBITRC1_2, AMFBS_None, { MCK_RegCRBITRC, MCK_RegCRBITRC, MCK_RegCRBITRC }, },
  { 3137 /* crclr */, PPC::CRXOR, Convert__RegCRBITRC1_0__RegCRBITRC1_0__RegCRBITRC1_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 3143 /* creqv */, PPC::CREQV, Convert__RegCRBITRC1_0__RegCRBITRC1_1__RegCRBITRC1_2, AMFBS_None, { MCK_RegCRBITRC, MCK_RegCRBITRC, MCK_RegCRBITRC }, },
  { 3149 /* crmove */, PPC::CROR, Convert__RegCRBITRC1_0__RegCRBITRC1_1__RegCRBITRC1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_RegCRBITRC }, },
  { 3156 /* crnand */, PPC::CRNAND, Convert__RegCRBITRC1_0__RegCRBITRC1_1__RegCRBITRC1_2, AMFBS_None, { MCK_RegCRBITRC, MCK_RegCRBITRC, MCK_RegCRBITRC }, },
  { 3163 /* crnor */, PPC::CRNOR, Convert__RegCRBITRC1_0__RegCRBITRC1_1__RegCRBITRC1_2, AMFBS_None, { MCK_RegCRBITRC, MCK_RegCRBITRC, MCK_RegCRBITRC }, },
  { 3169 /* crnot */, PPC::CRNOR, Convert__RegCRBITRC1_0__RegCRBITRC1_1__RegCRBITRC1_1, AMFBS_None, { MCK_RegCRBITRC, MCK_RegCRBITRC }, },
  { 3175 /* cror */, PPC::CROR, Convert__RegCRBITRC1_0__RegCRBITRC1_1__RegCRBITRC1_2, AMFBS_None, { MCK_RegCRBITRC, MCK_RegCRBITRC, MCK_RegCRBITRC }, },
  { 3180 /* crorc */, PPC::CRORC, Convert__RegCRBITRC1_0__RegCRBITRC1_1__RegCRBITRC1_2, AMFBS_None, { MCK_RegCRBITRC, MCK_RegCRBITRC, MCK_RegCRBITRC }, },
  { 3186 /* crset */, PPC::CREQV, Convert__RegCRBITRC1_0__RegCRBITRC1_0__RegCRBITRC1_0, AMFBS_None, { MCK_RegCRBITRC }, },
  { 3192 /* crxor */, PPC::CRXOR, Convert__RegCRBITRC1_0__RegCRBITRC1_1__RegCRBITRC1_2, AMFBS_None, { MCK_RegCRBITRC, MCK_RegCRBITRC, MCK_RegCRBITRC }, },
  { 3198 /* darn */, PPC::DARN, Convert__RegG8RC1_0__Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_Imm }, },
  { 3203 /* dcba */, PPC::DCBA, Convert__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3208 /* dcbf */, PPC::DCBFx, Convert__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3208 /* dcbf */, PPC::DCBF, Convert__U5Imm1_2__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_U5Imm }, },
  { 3213 /* dcbfep */, PPC::DCBFEP, Convert__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3220 /* dcbfl */, PPC::DCBFL, Convert__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3226 /* dcbflp */, PPC::DCBFLP, Convert__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3233 /* dcbi */, PPC::DCBI, Convert__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3238 /* dcbst */, PPC::DCBST, Convert__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3244 /* dcbstep */, PPC::DCBSTEP, Convert__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3252 /* dcbt */, PPC::DCBTx, Convert__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3252 /* dcbt */, PPC::DCBT, Convert__U5Imm1_2__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_U5Imm }, },
  { 3257 /* dcbtct */, PPC::DCBTCT, Convert__RegGxRCNoR01_0__RegGxRC1_1__U5Imm1_2, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_U5Imm }, },
  { 3264 /* dcbtds */, PPC::DCBTDS, Convert__RegGxRCNoR01_0__RegGxRC1_1__U5Imm1_2, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_U5Imm }, },
  { 3271 /* dcbtep */, PPC::DCBTEP, Convert__RegGxRCNoR01_1__RegGxRC1_2__U5Imm1_0, AMFBS_None, { MCK_U5Imm, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3278 /* dcbtst */, PPC::DCBTSTx, Convert__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3278 /* dcbtst */, PPC::DCBTST, Convert__U5Imm1_2__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_U5Imm }, },
  { 3285 /* dcbtstct */, PPC::DCBTSTCT, Convert__RegGxRCNoR01_0__RegGxRC1_1__U5Imm1_2, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_U5Imm }, },
  { 3294 /* dcbtstds */, PPC::DCBTSTDS, Convert__RegGxRCNoR01_0__RegGxRC1_1__U5Imm1_2, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_U5Imm }, },
  { 3303 /* dcbtstep */, PPC::DCBTSTEP, Convert__RegGxRCNoR01_1__RegGxRC1_2__U5Imm1_0, AMFBS_None, { MCK_U5Imm, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3312 /* dcbtstt */, PPC::DCBTSTT, Convert__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3320 /* dcbtt */, PPC::DCBTT, Convert__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3326 /* dcbz */, PPC::DCBZ, Convert__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3331 /* dcbzep */, PPC::DCBZEP, Convert__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3338 /* dcbzl */, PPC::DCBZL, Convert__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3344 /* dcbzlep */, PPC::DCBZLEP, Convert__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3352 /* dccci */, PPC::DCCCI, Convert__regR0__regR0, AMFBS_None, {  }, },
  { 3352 /* dccci */, PPC::DCCCI, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 3358 /* dci */, PPC::DCCCI, Convert__regR0__regR0, AMFBS_None, { MCK_0 }, },
  { 3362 /* divd */, PPC::DIVD, Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3362 /* divd */, PPC::DIVD_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3367 /* divde */, PPC::DIVDE, Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3367 /* divde */, PPC::DIVDE_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3373 /* divdeo */, PPC::DIVDEO, Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3373 /* divdeo */, PPC::DIVDEO_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3380 /* divdeu */, PPC::DIVDEU, Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3380 /* divdeu */, PPC::DIVDEU_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3387 /* divdeuo */, PPC::DIVDEUO, Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3387 /* divdeuo */, PPC::DIVDEUO_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3395 /* divdo */, PPC::DIVDO, Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3395 /* divdo */, PPC::DIVDO_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3401 /* divdu */, PPC::DIVDU, Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3401 /* divdu */, PPC::DIVDU_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3407 /* divduo */, PPC::DIVDUO, Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3407 /* divduo */, PPC::DIVDUO_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3414 /* divw */, PPC::DIVW, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3414 /* divw */, PPC::DIVW_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3419 /* divwe */, PPC::DIVWE, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3419 /* divwe */, PPC::DIVWE_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3425 /* divweo */, PPC::DIVWEO, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3425 /* divweo */, PPC::DIVWEO_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3432 /* divweu */, PPC::DIVWEU, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3432 /* divweu */, PPC::DIVWEU_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3439 /* divweuo */, PPC::DIVWEUO, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3439 /* divweuo */, PPC::DIVWEUO_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3447 /* divwo */, PPC::DIVWO, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3447 /* divwo */, PPC::DIVWO_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3453 /* divwu */, PPC::DIVWU, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3453 /* divwu */, PPC::DIVWU_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3459 /* divwuo */, PPC::DIVWUO, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3459 /* divwuo */, PPC::DIVWUO_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3466 /* dss */, PPC::DSS, Convert__U5Imm1_0, AMFBS_None, { MCK_U5Imm }, },
  { 3470 /* dssall */, PPC::DSSALL, Convert_NoOperands, AMFBS_None, {  }, },
  { 3477 /* dst */, PPC::DST, Convert__U5Imm1_2__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 3481 /* dstst */, PPC::DSTST, Convert__U5Imm1_2__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 3487 /* dststt */, PPC::DSTSTT, Convert__U5Imm1_2__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 3494 /* dstt */, PPC::DSTT, Convert__U5Imm1_2__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 3499 /* efdabs */, PPC::EFDABS, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 3506 /* efdadd */, PPC::EFDADD, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 3513 /* efdcfs */, PPC::EFDCFS, Convert__RegSPERC1_0__RegSPE4RC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPE4RC }, },
  { 3520 /* efdcfsf */, PPC::EFDCFSF, Convert__RegSPERC1_0__RegSPE4RC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPE4RC }, },
  { 3528 /* efdcfsi */, PPC::EFDCFSI, Convert__RegSPERC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegGPRC }, },
  { 3536 /* efdcfsid */, PPC::EFDCFSID, Convert__RegSPERC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegGPRC }, },
  { 3545 /* efdcfuf */, PPC::EFDCFUF, Convert__RegSPERC1_0__RegSPE4RC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPE4RC }, },
  { 3553 /* efdcfui */, PPC::EFDCFUI, Convert__RegSPERC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegGPRC }, },
  { 3561 /* efdcfuid */, PPC::EFDCFUID, Convert__RegSPERC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegGPRC }, },
  { 3570 /* efdcmpeq */, PPC::EFDCMPEQ, Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 3579 /* efdcmpgt */, PPC::EFDCMPGT, Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 3588 /* efdcmplt */, PPC::EFDCMPLT, Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 3597 /* efdctsf */, PPC::EFDCTSF, Convert__RegSPERC1_0__RegSPE4RC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPE4RC }, },
  { 3605 /* efdctsi */, PPC::EFDCTSI, Convert__RegGPRC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegSPERC }, },
  { 3613 /* efdctsidz */, PPC::EFDCTSIDZ, Convert__RegGPRC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegSPERC }, },
  { 3623 /* efdctsiz */, PPC::EFDCTSIZ, Convert__RegGPRC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegSPERC }, },
  { 3632 /* efdctuf */, PPC::EFDCTUF, Convert__RegSPERC1_0__RegSPE4RC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPE4RC }, },
  { 3640 /* efdctui */, PPC::EFDCTUI, Convert__RegGPRC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegSPERC }, },
  { 3648 /* efdctuidz */, PPC::EFDCTUIDZ, Convert__RegGPRC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegSPERC }, },
  { 3658 /* efdctuiz */, PPC::EFDCTUIZ, Convert__RegGPRC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegSPERC }, },
  { 3667 /* efddiv */, PPC::EFDDIV, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 3674 /* efdmul */, PPC::EFDMUL, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 3681 /* efdnabs */, PPC::EFDNABS, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 3689 /* efdneg */, PPC::EFDNEG, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 3696 /* efdsub */, PPC::EFDSUB, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 3703 /* efdtsteq */, PPC::EFDTSTEQ, Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 3712 /* efdtstgt */, PPC::EFDTSTGT, Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 3721 /* efdtstlt */, PPC::EFDTSTLT, Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 3730 /* efsabs */, PPC::EFSABS, Convert__RegSPE4RC1_0__RegSPE4RC1_1, AMFBS_None, { MCK_RegSPE4RC, MCK_RegSPE4RC }, },
  { 3737 /* efsadd */, PPC::EFSADD, Convert__RegSPE4RC1_0__RegSPE4RC1_1__RegSPE4RC1_2, AMFBS_None, { MCK_RegSPE4RC, MCK_RegSPE4RC, MCK_RegSPE4RC }, },
  { 3744 /* efscfd */, PPC::EFSCFD, Convert__RegSPE4RC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPE4RC, MCK_RegSPERC }, },
  { 3751 /* efscfsf */, PPC::EFSCFSF, Convert__RegSPE4RC1_0__RegSPE4RC1_1, AMFBS_None, { MCK_RegSPE4RC, MCK_RegSPE4RC }, },
  { 3759 /* efscfsi */, PPC::EFSCFSI, Convert__RegSPE4RC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegSPE4RC, MCK_RegGPRC }, },
  { 3767 /* efscfuf */, PPC::EFSCFUF, Convert__RegSPE4RC1_0__RegSPE4RC1_1, AMFBS_None, { MCK_RegSPE4RC, MCK_RegSPE4RC }, },
  { 3775 /* efscfui */, PPC::EFSCFUI, Convert__RegSPE4RC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegSPE4RC, MCK_RegGPRC }, },
  { 3783 /* efscmpeq */, PPC::EFSCMPEQ, Convert__RegCRRC1_0__RegSPE4RC1_1__RegSPE4RC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPE4RC, MCK_RegSPE4RC }, },
  { 3792 /* efscmpgt */, PPC::EFSCMPGT, Convert__RegCRRC1_0__RegSPE4RC1_1__RegSPE4RC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPE4RC, MCK_RegSPE4RC }, },
  { 3801 /* efscmplt */, PPC::EFSCMPLT, Convert__RegCRRC1_0__RegSPE4RC1_1__RegSPE4RC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPE4RC, MCK_RegSPE4RC }, },
  { 3810 /* efsctsf */, PPC::EFSCTSF, Convert__RegSPE4RC1_0__RegSPE4RC1_1, AMFBS_None, { MCK_RegSPE4RC, MCK_RegSPE4RC }, },
  { 3818 /* efsctsi */, PPC::EFSCTSI, Convert__RegGPRC1_0__RegSPE4RC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegSPE4RC }, },
  { 3826 /* efsctsiz */, PPC::EFSCTSIZ, Convert__RegGPRC1_0__RegSPE4RC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegSPE4RC }, },
  { 3835 /* efsctuf */, PPC::EFSCTUF, Convert__RegSPERC1_0__RegSPE4RC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPE4RC }, },
  { 3843 /* efsctui */, PPC::EFSCTUI, Convert__RegGPRC1_0__RegSPE4RC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegSPE4RC }, },
  { 3851 /* efsctuiz */, PPC::EFSCTUIZ, Convert__RegGPRC1_0__RegSPE4RC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegSPE4RC }, },
  { 3860 /* efsdiv */, PPC::EFSDIV, Convert__RegSPE4RC1_0__RegSPE4RC1_1__RegSPE4RC1_2, AMFBS_None, { MCK_RegSPE4RC, MCK_RegSPE4RC, MCK_RegSPE4RC }, },
  { 3867 /* efsmul */, PPC::EFSMUL, Convert__RegSPE4RC1_0__RegSPE4RC1_1__RegSPE4RC1_2, AMFBS_None, { MCK_RegSPE4RC, MCK_RegSPE4RC, MCK_RegSPE4RC }, },
  { 3874 /* efsnabs */, PPC::EFSNABS, Convert__RegSPE4RC1_0__RegSPE4RC1_1, AMFBS_None, { MCK_RegSPE4RC, MCK_RegSPE4RC }, },
  { 3882 /* efsneg */, PPC::EFSNEG, Convert__RegSPE4RC1_0__RegSPE4RC1_1, AMFBS_None, { MCK_RegSPE4RC, MCK_RegSPE4RC }, },
  { 3889 /* efssub */, PPC::EFSSUB, Convert__RegSPE4RC1_0__RegSPE4RC1_1__RegSPE4RC1_2, AMFBS_None, { MCK_RegSPE4RC, MCK_RegSPE4RC, MCK_RegSPE4RC }, },
  { 3896 /* efststeq */, PPC::EFSTSTEQ, Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 3905 /* efststgt */, PPC::EFSTSTGT, Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 3914 /* efststlt */, PPC::EFSTSTLT, Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 3923 /* eieio */, PPC::EnforceIEIO, Convert_NoOperands, AMFBS_None, {  }, },
  { 3929 /* eqv */, PPC::EQV, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3929 /* eqv */, PPC::EQV_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3933 /* evabs */, PPC::EVABS, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 3939 /* evaddiw */, PPC::EVADDIW, Convert__RegSPERC1_0__RegSPERC1_2__U5Imm1_1, AMFBS_None, { MCK_RegSPERC, MCK_U5Imm, MCK_RegSPERC }, },
  { 3947 /* evaddsmiaaw */, PPC::EVADDSMIAAW, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 3959 /* evaddssiaaw */, PPC::EVADDSSIAAW, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 3971 /* evaddumiaaw */, PPC::EVADDUMIAAW, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 3983 /* evaddusiaaw */, PPC::EVADDUSIAAW, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 3995 /* evaddw */, PPC::EVADDW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4002 /* evand */, PPC::EVAND, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4008 /* evandc */, PPC::EVANDC, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4015 /* evcmpeq */, PPC::EVCMPEQ, Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4023 /* evcmpgts */, PPC::EVCMPGTS, Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4032 /* evcmpgtu */, PPC::EVCMPGTU, Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4041 /* evcmplts */, PPC::EVCMPLTS, Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4050 /* evcmpltu */, PPC::EVCMPLTU, Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4059 /* evcntlsw */, PPC::EVCNTLSW, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 4068 /* evcntlzw */, PPC::EVCNTLZW, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 4077 /* evdivws */, PPC::EVDIVWS, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4085 /* evdivwu */, PPC::EVDIVWU, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4093 /* eveqv */, PPC::EVEQV, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4099 /* evextsb */, PPC::EVEXTSB, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 4107 /* evextsh */, PPC::EVEXTSH, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 4115 /* evfsabs */, PPC::EVFSABS, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 4123 /* evfsadd */, PPC::EVFSADD, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4131 /* evfscfsf */, PPC::EVFSCFSF, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 4140 /* evfscfsi */, PPC::EVFSCFSI, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 4149 /* evfscfuf */, PPC::EVFSCFUF, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 4158 /* evfscfui */, PPC::EVFSCFUI, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 4167 /* evfscmpeq */, PPC::EVFSCMPEQ, Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4177 /* evfscmpgt */, PPC::EVFSCMPGT, Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4187 /* evfscmplt */, PPC::EVFSCMPLT, Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4197 /* evfsctsf */, PPC::EVFSCTSF, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 4197 /* evfsctsf */, PPC::EVFSCTUF, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 4206 /* evfsctsi */, PPC::EVFSCTSI, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 4215 /* evfsctsiz */, PPC::EVFSCTSIZ, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 4215 /* evfsctsiz */, PPC::EVFSCTUIZ, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 4225 /* evfsctui */, PPC::EVFSCTUI, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 4234 /* evfsdiv */, PPC::EVFSDIV, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4242 /* evfsmul */, PPC::EVFSMUL, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4250 /* evfsnabs */, PPC::EVFSNABS, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 4259 /* evfsneg */, PPC::EVFSNEG, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 4267 /* evfssub */, PPC::EVFSSUB, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4275 /* evfststeq */, PPC::EVFSTSTEQ, Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4285 /* evfststgt */, PPC::EVFSTSTGT, Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4295 /* evfststlt */, PPC::EVFSTSTLT, Convert__RegCRRC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4305 /* evldd */, PPC::EVLDD, Convert__RegSPERC1_0__DispSPE81_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegSPERC, MCK_DispSPE8, MCK_RegGxRCNoR0 }, },
  { 4311 /* evlddx */, PPC::EVLDDX, Convert__RegSPERC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 4318 /* evldh */, PPC::EVLDH, Convert__RegSPERC1_0__DispSPE81_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegSPERC, MCK_DispSPE8, MCK_RegGxRCNoR0 }, },
  { 4324 /* evldhx */, PPC::EVLDHX, Convert__RegSPERC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 4331 /* evldw */, PPC::EVLDW, Convert__RegSPERC1_0__DispSPE81_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegSPERC, MCK_DispSPE8, MCK_RegGxRCNoR0 }, },
  { 4337 /* evldwx */, PPC::EVLDWX, Convert__RegSPERC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 4344 /* evlhhesplat */, PPC::EVLHHESPLAT, Convert__RegSPERC1_0__DispSPE21_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegSPERC, MCK_DispSPE2, MCK_RegGxRCNoR0 }, },
  { 4356 /* evlhhesplatx */, PPC::EVLHHESPLATX, Convert__RegSPERC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 4369 /* evlhhossplat */, PPC::EVLHHOSSPLAT, Convert__RegSPERC1_0__DispSPE21_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegSPERC, MCK_DispSPE2, MCK_RegGxRCNoR0 }, },
  { 4382 /* evlhhossplatx */, PPC::EVLHHOSSPLATX, Convert__RegSPERC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 4396 /* evlhhousplat */, PPC::EVLHHOUSPLAT, Convert__RegSPERC1_0__DispSPE21_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegSPERC, MCK_DispSPE2, MCK_RegGxRCNoR0 }, },
  { 4409 /* evlhhousplatx */, PPC::EVLHHOUSPLATX, Convert__RegSPERC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 4423 /* evlwhe */, PPC::EVLWHE, Convert__RegSPERC1_0__DispSPE41_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegSPERC, MCK_DispSPE4, MCK_RegGxRCNoR0 }, },
  { 4430 /* evlwhex */, PPC::EVLWHEX, Convert__RegSPERC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 4438 /* evlwhos */, PPC::EVLWHOS, Convert__RegSPERC1_0__DispSPE41_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegSPERC, MCK_DispSPE4, MCK_RegGxRCNoR0 }, },
  { 4446 /* evlwhosx */, PPC::EVLWHOSX, Convert__RegSPERC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 4455 /* evlwhou */, PPC::EVLWHOU, Convert__RegSPERC1_0__DispSPE41_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegSPERC, MCK_DispSPE4, MCK_RegGxRCNoR0 }, },
  { 4463 /* evlwhoux */, PPC::EVLWHOUX, Convert__RegSPERC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 4472 /* evlwhsplat */, PPC::EVLWHSPLAT, Convert__RegSPERC1_0__DispSPE41_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegSPERC, MCK_DispSPE4, MCK_RegGxRCNoR0 }, },
  { 4483 /* evlwhsplatx */, PPC::EVLWHSPLATX, Convert__RegSPERC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 4495 /* evlwwsplat */, PPC::EVLWWSPLAT, Convert__RegSPERC1_0__DispSPE41_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegSPERC, MCK_DispSPE4, MCK_RegGxRCNoR0 }, },
  { 4506 /* evlwwsplatx */, PPC::EVLWWSPLATX, Convert__RegSPERC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 4518 /* evmergehi */, PPC::EVMERGEHI, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4528 /* evmergehilo */, PPC::EVMERGEHILO, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4540 /* evmergelo */, PPC::EVMERGELO, Convert__RegSPERC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4550 /* evmergelohi */, PPC::EVMERGELOHI, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4562 /* evmhegsmfaa */, PPC::EVMHEGSMFAA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4574 /* evmhegsmfan */, PPC::EVMHEGSMFAN, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4586 /* evmhegsmiaa */, PPC::EVMHEGSMIAA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4598 /* evmhegsmian */, PPC::EVMHEGSMIAN, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4610 /* evmhegumiaa */, PPC::EVMHEGUMIAA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4622 /* evmhegumian */, PPC::EVMHEGUMIAN, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4634 /* evmhesmf */, PPC::EVMHESMF, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4643 /* evmhesmfa */, PPC::EVMHESMFA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4653 /* evmhesmfaaw */, PPC::EVMHESMFAAW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4665 /* evmhesmfanw */, PPC::EVMHESMFANW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4677 /* evmhesmi */, PPC::EVMHESMI, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4686 /* evmhesmia */, PPC::EVMHESMIA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4696 /* evmhesmiaaw */, PPC::EVMHESMIAAW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4708 /* evmhesmianw */, PPC::EVMHESMIANW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4720 /* evmhessf */, PPC::EVMHESSF, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4729 /* evmhessfa */, PPC::EVMHESSFA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4739 /* evmhessfaaw */, PPC::EVMHESSFAAW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4751 /* evmhessfanw */, PPC::EVMHESSFANW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4763 /* evmhessiaaw */, PPC::EVMHESSIAAW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4775 /* evmhessianw */, PPC::EVMHESSIANW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4787 /* evmheumi */, PPC::EVMHEUMI, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4796 /* evmheumia */, PPC::EVMHEUMIA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4806 /* evmheumiaaw */, PPC::EVMHEUMIAAW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4818 /* evmheumianw */, PPC::EVMHEUMIANW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4830 /* evmheusiaaw */, PPC::EVMHEUSIAAW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4842 /* evmheusianw */, PPC::EVMHEUSIANW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4854 /* evmhogsmfaa */, PPC::EVMHOGSMFAA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4866 /* evmhogsmfan */, PPC::EVMHOGSMFAN, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4878 /* evmhogsmiaa */, PPC::EVMHOGSMIAA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4890 /* evmhogsmian */, PPC::EVMHOGSMIAN, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4902 /* evmhogumiaa */, PPC::EVMHOGUMIAA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4914 /* evmhogumian */, PPC::EVMHOGUMIAN, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4926 /* evmhosmf */, PPC::EVMHOSMF, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4935 /* evmhosmfa */, PPC::EVMHOSMFA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4945 /* evmhosmfaaw */, PPC::EVMHOSMFAAW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4957 /* evmhosmfanw */, PPC::EVMHOSMFANW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4969 /* evmhosmi */, PPC::EVMHOSMI, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4978 /* evmhosmia */, PPC::EVMHOSMIA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 4988 /* evmhosmiaaw */, PPC::EVMHOSMIAAW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5000 /* evmhosmianw */, PPC::EVMHOSMIANW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5012 /* evmhossf */, PPC::EVMHOSSF, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5021 /* evmhossfa */, PPC::EVMHOSSFA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5031 /* evmhossfaaw */, PPC::EVMHOSSFAAW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5043 /* evmhossfanw */, PPC::EVMHOSSFANW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5055 /* evmhossiaaw */, PPC::EVMHOSSIAAW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5067 /* evmhossianw */, PPC::EVMHOSSIANW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5079 /* evmhoumi */, PPC::EVMHOUMI, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5088 /* evmhoumia */, PPC::EVMHOUMIA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5098 /* evmhoumiaaw */, PPC::EVMHOUMIAAW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5110 /* evmhoumianw */, PPC::EVMHOUMIANW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5122 /* evmhousiaaw */, PPC::EVMHOUSIAAW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5134 /* evmhousianw */, PPC::EVMHOUSIANW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5146 /* evmra */, PPC::EVMRA, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 5152 /* evmwhsmf */, PPC::EVMWHSMF, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5161 /* evmwhsmfa */, PPC::EVMWHSMFA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5171 /* evmwhsmi */, PPC::EVMWHSMI, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5180 /* evmwhsmia */, PPC::EVMWHSMIA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5190 /* evmwhssf */, PPC::EVMWHSSF, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5199 /* evmwhssfa */, PPC::EVMWHSSFA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5209 /* evmwhumi */, PPC::EVMWHUMI, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5218 /* evmwhumia */, PPC::EVMWHUMIA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5228 /* evmwlsmiaaw */, PPC::EVMWLSMIAAW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5240 /* evmwlsmianw */, PPC::EVMWLSMIANW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5252 /* evmwlssiaaw */, PPC::EVMWLSSIAAW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5264 /* evmwlssianw */, PPC::EVMWLSSIANW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5276 /* evmwlumi */, PPC::EVMWLUMI, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5285 /* evmwlumia */, PPC::EVMWLUMIA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5295 /* evmwlumiaaw */, PPC::EVMWLUMIAAW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5307 /* evmwlumianw */, PPC::EVMWLUMIANW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5319 /* evmwlusiaaw */, PPC::EVMWLUSIAAW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5331 /* evmwlusianw */, PPC::EVMWLUSIANW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5343 /* evmwsmf */, PPC::EVMWSMF, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5351 /* evmwsmfa */, PPC::EVMWSMFA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5360 /* evmwsmfaa */, PPC::EVMWSMFAA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5370 /* evmwsmfan */, PPC::EVMWSMFAN, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5380 /* evmwsmi */, PPC::EVMWSMI, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5388 /* evmwsmia */, PPC::EVMWSMIA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5397 /* evmwsmiaa */, PPC::EVMWSMIAA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5407 /* evmwsmian */, PPC::EVMWSMIAN, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5417 /* evmwssf */, PPC::EVMWSSF, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5425 /* evmwssfa */, PPC::EVMWSSFA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5434 /* evmwssfaa */, PPC::EVMWSSFAA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5444 /* evmwssfan */, PPC::EVMWSSFAN, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5454 /* evmwumi */, PPC::EVMWUMI, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5462 /* evmwumia */, PPC::EVMWUMIA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5471 /* evmwumiaa */, PPC::EVMWUMIAA, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5481 /* evmwumian */, PPC::EVMWUMIAN, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5491 /* evnand */, PPC::EVNAND, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5498 /* evneg */, PPC::EVNEG, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 5504 /* evnor */, PPC::EVNOR, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5510 /* evor */, PPC::EVOR, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5515 /* evorc */, PPC::EVORC, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5521 /* evrlw */, PPC::EVRLW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5527 /* evrlwi */, PPC::EVRLWI, Convert__RegSPERC1_0__RegSPERC1_1__U5Imm1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_U5Imm }, },
  { 5534 /* evrndw */, PPC::EVRNDW, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 5541 /* evsel */, PPC::EVSEL, Convert__RegSPERC1_1__RegSPERC1_2__RegSPERC1_3__imm_95_0, AMFBS_None, { MCK_crD, MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5547 /* evslw */, PPC::EVSLW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5553 /* evslwi */, PPC::EVSLWI, Convert__RegSPERC1_0__RegSPERC1_1__U5Imm1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_U5Imm }, },
  { 5560 /* evsplatfi */, PPC::EVSPLATFI, Convert__RegSPERC1_0__S5Imm1_1, AMFBS_None, { MCK_RegSPERC, MCK_S5Imm }, },
  { 5570 /* evsplati */, PPC::EVSPLATI, Convert__RegSPERC1_0__S5Imm1_1, AMFBS_None, { MCK_RegSPERC, MCK_S5Imm }, },
  { 5579 /* evsrwis */, PPC::EVSRWIS, Convert__RegSPERC1_0__RegSPERC1_1__U5Imm1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_U5Imm }, },
  { 5587 /* evsrwiu */, PPC::EVSRWIU, Convert__RegSPERC1_0__RegSPERC1_1__U5Imm1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_U5Imm }, },
  { 5595 /* evsrws */, PPC::EVSRWS, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5602 /* evsrwu */, PPC::EVSRWU, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5609 /* evstdd */, PPC::EVSTDD, Convert__RegSPERC1_0__DispSPE81_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegSPERC, MCK_DispSPE8, MCK_RegGxRCNoR0 }, },
  { 5616 /* evstddx */, PPC::EVSTDDX, Convert__RegSPERC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5624 /* evstdh */, PPC::EVSTDH, Convert__RegSPERC1_0__DispSPE81_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegSPERC, MCK_DispSPE8, MCK_RegGxRCNoR0 }, },
  { 5631 /* evstdhx */, PPC::EVSTDHX, Convert__RegSPERC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5639 /* evstdw */, PPC::EVSTDW, Convert__RegSPERC1_0__DispSPE81_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegSPERC, MCK_DispSPE8, MCK_RegGxRCNoR0 }, },
  { 5646 /* evstdwx */, PPC::EVSTDWX, Convert__RegSPERC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5654 /* evstwhe */, PPC::EVSTWHE, Convert__RegSPERC1_0__DispSPE41_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegSPERC, MCK_DispSPE4, MCK_RegGxRCNoR0 }, },
  { 5662 /* evstwhex */, PPC::EVSTWHEX, Convert__RegSPERC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5671 /* evstwho */, PPC::EVSTWHO, Convert__RegSPERC1_0__DispSPE41_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegSPERC, MCK_DispSPE4, MCK_RegGxRCNoR0 }, },
  { 5679 /* evstwhox */, PPC::EVSTWHOX, Convert__RegSPERC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5688 /* evstwwe */, PPC::EVSTWWE, Convert__RegSPERC1_0__DispSPE41_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegSPERC, MCK_DispSPE4, MCK_RegGxRCNoR0 }, },
  { 5696 /* evstwwex */, PPC::EVSTWWEX, Convert__RegSPERC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5705 /* evstwwo */, PPC::EVSTWWO, Convert__RegSPERC1_0__DispSPE41_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegSPERC, MCK_DispSPE4, MCK_RegGxRCNoR0 }, },
  { 5713 /* evstwwox */, PPC::EVSTWWOX, Convert__RegSPERC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5722 /* evsubfsmiaaw */, PPC::EVSUBFSMIAAW, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 5735 /* evsubfssiaaw */, PPC::EVSUBFSSIAAW, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 5748 /* evsubfumiaaw */, PPC::EVSUBFUMIAAW, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 5761 /* evsubfusiaaw */, PPC::EVSUBFUSIAAW, Convert__RegSPERC1_0__RegSPERC1_1, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC }, },
  { 5774 /* evsubfw */, PPC::EVSUBFW, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5782 /* evsubifw */, PPC::EVSUBIFW, Convert__RegSPERC1_0__U5Imm1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_U5Imm, MCK_RegSPERC }, },
  { 5791 /* evxor */, PPC::EVXOR, Convert__RegSPERC1_0__RegSPERC1_1__RegSPERC1_2, AMFBS_None, { MCK_RegSPERC, MCK_RegSPERC, MCK_RegSPERC }, },
  { 5797 /* extldi */, PPC::EXTLDI, Convert__RegG8RC1_0__RegG8RC1_1__U6Imm1_2__U6Imm1_3, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 5797 /* extldi */, PPC::EXTLDI_rec, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 5804 /* extlwi */, PPC::EXTLWI, Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2__U5Imm1_3, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 5804 /* extlwi */, PPC::EXTLWI_rec, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 5811 /* extrdi */, PPC::EXTRDI, Convert__RegG8RC1_0__RegG8RC1_1__U6Imm1_2__U6Imm1_3, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 5811 /* extrdi */, PPC::EXTRDI_rec, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 5818 /* extrwi */, PPC::EXTRWI, Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2__U5Imm1_3, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 5818 /* extrwi */, PPC::EXTRWI_rec, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 5825 /* extsb */, PPC::EXTSB, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 5825 /* extsb */, PPC::EXTSB_rec, Convert__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 5831 /* extsh */, PPC::EXTSH, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 5831 /* extsh */, PPC::EXTSH_rec, Convert__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 5837 /* extsw */, PPC::EXTSW, Convert__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 5837 /* extsw */, PPC::EXTSW_rec, Convert__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC }, },
  { 5843 /* extswsli */, PPC::EXTSWSLI, Convert__RegG8RC1_0__RegG8RC1_1__U6Imm1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 5843 /* extswsli */, PPC::EXTSWSLI_rec, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 5852 /* fabs */, PPC::FABSS, Convert__RegF4RC1_0__RegF4RC1_1, AMFBS_None, { MCK_RegF4RC, MCK_RegF4RC }, },
  { 5852 /* fabs */, PPC::FABSS_rec, Convert__RegF4RC1_1__RegF4RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5857 /* fadd */, PPC::FADD, Convert__RegF8RC1_0__RegF8RC1_1__RegF8RC1_2, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5857 /* fadd */, PPC::FADD_rec, Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5862 /* fadds */, PPC::FADDS, Convert__RegF4RC1_0__RegF4RC1_1__RegF4RC1_2, AMFBS_None, { MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5862 /* fadds */, PPC::FADDS_rec, Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5868 /* fcfid */, PPC::FCFID, Convert__RegF8RC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC }, },
  { 5868 /* fcfid */, PPC::FCFID_rec, Convert__RegF8RC1_1__RegF8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5874 /* fcfids */, PPC::FCFIDS, Convert__RegF4RC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegF4RC, MCK_RegF8RC }, },
  { 5874 /* fcfids */, PPC::FCFIDS_rec, Convert__RegF4RC1_1__RegF8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF8RC }, },
  { 5881 /* fcfidu */, PPC::FCFIDU, Convert__RegF8RC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC }, },
  { 5881 /* fcfidu */, PPC::FCFIDU_rec, Convert__RegF8RC1_1__RegF8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5888 /* fcfidus */, PPC::FCFIDUS, Convert__RegF4RC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegF4RC, MCK_RegF8RC }, },
  { 5888 /* fcfidus */, PPC::FCFIDUS_rec, Convert__RegF4RC1_1__RegF8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF8RC }, },
  { 5896 /* fcmpu */, PPC::FCMPUS, Convert__RegCRRC1_0__RegF4RC1_1__RegF4RC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5902 /* fcpsgn */, PPC::FCPSGNS, Convert__RegF4RC1_0__RegF4RC1_1__RegF4RC1_2, AMFBS_None, { MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5902 /* fcpsgn */, PPC::FCPSGNS_rec, Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5909 /* fctid */, PPC::FCTID, Convert__RegF8RC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC }, },
  { 5909 /* fctid */, PPC::FCTID_rec, Convert__RegF8RC1_1__RegF8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5915 /* fctidu */, PPC::FCTIDU, Convert__RegF8RC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC }, },
  { 5915 /* fctidu */, PPC::FCTIDU_rec, Convert__RegF8RC1_1__RegF8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5922 /* fctiduz */, PPC::FCTIDUZ, Convert__RegF8RC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC }, },
  { 5922 /* fctiduz */, PPC::FCTIDUZ_rec, Convert__RegF8RC1_1__RegF8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5930 /* fctidz */, PPC::FCTIDZ, Convert__RegF8RC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC }, },
  { 5930 /* fctidz */, PPC::FCTIDZ_rec, Convert__RegF8RC1_1__RegF8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5937 /* fctiw */, PPC::FCTIW, Convert__RegF8RC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC }, },
  { 5937 /* fctiw */, PPC::FCTIW_rec, Convert__RegF8RC1_1__RegF8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5943 /* fctiwu */, PPC::FCTIWU, Convert__RegF8RC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC }, },
  { 5943 /* fctiwu */, PPC::FCTIWU_rec, Convert__RegF8RC1_1__RegF8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5950 /* fctiwuz */, PPC::FCTIWUZ, Convert__RegF8RC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC }, },
  { 5950 /* fctiwuz */, PPC::FCTIWUZ_rec, Convert__RegF8RC1_1__RegF8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5958 /* fctiwz */, PPC::FCTIWZ, Convert__RegF8RC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC }, },
  { 5958 /* fctiwz */, PPC::FCTIWZ_rec, Convert__RegF8RC1_1__RegF8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5965 /* fdiv */, PPC::FDIV, Convert__RegF8RC1_0__RegF8RC1_1__RegF8RC1_2, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5965 /* fdiv */, PPC::FDIV_rec, Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5970 /* fdivs */, PPC::FDIVS, Convert__RegF4RC1_0__RegF4RC1_1__RegF4RC1_2, AMFBS_None, { MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5970 /* fdivs */, PPC::FDIVS_rec, Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5976 /* fmadd */, PPC::FMADD, Convert__RegF8RC1_0__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5976 /* fmadd */, PPC::FMADD_rec, Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5982 /* fmadds */, PPC::FMADDS, Convert__RegF4RC1_0__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3, AMFBS_None, { MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5982 /* fmadds */, PPC::FMADDS_rec, Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5989 /* fmr */, PPC::FMR, Convert__RegF4RC1_0__RegF4RC1_1, AMFBS_None, { MCK_RegF4RC, MCK_RegF4RC }, },
  { 5989 /* fmr */, PPC::FMR_rec, Convert__RegF4RC1_1__RegF4RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5993 /* fmsub */, PPC::FMSUB, Convert__RegF8RC1_0__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5993 /* fmsub */, PPC::FMSUB_rec, Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5999 /* fmsubs */, PPC::FMSUBS, Convert__RegF4RC1_0__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3, AMFBS_None, { MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5999 /* fmsubs */, PPC::FMSUBS_rec, Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 6006 /* fmul */, PPC::FMUL, Convert__RegF8RC1_0__RegF8RC1_1__RegF8RC1_2, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 6006 /* fmul */, PPC::FMUL_rec, Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 6011 /* fmuls */, PPC::FMULS, Convert__RegF4RC1_0__RegF4RC1_1__RegF4RC1_2, AMFBS_None, { MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 6011 /* fmuls */, PPC::FMULS_rec, Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 6017 /* fnabs */, PPC::FNABSS, Convert__RegF4RC1_0__RegF4RC1_1, AMFBS_None, { MCK_RegF4RC, MCK_RegF4RC }, },
  { 6017 /* fnabs */, PPC::FNABSS_rec, Convert__RegF4RC1_1__RegF4RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 6023 /* fneg */, PPC::FNEGS, Convert__RegF4RC1_0__RegF4RC1_1, AMFBS_None, { MCK_RegF4RC, MCK_RegF4RC }, },
  { 6023 /* fneg */, PPC::FNEGS_rec, Convert__RegF4RC1_1__RegF4RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 6028 /* fnmadd */, PPC::FNMADD, Convert__RegF8RC1_0__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 6028 /* fnmadd */, PPC::FNMADD_rec, Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 6035 /* fnmadds */, PPC::FNMADDS, Convert__RegF4RC1_0__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3, AMFBS_None, { MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 6035 /* fnmadds */, PPC::FNMADDS_rec, Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 6043 /* fnmsub */, PPC::FNMSUB, Convert__RegF8RC1_0__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 6043 /* fnmsub */, PPC::FNMSUB_rec, Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 6050 /* fnmsubs */, PPC::FNMSUBS, Convert__RegF4RC1_0__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3, AMFBS_None, { MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 6050 /* fnmsubs */, PPC::FNMSUBS_rec, Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 6058 /* fre */, PPC::FRE, Convert__RegF8RC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC }, },
  { 6058 /* fre */, PPC::FRE_rec, Convert__RegF8RC1_1__RegF8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 6062 /* fres */, PPC::FRES, Convert__RegF4RC1_0__RegF4RC1_1, AMFBS_None, { MCK_RegF4RC, MCK_RegF4RC }, },
  { 6062 /* fres */, PPC::FRES_rec, Convert__RegF4RC1_1__RegF4RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 6067 /* frim */, PPC::FRIMS, Convert__RegF4RC1_0__RegF4RC1_1, AMFBS_None, { MCK_RegF4RC, MCK_RegF4RC }, },
  { 6067 /* frim */, PPC::FRIMS_rec, Convert__RegF4RC1_1__RegF4RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 6072 /* frin */, PPC::FRINS, Convert__RegF4RC1_0__RegF4RC1_1, AMFBS_None, { MCK_RegF4RC, MCK_RegF4RC }, },
  { 6072 /* frin */, PPC::FRINS_rec, Convert__RegF4RC1_1__RegF4RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 6077 /* frip */, PPC::FRIPS, Convert__RegF4RC1_0__RegF4RC1_1, AMFBS_None, { MCK_RegF4RC, MCK_RegF4RC }, },
  { 6077 /* frip */, PPC::FRIPS_rec, Convert__RegF4RC1_1__RegF4RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 6082 /* friz */, PPC::FRIZS, Convert__RegF4RC1_0__RegF4RC1_1, AMFBS_None, { MCK_RegF4RC, MCK_RegF4RC }, },
  { 6082 /* friz */, PPC::FRIZS_rec, Convert__RegF4RC1_1__RegF4RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 6087 /* frsp */, PPC::FRSP, Convert__RegF4RC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegF4RC, MCK_RegF8RC }, },
  { 6087 /* frsp */, PPC::FRSP_rec, Convert__RegF4RC1_1__RegF8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF8RC }, },
  { 6092 /* frsqrte */, PPC::FRSQRTE, Convert__RegF8RC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC }, },
  { 6092 /* frsqrte */, PPC::FRSQRTE_rec, Convert__RegF8RC1_1__RegF8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 6100 /* frsqrtes */, PPC::FRSQRTES, Convert__RegF4RC1_0__RegF4RC1_1, AMFBS_None, { MCK_RegF4RC, MCK_RegF4RC }, },
  { 6100 /* frsqrtes */, PPC::FRSQRTES_rec, Convert__RegF4RC1_1__RegF4RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 6109 /* fsel */, PPC::FSELS, Convert__RegF4RC1_0__RegF8RC1_1__RegF4RC1_2__RegF4RC1_3, AMFBS_None, { MCK_RegF4RC, MCK_RegF8RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 6109 /* fsel */, PPC::FSELS_rec, Convert__RegF4RC1_1__RegF8RC1_2__RegF4RC1_3__RegF4RC1_4, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF8RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 6114 /* fsqrt */, PPC::FSQRT, Convert__RegF8RC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC }, },
  { 6114 /* fsqrt */, PPC::FSQRT_rec, Convert__RegF8RC1_1__RegF8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 6120 /* fsqrts */, PPC::FSQRTS, Convert__RegF4RC1_0__RegF4RC1_1, AMFBS_None, { MCK_RegF4RC, MCK_RegF4RC }, },
  { 6120 /* fsqrts */, PPC::FSQRTS_rec, Convert__RegF4RC1_1__RegF4RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 6127 /* fsub */, PPC::FSUB, Convert__RegF8RC1_0__RegF8RC1_1__RegF8RC1_2, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 6127 /* fsub */, PPC::FSUB_rec, Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 6132 /* fsubs */, PPC::FSUBS, Convert__RegF4RC1_0__RegF4RC1_1__RegF4RC1_2, AMFBS_None, { MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 6132 /* fsubs */, PPC::FSUBS_rec, Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 6138 /* ftdiv */, PPC::FTDIV, Convert__RegCRRC1_0__RegF8RC1_1__RegF8RC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 6144 /* ftsqrt */, PPC::FTSQRT, Convert__RegCRRC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegCRRC, MCK_RegF8RC }, },
  { 6151 /* hrfid */, PPC::HRFID, Convert_NoOperands, AMFBS_None, {  }, },
  { 6157 /* icbi */, PPC::ICBI, Convert__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6162 /* icbiep */, PPC::ICBIEP, Convert__RegGxRCNoR01_0__RegGxRC1_1, AMFBS_None, { MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6169 /* icblc */, PPC::ICBLC, Convert__U4Imm1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_U4Imm, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6175 /* icblq */, PPC::ICBLQ, Convert__U4Imm1_1__RegGxRCNoR01_2__RegGxRC1_3, AMFBS_None, { MCK__DOT_, MCK_U4Imm, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6181 /* icbt */, PPC::ICBT, Convert__U4Imm1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_U4Imm, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6186 /* icbtls */, PPC::ICBTLS, Convert__U4Imm1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_U4Imm, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6193 /* iccci */, PPC::ICCCI, Convert__regR0__regR0, AMFBS_None, {  }, },
  { 6193 /* iccci */, PPC::ICCCI, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 6199 /* ici */, PPC::ICCCI, Convert__regR0__regR0, AMFBS_None, { MCK_0 }, },
  { 6203 /* inslwi */, PPC::INSLWI, Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2__U5Imm1_3, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 6203 /* inslwi */, PPC::INSLWI_rec, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 6210 /* insrdi */, PPC::INSRDI, Convert__RegG8RC1_0__RegG8RC1_1__U6Imm1_2__U6Imm1_3, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 6210 /* insrdi */, PPC::INSRDI_rec, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 6217 /* insrwi */, PPC::INSRWI, Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2__U5Imm1_3, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 6217 /* insrwi */, PPC::INSRWI_rec, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 6224 /* isel */, PPC::ISEL, Convert__RegGPRC1_0__RegGPRCNoR01_1__RegGPRC1_2__RegCRBITRC1_3, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRCNoR0, MCK_RegGPRC, MCK_RegCRBITRC }, },
  { 6229 /* iseleq */, PPC::ISEL8, Convert__RegG8RC1_0__RegG8RCNoX01_1__RegG8RC1_2__regCR0EQ, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RCNoX0, MCK_RegG8RC }, },
  { 6229 /* iseleq */, PPC::ISEL, Convert__RegGPRC1_0__RegGPRCNoR01_1__RegGPRC1_2__regCR0EQ, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRCNoR0, MCK_RegGPRC }, },
  { 6236 /* iselgt */, PPC::ISEL8, Convert__RegG8RC1_0__RegG8RCNoX01_1__RegG8RC1_2__regCR0GT, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RCNoX0, MCK_RegG8RC }, },
  { 6236 /* iselgt */, PPC::ISEL, Convert__RegGPRC1_0__RegGPRCNoR01_1__RegGPRC1_2__regCR0GT, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRCNoR0, MCK_RegGPRC }, },
  { 6243 /* isellt */, PPC::ISEL8, Convert__RegG8RC1_0__RegG8RCNoX01_1__RegG8RC1_2__regCR0LT, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RCNoX0, MCK_RegG8RC }, },
  { 6243 /* isellt */, PPC::ISEL, Convert__RegGPRC1_0__RegGPRCNoR01_1__RegGPRC1_2__regCR0LT, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRCNoR0, MCK_RegGPRC }, },
  { 6250 /* isync */, PPC::ISYNC, Convert_NoOperands, AMFBS_None, {  }, },
  { 6256 /* la */, PPC::LAx, Convert__RegGPRC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 6259 /* lbarx */, PPC::LBARX, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6259 /* lbarx */, PPC::LBARXL, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_1 }, },
  { 6265 /* lbepx */, PPC::LBEPX, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6271 /* lbz */, PPC::LBZ, Convert__RegGPRC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 6275 /* lbzcix */, PPC::LBZCIX, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6282 /* lbzu */, PPC::LBZU, Convert__RegGPRC1_0__imm_95_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 6287 /* lbzux */, PPC::LBZUX, Convert__RegGPRC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6293 /* lbzx */, PPC::LBZXTLS_, Convert__RegG8RC1_0__RegGxRCNoR01_1__TLSReg1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_TLSReg }, },
  { 6293 /* lbzx */, PPC::LBZX, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6298 /* ld */, PPC::LD, Convert__RegG8RC1_0__DispRIX1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegG8RC, MCK_DispRIX, MCK_RegGxRCNoR0 }, },
  { 6301 /* ldarx */, PPC::LDARX, Convert__RegG8RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6301 /* ldarx */, PPC::LDARXL, Convert__RegG8RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_1 }, },
  { 6307 /* ldat */, PPC::LDAT, Convert__RegG8RC1_0__RegG8RC1_1__U5Imm1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U5Imm }, },
  { 6312 /* ldbrx */, PPC::LDBRX, Convert__RegG8RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6318 /* ldcix */, PPC::LDCIX, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6324 /* ldmx */, PPC::LDMX, Convert__RegG8RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6329 /* ldu */, PPC::LDU, Convert__RegG8RC1_0__imm_95_0__DispRIX1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegG8RC, MCK_DispRIX, MCK_RegGxRCNoR0 }, },
  { 6333 /* ldux */, PPC::LDUX, Convert__RegG8RC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6338 /* ldx */, PPC::LDX, Convert__RegG8RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6338 /* ldx */, PPC::LDXTLS_, Convert__RegG8RC1_0__RegGxRCNoR01_1__TLSReg1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_TLSReg }, },
  { 6342 /* lfd */, PPC::LFD, Convert__RegF8RC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegF8RC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 6346 /* lfdepx */, PPC::LFDEPX, Convert__RegF8RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegF8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6353 /* lfdu */, PPC::LFDU, Convert__RegF8RC1_0__imm_95_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegF8RC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 6358 /* lfdux */, PPC::LFDUX, Convert__RegF8RC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegF8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6364 /* lfdx */, PPC::LFDX, Convert__RegF8RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegF8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6369 /* lfiwax */, PPC::LFIWAX, Convert__RegF8RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegF8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6376 /* lfiwzx */, PPC::LFIWZX, Convert__RegF8RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegF8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6383 /* lfs */, PPC::LFS, Convert__RegF4RC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegF4RC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 6387 /* lfsu */, PPC::LFSU, Convert__RegF4RC1_0__imm_95_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegF4RC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 6392 /* lfsux */, PPC::LFSUX, Convert__RegF4RC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegF4RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6398 /* lfsx */, PPC::LFSX, Convert__RegF4RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegF4RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6403 /* lha */, PPC::LHA, Convert__RegGPRC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 6407 /* lharx */, PPC::LHARX, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6407 /* lharx */, PPC::LHARXL, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_1 }, },
  { 6413 /* lhau */, PPC::LHAU, Convert__RegGPRC1_0__imm_95_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 6418 /* lhaux */, PPC::LHAUX, Convert__RegGPRC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6424 /* lhax */, PPC::LHAX, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6429 /* lhbrx */, PPC::LHBRX, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6435 /* lhepx */, PPC::LHEPX, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6441 /* lhz */, PPC::LHZ, Convert__RegGPRC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 6445 /* lhzcix */, PPC::LHZCIX, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6452 /* lhzu */, PPC::LHZU, Convert__RegGPRC1_0__imm_95_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 6457 /* lhzux */, PPC::LHZUX, Convert__RegGPRC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6463 /* lhzx */, PPC::LHZXTLS_, Convert__RegG8RC1_0__RegGxRCNoR01_1__TLSReg1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_TLSReg }, },
  { 6463 /* lhzx */, PPC::LHZX, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6468 /* li */, PPC::ADDI8, Convert__RegG8RC1_0__regZERO8__S16Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_S16Imm }, },
  { 6468 /* li */, PPC::LI, Convert__RegGPRC1_0__S16Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S16Imm }, },
  { 6468 /* li */, PPC::ADDI, Convert__RegGPRC1_0__regZERO__S16Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S16Imm }, },
  { 6471 /* lis */, PPC::ADDIS8, Convert__RegG8RC1_0__regZERO8__S17Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_S17Imm }, },
  { 6471 /* lis */, PPC::LIS, Convert__RegGPRC1_0__S17Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S17Imm }, },
  { 6471 /* lis */, PPC::ADDIS, Convert__RegGPRC1_0__regZERO__S17Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S17Imm }, },
  { 6475 /* lmw */, PPC::LMW, Convert__RegGPRC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 6479 /* lnia */, PPC::ADDPCIS, Convert__RegG8RC1_0__imm_95_0, AMFBS_None, { MCK_RegG8RC }, },
  { 6484 /* lswi */, PPC::LSWI, Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 6489 /* lvebx */, PPC::LVEBX, Convert__RegVRRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6495 /* lvehx */, PPC::LVEHX, Convert__RegVRRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6501 /* lvewx */, PPC::LVEWX, Convert__RegVRRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6507 /* lvsl */, PPC::LVSL, Convert__RegVRRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6512 /* lvsr */, PPC::LVSR, Convert__RegVRRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6517 /* lvx */, PPC::LVX, Convert__RegVRRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6521 /* lvxl */, PPC::LVXL, Convert__RegVRRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6526 /* lwa */, PPC::LWA, Convert__RegG8RC1_0__DispRIX1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegG8RC, MCK_DispRIX, MCK_RegGxRCNoR0 }, },
  { 6530 /* lwarx */, PPC::LWARX, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6530 /* lwarx */, PPC::LWARXL, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_1 }, },
  { 6536 /* lwat */, PPC::LWAT, Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 6541 /* lwaux */, PPC::LWAUX, Convert__RegG8RC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6547 /* lwax */, PPC::LWAX, Convert__RegG8RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6552 /* lwbrx */, PPC::LWBRX, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6558 /* lwepx */, PPC::LWEPX, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6564 /* lwsync */, PPC::SYNC, Convert__imm_95_1, AMFBS_None, {  }, },
  { 6571 /* lwz */, PPC::LWZ, Convert__RegGPRC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 6571 /* lwz */, PPC::SPELWZ, Convert__RegSPE4RC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegSPE4RC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 6575 /* lwzcix */, PPC::LWZCIX, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6582 /* lwzu */, PPC::LWZU, Convert__RegGPRC1_0__imm_95_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 6587 /* lwzux */, PPC::LWZUX, Convert__RegGPRC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6593 /* lwzx */, PPC::LWZXTLS_, Convert__RegG8RC1_0__RegGxRCNoR01_1__TLSReg1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_TLSReg }, },
  { 6593 /* lwzx */, PPC::LWZX, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6593 /* lwzx */, PPC::SPELWZX, Convert__RegSPE4RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegSPE4RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6598 /* lxsd */, PPC::LXSD, Convert__RegVFRC1_0__DispRIX1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegVFRC, MCK_DispRIX, MCK_RegGxRCNoR0 }, },
  { 6603 /* lxsdx */, PPC::LXSDX, Convert__RegVSFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6609 /* lxsibzx */, PPC::LXSIBZX, Convert__RegVSFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6617 /* lxsihzx */, PPC::LXSIHZX, Convert__RegVSFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6625 /* lxsiwax */, PPC::LXSIWAX, Convert__RegVSFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6633 /* lxsiwzx */, PPC::LXSIWZX, Convert__RegVSFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6641 /* lxssp */, PPC::LXSSP, Convert__RegVFRC1_0__DispRIX1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegVFRC, MCK_DispRIX, MCK_RegGxRCNoR0 }, },
  { 6647 /* lxsspx */, PPC::LXSSPX, Convert__RegVSSRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6654 /* lxv */, PPC::LXV, Convert__RegVSRC1_0__DispRIX161_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegVSRC, MCK_DispRIX16, MCK_RegGxRCNoR0 }, },
  { 6658 /* lxvb16x */, PPC::LXVB16X, Convert__RegVSRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6666 /* lxvd2x */, PPC::LXVD2X, Convert__RegVSRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6673 /* lxvdsx */, PPC::LXVDSX, Convert__RegVSRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6680 /* lxvh8x */, PPC::LXVH8X, Convert__RegVSRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6687 /* lxvl */, PPC::LXVL, Convert__RegVSRC1_0__Imm1_1__RegG8RC1_2, AMFBS_None, { MCK_RegVSRC, MCK_Imm, MCK_RegG8RC }, },
  { 6692 /* lxvll */, PPC::LXVLL, Convert__RegVSRC1_0__Imm1_1__RegG8RC1_2, AMFBS_None, { MCK_RegVSRC, MCK_Imm, MCK_RegG8RC }, },
  { 6698 /* lxvw4x */, PPC::LXVW4X, Convert__RegVSRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6705 /* lxvwsx */, PPC::LXVWSX, Convert__RegVSRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6712 /* lxvx */, PPC::LXVX, Convert__RegVSRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 6717 /* maddhd */, PPC::MADDHD, Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 6724 /* maddhdu */, PPC::MADDHDU, Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 6732 /* maddld */, PPC::MADDLD, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6739 /* mbar */, PPC::MBAR, Convert__imm_95_0, AMFBS_None, {  }, },
  { 6739 /* mbar */, PPC::MBAR, Convert__U5Imm1_0, AMFBS_None, { MCK_U5Imm }, },
  { 6744 /* mcrf */, PPC::MCRF, Convert__RegCRRC1_0__RegCRRC1_1, AMFBS_None, { MCK_RegCRRC, MCK_RegCRRC }, },
  { 6749 /* mcrfs */, PPC::MCRFS, Convert__RegCRRC1_0__RegCRRC1_1, AMFBS_None, { MCK_RegCRRC, MCK_RegCRRC }, },
  { 6755 /* mcrxrx */, PPC::MCRXRX, Convert__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 6762 /* mfamr */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_29, AMFBS_None, { MCK_RegGPRC }, },
  { 6768 /* mfasr */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_280, AMFBS_None, { MCK_RegGPRC }, },
  { 6774 /* mfbhrbe */, PPC::MFBHRBE, Convert__RegGPRC1_0__U10Imm1_1__imm_95_0, AMFBS_None, { MCK_RegGPRC, MCK_U10Imm }, },
  { 6782 /* mfbr0 */, PPC::MFDCR, Convert__RegGPRC1_0__imm_95_128, AMFBS_None, { MCK_RegGPRC }, },
  { 6788 /* mfbr1 */, PPC::MFDCR, Convert__RegGPRC1_0__imm_95_129, AMFBS_None, { MCK_RegGPRC }, },
  { 6794 /* mfbr2 */, PPC::MFDCR, Convert__RegGPRC1_0__imm_95_130, AMFBS_None, { MCK_RegGPRC }, },
  { 6800 /* mfbr3 */, PPC::MFDCR, Convert__RegGPRC1_0__imm_95_131, AMFBS_None, { MCK_RegGPRC }, },
  { 6806 /* mfbr4 */, PPC::MFDCR, Convert__RegGPRC1_0__imm_95_132, AMFBS_None, { MCK_RegGPRC }, },
  { 6812 /* mfbr5 */, PPC::MFDCR, Convert__RegGPRC1_0__imm_95_133, AMFBS_None, { MCK_RegGPRC }, },
  { 6818 /* mfbr6 */, PPC::MFDCR, Convert__RegGPRC1_0__imm_95_134, AMFBS_None, { MCK_RegGPRC }, },
  { 6824 /* mfbr7 */, PPC::MFDCR, Convert__RegGPRC1_0__imm_95_135, AMFBS_None, { MCK_RegGPRC }, },
  { 6830 /* mfcfar */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_28, AMFBS_None, { MCK_RegGPRC }, },
  { 6837 /* mfcr */, PPC::MFCR, Convert__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 6842 /* mfctr */, PPC::MFCTR, Convert__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 6848 /* mfdar */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_19, AMFBS_None, { MCK_RegGPRC }, },
  { 6854 /* mfdbatl */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_537, AMFBS_None, { MCK_RegGPRC, MCK_0 }, },
  { 6854 /* mfdbatl */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_539, AMFBS_None, { MCK_RegGPRC, MCK_1 }, },
  { 6854 /* mfdbatl */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_541, AMFBS_None, { MCK_RegGPRC, MCK_2 }, },
  { 6854 /* mfdbatl */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_543, AMFBS_None, { MCK_RegGPRC, MCK_3 }, },
  { 6862 /* mfdbatu */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_536, AMFBS_None, { MCK_RegGPRC, MCK_0 }, },
  { 6862 /* mfdbatu */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_538, AMFBS_None, { MCK_RegGPRC, MCK_1 }, },
  { 6862 /* mfdbatu */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_540, AMFBS_None, { MCK_RegGPRC, MCK_2 }, },
  { 6862 /* mfdbatu */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_542, AMFBS_None, { MCK_RegGPRC, MCK_3 }, },
  { 6870 /* mfdccr */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_1018, AMFBS_None, { MCK_RegGPRC }, },
  { 6877 /* mfdcr */, PPC::MFDCR, Convert__RegGPRC1_0__Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_Imm }, },
  { 6883 /* mfdear */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_981, AMFBS_None, { MCK_RegGPRC }, },
  { 6890 /* mfdec */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_22, AMFBS_None, { MCK_RegGPRC }, },
  { 6896 /* mfdscr */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_17, AMFBS_None, { MCK_RegGPRC }, },
  { 6903 /* mfdsisr */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_18, AMFBS_None, { MCK_RegGPRC }, },
  { 6911 /* mfesr */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_980, AMFBS_None, { MCK_RegGPRC }, },
  { 6917 /* mffprd */, PPC::MFVSRD, Convert__RegG8RC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegF8RC }, },
  { 6924 /* mffprwz */, PPC::MFVSRWZ, Convert__RegGPRC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegF8RC }, },
  { 6932 /* mffs */, PPC::MFFS, Convert__RegF8RC1_0, AMFBS_None, { MCK_RegF8RC }, },
  { 6932 /* mffs */, PPC::MFFS_rec, Convert__RegF8RC1_1, AMFBS_None, { MCK__DOT_, MCK_RegF8RC }, },
  { 6937 /* mffscdrn */, PPC::MFFSCDRN, Convert__RegF8RC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC }, },
  { 6946 /* mffscdrni */, PPC::MFFSCDRNI, Convert__RegF8RC1_0__U3Imm1_1, AMFBS_None, { MCK_RegF8RC, MCK_U3Imm }, },
  { 6956 /* mffsce */, PPC::MFFSCE, Convert__RegF8RC1_0, AMFBS_None, { MCK_RegF8RC }, },
  { 6963 /* mffscrn */, PPC::MFFSCRN, Convert__RegF8RC1_0__RegF8RC1_1, AMFBS_None, { MCK_RegF8RC, MCK_RegF8RC }, },
  { 6971 /* mffscrni */, PPC::MFFSCRNI, Convert__RegF8RC1_0__U2Imm1_1, AMFBS_None, { MCK_RegF8RC, MCK_U2Imm }, },
  { 6980 /* mffsl */, PPC::MFFSL, Convert__RegF8RC1_0, AMFBS_None, { MCK_RegF8RC }, },
  { 6986 /* mfibatl */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_529, AMFBS_None, { MCK_RegGPRC, MCK_0 }, },
  { 6986 /* mfibatl */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_531, AMFBS_None, { MCK_RegGPRC, MCK_1 }, },
  { 6986 /* mfibatl */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_533, AMFBS_None, { MCK_RegGPRC, MCK_2 }, },
  { 6986 /* mfibatl */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_535, AMFBS_None, { MCK_RegGPRC, MCK_3 }, },
  { 6994 /* mfibatu */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_528, AMFBS_None, { MCK_RegGPRC, MCK_0 }, },
  { 6994 /* mfibatu */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_530, AMFBS_None, { MCK_RegGPRC, MCK_1 }, },
  { 6994 /* mfibatu */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_532, AMFBS_None, { MCK_RegGPRC, MCK_2 }, },
  { 6994 /* mfibatu */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_534, AMFBS_None, { MCK_RegGPRC, MCK_3 }, },
  { 7002 /* mficcr */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_1019, AMFBS_None, { MCK_RegGPRC }, },
  { 7009 /* mflr */, PPC::MFLR, Convert__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7014 /* mfmsr */, PPC::MFMSR, Convert__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7020 /* mfocrf */, PPC::MFOCRF, Convert__RegGPRC1_0__CRBitMask1_1, AMFBS_None, { MCK_RegGPRC, MCK_CRBitMask }, },
  { 7027 /* mfpid */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_48, AMFBS_None, { MCK_RegGPRC }, },
  { 7033 /* mfpmr */, PPC::MFPMR, Convert__RegGPRC1_0__Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_Imm }, },
  { 7039 /* mfpvr */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_287, AMFBS_None, { MCK_RegGPRC }, },
  { 7045 /* mfrtcl */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_5, AMFBS_None, { MCK_RegGPRC }, },
  { 7052 /* mfrtcu */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_4, AMFBS_None, { MCK_RegGPRC }, },
  { 7059 /* mfsdr1 */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_25, AMFBS_None, { MCK_RegGPRC }, },
  { 7066 /* mfspefscr */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_512, AMFBS_None, { MCK_RegGPRC }, },
  { 7076 /* mfspr */, PPC::MFSPR, Convert__RegGPRC1_0__Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_Imm }, },
  { 7082 /* mfsprg */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_272, AMFBS_None, { MCK_RegGPRC, MCK_0 }, },
  { 7082 /* mfsprg */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_273, AMFBS_None, { MCK_RegGPRC, MCK_1 }, },
  { 7082 /* mfsprg */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_274, AMFBS_None, { MCK_RegGPRC, MCK_2 }, },
  { 7082 /* mfsprg */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_275, AMFBS_None, { MCK_RegGPRC, MCK_3 }, },
  { 7082 /* mfsprg */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_260, AMFBS_None, { MCK_RegGPRC, MCK_4 }, },
  { 7082 /* mfsprg */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_261, AMFBS_None, { MCK_RegGPRC, MCK_5 }, },
  { 7082 /* mfsprg */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_262, AMFBS_None, { MCK_RegGPRC, MCK_6 }, },
  { 7082 /* mfsprg */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_263, AMFBS_None, { MCK_RegGPRC, MCK_7 }, },
  { 7089 /* mfsprg0 */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_272, AMFBS_None, { MCK_RegGPRC }, },
  { 7097 /* mfsprg1 */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_273, AMFBS_None, { MCK_RegGPRC }, },
  { 7105 /* mfsprg2 */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_274, AMFBS_None, { MCK_RegGPRC }, },
  { 7113 /* mfsprg3 */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_275, AMFBS_None, { MCK_RegGPRC }, },
  { 7121 /* mfsprg4 */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_260, AMFBS_None, { MCK_RegGPRC }, },
  { 7129 /* mfsprg5 */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_261, AMFBS_None, { MCK_RegGPRC }, },
  { 7137 /* mfsprg6 */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_262, AMFBS_None, { MCK_RegGPRC }, },
  { 7145 /* mfsprg7 */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_263, AMFBS_None, { MCK_RegGPRC }, },
  { 7153 /* mfsr */, PPC::MFSR, Convert__RegGPRC1_0__U4Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_U4Imm }, },
  { 7158 /* mfsrin */, PPC::MFSRIN, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 7165 /* mfsrr0 */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_26, AMFBS_None, { MCK_RegGPRC }, },
  { 7172 /* mfsrr1 */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_27, AMFBS_None, { MCK_RegGPRC }, },
  { 7179 /* mfsrr2 */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_990, AMFBS_None, { MCK_RegGPRC }, },
  { 7186 /* mfsrr3 */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_991, AMFBS_None, { MCK_RegGPRC }, },
  { 7193 /* mftb */, PPC::MFTB, Convert__RegGPRC1_0__imm_95_268, AMFBS_None, { MCK_RegGPRC }, },
  { 7193 /* mftb */, PPC::MFTB, Convert__RegGPRC1_0__Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_Imm }, },
  { 7198 /* mftbhi */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_988, AMFBS_None, { MCK_RegGPRC }, },
  { 7205 /* mftbl */, PPC::MFTB, Convert__RegGPRC1_0__imm_95_268, AMFBS_None, { MCK_RegGPRC }, },
  { 7211 /* mftblo */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_989, AMFBS_None, { MCK_RegGPRC }, },
  { 7218 /* mftbu */, PPC::MFTB, Convert__RegGPRC1_0__imm_95_269, AMFBS_None, { MCK_RegGPRC }, },
  { 7224 /* mftcr */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_986, AMFBS_None, { MCK_RegGPRC }, },
  { 7230 /* mfvrd */, PPC::MFVRD, Convert__RegG8RC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegVRRC }, },
  { 7236 /* mfvrsave */, PPC::MFVRSAVE, Convert__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7245 /* mfvrwz */, PPC::MFVRWZ, Convert__RegGPRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegVRRC }, },
  { 7252 /* mfvscr */, PPC::MFVSCR, Convert__RegVRRC1_0, AMFBS_None, { MCK_RegVRRC }, },
  { 7259 /* mfvsrd */, PPC::MFVSRD, Convert__RegG8RC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegVSFRC }, },
  { 7266 /* mfvsrld */, PPC::MFVSRLD, Convert__RegG8RC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegVSRC }, },
  { 7274 /* mfvsrwz */, PPC::MFVSRWZ, Convert__RegGPRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegVSFRC }, },
  { 7282 /* mfxer */, PPC::MFSPR, Convert__RegGPRC1_0__imm_95_1, AMFBS_None, { MCK_RegGPRC }, },
  { 7288 /* modsd */, PPC::MODSD, Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 7294 /* modsw */, PPC::MODSW, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7300 /* modud */, PPC::MODUD, Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 7306 /* moduw */, PPC::MODUW, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7312 /* mr */, PPC::OR8, Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 7312 /* mr */, PPC::OR, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 7312 /* mr */, PPC::OR8_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC }, },
  { 7312 /* mr */, PPC::OR_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7315 /* msgsync */, PPC::MSGSYNC, Convert_NoOperands, AMFBS_None, {  }, },
  { 7323 /* msync */, PPC::SYNC, Convert__imm_95_0, AMFBS_None, {  }, },
  { 7329 /* mtamr */, PPC::MTSPR, Convert__imm_95_29__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7335 /* mtasr */, PPC::MTSPR, Convert__imm_95_280__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7341 /* mtbr0 */, PPC::MTDCR, Convert__RegGPRC1_0__imm_95_128, AMFBS_None, { MCK_RegGPRC }, },
  { 7347 /* mtbr1 */, PPC::MTDCR, Convert__RegGPRC1_0__imm_95_129, AMFBS_None, { MCK_RegGPRC }, },
  { 7353 /* mtbr2 */, PPC::MTDCR, Convert__RegGPRC1_0__imm_95_130, AMFBS_None, { MCK_RegGPRC }, },
  { 7359 /* mtbr3 */, PPC::MTDCR, Convert__RegGPRC1_0__imm_95_131, AMFBS_None, { MCK_RegGPRC }, },
  { 7365 /* mtbr4 */, PPC::MTDCR, Convert__RegGPRC1_0__imm_95_132, AMFBS_None, { MCK_RegGPRC }, },
  { 7371 /* mtbr5 */, PPC::MTDCR, Convert__RegGPRC1_0__imm_95_133, AMFBS_None, { MCK_RegGPRC }, },
  { 7377 /* mtbr6 */, PPC::MTDCR, Convert__RegGPRC1_0__imm_95_134, AMFBS_None, { MCK_RegGPRC }, },
  { 7383 /* mtbr7 */, PPC::MTDCR, Convert__RegGPRC1_0__imm_95_135, AMFBS_None, { MCK_RegGPRC }, },
  { 7389 /* mtcfar */, PPC::MTSPR, Convert__imm_95_28__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7396 /* mtcr */, PPC::MTCRF8, Convert__imm_95_255__RegG8RC1_0, AMFBS_None, { MCK_RegG8RC }, },
  { 7396 /* mtcr */, PPC::MTCRF, Convert__imm_95_255__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7401 /* mtcrf */, PPC::MTCRF, Convert__Imm1_0__RegGPRC1_1, AMFBS_None, { MCK_Imm, MCK_RegGPRC }, },
  { 7407 /* mtctr */, PPC::MTCTR, Convert__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7413 /* mtdar */, PPC::MTSPR, Convert__imm_95_19__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7419 /* mtdbatl */, PPC::MTSPR, Convert__imm_95_537__RegGPRC1_1, AMFBS_None, { MCK_0, MCK_RegGPRC }, },
  { 7419 /* mtdbatl */, PPC::MTSPR, Convert__imm_95_539__RegGPRC1_1, AMFBS_None, { MCK_1, MCK_RegGPRC }, },
  { 7419 /* mtdbatl */, PPC::MTSPR, Convert__imm_95_541__RegGPRC1_1, AMFBS_None, { MCK_2, MCK_RegGPRC }, },
  { 7419 /* mtdbatl */, PPC::MTSPR, Convert__imm_95_543__RegGPRC1_1, AMFBS_None, { MCK_3, MCK_RegGPRC }, },
  { 7427 /* mtdbatu */, PPC::MTSPR, Convert__imm_95_536__RegGPRC1_1, AMFBS_None, { MCK_0, MCK_RegGPRC }, },
  { 7427 /* mtdbatu */, PPC::MTSPR, Convert__imm_95_538__RegGPRC1_1, AMFBS_None, { MCK_1, MCK_RegGPRC }, },
  { 7427 /* mtdbatu */, PPC::MTSPR, Convert__imm_95_540__RegGPRC1_1, AMFBS_None, { MCK_2, MCK_RegGPRC }, },
  { 7427 /* mtdbatu */, PPC::MTSPR, Convert__imm_95_542__RegGPRC1_1, AMFBS_None, { MCK_3, MCK_RegGPRC }, },
  { 7435 /* mtdccr */, PPC::MTSPR, Convert__imm_95_1018__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7442 /* mtdcr */, PPC::MTDCR, Convert__RegGPRC1_1__Imm1_0, AMFBS_None, { MCK_Imm, MCK_RegGPRC }, },
  { 7448 /* mtdear */, PPC::MTSPR, Convert__imm_95_981__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7455 /* mtdec */, PPC::MTSPR, Convert__imm_95_22__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7461 /* mtdscr */, PPC::MTSPR, Convert__imm_95_17__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7468 /* mtdsisr */, PPC::MTSPR, Convert__imm_95_18__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7476 /* mtesr */, PPC::MTSPR, Convert__imm_95_980__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7482 /* mtfprd */, PPC::MTVSRD, Convert__RegF8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegF8RC, MCK_RegG8RC }, },
  { 7489 /* mtfprwa */, PPC::MTVSRWA, Convert__RegF8RC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegF8RC, MCK_RegGPRC }, },
  { 7497 /* mtfprwz */, PPC::MTVSRWZ, Convert__RegF8RC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegF8RC, MCK_RegGPRC }, },
  { 7505 /* mtfsb0 */, PPC::MTFSB0, Convert__U5Imm1_0, AMFBS_None, { MCK_U5Imm }, },
  { 7512 /* mtfsb1 */, PPC::MTFSB1, Convert__U5Imm1_0, AMFBS_None, { MCK_U5Imm }, },
  { 7519 /* mtfsf */, PPC::MTFSF, Convert__Imm1_0__RegF8RC1_1__imm_95_0__imm_95_0, AMFBS_None, { MCK_Imm, MCK_RegF8RC }, },
  { 7519 /* mtfsf */, PPC::MTFSF_rec, Convert__Imm1_1__RegF8RC1_2__imm_95_0__imm_95_0, AMFBS_None, { MCK__DOT_, MCK_Imm, MCK_RegF8RC }, },
  { 7519 /* mtfsf */, PPC::MTFSF, Convert__Imm1_0__RegF8RC1_1__Imm1_2__Imm1_3, AMFBS_None, { MCK_Imm, MCK_RegF8RC, MCK_Imm, MCK_Imm }, },
  { 7519 /* mtfsf */, PPC::MTFSF_rec, Convert__Imm1_1__RegF8RC1_2__Imm1_3__Imm1_4, AMFBS_None, { MCK__DOT_, MCK_Imm, MCK_RegF8RC, MCK_Imm, MCK_Imm }, },
  { 7525 /* mtfsfi */, PPC::MTFSFI, Convert__RegCRRC1_0__Imm1_1__imm_95_0, AMFBS_None, { MCK_RegCRRC, MCK_Imm }, },
  { 7525 /* mtfsfi */, PPC::MTFSFI_rec, Convert__RegCRRC1_1__Imm1_2__imm_95_0, AMFBS_None, { MCK__DOT_, MCK_RegCRRC, MCK_Imm }, },
  { 7525 /* mtfsfi */, PPC::MTFSFI, Convert__RegCRRC1_0__Imm1_1__Imm1_2, AMFBS_None, { MCK_RegCRRC, MCK_Imm, MCK_Imm }, },
  { 7525 /* mtfsfi */, PPC::MTFSFI_rec, Convert__RegCRRC1_1__Imm1_2__Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegCRRC, MCK_Imm, MCK_Imm }, },
  { 7532 /* mtibatl */, PPC::MTSPR, Convert__imm_95_529__RegGPRC1_1, AMFBS_None, { MCK_0, MCK_RegGPRC }, },
  { 7532 /* mtibatl */, PPC::MTSPR, Convert__imm_95_531__RegGPRC1_1, AMFBS_None, { MCK_1, MCK_RegGPRC }, },
  { 7532 /* mtibatl */, PPC::MTSPR, Convert__imm_95_533__RegGPRC1_1, AMFBS_None, { MCK_2, MCK_RegGPRC }, },
  { 7532 /* mtibatl */, PPC::MTSPR, Convert__imm_95_535__RegGPRC1_1, AMFBS_None, { MCK_3, MCK_RegGPRC }, },
  { 7540 /* mtibatu */, PPC::MTSPR, Convert__imm_95_528__RegGPRC1_1, AMFBS_None, { MCK_0, MCK_RegGPRC }, },
  { 7540 /* mtibatu */, PPC::MTSPR, Convert__imm_95_530__RegGPRC1_1, AMFBS_None, { MCK_1, MCK_RegGPRC }, },
  { 7540 /* mtibatu */, PPC::MTSPR, Convert__imm_95_532__RegGPRC1_1, AMFBS_None, { MCK_2, MCK_RegGPRC }, },
  { 7540 /* mtibatu */, PPC::MTSPR, Convert__imm_95_534__RegGPRC1_1, AMFBS_None, { MCK_3, MCK_RegGPRC }, },
  { 7548 /* mticcr */, PPC::MTSPR, Convert__imm_95_1019__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7555 /* mtlr */, PPC::MTLR, Convert__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7560 /* mtmsr */, PPC::MTMSR, Convert__RegGPRC1_0__imm_95_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7560 /* mtmsr */, PPC::MTMSR, Convert__RegGPRC1_0__Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_Imm }, },
  { 7566 /* mtmsrd */, PPC::MTMSRD, Convert__RegGPRC1_0__imm_95_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7566 /* mtmsrd */, PPC::MTMSRD, Convert__RegGPRC1_0__Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_Imm }, },
  { 7573 /* mtocrf */, PPC::MTOCRF, Convert__CRBitMask1_0__RegGPRC1_1, AMFBS_None, { MCK_CRBitMask, MCK_RegGPRC }, },
  { 7580 /* mtpid */, PPC::MTSPR, Convert__imm_95_48__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7586 /* mtpmr */, PPC::MTPMR, Convert__Imm1_0__RegGPRC1_1, AMFBS_None, { MCK_Imm, MCK_RegGPRC }, },
  { 7592 /* mtsdr1 */, PPC::MTSPR, Convert__imm_95_25__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7599 /* mtspefscr */, PPC::MTSPR, Convert__imm_95_512__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7609 /* mtspr */, PPC::MTSPR, Convert__Imm1_0__RegGPRC1_1, AMFBS_None, { MCK_Imm, MCK_RegGPRC }, },
  { 7615 /* mtsprg */, PPC::MTSPR, Convert__imm_95_272__RegGPRC1_1, AMFBS_None, { MCK_0, MCK_RegGPRC }, },
  { 7615 /* mtsprg */, PPC::MTSPR, Convert__imm_95_273__RegGPRC1_1, AMFBS_None, { MCK_1, MCK_RegGPRC }, },
  { 7615 /* mtsprg */, PPC::MTSPR, Convert__imm_95_274__RegGPRC1_1, AMFBS_None, { MCK_2, MCK_RegGPRC }, },
  { 7615 /* mtsprg */, PPC::MTSPR, Convert__imm_95_275__RegGPRC1_1, AMFBS_None, { MCK_3, MCK_RegGPRC }, },
  { 7615 /* mtsprg */, PPC::MTSPR, Convert__imm_95_260__RegGPRC1_1, AMFBS_None, { MCK_4, MCK_RegGPRC }, },
  { 7615 /* mtsprg */, PPC::MTSPR, Convert__imm_95_261__RegGPRC1_1, AMFBS_None, { MCK_5, MCK_RegGPRC }, },
  { 7615 /* mtsprg */, PPC::MTSPR, Convert__imm_95_262__RegGPRC1_1, AMFBS_None, { MCK_6, MCK_RegGPRC }, },
  { 7615 /* mtsprg */, PPC::MTSPR, Convert__imm_95_263__RegGPRC1_1, AMFBS_None, { MCK_7, MCK_RegGPRC }, },
  { 7622 /* mtsprg0 */, PPC::MTSPR, Convert__imm_95_272__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7630 /* mtsprg1 */, PPC::MTSPR, Convert__imm_95_273__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7638 /* mtsprg2 */, PPC::MTSPR, Convert__imm_95_274__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7646 /* mtsprg3 */, PPC::MTSPR, Convert__imm_95_275__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7654 /* mtsprg4 */, PPC::MTSPR, Convert__imm_95_260__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7662 /* mtsprg5 */, PPC::MTSPR, Convert__imm_95_261__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7670 /* mtsprg6 */, PPC::MTSPR, Convert__imm_95_262__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7678 /* mtsprg7 */, PPC::MTSPR, Convert__imm_95_263__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7686 /* mtsr */, PPC::MTSR, Convert__RegGPRC1_1__U4Imm1_0, AMFBS_None, { MCK_U4Imm, MCK_RegGPRC }, },
  { 7691 /* mtsrin */, PPC::MTSRIN, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 7698 /* mtsrr0 */, PPC::MTSPR, Convert__imm_95_26__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7705 /* mtsrr1 */, PPC::MTSPR, Convert__imm_95_27__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7712 /* mtsrr2 */, PPC::MTSPR, Convert__imm_95_990__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7719 /* mtsrr3 */, PPC::MTSPR, Convert__imm_95_991__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7726 /* mttbhi */, PPC::MTSPR, Convert__imm_95_988__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7733 /* mttbl */, PPC::MTSPR, Convert__imm_95_284__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7739 /* mttblo */, PPC::MTSPR, Convert__imm_95_989__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7746 /* mttbu */, PPC::MTSPR, Convert__imm_95_285__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7752 /* mttcr */, PPC::MTSPR, Convert__imm_95_986__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7758 /* mtvrd */, PPC::MTVRD, Convert__RegVRRC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegG8RC }, },
  { 7764 /* mtvrsave */, PPC::MTVRSAVE, Convert__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7773 /* mtvrwa */, PPC::MTVRWA, Convert__RegVRRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegGPRC }, },
  { 7780 /* mtvrwz */, PPC::MTVRWZ, Convert__RegVRRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegGPRC }, },
  { 7787 /* mtvscr */, PPC::MTVSCR, Convert__RegVRRC1_0, AMFBS_None, { MCK_RegVRRC }, },
  { 7794 /* mtvsrd */, PPC::MTVSRD, Convert__RegVSFRC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegG8RC }, },
  { 7801 /* mtvsrdd */, PPC::MTVSRDD, Convert__RegVSRC1_0__RegG8RCNoX01_1__RegG8RC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegG8RCNoX0, MCK_RegG8RC }, },
  { 7809 /* mtvsrwa */, PPC::MTVSRWA, Convert__RegVSFRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegGPRC }, },
  { 7817 /* mtvsrws */, PPC::MTVSRWS, Convert__RegVSRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegGPRC }, },
  { 7825 /* mtvsrwz */, PPC::MTVSRWZ, Convert__RegVSFRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegGPRC }, },
  { 7833 /* mtxer */, PPC::MTSPR, Convert__imm_95_1__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 7839 /* mulhd */, PPC::MULHD, Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 7839 /* mulhd */, PPC::MULHD_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 7845 /* mulhdu */, PPC::MULHDU, Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 7845 /* mulhdu */, PPC::MULHDU_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 7852 /* mulhw */, PPC::MULHW, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7852 /* mulhw */, PPC::MULHW_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7858 /* mulhwu */, PPC::MULHWU, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7858 /* mulhwu */, PPC::MULHWU_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7865 /* mulld */, PPC::MULLD, Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 7865 /* mulld */, PPC::MULLD_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 7871 /* mulldo */, PPC::MULLDO, Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 7871 /* mulldo */, PPC::MULLDO_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 7878 /* mulli */, PPC::MULLI, Convert__RegGPRC1_0__RegGPRC1_1__S16Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_S16Imm }, },
  { 7884 /* mullw */, PPC::MULLW, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7884 /* mullw */, PPC::MULLW_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7890 /* mullwo */, PPC::MULLWO, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7890 /* mullwo */, PPC::MULLWO_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7897 /* nand */, PPC::NAND, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7897 /* nand */, PPC::NAND_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7902 /* nap */, PPC::NAP, Convert_NoOperands, AMFBS_None, {  }, },
  { 7906 /* neg */, PPC::NEG, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 7906 /* neg */, PPC::NEG_rec, Convert__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7910 /* nego */, PPC::NEGO, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 7910 /* nego */, PPC::NEGO_rec, Convert__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7915 /* nop */, PPC::NOP, Convert_NoOperands, AMFBS_None, {  }, },
  { 7915 /* nop */, PPC::ORI, Convert__regR0__regR0__imm_95_0, AMFBS_None, {  }, },
  { 7915 /* nop */, PPC::ORI8, Convert__regX0__regX0__imm_95_0, AMFBS_None, {  }, },
  { 7919 /* nor */, PPC::NOR, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7919 /* nor */, PPC::NOR_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7923 /* not */, PPC::NOR8, Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 7923 /* not */, PPC::NOR, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 7923 /* not */, PPC::NOR8_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC }, },
  { 7923 /* not */, PPC::NOR_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7927 /* or */, PPC::OR, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7927 /* or */, PPC::OR_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7930 /* orc */, PPC::ORC, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7930 /* orc */, PPC::ORC_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7934 /* ori */, PPC::ORI, Convert__RegGPRC1_0__RegGPRC1_1__U16Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U16Imm }, },
  { 7938 /* oris */, PPC::ORIS, Convert__RegGPRC1_0__RegGPRC1_1__U16Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U16Imm }, },
  { 7943 /* paddi */, PPC::PADDIpc, Convert__RegGPRC1_0__ImmZero1_1__S34Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_ImmZero, MCK_S34Imm, MCK_1 }, },
  { 7943 /* paddi */, PPC::PADDI, Convert__RegGPRC1_0__RegGPRC1_1__S34Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_S34Imm, MCK_0 }, },
  { 7949 /* paste */, PPC::CP_PASTEx, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 7949 /* paste */, PPC::CP_PASTE, Convert__RegGPRC1_0__RegGPRC1_1__U1Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U1Imm }, },
  { 7949 /* paste */, PPC::CP_PASTE_rec, Convert__RegGPRC1_1__RegGPRC1_2__U1Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U1Imm }, },
  { 7955 /* paste_last */, PPC::CP_PASTE_LAST, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 7966 /* plbz */, PPC::PLBZpc, Convert__RegGPRC1_0__DispRI341_1__ImmZero1_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI34, MCK_ImmZero, MCK_1 }, },
  { 7966 /* plbz */, PPC::PLBZ, Convert__RegGPRC1_0__DispRI341_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI34, MCK_RegGxRCNoR0, MCK_0 }, },
  { 7971 /* pld */, PPC::PLDpc, Convert__RegG8RC1_0__DispRI341_1__ImmZero1_2, AMFBS_None, { MCK_RegG8RC, MCK_DispRI34, MCK_ImmZero, MCK_1 }, },
  { 7971 /* pld */, PPC::PLD, Convert__RegG8RC1_0__DispRI341_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegG8RC, MCK_DispRI34, MCK_RegGxRCNoR0, MCK_0 }, },
  { 7975 /* plfd */, PPC::PLFDpc, Convert__RegF8RC1_0__DispRI341_1__ImmZero1_2, AMFBS_None, { MCK_RegF8RC, MCK_DispRI34, MCK_ImmZero, MCK_1 }, },
  { 7975 /* plfd */, PPC::PLFD, Convert__RegF8RC1_0__DispRI341_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegF8RC, MCK_DispRI34, MCK_RegGxRCNoR0, MCK_0 }, },
  { 7980 /* plfs */, PPC::PLFSpc, Convert__RegF4RC1_0__DispRI341_1__ImmZero1_2, AMFBS_None, { MCK_RegF4RC, MCK_DispRI34, MCK_ImmZero, MCK_1 }, },
  { 7980 /* plfs */, PPC::PLFS, Convert__RegF4RC1_0__DispRI341_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegF4RC, MCK_DispRI34, MCK_RegGxRCNoR0, MCK_0 }, },
  { 7985 /* plha */, PPC::PLHApc, Convert__RegGPRC1_0__DispRI341_1__ImmZero1_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI34, MCK_ImmZero, MCK_1 }, },
  { 7985 /* plha */, PPC::PLHA, Convert__RegGPRC1_0__DispRI341_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI34, MCK_RegGxRCNoR0, MCK_0 }, },
  { 7990 /* plhz */, PPC::PLHZpc, Convert__RegGPRC1_0__DispRI341_1__ImmZero1_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI34, MCK_ImmZero, MCK_1 }, },
  { 7990 /* plhz */, PPC::PLHZ, Convert__RegGPRC1_0__DispRI341_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI34, MCK_RegGxRCNoR0, MCK_0 }, },
  { 7995 /* pli */, PPC::PLI, Convert__RegGPRC1_0__S34Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S34Imm }, },
  { 7999 /* plwa */, PPC::PLWApc, Convert__RegGPRC1_0__DispRI341_1__ImmZero1_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI34, MCK_ImmZero, MCK_1 }, },
  { 7999 /* plwa */, PPC::PLWA, Convert__RegGPRC1_0__DispRI341_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI34, MCK_RegGxRCNoR0, MCK_0 }, },
  { 8004 /* plwz */, PPC::PLWZpc, Convert__RegGPRC1_0__DispRI341_1__ImmZero1_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI34, MCK_ImmZero, MCK_1 }, },
  { 8004 /* plwz */, PPC::PLWZ, Convert__RegGPRC1_0__DispRI341_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI34, MCK_RegGxRCNoR0, MCK_0 }, },
  { 8009 /* plxsd */, PPC::PLXSDpc, Convert__RegVFRC1_0__DispRI341_1__ImmZero1_2, AMFBS_None, { MCK_RegVFRC, MCK_DispRI34, MCK_ImmZero, MCK_1 }, },
  { 8009 /* plxsd */, PPC::PLXSD, Convert__RegVFRC1_0__DispRI341_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegVFRC, MCK_DispRI34, MCK_RegGxRCNoR0, MCK_0 }, },
  { 8015 /* plxssp */, PPC::PLXSSPpc, Convert__RegVFRC1_0__DispRI341_1__ImmZero1_2, AMFBS_None, { MCK_RegVFRC, MCK_DispRI34, MCK_ImmZero, MCK_1 }, },
  { 8015 /* plxssp */, PPC::PLXSSP, Convert__RegVFRC1_0__DispRI341_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegVFRC, MCK_DispRI34, MCK_RegGxRCNoR0, MCK_0 }, },
  { 8022 /* plxv */, PPC::PLXVpc, Convert__RegVSRC1_0__DispRI341_1__ImmZero1_2, AMFBS_None, { MCK_RegVSRC, MCK_DispRI34, MCK_ImmZero, MCK_1 }, },
  { 8022 /* plxv */, PPC::PLXV, Convert__RegVSRC1_0__DispRI341_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegVSRC, MCK_DispRI34, MCK_RegGxRCNoR0, MCK_0 }, },
  { 8027 /* popcntb */, PPC::POPCNTB, Convert__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 8035 /* popcntd */, PPC::POPCNTD, Convert__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 8043 /* popcntw */, PPC::POPCNTW, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 8051 /* pstb */, PPC::PSTBpc, Convert__RegGPRC1_0__DispRI341_1__ImmZero1_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI34, MCK_ImmZero, MCK_1 }, },
  { 8051 /* pstb */, PPC::PSTB, Convert__RegGPRC1_0__DispRI341_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI34, MCK_RegGxRCNoR0, MCK_0 }, },
  { 8056 /* pstd */, PPC::PSTDpc, Convert__RegG8RC1_0__DispRI341_1__ImmZero1_2, AMFBS_None, { MCK_RegG8RC, MCK_DispRI34, MCK_ImmZero, MCK_1 }, },
  { 8056 /* pstd */, PPC::PSTD, Convert__RegG8RC1_0__DispRI341_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegG8RC, MCK_DispRI34, MCK_RegGxRCNoR0, MCK_0 }, },
  { 8061 /* pstfd */, PPC::PSTFDpc, Convert__RegF8RC1_0__DispRI341_1__ImmZero1_2, AMFBS_None, { MCK_RegF8RC, MCK_DispRI34, MCK_ImmZero, MCK_1 }, },
  { 8061 /* pstfd */, PPC::PSTFD, Convert__RegF8RC1_0__DispRI341_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegF8RC, MCK_DispRI34, MCK_RegGxRCNoR0, MCK_0 }, },
  { 8067 /* pstfs */, PPC::PSTFSpc, Convert__RegF4RC1_0__DispRI341_1__ImmZero1_2, AMFBS_None, { MCK_RegF4RC, MCK_DispRI34, MCK_ImmZero, MCK_1 }, },
  { 8067 /* pstfs */, PPC::PSTFS, Convert__RegF4RC1_0__DispRI341_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegF4RC, MCK_DispRI34, MCK_RegGxRCNoR0, MCK_0 }, },
  { 8073 /* psth */, PPC::PSTHpc, Convert__RegGPRC1_0__DispRI341_1__ImmZero1_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI34, MCK_ImmZero, MCK_1 }, },
  { 8073 /* psth */, PPC::PSTH, Convert__RegGPRC1_0__DispRI341_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI34, MCK_RegGxRCNoR0, MCK_0 }, },
  { 8078 /* pstw */, PPC::PSTWpc, Convert__RegGPRC1_0__DispRI341_1__ImmZero1_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI34, MCK_ImmZero, MCK_1 }, },
  { 8078 /* pstw */, PPC::PSTW, Convert__RegGPRC1_0__DispRI341_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI34, MCK_RegGxRCNoR0, MCK_0 }, },
  { 8083 /* pstxsd */, PPC::PSTXSDpc, Convert__RegVFRC1_0__DispRI341_1__ImmZero1_2, AMFBS_None, { MCK_RegVFRC, MCK_DispRI34, MCK_ImmZero, MCK_1 }, },
  { 8083 /* pstxsd */, PPC::PSTXSD, Convert__RegVFRC1_0__DispRI341_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegVFRC, MCK_DispRI34, MCK_RegGxRCNoR0, MCK_0 }, },
  { 8090 /* pstxssp */, PPC::PSTXSSPpc, Convert__RegVFRC1_0__DispRI341_1__ImmZero1_2, AMFBS_None, { MCK_RegVFRC, MCK_DispRI34, MCK_ImmZero, MCK_1 }, },
  { 8090 /* pstxssp */, PPC::PSTXSSP, Convert__RegVFRC1_0__DispRI341_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegVFRC, MCK_DispRI34, MCK_RegGxRCNoR0, MCK_0 }, },
  { 8098 /* pstxv */, PPC::PSTXVpc, Convert__RegVSRC1_0__DispRI341_1__ImmZero1_2, AMFBS_None, { MCK_RegVSRC, MCK_DispRI34, MCK_ImmZero, MCK_1 }, },
  { 8098 /* pstxv */, PPC::PSTXV, Convert__RegVSRC1_0__DispRI341_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegVSRC, MCK_DispRI34, MCK_RegGxRCNoR0, MCK_0 }, },
  { 8104 /* ptesync */, PPC::SYNC, Convert__imm_95_2, AMFBS_None, {  }, },
  { 8112 /* qvaligni */, PPC::QVALIGNI, Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_2__U2Imm1_3, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_U2Imm }, },
  { 8121 /* qvesplati */, PPC::QVESPLATI, Convert__RegQFRC1_0__RegQFRC1_1__U2Imm1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_U2Imm }, },
  { 8131 /* qvfabs */, PPC::QVFABS, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8138 /* qvfadd */, PPC::QVFADD, Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8145 /* qvfadds */, PPC::QVFADDSs, Convert__RegQSRC1_0__RegQSRC1_1__RegQSRC1_2, AMFBS_None, { MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC }, },
  { 8153 /* qvfand */, PPC::QVFLOGICALb, Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_1, AMFBS_None, { MCK_RegQBRC, MCK_RegQBRC, MCK_RegQBRC }, },
  { 8160 /* qvfandc */, PPC::QVFLOGICALb, Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_4, AMFBS_None, { MCK_RegQBRC, MCK_RegQBRC, MCK_RegQBRC }, },
  { 8168 /* qvfcfid */, PPC::QVFCFID, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8176 /* qvfcfids */, PPC::QVFCFIDS, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8185 /* qvfcfidu */, PPC::QVFCFIDU, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8194 /* qvfcfidus */, PPC::QVFCFIDUS, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8204 /* qvfclr */, PPC::QVFLOGICALb, Convert__RegQBRC1_0__RegQBRC1_0__RegQBRC1_0__imm_95_0, AMFBS_None, { MCK_RegQBRC }, },
  { 8211 /* qvfcmpeq */, PPC::QVFCMPEQb, Convert__RegQBRC1_0__RegQFRC1_1__RegQFRC1_2, AMFBS_None, { MCK_RegQBRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8220 /* qvfcmpgt */, PPC::QVFCMPGTb, Convert__RegQBRC1_0__RegQFRC1_1__RegQFRC1_2, AMFBS_None, { MCK_RegQBRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8229 /* qvfcmplt */, PPC::QVFCMPLTb, Convert__RegQBRC1_0__RegQFRC1_1__RegQFRC1_2, AMFBS_None, { MCK_RegQBRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8238 /* qvfcpsgn */, PPC::QVFCPSGN, Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8247 /* qvfctfb */, PPC::QVFLOGICALb, Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_1__imm_95_5, AMFBS_None, { MCK_RegQBRC, MCK_RegQBRC }, },
  { 8255 /* qvfctid */, PPC::QVFCTID, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8263 /* qvfctidu */, PPC::QVFCTIDU, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8272 /* qvfctiduz */, PPC::QVFCTIDUZ, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8282 /* qvfctidz */, PPC::QVFCTIDZ, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8291 /* qvfctiw */, PPC::QVFCTIW, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8299 /* qvfctiwu */, PPC::QVFCTIWU, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8308 /* qvfctiwuz */, PPC::QVFCTIWUZ, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8318 /* qvfctiwz */, PPC::QVFCTIWZ, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8327 /* qvfequ */, PPC::QVFLOGICALb, Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_9, AMFBS_None, { MCK_RegQBRC, MCK_RegQBRC, MCK_RegQBRC }, },
  { 8334 /* qvflogical */, PPC::QVFLOGICALb, Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__U12Imm1_3, AMFBS_None, { MCK_RegQBRC, MCK_RegQBRC, MCK_RegQBRC, MCK_U12Imm }, },
  { 8345 /* qvfmadd */, PPC::QVFMADD, Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8353 /* qvfmadds */, PPC::QVFMADDSs, Convert__RegQSRC1_0__RegQSRC1_1__RegQSRC1_2__RegQSRC1_3, AMFBS_None, { MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC }, },
  { 8362 /* qvfmr */, PPC::QVFMR, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8368 /* qvfmsub */, PPC::QVFMSUB, Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8376 /* qvfmsubs */, PPC::QVFMSUBSs, Convert__RegQSRC1_0__RegQSRC1_1__RegQSRC1_2__RegQSRC1_3, AMFBS_None, { MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC }, },
  { 8385 /* qvfmul */, PPC::QVFMUL, Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8392 /* qvfmuls */, PPC::QVFMULSs, Convert__RegQSRC1_0__RegQSRC1_1__RegQSRC1_2, AMFBS_None, { MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC }, },
  { 8400 /* qvfnabs */, PPC::QVFNABS, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8408 /* qvfnand */, PPC::QVFLOGICALb, Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_14, AMFBS_None, { MCK_RegQBRC, MCK_RegQBRC, MCK_RegQBRC }, },
  { 8416 /* qvfneg */, PPC::QVFNEG, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8423 /* qvfnmadd */, PPC::QVFNMADD, Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8432 /* qvfnmadds */, PPC::QVFNMADDSs, Convert__RegQSRC1_0__RegQSRC1_1__RegQSRC1_2__RegQSRC1_3, AMFBS_None, { MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC }, },
  { 8442 /* qvfnmsub */, PPC::QVFNMSUB, Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8451 /* qvfnmsubs */, PPC::QVFNMSUBSs, Convert__RegQSRC1_0__RegQSRC1_1__RegQSRC1_2__RegQSRC1_3, AMFBS_None, { MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC }, },
  { 8461 /* qvfnor */, PPC::QVFLOGICALb, Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_8, AMFBS_None, { MCK_RegQBRC, MCK_RegQBRC, MCK_RegQBRC }, },
  { 8468 /* qvfnot */, PPC::QVFLOGICALb, Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_1__imm_95_10, AMFBS_None, { MCK_RegQBRC, MCK_RegQBRC }, },
  { 8475 /* qvfor */, PPC::QVFLOGICALb, Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_7, AMFBS_None, { MCK_RegQBRC, MCK_RegQBRC, MCK_RegQBRC }, },
  { 8481 /* qvforc */, PPC::QVFLOGICALb, Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_13, AMFBS_None, { MCK_RegQBRC, MCK_RegQBRC, MCK_RegQBRC }, },
  { 8488 /* qvfperm */, PPC::QVFPERM, Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8496 /* qvfre */, PPC::QVFRE, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8502 /* qvfres */, PPC::QVFRES, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8509 /* qvfrim */, PPC::QVFRIM, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8516 /* qvfrin */, PPC::QVFRIN, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8523 /* qvfrip */, PPC::QVFRIP, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8530 /* qvfriz */, PPC::QVFRIZ, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8537 /* qvfrsp */, PPC::QVFRSPs, Convert__RegQSRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQSRC, MCK_RegQFRC }, },
  { 8544 /* qvfrsqrte */, PPC::QVFRSQRTE, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8554 /* qvfrsqrtes */, PPC::QVFRSQRTES, Convert__RegQFRC1_0__RegQFRC1_1, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC }, },
  { 8565 /* qvfsel */, PPC::QVFSELb, Convert__RegQFRC1_0__RegQBRC1_1__RegQFRC1_3__RegQFRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegQBRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8572 /* qvfset */, PPC::QVFLOGICALb, Convert__RegQBRC1_0__RegQBRC1_0__RegQBRC1_0__imm_95_15, AMFBS_None, { MCK_RegQBRC }, },
  { 8579 /* qvfsub */, PPC::QVFSUB, Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8586 /* qvfsubs */, PPC::QVFSUBSs, Convert__RegQSRC1_0__RegQSRC1_1__RegQSRC1_2, AMFBS_None, { MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC }, },
  { 8594 /* qvftstnan */, PPC::QVFTSTNANb, Convert__RegQBRC1_0__RegQFRC1_1__RegQFRC1_2, AMFBS_None, { MCK_RegQBRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8604 /* qvfxmadd */, PPC::QVFXMADD, Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_3__RegQFRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8613 /* qvfxmadds */, PPC::QVFXMADDS, Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_3__RegQFRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8623 /* qvfxmul */, PPC::QVFXMUL, Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8631 /* qvfxmuls */, PPC::QVFXMULS, Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8640 /* qvfxor */, PPC::QVFLOGICALb, Convert__RegQBRC1_0__RegQBRC1_1__RegQBRC1_2__imm_95_6, AMFBS_None, { MCK_RegQBRC, MCK_RegQBRC, MCK_RegQBRC }, },
  { 8647 /* qvfxxcpnmadd */, PPC::QVFXXCPNMADD, Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_3__RegQFRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8660 /* qvfxxcpnmadds */, PPC::QVFXXCPNMADDS, Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_3__RegQFRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8674 /* qvfxxmadd */, PPC::QVFXXMADD, Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_3__RegQFRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8684 /* qvfxxmadds */, PPC::QVFXXMADDS, Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_3__RegQFRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8695 /* qvfxxnpmadd */, PPC::QVFXXNPMADD, Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_3__RegQFRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8707 /* qvfxxnpmadds */, PPC::QVFXXNPMADDS, Convert__RegQFRC1_0__RegQFRC1_1__RegQFRC1_3__RegQFRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 8720 /* qvgpci */, PPC::QVGPCI, Convert__RegQFRC1_0__U12Imm1_1, AMFBS_None, { MCK_RegQFRC, MCK_U12Imm }, },
  { 8727 /* qvlfcdux */, PPC::QVLFCDUX, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8736 /* qvlfcduxa */, PPC::QVLFCDUXA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8746 /* qvlfcdx */, PPC::QVLFCDX, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8754 /* qvlfcdxa */, PPC::QVLFCDXA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8763 /* qvlfcsux */, PPC::QVLFCSUX, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8772 /* qvlfcsuxa */, PPC::QVLFCSUXA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8782 /* qvlfcsx */, PPC::QVLFCSX, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8790 /* qvlfcsxa */, PPC::QVLFCSXA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8799 /* qvlfdux */, PPC::QVLFDUX, Convert__RegQFRC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8807 /* qvlfduxa */, PPC::QVLFDUXA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8816 /* qvlfdx */, PPC::QVLFDX, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8823 /* qvlfdxa */, PPC::QVLFDXA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8831 /* qvlfiwax */, PPC::QVLFIWAX, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8840 /* qvlfiwaxa */, PPC::QVLFIWAXA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8850 /* qvlfiwzx */, PPC::QVLFIWZX, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8859 /* qvlfiwzxa */, PPC::QVLFIWZXA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8869 /* qvlfsux */, PPC::QVLFSUX, Convert__RegQSRC1_0__imm_95_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8877 /* qvlfsuxa */, PPC::QVLFSUXA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8886 /* qvlfsx */, PPC::QVLFSX, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8893 /* qvlfsxa */, PPC::QVLFSXA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8901 /* qvlpcldx */, PPC::QVLPCLDX, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8910 /* qvlpclsx */, PPC::QVLPCLSX, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8919 /* qvlpcrdx */, PPC::QVLPCRDX, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8928 /* qvlpcrsx */, PPC::QVLPCRSX, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8937 /* qvstfcdux */, PPC::QVSTFCDUX, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8947 /* qvstfcduxa */, PPC::QVSTFCDUXA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8958 /* qvstfcduxi */, PPC::QVSTFCDUXI, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8969 /* qvstfcduxia */, PPC::QVSTFCDUXIA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8981 /* qvstfcdx */, PPC::QVSTFCDX, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8990 /* qvstfcdxa */, PPC::QVSTFCDXA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9000 /* qvstfcdxi */, PPC::QVSTFCDXI, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9010 /* qvstfcdxia */, PPC::QVSTFCDXIA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9021 /* qvstfcsux */, PPC::QVSTFCSUX, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9031 /* qvstfcsuxa */, PPC::QVSTFCSUXA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9042 /* qvstfcsuxi */, PPC::QVSTFCSUXI, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9053 /* qvstfcsuxia */, PPC::QVSTFCSUXIA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9065 /* qvstfcsx */, PPC::QVSTFCSX, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9074 /* qvstfcsxa */, PPC::QVSTFCSXA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9084 /* qvstfcsxi */, PPC::QVSTFCSXI, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9094 /* qvstfcsxia */, PPC::QVSTFCSXIA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9105 /* qvstfdux */, PPC::QVSTFDUX, Convert__imm_95_0__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9114 /* qvstfduxa */, PPC::QVSTFDUXA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9124 /* qvstfduxi */, PPC::QVSTFDUXI, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9134 /* qvstfduxia */, PPC::QVSTFDUXIA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9145 /* qvstfdx */, PPC::QVSTFDX, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9153 /* qvstfdxa */, PPC::QVSTFDXA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9162 /* qvstfdxi */, PPC::QVSTFDXI, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9171 /* qvstfdxia */, PPC::QVSTFDXIA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9181 /* qvstfiwx */, PPC::QVSTFIWX, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9190 /* qvstfiwxa */, PPC::QVSTFIWXA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9200 /* qvstfsux */, PPC::QVSTFSUX, Convert__imm_95_0__RegQSRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9209 /* qvstfsuxa */, PPC::QVSTFSUXA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9219 /* qvstfsuxi */, PPC::QVSTFSUXI, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9229 /* qvstfsuxia */, PPC::QVSTFSUXIA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9240 /* qvstfsx */, PPC::QVSTFSX, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9248 /* qvstfsxa */, PPC::QVSTFSXA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9257 /* qvstfsxi */, PPC::QVSTFSXI, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9266 /* qvstfsxia */, PPC::QVSTFSXIA, Convert__RegQFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9276 /* rfci */, PPC::RFCI, Convert_NoOperands, AMFBS_None, {  }, },
  { 9281 /* rfdi */, PPC::RFDI, Convert_NoOperands, AMFBS_None, {  }, },
  { 9286 /* rfebb */, PPC::RFEBB, Convert__imm_95_1, AMFBS_None, {  }, },
  { 9286 /* rfebb */, PPC::RFEBB, Convert__U1Imm1_0, AMFBS_None, { MCK_U1Imm }, },
  { 9292 /* rfi */, PPC::RFI, Convert_NoOperands, AMFBS_None, {  }, },
  { 9296 /* rfmci */, PPC::RFMCI, Convert_NoOperands, AMFBS_None, {  }, },
  { 9302 /* rldcl */, PPC::RLDCL, Convert__RegG8RC1_0__RegG8RC1_1__RegGPRC1_2__U6Imm1_3, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC, MCK_U6Imm }, },
  { 9302 /* rldcl */, PPC::RLDCL_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3__U6Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC, MCK_U6Imm }, },
  { 9308 /* rldcr */, PPC::RLDCR, Convert__RegG8RC1_0__RegG8RC1_1__RegGPRC1_2__U6Imm1_3, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC, MCK_U6Imm }, },
  { 9308 /* rldcr */, PPC::RLDCR_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3__U6Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC, MCK_U6Imm }, },
  { 9314 /* rldic */, PPC::RLDIC, Convert__RegG8RC1_0__RegG8RC1_1__U6Imm1_2__U6Imm1_3, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 9314 /* rldic */, PPC::RLDIC_rec, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 9320 /* rldicl */, PPC::RLDICL, Convert__RegG8RC1_0__RegG8RC1_1__U6Imm1_2__U6Imm1_3, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 9320 /* rldicl */, PPC::RLDICL_rec, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 9327 /* rldicr */, PPC::RLDICR, Convert__RegG8RC1_0__RegG8RC1_1__U6Imm1_2__U6Imm1_3, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 9327 /* rldicr */, PPC::RLDICR_rec, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 9334 /* rldimi */, PPC::RLDIMI, Convert__RegG8RC1_0__Tie0_1_1__RegG8RC1_1__U6Imm1_2__U6Imm1_3, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 9334 /* rldimi */, PPC::RLDIMI_rec, Convert__RegG8RC1_1__Tie0_1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 9341 /* rlwimi */, PPC::RLWIMIbm, Convert__RegG8RC1_0__RegG8RC1_1__U5Imm1_2__Imm1_3, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U5Imm, MCK_Imm }, },
  { 9341 /* rlwimi */, PPC::RLWIMIbm_rec, Convert__RegG8RC1_1__RegG8RC1_2__U5Imm1_3__Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U5Imm, MCK_Imm }, },
  { 9341 /* rlwimi */, PPC::RLWIMI, Convert__RegGPRC1_0__Tie0_1_1__RegGPRC1_1__U5Imm1_2__U5Imm1_3__U5Imm1_4, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm, MCK_U5Imm }, },
  { 9341 /* rlwimi */, PPC::RLWIMI_rec, Convert__RegGPRC1_1__Tie0_1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4__U5Imm1_5, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm, MCK_U5Imm }, },
  { 9348 /* rlwinm */, PPC::RLWINMbm, Convert__RegG8RC1_0__RegG8RC1_1__U5Imm1_2__Imm1_3, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U5Imm, MCK_Imm }, },
  { 9348 /* rlwinm */, PPC::RLWINMbm_rec, Convert__RegG8RC1_1__RegG8RC1_2__U5Imm1_3__Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U5Imm, MCK_Imm }, },
  { 9348 /* rlwinm */, PPC::RLWINM, Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2__U5Imm1_3__U5Imm1_4, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm, MCK_U5Imm }, },
  { 9348 /* rlwinm */, PPC::RLWINM_rec, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4__U5Imm1_5, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm, MCK_U5Imm }, },
  { 9355 /* rlwnm */, PPC::RLWNMbm, Convert__RegG8RC1_0__RegG8RC1_1__U5Imm1_2__Imm1_3, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U5Imm, MCK_Imm }, },
  { 9355 /* rlwnm */, PPC::RLWNMbm_rec, Convert__RegG8RC1_1__RegG8RC1_2__U5Imm1_3__Imm1_4, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U5Imm, MCK_Imm }, },
  { 9355 /* rlwnm */, PPC::RLWNM, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 9355 /* rlwnm */, PPC::RLWNM_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3__U5Imm1_4__U5Imm1_5, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 9361 /* rotld */, PPC::RLDCL, Convert__RegG8RC1_0__RegG8RC1_1__RegGPRC1_2__imm_95_0, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC }, },
  { 9361 /* rotld */, PPC::RLDCL_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3__imm_95_0, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC }, },
  { 9367 /* rotldi */, PPC::RLDICL, Convert__RegG8RC1_0__RegG8RC1_1__U6Imm1_2__imm_95_0, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 9367 /* rotldi */, PPC::RLDICL_32_64, Convert__RegG8RC1_0__RegGPRC1_1__U6Imm1_2__imm_95_0, AMFBS_None, { MCK_RegG8RC, MCK_RegGPRC, MCK_U6Imm }, },
  { 9367 /* rotldi */, PPC::RLDICL_rec, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__imm_95_0, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 9374 /* rotlw */, PPC::RLWNM8, Convert__RegG8RC1_0__RegG8RC1_1__RegG8RC1_2__imm_95_0__imm_95_31, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 9374 /* rotlw */, PPC::RLWNM, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2__imm_95_0__imm_95_31, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9374 /* rotlw */, PPC::RLWNM8_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3__imm_95_0__imm_95_31, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 9374 /* rotlw */, PPC::RLWNM_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3__imm_95_0__imm_95_31, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9380 /* rotlwi */, PPC::RLWINM8, Convert__RegG8RC1_0__RegG8RC1_1__U5Imm1_2__imm_95_0__imm_95_31, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U5Imm }, },
  { 9380 /* rotlwi */, PPC::RLWINM, Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2__imm_95_0__imm_95_31, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 9380 /* rotlwi */, PPC::RLWINM8_rec, Convert__RegG8RC1_1__RegG8RC1_2__U5Imm1_3__imm_95_0__imm_95_31, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U5Imm }, },
  { 9380 /* rotlwi */, PPC::RLWINM_rec, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__imm_95_0__imm_95_31, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 9387 /* rotrdi */, PPC::ROTRDI, Convert__RegG8RC1_0__RegG8RC1_1__U6Imm1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 9387 /* rotrdi */, PPC::ROTRDI_rec, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 9394 /* rotrwi */, PPC::ROTRWI, Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 9394 /* rotrwi */, PPC::ROTRWI_rec, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 9401 /* sc */, PPC::SC, Convert__imm_95_0, AMFBS_None, {  }, },
  { 9401 /* sc */, PPC::SC, Convert__Imm1_0, AMFBS_None, { MCK_Imm }, },
  { 9404 /* setb */, PPC::SETB, Convert__RegGPRC1_0__RegCRRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegCRRC }, },
  { 9409 /* slbfee */, PPC::SLBFEE_rec, Convert__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9416 /* slbia */, PPC::SLBIA, Convert_NoOperands, AMFBS_None, {  }, },
  { 9422 /* slbie */, PPC::SLBIE, Convert__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 9428 /* slbieg */, PPC::SLBIEG, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 9435 /* slbmfee */, PPC::SLBMFEE, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 9443 /* slbmfev */, PPC::SLBMFEV, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 9451 /* slbmte */, PPC::SLBMTE, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 9458 /* slbsync */, PPC::SLBSYNC, Convert_NoOperands, AMFBS_None, {  }, },
  { 9466 /* sld */, PPC::SLD, Convert__RegG8RC1_0__RegG8RC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC }, },
  { 9466 /* sld */, PPC::SLD_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC }, },
  { 9470 /* sldi */, PPC::SLDI, Convert__RegG8RC1_0__RegG8RC1_1__U6Imm1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 9470 /* sldi */, PPC::SLDI_rec, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 9475 /* slw */, PPC::SLW, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9475 /* slw */, PPC::SLW_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9479 /* slwi */, PPC::SLWI, Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 9479 /* slwi */, PPC::SLWI_rec, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 9484 /* srad */, PPC::SRAD, Convert__RegG8RC1_0__RegG8RC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC }, },
  { 9484 /* srad */, PPC::SRAD_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC }, },
  { 9489 /* sradi */, PPC::SRADI, Convert__RegG8RC1_0__RegG8RC1_1__U6Imm1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 9489 /* sradi */, PPC::SRADI_rec, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 9495 /* sraw */, PPC::SRAW, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9495 /* sraw */, PPC::SRAW_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9500 /* srawi */, PPC::SRAWI, Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 9500 /* srawi */, PPC::SRAWI_rec, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 9506 /* srd */, PPC::SRD, Convert__RegG8RC1_0__RegG8RC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC }, },
  { 9506 /* srd */, PPC::SRD_rec, Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC }, },
  { 9510 /* srdi */, PPC::SRDI, Convert__RegG8RC1_0__RegG8RC1_1__U6Imm1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 9510 /* srdi */, PPC::SRDI_rec, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 9515 /* srw */, PPC::SRW, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9515 /* srw */, PPC::SRW_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9519 /* srwi */, PPC::SRWI, Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 9519 /* srwi */, PPC::SRWI_rec, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 9524 /* stb */, PPC::STB, Convert__RegGPRC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 9528 /* stbcix */, PPC::STBCIX, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9535 /* stbcx */, PPC::STBCX, Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9541 /* stbepx */, PPC::STBEPX, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9548 /* stbu */, PPC::STBU, Convert__imm_95_0__RegGPRC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 9553 /* stbux */, PPC::STBUX, Convert__imm_95_0__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9559 /* stbx */, PPC::STBXTLS_, Convert__RegG8RC1_0__RegGxRCNoR01_1__TLSReg1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_TLSReg }, },
  { 9559 /* stbx */, PPC::STBX, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9564 /* std */, PPC::STD, Convert__RegG8RC1_0__DispRIX1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegG8RC, MCK_DispRIX, MCK_RegGxRCNoR0 }, },
  { 9568 /* stdat */, PPC::STDAT, Convert__RegG8RC1_0__RegG8RC1_1__U5Imm1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_U5Imm }, },
  { 9574 /* stdbrx */, PPC::STDBRX, Convert__RegG8RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9581 /* stdcix */, PPC::STDCIX, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9588 /* stdcx */, PPC::STDCX, Convert__RegG8RC1_1__RegGxRCNoR01_2__RegGxRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9594 /* stdu */, PPC::STDU, Convert__imm_95_0__RegG8RC1_0__DispRIX1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegG8RC, MCK_DispRIX, MCK_RegGxRCNoR0 }, },
  { 9599 /* stdux */, PPC::STDUX, Convert__imm_95_0__RegG8RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9605 /* stdx */, PPC::STDX, Convert__RegG8RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9605 /* stdx */, PPC::STDXTLS_, Convert__RegG8RC1_0__RegGxRCNoR01_1__TLSReg1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_TLSReg }, },
  { 9610 /* stfd */, PPC::STFD, Convert__RegF8RC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegF8RC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 9615 /* stfdepx */, PPC::STFDEPX, Convert__RegF8RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegF8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9623 /* stfdu */, PPC::STFDU, Convert__imm_95_0__RegF8RC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegF8RC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 9629 /* stfdux */, PPC::STFDUX, Convert__imm_95_0__RegF8RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegF8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9636 /* stfdx */, PPC::STFDX, Convert__RegF8RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegF8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9642 /* stfiwx */, PPC::STFIWX, Convert__RegF8RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegF8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9649 /* stfs */, PPC::STFS, Convert__RegF4RC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegF4RC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 9654 /* stfsu */, PPC::STFSU, Convert__imm_95_0__RegF4RC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegF4RC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 9660 /* stfsux */, PPC::STFSUX, Convert__imm_95_0__RegF4RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegF4RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9667 /* stfsx */, PPC::STFSX, Convert__RegF4RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegF4RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9673 /* sth */, PPC::STH, Convert__RegGPRC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 9677 /* sthbrx */, PPC::STHBRX, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9684 /* sthcix */, PPC::STHCIX, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9691 /* sthcx */, PPC::STHCX, Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9697 /* sthepx */, PPC::STHEPX, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9704 /* sthu */, PPC::STHU, Convert__imm_95_0__RegGPRC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 9709 /* sthux */, PPC::STHUX, Convert__imm_95_0__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9715 /* sthx */, PPC::STHXTLS_, Convert__RegG8RC1_0__RegGxRCNoR01_1__TLSReg1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_TLSReg }, },
  { 9715 /* sthx */, PPC::STHX, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9720 /* stmw */, PPC::STMW, Convert__RegGPRC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 9725 /* stop */, PPC::STOP, Convert_NoOperands, AMFBS_None, {  }, },
  { 9730 /* stswi */, PPC::STSWI, Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 9736 /* stvebx */, PPC::STVEBX, Convert__RegVRRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9743 /* stvehx */, PPC::STVEHX, Convert__RegVRRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9750 /* stvewx */, PPC::STVEWX, Convert__RegVRRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9757 /* stvx */, PPC::STVX, Convert__RegVRRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9762 /* stvxl */, PPC::STVXL, Convert__RegVRRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9768 /* stw */, PPC::STW, Convert__RegGPRC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 9768 /* stw */, PPC::SPESTW, Convert__RegSPE4RC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegSPE4RC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 9772 /* stwat */, PPC::STWAT, Convert__RegGPRC1_0__RegGPRC1_1__U5Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 9778 /* stwbrx */, PPC::STWBRX, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9785 /* stwcix */, PPC::STWCIX, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9792 /* stwcx */, PPC::STWCX, Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9798 /* stwepx */, PPC::STWEPX, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9805 /* stwu */, PPC::STWU, Convert__imm_95_0__RegGPRC1_0__DispRI1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 9810 /* stwux */, PPC::STWUX, Convert__imm_95_0__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9816 /* stwx */, PPC::STWXTLS_, Convert__RegG8RC1_0__RegGxRCNoR01_1__TLSReg1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_TLSReg }, },
  { 9816 /* stwx */, PPC::STWX, Convert__RegGPRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9816 /* stwx */, PPC::SPESTWX, Convert__RegSPE4RC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegSPE4RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9821 /* stxsd */, PPC::STXSD, Convert__RegVFRC1_0__DispRIX1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegVFRC, MCK_DispRIX, MCK_RegGxRCNoR0 }, },
  { 9827 /* stxsdx */, PPC::STXSDX, Convert__RegVSFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9834 /* stxsibx */, PPC::STXSIBX, Convert__RegVSFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9842 /* stxsihx */, PPC::STXSIHX, Convert__RegVSFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9850 /* stxsiwx */, PPC::STXSIWX, Convert__RegVSFRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9858 /* stxssp */, PPC::STXSSP, Convert__RegVFRC1_0__DispRIX1_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegVFRC, MCK_DispRIX, MCK_RegGxRCNoR0 }, },
  { 9865 /* stxsspx */, PPC::STXSSPX, Convert__RegVSSRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9873 /* stxv */, PPC::STXV, Convert__RegVSRC1_0__DispRIX161_1__RegGxRCNoR01_2, AMFBS_None, { MCK_RegVSRC, MCK_DispRIX16, MCK_RegGxRCNoR0 }, },
  { 9878 /* stxvb16x */, PPC::STXVB16X, Convert__RegVSRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9887 /* stxvd2x */, PPC::STXVD2X, Convert__RegVSRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9895 /* stxvh8x */, PPC::STXVH8X, Convert__RegVSRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9903 /* stxvl */, PPC::STXVL, Convert__RegVSRC1_0__Imm1_1__RegG8RC1_2, AMFBS_None, { MCK_RegVSRC, MCK_Imm, MCK_RegG8RC }, },
  { 9909 /* stxvll */, PPC::STXVLL, Convert__RegVSRC1_0__Imm1_1__RegG8RC1_2, AMFBS_None, { MCK_RegVSRC, MCK_Imm, MCK_RegG8RC }, },
  { 9916 /* stxvw4x */, PPC::STXVW4X, Convert__RegVSRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9924 /* stxvx */, PPC::STXVX, Convert__RegVSRC1_0__RegGxRCNoR01_1__RegGxRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 9930 /* sub */, PPC::SUBF8, Convert__RegG8RC1_0__RegG8RC1_2__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 9930 /* sub */, PPC::SUBF, Convert__RegGPRC1_0__RegGPRC1_2__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9930 /* sub */, PPC::SUBF8_rec, Convert__RegG8RC1_1__RegG8RC1_3__RegG8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 9930 /* sub */, PPC::SUBF_rec, Convert__RegGPRC1_1__RegGPRC1_3__RegGPRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9934 /* subc */, PPC::SUBFC8, Convert__RegG8RC1_0__RegG8RC1_2__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 9934 /* subc */, PPC::SUBFC, Convert__RegGPRC1_0__RegGPRC1_2__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9934 /* subc */, PPC::SUBFC8_rec, Convert__RegG8RC1_1__RegG8RC1_3__RegG8RC1_2, AMFBS_None, { MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 9934 /* subc */, PPC::SUBFC_rec, Convert__RegGPRC1_1__RegGPRC1_3__RegGPRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9939 /* subf */, PPC::SUBF, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9939 /* subf */, PPC::SUBF_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9944 /* subfc */, PPC::SUBFC, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9944 /* subfc */, PPC::SUBFC_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9950 /* subfco */, PPC::SUBFCO, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9950 /* subfco */, PPC::SUBFCO_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9957 /* subfe */, PPC::SUBFE, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9957 /* subfe */, PPC::SUBFE_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9963 /* subfeo */, PPC::SUBFEO, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9963 /* subfeo */, PPC::SUBFEO_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9970 /* subfic */, PPC::SUBFIC, Convert__RegGPRC1_0__RegGPRC1_1__S16Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_S16Imm }, },
  { 9977 /* subfme */, PPC::SUBFME, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 9977 /* subfme */, PPC::SUBFME_rec, Convert__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9984 /* subfmeo */, PPC::SUBFMEO, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 9984 /* subfmeo */, PPC::SUBFMEO_rec, Convert__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9992 /* subfo */, PPC::SUBFO, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9992 /* subfo */, PPC::SUBFO_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9998 /* subfze */, PPC::SUBFZE, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 9998 /* subfze */, PPC::SUBFZE_rec, Convert__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 10005 /* subfzeo */, PPC::SUBFZEO, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10005 /* subfzeo */, PPC::SUBFZEO_rec, Convert__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 10013 /* subi */, PPC::SUBI, Convert__RegGPRC1_0__RegGPRC1_1__S16Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_S16Imm }, },
  { 10018 /* subic */, PPC::SUBIC, Convert__RegGPRC1_0__RegGPRC1_1__S16Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_S16Imm }, },
  { 10018 /* subic */, PPC::SUBIC_rec, Convert__RegGPRC1_1__RegGPRC1_2__S16Imm1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_S16Imm }, },
  { 10024 /* subis */, PPC::SUBIS, Convert__RegGPRC1_0__RegGPRC1_1__S16Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_S16Imm }, },
  { 10030 /* subpcis */, PPC::SUBPCIS, Convert__RegG8RC1_0__S16Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_S16Imm }, },
  { 10038 /* sync */, PPC::SYNC, Convert__imm_95_0, AMFBS_None, {  }, },
  { 10038 /* sync */, PPC::SYNC, Convert__Imm1_0, AMFBS_None, { MCK_Imm }, },
  { 10043 /* tabort */, PPC::TABORT, Convert__RegGPRC1_1, AMFBS_None, { MCK__DOT_, MCK_RegGPRC }, },
  { 10050 /* tabortdc */, PPC::TABORTDC, Convert__U5Imm1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_U5Imm, MCK_RegGPRC, MCK_RegGPRC }, },
  { 10059 /* tabortdci */, PPC::TABORTDCI, Convert__U5Imm1_1__RegGPRC1_2__U5Imm1_3, AMFBS_None, { MCK__DOT_, MCK_U5Imm, MCK_RegGPRC, MCK_U5Imm }, },
  { 10069 /* tabortwc */, PPC::TABORTWC, Convert__U5Imm1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_U5Imm, MCK_RegGPRC, MCK_RegGPRC }, },
  { 10078 /* tabortwci */, PPC::TABORTWCI, Convert__U5Imm1_1__RegGPRC1_2__U5Imm1_3, AMFBS_None, { MCK__DOT_, MCK_U5Imm, MCK_RegGPRC, MCK_U5Imm }, },
  { 10088 /* tbegin */, PPC::TBEGIN, Convert__U1Imm1_1, AMFBS_None, { MCK__DOT_, MCK_U1Imm }, },
  { 10095 /* tcheck */, PPC::TCHECK, Convert__RegCRRC1_0, AMFBS_None, { MCK_RegCRRC }, },
  { 10102 /* td */, PPC::TD, Convert__U5Imm1_0__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK_U5Imm, MCK_RegG8RC, MCK_RegG8RC }, },
  { 10105 /* tdeq */, PPC::TD, Convert__imm_95_4__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 10110 /* tdeqi */, PPC::TDI, Convert__imm_95_4__RegG8RC1_0__S16Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_S16Imm }, },
  { 10116 /* tdge */, PPC::TD, Convert__imm_95_12__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 10121 /* tdgei */, PPC::TDI, Convert__imm_95_12__RegG8RC1_0__S16Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_S16Imm }, },
  { 10127 /* tdgt */, PPC::TD, Convert__imm_95_8__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 10132 /* tdgti */, PPC::TDI, Convert__imm_95_8__RegG8RC1_0__S16Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_S16Imm }, },
  { 10138 /* tdi */, PPC::TDI, Convert__U5Imm1_0__RegG8RC1_1__S16Imm1_2, AMFBS_None, { MCK_U5Imm, MCK_RegG8RC, MCK_S16Imm }, },
  { 10142 /* tdle */, PPC::TD, Convert__imm_95_20__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 10147 /* tdlei */, PPC::TDI, Convert__imm_95_20__RegG8RC1_0__S16Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_S16Imm }, },
  { 10153 /* tdlge */, PPC::TD, Convert__imm_95_5__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 10159 /* tdlgei */, PPC::TDI, Convert__imm_95_5__RegG8RC1_0__S16Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_S16Imm }, },
  { 10166 /* tdlgt */, PPC::TD, Convert__imm_95_1__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 10172 /* tdlgti */, PPC::TDI, Convert__imm_95_1__RegG8RC1_0__S16Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_S16Imm }, },
  { 10179 /* tdlle */, PPC::TD, Convert__imm_95_6__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 10185 /* tdllei */, PPC::TDI, Convert__imm_95_6__RegG8RC1_0__S16Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_S16Imm }, },
  { 10192 /* tdllt */, PPC::TD, Convert__imm_95_2__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 10198 /* tdllti */, PPC::TDI, Convert__imm_95_2__RegG8RC1_0__S16Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_S16Imm }, },
  { 10205 /* tdlng */, PPC::TD, Convert__imm_95_6__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 10211 /* tdlngi */, PPC::TDI, Convert__imm_95_6__RegG8RC1_0__S16Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_S16Imm }, },
  { 10218 /* tdlnl */, PPC::TD, Convert__imm_95_5__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 10224 /* tdlnli */, PPC::TDI, Convert__imm_95_5__RegG8RC1_0__S16Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_S16Imm }, },
  { 10231 /* tdlt */, PPC::TD, Convert__imm_95_16__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 10236 /* tdlti */, PPC::TDI, Convert__imm_95_16__RegG8RC1_0__S16Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_S16Imm }, },
  { 10242 /* tdne */, PPC::TD, Convert__imm_95_24__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 10247 /* tdnei */, PPC::TDI, Convert__imm_95_24__RegG8RC1_0__S16Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_S16Imm }, },
  { 10253 /* tdng */, PPC::TD, Convert__imm_95_20__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 10258 /* tdngi */, PPC::TDI, Convert__imm_95_20__RegG8RC1_0__S16Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_S16Imm }, },
  { 10264 /* tdnl */, PPC::TD, Convert__imm_95_12__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 10269 /* tdnli */, PPC::TDI, Convert__imm_95_12__RegG8RC1_0__S16Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_S16Imm }, },
  { 10275 /* tdu */, PPC::TD, Convert__imm_95_31__RegG8RC1_0__RegG8RC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC }, },
  { 10279 /* tdui */, PPC::TDI, Convert__imm_95_31__RegG8RC1_0__S16Imm1_1, AMFBS_None, { MCK_RegG8RC, MCK_S16Imm }, },
  { 10284 /* tend */, PPC::TEND, Convert__imm_95_0, AMFBS_None, { MCK__DOT_ }, },
  { 10284 /* tend */, PPC::TEND, Convert__U1Imm1_1, AMFBS_None, { MCK__DOT_, MCK_U1Imm }, },
  { 10289 /* tendall */, PPC::TEND, Convert__imm_95_1, AMFBS_None, { MCK__DOT_ }, },
  { 10297 /* tlbia */, PPC::TLBIA, Convert_NoOperands, AMFBS_None, {  }, },
  { 10303 /* tlbie */, PPC::TLBIE, Convert__regR0__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 10303 /* tlbie */, PPC::TLBIE, Convert__RegGPRC1_1__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10309 /* tlbiel */, PPC::TLBIEL, Convert__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 10316 /* tlbivax */, PPC::TLBIVAX, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10324 /* tlbld */, PPC::TLBLD, Convert__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 10330 /* tlbli */, PPC::TLBLI, Convert__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 10336 /* tlbre */, PPC::TLBRE, Convert_NoOperands, AMFBS_None, {  }, },
  { 10336 /* tlbre */, PPC::TLBRE2, Convert__RegGPRC1_0__RegGPRC1_1__Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_Imm }, },
  { 10342 /* tlbrehi */, PPC::TLBRE2, Convert__RegGPRC1_0__RegGPRC1_1__imm_95_0, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10350 /* tlbrelo */, PPC::TLBRE2, Convert__RegGPRC1_0__RegGPRC1_1__imm_95_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10358 /* tlbsx */, PPC::TLBSX, Convert__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10358 /* tlbsx */, PPC::TLBSX2, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 10358 /* tlbsx */, PPC::TLBSX2D, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 10364 /* tlbsync */, PPC::TLBSYNC, Convert_NoOperands, AMFBS_None, {  }, },
  { 10372 /* tlbwe */, PPC::TLBWE, Convert_NoOperands, AMFBS_None, {  }, },
  { 10372 /* tlbwe */, PPC::TLBWE2, Convert__RegGPRC1_0__RegGPRC1_1__Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_Imm }, },
  { 10378 /* tlbwehi */, PPC::TLBWE2, Convert__RegGPRC1_0__RegGPRC1_1__imm_95_0, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10386 /* tlbwelo */, PPC::TLBWE2, Convert__RegGPRC1_0__RegGPRC1_1__imm_95_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10394 /* trap */, PPC::TRAP, Convert_NoOperands, AMFBS_None, {  }, },
  { 10394 /* trap */, PPC::TW, Convert__imm_95_31__regR0__regR0, AMFBS_None, {  }, },
  { 10399 /* trechkpt */, PPC::TRECHKPT, Convert_NoOperands, AMFBS_None, { MCK__DOT_ }, },
  { 10408 /* treclaim */, PPC::TRECLAIM, Convert__RegGPRC1_1, AMFBS_None, { MCK__DOT_, MCK_RegGPRC }, },
  { 10417 /* tresume */, PPC::TSR, Convert__imm_95_1, AMFBS_None, { MCK__DOT_ }, },
  { 10425 /* tsr */, PPC::TSR, Convert__U1Imm1_1, AMFBS_None, { MCK__DOT_, MCK_U1Imm }, },
  { 10429 /* tsuspend */, PPC::TSR, Convert__imm_95_0, AMFBS_None, { MCK__DOT_ }, },
  { 10438 /* tw */, PPC::TW, Convert__U5Imm1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_U5Imm, MCK_RegGPRC, MCK_RegGPRC }, },
  { 10441 /* tweq */, PPC::TW, Convert__imm_95_4__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10446 /* tweqi */, PPC::TWI, Convert__imm_95_4__RegGPRC1_0__S16Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S16Imm }, },
  { 10452 /* twge */, PPC::TW, Convert__imm_95_12__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10457 /* twgei */, PPC::TWI, Convert__imm_95_12__RegGPRC1_0__S16Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S16Imm }, },
  { 10463 /* twgt */, PPC::TW, Convert__imm_95_8__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10468 /* twgti */, PPC::TWI, Convert__imm_95_8__RegGPRC1_0__S16Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S16Imm }, },
  { 10474 /* twi */, PPC::TWI, Convert__U5Imm1_0__RegGPRC1_1__S16Imm1_2, AMFBS_None, { MCK_U5Imm, MCK_RegGPRC, MCK_S16Imm }, },
  { 10478 /* twle */, PPC::TW, Convert__imm_95_20__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10483 /* twlei */, PPC::TWI, Convert__imm_95_20__RegGPRC1_0__S16Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S16Imm }, },
  { 10489 /* twlge */, PPC::TW, Convert__imm_95_5__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10495 /* twlgei */, PPC::TWI, Convert__imm_95_5__RegGPRC1_0__S16Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S16Imm }, },
  { 10502 /* twlgt */, PPC::TW, Convert__imm_95_1__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10508 /* twlgti */, PPC::TWI, Convert__imm_95_1__RegGPRC1_0__S16Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S16Imm }, },
  { 10515 /* twlle */, PPC::TW, Convert__imm_95_6__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10521 /* twllei */, PPC::TWI, Convert__imm_95_6__RegGPRC1_0__S16Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S16Imm }, },
  { 10528 /* twllt */, PPC::TW, Convert__imm_95_2__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10534 /* twllti */, PPC::TWI, Convert__imm_95_2__RegGPRC1_0__S16Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S16Imm }, },
  { 10541 /* twlng */, PPC::TW, Convert__imm_95_6__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10547 /* twlngi */, PPC::TWI, Convert__imm_95_6__RegGPRC1_0__S16Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S16Imm }, },
  { 10554 /* twlnl */, PPC::TW, Convert__imm_95_5__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10560 /* twlnli */, PPC::TWI, Convert__imm_95_5__RegGPRC1_0__S16Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S16Imm }, },
  { 10567 /* twlt */, PPC::TW, Convert__imm_95_16__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10572 /* twlti */, PPC::TWI, Convert__imm_95_16__RegGPRC1_0__S16Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S16Imm }, },
  { 10578 /* twne */, PPC::TW, Convert__imm_95_24__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10583 /* twnei */, PPC::TWI, Convert__imm_95_24__RegGPRC1_0__S16Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S16Imm }, },
  { 10589 /* twng */, PPC::TW, Convert__imm_95_20__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10594 /* twngi */, PPC::TWI, Convert__imm_95_20__RegGPRC1_0__S16Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S16Imm }, },
  { 10600 /* twnl */, PPC::TW, Convert__imm_95_12__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10605 /* twnli */, PPC::TWI, Convert__imm_95_12__RegGPRC1_0__S16Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S16Imm }, },
  { 10611 /* twu */, PPC::TW, Convert__imm_95_31__RegGPRC1_0__RegGPRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC }, },
  { 10615 /* twui */, PPC::TWI, Convert__imm_95_31__RegGPRC1_0__S16Imm1_1, AMFBS_None, { MCK_RegGPRC, MCK_S16Imm }, },
  { 10620 /* vabsdub */, PPC::VABSDUB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10628 /* vabsduh */, PPC::VABSDUH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10636 /* vabsduw */, PPC::VABSDUW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10644 /* vaddcuq */, PPC::VADDCUQ, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10652 /* vaddcuw */, PPC::VADDCUW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10660 /* vaddecuq */, PPC::VADDECUQ, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10669 /* vaddeuqm */, PPC::VADDEUQM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10678 /* vaddfp */, PPC::VADDFP, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10685 /* vaddsbs */, PPC::VADDSBS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10693 /* vaddshs */, PPC::VADDSHS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10701 /* vaddsws */, PPC::VADDSWS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10709 /* vaddubm */, PPC::VADDUBM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10717 /* vaddubs */, PPC::VADDUBS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10725 /* vaddudm */, PPC::VADDUDM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10733 /* vadduhm */, PPC::VADDUHM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10741 /* vadduhs */, PPC::VADDUHS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10749 /* vadduqm */, PPC::VADDUQM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10757 /* vadduwm */, PPC::VADDUWM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10765 /* vadduws */, PPC::VADDUWS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10773 /* vand */, PPC::VAND, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10778 /* vandc */, PPC::VANDC, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10784 /* vavgsb */, PPC::VAVGSB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10791 /* vavgsh */, PPC::VAVGSH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10798 /* vavgsw */, PPC::VAVGSW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10805 /* vavgub */, PPC::VAVGUB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10812 /* vavguh */, PPC::VAVGUH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10819 /* vavguw */, PPC::VAVGUW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10826 /* vbpermd */, PPC::VBPERMD, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10834 /* vbpermq */, PPC::VBPERMQ, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10842 /* vcfsx */, PPC::VCFSX, Convert__RegVRRC1_0__U5Imm1_2__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_U5Imm }, },
  { 10848 /* vcfux */, PPC::VCFUX, Convert__RegVRRC1_0__U5Imm1_2__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_U5Imm }, },
  { 10854 /* vcipher */, PPC::VCIPHER, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10862 /* vcipherlast */, PPC::VCIPHERLAST, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10874 /* vclzb */, PPC::VCLZB, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 10880 /* vclzd */, PPC::VCLZD, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 10886 /* vclzh */, PPC::VCLZH, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 10892 /* vclzlsbb */, PPC::VCLZLSBB, Convert__RegGPRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegVRRC }, },
  { 10901 /* vclzw */, PPC::VCLZW, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 10907 /* vcmpbfp */, PPC::VCMPBFP, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10907 /* vcmpbfp */, PPC::VCMPBFP_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10915 /* vcmpeqfp */, PPC::VCMPEQFP, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10915 /* vcmpeqfp */, PPC::VCMPEQFP_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10924 /* vcmpequb */, PPC::VCMPEQUB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10924 /* vcmpequb */, PPC::VCMPEQUB_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10933 /* vcmpequd */, PPC::VCMPEQUD, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10933 /* vcmpequd */, PPC::VCMPEQUD_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10942 /* vcmpequh */, PPC::VCMPEQUH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10942 /* vcmpequh */, PPC::VCMPEQUH_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10951 /* vcmpequw */, PPC::VCMPEQUW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10951 /* vcmpequw */, PPC::VCMPEQUW_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10960 /* vcmpgefp */, PPC::VCMPGEFP, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10960 /* vcmpgefp */, PPC::VCMPGEFP_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10969 /* vcmpgtfp */, PPC::VCMPGTFP, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10969 /* vcmpgtfp */, PPC::VCMPGTFP_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10978 /* vcmpgtsb */, PPC::VCMPGTSB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10978 /* vcmpgtsb */, PPC::VCMPGTSB_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10987 /* vcmpgtsd */, PPC::VCMPGTSD, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10987 /* vcmpgtsd */, PPC::VCMPGTSD_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10996 /* vcmpgtsh */, PPC::VCMPGTSH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10996 /* vcmpgtsh */, PPC::VCMPGTSH_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11005 /* vcmpgtsw */, PPC::VCMPGTSW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11005 /* vcmpgtsw */, PPC::VCMPGTSW_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11014 /* vcmpgtub */, PPC::VCMPGTUB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11014 /* vcmpgtub */, PPC::VCMPGTUB_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11023 /* vcmpgtud */, PPC::VCMPGTUD, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11023 /* vcmpgtud */, PPC::VCMPGTUD_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11032 /* vcmpgtuh */, PPC::VCMPGTUH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11032 /* vcmpgtuh */, PPC::VCMPGTUH_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11041 /* vcmpgtuw */, PPC::VCMPGTUW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11041 /* vcmpgtuw */, PPC::VCMPGTUW_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11050 /* vcmpneb */, PPC::VCMPNEB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11050 /* vcmpneb */, PPC::VCMPNEB_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11058 /* vcmpneh */, PPC::VCMPNEH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11058 /* vcmpneh */, PPC::VCMPNEH_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11066 /* vcmpnew */, PPC::VCMPNEW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11066 /* vcmpnew */, PPC::VCMPNEW_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11074 /* vcmpnezb */, PPC::VCMPNEZB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11074 /* vcmpnezb */, PPC::VCMPNEZB_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11083 /* vcmpnezh */, PPC::VCMPNEZH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11083 /* vcmpnezh */, PPC::VCMPNEZH_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11092 /* vcmpnezw */, PPC::VCMPNEZW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11092 /* vcmpnezw */, PPC::VCMPNEZW_rec, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11101 /* vctsxs */, PPC::VCTSXS, Convert__RegVRRC1_0__U5Imm1_2__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_U5Imm }, },
  { 11108 /* vctuxs */, PPC::VCTUXS, Convert__RegVRRC1_0__U5Imm1_2__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_U5Imm }, },
  { 11115 /* vctzb */, PPC::VCTZB, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 11121 /* vctzd */, PPC::VCTZD, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 11127 /* vctzh */, PPC::VCTZH, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 11133 /* vctzlsbb */, PPC::VCTZLSBB, Convert__RegGPRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegGPRC, MCK_RegVRRC }, },
  { 11142 /* vctzw */, PPC::VCTZW, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 11148 /* veqv */, PPC::VEQV, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11153 /* vexptefp */, PPC::VEXPTEFP, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 11162 /* vextractd */, PPC::VEXTRACTD, Convert__RegVRRC1_0__U4Imm1_2__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_U4Imm }, },
  { 11172 /* vextractub */, PPC::VEXTRACTUB, Convert__RegVRRC1_0__U4Imm1_2__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_U4Imm }, },
  { 11183 /* vextractuh */, PPC::VEXTRACTUH, Convert__RegVRRC1_0__U4Imm1_2__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_U4Imm }, },
  { 11194 /* vextractuw */, PPC::VEXTRACTUW, Convert__RegVRRC1_0__U4Imm1_2__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_U4Imm }, },
  { 11205 /* vextsb2d */, PPC::VEXTSB2D, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 11214 /* vextsb2w */, PPC::VEXTSB2W, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 11223 /* vextsh2d */, PPC::VEXTSH2D, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 11232 /* vextsh2w */, PPC::VEXTSH2W, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 11241 /* vextsw2d */, PPC::VEXTSW2D, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 11250 /* vextublx */, PPC::VEXTUBLX, Convert__RegG8RC1_0__RegG8RC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegVRRC }, },
  { 11259 /* vextubrx */, PPC::VEXTUBRX, Convert__RegG8RC1_0__RegG8RC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegVRRC }, },
  { 11268 /* vextuhlx */, PPC::VEXTUHLX, Convert__RegG8RC1_0__RegG8RC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegVRRC }, },
  { 11277 /* vextuhrx */, PPC::VEXTUHRX, Convert__RegG8RC1_0__RegG8RC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegVRRC }, },
  { 11286 /* vextuwlx */, PPC::VEXTUWLX, Convert__RegG8RC1_0__RegG8RC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegVRRC }, },
  { 11295 /* vextuwrx */, PPC::VEXTUWRX, Convert__RegG8RC1_0__RegG8RC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegG8RC, MCK_RegG8RC, MCK_RegVRRC }, },
  { 11304 /* vgbbd */, PPC::VGBBD, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 11310 /* vinsertb */, PPC::VINSERTB, Convert__RegVRRC1_0__Tie0_1_1__U4Imm1_2__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_U4Imm }, },
  { 11319 /* vinsertd */, PPC::VINSERTD, Convert__RegVRRC1_0__U4Imm1_2__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_U4Imm }, },
  { 11328 /* vinserth */, PPC::VINSERTH, Convert__RegVRRC1_0__Tie0_1_1__U4Imm1_2__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_U4Imm }, },
  { 11337 /* vinsertw */, PPC::VINSERTW, Convert__RegVRRC1_0__U4Imm1_2__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_U4Imm }, },
  { 11346 /* vlogefp */, PPC::VLOGEFP, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 11354 /* vmaddfp */, PPC::VMADDFP, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11362 /* vmaxfp */, PPC::VMAXFP, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11369 /* vmaxsb */, PPC::VMAXSB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11376 /* vmaxsd */, PPC::VMAXSD, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11383 /* vmaxsh */, PPC::VMAXSH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11390 /* vmaxsw */, PPC::VMAXSW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11397 /* vmaxub */, PPC::VMAXUB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11404 /* vmaxud */, PPC::VMAXUD, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11411 /* vmaxuh */, PPC::VMAXUH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11418 /* vmaxuw */, PPC::VMAXUW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11425 /* vmhaddshs */, PPC::VMHADDSHS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11435 /* vmhraddshs */, PPC::VMHRADDSHS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11446 /* vminfp */, PPC::VMINFP, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11453 /* vminsb */, PPC::VMINSB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11460 /* vminsd */, PPC::VMINSD, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11467 /* vminsh */, PPC::VMINSH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11474 /* vminsw */, PPC::VMINSW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11481 /* vminub */, PPC::VMINUB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11488 /* vminud */, PPC::VMINUD, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11495 /* vminuh */, PPC::VMINUH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11502 /* vminuw */, PPC::VMINUW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11509 /* vmladduhm */, PPC::VMLADDUHM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11519 /* vmr */, PPC::VOR, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 11523 /* vmrgew */, PPC::VMRGEW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11530 /* vmrghb */, PPC::VMRGHB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11537 /* vmrghh */, PPC::VMRGHH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11544 /* vmrghw */, PPC::VMRGHW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11551 /* vmrglb */, PPC::VMRGLB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11558 /* vmrglh */, PPC::VMRGLH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11565 /* vmrglw */, PPC::VMRGLW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11572 /* vmrgow */, PPC::VMRGOW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11579 /* vmsummbm */, PPC::VMSUMMBM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11588 /* vmsumshm */, PPC::VMSUMSHM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11597 /* vmsumshs */, PPC::VMSUMSHS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11606 /* vmsumubm */, PPC::VMSUMUBM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11615 /* vmsumudm */, PPC::VMSUMUDM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11624 /* vmsumuhm */, PPC::VMSUMUHM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11633 /* vmsumuhs */, PPC::VMSUMUHS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11642 /* vmul10cuq */, PPC::VMUL10CUQ, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 11652 /* vmul10ecuq */, PPC::VMUL10ECUQ, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11663 /* vmul10euq */, PPC::VMUL10EUQ, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11673 /* vmul10uq */, PPC::VMUL10UQ, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 11682 /* vmulesb */, PPC::VMULESB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11690 /* vmulesh */, PPC::VMULESH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11698 /* vmulesw */, PPC::VMULESW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11706 /* vmuleub */, PPC::VMULEUB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11714 /* vmuleuh */, PPC::VMULEUH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11722 /* vmuleuw */, PPC::VMULEUW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11730 /* vmulosb */, PPC::VMULOSB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11738 /* vmulosh */, PPC::VMULOSH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11746 /* vmulosw */, PPC::VMULOSW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11754 /* vmuloub */, PPC::VMULOUB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11762 /* vmulouh */, PPC::VMULOUH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11770 /* vmulouw */, PPC::VMULOUW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11778 /* vmuluwm */, PPC::VMULUWM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11786 /* vnand */, PPC::VNAND, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11792 /* vncipher */, PPC::VNCIPHER, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11801 /* vncipherlast */, PPC::VNCIPHERLAST, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11814 /* vnegd */, PPC::VNEGD, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 11820 /* vnegw */, PPC::VNEGW, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 11826 /* vnmsubfp */, PPC::VNMSUBFP, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11835 /* vnor */, PPC::VNOR, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11840 /* vnot */, PPC::VNOR, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 11845 /* vor */, PPC::VOR, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11849 /* vorc */, PPC::VORC, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11854 /* vperm */, PPC::VPERM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11860 /* vpermr */, PPC::VPERMR, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11867 /* vpermxor */, PPC::VPERMXOR, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11876 /* vpkpx */, PPC::VPKPX, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11882 /* vpksdss */, PPC::VPKSDSS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11890 /* vpksdus */, PPC::VPKSDUS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11898 /* vpkshss */, PPC::VPKSHSS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11906 /* vpkshus */, PPC::VPKSHUS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11914 /* vpkswss */, PPC::VPKSWSS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11922 /* vpkswus */, PPC::VPKSWUS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11930 /* vpkudum */, PPC::VPKUDUM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11938 /* vpkudus */, PPC::VPKUDUS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11946 /* vpkuhum */, PPC::VPKUHUM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11954 /* vpkuhus */, PPC::VPKUHUS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11962 /* vpkuwum */, PPC::VPKUWUM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11970 /* vpkuwus */, PPC::VPKUWUS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11978 /* vpmsumb */, PPC::VPMSUMB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11986 /* vpmsumd */, PPC::VPMSUMD, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 11994 /* vpmsumh */, PPC::VPMSUMH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12002 /* vpmsumw */, PPC::VPMSUMW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12010 /* vpopcntb */, PPC::VPOPCNTB, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12019 /* vpopcntd */, PPC::VPOPCNTD, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12028 /* vpopcnth */, PPC::VPOPCNTH, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12037 /* vpopcntw */, PPC::VPOPCNTW, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12046 /* vprtybd */, PPC::VPRTYBD, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12054 /* vprtybq */, PPC::VPRTYBQ, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12062 /* vprtybw */, PPC::VPRTYBW, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12070 /* vrefp */, PPC::VREFP, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12076 /* vrfim */, PPC::VRFIM, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12082 /* vrfin */, PPC::VRFIN, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12088 /* vrfip */, PPC::VRFIP, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12094 /* vrfiz */, PPC::VRFIZ, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12100 /* vrlb */, PPC::VRLB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12105 /* vrld */, PPC::VRLD, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12110 /* vrldmi */, PPC::VRLDMI, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__Tie0_1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12117 /* vrldnm */, PPC::VRLDNM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12124 /* vrlh */, PPC::VRLH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12129 /* vrlw */, PPC::VRLW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12134 /* vrlwmi */, PPC::VRLWMI, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__Tie0_1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12141 /* vrlwnm */, PPC::VRLWNM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12148 /* vrsqrtefp */, PPC::VRSQRTEFP, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12158 /* vsbox */, PPC::VSBOX, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12164 /* vsel */, PPC::VSEL, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12169 /* vshasigmad */, PPC::VSHASIGMAD, Convert__RegVRRC1_0__RegVRRC1_1__U1Imm1_2__U4Imm1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_U1Imm, MCK_U4Imm }, },
  { 12180 /* vshasigmaw */, PPC::VSHASIGMAW, Convert__RegVRRC1_0__RegVRRC1_1__U1Imm1_2__U4Imm1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_U1Imm, MCK_U4Imm }, },
  { 12191 /* vsl */, PPC::VSL, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12195 /* vslb */, PPC::VSLB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12200 /* vsld */, PPC::VSLD, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12205 /* vsldoi */, PPC::VSLDOI, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__U4Imm1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_U4Imm }, },
  { 12212 /* vslh */, PPC::VSLH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12217 /* vslo */, PPC::VSLO, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12222 /* vslv */, PPC::VSLV, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12227 /* vslw */, PPC::VSLW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12232 /* vspltb */, PPC::VSPLTB, Convert__RegVRRC1_0__U5Imm1_2__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_U5Imm }, },
  { 12239 /* vsplth */, PPC::VSPLTH, Convert__RegVRRC1_0__U5Imm1_2__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_U5Imm }, },
  { 12246 /* vspltisb */, PPC::VSPLTISB, Convert__RegVRRC1_0__S5Imm1_1, AMFBS_None, { MCK_RegVRRC, MCK_S5Imm }, },
  { 12255 /* vspltish */, PPC::VSPLTISH, Convert__RegVRRC1_0__S5Imm1_1, AMFBS_None, { MCK_RegVRRC, MCK_S5Imm }, },
  { 12264 /* vspltisw */, PPC::VSPLTISW, Convert__RegVRRC1_0__S5Imm1_1, AMFBS_None, { MCK_RegVRRC, MCK_S5Imm }, },
  { 12273 /* vspltw */, PPC::VSPLTW, Convert__RegVRRC1_0__U5Imm1_2__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_U5Imm }, },
  { 12280 /* vsr */, PPC::VSR, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12284 /* vsrab */, PPC::VSRAB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12290 /* vsrad */, PPC::VSRAD, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12296 /* vsrah */, PPC::VSRAH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12302 /* vsraw */, PPC::VSRAW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12308 /* vsrb */, PPC::VSRB, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12313 /* vsrd */, PPC::VSRD, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12318 /* vsrh */, PPC::VSRH, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12323 /* vsro */, PPC::VSRO, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12328 /* vsrv */, PPC::VSRV, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12333 /* vsrw */, PPC::VSRW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12338 /* vsubcuq */, PPC::VSUBCUQ, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12346 /* vsubcuw */, PPC::VSUBCUW, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12354 /* vsubecuq */, PPC::VSUBECUQ, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12363 /* vsubeuqm */, PPC::VSUBEUQM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12372 /* vsubfp */, PPC::VSUBFP, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12379 /* vsubsbs */, PPC::VSUBSBS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12387 /* vsubshs */, PPC::VSUBSHS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12395 /* vsubsws */, PPC::VSUBSWS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12403 /* vsububm */, PPC::VSUBUBM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12411 /* vsububs */, PPC::VSUBUBS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12419 /* vsubudm */, PPC::VSUBUDM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12427 /* vsubuhm */, PPC::VSUBUHM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12435 /* vsubuhs */, PPC::VSUBUHS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12443 /* vsubuqm */, PPC::VSUBUQM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12451 /* vsubuwm */, PPC::VSUBUWM, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12459 /* vsubuws */, PPC::VSUBUWS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12467 /* vsum2sws */, PPC::VSUM2SWS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12476 /* vsum4sbs */, PPC::VSUM4SBS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12485 /* vsum4shs */, PPC::VSUM4SHS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12494 /* vsum4ubs */, PPC::VSUM4UBS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12503 /* vsumsws */, PPC::VSUMSWS, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12511 /* vupkhpx */, PPC::VUPKHPX, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12519 /* vupkhsb */, PPC::VUPKHSB, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12527 /* vupkhsh */, PPC::VUPKHSH, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12535 /* vupkhsw */, PPC::VUPKHSW, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12543 /* vupklpx */, PPC::VUPKLPX, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12551 /* vupklsb */, PPC::VUPKLSB, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12559 /* vupklsh */, PPC::VUPKLSH, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12567 /* vupklsw */, PPC::VUPKLSW, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12575 /* vxor */, PPC::VXOR, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12580 /* wait */, PPC::WAIT, Convert__imm_95_0, AMFBS_None, {  }, },
  { 12580 /* wait */, PPC::WAIT, Convert__Imm1_0, AMFBS_None, { MCK_Imm }, },
  { 12585 /* waitimpl */, PPC::WAIT, Convert__imm_95_2, AMFBS_None, {  }, },
  { 12594 /* waitrsv */, PPC::WAIT, Convert__imm_95_1, AMFBS_None, {  }, },
  { 12602 /* wrtee */, PPC::WRTEE, Convert__RegGPRC1_0, AMFBS_None, { MCK_RegGPRC }, },
  { 12608 /* wrteei */, PPC::WRTEEI, Convert__Imm1_0, AMFBS_None, { MCK_Imm }, },
  { 12615 /* xnop */, PPC::XORI8, Convert__regX0__regX0__imm_95_0, AMFBS_None, {  }, },
  { 12615 /* xnop */, PPC::XORI, Convert__regR0__regR0__imm_95_0, AMFBS_None, {  }, },
  { 12620 /* xor */, PPC::XOR, Convert__RegGPRC1_0__RegGPRC1_1__RegGPRC1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 12620 /* xor */, PPC::XOR_rec, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 12624 /* xori */, PPC::XORI, Convert__RegGPRC1_0__RegGPRC1_1__U16Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U16Imm }, },
  { 12629 /* xoris */, PPC::XORIS, Convert__RegGPRC1_0__RegGPRC1_1__U16Imm1_2, AMFBS_None, { MCK_RegGPRC, MCK_RegGPRC, MCK_U16Imm }, },
  { 12635 /* xsabsdp */, PPC::XSABSDP, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 12643 /* xsabsqp */, PPC::XSABSQP, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12651 /* xsadddp */, PPC::XSADDDP, Convert__RegVSFRC1_0__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 12659 /* xsaddqp */, PPC::XSADDQP, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12667 /* xsaddqpo */, PPC::XSADDQPO, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12676 /* xsaddsp */, PPC::XSADDSP, Convert__RegVSSRC1_0__RegVSSRC1_1__RegVSSRC1_2, AMFBS_None, { MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 12684 /* xscmpeqdp */, PPC::XSCMPEQDP, Convert__RegVSRC1_0__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 12694 /* xscmpexpdp */, PPC::XSCMPEXPDP, Convert__RegCRRC1_0__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 12705 /* xscmpexpqp */, PPC::XSCMPEXPQP, Convert__RegCRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12716 /* xscmpgedp */, PPC::XSCMPGEDP, Convert__RegVSRC1_0__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 12726 /* xscmpgtdp */, PPC::XSCMPGTDP, Convert__RegVSRC1_0__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 12736 /* xscmpodp */, PPC::XSCMPODP, Convert__RegCRRC1_0__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 12745 /* xscmpoqp */, PPC::XSCMPOQP, Convert__RegCRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12754 /* xscmpudp */, PPC::XSCMPUDP, Convert__RegCRRC1_0__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 12763 /* xscmpuqp */, PPC::XSCMPUQP, Convert__RegCRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12772 /* xscpsgndp */, PPC::XSCPSGNDP, Convert__RegVSFRC1_0__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 12782 /* xscpsgnqp */, PPC::XSCPSGNQP, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 12792 /* xscvdphp */, PPC::XSCVDPHP, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 12801 /* xscvdpqp */, PPC::XSCVDPQP, Convert__RegVRRC1_0__RegVFRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVFRC }, },
  { 12810 /* xscvdpsp */, PPC::XSCVDPSP, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 12819 /* xscvdpspn */, PPC::XSCVDPSPN, Convert__RegVSRC1_0__RegVSSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSSRC }, },
  { 12829 /* xscvdpsxds */, PPC::XSCVDPSXDS, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 12840 /* xscvdpsxws */, PPC::XSCVDPSXWS, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 12851 /* xscvdpuxds */, PPC::XSCVDPUXDS, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 12862 /* xscvdpuxws */, PPC::XSCVDPUXWS, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 12873 /* xscvhpdp */, PPC::XSCVHPDP, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 12882 /* xscvqpdp */, PPC::XSCVQPDP, Convert__RegVFRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVFRC, MCK_RegVRRC }, },
  { 12891 /* xscvqpdpo */, PPC::XSCVQPDPO, Convert__RegVFRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVFRC, MCK_RegVRRC }, },
  { 12901 /* xscvqpsdz */, PPC::XSCVQPSDZ, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12911 /* xscvqpswz */, PPC::XSCVQPSWZ, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12921 /* xscvqpudz */, PPC::XSCVQPUDZ, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12931 /* xscvqpuwz */, PPC::XSCVQPUWZ, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 12941 /* xscvsdqp */, PPC::XSCVSDQP, Convert__RegVRRC1_0__RegVFRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVFRC }, },
  { 12950 /* xscvspdp */, PPC::XSCVSPDP, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 12959 /* xscvspdpn */, PPC::XSCVSPDPN, Convert__RegVSSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSSRC, MCK_RegVSRC }, },
  { 12969 /* xscvsxddp */, PPC::XSCVSXDDP, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 12979 /* xscvsxdsp */, PPC::XSCVSXDSP, Convert__RegVSSRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSSRC, MCK_RegVSFRC }, },
  { 12989 /* xscvudqp */, PPC::XSCVUDQP, Convert__RegVRRC1_0__RegVFRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVFRC }, },
  { 12998 /* xscvuxddp */, PPC::XSCVUXDDP, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13008 /* xscvuxdsp */, PPC::XSCVUXDSP, Convert__RegVSSRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSSRC, MCK_RegVSFRC }, },
  { 13018 /* xsdivdp */, PPC::XSDIVDP, Convert__RegVSFRC1_0__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13026 /* xsdivqp */, PPC::XSDIVQP, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 13034 /* xsdivqpo */, PPC::XSDIVQPO, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 13043 /* xsdivsp */, PPC::XSDIVSP, Convert__RegVSSRC1_0__RegVSSRC1_1__RegVSSRC1_2, AMFBS_None, { MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 13051 /* xsiexpdp */, PPC::XSIEXPDP, Convert__RegVSRC1_0__RegG8RC1_1__RegG8RC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 13060 /* xsiexpqp */, PPC::XSIEXPQP, Convert__RegVRRC1_0__RegVRRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVSFRC }, },
  { 13069 /* xsmaddadp */, PPC::XSMADDADP, Convert__RegVSFRC1_0__Tie0_1_1__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13079 /* xsmaddasp */, PPC::XSMADDASP, Convert__RegVSSRC1_0__Tie0_1_1__RegVSSRC1_1__RegVSSRC1_2, AMFBS_None, { MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 13089 /* xsmaddmdp */, PPC::XSMADDMDP, Convert__RegVSFRC1_0__Tie0_1_1__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13099 /* xsmaddmsp */, PPC::XSMADDMSP, Convert__RegVSSRC1_0__Tie0_1_1__RegVSSRC1_1__RegVSSRC1_2, AMFBS_None, { MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 13109 /* xsmaddqp */, PPC::XSMADDQP, Convert__RegVRRC1_0__Tie0_1_1__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 13118 /* xsmaddqpo */, PPC::XSMADDQPO, Convert__RegVRRC1_0__Tie0_1_1__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 13128 /* xsmaxcdp */, PPC::XSMAXCDP, Convert__RegVSFRC1_0__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13137 /* xsmaxdp */, PPC::XSMAXDP, Convert__RegVSFRC1_0__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13145 /* xsmaxjdp */, PPC::XSMAXJDP, Convert__RegVSRC1_0__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13154 /* xsmincdp */, PPC::XSMINCDP, Convert__RegVSFRC1_0__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13163 /* xsmindp */, PPC::XSMINDP, Convert__RegVSFRC1_0__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13171 /* xsminjdp */, PPC::XSMINJDP, Convert__RegVSRC1_0__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13180 /* xsmsubadp */, PPC::XSMSUBADP, Convert__RegVSFRC1_0__Tie0_1_1__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13190 /* xsmsubasp */, PPC::XSMSUBASP, Convert__RegVSSRC1_0__Tie0_1_1__RegVSSRC1_1__RegVSSRC1_2, AMFBS_None, { MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 13200 /* xsmsubmdp */, PPC::XSMSUBMDP, Convert__RegVSFRC1_0__Tie0_1_1__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13210 /* xsmsubmsp */, PPC::XSMSUBMSP, Convert__RegVSSRC1_0__Tie0_1_1__RegVSSRC1_1__RegVSSRC1_2, AMFBS_None, { MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 13220 /* xsmsubqp */, PPC::XSMSUBQP, Convert__RegVRRC1_0__Tie0_1_1__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 13229 /* xsmsubqpo */, PPC::XSMSUBQPO, Convert__RegVRRC1_0__Tie0_1_1__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 13239 /* xsmuldp */, PPC::XSMULDP, Convert__RegVSFRC1_0__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13247 /* xsmulqp */, PPC::XSMULQP, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 13255 /* xsmulqpo */, PPC::XSMULQPO, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 13264 /* xsmulsp */, PPC::XSMULSP, Convert__RegVSSRC1_0__RegVSSRC1_1__RegVSSRC1_2, AMFBS_None, { MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 13272 /* xsnabsdp */, PPC::XSNABSDP, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13281 /* xsnabsqp */, PPC::XSNABSQP, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 13290 /* xsnegdp */, PPC::XSNEGDP, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13298 /* xsnegqp */, PPC::XSNEGQP, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 13306 /* xsnmaddadp */, PPC::XSNMADDADP, Convert__RegVSFRC1_0__Tie0_1_1__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13317 /* xsnmaddasp */, PPC::XSNMADDASP, Convert__RegVSSRC1_0__Tie0_1_1__RegVSSRC1_1__RegVSSRC1_2, AMFBS_None, { MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 13328 /* xsnmaddmdp */, PPC::XSNMADDMDP, Convert__RegVSFRC1_0__Tie0_1_1__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13339 /* xsnmaddmsp */, PPC::XSNMADDMSP, Convert__RegVSSRC1_0__Tie0_1_1__RegVSSRC1_1__RegVSSRC1_2, AMFBS_None, { MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 13350 /* xsnmaddqp */, PPC::XSNMADDQP, Convert__RegVRRC1_0__Tie0_1_1__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 13360 /* xsnmaddqpo */, PPC::XSNMADDQPO, Convert__RegVRRC1_0__Tie0_1_1__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 13371 /* xsnmsubadp */, PPC::XSNMSUBADP, Convert__RegVSFRC1_0__Tie0_1_1__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13382 /* xsnmsubasp */, PPC::XSNMSUBASP, Convert__RegVSSRC1_0__Tie0_1_1__RegVSSRC1_1__RegVSSRC1_2, AMFBS_None, { MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 13393 /* xsnmsubmdp */, PPC::XSNMSUBMDP, Convert__RegVSFRC1_0__Tie0_1_1__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13404 /* xsnmsubmsp */, PPC::XSNMSUBMSP, Convert__RegVSSRC1_0__Tie0_1_1__RegVSSRC1_1__RegVSSRC1_2, AMFBS_None, { MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 13415 /* xsnmsubqp */, PPC::XSNMSUBQP, Convert__RegVRRC1_0__Tie0_1_1__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 13425 /* xsnmsubqpo */, PPC::XSNMSUBQPO, Convert__RegVRRC1_0__Tie0_1_1__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 13436 /* xsrdpi */, PPC::XSRDPI, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13443 /* xsrdpic */, PPC::XSRDPIC, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13451 /* xsrdpim */, PPC::XSRDPIM, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13459 /* xsrdpip */, PPC::XSRDPIP, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13467 /* xsrdpiz */, PPC::XSRDPIZ, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13475 /* xsredp */, PPC::XSREDP, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13482 /* xsresp */, PPC::XSRESP, Convert__RegVSSRC1_0__RegVSSRC1_1, AMFBS_None, { MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 13489 /* xsrqpi */, PPC::XSRQPI, Convert__RegVRRC1_1__U1Imm1_0__RegVRRC1_2__U2Imm1_3, AMFBS_None, { MCK_U1Imm, MCK_RegVRRC, MCK_RegVRRC, MCK_U2Imm }, },
  { 13496 /* xsrqpix */, PPC::XSRQPIX, Convert__RegVRRC1_1__U1Imm1_0__RegVRRC1_2__U2Imm1_3, AMFBS_None, { MCK_U1Imm, MCK_RegVRRC, MCK_RegVRRC, MCK_U2Imm }, },
  { 13504 /* xsrqpxp */, PPC::XSRQPXP, Convert__RegVRRC1_1__U1Imm1_0__RegVRRC1_2__U2Imm1_3, AMFBS_None, { MCK_U1Imm, MCK_RegVRRC, MCK_RegVRRC, MCK_U2Imm }, },
  { 13512 /* xsrsp */, PPC::XSRSP, Convert__RegVSSRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSSRC, MCK_RegVSFRC }, },
  { 13518 /* xsrsqrtedp */, PPC::XSRSQRTEDP, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13529 /* xsrsqrtesp */, PPC::XSRSQRTESP, Convert__RegVSSRC1_0__RegVSSRC1_1, AMFBS_None, { MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 13540 /* xssqrtdp */, PPC::XSSQRTDP, Convert__RegVSFRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13549 /* xssqrtqp */, PPC::XSSQRTQP, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 13558 /* xssqrtqpo */, PPC::XSSQRTQPO, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 13568 /* xssqrtsp */, PPC::XSSQRTSP, Convert__RegVSSRC1_0__RegVSSRC1_1, AMFBS_None, { MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 13577 /* xssubdp */, PPC::XSSUBDP, Convert__RegVSFRC1_0__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13585 /* xssubqp */, PPC::XSSUBQP, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 13593 /* xssubqpo */, PPC::XSSUBQPO, Convert__RegVRRC1_0__RegVRRC1_1__RegVRRC1_2, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 13602 /* xssubsp */, PPC::XSSUBSP, Convert__RegVSSRC1_0__RegVSSRC1_1__RegVSSRC1_2, AMFBS_None, { MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 13610 /* xstdivdp */, PPC::XSTDIVDP, Convert__RegCRRC1_0__RegVSFRC1_1__RegVSFRC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 13619 /* xstsqrtdp */, PPC::XSTSQRTDP, Convert__RegCRRC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegCRRC, MCK_RegVSFRC }, },
  { 13629 /* xststdcdp */, PPC::XSTSTDCDP, Convert__RegCRRC1_0__U7Imm1_2__RegVSFRC1_1, AMFBS_None, { MCK_RegCRRC, MCK_RegVSFRC, MCK_U7Imm }, },
  { 13639 /* xststdcqp */, PPC::XSTSTDCQP, Convert__RegCRRC1_0__U7Imm1_2__RegVRRC1_1, AMFBS_None, { MCK_RegCRRC, MCK_RegVRRC, MCK_U7Imm }, },
  { 13649 /* xststdcsp */, PPC::XSTSTDCSP, Convert__RegCRRC1_0__U7Imm1_2__RegVSFRC1_1, AMFBS_None, { MCK_RegCRRC, MCK_RegVSFRC, MCK_U7Imm }, },
  { 13659 /* xsxexpdp */, PPC::XSXEXPDP, Convert__RegG8RC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegVSFRC }, },
  { 13668 /* xsxexpqp */, PPC::XSXEXPQP, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 13677 /* xsxsigdp */, PPC::XSXSIGDP, Convert__RegG8RC1_0__RegVSFRC1_1, AMFBS_None, { MCK_RegG8RC, MCK_RegVSFRC }, },
  { 13686 /* xsxsigqp */, PPC::XSXSIGQP, Convert__RegVRRC1_0__RegVRRC1_1, AMFBS_None, { MCK_RegVRRC, MCK_RegVRRC }, },
  { 13695 /* xvabsdp */, PPC::XVABSDP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 13703 /* xvabssp */, PPC::XVABSSP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 13711 /* xvadddp */, PPC::XVADDDP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 13719 /* xvaddsp */, PPC::XVADDSP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 13727 /* xvcmpeqdp */, PPC::XVCMPEQDP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 13727 /* xvcmpeqdp */, PPC::XVCMPEQDP_rec, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 13737 /* xvcmpeqsp */, PPC::XVCMPEQSP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 13737 /* xvcmpeqsp */, PPC::XVCMPEQSP_rec, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 13747 /* xvcmpgedp */, PPC::XVCMPGEDP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 13747 /* xvcmpgedp */, PPC::XVCMPGEDP_rec, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 13757 /* xvcmpgesp */, PPC::XVCMPGESP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 13757 /* xvcmpgesp */, PPC::XVCMPGESP_rec, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 13767 /* xvcmpgtdp */, PPC::XVCMPGTDP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 13767 /* xvcmpgtdp */, PPC::XVCMPGTDP_rec, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 13777 /* xvcmpgtsp */, PPC::XVCMPGTSP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 13777 /* xvcmpgtsp */, PPC::XVCMPGTSP_rec, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, AMFBS_None, { MCK__DOT_, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 13787 /* xvcpsgndp */, PPC::XVCPSGNDP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 13797 /* xvcpsgnsp */, PPC::XVCPSGNSP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 13807 /* xvcvdpsp */, PPC::XVCVDPSP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 13816 /* xvcvdpsxds */, PPC::XVCVDPSXDS, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 13827 /* xvcvdpsxws */, PPC::XVCVDPSXWS, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 13838 /* xvcvdpuxds */, PPC::XVCVDPUXDS, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 13849 /* xvcvdpuxws */, PPC::XVCVDPUXWS, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 13860 /* xvcvhpsp */, PPC::XVCVHPSP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 13869 /* xvcvspdp */, PPC::XVCVSPDP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 13878 /* xvcvsphp */, PPC::XVCVSPHP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 13887 /* xvcvspsxds */, PPC::XVCVSPSXDS, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 13898 /* xvcvspsxws */, PPC::XVCVSPSXWS, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 13909 /* xvcvspuxds */, PPC::XVCVSPUXDS, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 13920 /* xvcvspuxws */, PPC::XVCVSPUXWS, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 13931 /* xvcvsxddp */, PPC::XVCVSXDDP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 13941 /* xvcvsxdsp */, PPC::XVCVSXDSP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 13951 /* xvcvsxwdp */, PPC::XVCVSXWDP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 13961 /* xvcvsxwsp */, PPC::XVCVSXWSP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 13971 /* xvcvuxddp */, PPC::XVCVUXDDP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 13981 /* xvcvuxdsp */, PPC::XVCVUXDSP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 13991 /* xvcvuxwdp */, PPC::XVCVUXWDP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14001 /* xvcvuxwsp */, PPC::XVCVUXWSP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14011 /* xvdivdp */, PPC::XVDIVDP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14019 /* xvdivsp */, PPC::XVDIVSP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14027 /* xviexpdp */, PPC::XVIEXPDP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14036 /* xviexpsp */, PPC::XVIEXPSP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14045 /* xvmaddadp */, PPC::XVMADDADP, Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14055 /* xvmaddasp */, PPC::XVMADDASP, Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14065 /* xvmaddmdp */, PPC::XVMADDMDP, Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14075 /* xvmaddmsp */, PPC::XVMADDMSP, Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14085 /* xvmaxdp */, PPC::XVMAXDP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14093 /* xvmaxsp */, PPC::XVMAXSP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14101 /* xvmindp */, PPC::XVMINDP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14109 /* xvminsp */, PPC::XVMINSP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14117 /* xvmovdp */, PPC::XVCPSGNDP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14125 /* xvmovsp */, PPC::XVCPSGNSP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14133 /* xvmsubadp */, PPC::XVMSUBADP, Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14143 /* xvmsubasp */, PPC::XVMSUBASP, Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14153 /* xvmsubmdp */, PPC::XVMSUBMDP, Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14163 /* xvmsubmsp */, PPC::XVMSUBMSP, Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14173 /* xvmuldp */, PPC::XVMULDP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14181 /* xvmulsp */, PPC::XVMULSP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14189 /* xvnabsdp */, PPC::XVNABSDP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14198 /* xvnabssp */, PPC::XVNABSSP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14207 /* xvnegdp */, PPC::XVNEGDP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14215 /* xvnegsp */, PPC::XVNEGSP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14223 /* xvnmaddadp */, PPC::XVNMADDADP, Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14234 /* xvnmaddasp */, PPC::XVNMADDASP, Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14245 /* xvnmaddmdp */, PPC::XVNMADDMDP, Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14256 /* xvnmaddmsp */, PPC::XVNMADDMSP, Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14267 /* xvnmsubadp */, PPC::XVNMSUBADP, Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14278 /* xvnmsubasp */, PPC::XVNMSUBASP, Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14289 /* xvnmsubmdp */, PPC::XVNMSUBMDP, Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14300 /* xvnmsubmsp */, PPC::XVNMSUBMSP, Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14311 /* xvrdpi */, PPC::XVRDPI, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14318 /* xvrdpic */, PPC::XVRDPIC, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14326 /* xvrdpim */, PPC::XVRDPIM, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14334 /* xvrdpip */, PPC::XVRDPIP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14342 /* xvrdpiz */, PPC::XVRDPIZ, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14350 /* xvredp */, PPC::XVREDP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14357 /* xvresp */, PPC::XVRESP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14364 /* xvrspi */, PPC::XVRSPI, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14371 /* xvrspic */, PPC::XVRSPIC, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14379 /* xvrspim */, PPC::XVRSPIM, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14387 /* xvrspip */, PPC::XVRSPIP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14395 /* xvrspiz */, PPC::XVRSPIZ, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14403 /* xvrsqrtedp */, PPC::XVRSQRTEDP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14414 /* xvrsqrtesp */, PPC::XVRSQRTESP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14425 /* xvsqrtdp */, PPC::XVSQRTDP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14434 /* xvsqrtsp */, PPC::XVSQRTSP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14443 /* xvsubdp */, PPC::XVSUBDP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14451 /* xvsubsp */, PPC::XVSUBSP, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14459 /* xvtdivdp */, PPC::XVTDIVDP, Convert__RegCRRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14468 /* xvtdivsp */, PPC::XVTDIVSP, Convert__RegCRRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegCRRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14477 /* xvtsqrtdp */, PPC::XVTSQRTDP, Convert__RegCRRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegCRRC, MCK_RegVSRC }, },
  { 14487 /* xvtsqrtsp */, PPC::XVTSQRTSP, Convert__RegCRRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegCRRC, MCK_RegVSRC }, },
  { 14497 /* xvtstdcdp */, PPC::XVTSTDCDP, Convert__RegVSRC1_0__U7Imm1_2__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_U7Imm }, },
  { 14507 /* xvtstdcsp */, PPC::XVTSTDCSP, Convert__RegVSRC1_0__U7Imm1_2__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_U7Imm }, },
  { 14517 /* xvxexpdp */, PPC::XVXEXPDP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14526 /* xvxexpsp */, PPC::XVXEXPSP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14535 /* xvxsigdp */, PPC::XVXSIGDP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14544 /* xvxsigsp */, PPC::XVXSIGSP, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14553 /* xxbrd */, PPC::XXBRD, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14559 /* xxbrh */, PPC::XXBRH, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14565 /* xxbrq */, PPC::XXBRQ, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14571 /* xxbrw */, PPC::XXBRW, Convert__RegVSRC1_0__RegVSRC1_1, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
  { 14577 /* xxextractuw */, PPC::XXEXTRACTUW, Convert__RegVSFRC1_0__RegVSRC1_1__U4Imm1_2, AMFBS_None, { MCK_RegVSFRC, MCK_RegVSRC, MCK_U4Imm }, },
  { 14589 /* xxinsertw */, PPC::XXINSERTW, Convert__RegVSRC1_0__Tie0_1_1__RegVSRC1_1__U4Imm1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_U4Imm }, },
  { 14599 /* xxland */, PPC::XXLAND, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14606 /* xxlandc */, PPC::XXLANDC, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14614 /* xxleqv */, PPC::XXLEQV, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14621 /* xxlnand */, PPC::XXLNAND, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14629 /* xxlnor */, PPC::XXLNOR, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14636 /* xxlor */, PPC::XXLOR, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14642 /* xxlorc */, PPC::XXLORC, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14649 /* xxlxor */, PPC::XXLXOR, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14656 /* xxmrghd */, PPC::XXPERMDI, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2__imm_95_0, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14664 /* xxmrghw */, PPC::XXMRGHW, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14672 /* xxmrgld */, PPC::XXPERMDI, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2__imm_95_3, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14680 /* xxmrglw */, PPC::XXMRGLW, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14688 /* xxperm */, PPC::XXPERM, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14695 /* xxpermdi */, PPC::XXPERMDI, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2__U2Imm1_3, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC, MCK_U2Imm }, },
  { 14704 /* xxpermr */, PPC::XXPERMR, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14712 /* xxsel */, PPC::XXSEL, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 14718 /* xxsldwi */, PPC::XXSLDWI, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_2__U2Imm1_3, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC, MCK_U2Imm }, },
  { 14726 /* xxspltd */, PPC::XXPERMDIs, Convert__RegVSRC1_0__RegVSFRC1_1__imm_95_0, AMFBS_None, { MCK_RegVSRC, MCK_RegVSFRC, MCK_0 }, },
  { 14726 /* xxspltd */, PPC::XXPERMDIs, Convert__RegVSRC1_0__RegVSFRC1_1__imm_95_3, AMFBS_None, { MCK_RegVSRC, MCK_RegVSFRC, MCK_1 }, },
  { 14726 /* xxspltd */, PPC::XXPERMDI, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_1__imm_95_0, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_0 }, },
  { 14726 /* xxspltd */, PPC::XXPERMDI, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_1__imm_95_3, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_1 }, },
  { 14734 /* xxspltib */, PPC::XXSPLTIB, Convert__RegVSRC1_0__U8Imm1_1, AMFBS_None, { MCK_RegVSRC, MCK_U8Imm }, },
  { 14743 /* xxspltw */, PPC::XXSPLTW, Convert__RegVSRC1_0__RegVSRC1_1__U2Imm1_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC, MCK_U2Imm }, },
  { 14751 /* xxswapd */, PPC::XXPERMDIs, Convert__RegVSRC1_0__RegVSFRC1_1__imm_95_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSFRC }, },
  { 14751 /* xxswapd */, PPC::XXPERMDI, Convert__RegVSRC1_0__RegVSRC1_1__RegVSRC1_1__imm_95_2, AMFBS_None, { MCK_RegVSRC, MCK_RegVSRC }, },
};

#include "llvm/Support/Debug.h"
#include "llvm/Support/Format.h"

unsigned PPCAsmParser::
MatchInstructionImpl(const OperandVector &Operands,
                     MCInst &Inst,
                     uint64_t &ErrorInfo,
                     FeatureBitset &MissingFeatures,
                     bool matchingInlineAsm, unsigned VariantID) {
  // Eliminate obvious mismatches.
  if (Operands.size() > 7) {
    ErrorInfo = 7;
    return Match_InvalidOperand;
  }

  // Get the current feature set.
  const FeatureBitset &AvailableFeatures = getAvailableFeatures();

  // Get the instruction mnemonic, which is the first token.
  StringRef Mnemonic = ((PPCOperand&)*Operands[0]).getToken();

  // Process all MnemonicAliases to remap the mnemonic.
  applyMnemonicAliases(Mnemonic, AvailableFeatures, VariantID);

  // Some state to try to produce better error messages.
  bool HadMatchOtherThanFeatures = false;
  bool HadMatchOtherThanPredicate = false;
  unsigned RetCode = Match_InvalidOperand;
  MissingFeatures.set();
  // Set ErrorInfo to the operand that mismatches if it is
  // wrong for all instances of the instruction.
  ErrorInfo = ~0ULL;
  // Find the appropriate table for this asm variant.
  const MatchEntry *Start, *End;
  switch (VariantID) {
  default: llvm_unreachable("invalid variant!");
  case 0: Start = std::begin(MatchTable0); End = std::end(MatchTable0); break;
  }
  // Search the table.
  auto MnemonicRange = std::equal_range(Start, End, Mnemonic, LessOpcode());

  DEBUG_WITH_TYPE("asm-matcher", dbgs() << "AsmMatcher: found " <<
  std::distance(MnemonicRange.first, MnemonicRange.second) << 
  " encodings with mnemonic '" << Mnemonic << "'\n");

  // Return a more specific error code if no mnemonics match.
  if (MnemonicRange.first == MnemonicRange.second)
    return Match_MnemonicFail;

  for (const MatchEntry *it = MnemonicRange.first, *ie = MnemonicRange.second;
       it != ie; ++it) {
    const FeatureBitset &RequiredFeatures = FeatureBitsets[it->RequiredFeaturesIdx];
    bool HasRequiredFeatures =
      (AvailableFeatures & RequiredFeatures) == RequiredFeatures;
    DEBUG_WITH_TYPE("asm-matcher", dbgs() << "Trying to match opcode "
                                          << MII.getName(it->Opcode) << "\n");
    // equal_range guarantees that instruction mnemonic matches.
    assert(Mnemonic == it->getMnemonic());
    bool OperandsValid = true;
    for (unsigned FormalIdx = 0, ActualIdx = 1; FormalIdx != 6; ++FormalIdx) {
      auto Formal = static_cast<MatchClassKind>(it->Classes[FormalIdx]);
      DEBUG_WITH_TYPE("asm-matcher",
                      dbgs() << "  Matching formal operand class " << getMatchClassName(Formal)
                             << " against actual operand at index " << ActualIdx);
      if (ActualIdx < Operands.size())
        DEBUG_WITH_TYPE("asm-matcher", dbgs() << " (";
                        Operands[ActualIdx]->print(dbgs()); dbgs() << "): ");
      else
        DEBUG_WITH_TYPE("asm-matcher", dbgs() << ": ");
      if (ActualIdx >= Operands.size()) {
        DEBUG_WITH_TYPE("asm-matcher", dbgs() << "actual operand index out of range ");
        OperandsValid = (Formal == InvalidMatchClass) || isSubclass(Formal, OptionalMatchClass);
        if (!OperandsValid) ErrorInfo = ActualIdx;
        break;
      }
      MCParsedAsmOperand &Actual = *Operands[ActualIdx];
      unsigned Diag = validateOperandClass(Actual, Formal);
      if (Diag == Match_Success) {
        DEBUG_WITH_TYPE("asm-matcher",
                        dbgs() << "match success using generic matcher\n");
        ++ActualIdx;
        continue;
      }
      // If the generic handler indicates an invalid operand
      // failure, check for a special case.
      if (Diag != Match_Success) {
        unsigned TargetDiag = validateTargetOperandClass(Actual, Formal);
        if (TargetDiag == Match_Success) {
          DEBUG_WITH_TYPE("asm-matcher",
                          dbgs() << "match success using target matcher\n");
          ++ActualIdx;
          continue;
        }
        // If the target matcher returned a specific error code use
        // that, else use the one from the generic matcher.
        if (TargetDiag != Match_InvalidOperand && HasRequiredFeatures)
          Diag = TargetDiag;
      }
      // If current formal operand wasn't matched and it is optional
      // then try to match next formal operand
      if (Diag == Match_InvalidOperand && isSubclass(Formal, OptionalMatchClass)) {
        DEBUG_WITH_TYPE("asm-matcher", dbgs() << "ignoring optional operand\n");
        continue;
      }
      // If this operand is broken for all of the instances of this
      // mnemonic, keep track of it so we can report loc info.
      // If we already had a match that only failed due to a
      // target predicate, that diagnostic is preferred.
      if (!HadMatchOtherThanPredicate &&
          (it == MnemonicRange.first || ErrorInfo <= ActualIdx)) {
        if (HasRequiredFeatures && (ErrorInfo != ActualIdx || Diag != Match_InvalidOperand))
          RetCode = Diag;
        ErrorInfo = ActualIdx;
      }
      // Otherwise, just reject this instance of the mnemonic.
      OperandsValid = false;
      break;
    }

    if (!OperandsValid) {
      DEBUG_WITH_TYPE("asm-matcher", dbgs() << "Opcode result: multiple "
                                               "operand mismatches, ignoring "
                                               "this opcode\n");
      continue;
    }
    if (!HasRequiredFeatures) {
      HadMatchOtherThanFeatures = true;
      FeatureBitset NewMissingFeatures = RequiredFeatures & ~AvailableFeatures;
      DEBUG_WITH_TYPE("asm-matcher", dbgs() << "Missing target features:";
                       for (unsigned I = 0, E = NewMissingFeatures.size(); I != E; ++I)
                         if (NewMissingFeatures[I])
                           dbgs() << ' ' << I;
                       dbgs() << "\n");
      if (NewMissingFeatures.count() <=
          MissingFeatures.count())
        MissingFeatures = NewMissingFeatures;
      continue;
    }

    Inst.clear();

    Inst.setOpcode(it->Opcode);
    // We have a potential match but have not rendered the operands.
    // Check the target predicate to handle any context sensitive
    // constraints.
    // For example, Ties that are referenced multiple times must be
    // checked here to ensure the input is the same for each match
    // constraints. If we leave it any later the ties will have been
    // canonicalized
    unsigned MatchResult;
    if ((MatchResult = checkEarlyTargetMatchPredicate(Inst, Operands)) != Match_Success) {
      Inst.clear();
      DEBUG_WITH_TYPE(
          "asm-matcher",
          dbgs() << "Early target match predicate failed with diag code "
                 << MatchResult << "\n");
      RetCode = MatchResult;
      HadMatchOtherThanPredicate = true;
      continue;
    }

    if (matchingInlineAsm) {
      convertToMapAndConstraints(it->ConvertFn, Operands);
      if (!checkAsmTiedOperandConstraints(*this, it->ConvertFn, Operands, ErrorInfo))
        return Match_InvalidTiedOperand;

      return Match_Success;
    }

    // We have selected a definite instruction, convert the parsed
    // operands into the appropriate MCInst.
    convertToMCInst(it->ConvertFn, Inst, it->Opcode, Operands);

    // We have a potential match. Check the target predicate to
    // handle any context sensitive constraints.
    if ((MatchResult = checkTargetMatchPredicate(Inst)) != Match_Success) {
      DEBUG_WITH_TYPE("asm-matcher",
                      dbgs() << "Target match predicate failed with diag code "
                             << MatchResult << "\n");
      Inst.clear();
      RetCode = MatchResult;
      HadMatchOtherThanPredicate = true;
      continue;
    }

    std::string Info;
    if (!getParser().getTargetParser().
        getTargetOptions().MCNoDeprecatedWarn &&
        MII.getDeprecatedInfo(Inst, getSTI(), Info)) {
      SMLoc Loc = ((PPCOperand&)*Operands[0]).getStartLoc();
      getParser().Warning(Loc, Info, None);
    }
    if (!checkAsmTiedOperandConstraints(*this, it->ConvertFn, Operands, ErrorInfo))
      return Match_InvalidTiedOperand;

    DEBUG_WITH_TYPE(
        "asm-matcher",
        dbgs() << "Opcode result: complete match, selecting this opcode\n");
    return Match_Success;
  }

  // Okay, we had no match.  Try to return a useful error code.
  if (HadMatchOtherThanPredicate || !HadMatchOtherThanFeatures)
    return RetCode;

  ErrorInfo = 0;
  return Match_MissingFeature;
}

#endif // GET_MATCHER_IMPLEMENTATION


#ifdef GET_MNEMONIC_SPELL_CHECKER
#undef GET_MNEMONIC_SPELL_CHECKER

static std::string PPCMnemonicSpellCheck(StringRef S, const FeatureBitset &FBS, unsigned VariantID) {
  const unsigned MaxEditDist = 2;
  std::vector<StringRef> Candidates;
  StringRef Prev = "";

  // Find the appropriate table for this asm variant.
  const MatchEntry *Start, *End;
  switch (VariantID) {
  default: llvm_unreachable("invalid variant!");
  case 0: Start = std::begin(MatchTable0); End = std::end(MatchTable0); break;
  }

  for (auto I = Start; I < End; I++) {
    // Ignore unsupported instructions.
    const FeatureBitset &RequiredFeatures = FeatureBitsets[I->RequiredFeaturesIdx];
    if ((FBS & RequiredFeatures) != RequiredFeatures)
      continue;

    StringRef T = I->getMnemonic();
    // Avoid recomputing the edit distance for the same string.
    if (T.equals(Prev))
      continue;

    Prev = T;
    unsigned Dist = S.edit_distance(T, false, MaxEditDist);
    if (Dist <= MaxEditDist)
      Candidates.push_back(T);
  }

  if (Candidates.empty())
    return "";

  std::string Res = ", did you mean: ";
  unsigned i = 0;
  for( ; i < Candidates.size() - 1; i++)
    Res += Candidates[i].str() + ", ";
  return Res + Candidates[i].str() + "?";
}

#endif // GET_MNEMONIC_SPELL_CHECKER

