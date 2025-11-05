/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Subtarget Enumeration Source Fragment                                      *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_SUBTARGETINFO_ENUM
#undef GET_SUBTARGETINFO_ENUM

namespace llvm {
namespace PPC {
enum {
  DeprecatedDST = 0,
  Directive32 = 1,
  Directive64 = 2,
  Directive440 = 3,
  Directive601 = 4,
  Directive602 = 5,
  Directive603 = 6,
  Directive604 = 7,
  Directive620 = 8,
  Directive750 = 9,
  Directive970 = 10,
  Directive7400 = 11,
  DirectiveA2 = 12,
  DirectiveE200Z0 = 13,
  DirectiveE200Z3 = 14,
  DirectiveE200Z4 = 15,
  DirectiveE200Z6 = 16,
  DirectiveE200Z7 = 17,
  DirectiveE500 = 18,
  DirectiveE500mc = 19,
  DirectiveE5500 = 20,
  DirectivePwr3 = 21,
  DirectivePwr4 = 22,
  DirectivePwr5 = 23,
  DirectivePwr5x = 24,
  DirectivePwr6 = 25,
  DirectivePwr6x = 26,
  DirectivePwr7 = 27,
  DirectivePwr8 = 28,
  DirectivePwr9 = 29,
  DirectivePwr10 = 30,
  DirectivePwrFuture = 31,
  Feature64Bit = 32,
  Feature64BitRegs = 33,
  FeatureAddiLoadFusion = 34,
  FeatureAddisLoadFusion = 35,
  FeatureAltivec = 36,
  FeatureBPERMD = 37,
  FeatureBookE = 38,
  FeatureCMPB = 39,
  FeatureCRBits = 40,
  FeatureDirectMove = 41,
  FeatureE200 = 42,
  FeatureE500 = 43,
  FeatureExtDiv = 44,
  FeatureFCPSGN = 45,
  FeatureFPCVT = 46,
  FeatureFPRND = 47,
  FeatureFPU = 48,
  FeatureFRE = 49,
  FeatureFRES = 50,
  FeatureFRSQRTE = 51,
  FeatureFRSQRTES = 52,
  FeatureFSqrt = 53,
  FeatureFloat128 = 54,
  FeatureFusion = 55,
  FeatureHTM = 56,
  FeatureHardFloat = 57,
  FeatureICBT = 58,
  FeatureISA3_0 = 59,
  FeatureISA3_1 = 60,
  FeatureISEL = 61,
  FeatureInvariantFunctionDescriptors = 62,
  FeatureLDBRX = 63,
  FeatureLFIWAX = 64,
  FeatureLongCall = 65,
  FeatureMFOCRF = 66,
  FeatureMFTB = 67,
  FeatureMSYNC = 68,
  FeatureP8Altivec = 69,
  FeatureP8Crypto = 70,
  FeatureP8Vector = 71,
  FeatureP9Altivec = 72,
  FeatureP9Vector = 73,
  FeaturePCRelativeMemops = 74,
  FeaturePOPCNTD = 75,
  FeaturePPC4xx = 76,
  FeaturePPC6xx = 77,
  FeaturePPCPostRASched = 78,
  FeaturePPCPreRASched = 79,
  FeaturePartwordAtomic = 80,
  FeaturePredictableSelectIsExpensive = 81,
  FeaturePrefixInstrs = 82,
  FeatureQPX = 83,
  FeatureRecipPrec = 84,
  FeatureSPE = 85,
  FeatureSTFIWX = 86,
  FeatureSecurePlt = 87,
  FeatureSlowPOPCNTD = 88,
  FeatureTwoConstNR = 89,
  FeatureUnalignedFloats = 90,
  FeatureVLE = 91,
  FeatureVSX = 92,
  FeatureVectorsUseTwoUnits = 93,
  NumSubtargetFeatures = 94
};
} // end namespace PPC
} // end namespace llvm

#endif // GET_SUBTARGETINFO_ENUM


#ifdef GET_SUBTARGETINFO_MC_DESC
#undef GET_SUBTARGETINFO_MC_DESC

namespace llvm {
// Sorted (by key) array of values for CPU features.
extern const llvm::SubtargetFeatureKV PPCFeatureKV[] = {
  { "64bit", "Enable 64-bit instructions", PPC::Feature64Bit, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "64bitregs", "Enable 64-bit registers usage for ppc32 [beta]", PPC::Feature64BitRegs, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "allow-unaligned-fp-access", "CPU does not trap on unaligned FP access", PPC::FeatureUnalignedFloats, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "altivec", "Enable Altivec instructions", PPC::FeatureAltivec, { { { 0x1000000000000ULL, 0x0ULL, 0x0ULL, } } } },
  { "booke", "Enable Book E instructions", PPC::FeatureBookE, { { { 0x400000000000000ULL, 0x0ULL, 0x0ULL, } } } },
  { "bpermd", "Enable the bpermd instruction", PPC::FeatureBPERMD, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "cmpb", "Enable the cmpb instruction", PPC::FeatureCMPB, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "crbits", "Use condition-register bits individually", PPC::FeatureCRBits, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "crypto", "Enable POWER8 Crypto instructions", PPC::FeatureP8Crypto, { { { 0x0ULL, 0x20ULL, 0x0ULL, } } } },
  { "direct-move", "Enable Power8 direct move instructions", PPC::FeatureDirectMove, { { { 0x0ULL, 0x10000000ULL, 0x0ULL, } } } },
  { "e200", "Enable e200 instructions", PPC::FeatureE200, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "e500", "Enable E500/E500mc instructions", PPC::FeatureE500, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "extdiv", "Enable extended divide instructions", PPC::FeatureExtDiv, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "fcpsgn", "Enable the fcpsgn instruction", PPC::FeatureFCPSGN, { { { 0x1000000000000ULL, 0x0ULL, 0x0ULL, } } } },
  { "float128", "Enable the __float128 data type for IEEE-754R Binary128.", PPC::FeatureFloat128, { { { 0x0ULL, 0x10000000ULL, 0x0ULL, } } } },
  { "fpcvt", "Enable fc[ft]* (unsigned and single-precision) and lfiwzx instructions", PPC::FeatureFPCVT, { { { 0x1000000000000ULL, 0x0ULL, 0x0ULL, } } } },
  { "fprnd", "Enable the fri[mnpz] instructions", PPC::FeatureFPRND, { { { 0x1000000000000ULL, 0x0ULL, 0x0ULL, } } } },
  { "fpu", "Enable classic FPU instructions", PPC::FeatureFPU, { { { 0x200000000000000ULL, 0x0ULL, 0x0ULL, } } } },
  { "fre", "Enable the fre instruction", PPC::FeatureFRE, { { { 0x1000000000000ULL, 0x0ULL, 0x0ULL, } } } },
  { "fres", "Enable the fres instruction", PPC::FeatureFRES, { { { 0x1000000000000ULL, 0x0ULL, 0x0ULL, } } } },
  { "frsqrte", "Enable the frsqrte instruction", PPC::FeatureFRSQRTE, { { { 0x1000000000000ULL, 0x0ULL, 0x0ULL, } } } },
  { "frsqrtes", "Enable the frsqrtes instruction", PPC::FeatureFRSQRTES, { { { 0x1000000000000ULL, 0x0ULL, 0x0ULL, } } } },
  { "fsqrt", "Enable the fsqrt instruction", PPC::FeatureFSqrt, { { { 0x1000000000000ULL, 0x0ULL, 0x0ULL, } } } },
  { "fuse-addi-load", "Power8 Addi-Load fusion", PPC::FeatureAddiLoadFusion, { { { 0x80000000000000ULL, 0x0ULL, 0x0ULL, } } } },
  { "fuse-addis-load", "Power8 Addis-Load fusion", PPC::FeatureAddisLoadFusion, { { { 0x80000000000000ULL, 0x0ULL, 0x0ULL, } } } },
  { "fusion", "Target supports instruction fusion", PPC::FeatureFusion, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "hard-float", "Enable floating-point instructions", PPC::FeatureHardFloat, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "htm", "Enable Hardware Transactional Memory instructions", PPC::FeatureHTM, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "icbt", "Enable icbt instruction", PPC::FeatureICBT, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "invariant-function-descriptors", "Assume function descriptors are invariant", PPC::FeatureInvariantFunctionDescriptors, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "isa-v30-instructions", "Enable instructions added in ISA 3.0.", PPC::FeatureISA3_0, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "isa-v31-instructions", "Enable instructions added in ISA 3.1.", PPC::FeatureISA3_1, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "isel", "Enable the isel instruction", PPC::FeatureISEL, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "ldbrx", "Enable the ldbrx instruction", PPC::FeatureLDBRX, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "lfiwax", "Enable the lfiwax instruction", PPC::FeatureLFIWAX, { { { 0x1000000000000ULL, 0x0ULL, 0x0ULL, } } } },
  { "longcall", "Always use indirect calls", PPC::FeatureLongCall, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "mfocrf", "Enable the MFOCRF instruction", PPC::FeatureMFOCRF, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "msync", "Has only the msync instruction instead of sync", PPC::FeatureMSYNC, { { { 0x4000000000ULL, 0x0ULL, 0x0ULL, } } } },
  { "partword-atomics", "Enable l[bh]arx and st[bh]cx.", PPC::FeaturePartwordAtomic, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "pcrelative-memops", "Enable PC relative Memory Ops", PPC::FeaturePCRelativeMemops, { { { 0x800000000000000ULL, 0x0ULL, 0x0ULL, } } } },
  { "popcntd", "Enable the popcnt[dw] instructions", PPC::FeaturePOPCNTD, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "power8-altivec", "Enable POWER8 Altivec instructions", PPC::FeatureP8Altivec, { { { 0x1000000000ULL, 0x0ULL, 0x0ULL, } } } },
  { "power8-vector", "Enable POWER8 vector instructions", PPC::FeatureP8Vector, { { { 0x0ULL, 0x10000020ULL, 0x0ULL, } } } },
  { "power9-altivec", "Enable POWER9 Altivec instructions", PPC::FeatureP9Altivec, { { { 0x800000000000000ULL, 0x20ULL, 0x0ULL, } } } },
  { "power9-vector", "Enable POWER9 vector instructions", PPC::FeatureP9Vector, { { { 0x800000000000000ULL, 0x180ULL, 0x0ULL, } } } },
  { "ppc-postra-sched", "Use PowerPC post-RA scheduling strategy", PPC::FeaturePPCPostRASched, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "ppc-prera-sched", "Use PowerPC pre-RA scheduling strategy", PPC::FeaturePPCPreRASched, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "ppc4xx", "Enable PPC 4xx instructions", PPC::FeaturePPC4xx, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "ppc6xx", "Enable PPC 6xx instructions", PPC::FeaturePPC6xx, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "predictable-select-expensive", "Prefer likely predicted branches over selects", PPC::FeaturePredictableSelectIsExpensive, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "prefix-instrs", "Enable prefixed instructions", PPC::FeaturePrefixInstrs, { { { 0x800000000000000ULL, 0x180ULL, 0x0ULL, } } } },
  { "qpx", "Enable QPX instructions", PPC::FeatureQPX, { { { 0x1000000000000ULL, 0x0ULL, 0x0ULL, } } } },
  { "recipprec", "Assume higher precision reciprocal estimates", PPC::FeatureRecipPrec, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "secure-plt", "Enable secure plt mode", PPC::FeatureSecurePlt, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "slow-popcntd", "Has slow popcnt[dw] instructions", PPC::FeatureSlowPOPCNTD, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "spe", "Enable SPE instructions", PPC::FeatureSPE, { { { 0x200000000000000ULL, 0x0ULL, 0x0ULL, } } } },
  { "stfiwx", "Enable the stfiwx instruction", PPC::FeatureSTFIWX, { { { 0x1000000000000ULL, 0x0ULL, 0x0ULL, } } } },
  { "two-const-nr", "Requires two constant Newton-Raphson computation", PPC::FeatureTwoConstNR, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "vectors-use-two-units", "Vectors use two units", PPC::FeatureVectorsUseTwoUnits, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "vle", "Enable VLE (Variable Length Encoding) instructions", PPC::FeatureVLE, { { { 0x0ULL, 0x0ULL, 0x0ULL, } } } },
  { "vsx", "Enable VSX instructions", PPC::FeatureVSX, { { { 0x1000000000ULL, 0x0ULL, 0x0ULL, } } } },
};

#ifdef DBGFIELD
#error "<target>GenSubtargetInfo.inc requires a DBGFIELD macro"
#endif
#if !defined(NDEBUG) || defined(LLVM_ENABLE_DUMP)
#define DBGFIELD(x) x,
#else
#define DBGFIELD(x)
#endif

// Functional units for "PPC440Itineraries"
namespace PPC440ItinerariesFU {
  const InstrStage::FuncUnits P440_DISS1 = 1ULL << 0;
  const InstrStage::FuncUnits P440_DISS2 = 1ULL << 1;
  const InstrStage::FuncUnits P440_FRACC = 1ULL << 2;
  const InstrStage::FuncUnits P440_IRACC = 1ULL << 3;
  const InstrStage::FuncUnits P440_IEXE1 = 1ULL << 4;
  const InstrStage::FuncUnits P440_IEXE2 = 1ULL << 5;
  const InstrStage::FuncUnits P440_IWB = 1ULL << 6;
  const InstrStage::FuncUnits P440_LRACC = 1ULL << 7;
  const InstrStage::FuncUnits P440_JEXE1 = 1ULL << 8;
  const InstrStage::FuncUnits P440_JEXE2 = 1ULL << 9;
  const InstrStage::FuncUnits P440_JWB = 1ULL << 10;
  const InstrStage::FuncUnits P440_AGEN = 1ULL << 11;
  const InstrStage::FuncUnits P440_CRD = 1ULL << 12;
  const InstrStage::FuncUnits P440_LWB = 1ULL << 13;
  const InstrStage::FuncUnits P440_FEXE1 = 1ULL << 14;
  const InstrStage::FuncUnits P440_FEXE2 = 1ULL << 15;
  const InstrStage::FuncUnits P440_FEXE3 = 1ULL << 16;
  const InstrStage::FuncUnits P440_FEXE4 = 1ULL << 17;
  const InstrStage::FuncUnits P440_FEXE5 = 1ULL << 18;
  const InstrStage::FuncUnits P440_FEXE6 = 1ULL << 19;
  const InstrStage::FuncUnits P440_FWB = 1ULL << 20;
  const InstrStage::FuncUnits P440_LWARX_Hold = 1ULL << 21;
} // end namespace PPC440ItinerariesFU

// Pipeline forwarding paths for itineraries "PPC440Itineraries"
namespace PPC440ItinerariesBypass {
  const unsigned NoBypass = 0;
  const unsigned P440_GPR_Bypass = 1 << 0;
  const unsigned P440_FPR_Bypass = 1 << 1;
} // end namespace PPC440ItinerariesBypass

// Functional units for "G3Itineraries"
namespace G3ItinerariesFU {
  const InstrStage::FuncUnits G3_IU1 = 1ULL << 0;
  const InstrStage::FuncUnits G3_IU2 = 1ULL << 1;
  const InstrStage::FuncUnits G3_FPU1 = 1ULL << 2;
  const InstrStage::FuncUnits G3_BPU = 1ULL << 3;
  const InstrStage::FuncUnits G3_SRU = 1ULL << 4;
  const InstrStage::FuncUnits G3_SLU = 1ULL << 5;
} // end namespace G3ItinerariesFU

// Functional units for "G4Itineraries"
namespace G4ItinerariesFU {
  const InstrStage::FuncUnits G4_IU1 = 1ULL << 0;
  const InstrStage::FuncUnits G4_IU2 = 1ULL << 1;
  const InstrStage::FuncUnits G4_SLU = 1ULL << 2;
  const InstrStage::FuncUnits G4_SRU = 1ULL << 3;
  const InstrStage::FuncUnits G4_BPU = 1ULL << 4;
  const InstrStage::FuncUnits G4_FPU1 = 1ULL << 5;
  const InstrStage::FuncUnits G4_VIU1 = 1ULL << 6;
  const InstrStage::FuncUnits G4_VIU2 = 1ULL << 7;
  const InstrStage::FuncUnits G4_VPU = 1ULL << 8;
  const InstrStage::FuncUnits G4_VFPU = 1ULL << 9;
} // end namespace G4ItinerariesFU

// Functional units for "G4PlusItineraries"
namespace G4PlusItinerariesFU {
  const InstrStage::FuncUnits G4P_IU1 = 1ULL << 0;
  const InstrStage::FuncUnits G4P_IU2 = 1ULL << 1;
  const InstrStage::FuncUnits G4P_IU3 = 1ULL << 2;
  const InstrStage::FuncUnits G4P_IU4 = 1ULL << 3;
  const InstrStage::FuncUnits G4P_BPU = 1ULL << 4;
  const InstrStage::FuncUnits G4P_SLU = 1ULL << 5;
  const InstrStage::FuncUnits G4P_FPU1 = 1ULL << 6;
  const InstrStage::FuncUnits G4P_VFPU = 1ULL << 7;
  const InstrStage::FuncUnits G4P_VIU1 = 1ULL << 8;
  const InstrStage::FuncUnits G4P_VIU2 = 1ULL << 9;
  const InstrStage::FuncUnits G4P_VPU = 1ULL << 10;
} // end namespace G4PlusItinerariesFU

// Functional units for "G5Itineraries"
namespace G5ItinerariesFU {
  const InstrStage::FuncUnits G5_IU1 = 1ULL << 0;
  const InstrStage::FuncUnits G5_IU2 = 1ULL << 1;
  const InstrStage::FuncUnits G5_SLU = 1ULL << 2;
  const InstrStage::FuncUnits G5_BPU = 1ULL << 3;
  const InstrStage::FuncUnits G5_FPU1 = 1ULL << 4;
  const InstrStage::FuncUnits G5_FPU2 = 1ULL << 5;
  const InstrStage::FuncUnits G5_VFPU = 1ULL << 6;
  const InstrStage::FuncUnits G5_VIU1 = 1ULL << 7;
  const InstrStage::FuncUnits G5_VIU2 = 1ULL << 8;
  const InstrStage::FuncUnits G5_VPU = 1ULL << 9;
} // end namespace G5ItinerariesFU

// Functional units for "PPCA2Itineraries"
namespace PPCA2ItinerariesFU {
  const InstrStage::FuncUnits A2_XU = 1ULL << 0;
  const InstrStage::FuncUnits A2_FU = 1ULL << 1;
} // end namespace PPCA2ItinerariesFU

// Functional units for "PPCE200Z0Itineraries"
namespace PPCE200Z0ItinerariesFU {
  const InstrStage::FuncUnits E200Z0_FETCH = 1ULL << 0;
  const InstrStage::FuncUnits E200Z0_DECODE = 1ULL << 1;
  const InstrStage::FuncUnits E200Z0_EX = 1ULL << 2;
  const InstrStage::FuncUnits E200Z0_WB = 1ULL << 3;
  const InstrStage::FuncUnits E200Z0_ALU = 1ULL << 4;
  const InstrStage::FuncUnits E200Z0_BU = 1ULL << 5;
  const InstrStage::FuncUnits E200Z0_LSU = 1ULL << 6;
  const InstrStage::FuncUnits E200Z0_MUL = 1ULL << 7;
} // end namespace PPCE200Z0ItinerariesFU

// Pipeline forwarding paths for itineraries "PPCE200Z0Itineraries"
namespace PPCE200Z0ItinerariesBypass {
  const unsigned NoBypass = 0;
  const unsigned E200Z0_CR_Bypass = 1 << 0;
  const unsigned E200Z0_GPR_Bypass = 1 << 1;
} // end namespace PPCE200Z0ItinerariesBypass

// Functional units for "PPCE200Z3Itineraries"
namespace PPCE200Z3ItinerariesFU {
  const InstrStage::FuncUnits E200Z3_DIS = 1ULL << 0;
  const InstrStage::FuncUnits E200Z3_SU = 1ULL << 1;
  const InstrStage::FuncUnits E200Z3_BU = 1ULL << 2;
  const InstrStage::FuncUnits E200Z3_MU = 1ULL << 3;
  const InstrStage::FuncUnits E200Z3_LSU = 1ULL << 4;
} // end namespace PPCE200Z3ItinerariesFU

// Pipeline forwarding paths for itineraries "PPCE200Z3Itineraries"
namespace PPCE200Z3ItinerariesBypass {
  const unsigned NoBypass = 0;
  const unsigned E200Z3_CR_Bypass = 1 << 0;
  const unsigned E200Z3_GPR_Bypass = 1 << 1;
  const unsigned E200Z3_DivBypass = 1 << 2;
} // end namespace PPCE200Z3ItinerariesBypass

// Functional units for "PPCE200Z4Itineraries"
namespace PPCE200Z4ItinerariesFU {
  const InstrStage::FuncUnits E200Z4_FETCH = 1ULL << 0;
  const InstrStage::FuncUnits E200Z4_DECODE = 1ULL << 1;
  const InstrStage::FuncUnits E200Z4_EX = 1ULL << 2;
  const InstrStage::FuncUnits E200Z4_MEM = 1ULL << 3;
  const InstrStage::FuncUnits E200Z4_WB = 1ULL << 4;
  const InstrStage::FuncUnits E200Z4_DIS0 = 1ULL << 5;
  const InstrStage::FuncUnits E200Z4_DIS1 = 1ULL << 6;
  const InstrStage::FuncUnits E200Z4_SU0 = 1ULL << 7;
  const InstrStage::FuncUnits E200Z4_SU1 = 1ULL << 8;
  const InstrStage::FuncUnits E200Z4_ALU = 1ULL << 9;
  const InstrStage::FuncUnits E200Z4_BU = 1ULL << 10;
  const InstrStage::FuncUnits E200Z4_LSU = 1ULL << 11;
  const InstrStage::FuncUnits E200Z4_MUL = 1ULL << 12;
  const InstrStage::FuncUnits E200Z4_FPU = 1ULL << 13;
  const InstrStage::FuncUnits E200Z4_SPE = 1ULL << 14;
  const InstrStage::FuncUnits E200Z4_ICache = 1ULL << 15;
} // end namespace PPCE200Z4ItinerariesFU

// Pipeline forwarding paths for itineraries "PPCE200Z4Itineraries"
namespace PPCE200Z4ItinerariesBypass {
  const unsigned NoBypass = 0;
  const unsigned E200Z4_CR_Bypass = 1 << 0;
  const unsigned E200Z4_GPR_Bypass = 1 << 1;
  const unsigned E200Z4_SPE_Bypass = 1 << 2;
} // end namespace PPCE200Z4ItinerariesBypass

// Functional units for "PPCE200Z6Itineraries"
namespace PPCE200Z6ItinerariesFU {
  const InstrStage::FuncUnits E200Z6_FETCH = 1ULL << 0;
  const InstrStage::FuncUnits E200Z6_DECODE = 1ULL << 1;
  const InstrStage::FuncUnits E200Z6_EX = 1ULL << 2;
  const InstrStage::FuncUnits E200Z6_MEM = 1ULL << 3;
  const InstrStage::FuncUnits E200Z6_WB = 1ULL << 4;
  const InstrStage::FuncUnits E200Z6_ALU = 1ULL << 5;
  const InstrStage::FuncUnits E200Z6_BU = 1ULL << 6;
  const InstrStage::FuncUnits E200Z6_LSU = 1ULL << 7;
  const InstrStage::FuncUnits E200Z6_MUL = 1ULL << 8;
  const InstrStage::FuncUnits E200Z6_FPU = 1ULL << 9;
} // end namespace PPCE200Z6ItinerariesFU

// Pipeline forwarding paths for itineraries "PPCE200Z6Itineraries"
namespace PPCE200Z6ItinerariesBypass {
  const unsigned NoBypass = 0;
  const unsigned E200Z6_CR_Bypass = 1 << 0;
  const unsigned E200Z6_GPR_Bypass = 1 << 1;
  const unsigned E200Z6_FPR_Bypass = 1 << 2;
} // end namespace PPCE200Z6ItinerariesBypass

// Functional units for "PPCE200Z7Itineraries"
namespace PPCE200Z7ItinerariesFU {
  const InstrStage::FuncUnits E200Z7_FETCH = 1ULL << 0;
  const InstrStage::FuncUnits E200Z7_DIS0 = 1ULL << 1;
  const InstrStage::FuncUnits E200Z7_DIS1 = 1ULL << 2;
  const InstrStage::FuncUnits E200Z7_ALU0 = 1ULL << 3;
  const InstrStage::FuncUnits E200Z7_ALU1 = 1ULL << 4;
  const InstrStage::FuncUnits E200Z7_BU = 1ULL << 5;
  const InstrStage::FuncUnits E200Z7_SPE = 1ULL << 6;
  const InstrStage::FuncUnits E200Z7_LSU = 1ULL << 7;
  const InstrStage::FuncUnits E200Z7_MUL = 1ULL << 8;
} // end namespace PPCE200Z7ItinerariesFU

// Pipeline forwarding paths for itineraries "PPCE200Z7Itineraries"
namespace PPCE200Z7ItinerariesBypass {
  const unsigned NoBypass = 0;
  const unsigned E200Z7_CR_Bypass = 1 << 0;
  const unsigned E200Z7_GPR_Bypass = 1 << 1;
  const unsigned E200Z7_SPE_Bypass = 1 << 2;
  const unsigned E200Z7_FPR_Bypass = 1 << 3;
} // end namespace PPCE200Z7ItinerariesBypass

// Functional units for "PPCE500Itineraries"
namespace PPCE500ItinerariesFU {
  const InstrStage::FuncUnits E500_DIS0 = 1ULL << 0;
  const InstrStage::FuncUnits E500_DIS1 = 1ULL << 1;
  const InstrStage::FuncUnits E500_SU0 = 1ULL << 2;
  const InstrStage::FuncUnits E500_SU1 = 1ULL << 3;
  const InstrStage::FuncUnits E500_BU = 1ULL << 4;
  const InstrStage::FuncUnits E500_MU = 1ULL << 5;
  const InstrStage::FuncUnits E500_LSU_0 = 1ULL << 6;
} // end namespace PPCE500ItinerariesFU

// Pipeline forwarding paths for itineraries "PPCE500Itineraries"
namespace PPCE500ItinerariesBypass {
  const unsigned NoBypass = 0;
  const unsigned E500_CR_Bypass = 1 << 0;
  const unsigned E500_GPR_Bypass = 1 << 1;
  const unsigned E500_DivBypass = 1 << 2;
} // end namespace PPCE500ItinerariesBypass

// Functional units for "PPCE500mcItineraries"
namespace PPCE500mcItinerariesFU {
  const InstrStage::FuncUnits E500mc_DIS0 = 1ULL << 0;
  const InstrStage::FuncUnits E500mc_DIS1 = 1ULL << 1;
  const InstrStage::FuncUnits E500mc_SFX0 = 1ULL << 2;
  const InstrStage::FuncUnits E500mc_SFX1 = 1ULL << 3;
  const InstrStage::FuncUnits E500mc_BU = 1ULL << 4;
  const InstrStage::FuncUnits E500mc_CFX_DivBypass = 1ULL << 5;
  const InstrStage::FuncUnits E500mc_CFX_0 = 1ULL << 6;
  const InstrStage::FuncUnits E500mc_LSU_0 = 1ULL << 7;
  const InstrStage::FuncUnits E500mc_FPU_0 = 1ULL << 8;
} // end namespace PPCE500mcItinerariesFU

// Pipeline forwarding paths for itineraries "PPCE500mcItineraries"
namespace PPCE500mcItinerariesBypass {
  const unsigned NoBypass = 0;
  const unsigned E500mc_CR_Bypass = 1 << 0;
  const unsigned E500mc_GPR_Bypass = 1 << 1;
  const unsigned E500mc_FPR_Bypass = 1 << 2;
} // end namespace PPCE500mcItinerariesBypass

// Functional units for "PPCE5500Itineraries"
namespace PPCE5500ItinerariesFU {
  const InstrStage::FuncUnits E5500_DIS0 = 1ULL << 0;
  const InstrStage::FuncUnits E5500_DIS1 = 1ULL << 1;
  const InstrStage::FuncUnits E5500_SFX0 = 1ULL << 2;
  const InstrStage::FuncUnits E5500_SFX1 = 1ULL << 3;
  const InstrStage::FuncUnits E5500_BU = 1ULL << 4;
  const InstrStage::FuncUnits E5500_CFX_DivBypass = 1ULL << 5;
  const InstrStage::FuncUnits E5500_CFX_0 = 1ULL << 6;
  const InstrStage::FuncUnits E5500_CFX_1 = 1ULL << 7;
  const InstrStage::FuncUnits E5500_LSU_0 = 1ULL << 8;
  const InstrStage::FuncUnits E5500_FPU_0 = 1ULL << 9;
} // end namespace PPCE5500ItinerariesFU

// Pipeline forwarding paths for itineraries "PPCE5500Itineraries"
namespace PPCE5500ItinerariesBypass {
  const unsigned NoBypass = 0;
  const unsigned E5500_CR_Bypass = 1 << 0;
  const unsigned E5500_GPR_Bypass = 1 << 1;
  const unsigned E5500_FPR_Bypass = 1 << 2;
} // end namespace PPCE5500ItinerariesBypass

// Functional units for "P8Itineraries"
namespace P8ItinerariesFU {
  const InstrStage::FuncUnits P8_DU1 = 1ULL << 0;
  const InstrStage::FuncUnits P8_DU2 = 1ULL << 1;
  const InstrStage::FuncUnits P8_DU3 = 1ULL << 2;
  const InstrStage::FuncUnits P8_DU4 = 1ULL << 3;
  const InstrStage::FuncUnits P8_DU5 = 1ULL << 4;
  const InstrStage::FuncUnits P8_DU6 = 1ULL << 5;
  const InstrStage::FuncUnits P8_DU7 = 1ULL << 6;
  const InstrStage::FuncUnits P8_DU8 = 1ULL << 7;
  const InstrStage::FuncUnits P8_LU1 = 1ULL << 8;
  const InstrStage::FuncUnits P8_LU2 = 1ULL << 9;
  const InstrStage::FuncUnits P8_LSU1 = 1ULL << 10;
  const InstrStage::FuncUnits P8_LSU2 = 1ULL << 11;
  const InstrStage::FuncUnits P8_FXU1 = 1ULL << 12;
  const InstrStage::FuncUnits P8_FXU2 = 1ULL << 13;
  const InstrStage::FuncUnits P8_FPU1 = 1ULL << 14;
  const InstrStage::FuncUnits P8_FPU2 = 1ULL << 15;
  const InstrStage::FuncUnits P8_CRU = 1ULL << 16;
  const InstrStage::FuncUnits P8_BRU = 1ULL << 17;
} // end namespace P8ItinerariesFU

// Functional units for "P7Itineraries"
namespace P7ItinerariesFU {
  const InstrStage::FuncUnits P7_DU1 = 1ULL << 0;
  const InstrStage::FuncUnits P7_DU2 = 1ULL << 1;
  const InstrStage::FuncUnits P7_DU3 = 1ULL << 2;
  const InstrStage::FuncUnits P7_DU4 = 1ULL << 3;
  const InstrStage::FuncUnits P7_DU5 = 1ULL << 4;
  const InstrStage::FuncUnits P7_DU6 = 1ULL << 5;
  const InstrStage::FuncUnits P7_LS1 = 1ULL << 6;
  const InstrStage::FuncUnits P7_LS2 = 1ULL << 7;
  const InstrStage::FuncUnits P7_FX1 = 1ULL << 8;
  const InstrStage::FuncUnits P7_FX2 = 1ULL << 9;
  const InstrStage::FuncUnits P7_VS1 = 1ULL << 10;
  const InstrStage::FuncUnits P7_VS2 = 1ULL << 11;
  const InstrStage::FuncUnits P7_CRU = 1ULL << 12;
  const InstrStage::FuncUnits P7_BRU = 1ULL << 13;
} // end namespace P7ItinerariesFU

extern const llvm::InstrStage PPCStages[] = {
  { 0, 0, 0, llvm::InstrStage::Required }, // No itinerary
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_LRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 3, PPC440ItinerariesFU::P440_AGEN, 1, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPC440ItinerariesFU::P440_CRD, 1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_LWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 1-5
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IRACC | PPC440ItinerariesFU::P440_LRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IEXE1 | PPC440ItinerariesFU::P440_JEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IEXE2 | PPC440ItinerariesFU::P440_JEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IWB | PPC440ItinerariesFU::P440_JWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 6-10
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 11-15
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_LRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_AGEN, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_CRD, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_LWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 16-20
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_LRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_AGEN, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_CRD, -1, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPC440ItinerariesFU::P440_LWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 21-25
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 33, PPC440ItinerariesFU::P440_IWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 26-30
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE3, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE4, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE5, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE6, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 31-39
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE3, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE4, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE5, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE6, -1, (llvm::InstrStage::ReservationKinds)0 },   { 25, PPC440ItinerariesFU::P440_FWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 40-48
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE3, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE4, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE5, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE6, -1, (llvm::InstrStage::ReservationKinds)0 },   { 13, PPC440ItinerariesFU::P440_FWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 49-57
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FRACC, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_LRACC, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_AGEN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_JEXE1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_CRD, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_JEXE2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 6, PPC440ItinerariesFU::P440_FEXE3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 6, PPC440ItinerariesFU::P440_LWB, 0, (llvm::InstrStage::ReservationKinds)0 },   { 6, PPC440ItinerariesFU::P440_JWB, 0, (llvm::InstrStage::ReservationKinds)0 },   { 6, PPC440ItinerariesFU::P440_IWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 58-73
  { 1, PPC440ItinerariesFU::P440_DISS1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IRACC, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPC440ItinerariesFU::P440_LWARX_Hold, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_LRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_AGEN, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_CRD, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_LWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 74-80
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 3, PPC440ItinerariesFU::P440_IWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 81-85
  { 3, G3ItinerariesFU::G3_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 86
  { 1, G3ItinerariesFU::G3_IU1 | G3ItinerariesFU::G3_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 87
  { 1, G3ItinerariesFU::G3_BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 88
  { 1, G3ItinerariesFU::G3_SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 89
  { 2, G3ItinerariesFU::G3_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 90
  { 19, G3ItinerariesFU::G3_IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 91
  { 1, G3ItinerariesFU::G3_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 92
  { 31, G3ItinerariesFU::G3_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 93
  { 17, G3ItinerariesFU::G3_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 94
  { 2, G3ItinerariesFU::G3_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 95
  { 2, G3ItinerariesFU::G3_SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 96
  { 34, G3ItinerariesFU::G3_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 97
  { 3, G3ItinerariesFU::G3_SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 98
  { 3, G3ItinerariesFU::G3_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 99
  { 5, G3ItinerariesFU::G3_IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 100
  { 6, G3ItinerariesFU::G3_IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 101
  { 3, G3ItinerariesFU::G3_IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 102
  { 8, G3ItinerariesFU::G3_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 103
  { 2, G3ItinerariesFU::G3_IU1 | G3ItinerariesFU::G3_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 104
  { 8, G4ItinerariesFU::G4_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 105
  { 1, G4ItinerariesFU::G4_IU1 | G4ItinerariesFU::G4_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 106
  { 1, G4ItinerariesFU::G4_BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 107
  { 4, G4ItinerariesFU::G4_VFPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 108
  { 1, G4ItinerariesFU::G4_SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 109
  { 2, G4ItinerariesFU::G4_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 110
  { 19, G4ItinerariesFU::G4_IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 111
  { 1, G4ItinerariesFU::G4_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 112
  { 31, G4ItinerariesFU::G4_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 113
  { 1, G4ItinerariesFU::G4_VIU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 114
  { 3, G4ItinerariesFU::G4_VIU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 115
  { 17, G4ItinerariesFU::G4_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 116
  { 2, G4ItinerariesFU::G4_SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 117
  { 3, G4ItinerariesFU::G4_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 118
  { 34, G4ItinerariesFU::G4_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 119
  { 3, G4ItinerariesFU::G4_SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 120
  { 3, G4ItinerariesFU::G4_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 121
  { 5, G4ItinerariesFU::G4_IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 122
  { 6, G4ItinerariesFU::G4_IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 123
  { 3, G4ItinerariesFU::G4_IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 124
  { 1, G4ItinerariesFU::G4_VPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 125
  { 5, G4ItinerariesFU::G4_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 126
  { 8, G4ItinerariesFU::G4_SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 127
  { 2, G4ItinerariesFU::G4_IU1 | G4ItinerariesFU::G4_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 128
  { 35, G4PlusItinerariesFU::G4P_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 129
  { 1, G4PlusItinerariesFU::G4P_IU1 | G4PlusItinerariesFU::G4P_IU2 | G4PlusItinerariesFU::G4P_IU3 | G4PlusItinerariesFU::G4P_IU4, -1, (llvm::InstrStage::ReservationKinds)0 }, // 130
  { 1, G4PlusItinerariesFU::G4P_BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 131
  { 4, G4PlusItinerariesFU::G4P_VFPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 132
  { 2, G4PlusItinerariesFU::G4P_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 133
  { 3, G4PlusItinerariesFU::G4P_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 134
  { 23, G4PlusItinerariesFU::G4P_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 135
  { 5, G4PlusItinerariesFU::G4P_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 136
  { 35, G4PlusItinerariesFU::G4P_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 137
  { 1, G4PlusItinerariesFU::G4P_VIU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 138
  { 4, G4PlusItinerariesFU::G4P_VIU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 139
  { 21, G4PlusItinerariesFU::G4P_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 140
  { 3, G4PlusItinerariesFU::G4P_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 141
  { 0, G4PlusItinerariesFU::G4P_IU1 | G4PlusItinerariesFU::G4P_IU2 | G4PlusItinerariesFU::G4P_IU3 | G4PlusItinerariesFU::G4P_IU4, -1, (llvm::InstrStage::ReservationKinds)0 }, // 142
  { 4, G4PlusItinerariesFU::G4P_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 143
  { 37, G4PlusItinerariesFU::G4P_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 144
  { 4, G4PlusItinerariesFU::G4P_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 145
  { 5, G4PlusItinerariesFU::G4P_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 146
  { 2, G4PlusItinerariesFU::G4P_VPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 147
  { 2, G4PlusItinerariesFU::G4P_IU1 | G4PlusItinerariesFU::G4P_IU2 | G4PlusItinerariesFU::G4P_IU3 | G4PlusItinerariesFU::G4P_IU4, -1, (llvm::InstrStage::ReservationKinds)0 }, // 148
  { 2, G4PlusItinerariesFU::G4P_VFPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 149
  { 35, G5ItinerariesFU::G5_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 150
  { 2, G5ItinerariesFU::G5_IU1 | G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 151
  { 1, G5ItinerariesFU::G5_BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 152
  { 8, G5ItinerariesFU::G5_VFPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 153
  { 3, G5ItinerariesFU::G5_IU1 | G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 154
  { 4, G5ItinerariesFU::G5_BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 155
  { 3, G5ItinerariesFU::G5_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 156
  { 68, G5ItinerariesFU::G5_IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 157
  { 36, G5ItinerariesFU::G5_IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 158
  { 6, G5ItinerariesFU::G5_FPU1 | G5ItinerariesFU::G5_FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 159
  { 33, G5ItinerariesFU::G5_FPU1 | G5ItinerariesFU::G5_FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 160
  { 8, G5ItinerariesFU::G5_FPU1 | G5ItinerariesFU::G5_FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 161
  { 2, G5ItinerariesFU::G5_VIU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 162
  { 5, G5ItinerariesFU::G5_VIU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 163
  { 40, G5ItinerariesFU::G5_FPU1 | G5ItinerariesFU::G5_FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 164
  { 40, G5ItinerariesFU::G5_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 165
  { 11, G5ItinerariesFU::G5_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 166
  { 5, G5ItinerariesFU::G5_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 167
  { 64, G5ItinerariesFU::G5_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 168
  { 7, G5ItinerariesFU::G5_IU1 | G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 169
  { 2, G5ItinerariesFU::G5_BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 170
  { 3, G5ItinerariesFU::G5_BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 171
  { 2, G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 172
  { 3, G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 173
  { 6, G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 174
  { 10, G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 175
  { 8, G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 176
  { 5, G5ItinerariesFU::G5_IU1 | G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 177
  { 4, G5ItinerariesFU::G5_IU1 | G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 178
  { 3, G5ItinerariesFU::G5_VPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 179
  { 4, G5ItinerariesFU::G5_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 180
  { 1, G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 181
  { 1, G5ItinerariesFU::G5_IU1 | G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 182
  { 2, G5ItinerariesFU::G5_VFPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 183
  { 1, PPCA2ItinerariesFU::A2_XU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 184
  { 1, PPCA2ItinerariesFU::A2_FU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 185
  { 1, PPCE200Z0ItinerariesFU::E200Z0_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_EX | PPCE200Z0ItinerariesFU::E200Z0_ALU, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_WB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 186-189
  { 1, PPCE200Z0ItinerariesFU::E200Z0_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_EX | PPCE200Z0ItinerariesFU::E200Z0_BU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 190-192
  { 1, PPCE200Z0ItinerariesFU::E200Z0_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_EX | PPCE200Z0ItinerariesFU::E200Z0_LSU, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_WB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 193-196
  { 1, PPCE200Z0ItinerariesFU::E200Z0_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_EX | PPCE200Z0ItinerariesFU::E200Z0_ALU, 0, (llvm::InstrStage::ReservationKinds)0 },   { 34, PPCE200Z0ItinerariesFU::E200Z0_EX | PPCE200Z0ItinerariesFU::E200Z0_ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 197-200
  { 1, PPCE200Z0ItinerariesFU::E200Z0_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE200Z0ItinerariesFU::E200Z0_EX | PPCE200Z0ItinerariesFU::E200Z0_LSU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 201-203
  { 1, PPCE200Z0ItinerariesFU::E200Z0_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_EX | PPCE200Z0ItinerariesFU::E200Z0_ALU, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_EX | PPCE200Z0ItinerariesFU::E200Z0_LSU, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_WB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 204-208
  { 1, PPCE200Z0ItinerariesFU::E200Z0_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_EX | PPCE200Z0ItinerariesFU::E200Z0_ALU, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE200Z0ItinerariesFU::E200Z0_EX | PPCE200Z0ItinerariesFU::E200Z0_LSU, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_WB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 209-213
  { 1, PPCE200Z0ItinerariesFU::E200Z0_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_EX | PPCE200Z0ItinerariesFU::E200Z0_ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 214-216
  { 1, PPCE200Z0ItinerariesFU::E200Z0_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_EX | PPCE200Z0ItinerariesFU::E200Z0_MUL, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, PPCE200Z0ItinerariesFU::E200Z0_EX | PPCE200Z0ItinerariesFU::E200Z0_MUL, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_WB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 217-221
  { 1, PPCE200Z0ItinerariesFU::E200Z0_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_EX | PPCE200Z0ItinerariesFU::E200Z0_MUL, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, PPCE200Z0ItinerariesFU::E200Z0_EX | PPCE200Z0ItinerariesFU::E200Z0_MUL, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_WB, 0, (llvm::InstrStage::ReservationKinds)0 }, // 222-226
  { 1, PPCE200Z0ItinerariesFU::E200Z0_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_EX | PPCE200Z0ItinerariesFU::E200Z0_ALU, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE200Z0ItinerariesFU::E200Z0_EX | PPCE200Z0ItinerariesFU::E200Z0_LSU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 227-230
  { 1, PPCE200Z0ItinerariesFU::E200Z0_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE200Z0ItinerariesFU::E200Z0_EX | PPCE200Z0ItinerariesFU::E200Z0_ALU, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z0ItinerariesFU::E200Z0_WB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 231-234
  { 1, PPCE200Z3ItinerariesFU::E200Z3_DIS, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z3ItinerariesFU::E200Z3_SU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 235-236
  { 1, PPCE200Z3ItinerariesFU::E200Z3_DIS, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z3ItinerariesFU::E200Z3_BU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 237-238
  { 1, PPCE200Z3ItinerariesFU::E200Z3_DIS, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z3ItinerariesFU::E200Z3_LSU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 239-240
  { 1, PPCE200Z3ItinerariesFU::E200Z3_DIS, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE200Z3ItinerariesFU::E200Z3_LSU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 241-242
  { 1, PPCE200Z3ItinerariesFU::E200Z3_DIS, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z3ItinerariesFU::E200Z3_MU, 0, (llvm::InstrStage::ReservationKinds)0 },   { 14, PPCE200Z3ItinerariesFU::E200Z3_MU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 243-245
  { 1, PPCE200Z3ItinerariesFU::E200Z3_DIS, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, PPCE200Z3ItinerariesFU::E200Z3_LSU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 246-247
  { 1, PPCE200Z3ItinerariesFU::E200Z3_DIS, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPCE200Z3ItinerariesFU::E200Z3_MU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 248-249
  { 1, PPCE200Z3ItinerariesFU::E200Z3_DIS, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE200Z3ItinerariesFU::E200Z3_SU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 250-251
  { 1, PPCE200Z4ItinerariesFU::E200Z4_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_EX | PPCE200Z4ItinerariesFU::E200Z4_ALU, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_MEM, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_WB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 252-256
  { 1, PPCE200Z4ItinerariesFU::E200Z4_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_EX | PPCE200Z4ItinerariesFU::E200Z4_BU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 257-259
  { 1, PPCE200Z4ItinerariesFU::E200Z4_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_EX | PPCE200Z4ItinerariesFU::E200Z4_LSU, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_MEM | PPCE200Z4ItinerariesFU::E200Z4_LSU, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_WB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 260-264
  { 1, PPCE200Z4ItinerariesFU::E200Z4_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_EX | PPCE200Z4ItinerariesFU::E200Z4_ALU, 0, (llvm::InstrStage::ReservationKinds)0 },   { 13, PPCE200Z4ItinerariesFU::E200Z4_EX | PPCE200Z4ItinerariesFU::E200Z4_ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 265-268
  { 1, PPCE200Z4ItinerariesFU::E200Z4_FETCH | PPCE200Z4ItinerariesFU::E200Z4_ICache, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_DIS0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_SPE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_SPE, -1, (llvm::InstrStage::ReservationKinds)0 }, // 269-272
  { 1, PPCE200Z4ItinerariesFU::E200Z4_FETCH | PPCE200Z4ItinerariesFU::E200Z4_ICache, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_DIS0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_SPE, -1, (llvm::InstrStage::ReservationKinds)0 }, // 273-275
  { 1, PPCE200Z4ItinerariesFU::E200Z4_FETCH | PPCE200Z4ItinerariesFU::E200Z4_ICache, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_DIS0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_SPE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, PPCE200Z4ItinerariesFU::E200Z4_SPE, -1, (llvm::InstrStage::ReservationKinds)0 }, // 276-279
  { 1, PPCE200Z4ItinerariesFU::E200Z4_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_EX | PPCE200Z4ItinerariesFU::E200Z4_LSU, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_MEM | PPCE200Z4ItinerariesFU::E200Z4_LSU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 280-283
  { 1, PPCE200Z4ItinerariesFU::E200Z4_FETCH | PPCE200Z4ItinerariesFU::E200Z4_ICache, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_DIS0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_SPE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 12, PPCE200Z4ItinerariesFU::E200Z4_SPE, -1, (llvm::InstrStage::ReservationKinds)0 }, // 284-287
  { 1, PPCE200Z4ItinerariesFU::E200Z4_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_EX | PPCE200Z4ItinerariesFU::E200Z4_ALU, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_MEM | PPCE200Z4ItinerariesFU::E200Z4_LSU, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_WB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 288-292
  { 1, PPCE200Z4ItinerariesFU::E200Z4_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_EX | PPCE200Z4ItinerariesFU::E200Z4_ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 293-295
  { 1, PPCE200Z4ItinerariesFU::E200Z4_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_EX | PPCE200Z4ItinerariesFU::E200Z4_MUL, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_MEM, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_WB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 296-300
  { 1, PPCE200Z4ItinerariesFU::E200Z4_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_EX | PPCE200Z4ItinerariesFU::E200Z4_ALU, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_MEM | PPCE200Z4ItinerariesFU::E200Z4_LSU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 301-304
  { 1, PPCE200Z4ItinerariesFU::E200Z4_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE200Z4ItinerariesFU::E200Z4_EX | PPCE200Z4ItinerariesFU::E200Z4_ALU, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_MEM, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z4ItinerariesFU::E200Z4_WB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 305-309
  { 1, PPCE200Z6ItinerariesFU::E200Z6_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_EX | PPCE200Z6ItinerariesFU::E200Z6_ALU, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_MEM, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_WB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 310-314
  { 1, PPCE200Z6ItinerariesFU::E200Z6_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_EX | PPCE200Z6ItinerariesFU::E200Z6_BU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 315-317
  { 1, PPCE200Z6ItinerariesFU::E200Z6_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_EX, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_MEM | PPCE200Z6ItinerariesFU::E200Z6_LSU, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_WB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 318-322
  { 1, PPCE200Z6ItinerariesFU::E200Z6_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_EX | PPCE200Z6ItinerariesFU::E200Z6_ALU, 0, (llvm::InstrStage::ReservationKinds)0 },   { 34, PPCE200Z6ItinerariesFU::E200Z6_EX | PPCE200Z6ItinerariesFU::E200Z6_ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 323-326
  { 1, PPCE200Z6ItinerariesFU::E200Z6_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_EX, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_MEM | PPCE200Z6ItinerariesFU::E200Z6_LSU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 327-330
  { 1, PPCE200Z6ItinerariesFU::E200Z6_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_EX | PPCE200Z6ItinerariesFU::E200Z6_ALU, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_MEM | PPCE200Z6ItinerariesFU::E200Z6_LSU, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_WB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 331-335
  { 1, PPCE200Z6ItinerariesFU::E200Z6_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_EX | PPCE200Z6ItinerariesFU::E200Z6_ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 336-338
  { 1, PPCE200Z6ItinerariesFU::E200Z6_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_EX | PPCE200Z6ItinerariesFU::E200Z6_MUL, -1, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPCE200Z6ItinerariesFU::E200Z6_MEM, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_WB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 339-343
  { 1, PPCE200Z6ItinerariesFU::E200Z6_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_EX | PPCE200Z6ItinerariesFU::E200Z6_ALU, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_MEM | PPCE200Z6ItinerariesFU::E200Z6_LSU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 344-347
  { 1, PPCE200Z6ItinerariesFU::E200Z6_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_DECODE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE200Z6ItinerariesFU::E200Z6_EX | PPCE200Z6ItinerariesFU::E200Z6_ALU, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_MEM, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z6ItinerariesFU::E200Z6_WB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 348-352
  { 1, PPCE200Z7ItinerariesFU::E200Z7_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_DIS0 | PPCE200Z7ItinerariesFU::E200Z7_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_ALU0 | PPCE200Z7ItinerariesFU::E200Z7_ALU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 353-355
  { 1, PPCE200Z7ItinerariesFU::E200Z7_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_DIS0 | PPCE200Z7ItinerariesFU::E200Z7_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_BU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 356-358
  { 1, PPCE200Z7ItinerariesFU::E200Z7_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_DIS0 | PPCE200Z7ItinerariesFU::E200Z7_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_LSU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 359-361
  { 1, PPCE200Z7ItinerariesFU::E200Z7_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_DIS0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_ALU0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 15, PPCE200Z7ItinerariesFU::E200Z7_ALU0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 362-365
  { 1, PPCE200Z7ItinerariesFU::E200Z7_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_DIS0 | PPCE200Z7ItinerariesFU::E200Z7_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_SPE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, PPCE200Z7ItinerariesFU::E200Z7_SPE, -1, (llvm::InstrStage::ReservationKinds)0 }, // 366-369
  { 1, PPCE200Z7ItinerariesFU::E200Z7_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_DIS0 | PPCE200Z7ItinerariesFU::E200Z7_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_SPE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE200Z7ItinerariesFU::E200Z7_SPE, -1, (llvm::InstrStage::ReservationKinds)0 }, // 370-373
  { 1, PPCE200Z7ItinerariesFU::E200Z7_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_DIS0 | PPCE200Z7ItinerariesFU::E200Z7_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_SPE, -1, (llvm::InstrStage::ReservationKinds)0 }, // 374-376
  { 1, PPCE200Z7ItinerariesFU::E200Z7_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_DIS0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_SPE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, PPCE200Z7ItinerariesFU::E200Z7_SPE, -1, (llvm::InstrStage::ReservationKinds)0 }, // 377-380
  { 1, PPCE200Z7ItinerariesFU::E200Z7_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_DIS0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_SPE, 0, (llvm::InstrStage::ReservationKinds)0 },   { 9, PPCE200Z7ItinerariesFU::E200Z7_SPE, -1, (llvm::InstrStage::ReservationKinds)0 }, // 381-384
  { 1, PPCE200Z7ItinerariesFU::E200Z7_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_DIS0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_ALU0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_LSU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 385-388
  { 1, PPCE200Z7ItinerariesFU::E200Z7_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_DIS0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_ALU0 | PPCE200Z7ItinerariesFU::E200Z7_MUL, -1, (llvm::InstrStage::ReservationKinds)0 },   { 3, PPCE200Z7ItinerariesFU::E200Z7_MUL, -1, (llvm::InstrStage::ReservationKinds)0 }, // 389-392
  { 1, PPCE200Z7ItinerariesFU::E200Z7_FETCH, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE200Z7ItinerariesFU::E200Z7_DIS0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE200Z7ItinerariesFU::E200Z7_ALU0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 393-395
  { 1, PPCE500ItinerariesFU::E500_DIS0 | PPCE500ItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500ItinerariesFU::E500_LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 396-397
  { 1, PPCE500ItinerariesFU::E500_DIS0 | PPCE500ItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500ItinerariesFU::E500_SU0 | PPCE500ItinerariesFU::E500_SU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 398-399
  { 1, PPCE500ItinerariesFU::E500_DIS0 | PPCE500ItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500ItinerariesFU::E500_BU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 400-401
  { 1, PPCE500ItinerariesFU::E500_DIS0 | PPCE500ItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500ItinerariesFU::E500_MU, 0, (llvm::InstrStage::ReservationKinds)0 },   { 14, PPCE500ItinerariesFU::E500_MU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 402-404
  { 1, PPCE500ItinerariesFU::E500_DIS0 | PPCE500ItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 6, PPCE500ItinerariesFU::E500_MU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 405-406
  { 1, PPCE500ItinerariesFU::E500_DIS0 | PPCE500ItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 32, PPCE500ItinerariesFU::E500_MU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 407-408
  { 1, PPCE500ItinerariesFU::E500_DIS0 | PPCE500ItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPCE500ItinerariesFU::E500_MU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 409-410
  { 1, PPCE500ItinerariesFU::E500_DIS0 | PPCE500ItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500ItinerariesFU::E500_SU0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 411-412
  { 1, PPCE500ItinerariesFU::E500_DIS0 | PPCE500ItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 29, PPCE500ItinerariesFU::E500_MU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 413-414
  { 1, PPCE500ItinerariesFU::E500_DIS0 | PPCE500ItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, PPCE500ItinerariesFU::E500_LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 415-416
  { 1, PPCE500ItinerariesFU::E500_DIS0 | PPCE500ItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500ItinerariesFU::E500_SU0 | PPCE500ItinerariesFU::E500_SU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500ItinerariesFU::E500_LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 417-419
  { 1, PPCE500ItinerariesFU::E500_DIS0 | PPCE500ItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 5, PPCE500ItinerariesFU::E500_SU0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 420-421
  { 1, PPCE500ItinerariesFU::E500_DIS0 | PPCE500ItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPCE500ItinerariesFU::E500_SU0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 422-423
  { 1, PPCE500ItinerariesFU::E500_DIS0 | PPCE500ItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE500ItinerariesFU::E500_SU0 | PPCE500ItinerariesFU::E500_SU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 424-425
  { 1, PPCE500ItinerariesFU::E500_DIS0 | PPCE500ItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500ItinerariesFU::E500_LSU_0, 0, (llvm::InstrStage::ReservationKinds)0 }, // 426-427
  { 1, PPCE500ItinerariesFU::E500_DIS0 | PPCE500ItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE500ItinerariesFU::E500_SU0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 428-429
  { 1, PPCE500mcItinerariesFU::E500mc_DIS0 | PPCE500mcItinerariesFU::E500mc_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::E500mc_LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 430-431
  { 1, PPCE500mcItinerariesFU::E500mc_DIS0 | PPCE500mcItinerariesFU::E500mc_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::E500mc_SFX0 | PPCE500mcItinerariesFU::E500mc_SFX1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 432-433
  { 1, PPCE500mcItinerariesFU::E500mc_DIS0 | PPCE500mcItinerariesFU::E500mc_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::E500mc_BU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 434-435
  { 1, PPCE500mcItinerariesFU::E500mc_DIS0 | PPCE500mcItinerariesFU::E500mc_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::E500mc_CFX_0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 14, PPCE500mcItinerariesFU::E500mc_CFX_DivBypass, -1, (llvm::InstrStage::ReservationKinds)0 }, // 436-438
  { 1, PPCE500mcItinerariesFU::E500mc_DIS0 | PPCE500mcItinerariesFU::E500mc_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPCE500mcItinerariesFU::E500mc_FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 439-440
  { 1, PPCE500mcItinerariesFU::E500mc_DIS0 | PPCE500mcItinerariesFU::E500mc_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 68, PPCE500mcItinerariesFU::E500mc_FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 441-442
  { 1, PPCE500mcItinerariesFU::E500mc_DIS0 | PPCE500mcItinerariesFU::E500mc_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE500mcItinerariesFU::E500mc_FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 443-444
  { 1, PPCE500mcItinerariesFU::E500mc_DIS0 | PPCE500mcItinerariesFU::E500mc_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 38, PPCE500mcItinerariesFU::E500mc_FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 445-446
  { 1, PPCE500mcItinerariesFU::E500mc_DIS0 | PPCE500mcItinerariesFU::E500mc_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, PPCE500mcItinerariesFU::E500mc_LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 447-448
  { 1, PPCE500mcItinerariesFU::E500mc_DIS0 | PPCE500mcItinerariesFU::E500mc_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::E500mc_SFX0 | PPCE500mcItinerariesFU::E500mc_SFX1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::E500mc_LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 449-451
  { 1, PPCE500mcItinerariesFU::E500mc_DIS0 | PPCE500mcItinerariesFU::E500mc_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 5, PPCE500mcItinerariesFU::E500mc_SFX0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 452-453
  { 1, PPCE500mcItinerariesFU::E500mc_DIS0 | PPCE500mcItinerariesFU::E500mc_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 8, PPCE500mcItinerariesFU::E500mc_FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 454-455
  { 1, PPCE500mcItinerariesFU::E500mc_DIS0 | PPCE500mcItinerariesFU::E500mc_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPCE500mcItinerariesFU::E500mc_SFX0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 456-457
  { 1, PPCE500mcItinerariesFU::E500mc_DIS0 | PPCE500mcItinerariesFU::E500mc_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE500mcItinerariesFU::E500mc_SFX0 | PPCE500mcItinerariesFU::E500mc_SFX1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 458-459
  { 1, PPCE500mcItinerariesFU::E500mc_DIS0 | PPCE500mcItinerariesFU::E500mc_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::E500mc_SFX0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 460-461
  { 1, PPCE500mcItinerariesFU::E500mc_DIS0 | PPCE500mcItinerariesFU::E500mc_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::E500mc_CFX_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 462-463
  { 1, PPCE500mcItinerariesFU::E500mc_DIS0 | PPCE500mcItinerariesFU::E500mc_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::E500mc_LSU_0, 0, (llvm::InstrStage::ReservationKinds)0 }, // 464-465
  { 1, PPCE500mcItinerariesFU::E500mc_DIS0 | PPCE500mcItinerariesFU::E500mc_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE500mcItinerariesFU::E500mc_SFX0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 466-467
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 468-469
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_SFX0 | PPCE5500ItinerariesFU::E5500_SFX1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 470-471
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_BU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 472-473
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_CFX_0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 26, PPCE5500ItinerariesFU::E5500_CFX_DivBypass, -1, (llvm::InstrStage::ReservationKinds)0 }, // 474-476
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_CFX_0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 16, PPCE5500ItinerariesFU::E5500_CFX_DivBypass, -1, (llvm::InstrStage::ReservationKinds)0 }, // 477-479
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 480-481
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 31, PPCE5500ItinerariesFU::E5500_FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 482-483
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 16, PPCE5500ItinerariesFU::E5500_FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 484-485
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, PPCE5500ItinerariesFU::E5500_LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 486-487
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_SFX0 | PPCE5500ItinerariesFU::E5500_SFX1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 488-490
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPCE5500ItinerariesFU::E5500_LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 491-492
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_CFX_0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE5500ItinerariesFU::E5500_CFX_1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 493-495
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_CFX_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 496-497
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 5, PPCE5500ItinerariesFU::E5500_CFX_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 498-499
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPCE5500ItinerariesFU::E5500_CFX_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 500-501
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 7, PPCE5500ItinerariesFU::E5500_FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 502-503
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE5500ItinerariesFU::E5500_CFX_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 504-505
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_CFX_0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_CFX_1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 506-508
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE5500ItinerariesFU::E5500_SFX0 | PPCE5500ItinerariesFU::E5500_SFX1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 509-510
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_LSU_0, 0, (llvm::InstrStage::ReservationKinds)0 }, // 511-512
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE5500ItinerariesFU::E5500_SFX0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 513-514
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2 | P8ItinerariesFU::P8_DU3 | P8ItinerariesFU::P8_DU4 | P8ItinerariesFU::P8_DU5 | P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2 | P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2 | P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 515-516
  { 1, P8ItinerariesFU::P8_DU7 | P8ItinerariesFU::P8_DU8, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_BRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 517-518
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FPU1 | P8ItinerariesFU::P8_FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 519-520
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2 | P8ItinerariesFU::P8_DU3 | P8ItinerariesFU::P8_DU4 | P8ItinerariesFU::P8_DU5 | P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 521-522
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_CRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 523-524
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2 | P8ItinerariesFU::P8_DU3 | P8ItinerariesFU::P8_DU4 | P8ItinerariesFU::P8_DU5 | P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2 | P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 525-526
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2 | P8ItinerariesFU::P8_DU3 | P8ItinerariesFU::P8_DU4 | P8ItinerariesFU::P8_DU5 | P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 23, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 527-528
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2 | P8ItinerariesFU::P8_DU3 | P8ItinerariesFU::P8_DU4 | P8ItinerariesFU::P8_DU5 | P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 15, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 529-530
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2 | P8ItinerariesFU::P8_DU3 | P8ItinerariesFU::P8_DU4 | P8ItinerariesFU::P8_DU5 | P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FPU1 | P8ItinerariesFU::P8_FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 531-532
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2 | P8ItinerariesFU::P8_DU3 | P8ItinerariesFU::P8_DU4 | P8ItinerariesFU::P8_DU5 | P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 533-535
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_BRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 536-538
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2 | P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 539-543
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2 | P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 544-547
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU5, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2 | P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 548-554
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2 | P8ItinerariesFU::P8_DU3 | P8ItinerariesFU::P8_DU4 | P8ItinerariesFU::P8_DU5 | P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 555-556
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 557-560
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2 | P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2 | P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 561-564
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2 | P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 565-569
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU5, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2 | P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 570-578
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2 | P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 579-582
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2 | P8ItinerariesFU::P8_DU3 | P8ItinerariesFU::P8_DU4 | P8ItinerariesFU::P8_DU5 | P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_CRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 583-584
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 585-586
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FPU1 | P8ItinerariesFU::P8_FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 587-588
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2 | P8ItinerariesFU::P8_DU3 | P8ItinerariesFU::P8_DU4 | P8ItinerariesFU::P8_DU5 | P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FPU1 | P8ItinerariesFU::P8_FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 589-591
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FPU1 | P8ItinerariesFU::P8_FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 592-596
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU5, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 597-604
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2 | P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 605-608
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU5, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 609-617
  { 1, P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2 | P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2 | P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2 | P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 618-620
  { 1, P7ItinerariesFU::P7_DU1 | P7ItinerariesFU::P7_DU2 | P7ItinerariesFU::P7_DU3 | P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2 | P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 621-622
  { 1, P7ItinerariesFU::P7_DU1 | P7ItinerariesFU::P7_DU2 | P7ItinerariesFU::P7_DU3 | P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 623-624
  { 1, P7ItinerariesFU::P7_DU5 | P7ItinerariesFU::P7_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_BRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 625-626
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_VS1 | P7ItinerariesFU::P7_VS2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 627-628
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_CRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 629-630
  { 1, P7ItinerariesFU::P7_DU1 | P7ItinerariesFU::P7_DU2 | P7ItinerariesFU::P7_DU3 | P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 631-632
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 68, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 633-635
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 36, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 636-638
  { 1, P7ItinerariesFU::P7_DU1 | P7ItinerariesFU::P7_DU2 | P7ItinerariesFU::P7_DU3 | P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_VS1 | P7ItinerariesFU::P7_VS2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 639-640
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_VS1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 641-642
  { 1, P7ItinerariesFU::P7_DU1 | P7ItinerariesFU::P7_DU2 | P7ItinerariesFU::P7_DU3 | P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 643-645
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_BRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 646-648
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 649-653
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 654-657
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 658-664
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 665-668
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 669-673
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 674-681
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_CRU, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 682-687
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 688-689
  { 1, P7ItinerariesFU::P7_DU1 | P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_VS2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 690-691
  { 1, P7ItinerariesFU::P7_DU1 | P7ItinerariesFU::P7_DU2 | P7ItinerariesFU::P7_DU3 | P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_VS1 | P7ItinerariesFU::P7_VS2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 692-694
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_VS1 | P7ItinerariesFU::P7_VS2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 695-699
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 700-706
  { 0, 0, 0, llvm::InstrStage::Required } // End stages
};
extern const unsigned PPCOperandCycles[] = {
  0, // No itinerary
  2,   0,   0, // 1-3
  2,   0,   0, // 4-6
  4,   0, // 7-8
  2,   0,   0, // 9-11
  4,   0,   0, // 12-14
  1,   1, // 15-16
  5,   1,   1, // 17-19
  36,   0,   0, // 20-22
  6,   0,   0, // 23-25
  31,   0,   0, // 26-28
  6,   0,   0, // 29-31
  6,   0,   0, // 32-34
  1,   1,   1, // 35-37
  19,   0,   0, // 38-40
  6,   0,   0,   0, // 41-44
  4,   1,   1, // 45-47
  2,   0,   0,   0, // 48-51
  4,   1,   1, // 52-54
  5,   2,   1,   1, // 55-58
  5,   2,   1,   1, // 59-62
  5,   1,   1, // 63-65
  5,   2,   1,   1, // 66-69
  5,   2,   1,   1, // 70-73
  4,   1,   1, // 74-76
  4,   1,   1, // 77-79
  4,   1,   1, // 80-82
  4,   1,   1, // 83-85
  4,   0,   0, // 86-88
  4,   0,   0, // 89-91
  4,   0, // 92-93
  6,   0, // 94-95
  3,   0,   0, // 96-98
  3,   0, // 99-100
  2,   0, // 101-102
  6,   0, // 103-104
  6,   0, // 105-106
  3,   0,   0, // 107-109
  2,   0, // 110-111
  5,   0, // 112-113
  4,   0,   0, // 114-116
  4,   0,   0, // 117-119
  4,   0,   0, // 120-122
  1,   1,   1, // 123-125
  2,   1,   1,   1, // 126-129
  4,   0, // 130-131
  2,   0,   0, // 132-134
  2,   0,   0, // 135-137
  4,   1,   1, // 138-140
  2,   1,   1,   1, // 141-144
  2,   1,   1,   1, // 145-148
  4,   1,   1, // 149-151
  4,   1,   1, // 152-154
  2,   0, // 155-156
  6,   0, // 157-158
  3,   0,   0, // 159-161
  3,   0,   0, // 162-164
  2,   0,   0, // 165-167
  2,   0, // 168-169
  6,   0,   0, // 170-172
  6,   0,   0, // 173-175
  2,   0,   0, // 176-178
  2,   0,   0, // 179-181
  2,   0,   0, // 182-184
  2,   0,   0, // 185-187
  4,   0,   0, // 188-190
  4,   0,   0, // 191-193
  4,   0, // 194-195
  6,   0, // 196-197
  5,   1,   1, // 198-200
  2,   0,   0, // 201-203
  4,   0,   0, // 204-206
  4,   0,   0, // 207-209
  2,   0,   0, // 210-212
  6,   0,   0, // 213-215
  2,   0,   0, // 216-218
  2,   0,   0,   0, // 219-222
  6,   0, // 223-224
  1,   1,   1, // 225-227
  5,   1,   1, // 228-230
  6,   0,   0, // 231-233
  4,   0,   0, // 234-236
  4,   0,   0, // 237-239
  4,   0,   0, // 240-242
  6,   0,   0, // 243-245
  6,   0,   0, // 246-248
  6,   0,   0,   0, // 249-252
  6,   0,   0, // 253-255
  4,   0,   0, // 256-258
  4,   0,   0, // 259-261
  6,   0,   0, // 262-264
  6,   0,   0, // 265-267
  6,   0,   0,   0, // 268-271
  5,   1,   1, // 272-274
  6,   0,   0, // 275-277
  5,   1,   1, // 278-280
  5,   1,   1, // 281-283
  5,   1,   1, // 284-286
  1,   1, // 287-288
  4,   1,   1, // 289-291
  5,   1,   1, // 292-294
  4,   1,   1, // 295-297
  4,   1,   1, // 298-300
  5,   1,   1, // 301-303
  5,   2,   1,   1, // 304-307
  5,   2,   1,   1, // 308-311
  6,   0, // 312-313
  4,   1,   1, // 314-316
  4,   1,   1, // 317-319
  4,   1,   1, // 320-322
  6,   0, // 323-324
  5,   1,   1, // 325-327
  5,   1,   1, // 328-330
  5,   1,   1, // 331-333
  5,   1,   1, // 334-336
  4,   1,   1, // 337-339
  4,   1,   1, // 340-342
  5,   1,   1, // 343-345
  1,   1,   1, // 346-348
  1,   1,   1, // 349-351
  4,   1,   1, // 352-354
  5,   1,   1, // 355-357
  4,   1,   1, // 358-360
  1,   1,   1, // 361-363
  1,   1,   1, // 364-366
  5,   1,   1, // 367-369
  6,   0, // 370-371
  2,   0,   0, // 372-374
  6,   0, // 375-376
  6,   0, // 377-378
  3,   0, // 379-380
  2,   0, // 381-382
  6,   0, // 383-384
  36,   0,   0, // 385-387
  36,   0,   0, // 388-390
  36,   0,   0, // 391-393
  36,   0,   0, // 394-396
  4,   0,   0, // 397-399
  2,   0,   0, // 400-402
  6,   0,   0, // 403-405
  4,   0,   0, // 406-408
  3,   0,   0, // 409-411
  3,   0,   0, // 412-414
  2,   0,   0, // 415-417
  2,   0,   0, // 418-420
  2,   0,   0, // 421-423
  3,   0,   0, // 424-426
  4,   0, // 427-428
  31,   0,   0, // 429-431
  31,   0,   0, // 432-434
  31,   0,   0, // 435-437
  19,   0,   0, // 438-440
  19,   0,   0, // 441-443
  19,   0,   0, // 444-446
  19,   0,   0, // 447-449
  31,   0,   0, // 450-452
  5,   2,   1,   1, // 453-456
  5,   2,   1,   1, // 457-460
  2,   1,   1,   1, // 461-464
  2,   1,   1,   1, // 465-468
  2,   1,   1,   1, // 469-472
  5,   2,   1,   1, // 473-476
  5,   2,   1,   1, // 477-480
  5,   2,   1,   1, // 481-484
  5,   2,   1,   1, // 485-488
  4,   0, // 489-490
  4,   0, // 491-492
  5,   1,   1, // 493-495
  1,   1,   1, // 496-498
  2,   0,   0, // 499-501
  5,   1,   1, // 502-504
  1,   1,   1, // 505-507
  4,   0, // 508-509
  4,   0, // 510-511
  5,   1,   1, // 512-514
  1,   1,   1, // 515-517
  5,   1,   1, // 518-520
  1,   1,   1, // 521-523
  2,   0, // 524-525
  5,   0, // 526-527
  6,   0, // 528-529
  6,   0, // 530-531
  2,   0,   0, // 532-534
  2,   0, // 535-536
  1,   1, // 537-538
  6, // 539
  1,   0,   0, // 540-542
  2,   0,   0, // 543-545
  6,   0,   0, // 546-548
  2,   0,   0, // 549-551
  1,   0,   0, // 552-554
  1,   0,   0, // 555-557
  6,   0,   0, // 558-560
  71,   0,   0, // 561-563
  39,   0,   0, // 564-566
  6,   0,   0, // 567-569
  72,   0,   0, // 570-572
  5,   0,   0, // 573-575
  6,   0,   0, // 576-578
  0,   0,   0, // 579-581
  2,   0,   0, // 582-584
  59,   0,   0, // 585-587
  6,   0,   0,   0, // 588-591
  69,   0,   0, // 592-594
  65,   0,   0, // 595-597
  16,   0,   0, // 598-600
  2,   0,   0,   0, // 601-604
  16, // 605
  82,   0,   0, // 606-608
  6,   8,   0,   0, // 609-612
  6,   8,   0,   0, // 613-616
  6,   0,   0, // 617-619
  6,   0,   0, // 620-622
  7,   0,   0, // 623-625
  7,   9,   0,   0, // 626-629
  7,   9,   0,   0, // 630-633
  6,   0,   0, // 634-636
  6,   8,   0,   0, // 637-640
  6,   8,   0,   0, // 641-644
  5,   0,   0, // 645-647
  1,   0,   0, // 648-650
  6,   0, // 651-652
  6,   0, // 653-654
  4,   0, // 655-656
  1,   0, // 657-658
  4,   0, // 659-660
  6,   0, // 661-662
  16,   0, // 663-664
  5,   0,   0, // 665-667
  5,   0,   0, // 668-670
  6,   0,   0, // 671-673
  0,   0,   0, // 674-676
  2,   0,   0,   0, // 677-680
  16, // 681
  2,   0,   0, // 682-684
  2,   0,   0, // 685-687
  2,   0,   0, // 688-690
  82,   0,   0, // 691-693
  2,   0,   0,   0, // 694-697
  2,   0,   0,   0, // 698-701
  0,   0,   0, // 702-704
  82,   0,   0, // 705-707
  2,   0, // 708-709
  2,   0, // 710-711
  6,   0, // 712-713
  2,   0,   0, // 714-716
  2,   0, // 717-718
  2,   0, // 719-720
  5,   0,   0, // 721-723
  5,   0,   0, // 724-726
  2,   0,   0, // 727-729
  2,   0,   0, // 730-732
  2,   0,   0, // 733-735
  2,   0,   0, // 736-738
  2,   0,   0, // 739-741
  1,   0,   0, // 742-744
  5,   0,   0, // 745-747
  1,   0,   0, // 748-750
  6,   0,   0, // 751-753
  6,   0, // 754-755
  6,   0,   0, // 756-758
  2,   0,   0, // 759-761
  2,   0,   0, // 762-764
  2,   0,   0, // 765-767
  1,   0, // 768-769
  1,   0,   0, // 770-772
  1,   0,   0, // 773-775
  2,   0,   0, // 776-778
  6,   0,   0, // 779-781
  2,   0,   0, // 782-784
  2,   0,   0,   0, // 785-788
  6,   0, // 789-790
  0,   0,   0, // 791-793
  6,   0,   0, // 794-796
  5,   0,   0, // 797-799
  5,   0,   0, // 800-802
  5,   0,   0, // 803-805
  6,   0,   0, // 806-808
  6,   0,   0, // 809-811
  6,   0,   0, // 812-814
  6,   0,   0,   0, // 815-818
  6,   0,   0, // 819-821
  5,   0,   0, // 822-824
  5,   0,   0, // 825-827
  6,   0,   0, // 828-830
  6,   0,   0, // 831-833
  6,   0,   0,   0, // 834-837
  6,   0,   0, // 838-840
  5,   0,   0, // 841-843
  6,   0,   0, // 844-846
  6,   0,   0, // 847-849
  7,   0,   0, // 850-852
  1,   0,   0, // 853-855
  16,   0,   0, // 856-858
  6,   0,   0, // 859-861
  82,   0,   0, // 862-864
  16, // 865
  6, // 866
  7,   0,   0, // 867-869
  6,   8,   0,   0, // 870-873
  6,   8,   0,   0, // 874-877
  6,   0, // 878-879
  82,   0,   0, // 880-882
  82,   0,   0, // 883-885
  6,   0,   0, // 886-888
  6,   0, // 889-890
  7,   0,   0, // 891-893
  7,   0,   0, // 894-896
  7,   0,   0, // 897-899
  7,   0,   0, // 900-902
  6,   8,   0,   0, // 903-906
  6,   8,   0,   0, // 907-910
  7,   0,   0, // 911-913
  0,   0,   0, // 914-916
  0,   0,   0, // 917-919
  0,   0,   0, // 920-922
  6,   0,   0, // 923-925
  0,   0,   0, // 926-928
  0,   0,   0, // 929-931
  6,   0,   0, // 932-934
  6,   0, // 935-936
  2,   0,   0, // 937-939
  4,   0, // 940-941
  6,   0, // 942-943
  4,   0, // 944-945
  16,   0, // 946-947
  6,   0, // 948-949
  39,   0,   0, // 950-952
  39,   0,   0, // 953-955
  71,   0,   0, // 956-958
  71,   0,   0, // 959-961
  39,   0,   0, // 962-964
  71,   0,   0, // 965-967
  39,   0,   0, // 968-970
  71,   0,   0, // 971-973
  1,   0,   0, // 974-976
  2,   0,   0, // 977-979
  6,   0,   0, // 980-982
  5,   0,   0, // 983-985
  2,   0,   0, // 986-988
  2,   0,   0, // 989-991
  2,   0,   0, // 992-994
  2,   0,   0, // 995-997
  2,   0,   0, // 998-1000
  6,   0, // 1001-1002
  2,   0,   0, // 1003-1005
  2,   0,   0, // 1006-1008
  72,   0,   0, // 1009-1011
  72,   0,   0, // 1012-1014
  69,   0,   0, // 1015-1017
  69,   0,   0, // 1018-1020
  69,   0,   0, // 1021-1023
  65,   0,   0, // 1024-1026
  69,   0,   0, // 1027-1029
  65,   0,   0, // 1030-1032
  65,   0,   0, // 1033-1035
  65,   0,   0, // 1036-1038
  72,   0,   0, // 1039-1041
  59,   0,   0, // 1042-1044
  59,   0,   0, // 1045-1047
  59,   0,   0, // 1048-1050
  59,   0,   0, // 1051-1053
  72,   0,   0, // 1054-1056
  7,   9,   0,   0, // 1057-1060
  7,   9,   0,   0, // 1061-1064
  2,   0,   0,   0, // 1065-1068
  2,   0,   0,   0, // 1069-1072
  2,   0,   0,   0, // 1073-1076
  6,   8,   0,   0, // 1077-1080
  6,   8,   0,   0, // 1081-1084
  6,   0,   0, // 1085-1087
  6,   0,   0, // 1088-1090
  7,   9,   0,   0, // 1091-1094
  7,   9,   0,   0, // 1095-1098
  6,   0,   0, // 1099-1101
  6,   0,   0, // 1102-1104
  6,   0,   0, // 1105-1107
  0,   0,   0, // 1108-1110
  1,   0,   0, // 1111-1113
  6,   0,   0, // 1114-1116
  0,   0,   0, // 1117-1119
  6,   0,   0, // 1120-1122
  16, // 1123
  6,   0,   0, // 1124-1126
  0,   0,   0, // 1127-1129
  7,   0,   0, // 1130-1132
  0,   0,   0, // 1133-1135
  6,   0, // 1136-1137
  6,   0, // 1138-1139
  1,   0,   0, // 1140-1142
  16,   0, // 1143-1144
  6, // 1145
  1,   0,   0, // 1146-1148
  4,   1,   1,   1, // 1149-1152
  4,   1,   1,   1, // 1153-1156
  4,   1,   1, // 1157-1159
  5,   1,   1,   1, // 1160-1163
  4,   1,   1,   1, // 1164-1167
  4,   1,   1,   1, // 1168-1171
  38,   1,   1, // 1172-1174
  5,   1,   1, // 1175-1177
  4,   1,   1,   1, // 1178-1181
  5,   1,   1,   1,   1, // 1182-1186
  6,   1,   1,   1,   1, // 1187-1191
  4,   1,   1, // 1192-1194
  4,   1,   1,   1, // 1195-1198
  4,   1,   1,   1, // 1199-1202
  4,   1,   1,   1, // 1203-1206
  7,   1,   1,   1,   1, // 1207-1211
  7,   1,   1,   1,   1, // 1212-1216
  6,   1,   1,   1,   1, // 1217-1221
  4,   1,   1,   1, // 1222-1225
  4,   1,   1,   1, // 1226-1229
  6,   1,   1,   1, // 1230-1233
  6,   1,   1,   1, // 1234-1237
  5,   1,   1, // 1238-1240
  4,   1,   1,   1, // 1241-1244
  5,   1,   1,   1, // 1245-1248
  5,   1,   1, // 1249-1251
  4,   1,   1,   1, // 1252-1255
  5,   1,   1,   1, // 1256-1259
  4,   1,   1,   1, // 1260-1263
  4,   1,   1,   1, // 1264-1267
  4,   1,   1, // 1268-1270
  4,   1,   1,   1, // 1271-1274
  4,   1,   1, // 1275-1277
  4,   1,   1,   1, // 1278-1281
  4,   1,   1,   1, // 1282-1285
  4,   1,   1,   1, // 1286-1289
  4,   1,   1,   1, // 1290-1293
  4,   1,   1,   1, // 1294-1297
  4,   1,   1,   1, // 1298-1301
  4,   1,   1,   1, // 1302-1305
  4,   1,   1,   1, // 1306-1309
  4,   1,   1,   1, // 1310-1313
  5,   1,   1, // 1314-1316
  4,   1,   1,   1, // 1317-1320
  7,   1,   1,   1,   1, // 1321-1325
  7,   1,   1,   1,   1, // 1326-1330
  6,   1,   1,   1,   1, // 1331-1335
  7,   1,   1,   1,   1, // 1336-1340
  7,   1,   1,   1,   1, // 1341-1345
  4,   1,   1,   1, // 1346-1349
  4,   1,   1,   1, // 1350-1353
  4,   1,   1,   1, // 1354-1357
  4,   1,   1,   1, // 1358-1361
  5,   1,   1,   1,   1, // 1362-1366
  6,   1,   1,   1,   1, // 1367-1371
  4,   1,   1,   1, // 1372-1375
  4,   1,   1,   1, // 1376-1379
  5,   1,   1, // 1380-1382
  4,   1,   1,   1, // 1383-1386
  5,   1,   1, // 1387-1389
  4,   1,   1,   1, // 1390-1393
  4,   1,   1,   1, // 1394-1397
  4,   1,   1,   1, // 1398-1401
  4,   1,   1,   1, // 1402-1405
  4,   1,   1,   1, // 1406-1409
  38,   1,   1, // 1410-1412
  38,   1,   1, // 1413-1415
  38,   1,   1, // 1416-1418
  38,   1,   1, // 1419-1421
  4,   1,   1,   1, // 1422-1425
  4,   1,   1,   1, // 1426-1429
  4,   1,   1, // 1430-1432
  4,   1,   1,   1, // 1433-1436
  4,   1,   1,   1, // 1437-1440
  4,   1,   1,   1, // 1441-1444
  6,   1,   1,   1, // 1445-1448
  6,   1,   1,   1, // 1449-1452
  5,   1,   1,   1,   1, // 1453-1457
  6,   1,   1,   1,   1, // 1458-1462
  4,   1,   1, // 1463-1465
  4,   1,   1, // 1466-1468
  4,   1,   1,   1, // 1469-1472
  5,   1,   1, // 1473-1475
  4,   1,   1,   1, // 1476-1479
  4,   1,   1,   1, // 1480-1483
  5,   1,   1, // 1484-1486
  4,   1,   1, // 1487-1489
  4,   1,   1,   1, // 1490-1493
  5,   1,   1, // 1494-1496
  4,   1,   1,   1, // 1497-1500
  4,   1,   1,   1, // 1501-1504
  4,   1,   1,   1, // 1505-1508
  2,   1, // 1509-1510
  2,   1, // 1511-1512
  2,   1, // 1513-1514
  3,   1, // 1515-1516
  2,   1, // 1517-1518
  2,   1, // 1519-1520
  3,   1, // 1521-1522
  16,   1, // 1523-1524
  2,   1, // 1525-1526
  2,   1,   1, // 1527-1529
  4,   1, // 1530-1531
  3,   1,   1, // 1532-1534
  2,   1, // 1535-1536
  2,   1, // 1537-1538
  2,   1, // 1539-1540
  2,   1, // 1541-1542
  2,   1, // 1543-1544
  2,   1, // 1545-1546
  6,   1, // 1547-1548
  6,   1, // 1549-1550
  6,   1, // 1551-1552
  2,   1, // 1553-1554
  2,   1, // 1555-1556
  3,   1, // 1557-1558
  2,   1,   1, // 1559-1561
  3,   1, // 1562-1563
  2,   1, // 1564-1565
  3,   1, // 1566-1567
  3,   1, // 1568-1569
  2,   1, // 1570-1571
  3,   1, // 1572-1573
  2,   1, // 1574-1575
  2,   1, // 1576-1577
  2,   1, // 1578-1579
  2,   1, // 1580-1581
  2,   1, // 1582-1583
  2,   1, // 1584-1585
  3,   1, // 1586-1587
  2,   1, // 1588-1589
  2,   1, // 1590-1591
  2,   1, // 1592-1593
  2,   1, // 1594-1595
  2,   1, // 1596-1597
  2,   1, // 1598-1599
  2,   1,   1, // 1600-1602
  2,   1, // 1603-1604
  2,   1, // 1605-1606
  3,   1, // 1607-1608
  6,   1, // 1609-1610
  6,   1, // 1611-1612
  6,   1, // 1613-1614
  6,   1, // 1615-1616
  6,   1, // 1617-1618
  3,   1, // 1619-1620
  3,   1, // 1621-1622
  3,   1, // 1623-1624
  2,   1, // 1625-1626
  3,   1, // 1627-1628
  4,   1, // 1629-1630
  3,   1,   1, // 1631-1633
  2,   1, // 1634-1635
  3,   1, // 1636-1637
  2,   1, // 1638-1639
  2,   1, // 1640-1641
  3,   1, // 1642-1643
  2,   1, // 1644-1645
  3,   1, // 1646-1647
  2,   1, // 1648-1649
  2,   1, // 1650-1651
  2,   1, // 1652-1653
  2,   1, // 1654-1655
  16,   1, // 1656-1657
  16,   1, // 1658-1659
  16,   1, // 1660-1661
  16,   1, // 1662-1663
  2,   1, // 1664-1665
  2,   1, // 1666-1667
  2,   1, // 1668-1669
  2,   1, // 1670-1671
  2,   1, // 1672-1673
  2,   1, // 1674-1675
  2,   1, // 1676-1677
  2,   1,   1, // 1678-1680
  3,   1,   1, // 1681-1683
  2,   1, // 1684-1685
  2,   1, // 1686-1687
  3,   1, // 1688-1689
  2,   1, // 1690-1691
  2,   1, // 1692-1693
  3,   1, // 1694-1695
  2,   1, // 1696-1697
  2,   1, // 1698-1699
  3,   1, // 1700-1701
  2,   1, // 1702-1703
  2,   1, // 1704-1705
  2,   1, // 1706-1707
  2,   1, // 1708-1709
  2,   1, // 1710-1711
  5,   1,   1,   1,   1, // 1712-1716
  5,   1,   1,   1,   1, // 1717-1721
  4,   1,   1, // 1722-1724
  6,   1,   1,   1,   1, // 1725-1729
  4,   1,   1,   1, // 1730-1733
  5,   1,   1,   1,   1, // 1734-1738
  17,   1,   1, // 1739-1741
  5,   1,   1,   1, // 1742-1745
  5,   1,   1,   1, // 1746-1749
  5,   1,   1,   1, // 1750-1753
  4,   1,   1, // 1754-1756
  7,   1,   1, // 1757-1759
  4,   1,   1,   1, // 1760-1763
  17,   1,   1,   1, // 1764-1767
  5,   1,   1,   1,   1,   1, // 1768-1773
  5,   1,   1,   1,   1, // 1774-1778
  5,   1,   1,   1,   1, // 1779-1783
  4,   1,   1, // 1784-1786
  4,   1,   1,   1, // 1787-1790
  5,   1,   1,   1,   1, // 1791-1795
  5,   1,   1,   1,   1, // 1796-1800
  5,   1,   1,   1,   1, // 1801-1805
  5,   1,   1,   1,   1, // 1806-1810
  5,   1,   1,   1,   1, // 1811-1815
  5,   1,   1,   1,   1, // 1816-1820
  5,   1,   1,   1,   1, // 1821-1825
  4,   1,   1,   1, // 1826-1829
  4,   1,   1,   1, // 1830-1833
  6,   1,   1,   1, // 1834-1837
  4,   1,   1, // 1838-1840
  5,   1,   1,   1,   1, // 1841-1845
  6,   1,   1,   1,   1, // 1846-1850
  6,   1,   1,   1, // 1851-1854
  5,   1,   1,   1, // 1855-1858
  5,   1,   1,   1, // 1859-1862
  5,   1,   1,   1,   1, // 1863-1867
  4,   1,   1, // 1868-1870
  6,   1,   1,   1,   1, // 1871-1875
  5,   1,   1,   1,   1, // 1876-1880
  5,   1,   1,   1,   1, // 1881-1885
  4,   1,   1, // 1886-1888
  4,   1,   1,   1, // 1889-1892
  4,   1,   1, // 1893-1895
  5,   1,   1,   1,   1, // 1896-1900
  5,   1,   1,   1,   1, // 1901-1905
  5,   1,   1,   1,   1, // 1906-1910
  4,   1,   1,   1, // 1911-1914
  4,   1,   1,   1, // 1915-1918
  5,   1,   1,   1,   1, // 1919-1923
  5,   1,   1,   1, // 1924-1927
  5,   1,   1,   1,   1, // 1928-1932
  5,   1,   1,   1,   1,   1, // 1933-1938
  5,   1,   1,   1,   1, // 1939-1943
  4,   1,   1,   1, // 1944-1947
  5,   1,   1,   1,   1, // 1948-1952
  4,   1,   1, // 1953-1955
  5,   1,   1,   1, // 1956-1959
  4,   1,   1, // 1960-1962
  5,   1,   1,   1,   1, // 1963-1967
  5,   1,   1,   1,   1, // 1968-1972
  5,   1,   1,   1,   1, // 1973-1977
  5,   1,   1,   1, // 1978-1981
  5,   1,   1,   1, // 1982-1985
  5,   1,   1,   1, // 1986-1989
  5,   1,   1,   1,   1, // 1990-1994
  5,   1,   1,   1,   1, // 1995-1999
  5,   1,   1,   1, // 2000-2003
  5,   1,   1,   1, // 2004-2007
  5,   1,   1,   1,   1, // 2008-2012
  4,   1,   1, // 2013-2015
  5,   1,   1,   1, // 2016-2019
  5,   1,   1,   1,   1, // 2020-2024
  5,   1,   1,   1,   1, // 2025-2029
  5,   1,   1,   1,   1, // 2030-2034
  5,   1,   1,   1,   1, // 2035-2039
  5,   1,   1,   1,   1, // 2040-2044
  5,   1,   1,   1,   1, // 2045-2049
  5,   1,   1,   1,   1, // 2050-2054
  4,   1,   1,   1, // 2055-2058
  5,   1,   1,   1,   1, // 2059-2063
  4,   1,   1,   1, // 2064-2067
  5,   1,   1,   1,   1, // 2068-2072
  5,   1,   1,   1,   1, // 2073-2077
  5,   1,   1,   1,   1, // 2078-2082
  5,   1,   1,   1,   1, // 2083-2087
  5,   1,   1,   1,   1, // 2088-2092
  17,   1,   1, // 2093-2095
  17,   1,   1, // 2096-2098
  17,   1,   1, // 2099-2101
  17,   1,   1, // 2102-2104
  4,   1,   1,   1, // 2105-2108
  5,   1,   1,   1,   1, // 2109-2113
  5,   1,   1,   1, // 2114-2117
  4,   1,   1, // 2118-2120
  5,   1,   1,   1,   1, // 2121-2125
  5,   1,   1,   1,   1, // 2126-2130
  5,   1,   1,   1,   1, // 2131-2135
  17,   1,   1,   1, // 2136-2139
  17,   1,   1,   1, // 2140-2143
  17,   1,   1,   1, // 2144-2147
  17,   1,   1,   1, // 2148-2151
  4,   1,   1,   1, // 2152-2155
  4,   1,   1,   1, // 2156-2159
  5,   1,   1,   1,   1, // 2160-2164
  5,   1,   1,   1,   1, // 2165-2169
  4,   1,   1, // 2170-2172
  4,   1,   1, // 2173-2175
  5,   1,   1,   1,   1, // 2176-2180
  4,   1,   1,   1, // 2181-2184
  5,   1,   1,   1,   1, // 2185-2189
  4,   1,   1, // 2190-2192
  7,   1,   1, // 2193-2195
  5,   1,   1,   1,   1, // 2196-2200
  4,   1,   1,   1, // 2201-2204
  4,   1,   1, // 2205-2207
  5,   1,   1,   1,   1, // 2208-2212
  4,   1,   1,   1, // 2213-2216
  5,   1,   1,   1,   1, // 2217-2221
  5,   1,   1,   1,   1, // 2222-2226
  5,   1,   1,   1,   1, // 2227-2231
  5,   1,   1,   1,   1, // 2232-2236
  5,   1,   1,   1,   1, // 2237-2241
  4,   1,   1, // 2242-2244
  6,   1,   1,   1,   1, // 2245-2249
  4,   1,   1,   1, // 2250-2253
  6,   1,   1,   1,   1, // 2254-2258
  38,   1,   1, // 2259-2261
  5,   1,   1,   1, // 2262-2265
  5,   1,   1,   1,   1,   1, // 2266-2271
  6,   1,   1,   1,   1, // 2272-2276
  6,   1,   1,   1,   1, // 2277-2281
  4,   1,   1, // 2282-2284
  4,   1,   1,   1, // 2285-2288
  5,   1,   1,   1,   1, // 2289-2293
  5,   1,   1,   1,   1, // 2294-2298
  8,   1,   1,   1,   1, // 2299-2303
  8,   1,   1,   1,   1, // 2304-2308
  8,   1,   1,   1,   1, // 2309-2313
  5,   1,   1,   1,   1, // 2314-2318
  5,   1,   1,   1,   1, // 2319-2323
  5,   1,   1,   1, // 2324-2327
  5,   1,   1,   1, // 2328-2331
  6,   1,   1,   1, // 2332-2335
  5,   1,   1,   1,   1, // 2336-2340
  6,   1,   1,   1,   1, // 2341-2345
  6,   1,   1,   1, // 2346-2349
  5,   1,   1,   1,   1, // 2350-2354
  6,   1,   1,   1,   1, // 2355-2359
  5,   1,   1,   1,   1, // 2360-2364
  5,   1,   1,   1,   1, // 2365-2369
  4,   1,   1, // 2370-2372
  4,   1,   1,   1, // 2373-2376
  4,   1,   1, // 2377-2379
  5,   1,   1,   1,   1, // 2380-2384
  6,   1,   1,   1,   1, // 2385-2389
  5,   1,   1,   1,   1, // 2390-2394
  4,   1,   1,   1, // 2395-2398
  4,   1,   1,   1, // 2399-2402
  5,   1,   1,   1,   1, // 2403-2407
  5,   1,   1,   1,   1, // 2408-2412
  5,   1,   1,   1,   1,   1, // 2413-2418
  5,   1,   1,   1,   1, // 2419-2423
  5,   1,   1,   1, // 2424-2427
  6,   1,   1,   1,   1, // 2428-2432
  8,   1,   1,   1,   1, // 2433-2437
  8,   1,   1,   1,   1, // 2438-2442
  8,   1,   1,   1,   1, // 2443-2447
  8,   1,   1,   1,   1, // 2448-2452
  8,   1,   1,   1,   1, // 2453-2457
  6,   1,   1,   1,   1, // 2458-2462
  6,   1,   1,   1,   1, // 2463-2467
  6,   1,   1,   1,   1, // 2468-2472
  6,   1,   1,   1,   1, // 2473-2477
  6,   1,   1,   1,   1, // 2478-2482
  6,   1,   1,   1,   1, // 2483-2487
  5,   1,   1,   1,   1, // 2488-2492
  5,   1,   1,   1,   1, // 2493-2497
  5,   1,   1,   1, // 2498-2501
  6,   1,   1,   1,   1, // 2502-2506
  5,   1,   1,   1, // 2507-2510
  6,   1,   1,   1,   1, // 2511-2515
  5,   1,   1,   1,   1, // 2516-2520
  5,   1,   1,   1,   1, // 2521-2525
  5,   1,   1,   1,   1, // 2526-2530
  5,   1,   1,   1,   1, // 2531-2535
  38,   1,   1, // 2536-2538
  38,   1,   1, // 2539-2541
  38,   1,   1, // 2542-2544
  38,   1,   1, // 2545-2547
  4,   1,   1,   1, // 2548-2551
  5,   1,   1,   1,   1, // 2552-2556
  4,   1,   1, // 2557-2559
  5,   1,   1,   1,   1, // 2560-2564
  5,   1,   1,   1,   1, // 2565-2569
  5,   1,   1,   1,   1, // 2570-2574
  5,   1,   1,   1, // 2575-2578
  5,   1,   1,   1, // 2579-2582
  6,   1,   1,   1,   1, // 2583-2587
  6,   1,   1,   1,   1, // 2588-2592
  4,   1,   1, // 2593-2595
  4,   1,   1, // 2596-2598
  6,   1,   1,   1,   1, // 2599-2603
  5,   1,   1,   1, // 2604-2607
  5,   1,   1,   1,   1, // 2608-2612
  6,   1,   1,   1,   1, // 2613-2617
  5,   1,   1,   1, // 2618-2621
  4,   1,   1, // 2622-2624
  6,   1,   1,   1,   1, // 2625-2629
  5,   1,   1,   1, // 2630-2633
  5,   1,   1,   1,   1, // 2634-2638
  5,   1,   1,   1,   1, // 2639-2643
  5,   1,   1,   1,   1, // 2644-2648
  4,   1,   1, // 2649-2651
  4,   1,   1, // 2652-2654
  4,   1,   1, // 2655-2657
  5,   1,   1, // 2658-2660
  4,   1,   1,   1, // 2661-2664
  6,   1,   1, // 2665-2667
  19,   1,   1, // 2668-2670
  8,   1,   1,   1, // 2671-2674
  7,   1,   1,   1, // 2675-2678
  7,   1,   1,   1, // 2679-2682
  5,   1,   1, // 2683-2685
  7,   1,   1, // 2686-2688
  5,   1,   1, // 2689-2691
  13,   1,   1,   1, // 2692-2695
  4,   1,   1,   1, // 2696-2699
  6,   1,   1, // 2700-2702
  6,   1,   1, // 2703-2705
  4,   1,   1, // 2706-2708
  4,   1,   1,   1, // 2709-2712
  7,   1,   1, // 2713-2715
  7,   1,   1, // 2716-2718
  7,   1,   1, // 2719-2721
  4,   1,   1, // 2722-2724
  4,   1,   1, // 2725-2727
  5,   1,   1, // 2728-2730
  5,   1,   1, // 2731-2733
  5,   1,   1, // 2734-2736
  5,   1,   1, // 2737-2739
  5,   1,   1, // 2740-2742
  5,   1,   1, // 2743-2745
  7,   1,   1,   1, // 2746-2749
  7,   1,   1,   1, // 2750-2753
  4,   1,   1, // 2754-2756
  5,   1,   1, // 2757-2759
  5,   1,   1, // 2760-2762
  4,   1,   1, // 2763-2765
  4,   1,   1, // 2766-2768
  4,   1,   1, // 2769-2771
  4,   1,   1,   1, // 2772-2775
  4,   1,   1, // 2776-2778
  6,   1,   1, // 2779-2781
  4,   1,   1, // 2782-2784
  4,   1,   1,   1, // 2785-2788
  4,   1,   1,   1, // 2789-2792
  4,   1,   1, // 2793-2795
  7,   1,   1,   1, // 2796-2799
  4,   1,   1, // 2800-2802
  4,   1,   1,   1, // 2803-2806
  5,   1,   1, // 2807-2809
  6,   1,   1, // 2810-2812
  5,   1,   1, // 2813-2815
  7,   1,   1,   1, // 2816-2819
  5,   1,   1, // 2820-2822
  7,   1,   1, // 2823-2825
  7,   1,   1, // 2826-2828
  7,   1,   1, // 2829-2831
  7,   1,   1,   1, // 2832-2835
  8,   1,   1,   1, // 2836-2839
  7,   1,   1,   1, // 2840-2843
  7,   1,   1, // 2844-2846
  7,   1,   1, // 2847-2849
  7,   1,   1,   1, // 2850-2853
  8,   1,   1,   1, // 2854-2857
  6,   1,   1, // 2858-2860
  5,   1,   1, // 2861-2863
  7,   1,   1,   1, // 2864-2867
  6,   1,   1, // 2868-2870
  6,   1,   1, // 2871-2873
  6,   1,   1, // 2874-2876
  6,   1,   1, // 2877-2879
  6,   1,   1, // 2880-2882
  5,   1,   1, // 2883-2885
  6,   1,   1, // 2886-2888
  5,   1,   1, // 2889-2891
  6,   1,   1, // 2892-2894
  4,   1,   1, // 2895-2897
  19,   1,   1, // 2898-2900
  19,   1,   1, // 2901-2903
  19,   1,   1, // 2904-2906
  19,   1,   1, // 2907-2909
  4,   1,   1,   1, // 2910-2913
  4,   1,   1, // 2914-2916
  7,   1,   1,   1, // 2917-2920
  4,   1,   1, // 2921-2923
  4,   1,   1, // 2924-2926
  4,   1,   1, // 2927-2929
  4,   1,   1, // 2930-2932
  13,   1,   1,   1, // 2933-2936
  13,   1,   1,   1, // 2937-2940
  13,   1,   1,   1, // 2941-2944
  13,   1,   1,   1, // 2945-2948
  5,   1,   1, // 2949-2951
  5,   1,   1, // 2952-2954
  6,   1,   1, // 2955-2957
  6,   1,   1, // 2958-2960
  4,   1,   1, // 2961-2963
  4,   1,   1, // 2964-2966
  6,   1,   1, // 2967-2969
  5,   1,   1, // 2970-2972
  4,   1,   1, // 2973-2975
  5,   1,   1, // 2976-2978
  7,   1,   1, // 2979-2981
  6,   1,   1, // 2982-2984
  5,   1,   1, // 2985-2987
  4,   1,   1, // 2988-2990
  6,   1,   1, // 2991-2993
  5,   1,   1, // 2994-2996
  4,   1,   1, // 2997-2999
  4,   1,   1, // 3000-3002
  4,   1,   1, // 3003-3005
  4,   1, // 3006-3007
  5,   1,   1, // 3008-3010
  4,   1,   1, // 3011-3013
  6,   1, // 3014-3015
  6,   1, // 3016-3017
  17,   1,   1, // 3018-3020
  9,   1,   1, // 3021-3023
  35,   1,   1, // 3024-3026
  7,   1,   1, // 3027-3029
  4,   1,   1, // 3030-3032
  7,   1,   1, // 3033-3035
  6,   1, // 3036-3037
  32,   1,   1, // 3038-3040
  6,   1, // 3041-3042
  4,   1,   1,   1, // 3043-3046
  6,   1,   1, // 3047-3049
  6,   1, // 3050-3051
  6,   1, // 3052-3053
  6,   1, // 3054-3055
  6,   1, // 3056-3057
  6,   1, // 3058-3059
  7,   1, // 3060-3061
  4,   1, // 3062-3063
  4,   1,   1, // 3064-3066
  8,   1, // 3067-3068
  4,   1, // 3069-3070
  7,   1, // 3071-3072
  8,   1, // 3073-3074
  7,   1, // 3075-3076
  7,   1, // 3077-3078
  7,   1, // 3079-3080
  4,   1, // 3081-3082
  5,   1, // 3083-3084
  4,   1, // 3085-3086
  5,   1, // 3087-3088
  7,   1,   1, // 3089-3091
  7,   1,   1, // 3092-3094
  7,   1,   1, // 3095-3097
  4,   1,   1, // 3098-3100
  4,   1,   1, // 3101-3103
  6,   1, // 3104-3105
  6,   1, // 3106-3107
  6,   1, // 3108-3109
  5,   1, // 3110-3111
  4,   1,   1, // 3112-3114
  4,   1, // 3115-3116
  5,   1,   1, // 3117-3119
  5,   1, // 3120-3121
  4,   1,   1, // 3122-3124
  4,   1,   1, // 3125-3127
  5,   1,   1, // 3128-3130
  4,   1,   1, // 3131-3133
  4,   1,   1, // 3134-3136
  4,   1, // 3137-3138
  4,   1,   1, // 3139-3141
  4,   1, // 3142-3143
  4,   1, // 3144-3145
  6,   1, // 3146-3147
  4,   1,   1, // 3148-3150
  8,   1, // 3151-3152
  4,   1,   1, // 3153-3155
  4,   1,   1, // 3156-3158
  4,   1,   1, // 3159-3161
  4,   1,   1, // 3162-3164
  4,   1,   1,   1, // 3165-3168
  4,   1, // 3169-3170
  6,   1, // 3171-3172
  6,   1, // 3173-3174
  4,   1,   1, // 3175-3177
  4,   1,   1, // 3178-3180
  7,   1,   1, // 3181-3183
  7,   1,   1, // 3184-3186
  7,   1,   1, // 3187-3189
  7,   1,   1, // 3190-3192
  7,   1,   1, // 3193-3195
  6,   1, // 3196-3197
  4,   1,   1, // 3198-3200
  6,   1, // 3201-3202
  6,   1, // 3203-3204
  6,   1, // 3205-3206
  6,   1, // 3207-3208
  6,   1, // 3209-3210
  6,   1,   1, // 3211-3213
  7,   1, // 3214-3215
  6,   1, // 3216-3217
  6,   1, // 3218-3219
  4,   1, // 3220-3221
  6,   1, // 3222-3223
  6,   1, // 3224-3225
  4,   1, // 3226-3227
  6,   1, // 3228-3229
  6,   1, // 3230-3231
  6,   1, // 3232-3233
  6,   1, // 3234-3235
  7,   1, // 3236-3237
  6,   1, // 3238-3239
  6,   1, // 3240-3241
  4,   1, // 3242-3243
  4,   1,   1, // 3244-3246
  7,   1, // 3247-3248
  4,   1, // 3249-3250
  7,   1, // 3251-3252
  4,   1, // 3253-3254
  7,   1, // 3255-3256
  5,   1, // 3257-3258
  4,   1, // 3259-3260
  17,   1,   1, // 3261-3263
  17,   1,   1, // 3264-3266
  17,   1,   1, // 3267-3269
  17,   1,   1, // 3270-3272
  4,   1,   1, // 3273-3275
  4,   1,   1, // 3276-3278
  4,   1, // 3279-3280
  4,   1,   1, // 3281-3283
  4,   1,   1, // 3284-3286
  4,   1,   1, // 3287-3289
  8,   1, // 3290-3291
  35,   1,   1, // 3292-3294
  35,   1,   1, // 3295-3297
  35,   1,   1, // 3298-3300
  32,   1,   1, // 3301-3303
  32,   1,   1, // 3304-3306
  32,   1,   1, // 3307-3309
  32,   1,   1, // 3310-3312
  35,   1,   1, // 3313-3315
  6,   1, // 3316-3317
  6,   1, // 3318-3319
  6,   1, // 3320-3321
  6,   1, // 3322-3323
  4,   1, // 3324-3325
  4,   1, // 3326-3327
  6,   1, // 3328-3329
  6,   1, // 3330-3331
  4,   1,   1, // 3332-3334
  4,   1,   1, // 3335-3337
  7,   1,   1, // 3338-3340
  6,   1, // 3341-3342
  6,   1, // 3343-3344
  4,   1, // 3345-3346
  6,   1, // 3347-3348
  6,   1, // 3349-3350
  7,   1, // 3351-3352
  5,   1, // 3353-3354
  4,   1, // 3355-3356
  4,   1, // 3357-3358
  4,   1,   1, // 3359-3361
  5,   1, // 3362-3363
  6,   1, // 3364-3365
  4,   1,   1, // 3366-3368
  4,   1,   1, // 3369-3371
  4,   1, // 3372-3373
  5,   1,   1, // 3374-3376
  4,   1,   1, // 3377-3379
  6,   1, // 3380-3381
  6,   1, // 3382-3383
  17,   1,   1, // 3384-3386
  13,   1,   1, // 3387-3389
  71,   1,   1, // 3390-3392
  11,   1,   1, // 3393-3395
  11,   1,   1, // 3396-3398
  6,   1, // 3399-3400
  41,   1,   1, // 3401-3403
  13,   1,   1,   1, // 3404-3407
  6,   1, // 3408-3409
  4,   1,   1,   1, // 3410-3413
  6,   1,   1, // 3414-3416
  6,   1, // 3417-3418
  6,   1, // 3419-3420
  7,   1,   1, // 3421-3423
  7,   1,   1, // 3424-3426
  7,   1,   1, // 3427-3429
  6,   1, // 3430-3431
  6,   1, // 3432-3433
  6,   1, // 3434-3435
  7,   1, // 3436-3437
  4,   1, // 3438-3439
  4,   1,   1, // 3440-3442
  8,   1, // 3443-3444
  4,   1, // 3445-3446
  11, // 3447
  7,   1, // 3448-3449
  8,   1, // 3450-3451
  7,   1, // 3452-3453
  7,   1, // 3454-3455
  7,   1, // 3456-3457
  4,   1, // 3458-3459
  11,   1,   1, // 3460-3462
  5,   1, // 3463-3464
  4,   1, // 3465-3466
  5,   1, // 3467-3468
  7,   1,   1, // 3469-3471
  7,   1,   1, // 3472-3474
  7,   1,   1, // 3475-3477
  6,   1,   1, // 3478-3480
  6,   1,   1, // 3481-3483
  4,   1,   1, // 3484-3486
  4,   1,   1, // 3487-3489
  6,   1, // 3490-3491
  6,   1, // 3492-3493
  6,   1, // 3494-3495
  5,   1, // 3496-3497
  4,   1, // 3498-3499
  11,   1,   1, // 3500-3502
  11, // 3503
  5,   1,   1, // 3504-3506
  5,   1, // 3507-3508
  11,   1,   1, // 3509-3511
  11,   1,   1, // 3512-3514
  4,   1,   1, // 3515-3517
  5,   1,   1, // 3518-3520
  4,   1,   1, // 3521-3523
  4,   1,   1, // 3524-3526
  4,   1, // 3527-3528
  4,   1,   1, // 3529-3531
  4,   1, // 3532-3533
  4,   1, // 3534-3535
  6,   1, // 3536-3537
  4,   1,   1, // 3538-3540
  8,   1, // 3541-3542
  4,   1,   1, // 3543-3545
  4,   1,   1, // 3546-3548
  4,   1,   1, // 3549-3551
  11,   1,   1, // 3552-3554
  4,   1,   1, // 3555-3557
  4,   1,   1,   1, // 3558-3561
  4,   1, // 3562-3563
  6,   1, // 3564-3565
  6,   1, // 3566-3567
  11,   1,   1, // 3568-3570
  7,   1,   1, // 3571-3573
  7,   1,   1, // 3574-3576
  7,   1,   1, // 3577-3579
  11,   1,   1, // 3580-3582
  13,   1,   1, // 3583-3585
  13,   1,   1,   1, // 3586-3589
  11,   1,   1, // 3590-3592
  7,   1,   1, // 3593-3595
  7,   1,   1, // 3596-3598
  11,   1,   1, // 3599-3601
  13,   1,   1, // 3602-3604
  13,   1,   1,   1, // 3605-3608
  6,   1, // 3609-3610
  11,   1,   1, // 3611-3613
  6,   1, // 3614-3615
  6,   1, // 3616-3617
  7,   1,   1, // 3618-3620
  6,   1, // 3621-3622
  6,   1, // 3623-3624
  6,   1, // 3625-3626
  6,   1,   1, // 3627-3629
  7,   1, // 3630-3631
  7,   1,   1, // 3632-3634
  6,   1, // 3635-3636
  6,   1, // 3637-3638
  4,   1, // 3639-3640
  6,   1, // 3641-3642
  6,   1, // 3643-3644
  4,   1, // 3645-3646
  7,   1,   1, // 3647-3649
  7,   1,   1, // 3650-3652
  7,   1,   1, // 3653-3655
  7,   1,   1, // 3656-3658
  6,   1, // 3659-3660
  6,   1, // 3661-3662
  7,   1,   1, // 3663-3665
  6,   1,   1, // 3666-3668
  6,   1, // 3669-3670
  6,   1, // 3671-3672
  7,   1, // 3673-3674
  6,   1, // 3675-3676
  6,   1,   1, // 3677-3679
  6,   1, // 3680-3681
  4,   1, // 3682-3683
  4,   1,   1, // 3684-3686
  7,   1, // 3687-3688
  4,   1, // 3689-3690
  7,   1, // 3691-3692
  4,   1, // 3693-3694
  7,   1, // 3695-3696
  5,   1, // 3697-3698
  4,   1, // 3699-3700
  17,   1,   1, // 3701-3703
  17,   1,   1, // 3704-3706
  17,   1,   1, // 3707-3709
  17,   1,   1, // 3710-3712
  4,   1,   1, // 3713-3715
  4,   1,   1, // 3716-3718
  11,   1,   1, // 3719-3721
  4,   1, // 3722-3723
  11, // 3724
  11,   1,   1, // 3725-3727
  4,   1,   1, // 3728-3730
  4,   1,   1, // 3731-3733
  4,   1,   1, // 3734-3736
  11, // 3737
  8,   1, // 3738-3739
  71,   1,   1, // 3740-3742
  71,   1,   1, // 3743-3745
  71,   1,   1, // 3746-3748
  41,   1,   1, // 3749-3751
  41,   1,   1, // 3752-3754
  41,   1,   1, // 3755-3757
  41,   1,   1, // 3758-3760
  71,   1,   1, // 3761-3763
  7,   1,   1, // 3764-3766
  7,   1,   1, // 3767-3769
  6,   1,   1, // 3770-3772
  6,   1, // 3773-3774
  6,   1, // 3775-3776
  6,   1, // 3777-3778
  6,   1, // 3779-3780
  7,   1,   1, // 3781-3783
  7,   1,   1, // 3784-3786
  4,   1, // 3787-3788
  4,   1, // 3789-3790
  6,   1, // 3791-3792
  6,   1, // 3793-3794
  4,   1,   1, // 3795-3797
  6,   1, // 3798-3799
  6,   1, // 3800-3801
  4,   1, // 3802-3803
  6,   1, // 3804-3805
  6,   1, // 3806-3807
  7,   1,   1, // 3808-3810
  6,   1,   1, // 3811-3813
  7,   1, // 3814-3815
  5,   1, // 3816-3817
  4,   1, // 3818-3819
  4,   1, // 3820-3821
  4,   1,   1, // 3822-3824
  5,   1, // 3825-3826
  6,   1, // 3827-3828
  5,   2,   2, // 3829-3831
  5,   2,   2, // 3832-3834
  5,   2, // 3835-3836
  6,   2,   2, // 3837-3839
  5,   2,   2, // 3840-3842
  7,   2, // 3843-3844
  7,   2, // 3845-3846
  7,   2, // 3847-3848
  30,   2,   2, // 3849-3851
  20,   2,   2, // 3852-3854
  11,   2,   2, // 3855-3857
  39,   2,   2, // 3858-3860
  11,   2,   2, // 3861-3863
  11,   2,   2, // 3864-3866
  7,   2, // 3867-3868
  5,   2,   2, // 3869-3871
  24,   2,   2, // 3872-3874
  11,   2,   2,   2, // 3875-3878
  7,   2, // 3879-3880
  5,   2,   2,   2, // 3881-3884
  7,   2,   2, // 3885-3887
  7,   2, // 3888-3889
  7,   2, // 3890-3891
  7,   2, // 3892-3893
  7,   2, // 3894-3895
  7,   2, // 3896-3897
  8,   2,   2, // 3898-3900
  8,   2,   2, // 3901-3903
  8,   2,   2, // 3904-3906
  7,   2, // 3907-3908
  7,   2, // 3909-3910
  7,   2, // 3911-3912
  8,   2, // 3913-3914
  9,   2,   2, // 3915-3917
  5,   2, // 3918-3919
  5,   2,   2, // 3920-3922
  9,   2, // 3923-3924
  5, // 3925
  11, // 3926
  9,   2, // 3927-3928
  8,   2, // 3929-3930
  8,   2, // 3931-3932
  5, // 3933
  11,   2,   2, // 3934-3936
  6,   2, // 3937-3938
  5, // 3939
  8,   2,   2, // 3940-3942
  8,   2,   2, // 3943-3945
  8,   2,   2, // 3946-3948
  7,   2,   2, // 3949-3951
  7,   2,   2, // 3952-3954
  6,   2,   2, // 3955-3957
  5,   2,   2, // 3958-3960
  6,   2,   2, // 3961-3963
  7,   2, // 3964-3965
  7,   2, // 3966-3967
  7,   2, // 3968-3969
  7,   2, // 3970-3971
  7,   2, // 3972-3973
  6,   2, // 3974-3975
  5, // 3976
  11,   2,   2, // 3977-3979
  11, // 3980
  6,   2,   2, // 3981-3983
  6,   2, // 3984-3985
  11,   2,   2, // 3986-3988
  11,   2,   2, // 3989-3991
  5,   2,   2, // 3992-3994
  6,   2,   2, // 3995-3997
  5,   2,   2, // 3998-4000
  6,   2,   2, // 4001-4003
  5,   2,   2, // 4004-4006
  5,   2,   2, // 4007-4009
  5,   2, // 4010-4011
  5,   2,   2, // 4012-4014
  5,   2, // 4015-4016
  5, // 4017
  7,   2, // 4018-4019
  6,   2,   2, // 4020-4022
  5,   2,   2, // 4023-4025
  5,   2,   2, // 4026-4028
  9,   2, // 4029-4030
  5,   2,   2, // 4031-4033
  5,   2,   2, // 4034-4036
  5,   2,   2, // 4037-4039
  11,   2,   2, // 4040-4042
  6,   2,   2, // 4043-4045
  5,   2,   2,   2, // 4046-4049
  5, // 4050
  7,   2, // 4051-4052
  7,   2, // 4053-4054
  11,   2,   2, // 4055-4057
  9,   2,   2, // 4058-4060
  8,   2,   2, // 4061-4063
  8,   2,   2, // 4064-4066
  8,   2,   2, // 4067-4069
  11,   2,   2, // 4070-4072
  11,   2,   2, // 4073-4075
  11,   2,   2,   2, // 4076-4079
  11,   2,   2, // 4080-4082
  8,   2,   2, // 4083-4085
  8,   2,   2, // 4086-4088
  9,   2,   2, // 4089-4091
  11,   2,   2, // 4092-4094
  11,   2,   2, // 4095-4097
  11,   2,   2,   2, // 4098-4101
  7,   2, // 4102-4103
  11,   2,   2, // 4104-4106
  7,   2, // 4107-4108
  7,   2, // 4109-4110
  8,   2,   2, // 4111-4113
  7,   2, // 4114-4115
  7,   2, // 4116-4117
  7,   2, // 4118-4119
  7,   2,   2, // 4120-4122
  7,   2, // 4123-4124
  7,   2, // 4125-4126
  8,   2, // 4127-4128
  8,   2,   2, // 4129-4131
  7,   2, // 4132-4133
  7,   2, // 4134-4135
  5, // 4136
  7,   2, // 4137-4138
  7,   2, // 4139-4140
  7,   2, // 4141-4142
  7,   2, // 4143-4144
  5, // 4145
  8,   2,   2, // 4146-4148
  8,   2,   2, // 4149-4151
  8,   2,   2, // 4152-4154
  8,   2,   2, // 4155-4157
  7,   2, // 4158-4159
  7,   2, // 4160-4161
  8,   2,   2, // 4162-4164
  7,   2,   2, // 4165-4167
  7,   2, // 4168-4169
  7,   2, // 4170-4171
  7,   2, // 4172-4173
  8,   2, // 4174-4175
  7,   2, // 4176-4177
  7,   2,   2, // 4178-4180
  7,   2, // 4181-4182
  5, // 4183
  5,   2,   2, // 4184-4186
  8,   2, // 4187-4188
  5, // 4189
  8,   2, // 4190-4191
  5, // 4192
  6,   2, // 4193-4194
  5, // 4195
  20,   2,   2, // 4196-4198
  20,   2,   2, // 4199-4201
  30,   2,   2, // 4202-4204
  30,   2,   2, // 4205-4207
  20,   2,   2, // 4208-4210
  30,   2,   2, // 4211-4213
  20,   2,   2, // 4214-4216
  30,   2,   2, // 4217-4219
  5,   2,   2, // 4220-4222
  5,   2,   2, // 4223-4225
  11,   2,   2, // 4226-4228
  5,   2, // 4229-4230
  11, // 4231
  11,   2,   2, // 4232-4234
  6,   2,   2, // 4235-4237
  5,   2,   2, // 4238-4240
  5,   2,   2, // 4241-4243
  5,   2,   2, // 4244-4246
  6,   2,   2, // 4247-4249
  11, // 4250
  9,   2, // 4251-4252
  5,   2,   2, // 4253-4255
  6,   2,   2, // 4256-4258
  39,   2,   2, // 4259-4261
  39,   2,   2, // 4262-4264
  39,   2,   2, // 4265-4267
  24,   2,   2, // 4268-4270
  24,   2,   2, // 4271-4273
  24,   2,   2, // 4274-4276
  24,   2,   2, // 4277-4279
  39,   2,   2, // 4280-4282
  8,   2,   2, // 4283-4285
  8,   2,   2, // 4286-4288
  7,   2,   2, // 4289-4291
  7,   2, // 4292-4293
  7,   2, // 4294-4295
  7,   2, // 4296-4297
  7,   2, // 4298-4299
  7,   2, // 4300-4301
  7,   2, // 4302-4303
  8,   2,   2, // 4304-4306
  8,   2,   2, // 4307-4309
  5,   2, // 4310-4311
  5,   2, // 4312-4313
  7,   2, // 4314-4315
  7,   2, // 4316-4317
  5,   2,   2, // 4318-4320
  7,   2, // 4321-4322
  7,   2, // 4323-4324
  5,   2, // 4325-4326
  7,   2, // 4327-4328
  7,   2, // 4329-4330
  8,   2,   2, // 4331-4333
  7,   2,   2, // 4334-4336
  5, // 4337
  5, // 4338
  5,   2,   2, // 4339-4341
  6,   2, // 4342-4343
  7,   2, // 4344-4345
  1,   1,   1, // 4346-4348
  1,   1,   1, // 4349-4351
  3,   1,   1, // 4352-4354
  6,   1,   1, // 4355-4357
  1,   1,   1, // 4358-4360
  3,   1,   1, // 4361-4363
  2,   1,   1, // 4364-4366
  2,   1,   1, // 4367-4369
  23,   1,   1, // 4370-4372
  15,   1,   1, // 4373-4375
  5,   1,   1, // 4376-4378
  33,   1,   1, // 4379-4381
  8,   1,   1, // 4382-4384
  5,   1,   1, // 4385-4387
  2,   1,   1, // 4388-4390
  7,   1,   1, // 4391-4393
  1,   1,   1, // 4394-4396
  1,   1,   1, // 4397-4399
  27,   1,   1, // 4400-4402
  5,   1,   1,   1, // 4403-4406
  44,   1,   1, // 4407-4409
  32,   1,   1, // 4410-4412
  1,   1,   1,   1, // 4413-4416
  3,   1,   1, // 4417-4419
  2,   2,   1,   1, // 4420-4423
  3,   3,   1,   1, // 4424-4427
  3,   1,   1, // 4428-4430
  2,   2,   1,   1, // 4431-4434
  3,   3,   1,   1, // 4435-4438
  3,   1,   1, // 4439-4441
  3,   3,   1,   1, // 4442-4445
  3,   3,   1,   1, // 4446-4449
  3,   1,   1, // 4450-4452
  4,   4,   1,   1, // 4453-4456
  4,   4,   1,   1, // 4457-4460
  2,   1,   1, // 4461-4463
  3,   1,   1, // 4464-4466
  4,   1,   1, // 4467-4469
  3,   1,   1, // 4470-4472
  3,   1, // 4473-4474
  6,   1, // 4475-4476
  3,   1, // 4477-4478
  4,   1, // 4479-4480
  4,   1,   1, // 4481-4483
  4,   1,   1, // 4484-4486
  4,   1,   1, // 4487-4489
  3,   1,   1, // 4490-4492
  1,   1,   1, // 4493-4495
  2,   1,   1,   1, // 4496-4499
  1,   1,   1, // 4500-4502
  1,   1,   1, // 4503-4505
  1,   1,   1, // 4506-4508
  1,   1,   1, // 4509-4511
  2,   1,   1,   1, // 4512-4515
  2,   1,   1,   1, // 4516-4519
  1,   1,   1, // 4520-4522
  1,   1, // 4523-4524
  1,   1, // 4525-4526
  6,   1,   1, // 4527-4529
  2,   1,   1, // 4530-4532
  6,   1,   1, // 4533-4535
  3,   1,   1, // 4536-4538
  4,   1, // 4539-4540
  1,   1,   1, // 4541-4543
  1,   1, // 4544-4545
  1,   1, // 4546-4547
  8,   1,   1, // 4548-4550
  6,   1,   1, // 4551-4553
  6,   1,   1, // 4554-4556
  8,   1,   1, // 4557-4559
  1,   1,   1, // 4560-4562
  1,   1,   1, // 4563-4565
  1,   1,   1, // 4566-4568
  2,   1,   1, // 4569-4571
  1,   1,   1, // 4572-4574
  1,   1,   1, // 4575-4577
  1,   1,   1, // 4578-4580
  3,   1,   1, // 4581-4583
  3,   1, // 4584-4585
  6,   1,   1, // 4586-4588
  3,   1,   1, // 4589-4591
  4,   1, // 4592-4593
  2,   1,   1, // 4594-4596
  1,   1,   1, // 4597-4599
  1,   1,   1, // 4600-4602
  1,   1,   1, // 4603-4605
  3,   1, // 4606-4607
  3,   1, // 4608-4609
  3,   1,   1, // 4610-4612
  1,   1,   1, // 4613-4615
  5,   1,   1, // 4616-4618
  1,   1,   1, // 4619-4621
  1,   1,   1,   1, // 4622-4625
  6,   1,   1, // 4626-4628
  4,   1, // 4629-4630
  1,   1,   1, // 4631-4633
  2,   1,   1, // 4634-4636
  6,   1,   1, // 4637-4639
  2,   1,   1, // 4640-4642
  6,   1,   1, // 4643-4645
  8,   1,   1, // 4646-4648
  6,   1,   1, // 4649-4651
  2,   1,   1, // 4652-4654
  4,   1,   1, // 4655-4657
  4,   1,   1, // 4658-4660
  4,   1,   1, // 4661-4663
  4,   1,   1, // 4664-4666
  5,   1,   1, // 4667-4669
  5,   1,   1, // 4670-4672
  5,   1,   1,   1, // 4673-4676
  6,   1,   1, // 4677-4679
  5,   1,   1, // 4680-4682
  4,   1,   1, // 4683-4685
  4,   1,   1, // 4686-4688
  4,   1,   1, // 4689-4691
  5,   1,   1, // 4692-4694
  5,   1,   1, // 4695-4697
  5,   1,   1,   1, // 4698-4701
  6,   1,   1, // 4702-4704
  2,   1,   1, // 4705-4707
  3,   1,   1, // 4708-4710
  6,   1,   1, // 4711-4713
  2,   1,   1, // 4714-4716
  8,   1,   1, // 4717-4719
  6,   1,   1, // 4720-4722
  6,   1,   1, // 4723-4725
  6,   1,   1, // 4726-4728
  6,   1,   1, // 4729-4731
  6,   1,   1, // 4732-4734
  6,   1,   1, // 4735-4737
  2,   1,   1, // 4738-4740
  2,   1,   1, // 4741-4743
  3,   1,   1, // 4744-4746
  2,   1,   1, // 4747-4749
  3,   1,   1, // 4750-4752
  2,   1,   1, // 4753-4755
  3,   1,   1, // 4756-4758
  2,   1,   1, // 4759-4761
  3,   1,   1, // 4762-4764
  2,   2,   1,   1, // 4765-4768
  3,   3,   1,   1, // 4769-4772
  4,   1, // 4773-4774
  1,   1,   1, // 4775-4777
  1,   1,   1, // 4778-4780
  2,   1,   1, // 4781-4783
  3,   1,   1, // 4784-4786
  3,   1,   1, // 4787-4789
  4,   1, // 4790-4791
  3,   1,   1, // 4792-4794
  3,   1,   1, // 4795-4797
  3,   1,   1, // 4798-4800
  3,   1,   1, // 4801-4803
  4,   4,   1,   1, // 4804-4807
  4,   4,   1,   1, // 4808-4811
  3,   1,   1, // 4812-4814
  1,   1,   1, // 4815-4817
  1,   1,   1, // 4818-4820
  2,   1,   1, // 4821-4823
  2,   1,   1, // 4824-4826
  1,   1,   1, // 4827-4829
  1,   1,   1, // 4830-4832
  2,   1,   1, // 4833-4835
  4,   1, // 4836-4837
  1,   1,   1, // 4838-4840
  4,   1, // 4841-4842
  15,   1,   1, // 4843-4845
  15,   1,   1, // 4846-4848
  23,   1,   1, // 4849-4851
  23,   1,   1, // 4852-4854
  15,   1,   1, // 4855-4857
  23,   1,   1, // 4858-4860
  15,   1,   1, // 4861-4863
  23,   1,   1, // 4864-4866
  3,   1, // 4867-4868
  1,   1,   1, // 4869-4871
  5,   1,   1, // 4872-4874
  3,   1,   1, // 4875-4877
  1,   1,   1, // 4878-4880
  1,   1,   1, // 4881-4883
  1,   1,   1, // 4884-4886
  1,   1,   1, // 4887-4889
  1,   1,   1, // 4890-4892
  6,   1, // 4893-4894
  1,   1,   1, // 4895-4897
  1,   1,   1, // 4898-4900
  33,   1,   1, // 4901-4903
  33,   1,   1, // 4904-4906
  44,   1,   1, // 4907-4909
  44,   1,   1, // 4910-4912
  44,   1,   1, // 4913-4915
  32,   1,   1, // 4916-4918
  44,   1,   1, // 4919-4921
  32,   1,   1, // 4922-4924
  32,   1,   1, // 4925-4927
  32,   1,   1, // 4928-4930
  33,   1,   1, // 4931-4933
  27,   1,   1, // 4934-4936
  27,   1,   1, // 4937-4939
  27,   1,   1, // 4940-4942
  27,   1,   1, // 4943-4945
  33,   1,   1, // 4946-4948
  3,   3,   1,   1, // 4949-4952
  3,   3,   1,   1, // 4953-4956
  2,   1,   1,   1, // 4957-4960
  2,   1,   1,   1, // 4961-4964
  2,   1,   1,   1, // 4965-4968
  2,   2,   1,   1, // 4969-4972
  3,   3,   1,   1, // 4973-4976
  2,   2,   1,   1, // 4977-4980
  3,   3,   1,   1, // 4981-4984
  3,   3,   1,   1, // 4985-4988
  3,   3,   1,   1, // 4989-4992
  6,   1,   1, // 4993-4995
  3,   1,   1, // 4996-4998
  3,   1,   1, // 4999-5001
  2,   1,   1, // 5002-5004
  1,   1,   1, // 5005-5007
  1,   1,   1, // 5008-5010
  2,   1,   1, // 5011-5013
  7,   1,   1, // 5014-5016
  2,   1,   1, // 5017-5019
  1,   1,   1, // 5020-5022
  3,   1,   1, // 5023-5025
  2,   1,   1, // 5026-5028
  1,   1,   1, // 5029-5031
  3,   1,   1, // 5032-5034
  1,   1,   1, // 5035-5037
  4,   1, // 5038-5039
  1,   1,   1, // 5040-5042
  1,   1,   1, // 5043-5045
  1,   1,   1, // 5046-5048
  3,   1,   1, // 5049-5051
  6,   1,   1, // 5052-5054
  1,   1,   1, // 5055-5057
  3,   1,   1, // 5058-5060
  2,   1,   1, // 5061-5063
  2,   1,   1, // 5064-5066
  68,   1,   1, // 5067-5069
  36,   1,   1, // 5070-5072
  5,   1,   1, // 5073-5075
  33,   1,   1, // 5076-5078
  8,   1,   1, // 5079-5081
  5,   1,   1, // 5082-5084
  2,   1,   1, // 5085-5087
  7,   1,   1, // 5088-5090
  1,   1,   1, // 5091-5093
  1,   1,   1, // 5094-5096
  27,   1,   1, // 5097-5099
  5,   1,   1,   1, // 5100-5103
  44,   1,   1, // 5104-5106
  32,   1,   1, // 5107-5109
  1,   1,   1,   1, // 5110-5113
  3,   1,   1, // 5114-5116
  2,   2,   1,   1, // 5117-5120
  3,   3,   1,   1, // 5121-5124
  3,   1,   1, // 5125-5127
  2,   2,   1,   1, // 5128-5131
  3,   3,   1,   1, // 5132-5135
  3,   1,   1, // 5136-5138
  3,   3,   1,   1, // 5139-5142
  3,   3,   1,   1, // 5143-5146
  3,   1,   1, // 5147-5149
  4,   4,   1,   1, // 5150-5153
  4,   4,   1,   1, // 5154-5157
  2,   1,   1, // 5158-5160
  3,   1,   1, // 5161-5163
  4,   1,   1, // 5164-5166
  3,   1,   1, // 5167-5169
  3,   1, // 5170-5171
  6,   1, // 5172-5173
  3,   1, // 5174-5175
  4,   1, // 5176-5177
  4,   1,   1, // 5178-5180
  4,   1,   1, // 5181-5183
  4,   1,   1, // 5184-5186
  3,   1,   1, // 5187-5189
  1,   1,   1, // 5190-5192
  2,   1,   1,   1, // 5193-5196
  1,   1,   1, // 5197-5199
  1,   1,   1, // 5200-5202
  1,   1,   1, // 5203-5205
  1,   1,   1, // 5206-5208
  2,   1,   1,   1, // 5209-5212
  2,   1,   1,   1, // 5213-5216
  1,   1,   1, // 5217-5219
  1,   1,   1, // 5220-5222
  1,   1, // 5223-5224
  1,   1, // 5225-5226
  6,   1,   1, // 5227-5229
  2,   1,   1, // 5230-5232
  6,   1,   1, // 5233-5235
  3,   1,   1, // 5236-5238
  4,   1, // 5239-5240
  1,   1,   1, // 5241-5243
  1,   1, // 5244-5245
  1,   1, // 5246-5247
  8,   1,   1, // 5248-5250
  6,   1,   1, // 5251-5253
  6,   1,   1, // 5254-5256
  8,   1,   1, // 5257-5259
  1,   1,   1, // 5260-5262
  1,   1,   1, // 5263-5265
  1,   1,   1, // 5266-5268
  2,   1,   1, // 5269-5271
  1,   1,   1, // 5272-5274
  1,   1,   1, // 5275-5277
  1,   1,   1, // 5278-5280
  3,   1,   1, // 5281-5283
  3,   1, // 5284-5285
  6,   1,   1, // 5286-5288
  3,   1,   1, // 5289-5291
  4,   1, // 5292-5293
  2,   1,   1, // 5294-5296
  1,   1,   1, // 5297-5299
  1,   1,   1, // 5300-5302
  1,   1,   1, // 5303-5305
  3,   1, // 5306-5307
  3,   1, // 5308-5309
  3,   1,   1, // 5310-5312
  1,   1,   1, // 5313-5315
  5,   1,   1, // 5316-5318
  1,   1,   1, // 5319-5321
  1,   1,   1,   1, // 5322-5325
  6,   1,   1, // 5326-5328
  4,   1, // 5329-5330
  1,   1,   1, // 5331-5333
  2,   1,   1, // 5334-5336
  6,   1,   1, // 5337-5339
  2,   1,   1, // 5340-5342
  6,   1,   1, // 5343-5345
  8,   1,   1, // 5346-5348
  6,   1,   1, // 5349-5351
  2,   1,   1, // 5352-5354
  4,   1,   1, // 5355-5357
  4,   1,   1, // 5358-5360
  4,   1,   1, // 5361-5363
  4,   1,   1, // 5364-5366
  5,   1,   1, // 5367-5369
  5,   1,   1, // 5370-5372
  5,   1,   1,   1, // 5373-5376
  6,   1,   1, // 5377-5379
  5,   1,   1, // 5380-5382
  4,   1,   1, // 5383-5385
  4,   1,   1, // 5386-5388
  4,   1,   1, // 5389-5391
  5,   1,   1, // 5392-5394
  5,   1,   1, // 5395-5397
  5,   1,   1,   1, // 5398-5401
  6,   1,   1, // 5402-5404
  2,   1,   1, // 5405-5407
  3,   1,   1, // 5408-5410
  6,   1,   1, // 5411-5413
  2,   1,   1, // 5414-5416
  8,   1,   1, // 5417-5419
  6,   1,   1, // 5420-5422
  6,   1,   1, // 5423-5425
  6,   1,   1, // 5426-5428
  6,   1,   1, // 5429-5431
  6,   1,   1, // 5432-5434
  6,   1,   1, // 5435-5437
  2,   1,   1, // 5438-5440
  2,   1,   1, // 5441-5443
  3,   1,   1, // 5444-5446
  2,   1,   1, // 5447-5449
  3,   1,   1, // 5450-5452
  2,   1,   1, // 5453-5455
  3,   1,   1, // 5456-5458
  2,   1,   1, // 5459-5461
  3,   1,   1, // 5462-5464
  2,   2,   1,   1, // 5465-5468
  3,   3,   1,   1, // 5469-5472
  4,   1, // 5473-5474
  1,   1,   1, // 5475-5477
  1,   1,   1, // 5478-5480
  2,   1,   1, // 5481-5483
  3,   1,   1, // 5484-5486
  3,   1,   1, // 5487-5489
  4,   1, // 5490-5491
  3,   1,   1, // 5492-5494
  3,   1,   1, // 5495-5497
  3,   1,   1, // 5498-5500
  3,   1,   1, // 5501-5503
  4,   4,   1,   1, // 5504-5507
  4,   4,   1,   1, // 5508-5511
  3,   1,   1, // 5512-5514
  1,   1,   1, // 5515-5517
  1,   1,   1, // 5518-5520
  1,   1,   1, // 5521-5523
  2,   1,   1, // 5524-5526
  2,   1,   1, // 5527-5529
  1,   1,   1, // 5530-5532
  1,   1,   1, // 5533-5535
  2,   1,   1, // 5536-5538
  4,   1, // 5539-5540
  1,   1,   1, // 5541-5543
  4,   1, // 5544-5545
  36,   1,   1, // 5546-5548
  36,   1,   1, // 5549-5551
  68,   1,   1, // 5552-5554
  68,   1,   1, // 5555-5557
  36,   1,   1, // 5558-5560
  68,   1,   1, // 5561-5563
  36,   1,   1, // 5564-5566
  68,   1,   1, // 5567-5569
  3,   1, // 5570-5571
  1,   1,   1, // 5572-5574
  5,   1,   1, // 5575-5577
  3,   1,   1, // 5578-5580
  1,   1,   1, // 5581-5583
  1,   1,   1, // 5584-5586
  1,   1,   1, // 5587-5589
  1,   1,   1, // 5590-5592
  1,   1,   1, // 5593-5595
  6,   1, // 5596-5597
  1,   1,   1, // 5598-5600
  1,   1,   1, // 5601-5603
  33,   1,   1, // 5604-5606
  33,   1,   1, // 5607-5609
  44,   1,   1, // 5610-5612
  44,   1,   1, // 5613-5615
  44,   1,   1, // 5616-5618
  32,   1,   1, // 5619-5621
  44,   1,   1, // 5622-5624
  32,   1,   1, // 5625-5627
  32,   1,   1, // 5628-5630
  32,   1,   1, // 5631-5633
  33,   1,   1, // 5634-5636
  27,   1,   1, // 5637-5639
  27,   1,   1, // 5640-5642
  27,   1,   1, // 5643-5645
  27,   1,   1, // 5646-5648
  33,   1,   1, // 5649-5651
  3,   3,   1,   1, // 5652-5655
  3,   3,   1,   1, // 5656-5659
  2,   1,   1,   1, // 5660-5663
  2,   1,   1,   1, // 5664-5667
  2,   1,   1,   1, // 5668-5671
  2,   2,   1,   1, // 5672-5675
  3,   3,   1,   1, // 5676-5679
  2,   2,   1,   1, // 5680-5683
  3,   3,   1,   1, // 5684-5687
  3,   3,   1,   1, // 5688-5691
  3,   3,   1,   1, // 5692-5695
  6,   1,   1, // 5696-5698
  3,   1,   1, // 5699-5701
  3,   1,   1, // 5702-5704
  2,   1,   1, // 5705-5707
  1,   1,   1, // 5708-5710
  1,   1,   1, // 5711-5713
  2,   1,   1, // 5714-5716
  7,   1,   1, // 5717-5719
  2,   1,   1, // 5720-5722
  1,   1,   1, // 5723-5725
  3,   1,   1, // 5726-5728
  2,   1,   1, // 5729-5731
  1,   1,   1, // 5732-5734
  3,   1,   1, // 5735-5737
  1,   1,   1, // 5738-5740
  4,   1, // 5741-5742
  1,   1,   1, // 5743-5745
  0 // End operand cycles
};
extern const unsigned PPCForwardingPaths[] = {
 0, // No itinerary
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 1-3
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 4-6
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 7-8
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 9-11
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 12-14
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 15-16
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 17-19
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 20-22
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 23-25
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 26-28
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 29-31
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 32-34
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 35-37
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 38-40
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 41-44
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 45-47
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::NoBypass, // 48-51
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 52-54
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0,  0, // 55-58
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0,  0, // 59-62
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 63-65
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 66-69
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 70-73
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 74-76
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 77-79
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 80-82
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 83-85
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 86-88
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 89-91
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 92-93
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 94-95
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 96-98
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 99-100
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 101-102
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 103-104
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 105-106
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 107-109
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 110-111
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 112-113
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 114-116
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 117-119
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 120-122
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 123-125
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 126-129
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 130-131
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 132-134
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 135-137
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 138-140
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0,  0, // 141-144
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0,  0, // 145-148
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 149-151
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 152-154
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 155-156
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 157-158
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 159-161
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 162-164
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 165-167
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 168-169
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 170-172
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 173-175
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 176-178
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 179-181
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 182-184
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 185-187
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 188-190
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 191-193
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 194-195
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 196-197
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 198-200
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 201-203
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 204-206
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 207-209
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 210-212
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 213-215
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 216-218
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::NoBypass, // 219-222
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 223-224
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 225-227
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 228-230
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 231-233
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 234-236
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 237-239
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 240-242
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 243-245
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 246-248
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 249-252
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 253-255
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 256-258
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 259-261
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 262-264
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 265-267
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 268-271
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 272-274
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 275-277
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 278-280
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 281-283
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 284-286
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 287-288
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 289-291
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 292-294
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 295-297
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 298-300
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 301-303
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0,  0, // 304-307
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0,  0, // 308-311
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 312-313
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 314-316
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 317-319
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 320-322
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 323-324
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 325-327
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 328-330
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 331-333
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 334-336
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 337-339
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 340-342
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 343-345
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 346-348
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 349-351
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 352-354
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 355-357
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 358-360
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 361-363
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 364-366
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 367-369
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 370-371
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 372-374
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 375-376
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 377-378
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 379-380
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 381-382
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 383-384
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 385-387
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 388-390
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 391-393
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 394-396
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 397-399
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 400-402
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 403-405
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 406-408
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 409-411
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 412-414
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 415-417
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 418-420
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 421-423
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 424-426
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 427-428
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 429-431
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 432-434
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 435-437
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 438-440
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 441-443
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 444-446
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 447-449
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 450-452
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 453-456
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 457-460
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 461-464
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0,  0, // 465-468
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0,  0, // 469-472
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0,  0, // 473-476
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0,  0, // 477-480
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 481-484
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 485-488
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 489-490
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 491-492
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 493-495
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 496-498
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 499-501
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 502-504
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 505-507
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 508-509
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 510-511
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 512-514
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 515-517
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 518-520
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 521-523
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 524-525
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 526-527
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 528-529
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 530-531
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 532-534
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 535-536
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 537-538
 0, // 539
 0,  0,  0, // 540-542
 0,  0,  0, // 543-545
 0,  0,  0, // 546-548
 0,  0,  0, // 549-551
 0,  0,  0, // 552-554
 0,  0,  0, // 555-557
 0,  0,  0, // 558-560
 0,  0,  0, // 561-563
 0,  0,  0, // 564-566
 0,  0,  0, // 567-569
 0,  0,  0, // 570-572
 0,  0,  0, // 573-575
 0,  0,  0, // 576-578
 0,  0,  0, // 579-581
 0,  0,  0, // 582-584
 0,  0,  0, // 585-587
 0,  0,  0,  0, // 588-591
 0,  0,  0, // 592-594
 0,  0,  0, // 595-597
 0,  0,  0, // 598-600
 0,  0,  0,  0, // 601-604
 0, // 605
 0,  0,  0, // 606-608
 0,  0,  0,  0, // 609-612
 0,  0,  0,  0, // 613-616
 0,  0,  0, // 617-619
 0,  0,  0, // 620-622
 0,  0,  0, // 623-625
 0,  0,  0,  0, // 626-629
 0,  0,  0,  0, // 630-633
 0,  0,  0, // 634-636
 0,  0,  0,  0, // 637-640
 0,  0,  0,  0, // 641-644
 0,  0,  0, // 645-647
 0,  0,  0, // 648-650
 0,  0, // 651-652
 0,  0, // 653-654
 0,  0, // 655-656
 0,  0, // 657-658
 0,  0, // 659-660
 0,  0, // 661-662
 0,  0, // 663-664
 0,  0,  0, // 665-667
 0,  0,  0, // 668-670
 0,  0,  0, // 671-673
 0,  0,  0, // 674-676
 0,  0,  0,  0, // 677-680
 0, // 681
 0,  0,  0, // 682-684
 0,  0,  0, // 685-687
 0,  0,  0, // 688-690
 0,  0,  0, // 691-693
 0,  0,  0,  0, // 694-697
 0,  0,  0,  0, // 698-701
 0,  0,  0, // 702-704
 0,  0,  0, // 705-707
 0,  0, // 708-709
 0,  0, // 710-711
 0,  0, // 712-713
 0,  0,  0, // 714-716
 0,  0, // 717-718
 0,  0, // 719-720
 0,  0,  0, // 721-723
 0,  0,  0, // 724-726
 0,  0,  0, // 727-729
 0,  0,  0, // 730-732
 0,  0,  0, // 733-735
 0,  0,  0, // 736-738
 0,  0,  0, // 739-741
 0,  0,  0, // 742-744
 0,  0,  0, // 745-747
 0,  0,  0, // 748-750
 0,  0,  0, // 751-753
 0,  0, // 754-755
 0,  0,  0, // 756-758
 0,  0,  0, // 759-761
 0,  0,  0, // 762-764
 0,  0,  0, // 765-767
 0,  0, // 768-769
 0,  0,  0, // 770-772
 0,  0,  0, // 773-775
 0,  0,  0, // 776-778
 0,  0,  0, // 779-781
 0,  0,  0, // 782-784
 0,  0,  0,  0, // 785-788
 0,  0, // 789-790
 0,  0,  0, // 791-793
 0,  0,  0, // 794-796
 0,  0,  0, // 797-799
 0,  0,  0, // 800-802
 0,  0,  0, // 803-805
 0,  0,  0, // 806-808
 0,  0,  0, // 809-811
 0,  0,  0, // 812-814
 0,  0,  0,  0, // 815-818
 0,  0,  0, // 819-821
 0,  0,  0, // 822-824
 0,  0,  0, // 825-827
 0,  0,  0, // 828-830
 0,  0,  0, // 831-833
 0,  0,  0,  0, // 834-837
 0,  0,  0, // 838-840
 0,  0,  0, // 841-843
 0,  0,  0, // 844-846
 0,  0,  0, // 847-849
 0,  0,  0, // 850-852
 0,  0,  0, // 853-855
 0,  0,  0, // 856-858
 0,  0,  0, // 859-861
 0,  0,  0, // 862-864
 0, // 865
 0, // 866
 0,  0,  0, // 867-869
 0,  0,  0,  0, // 870-873
 0,  0,  0,  0, // 874-877
 0,  0, // 878-879
 0,  0,  0, // 880-882
 0,  0,  0, // 883-885
 0,  0,  0, // 886-888
 0,  0, // 889-890
 0,  0,  0, // 891-893
 0,  0,  0, // 894-896
 0,  0,  0, // 897-899
 0,  0,  0, // 900-902
 0,  0,  0,  0, // 903-906
 0,  0,  0,  0, // 907-910
 0,  0,  0, // 911-913
 0,  0,  0, // 914-916
 0,  0,  0, // 917-919
 0,  0,  0, // 920-922
 0,  0,  0, // 923-925
 0,  0,  0, // 926-928
 0,  0,  0, // 929-931
 0,  0,  0, // 932-934
 0,  0, // 935-936
 0,  0,  0, // 937-939
 0,  0, // 940-941
 0,  0, // 942-943
 0,  0, // 944-945
 0,  0, // 946-947
 0,  0, // 948-949
 0,  0,  0, // 950-952
 0,  0,  0, // 953-955
 0,  0,  0, // 956-958
 0,  0,  0, // 959-961
 0,  0,  0, // 962-964
 0,  0,  0, // 965-967
 0,  0,  0, // 968-970
 0,  0,  0, // 971-973
 0,  0,  0, // 974-976
 0,  0,  0, // 977-979
 0,  0,  0, // 980-982
 0,  0,  0, // 983-985
 0,  0,  0, // 986-988
 0,  0,  0, // 989-991
 0,  0,  0, // 992-994
 0,  0,  0, // 995-997
 0,  0,  0, // 998-1000
 0,  0, // 1001-1002
 0,  0,  0, // 1003-1005
 0,  0,  0, // 1006-1008
 0,  0,  0, // 1009-1011
 0,  0,  0, // 1012-1014
 0,  0,  0, // 1015-1017
 0,  0,  0, // 1018-1020
 0,  0,  0, // 1021-1023
 0,  0,  0, // 1024-1026
 0,  0,  0, // 1027-1029
 0,  0,  0, // 1030-1032
 0,  0,  0, // 1033-1035
 0,  0,  0, // 1036-1038
 0,  0,  0, // 1039-1041
 0,  0,  0, // 1042-1044
 0,  0,  0, // 1045-1047
 0,  0,  0, // 1048-1050
 0,  0,  0, // 1051-1053
 0,  0,  0, // 1054-1056
 0,  0,  0,  0, // 1057-1060
 0,  0,  0,  0, // 1061-1064
 0,  0,  0,  0, // 1065-1068
 0,  0,  0,  0, // 1069-1072
 0,  0,  0,  0, // 1073-1076
 0,  0,  0,  0, // 1077-1080
 0,  0,  0,  0, // 1081-1084
 0,  0,  0, // 1085-1087
 0,  0,  0, // 1088-1090
 0,  0,  0,  0, // 1091-1094
 0,  0,  0,  0, // 1095-1098
 0,  0,  0, // 1099-1101
 0,  0,  0, // 1102-1104
 0,  0,  0, // 1105-1107
 0,  0,  0, // 1108-1110
 0,  0,  0, // 1111-1113
 0,  0,  0, // 1114-1116
 0,  0,  0, // 1117-1119
 0,  0,  0, // 1120-1122
 0, // 1123
 0,  0,  0, // 1124-1126
 0,  0,  0, // 1127-1129
 0,  0,  0, // 1130-1132
 0,  0,  0, // 1133-1135
 0,  0, // 1136-1137
 0,  0, // 1138-1139
 0,  0,  0, // 1140-1142
 0,  0, // 1143-1144
 0, // 1145
 0,  0,  0, // 1146-1148
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1149-1152
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1153-1156
PPCE200Z0ItinerariesBypass::NoBypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1157-1159
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1160-1163
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass,  0, // 1164-1167
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1168-1171
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, // 1172-1174
PPCE200Z0ItinerariesBypass::NoBypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1175-1177
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, // 1178-1181
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0,  0, // 1182-1186
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0,  0, // 1187-1191
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass,  0, // 1192-1194
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1195-1198
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass,  0,  0, // 1199-1202
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1203-1206
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1207-1211
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1212-1216
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1217-1221
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1222-1225
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1226-1229
PPCE200Z0ItinerariesBypass::NoBypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1230-1233
PPCE200Z0ItinerariesBypass::NoBypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1234-1237
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1238-1240
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1241-1244
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1245-1248
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1249-1251
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1252-1255
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1256-1259
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1260-1263
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1264-1267
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass,  0, // 1268-1270
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1271-1274
PPCE200Z0ItinerariesBypass::NoBypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1275-1277
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1278-1281
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1282-1285
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1286-1289
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1290-1293
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass,  0, // 1294-1297
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1298-1301
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1302-1305
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, // 1306-1309
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1310-1313
PPCE200Z0ItinerariesBypass::NoBypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1314-1316
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1317-1320
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1321-1325
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1326-1330
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1331-1335
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1336-1340
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1341-1345
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1346-1349
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1350-1353
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1354-1357
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1358-1361
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0,  0, // 1362-1366
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0,  0, // 1367-1371
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1372-1375
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1376-1379
PPCE200Z0ItinerariesBypass::NoBypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1380-1382
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1383-1386
PPCE200Z0ItinerariesBypass::NoBypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1387-1389
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1390-1393
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1394-1397
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1398-1401
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass,  0,  0, // 1402-1405
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1406-1409
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, // 1410-1412
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, // 1413-1415
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, // 1416-1418
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, // 1419-1421
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1422-1425
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1426-1429
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass,  0, // 1430-1432
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1433-1436
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1437-1440
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1441-1444
PPCE200Z0ItinerariesBypass::NoBypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1445-1448
PPCE200Z0ItinerariesBypass::NoBypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1449-1452
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0,  0, // 1453-1457
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0,  0, // 1458-1462
PPCE200Z0ItinerariesBypass::NoBypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1463-1465
PPCE200Z0ItinerariesBypass::NoBypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1466-1468
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1469-1472
PPCE200Z0ItinerariesBypass::NoBypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1473-1475
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1476-1479
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1480-1483
PPCE200Z0ItinerariesBypass::NoBypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1484-1486
PPCE200Z0ItinerariesBypass::NoBypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1487-1489
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1490-1493
PPCE200Z0ItinerariesBypass::NoBypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1494-1496
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass,  0,  0, // 1497-1500
PPCE200Z0ItinerariesBypass::E200Z0_CR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0,  0, // 1501-1504
PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass, PPCE200Z0ItinerariesBypass::E200Z0_GPR_Bypass,  0, // 1505-1508
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1509-1510
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1511-1512
PPCE200Z3ItinerariesBypass::NoBypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1513-1514
PPCE200Z3ItinerariesBypass::E200Z3_CR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1515-1516
PPCE200Z3ItinerariesBypass::E200Z3_CR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_CR_Bypass, // 1517-1518
PPCE200Z3ItinerariesBypass::NoBypass,  0, // 1519-1520
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1521-1522
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1523-1524
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1525-1526
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_CR_Bypass, // 1527-1529
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1530-1531
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1532-1534
PPCE200Z3ItinerariesBypass::E200Z3_CR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_CR_Bypass, // 1535-1536
PPCE200Z3ItinerariesBypass::E200Z3_CR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1537-1538
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1539-1540
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1541-1542
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1543-1544
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1545-1546
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1547-1548
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1549-1550
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1551-1552
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1553-1554
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1555-1556
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1557-1558
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1559-1561
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1562-1563
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1564-1565
PPCE200Z3ItinerariesBypass::E200Z3_CR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1566-1567
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1568-1569
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1570-1571
PPCE200Z3ItinerariesBypass::E200Z3_CR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1572-1573
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1574-1575
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1576-1577
PPCE200Z3ItinerariesBypass::E200Z3_CR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_CR_Bypass, // 1578-1579
PPCE200Z3ItinerariesBypass::E200Z3_CR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1580-1581
PPCE200Z3ItinerariesBypass::NoBypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1582-1583
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1584-1585
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1586-1587
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1588-1589
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1590-1591
PPCE200Z3ItinerariesBypass::E200Z3_CR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1592-1593
PPCE200Z3ItinerariesBypass::E200Z3_CR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_CR_Bypass, // 1594-1595
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1596-1597
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1598-1599
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_CR_Bypass, // 1600-1602
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1603-1604
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1605-1606
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1607-1608
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1609-1610
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1611-1612
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1613-1614
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1615-1616
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1617-1618
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1619-1620
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1621-1622
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1623-1624
PPCE200Z3ItinerariesBypass::NoBypass,  0, // 1625-1626
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1627-1628
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1629-1630
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1631-1633
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1634-1635
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1636-1637
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1638-1639
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1640-1641
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1642-1643
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1644-1645
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1646-1647
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1648-1649
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1650-1651
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1652-1653
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1654-1655
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1656-1657
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1658-1659
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1660-1661
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1662-1663
PPCE200Z3ItinerariesBypass::E200Z3_CR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1664-1665
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1666-1667
PPCE200Z3ItinerariesBypass::E200Z3_CR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_CR_Bypass, // 1668-1669
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1670-1671
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1672-1673
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1674-1675
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1676-1677
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1678-1680
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1681-1683
PPCE200Z3ItinerariesBypass::NoBypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1684-1685
PPCE200Z3ItinerariesBypass::NoBypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1686-1687
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1688-1689
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1690-1691
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1692-1693
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1694-1695
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1696-1697
PPCE200Z3ItinerariesBypass::NoBypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1698-1699
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1700-1701
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1702-1703
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1704-1705
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass,  0, // 1706-1707
PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, PPCE200Z3ItinerariesBypass::E200Z3_GPR_Bypass, // 1708-1709
PPCE200Z3ItinerariesBypass::NoBypass,  0, // 1710-1711
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1712-1716
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1717-1721
PPCE200Z4ItinerariesBypass::NoBypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0, // 1722-1724
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1725-1729
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass,  0, // 1730-1733
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 1734-1738
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, // 1739-1741
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0, // 1742-1745
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0, // 1746-1749
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0, // 1750-1753
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0,  0, // 1754-1756
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0,  0, // 1757-1759
PPCE200Z4ItinerariesBypass::NoBypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1760-1763
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0, // 1764-1767
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass,  0,  0, // 1768-1773
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 1774-1778
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 1779-1783
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass,  0, // 1784-1786
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1787-1790
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass,  0,  0,  0, // 1791-1795
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 1796-1800
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1801-1805
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1806-1810
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1811-1815
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1816-1820
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1821-1825
PPCE200Z4ItinerariesBypass::NoBypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1826-1829
PPCE200Z4ItinerariesBypass::NoBypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1830-1833
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1834-1837
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0,  0, // 1838-1840
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 1841-1845
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1846-1850
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1851-1854
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0, // 1855-1858
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0, // 1859-1862
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1863-1867
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0,  0, // 1868-1870
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1871-1875
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1876-1880
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1881-1885
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass,  0, // 1886-1888
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1889-1892
PPCE200Z4ItinerariesBypass::NoBypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0, // 1893-1895
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 1896-1900
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 1901-1905
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1906-1910
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1911-1914
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass,  0, // 1915-1918
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1919-1923
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0, // 1924-1927
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1928-1932
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass,  0,  0, // 1933-1938
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 1939-1943
PPCE200Z4ItinerariesBypass::NoBypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1944-1947
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 1948-1952
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0,  0, // 1953-1955
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0, // 1956-1959
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0,  0, // 1960-1962
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1963-1967
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1968-1972
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1973-1977
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0, // 1978-1981
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0, // 1982-1985
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0, // 1986-1989
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1990-1994
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 1995-1999
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0, // 2000-2003
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0, // 2004-2007
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 2008-2012
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0,  0, // 2013-2015
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0, // 2016-2019
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 2020-2024
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 2025-2029
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 2030-2034
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 2035-2039
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 2040-2044
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 2045-2049
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 2050-2054
PPCE200Z4ItinerariesBypass::NoBypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 2055-2058
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 2059-2063
PPCE200Z4ItinerariesBypass::NoBypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 2064-2067
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 2068-2072
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 2073-2077
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 2078-2082
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass,  0,  0,  0, // 2083-2087
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 2088-2092
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, // 2093-2095
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, // 2096-2098
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, // 2099-2101
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, // 2102-2104
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 2105-2108
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 2109-2113
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0, // 2114-2117
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass,  0, // 2118-2120
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 2121-2125
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 2126-2130
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 2131-2135
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0, // 2136-2139
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0, // 2140-2143
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0, // 2144-2147
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0, // 2148-2151
PPCE200Z4ItinerariesBypass::NoBypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 2152-2155
PPCE200Z4ItinerariesBypass::NoBypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 2156-2159
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 2160-2164
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 2165-2169
PPCE200Z4ItinerariesBypass::NoBypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0, // 2170-2172
PPCE200Z4ItinerariesBypass::NoBypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0, // 2173-2175
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 2176-2180
PPCE200Z4ItinerariesBypass::NoBypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 2181-2184
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 2185-2189
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0,  0, // 2190-2192
PPCE200Z4ItinerariesBypass::E200Z4_SPE_Bypass,  0,  0, // 2193-2195
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 2196-2200
PPCE200Z4ItinerariesBypass::NoBypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 2201-2204
PPCE200Z4ItinerariesBypass::NoBypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0, // 2205-2207
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 2208-2212
PPCE200Z4ItinerariesBypass::NoBypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 2213-2216
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass,  0,  0,  0, // 2217-2221
PPCE200Z4ItinerariesBypass::E200Z4_CR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0,  0, // 2222-2226
PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass, PPCE200Z4ItinerariesBypass::E200Z4_GPR_Bypass,  0,  0, // 2227-2231
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2232-2236
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2237-2241
PPCE200Z6ItinerariesBypass::NoBypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0, // 2242-2244
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2245-2249
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass,  0, // 2250-2253
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2254-2258
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, // 2259-2261
PPCE200Z6ItinerariesBypass::NoBypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2262-2265
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass,  0,  0, // 2266-2271
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2272-2276
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2277-2281
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass,  0, // 2282-2284
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2285-2288
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass,  0,  0,  0, // 2289-2293
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2294-2298
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2299-2303
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2304-2308
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2309-2313
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2314-2318
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2319-2323
PPCE200Z6ItinerariesBypass::NoBypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2324-2327
PPCE200Z6ItinerariesBypass::NoBypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2328-2331
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2332-2335
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2336-2340
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2341-2345
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2346-2349
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2350-2354
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2355-2359
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2360-2364
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2365-2369
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass,  0, // 2370-2372
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2373-2376
PPCE200Z6ItinerariesBypass::NoBypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0, // 2377-2379
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2380-2384
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2385-2389
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2390-2394
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2395-2398
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass,  0, // 2399-2402
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2403-2407
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2408-2412
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass,  0,  0, // 2413-2418
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2419-2423
PPCE200Z6ItinerariesBypass::NoBypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2424-2427
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2428-2432
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2433-2437
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2438-2442
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2443-2447
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2448-2452
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2453-2457
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2458-2462
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2463-2467
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2468-2472
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2473-2477
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2478-2482
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2483-2487
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2488-2492
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2493-2497
PPCE200Z6ItinerariesBypass::NoBypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2498-2501
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2502-2506
PPCE200Z6ItinerariesBypass::NoBypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2507-2510
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2511-2515
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2516-2520
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2521-2525
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass,  0,  0,  0, // 2526-2530
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2531-2535
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, // 2536-2538
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, // 2539-2541
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, // 2542-2544
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, // 2545-2547
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2548-2551
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2552-2556
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass,  0, // 2557-2559
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2560-2564
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2565-2569
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2570-2574
PPCE200Z6ItinerariesBypass::NoBypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2575-2578
PPCE200Z6ItinerariesBypass::NoBypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2579-2582
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2583-2587
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2588-2592
PPCE200Z6ItinerariesBypass::NoBypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0, // 2593-2595
PPCE200Z6ItinerariesBypass::NoBypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0, // 2596-2598
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2599-2603
PPCE200Z6ItinerariesBypass::NoBypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2604-2607
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2608-2612
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2613-2617
PPCE200Z6ItinerariesBypass::NoBypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2618-2621
PPCE200Z6ItinerariesBypass::NoBypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0, // 2622-2624
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2625-2629
PPCE200Z6ItinerariesBypass::NoBypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2630-2633
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass,  0,  0,  0, // 2634-2638
PPCE200Z6ItinerariesBypass::E200Z6_CR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0,  0, // 2639-2643
PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass, PPCE200Z6ItinerariesBypass::E200Z6_GPR_Bypass,  0,  0, // 2644-2648
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2649-2651
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2652-2654
PPCE200Z7ItinerariesBypass::NoBypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2655-2657
PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2658-2660
PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass,  0, // 2661-2664
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2665-2667
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2668-2670
PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass,  0, // 2671-2674
PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass,  0, // 2675-2678
PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass,  0, // 2679-2682
PPCE200Z7ItinerariesBypass::E200Z7_SPE_Bypass,  0,  0, // 2683-2685
PPCE200Z7ItinerariesBypass::E200Z7_SPE_Bypass,  0,  0, // 2686-2688
PPCE200Z7ItinerariesBypass::NoBypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2689-2691
PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass,  0, // 2692-2695
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, // 2696-2699
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2700-2702
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2703-2705
PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass,  0, // 2706-2708
PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0,  0, // 2709-2712
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2713-2715
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2716-2718
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2719-2721
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2722-2724
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2725-2727
PPCE200Z7ItinerariesBypass::NoBypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2728-2730
PPCE200Z7ItinerariesBypass::NoBypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2731-2733
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2734-2736
PPCE200Z7ItinerariesBypass::E200Z7_SPE_Bypass,  0,  0, // 2737-2739
PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2740-2742
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2743-2745
PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass,  0, // 2746-2749
PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass,  0, // 2750-2753
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2754-2756
PPCE200Z7ItinerariesBypass::E200Z7_SPE_Bypass,  0,  0, // 2757-2759
PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2760-2762
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2763-2765
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2766-2768
PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass,  0, // 2769-2771
PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0,  0, // 2772-2775
PPCE200Z7ItinerariesBypass::NoBypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2776-2778
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2779-2781
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2782-2784
PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0,  0, // 2785-2788
PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass,  0, // 2789-2792
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2793-2795
PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass,  0, // 2796-2799
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2800-2802
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, // 2803-2806
PPCE200Z7ItinerariesBypass::NoBypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2807-2809
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2810-2812
PPCE200Z7ItinerariesBypass::E200Z7_SPE_Bypass,  0,  0, // 2813-2815
PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass,  0, // 2816-2819
PPCE200Z7ItinerariesBypass::E200Z7_SPE_Bypass,  0,  0, // 2820-2822
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2823-2825
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2826-2828
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2829-2831
PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass,  0, // 2832-2835
PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass,  0, // 2836-2839
PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass,  0, // 2840-2843
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2844-2846
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2847-2849
PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass,  0, // 2850-2853
PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass,  0, // 2854-2857
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2858-2860
PPCE200Z7ItinerariesBypass::E200Z7_SPE_Bypass,  0,  0, // 2861-2863
PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass,  0, // 2864-2867
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2868-2870
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2871-2873
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2874-2876
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2877-2879
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2880-2882
PPCE200Z7ItinerariesBypass::NoBypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2883-2885
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2886-2888
PPCE200Z7ItinerariesBypass::NoBypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2889-2891
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2892-2894
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2895-2897
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2898-2900
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2901-2903
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2904-2906
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2907-2909
PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0,  0, // 2910-2913
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2914-2916
PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass,  0, // 2917-2920
PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_CR_Bypass,  0, // 2921-2923
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2924-2926
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2927-2929
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2930-2932
PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass,  0, // 2933-2936
PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass,  0, // 2937-2940
PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass,  0, // 2941-2944
PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_FPR_Bypass,  0, // 2945-2948
PPCE200Z7ItinerariesBypass::NoBypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2949-2951
PPCE200Z7ItinerariesBypass::NoBypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2952-2954
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2955-2957
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2958-2960
PPCE200Z7ItinerariesBypass::NoBypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2961-2963
PPCE200Z7ItinerariesBypass::NoBypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2964-2966
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2967-2969
PPCE200Z7ItinerariesBypass::NoBypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2970-2972
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2973-2975
PPCE200Z7ItinerariesBypass::E200Z7_SPE_Bypass,  0,  0, // 2976-2978
PPCE200Z7ItinerariesBypass::E200Z7_SPE_Bypass,  0,  0, // 2979-2981
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2982-2984
PPCE200Z7ItinerariesBypass::NoBypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2985-2987
PPCE200Z7ItinerariesBypass::NoBypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2988-2990
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2991-2993
PPCE200Z7ItinerariesBypass::NoBypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass,  0, // 2994-2996
PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, PPCE200Z7ItinerariesBypass::E200Z7_GPR_Bypass, // 2997-2999
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3000-3002
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3003-3005
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3006-3007
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3008-3010
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_CR_Bypass, // 3011-3013
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3014-3015
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3016-3017
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3018-3020
PPCE500ItinerariesBypass::NoBypass,  0,  0, // 3021-3023
PPCE500ItinerariesBypass::E500_DivBypass,  0,  0, // 3024-3026
PPCE500ItinerariesBypass::NoBypass,  0,  0, // 3027-3029
PPCE500ItinerariesBypass::NoBypass,  0,  0, // 3030-3032
PPCE500ItinerariesBypass::NoBypass,  0,  0, // 3033-3035
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3036-3037
PPCE500ItinerariesBypass::E500_DivBypass,  0,  0, // 3038-3040
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3041-3042
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_CR_Bypass, // 3043-3046
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3047-3049
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3050-3051
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3052-3053
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3054-3055
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3056-3057
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3058-3059
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3060-3061
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_CR_Bypass, // 3062-3063
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass,  0, // 3064-3066
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_CR_Bypass, // 3067-3068
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_CR_Bypass, // 3069-3070
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3071-3072
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_CR_Bypass, // 3073-3074
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3075-3076
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3077-3078
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3079-3080
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3081-3082
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3083-3084
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3085-3086
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3087-3088
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3089-3091
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3092-3094
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3095-3097
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3098-3100
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3101-3103
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3104-3105
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3106-3107
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3108-3109
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3110-3111
PPCE500ItinerariesBypass::NoBypass,  0,  0, // 3112-3114
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3115-3116
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3117-3119
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3120-3121
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3122-3124
PPCE500ItinerariesBypass::NoBypass,  0,  0, // 3125-3127
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3128-3130
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3131-3133
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3134-3136
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_CR_Bypass, // 3137-3138
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass,  0, // 3139-3141
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3142-3143
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3144-3145
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3146-3147
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3148-3150
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_CR_Bypass, // 3151-3152
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass,  0, // 3153-3155
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_CR_Bypass, // 3156-3158
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3159-3161
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3162-3164
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_CR_Bypass, // 3165-3168
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3169-3170
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3171-3172
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3173-3174
PPCE500ItinerariesBypass::NoBypass,  0,  0, // 3175-3177
PPCE500ItinerariesBypass::NoBypass,  0,  0, // 3178-3180
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3181-3183
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3184-3186
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3187-3189
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3190-3192
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3193-3195
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3196-3197
PPCE500ItinerariesBypass::NoBypass,  0,  0, // 3198-3200
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3201-3202
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3203-3204
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3205-3206
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3207-3208
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3209-3210
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3211-3213
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3214-3215
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3216-3217
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3218-3219
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3220-3221
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3222-3223
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3224-3225
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3226-3227
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3228-3229
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3230-3231
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3232-3233
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3234-3235
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3236-3237
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3238-3239
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3240-3241
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3242-3243
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3244-3246
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3247-3248
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3249-3250
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3251-3252
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_CR_Bypass, // 3253-3254
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3255-3256
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3257-3258
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3259-3260
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3261-3263
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3264-3266
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3267-3269
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3270-3272
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass,  0, // 3273-3275
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3276-3278
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_CR_Bypass, // 3279-3280
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3281-3283
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3284-3286
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3287-3289
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_CR_Bypass, // 3290-3291
PPCE500ItinerariesBypass::E500_DivBypass,  0,  0, // 3292-3294
PPCE500ItinerariesBypass::E500_DivBypass,  0,  0, // 3295-3297
PPCE500ItinerariesBypass::E500_DivBypass,  0,  0, // 3298-3300
PPCE500ItinerariesBypass::E500_DivBypass,  0,  0, // 3301-3303
PPCE500ItinerariesBypass::E500_DivBypass,  0,  0, // 3304-3306
PPCE500ItinerariesBypass::E500_DivBypass,  0,  0, // 3307-3309
PPCE500ItinerariesBypass::E500_DivBypass,  0,  0, // 3310-3312
PPCE500ItinerariesBypass::E500_DivBypass,  0,  0, // 3313-3315
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3316-3317
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3318-3319
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3320-3321
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3322-3323
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3324-3325
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3326-3327
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3328-3329
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3330-3331
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3332-3334
PPCE500ItinerariesBypass::NoBypass,  0,  0, // 3335-3337
PPCE500ItinerariesBypass::NoBypass,  0,  0, // 3338-3340
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3341-3342
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3343-3344
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3345-3346
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3347-3348
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3349-3350
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3351-3352
PPCE500ItinerariesBypass::NoBypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3353-3354
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_CR_Bypass, // 3355-3356
PPCE500ItinerariesBypass::E500_CR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3357-3358
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3359-3361
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3362-3363
PPCE500ItinerariesBypass::E500_GPR_Bypass, PPCE500ItinerariesBypass::E500_GPR_Bypass, // 3364-3365
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3366-3368
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3369-3371
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3372-3373
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3374-3376
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_CR_Bypass, // 3377-3379
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3380-3381
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3382-3383
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3384-3386
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3387-3389
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3390-3392
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3393-3395
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3396-3398
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3399-3400
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3401-3403
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3404-3407
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3408-3409
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_CR_Bypass, // 3410-3413
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3414-3416
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3417-3418
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3419-3420
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3421-3423
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3424-3426
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3427-3429
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3430-3431
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3432-3433
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3434-3435
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3436-3437
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_CR_Bypass, // 3438-3439
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass,  0, // 3440-3442
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_CR_Bypass, // 3443-3444
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_CR_Bypass, // 3445-3446
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3447
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3448-3449
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_CR_Bypass, // 3450-3451
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3452-3453
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3454-3455
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3456-3457
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3458-3459
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::NoBypass, // 3460-3462
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3463-3464
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3465-3466
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3467-3468
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3469-3471
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3472-3474
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3475-3477
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3478-3480
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3481-3483
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3484-3486
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3487-3489
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3490-3491
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3492-3493
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3494-3495
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3496-3497
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3498-3499
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::NoBypass, // 3500-3502
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3503
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3504-3506
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3507-3508
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3509-3511
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3512-3514
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3515-3517
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3518-3520
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3521-3523
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3524-3526
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_CR_Bypass, // 3527-3528
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass,  0, // 3529-3531
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3532-3533
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3534-3535
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3536-3537
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3538-3540
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_CR_Bypass, // 3541-3542
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass,  0, // 3543-3545
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_CR_Bypass, // 3546-3548
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3549-3551
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3552-3554
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3555-3557
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_CR_Bypass, // 3558-3561
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3562-3563
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3564-3565
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3566-3567
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3568-3570
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3571-3573
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3574-3576
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3577-3579
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3580-3582
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3583-3585
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3586-3589
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3590-3592
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3593-3595
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3596-3598
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3599-3601
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3602-3604
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3605-3608
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3609-3610
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3611-3613
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3614-3615
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3616-3617
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3618-3620
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3621-3622
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3623-3624
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3625-3626
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3627-3629
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3630-3631
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3632-3634
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3635-3636
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3637-3638
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3639-3640
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3641-3642
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3643-3644
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3645-3646
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3647-3649
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3650-3652
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3653-3655
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3656-3658
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3659-3660
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3661-3662
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3663-3665
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3666-3668
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3669-3670
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3671-3672
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3673-3674
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3675-3676
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3677-3679
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3680-3681
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3682-3683
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3684-3686
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3687-3688
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3689-3690
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3691-3692
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_CR_Bypass, // 3693-3694
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3695-3696
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3697-3698
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3699-3700
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3701-3703
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3704-3706
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3707-3709
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3710-3712
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass,  0, // 3713-3715
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3716-3718
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3719-3721
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_CR_Bypass, // 3722-3723
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3724
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::NoBypass, // 3725-3727
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3728-3730
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3731-3733
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3734-3736
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3737
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_CR_Bypass, // 3738-3739
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3740-3742
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3743-3745
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3746-3748
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3749-3751
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3752-3754
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3755-3757
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3758-3760
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, // 3761-3763
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3764-3766
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3767-3769
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3770-3772
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3773-3774
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3775-3776
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3777-3778
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3779-3780
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3781-3783
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3784-3786
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3787-3788
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3789-3790
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3791-3792
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3793-3794
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3795-3797
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3798-3799
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3800-3801
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3802-3803
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3804-3805
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3806-3807
PPCE500mcItinerariesBypass::E500mc_FPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3808-3810
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3811-3813
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3814-3815
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3816-3817
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_CR_Bypass, // 3818-3819
PPCE500mcItinerariesBypass::E500mc_CR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3820-3821
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3822-3824
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3825-3826
PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, PPCE500mcItinerariesBypass::E500mc_GPR_Bypass, // 3827-3828
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3829-3831
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3832-3834
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3835-3836
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3837-3839
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_CR_Bypass, // 3840-3842
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3843-3844
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3845-3846
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3847-3848
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3849-3851
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3852-3854
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 3855-3857
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 3858-3860
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 3861-3863
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 3864-3866
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3867-3868
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3869-3871
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 3872-3874
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 3875-3878
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3879-3880
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_CR_Bypass, // 3881-3884
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3885-3887
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3888-3889
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3890-3891
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3892-3893
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3894-3895
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3896-3897
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3898-3900
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3901-3903
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3904-3906
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3907-3908
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3909-3910
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3911-3912
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3913-3914
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3915-3917
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_CR_Bypass, // 3918-3919
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass,  0, // 3920-3922
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_CR_Bypass, // 3923-3924
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3925
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 3926
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_CR_Bypass, // 3927-3928
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3929-3930
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3931-3932
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3933
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::NoBypass, // 3934-3936
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3937-3938
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3939
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3940-3942
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3943-3945
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3946-3948
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3949-3951
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3952-3954
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3955-3957
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3958-3960
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3961-3963
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3964-3965
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3966-3967
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3968-3969
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3970-3971
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3972-3973
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3974-3975
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3976
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::NoBypass, // 3977-3979
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 3980
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3981-3983
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3984-3985
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 3986-3988
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 3989-3991
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3992-3994
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3995-3997
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 3998-4000
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4001-4003
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4004-4006
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4007-4009
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_CR_Bypass, // 4010-4011
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass,  0, // 4012-4014
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4015-4016
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4017
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4018-4019
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4020-4022
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4023-4025
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4026-4028
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_CR_Bypass, // 4029-4030
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass,  0, // 4031-4033
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_CR_Bypass, // 4034-4036
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4037-4039
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4040-4042
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4043-4045
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_CR_Bypass, // 4046-4049
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4050
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4051-4052
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4053-4054
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4055-4057
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4058-4060
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4061-4063
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4064-4066
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4067-4069
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4070-4072
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4073-4075
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4076-4079
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4080-4082
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4083-4085
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4086-4088
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4089-4091
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4092-4094
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4095-4097
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4098-4101
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4102-4103
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4104-4106
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4107-4108
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4109-4110
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4111-4113
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4114-4115
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4116-4117
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4118-4119
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4120-4122
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4123-4124
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4125-4126
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4127-4128
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4129-4131
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4132-4133
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4134-4135
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4136
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4137-4138
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4139-4140
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4141-4142
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4143-4144
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4145
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4146-4148
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4149-4151
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4152-4154
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4155-4157
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4158-4159
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4160-4161
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4162-4164
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4165-4167
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4168-4169
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4170-4171
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4172-4173
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4174-4175
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4176-4177
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4178-4180
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4181-4182
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4183
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4184-4186
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4187-4188
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4189
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4190-4191
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4192
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4193-4194
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4195
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4196-4198
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4199-4201
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4202-4204
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4205-4207
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4208-4210
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4211-4213
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4214-4216
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4217-4219
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass,  0, // 4220-4222
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4223-4225
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4226-4228
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_CR_Bypass, // 4229-4230
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4231
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::NoBypass, // 4232-4234
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4235-4237
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4238-4240
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4241-4243
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4244-4246
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4247-4249
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4250
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_CR_Bypass, // 4251-4252
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4253-4255
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4256-4258
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4259-4261
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4262-4264
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4265-4267
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4268-4270
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4271-4273
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4274-4276
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4277-4279
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 4280-4282
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4283-4285
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4286-4288
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4289-4291
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4292-4293
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4294-4295
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4296-4297
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4298-4299
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4300-4301
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4302-4303
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4304-4306
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4307-4309
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4310-4311
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4312-4313
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4314-4315
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4316-4317
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4318-4320
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4321-4322
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4323-4324
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4325-4326
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4327-4328
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4329-4330
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4331-4333
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4334-4336
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4337
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4338
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4339-4341
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4342-4343
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 4344-4345
 0,  0,  0, // 4346-4348
 0,  0,  0, // 4349-4351
 0,  0,  0, // 4352-4354
 0,  0,  0, // 4355-4357
 0,  0,  0, // 4358-4360
 0,  0,  0, // 4361-4363
 0,  0,  0, // 4364-4366
 0,  0,  0, // 4367-4369
 0,  0,  0, // 4370-4372
 0,  0,  0, // 4373-4375
 0,  0,  0, // 4376-4378
 0,  0,  0, // 4379-4381
 0,  0,  0, // 4382-4384
 0,  0,  0, // 4385-4387
 0,  0,  0, // 4388-4390
 0,  0,  0, // 4391-4393
 0,  0,  0, // 4394-4396
 0,  0,  0, // 4397-4399
 0,  0,  0, // 4400-4402
 0,  0,  0,  0, // 4403-4406
 0,  0,  0, // 4407-4409
 0,  0,  0, // 4410-4412
 0,  0,  0,  0, // 4413-4416
 0,  0,  0, // 4417-4419
 0,  0,  0,  0, // 4420-4423
 0,  0,  0,  0, // 4424-4427
 0,  0,  0, // 4428-4430
 0,  0,  0,  0, // 4431-4434
 0,  0,  0,  0, // 4435-4438
 0,  0,  0, // 4439-4441
 0,  0,  0,  0, // 4442-4445
 0,  0,  0,  0, // 4446-4449
 0,  0,  0, // 4450-4452
 0,  0,  0,  0, // 4453-4456
 0,  0,  0,  0, // 4457-4460
 0,  0,  0, // 4461-4463
 0,  0,  0, // 4464-4466
 0,  0,  0, // 4467-4469
 0,  0,  0, // 4470-4472
 0,  0, // 4473-4474
 0,  0, // 4475-4476
 0,  0, // 4477-4478
 0,  0, // 4479-4480
 0,  0,  0, // 4481-4483
 0,  0,  0, // 4484-4486
 0,  0,  0, // 4487-4489
 0,  0,  0, // 4490-4492
 0,  0,  0, // 4493-4495
 0,  0,  0,  0, // 4496-4499
 0,  0,  0, // 4500-4502
 0,  0,  0, // 4503-4505
 0,  0,  0, // 4506-4508
 0,  0,  0, // 4509-4511
 0,  0,  0,  0, // 4512-4515
 0,  0,  0,  0, // 4516-4519
 0,  0,  0, // 4520-4522
 0,  0, // 4523-4524
 0,  0, // 4525-4526
 0,  0,  0, // 4527-4529
 0,  0,  0, // 4530-4532
 0,  0,  0, // 4533-4535
 0,  0,  0, // 4536-4538
 0,  0, // 4539-4540
 0,  0,  0, // 4541-4543
 0,  0, // 4544-4545
 0,  0, // 4546-4547
 0,  0,  0, // 4548-4550
 0,  0,  0, // 4551-4553
 0,  0,  0, // 4554-4556
 0,  0,  0, // 4557-4559
 0,  0,  0, // 4560-4562
 0,  0,  0, // 4563-4565
 0,  0,  0, // 4566-4568
 0,  0,  0, // 4569-4571
 0,  0,  0, // 4572-4574
 0,  0,  0, // 4575-4577
 0,  0,  0, // 4578-4580
 0,  0,  0, // 4581-4583
 0,  0, // 4584-4585
 0,  0,  0, // 4586-4588
 0,  0,  0, // 4589-4591
 0,  0, // 4592-4593
 0,  0,  0, // 4594-4596
 0,  0,  0, // 4597-4599
 0,  0,  0, // 4600-4602
 0,  0,  0, // 4603-4605
 0,  0, // 4606-4607
 0,  0, // 4608-4609
 0,  0,  0, // 4610-4612
 0,  0,  0, // 4613-4615
 0,  0,  0, // 4616-4618
 0,  0,  0, // 4619-4621
 0,  0,  0,  0, // 4622-4625
 0,  0,  0, // 4626-4628
 0,  0, // 4629-4630
 0,  0,  0, // 4631-4633
 0,  0,  0, // 4634-4636
 0,  0,  0, // 4637-4639
 0,  0,  0, // 4640-4642
 0,  0,  0, // 4643-4645
 0,  0,  0, // 4646-4648
 0,  0,  0, // 4649-4651
 0,  0,  0, // 4652-4654
 0,  0,  0, // 4655-4657
 0,  0,  0, // 4658-4660
 0,  0,  0, // 4661-4663
 0,  0,  0, // 4664-4666
 0,  0,  0, // 4667-4669
 0,  0,  0, // 4670-4672
 0,  0,  0,  0, // 4673-4676
 0,  0,  0, // 4677-4679
 0,  0,  0, // 4680-4682
 0,  0,  0, // 4683-4685
 0,  0,  0, // 4686-4688
 0,  0,  0, // 4689-4691
 0,  0,  0, // 4692-4694
 0,  0,  0, // 4695-4697
 0,  0,  0,  0, // 4698-4701
 0,  0,  0, // 4702-4704
 0,  0,  0, // 4705-4707
 0,  0,  0, // 4708-4710
 0,  0,  0, // 4711-4713
 0,  0,  0, // 4714-4716
 0,  0,  0, // 4717-4719
 0,  0,  0, // 4720-4722
 0,  0,  0, // 4723-4725
 0,  0,  0, // 4726-4728
 0,  0,  0, // 4729-4731
 0,  0,  0, // 4732-4734
 0,  0,  0, // 4735-4737
 0,  0,  0, // 4738-4740
 0,  0,  0, // 4741-4743
 0,  0,  0, // 4744-4746
 0,  0,  0, // 4747-4749
 0,  0,  0, // 4750-4752
 0,  0,  0, // 4753-4755
 0,  0,  0, // 4756-4758
 0,  0,  0, // 4759-4761
 0,  0,  0, // 4762-4764
 0,  0,  0,  0, // 4765-4768
 0,  0,  0,  0, // 4769-4772
 0,  0, // 4773-4774
 0,  0,  0, // 4775-4777
 0,  0,  0, // 4778-4780
 0,  0,  0, // 4781-4783
 0,  0,  0, // 4784-4786
 0,  0,  0, // 4787-4789
 0,  0, // 4790-4791
 0,  0,  0, // 4792-4794
 0,  0,  0, // 4795-4797
 0,  0,  0, // 4798-4800
 0,  0,  0, // 4801-4803
 0,  0,  0,  0, // 4804-4807
 0,  0,  0,  0, // 4808-4811
 0,  0,  0, // 4812-4814
 0,  0,  0, // 4815-4817
 0,  0,  0, // 4818-4820
 0,  0,  0, // 4821-4823
 0,  0,  0, // 4824-4826
 0,  0,  0, // 4827-4829
 0,  0,  0, // 4830-4832
 0,  0,  0, // 4833-4835
 0,  0, // 4836-4837
 0,  0,  0, // 4838-4840
 0,  0, // 4841-4842
 0,  0,  0, // 4843-4845
 0,  0,  0, // 4846-4848
 0,  0,  0, // 4849-4851
 0,  0,  0, // 4852-4854
 0,  0,  0, // 4855-4857
 0,  0,  0, // 4858-4860
 0,  0,  0, // 4861-4863
 0,  0,  0, // 4864-4866
 0,  0, // 4867-4868
 0,  0,  0, // 4869-4871
 0,  0,  0, // 4872-4874
 0,  0,  0, // 4875-4877
 0,  0,  0, // 4878-4880
 0,  0,  0, // 4881-4883
 0,  0,  0, // 4884-4886
 0,  0,  0, // 4887-4889
 0,  0,  0, // 4890-4892
 0,  0, // 4893-4894
 0,  0,  0, // 4895-4897
 0,  0,  0, // 4898-4900
 0,  0,  0, // 4901-4903
 0,  0,  0, // 4904-4906
 0,  0,  0, // 4907-4909
 0,  0,  0, // 4910-4912
 0,  0,  0, // 4913-4915
 0,  0,  0, // 4916-4918
 0,  0,  0, // 4919-4921
 0,  0,  0, // 4922-4924
 0,  0,  0, // 4925-4927
 0,  0,  0, // 4928-4930
 0,  0,  0, // 4931-4933
 0,  0,  0, // 4934-4936
 0,  0,  0, // 4937-4939
 0,  0,  0, // 4940-4942
 0,  0,  0, // 4943-4945
 0,  0,  0, // 4946-4948
 0,  0,  0,  0, // 4949-4952
 0,  0,  0,  0, // 4953-4956
 0,  0,  0,  0, // 4957-4960
 0,  0,  0,  0, // 4961-4964
 0,  0,  0,  0, // 4965-4968
 0,  0,  0,  0, // 4969-4972
 0,  0,  0,  0, // 4973-4976
 0,  0,  0,  0, // 4977-4980
 0,  0,  0,  0, // 4981-4984
 0,  0,  0,  0, // 4985-4988
 0,  0,  0,  0, // 4989-4992
 0,  0,  0, // 4993-4995
 0,  0,  0, // 4996-4998
 0,  0,  0, // 4999-5001
 0,  0,  0, // 5002-5004
 0,  0,  0, // 5005-5007
 0,  0,  0, // 5008-5010
 0,  0,  0, // 5011-5013
 0,  0,  0, // 5014-5016
 0,  0,  0, // 5017-5019
 0,  0,  0, // 5020-5022
 0,  0,  0, // 5023-5025
 0,  0,  0, // 5026-5028
 0,  0,  0, // 5029-5031
 0,  0,  0, // 5032-5034
 0,  0,  0, // 5035-5037
 0,  0, // 5038-5039
 0,  0,  0, // 5040-5042
 0,  0,  0, // 5043-5045
 0,  0,  0, // 5046-5048
 0,  0,  0, // 5049-5051
 0,  0,  0, // 5052-5054
 0,  0,  0, // 5055-5057
 0,  0,  0, // 5058-5060
 0,  0,  0, // 5061-5063
 0,  0,  0, // 5064-5066
 0,  0,  0, // 5067-5069
 0,  0,  0, // 5070-5072
 0,  0,  0, // 5073-5075
 0,  0,  0, // 5076-5078
 0,  0,  0, // 5079-5081
 0,  0,  0, // 5082-5084
 0,  0,  0, // 5085-5087
 0,  0,  0, // 5088-5090
 0,  0,  0, // 5091-5093
 0,  0,  0, // 5094-5096
 0,  0,  0, // 5097-5099
 0,  0,  0,  0, // 5100-5103
 0,  0,  0, // 5104-5106
 0,  0,  0, // 5107-5109
 0,  0,  0,  0, // 5110-5113
 0,  0,  0, // 5114-5116
 0,  0,  0,  0, // 5117-5120
 0,  0,  0,  0, // 5121-5124
 0,  0,  0, // 5125-5127
 0,  0,  0,  0, // 5128-5131
 0,  0,  0,  0, // 5132-5135
 0,  0,  0, // 5136-5138
 0,  0,  0,  0, // 5139-5142
 0,  0,  0,  0, // 5143-5146
 0,  0,  0, // 5147-5149
 0,  0,  0,  0, // 5150-5153
 0,  0,  0,  0, // 5154-5157
 0,  0,  0, // 5158-5160
 0,  0,  0, // 5161-5163
 0,  0,  0, // 5164-5166
 0,  0,  0, // 5167-5169
 0,  0, // 5170-5171
 0,  0, // 5172-5173
 0,  0, // 5174-5175
 0,  0, // 5176-5177
 0,  0,  0, // 5178-5180
 0,  0,  0, // 5181-5183
 0,  0,  0, // 5184-5186
 0,  0,  0, // 5187-5189
 0,  0,  0, // 5190-5192
 0,  0,  0,  0, // 5193-5196
 0,  0,  0, // 5197-5199
 0,  0,  0, // 5200-5202
 0,  0,  0, // 5203-5205
 0,  0,  0, // 5206-5208
 0,  0,  0,  0, // 5209-5212
 0,  0,  0,  0, // 5213-5216
 0,  0,  0, // 5217-5219
 0,  0,  0, // 5220-5222
 0,  0, // 5223-5224
 0,  0, // 5225-5226
 0,  0,  0, // 5227-5229
 0,  0,  0, // 5230-5232
 0,  0,  0, // 5233-5235
 0,  0,  0, // 5236-5238
 0,  0, // 5239-5240
 0,  0,  0, // 5241-5243
 0,  0, // 5244-5245
 0,  0, // 5246-5247
 0,  0,  0, // 5248-5250
 0,  0,  0, // 5251-5253
 0,  0,  0, // 5254-5256
 0,  0,  0, // 5257-5259
 0,  0,  0, // 5260-5262
 0,  0,  0, // 5263-5265
 0,  0,  0, // 5266-5268
 0,  0,  0, // 5269-5271
 0,  0,  0, // 5272-5274
 0,  0,  0, // 5275-5277
 0,  0,  0, // 5278-5280
 0,  0,  0, // 5281-5283
 0,  0, // 5284-5285
 0,  0,  0, // 5286-5288
 0,  0,  0, // 5289-5291
 0,  0, // 5292-5293
 0,  0,  0, // 5294-5296
 0,  0,  0, // 5297-5299
 0,  0,  0, // 5300-5302
 0,  0,  0, // 5303-5305
 0,  0, // 5306-5307
 0,  0, // 5308-5309
 0,  0,  0, // 5310-5312
 0,  0,  0, // 5313-5315
 0,  0,  0, // 5316-5318
 0,  0,  0, // 5319-5321
 0,  0,  0,  0, // 5322-5325
 0,  0,  0, // 5326-5328
 0,  0, // 5329-5330
 0,  0,  0, // 5331-5333
 0,  0,  0, // 5334-5336
 0,  0,  0, // 5337-5339
 0,  0,  0, // 5340-5342
 0,  0,  0, // 5343-5345
 0,  0,  0, // 5346-5348
 0,  0,  0, // 5349-5351
 0,  0,  0, // 5352-5354
 0,  0,  0, // 5355-5357
 0,  0,  0, // 5358-5360
 0,  0,  0, // 5361-5363
 0,  0,  0, // 5364-5366
 0,  0,  0, // 5367-5369
 0,  0,  0, // 5370-5372
 0,  0,  0,  0, // 5373-5376
 0,  0,  0, // 5377-5379
 0,  0,  0, // 5380-5382
 0,  0,  0, // 5383-5385
 0,  0,  0, // 5386-5388
 0,  0,  0, // 5389-5391
 0,  0,  0, // 5392-5394
 0,  0,  0, // 5395-5397
 0,  0,  0,  0, // 5398-5401
 0,  0,  0, // 5402-5404
 0,  0,  0, // 5405-5407
 0,  0,  0, // 5408-5410
 0,  0,  0, // 5411-5413
 0,  0,  0, // 5414-5416
 0,  0,  0, // 5417-5419
 0,  0,  0, // 5420-5422
 0,  0,  0, // 5423-5425
 0,  0,  0, // 5426-5428
 0,  0,  0, // 5429-5431
 0,  0,  0, // 5432-5434
 0,  0,  0, // 5435-5437
 0,  0,  0, // 5438-5440
 0,  0,  0, // 5441-5443
 0,  0,  0, // 5444-5446
 0,  0,  0, // 5447-5449
 0,  0,  0, // 5450-5452
 0,  0,  0, // 5453-5455
 0,  0,  0, // 5456-5458
 0,  0,  0, // 5459-5461
 0,  0,  0, // 5462-5464
 0,  0,  0,  0, // 5465-5468
 0,  0,  0,  0, // 5469-5472
 0,  0, // 5473-5474
 0,  0,  0, // 5475-5477
 0,  0,  0, // 5478-5480
 0,  0,  0, // 5481-5483
 0,  0,  0, // 5484-5486
 0,  0,  0, // 5487-5489
 0,  0, // 5490-5491
 0,  0,  0, // 5492-5494
 0,  0,  0, // 5495-5497
 0,  0,  0, // 5498-5500
 0,  0,  0, // 5501-5503
 0,  0,  0,  0, // 5504-5507
 0,  0,  0,  0, // 5508-5511
 0,  0,  0, // 5512-5514
 0,  0,  0, // 5515-5517
 0,  0,  0, // 5518-5520
 0,  0,  0, // 5521-5523
 0,  0,  0, // 5524-5526
 0,  0,  0, // 5527-5529
 0,  0,  0, // 5530-5532
 0,  0,  0, // 5533-5535
 0,  0,  0, // 5536-5538
 0,  0, // 5539-5540
 0,  0,  0, // 5541-5543
 0,  0, // 5544-5545
 0,  0,  0, // 5546-5548
 0,  0,  0, // 5549-5551
 0,  0,  0, // 5552-5554
 0,  0,  0, // 5555-5557
 0,  0,  0, // 5558-5560
 0,  0,  0, // 5561-5563
 0,  0,  0, // 5564-5566
 0,  0,  0, // 5567-5569
 0,  0, // 5570-5571
 0,  0,  0, // 5572-5574
 0,  0,  0, // 5575-5577
 0,  0,  0, // 5578-5580
 0,  0,  0, // 5581-5583
 0,  0,  0, // 5584-5586
 0,  0,  0, // 5587-5589
 0,  0,  0, // 5590-5592
 0,  0,  0, // 5593-5595
 0,  0, // 5596-5597
 0,  0,  0, // 5598-5600
 0,  0,  0, // 5601-5603
 0,  0,  0, // 5604-5606
 0,  0,  0, // 5607-5609
 0,  0,  0, // 5610-5612
 0,  0,  0, // 5613-5615
 0,  0,  0, // 5616-5618
 0,  0,  0, // 5619-5621
 0,  0,  0, // 5622-5624
 0,  0,  0, // 5625-5627
 0,  0,  0, // 5628-5630
 0,  0,  0, // 5631-5633
 0,  0,  0, // 5634-5636
 0,  0,  0, // 5637-5639
 0,  0,  0, // 5640-5642
 0,  0,  0, // 5643-5645
 0,  0,  0, // 5646-5648
 0,  0,  0, // 5649-5651
 0,  0,  0,  0, // 5652-5655
 0,  0,  0,  0, // 5656-5659
 0,  0,  0,  0, // 5660-5663
 0,  0,  0,  0, // 5664-5667
 0,  0,  0,  0, // 5668-5671
 0,  0,  0,  0, // 5672-5675
 0,  0,  0,  0, // 5676-5679
 0,  0,  0,  0, // 5680-5683
 0,  0,  0,  0, // 5684-5687
 0,  0,  0,  0, // 5688-5691
 0,  0,  0,  0, // 5692-5695
 0,  0,  0, // 5696-5698
 0,  0,  0, // 5699-5701
 0,  0,  0, // 5702-5704
 0,  0,  0, // 5705-5707
 0,  0,  0, // 5708-5710
 0,  0,  0, // 5711-5713
 0,  0,  0, // 5714-5716
 0,  0,  0, // 5717-5719
 0,  0,  0, // 5720-5722
 0,  0,  0, // 5723-5725
 0,  0,  0, // 5726-5728
 0,  0,  0, // 5729-5731
 0,  0,  0, // 5732-5734
 0,  0,  0, // 5735-5737
 0,  0,  0, // 5738-5740
 0,  0, // 5741-5742
 0,  0,  0, // 5743-5745
 0 // End bypass tables
};

static const llvm::InstrItinerary PPC440Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 1, 6, 0, 0 }, // 1 IIC_LdStSync
  { 1, 6, 11, 1, 4 }, // 2 IIC_IntSimple
  { 1, 6, 11, 4, 7 }, // 3 IIC_IntGeneral
  { 1, 11, 16, 7, 9 }, // 4 IIC_BrB
  { 0, 0, 0, 0, 0 }, // 5 IIC_VecFP
  { 1, 6, 11, 9, 12 }, // 6 IIC_IntCompare
  { 0, 0, 0, 0, 0 }, // 7 IIC_SprABORT
  { 0, 0, 0, 0, 0 }, // 8 IIC_LdStCOPY
  { 0, 0, 0, 0, 0 }, // 9 IIC_LdStPASTE
  { 1, 11, 16, 12, 15 }, // 10 IIC_BrCR
  { 0, 0, 0, 0, 0 }, // 11 IIC_LdStLD
  { 1, 16, 21, 15, 17 }, // 12 IIC_LdStDCBF
  { 1, 21, 26, 17, 20 }, // 13 IIC_LdStLoad
  { 0, 0, 0, 0, 0 }, // 14 IIC_IntDivD
  { 1, 26, 31, 20, 23 }, // 15 IIC_IntDivW
  { 0, 0, 0, 0, 0 }, // 16 IIC_FPDGeneral
  { 1, 31, 40, 23, 26 }, // 17 IIC_FPAddSub
  { 1, 40, 49, 26, 29 }, // 18 IIC_FPDivD
  { 0, 0, 0, 0, 0 }, // 19 IIC_FPSGeneral
  { 1, 31, 40, 29, 32 }, // 20 IIC_FPCompare
  { 1, 31, 40, 32, 35 }, // 21 IIC_FPGeneral
  { 0, 0, 0, 0, 0 }, // 22 IIC_VecGeneral
  { 0, 0, 0, 0, 0 }, // 23 IIC_VecComplex
  { 1, 21, 26, 35, 38 }, // 24 IIC_LdStStore
  { 0, 0, 0, 0, 0 }, // 25 IIC_IntRotateDI
  { 1, 49, 58, 38, 41 }, // 26 IIC_FPDivS
  { 1, 31, 40, 41, 45 }, // 27 IIC_FPFused
  { 0, 0, 0, 0, 0 }, // 28 IIC_FPSqrtD
  { 0, 0, 0, 0, 0 }, // 29 IIC_FPSqrtS
  { 1, 16, 21, 45, 48 }, // 30 IIC_LdStICBI
  { 1, 6, 11, 48, 52 }, // 31 IIC_IntISEL
  { 1, 58, 74, 0, 0 }, // 32 IIC_SprISYNC
  { 1, 74, 81, 52, 55 }, // 33 IIC_LdStLWARX
  { 1, 21, 26, 55, 59 }, // 34 IIC_LdStLoadUpd
  { 1, 21, 26, 59, 63 }, // 35 IIC_LdStLoadUpdX
  { 0, 0, 0, 0, 0 }, // 36 IIC_LdStLDARX
  { 0, 0, 0, 0, 0 }, // 37 IIC_LdStLDU
  { 0, 0, 0, 0, 0 }, // 38 IIC_LdStLDUX
  { 1, 21, 26, 63, 66 }, // 39 IIC_LdStLFD
  { 1, 16, 21, 66, 70 }, // 40 IIC_LdStLFDU
  { 1, 16, 21, 70, 74 }, // 41 IIC_LdStLFDUX
  { 1, 16, 21, 74, 77 }, // 42 IIC_LdStLHA
  { 1, 16, 21, 77, 80 }, // 43 IIC_LdStLHAU
  { 1, 16, 21, 80, 83 }, // 44 IIC_LdStLHAUX
  { 1, 16, 21, 83, 86 }, // 45 IIC_LdStLMW
  { 0, 0, 0, 0, 0 }, // 46 IIC_LdStLWA
  { 0, 0, 0, 0, 0 }, // 47 IIC_IntMulHD
  { 1, 11, 16, 86, 89 }, // 48 IIC_BrMCR
  { 1, 11, 16, 89, 92 }, // 49 IIC_BrMCRX
  { 1, 11, 16, 92, 94 }, // 50 IIC_SprMFCR
  { 1, 81, 86, 94, 96 }, // 51 IIC_SprMFSPR
  { 1, 11, 16, 96, 99 }, // 52 IIC_IntMFFS
  { 1, 11, 16, 99, 101 }, // 53 IIC_SprMFMSR
  { 0, 0, 0, 0, 0 }, // 54 IIC_SprMFCRF
  { 0, 0, 0, 0, 0 }, // 55 IIC_SprMFPMR
  { 1, 11, 16, 101, 103 }, // 56 IIC_SprMFSR
  { 1, 81, 86, 103, 105 }, // 57 IIC_SprMFTB
  { 0, 0, 0, 0, 0 }, // 58 IIC_SprMSGSYNC
  { 1, 81, 86, 105, 107 }, // 59 IIC_SprMTSPR
  { 1, 11, 16, 107, 110 }, // 60 IIC_IntMTFSB0
  { 1, 11, 16, 110, 112 }, // 61 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 62 IIC_SprMTMSRD
  { 0, 0, 0, 0, 0 }, // 63 IIC_SprMTPMR
  { 1, 81, 86, 112, 114 }, // 64 IIC_SprMTSR
  { 1, 11, 16, 114, 117 }, // 65 IIC_IntMulHW
  { 1, 11, 16, 117, 120 }, // 66 IIC_IntMulHWU
  { 1, 11, 16, 120, 123 }, // 67 IIC_IntMulLI
  { 0, 0, 0, 0, 0 }, // 68 IIC_VecPerm
  { 1, 16, 21, 123, 126 }, // 69 IIC_LdStSTFD
  { 1, 16, 21, 126, 130 }, // 70 IIC_LdStSTFDU
  { 1, 11, 16, 130, 132 }, // 71 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 72 IIC_IntRFID
  { 0, 0, 0, 0, 0 }, // 73 IIC_IntRotateD
  { 1, 6, 11, 132, 135 }, // 74 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 75 IIC_SprSLBFEE
  { 0, 0, 0, 0, 0 }, // 76 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 77 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprSLBIEG
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprSLBMFEV
  { 0, 0, 0, 0, 0 }, // 81 IIC_SprSLBMTE
  { 0, 0, 0, 0, 0 }, // 82 IIC_SprSLBSYNC
  { 1, 6, 11, 135, 138 }, // 83 IIC_IntShift
  { 1, 74, 81, 138, 141 }, // 84 IIC_LdStSTWCX
  { 1, 21, 26, 141, 145 }, // 85 IIC_LdStSTU
  { 1, 21, 26, 145, 149 }, // 86 IIC_LdStSTUX
  { 1, 21, 26, 149, 152 }, // 87 IIC_LdStSTD
  { 1, 74, 81, 152, 155 }, // 88 IIC_LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 89 IIC_SprSTOP
  { 0, 0, 0, 0, 0 }, // 90 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 91 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 92 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 93 IIC_SprTLBIEL
  { 1, 11, 16, 0, 0 }, // 94 IIC_SprTLBSYNC
  { 1, 11, 16, 155, 157 }, // 95 IIC_IntTrapW
  { 0, 0, 0, 0, 0 }, // 96 IIC_VecFPCompare
  { 0, 0, 0, 0, 0 }, // 97 VADDUBM_VADDUDM_VADDUHM_VADDUWM_VEXTSB2D_VEXTSB2Ds_VEXTSB2W_VEXTSB2Ws_VEXTSH2D_VEXTSH2Ds_VEXTSH2W_VEXTSH2Ws_VEXTSW2D_VEXTSW2Ds_VSLD_VSRD_VSUBUBM_VSUBUDM_VSUBUHM_VSUBUWM_VPOPCNTB_VPOPCNTH_VSRAD_MTVSRDD_VEQV_VNAND_VNEGD_VNEGW_VORC_XXLAND_XXLANDC_XXLEQV_XXLEQVOnes_XXLNAND_XXLNOR_XXLOR_XXLORf_XXLORC_XXLXOR_XXLXORdpz_XXLXORspz_XXLXORz
  { 0, 0, 0, 0, 0 }, // 98 VAND_VANDC_V_SET0_V_SET0B_V_SET0H_VSLB_VSLH_VSLW_VSRB_VSRH_VSRW_VRLB_VRLD_VRLH_VRLW_VSRAB_VSRAH_VSRAW_XVABSDP_XVABSSP_XVNABSDP_XVNABSSP_XVCPSGNDP_XVCPSGNSP_XVIEXPDP_XVIEXPSP_XVXEXPDP_XVXEXPSP_VRLDMI_VRLDNM_VRLWMI_VRLWNM_VMRGEW_VMRGOW_VNOR_VOR_VSEL_VXOR_XVNEGDP_XVNEGSP_XSABSQP_XSCPSGNQP_XSIEXPQP_XSNABSQP_XSNEGQP_XSXEXPQP
  { 0, 0, 0, 0, 0 }, // 99 XXSEL
  { 1, 81, 86, 157, 159 }, // 100 TABORTDC_TABORTDCI_TABORTWC_TABORTWCI
  { 1, 11, 16, 159, 162 }, // 101 MTFSB0_MTFSB1
  { 1, 11, 16, 162, 165 }, // 102 MFFSCDRN_MFFSCDRNI_MFFSCRN_MFFSCRNI
  { 1, 6, 11, 165, 168 }, // 103 CMPRB_CMPRB8_CMPEQB
  { 0, 0, 0, 0, 0 }, // 104 TD_TDI
  { 1, 11, 16, 168, 170 }, // 105 TW_TWI
  { 1, 31, 40, 170, 173 }, // 106 FCMPUD_FCMPUS_FTDIV_FTSQRT
  { 0, 0, 0, 0, 0 }, // 107 XSTSTDCDP_XSTSTDCSP
  { 0, 0, 0, 0, 0 }, // 108 XSMAXCDP_XSMAXDP_XSMAXJDP_XSMINCDP_XSMINDP_XSMINJDP_XSXSIGDP_XSCVSPDPN
  { 1, 31, 40, 173, 176 }, // 109 XSCMPEQDP_XSCMPEXPDP_XSCMPGEDP_XSCMPGTDP_XSCMPODP_XSCMPUDP_XSTDIVDP_XSTSQRTDP
  { 1, 6, 11, 176, 179 }, // 110 CNTLZD_CNTLZD_rec_CNTLZW_CNTLZW8_CNTLZW8_rec_CNTLZW_rec_CNTTZD_CNTTZD_rec_CNTTZW_CNTTZW8_CNTTZW8_rec_CNTTZW_rec_POPCNTD_POPCNTW_CMPB_CMPB8_SETB_SETB8_BPERMD
  { 0, 0, 0, 0, 0 }, // 111 SLD_SRD_SRAD
  { 0, 0, 0, 0, 0 }, // 112 SRADI_EXTSWSLI_32_64_EXTSWSLI_SRADI_32_RLDIC
  { 0, 0, 0, 0, 0 }, // 113 MFVRD_MFVSRD_MTVRD_MTVSRD_MTVRWA_MTVRWZ_MTVSRWA_MTVSRWZ_MFVSRWZ_MFVRWZ
  { 1, 6, 11, 179, 182 }, // 114 CMPLW_CMPLWI_CMPW_CMPWI_CMPD_CMPDI_CMPLD_CMPLDI
  { 1, 6, 11, 182, 185 }, // 115 SUBFC_SUBFC8_SUBFC8O_SUBFCO_SUBFIC_SUBFIC8_ANDI8_rec_ANDIS8_rec_ANDIS_rec_ANDI_rec_ADDC_ADDC8_ADDC8O_ADDCO_ADDIC_ADDIC8_ADDIC_rec_ADDE_ADDE8_ADDE8O_ADDE8O_rec_ADDE8_rec_ADDEO_ADDEO_rec_ADDE_rec_ADDME_ADDME8_ADDME8O_ADDME8O_rec_ADDME8_rec_ADDMEO_ADDMEO_rec_ADDME_rec_ADDZE_ADDZE8_ADDZE8O_ADDZE8O_rec_ADDZE8_rec_ADDZEO_ADDZEO_rec_ADDZE_rec_SUBF_SUBF8_SUBF8O_SUBF8O_rec_SUBF8_rec_SUBFE_SUBFE8_SUBFE8O_SUBFE8O_rec_SUBFE8_rec_SUBFEO_SUBFEO_rec_SUBFE_rec_SUBFME_SUBFME8_SUBFME8O_SUBFME8O_rec_SUBFME8_rec_SUBFMEO_SUBFMEO_rec_SUBFME_rec_SUBFO_SUBFO_rec_SUBFZE_SUBFZE8_SUBFZE8O_SUBFZE8O_rec_SUBFZE8_rec_SUBFZEO_SUBFZEO_rec_SUBFZE_rec_SUBF_rec_POPCNTB_LA
  { 1, 6, 11, 185, 188 }, // 116 ADD4_ADD4O_ADD4O_rec_ADD4_rec_ADD8_ADD8O_ADD8O_rec_ADD8_rec_NEG_NEG8_NEG8O_NEG8O_rec_NEG8_rec_NEGO_NEGO_rec_NEG_rec_ADDI_ADDI8_ADDIS_ADDIS8_LI_LI8_LIS_LIS8_OR_OR8_OR8_rec_ORI_ORI8_ORIS_ORIS8_OR_rec_XOR_XOR8_XOR8_rec_XORI_XORI8_XORIS_XORIS8_XOR_rec_NAND_NAND8_NAND8_rec_NAND_rec_AND_AND8_AND8_rec_ANDC_ANDC8_ANDC8_rec_ANDC_rec_AND_rec_NOR_NOR8_NOR8_rec_NOR_rec_ORC_ORC8_ORC8_rec_ORC_rec_EQV_EQV8_EQV8_rec_EQV_rec_EXTSB_EXTSB8_EXTSB8_32_64_EXTSB8_rec_EXTSB_rec_EXTSH_EXTSH8_EXTSH8_32_64_EXTSH8_rec_EXTSH_rec_EXTSW_EXTSW_32_EXTSW_32_64_EXTSW_32_64_rec_EXTSW_rec_ADD4TLS_ADD8TLS_ADD8TLS__NOP
  { 0, 0, 0, 0, 0 }, // 117 ADDIStocHA_ADDIStocHA8_ADDItocL_COPY
  { 1, 11, 16, 188, 191 }, // 118 MCRF
  { 1, 11, 16, 191, 194 }, // 119 MCRXRX
  { 0, 0, 0, 0, 0 }, // 120 XSNABSDP_XSXEXPDP_XSABSDP_XSNEGDP_XSCPSGNDP
  { 1, 11, 16, 194, 196 }, // 121 RFEBB
  { 1, 81, 86, 196, 198 }, // 122 TBEGIN_TRECHKPT
  { 1, 21, 26, 198, 201 }, // 123 WAIT
  { 0, 0, 0, 0, 0 }, // 124 RLDCL_RLDCR
  { 1, 6, 11, 201, 204 }, // 125 RLWIMI_RLWIMI8
  { 0, 0, 0, 0, 0 }, // 126 RLDICL_RLDICL_32_RLDICL_32_64_RLDICR_RLDICR_32_RLDIMI
  { 0, 0, 0, 0, 0 }, // 127 MFOCRF_MFOCRF8
  { 1, 11, 16, 204, 207 }, // 128 MTOCRF_MTOCRF8
  { 1, 11, 16, 207, 210 }, // 129 CR6SET_CR6UNSET_CRSET_CRUNSET_CRAND_CRANDC_CRNAND_CRNOR_CROR_CRORC_CREQV_CRXOR
  { 1, 6, 11, 210, 213 }, // 130 SLW_SLW8_SRW_SRW8_RLWINM_RLWINM8_RLWNM_RLWNM8
  { 1, 31, 40, 213, 216 }, // 131 FABSD_FABSS_FNABSD_FNABSS_FNEGD_FNEGS_FCPSGND_FCPSGNS_FMR
  { 1, 6, 11, 216, 219 }, // 132 SRAW_SRAWI
  { 1, 6, 11, 219, 223 }, // 133 ISEL_ISEL8
  { 0, 0, 0, 0, 0 }, // 134 XSIEXPDP
  { 1, 81, 86, 223, 225 }, // 135 TRECLAIM_TSR_TABORT
  { 1, 21, 26, 225, 228 }, // 136 MFVSCR
  { 1, 21, 26, 228, 231 }, // 137 MTVSCR
  { 0, 0, 0, 0, 0 }, // 138 VCMPNEZB_VCMPNEZH_VCMPNEZW_VCMPEQUB_VCMPEQUD_VCMPEQUH_VCMPEQUW_VCMPNEB_VCMPNEH_VCMPNEW_VCMPEQFP_VCMPEQFP_rec_VCMPGEFP_VCMPGEFP_rec_VCMPGTFP_VCMPGTFP_rec_VCMPBFP_VCMPBFP_rec_VCMPGTSB_VCMPGTSB_rec_VCMPGTSD_VCMPGTSD_rec_VCMPGTSH_VCMPGTSH_rec_VCMPGTSW_VCMPGTSW_rec_VCMPGTUB_VCMPGTUB_rec_VCMPGTUD_VCMPGTUD_rec_VCMPGTUH_VCMPGTUH_rec_VCMPGTUW_VCMPGTUW_rec_VCMPNEB_rec_VCMPNEH_rec_VCMPNEW_rec_VCMPNEZB_rec_VCMPNEZH_rec_VCMPNEZW_rec_VCMPEQUB_rec_VCMPEQUD_rec_VCMPEQUH_rec_VCMPEQUW_rec_XVCMPEQDP_XVCMPEQDP_rec_XVCMPEQSP_XVCMPEQSP_rec_XVCMPGEDP_XVCMPGEDP_rec_XVCMPGESP_XVCMPGESP_rec_XVCMPGTDP_XVCMPGTDP_rec_XVCMPGTSP_XVCMPGTSP_rec
  { 0, 0, 0, 0, 0 }, // 139 VABSDUB_VABSDUH_VABSDUW_VCLZB_VCLZD_VCLZH_VCLZW_VCTZB_VCTZD_VCTZH_VCTZW_VPOPCNTW_VPOPCNTD_VPRTYBD_VPRTYBW
  { 0, 0, 0, 0, 0 }, // 140 VADDUBS_VADDUHS_VADDUWS_VAVGSB_VAVGSH_VAVGSW_VAVGUB_VAVGUH_VAVGUW_VADDSBS_VADDSHS_VADDSWS_VMAXFP_VMINFP_VMAXSB_VMAXSD_VMAXSH_VMAXSW_VMAXUB_VMAXUD_VMAXUH_VMAXUW_VMINSB_VMINSD_VMINSH_VMINSW_VMINUB_VMINUD_VMINUH_VMINUW_VBPERMD_VADDCUW_VSHASIGMAD_VSHASIGMAW_VSUBSBS_VSUBSHS_VSUBSWS_VSUBUBS_VSUBUHS_VSUBUWS_VSUBCUW_XVMAXDP_XVMAXSP_XVMINDP_XVMINSP_XVTSTDCDP_XVTSTDCSP_XVXSIGDP_XVXSIGSP
  { 1, 31, 40, 231, 234 }, // 141 XVTDIVDP_XVTDIVSP_XVTSQRTDP_XVTSQRTSP
  { 0, 0, 0, 0, 0 }, // 142 VADDFP_VCTSXS_VCTSXS_0_VCTUXS_VCTUXS_0_VEXPTEFP_VLOGEFP_VMADDFP_VMHADDSHS_VNMSUBFP_VREFP_VRFIM_VRFIN_VRFIP_VRFIZ_VRSQRTEFP_XVADDDP_XVADDSP_XVCVDPSP_XVCVDPSXDS_XVCVDPSXWS_XVCVDPUXDS_XVCVDPUXWS_XVCVHPSP_XVCVSPDP_XVCVSPHP_XVCVSPSXDS_XVCVSPSXWS_XVCVSPUXDS_XVCVSPUXWS_XVCVSXDDP_XVCVSXDSP_XVCVSXWDP_XVCVSXWSP_XVCVUXDDP_XVCVUXDSP_XVCVUXWDP_XVCVUXWSP_XVMADDADP_XVMADDASP_XVMADDMDP_XVMADDMSP_XVMSUBADP_XVMSUBASP_XVMSUBMDP_XVMSUBMSP_XVMULDP_XVMULSP_XVNMADDADP_XVNMADDASP_XVNMADDMDP_XVNMADDMSP_XVNMSUBADP_XVNMSUBASP_XVNMSUBMDP_XVNMSUBMSP_XVRDPI_XVRDPIC_XVRDPIM_XVRDPIP_XVRDPIZ_XVREDP_XVRESP_XVRSPI_XVRSPIC_XVRSPIM_XVRSPIP_XVRSPIZ_XVRSQRTEDP_XVRSQRTESP_XVSUBDP_XVSUBSP_VCFSX_VCFSX_0_VCFUX_VCFUX_0_VMHRADDSHS_VMLADDUHM_VMSUMMBM_VMSUMSHM_VMSUMSHS_VMSUMUBM_VMSUMUHM_VMSUMUDM_VMSUMUHS_VMULESB_VMULESH_VMULESW_VMULEUB_VMULEUH_VMULEUW_VMULOSB_VMULOSH_VMULOSW_VMULOUB_VMULOUH_VMULOUW_VSUM2SWS_VSUM4SBS_VSUM4SHS_VSUM4UBS_VSUMSWS
  { 0, 0, 0, 0, 0 }, // 143 VSUBFP_VMULUWM
  { 0, 0, 0, 0, 0 }, // 144 MADDHD_MADDHDU_MADDLD_MADDLD8_MULLD_MULLDO
  { 1, 11, 16, 234, 237 }, // 145 MULHD_MULHW_MULLW_MULLWO
  { 1, 11, 16, 237, 240 }, // 146 MULHDU_MULHWU
  { 1, 11, 16, 240, 243 }, // 147 MULLI_MULLI8
  { 1, 31, 40, 243, 246 }, // 148 FRSP_FRIMD_FRIMS_FRIND_FRINS_FRIPD_FRIPS_FRIZD_FRIZS_FRE_FRES_FADDS_FMSUBS_FMADDS_FSUBS_FCFID_FCFIDS_FCFIDU_FCFIDUS_FCTID_FCTIDU_FCTIDUZ_FCTIDZ_FCTIW_FCTIWU_FCTIWUZ_FCTIWZ_FRSQRTE_FRSQRTES_FNMADDS_FNMSUBS_FSELD_FSELS_FMULS
  { 1, 31, 40, 246, 249 }, // 149 FADD_FSUB
  { 1, 31, 40, 249, 253 }, // 150 FMSUB_FMADD_FNMADD_FNMSUB_FMUL
  { 0, 0, 0, 0, 0 }, // 151 XSMADDADP_XSMADDASP_XSMADDMDP_XSMADDMSP_XSMSUBADP_XSMSUBASP_XSMSUBMDP_XSMSUBMSP_XSMULDP_XSMULSP_XSNMADDADP_XSNMADDASP_XSNMADDMDP_XSNMADDMSP_XSNMSUBADP_XSNMSUBASP_XSNMSUBMDP_XSNMSUBMSP
  { 1, 31, 40, 253, 256 }, // 152 FSELD_rec_FSELS_rec
  { 1, 11, 16, 256, 259 }, // 153 MULHDU_rec_MULHWU_rec
  { 1, 11, 16, 259, 262 }, // 154 MULHD_rec_MULHW_rec_MULLWO_rec_MULLW_rec
  { 0, 0, 0, 0, 0 }, // 155 MULLDO_rec_MULLD_rec
  { 1, 31, 40, 262, 265 }, // 156 FRIMD_rec_FRIMS_rec_FRIND_rec_FRINS_rec_FRIPD_rec_FRIPS_rec_FRIZD_rec_FRIZS_rec_FRES_rec_FRE_rec_FADDS_rec_FSUBS_rec_FMSUBS_rec_FNMSUBS_rec_FMADDS_rec_FNMADDS_rec_FCFIDS_rec_FCFIDUS_rec_FCFIDU_rec_FCFID_rec_FCTIDUZ_rec_FCTIDU_rec_FCTIDZ_rec_FCTID_rec_FCTIWUZ_rec_FCTIWU_rec_FCTIWZ_rec_FCTIW_rec_FMULS_rec_FRSQRTES_rec_FRSQRTE_rec_FRSP_rec
  { 1, 31, 40, 265, 268 }, // 157 FADD_rec_FSUB_rec
  { 1, 31, 40, 268, 272 }, // 158 FMSUB_rec_FNMSUB_rec_FMADD_rec_FNMADD_rec_FMUL_rec
  { 0, 0, 0, 0, 0 }, // 159 XSADDDP_XSADDSP_XSCVDPHP_XSCVDPSP_XSCVDPSXDS_XSCVDPSXDSs_XSCVDPSXWS_XSCVDPUXDS_XSCVDPUXDSs_XSCVDPUXWS_XSCVDPSXWSs_XSCVDPUXWSs_XSCVHPDP_XSCVSPDP_XSCVSXDDP_XSCVSXDSP_XSCVUXDDP_XSCVUXDSP_XSRDPI_XSRDPIC_XSRDPIM_XSRDPIP_XSRDPIZ_XSREDP_XSRESP_XSRSQRTEDP_XSRSQRTESP_XSSUBDP_XSSUBSP_XSCVDPSPN_XSRSP
  { 1, 21, 26, 272, 275 }, // 160 LVSL_LVSR
  { 0, 0, 0, 0, 0 }, // 161 VSPLTISB_VSPLTISH_VSPLTISW_VSPLTB_VSPLTBs_VSPLTH_VSPLTHs_VSPLTW_XXMRGHW_XXMRGLW_XXPERM_XXPERMR_XXSLDWI_XXSLDWIs_XXSPLTIB_XXSPLTW_XXSPLTWs_XXPERMDI_XXPERMDIs
  { 0, 0, 0, 0, 0 }, // 162 V_SETALLONES_V_SETALLONESB_V_SETALLONESH_VBPERMQ_VGBBD_VMRGHB_VMRGHH_VMRGHW_VMRGLB_VMRGLH_VMRGLW_VPERM_VPERMR_VPERMXOR_VPKPX_VPKSDSS_VPKSDUS_VPKSHSS_VPKSHUS_VPKSWSS_VPKSWUS_VPKUDUM_VPKUDUS_VPKUHUM_VPKUHUS_VPKUWUM_VPKUWUS_VSL_VSLDOI_VSLO_VSLV_VSR_VSRO_VSRV_VUPKHPX_VUPKHSB_VUPKHSH_VUPKHSW_VUPKLPX_VUPKLSB_VUPKLSH_VUPKLSW_XXBRD_XXBRH_XXBRQ_XXBRW_XXEXTRACTUW_XXINSERTW_VADDCUQ_VADDECUQ_VADDEUQM_VMUL10CUQ_VMUL10ECUQ_VMUL10EUQ_VMUL10UQ_VSUBCUQ_VSUBECUQ_VSUBEUQM_XSTSTDCQP_XSXSIGQP_BCDCFN_rec_BCDCFZ_rec_BCDCPSGN_rec_BCDCTN_rec_BCDCTZ_rec_BCDSETSGN_rec_BCDS_rec_BCDTRUNC_rec_BCDUS_rec_BCDUTRUNC_rec
  { 0, 0, 0, 0, 0 }, // 163 VEXTRACTUB_VEXTRACTUH_VEXTRACTUW_VINSERTB_VINSERTD_VINSERTH_VINSERTW_MFVSRLD_MTVSRWS_VCLZLSBB_VCTZLSBB_VEXTRACTD_VEXTUBLX_VEXTUBRX_VEXTUHLX_VEXTUHRX_VEXTUWLX_VEXTUWRX_VPRTYBQ_VADDUQM_VSUBUQM
  { 1, 31, 40, 275, 278 }, // 164 XSCMPEXPQP_XSCMPOQP_XSCMPUQP
  { 0, 0, 0, 0, 0 }, // 165 BCDSR_rec_XSADDQP_XSADDQPO_XSCVDPQP_XSCVQPDP_XSCVQPDPO_XSCVQPSDZ_XSCVQPSWZ_XSCVQPUDZ_XSCVQPUWZ_XSCVSDQP_XSCVUDQP_XSRQPI_XSRQPIX_XSRQPXP_XSSUBQP_XSSUBQPO
  { 0, 0, 0, 0, 0 }, // 166 BCDCTSQ_rec
  { 0, 0, 0, 0, 0 }, // 167 XSMADDQP_XSMADDQPO_XSMSUBQP_XSMSUBQPO_XSMULQP_XSMULQPO_XSNMADDQP_XSNMADDQPO_XSNMSUBQP_XSNMSUBQPO
  { 0, 0, 0, 0, 0 }, // 168 BCDCFSQ_rec
  { 0, 0, 0, 0, 0 }, // 169 XSDIVQP_XSDIVQPO
  { 0, 0, 0, 0, 0 }, // 170 XSSQRTQP_XSSQRTQPO
  { 1, 21, 26, 278, 281 }, // 171 LXVL_LXVLL
  { 1, 21, 26, 281, 284 }, // 172 LVEBX_LVEHX_LVEWX_LVX_LVXL
  { 1, 21, 26, 284, 287 }, // 173 LXSIBZX_LXSIHZX_LXSDX_LXVB16X_LXVD2X_LXVWSX_LXSIWZX_LXV_LXVX_LXSD
  { 0, 0, 0, 0, 0 }, // 174 DFLOADf64_XFLOADf64_LIWZX
  { 1, 16, 21, 287, 289 }, // 175 DCBF_DCBFEP_DCBST_DCBSTEP_DCBT_DCBTEP_DCBZ_DCBZEP_DCBZL_DCBZLEP_DCBTST_DCBTSTEP
  { 0, 0, 0, 0, 0 }, // 176 CP_COPY_CP_COPY8
  { 0, 0, 0, 0, 0 }, // 177 CP_PASTE_CP_PASTE8
  { 1, 16, 21, 289, 292 }, // 178 ICBI_ICBIEP
  { 1, 21, 26, 292, 295 }, // 179 ICBT_ICBTLS_LBZ_LBZ8_LBZCIX_LBZX_LBZX8_LBZXTLS_LBZXTLS__LBZXTLS_32_LDBRX_LDCIX_LHBRX_LHBRX8_LHZ_LHZ8_LHZCIX_LHZX_LHZX8_LHZXTLS_LHZXTLS__LHZXTLS_32_LWBRX_LWBRX8_LWZ_LWZ8_LWZCIX_LWZX_LWZX8_LWZXTLS_LWZXTLS__LWZXTLS_32_EnforceIEIO_LSWI
  { 1, 74, 81, 295, 298 }, // 180 LBARX_LBARXL_LHARX_LHARXL_LWARX_LWARXL
  { 0, 0, 0, 0, 0 }, // 181 LD_LDX_LDXTLS_LDXTLS__DARN
  { 0, 0, 0, 0, 0 }, // 182 LDARX_LDARXL
  { 0, 0, 0, 0, 0 }, // 183 CP_ABORT
  { 1, 58, 74, 0, 0 }, // 184 ISYNC
  { 0, 0, 0, 0, 0 }, // 185 MSGSYNC
  { 1, 11, 16, 0, 0 }, // 186 TLBSYNC
  { 1, 1, 6, 0, 0 }, // 187 SYNC
  { 1, 16, 21, 298, 301 }, // 188 LMW
  { 1, 21, 26, 301, 304 }, // 189 LFIWZX_LFDX_LFD
  { 0, 0, 0, 0, 0 }, // 190 SLBIA
  { 0, 0, 0, 0, 0 }, // 191 SLBIE
  { 0, 0, 0, 0, 0 }, // 192 SLBMFEE
  { 0, 0, 0, 0, 0 }, // 193 SLBMFEV
  { 0, 0, 0, 0, 0 }, // 194 SLBMTE
  { 0, 0, 0, 0, 0 }, // 195 TLBIEL
  { 1, 21, 26, 304, 308 }, // 196 LHZU_LHZU8_LWZU_LWZU8
  { 1, 21, 26, 308, 312 }, // 197 LHZUX_LHZUX8_LWZUX_LWZUX8
  { 1, 81, 86, 312, 314 }, // 198 TEND
  { 1, 74, 81, 314, 317 }, // 199 STBCX_STHCX_STWCX
  { 1, 74, 81, 317, 320 }, // 200 STDCX
  { 0, 0, 0, 0, 0 }, // 201 LDMX
  { 1, 16, 21, 320, 323 }, // 202 LHA_LHA8_LHAX_LHAX8_LWAX_LWAX_32
  { 0, 0, 0, 0, 0 }, // 203 CP_PASTE8_rec_CP_PASTE_rec
  { 0, 0, 0, 0, 0 }, // 204 LWA_LWA_32
  { 1, 81, 86, 323, 325 }, // 205 TCHECK
  { 1, 21, 26, 325, 328 }, // 206 LFIWAX
  { 1, 21, 26, 328, 331 }, // 207 LXSIWAX
  { 0, 0, 0, 0, 0 }, // 208 LIWAX
  { 1, 21, 26, 331, 334 }, // 209 LFSX_LFS
  { 1, 21, 26, 334, 337 }, // 210 LXSSP_LXSSPX
  { 0, 0, 0, 0, 0 }, // 211 XFLOADf32_DFLOADf32
  { 1, 16, 21, 337, 340 }, // 212 LHAU_LHAU8
  { 1, 16, 21, 340, 343 }, // 213 LHAUX_LHAUX8_LWAUX
  { 1, 21, 26, 343, 346 }, // 214 LXVH8X_LXVDSX_LXVW4X
  { 1, 16, 21, 346, 349 }, // 215 STFD_STFDX_STFIWX_STFS_STFSX_STXSD_STXSDX_STXSIBX_STXSIBXv_STXSIHX_STXSIHXv_STXSIWX_STXSSP_STXSSPX
  { 1, 21, 26, 349, 352 }, // 216 STW_STW8_STDBRX_STHBRX_STWBRX_STB_STB8_STH_STH8_STBX_STBX8_STBXTLS_STBXTLS__STBXTLS_32_STHX_STHX8_STHXTLS_STHXTLS__STHXTLS_32_STWX_STWX8_STWXTLS_STWXTLS__STWXTLS_32
  { 0, 0, 0, 0, 0 }, // 217 DFSTOREf32_DFSTOREf64_XFSTOREf32_XFSTOREf64_STIWX
  { 1, 21, 26, 352, 355 }, // 218 STD_STDX_STDXTLS_STDXTLS_
  { 1, 21, 26, 355, 358 }, // 219 STBCIX_STDCIX_STHCIX_STWCIX_STSWI
  { 0, 0, 0, 0, 0 }, // 220 SLBIEG
  { 1, 16, 21, 358, 361 }, // 221 STMW
  { 0, 0, 0, 0, 0 }, // 222 TLBIE
  { 1, 21, 26, 361, 364 }, // 223 STVEBX_STVEHX_STVEWX_STVX_STVXL
  { 1, 16, 21, 364, 367 }, // 224 STXV_STXVB16X_STXVD2X_STXVH8X_STXVW4X_STXVX
  { 1, 21, 26, 367, 370 }, // 225 STXVL_STXVLL
  { 1, 81, 86, 370, 372 }, // 226 MTCTR_MTCTR8_MTCTR8loop_MTCTRloop_MTLR_MTLR8
  { 1, 6, 11, 372, 375 }, // 227 MFVRSAVE_MFVRSAVEv_MTVRSAVE_MTVRSAVEv
  { 0, 0, 0, 0, 0 }, // 228 MFPMR
  { 0, 0, 0, 0, 0 }, // 229 MTPMR
  { 1, 81, 86, 375, 377 }, // 230 MFTB_MFTB8
  { 1, 81, 86, 377, 379 }, // 231 MFCTR_MFCTR8_MFLR_MFLR8_MFSPR_MFSPR8
  { 1, 11, 16, 379, 381 }, // 232 MFMSR
  { 1, 11, 16, 381, 383 }, // 233 MTMSR
  { 0, 0, 0, 0, 0 }, // 234 MTMSRD
  { 1, 81, 86, 383, 385 }, // 235 MTSPR_MTSPR8
  { 1, 26, 31, 385, 388 }, // 236 DIVW_DIVWO_DIVWU_DIVWUO_MODSW
  { 1, 26, 31, 388, 391 }, // 237 DIVWE_DIVWEO_DIVWEU_DIVWEUO_MODSD_MODUD_MODUW
  { 0, 0, 0, 0, 0 }, // 238 DIVD_DIVDO_DIVDU_DIVDUO
  { 0, 0, 0, 0, 0 }, // 239 DIVDE_DIVDEO_DIVDEU_DIVDEUO
  { 1, 26, 31, 391, 394 }, // 240 DIVWO_rec_DIVWUO_rec_DIVWU_rec_DIVW_rec
  { 0, 0, 0, 0, 0 }, // 241 DIVD_rec_DIVDO_rec_DIVDU_rec_DIVDUO_rec
  { 1, 26, 31, 394, 397 }, // 242 DIVWE_rec_DIVWEO_rec_DIVWEU_rec_DIVWEUO_rec
  { 0, 0, 0, 0, 0 }, // 243 DIVDE_rec_DIVDEO_rec_DIVDEU_rec_DIVDEUO_rec
  { 1, 11, 16, 397, 400 }, // 244 MTCRF_MTCRF8
  { 1, 6, 11, 400, 403 }, // 245 ADDC8O_rec_ADDC8_rec_ADDCO_rec_ADDC_rec_SUBFC8O_rec_SUBFC8_rec_SUBFCO_rec_SUBFC_rec
  { 1, 31, 40, 403, 406 }, // 246 FABSD_rec_FABSS_rec_FNABSD_rec_FNABSS_rec_FCPSGND_rec_FCPSGNS_rec_FNEGD_rec_FNEGS_rec_FMR_rec
  { 1, 11, 16, 406, 409 }, // 247 MCRFS
  { 1, 11, 16, 409, 412 }, // 248 MTFSF_MTFSF_rec_MTFSFI_MTFSFI_rec
  { 1, 11, 16, 412, 415 }, // 249 MTFSFb
  { 0, 0, 0, 0, 0 }, // 250 RLDCL_rec_RLDCR_rec
  { 0, 0, 0, 0, 0 }, // 251 RLDICL_rec_RLDICR_rec_RLDICL_32_rec_RLDIMI_rec
  { 1, 6, 11, 415, 418 }, // 252 RLWIMI8_rec_RLWIMI_rec
  { 1, 6, 11, 418, 421 }, // 253 RLWINM8_rec_RLWINM_rec_RLWNM8_rec_RLWNM_rec_SLW8_rec_SLW_rec_SRW8_rec_SRW_rec
  { 1, 6, 11, 421, 424 }, // 254 SRAWI_rec_SRAW_rec
  { 1, 11, 16, 424, 427 }, // 255 MFFS_MFFSCE_MFFSL_MFFS_rec
  { 1, 11, 16, 427, 429 }, // 256 MFCR_MFCR8
  { 0, 0, 0, 0, 0 }, // 257 EXTSWSLI_32_64_rec_SRADI_rec_EXTSWSLI_rec_RLDIC_rec
  { 0, 0, 0, 0, 0 }, // 258 SRAD_rec_SLD_rec_SRD_rec
  { 1, 40, 49, 429, 432 }, // 259 FDIV
  { 1, 40, 49, 432, 435 }, // 260 FDIV_rec
  { 0, 0, 0, 0, 0 }, // 261 XSSQRTDP
  { 0, 0, 0, 0, 0 }, // 262 FSQRT
  { 0, 0, 0, 0, 0 }, // 263 XVSQRTDP
  { 0, 0, 0, 0, 0 }, // 264 XVSQRTSP
  { 0, 0, 0, 0, 0 }, // 265 FSQRT_rec
  { 0, 0, 0, 0, 0 }, // 266 XSSQRTSP
  { 0, 0, 0, 0, 0 }, // 267 FSQRTS
  { 0, 0, 0, 0, 0 }, // 268 FSQRTS_rec
  { 1, 40, 49, 435, 438 }, // 269 XSDIVDP
  { 1, 49, 58, 438, 441 }, // 270 FDIVS
  { 1, 49, 58, 441, 444 }, // 271 FDIVS_rec
  { 1, 49, 58, 444, 447 }, // 272 XSDIVSP
  { 1, 49, 58, 447, 450 }, // 273 XVDIVSP
  { 1, 40, 49, 450, 453 }, // 274 XVDIVDP
  { 1, 16, 21, 453, 457 }, // 275 LFSU
  { 1, 16, 21, 457, 461 }, // 276 LFSUX
  { 1, 16, 21, 461, 465 }, // 277 STFDU_STFDUX_STFSU_STFSUX
  { 1, 21, 26, 465, 469 }, // 278 STBU_STBU8_STDU_STHU_STHU8_STWU_STWU8
  { 1, 21, 26, 469, 473 }, // 279 STBUX_STBUX8_STDUX_STHUX_STHUX8_STWUX_STWUX8
  { 1, 21, 26, 473, 477 }, // 280 LBZU_LBZU8
  { 1, 21, 26, 477, 481 }, // 281 LBZUX_LBZUX8
  { 0, 0, 0, 0, 0 }, // 282 LDU
  { 0, 0, 0, 0, 0 }, // 283 LDUX
  { 1, 16, 21, 481, 485 }, // 284 LFDU
  { 1, 16, 21, 485, 489 }, // 285 LFDUX
  { 0, 0, 0, 0, 0 }, // 286 VPMSUMB_VPMSUMD_VPMSUMH_VPMSUMW_VCIPHER_VCIPHERLAST_VNCIPHER_VNCIPHERLAST_VSBOX
  { 1, 11, 16, 489, 491 }, // 287 BCCCTR_BCCCTR8_BCCCTRL_BCCCTRL8_BCCL_BCCLA_BCCLR_BCCLRL_BCCTR_BCCTR8_BCCTR8n_BCCTRL_BCCTRL8_BCCTRL8n_BCCTRLn_BCCTRn_BDNZ_BDNZ8_BDNZA_BDNZAm_BDNZAp_BDNZm_BDNZp_BDZ_BDZ8_BDZA_BDZAm_BDZAp_BDZm_BDZp_BDNZL_BDNZLA_BDNZLAm_BDNZLAp_BDNZLR_BDNZLR8_BDNZLRL_BDNZLRLm_BDNZLRLp_BDNZLRm_BDNZLRp_BDNZLm_BDNZLp_BDZL_BDZLA_BDZLAm_BDZLAp_BDZLR_BDZLR8_BDZLRL_BDZLRLm_BDZLRLp_BDZLRm_BDZLRp_BDZLm_BDZLp_BL_BL_NOP_BL_TLS_BL8_BL8_NOP_BL8_NOP_TLS_BL8_TLS_BL8_TLS__BLA_BLA8_BLA8_NOP_BLR_BLR8_BLRL_TAILB_TAILB8_TAILBA_TAILBA8_TAILBCTR_TAILBCTR8_gBC_gBCA_gBCAat_gBCCTR_gBCCTRL_gBCL_gBCLA_gBCLAat_gBCLR_gBCLRL_gBCLat_gBCat_BCLR_BCLRL_BCLRLn_BCLRn_BCTR_BCTR8_BCTRL_BCTRL8_B_BA_BC_BCC_BCCA_BCL_BCLalways_BCLn_BCTRL8_LDinto_toc_BCTRL_LWZinto_toc_BCn_CTRL_DEP
  { 1, 11, 16, 491, 493 }, // 288 ADDPCIS
  { 1, 21, 26, 493, 496 }, // 289 LDAT_LWAT
  { 1, 21, 26, 496, 499 }, // 290 STDAT_STWAT
  { 1, 6, 11, 499, 502 }, // 291 BRINC
  { 0, 0, 0, 0, 0 }, // 292 EVABS_EVEQV_EVNAND_EVNEG_EVADDIW_EVADDW_EVAND_EVANDC_EVCMPEQ_EVCMPGTS_EVCMPGTU_EVCMPLTS_EVCMPLTU_EVCNTLSW_EVCNTLZW_EVEXTSB_EVEXTSH_EVMERGEHI_EVMERGEHILO_EVMERGELO_EVMERGELOHI_EVNOR_EVOR_EVORC_EVXOR_EVRLW_EVRLWI_EVRNDW_EVSLW_EVSLWI_EVSPLATFI_EVSPLATI_EVSRWIS_EVSRWIU_EVSRWS_EVSRWU_EVSUBFW_EVSUBIFW
  { 0, 0, 0, 0, 0 }, // 293 EVMRA_EVADDSMIAAW_EVADDSSIAAW_EVADDUMIAAW_EVADDUSIAAW_EVDIVWS_EVDIVWU_EVMHEGSMFAA_EVMHEGSMFAN_EVMHEGSMIAA_EVMHEGSMIAN_EVMHEGUMIAA_EVMHEGUMIAN_EVMHESMF_EVMHESMFA_EVMHESMFAAW_EVMHESMFANW_EVMHESMI_EVMHESMIA_EVMHESMIAAW_EVMHESMIANW_EVMHESSF_EVMHESSFA_EVMHESSFAAW_EVMHESSFANW_EVMHESSIAAW_EVMHESSIANW_EVMHEUMI_EVMHEUMIA_EVMHEUMIAAW_EVMHEUMIANW_EVMHEUSIAAW_EVMHEUSIANW_EVMHOGSMFAA_EVMHOGSMFAN_EVMHOGSMIAA_EVMHOGSMIAN_EVMHOGUMIAA_EVMHOGUMIAN_EVMHOSMF_EVMHOSMFA_EVMHOSMFAAW_EVMHOSMFANW_EVMHOSMI_EVMHOSMIA_EVMHOSMIAAW_EVMHOSMIANW_EVMHOSSF_EVMHOSSFA_EVMHOSSFAAW_EVMHOSSFANW_EVMHOSSIAAW_EVMHOSSIANW_EVMHOUMI_EVMHOUMIA_EVMHOUMIAAW_EVMHOUMIANW_EVMHOUSIAAW_EVMHOUSIANW_EVMWHSMF_EVMWHSMFA_EVMWHSMI_EVMWHSMIA_EVMWHSSF_EVMWHSSFA_EVMWHUMI_EVMWHUMIA_EVMWLSMIAAW_EVMWLSMIANW_EVMWLSSIAAW_EVMWLSSIANW_EVMWLUMI_EVMWLUMIA_EVMWLUMIAAW_EVMWLUMIANW_EVMWLUSIAAW_EVMWLUSIANW_EVMWSMF_EVMWSMFA_EVMWSMFAA_EVMWSMFAN_EVMWSMI_EVMWSMIA_EVMWSMIAA_EVMWSMIAN_EVMWSSF_EVMWSSFA_EVMWSSFAA_EVMWSSFAN_EVMWUMI_EVMWUMIA_EVMWUMIAA_EVMWUMIAN_EVSUBFSMIAAW_EVSUBFSSIAAW_EVSUBFUMIAAW_EVSUBFUSIAAW
  { 1, 21, 26, 502, 505 }, // 294 EVLDD_EVLDDX_EVLDH_EVLDHX_EVLDW_EVLDWX_EVLHHESPLAT_EVLHHESPLATX_EVLHHOSSPLAT_EVLHHOSSPLATX_EVLHHOUSPLAT_EVLHHOUSPLATX_EVLWHE_EVLWHEX_EVLWHOS_EVLWHOSX_EVLWHOU_EVLWHOUX_EVLWHSPLAT_EVLWHSPLATX_EVLWWSPLAT_EVLWWSPLATX
  { 1, 21, 26, 505, 508 }, // 295 EVSTDD_EVSTDDX_EVSTDH_EVSTDHX_EVSTDW_EVSTDWX_EVSTWHE_EVSTWHEX_EVSTWHO_EVSTWHOX_EVSTWWE_EVSTWWEX_EVSTWWO_EVSTWWOX
  { 1, 11, 16, 508, 510 }, // 296 HRFID_ATTN_CLRBHRB_MFBHRBE_NAP_RFCI_RFDI_RFMCI_SC
  { 1, 11, 16, 510, 512 }, // 297 RFI
  { 0, 0, 0, 0, 0 }, // 298 RFID
  { 1, 21, 26, 512, 515 }, // 299 DSS_DSSALL_DST_DST64_DSTST_DSTST64_DSTSTT_DSTSTT64_DSTT_DSTT64_ICBLQ_LBEPX_LHEPX_LWEPX_TLBIVAX_TLBLD_TLBLI_TLBRE_TLBRE2_TLBSX_TLBSX2_TLBSX2D_TLBWE_TLBWE2_MBAR_TRAP_DCCCI_ICCCI
  { 1, 21, 26, 515, 518 }, // 300 ICBLC_STBEPX_STHEPX_STWEPX
  { 1, 21, 26, 518, 521 }, // 301 LFDEPX
  { 1, 16, 21, 521, 524 }, // 302 STFDEPX
  { 1, 11, 16, 524, 526 }, // 303 MFSR_MFSRIN
  { 1, 81, 86, 526, 528 }, // 304 MTSR_MTSRIN
  { 1, 81, 86, 528, 530 }, // 305 MFDCR
  { 1, 81, 86, 530, 532 }, // 306 MTDCR
  { 1, 6, 11, 532, 535 }, // 307 NOP_GT_PWR6_NOP_GT_PWR7
  { 0, 0, 0, 0, 0 }, // 308 TLBIA
  { 1, 11, 16, 535, 537 }, // 309 WRTEE_WRTEEI
  { 1, 1, 6, 0, 0 }, // 310 MSYNC
  { 0, 0, 0, 0, 0 }, // 311 SLBSYNC
  { 0, 0, 0, 0, 0 }, // 312 SLBFEE_rec
  { 0, 0, 0, 0, 0 }, // 313 STOP
  { 1, 16, 21, 537, 539 }, // 314 DCBA_DCBI
  { 0, uint16_t(~0U), uint16_t(~0U), uint16_t(~0U), uint16_t(~0U) }// end marker
};

static const llvm::InstrItinerary G3Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 86, 87, 0, 0 }, // 1 IIC_LdStSync
  { 1, 87, 88, 0, 0 }, // 2 IIC_IntSimple
  { 1, 87, 88, 0, 0 }, // 3 IIC_IntGeneral
  { 1, 88, 89, 0, 0 }, // 4 IIC_BrB
  { 0, 0, 0, 0, 0 }, // 5 IIC_VecFP
  { 1, 87, 88, 0, 0 }, // 6 IIC_IntCompare
  { 0, 0, 0, 0, 0 }, // 7 IIC_SprABORT
  { 0, 0, 0, 0, 0 }, // 8 IIC_LdStCOPY
  { 0, 0, 0, 0, 0 }, // 9 IIC_LdStPASTE
  { 1, 89, 90, 0, 0 }, // 10 IIC_BrCR
  { 0, 0, 0, 0, 0 }, // 11 IIC_LdStLD
  { 1, 86, 87, 0, 0 }, // 12 IIC_LdStDCBF
  { 1, 90, 91, 0, 0 }, // 13 IIC_LdStLoad
  { 0, 0, 0, 0, 0 }, // 14 IIC_IntDivD
  { 1, 91, 92, 0, 0 }, // 15 IIC_IntDivW
  { 0, 0, 0, 0, 0 }, // 16 IIC_FPDGeneral
  { 1, 92, 93, 0, 0 }, // 17 IIC_FPAddSub
  { 1, 93, 94, 0, 0 }, // 18 IIC_FPDivD
  { 0, 0, 0, 0, 0 }, // 19 IIC_FPSGeneral
  { 1, 92, 93, 0, 0 }, // 20 IIC_FPCompare
  { 1, 92, 93, 0, 0 }, // 21 IIC_FPGeneral
  { 0, 0, 0, 0, 0 }, // 22 IIC_VecGeneral
  { 0, 0, 0, 0, 0 }, // 23 IIC_VecComplex
  { 1, 90, 91, 0, 0 }, // 24 IIC_LdStStore
  { 0, 0, 0, 0, 0 }, // 25 IIC_IntRotateDI
  { 1, 94, 95, 0, 0 }, // 26 IIC_FPDivS
  { 1, 95, 96, 0, 0 }, // 27 IIC_FPFused
  { 0, 0, 0, 0, 0 }, // 28 IIC_FPSqrtD
  { 0, 0, 0, 0, 0 }, // 29 IIC_FPSqrtS
  { 1, 86, 87, 0, 0 }, // 30 IIC_LdStICBI
  { 0, 0, 0, 0, 0 }, // 31 IIC_IntISEL
  { 1, 96, 97, 0, 0 }, // 32 IIC_SprISYNC
  { 1, 86, 87, 0, 0 }, // 33 IIC_LdStLWARX
  { 1, 90, 91, 0, 0 }, // 34 IIC_LdStLoadUpd
  { 1, 90, 91, 0, 0 }, // 35 IIC_LdStLoadUpdX
  { 0, 0, 0, 0, 0 }, // 36 IIC_LdStLDARX
  { 0, 0, 0, 0, 0 }, // 37 IIC_LdStLDU
  { 0, 0, 0, 0, 0 }, // 38 IIC_LdStLDUX
  { 1, 90, 91, 0, 0 }, // 39 IIC_LdStLFD
  { 1, 90, 91, 0, 0 }, // 40 IIC_LdStLFDU
  { 1, 90, 91, 0, 0 }, // 41 IIC_LdStLFDUX
  { 1, 90, 91, 0, 0 }, // 42 IIC_LdStLHA
  { 1, 90, 91, 0, 0 }, // 43 IIC_LdStLHAU
  { 1, 90, 91, 0, 0 }, // 44 IIC_LdStLHAUX
  { 1, 97, 98, 0, 0 }, // 45 IIC_LdStLMW
  { 0, 0, 0, 0, 0 }, // 46 IIC_LdStLWA
  { 0, 0, 0, 0, 0 }, // 47 IIC_IntMulHD
  { 1, 89, 90, 0, 0 }, // 48 IIC_BrMCR
  { 1, 89, 90, 0, 0 }, // 49 IIC_BrMCRX
  { 1, 89, 90, 0, 0 }, // 50 IIC_SprMFCR
  { 1, 98, 99, 0, 0 }, // 51 IIC_SprMFSPR
  { 1, 92, 93, 0, 0 }, // 52 IIC_IntMFFS
  { 1, 89, 90, 0, 0 }, // 53 IIC_SprMFMSR
  { 0, 0, 0, 0, 0 }, // 54 IIC_SprMFCRF
  { 0, 0, 0, 0, 0 }, // 55 IIC_SprMFPMR
  { 1, 98, 99, 0, 0 }, // 56 IIC_SprMFSR
  { 1, 98, 99, 0, 0 }, // 57 IIC_SprMFTB
  { 0, 0, 0, 0, 0 }, // 58 IIC_SprMSGSYNC
  { 1, 96, 97, 0, 0 }, // 59 IIC_SprMTSPR
  { 1, 99, 100, 0, 0 }, // 60 IIC_IntMTFSB0
  { 1, 89, 90, 0, 0 }, // 61 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 62 IIC_SprMTMSRD
  { 0, 0, 0, 0, 0 }, // 63 IIC_SprMTPMR
  { 1, 96, 97, 0, 0 }, // 64 IIC_SprMTSR
  { 1, 100, 101, 0, 0 }, // 65 IIC_IntMulHW
  { 1, 101, 102, 0, 0 }, // 66 IIC_IntMulHWU
  { 1, 102, 103, 0, 0 }, // 67 IIC_IntMulLI
  { 0, 0, 0, 0, 0 }, // 68 IIC_VecPerm
  { 1, 90, 91, 0, 0 }, // 69 IIC_LdStSTFD
  { 1, 90, 91, 0, 0 }, // 70 IIC_LdStSTFDU
  { 1, 96, 97, 0, 0 }, // 71 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 72 IIC_IntRFID
  { 0, 0, 0, 0, 0 }, // 73 IIC_IntRotateD
  { 1, 87, 88, 0, 0 }, // 74 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 75 IIC_SprSLBFEE
  { 0, 0, 0, 0, 0 }, // 76 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 77 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprSLBIEG
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprSLBMFEV
  { 0, 0, 0, 0, 0 }, // 81 IIC_SprSLBMTE
  { 0, 0, 0, 0, 0 }, // 82 IIC_SprSLBSYNC
  { 1, 87, 88, 0, 0 }, // 83 IIC_IntShift
  { 1, 103, 104, 0, 0 }, // 84 IIC_LdStSTWCX
  { 1, 90, 91, 0, 0 }, // 85 IIC_LdStSTU
  { 1, 90, 91, 0, 0 }, // 86 IIC_LdStSTUX
  { 0, 0, 0, 0, 0 }, // 87 IIC_LdStSTD
  { 0, 0, 0, 0, 0 }, // 88 IIC_LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 89 IIC_SprSTOP
  { 0, 0, 0, 0, 0 }, // 90 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 91 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 92 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 93 IIC_SprTLBIEL
  { 1, 98, 99, 0, 0 }, // 94 IIC_SprTLBSYNC
  { 1, 104, 105, 0, 0 }, // 95 IIC_IntTrapW
  { 0, 0, 0, 0, 0 }, // 96 IIC_VecFPCompare
  { 0, 0, 0, 0, 0 }, // 97 VADDUBM_VADDUDM_VADDUHM_VADDUWM_VEXTSB2D_VEXTSB2Ds_VEXTSB2W_VEXTSB2Ws_VEXTSH2D_VEXTSH2Ds_VEXTSH2W_VEXTSH2Ws_VEXTSW2D_VEXTSW2Ds_VSLD_VSRD_VSUBUBM_VSUBUDM_VSUBUHM_VSUBUWM_VPOPCNTB_VPOPCNTH_VSRAD_MTVSRDD_VEQV_VNAND_VNEGD_VNEGW_VORC_XXLAND_XXLANDC_XXLEQV_XXLEQVOnes_XXLNAND_XXLNOR_XXLOR_XXLORf_XXLORC_XXLXOR_XXLXORdpz_XXLXORspz_XXLXORz
  { 0, 0, 0, 0, 0 }, // 98 VAND_VANDC_V_SET0_V_SET0B_V_SET0H_VSLB_VSLH_VSLW_VSRB_VSRH_VSRW_VRLB_VRLD_VRLH_VRLW_VSRAB_VSRAH_VSRAW_XVABSDP_XVABSSP_XVNABSDP_XVNABSSP_XVCPSGNDP_XVCPSGNSP_XVIEXPDP_XVIEXPSP_XVXEXPDP_XVXEXPSP_VRLDMI_VRLDNM_VRLWMI_VRLWNM_VMRGEW_VMRGOW_VNOR_VOR_VSEL_VXOR_XVNEGDP_XVNEGSP_XSABSQP_XSCPSGNQP_XSIEXPQP_XSNABSQP_XSNEGQP_XSXEXPQP
  { 0, 0, 0, 0, 0 }, // 99 XXSEL
  { 1, 96, 97, 0, 0 }, // 100 TABORTDC_TABORTDCI_TABORTWC_TABORTWCI
  { 1, 99, 100, 0, 0 }, // 101 MTFSB0_MTFSB1
  { 1, 92, 93, 0, 0 }, // 102 MFFSCDRN_MFFSCDRNI_MFFSCRN_MFFSCRNI
  { 1, 87, 88, 0, 0 }, // 103 CMPRB_CMPRB8_CMPEQB
  { 0, 0, 0, 0, 0 }, // 104 TD_TDI
  { 1, 104, 105, 0, 0 }, // 105 TW_TWI
  { 1, 92, 93, 0, 0 }, // 106 FCMPUD_FCMPUS_FTDIV_FTSQRT
  { 0, 0, 0, 0, 0 }, // 107 XSTSTDCDP_XSTSTDCSP
  { 0, 0, 0, 0, 0 }, // 108 XSMAXCDP_XSMAXDP_XSMAXJDP_XSMINCDP_XSMINDP_XSMINJDP_XSXSIGDP_XSCVSPDPN
  { 1, 92, 93, 0, 0 }, // 109 XSCMPEQDP_XSCMPEXPDP_XSCMPGEDP_XSCMPGTDP_XSCMPODP_XSCMPUDP_XSTDIVDP_XSTSQRTDP
  { 1, 87, 88, 0, 0 }, // 110 CNTLZD_CNTLZD_rec_CNTLZW_CNTLZW8_CNTLZW8_rec_CNTLZW_rec_CNTTZD_CNTTZD_rec_CNTTZW_CNTTZW8_CNTTZW8_rec_CNTTZW_rec_POPCNTD_POPCNTW_CMPB_CMPB8_SETB_SETB8_BPERMD
  { 0, 0, 0, 0, 0 }, // 111 SLD_SRD_SRAD
  { 0, 0, 0, 0, 0 }, // 112 SRADI_EXTSWSLI_32_64_EXTSWSLI_SRADI_32_RLDIC
  { 0, 0, 0, 0, 0 }, // 113 MFVRD_MFVSRD_MTVRD_MTVSRD_MTVRWA_MTVRWZ_MTVSRWA_MTVSRWZ_MFVSRWZ_MFVRWZ
  { 1, 87, 88, 0, 0 }, // 114 CMPLW_CMPLWI_CMPW_CMPWI_CMPD_CMPDI_CMPLD_CMPLDI
  { 1, 87, 88, 0, 0 }, // 115 SUBFC_SUBFC8_SUBFC8O_SUBFCO_SUBFIC_SUBFIC8_ANDI8_rec_ANDIS8_rec_ANDIS_rec_ANDI_rec_ADDC_ADDC8_ADDC8O_ADDCO_ADDIC_ADDIC8_ADDIC_rec_ADDE_ADDE8_ADDE8O_ADDE8O_rec_ADDE8_rec_ADDEO_ADDEO_rec_ADDE_rec_ADDME_ADDME8_ADDME8O_ADDME8O_rec_ADDME8_rec_ADDMEO_ADDMEO_rec_ADDME_rec_ADDZE_ADDZE8_ADDZE8O_ADDZE8O_rec_ADDZE8_rec_ADDZEO_ADDZEO_rec_ADDZE_rec_SUBF_SUBF8_SUBF8O_SUBF8O_rec_SUBF8_rec_SUBFE_SUBFE8_SUBFE8O_SUBFE8O_rec_SUBFE8_rec_SUBFEO_SUBFEO_rec_SUBFE_rec_SUBFME_SUBFME8_SUBFME8O_SUBFME8O_rec_SUBFME8_rec_SUBFMEO_SUBFMEO_rec_SUBFME_rec_SUBFO_SUBFO_rec_SUBFZE_SUBFZE8_SUBFZE8O_SUBFZE8O_rec_SUBFZE8_rec_SUBFZEO_SUBFZEO_rec_SUBFZE_rec_SUBF_rec_POPCNTB_LA
  { 1, 87, 88, 0, 0 }, // 116 ADD4_ADD4O_ADD4O_rec_ADD4_rec_ADD8_ADD8O_ADD8O_rec_ADD8_rec_NEG_NEG8_NEG8O_NEG8O_rec_NEG8_rec_NEGO_NEGO_rec_NEG_rec_ADDI_ADDI8_ADDIS_ADDIS8_LI_LI8_LIS_LIS8_OR_OR8_OR8_rec_ORI_ORI8_ORIS_ORIS8_OR_rec_XOR_XOR8_XOR8_rec_XORI_XORI8_XORIS_XORIS8_XOR_rec_NAND_NAND8_NAND8_rec_NAND_rec_AND_AND8_AND8_rec_ANDC_ANDC8_ANDC8_rec_ANDC_rec_AND_rec_NOR_NOR8_NOR8_rec_NOR_rec_ORC_ORC8_ORC8_rec_ORC_rec_EQV_EQV8_EQV8_rec_EQV_rec_EXTSB_EXTSB8_EXTSB8_32_64_EXTSB8_rec_EXTSB_rec_EXTSH_EXTSH8_EXTSH8_32_64_EXTSH8_rec_EXTSH_rec_EXTSW_EXTSW_32_EXTSW_32_64_EXTSW_32_64_rec_EXTSW_rec_ADD4TLS_ADD8TLS_ADD8TLS__NOP
  { 0, 0, 0, 0, 0 }, // 117 ADDIStocHA_ADDIStocHA8_ADDItocL_COPY
  { 1, 89, 90, 0, 0 }, // 118 MCRF
  { 1, 89, 90, 0, 0 }, // 119 MCRXRX
  { 0, 0, 0, 0, 0 }, // 120 XSNABSDP_XSXEXPDP_XSABSDP_XSNEGDP_XSCPSGNDP
  { 1, 88, 89, 0, 0 }, // 121 RFEBB
  { 1, 96, 97, 0, 0 }, // 122 TBEGIN_TRECHKPT
  { 1, 90, 91, 0, 0 }, // 123 WAIT
  { 0, 0, 0, 0, 0 }, // 124 RLDCL_RLDCR
  { 1, 87, 88, 0, 0 }, // 125 RLWIMI_RLWIMI8
  { 0, 0, 0, 0, 0 }, // 126 RLDICL_RLDICL_32_RLDICL_32_64_RLDICR_RLDICR_32_RLDIMI
  { 0, 0, 0, 0, 0 }, // 127 MFOCRF_MFOCRF8
  { 1, 89, 90, 0, 0 }, // 128 MTOCRF_MTOCRF8
  { 1, 89, 90, 0, 0 }, // 129 CR6SET_CR6UNSET_CRSET_CRUNSET_CRAND_CRANDC_CRNAND_CRNOR_CROR_CRORC_CREQV_CRXOR
  { 1, 87, 88, 0, 0 }, // 130 SLW_SLW8_SRW_SRW8_RLWINM_RLWINM8_RLWNM_RLWNM8
  { 1, 92, 93, 0, 0 }, // 131 FABSD_FABSS_FNABSD_FNABSS_FNEGD_FNEGS_FCPSGND_FCPSGNS_FMR
  { 1, 87, 88, 0, 0 }, // 132 SRAW_SRAWI
  { 0, 0, 0, 0, 0 }, // 133 ISEL_ISEL8
  { 0, 0, 0, 0, 0 }, // 134 XSIEXPDP
  { 1, 96, 97, 0, 0 }, // 135 TRECLAIM_TSR_TABORT
  { 1, 90, 91, 0, 0 }, // 136 MFVSCR
  { 1, 90, 91, 0, 0 }, // 137 MTVSCR
  { 0, 0, 0, 0, 0 }, // 138 VCMPNEZB_VCMPNEZH_VCMPNEZW_VCMPEQUB_VCMPEQUD_VCMPEQUH_VCMPEQUW_VCMPNEB_VCMPNEH_VCMPNEW_VCMPEQFP_VCMPEQFP_rec_VCMPGEFP_VCMPGEFP_rec_VCMPGTFP_VCMPGTFP_rec_VCMPBFP_VCMPBFP_rec_VCMPGTSB_VCMPGTSB_rec_VCMPGTSD_VCMPGTSD_rec_VCMPGTSH_VCMPGTSH_rec_VCMPGTSW_VCMPGTSW_rec_VCMPGTUB_VCMPGTUB_rec_VCMPGTUD_VCMPGTUD_rec_VCMPGTUH_VCMPGTUH_rec_VCMPGTUW_VCMPGTUW_rec_VCMPNEB_rec_VCMPNEH_rec_VCMPNEW_rec_VCMPNEZB_rec_VCMPNEZH_rec_VCMPNEZW_rec_VCMPEQUB_rec_VCMPEQUD_rec_VCMPEQUH_rec_VCMPEQUW_rec_XVCMPEQDP_XVCMPEQDP_rec_XVCMPEQSP_XVCMPEQSP_rec_XVCMPGEDP_XVCMPGEDP_rec_XVCMPGESP_XVCMPGESP_rec_XVCMPGTDP_XVCMPGTDP_rec_XVCMPGTSP_XVCMPGTSP_rec
  { 0, 0, 0, 0, 0 }, // 139 VABSDUB_VABSDUH_VABSDUW_VCLZB_VCLZD_VCLZH_VCLZW_VCTZB_VCTZD_VCTZH_VCTZW_VPOPCNTW_VPOPCNTD_VPRTYBD_VPRTYBW
  { 0, 0, 0, 0, 0 }, // 140 VADDUBS_VADDUHS_VADDUWS_VAVGSB_VAVGSH_VAVGSW_VAVGUB_VAVGUH_VAVGUW_VADDSBS_VADDSHS_VADDSWS_VMAXFP_VMINFP_VMAXSB_VMAXSD_VMAXSH_VMAXSW_VMAXUB_VMAXUD_VMAXUH_VMAXUW_VMINSB_VMINSD_VMINSH_VMINSW_VMINUB_VMINUD_VMINUH_VMINUW_VBPERMD_VADDCUW_VSHASIGMAD_VSHASIGMAW_VSUBSBS_VSUBSHS_VSUBSWS_VSUBUBS_VSUBUHS_VSUBUWS_VSUBCUW_XVMAXDP_XVMAXSP_XVMINDP_XVMINSP_XVTSTDCDP_XVTSTDCSP_XVXSIGDP_XVXSIGSP
  { 1, 92, 93, 0, 0 }, // 141 XVTDIVDP_XVTDIVSP_XVTSQRTDP_XVTSQRTSP
  { 0, 0, 0, 0, 0 }, // 142 VADDFP_VCTSXS_VCTSXS_0_VCTUXS_VCTUXS_0_VEXPTEFP_VLOGEFP_VMADDFP_VMHADDSHS_VNMSUBFP_VREFP_VRFIM_VRFIN_VRFIP_VRFIZ_VRSQRTEFP_XVADDDP_XVADDSP_XVCVDPSP_XVCVDPSXDS_XVCVDPSXWS_XVCVDPUXDS_XVCVDPUXWS_XVCVHPSP_XVCVSPDP_XVCVSPHP_XVCVSPSXDS_XVCVSPSXWS_XVCVSPUXDS_XVCVSPUXWS_XVCVSXDDP_XVCVSXDSP_XVCVSXWDP_XVCVSXWSP_XVCVUXDDP_XVCVUXDSP_XVCVUXWDP_XVCVUXWSP_XVMADDADP_XVMADDASP_XVMADDMDP_XVMADDMSP_XVMSUBADP_XVMSUBASP_XVMSUBMDP_XVMSUBMSP_XVMULDP_XVMULSP_XVNMADDADP_XVNMADDASP_XVNMADDMDP_XVNMADDMSP_XVNMSUBADP_XVNMSUBASP_XVNMSUBMDP_XVNMSUBMSP_XVRDPI_XVRDPIC_XVRDPIM_XVRDPIP_XVRDPIZ_XVREDP_XVRESP_XVRSPI_XVRSPIC_XVRSPIM_XVRSPIP_XVRSPIZ_XVRSQRTEDP_XVRSQRTESP_XVSUBDP_XVSUBSP_VCFSX_VCFSX_0_VCFUX_VCFUX_0_VMHRADDSHS_VMLADDUHM_VMSUMMBM_VMSUMSHM_VMSUMSHS_VMSUMUBM_VMSUMUHM_VMSUMUDM_VMSUMUHS_VMULESB_VMULESH_VMULESW_VMULEUB_VMULEUH_VMULEUW_VMULOSB_VMULOSH_VMULOSW_VMULOUB_VMULOUH_VMULOUW_VSUM2SWS_VSUM4SBS_VSUM4SHS_VSUM4UBS_VSUMSWS
  { 0, 0, 0, 0, 0 }, // 143 VSUBFP_VMULUWM
  { 0, 0, 0, 0, 0 }, // 144 MADDHD_MADDHDU_MADDLD_MADDLD8_MULLD_MULLDO
  { 1, 100, 101, 0, 0 }, // 145 MULHD_MULHW_MULLW_MULLWO
  { 1, 101, 102, 0, 0 }, // 146 MULHDU_MULHWU
  { 1, 102, 103, 0, 0 }, // 147 MULLI_MULLI8
  { 1, 92, 93, 0, 0 }, // 148 FRSP_FRIMD_FRIMS_FRIND_FRINS_FRIPD_FRIPS_FRIZD_FRIZS_FRE_FRES_FADDS_FMSUBS_FMADDS_FSUBS_FCFID_FCFIDS_FCFIDU_FCFIDUS_FCTID_FCTIDU_FCTIDUZ_FCTIDZ_FCTIW_FCTIWU_FCTIWUZ_FCTIWZ_FRSQRTE_FRSQRTES_FNMADDS_FNMSUBS_FSELD_FSELS_FMULS
  { 1, 92, 93, 0, 0 }, // 149 FADD_FSUB
  { 1, 95, 96, 0, 0 }, // 150 FMSUB_FMADD_FNMADD_FNMSUB_FMUL
  { 0, 0, 0, 0, 0 }, // 151 XSMADDADP_XSMADDASP_XSMADDMDP_XSMADDMSP_XSMSUBADP_XSMSUBASP_XSMSUBMDP_XSMSUBMSP_XSMULDP_XSMULSP_XSNMADDADP_XSNMADDASP_XSNMADDMDP_XSNMADDMSP_XSNMSUBADP_XSNMSUBASP_XSNMSUBMDP_XSNMSUBMSP
  { 1, 92, 93, 0, 0 }, // 152 FSELD_rec_FSELS_rec
  { 1, 101, 102, 0, 0 }, // 153 MULHDU_rec_MULHWU_rec
  { 1, 100, 101, 0, 0 }, // 154 MULHD_rec_MULHW_rec_MULLWO_rec_MULLW_rec
  { 0, 0, 0, 0, 0 }, // 155 MULLDO_rec_MULLD_rec
  { 1, 92, 93, 0, 0 }, // 156 FRIMD_rec_FRIMS_rec_FRIND_rec_FRINS_rec_FRIPD_rec_FRIPS_rec_FRIZD_rec_FRIZS_rec_FRES_rec_FRE_rec_FADDS_rec_FSUBS_rec_FMSUBS_rec_FNMSUBS_rec_FMADDS_rec_FNMADDS_rec_FCFIDS_rec_FCFIDUS_rec_FCFIDU_rec_FCFID_rec_FCTIDUZ_rec_FCTIDU_rec_FCTIDZ_rec_FCTID_rec_FCTIWUZ_rec_FCTIWU_rec_FCTIWZ_rec_FCTIW_rec_FMULS_rec_FRSQRTES_rec_FRSQRTE_rec_FRSP_rec
  { 1, 92, 93, 0, 0 }, // 157 FADD_rec_FSUB_rec
  { 1, 95, 96, 0, 0 }, // 158 FMSUB_rec_FNMSUB_rec_FMADD_rec_FNMADD_rec_FMUL_rec
  { 0, 0, 0, 0, 0 }, // 159 XSADDDP_XSADDSP_XSCVDPHP_XSCVDPSP_XSCVDPSXDS_XSCVDPSXDSs_XSCVDPSXWS_XSCVDPUXDS_XSCVDPUXDSs_XSCVDPUXWS_XSCVDPSXWSs_XSCVDPUXWSs_XSCVHPDP_XSCVSPDP_XSCVSXDDP_XSCVSXDSP_XSCVUXDDP_XSCVUXDSP_XSRDPI_XSRDPIC_XSRDPIM_XSRDPIP_XSRDPIZ_XSREDP_XSRESP_XSRSQRTEDP_XSRSQRTESP_XSSUBDP_XSSUBSP_XSCVDPSPN_XSRSP
  { 1, 90, 91, 0, 0 }, // 160 LVSL_LVSR
  { 0, 0, 0, 0, 0 }, // 161 VSPLTISB_VSPLTISH_VSPLTISW_VSPLTB_VSPLTBs_VSPLTH_VSPLTHs_VSPLTW_XXMRGHW_XXMRGLW_XXPERM_XXPERMR_XXSLDWI_XXSLDWIs_XXSPLTIB_XXSPLTW_XXSPLTWs_XXPERMDI_XXPERMDIs
  { 0, 0, 0, 0, 0 }, // 162 V_SETALLONES_V_SETALLONESB_V_SETALLONESH_VBPERMQ_VGBBD_VMRGHB_VMRGHH_VMRGHW_VMRGLB_VMRGLH_VMRGLW_VPERM_VPERMR_VPERMXOR_VPKPX_VPKSDSS_VPKSDUS_VPKSHSS_VPKSHUS_VPKSWSS_VPKSWUS_VPKUDUM_VPKUDUS_VPKUHUM_VPKUHUS_VPKUWUM_VPKUWUS_VSL_VSLDOI_VSLO_VSLV_VSR_VSRO_VSRV_VUPKHPX_VUPKHSB_VUPKHSH_VUPKHSW_VUPKLPX_VUPKLSB_VUPKLSH_VUPKLSW_XXBRD_XXBRH_XXBRQ_XXBRW_XXEXTRACTUW_XXINSERTW_VADDCUQ_VADDECUQ_VADDEUQM_VMUL10CUQ_VMUL10ECUQ_VMUL10EUQ_VMUL10UQ_VSUBCUQ_VSUBECUQ_VSUBEUQM_XSTSTDCQP_XSXSIGQP_BCDCFN_rec_BCDCFZ_rec_BCDCPSGN_rec_BCDCTN_rec_BCDCTZ_rec_BCDSETSGN_rec_BCDS_rec_BCDTRUNC_rec_BCDUS_rec_BCDUTRUNC_rec
  { 0, 0, 0, 0, 0 }, // 163 VEXTRACTUB_VEXTRACTUH_VEXTRACTUW_VINSERTB_VINSERTD_VINSERTH_VINSERTW_MFVSRLD_MTVSRWS_VCLZLSBB_VCTZLSBB_VEXTRACTD_VEXTUBLX_VEXTUBRX_VEXTUHLX_VEXTUHRX_VEXTUWLX_VEXTUWRX_VPRTYBQ_VADDUQM_VSUBUQM
  { 1, 92, 93, 0, 0 }, // 164 XSCMPEXPQP_XSCMPOQP_XSCMPUQP
  { 0, 0, 0, 0, 0 }, // 165 BCDSR_rec_XSADDQP_XSADDQPO_XSCVDPQP_XSCVQPDP_XSCVQPDPO_XSCVQPSDZ_XSCVQPSWZ_XSCVQPUDZ_XSCVQPUWZ_XSCVSDQP_XSCVUDQP_XSRQPI_XSRQPIX_XSRQPXP_XSSUBQP_XSSUBQPO
  { 0, 0, 0, 0, 0 }, // 166 BCDCTSQ_rec
  { 0, 0, 0, 0, 0 }, // 167 XSMADDQP_XSMADDQPO_XSMSUBQP_XSMSUBQPO_XSMULQP_XSMULQPO_XSNMADDQP_XSNMADDQPO_XSNMSUBQP_XSNMSUBQPO
  { 0, 0, 0, 0, 0 }, // 168 BCDCFSQ_rec
  { 0, 0, 0, 0, 0 }, // 169 XSDIVQP_XSDIVQPO
  { 0, 0, 0, 0, 0 }, // 170 XSSQRTQP_XSSQRTQPO
  { 1, 90, 91, 0, 0 }, // 171 LXVL_LXVLL
  { 1, 90, 91, 0, 0 }, // 172 LVEBX_LVEHX_LVEWX_LVX_LVXL
  { 1, 90, 91, 0, 0 }, // 173 LXSIBZX_LXSIHZX_LXSDX_LXVB16X_LXVD2X_LXVWSX_LXSIWZX_LXV_LXVX_LXSD
  { 0, 0, 0, 0, 0 }, // 174 DFLOADf64_XFLOADf64_LIWZX
  { 1, 86, 87, 0, 0 }, // 175 DCBF_DCBFEP_DCBST_DCBSTEP_DCBT_DCBTEP_DCBZ_DCBZEP_DCBZL_DCBZLEP_DCBTST_DCBTSTEP
  { 0, 0, 0, 0, 0 }, // 176 CP_COPY_CP_COPY8
  { 0, 0, 0, 0, 0 }, // 177 CP_PASTE_CP_PASTE8
  { 1, 86, 87, 0, 0 }, // 178 ICBI_ICBIEP
  { 1, 90, 91, 0, 0 }, // 179 ICBT_ICBTLS_LBZ_LBZ8_LBZCIX_LBZX_LBZX8_LBZXTLS_LBZXTLS__LBZXTLS_32_LDBRX_LDCIX_LHBRX_LHBRX8_LHZ_LHZ8_LHZCIX_LHZX_LHZX8_LHZXTLS_LHZXTLS__LHZXTLS_32_LWBRX_LWBRX8_LWZ_LWZ8_LWZCIX_LWZX_LWZX8_LWZXTLS_LWZXTLS__LWZXTLS_32_EnforceIEIO_LSWI
  { 1, 86, 87, 0, 0 }, // 180 LBARX_LBARXL_LHARX_LHARXL_LWARX_LWARXL
  { 0, 0, 0, 0, 0 }, // 181 LD_LDX_LDXTLS_LDXTLS__DARN
  { 0, 0, 0, 0, 0 }, // 182 LDARX_LDARXL
  { 0, 0, 0, 0, 0 }, // 183 CP_ABORT
  { 1, 96, 97, 0, 0 }, // 184 ISYNC
  { 0, 0, 0, 0, 0 }, // 185 MSGSYNC
  { 1, 98, 99, 0, 0 }, // 186 TLBSYNC
  { 1, 86, 87, 0, 0 }, // 187 SYNC
  { 1, 97, 98, 0, 0 }, // 188 LMW
  { 1, 90, 91, 0, 0 }, // 189 LFIWZX_LFDX_LFD
  { 0, 0, 0, 0, 0 }, // 190 SLBIA
  { 0, 0, 0, 0, 0 }, // 191 SLBIE
  { 0, 0, 0, 0, 0 }, // 192 SLBMFEE
  { 0, 0, 0, 0, 0 }, // 193 SLBMFEV
  { 0, 0, 0, 0, 0 }, // 194 SLBMTE
  { 0, 0, 0, 0, 0 }, // 195 TLBIEL
  { 1, 90, 91, 0, 0 }, // 196 LHZU_LHZU8_LWZU_LWZU8
  { 1, 90, 91, 0, 0 }, // 197 LHZUX_LHZUX8_LWZUX_LWZUX8
  { 1, 96, 97, 0, 0 }, // 198 TEND
  { 1, 103, 104, 0, 0 }, // 199 STBCX_STHCX_STWCX
  { 0, 0, 0, 0, 0 }, // 200 STDCX
  { 0, 0, 0, 0, 0 }, // 201 LDMX
  { 1, 90, 91, 0, 0 }, // 202 LHA_LHA8_LHAX_LHAX8_LWAX_LWAX_32
  { 0, 0, 0, 0, 0 }, // 203 CP_PASTE8_rec_CP_PASTE_rec
  { 0, 0, 0, 0, 0 }, // 204 LWA_LWA_32
  { 1, 96, 97, 0, 0 }, // 205 TCHECK
  { 1, 90, 91, 0, 0 }, // 206 LFIWAX
  { 1, 90, 91, 0, 0 }, // 207 LXSIWAX
  { 0, 0, 0, 0, 0 }, // 208 LIWAX
  { 1, 90, 91, 0, 0 }, // 209 LFSX_LFS
  { 1, 90, 91, 0, 0 }, // 210 LXSSP_LXSSPX
  { 0, 0, 0, 0, 0 }, // 211 XFLOADf32_DFLOADf32
  { 1, 90, 91, 0, 0 }, // 212 LHAU_LHAU8
  { 1, 90, 91, 0, 0 }, // 213 LHAUX_LHAUX8_LWAUX
  { 1, 90, 91, 0, 0 }, // 214 LXVH8X_LXVDSX_LXVW4X
  { 1, 90, 91, 0, 0 }, // 215 STFD_STFDX_STFIWX_STFS_STFSX_STXSD_STXSDX_STXSIBX_STXSIBXv_STXSIHX_STXSIHXv_STXSIWX_STXSSP_STXSSPX
  { 1, 90, 91, 0, 0 }, // 216 STW_STW8_STDBRX_STHBRX_STWBRX_STB_STB8_STH_STH8_STBX_STBX8_STBXTLS_STBXTLS__STBXTLS_32_STHX_STHX8_STHXTLS_STHXTLS__STHXTLS_32_STWX_STWX8_STWXTLS_STWXTLS__STWXTLS_32
  { 0, 0, 0, 0, 0 }, // 217 DFSTOREf32_DFSTOREf64_XFSTOREf32_XFSTOREf64_STIWX
  { 0, 0, 0, 0, 0 }, // 218 STD_STDX_STDXTLS_STDXTLS_
  { 1, 90, 91, 0, 0 }, // 219 STBCIX_STDCIX_STHCIX_STWCIX_STSWI
  { 0, 0, 0, 0, 0 }, // 220 SLBIEG
  { 1, 97, 98, 0, 0 }, // 221 STMW
  { 0, 0, 0, 0, 0 }, // 222 TLBIE
  { 1, 90, 91, 0, 0 }, // 223 STVEBX_STVEHX_STVEWX_STVX_STVXL
  { 1, 90, 91, 0, 0 }, // 224 STXV_STXVB16X_STXVD2X_STXVH8X_STXVW4X_STXVX
  { 1, 90, 91, 0, 0 }, // 225 STXVL_STXVLL
  { 1, 96, 97, 0, 0 }, // 226 MTCTR_MTCTR8_MTCTR8loop_MTCTRloop_MTLR_MTLR8
  { 1, 87, 88, 0, 0 }, // 227 MFVRSAVE_MFVRSAVEv_MTVRSAVE_MTVRSAVEv
  { 0, 0, 0, 0, 0 }, // 228 MFPMR
  { 0, 0, 0, 0, 0 }, // 229 MTPMR
  { 1, 98, 99, 0, 0 }, // 230 MFTB_MFTB8
  { 1, 98, 99, 0, 0 }, // 231 MFCTR_MFCTR8_MFLR_MFLR8_MFSPR_MFSPR8
  { 1, 89, 90, 0, 0 }, // 232 MFMSR
  { 1, 89, 90, 0, 0 }, // 233 MTMSR
  { 0, 0, 0, 0, 0 }, // 234 MTMSRD
  { 1, 96, 97, 0, 0 }, // 235 MTSPR_MTSPR8
  { 1, 91, 92, 0, 0 }, // 236 DIVW_DIVWO_DIVWU_DIVWUO_MODSW
  { 1, 91, 92, 0, 0 }, // 237 DIVWE_DIVWEO_DIVWEU_DIVWEUO_MODSD_MODUD_MODUW
  { 0, 0, 0, 0, 0 }, // 238 DIVD_DIVDO_DIVDU_DIVDUO
  { 0, 0, 0, 0, 0 }, // 239 DIVDE_DIVDEO_DIVDEU_DIVDEUO
  { 1, 91, 92, 0, 0 }, // 240 DIVWO_rec_DIVWUO_rec_DIVWU_rec_DIVW_rec
  { 0, 0, 0, 0, 0 }, // 241 DIVD_rec_DIVDO_rec_DIVDU_rec_DIVDUO_rec
  { 1, 91, 92, 0, 0 }, // 242 DIVWE_rec_DIVWEO_rec_DIVWEU_rec_DIVWEUO_rec
  { 0, 0, 0, 0, 0 }, // 243 DIVDE_rec_DIVDEO_rec_DIVDEU_rec_DIVDEUO_rec
  { 1, 89, 90, 0, 0 }, // 244 MTCRF_MTCRF8
  { 1, 87, 88, 0, 0 }, // 245 ADDC8O_rec_ADDC8_rec_ADDCO_rec_ADDC_rec_SUBFC8O_rec_SUBFC8_rec_SUBFCO_rec_SUBFC_rec
  { 1, 92, 93, 0, 0 }, // 246 FABSD_rec_FABSS_rec_FNABSD_rec_FNABSS_rec_FCPSGND_rec_FCPSGNS_rec_FNEGD_rec_FNEGS_rec_FMR_rec
  { 1, 89, 90, 0, 0 }, // 247 MCRFS
  { 1, 92, 93, 0, 0 }, // 248 MTFSF_MTFSF_rec_MTFSFI_MTFSFI_rec
  { 1, 99, 100, 0, 0 }, // 249 MTFSFb
  { 0, 0, 0, 0, 0 }, // 250 RLDCL_rec_RLDCR_rec
  { 0, 0, 0, 0, 0 }, // 251 RLDICL_rec_RLDICR_rec_RLDICL_32_rec_RLDIMI_rec
  { 1, 87, 88, 0, 0 }, // 252 RLWIMI8_rec_RLWIMI_rec
  { 1, 87, 88, 0, 0 }, // 253 RLWINM8_rec_RLWINM_rec_RLWNM8_rec_RLWNM_rec_SLW8_rec_SLW_rec_SRW8_rec_SRW_rec
  { 1, 87, 88, 0, 0 }, // 254 SRAWI_rec_SRAW_rec
  { 1, 92, 93, 0, 0 }, // 255 MFFS_MFFSCE_MFFSL_MFFS_rec
  { 1, 89, 90, 0, 0 }, // 256 MFCR_MFCR8
  { 0, 0, 0, 0, 0 }, // 257 EXTSWSLI_32_64_rec_SRADI_rec_EXTSWSLI_rec_RLDIC_rec
  { 0, 0, 0, 0, 0 }, // 258 SRAD_rec_SLD_rec_SRD_rec
  { 1, 93, 94, 0, 0 }, // 259 FDIV
  { 1, 93, 94, 0, 0 }, // 260 FDIV_rec
  { 0, 0, 0, 0, 0 }, // 261 XSSQRTDP
  { 0, 0, 0, 0, 0 }, // 262 FSQRT
  { 0, 0, 0, 0, 0 }, // 263 XVSQRTDP
  { 0, 0, 0, 0, 0 }, // 264 XVSQRTSP
  { 0, 0, 0, 0, 0 }, // 265 FSQRT_rec
  { 0, 0, 0, 0, 0 }, // 266 XSSQRTSP
  { 0, 0, 0, 0, 0 }, // 267 FSQRTS
  { 0, 0, 0, 0, 0 }, // 268 FSQRTS_rec
  { 1, 93, 94, 0, 0 }, // 269 XSDIVDP
  { 1, 94, 95, 0, 0 }, // 270 FDIVS
  { 1, 94, 95, 0, 0 }, // 271 FDIVS_rec
  { 1, 94, 95, 0, 0 }, // 272 XSDIVSP
  { 1, 94, 95, 0, 0 }, // 273 XVDIVSP
  { 1, 93, 94, 0, 0 }, // 274 XVDIVDP
  { 1, 90, 91, 0, 0 }, // 275 LFSU
  { 1, 90, 91, 0, 0 }, // 276 LFSUX
  { 1, 90, 91, 0, 0 }, // 277 STFDU_STFDUX_STFSU_STFSUX
  { 1, 90, 91, 0, 0 }, // 278 STBU_STBU8_STDU_STHU_STHU8_STWU_STWU8
  { 1, 90, 91, 0, 0 }, // 279 STBUX_STBUX8_STDUX_STHUX_STHUX8_STWUX_STWUX8
  { 1, 90, 91, 0, 0 }, // 280 LBZU_LBZU8
  { 1, 90, 91, 0, 0 }, // 281 LBZUX_LBZUX8
  { 0, 0, 0, 0, 0 }, // 282 LDU
  { 0, 0, 0, 0, 0 }, // 283 LDUX
  { 1, 90, 91, 0, 0 }, // 284 LFDU
  { 1, 90, 91, 0, 0 }, // 285 LFDUX
  { 0, 0, 0, 0, 0 }, // 286 VPMSUMB_VPMSUMD_VPMSUMH_VPMSUMW_VCIPHER_VCIPHERLAST_VNCIPHER_VNCIPHERLAST_VSBOX
  { 1, 88, 89, 0, 0 }, // 287 BCCCTR_BCCCTR8_BCCCTRL_BCCCTRL8_BCCL_BCCLA_BCCLR_BCCLRL_BCCTR_BCCTR8_BCCTR8n_BCCTRL_BCCTRL8_BCCTRL8n_BCCTRLn_BCCTRn_BDNZ_BDNZ8_BDNZA_BDNZAm_BDNZAp_BDNZm_BDNZp_BDZ_BDZ8_BDZA_BDZAm_BDZAp_BDZm_BDZp_BDNZL_BDNZLA_BDNZLAm_BDNZLAp_BDNZLR_BDNZLR8_BDNZLRL_BDNZLRLm_BDNZLRLp_BDNZLRm_BDNZLRp_BDNZLm_BDNZLp_BDZL_BDZLA_BDZLAm_BDZLAp_BDZLR_BDZLR8_BDZLRL_BDZLRLm_BDZLRLp_BDZLRm_BDZLRp_BDZLm_BDZLp_BL_BL_NOP_BL_TLS_BL8_BL8_NOP_BL8_NOP_TLS_BL8_TLS_BL8_TLS__BLA_BLA8_BLA8_NOP_BLR_BLR8_BLRL_TAILB_TAILB8_TAILBA_TAILBA8_TAILBCTR_TAILBCTR8_gBC_gBCA_gBCAat_gBCCTR_gBCCTRL_gBCL_gBCLA_gBCLAat_gBCLR_gBCLRL_gBCLat_gBCat_BCLR_BCLRL_BCLRLn_BCLRn_BCTR_BCTR8_BCTRL_BCTRL8_B_BA_BC_BCC_BCCA_BCL_BCLalways_BCLn_BCTRL8_LDinto_toc_BCTRL_LWZinto_toc_BCn_CTRL_DEP
  { 1, 88, 89, 0, 0 }, // 288 ADDPCIS
  { 1, 90, 91, 0, 0 }, // 289 LDAT_LWAT
  { 1, 90, 91, 0, 0 }, // 290 STDAT_STWAT
  { 1, 87, 88, 0, 0 }, // 291 BRINC
  { 0, 0, 0, 0, 0 }, // 292 EVABS_EVEQV_EVNAND_EVNEG_EVADDIW_EVADDW_EVAND_EVANDC_EVCMPEQ_EVCMPGTS_EVCMPGTU_EVCMPLTS_EVCMPLTU_EVCNTLSW_EVCNTLZW_EVEXTSB_EVEXTSH_EVMERGEHI_EVMERGEHILO_EVMERGELO_EVMERGELOHI_EVNOR_EVOR_EVORC_EVXOR_EVRLW_EVRLWI_EVRNDW_EVSLW_EVSLWI_EVSPLATFI_EVSPLATI_EVSRWIS_EVSRWIU_EVSRWS_EVSRWU_EVSUBFW_EVSUBIFW
  { 0, 0, 0, 0, 0 }, // 293 EVMRA_EVADDSMIAAW_EVADDSSIAAW_EVADDUMIAAW_EVADDUSIAAW_EVDIVWS_EVDIVWU_EVMHEGSMFAA_EVMHEGSMFAN_EVMHEGSMIAA_EVMHEGSMIAN_EVMHEGUMIAA_EVMHEGUMIAN_EVMHESMF_EVMHESMFA_EVMHESMFAAW_EVMHESMFANW_EVMHESMI_EVMHESMIA_EVMHESMIAAW_EVMHESMIANW_EVMHESSF_EVMHESSFA_EVMHESSFAAW_EVMHESSFANW_EVMHESSIAAW_EVMHESSIANW_EVMHEUMI_EVMHEUMIA_EVMHEUMIAAW_EVMHEUMIANW_EVMHEUSIAAW_EVMHEUSIANW_EVMHOGSMFAA_EVMHOGSMFAN_EVMHOGSMIAA_EVMHOGSMIAN_EVMHOGUMIAA_EVMHOGUMIAN_EVMHOSMF_EVMHOSMFA_EVMHOSMFAAW_EVMHOSMFANW_EVMHOSMI_EVMHOSMIA_EVMHOSMIAAW_EVMHOSMIANW_EVMHOSSF_EVMHOSSFA_EVMHOSSFAAW_EVMHOSSFANW_EVMHOSSIAAW_EVMHOSSIANW_EVMHOUMI_EVMHOUMIA_EVMHOUMIAAW_EVMHOUMIANW_EVMHOUSIAAW_EVMHOUSIANW_EVMWHSMF_EVMWHSMFA_EVMWHSMI_EVMWHSMIA_EVMWHSSF_EVMWHSSFA_EVMWHUMI_EVMWHUMIA_EVMWLSMIAAW_EVMWLSMIANW_EVMWLSSIAAW_EVMWLSSIANW_EVMWLUMI_EVMWLUMIA_EVMWLUMIAAW_EVMWLUMIANW_EVMWLUSIAAW_EVMWLUSIANW_EVMWSMF_EVMWSMFA_EVMWSMFAA_EVMWSMFAN_EVMWSMI_EVMWSMIA_EVMWSMIAA_EVMWSMIAN_EVMWSSF_EVMWSSFA_EVMWSSFAA_EVMWSSFAN_EVMWUMI_EVMWUMIA_EVMWUMIAA_EVMWUMIAN_EVSUBFSMIAAW_EVSUBFSSIAAW_EVSUBFUMIAAW_EVSUBFUSIAAW
  { 1, 90, 91, 0, 0 }, // 294 EVLDD_EVLDDX_EVLDH_EVLDHX_EVLDW_EVLDWX_EVLHHESPLAT_EVLHHESPLATX_EVLHHOSSPLAT_EVLHHOSSPLATX_EVLHHOUSPLAT_EVLHHOUSPLATX_EVLWHE_EVLWHEX_EVLWHOS_EVLWHOSX_EVLWHOU_EVLWHOUX_EVLWHSPLAT_EVLWHSPLATX_EVLWWSPLAT_EVLWWSPLATX
  { 1, 90, 91, 0, 0 }, // 295 EVSTDD_EVSTDDX_EVSTDH_EVSTDHX_EVSTDW_EVSTDWX_EVSTWHE_EVSTWHEX_EVSTWHO_EVSTWHOX_EVSTWWE_EVSTWWEX_EVSTWWO_EVSTWWOX
  { 1, 88, 89, 0, 0 }, // 296 HRFID_ATTN_CLRBHRB_MFBHRBE_NAP_RFCI_RFDI_RFMCI_SC
  { 1, 96, 97, 0, 0 }, // 297 RFI
  { 0, 0, 0, 0, 0 }, // 298 RFID
  { 1, 90, 91, 0, 0 }, // 299 DSS_DSSALL_DST_DST64_DSTST_DSTST64_DSTSTT_DSTSTT64_DSTT_DSTT64_ICBLQ_LBEPX_LHEPX_LWEPX_TLBIVAX_TLBLD_TLBLI_TLBRE_TLBRE2_TLBSX_TLBSX2_TLBSX2D_TLBWE_TLBWE2_MBAR_TRAP_DCCCI_ICCCI
  { 1, 90, 91, 0, 0 }, // 300 ICBLC_STBEPX_STHEPX_STWEPX
  { 1, 90, 91, 0, 0 }, // 301 LFDEPX
  { 1, 90, 91, 0, 0 }, // 302 STFDEPX
  { 1, 98, 99, 0, 0 }, // 303 MFSR_MFSRIN
  { 1, 96, 97, 0, 0 }, // 304 MTSR_MTSRIN
  { 1, 98, 99, 0, 0 }, // 305 MFDCR
  { 1, 96, 97, 0, 0 }, // 306 MTDCR
  { 1, 87, 88, 0, 0 }, // 307 NOP_GT_PWR6_NOP_GT_PWR7
  { 0, 0, 0, 0, 0 }, // 308 TLBIA
  { 1, 89, 90, 0, 0 }, // 309 WRTEE_WRTEEI
  { 1, 86, 87, 0, 0 }, // 310 MSYNC
  { 0, 0, 0, 0, 0 }, // 311 SLBSYNC
  { 0, 0, 0, 0, 0 }, // 312 SLBFEE_rec
  { 0, 0, 0, 0, 0 }, // 313 STOP
  { 1, 86, 87, 0, 0 }, // 314 DCBA_DCBI
  { 0, uint16_t(~0U), uint16_t(~0U), uint16_t(~0U), uint16_t(~0U) }// end marker
};

static const llvm::InstrItinerary G4Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 105, 106, 0, 0 }, // 1 IIC_LdStSync
  { 1, 106, 107, 0, 0 }, // 2 IIC_IntSimple
  { 1, 106, 107, 0, 0 }, // 3 IIC_IntGeneral
  { 1, 107, 108, 0, 0 }, // 4 IIC_BrB
  { 1, 108, 109, 0, 0 }, // 5 IIC_VecFP
  { 1, 106, 107, 0, 0 }, // 6 IIC_IntCompare
  { 0, 0, 0, 0, 0 }, // 7 IIC_SprABORT
  { 0, 0, 0, 0, 0 }, // 8 IIC_LdStCOPY
  { 0, 0, 0, 0, 0 }, // 9 IIC_LdStPASTE
  { 1, 109, 110, 0, 0 }, // 10 IIC_BrCR
  { 0, 0, 0, 0, 0 }, // 11 IIC_LdStLD
  { 1, 110, 111, 0, 0 }, // 12 IIC_LdStDCBF
  { 1, 110, 111, 0, 0 }, // 13 IIC_LdStLoad
  { 0, 0, 0, 0, 0 }, // 14 IIC_IntDivD
  { 1, 111, 112, 0, 0 }, // 15 IIC_IntDivW
  { 0, 0, 0, 0, 0 }, // 16 IIC_FPDGeneral
  { 1, 112, 113, 0, 0 }, // 17 IIC_FPAddSub
  { 1, 113, 114, 0, 0 }, // 18 IIC_FPDivD
  { 0, 0, 0, 0, 0 }, // 19 IIC_FPSGeneral
  { 1, 112, 113, 0, 0 }, // 20 IIC_FPCompare
  { 1, 112, 113, 0, 0 }, // 21 IIC_FPGeneral
  { 1, 114, 115, 0, 0 }, // 22 IIC_VecGeneral
  { 1, 115, 116, 0, 0 }, // 23 IIC_VecComplex
  { 1, 110, 111, 0, 0 }, // 24 IIC_LdStStore
  { 0, 0, 0, 0, 0 }, // 25 IIC_IntRotateDI
  { 1, 116, 117, 0, 0 }, // 26 IIC_FPDivS
  { 1, 112, 113, 0, 0 }, // 27 IIC_FPFused
  { 0, 0, 0, 0, 0 }, // 28 IIC_FPSqrtD
  { 0, 0, 0, 0, 0 }, // 29 IIC_FPSqrtS
  { 1, 110, 111, 0, 0 }, // 30 IIC_LdStICBI
  { 0, 0, 0, 0, 0 }, // 31 IIC_IntISEL
  { 1, 117, 118, 0, 0 }, // 32 IIC_SprISYNC
  { 1, 118, 119, 0, 0 }, // 33 IIC_LdStLWARX
  { 1, 110, 111, 0, 0 }, // 34 IIC_LdStLoadUpd
  { 1, 110, 111, 0, 0 }, // 35 IIC_LdStLoadUpdX
  { 0, 0, 0, 0, 0 }, // 36 IIC_LdStLDARX
  { 0, 0, 0, 0, 0 }, // 37 IIC_LdStLDU
  { 0, 0, 0, 0, 0 }, // 38 IIC_LdStLDUX
  { 1, 110, 111, 0, 0 }, // 39 IIC_LdStLFD
  { 1, 110, 111, 0, 0 }, // 40 IIC_LdStLFDU
  { 1, 110, 111, 0, 0 }, // 41 IIC_LdStLFDUX
  { 1, 110, 111, 0, 0 }, // 42 IIC_LdStLHA
  { 1, 110, 111, 0, 0 }, // 43 IIC_LdStLHAU
  { 1, 110, 111, 0, 0 }, // 44 IIC_LdStLHAUX
  { 1, 119, 120, 0, 0 }, // 45 IIC_LdStLMW
  { 0, 0, 0, 0, 0 }, // 46 IIC_LdStLWA
  { 0, 0, 0, 0, 0 }, // 47 IIC_IntMulHD
  { 1, 109, 110, 0, 0 }, // 48 IIC_BrMCR
  { 1, 109, 110, 0, 0 }, // 49 IIC_BrMCRX
  { 1, 109, 110, 0, 0 }, // 50 IIC_SprMFCR
  { 1, 120, 121, 0, 0 }, // 51 IIC_SprMFSPR
  { 1, 121, 122, 0, 0 }, // 52 IIC_IntMFFS
  { 1, 109, 110, 0, 0 }, // 53 IIC_SprMFMSR
  { 0, 0, 0, 0, 0 }, // 54 IIC_SprMFCRF
  { 0, 0, 0, 0, 0 }, // 55 IIC_SprMFPMR
  { 1, 120, 121, 0, 0 }, // 56 IIC_SprMFSR
  { 1, 109, 110, 0, 0 }, // 57 IIC_SprMFTB
  { 0, 0, 0, 0, 0 }, // 58 IIC_SprMSGSYNC
  { 1, 117, 118, 0, 0 }, // 59 IIC_SprMTSPR
  { 1, 121, 122, 0, 0 }, // 60 IIC_IntMTFSB0
  { 1, 109, 110, 0, 0 }, // 61 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 62 IIC_SprMTMSRD
  { 0, 0, 0, 0, 0 }, // 63 IIC_SprMTPMR
  { 1, 117, 118, 0, 0 }, // 64 IIC_SprMTSR
  { 1, 122, 123, 0, 0 }, // 65 IIC_IntMulHW
  { 1, 123, 124, 0, 0 }, // 66 IIC_IntMulHWU
  { 1, 124, 125, 0, 0 }, // 67 IIC_IntMulLI
  { 1, 125, 126, 0, 0 }, // 68 IIC_VecPerm
  { 1, 110, 111, 0, 0 }, // 69 IIC_LdStSTFD
  { 1, 110, 111, 0, 0 }, // 70 IIC_LdStSTFDU
  { 1, 117, 118, 0, 0 }, // 71 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 72 IIC_IntRFID
  { 0, 0, 0, 0, 0 }, // 73 IIC_IntRotateD
  { 1, 106, 107, 0, 0 }, // 74 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 75 IIC_SprSLBFEE
  { 0, 0, 0, 0, 0 }, // 76 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 77 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprSLBIEG
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprSLBMFEV
  { 0, 0, 0, 0, 0 }, // 81 IIC_SprSLBMTE
  { 0, 0, 0, 0, 0 }, // 82 IIC_SprSLBSYNC
  { 1, 106, 107, 0, 0 }, // 83 IIC_IntShift
  { 1, 126, 127, 0, 0 }, // 84 IIC_LdStSTWCX
  { 1, 110, 111, 0, 0 }, // 85 IIC_LdStSTU
  { 1, 110, 111, 0, 0 }, // 86 IIC_LdStSTUX
  { 0, 0, 0, 0, 0 }, // 87 IIC_LdStSTD
  { 0, 0, 0, 0, 0 }, // 88 IIC_LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 89 IIC_SprSTOP
  { 0, 0, 0, 0, 0 }, // 90 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 91 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 92 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 93 IIC_SprTLBIEL
  { 1, 127, 128, 0, 0 }, // 94 IIC_SprTLBSYNC
  { 1, 128, 129, 0, 0 }, // 95 IIC_IntTrapW
  { 1, 114, 115, 0, 0 }, // 96 IIC_VecFPCompare
  { 1, 114, 115, 0, 0 }, // 97 VADDUBM_VADDUDM_VADDUHM_VADDUWM_VEXTSB2D_VEXTSB2Ds_VEXTSB2W_VEXTSB2Ws_VEXTSH2D_VEXTSH2Ds_VEXTSH2W_VEXTSH2Ws_VEXTSW2D_VEXTSW2Ds_VSLD_VSRD_VSUBUBM_VSUBUDM_VSUBUHM_VSUBUWM_VPOPCNTB_VPOPCNTH_VSRAD_MTVSRDD_VEQV_VNAND_VNEGD_VNEGW_VORC_XXLAND_XXLANDC_XXLEQV_XXLEQVOnes_XXLNAND_XXLNOR_XXLOR_XXLORf_XXLORC_XXLXOR_XXLXORdpz_XXLXORspz_XXLXORz
  { 1, 108, 109, 0, 0 }, // 98 VAND_VANDC_V_SET0_V_SET0B_V_SET0H_VSLB_VSLH_VSLW_VSRB_VSRH_VSRW_VRLB_VRLD_VRLH_VRLW_VSRAB_VSRAH_VSRAW_XVABSDP_XVABSSP_XVNABSDP_XVNABSSP_XVCPSGNDP_XVCPSGNSP_XVIEXPDP_XVIEXPSP_XVXEXPDP_XVXEXPSP_VRLDMI_VRLDNM_VRLWMI_VRLWNM_VMRGEW_VMRGOW_VNOR_VOR_VSEL_VXOR_XVNEGDP_XVNEGSP_XSABSQP_XSCPSGNQP_XSIEXPQP_XSNABSQP_XSNEGQP_XSXEXPQP
  { 1, 125, 126, 0, 0 }, // 99 XXSEL
  { 1, 117, 118, 0, 0 }, // 100 TABORTDC_TABORTDCI_TABORTWC_TABORTWCI
  { 1, 121, 122, 0, 0 }, // 101 MTFSB0_MTFSB1
  { 1, 121, 122, 0, 0 }, // 102 MFFSCDRN_MFFSCDRNI_MFFSCRN_MFFSCRNI
  { 1, 106, 107, 0, 0 }, // 103 CMPRB_CMPRB8_CMPEQB
  { 0, 0, 0, 0, 0 }, // 104 TD_TDI
  { 1, 128, 129, 0, 0 }, // 105 TW_TWI
  { 1, 112, 113, 0, 0 }, // 106 FCMPUD_FCMPUS_FTDIV_FTSQRT
  { 1, 108, 109, 0, 0 }, // 107 XSTSTDCDP_XSTSTDCSP
  { 1, 108, 109, 0, 0 }, // 108 XSMAXCDP_XSMAXDP_XSMAXJDP_XSMINCDP_XSMINDP_XSMINJDP_XSXSIGDP_XSCVSPDPN
  { 1, 112, 113, 0, 0 }, // 109 XSCMPEQDP_XSCMPEXPDP_XSCMPGEDP_XSCMPGTDP_XSCMPODP_XSCMPUDP_XSTDIVDP_XSTSQRTDP
  { 1, 106, 107, 0, 0 }, // 110 CNTLZD_CNTLZD_rec_CNTLZW_CNTLZW8_CNTLZW8_rec_CNTLZW_rec_CNTTZD_CNTTZD_rec_CNTTZW_CNTTZW8_CNTTZW8_rec_CNTTZW_rec_POPCNTD_POPCNTW_CMPB_CMPB8_SETB_SETB8_BPERMD
  { 0, 0, 0, 0, 0 }, // 111 SLD_SRD_SRAD
  { 0, 0, 0, 0, 0 }, // 112 SRADI_EXTSWSLI_32_64_EXTSWSLI_SRADI_32_RLDIC
  { 1, 114, 115, 0, 0 }, // 113 MFVRD_MFVSRD_MTVRD_MTVSRD_MTVRWA_MTVRWZ_MTVSRWA_MTVSRWZ_MFVSRWZ_MFVRWZ
  { 1, 106, 107, 0, 0 }, // 114 CMPLW_CMPLWI_CMPW_CMPWI_CMPD_CMPDI_CMPLD_CMPLDI
  { 1, 106, 107, 0, 0 }, // 115 SUBFC_SUBFC8_SUBFC8O_SUBFCO_SUBFIC_SUBFIC8_ANDI8_rec_ANDIS8_rec_ANDIS_rec_ANDI_rec_ADDC_ADDC8_ADDC8O_ADDCO_ADDIC_ADDIC8_ADDIC_rec_ADDE_ADDE8_ADDE8O_ADDE8O_rec_ADDE8_rec_ADDEO_ADDEO_rec_ADDE_rec_ADDME_ADDME8_ADDME8O_ADDME8O_rec_ADDME8_rec_ADDMEO_ADDMEO_rec_ADDME_rec_ADDZE_ADDZE8_ADDZE8O_ADDZE8O_rec_ADDZE8_rec_ADDZEO_ADDZEO_rec_ADDZE_rec_SUBF_SUBF8_SUBF8O_SUBF8O_rec_SUBF8_rec_SUBFE_SUBFE8_SUBFE8O_SUBFE8O_rec_SUBFE8_rec_SUBFEO_SUBFEO_rec_SUBFE_rec_SUBFME_SUBFME8_SUBFME8O_SUBFME8O_rec_SUBFME8_rec_SUBFMEO_SUBFMEO_rec_SUBFME_rec_SUBFO_SUBFO_rec_SUBFZE_SUBFZE8_SUBFZE8O_SUBFZE8O_rec_SUBFZE8_rec_SUBFZEO_SUBFZEO_rec_SUBFZE_rec_SUBF_rec_POPCNTB_LA
  { 1, 106, 107, 0, 0 }, // 116 ADD4_ADD4O_ADD4O_rec_ADD4_rec_ADD8_ADD8O_ADD8O_rec_ADD8_rec_NEG_NEG8_NEG8O_NEG8O_rec_NEG8_rec_NEGO_NEGO_rec_NEG_rec_ADDI_ADDI8_ADDIS_ADDIS8_LI_LI8_LIS_LIS8_OR_OR8_OR8_rec_ORI_ORI8_ORIS_ORIS8_OR_rec_XOR_XOR8_XOR8_rec_XORI_XORI8_XORIS_XORIS8_XOR_rec_NAND_NAND8_NAND8_rec_NAND_rec_AND_AND8_AND8_rec_ANDC_ANDC8_ANDC8_rec_ANDC_rec_AND_rec_NOR_NOR8_NOR8_rec_NOR_rec_ORC_ORC8_ORC8_rec_ORC_rec_EQV_EQV8_EQV8_rec_EQV_rec_EXTSB_EXTSB8_EXTSB8_32_64_EXTSB8_rec_EXTSB_rec_EXTSH_EXTSH8_EXTSH8_32_64_EXTSH8_rec_EXTSH_rec_EXTSW_EXTSW_32_EXTSW_32_64_EXTSW_32_64_rec_EXTSW_rec_ADD4TLS_ADD8TLS_ADD8TLS__NOP
  { 0, 0, 0, 0, 0 }, // 117 ADDIStocHA_ADDIStocHA8_ADDItocL_COPY
  { 1, 109, 110, 0, 0 }, // 118 MCRF
  { 1, 109, 110, 0, 0 }, // 119 MCRXRX
  { 1, 108, 109, 0, 0 }, // 120 XSNABSDP_XSXEXPDP_XSABSDP_XSNEGDP_XSCPSGNDP
  { 1, 107, 108, 0, 0 }, // 121 RFEBB
  { 1, 117, 118, 0, 0 }, // 122 TBEGIN_TRECHKPT
  { 1, 110, 111, 0, 0 }, // 123 WAIT
  { 0, 0, 0, 0, 0 }, // 124 RLDCL_RLDCR
  { 1, 106, 107, 0, 0 }, // 125 RLWIMI_RLWIMI8
  { 0, 0, 0, 0, 0 }, // 126 RLDICL_RLDICL_32_RLDICL_32_64_RLDICR_RLDICR_32_RLDIMI
  { 0, 0, 0, 0, 0 }, // 127 MFOCRF_MFOCRF8
  { 1, 109, 110, 0, 0 }, // 128 MTOCRF_MTOCRF8
  { 1, 109, 110, 0, 0 }, // 129 CR6SET_CR6UNSET_CRSET_CRUNSET_CRAND_CRANDC_CRNAND_CRNOR_CROR_CRORC_CREQV_CRXOR
  { 1, 106, 107, 0, 0 }, // 130 SLW_SLW8_SRW_SRW8_RLWINM_RLWINM8_RLWNM_RLWNM8
  { 1, 112, 113, 0, 0 }, // 131 FABSD_FABSS_FNABSD_FNABSS_FNEGD_FNEGS_FCPSGND_FCPSGNS_FMR
  { 1, 106, 107, 0, 0 }, // 132 SRAW_SRAWI
  { 0, 0, 0, 0, 0 }, // 133 ISEL_ISEL8
  { 1, 108, 109, 0, 0 }, // 134 XSIEXPDP
  { 1, 117, 118, 0, 0 }, // 135 TRECLAIM_TSR_TABORT
  { 1, 110, 111, 0, 0 }, // 136 MFVSCR
  { 1, 110, 111, 0, 0 }, // 137 MTVSCR
  { 1, 114, 115, 0, 0 }, // 138 VCMPNEZB_VCMPNEZH_VCMPNEZW_VCMPEQUB_VCMPEQUD_VCMPEQUH_VCMPEQUW_VCMPNEB_VCMPNEH_VCMPNEW_VCMPEQFP_VCMPEQFP_rec_VCMPGEFP_VCMPGEFP_rec_VCMPGTFP_VCMPGTFP_rec_VCMPBFP_VCMPBFP_rec_VCMPGTSB_VCMPGTSB_rec_VCMPGTSD_VCMPGTSD_rec_VCMPGTSH_VCMPGTSH_rec_VCMPGTSW_VCMPGTSW_rec_VCMPGTUB_VCMPGTUB_rec_VCMPGTUD_VCMPGTUD_rec_VCMPGTUH_VCMPGTUH_rec_VCMPGTUW_VCMPGTUW_rec_VCMPNEB_rec_VCMPNEH_rec_VCMPNEW_rec_VCMPNEZB_rec_VCMPNEZH_rec_VCMPNEZW_rec_VCMPEQUB_rec_VCMPEQUD_rec_VCMPEQUH_rec_VCMPEQUW_rec_XVCMPEQDP_XVCMPEQDP_rec_XVCMPEQSP_XVCMPEQSP_rec_XVCMPGEDP_XVCMPGEDP_rec_XVCMPGESP_XVCMPGESP_rec_XVCMPGTDP_XVCMPGTDP_rec_XVCMPGTSP_XVCMPGTSP_rec
  { 1, 114, 115, 0, 0 }, // 139 VABSDUB_VABSDUH_VABSDUW_VCLZB_VCLZD_VCLZH_VCLZW_VCTZB_VCTZD_VCTZH_VCTZW_VPOPCNTW_VPOPCNTD_VPRTYBD_VPRTYBW
  { 1, 108, 109, 0, 0 }, // 140 VADDUBS_VADDUHS_VADDUWS_VAVGSB_VAVGSH_VAVGSW_VAVGUB_VAVGUH_VAVGUW_VADDSBS_VADDSHS_VADDSWS_VMAXFP_VMINFP_VMAXSB_VMAXSD_VMAXSH_VMAXSW_VMAXUB_VMAXUD_VMAXUH_VMAXUW_VMINSB_VMINSD_VMINSH_VMINSW_VMINUB_VMINUD_VMINUH_VMINUW_VBPERMD_VADDCUW_VSHASIGMAD_VSHASIGMAW_VSUBSBS_VSUBSHS_VSUBSWS_VSUBUBS_VSUBUHS_VSUBUWS_VSUBCUW_XVMAXDP_XVMAXSP_XVMINDP_XVMINSP_XVTSTDCDP_XVTSTDCSP_XVXSIGDP_XVXSIGSP
  { 1, 112, 113, 0, 0 }, // 141 XVTDIVDP_XVTDIVSP_XVTSQRTDP_XVTSQRTSP
  { 1, 108, 109, 0, 0 }, // 142 VADDFP_VCTSXS_VCTSXS_0_VCTUXS_VCTUXS_0_VEXPTEFP_VLOGEFP_VMADDFP_VMHADDSHS_VNMSUBFP_VREFP_VRFIM_VRFIN_VRFIP_VRFIZ_VRSQRTEFP_XVADDDP_XVADDSP_XVCVDPSP_XVCVDPSXDS_XVCVDPSXWS_XVCVDPUXDS_XVCVDPUXWS_XVCVHPSP_XVCVSPDP_XVCVSPHP_XVCVSPSXDS_XVCVSPSXWS_XVCVSPUXDS_XVCVSPUXWS_XVCVSXDDP_XVCVSXDSP_XVCVSXWDP_XVCVSXWSP_XVCVUXDDP_XVCVUXDSP_XVCVUXWDP_XVCVUXWSP_XVMADDADP_XVMADDASP_XVMADDMDP_XVMADDMSP_XVMSUBADP_XVMSUBASP_XVMSUBMDP_XVMSUBMSP_XVMULDP_XVMULSP_XVNMADDADP_XVNMADDASP_XVNMADDMDP_XVNMADDMSP_XVNMSUBADP_XVNMSUBASP_XVNMSUBMDP_XVNMSUBMSP_XVRDPI_XVRDPIC_XVRDPIM_XVRDPIP_XVRDPIZ_XVREDP_XVRESP_XVRSPI_XVRSPIC_XVRSPIM_XVRSPIP_XVRSPIZ_XVRSQRTEDP_XVRSQRTESP_XVSUBDP_XVSUBSP_VCFSX_VCFSX_0_VCFUX_VCFUX_0_VMHRADDSHS_VMLADDUHM_VMSUMMBM_VMSUMSHM_VMSUMSHS_VMSUMUBM_VMSUMUHM_VMSUMUDM_VMSUMUHS_VMULESB_VMULESH_VMULESW_VMULEUB_VMULEUH_VMULEUW_VMULOSB_VMULOSH_VMULOSW_VMULOUB_VMULOUH_VMULOUW_VSUM2SWS_VSUM4SBS_VSUM4SHS_VSUM4UBS_VSUMSWS
  { 1, 114, 115, 0, 0 }, // 143 VSUBFP_VMULUWM
  { 0, 0, 0, 0, 0 }, // 144 MADDHD_MADDHDU_MADDLD_MADDLD8_MULLD_MULLDO
  { 1, 122, 123, 0, 0 }, // 145 MULHD_MULHW_MULLW_MULLWO
  { 1, 123, 124, 0, 0 }, // 146 MULHDU_MULHWU
  { 1, 124, 125, 0, 0 }, // 147 MULLI_MULLI8
  { 1, 112, 113, 0, 0 }, // 148 FRSP_FRIMD_FRIMS_FRIND_FRINS_FRIPD_FRIPS_FRIZD_FRIZS_FRE_FRES_FADDS_FMSUBS_FMADDS_FSUBS_FCFID_FCFIDS_FCFIDU_FCFIDUS_FCTID_FCTIDU_FCTIDUZ_FCTIDZ_FCTIW_FCTIWU_FCTIWUZ_FCTIWZ_FRSQRTE_FRSQRTES_FNMADDS_FNMSUBS_FSELD_FSELS_FMULS
  { 1, 112, 113, 0, 0 }, // 149 FADD_FSUB
  { 1, 112, 113, 0, 0 }, // 150 FMSUB_FMADD_FNMADD_FNMSUB_FMUL
  { 1, 108, 109, 0, 0 }, // 151 XSMADDADP_XSMADDASP_XSMADDMDP_XSMADDMSP_XSMSUBADP_XSMSUBASP_XSMSUBMDP_XSMSUBMSP_XSMULDP_XSMULSP_XSNMADDADP_XSNMADDASP_XSNMADDMDP_XSNMADDMSP_XSNMSUBADP_XSNMSUBASP_XSNMSUBMDP_XSNMSUBMSP
  { 1, 112, 113, 0, 0 }, // 152 FSELD_rec_FSELS_rec
  { 1, 123, 124, 0, 0 }, // 153 MULHDU_rec_MULHWU_rec
  { 1, 122, 123, 0, 0 }, // 154 MULHD_rec_MULHW_rec_MULLWO_rec_MULLW_rec
  { 0, 0, 0, 0, 0 }, // 155 MULLDO_rec_MULLD_rec
  { 1, 112, 113, 0, 0 }, // 156 FRIMD_rec_FRIMS_rec_FRIND_rec_FRINS_rec_FRIPD_rec_FRIPS_rec_FRIZD_rec_FRIZS_rec_FRES_rec_FRE_rec_FADDS_rec_FSUBS_rec_FMSUBS_rec_FNMSUBS_rec_FMADDS_rec_FNMADDS_rec_FCFIDS_rec_FCFIDUS_rec_FCFIDU_rec_FCFID_rec_FCTIDUZ_rec_FCTIDU_rec_FCTIDZ_rec_FCTID_rec_FCTIWUZ_rec_FCTIWU_rec_FCTIWZ_rec_FCTIW_rec_FMULS_rec_FRSQRTES_rec_FRSQRTE_rec_FRSP_rec
  { 1, 112, 113, 0, 0 }, // 157 FADD_rec_FSUB_rec
  { 1, 112, 113, 0, 0 }, // 158 FMSUB_rec_FNMSUB_rec_FMADD_rec_FNMADD_rec_FMUL_rec
  { 1, 108, 109, 0, 0 }, // 159 XSADDDP_XSADDSP_XSCVDPHP_XSCVDPSP_XSCVDPSXDS_XSCVDPSXDSs_XSCVDPSXWS_XSCVDPUXDS_XSCVDPUXDSs_XSCVDPUXWS_XSCVDPSXWSs_XSCVDPUXWSs_XSCVHPDP_XSCVSPDP_XSCVSXDDP_XSCVSXDSP_XSCVUXDDP_XSCVUXDSP_XSRDPI_XSRDPIC_XSRDPIM_XSRDPIP_XSRDPIZ_XSREDP_XSRESP_XSRSQRTEDP_XSRSQRTESP_XSSUBDP_XSSUBSP_XSCVDPSPN_XSRSP
  { 1, 110, 111, 0, 0 }, // 160 LVSL_LVSR
  { 1, 125, 126, 0, 0 }, // 161 VSPLTISB_VSPLTISH_VSPLTISW_VSPLTB_VSPLTBs_VSPLTH_VSPLTHs_VSPLTW_XXMRGHW_XXMRGLW_XXPERM_XXPERMR_XXSLDWI_XXSLDWIs_XXSPLTIB_XXSPLTW_XXSPLTWs_XXPERMDI_XXPERMDIs
  { 1, 108, 109, 0, 0 }, // 162 V_SETALLONES_V_SETALLONESB_V_SETALLONESH_VBPERMQ_VGBBD_VMRGHB_VMRGHH_VMRGHW_VMRGLB_VMRGLH_VMRGLW_VPERM_VPERMR_VPERMXOR_VPKPX_VPKSDSS_VPKSDUS_VPKSHSS_VPKSHUS_VPKSWSS_VPKSWUS_VPKUDUM_VPKUDUS_VPKUHUM_VPKUHUS_VPKUWUM_VPKUWUS_VSL_VSLDOI_VSLO_VSLV_VSR_VSRO_VSRV_VUPKHPX_VUPKHSB_VUPKHSH_VUPKHSW_VUPKLPX_VUPKLSB_VUPKLSH_VUPKLSW_XXBRD_XXBRH_XXBRQ_XXBRW_XXEXTRACTUW_XXINSERTW_VADDCUQ_VADDECUQ_VADDEUQM_VMUL10CUQ_VMUL10ECUQ_VMUL10EUQ_VMUL10UQ_VSUBCUQ_VSUBECUQ_VSUBEUQM_XSTSTDCQP_XSXSIGQP_BCDCFN_rec_BCDCFZ_rec_BCDCPSGN_rec_BCDCTN_rec_BCDCTZ_rec_BCDSETSGN_rec_BCDS_rec_BCDTRUNC_rec_BCDUS_rec_BCDUTRUNC_rec
  { 1, 114, 115, 0, 0 }, // 163 VEXTRACTUB_VEXTRACTUH_VEXTRACTUW_VINSERTB_VINSERTD_VINSERTH_VINSERTW_MFVSRLD_MTVSRWS_VCLZLSBB_VCTZLSBB_VEXTRACTD_VEXTUBLX_VEXTUBRX_VEXTUHLX_VEXTUHRX_VEXTUWLX_VEXTUWRX_VPRTYBQ_VADDUQM_VSUBUQM
  { 1, 112, 113, 0, 0 }, // 164 XSCMPEXPQP_XSCMPOQP_XSCMPUQP
  { 1, 108, 109, 0, 0 }, // 165 BCDSR_rec_XSADDQP_XSADDQPO_XSCVDPQP_XSCVQPDP_XSCVQPDPO_XSCVQPSDZ_XSCVQPSWZ_XSCVQPUDZ_XSCVQPUWZ_XSCVSDQP_XSCVUDQP_XSRQPI_XSRQPIX_XSRQPXP_XSSUBQP_XSSUBQPO
  { 1, 108, 109, 0, 0 }, // 166 BCDCTSQ_rec
  { 1, 108, 109, 0, 0 }, // 167 XSMADDQP_XSMADDQPO_XSMSUBQP_XSMSUBQPO_XSMULQP_XSMULQPO_XSNMADDQP_XSNMADDQPO_XSNMSUBQP_XSNMSUBQPO
  { 1, 108, 109, 0, 0 }, // 168 BCDCFSQ_rec
  { 1, 108, 109, 0, 0 }, // 169 XSDIVQP_XSDIVQPO
  { 1, 108, 109, 0, 0 }, // 170 XSSQRTQP_XSSQRTQPO
  { 1, 110, 111, 0, 0 }, // 171 LXVL_LXVLL
  { 1, 110, 111, 0, 0 }, // 172 LVEBX_LVEHX_LVEWX_LVX_LVXL
  { 1, 110, 111, 0, 0 }, // 173 LXSIBZX_LXSIHZX_LXSDX_LXVB16X_LXVD2X_LXVWSX_LXSIWZX_LXV_LXVX_LXSD
  { 0, 0, 0, 0, 0 }, // 174 DFLOADf64_XFLOADf64_LIWZX
  { 1, 110, 111, 0, 0 }, // 175 DCBF_DCBFEP_DCBST_DCBSTEP_DCBT_DCBTEP_DCBZ_DCBZEP_DCBZL_DCBZLEP_DCBTST_DCBTSTEP
  { 0, 0, 0, 0, 0 }, // 176 CP_COPY_CP_COPY8
  { 0, 0, 0, 0, 0 }, // 177 CP_PASTE_CP_PASTE8
  { 1, 110, 111, 0, 0 }, // 178 ICBI_ICBIEP
  { 1, 110, 111, 0, 0 }, // 179 ICBT_ICBTLS_LBZ_LBZ8_LBZCIX_LBZX_LBZX8_LBZXTLS_LBZXTLS__LBZXTLS_32_LDBRX_LDCIX_LHBRX_LHBRX8_LHZ_LHZ8_LHZCIX_LHZX_LHZX8_LHZXTLS_LHZXTLS__LHZXTLS_32_LWBRX_LWBRX8_LWZ_LWZ8_LWZCIX_LWZX_LWZX8_LWZXTLS_LWZXTLS__LWZXTLS_32_EnforceIEIO_LSWI
  { 1, 118, 119, 0, 0 }, // 180 LBARX_LBARXL_LHARX_LHARXL_LWARX_LWARXL
  { 0, 0, 0, 0, 0 }, // 181 LD_LDX_LDXTLS_LDXTLS__DARN
  { 0, 0, 0, 0, 0 }, // 182 LDARX_LDARXL
  { 0, 0, 0, 0, 0 }, // 183 CP_ABORT
  { 1, 117, 118, 0, 0 }, // 184 ISYNC
  { 0, 0, 0, 0, 0 }, // 185 MSGSYNC
  { 1, 127, 128, 0, 0 }, // 186 TLBSYNC
  { 1, 105, 106, 0, 0 }, // 187 SYNC
  { 1, 119, 120, 0, 0 }, // 188 LMW
  { 1, 110, 111, 0, 0 }, // 189 LFIWZX_LFDX_LFD
  { 0, 0, 0, 0, 0 }, // 190 SLBIA
  { 0, 0, 0, 0, 0 }, // 191 SLBIE
  { 0, 0, 0, 0, 0 }, // 192 SLBMFEE
  { 0, 0, 0, 0, 0 }, // 193 SLBMFEV
  { 0, 0, 0, 0, 0 }, // 194 SLBMTE
  { 0, 0, 0, 0, 0 }, // 195 TLBIEL
  { 1, 110, 111, 0, 0 }, // 196 LHZU_LHZU8_LWZU_LWZU8
  { 1, 110, 111, 0, 0 }, // 197 LHZUX_LHZUX8_LWZUX_LWZUX8
  { 1, 117, 118, 0, 0 }, // 198 TEND
  { 1, 126, 127, 0, 0 }, // 199 STBCX_STHCX_STWCX
  { 0, 0, 0, 0, 0 }, // 200 STDCX
  { 0, 0, 0, 0, 0 }, // 201 LDMX
  { 1, 110, 111, 0, 0 }, // 202 LHA_LHA8_LHAX_LHAX8_LWAX_LWAX_32
  { 0, 0, 0, 0, 0 }, // 203 CP_PASTE8_rec_CP_PASTE_rec
  { 0, 0, 0, 0, 0 }, // 204 LWA_LWA_32
  { 1, 117, 118, 0, 0 }, // 205 TCHECK
  { 1, 110, 111, 0, 0 }, // 206 LFIWAX
  { 1, 110, 111, 0, 0 }, // 207 LXSIWAX
  { 0, 0, 0, 0, 0 }, // 208 LIWAX
  { 1, 110, 111, 0, 0 }, // 209 LFSX_LFS
  { 1, 110, 111, 0, 0 }, // 210 LXSSP_LXSSPX
  { 0, 0, 0, 0, 0 }, // 211 XFLOADf32_DFLOADf32
  { 1, 110, 111, 0, 0 }, // 212 LHAU_LHAU8
  { 1, 110, 111, 0, 0 }, // 213 LHAUX_LHAUX8_LWAUX
  { 1, 110, 111, 0, 0 }, // 214 LXVH8X_LXVDSX_LXVW4X
  { 1, 110, 111, 0, 0 }, // 215 STFD_STFDX_STFIWX_STFS_STFSX_STXSD_STXSDX_STXSIBX_STXSIBXv_STXSIHX_STXSIHXv_STXSIWX_STXSSP_STXSSPX
  { 1, 110, 111, 0, 0 }, // 216 STW_STW8_STDBRX_STHBRX_STWBRX_STB_STB8_STH_STH8_STBX_STBX8_STBXTLS_STBXTLS__STBXTLS_32_STHX_STHX8_STHXTLS_STHXTLS__STHXTLS_32_STWX_STWX8_STWXTLS_STWXTLS__STWXTLS_32
  { 0, 0, 0, 0, 0 }, // 217 DFSTOREf32_DFSTOREf64_XFSTOREf32_XFSTOREf64_STIWX
  { 0, 0, 0, 0, 0 }, // 218 STD_STDX_STDXTLS_STDXTLS_
  { 1, 110, 111, 0, 0 }, // 219 STBCIX_STDCIX_STHCIX_STWCIX_STSWI
  { 0, 0, 0, 0, 0 }, // 220 SLBIEG
  { 1, 119, 120, 0, 0 }, // 221 STMW
  { 0, 0, 0, 0, 0 }, // 222 TLBIE
  { 1, 110, 111, 0, 0 }, // 223 STVEBX_STVEHX_STVEWX_STVX_STVXL
  { 1, 110, 111, 0, 0 }, // 224 STXV_STXVB16X_STXVD2X_STXVH8X_STXVW4X_STXVX
  { 1, 110, 111, 0, 0 }, // 225 STXVL_STXVLL
  { 1, 117, 118, 0, 0 }, // 226 MTCTR_MTCTR8_MTCTR8loop_MTCTRloop_MTLR_MTLR8
  { 1, 106, 107, 0, 0 }, // 227 MFVRSAVE_MFVRSAVEv_MTVRSAVE_MTVRSAVEv
  { 0, 0, 0, 0, 0 }, // 228 MFPMR
  { 0, 0, 0, 0, 0 }, // 229 MTPMR
  { 1, 109, 110, 0, 0 }, // 230 MFTB_MFTB8
  { 1, 120, 121, 0, 0 }, // 231 MFCTR_MFCTR8_MFLR_MFLR8_MFSPR_MFSPR8
  { 1, 109, 110, 0, 0 }, // 232 MFMSR
  { 1, 109, 110, 0, 0 }, // 233 MTMSR
  { 0, 0, 0, 0, 0 }, // 234 MTMSRD
  { 1, 117, 118, 0, 0 }, // 235 MTSPR_MTSPR8
  { 1, 111, 112, 0, 0 }, // 236 DIVW_DIVWO_DIVWU_DIVWUO_MODSW
  { 1, 111, 112, 0, 0 }, // 237 DIVWE_DIVWEO_DIVWEU_DIVWEUO_MODSD_MODUD_MODUW
  { 0, 0, 0, 0, 0 }, // 238 DIVD_DIVDO_DIVDU_DIVDUO
  { 0, 0, 0, 0, 0 }, // 239 DIVDE_DIVDEO_DIVDEU_DIVDEUO
  { 1, 111, 112, 0, 0 }, // 240 DIVWO_rec_DIVWUO_rec_DIVWU_rec_DIVW_rec
  { 0, 0, 0, 0, 0 }, // 241 DIVD_rec_DIVDO_rec_DIVDU_rec_DIVDUO_rec
  { 1, 111, 112, 0, 0 }, // 242 DIVWE_rec_DIVWEO_rec_DIVWEU_rec_DIVWEUO_rec
  { 0, 0, 0, 0, 0 }, // 243 DIVDE_rec_DIVDEO_rec_DIVDEU_rec_DIVDEUO_rec
  { 1, 109, 110, 0, 0 }, // 244 MTCRF_MTCRF8
  { 1, 106, 107, 0, 0 }, // 245 ADDC8O_rec_ADDC8_rec_ADDCO_rec_ADDC_rec_SUBFC8O_rec_SUBFC8_rec_SUBFCO_rec_SUBFC_rec
  { 1, 112, 113, 0, 0 }, // 246 FABSD_rec_FABSS_rec_FNABSD_rec_FNABSS_rec_FCPSGND_rec_FCPSGNS_rec_FNEGD_rec_FNEGS_rec_FMR_rec
  { 1, 109, 110, 0, 0 }, // 247 MCRFS
  { 1, 121, 122, 0, 0 }, // 248 MTFSF_MTFSF_rec_MTFSFI_MTFSFI_rec
  { 1, 121, 122, 0, 0 }, // 249 MTFSFb
  { 0, 0, 0, 0, 0 }, // 250 RLDCL_rec_RLDCR_rec
  { 0, 0, 0, 0, 0 }, // 251 RLDICL_rec_RLDICR_rec_RLDICL_32_rec_RLDIMI_rec
  { 1, 106, 107, 0, 0 }, // 252 RLWIMI8_rec_RLWIMI_rec
  { 1, 106, 107, 0, 0 }, // 253 RLWINM8_rec_RLWINM_rec_RLWNM8_rec_RLWNM_rec_SLW8_rec_SLW_rec_SRW8_rec_SRW_rec
  { 1, 106, 107, 0, 0 }, // 254 SRAWI_rec_SRAW_rec
  { 1, 121, 122, 0, 0 }, // 255 MFFS_MFFSCE_MFFSL_MFFS_rec
  { 1, 109, 110, 0, 0 }, // 256 MFCR_MFCR8
  { 0, 0, 0, 0, 0 }, // 257 EXTSWSLI_32_64_rec_SRADI_rec_EXTSWSLI_rec_RLDIC_rec
  { 0, 0, 0, 0, 0 }, // 258 SRAD_rec_SLD_rec_SRD_rec
  { 1, 113, 114, 0, 0 }, // 259 FDIV
  { 1, 113, 114, 0, 0 }, // 260 FDIV_rec
  { 0, 0, 0, 0, 0 }, // 261 XSSQRTDP
  { 0, 0, 0, 0, 0 }, // 262 FSQRT
  { 0, 0, 0, 0, 0 }, // 263 XVSQRTDP
  { 0, 0, 0, 0, 0 }, // 264 XVSQRTSP
  { 0, 0, 0, 0, 0 }, // 265 FSQRT_rec
  { 0, 0, 0, 0, 0 }, // 266 XSSQRTSP
  { 0, 0, 0, 0, 0 }, // 267 FSQRTS
  { 0, 0, 0, 0, 0 }, // 268 FSQRTS_rec
  { 1, 113, 114, 0, 0 }, // 269 XSDIVDP
  { 1, 116, 117, 0, 0 }, // 270 FDIVS
  { 1, 116, 117, 0, 0 }, // 271 FDIVS_rec
  { 1, 116, 117, 0, 0 }, // 272 XSDIVSP
  { 1, 116, 117, 0, 0 }, // 273 XVDIVSP
  { 1, 113, 114, 0, 0 }, // 274 XVDIVDP
  { 1, 110, 111, 0, 0 }, // 275 LFSU
  { 1, 110, 111, 0, 0 }, // 276 LFSUX
  { 1, 110, 111, 0, 0 }, // 277 STFDU_STFDUX_STFSU_STFSUX
  { 1, 110, 111, 0, 0 }, // 278 STBU_STBU8_STDU_STHU_STHU8_STWU_STWU8
  { 1, 110, 111, 0, 0 }, // 279 STBUX_STBUX8_STDUX_STHUX_STHUX8_STWUX_STWUX8
  { 1, 110, 111, 0, 0 }, // 280 LBZU_LBZU8
  { 1, 110, 111, 0, 0 }, // 281 LBZUX_LBZUX8
  { 0, 0, 0, 0, 0 }, // 282 LDU
  { 0, 0, 0, 0, 0 }, // 283 LDUX
  { 1, 110, 111, 0, 0 }, // 284 LFDU
  { 1, 110, 111, 0, 0 }, // 285 LFDUX
  { 1, 108, 109, 0, 0 }, // 286 VPMSUMB_VPMSUMD_VPMSUMH_VPMSUMW_VCIPHER_VCIPHERLAST_VNCIPHER_VNCIPHERLAST_VSBOX
  { 1, 107, 108, 0, 0 }, // 287 BCCCTR_BCCCTR8_BCCCTRL_BCCCTRL8_BCCL_BCCLA_BCCLR_BCCLRL_BCCTR_BCCTR8_BCCTR8n_BCCTRL_BCCTRL8_BCCTRL8n_BCCTRLn_BCCTRn_BDNZ_BDNZ8_BDNZA_BDNZAm_BDNZAp_BDNZm_BDNZp_BDZ_BDZ8_BDZA_BDZAm_BDZAp_BDZm_BDZp_BDNZL_BDNZLA_BDNZLAm_BDNZLAp_BDNZLR_BDNZLR8_BDNZLRL_BDNZLRLm_BDNZLRLp_BDNZLRm_BDNZLRp_BDNZLm_BDNZLp_BDZL_BDZLA_BDZLAm_BDZLAp_BDZLR_BDZLR8_BDZLRL_BDZLRLm_BDZLRLp_BDZLRm_BDZLRp_BDZLm_BDZLp_BL_BL_NOP_BL_TLS_BL8_BL8_NOP_BL8_NOP_TLS_BL8_TLS_BL8_TLS__BLA_BLA8_BLA8_NOP_BLR_BLR8_BLRL_TAILB_TAILB8_TAILBA_TAILBA8_TAILBCTR_TAILBCTR8_gBC_gBCA_gBCAat_gBCCTR_gBCCTRL_gBCL_gBCLA_gBCLAat_gBCLR_gBCLRL_gBCLat_gBCat_BCLR_BCLRL_BCLRLn_BCLRn_BCTR_BCTR8_BCTRL_BCTRL8_B_BA_BC_BCC_BCCA_BCL_BCLalways_BCLn_BCTRL8_LDinto_toc_BCTRL_LWZinto_toc_BCn_CTRL_DEP
  { 1, 107, 108, 0, 0 }, // 288 ADDPCIS
  { 1, 110, 111, 0, 0 }, // 289 LDAT_LWAT
  { 1, 110, 111, 0, 0 }, // 290 STDAT_STWAT
  { 1, 106, 107, 0, 0 }, // 291 BRINC
  { 1, 114, 115, 0, 0 }, // 292 EVABS_EVEQV_EVNAND_EVNEG_EVADDIW_EVADDW_EVAND_EVANDC_EVCMPEQ_EVCMPGTS_EVCMPGTU_EVCMPLTS_EVCMPLTU_EVCNTLSW_EVCNTLZW_EVEXTSB_EVEXTSH_EVMERGEHI_EVMERGEHILO_EVMERGELO_EVMERGELOHI_EVNOR_EVOR_EVORC_EVXOR_EVRLW_EVRLWI_EVRNDW_EVSLW_EVSLWI_EVSPLATFI_EVSPLATI_EVSRWIS_EVSRWIU_EVSRWS_EVSRWU_EVSUBFW_EVSUBIFW
  { 1, 115, 116, 0, 0 }, // 293 EVMRA_EVADDSMIAAW_EVADDSSIAAW_EVADDUMIAAW_EVADDUSIAAW_EVDIVWS_EVDIVWU_EVMHEGSMFAA_EVMHEGSMFAN_EVMHEGSMIAA_EVMHEGSMIAN_EVMHEGUMIAA_EVMHEGUMIAN_EVMHESMF_EVMHESMFA_EVMHESMFAAW_EVMHESMFANW_EVMHESMI_EVMHESMIA_EVMHESMIAAW_EVMHESMIANW_EVMHESSF_EVMHESSFA_EVMHESSFAAW_EVMHESSFANW_EVMHESSIAAW_EVMHESSIANW_EVMHEUMI_EVMHEUMIA_EVMHEUMIAAW_EVMHEUMIANW_EVMHEUSIAAW_EVMHEUSIANW_EVMHOGSMFAA_EVMHOGSMFAN_EVMHOGSMIAA_EVMHOGSMIAN_EVMHOGUMIAA_EVMHOGUMIAN_EVMHOSMF_EVMHOSMFA_EVMHOSMFAAW_EVMHOSMFANW_EVMHOSMI_EVMHOSMIA_EVMHOSMIAAW_EVMHOSMIANW_EVMHOSSF_EVMHOSSFA_EVMHOSSFAAW_EVMHOSSFANW_EVMHOSSIAAW_EVMHOSSIANW_EVMHOUMI_EVMHOUMIA_EVMHOUMIAAW_EVMHOUMIANW_EVMHOUSIAAW_EVMHOUSIANW_EVMWHSMF_EVMWHSMFA_EVMWHSMI_EVMWHSMIA_EVMWHSSF_EVMWHSSFA_EVMWHUMI_EVMWHUMIA_EVMWLSMIAAW_EVMWLSMIANW_EVMWLSSIAAW_EVMWLSSIANW_EVMWLUMI_EVMWLUMIA_EVMWLUMIAAW_EVMWLUMIANW_EVMWLUSIAAW_EVMWLUSIANW_EVMWSMF_EVMWSMFA_EVMWSMFAA_EVMWSMFAN_EVMWSMI_EVMWSMIA_EVMWSMIAA_EVMWSMIAN_EVMWSSF_EVMWSSFA_EVMWSSFAA_EVMWSSFAN_EVMWUMI_EVMWUMIA_EVMWUMIAA_EVMWUMIAN_EVSUBFSMIAAW_EVSUBFSSIAAW_EVSUBFUMIAAW_EVSUBFUSIAAW
  { 1, 110, 111, 0, 0 }, // 294 EVLDD_EVLDDX_EVLDH_EVLDHX_EVLDW_EVLDWX_EVLHHESPLAT_EVLHHESPLATX_EVLHHOSSPLAT_EVLHHOSSPLATX_EVLHHOUSPLAT_EVLHHOUSPLATX_EVLWHE_EVLWHEX_EVLWHOS_EVLWHOSX_EVLWHOU_EVLWHOUX_EVLWHSPLAT_EVLWHSPLATX_EVLWWSPLAT_EVLWWSPLATX
  { 1, 110, 111, 0, 0 }, // 295 EVSTDD_EVSTDDX_EVSTDH_EVSTDHX_EVSTDW_EVSTDWX_EVSTWHE_EVSTWHEX_EVSTWHO_EVSTWHOX_EVSTWWE_EVSTWWEX_EVSTWWO_EVSTWWOX
  { 1, 107, 108, 0, 0 }, // 296 HRFID_ATTN_CLRBHRB_MFBHRBE_NAP_RFCI_RFDI_RFMCI_SC
  { 1, 117, 118, 0, 0 }, // 297 RFI
  { 0, 0, 0, 0, 0 }, // 298 RFID
  { 1, 110, 111, 0, 0 }, // 299 DSS_DSSALL_DST_DST64_DSTST_DSTST64_DSTSTT_DSTSTT64_DSTT_DSTT64_ICBLQ_LBEPX_LHEPX_LWEPX_TLBIVAX_TLBLD_TLBLI_TLBRE_TLBRE2_TLBSX_TLBSX2_TLBSX2D_TLBWE_TLBWE2_MBAR_TRAP_DCCCI_ICCCI
  { 1, 110, 111, 0, 0 }, // 300 ICBLC_STBEPX_STHEPX_STWEPX
  { 1, 110, 111, 0, 0 }, // 301 LFDEPX
  { 1, 110, 111, 0, 0 }, // 302 STFDEPX
  { 1, 120, 121, 0, 0 }, // 303 MFSR_MFSRIN
  { 1, 117, 118, 0, 0 }, // 304 MTSR_MTSRIN
  { 1, 120, 121, 0, 0 }, // 305 MFDCR
  { 1, 117, 118, 0, 0 }, // 306 MTDCR
  { 1, 106, 107, 0, 0 }, // 307 NOP_GT_PWR6_NOP_GT_PWR7
  { 0, 0, 0, 0, 0 }, // 308 TLBIA
  { 1, 109, 110, 0, 0 }, // 309 WRTEE_WRTEEI
  { 1, 105, 106, 0, 0 }, // 310 MSYNC
  { 0, 0, 0, 0, 0 }, // 311 SLBSYNC
  { 0, 0, 0, 0, 0 }, // 312 SLBFEE_rec
  { 0, 0, 0, 0, 0 }, // 313 STOP
  { 1, 110, 111, 0, 0 }, // 314 DCBA_DCBI
  { 0, uint16_t(~0U), uint16_t(~0U), uint16_t(~0U), uint16_t(~0U) }// end marker
};

static const llvm::InstrItinerary G4PlusItineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 129, 130, 0, 0 }, // 1 IIC_LdStSync
  { 1, 130, 131, 0, 0 }, // 2 IIC_IntSimple
  { 1, 130, 131, 0, 0 }, // 3 IIC_IntGeneral
  { 1, 131, 132, 0, 0 }, // 4 IIC_BrB
  { 1, 132, 133, 0, 0 }, // 5 IIC_VecFP
  { 1, 130, 131, 0, 0 }, // 6 IIC_IntCompare
  { 0, 0, 0, 0, 0 }, // 7 IIC_SprABORT
  { 0, 0, 0, 0, 0 }, // 8 IIC_LdStCOPY
  { 0, 0, 0, 0, 0 }, // 9 IIC_LdStPASTE
  { 1, 133, 134, 0, 0 }, // 10 IIC_BrCR
  { 0, 0, 0, 0, 0 }, // 11 IIC_LdStLD
  { 1, 134, 135, 0, 0 }, // 12 IIC_LdStDCBF
  { 1, 134, 135, 0, 0 }, // 13 IIC_LdStLoad
  { 0, 0, 0, 0, 0 }, // 14 IIC_IntDivD
  { 1, 135, 136, 0, 0 }, // 15 IIC_IntDivW
  { 0, 0, 0, 0, 0 }, // 16 IIC_FPDGeneral
  { 1, 136, 137, 0, 0 }, // 17 IIC_FPAddSub
  { 1, 137, 138, 0, 0 }, // 18 IIC_FPDivD
  { 0, 0, 0, 0, 0 }, // 19 IIC_FPSGeneral
  { 1, 136, 137, 0, 0 }, // 20 IIC_FPCompare
  { 1, 136, 137, 0, 0 }, // 21 IIC_FPGeneral
  { 1, 138, 139, 0, 0 }, // 22 IIC_VecGeneral
  { 1, 139, 140, 0, 0 }, // 23 IIC_VecComplex
  { 1, 134, 135, 0, 0 }, // 24 IIC_LdStStore
  { 0, 0, 0, 0, 0 }, // 25 IIC_IntRotateDI
  { 1, 140, 141, 0, 0 }, // 26 IIC_FPDivS
  { 1, 136, 137, 0, 0 }, // 27 IIC_FPFused
  { 0, 0, 0, 0, 0 }, // 28 IIC_FPSqrtD
  { 0, 0, 0, 0, 0 }, // 29 IIC_FPSqrtS
  { 1, 141, 142, 0, 0 }, // 30 IIC_LdStICBI
  { 0, 0, 0, 0, 0 }, // 31 IIC_IntISEL
  { 1, 142, 143, 0, 0 }, // 32 IIC_SprISYNC
  { 1, 134, 135, 0, 0 }, // 33 IIC_LdStLWARX
  { 1, 134, 135, 0, 0 }, // 34 IIC_LdStLoadUpd
  { 1, 134, 135, 0, 0 }, // 35 IIC_LdStLoadUpdX
  { 0, 0, 0, 0, 0 }, // 36 IIC_LdStLDARX
  { 0, 0, 0, 0, 0 }, // 37 IIC_LdStLDU
  { 0, 0, 0, 0, 0 }, // 38 IIC_LdStLDUX
  { 1, 143, 144, 0, 0 }, // 39 IIC_LdStLFD
  { 1, 143, 144, 0, 0 }, // 40 IIC_LdStLFDU
  { 1, 143, 144, 0, 0 }, // 41 IIC_LdStLFDUX
  { 1, 134, 135, 0, 0 }, // 42 IIC_LdStLHA
  { 1, 134, 135, 0, 0 }, // 43 IIC_LdStLHAU
  { 1, 134, 135, 0, 0 }, // 44 IIC_LdStLHAUX
  { 1, 144, 145, 0, 0 }, // 45 IIC_LdStLMW
  { 1, 134, 135, 0, 0 }, // 46 IIC_LdStLWA
  { 0, 0, 0, 0, 0 }, // 47 IIC_IntMulHD
  { 1, 133, 134, 0, 0 }, // 48 IIC_BrMCR
  { 1, 133, 134, 0, 0 }, // 49 IIC_BrMCRX
  { 1, 133, 134, 0, 0 }, // 50 IIC_SprMFCR
  { 1, 145, 146, 0, 0 }, // 51 IIC_SprMFSPR
  { 1, 136, 137, 0, 0 }, // 52 IIC_IntMFFS
  { 1, 141, 142, 0, 0 }, // 53 IIC_SprMFMSR
  { 0, 0, 0, 0, 0 }, // 54 IIC_SprMFCRF
  { 0, 0, 0, 0, 0 }, // 55 IIC_SprMFPMR
  { 1, 145, 146, 0, 0 }, // 56 IIC_SprMFSR
  { 1, 146, 147, 0, 0 }, // 57 IIC_SprMFTB
  { 0, 0, 0, 0, 0 }, // 58 IIC_SprMSGSYNC
  { 1, 133, 134, 0, 0 }, // 59 IIC_SprMTSPR
  { 1, 136, 137, 0, 0 }, // 60 IIC_IntMTFSB0
  { 1, 133, 134, 0, 0 }, // 61 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 62 IIC_SprMTMSRD
  { 0, 0, 0, 0, 0 }, // 63 IIC_SprMTPMR
  { 1, 133, 134, 0, 0 }, // 64 IIC_SprMTSR
  { 1, 145, 146, 0, 0 }, // 65 IIC_IntMulHW
  { 1, 145, 146, 0, 0 }, // 66 IIC_IntMulHWU
  { 1, 141, 142, 0, 0 }, // 67 IIC_IntMulLI
  { 1, 147, 148, 0, 0 }, // 68 IIC_VecPerm
  { 1, 134, 135, 0, 0 }, // 69 IIC_LdStSTFD
  { 1, 134, 135, 0, 0 }, // 70 IIC_LdStSTFDU
  { 1, 130, 131, 0, 0 }, // 71 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 72 IIC_IntRFID
  { 0, 0, 0, 0, 0 }, // 73 IIC_IntRotateD
  { 1, 130, 131, 0, 0 }, // 74 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 75 IIC_SprSLBFEE
  { 0, 0, 0, 0, 0 }, // 76 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 77 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprSLBIEG
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprSLBMFEV
  { 0, 0, 0, 0, 0 }, // 81 IIC_SprSLBMTE
  { 0, 0, 0, 0, 0 }, // 82 IIC_SprSLBSYNC
  { 1, 148, 149, 0, 0 }, // 83 IIC_IntShift
  { 1, 134, 135, 0, 0 }, // 84 IIC_LdStSTWCX
  { 1, 134, 135, 0, 0 }, // 85 IIC_LdStSTU
  { 1, 134, 135, 0, 0 }, // 86 IIC_LdStSTUX
  { 1, 134, 135, 0, 0 }, // 87 IIC_LdStSTD
  { 1, 134, 135, 0, 0 }, // 88 IIC_LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 89 IIC_SprSTOP
  { 0, 0, 0, 0, 0 }, // 90 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 91 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 92 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 93 IIC_SprTLBIEL
  { 1, 134, 135, 0, 0 }, // 94 IIC_SprTLBSYNC
  { 1, 148, 149, 0, 0 }, // 95 IIC_IntTrapW
  { 1, 149, 150, 0, 0 }, // 96 IIC_VecFPCompare
  { 1, 138, 139, 0, 0 }, // 97 VADDUBM_VADDUDM_VADDUHM_VADDUWM_VEXTSB2D_VEXTSB2Ds_VEXTSB2W_VEXTSB2Ws_VEXTSH2D_VEXTSH2Ds_VEXTSH2W_VEXTSH2Ws_VEXTSW2D_VEXTSW2Ds_VSLD_VSRD_VSUBUBM_VSUBUDM_VSUBUHM_VSUBUWM_VPOPCNTB_VPOPCNTH_VSRAD_MTVSRDD_VEQV_VNAND_VNEGD_VNEGW_VORC_XXLAND_XXLANDC_XXLEQV_XXLEQVOnes_XXLNAND_XXLNOR_XXLOR_XXLORf_XXLORC_XXLXOR_XXLXORdpz_XXLXORspz_XXLXORz
  { 1, 132, 133, 0, 0 }, // 98 VAND_VANDC_V_SET0_V_SET0B_V_SET0H_VSLB_VSLH_VSLW_VSRB_VSRH_VSRW_VRLB_VRLD_VRLH_VRLW_VSRAB_VSRAH_VSRAW_XVABSDP_XVABSSP_XVNABSDP_XVNABSSP_XVCPSGNDP_XVCPSGNSP_XVIEXPDP_XVIEXPSP_XVXEXPDP_XVXEXPSP_VRLDMI_VRLDNM_VRLWMI_VRLWNM_VMRGEW_VMRGOW_VNOR_VOR_VSEL_VXOR_XVNEGDP_XVNEGSP_XSABSQP_XSCPSGNQP_XSIEXPQP_XSNABSQP_XSNEGQP_XSXEXPQP
  { 1, 147, 148, 0, 0 }, // 99 XXSEL
  { 1, 133, 134, 0, 0 }, // 100 TABORTDC_TABORTDCI_TABORTWC_TABORTWCI
  { 1, 136, 137, 0, 0 }, // 101 MTFSB0_MTFSB1
  { 1, 136, 137, 0, 0 }, // 102 MFFSCDRN_MFFSCDRNI_MFFSCRN_MFFSCRNI
  { 1, 130, 131, 0, 0 }, // 103 CMPRB_CMPRB8_CMPEQB
  { 0, 0, 0, 0, 0 }, // 104 TD_TDI
  { 1, 148, 149, 0, 0 }, // 105 TW_TWI
  { 1, 136, 137, 0, 0 }, // 106 FCMPUD_FCMPUS_FTDIV_FTSQRT
  { 1, 132, 133, 0, 0 }, // 107 XSTSTDCDP_XSTSTDCSP
  { 1, 132, 133, 0, 0 }, // 108 XSMAXCDP_XSMAXDP_XSMAXJDP_XSMINCDP_XSMINDP_XSMINJDP_XSXSIGDP_XSCVSPDPN
  { 1, 136, 137, 0, 0 }, // 109 XSCMPEQDP_XSCMPEXPDP_XSCMPGEDP_XSCMPGTDP_XSCMPODP_XSCMPUDP_XSTDIVDP_XSTSQRTDP
  { 1, 130, 131, 0, 0 }, // 110 CNTLZD_CNTLZD_rec_CNTLZW_CNTLZW8_CNTLZW8_rec_CNTLZW_rec_CNTTZD_CNTTZD_rec_CNTTZW_CNTTZW8_CNTTZW8_rec_CNTTZW_rec_POPCNTD_POPCNTW_CMPB_CMPB8_SETB_SETB8_BPERMD
  { 0, 0, 0, 0, 0 }, // 111 SLD_SRD_SRAD
  { 0, 0, 0, 0, 0 }, // 112 SRADI_EXTSWSLI_32_64_EXTSWSLI_SRADI_32_RLDIC
  { 1, 138, 139, 0, 0 }, // 113 MFVRD_MFVSRD_MTVRD_MTVSRD_MTVRWA_MTVRWZ_MTVSRWA_MTVSRWZ_MFVSRWZ_MFVRWZ
  { 1, 130, 131, 0, 0 }, // 114 CMPLW_CMPLWI_CMPW_CMPWI_CMPD_CMPDI_CMPLD_CMPLDI
  { 1, 130, 131, 0, 0 }, // 115 SUBFC_SUBFC8_SUBFC8O_SUBFCO_SUBFIC_SUBFIC8_ANDI8_rec_ANDIS8_rec_ANDIS_rec_ANDI_rec_ADDC_ADDC8_ADDC8O_ADDCO_ADDIC_ADDIC8_ADDIC_rec_ADDE_ADDE8_ADDE8O_ADDE8O_rec_ADDE8_rec_ADDEO_ADDEO_rec_ADDE_rec_ADDME_ADDME8_ADDME8O_ADDME8O_rec_ADDME8_rec_ADDMEO_ADDMEO_rec_ADDME_rec_ADDZE_ADDZE8_ADDZE8O_ADDZE8O_rec_ADDZE8_rec_ADDZEO_ADDZEO_rec_ADDZE_rec_SUBF_SUBF8_SUBF8O_SUBF8O_rec_SUBF8_rec_SUBFE_SUBFE8_SUBFE8O_SUBFE8O_rec_SUBFE8_rec_SUBFEO_SUBFEO_rec_SUBFE_rec_SUBFME_SUBFME8_SUBFME8O_SUBFME8O_rec_SUBFME8_rec_SUBFMEO_SUBFMEO_rec_SUBFME_rec_SUBFO_SUBFO_rec_SUBFZE_SUBFZE8_SUBFZE8O_SUBFZE8O_rec_SUBFZE8_rec_SUBFZEO_SUBFZEO_rec_SUBFZE_rec_SUBF_rec_POPCNTB_LA
  { 1, 130, 131, 0, 0 }, // 116 ADD4_ADD4O_ADD4O_rec_ADD4_rec_ADD8_ADD8O_ADD8O_rec_ADD8_rec_NEG_NEG8_NEG8O_NEG8O_rec_NEG8_rec_NEGO_NEGO_rec_NEG_rec_ADDI_ADDI8_ADDIS_ADDIS8_LI_LI8_LIS_LIS8_OR_OR8_OR8_rec_ORI_ORI8_ORIS_ORIS8_OR_rec_XOR_XOR8_XOR8_rec_XORI_XORI8_XORIS_XORIS8_XOR_rec_NAND_NAND8_NAND8_rec_NAND_rec_AND_AND8_AND8_rec_ANDC_ANDC8_ANDC8_rec_ANDC_rec_AND_rec_NOR_NOR8_NOR8_rec_NOR_rec_ORC_ORC8_ORC8_rec_ORC_rec_EQV_EQV8_EQV8_rec_EQV_rec_EXTSB_EXTSB8_EXTSB8_32_64_EXTSB8_rec_EXTSB_rec_EXTSH_EXTSH8_EXTSH8_32_64_EXTSH8_rec_EXTSH_rec_EXTSW_EXTSW_32_EXTSW_32_64_EXTSW_32_64_rec_EXTSW_rec_ADD4TLS_ADD8TLS_ADD8TLS__NOP
  { 0, 0, 0, 0, 0 }, // 117 ADDIStocHA_ADDIStocHA8_ADDItocL_COPY
  { 1, 133, 134, 0, 0 }, // 118 MCRF
  { 1, 133, 134, 0, 0 }, // 119 MCRXRX
  { 1, 132, 133, 0, 0 }, // 120 XSNABSDP_XSXEXPDP_XSABSDP_XSNEGDP_XSCPSGNDP
  { 1, 131, 132, 0, 0 }, // 121 RFEBB
  { 1, 133, 134, 0, 0 }, // 122 TBEGIN_TRECHKPT
  { 1, 134, 135, 0, 0 }, // 123 WAIT
  { 0, 0, 0, 0, 0 }, // 124 RLDCL_RLDCR
  { 1, 130, 131, 0, 0 }, // 125 RLWIMI_RLWIMI8
  { 0, 0, 0, 0, 0 }, // 126 RLDICL_RLDICL_32_RLDICL_32_64_RLDICR_RLDICR_32_RLDIMI
  { 0, 0, 0, 0, 0 }, // 127 MFOCRF_MFOCRF8
  { 1, 133, 134, 0, 0 }, // 128 MTOCRF_MTOCRF8
  { 1, 133, 134, 0, 0 }, // 129 CR6SET_CR6UNSET_CRSET_CRUNSET_CRAND_CRANDC_CRNAND_CRNOR_CROR_CRORC_CREQV_CRXOR
  { 1, 130, 131, 0, 0 }, // 130 SLW_SLW8_SRW_SRW8_RLWINM_RLWINM8_RLWNM_RLWNM8
  { 1, 136, 137, 0, 0 }, // 131 FABSD_FABSS_FNABSD_FNABSS_FNEGD_FNEGS_FCPSGND_FCPSGNS_FMR
  { 1, 148, 149, 0, 0 }, // 132 SRAW_SRAWI
  { 0, 0, 0, 0, 0 }, // 133 ISEL_ISEL8
  { 1, 132, 133, 0, 0 }, // 134 XSIEXPDP
  { 1, 133, 134, 0, 0 }, // 135 TRECLAIM_TSR_TABORT
  { 1, 134, 135, 0, 0 }, // 136 MFVSCR
  { 1, 134, 135, 0, 0 }, // 137 MTVSCR
  { 1, 149, 150, 0, 0 }, // 138 VCMPNEZB_VCMPNEZH_VCMPNEZW_VCMPEQUB_VCMPEQUD_VCMPEQUH_VCMPEQUW_VCMPNEB_VCMPNEH_VCMPNEW_VCMPEQFP_VCMPEQFP_rec_VCMPGEFP_VCMPGEFP_rec_VCMPGTFP_VCMPGTFP_rec_VCMPBFP_VCMPBFP_rec_VCMPGTSB_VCMPGTSB_rec_VCMPGTSD_VCMPGTSD_rec_VCMPGTSH_VCMPGTSH_rec_VCMPGTSW_VCMPGTSW_rec_VCMPGTUB_VCMPGTUB_rec_VCMPGTUD_VCMPGTUD_rec_VCMPGTUH_VCMPGTUH_rec_VCMPGTUW_VCMPGTUW_rec_VCMPNEB_rec_VCMPNEH_rec_VCMPNEW_rec_VCMPNEZB_rec_VCMPNEZH_rec_VCMPNEZW_rec_VCMPEQUB_rec_VCMPEQUD_rec_VCMPEQUH_rec_VCMPEQUW_rec_XVCMPEQDP_XVCMPEQDP_rec_XVCMPEQSP_XVCMPEQSP_rec_XVCMPGEDP_XVCMPGEDP_rec_XVCMPGESP_XVCMPGESP_rec_XVCMPGTDP_XVCMPGTDP_rec_XVCMPGTSP_XVCMPGTSP_rec
  { 1, 138, 139, 0, 0 }, // 139 VABSDUB_VABSDUH_VABSDUW_VCLZB_VCLZD_VCLZH_VCLZW_VCTZB_VCTZD_VCTZH_VCTZW_VPOPCNTW_VPOPCNTD_VPRTYBD_VPRTYBW
  { 1, 132, 133, 0, 0 }, // 140 VADDUBS_VADDUHS_VADDUWS_VAVGSB_VAVGSH_VAVGSW_VAVGUB_VAVGUH_VAVGUW_VADDSBS_VADDSHS_VADDSWS_VMAXFP_VMINFP_VMAXSB_VMAXSD_VMAXSH_VMAXSW_VMAXUB_VMAXUD_VMAXUH_VMAXUW_VMINSB_VMINSD_VMINSH_VMINSW_VMINUB_VMINUD_VMINUH_VMINUW_VBPERMD_VADDCUW_VSHASIGMAD_VSHASIGMAW_VSUBSBS_VSUBSHS_VSUBSWS_VSUBUBS_VSUBUHS_VSUBUWS_VSUBCUW_XVMAXDP_XVMAXSP_XVMINDP_XVMINSP_XVTSTDCDP_XVTSTDCSP_XVXSIGDP_XVXSIGSP
  { 1, 136, 137, 0, 0 }, // 141 XVTDIVDP_XVTDIVSP_XVTSQRTDP_XVTSQRTSP
  { 1, 132, 133, 0, 0 }, // 142 VADDFP_VCTSXS_VCTSXS_0_VCTUXS_VCTUXS_0_VEXPTEFP_VLOGEFP_VMADDFP_VMHADDSHS_VNMSUBFP_VREFP_VRFIM_VRFIN_VRFIP_VRFIZ_VRSQRTEFP_XVADDDP_XVADDSP_XVCVDPSP_XVCVDPSXDS_XVCVDPSXWS_XVCVDPUXDS_XVCVDPUXWS_XVCVHPSP_XVCVSPDP_XVCVSPHP_XVCVSPSXDS_XVCVSPSXWS_XVCVSPUXDS_XVCVSPUXWS_XVCVSXDDP_XVCVSXDSP_XVCVSXWDP_XVCVSXWSP_XVCVUXDDP_XVCVUXDSP_XVCVUXWDP_XVCVUXWSP_XVMADDADP_XVMADDASP_XVMADDMDP_XVMADDMSP_XVMSUBADP_XVMSUBASP_XVMSUBMDP_XVMSUBMSP_XVMULDP_XVMULSP_XVNMADDADP_XVNMADDASP_XVNMADDMDP_XVNMADDMSP_XVNMSUBADP_XVNMSUBASP_XVNMSUBMDP_XVNMSUBMSP_XVRDPI_XVRDPIC_XVRDPIM_XVRDPIP_XVRDPIZ_XVREDP_XVRESP_XVRSPI_XVRSPIC_XVRSPIM_XVRSPIP_XVRSPIZ_XVRSQRTEDP_XVRSQRTESP_XVSUBDP_XVSUBSP_VCFSX_VCFSX_0_VCFUX_VCFUX_0_VMHRADDSHS_VMLADDUHM_VMSUMMBM_VMSUMSHM_VMSUMSHS_VMSUMUBM_VMSUMUHM_VMSUMUDM_VMSUMUHS_VMULESB_VMULESH_VMULESW_VMULEUB_VMULEUH_VMULEUW_VMULOSB_VMULOSH_VMULOSW_VMULOUB_VMULOUH_VMULOUW_VSUM2SWS_VSUM4SBS_VSUM4SHS_VSUM4UBS_VSUMSWS
  { 1, 138, 139, 0, 0 }, // 143 VSUBFP_VMULUWM
  { 0, 0, 0, 0, 0 }, // 144 MADDHD_MADDHDU_MADDLD_MADDLD8_MULLD_MULLDO
  { 1, 145, 146, 0, 0 }, // 145 MULHD_MULHW_MULLW_MULLWO
  { 1, 145, 146, 0, 0 }, // 146 MULHDU_MULHWU
  { 1, 141, 142, 0, 0 }, // 147 MULLI_MULLI8
  { 1, 136, 137, 0, 0 }, // 148 FRSP_FRIMD_FRIMS_FRIND_FRINS_FRIPD_FRIPS_FRIZD_FRIZS_FRE_FRES_FADDS_FMSUBS_FMADDS_FSUBS_FCFID_FCFIDS_FCFIDU_FCFIDUS_FCTID_FCTIDU_FCTIDUZ_FCTIDZ_FCTIW_FCTIWU_FCTIWUZ_FCTIWZ_FRSQRTE_FRSQRTES_FNMADDS_FNMSUBS_FSELD_FSELS_FMULS
  { 1, 136, 137, 0, 0 }, // 149 FADD_FSUB
  { 1, 136, 137, 0, 0 }, // 150 FMSUB_FMADD_FNMADD_FNMSUB_FMUL
  { 1, 132, 133, 0, 0 }, // 151 XSMADDADP_XSMADDASP_XSMADDMDP_XSMADDMSP_XSMSUBADP_XSMSUBASP_XSMSUBMDP_XSMSUBMSP_XSMULDP_XSMULSP_XSNMADDADP_XSNMADDASP_XSNMADDMDP_XSNMADDMSP_XSNMSUBADP_XSNMSUBASP_XSNMSUBMDP_XSNMSUBMSP
  { 1, 136, 137, 0, 0 }, // 152 FSELD_rec_FSELS_rec
  { 1, 145, 146, 0, 0 }, // 153 MULHDU_rec_MULHWU_rec
  { 1, 145, 146, 0, 0 }, // 154 MULHD_rec_MULHW_rec_MULLWO_rec_MULLW_rec
  { 0, 0, 0, 0, 0 }, // 155 MULLDO_rec_MULLD_rec
  { 1, 136, 137, 0, 0 }, // 156 FRIMD_rec_FRIMS_rec_FRIND_rec_FRINS_rec_FRIPD_rec_FRIPS_rec_FRIZD_rec_FRIZS_rec_FRES_rec_FRE_rec_FADDS_rec_FSUBS_rec_FMSUBS_rec_FNMSUBS_rec_FMADDS_rec_FNMADDS_rec_FCFIDS_rec_FCFIDUS_rec_FCFIDU_rec_FCFID_rec_FCTIDUZ_rec_FCTIDU_rec_FCTIDZ_rec_FCTID_rec_FCTIWUZ_rec_FCTIWU_rec_FCTIWZ_rec_FCTIW_rec_FMULS_rec_FRSQRTES_rec_FRSQRTE_rec_FRSP_rec
  { 1, 136, 137, 0, 0 }, // 157 FADD_rec_FSUB_rec
  { 1, 136, 137, 0, 0 }, // 158 FMSUB_rec_FNMSUB_rec_FMADD_rec_FNMADD_rec_FMUL_rec
  { 1, 132, 133, 0, 0 }, // 159 XSADDDP_XSADDSP_XSCVDPHP_XSCVDPSP_XSCVDPSXDS_XSCVDPSXDSs_XSCVDPSXWS_XSCVDPUXDS_XSCVDPUXDSs_XSCVDPUXWS_XSCVDPSXWSs_XSCVDPUXWSs_XSCVHPDP_XSCVSPDP_XSCVSXDDP_XSCVSXDSP_XSCVUXDDP_XSCVUXDSP_XSRDPI_XSRDPIC_XSRDPIM_XSRDPIP_XSRDPIZ_XSREDP_XSRESP_XSRSQRTEDP_XSRSQRTESP_XSSUBDP_XSSUBSP_XSCVDPSPN_XSRSP
  { 1, 134, 135, 0, 0 }, // 160 LVSL_LVSR
  { 1, 147, 148, 0, 0 }, // 161 VSPLTISB_VSPLTISH_VSPLTISW_VSPLTB_VSPLTBs_VSPLTH_VSPLTHs_VSPLTW_XXMRGHW_XXMRGLW_XXPERM_XXPERMR_XXSLDWI_XXSLDWIs_XXSPLTIB_XXSPLTW_XXSPLTWs_XXPERMDI_XXPERMDIs
  { 1, 132, 133, 0, 0 }, // 162 V_SETALLONES_V_SETALLONESB_V_SETALLONESH_VBPERMQ_VGBBD_VMRGHB_VMRGHH_VMRGHW_VMRGLB_VMRGLH_VMRGLW_VPERM_VPERMR_VPERMXOR_VPKPX_VPKSDSS_VPKSDUS_VPKSHSS_VPKSHUS_VPKSWSS_VPKSWUS_VPKUDUM_VPKUDUS_VPKUHUM_VPKUHUS_VPKUWUM_VPKUWUS_VSL_VSLDOI_VSLO_VSLV_VSR_VSRO_VSRV_VUPKHPX_VUPKHSB_VUPKHSH_VUPKHSW_VUPKLPX_VUPKLSB_VUPKLSH_VUPKLSW_XXBRD_XXBRH_XXBRQ_XXBRW_XXEXTRACTUW_XXINSERTW_VADDCUQ_VADDECUQ_VADDEUQM_VMUL10CUQ_VMUL10ECUQ_VMUL10EUQ_VMUL10UQ_VSUBCUQ_VSUBECUQ_VSUBEUQM_XSTSTDCQP_XSXSIGQP_BCDCFN_rec_BCDCFZ_rec_BCDCPSGN_rec_BCDCTN_rec_BCDCTZ_rec_BCDSETSGN_rec_BCDS_rec_BCDTRUNC_rec_BCDUS_rec_BCDUTRUNC_rec
  { 1, 138, 139, 0, 0 }, // 163 VEXTRACTUB_VEXTRACTUH_VEXTRACTUW_VINSERTB_VINSERTD_VINSERTH_VINSERTW_MFVSRLD_MTVSRWS_VCLZLSBB_VCTZLSBB_VEXTRACTD_VEXTUBLX_VEXTUBRX_VEXTUHLX_VEXTUHRX_VEXTUWLX_VEXTUWRX_VPRTYBQ_VADDUQM_VSUBUQM
  { 1, 136, 137, 0, 0 }, // 164 XSCMPEXPQP_XSCMPOQP_XSCMPUQP
  { 1, 132, 133, 0, 0 }, // 165 BCDSR_rec_XSADDQP_XSADDQPO_XSCVDPQP_XSCVQPDP_XSCVQPDPO_XSCVQPSDZ_XSCVQPSWZ_XSCVQPUDZ_XSCVQPUWZ_XSCVSDQP_XSCVUDQP_XSRQPI_XSRQPIX_XSRQPXP_XSSUBQP_XSSUBQPO
  { 1, 132, 133, 0, 0 }, // 166 BCDCTSQ_rec
  { 1, 132, 133, 0, 0 }, // 167 XSMADDQP_XSMADDQPO_XSMSUBQP_XSMSUBQPO_XSMULQP_XSMULQPO_XSNMADDQP_XSNMADDQPO_XSNMSUBQP_XSNMSUBQPO
  { 1, 132, 133, 0, 0 }, // 168 BCDCFSQ_rec
  { 1, 132, 133, 0, 0 }, // 169 XSDIVQP_XSDIVQPO
  { 1, 132, 133, 0, 0 }, // 170 XSSQRTQP_XSSQRTQPO
  { 1, 134, 135, 0, 0 }, // 171 LXVL_LXVLL
  { 1, 134, 135, 0, 0 }, // 172 LVEBX_LVEHX_LVEWX_LVX_LVXL
  { 1, 143, 144, 0, 0 }, // 173 LXSIBZX_LXSIHZX_LXSDX_LXVB16X_LXVD2X_LXVWSX_LXSIWZX_LXV_LXVX_LXSD
  { 0, 0, 0, 0, 0 }, // 174 DFLOADf64_XFLOADf64_LIWZX
  { 1, 134, 135, 0, 0 }, // 175 DCBF_DCBFEP_DCBST_DCBSTEP_DCBT_DCBTEP_DCBZ_DCBZEP_DCBZL_DCBZLEP_DCBTST_DCBTSTEP
  { 0, 0, 0, 0, 0 }, // 176 CP_COPY_CP_COPY8
  { 0, 0, 0, 0, 0 }, // 177 CP_PASTE_CP_PASTE8
  { 1, 141, 142, 0, 0 }, // 178 ICBI_ICBIEP
  { 1, 134, 135, 0, 0 }, // 179 ICBT_ICBTLS_LBZ_LBZ8_LBZCIX_LBZX_LBZX8_LBZXTLS_LBZXTLS__LBZXTLS_32_LDBRX_LDCIX_LHBRX_LHBRX8_LHZ_LHZ8_LHZCIX_LHZX_LHZX8_LHZXTLS_LHZXTLS__LHZXTLS_32_LWBRX_LWBRX8_LWZ_LWZ8_LWZCIX_LWZX_LWZX8_LWZXTLS_LWZXTLS__LWZXTLS_32_EnforceIEIO_LSWI
  { 1, 134, 135, 0, 0 }, // 180 LBARX_LBARXL_LHARX_LHARXL_LWARX_LWARXL
  { 0, 0, 0, 0, 0 }, // 181 LD_LDX_LDXTLS_LDXTLS__DARN
  { 0, 0, 0, 0, 0 }, // 182 LDARX_LDARXL
  { 0, 0, 0, 0, 0 }, // 183 CP_ABORT
  { 1, 142, 143, 0, 0 }, // 184 ISYNC
  { 0, 0, 0, 0, 0 }, // 185 MSGSYNC
  { 1, 134, 135, 0, 0 }, // 186 TLBSYNC
  { 1, 129, 130, 0, 0 }, // 187 SYNC
  { 1, 144, 145, 0, 0 }, // 188 LMW
  { 1, 143, 144, 0, 0 }, // 189 LFIWZX_LFDX_LFD
  { 0, 0, 0, 0, 0 }, // 190 SLBIA
  { 0, 0, 0, 0, 0 }, // 191 SLBIE
  { 0, 0, 0, 0, 0 }, // 192 SLBMFEE
  { 0, 0, 0, 0, 0 }, // 193 SLBMFEV
  { 0, 0, 0, 0, 0 }, // 194 SLBMTE
  { 0, 0, 0, 0, 0 }, // 195 TLBIEL
  { 1, 134, 135, 0, 0 }, // 196 LHZU_LHZU8_LWZU_LWZU8
  { 1, 134, 135, 0, 0 }, // 197 LHZUX_LHZUX8_LWZUX_LWZUX8
  { 1, 133, 134, 0, 0 }, // 198 TEND
  { 1, 134, 135, 0, 0 }, // 199 STBCX_STHCX_STWCX
  { 1, 134, 135, 0, 0 }, // 200 STDCX
  { 0, 0, 0, 0, 0 }, // 201 LDMX
  { 1, 134, 135, 0, 0 }, // 202 LHA_LHA8_LHAX_LHAX8_LWAX_LWAX_32
  { 0, 0, 0, 0, 0 }, // 203 CP_PASTE8_rec_CP_PASTE_rec
  { 1, 134, 135, 0, 0 }, // 204 LWA_LWA_32
  { 1, 133, 134, 0, 0 }, // 205 TCHECK
  { 1, 143, 144, 0, 0 }, // 206 LFIWAX
  { 1, 143, 144, 0, 0 }, // 207 LXSIWAX
  { 0, 0, 0, 0, 0 }, // 208 LIWAX
  { 1, 143, 144, 0, 0 }, // 209 LFSX_LFS
  { 1, 143, 144, 0, 0 }, // 210 LXSSP_LXSSPX
  { 0, 0, 0, 0, 0 }, // 211 XFLOADf32_DFLOADf32
  { 1, 134, 135, 0, 0 }, // 212 LHAU_LHAU8
  { 1, 134, 135, 0, 0 }, // 213 LHAUX_LHAUX8_LWAUX
  { 1, 143, 144, 0, 0 }, // 214 LXVH8X_LXVDSX_LXVW4X
  { 1, 134, 135, 0, 0 }, // 215 STFD_STFDX_STFIWX_STFS_STFSX_STXSD_STXSDX_STXSIBX_STXSIBXv_STXSIHX_STXSIHXv_STXSIWX_STXSSP_STXSSPX
  { 1, 134, 135, 0, 0 }, // 216 STW_STW8_STDBRX_STHBRX_STWBRX_STB_STB8_STH_STH8_STBX_STBX8_STBXTLS_STBXTLS__STBXTLS_32_STHX_STHX8_STHXTLS_STHXTLS__STHXTLS_32_STWX_STWX8_STWXTLS_STWXTLS__STWXTLS_32
  { 0, 0, 0, 0, 0 }, // 217 DFSTOREf32_DFSTOREf64_XFSTOREf32_XFSTOREf64_STIWX
  { 1, 134, 135, 0, 0 }, // 218 STD_STDX_STDXTLS_STDXTLS_
  { 1, 134, 135, 0, 0 }, // 219 STBCIX_STDCIX_STHCIX_STWCIX_STSWI
  { 0, 0, 0, 0, 0 }, // 220 SLBIEG
  { 1, 144, 145, 0, 0 }, // 221 STMW
  { 0, 0, 0, 0, 0 }, // 222 TLBIE
  { 1, 134, 135, 0, 0 }, // 223 STVEBX_STVEHX_STVEWX_STVX_STVXL
  { 1, 134, 135, 0, 0 }, // 224 STXV_STXVB16X_STXVD2X_STXVH8X_STXVW4X_STXVX
  { 1, 134, 135, 0, 0 }, // 225 STXVL_STXVLL
  { 1, 133, 134, 0, 0 }, // 226 MTCTR_MTCTR8_MTCTR8loop_MTCTRloop_MTLR_MTLR8
  { 1, 130, 131, 0, 0 }, // 227 MFVRSAVE_MFVRSAVEv_MTVRSAVE_MTVRSAVEv
  { 0, 0, 0, 0, 0 }, // 228 MFPMR
  { 0, 0, 0, 0, 0 }, // 229 MTPMR
  { 1, 146, 147, 0, 0 }, // 230 MFTB_MFTB8
  { 1, 145, 146, 0, 0 }, // 231 MFCTR_MFCTR8_MFLR_MFLR8_MFSPR_MFSPR8
  { 1, 141, 142, 0, 0 }, // 232 MFMSR
  { 1, 133, 134, 0, 0 }, // 233 MTMSR
  { 0, 0, 0, 0, 0 }, // 234 MTMSRD
  { 1, 133, 134, 0, 0 }, // 235 MTSPR_MTSPR8
  { 1, 135, 136, 0, 0 }, // 236 DIVW_DIVWO_DIVWU_DIVWUO_MODSW
  { 1, 135, 136, 0, 0 }, // 237 DIVWE_DIVWEO_DIVWEU_DIVWEUO_MODSD_MODUD_MODUW
  { 0, 0, 0, 0, 0 }, // 238 DIVD_DIVDO_DIVDU_DIVDUO
  { 0, 0, 0, 0, 0 }, // 239 DIVDE_DIVDEO_DIVDEU_DIVDEUO
  { 1, 135, 136, 0, 0 }, // 240 DIVWO_rec_DIVWUO_rec_DIVWU_rec_DIVW_rec
  { 0, 0, 0, 0, 0 }, // 241 DIVD_rec_DIVDO_rec_DIVDU_rec_DIVDUO_rec
  { 1, 135, 136, 0, 0 }, // 242 DIVWE_rec_DIVWEO_rec_DIVWEU_rec_DIVWEUO_rec
  { 0, 0, 0, 0, 0 }, // 243 DIVDE_rec_DIVDEO_rec_DIVDEU_rec_DIVDEUO_rec
  { 1, 133, 134, 0, 0 }, // 244 MTCRF_MTCRF8
  { 1, 130, 131, 0, 0 }, // 245 ADDC8O_rec_ADDC8_rec_ADDCO_rec_ADDC_rec_SUBFC8O_rec_SUBFC8_rec_SUBFCO_rec_SUBFC_rec
  { 1, 136, 137, 0, 0 }, // 246 FABSD_rec_FABSS_rec_FNABSD_rec_FNABSS_rec_FCPSGND_rec_FCPSGNS_rec_FNEGD_rec_FNEGS_rec_FMR_rec
  { 1, 133, 134, 0, 0 }, // 247 MCRFS
  { 1, 136, 137, 0, 0 }, // 248 MTFSF_MTFSF_rec_MTFSFI_MTFSFI_rec
  { 1, 136, 137, 0, 0 }, // 249 MTFSFb
  { 0, 0, 0, 0, 0 }, // 250 RLDCL_rec_RLDCR_rec
  { 0, 0, 0, 0, 0 }, // 251 RLDICL_rec_RLDICR_rec_RLDICL_32_rec_RLDIMI_rec
  { 1, 130, 131, 0, 0 }, // 252 RLWIMI8_rec_RLWIMI_rec
  { 1, 130, 131, 0, 0 }, // 253 RLWINM8_rec_RLWINM_rec_RLWNM8_rec_RLWNM_rec_SLW8_rec_SLW_rec_SRW8_rec_SRW_rec
  { 1, 148, 149, 0, 0 }, // 254 SRAWI_rec_SRAW_rec
  { 1, 136, 137, 0, 0 }, // 255 MFFS_MFFSCE_MFFSL_MFFS_rec
  { 1, 133, 134, 0, 0 }, // 256 MFCR_MFCR8
  { 0, 0, 0, 0, 0 }, // 257 EXTSWSLI_32_64_rec_SRADI_rec_EXTSWSLI_rec_RLDIC_rec
  { 0, 0, 0, 0, 0 }, // 258 SRAD_rec_SLD_rec_SRD_rec
  { 1, 137, 138, 0, 0 }, // 259 FDIV
  { 1, 137, 138, 0, 0 }, // 260 FDIV_rec
  { 0, 0, 0, 0, 0 }, // 261 XSSQRTDP
  { 0, 0, 0, 0, 0 }, // 262 FSQRT
  { 0, 0, 0, 0, 0 }, // 263 XVSQRTDP
  { 0, 0, 0, 0, 0 }, // 264 XVSQRTSP
  { 0, 0, 0, 0, 0 }, // 265 FSQRT_rec
  { 0, 0, 0, 0, 0 }, // 266 XSSQRTSP
  { 0, 0, 0, 0, 0 }, // 267 FSQRTS
  { 0, 0, 0, 0, 0 }, // 268 FSQRTS_rec
  { 1, 137, 138, 0, 0 }, // 269 XSDIVDP
  { 1, 140, 141, 0, 0 }, // 270 FDIVS
  { 1, 140, 141, 0, 0 }, // 271 FDIVS_rec
  { 1, 140, 141, 0, 0 }, // 272 XSDIVSP
  { 1, 140, 141, 0, 0 }, // 273 XVDIVSP
  { 1, 137, 138, 0, 0 }, // 274 XVDIVDP
  { 1, 143, 144, 0, 0 }, // 275 LFSU
  { 1, 143, 144, 0, 0 }, // 276 LFSUX
  { 1, 134, 135, 0, 0 }, // 277 STFDU_STFDUX_STFSU_STFSUX
  { 1, 134, 135, 0, 0 }, // 278 STBU_STBU8_STDU_STHU_STHU8_STWU_STWU8
  { 1, 134, 135, 0, 0 }, // 279 STBUX_STBUX8_STDUX_STHUX_STHUX8_STWUX_STWUX8
  { 1, 134, 135, 0, 0 }, // 280 LBZU_LBZU8
  { 1, 134, 135, 0, 0 }, // 281 LBZUX_LBZUX8
  { 0, 0, 0, 0, 0 }, // 282 LDU
  { 0, 0, 0, 0, 0 }, // 283 LDUX
  { 1, 143, 144, 0, 0 }, // 284 LFDU
  { 1, 143, 144, 0, 0 }, // 285 LFDUX
  { 1, 132, 133, 0, 0 }, // 286 VPMSUMB_VPMSUMD_VPMSUMH_VPMSUMW_VCIPHER_VCIPHERLAST_VNCIPHER_VNCIPHERLAST_VSBOX
  { 1, 131, 132, 0, 0 }, // 287 BCCCTR_BCCCTR8_BCCCTRL_BCCCTRL8_BCCL_BCCLA_BCCLR_BCCLRL_BCCTR_BCCTR8_BCCTR8n_BCCTRL_BCCTRL8_BCCTRL8n_BCCTRLn_BCCTRn_BDNZ_BDNZ8_BDNZA_BDNZAm_BDNZAp_BDNZm_BDNZp_BDZ_BDZ8_BDZA_BDZAm_BDZAp_BDZm_BDZp_BDNZL_BDNZLA_BDNZLAm_BDNZLAp_BDNZLR_BDNZLR8_BDNZLRL_BDNZLRLm_BDNZLRLp_BDNZLRm_BDNZLRp_BDNZLm_BDNZLp_BDZL_BDZLA_BDZLAm_BDZLAp_BDZLR_BDZLR8_BDZLRL_BDZLRLm_BDZLRLp_BDZLRm_BDZLRp_BDZLm_BDZLp_BL_BL_NOP_BL_TLS_BL8_BL8_NOP_BL8_NOP_TLS_BL8_TLS_BL8_TLS__BLA_BLA8_BLA8_NOP_BLR_BLR8_BLRL_TAILB_TAILB8_TAILBA_TAILBA8_TAILBCTR_TAILBCTR8_gBC_gBCA_gBCAat_gBCCTR_gBCCTRL_gBCL_gBCLA_gBCLAat_gBCLR_gBCLRL_gBCLat_gBCat_BCLR_BCLRL_BCLRLn_BCLRn_BCTR_BCTR8_BCTRL_BCTRL8_B_BA_BC_BCC_BCCA_BCL_BCLalways_BCLn_BCTRL8_LDinto_toc_BCTRL_LWZinto_toc_BCn_CTRL_DEP
  { 1, 131, 132, 0, 0 }, // 288 ADDPCIS
  { 1, 134, 135, 0, 0 }, // 289 LDAT_LWAT
  { 1, 134, 135, 0, 0 }, // 290 STDAT_STWAT
  { 1, 130, 131, 0, 0 }, // 291 BRINC
  { 1, 138, 139, 0, 0 }, // 292 EVABS_EVEQV_EVNAND_EVNEG_EVADDIW_EVADDW_EVAND_EVANDC_EVCMPEQ_EVCMPGTS_EVCMPGTU_EVCMPLTS_EVCMPLTU_EVCNTLSW_EVCNTLZW_EVEXTSB_EVEXTSH_EVMERGEHI_EVMERGEHILO_EVMERGELO_EVMERGELOHI_EVNOR_EVOR_EVORC_EVXOR_EVRLW_EVRLWI_EVRNDW_EVSLW_EVSLWI_EVSPLATFI_EVSPLATI_EVSRWIS_EVSRWIU_EVSRWS_EVSRWU_EVSUBFW_EVSUBIFW
  { 1, 139, 140, 0, 0 }, // 293 EVMRA_EVADDSMIAAW_EVADDSSIAAW_EVADDUMIAAW_EVADDUSIAAW_EVDIVWS_EVDIVWU_EVMHEGSMFAA_EVMHEGSMFAN_EVMHEGSMIAA_EVMHEGSMIAN_EVMHEGUMIAA_EVMHEGUMIAN_EVMHESMF_EVMHESMFA_EVMHESMFAAW_EVMHESMFANW_EVMHESMI_EVMHESMIA_EVMHESMIAAW_EVMHESMIANW_EVMHESSF_EVMHESSFA_EVMHESSFAAW_EVMHESSFANW_EVMHESSIAAW_EVMHESSIANW_EVMHEUMI_EVMHEUMIA_EVMHEUMIAAW_EVMHEUMIANW_EVMHEUSIAAW_EVMHEUSIANW_EVMHOGSMFAA_EVMHOGSMFAN_EVMHOGSMIAA_EVMHOGSMIAN_EVMHOGUMIAA_EVMHOGUMIAN_EVMHOSMF_EVMHOSMFA_EVMHOSMFAAW_EVMHOSMFANW_EVMHOSMI_EVMHOSMIA_EVMHOSMIAAW_EVMHOSMIANW_EVMHOSSF_EVMHOSSFA_EVMHOSSFAAW_EVMHOSSFANW_EVMHOSSIAAW_EVMHOSSIANW_EVMHOUMI_EVMHOUMIA_EVMHOUMIAAW_EVMHOUMIANW_EVMHOUSIAAW_EVMHOUSIANW_EVMWHSMF_EVMWHSMFA_EVMWHSMI_EVMWHSMIA_EVMWHSSF_EVMWHSSFA_EVMWHUMI_EVMWHUMIA_EVMWLSMIAAW_EVMWLSMIANW_EVMWLSSIAAW_EVMWLSSIANW_EVMWLUMI_EVMWLUMIA_EVMWLUMIAAW_EVMWLUMIANW_EVMWLUSIAAW_EVMWLUSIANW_EVMWSMF_EVMWSMFA_EVMWSMFAA_EVMWSMFAN_EVMWSMI_EVMWSMIA_EVMWSMIAA_EVMWSMIAN_EVMWSSF_EVMWSSFA_EVMWSSFAA_EVMWSSFAN_EVMWUMI_EVMWUMIA_EVMWUMIAA_EVMWUMIAN_EVSUBFSMIAAW_EVSUBFSSIAAW_EVSUBFUMIAAW_EVSUBFUSIAAW
  { 1, 134, 135, 0, 0 }, // 294 EVLDD_EVLDDX_EVLDH_EVLDHX_EVLDW_EVLDWX_EVLHHESPLAT_EVLHHESPLATX_EVLHHOSSPLAT_EVLHHOSSPLATX_EVLHHOUSPLAT_EVLHHOUSPLATX_EVLWHE_EVLWHEX_EVLWHOS_EVLWHOSX_EVLWHOU_EVLWHOUX_EVLWHSPLAT_EVLWHSPLATX_EVLWWSPLAT_EVLWWSPLATX
  { 1, 134, 135, 0, 0 }, // 295 EVSTDD_EVSTDDX_EVSTDH_EVSTDHX_EVSTDW_EVSTDWX_EVSTWHE_EVSTWHEX_EVSTWHO_EVSTWHOX_EVSTWWE_EVSTWWEX_EVSTWWO_EVSTWWOX
  { 1, 131, 132, 0, 0 }, // 296 HRFID_ATTN_CLRBHRB_MFBHRBE_NAP_RFCI_RFDI_RFMCI_SC
  { 1, 130, 131, 0, 0 }, // 297 RFI
  { 0, 0, 0, 0, 0 }, // 298 RFID
  { 1, 134, 135, 0, 0 }, // 299 DSS_DSSALL_DST_DST64_DSTST_DSTST64_DSTSTT_DSTSTT64_DSTT_DSTT64_ICBLQ_LBEPX_LHEPX_LWEPX_TLBIVAX_TLBLD_TLBLI_TLBRE_TLBRE2_TLBSX_TLBSX2_TLBSX2D_TLBWE_TLBWE2_MBAR_TRAP_DCCCI_ICCCI
  { 1, 134, 135, 0, 0 }, // 300 ICBLC_STBEPX_STHEPX_STWEPX
  { 1, 143, 144, 0, 0 }, // 301 LFDEPX
  { 1, 134, 135, 0, 0 }, // 302 STFDEPX
  { 1, 145, 146, 0, 0 }, // 303 MFSR_MFSRIN
  { 1, 133, 134, 0, 0 }, // 304 MTSR_MTSRIN
  { 1, 145, 146, 0, 0 }, // 305 MFDCR
  { 1, 133, 134, 0, 0 }, // 306 MTDCR
  { 1, 130, 131, 0, 0 }, // 307 NOP_GT_PWR6_NOP_GT_PWR7
  { 0, 0, 0, 0, 0 }, // 308 TLBIA
  { 1, 133, 134, 0, 0 }, // 309 WRTEE_WRTEEI
  { 1, 129, 130, 0, 0 }, // 310 MSYNC
  { 0, 0, 0, 0, 0 }, // 311 SLBSYNC
  { 0, 0, 0, 0, 0 }, // 312 SLBFEE_rec
  { 0, 0, 0, 0, 0 }, // 313 STOP
  { 1, 134, 135, 0, 0 }, // 314 DCBA_DCBI
  { 0, uint16_t(~0U), uint16_t(~0U), uint16_t(~0U), uint16_t(~0U) }// end marker
};

static const llvm::InstrItinerary G5Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 150, 151, 0, 0 }, // 1 IIC_LdStSync
  { 1, 151, 152, 0, 0 }, // 2 IIC_IntSimple
  { 1, 151, 152, 0, 0 }, // 3 IIC_IntGeneral
  { 1, 152, 153, 0, 0 }, // 4 IIC_BrB
  { 1, 153, 154, 0, 0 }, // 5 IIC_VecFP
  { 1, 154, 155, 0, 0 }, // 6 IIC_IntCompare
  { 0, 0, 0, 0, 0 }, // 7 IIC_SprABORT
  { 0, 0, 0, 0, 0 }, // 8 IIC_LdStCOPY
  { 0, 0, 0, 0, 0 }, // 9 IIC_LdStPASTE
  { 1, 155, 156, 0, 0 }, // 10 IIC_BrCR
  { 1, 156, 157, 0, 0 }, // 11 IIC_LdStLD
  { 1, 156, 157, 0, 0 }, // 12 IIC_LdStDCBF
  { 1, 156, 157, 0, 0 }, // 13 IIC_LdStLoad
  { 1, 157, 158, 0, 0 }, // 14 IIC_IntDivD
  { 1, 158, 159, 0, 0 }, // 15 IIC_IntDivW
  { 0, 0, 0, 0, 0 }, // 16 IIC_FPDGeneral
  { 1, 159, 160, 0, 0 }, // 17 IIC_FPAddSub
  { 1, 160, 161, 0, 0 }, // 18 IIC_FPDivD
  { 0, 0, 0, 0, 0 }, // 19 IIC_FPSGeneral
  { 1, 161, 162, 0, 0 }, // 20 IIC_FPCompare
  { 1, 159, 160, 0, 0 }, // 21 IIC_FPGeneral
  { 1, 162, 163, 0, 0 }, // 22 IIC_VecGeneral
  { 1, 163, 164, 0, 0 }, // 23 IIC_VecComplex
  { 1, 156, 157, 0, 0 }, // 24 IIC_LdStStore
  { 1, 151, 152, 0, 0 }, // 25 IIC_IntRotateDI
  { 1, 160, 161, 0, 0 }, // 26 IIC_FPDivS
  { 1, 159, 160, 0, 0 }, // 27 IIC_FPFused
  { 1, 164, 165, 0, 0 }, // 28 IIC_FPSqrtD
  { 1, 164, 165, 0, 0 }, // 29 IIC_FPSqrtS
  { 1, 165, 166, 0, 0 }, // 30 IIC_LdStICBI
  { 0, 0, 0, 0, 0 }, // 31 IIC_IntISEL
  { 1, 165, 166, 0, 0 }, // 32 IIC_SprISYNC
  { 1, 166, 167, 0, 0 }, // 33 IIC_LdStLWARX
  { 1, 156, 157, 0, 0 }, // 34 IIC_LdStLoadUpd
  { 1, 156, 157, 0, 0 }, // 35 IIC_LdStLoadUpdX
  { 1, 166, 167, 0, 0 }, // 36 IIC_LdStLDARX
  { 1, 156, 157, 0, 0 }, // 37 IIC_LdStLDU
  { 1, 156, 157, 0, 0 }, // 38 IIC_LdStLDUX
  { 1, 156, 157, 0, 0 }, // 39 IIC_LdStLFD
  { 1, 167, 168, 0, 0 }, // 40 IIC_LdStLFDU
  { 1, 167, 168, 0, 0 }, // 41 IIC_LdStLFDUX
  { 1, 167, 168, 0, 0 }, // 42 IIC_LdStLHA
  { 1, 167, 168, 0, 0 }, // 43 IIC_LdStLHAU
  { 1, 167, 168, 0, 0 }, // 44 IIC_LdStLHAUX
  { 1, 168, 169, 0, 0 }, // 45 IIC_LdStLMW
  { 1, 167, 168, 0, 0 }, // 46 IIC_LdStLWA
  { 1, 169, 170, 0, 0 }, // 47 IIC_IntMulHD
  { 1, 170, 171, 0, 0 }, // 48 IIC_BrMCR
  { 1, 171, 172, 0, 0 }, // 49 IIC_BrMCRX
  { 1, 172, 173, 0, 0 }, // 50 IIC_SprMFCR
  { 1, 173, 174, 0, 0 }, // 51 IIC_SprMFSPR
  { 1, 174, 175, 0, 0 }, // 52 IIC_IntMFFS
  { 1, 173, 174, 0, 0 }, // 53 IIC_SprMFMSR
  { 1, 172, 173, 0, 0 }, // 54 IIC_SprMFCRF
  { 0, 0, 0, 0, 0 }, // 55 IIC_SprMFPMR
  { 1, 156, 157, 0, 0 }, // 56 IIC_SprMFSR
  { 1, 175, 176, 0, 0 }, // 57 IIC_SprMFTB
  { 0, 0, 0, 0, 0 }, // 58 IIC_SprMSGSYNC
  { 1, 176, 177, 0, 0 }, // 59 IIC_SprMTSPR
  { 1, 159, 160, 0, 0 }, // 60 IIC_IntMTFSB0
  { 1, 156, 157, 0, 0 }, // 61 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 62 IIC_SprMTMSRD
  { 0, 0, 0, 0, 0 }, // 63 IIC_SprMTPMR
  { 1, 156, 157, 0, 0 }, // 64 IIC_SprMTSR
  { 1, 177, 178, 0, 0 }, // 65 IIC_IntMulHW
  { 1, 177, 178, 0, 0 }, // 66 IIC_IntMulHWU
  { 1, 178, 179, 0, 0 }, // 67 IIC_IntMulLI
  { 1, 179, 180, 0, 0 }, // 68 IIC_VecPerm
  { 1, 180, 181, 0, 0 }, // 69 IIC_LdStSTFD
  { 1, 180, 181, 0, 0 }, // 70 IIC_LdStSTFDU
  { 0, 0, 0, 0, 0 }, // 71 IIC_SprRFI
  { 1, 181, 182, 0, 0 }, // 72 IIC_IntRFID
  { 1, 151, 152, 0, 0 }, // 73 IIC_IntRotateD
  { 1, 178, 179, 0, 0 }, // 74 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 75 IIC_SprSLBFEE
  { 0, 0, 0, 0, 0 }, // 76 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 77 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprSLBIEG
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprSLBMFEV
  { 0, 0, 0, 0, 0 }, // 81 IIC_SprSLBMTE
  { 0, 0, 0, 0, 0 }, // 82 IIC_SprSLBSYNC
  { 1, 151, 152, 0, 0 }, // 83 IIC_IntShift
  { 1, 166, 167, 0, 0 }, // 84 IIC_LdStSTWCX
  { 1, 156, 157, 0, 0 }, // 85 IIC_LdStSTU
  { 1, 156, 157, 0, 0 }, // 86 IIC_LdStSTUX
  { 1, 156, 157, 0, 0 }, // 87 IIC_LdStSTD
  { 1, 166, 167, 0, 0 }, // 88 IIC_LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 89 IIC_SprSTOP
  { 1, 182, 183, 0, 0 }, // 90 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 91 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 92 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 93 IIC_SprTLBIEL
  { 1, 156, 157, 0, 0 }, // 94 IIC_SprTLBSYNC
  { 1, 182, 183, 0, 0 }, // 95 IIC_IntTrapW
  { 1, 183, 184, 0, 0 }, // 96 IIC_VecFPCompare
  { 1, 162, 163, 0, 0 }, // 97 VADDUBM_VADDUDM_VADDUHM_VADDUWM_VEXTSB2D_VEXTSB2Ds_VEXTSB2W_VEXTSB2Ws_VEXTSH2D_VEXTSH2Ds_VEXTSH2W_VEXTSH2Ws_VEXTSW2D_VEXTSW2Ds_VSLD_VSRD_VSUBUBM_VSUBUDM_VSUBUHM_VSUBUWM_VPOPCNTB_VPOPCNTH_VSRAD_MTVSRDD_VEQV_VNAND_VNEGD_VNEGW_VORC_XXLAND_XXLANDC_XXLEQV_XXLEQVOnes_XXLNAND_XXLNOR_XXLOR_XXLORf_XXLORC_XXLXOR_XXLXORdpz_XXLXORspz_XXLXORz
  { 1, 153, 154, 0, 0 }, // 98 VAND_VANDC_V_SET0_V_SET0B_V_SET0H_VSLB_VSLH_VSLW_VSRB_VSRH_VSRW_VRLB_VRLD_VRLH_VRLW_VSRAB_VSRAH_VSRAW_XVABSDP_XVABSSP_XVNABSDP_XVNABSSP_XVCPSGNDP_XVCPSGNSP_XVIEXPDP_XVIEXPSP_XVXEXPDP_XVXEXPSP_VRLDMI_VRLDNM_VRLWMI_VRLWNM_VMRGEW_VMRGOW_VNOR_VOR_VSEL_VXOR_XVNEGDP_XVNEGSP_XSABSQP_XSCPSGNQP_XSIEXPQP_XSNABSQP_XSNEGQP_XSXEXPQP
  { 1, 179, 180, 0, 0 }, // 99 XXSEL
  { 1, 176, 177, 0, 0 }, // 100 TABORTDC_TABORTDCI_TABORTWC_TABORTWCI
  { 1, 159, 160, 0, 0 }, // 101 MTFSB0_MTFSB1
  { 1, 174, 175, 0, 0 }, // 102 MFFSCDRN_MFFSCDRNI_MFFSCRN_MFFSCRNI
  { 1, 154, 155, 0, 0 }, // 103 CMPRB_CMPRB8_CMPEQB
  { 1, 182, 183, 0, 0 }, // 104 TD_TDI
  { 1, 182, 183, 0, 0 }, // 105 TW_TWI
  { 1, 161, 162, 0, 0 }, // 106 FCMPUD_FCMPUS_FTDIV_FTSQRT
  { 1, 153, 154, 0, 0 }, // 107 XSTSTDCDP_XSTSTDCSP
  { 1, 153, 154, 0, 0 }, // 108 XSMAXCDP_XSMAXDP_XSMAXJDP_XSMINCDP_XSMINDP_XSMINJDP_XSXSIGDP_XSCVSPDPN
  { 1, 161, 162, 0, 0 }, // 109 XSCMPEQDP_XSCMPEXPDP_XSCMPGEDP_XSCMPGTDP_XSCMPODP_XSCMPUDP_XSTDIVDP_XSTSQRTDP
  { 1, 151, 152, 0, 0 }, // 110 CNTLZD_CNTLZD_rec_CNTLZW_CNTLZW8_CNTLZW8_rec_CNTLZW_rec_CNTTZD_CNTTZD_rec_CNTTZW_CNTTZW8_CNTTZW8_rec_CNTTZW_rec_POPCNTD_POPCNTW_CMPB_CMPB8_SETB_SETB8_BPERMD
  { 1, 151, 152, 0, 0 }, // 111 SLD_SRD_SRAD
  { 1, 151, 152, 0, 0 }, // 112 SRADI_EXTSWSLI_32_64_EXTSWSLI_SRADI_32_RLDIC
  { 1, 162, 163, 0, 0 }, // 113 MFVRD_MFVSRD_MTVRD_MTVSRD_MTVRWA_MTVRWZ_MTVSRWA_MTVSRWZ_MFVSRWZ_MFVRWZ
  { 1, 154, 155, 0, 0 }, // 114 CMPLW_CMPLWI_CMPW_CMPWI_CMPD_CMPDI_CMPLD_CMPLDI
  { 1, 151, 152, 0, 0 }, // 115 SUBFC_SUBFC8_SUBFC8O_SUBFCO_SUBFIC_SUBFIC8_ANDI8_rec_ANDIS8_rec_ANDIS_rec_ANDI_rec_ADDC_ADDC8_ADDC8O_ADDCO_ADDIC_ADDIC8_ADDIC_rec_ADDE_ADDE8_ADDE8O_ADDE8O_rec_ADDE8_rec_ADDEO_ADDEO_rec_ADDE_rec_ADDME_ADDME8_ADDME8O_ADDME8O_rec_ADDME8_rec_ADDMEO_ADDMEO_rec_ADDME_rec_ADDZE_ADDZE8_ADDZE8O_ADDZE8O_rec_ADDZE8_rec_ADDZEO_ADDZEO_rec_ADDZE_rec_SUBF_SUBF8_SUBF8O_SUBF8O_rec_SUBF8_rec_SUBFE_SUBFE8_SUBFE8O_SUBFE8O_rec_SUBFE8_rec_SUBFEO_SUBFEO_rec_SUBFE_rec_SUBFME_SUBFME8_SUBFME8O_SUBFME8O_rec_SUBFME8_rec_SUBFMEO_SUBFMEO_rec_SUBFME_rec_SUBFO_SUBFO_rec_SUBFZE_SUBFZE8_SUBFZE8O_SUBFZE8O_rec_SUBFZE8_rec_SUBFZEO_SUBFZEO_rec_SUBFZE_rec_SUBF_rec_POPCNTB_LA
  { 1, 151, 152, 0, 0 }, // 116 ADD4_ADD4O_ADD4O_rec_ADD4_rec_ADD8_ADD8O_ADD8O_rec_ADD8_rec_NEG_NEG8_NEG8O_NEG8O_rec_NEG8_rec_NEGO_NEGO_rec_NEG_rec_ADDI_ADDI8_ADDIS_ADDIS8_LI_LI8_LIS_LIS8_OR_OR8_OR8_rec_ORI_ORI8_ORIS_ORIS8_OR_rec_XOR_XOR8_XOR8_rec_XORI_XORI8_XORIS_XORIS8_XOR_rec_NAND_NAND8_NAND8_rec_NAND_rec_AND_AND8_AND8_rec_ANDC_ANDC8_ANDC8_rec_ANDC_rec_AND_rec_NOR_NOR8_NOR8_rec_NOR_rec_ORC_ORC8_ORC8_rec_ORC_rec_EQV_EQV8_EQV8_rec_EQV_rec_EXTSB_EXTSB8_EXTSB8_32_64_EXTSB8_rec_EXTSB_rec_EXTSH_EXTSH8_EXTSH8_32_64_EXTSH8_rec_EXTSH_rec_EXTSW_EXTSW_32_EXTSW_32_64_EXTSW_32_64_rec_EXTSW_rec_ADD4TLS_ADD8TLS_ADD8TLS__NOP
  { 0, 0, 0, 0, 0 }, // 117 ADDIStocHA_ADDIStocHA8_ADDItocL_COPY
  { 1, 170, 171, 0, 0 }, // 118 MCRF
  { 1, 171, 172, 0, 0 }, // 119 MCRXRX
  { 1, 153, 154, 0, 0 }, // 120 XSNABSDP_XSXEXPDP_XSABSDP_XSNEGDP_XSCPSGNDP
  { 1, 152, 153, 0, 0 }, // 121 RFEBB
  { 1, 176, 177, 0, 0 }, // 122 TBEGIN_TRECHKPT
  { 1, 156, 157, 0, 0 }, // 123 WAIT
  { 1, 151, 152, 0, 0 }, // 124 RLDCL_RLDCR
  { 1, 178, 179, 0, 0 }, // 125 RLWIMI_RLWIMI8
  { 1, 151, 152, 0, 0 }, // 126 RLDICL_RLDICL_32_RLDICL_32_64_RLDICR_RLDICR_32_RLDIMI
  { 1, 172, 173, 0, 0 }, // 127 MFOCRF_MFOCRF8
  { 1, 171, 172, 0, 0 }, // 128 MTOCRF_MTOCRF8
  { 1, 155, 156, 0, 0 }, // 129 CR6SET_CR6UNSET_CRSET_CRUNSET_CRAND_CRANDC_CRNAND_CRNOR_CROR_CRORC_CREQV_CRXOR
  { 1, 151, 152, 0, 0 }, // 130 SLW_SLW8_SRW_SRW8_RLWINM_RLWINM8_RLWNM_RLWNM8
  { 1, 159, 160, 0, 0 }, // 131 FABSD_FABSS_FNABSD_FNABSS_FNEGD_FNEGS_FCPSGND_FCPSGNS_FMR
  { 1, 151, 152, 0, 0 }, // 132 SRAW_SRAWI
  { 0, 0, 0, 0, 0 }, // 133 ISEL_ISEL8
  { 1, 153, 154, 0, 0 }, // 134 XSIEXPDP
  { 1, 176, 177, 0, 0 }, // 135 TRECLAIM_TSR_TABORT
  { 1, 156, 157, 0, 0 }, // 136 MFVSCR
  { 1, 156, 157, 0, 0 }, // 137 MTVSCR
  { 1, 183, 184, 0, 0 }, // 138 VCMPNEZB_VCMPNEZH_VCMPNEZW_VCMPEQUB_VCMPEQUD_VCMPEQUH_VCMPEQUW_VCMPNEB_VCMPNEH_VCMPNEW_VCMPEQFP_VCMPEQFP_rec_VCMPGEFP_VCMPGEFP_rec_VCMPGTFP_VCMPGTFP_rec_VCMPBFP_VCMPBFP_rec_VCMPGTSB_VCMPGTSB_rec_VCMPGTSD_VCMPGTSD_rec_VCMPGTSH_VCMPGTSH_rec_VCMPGTSW_VCMPGTSW_rec_VCMPGTUB_VCMPGTUB_rec_VCMPGTUD_VCMPGTUD_rec_VCMPGTUH_VCMPGTUH_rec_VCMPGTUW_VCMPGTUW_rec_VCMPNEB_rec_VCMPNEH_rec_VCMPNEW_rec_VCMPNEZB_rec_VCMPNEZH_rec_VCMPNEZW_rec_VCMPEQUB_rec_VCMPEQUD_rec_VCMPEQUH_rec_VCMPEQUW_rec_XVCMPEQDP_XVCMPEQDP_rec_XVCMPEQSP_XVCMPEQSP_rec_XVCMPGEDP_XVCMPGEDP_rec_XVCMPGESP_XVCMPGESP_rec_XVCMPGTDP_XVCMPGTDP_rec_XVCMPGTSP_XVCMPGTSP_rec
  { 1, 162, 163, 0, 0 }, // 139 VABSDUB_VABSDUH_VABSDUW_VCLZB_VCLZD_VCLZH_VCLZW_VCTZB_VCTZD_VCTZH_VCTZW_VPOPCNTW_VPOPCNTD_VPRTYBD_VPRTYBW
  { 1, 153, 154, 0, 0 }, // 140 VADDUBS_VADDUHS_VADDUWS_VAVGSB_VAVGSH_VAVGSW_VAVGUB_VAVGUH_VAVGUW_VADDSBS_VADDSHS_VADDSWS_VMAXFP_VMINFP_VMAXSB_VMAXSD_VMAXSH_VMAXSW_VMAXUB_VMAXUD_VMAXUH_VMAXUW_VMINSB_VMINSD_VMINSH_VMINSW_VMINUB_VMINUD_VMINUH_VMINUW_VBPERMD_VADDCUW_VSHASIGMAD_VSHASIGMAW_VSUBSBS_VSUBSHS_VSUBSWS_VSUBUBS_VSUBUHS_VSUBUWS_VSUBCUW_XVMAXDP_XVMAXSP_XVMINDP_XVMINSP_XVTSTDCDP_XVTSTDCSP_XVXSIGDP_XVXSIGSP
  { 1, 161, 162, 0, 0 }, // 141 XVTDIVDP_XVTDIVSP_XVTSQRTDP_XVTSQRTSP
  { 1, 153, 154, 0, 0 }, // 142 VADDFP_VCTSXS_VCTSXS_0_VCTUXS_VCTUXS_0_VEXPTEFP_VLOGEFP_VMADDFP_VMHADDSHS_VNMSUBFP_VREFP_VRFIM_VRFIN_VRFIP_VRFIZ_VRSQRTEFP_XVADDDP_XVADDSP_XVCVDPSP_XVCVDPSXDS_XVCVDPSXWS_XVCVDPUXDS_XVCVDPUXWS_XVCVHPSP_XVCVSPDP_XVCVSPHP_XVCVSPSXDS_XVCVSPSXWS_XVCVSPUXDS_XVCVSPUXWS_XVCVSXDDP_XVCVSXDSP_XVCVSXWDP_XVCVSXWSP_XVCVUXDDP_XVCVUXDSP_XVCVUXWDP_XVCVUXWSP_XVMADDADP_XVMADDASP_XVMADDMDP_XVMADDMSP_XVMSUBADP_XVMSUBASP_XVMSUBMDP_XVMSUBMSP_XVMULDP_XVMULSP_XVNMADDADP_XVNMADDASP_XVNMADDMDP_XVNMADDMSP_XVNMSUBADP_XVNMSUBASP_XVNMSUBMDP_XVNMSUBMSP_XVRDPI_XVRDPIC_XVRDPIM_XVRDPIP_XVRDPIZ_XVREDP_XVRESP_XVRSPI_XVRSPIC_XVRSPIM_XVRSPIP_XVRSPIZ_XVRSQRTEDP_XVRSQRTESP_XVSUBDP_XVSUBSP_VCFSX_VCFSX_0_VCFUX_VCFUX_0_VMHRADDSHS_VMLADDUHM_VMSUMMBM_VMSUMSHM_VMSUMSHS_VMSUMUBM_VMSUMUHM_VMSUMUDM_VMSUMUHS_VMULESB_VMULESH_VMULESW_VMULEUB_VMULEUH_VMULEUW_VMULOSB_VMULOSH_VMULOSW_VMULOUB_VMULOUH_VMULOUW_VSUM2SWS_VSUM4SBS_VSUM4SHS_VSUM4UBS_VSUMSWS
  { 1, 162, 163, 0, 0 }, // 143 VSUBFP_VMULUWM
  { 1, 169, 170, 0, 0 }, // 144 MADDHD_MADDHDU_MADDLD_MADDLD8_MULLD_MULLDO
  { 1, 177, 178, 0, 0 }, // 145 MULHD_MULHW_MULLW_MULLWO
  { 1, 177, 178, 0, 0 }, // 146 MULHDU_MULHWU
  { 1, 178, 179, 0, 0 }, // 147 MULLI_MULLI8
  { 1, 159, 160, 0, 0 }, // 148 FRSP_FRIMD_FRIMS_FRIND_FRINS_FRIPD_FRIPS_FRIZD_FRIZS_FRE_FRES_FADDS_FMSUBS_FMADDS_FSUBS_FCFID_FCFIDS_FCFIDU_FCFIDUS_FCTID_FCTIDU_FCTIDUZ_FCTIDZ_FCTIW_FCTIWU_FCTIWUZ_FCTIWZ_FRSQRTE_FRSQRTES_FNMADDS_FNMSUBS_FSELD_FSELS_FMULS
  { 1, 159, 160, 0, 0 }, // 149 FADD_FSUB
  { 1, 159, 160, 0, 0 }, // 150 FMSUB_FMADD_FNMADD_FNMSUB_FMUL
  { 1, 153, 154, 0, 0 }, // 151 XSMADDADP_XSMADDASP_XSMADDMDP_XSMADDMSP_XSMSUBADP_XSMSUBASP_XSMSUBMDP_XSMSUBMSP_XSMULDP_XSMULSP_XSNMADDADP_XSNMADDASP_XSNMADDMDP_XSNMADDMSP_XSNMSUBADP_XSNMSUBASP_XSNMSUBMDP_XSNMSUBMSP
  { 1, 159, 160, 0, 0 }, // 152 FSELD_rec_FSELS_rec
  { 1, 177, 178, 0, 0 }, // 153 MULHDU_rec_MULHWU_rec
  { 1, 177, 178, 0, 0 }, // 154 MULHD_rec_MULHW_rec_MULLWO_rec_MULLW_rec
  { 1, 169, 170, 0, 0 }, // 155 MULLDO_rec_MULLD_rec
  { 1, 159, 160, 0, 0 }, // 156 FRIMD_rec_FRIMS_rec_FRIND_rec_FRINS_rec_FRIPD_rec_FRIPS_rec_FRIZD_rec_FRIZS_rec_FRES_rec_FRE_rec_FADDS_rec_FSUBS_rec_FMSUBS_rec_FNMSUBS_rec_FMADDS_rec_FNMADDS_rec_FCFIDS_rec_FCFIDUS_rec_FCFIDU_rec_FCFID_rec_FCTIDUZ_rec_FCTIDU_rec_FCTIDZ_rec_FCTID_rec_FCTIWUZ_rec_FCTIWU_rec_FCTIWZ_rec_FCTIW_rec_FMULS_rec_FRSQRTES_rec_FRSQRTE_rec_FRSP_rec
  { 1, 159, 160, 0, 0 }, // 157 FADD_rec_FSUB_rec
  { 1, 159, 160, 0, 0 }, // 158 FMSUB_rec_FNMSUB_rec_FMADD_rec_FNMADD_rec_FMUL_rec
  { 1, 153, 154, 0, 0 }, // 159 XSADDDP_XSADDSP_XSCVDPHP_XSCVDPSP_XSCVDPSXDS_XSCVDPSXDSs_XSCVDPSXWS_XSCVDPUXDS_XSCVDPUXDSs_XSCVDPUXWS_XSCVDPSXWSs_XSCVDPUXWSs_XSCVHPDP_XSCVSPDP_XSCVSXDDP_XSCVSXDSP_XSCVUXDDP_XSCVUXDSP_XSRDPI_XSRDPIC_XSRDPIM_XSRDPIP_XSRDPIZ_XSREDP_XSRESP_XSRSQRTEDP_XSRSQRTESP_XSSUBDP_XSSUBSP_XSCVDPSPN_XSRSP
  { 1, 156, 157, 0, 0 }, // 160 LVSL_LVSR
  { 1, 179, 180, 0, 0 }, // 161 VSPLTISB_VSPLTISH_VSPLTISW_VSPLTB_VSPLTBs_VSPLTH_VSPLTHs_VSPLTW_XXMRGHW_XXMRGLW_XXPERM_XXPERMR_XXSLDWI_XXSLDWIs_XXSPLTIB_XXSPLTW_XXSPLTWs_XXPERMDI_XXPERMDIs
  { 1, 153, 154, 0, 0 }, // 162 V_SETALLONES_V_SETALLONESB_V_SETALLONESH_VBPERMQ_VGBBD_VMRGHB_VMRGHH_VMRGHW_VMRGLB_VMRGLH_VMRGLW_VPERM_VPERMR_VPERMXOR_VPKPX_VPKSDSS_VPKSDUS_VPKSHSS_VPKSHUS_VPKSWSS_VPKSWUS_VPKUDUM_VPKUDUS_VPKUHUM_VPKUHUS_VPKUWUM_VPKUWUS_VSL_VSLDOI_VSLO_VSLV_VSR_VSRO_VSRV_VUPKHPX_VUPKHSB_VUPKHSH_VUPKHSW_VUPKLPX_VUPKLSB_VUPKLSH_VUPKLSW_XXBRD_XXBRH_XXBRQ_XXBRW_XXEXTRACTUW_XXINSERTW_VADDCUQ_VADDECUQ_VADDEUQM_VMUL10CUQ_VMUL10ECUQ_VMUL10EUQ_VMUL10UQ_VSUBCUQ_VSUBECUQ_VSUBEUQM_XSTSTDCQP_XSXSIGQP_BCDCFN_rec_BCDCFZ_rec_BCDCPSGN_rec_BCDCTN_rec_BCDCTZ_rec_BCDSETSGN_rec_BCDS_rec_BCDTRUNC_rec_BCDUS_rec_BCDUTRUNC_rec
  { 1, 162, 163, 0, 0 }, // 163 VEXTRACTUB_VEXTRACTUH_VEXTRACTUW_VINSERTB_VINSERTD_VINSERTH_VINSERTW_MFVSRLD_MTVSRWS_VCLZLSBB_VCTZLSBB_VEXTRACTD_VEXTUBLX_VEXTUBRX_VEXTUHLX_VEXTUHRX_VEXTUWLX_VEXTUWRX_VPRTYBQ_VADDUQM_VSUBUQM
  { 1, 161, 162, 0, 0 }, // 164 XSCMPEXPQP_XSCMPOQP_XSCMPUQP
  { 1, 153, 154, 0, 0 }, // 165 BCDSR_rec_XSADDQP_XSADDQPO_XSCVDPQP_XSCVQPDP_XSCVQPDPO_XSCVQPSDZ_XSCVQPSWZ_XSCVQPUDZ_XSCVQPUWZ_XSCVSDQP_XSCVUDQP_XSRQPI_XSRQPIX_XSRQPXP_XSSUBQP_XSSUBQPO
  { 1, 153, 154, 0, 0 }, // 166 BCDCTSQ_rec
  { 1, 153, 154, 0, 0 }, // 167 XSMADDQP_XSMADDQPO_XSMSUBQP_XSMSUBQPO_XSMULQP_XSMULQPO_XSNMADDQP_XSNMADDQPO_XSNMSUBQP_XSNMSUBQPO
  { 1, 153, 154, 0, 0 }, // 168 BCDCFSQ_rec
  { 1, 153, 154, 0, 0 }, // 169 XSDIVQP_XSDIVQPO
  { 1, 153, 154, 0, 0 }, // 170 XSSQRTQP_XSSQRTQPO
  { 1, 156, 157, 0, 0 }, // 171 LXVL_LXVLL
  { 1, 156, 157, 0, 0 }, // 172 LVEBX_LVEHX_LVEWX_LVX_LVXL
  { 1, 156, 157, 0, 0 }, // 173 LXSIBZX_LXSIHZX_LXSDX_LXVB16X_LXVD2X_LXVWSX_LXSIWZX_LXV_LXVX_LXSD
  { 0, 0, 0, 0, 0 }, // 174 DFLOADf64_XFLOADf64_LIWZX
  { 1, 156, 157, 0, 0 }, // 175 DCBF_DCBFEP_DCBST_DCBSTEP_DCBT_DCBTEP_DCBZ_DCBZEP_DCBZL_DCBZLEP_DCBTST_DCBTSTEP
  { 0, 0, 0, 0, 0 }, // 176 CP_COPY_CP_COPY8
  { 0, 0, 0, 0, 0 }, // 177 CP_PASTE_CP_PASTE8
  { 1, 165, 166, 0, 0 }, // 178 ICBI_ICBIEP
  { 1, 156, 157, 0, 0 }, // 179 ICBT_ICBTLS_LBZ_LBZ8_LBZCIX_LBZX_LBZX8_LBZXTLS_LBZXTLS__LBZXTLS_32_LDBRX_LDCIX_LHBRX_LHBRX8_LHZ_LHZ8_LHZCIX_LHZX_LHZX8_LHZXTLS_LHZXTLS__LHZXTLS_32_LWBRX_LWBRX8_LWZ_LWZ8_LWZCIX_LWZX_LWZX8_LWZXTLS_LWZXTLS__LWZXTLS_32_EnforceIEIO_LSWI
  { 1, 166, 167, 0, 0 }, // 180 LBARX_LBARXL_LHARX_LHARXL_LWARX_LWARXL
  { 1, 156, 157, 0, 0 }, // 181 LD_LDX_LDXTLS_LDXTLS__DARN
  { 1, 166, 167, 0, 0 }, // 182 LDARX_LDARXL
  { 0, 0, 0, 0, 0 }, // 183 CP_ABORT
  { 1, 165, 166, 0, 0 }, // 184 ISYNC
  { 0, 0, 0, 0, 0 }, // 185 MSGSYNC
  { 1, 156, 157, 0, 0 }, // 186 TLBSYNC
  { 1, 150, 151, 0, 0 }, // 187 SYNC
  { 1, 168, 169, 0, 0 }, // 188 LMW
  { 1, 156, 157, 0, 0 }, // 189 LFIWZX_LFDX_LFD
  { 0, 0, 0, 0, 0 }, // 190 SLBIA
  { 0, 0, 0, 0, 0 }, // 191 SLBIE
  { 0, 0, 0, 0, 0 }, // 192 SLBMFEE
  { 0, 0, 0, 0, 0 }, // 193 SLBMFEV
  { 0, 0, 0, 0, 0 }, // 194 SLBMTE
  { 0, 0, 0, 0, 0 }, // 195 TLBIEL
  { 1, 156, 157, 0, 0 }, // 196 LHZU_LHZU8_LWZU_LWZU8
  { 1, 156, 157, 0, 0 }, // 197 LHZUX_LHZUX8_LWZUX_LWZUX8
  { 1, 176, 177, 0, 0 }, // 198 TEND
  { 1, 166, 167, 0, 0 }, // 199 STBCX_STHCX_STWCX
  { 1, 166, 167, 0, 0 }, // 200 STDCX
  { 1, 156, 157, 0, 0 }, // 201 LDMX
  { 1, 167, 168, 0, 0 }, // 202 LHA_LHA8_LHAX_LHAX8_LWAX_LWAX_32
  { 0, 0, 0, 0, 0 }, // 203 CP_PASTE8_rec_CP_PASTE_rec
  { 1, 167, 168, 0, 0 }, // 204 LWA_LWA_32
  { 1, 176, 177, 0, 0 }, // 205 TCHECK
  { 1, 156, 157, 0, 0 }, // 206 LFIWAX
  { 1, 156, 157, 0, 0 }, // 207 LXSIWAX
  { 0, 0, 0, 0, 0 }, // 208 LIWAX
  { 1, 156, 157, 0, 0 }, // 209 LFSX_LFS
  { 1, 156, 157, 0, 0 }, // 210 LXSSP_LXSSPX
  { 0, 0, 0, 0, 0 }, // 211 XFLOADf32_DFLOADf32
  { 1, 167, 168, 0, 0 }, // 212 LHAU_LHAU8
  { 1, 167, 168, 0, 0 }, // 213 LHAUX_LHAUX8_LWAUX
  { 1, 156, 157, 0, 0 }, // 214 LXVH8X_LXVDSX_LXVW4X
  { 1, 180, 181, 0, 0 }, // 215 STFD_STFDX_STFIWX_STFS_STFSX_STXSD_STXSDX_STXSIBX_STXSIBXv_STXSIHX_STXSIHXv_STXSIWX_STXSSP_STXSSPX
  { 1, 156, 157, 0, 0 }, // 216 STW_STW8_STDBRX_STHBRX_STWBRX_STB_STB8_STH_STH8_STBX_STBX8_STBXTLS_STBXTLS__STBXTLS_32_STHX_STHX8_STHXTLS_STHXTLS__STHXTLS_32_STWX_STWX8_STWXTLS_STWXTLS__STWXTLS_32
  { 0, 0, 0, 0, 0 }, // 217 DFSTOREf32_DFSTOREf64_XFSTOREf32_XFSTOREf64_STIWX
  { 1, 156, 157, 0, 0 }, // 218 STD_STDX_STDXTLS_STDXTLS_
  { 1, 156, 157, 0, 0 }, // 219 STBCIX_STDCIX_STHCIX_STWCIX_STSWI
  { 0, 0, 0, 0, 0 }, // 220 SLBIEG
  { 1, 168, 169, 0, 0 }, // 221 STMW
  { 0, 0, 0, 0, 0 }, // 222 TLBIE
  { 1, 156, 157, 0, 0 }, // 223 STVEBX_STVEHX_STVEWX_STVX_STVXL
  { 1, 180, 181, 0, 0 }, // 224 STXV_STXVB16X_STXVD2X_STXVH8X_STXVW4X_STXVX
  { 1, 156, 157, 0, 0 }, // 225 STXVL_STXVLL
  { 1, 176, 177, 0, 0 }, // 226 MTCTR_MTCTR8_MTCTR8loop_MTCTRloop_MTLR_MTLR8
  { 1, 151, 152, 0, 0 }, // 227 MFVRSAVE_MFVRSAVEv_MTVRSAVE_MTVRSAVEv
  { 0, 0, 0, 0, 0 }, // 228 MFPMR
  { 0, 0, 0, 0, 0 }, // 229 MTPMR
  { 1, 175, 176, 0, 0 }, // 230 MFTB_MFTB8
  { 1, 173, 174, 0, 0 }, // 231 MFCTR_MFCTR8_MFLR_MFLR8_MFSPR_MFSPR8
  { 1, 173, 174, 0, 0 }, // 232 MFMSR
  { 1, 156, 157, 0, 0 }, // 233 MTMSR
  { 0, 0, 0, 0, 0 }, // 234 MTMSRD
  { 1, 176, 177, 0, 0 }, // 235 MTSPR_MTSPR8
  { 1, 158, 159, 0, 0 }, // 236 DIVW_DIVWO_DIVWU_DIVWUO_MODSW
  { 1, 158, 159, 0, 0 }, // 237 DIVWE_DIVWEO_DIVWEU_DIVWEUO_MODSD_MODUD_MODUW
  { 1, 157, 158, 0, 0 }, // 238 DIVD_DIVDO_DIVDU_DIVDUO
  { 1, 157, 158, 0, 0 }, // 239 DIVDE_DIVDEO_DIVDEU_DIVDEUO
  { 1, 158, 159, 0, 0 }, // 240 DIVWO_rec_DIVWUO_rec_DIVWU_rec_DIVW_rec
  { 1, 157, 158, 0, 0 }, // 241 DIVD_rec_DIVDO_rec_DIVDU_rec_DIVDUO_rec
  { 1, 158, 159, 0, 0 }, // 242 DIVWE_rec_DIVWEO_rec_DIVWEU_rec_DIVWEUO_rec
  { 1, 157, 158, 0, 0 }, // 243 DIVDE_rec_DIVDEO_rec_DIVDEU_rec_DIVDEUO_rec
  { 1, 171, 172, 0, 0 }, // 244 MTCRF_MTCRF8
  { 1, 151, 152, 0, 0 }, // 245 ADDC8O_rec_ADDC8_rec_ADDCO_rec_ADDC_rec_SUBFC8O_rec_SUBFC8_rec_SUBFCO_rec_SUBFC_rec
  { 1, 159, 160, 0, 0 }, // 246 FABSD_rec_FABSS_rec_FNABSD_rec_FNABSS_rec_FCPSGND_rec_FCPSGNS_rec_FNEGD_rec_FNEGS_rec_FMR_rec
  { 1, 170, 171, 0, 0 }, // 247 MCRFS
  { 1, 174, 175, 0, 0 }, // 248 MTFSF_MTFSF_rec_MTFSFI_MTFSFI_rec
  { 1, 159, 160, 0, 0 }, // 249 MTFSFb
  { 1, 151, 152, 0, 0 }, // 250 RLDCL_rec_RLDCR_rec
  { 1, 151, 152, 0, 0 }, // 251 RLDICL_rec_RLDICR_rec_RLDICL_32_rec_RLDIMI_rec
  { 1, 178, 179, 0, 0 }, // 252 RLWIMI8_rec_RLWIMI_rec
  { 1, 151, 152, 0, 0 }, // 253 RLWINM8_rec_RLWINM_rec_RLWNM8_rec_RLWNM_rec_SLW8_rec_SLW_rec_SRW8_rec_SRW_rec
  { 1, 151, 152, 0, 0 }, // 254 SRAWI_rec_SRAW_rec
  { 1, 174, 175, 0, 0 }, // 255 MFFS_MFFSCE_MFFSL_MFFS_rec
  { 1, 172, 173, 0, 0 }, // 256 MFCR_MFCR8
  { 1, 151, 152, 0, 0 }, // 257 EXTSWSLI_32_64_rec_SRADI_rec_EXTSWSLI_rec_RLDIC_rec
  { 1, 151, 152, 0, 0 }, // 258 SRAD_rec_SLD_rec_SRD_rec
  { 1, 160, 161, 0, 0 }, // 259 FDIV
  { 1, 160, 161, 0, 0 }, // 260 FDIV_rec
  { 1, 164, 165, 0, 0 }, // 261 XSSQRTDP
  { 1, 164, 165, 0, 0 }, // 262 FSQRT
  { 1, 164, 165, 0, 0 }, // 263 XVSQRTDP
  { 1, 164, 165, 0, 0 }, // 264 XVSQRTSP
  { 1, 164, 165, 0, 0 }, // 265 FSQRT_rec
  { 1, 164, 165, 0, 0 }, // 266 XSSQRTSP
  { 1, 164, 165, 0, 0 }, // 267 FSQRTS
  { 1, 164, 165, 0, 0 }, // 268 FSQRTS_rec
  { 1, 160, 161, 0, 0 }, // 269 XSDIVDP
  { 1, 160, 161, 0, 0 }, // 270 FDIVS
  { 1, 160, 161, 0, 0 }, // 271 FDIVS_rec
  { 1, 160, 161, 0, 0 }, // 272 XSDIVSP
  { 1, 160, 161, 0, 0 }, // 273 XVDIVSP
  { 1, 160, 161, 0, 0 }, // 274 XVDIVDP
  { 1, 167, 168, 0, 0 }, // 275 LFSU
  { 1, 167, 168, 0, 0 }, // 276 LFSUX
  { 1, 180, 181, 0, 0 }, // 277 STFDU_STFDUX_STFSU_STFSUX
  { 1, 156, 157, 0, 0 }, // 278 STBU_STBU8_STDU_STHU_STHU8_STWU_STWU8
  { 1, 156, 157, 0, 0 }, // 279 STBUX_STBUX8_STDUX_STHUX_STHUX8_STWUX_STWUX8
  { 1, 156, 157, 0, 0 }, // 280 LBZU_LBZU8
  { 1, 156, 157, 0, 0 }, // 281 LBZUX_LBZUX8
  { 1, 156, 157, 0, 0 }, // 282 LDU
  { 1, 156, 157, 0, 0 }, // 283 LDUX
  { 1, 167, 168, 0, 0 }, // 284 LFDU
  { 1, 167, 168, 0, 0 }, // 285 LFDUX
  { 1, 153, 154, 0, 0 }, // 286 VPMSUMB_VPMSUMD_VPMSUMH_VPMSUMW_VCIPHER_VCIPHERLAST_VNCIPHER_VNCIPHERLAST_VSBOX
  { 1, 152, 153, 0, 0 }, // 287 BCCCTR_BCCCTR8_BCCCTRL_BCCCTRL8_BCCL_BCCLA_BCCLR_BCCLRL_BCCTR_BCCTR8_BCCTR8n_BCCTRL_BCCTRL8_BCCTRL8n_BCCTRLn_BCCTRn_BDNZ_BDNZ8_BDNZA_BDNZAm_BDNZAp_BDNZm_BDNZp_BDZ_BDZ8_BDZA_BDZAm_BDZAp_BDZm_BDZp_BDNZL_BDNZLA_BDNZLAm_BDNZLAp_BDNZLR_BDNZLR8_BDNZLRL_BDNZLRLm_BDNZLRLp_BDNZLRm_BDNZLRp_BDNZLm_BDNZLp_BDZL_BDZLA_BDZLAm_BDZLAp_BDZLR_BDZLR8_BDZLRL_BDZLRLm_BDZLRLp_BDZLRm_BDZLRp_BDZLm_BDZLp_BL_BL_NOP_BL_TLS_BL8_BL8_NOP_BL8_NOP_TLS_BL8_TLS_BL8_TLS__BLA_BLA8_BLA8_NOP_BLR_BLR8_BLRL_TAILB_TAILB8_TAILBA_TAILBA8_TAILBCTR_TAILBCTR8_gBC_gBCA_gBCAat_gBCCTR_gBCCTRL_gBCL_gBCLA_gBCLAat_gBCLR_gBCLRL_gBCLat_gBCat_BCLR_BCLRL_BCLRLn_BCLRn_BCTR_BCTR8_BCTRL_BCTRL8_B_BA_BC_BCC_BCCA_BCL_BCLalways_BCLn_BCTRL8_LDinto_toc_BCTRL_LWZinto_toc_BCn_CTRL_DEP
  { 1, 152, 153, 0, 0 }, // 288 ADDPCIS
  { 1, 156, 157, 0, 0 }, // 289 LDAT_LWAT
  { 1, 156, 157, 0, 0 }, // 290 STDAT_STWAT
  { 1, 151, 152, 0, 0 }, // 291 BRINC
  { 1, 162, 163, 0, 0 }, // 292 EVABS_EVEQV_EVNAND_EVNEG_EVADDIW_EVADDW_EVAND_EVANDC_EVCMPEQ_EVCMPGTS_EVCMPGTU_EVCMPLTS_EVCMPLTU_EVCNTLSW_EVCNTLZW_EVEXTSB_EVEXTSH_EVMERGEHI_EVMERGEHILO_EVMERGELO_EVMERGELOHI_EVNOR_EVOR_EVORC_EVXOR_EVRLW_EVRLWI_EVRNDW_EVSLW_EVSLWI_EVSPLATFI_EVSPLATI_EVSRWIS_EVSRWIU_EVSRWS_EVSRWU_EVSUBFW_EVSUBIFW
  { 1, 163, 164, 0, 0 }, // 293 EVMRA_EVADDSMIAAW_EVADDSSIAAW_EVADDUMIAAW_EVADDUSIAAW_EVDIVWS_EVDIVWU_EVMHEGSMFAA_EVMHEGSMFAN_EVMHEGSMIAA_EVMHEGSMIAN_EVMHEGUMIAA_EVMHEGUMIAN_EVMHESMF_EVMHESMFA_EVMHESMFAAW_EVMHESMFANW_EVMHESMI_EVMHESMIA_EVMHESMIAAW_EVMHESMIANW_EVMHESSF_EVMHESSFA_EVMHESSFAAW_EVMHESSFANW_EVMHESSIAAW_EVMHESSIANW_EVMHEUMI_EVMHEUMIA_EVMHEUMIAAW_EVMHEUMIANW_EVMHEUSIAAW_EVMHEUSIANW_EVMHOGSMFAA_EVMHOGSMFAN_EVMHOGSMIAA_EVMHOGSMIAN_EVMHOGUMIAA_EVMHOGUMIAN_EVMHOSMF_EVMHOSMFA_EVMHOSMFAAW_EVMHOSMFANW_EVMHOSMI_EVMHOSMIA_EVMHOSMIAAW_EVMHOSMIANW_EVMHOSSF_EVMHOSSFA_EVMHOSSFAAW_EVMHOSSFANW_EVMHOSSIAAW_EVMHOSSIANW_EVMHOUMI_EVMHOUMIA_EVMHOUMIAAW_EVMHOUMIANW_EVMHOUSIAAW_EVMHOUSIANW_EVMWHSMF_EVMWHSMFA_EVMWHSMI_EVMWHSMIA_EVMWHSSF_EVMWHSSFA_EVMWHUMI_EVMWHUMIA_EVMWLSMIAAW_EVMWLSMIANW_EVMWLSSIAAW_EVMWLSSIANW_EVMWLUMI_EVMWLUMIA_EVMWLUMIAAW_EVMWLUMIANW_EVMWLUSIAAW_EVMWLUSIANW_EVMWSMF_EVMWSMFA_EVMWSMFAA_EVMWSMFAN_EVMWSMI_EVMWSMIA_EVMWSMIAA_EVMWSMIAN_EVMWSSF_EVMWSSFA_EVMWSSFAA_EVMWSSFAN_EVMWUMI_EVMWUMIA_EVMWUMIAA_EVMWUMIAN_EVSUBFSMIAAW_EVSUBFSSIAAW_EVSUBFUMIAAW_EVSUBFUSIAAW
  { 1, 156, 157, 0, 0 }, // 294 EVLDD_EVLDDX_EVLDH_EVLDHX_EVLDW_EVLDWX_EVLHHESPLAT_EVLHHESPLATX_EVLHHOSSPLAT_EVLHHOSSPLATX_EVLHHOUSPLAT_EVLHHOUSPLATX_EVLWHE_EVLWHEX_EVLWHOS_EVLWHOSX_EVLWHOU_EVLWHOUX_EVLWHSPLAT_EVLWHSPLATX_EVLWWSPLAT_EVLWWSPLATX
  { 1, 156, 157, 0, 0 }, // 295 EVSTDD_EVSTDDX_EVSTDH_EVSTDHX_EVSTDW_EVSTDWX_EVSTWHE_EVSTWHEX_EVSTWHO_EVSTWHOX_EVSTWWE_EVSTWWEX_EVSTWWO_EVSTWWOX
  { 1, 152, 153, 0, 0 }, // 296 HRFID_ATTN_CLRBHRB_MFBHRBE_NAP_RFCI_RFDI_RFMCI_SC
  { 0, 0, 0, 0, 0 }, // 297 RFI
  { 1, 181, 182, 0, 0 }, // 298 RFID
  { 1, 156, 157, 0, 0 }, // 299 DSS_DSSALL_DST_DST64_DSTST_DSTST64_DSTSTT_DSTSTT64_DSTT_DSTT64_ICBLQ_LBEPX_LHEPX_LWEPX_TLBIVAX_TLBLD_TLBLI_TLBRE_TLBRE2_TLBSX_TLBSX2_TLBSX2D_TLBWE_TLBWE2_MBAR_TRAP_DCCCI_ICCCI
  { 1, 156, 157, 0, 0 }, // 300 ICBLC_STBEPX_STHEPX_STWEPX
  { 1, 156, 157, 0, 0 }, // 301 LFDEPX
  { 1, 180, 181, 0, 0 }, // 302 STFDEPX
  { 1, 156, 157, 0, 0 }, // 303 MFSR_MFSRIN
  { 1, 156, 157, 0, 0 }, // 304 MTSR_MTSRIN
  { 1, 173, 174, 0, 0 }, // 305 MFDCR
  { 1, 176, 177, 0, 0 }, // 306 MTDCR
  { 1, 151, 152, 0, 0 }, // 307 NOP_GT_PWR6_NOP_GT_PWR7
  { 0, 0, 0, 0, 0 }, // 308 TLBIA
  { 1, 156, 157, 0, 0 }, // 309 WRTEE_WRTEEI
  { 1, 150, 151, 0, 0 }, // 310 MSYNC
  { 0, 0, 0, 0, 0 }, // 311 SLBSYNC
  { 0, 0, 0, 0, 0 }, // 312 SLBFEE_rec
  { 0, 0, 0, 0, 0 }, // 313 STOP
  { 1, 156, 157, 0, 0 }, // 314 DCBA_DCBI
  { 0, uint16_t(~0U), uint16_t(~0U), uint16_t(~0U), uint16_t(~0U) }// end marker
};

static const llvm::InstrItinerary PPCA2Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 184, 185, 539, 540 }, // 1 IIC_LdStSync
  { 1, 184, 185, 540, 543 }, // 2 IIC_IntSimple
  { 1, 184, 185, 543, 546 }, // 3 IIC_IntGeneral
  { 1, 184, 185, 546, 549 }, // 4 IIC_BrB
  { 0, 0, 0, 0, 0 }, // 5 IIC_VecFP
  { 1, 184, 185, 549, 552 }, // 6 IIC_IntCompare
  { 0, 0, 0, 0, 0 }, // 7 IIC_SprABORT
  { 0, 0, 0, 0, 0 }, // 8 IIC_LdStCOPY
  { 0, 0, 0, 0, 0 }, // 9 IIC_LdStPASTE
  { 1, 184, 185, 552, 555 }, // 10 IIC_BrCR
  { 0, 0, 0, 0, 0 }, // 11 IIC_LdStLD
  { 1, 184, 185, 555, 558 }, // 12 IIC_LdStDCBF
  { 1, 184, 185, 558, 561 }, // 13 IIC_LdStLoad
  { 1, 184, 185, 561, 564 }, // 14 IIC_IntDivD
  { 1, 184, 185, 564, 567 }, // 15 IIC_IntDivW
  { 0, 0, 0, 0, 0 }, // 16 IIC_FPDGeneral
  { 1, 185, 186, 567, 570 }, // 17 IIC_FPAddSub
  { 1, 185, 186, 570, 573 }, // 18 IIC_FPDivD
  { 0, 0, 0, 0, 0 }, // 19 IIC_FPSGeneral
  { 1, 185, 186, 573, 576 }, // 20 IIC_FPCompare
  { 1, 185, 186, 576, 579 }, // 21 IIC_FPGeneral
  { 0, 0, 0, 0, 0 }, // 22 IIC_VecGeneral
  { 0, 0, 0, 0, 0 }, // 23 IIC_VecComplex
  { 1, 184, 185, 579, 582 }, // 24 IIC_LdStStore
  { 1, 184, 185, 582, 585 }, // 25 IIC_IntRotateDI
  { 1, 185, 186, 585, 588 }, // 26 IIC_FPDivS
  { 1, 185, 186, 588, 592 }, // 27 IIC_FPFused
  { 1, 185, 186, 592, 595 }, // 28 IIC_FPSqrtD
  { 1, 185, 186, 595, 598 }, // 29 IIC_FPSqrtS
  { 1, 184, 185, 598, 601 }, // 30 IIC_LdStICBI
  { 1, 184, 185, 601, 605 }, // 31 IIC_IntISEL
  { 1, 184, 185, 605, 606 }, // 32 IIC_SprISYNC
  { 1, 184, 185, 606, 609 }, // 33 IIC_LdStLWARX
  { 1, 184, 185, 609, 613 }, // 34 IIC_LdStLoadUpd
  { 1, 184, 185, 613, 617 }, // 35 IIC_LdStLoadUpdX
  { 0, 0, 0, 0, 0 }, // 36 IIC_LdStLDARX
  { 1, 184, 185, 617, 620 }, // 37 IIC_LdStLDU
  { 1, 184, 185, 620, 623 }, // 38 IIC_LdStLDUX
  { 1, 184, 185, 623, 626 }, // 39 IIC_LdStLFD
  { 1, 184, 185, 626, 630 }, // 40 IIC_LdStLFDU
  { 1, 184, 185, 630, 634 }, // 41 IIC_LdStLFDUX
  { 1, 184, 185, 634, 637 }, // 42 IIC_LdStLHA
  { 1, 184, 185, 637, 641 }, // 43 IIC_LdStLHAU
  { 1, 184, 185, 641, 645 }, // 44 IIC_LdStLHAUX
  { 0, 0, 0, 0, 0 }, // 45 IIC_LdStLMW
  { 0, 0, 0, 0, 0 }, // 46 IIC_LdStLWA
  { 0, 0, 0, 0, 0 }, // 47 IIC_IntMulHD
  { 1, 184, 185, 645, 648 }, // 48 IIC_BrMCR
  { 1, 184, 185, 648, 651 }, // 49 IIC_BrMCRX
  { 1, 184, 185, 651, 653 }, // 50 IIC_SprMFCR
  { 1, 184, 185, 653, 655 }, // 51 IIC_SprMFSPR
  { 0, 0, 0, 0, 0 }, // 52 IIC_IntMFFS
  { 1, 184, 185, 655, 657 }, // 53 IIC_SprMFMSR
  { 1, 184, 185, 657, 659 }, // 54 IIC_SprMFCRF
  { 0, 0, 0, 0, 0 }, // 55 IIC_SprMFPMR
  { 0, 0, 0, 0, 0 }, // 56 IIC_SprMFSR
  { 1, 184, 185, 659, 661 }, // 57 IIC_SprMFTB
  { 0, 0, 0, 0, 0 }, // 58 IIC_SprMSGSYNC
  { 1, 184, 185, 661, 663 }, // 59 IIC_SprMTSPR
  { 0, 0, 0, 0, 0 }, // 60 IIC_IntMTFSB0
  { 1, 184, 185, 663, 665 }, // 61 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 62 IIC_SprMTMSRD
  { 0, 0, 0, 0, 0 }, // 63 IIC_SprMTPMR
  { 0, 0, 0, 0, 0 }, // 64 IIC_SprMTSR
  { 1, 184, 185, 665, 668 }, // 65 IIC_IntMulHW
  { 1, 184, 185, 668, 671 }, // 66 IIC_IntMulHWU
  { 1, 184, 185, 671, 674 }, // 67 IIC_IntMulLI
  { 0, 0, 0, 0, 0 }, // 68 IIC_VecPerm
  { 1, 184, 185, 674, 677 }, // 69 IIC_LdStSTFD
  { 1, 184, 185, 677, 681 }, // 70 IIC_LdStSTFDU
  { 1, 184, 185, 681, 682 }, // 71 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 72 IIC_IntRFID
  { 1, 184, 185, 682, 685 }, // 73 IIC_IntRotateD
  { 1, 184, 185, 685, 688 }, // 74 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 75 IIC_SprSLBFEE
  { 0, 0, 0, 0, 0 }, // 76 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 77 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprSLBIEG
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprSLBMFEV
  { 0, 0, 0, 0, 0 }, // 81 IIC_SprSLBMTE
  { 0, 0, 0, 0, 0 }, // 82 IIC_SprSLBSYNC
  { 1, 184, 185, 688, 691 }, // 83 IIC_IntShift
  { 1, 184, 185, 691, 694 }, // 84 IIC_LdStSTWCX
  { 1, 184, 185, 694, 698 }, // 85 IIC_LdStSTU
  { 1, 184, 185, 698, 702 }, // 86 IIC_LdStSTUX
  { 1, 184, 185, 702, 705 }, // 87 IIC_LdStSTD
  { 1, 184, 185, 705, 708 }, // 88 IIC_LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 89 IIC_SprSTOP
  { 1, 184, 185, 708, 710 }, // 90 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 91 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 92 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 93 IIC_SprTLBIEL
  { 0, 0, 0, 0, 0 }, // 94 IIC_SprTLBSYNC
  { 1, 184, 185, 710, 712 }, // 95 IIC_IntTrapW
  { 0, 0, 0, 0, 0 }, // 96 IIC_VecFPCompare
  { 0, 0, 0, 0, 0 }, // 97 VADDUBM_VADDUDM_VADDUHM_VADDUWM_VEXTSB2D_VEXTSB2Ds_VEXTSB2W_VEXTSB2Ws_VEXTSH2D_VEXTSH2Ds_VEXTSH2W_VEXTSH2Ws_VEXTSW2D_VEXTSW2Ds_VSLD_VSRD_VSUBUBM_VSUBUDM_VSUBUHM_VSUBUWM_VPOPCNTB_VPOPCNTH_VSRAD_MTVSRDD_VEQV_VNAND_VNEGD_VNEGW_VORC_XXLAND_XXLANDC_XXLEQV_XXLEQVOnes_XXLNAND_XXLNOR_XXLOR_XXLORf_XXLORC_XXLXOR_XXLXORdpz_XXLXORspz_XXLXORz
  { 0, 0, 0, 0, 0 }, // 98 VAND_VANDC_V_SET0_V_SET0B_V_SET0H_VSLB_VSLH_VSLW_VSRB_VSRH_VSRW_VRLB_VRLD_VRLH_VRLW_VSRAB_VSRAH_VSRAW_XVABSDP_XVABSSP_XVNABSDP_XVNABSSP_XVCPSGNDP_XVCPSGNSP_XVIEXPDP_XVIEXPSP_XVXEXPDP_XVXEXPSP_VRLDMI_VRLDNM_VRLWMI_VRLWNM_VMRGEW_VMRGOW_VNOR_VOR_VSEL_VXOR_XVNEGDP_XVNEGSP_XSABSQP_XSCPSGNQP_XSIEXPQP_XSNABSQP_XSNEGQP_XSXEXPQP
  { 0, 0, 0, 0, 0 }, // 99 XXSEL
  { 1, 184, 185, 712, 714 }, // 100 TABORTDC_TABORTDCI_TABORTWC_TABORTWCI
  { 0, 0, 0, 0, 0 }, // 101 MTFSB0_MTFSB1
  { 0, 0, 0, 0, 0 }, // 102 MFFSCDRN_MFFSCDRNI_MFFSCRN_MFFSCRNI
  { 1, 184, 185, 714, 717 }, // 103 CMPRB_CMPRB8_CMPEQB
  { 1, 184, 185, 717, 719 }, // 104 TD_TDI
  { 1, 184, 185, 719, 721 }, // 105 TW_TWI
  { 1, 185, 186, 721, 724 }, // 106 FCMPUD_FCMPUS_FTDIV_FTSQRT
  { 0, 0, 0, 0, 0 }, // 107 XSTSTDCDP_XSTSTDCSP
  { 0, 0, 0, 0, 0 }, // 108 XSMAXCDP_XSMAXDP_XSMAXJDP_XSMINCDP_XSMINDP_XSMINJDP_XSXSIGDP_XSCVSPDPN
  { 1, 185, 186, 724, 727 }, // 109 XSCMPEQDP_XSCMPEXPDP_XSCMPGEDP_XSCMPGTDP_XSCMPODP_XSCMPUDP_XSTDIVDP_XSTSQRTDP
  { 1, 184, 185, 727, 730 }, // 110 CNTLZD_CNTLZD_rec_CNTLZW_CNTLZW8_CNTLZW8_rec_CNTLZW_rec_CNTTZD_CNTTZD_rec_CNTTZW_CNTTZW8_CNTTZW8_rec_CNTTZW_rec_POPCNTD_POPCNTW_CMPB_CMPB8_SETB_SETB8_BPERMD
  { 1, 184, 185, 730, 733 }, // 111 SLD_SRD_SRAD
  { 1, 184, 185, 733, 736 }, // 112 SRADI_EXTSWSLI_32_64_EXTSWSLI_SRADI_32_RLDIC
  { 0, 0, 0, 0, 0 }, // 113 MFVRD_MFVSRD_MTVRD_MTVSRD_MTVRWA_MTVRWZ_MTVSRWA_MTVSRWZ_MFVSRWZ_MFVRWZ
  { 1, 184, 185, 736, 739 }, // 114 CMPLW_CMPLWI_CMPW_CMPWI_CMPD_CMPDI_CMPLD_CMPLDI
  { 1, 184, 185, 739, 742 }, // 115 SUBFC_SUBFC8_SUBFC8O_SUBFCO_SUBFIC_SUBFIC8_ANDI8_rec_ANDIS8_rec_ANDIS_rec_ANDI_rec_ADDC_ADDC8_ADDC8O_ADDCO_ADDIC_ADDIC8_ADDIC_rec_ADDE_ADDE8_ADDE8O_ADDE8O_rec_ADDE8_rec_ADDEO_ADDEO_rec_ADDE_rec_ADDME_ADDME8_ADDME8O_ADDME8O_rec_ADDME8_rec_ADDMEO_ADDMEO_rec_ADDME_rec_ADDZE_ADDZE8_ADDZE8O_ADDZE8O_rec_ADDZE8_rec_ADDZEO_ADDZEO_rec_ADDZE_rec_SUBF_SUBF8_SUBF8O_SUBF8O_rec_SUBF8_rec_SUBFE_SUBFE8_SUBFE8O_SUBFE8O_rec_SUBFE8_rec_SUBFEO_SUBFEO_rec_SUBFE_rec_SUBFME_SUBFME8_SUBFME8O_SUBFME8O_rec_SUBFME8_rec_SUBFMEO_SUBFMEO_rec_SUBFME_rec_SUBFO_SUBFO_rec_SUBFZE_SUBFZE8_SUBFZE8O_SUBFZE8O_rec_SUBFZE8_rec_SUBFZEO_SUBFZEO_rec_SUBFZE_rec_SUBF_rec_POPCNTB_LA
  { 1, 184, 185, 742, 745 }, // 116 ADD4_ADD4O_ADD4O_rec_ADD4_rec_ADD8_ADD8O_ADD8O_rec_ADD8_rec_NEG_NEG8_NEG8O_NEG8O_rec_NEG8_rec_NEGO_NEGO_rec_NEG_rec_ADDI_ADDI8_ADDIS_ADDIS8_LI_LI8_LIS_LIS8_OR_OR8_OR8_rec_ORI_ORI8_ORIS_ORIS8_OR_rec_XOR_XOR8_XOR8_rec_XORI_XORI8_XORIS_XORIS8_XOR_rec_NAND_NAND8_NAND8_rec_NAND_rec_AND_AND8_AND8_rec_ANDC_ANDC8_ANDC8_rec_ANDC_rec_AND_rec_NOR_NOR8_NOR8_rec_NOR_rec_ORC_ORC8_ORC8_rec_ORC_rec_EQV_EQV8_EQV8_rec_EQV_rec_EXTSB_EXTSB8_EXTSB8_32_64_EXTSB8_rec_EXTSB_rec_EXTSH_EXTSH8_EXTSH8_32_64_EXTSH8_rec_EXTSH_rec_EXTSW_EXTSW_32_EXTSW_32_64_EXTSW_32_64_rec_EXTSW_rec_ADD4TLS_ADD8TLS_ADD8TLS__NOP
  { 0, 0, 0, 0, 0 }, // 117 ADDIStocHA_ADDIStocHA8_ADDItocL_COPY
  { 1, 184, 185, 745, 748 }, // 118 MCRF
  { 1, 184, 185, 748, 751 }, // 119 MCRXRX
  { 0, 0, 0, 0, 0 }, // 120 XSNABSDP_XSXEXPDP_XSABSDP_XSNEGDP_XSCPSGNDP
  { 1, 184, 185, 751, 754 }, // 121 RFEBB
  { 1, 184, 185, 754, 756 }, // 122 TBEGIN_TRECHKPT
  { 1, 184, 185, 756, 759 }, // 123 WAIT
  { 1, 184, 185, 759, 762 }, // 124 RLDCL_RLDCR
  { 1, 184, 185, 762, 765 }, // 125 RLWIMI_RLWIMI8
  { 1, 184, 185, 765, 768 }, // 126 RLDICL_RLDICL_32_RLDICL_32_64_RLDICR_RLDICR_32_RLDIMI
  { 1, 184, 185, 768, 770 }, // 127 MFOCRF_MFOCRF8
  { 1, 184, 185, 770, 773 }, // 128 MTOCRF_MTOCRF8
  { 1, 184, 185, 773, 776 }, // 129 CR6SET_CR6UNSET_CRSET_CRUNSET_CRAND_CRANDC_CRNAND_CRNOR_CROR_CRORC_CREQV_CRXOR
  { 1, 184, 185, 776, 779 }, // 130 SLW_SLW8_SRW_SRW8_RLWINM_RLWINM8_RLWNM_RLWNM8
  { 1, 185, 186, 779, 782 }, // 131 FABSD_FABSS_FNABSD_FNABSS_FNEGD_FNEGS_FCPSGND_FCPSGNS_FMR
  { 1, 184, 185, 782, 785 }, // 132 SRAW_SRAWI
  { 1, 184, 185, 785, 789 }, // 133 ISEL_ISEL8
  { 0, 0, 0, 0, 0 }, // 134 XSIEXPDP
  { 1, 184, 185, 789, 791 }, // 135 TRECLAIM_TSR_TABORT
  { 1, 184, 185, 791, 794 }, // 136 MFVSCR
  { 1, 184, 185, 794, 797 }, // 137 MTVSCR
  { 0, 0, 0, 0, 0 }, // 138 VCMPNEZB_VCMPNEZH_VCMPNEZW_VCMPEQUB_VCMPEQUD_VCMPEQUH_VCMPEQUW_VCMPNEB_VCMPNEH_VCMPNEW_VCMPEQFP_VCMPEQFP_rec_VCMPGEFP_VCMPGEFP_rec_VCMPGTFP_VCMPGTFP_rec_VCMPBFP_VCMPBFP_rec_VCMPGTSB_VCMPGTSB_rec_VCMPGTSD_VCMPGTSD_rec_VCMPGTSH_VCMPGTSH_rec_VCMPGTSW_VCMPGTSW_rec_VCMPGTUB_VCMPGTUB_rec_VCMPGTUD_VCMPGTUD_rec_VCMPGTUH_VCMPGTUH_rec_VCMPGTUW_VCMPGTUW_rec_VCMPNEB_rec_VCMPNEH_rec_VCMPNEW_rec_VCMPNEZB_rec_VCMPNEZH_rec_VCMPNEZW_rec_VCMPEQUB_rec_VCMPEQUD_rec_VCMPEQUH_rec_VCMPEQUW_rec_XVCMPEQDP_XVCMPEQDP_rec_XVCMPEQSP_XVCMPEQSP_rec_XVCMPGEDP_XVCMPGEDP_rec_XVCMPGESP_XVCMPGESP_rec_XVCMPGTDP_XVCMPGTDP_rec_XVCMPGTSP_XVCMPGTSP_rec
  { 0, 0, 0, 0, 0 }, // 139 VABSDUB_VABSDUH_VABSDUW_VCLZB_VCLZD_VCLZH_VCLZW_VCTZB_VCTZD_VCTZH_VCTZW_VPOPCNTW_VPOPCNTD_VPRTYBD_VPRTYBW
  { 0, 0, 0, 0, 0 }, // 140 VADDUBS_VADDUHS_VADDUWS_VAVGSB_VAVGSH_VAVGSW_VAVGUB_VAVGUH_VAVGUW_VADDSBS_VADDSHS_VADDSWS_VMAXFP_VMINFP_VMAXSB_VMAXSD_VMAXSH_VMAXSW_VMAXUB_VMAXUD_VMAXUH_VMAXUW_VMINSB_VMINSD_VMINSH_VMINSW_VMINUB_VMINUD_VMINUH_VMINUW_VBPERMD_VADDCUW_VSHASIGMAD_VSHASIGMAW_VSUBSBS_VSUBSHS_VSUBSWS_VSUBUBS_VSUBUHS_VSUBUWS_VSUBCUW_XVMAXDP_XVMAXSP_XVMINDP_XVMINSP_XVTSTDCDP_XVTSTDCSP_XVXSIGDP_XVXSIGSP
  { 1, 185, 186, 797, 800 }, // 141 XVTDIVDP_XVTDIVSP_XVTSQRTDP_XVTSQRTSP
  { 0, 0, 0, 0, 0 }, // 142 VADDFP_VCTSXS_VCTSXS_0_VCTUXS_VCTUXS_0_VEXPTEFP_VLOGEFP_VMADDFP_VMHADDSHS_VNMSUBFP_VREFP_VRFIM_VRFIN_VRFIP_VRFIZ_VRSQRTEFP_XVADDDP_XVADDSP_XVCVDPSP_XVCVDPSXDS_XVCVDPSXWS_XVCVDPUXDS_XVCVDPUXWS_XVCVHPSP_XVCVSPDP_XVCVSPHP_XVCVSPSXDS_XVCVSPSXWS_XVCVSPUXDS_XVCVSPUXWS_XVCVSXDDP_XVCVSXDSP_XVCVSXWDP_XVCVSXWSP_XVCVUXDDP_XVCVUXDSP_XVCVUXWDP_XVCVUXWSP_XVMADDADP_XVMADDASP_XVMADDMDP_XVMADDMSP_XVMSUBADP_XVMSUBASP_XVMSUBMDP_XVMSUBMSP_XVMULDP_XVMULSP_XVNMADDADP_XVNMADDASP_XVNMADDMDP_XVNMADDMSP_XVNMSUBADP_XVNMSUBASP_XVNMSUBMDP_XVNMSUBMSP_XVRDPI_XVRDPIC_XVRDPIM_XVRDPIP_XVRDPIZ_XVREDP_XVRESP_XVRSPI_XVRSPIC_XVRSPIM_XVRSPIP_XVRSPIZ_XVRSQRTEDP_XVRSQRTESP_XVSUBDP_XVSUBSP_VCFSX_VCFSX_0_VCFUX_VCFUX_0_VMHRADDSHS_VMLADDUHM_VMSUMMBM_VMSUMSHM_VMSUMSHS_VMSUMUBM_VMSUMUHM_VMSUMUDM_VMSUMUHS_VMULESB_VMULESH_VMULESW_VMULEUB_VMULEUH_VMULEUW_VMULOSB_VMULOSH_VMULOSW_VMULOUB_VMULOUH_VMULOUW_VSUM2SWS_VSUM4SBS_VSUM4SHS_VSUM4UBS_VSUMSWS
  { 0, 0, 0, 0, 0 }, // 143 VSUBFP_VMULUWM
  { 0, 0, 0, 0, 0 }, // 144 MADDHD_MADDHDU_MADDLD_MADDLD8_MULLD_MULLDO
  { 1, 184, 185, 800, 803 }, // 145 MULHD_MULHW_MULLW_MULLWO
  { 1, 184, 185, 803, 806 }, // 146 MULHDU_MULHWU
  { 1, 184, 185, 806, 809 }, // 147 MULLI_MULLI8
  { 1, 185, 186, 809, 812 }, // 148 FRSP_FRIMD_FRIMS_FRIND_FRINS_FRIPD_FRIPS_FRIZD_FRIZS_FRE_FRES_FADDS_FMSUBS_FMADDS_FSUBS_FCFID_FCFIDS_FCFIDU_FCFIDUS_FCTID_FCTIDU_FCTIDUZ_FCTIDZ_FCTIW_FCTIWU_FCTIWUZ_FCTIWZ_FRSQRTE_FRSQRTES_FNMADDS_FNMSUBS_FSELD_FSELS_FMULS
  { 1, 185, 186, 812, 815 }, // 149 FADD_FSUB
  { 1, 185, 186, 815, 819 }, // 150 FMSUB_FMADD_FNMADD_FNMSUB_FMUL
  { 0, 0, 0, 0, 0 }, // 151 XSMADDADP_XSMADDASP_XSMADDMDP_XSMADDMSP_XSMSUBADP_XSMSUBASP_XSMSUBMDP_XSMSUBMSP_XSMULDP_XSMULSP_XSNMADDADP_XSNMADDASP_XSNMADDMDP_XSNMADDMSP_XSNMSUBADP_XSNMSUBASP_XSNMSUBMDP_XSNMSUBMSP
  { 1, 185, 186, 819, 822 }, // 152 FSELD_rec_FSELS_rec
  { 1, 184, 185, 822, 825 }, // 153 MULHDU_rec_MULHWU_rec
  { 1, 184, 185, 825, 828 }, // 154 MULHD_rec_MULHW_rec_MULLWO_rec_MULLW_rec
  { 0, 0, 0, 0, 0 }, // 155 MULLDO_rec_MULLD_rec
  { 1, 185, 186, 828, 831 }, // 156 FRIMD_rec_FRIMS_rec_FRIND_rec_FRINS_rec_FRIPD_rec_FRIPS_rec_FRIZD_rec_FRIZS_rec_FRES_rec_FRE_rec_FADDS_rec_FSUBS_rec_FMSUBS_rec_FNMSUBS_rec_FMADDS_rec_FNMADDS_rec_FCFIDS_rec_FCFIDUS_rec_FCFIDU_rec_FCFID_rec_FCTIDUZ_rec_FCTIDU_rec_FCTIDZ_rec_FCTID_rec_FCTIWUZ_rec_FCTIWU_rec_FCTIWZ_rec_FCTIW_rec_FMULS_rec_FRSQRTES_rec_FRSQRTE_rec_FRSP_rec
  { 1, 185, 186, 831, 834 }, // 157 FADD_rec_FSUB_rec
  { 1, 185, 186, 834, 838 }, // 158 FMSUB_rec_FNMSUB_rec_FMADD_rec_FNMADD_rec_FMUL_rec
  { 0, 0, 0, 0, 0 }, // 159 XSADDDP_XSADDSP_XSCVDPHP_XSCVDPSP_XSCVDPSXDS_XSCVDPSXDSs_XSCVDPSXWS_XSCVDPUXDS_XSCVDPUXDSs_XSCVDPUXWS_XSCVDPSXWSs_XSCVDPUXWSs_XSCVHPDP_XSCVSPDP_XSCVSXDDP_XSCVSXDSP_XSCVUXDDP_XSCVUXDSP_XSRDPI_XSRDPIC_XSRDPIM_XSRDPIP_XSRDPIZ_XSREDP_XSRESP_XSRSQRTEDP_XSRSQRTESP_XSSUBDP_XSSUBSP_XSCVDPSPN_XSRSP
  { 1, 184, 185, 838, 841 }, // 160 LVSL_LVSR
  { 0, 0, 0, 0, 0 }, // 161 VSPLTISB_VSPLTISH_VSPLTISW_VSPLTB_VSPLTBs_VSPLTH_VSPLTHs_VSPLTW_XXMRGHW_XXMRGLW_XXPERM_XXPERMR_XXSLDWI_XXSLDWIs_XXSPLTIB_XXSPLTW_XXSPLTWs_XXPERMDI_XXPERMDIs
  { 0, 0, 0, 0, 0 }, // 162 V_SETALLONES_V_SETALLONESB_V_SETALLONESH_VBPERMQ_VGBBD_VMRGHB_VMRGHH_VMRGHW_VMRGLB_VMRGLH_VMRGLW_VPERM_VPERMR_VPERMXOR_VPKPX_VPKSDSS_VPKSDUS_VPKSHSS_VPKSHUS_VPKSWSS_VPKSWUS_VPKUDUM_VPKUDUS_VPKUHUM_VPKUHUS_VPKUWUM_VPKUWUS_VSL_VSLDOI_VSLO_VSLV_VSR_VSRO_VSRV_VUPKHPX_VUPKHSB_VUPKHSH_VUPKHSW_VUPKLPX_VUPKLSB_VUPKLSH_VUPKLSW_XXBRD_XXBRH_XXBRQ_XXBRW_XXEXTRACTUW_XXINSERTW_VADDCUQ_VADDECUQ_VADDEUQM_VMUL10CUQ_VMUL10ECUQ_VMUL10EUQ_VMUL10UQ_VSUBCUQ_VSUBECUQ_VSUBEUQM_XSTSTDCQP_XSXSIGQP_BCDCFN_rec_BCDCFZ_rec_BCDCPSGN_rec_BCDCTN_rec_BCDCTZ_rec_BCDSETSGN_rec_BCDS_rec_BCDTRUNC_rec_BCDUS_rec_BCDUTRUNC_rec
  { 0, 0, 0, 0, 0 }, // 163 VEXTRACTUB_VEXTRACTUH_VEXTRACTUW_VINSERTB_VINSERTD_VINSERTH_VINSERTW_MFVSRLD_MTVSRWS_VCLZLSBB_VCTZLSBB_VEXTRACTD_VEXTUBLX_VEXTUBRX_VEXTUHLX_VEXTUHRX_VEXTUWLX_VEXTUWRX_VPRTYBQ_VADDUQM_VSUBUQM
  { 1, 185, 186, 841, 844 }, // 164 XSCMPEXPQP_XSCMPOQP_XSCMPUQP
  { 0, 0, 0, 0, 0 }, // 165 BCDSR_rec_XSADDQP_XSADDQPO_XSCVDPQP_XSCVQPDP_XSCVQPDPO_XSCVQPSDZ_XSCVQPSWZ_XSCVQPUDZ_XSCVQPUWZ_XSCVSDQP_XSCVUDQP_XSRQPI_XSRQPIX_XSRQPXP_XSSUBQP_XSSUBQPO
  { 0, 0, 0, 0, 0 }, // 166 BCDCTSQ_rec
  { 0, 0, 0, 0, 0 }, // 167 XSMADDQP_XSMADDQPO_XSMSUBQP_XSMSUBQPO_XSMULQP_XSMULQPO_XSNMADDQP_XSNMADDQPO_XSNMSUBQP_XSNMSUBQPO
  { 0, 0, 0, 0, 0 }, // 168 BCDCFSQ_rec
  { 0, 0, 0, 0, 0 }, // 169 XSDIVQP_XSDIVQPO
  { 0, 0, 0, 0, 0 }, // 170 XSSQRTQP_XSSQRTQPO
  { 1, 184, 185, 844, 847 }, // 171 LXVL_LXVLL
  { 1, 184, 185, 847, 850 }, // 172 LVEBX_LVEHX_LVEWX_LVX_LVXL
  { 1, 184, 185, 850, 853 }, // 173 LXSIBZX_LXSIHZX_LXSDX_LXVB16X_LXVD2X_LXVWSX_LXSIWZX_LXV_LXVX_LXSD
  { 0, 0, 0, 0, 0 }, // 174 DFLOADf64_XFLOADf64_LIWZX
  { 1, 184, 185, 853, 856 }, // 175 DCBF_DCBFEP_DCBST_DCBSTEP_DCBT_DCBTEP_DCBZ_DCBZEP_DCBZL_DCBZLEP_DCBTST_DCBTSTEP
  { 0, 0, 0, 0, 0 }, // 176 CP_COPY_CP_COPY8
  { 0, 0, 0, 0, 0 }, // 177 CP_PASTE_CP_PASTE8
  { 1, 184, 185, 856, 859 }, // 178 ICBI_ICBIEP
  { 1, 184, 185, 859, 862 }, // 179 ICBT_ICBTLS_LBZ_LBZ8_LBZCIX_LBZX_LBZX8_LBZXTLS_LBZXTLS__LBZXTLS_32_LDBRX_LDCIX_LHBRX_LHBRX8_LHZ_LHZ8_LHZCIX_LHZX_LHZX8_LHZXTLS_LHZXTLS__LHZXTLS_32_LWBRX_LWBRX8_LWZ_LWZ8_LWZCIX_LWZX_LWZX8_LWZXTLS_LWZXTLS__LWZXTLS_32_EnforceIEIO_LSWI
  { 1, 184, 185, 862, 865 }, // 180 LBARX_LBARXL_LHARX_LHARXL_LWARX_LWARXL
  { 0, 0, 0, 0, 0 }, // 181 LD_LDX_LDXTLS_LDXTLS__DARN
  { 0, 0, 0, 0, 0 }, // 182 LDARX_LDARXL
  { 0, 0, 0, 0, 0 }, // 183 CP_ABORT
  { 1, 184, 185, 865, 866 }, // 184 ISYNC
  { 0, 0, 0, 0, 0 }, // 185 MSGSYNC
  { 0, 0, 0, 0, 0 }, // 186 TLBSYNC
  { 1, 184, 185, 866, 867 }, // 187 SYNC
  { 0, 0, 0, 0, 0 }, // 188 LMW
  { 1, 184, 185, 867, 870 }, // 189 LFIWZX_LFDX_LFD
  { 0, 0, 0, 0, 0 }, // 190 SLBIA
  { 0, 0, 0, 0, 0 }, // 191 SLBIE
  { 0, 0, 0, 0, 0 }, // 192 SLBMFEE
  { 0, 0, 0, 0, 0 }, // 193 SLBMFEV
  { 0, 0, 0, 0, 0 }, // 194 SLBMTE
  { 0, 0, 0, 0, 0 }, // 195 TLBIEL
  { 1, 184, 185, 870, 874 }, // 196 LHZU_LHZU8_LWZU_LWZU8
  { 1, 184, 185, 874, 878 }, // 197 LHZUX_LHZUX8_LWZUX_LWZUX8
  { 1, 184, 185, 878, 880 }, // 198 TEND
  { 1, 184, 185, 880, 883 }, // 199 STBCX_STHCX_STWCX
  { 1, 184, 185, 883, 886 }, // 200 STDCX
  { 0, 0, 0, 0, 0 }, // 201 LDMX
  { 1, 184, 185, 886, 889 }, // 202 LHA_LHA8_LHAX_LHAX8_LWAX_LWAX_32
  { 0, 0, 0, 0, 0 }, // 203 CP_PASTE8_rec_CP_PASTE_rec
  { 0, 0, 0, 0, 0 }, // 204 LWA_LWA_32
  { 1, 184, 185, 889, 891 }, // 205 TCHECK
  { 1, 184, 185, 891, 894 }, // 206 LFIWAX
  { 1, 184, 185, 894, 897 }, // 207 LXSIWAX
  { 0, 0, 0, 0, 0 }, // 208 LIWAX
  { 1, 184, 185, 897, 900 }, // 209 LFSX_LFS
  { 1, 184, 185, 900, 903 }, // 210 LXSSP_LXSSPX
  { 0, 0, 0, 0, 0 }, // 211 XFLOADf32_DFLOADf32
  { 1, 184, 185, 903, 907 }, // 212 LHAU_LHAU8
  { 1, 184, 185, 907, 911 }, // 213 LHAUX_LHAUX8_LWAUX
  { 1, 184, 185, 911, 914 }, // 214 LXVH8X_LXVDSX_LXVW4X
  { 1, 184, 185, 914, 917 }, // 215 STFD_STFDX_STFIWX_STFS_STFSX_STXSD_STXSDX_STXSIBX_STXSIBXv_STXSIHX_STXSIHXv_STXSIWX_STXSSP_STXSSPX
  { 1, 184, 185, 917, 920 }, // 216 STW_STW8_STDBRX_STHBRX_STWBRX_STB_STB8_STH_STH8_STBX_STBX8_STBXTLS_STBXTLS__STBXTLS_32_STHX_STHX8_STHXTLS_STHXTLS__STHXTLS_32_STWX_STWX8_STWXTLS_STWXTLS__STWXTLS_32
  { 0, 0, 0, 0, 0 }, // 217 DFSTOREf32_DFSTOREf64_XFSTOREf32_XFSTOREf64_STIWX
  { 1, 184, 185, 920, 923 }, // 218 STD_STDX_STDXTLS_STDXTLS_
  { 1, 184, 185, 923, 926 }, // 219 STBCIX_STDCIX_STHCIX_STWCIX_STSWI
  { 0, 0, 0, 0, 0 }, // 220 SLBIEG
  { 0, 0, 0, 0, 0 }, // 221 STMW
  { 0, 0, 0, 0, 0 }, // 222 TLBIE
  { 1, 184, 185, 926, 929 }, // 223 STVEBX_STVEHX_STVEWX_STVX_STVXL
  { 1, 184, 185, 929, 932 }, // 224 STXV_STXVB16X_STXVD2X_STXVH8X_STXVW4X_STXVX
  { 1, 184, 185, 932, 935 }, // 225 STXVL_STXVLL
  { 1, 184, 185, 935, 937 }, // 226 MTCTR_MTCTR8_MTCTR8loop_MTCTRloop_MTLR_MTLR8
  { 1, 184, 185, 937, 940 }, // 227 MFVRSAVE_MFVRSAVEv_MTVRSAVE_MTVRSAVEv
  { 0, 0, 0, 0, 0 }, // 228 MFPMR
  { 0, 0, 0, 0, 0 }, // 229 MTPMR
  { 1, 184, 185, 940, 942 }, // 230 MFTB_MFTB8
  { 1, 184, 185, 942, 944 }, // 231 MFCTR_MFCTR8_MFLR_MFLR8_MFSPR_MFSPR8
  { 1, 184, 185, 944, 946 }, // 232 MFMSR
  { 1, 184, 185, 946, 948 }, // 233 MTMSR
  { 0, 0, 0, 0, 0 }, // 234 MTMSRD
  { 1, 184, 185, 948, 950 }, // 235 MTSPR_MTSPR8
  { 1, 184, 185, 950, 953 }, // 236 DIVW_DIVWO_DIVWU_DIVWUO_MODSW
  { 1, 184, 185, 953, 956 }, // 237 DIVWE_DIVWEO_DIVWEU_DIVWEUO_MODSD_MODUD_MODUW
  { 1, 184, 185, 956, 959 }, // 238 DIVD_DIVDO_DIVDU_DIVDUO
  { 1, 184, 185, 959, 962 }, // 239 DIVDE_DIVDEO_DIVDEU_DIVDEUO
  { 1, 184, 185, 962, 965 }, // 240 DIVWO_rec_DIVWUO_rec_DIVWU_rec_DIVW_rec
  { 1, 184, 185, 965, 968 }, // 241 DIVD_rec_DIVDO_rec_DIVDU_rec_DIVDUO_rec
  { 1, 184, 185, 968, 971 }, // 242 DIVWE_rec_DIVWEO_rec_DIVWEU_rec_DIVWEUO_rec
  { 1, 184, 185, 971, 974 }, // 243 DIVDE_rec_DIVDEO_rec_DIVDEU_rec_DIVDEUO_rec
  { 1, 184, 185, 974, 977 }, // 244 MTCRF_MTCRF8
  { 1, 184, 185, 977, 980 }, // 245 ADDC8O_rec_ADDC8_rec_ADDCO_rec_ADDC_rec_SUBFC8O_rec_SUBFC8_rec_SUBFCO_rec_SUBFC_rec
  { 1, 185, 186, 980, 983 }, // 246 FABSD_rec_FABSS_rec_FNABSD_rec_FNABSS_rec_FCPSGND_rec_FCPSGNS_rec_FNEGD_rec_FNEGS_rec_FMR_rec
  { 1, 184, 185, 983, 986 }, // 247 MCRFS
  { 0, 0, 0, 0, 0 }, // 248 MTFSF_MTFSF_rec_MTFSFI_MTFSFI_rec
  { 0, 0, 0, 0, 0 }, // 249 MTFSFb
  { 1, 184, 185, 986, 989 }, // 250 RLDCL_rec_RLDCR_rec
  { 1, 184, 185, 989, 992 }, // 251 RLDICL_rec_RLDICR_rec_RLDICL_32_rec_RLDIMI_rec
  { 1, 184, 185, 992, 995 }, // 252 RLWIMI8_rec_RLWIMI_rec
  { 1, 184, 185, 995, 998 }, // 253 RLWINM8_rec_RLWINM_rec_RLWNM8_rec_RLWNM_rec_SLW8_rec_SLW_rec_SRW8_rec_SRW_rec
  { 1, 184, 185, 998, 1001 }, // 254 SRAWI_rec_SRAW_rec
  { 0, 0, 0, 0, 0 }, // 255 MFFS_MFFSCE_MFFSL_MFFS_rec
  { 1, 184, 185, 1001, 1003 }, // 256 MFCR_MFCR8
  { 1, 184, 185, 1003, 1006 }, // 257 EXTSWSLI_32_64_rec_SRADI_rec_EXTSWSLI_rec_RLDIC_rec
  { 1, 184, 185, 1006, 1009 }, // 258 SRAD_rec_SLD_rec_SRD_rec
  { 1, 185, 186, 1009, 1012 }, // 259 FDIV
  { 1, 185, 186, 1012, 1015 }, // 260 FDIV_rec
  { 1, 185, 186, 1015, 1018 }, // 261 XSSQRTDP
  { 1, 185, 186, 1018, 1021 }, // 262 FSQRT
  { 1, 185, 186, 1021, 1024 }, // 263 XVSQRTDP
  { 1, 185, 186, 1024, 1027 }, // 264 XVSQRTSP
  { 1, 185, 186, 1027, 1030 }, // 265 FSQRT_rec
  { 1, 185, 186, 1030, 1033 }, // 266 XSSQRTSP
  { 1, 185, 186, 1033, 1036 }, // 267 FSQRTS
  { 1, 185, 186, 1036, 1039 }, // 268 FSQRTS_rec
  { 1, 185, 186, 1039, 1042 }, // 269 XSDIVDP
  { 1, 185, 186, 1042, 1045 }, // 270 FDIVS
  { 1, 185, 186, 1045, 1048 }, // 271 FDIVS_rec
  { 1, 185, 186, 1048, 1051 }, // 272 XSDIVSP
  { 1, 185, 186, 1051, 1054 }, // 273 XVDIVSP
  { 1, 185, 186, 1054, 1057 }, // 274 XVDIVDP
  { 1, 184, 185, 1057, 1061 }, // 275 LFSU
  { 1, 184, 185, 1061, 1065 }, // 276 LFSUX
  { 1, 184, 185, 1065, 1069 }, // 277 STFDU_STFDUX_STFSU_STFSUX
  { 1, 184, 185, 1069, 1073 }, // 278 STBU_STBU8_STDU_STHU_STHU8_STWU_STWU8
  { 1, 184, 185, 1073, 1077 }, // 279 STBUX_STBUX8_STDUX_STHUX_STHUX8_STWUX_STWUX8
  { 1, 184, 185, 1077, 1081 }, // 280 LBZU_LBZU8
  { 1, 184, 185, 1081, 1085 }, // 281 LBZUX_LBZUX8
  { 1, 184, 185, 1085, 1088 }, // 282 LDU
  { 1, 184, 185, 1088, 1091 }, // 283 LDUX
  { 1, 184, 185, 1091, 1095 }, // 284 LFDU
  { 1, 184, 185, 1095, 1099 }, // 285 LFDUX
  { 0, 0, 0, 0, 0 }, // 286 VPMSUMB_VPMSUMD_VPMSUMH_VPMSUMW_VCIPHER_VCIPHERLAST_VNCIPHER_VNCIPHERLAST_VSBOX
  { 1, 184, 185, 1099, 1102 }, // 287 BCCCTR_BCCCTR8_BCCCTRL_BCCCTRL8_BCCL_BCCLA_BCCLR_BCCLRL_BCCTR_BCCTR8_BCCTR8n_BCCTRL_BCCTRL8_BCCTRL8n_BCCTRLn_BCCTRn_BDNZ_BDNZ8_BDNZA_BDNZAm_BDNZAp_BDNZm_BDNZp_BDZ_BDZ8_BDZA_BDZAm_BDZAp_BDZm_BDZp_BDNZL_BDNZLA_BDNZLAm_BDNZLAp_BDNZLR_BDNZLR8_BDNZLRL_BDNZLRLm_BDNZLRLp_BDNZLRm_BDNZLRp_BDNZLm_BDNZLp_BDZL_BDZLA_BDZLAm_BDZLAp_BDZLR_BDZLR8_BDZLRL_BDZLRLm_BDZLRLp_BDZLRm_BDZLRp_BDZLm_BDZLp_BL_BL_NOP_BL_TLS_BL8_BL8_NOP_BL8_NOP_TLS_BL8_TLS_BL8_TLS__BLA_BLA8_BLA8_NOP_BLR_BLR8_BLRL_TAILB_TAILB8_TAILBA_TAILBA8_TAILBCTR_TAILBCTR8_gBC_gBCA_gBCAat_gBCCTR_gBCCTRL_gBCL_gBCLA_gBCLAat_gBCLR_gBCLRL_gBCLat_gBCat_BCLR_BCLRL_BCLRLn_BCLRn_BCTR_BCTR8_BCTRL_BCTRL8_B_BA_BC_BCC_BCCA_BCL_BCLalways_BCLn_BCTRL8_LDinto_toc_BCTRL_LWZinto_toc_BCn_CTRL_DEP
  { 1, 184, 185, 1102, 1105 }, // 288 ADDPCIS
  { 1, 184, 185, 1105, 1108 }, // 289 LDAT_LWAT
  { 1, 184, 185, 1108, 1111 }, // 290 STDAT_STWAT
  { 1, 184, 185, 1111, 1114 }, // 291 BRINC
  { 0, 0, 0, 0, 0 }, // 292 EVABS_EVEQV_EVNAND_EVNEG_EVADDIW_EVADDW_EVAND_EVANDC_EVCMPEQ_EVCMPGTS_EVCMPGTU_EVCMPLTS_EVCMPLTU_EVCNTLSW_EVCNTLZW_EVEXTSB_EVEXTSH_EVMERGEHI_EVMERGEHILO_EVMERGELO_EVMERGELOHI_EVNOR_EVOR_EVORC_EVXOR_EVRLW_EVRLWI_EVRNDW_EVSLW_EVSLWI_EVSPLATFI_EVSPLATI_EVSRWIS_EVSRWIU_EVSRWS_EVSRWU_EVSUBFW_EVSUBIFW
  { 0, 0, 0, 0, 0 }, // 293 EVMRA_EVADDSMIAAW_EVADDSSIAAW_EVADDUMIAAW_EVADDUSIAAW_EVDIVWS_EVDIVWU_EVMHEGSMFAA_EVMHEGSMFAN_EVMHEGSMIAA_EVMHEGSMIAN_EVMHEGUMIAA_EVMHEGUMIAN_EVMHESMF_EVMHESMFA_EVMHESMFAAW_EVMHESMFANW_EVMHESMI_EVMHESMIA_EVMHESMIAAW_EVMHESMIANW_EVMHESSF_EVMHESSFA_EVMHESSFAAW_EVMHESSFANW_EVMHESSIAAW_EVMHESSIANW_EVMHEUMI_EVMHEUMIA_EVMHEUMIAAW_EVMHEUMIANW_EVMHEUSIAAW_EVMHEUSIANW_EVMHOGSMFAA_EVMHOGSMFAN_EVMHOGSMIAA_EVMHOGSMIAN_EVMHOGUMIAA_EVMHOGUMIAN_EVMHOSMF_EVMHOSMFA_EVMHOSMFAAW_EVMHOSMFANW_EVMHOSMI_EVMHOSMIA_EVMHOSMIAAW_EVMHOSMIANW_EVMHOSSF_EVMHOSSFA_EVMHOSSFAAW_EVMHOSSFANW_EVMHOSSIAAW_EVMHOSSIANW_EVMHOUMI_EVMHOUMIA_EVMHOUMIAAW_EVMHOUMIANW_EVMHOUSIAAW_EVMHOUSIANW_EVMWHSMF_EVMWHSMFA_EVMWHSMI_EVMWHSMIA_EVMWHSSF_EVMWHSSFA_EVMWHUMI_EVMWHUMIA_EVMWLSMIAAW_EVMWLSMIANW_EVMWLSSIAAW_EVMWLSSIANW_EVMWLUMI_EVMWLUMIA_EVMWLUMIAAW_EVMWLUMIANW_EVMWLUSIAAW_EVMWLUSIANW_EVMWSMF_EVMWSMFA_EVMWSMFAA_EVMWSMFAN_EVMWSMI_EVMWSMIA_EVMWSMIAA_EVMWSMIAN_EVMWSSF_EVMWSSFA_EVMWSSFAA_EVMWSSFAN_EVMWUMI_EVMWUMIA_EVMWUMIAA_EVMWUMIAN_EVSUBFSMIAAW_EVSUBFSSIAAW_EVSUBFUMIAAW_EVSUBFUSIAAW
  { 1, 184, 185, 1114, 1117 }, // 294 EVLDD_EVLDDX_EVLDH_EVLDHX_EVLDW_EVLDWX_EVLHHESPLAT_EVLHHESPLATX_EVLHHOSSPLAT_EVLHHOSSPLATX_EVLHHOUSPLAT_EVLHHOUSPLATX_EVLWHE_EVLWHEX_EVLWHOS_EVLWHOSX_EVLWHOU_EVLWHOUX_EVLWHSPLAT_EVLWHSPLATX_EVLWWSPLAT_EVLWWSPLATX
  { 1, 184, 185, 1117, 1120 }, // 295 EVSTDD_EVSTDDX_EVSTDH_EVSTDHX_EVSTDW_EVSTDWX_EVSTWHE_EVSTWHEX_EVSTWHO_EVSTWHOX_EVSTWWE_EVSTWWEX_EVSTWWO_EVSTWWOX
  { 1, 184, 185, 1120, 1123 }, // 296 HRFID_ATTN_CLRBHRB_MFBHRBE_NAP_RFCI_RFDI_RFMCI_SC
  { 1, 184, 185, 1123, 1124 }, // 297 RFI
  { 0, 0, 0, 0, 0 }, // 298 RFID
  { 1, 184, 185, 1124, 1127 }, // 299 DSS_DSSALL_DST_DST64_DSTST_DSTST64_DSTSTT_DSTSTT64_DSTT_DSTT64_ICBLQ_LBEPX_LHEPX_LWEPX_TLBIVAX_TLBLD_TLBLI_TLBRE_TLBRE2_TLBSX_TLBSX2_TLBSX2D_TLBWE_TLBWE2_MBAR_TRAP_DCCCI_ICCCI
  { 1, 184, 185, 1127, 1130 }, // 300 ICBLC_STBEPX_STHEPX_STWEPX
  { 1, 184, 185, 1130, 1133 }, // 301 LFDEPX
  { 1, 184, 185, 1133, 1136 }, // 302 STFDEPX
  { 0, 0, 0, 0, 0 }, // 303 MFSR_MFSRIN
  { 0, 0, 0, 0, 0 }, // 304 MTSR_MTSRIN
  { 1, 184, 185, 1136, 1138 }, // 305 MFDCR
  { 1, 184, 185, 1138, 1140 }, // 306 MTDCR
  { 1, 184, 185, 1140, 1143 }, // 307 NOP_GT_PWR6_NOP_GT_PWR7
  { 0, 0, 0, 0, 0 }, // 308 TLBIA
  { 1, 184, 185, 1143, 1145 }, // 309 WRTEE_WRTEEI
  { 1, 184, 185, 1145, 1146 }, // 310 MSYNC
  { 0, 0, 0, 0, 0 }, // 311 SLBSYNC
  { 0, 0, 0, 0, 0 }, // 312 SLBFEE_rec
  { 0, 0, 0, 0, 0 }, // 313 STOP
  { 1, 184, 185, 1146, 1149 }, // 314 DCBA_DCBI
  { 0, uint16_t(~0U), uint16_t(~0U), uint16_t(~0U), uint16_t(~0U) }// end marker
};

static const llvm::InstrItinerary PPCE200Z0Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 0, 0, 0, 0, 0 }, // 1 IIC_LdStSync
  { 1, 186, 190, 1149, 1153 }, // 2 IIC_IntSimple
  { 1, 186, 190, 1153, 1157 }, // 3 IIC_IntGeneral
  { 1, 190, 193, 1157, 1160 }, // 4 IIC_BrB
  { 0, 0, 0, 0, 0 }, // 5 IIC_VecFP
  { 1, 186, 190, 1160, 1164 }, // 6 IIC_IntCompare
  { 0, 0, 0, 0, 0 }, // 7 IIC_SprABORT
  { 0, 0, 0, 0, 0 }, // 8 IIC_LdStCOPY
  { 0, 0, 0, 0, 0 }, // 9 IIC_LdStPASTE
  { 1, 190, 193, 1164, 1168 }, // 10 IIC_BrCR
  { 0, 0, 0, 0, 0 }, // 11 IIC_LdStLD
  { 0, 0, 0, 0, 0 }, // 12 IIC_LdStDCBF
  { 1, 193, 197, 1168, 1172 }, // 13 IIC_LdStLoad
  { 0, 0, 0, 0, 0 }, // 14 IIC_IntDivD
  { 1, 197, 201, 1172, 1175 }, // 15 IIC_IntDivW
  { 0, 0, 0, 0, 0 }, // 16 IIC_FPDGeneral
  { 0, 0, 0, 0, 0 }, // 17 IIC_FPAddSub
  { 0, 0, 0, 0, 0 }, // 18 IIC_FPDivD
  { 0, 0, 0, 0, 0 }, // 19 IIC_FPSGeneral
  { 0, 0, 0, 0, 0 }, // 20 IIC_FPCompare
  { 0, 0, 0, 0, 0 }, // 21 IIC_FPGeneral
  { 0, 0, 0, 0, 0 }, // 22 IIC_VecGeneral
  { 0, 0, 0, 0, 0 }, // 23 IIC_VecComplex
  { 1, 201, 204, 1175, 1178 }, // 24 IIC_LdStStore
  { 0, 0, 0, 0, 0 }, // 25 IIC_IntRotateDI
  { 0, 0, 0, 0, 0 }, // 26 IIC_FPDivS
  { 0, 0, 0, 0, 0 }, // 27 IIC_FPFused
  { 0, 0, 0, 0, 0 }, // 28 IIC_FPSqrtD
  { 0, 0, 0, 0, 0 }, // 29 IIC_FPSqrtS
  { 0, 0, 0, 0, 0 }, // 30 IIC_LdStICBI
  { 1, 186, 190, 1178, 1182 }, // 31 IIC_IntISEL
  { 0, 0, 0, 0, 0 }, // 32 IIC_SprISYNC
  { 0, 0, 0, 0, 0 }, // 33 IIC_LdStLWARX
  { 2, 204, 209, 1182, 1187 }, // 34 IIC_LdStLoadUpd
  { 2, 209, 214, 1187, 1192 }, // 35 IIC_LdStLoadUpdX
  { 0, 0, 0, 0, 0 }, // 36 IIC_LdStLDARX
  { 0, 0, 0, 0, 0 }, // 37 IIC_LdStLDU
  { 0, 0, 0, 0, 0 }, // 38 IIC_LdStLDUX
  { 0, 0, 0, 0, 0 }, // 39 IIC_LdStLFD
  { 0, 0, 0, 0, 0 }, // 40 IIC_LdStLFDU
  { 0, 0, 0, 0, 0 }, // 41 IIC_LdStLFDUX
  { 0, 0, 0, 0, 0 }, // 42 IIC_LdStLHA
  { 0, 0, 0, 0, 0 }, // 43 IIC_LdStLHAU
  { 0, 0, 0, 0, 0 }, // 44 IIC_LdStLHAUX
  { 0, 0, 0, 0, 0 }, // 45 IIC_LdStLMW
  { 0, 0, 0, 0, 0 }, // 46 IIC_LdStLWA
  { 0, 0, 0, 0, 0 }, // 47 IIC_IntMulHD
  { 1, 190, 193, 1192, 1195 }, // 48 IIC_BrMCR
  { 1, 214, 217, 1195, 1199 }, // 49 IIC_BrMCRX
  { 0, 0, 0, 0, 0 }, // 50 IIC_SprMFCR
  { 1, 186, 190, 1199, 1203 }, // 51 IIC_SprMFSPR
  { 0, 0, 0, 0, 0 }, // 52 IIC_IntMFFS
  { 0, 0, 0, 0, 0 }, // 53 IIC_SprMFMSR
  { 0, 0, 0, 0, 0 }, // 54 IIC_SprMFCRF
  { 0, 0, 0, 0, 0 }, // 55 IIC_SprMFPMR
  { 0, 0, 0, 0, 0 }, // 56 IIC_SprMFSR
  { 0, 0, 0, 0, 0 }, // 57 IIC_SprMFTB
  { 0, 0, 0, 0, 0 }, // 58 IIC_SprMSGSYNC
  { 1, 186, 190, 1203, 1207 }, // 59 IIC_SprMTSPR
  { 0, 0, 0, 0, 0 }, // 60 IIC_IntMTFSB0
  { 0, 0, 0, 0, 0 }, // 61 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 62 IIC_SprMTMSRD
  { 0, 0, 0, 0, 0 }, // 63 IIC_SprMTPMR
  { 0, 0, 0, 0, 0 }, // 64 IIC_SprMTSR
  { 1, 217, 222, 1207, 1212 }, // 65 IIC_IntMulHW
  { 1, 217, 222, 1212, 1217 }, // 66 IIC_IntMulHWU
  { 1, 222, 227, 1217, 1222 }, // 67 IIC_IntMulLI
  { 0, 0, 0, 0, 0 }, // 68 IIC_VecPerm
  { 0, 0, 0, 0, 0 }, // 69 IIC_LdStSTFD
  { 0, 0, 0, 0, 0 }, // 70 IIC_LdStSTFDU
  { 0, 0, 0, 0, 0 }, // 71 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 72 IIC_IntRFID
  { 0, 0, 0, 0, 0 }, // 73 IIC_IntRotateD
  { 1, 186, 190, 1222, 1226 }, // 74 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 75 IIC_SprSLBFEE
  { 0, 0, 0, 0, 0 }, // 76 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 77 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprSLBIEG
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprSLBMFEV
  { 0, 0, 0, 0, 0 }, // 81 IIC_SprSLBMTE
  { 0, 0, 0, 0, 0 }, // 82 IIC_SprSLBSYNC
  { 1, 186, 190, 1226, 1230 }, // 83 IIC_IntShift
  { 0, 0, 0, 0, 0 }, // 84 IIC_LdStSTWCX
  { 2, 227, 231, 1230, 1234 }, // 85 IIC_LdStSTU
  { 2, 227, 231, 1234, 1238 }, // 86 IIC_LdStSTUX
  { 0, 0, 0, 0, 0 }, // 87 IIC_LdStSTD
  { 0, 0, 0, 0, 0 }, // 88 IIC_LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 89 IIC_SprSTOP
  { 0, 0, 0, 0, 0 }, // 90 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 91 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 92 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 93 IIC_SprTLBIEL
  { 0, 0, 0, 0, 0 }, // 94 IIC_SprTLBSYNC
  { 1, 231, 235, 1238, 1241 }, // 95 IIC_IntTrapW
  { 0, 0, 0, 0, 0 }, // 96 IIC_VecFPCompare
  { 0, 0, 0, 0, 0 }, // 97 VADDUBM_VADDUDM_VADDUHM_VADDUWM_VEXTSB2D_VEXTSB2Ds_VEXTSB2W_VEXTSB2Ws_VEXTSH2D_VEXTSH2Ds_VEXTSH2W_VEXTSH2Ws_VEXTSW2D_VEXTSW2Ds_VSLD_VSRD_VSUBUBM_VSUBUDM_VSUBUHM_VSUBUWM_VPOPCNTB_VPOPCNTH_VSRAD_MTVSRDD_VEQV_VNAND_VNEGD_VNEGW_VORC_XXLAND_XXLANDC_XXLEQV_XXLEQVOnes_XXLNAND_XXLNOR_XXLOR_XXLORf_XXLORC_XXLXOR_XXLXORdpz_XXLXORspz_XXLXORz
  { 0, 0, 0, 0, 0 }, // 98 VAND_VANDC_V_SET0_V_SET0B_V_SET0H_VSLB_VSLH_VSLW_VSRB_VSRH_VSRW_VRLB_VRLD_VRLH_VRLW_VSRAB_VSRAH_VSRAW_XVABSDP_XVABSSP_XVNABSDP_XVNABSSP_XVCPSGNDP_XVCPSGNSP_XVIEXPDP_XVIEXPSP_XVXEXPDP_XVXEXPSP_VRLDMI_VRLDNM_VRLWMI_VRLWNM_VMRGEW_VMRGOW_VNOR_VOR_VSEL_VXOR_XVNEGDP_XVNEGSP_XSABSQP_XSCPSGNQP_XSIEXPQP_XSNABSQP_XSNEGQP_XSXEXPQP
  { 0, 0, 0, 0, 0 }, // 99 XXSEL
  { 1, 186, 190, 1241, 1245 }, // 100 TABORTDC_TABORTDCI_TABORTWC_TABORTWCI
  { 0, 0, 0, 0, 0 }, // 101 MTFSB0_MTFSB1
  { 0, 0, 0, 0, 0 }, // 102 MFFSCDRN_MFFSCDRNI_MFFSCRN_MFFSCRNI
  { 1, 186, 190, 1245, 1249 }, // 103 CMPRB_CMPRB8_CMPEQB
  { 0, 0, 0, 0, 0 }, // 104 TD_TDI
  { 1, 231, 235, 1249, 1252 }, // 105 TW_TWI
  { 0, 0, 0, 0, 0 }, // 106 FCMPUD_FCMPUS_FTDIV_FTSQRT
  { 0, 0, 0, 0, 0 }, // 107 XSTSTDCDP_XSTSTDCSP
  { 0, 0, 0, 0, 0 }, // 108 XSMAXCDP_XSMAXDP_XSMAXJDP_XSMINCDP_XSMINDP_XSMINJDP_XSXSIGDP_XSCVSPDPN
  { 0, 0, 0, 0, 0 }, // 109 XSCMPEQDP_XSCMPEXPDP_XSCMPGEDP_XSCMPGTDP_XSCMPODP_XSCMPUDP_XSTDIVDP_XSTSQRTDP
  { 1, 186, 190, 1252, 1256 }, // 110 CNTLZD_CNTLZD_rec_CNTLZW_CNTLZW8_CNTLZW8_rec_CNTLZW_rec_CNTTZD_CNTTZD_rec_CNTTZW_CNTTZW8_CNTTZW8_rec_CNTTZW_rec_POPCNTD_POPCNTW_CMPB_CMPB8_SETB_SETB8_BPERMD
  { 0, 0, 0, 0, 0 }, // 111 SLD_SRD_SRAD
  { 0, 0, 0, 0, 0 }, // 112 SRADI_EXTSWSLI_32_64_EXTSWSLI_SRADI_32_RLDIC
  { 0, 0, 0, 0, 0 }, // 113 MFVRD_MFVSRD_MTVRD_MTVSRD_MTVRWA_MTVRWZ_MTVSRWA_MTVSRWZ_MFVSRWZ_MFVRWZ
  { 1, 186, 190, 1256, 1260 }, // 114 CMPLW_CMPLWI_CMPW_CMPWI_CMPD_CMPDI_CMPLD_CMPLDI
  { 1, 186, 190, 1260, 1264 }, // 115 SUBFC_SUBFC8_SUBFC8O_SUBFCO_SUBFIC_SUBFIC8_ANDI8_rec_ANDIS8_rec_ANDIS_rec_ANDI_rec_ADDC_ADDC8_ADDC8O_ADDCO_ADDIC_ADDIC8_ADDIC_rec_ADDE_ADDE8_ADDE8O_ADDE8O_rec_ADDE8_rec_ADDEO_ADDEO_rec_ADDE_rec_ADDME_ADDME8_ADDME8O_ADDME8O_rec_ADDME8_rec_ADDMEO_ADDMEO_rec_ADDME_rec_ADDZE_ADDZE8_ADDZE8O_ADDZE8O_rec_ADDZE8_rec_ADDZEO_ADDZEO_rec_ADDZE_rec_SUBF_SUBF8_SUBF8O_SUBF8O_rec_SUBF8_rec_SUBFE_SUBFE8_SUBFE8O_SUBFE8O_rec_SUBFE8_rec_SUBFEO_SUBFEO_rec_SUBFE_rec_SUBFME_SUBFME8_SUBFME8O_SUBFME8O_rec_SUBFME8_rec_SUBFMEO_SUBFMEO_rec_SUBFME_rec_SUBFO_SUBFO_rec_SUBFZE_SUBFZE8_SUBFZE8O_SUBFZE8O_rec_SUBFZE8_rec_SUBFZEO_SUBFZEO_rec_SUBFZE_rec_SUBF_rec_POPCNTB_LA
  { 1, 186, 190, 1264, 1268 }, // 116 ADD4_ADD4O_ADD4O_rec_ADD4_rec_ADD8_ADD8O_ADD8O_rec_ADD8_rec_NEG_NEG8_NEG8O_NEG8O_rec_NEG8_rec_NEGO_NEGO_rec_NEG_rec_ADDI_ADDI8_ADDIS_ADDIS8_LI_LI8_LIS_LIS8_OR_OR8_OR8_rec_ORI_ORI8_ORIS_ORIS8_OR_rec_XOR_XOR8_XOR8_rec_XORI_XORI8_XORIS_XORIS8_XOR_rec_NAND_NAND8_NAND8_rec_NAND_rec_AND_AND8_AND8_rec_ANDC_ANDC8_ANDC8_rec_ANDC_rec_AND_rec_NOR_NOR8_NOR8_rec_NOR_rec_ORC_ORC8_ORC8_rec_ORC_rec_EQV_EQV8_EQV8_rec_EQV_rec_EXTSB_EXTSB8_EXTSB8_32_64_EXTSB8_rec_EXTSB_rec_EXTSH_EXTSH8_EXTSH8_32_64_EXTSH8_rec_EXTSH_rec_EXTSW_EXTSW_32_EXTSW_32_64_EXTSW_32_64_rec_EXTSW_rec_ADD4TLS_ADD8TLS_ADD8TLS__NOP
  { 0, 0, 0, 0, 0 }, // 117 ADDIStocHA_ADDIStocHA8_ADDItocL_COPY
  { 1, 190, 193, 1268, 1271 }, // 118 MCRF
  { 1, 214, 217, 1271, 1275 }, // 119 MCRXRX
  { 0, 0, 0, 0, 0 }, // 120 XSNABSDP_XSXEXPDP_XSABSDP_XSNEGDP_XSCPSGNDP
  { 1, 190, 193, 1275, 1278 }, // 121 RFEBB
  { 1, 186, 190, 1278, 1282 }, // 122 TBEGIN_TRECHKPT
  { 1, 193, 197, 1282, 1286 }, // 123 WAIT
  { 0, 0, 0, 0, 0 }, // 124 RLDCL_RLDCR
  { 1, 186, 190, 1286, 1290 }, // 125 RLWIMI_RLWIMI8
  { 0, 0, 0, 0, 0 }, // 126 RLDICL_RLDICL_32_RLDICL_32_64_RLDICR_RLDICR_32_RLDIMI
  { 0, 0, 0, 0, 0 }, // 127 MFOCRF_MFOCRF8
  { 1, 214, 217, 1290, 1294 }, // 128 MTOCRF_MTOCRF8
  { 1, 190, 193, 1294, 1298 }, // 129 CR6SET_CR6UNSET_CRSET_CRUNSET_CRAND_CRANDC_CRNAND_CRNOR_CROR_CRORC_CREQV_CRXOR
  { 1, 186, 190, 1298, 1302 }, // 130 SLW_SLW8_SRW_SRW8_RLWINM_RLWINM8_RLWNM_RLWNM8
  { 0, 0, 0, 0, 0 }, // 131 FABSD_FABSS_FNABSD_FNABSS_FNEGD_FNEGS_FCPSGND_FCPSGNS_FMR
  { 1, 186, 190, 1302, 1306 }, // 132 SRAW_SRAWI
  { 1, 186, 190, 1306, 1310 }, // 133 ISEL_ISEL8
  { 0, 0, 0, 0, 0 }, // 134 XSIEXPDP
  { 1, 186, 190, 1310, 1314 }, // 135 TRECLAIM_TSR_TABORT
  { 1, 201, 204, 1314, 1317 }, // 136 MFVSCR
  { 1, 193, 197, 1317, 1321 }, // 137 MTVSCR
  { 0, 0, 0, 0, 0 }, // 138 VCMPNEZB_VCMPNEZH_VCMPNEZW_VCMPEQUB_VCMPEQUD_VCMPEQUH_VCMPEQUW_VCMPNEB_VCMPNEH_VCMPNEW_VCMPEQFP_VCMPEQFP_rec_VCMPGEFP_VCMPGEFP_rec_VCMPGTFP_VCMPGTFP_rec_VCMPBFP_VCMPBFP_rec_VCMPGTSB_VCMPGTSB_rec_VCMPGTSD_VCMPGTSD_rec_VCMPGTSH_VCMPGTSH_rec_VCMPGTSW_VCMPGTSW_rec_VCMPGTUB_VCMPGTUB_rec_VCMPGTUD_VCMPGTUD_rec_VCMPGTUH_VCMPGTUH_rec_VCMPGTUW_VCMPGTUW_rec_VCMPNEB_rec_VCMPNEH_rec_VCMPNEW_rec_VCMPNEZB_rec_VCMPNEZH_rec_VCMPNEZW_rec_VCMPEQUB_rec_VCMPEQUD_rec_VCMPEQUH_rec_VCMPEQUW_rec_XVCMPEQDP_XVCMPEQDP_rec_XVCMPEQSP_XVCMPEQSP_rec_XVCMPGEDP_XVCMPGEDP_rec_XVCMPGESP_XVCMPGESP_rec_XVCMPGTDP_XVCMPGTDP_rec_XVCMPGTSP_XVCMPGTSP_rec
  { 0, 0, 0, 0, 0 }, // 139 VABSDUB_VABSDUH_VABSDUW_VCLZB_VCLZD_VCLZH_VCLZW_VCTZB_VCTZD_VCTZH_VCTZW_VPOPCNTW_VPOPCNTD_VPRTYBD_VPRTYBW
  { 0, 0, 0, 0, 0 }, // 140 VADDUBS_VADDUHS_VADDUWS_VAVGSB_VAVGSH_VAVGSW_VAVGUB_VAVGUH_VAVGUW_VADDSBS_VADDSHS_VADDSWS_VMAXFP_VMINFP_VMAXSB_VMAXSD_VMAXSH_VMAXSW_VMAXUB_VMAXUD_VMAXUH_VMAXUW_VMINSB_VMINSD_VMINSH_VMINSW_VMINUB_VMINUD_VMINUH_VMINUW_VBPERMD_VADDCUW_VSHASIGMAD_VSHASIGMAW_VSUBSBS_VSUBSHS_VSUBSWS_VSUBUBS_VSUBUHS_VSUBUWS_VSUBCUW_XVMAXDP_XVMAXSP_XVMINDP_XVMINSP_XVTSTDCDP_XVTSTDCSP_XVXSIGDP_XVXSIGSP
  { 0, 0, 0, 0, 0 }, // 141 XVTDIVDP_XVTDIVSP_XVTSQRTDP_XVTSQRTSP
  { 0, 0, 0, 0, 0 }, // 142 VADDFP_VCTSXS_VCTSXS_0_VCTUXS_VCTUXS_0_VEXPTEFP_VLOGEFP_VMADDFP_VMHADDSHS_VNMSUBFP_VREFP_VRFIM_VRFIN_VRFIP_VRFIZ_VRSQRTEFP_XVADDDP_XVADDSP_XVCVDPSP_XVCVDPSXDS_XVCVDPSXWS_XVCVDPUXDS_XVCVDPUXWS_XVCVHPSP_XVCVSPDP_XVCVSPHP_XVCVSPSXDS_XVCVSPSXWS_XVCVSPUXDS_XVCVSPUXWS_XVCVSXDDP_XVCVSXDSP_XVCVSXWDP_XVCVSXWSP_XVCVUXDDP_XVCVUXDSP_XVCVUXWDP_XVCVUXWSP_XVMADDADP_XVMADDASP_XVMADDMDP_XVMADDMSP_XVMSUBADP_XVMSUBASP_XVMSUBMDP_XVMSUBMSP_XVMULDP_XVMULSP_XVNMADDADP_XVNMADDASP_XVNMADDMDP_XVNMADDMSP_XVNMSUBADP_XVNMSUBASP_XVNMSUBMDP_XVNMSUBMSP_XVRDPI_XVRDPIC_XVRDPIM_XVRDPIP_XVRDPIZ_XVREDP_XVRESP_XVRSPI_XVRSPIC_XVRSPIM_XVRSPIP_XVRSPIZ_XVRSQRTEDP_XVRSQRTESP_XVSUBDP_XVSUBSP_VCFSX_VCFSX_0_VCFUX_VCFUX_0_VMHRADDSHS_VMLADDUHM_VMSUMMBM_VMSUMSHM_VMSUMSHS_VMSUMUBM_VMSUMUHM_VMSUMUDM_VMSUMUHS_VMULESB_VMULESH_VMULESW_VMULEUB_VMULEUH_VMULEUW_VMULOSB_VMULOSH_VMULOSW_VMULOUB_VMULOUH_VMULOUW_VSUM2SWS_VSUM4SBS_VSUM4SHS_VSUM4UBS_VSUMSWS
  { 0, 0, 0, 0, 0 }, // 143 VSUBFP_VMULUWM
  { 0, 0, 0, 0, 0 }, // 144 MADDHD_MADDHDU_MADDLD_MADDLD8_MULLD_MULLDO
  { 1, 217, 222, 1321, 1326 }, // 145 MULHD_MULHW_MULLW_MULLWO
  { 1, 217, 222, 1326, 1331 }, // 146 MULHDU_MULHWU
  { 1, 222, 227, 1331, 1336 }, // 147 MULLI_MULLI8
  { 0, 0, 0, 0, 0 }, // 148 FRSP_FRIMD_FRIMS_FRIND_FRINS_FRIPD_FRIPS_FRIZD_FRIZS_FRE_FRES_FADDS_FMSUBS_FMADDS_FSUBS_FCFID_FCFIDS_FCFIDU_FCFIDUS_FCTID_FCTIDU_FCTIDUZ_FCTIDZ_FCTIW_FCTIWU_FCTIWUZ_FCTIWZ_FRSQRTE_FRSQRTES_FNMADDS_FNMSUBS_FSELD_FSELS_FMULS
  { 0, 0, 0, 0, 0 }, // 149 FADD_FSUB
  { 0, 0, 0, 0, 0 }, // 150 FMSUB_FMADD_FNMADD_FNMSUB_FMUL
  { 0, 0, 0, 0, 0 }, // 151 XSMADDADP_XSMADDASP_XSMADDMDP_XSMADDMSP_XSMSUBADP_XSMSUBASP_XSMSUBMDP_XSMSUBMSP_XSMULDP_XSMULSP_XSNMADDADP_XSNMADDASP_XSNMADDMDP_XSNMADDMSP_XSNMSUBADP_XSNMSUBASP_XSNMSUBMDP_XSNMSUBMSP
  { 0, 0, 0, 0, 0 }, // 152 FSELD_rec_FSELS_rec
  { 1, 217, 222, 1336, 1341 }, // 153 MULHDU_rec_MULHWU_rec
  { 1, 217, 222, 1341, 1346 }, // 154 MULHD_rec_MULHW_rec_MULLWO_rec_MULLW_rec
  { 0, 0, 0, 0, 0 }, // 155 MULLDO_rec_MULLD_rec
  { 0, 0, 0, 0, 0 }, // 156 FRIMD_rec_FRIMS_rec_FRIND_rec_FRINS_rec_FRIPD_rec_FRIPS_rec_FRIZD_rec_FRIZS_rec_FRES_rec_FRE_rec_FADDS_rec_FSUBS_rec_FMSUBS_rec_FNMSUBS_rec_FMADDS_rec_FNMADDS_rec_FCFIDS_rec_FCFIDUS_rec_FCFIDU_rec_FCFID_rec_FCTIDUZ_rec_FCTIDU_rec_FCTIDZ_rec_FCTID_rec_FCTIWUZ_rec_FCTIWU_rec_FCTIWZ_rec_FCTIW_rec_FMULS_rec_FRSQRTES_rec_FRSQRTE_rec_FRSP_rec
  { 0, 0, 0, 0, 0 }, // 157 FADD_rec_FSUB_rec
  { 0, 0, 0, 0, 0 }, // 158 FMSUB_rec_FNMSUB_rec_FMADD_rec_FNMADD_rec_FMUL_rec
  { 0, 0, 0, 0, 0 }, // 159 XSADDDP_XSADDSP_XSCVDPHP_XSCVDPSP_XSCVDPSXDS_XSCVDPSXDSs_XSCVDPSXWS_XSCVDPUXDS_XSCVDPUXDSs_XSCVDPUXWS_XSCVDPSXWSs_XSCVDPUXWSs_XSCVHPDP_XSCVSPDP_XSCVSXDDP_XSCVSXDSP_XSCVUXDDP_XSCVUXDSP_XSRDPI_XSRDPIC_XSRDPIM_XSRDPIP_XSRDPIZ_XSREDP_XSRESP_XSRSQRTEDP_XSRSQRTESP_XSSUBDP_XSSUBSP_XSCVDPSPN_XSRSP
  { 1, 193, 197, 1346, 1350 }, // 160 LVSL_LVSR
  { 0, 0, 0, 0, 0 }, // 161 VSPLTISB_VSPLTISH_VSPLTISW_VSPLTB_VSPLTBs_VSPLTH_VSPLTHs_VSPLTW_XXMRGHW_XXMRGLW_XXPERM_XXPERMR_XXSLDWI_XXSLDWIs_XXSPLTIB_XXSPLTW_XXSPLTWs_XXPERMDI_XXPERMDIs
  { 0, 0, 0, 0, 0 }, // 162 V_SETALLONES_V_SETALLONESB_V_SETALLONESH_VBPERMQ_VGBBD_VMRGHB_VMRGHH_VMRGHW_VMRGLB_VMRGLH_VMRGLW_VPERM_VPERMR_VPERMXOR_VPKPX_VPKSDSS_VPKSDUS_VPKSHSS_VPKSHUS_VPKSWSS_VPKSWUS_VPKUDUM_VPKUDUS_VPKUHUM_VPKUHUS_VPKUWUM_VPKUWUS_VSL_VSLDOI_VSLO_VSLV_VSR_VSRO_VSRV_VUPKHPX_VUPKHSB_VUPKHSH_VUPKHSW_VUPKLPX_VUPKLSB_VUPKLSH_VUPKLSW_XXBRD_XXBRH_XXBRQ_XXBRW_XXEXTRACTUW_XXINSERTW_VADDCUQ_VADDECUQ_VADDEUQM_VMUL10CUQ_VMUL10ECUQ_VMUL10EUQ_VMUL10UQ_VSUBCUQ_VSUBECUQ_VSUBEUQM_XSTSTDCQP_XSXSIGQP_BCDCFN_rec_BCDCFZ_rec_BCDCPSGN_rec_BCDCTN_rec_BCDCTZ_rec_BCDSETSGN_rec_BCDS_rec_BCDTRUNC_rec_BCDUS_rec_BCDUTRUNC_rec
  { 0, 0, 0, 0, 0 }, // 163 VEXTRACTUB_VEXTRACTUH_VEXTRACTUW_VINSERTB_VINSERTD_VINSERTH_VINSERTW_MFVSRLD_MTVSRWS_VCLZLSBB_VCTZLSBB_VEXTRACTD_VEXTUBLX_VEXTUBRX_VEXTUHLX_VEXTUHRX_VEXTUWLX_VEXTUWRX_VPRTYBQ_VADDUQM_VSUBUQM
  { 0, 0, 0, 0, 0 }, // 164 XSCMPEXPQP_XSCMPOQP_XSCMPUQP
  { 0, 0, 0, 0, 0 }, // 165 BCDSR_rec_XSADDQP_XSADDQPO_XSCVDPQP_XSCVQPDP_XSCVQPDPO_XSCVQPSDZ_XSCVQPSWZ_XSCVQPUDZ_XSCVQPUWZ_XSCVSDQP_XSCVUDQP_XSRQPI_XSRQPIX_XSRQPXP_XSSUBQP_XSSUBQPO
  { 0, 0, 0, 0, 0 }, // 166 BCDCTSQ_rec
  { 0, 0, 0, 0, 0 }, // 167 XSMADDQP_XSMADDQPO_XSMSUBQP_XSMSUBQPO_XSMULQP_XSMULQPO_XSNMADDQP_XSNMADDQPO_XSNMSUBQP_XSNMSUBQPO
  { 0, 0, 0, 0, 0 }, // 168 BCDCFSQ_rec
  { 0, 0, 0, 0, 0 }, // 169 XSDIVQP_XSDIVQPO
  { 0, 0, 0, 0, 0 }, // 170 XSSQRTQP_XSSQRTQPO
  { 1, 193, 197, 1350, 1354 }, // 171 LXVL_LXVLL
  { 1, 193, 197, 1354, 1358 }, // 172 LVEBX_LVEHX_LVEWX_LVX_LVXL
  { 0, 0, 0, 0, 0 }, // 173 LXSIBZX_LXSIHZX_LXSDX_LXVB16X_LXVD2X_LXVWSX_LXSIWZX_LXV_LXVX_LXSD
  { 0, 0, 0, 0, 0 }, // 174 DFLOADf64_XFLOADf64_LIWZX
  { 0, 0, 0, 0, 0 }, // 175 DCBF_DCBFEP_DCBST_DCBSTEP_DCBT_DCBTEP_DCBZ_DCBZEP_DCBZL_DCBZLEP_DCBTST_DCBTSTEP
  { 0, 0, 0, 0, 0 }, // 176 CP_COPY_CP_COPY8
  { 0, 0, 0, 0, 0 }, // 177 CP_PASTE_CP_PASTE8
  { 0, 0, 0, 0, 0 }, // 178 ICBI_ICBIEP
  { 1, 193, 197, 1358, 1362 }, // 179 ICBT_ICBTLS_LBZ_LBZ8_LBZCIX_LBZX_LBZX8_LBZXTLS_LBZXTLS__LBZXTLS_32_LDBRX_LDCIX_LHBRX_LHBRX8_LHZ_LHZ8_LHZCIX_LHZX_LHZX8_LHZXTLS_LHZXTLS__LHZXTLS_32_LWBRX_LWBRX8_LWZ_LWZ8_LWZCIX_LWZX_LWZX8_LWZXTLS_LWZXTLS__LWZXTLS_32_EnforceIEIO_LSWI
  { 0, 0, 0, 0, 0 }, // 180 LBARX_LBARXL_LHARX_LHARXL_LWARX_LWARXL
  { 0, 0, 0, 0, 0 }, // 181 LD_LDX_LDXTLS_LDXTLS__DARN
  { 0, 0, 0, 0, 0 }, // 182 LDARX_LDARXL
  { 0, 0, 0, 0, 0 }, // 183 CP_ABORT
  { 0, 0, 0, 0, 0 }, // 184 ISYNC
  { 0, 0, 0, 0, 0 }, // 185 MSGSYNC
  { 0, 0, 0, 0, 0 }, // 186 TLBSYNC
  { 0, 0, 0, 0, 0 }, // 187 SYNC
  { 0, 0, 0, 0, 0 }, // 188 LMW
  { 0, 0, 0, 0, 0 }, // 189 LFIWZX_LFDX_LFD
  { 0, 0, 0, 0, 0 }, // 190 SLBIA
  { 0, 0, 0, 0, 0 }, // 191 SLBIE
  { 0, 0, 0, 0, 0 }, // 192 SLBMFEE
  { 0, 0, 0, 0, 0 }, // 193 SLBMFEV
  { 0, 0, 0, 0, 0 }, // 194 SLBMTE
  { 0, 0, 0, 0, 0 }, // 195 TLBIEL
  { 2, 204, 209, 1362, 1367 }, // 196 LHZU_LHZU8_LWZU_LWZU8
  { 2, 209, 214, 1367, 1372 }, // 197 LHZUX_LHZUX8_LWZUX_LWZUX8
  { 1, 186, 190, 1372, 1376 }, // 198 TEND
  { 0, 0, 0, 0, 0 }, // 199 STBCX_STHCX_STWCX
  { 0, 0, 0, 0, 0 }, // 200 STDCX
  { 0, 0, 0, 0, 0 }, // 201 LDMX
  { 0, 0, 0, 0, 0 }, // 202 LHA_LHA8_LHAX_LHAX8_LWAX_LWAX_32
  { 0, 0, 0, 0, 0 }, // 203 CP_PASTE8_rec_CP_PASTE_rec
  { 0, 0, 0, 0, 0 }, // 204 LWA_LWA_32
  { 1, 186, 190, 1376, 1380 }, // 205 TCHECK
  { 0, 0, 0, 0, 0 }, // 206 LFIWAX
  { 0, 0, 0, 0, 0 }, // 207 LXSIWAX
  { 0, 0, 0, 0, 0 }, // 208 LIWAX
  { 0, 0, 0, 0, 0 }, // 209 LFSX_LFS
  { 0, 0, 0, 0, 0 }, // 210 LXSSP_LXSSPX
  { 0, 0, 0, 0, 0 }, // 211 XFLOADf32_DFLOADf32
  { 0, 0, 0, 0, 0 }, // 212 LHAU_LHAU8
  { 0, 0, 0, 0, 0 }, // 213 LHAUX_LHAUX8_LWAUX
  { 0, 0, 0, 0, 0 }, // 214 LXVH8X_LXVDSX_LXVW4X
  { 0, 0, 0, 0, 0 }, // 215 STFD_STFDX_STFIWX_STFS_STFSX_STXSD_STXSDX_STXSIBX_STXSIBXv_STXSIHX_STXSIHXv_STXSIWX_STXSSP_STXSSPX
  { 1, 201, 204, 1380, 1383 }, // 216 STW_STW8_STDBRX_STHBRX_STWBRX_STB_STB8_STH_STH8_STBX_STBX8_STBXTLS_STBXTLS__STBXTLS_32_STHX_STHX8_STHXTLS_STHXTLS__STHXTLS_32_STWX_STWX8_STWXTLS_STWXTLS__STWXTLS_32
  { 0, 0, 0, 0, 0 }, // 217 DFSTOREf32_DFSTOREf64_XFSTOREf32_XFSTOREf64_STIWX
  { 0, 0, 0, 0, 0 }, // 218 STD_STDX_STDXTLS_STDXTLS_
  { 1, 193, 197, 1383, 1387 }, // 219 STBCIX_STDCIX_STHCIX_STWCIX_STSWI
  { 0, 0, 0, 0, 0 }, // 220 SLBIEG
  { 0, 0, 0, 0, 0 }, // 221 STMW
  { 0, 0, 0, 0, 0 }, // 222 TLBIE
  { 1, 201, 204, 1387, 1390 }, // 223 STVEBX_STVEHX_STVEWX_STVX_STVXL
  { 0, 0, 0, 0, 0 }, // 224 STXV_STXVB16X_STXVD2X_STXVH8X_STXVW4X_STXVX
  { 1, 193, 197, 1390, 1394 }, // 225 STXVL_STXVLL
  { 1, 186, 190, 1394, 1398 }, // 226 MTCTR_MTCTR8_MTCTR8loop_MTCTRloop_MTLR_MTLR8
  { 1, 186, 190, 1398, 1402 }, // 227 MFVRSAVE_MFVRSAVEv_MTVRSAVE_MTVRSAVEv
  { 0, 0, 0, 0, 0 }, // 228 MFPMR
  { 0, 0, 0, 0, 0 }, // 229 MTPMR
  { 0, 0, 0, 0, 0 }, // 230 MFTB_MFTB8
  { 1, 186, 190, 1402, 1406 }, // 231 MFCTR_MFCTR8_MFLR_MFLR8_MFSPR_MFSPR8
  { 0, 0, 0, 0, 0 }, // 232 MFMSR
  { 0, 0, 0, 0, 0 }, // 233 MTMSR
  { 0, 0, 0, 0, 0 }, // 234 MTMSRD
  { 1, 186, 190, 1406, 1410 }, // 235 MTSPR_MTSPR8
  { 1, 197, 201, 1410, 1413 }, // 236 DIVW_DIVWO_DIVWU_DIVWUO_MODSW
  { 1, 197, 201, 1413, 1416 }, // 237 DIVWE_DIVWEO_DIVWEU_DIVWEUO_MODSD_MODUD_MODUW
  { 0, 0, 0, 0, 0 }, // 238 DIVD_DIVDO_DIVDU_DIVDUO
  { 0, 0, 0, 0, 0 }, // 239 DIVDE_DIVDEO_DIVDEU_DIVDEUO
  { 1, 197, 201, 1416, 1419 }, // 240 DIVWO_rec_DIVWUO_rec_DIVWU_rec_DIVW_rec
  { 0, 0, 0, 0, 0 }, // 241 DIVD_rec_DIVDO_rec_DIVDU_rec_DIVDUO_rec
  { 1, 197, 201, 1419, 1422 }, // 242 DIVWE_rec_DIVWEO_rec_DIVWEU_rec_DIVWEUO_rec
  { 0, 0, 0, 0, 0 }, // 243 DIVDE_rec_DIVDEO_rec_DIVDEU_rec_DIVDEUO_rec
  { 1, 214, 217, 1422, 1426 }, // 244 MTCRF_MTCRF8
  { 1, 186, 190, 1426, 1430 }, // 245 ADDC8O_rec_ADDC8_rec_ADDCO_rec_ADDC_rec_SUBFC8O_rec_SUBFC8_rec_SUBFCO_rec_SUBFC_rec
  { 0, 0, 0, 0, 0 }, // 246 FABSD_rec_FABSS_rec_FNABSD_rec_FNABSS_rec_FCPSGND_rec_FCPSGNS_rec_FNEGD_rec_FNEGS_rec_FMR_rec
  { 1, 190, 193, 1430, 1433 }, // 247 MCRFS
  { 0, 0, 0, 0, 0 }, // 248 MTFSF_MTFSF_rec_MTFSFI_MTFSFI_rec
  { 0, 0, 0, 0, 0 }, // 249 MTFSFb
  { 0, 0, 0, 0, 0 }, // 250 RLDCL_rec_RLDCR_rec
  { 0, 0, 0, 0, 0 }, // 251 RLDICL_rec_RLDICR_rec_RLDICL_32_rec_RLDIMI_rec
  { 1, 186, 190, 1433, 1437 }, // 252 RLWIMI8_rec_RLWIMI_rec
  { 1, 186, 190, 1437, 1441 }, // 253 RLWINM8_rec_RLWINM_rec_RLWNM8_rec_RLWNM_rec_SLW8_rec_SLW_rec_SRW8_rec_SRW_rec
  { 1, 186, 190, 1441, 1445 }, // 254 SRAWI_rec_SRAW_rec
  { 0, 0, 0, 0, 0 }, // 255 MFFS_MFFSCE_MFFSL_MFFS_rec
  { 0, 0, 0, 0, 0 }, // 256 MFCR_MFCR8
  { 0, 0, 0, 0, 0 }, // 257 EXTSWSLI_32_64_rec_SRADI_rec_EXTSWSLI_rec_RLDIC_rec
  { 0, 0, 0, 0, 0 }, // 258 SRAD_rec_SLD_rec_SRD_rec
  { 0, 0, 0, 0, 0 }, // 259 FDIV
  { 0, 0, 0, 0, 0 }, // 260 FDIV_rec
  { 0, 0, 0, 0, 0 }, // 261 XSSQRTDP
  { 0, 0, 0, 0, 0 }, // 262 FSQRT
  { 0, 0, 0, 0, 0 }, // 263 XVSQRTDP
  { 0, 0, 0, 0, 0 }, // 264 XVSQRTSP
  { 0, 0, 0, 0, 0 }, // 265 FSQRT_rec
  { 0, 0, 0, 0, 0 }, // 266 XSSQRTSP
  { 0, 0, 0, 0, 0 }, // 267 FSQRTS
  { 0, 0, 0, 0, 0 }, // 268 FSQRTS_rec
  { 0, 0, 0, 0, 0 }, // 269 XSDIVDP
  { 0, 0, 0, 0, 0 }, // 270 FDIVS
  { 0, 0, 0, 0, 0 }, // 271 FDIVS_rec
  { 0, 0, 0, 0, 0 }, // 272 XSDIVSP
  { 0, 0, 0, 0, 0 }, // 273 XVDIVSP
  { 0, 0, 0, 0, 0 }, // 274 XVDIVDP
  { 0, 0, 0, 0, 0 }, // 275 LFSU
  { 0, 0, 0, 0, 0 }, // 276 LFSUX
  { 0, 0, 0, 0, 0 }, // 277 STFDU_STFDUX_STFSU_STFSUX
  { 2, 227, 231, 1445, 1449 }, // 278 STBU_STBU8_STDU_STHU_STHU8_STWU_STWU8
  { 2, 227, 231, 1449, 1453 }, // 279 STBUX_STBUX8_STDUX_STHUX_STHUX8_STWUX_STWUX8
  { 2, 204, 209, 1453, 1458 }, // 280 LBZU_LBZU8
  { 2, 209, 214, 1458, 1463 }, // 281 LBZUX_LBZUX8
  { 0, 0, 0, 0, 0 }, // 282 LDU
  { 0, 0, 0, 0, 0 }, // 283 LDUX
  { 0, 0, 0, 0, 0 }, // 284 LFDU
  { 0, 0, 0, 0, 0 }, // 285 LFDUX
  { 0, 0, 0, 0, 0 }, // 286 VPMSUMB_VPMSUMD_VPMSUMH_VPMSUMW_VCIPHER_VCIPHERLAST_VNCIPHER_VNCIPHERLAST_VSBOX
  { 1, 190, 193, 1463, 1466 }, // 287 BCCCTR_BCCCTR8_BCCCTRL_BCCCTRL8_BCCL_BCCLA_BCCLR_BCCLRL_BCCTR_BCCTR8_BCCTR8n_BCCTRL_BCCTRL8_BCCTRL8n_BCCTRLn_BCCTRn_BDNZ_BDNZ8_BDNZA_BDNZAm_BDNZAp_BDNZm_BDNZp_BDZ_BDZ8_BDZA_BDZAm_BDZAp_BDZm_BDZp_BDNZL_BDNZLA_BDNZLAm_BDNZLAp_BDNZLR_BDNZLR8_BDNZLRL_BDNZLRLm_BDNZLRLp_BDNZLRm_BDNZLRp_BDNZLm_BDNZLp_BDZL_BDZLA_BDZLAm_BDZLAp_BDZLR_BDZLR8_BDZLRL_BDZLRLm_BDZLRLp_BDZLRm_BDZLRp_BDZLm_BDZLp_BL_BL_NOP_BL_TLS_BL8_BL8_NOP_BL8_NOP_TLS_BL8_TLS_BL8_TLS__BLA_BLA8_BLA8_NOP_BLR_BLR8_BLRL_TAILB_TAILB8_TAILBA_TAILBA8_TAILBCTR_TAILBCTR8_gBC_gBCA_gBCAat_gBCCTR_gBCCTRL_gBCL_gBCLA_gBCLAat_gBCLR_gBCLRL_gBCLat_gBCat_BCLR_BCLRL_BCLRLn_BCLRn_BCTR_BCTR8_BCTRL_BCTRL8_B_BA_BC_BCC_BCCA_BCL_BCLalways_BCLn_BCTRL8_LDinto_toc_BCTRL_LWZinto_toc_BCn_CTRL_DEP
  { 1, 190, 193, 1466, 1469 }, // 288 ADDPCIS
  { 1, 193, 197, 1469, 1473 }, // 289 LDAT_LWAT
  { 1, 201, 204, 1473, 1476 }, // 290 STDAT_STWAT
  { 1, 186, 190, 1476, 1480 }, // 291 BRINC
  { 0, 0, 0, 0, 0 }, // 292 EVABS_EVEQV_EVNAND_EVNEG_EVADDIW_EVADDW_EVAND_EVANDC_EVCMPEQ_EVCMPGTS_EVCMPGTU_EVCMPLTS_EVCMPLTU_EVCNTLSW_EVCNTLZW_EVEXTSB_EVEXTSH_EVMERGEHI_EVMERGEHILO_EVMERGELO_EVMERGELOHI_EVNOR_EVOR_EVORC_EVXOR_EVRLW_EVRLWI_EVRNDW_EVSLW_EVSLWI_EVSPLATFI_EVSPLATI_EVSRWIS_EVSRWIU_EVSRWS_EVSRWU_EVSUBFW_EVSUBIFW
  { 0, 0, 0, 0, 0 }, // 293 EVMRA_EVADDSMIAAW_EVADDSSIAAW_EVADDUMIAAW_EVADDUSIAAW_EVDIVWS_EVDIVWU_EVMHEGSMFAA_EVMHEGSMFAN_EVMHEGSMIAA_EVMHEGSMIAN_EVMHEGUMIAA_EVMHEGUMIAN_EVMHESMF_EVMHESMFA_EVMHESMFAAW_EVMHESMFANW_EVMHESMI_EVMHESMIA_EVMHESMIAAW_EVMHESMIANW_EVMHESSF_EVMHESSFA_EVMHESSFAAW_EVMHESSFANW_EVMHESSIAAW_EVMHESSIANW_EVMHEUMI_EVMHEUMIA_EVMHEUMIAAW_EVMHEUMIANW_EVMHEUSIAAW_EVMHEUSIANW_EVMHOGSMFAA_EVMHOGSMFAN_EVMHOGSMIAA_EVMHOGSMIAN_EVMHOGUMIAA_EVMHOGUMIAN_EVMHOSMF_EVMHOSMFA_EVMHOSMFAAW_EVMHOSMFANW_EVMHOSMI_EVMHOSMIA_EVMHOSMIAAW_EVMHOSMIANW_EVMHOSSF_EVMHOSSFA_EVMHOSSFAAW_EVMHOSSFANW_EVMHOSSIAAW_EVMHOSSIANW_EVMHOUMI_EVMHOUMIA_EVMHOUMIAAW_EVMHOUMIANW_EVMHOUSIAAW_EVMHOUSIANW_EVMWHSMF_EVMWHSMFA_EVMWHSMI_EVMWHSMIA_EVMWHSSF_EVMWHSSFA_EVMWHUMI_EVMWHUMIA_EVMWLSMIAAW_EVMWLSMIANW_EVMWLSSIAAW_EVMWLSSIANW_EVMWLUMI_EVMWLUMIA_EVMWLUMIAAW_EVMWLUMIANW_EVMWLUSIAAW_EVMWLUSIANW_EVMWSMF_EVMWSMFA_EVMWSMFAA_EVMWSMFAN_EVMWSMI_EVMWSMIA_EVMWSMIAA_EVMWSMIAN_EVMWSSF_EVMWSSFA_EVMWSSFAA_EVMWSSFAN_EVMWUMI_EVMWUMIA_EVMWUMIAA_EVMWUMIAN_EVSUBFSMIAAW_EVSUBFSSIAAW_EVSUBFUMIAAW_EVSUBFUSIAAW
  { 1, 193, 197, 1480, 1484 }, // 294 EVLDD_EVLDDX_EVLDH_EVLDHX_EVLDW_EVLDWX_EVLHHESPLAT_EVLHHESPLATX_EVLHHOSSPLAT_EVLHHOSSPLATX_EVLHHOUSPLAT_EVLHHOUSPLATX_EVLWHE_EVLWHEX_EVLWHOS_EVLWHOSX_EVLWHOU_EVLWHOUX_EVLWHSPLAT_EVLWHSPLATX_EVLWWSPLAT_EVLWWSPLATX
  { 1, 201, 204, 1484, 1487 }, // 295 EVSTDD_EVSTDDX_EVSTDH_EVSTDHX_EVSTDW_EVSTDWX_EVSTWHE_EVSTWHEX_EVSTWHO_EVSTWHOX_EVSTWWE_EVSTWWEX_EVSTWWO_EVSTWWOX
  { 1, 190, 193, 1487, 1490 }, // 296 HRFID_ATTN_CLRBHRB_MFBHRBE_NAP_RFCI_RFDI_RFMCI_SC
  { 0, 0, 0, 0, 0 }, // 297 RFI
  { 0, 0, 0, 0, 0 }, // 298 RFID
  { 1, 193, 197, 1490, 1494 }, // 299 DSS_DSSALL_DST_DST64_DSTST_DSTST64_DSTSTT_DSTSTT64_DSTT_DSTT64_ICBLQ_LBEPX_LHEPX_LWEPX_TLBIVAX_TLBLD_TLBLI_TLBRE_TLBRE2_TLBSX_TLBSX2_TLBSX2D_TLBWE_TLBWE2_MBAR_TRAP_DCCCI_ICCCI
  { 1, 201, 204, 1494, 1497 }, // 300 ICBLC_STBEPX_STHEPX_STWEPX
  { 0, 0, 0, 0, 0 }, // 301 LFDEPX
  { 0, 0, 0, 0, 0 }, // 302 STFDEPX
  { 0, 0, 0, 0, 0 }, // 303 MFSR_MFSRIN
  { 0, 0, 0, 0, 0 }, // 304 MTSR_MTSRIN
  { 1, 186, 190, 1497, 1501 }, // 305 MFDCR
  { 1, 186, 190, 1501, 1505 }, // 306 MTDCR
  { 1, 186, 190, 1505, 1509 }, // 307 NOP_GT_PWR6_NOP_GT_PWR7
  { 0, 0, 0, 0, 0 }, // 308 TLBIA
  { 0, 0, 0, 0, 0 }, // 309 WRTEE_WRTEEI
  { 0, 0, 0, 0, 0 }, // 310 MSYNC
  { 0, 0, 0, 0, 0 }, // 311 SLBSYNC
  { 0, 0, 0, 0, 0 }, // 312 SLBFEE_rec
  { 0, 0, 0, 0, 0 }, // 313 STOP
  { 0, 0, 0, 0, 0 }, // 314 DCBA_DCBI
  { 0, uint16_t(~0U), uint16_t(~0U), uint16_t(~0U), uint16_t(~0U) }// end marker
};

static const llvm::InstrItinerary PPCE200Z3Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 0, 0, 0, 0, 0 }, // 1 IIC_LdStSync
  { 1, 235, 237, 1509, 1511 }, // 2 IIC_IntSimple
  { 1, 235, 237, 1511, 1513 }, // 3 IIC_IntGeneral
  { 1, 237, 239, 1513, 1515 }, // 4 IIC_BrB
  { 0, 0, 0, 0, 0 }, // 5 IIC_VecFP
  { 1, 235, 237, 1515, 1517 }, // 6 IIC_IntCompare
  { 0, 0, 0, 0, 0 }, // 7 IIC_SprABORT
  { 0, 0, 0, 0, 0 }, // 8 IIC_LdStCOPY
  { 0, 0, 0, 0, 0 }, // 9 IIC_LdStPASTE
  { 1, 237, 239, 1517, 1519 }, // 10 IIC_BrCR
  { 0, 0, 0, 0, 0 }, // 11 IIC_LdStLD
  { 1, 239, 241, 1519, 1521 }, // 12 IIC_LdStDCBF
  { 1, 241, 243, 1521, 1523 }, // 13 IIC_LdStLoad
  { 0, 0, 0, 0, 0 }, // 14 IIC_IntDivD
  { 1, 243, 246, 1523, 1525 }, // 15 IIC_IntDivW
  { 0, 0, 0, 0, 0 }, // 16 IIC_FPDGeneral
  { 0, 0, 0, 0, 0 }, // 17 IIC_FPAddSub
  { 0, 0, 0, 0, 0 }, // 18 IIC_FPDivD
  { 0, 0, 0, 0, 0 }, // 19 IIC_FPSGeneral
  { 0, 0, 0, 0, 0 }, // 20 IIC_FPCompare
  { 0, 0, 0, 0, 0 }, // 21 IIC_FPGeneral
  { 0, 0, 0, 0, 0 }, // 22 IIC_VecGeneral
  { 0, 0, 0, 0, 0 }, // 23 IIC_VecComplex
  { 1, 239, 241, 1525, 1527 }, // 24 IIC_LdStStore
  { 0, 0, 0, 0, 0 }, // 25 IIC_IntRotateDI
  { 0, 0, 0, 0, 0 }, // 26 IIC_FPDivS
  { 0, 0, 0, 0, 0 }, // 27 IIC_FPFused
  { 0, 0, 0, 0, 0 }, // 28 IIC_FPSqrtD
  { 0, 0, 0, 0, 0 }, // 29 IIC_FPSqrtS
  { 0, 0, 0, 0, 0 }, // 30 IIC_LdStICBI
  { 1, 235, 237, 1527, 1530 }, // 31 IIC_IntISEL
  { 0, 0, 0, 0, 0 }, // 32 IIC_SprISYNC
  { 1, 246, 248, 1530, 1532 }, // 33 IIC_LdStLWARX
  { 1, 241, 243, 1532, 1535 }, // 34 IIC_LdStLoadUpd
  { 0, 0, 0, 0, 0 }, // 35 IIC_LdStLoadUpdX
  { 0, 0, 0, 0, 0 }, // 36 IIC_LdStLDARX
  { 0, 0, 0, 0, 0 }, // 37 IIC_LdStLDU
  { 0, 0, 0, 0, 0 }, // 38 IIC_LdStLDUX
  { 0, 0, 0, 0, 0 }, // 39 IIC_LdStLFD
  { 0, 0, 0, 0, 0 }, // 40 IIC_LdStLFDU
  { 0, 0, 0, 0, 0 }, // 41 IIC_LdStLFDUX
  { 0, 0, 0, 0, 0 }, // 42 IIC_LdStLHA
  { 0, 0, 0, 0, 0 }, // 43 IIC_LdStLHAU
  { 0, 0, 0, 0, 0 }, // 44 IIC_LdStLHAUX
  { 0, 0, 0, 0, 0 }, // 45 IIC_LdStLMW
  { 0, 0, 0, 0, 0 }, // 46 IIC_LdStLWA
  { 0, 0, 0, 0, 0 }, // 47 IIC_IntMulHD
  { 1, 237, 239, 1535, 1537 }, // 48 IIC_BrMCR
  { 1, 235, 237, 1537, 1539 }, // 49 IIC_BrMCRX
  { 1, 235, 237, 1539, 1541 }, // 50 IIC_SprMFCR
  { 1, 235, 237, 1541, 1543 }, // 51 IIC_SprMFSPR
  { 0, 0, 0, 0, 0 }, // 52 IIC_IntMFFS
  { 0, 0, 0, 0, 0 }, // 53 IIC_SprMFMSR
  { 1, 235, 237, 1543, 1545 }, // 54 IIC_SprMFCRF
  { 0, 0, 0, 0, 0 }, // 55 IIC_SprMFPMR
  { 0, 0, 0, 0, 0 }, // 56 IIC_SprMFSR
  { 0, 0, 0, 0, 0 }, // 57 IIC_SprMFTB
  { 0, 0, 0, 0, 0 }, // 58 IIC_SprMSGSYNC
  { 1, 235, 237, 1545, 1547 }, // 59 IIC_SprMTSPR
  { 0, 0, 0, 0, 0 }, // 60 IIC_IntMTFSB0
  { 0, 0, 0, 0, 0 }, // 61 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 62 IIC_SprMTMSRD
  { 0, 0, 0, 0, 0 }, // 63 IIC_SprMTPMR
  { 0, 0, 0, 0, 0 }, // 64 IIC_SprMTSR
  { 1, 248, 250, 1547, 1549 }, // 65 IIC_IntMulHW
  { 1, 248, 250, 1549, 1551 }, // 66 IIC_IntMulHWU
  { 1, 248, 250, 1551, 1553 }, // 67 IIC_IntMulLI
  { 0, 0, 0, 0, 0 }, // 68 IIC_VecPerm
  { 0, 0, 0, 0, 0 }, // 69 IIC_LdStSTFD
  { 0, 0, 0, 0, 0 }, // 70 IIC_LdStSTFDU
  { 0, 0, 0, 0, 0 }, // 71 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 72 IIC_IntRFID
  { 0, 0, 0, 0, 0 }, // 73 IIC_IntRotateD
  { 1, 235, 237, 1553, 1555 }, // 74 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 75 IIC_SprSLBFEE
  { 0, 0, 0, 0, 0 }, // 76 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 77 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprSLBIEG
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprSLBMFEV
  { 0, 0, 0, 0, 0 }, // 81 IIC_SprSLBMTE
  { 0, 0, 0, 0, 0 }, // 82 IIC_SprSLBSYNC
  { 1, 235, 237, 1555, 1557 }, // 83 IIC_IntShift
  { 1, 241, 243, 1557, 1559 }, // 84 IIC_LdStSTWCX
  { 1, 239, 241, 1559, 1562 }, // 85 IIC_LdStSTU
  { 0, 0, 0, 0, 0 }, // 86 IIC_LdStSTUX
  { 0, 0, 0, 0, 0 }, // 87 IIC_LdStSTD
  { 0, 0, 0, 0, 0 }, // 88 IIC_LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 89 IIC_SprSTOP
  { 0, 0, 0, 0, 0 }, // 90 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 91 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 92 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 93 IIC_SprTLBIEL
  { 0, 0, 0, 0, 0 }, // 94 IIC_SprTLBSYNC
  { 1, 250, 252, 1562, 1564 }, // 95 IIC_IntTrapW
  { 0, 0, 0, 0, 0 }, // 96 IIC_VecFPCompare
  { 0, 0, 0, 0, 0 }, // 97 VADDUBM_VADDUDM_VADDUHM_VADDUWM_VEXTSB2D_VEXTSB2Ds_VEXTSB2W_VEXTSB2Ws_VEXTSH2D_VEXTSH2Ds_VEXTSH2W_VEXTSH2Ws_VEXTSW2D_VEXTSW2Ds_VSLD_VSRD_VSUBUBM_VSUBUDM_VSUBUHM_VSUBUWM_VPOPCNTB_VPOPCNTH_VSRAD_MTVSRDD_VEQV_VNAND_VNEGD_VNEGW_VORC_XXLAND_XXLANDC_XXLEQV_XXLEQVOnes_XXLNAND_XXLNOR_XXLOR_XXLORf_XXLORC_XXLXOR_XXLXORdpz_XXLXORspz_XXLXORz
  { 0, 0, 0, 0, 0 }, // 98 VAND_VANDC_V_SET0_V_SET0B_V_SET0H_VSLB_VSLH_VSLW_VSRB_VSRH_VSRW_VRLB_VRLD_VRLH_VRLW_VSRAB_VSRAH_VSRAW_XVABSDP_XVABSSP_XVNABSDP_XVNABSSP_XVCPSGNDP_XVCPSGNSP_XVIEXPDP_XVIEXPSP_XVXEXPDP_XVXEXPSP_VRLDMI_VRLDNM_VRLWMI_VRLWNM_VMRGEW_VMRGOW_VNOR_VOR_VSEL_VXOR_XVNEGDP_XVNEGSP_XSABSQP_XSCPSGNQP_XSIEXPQP_XSNABSQP_XSNEGQP_XSXEXPQP
  { 0, 0, 0, 0, 0 }, // 99 XXSEL
  { 1, 235, 237, 1564, 1566 }, // 100 TABORTDC_TABORTDCI_TABORTWC_TABORTWCI
  { 0, 0, 0, 0, 0 }, // 101 MTFSB0_MTFSB1
  { 0, 0, 0, 0, 0 }, // 102 MFFSCDRN_MFFSCDRNI_MFFSCRN_MFFSCRNI
  { 1, 235, 237, 1566, 1568 }, // 103 CMPRB_CMPRB8_CMPEQB
  { 0, 0, 0, 0, 0 }, // 104 TD_TDI
  { 1, 250, 252, 1568, 1570 }, // 105 TW_TWI
  { 0, 0, 0, 0, 0 }, // 106 FCMPUD_FCMPUS_FTDIV_FTSQRT
  { 0, 0, 0, 0, 0 }, // 107 XSTSTDCDP_XSTSTDCSP
  { 0, 0, 0, 0, 0 }, // 108 XSMAXCDP_XSMAXDP_XSMAXJDP_XSMINCDP_XSMINDP_XSMINJDP_XSXSIGDP_XSCVSPDPN
  { 0, 0, 0, 0, 0 }, // 109 XSCMPEQDP_XSCMPEXPDP_XSCMPGEDP_XSCMPGTDP_XSCMPODP_XSCMPUDP_XSTDIVDP_XSTSQRTDP
  { 1, 235, 237, 1570, 1572 }, // 110 CNTLZD_CNTLZD_rec_CNTLZW_CNTLZW8_CNTLZW8_rec_CNTLZW_rec_CNTTZD_CNTTZD_rec_CNTTZW_CNTTZW8_CNTTZW8_rec_CNTTZW_rec_POPCNTD_POPCNTW_CMPB_CMPB8_SETB_SETB8_BPERMD
  { 0, 0, 0, 0, 0 }, // 111 SLD_SRD_SRAD
  { 0, 0, 0, 0, 0 }, // 112 SRADI_EXTSWSLI_32_64_EXTSWSLI_SRADI_32_RLDIC
  { 0, 0, 0, 0, 0 }, // 113 MFVRD_MFVSRD_MTVRD_MTVSRD_MTVRWA_MTVRWZ_MTVSRWA_MTVSRWZ_MFVSRWZ_MFVRWZ
  { 1, 235, 237, 1572, 1574 }, // 114 CMPLW_CMPLWI_CMPW_CMPWI_CMPD_CMPDI_CMPLD_CMPLDI
  { 1, 235, 237, 1574, 1576 }, // 115 SUBFC_SUBFC8_SUBFC8O_SUBFCO_SUBFIC_SUBFIC8_ANDI8_rec_ANDIS8_rec_ANDIS_rec_ANDI_rec_ADDC_ADDC8_ADDC8O_ADDCO_ADDIC_ADDIC8_ADDIC_rec_ADDE_ADDE8_ADDE8O_ADDE8O_rec_ADDE8_rec_ADDEO_ADDEO_rec_ADDE_rec_ADDME_ADDME8_ADDME8O_ADDME8O_rec_ADDME8_rec_ADDMEO_ADDMEO_rec_ADDME_rec_ADDZE_ADDZE8_ADDZE8O_ADDZE8O_rec_ADDZE8_rec_ADDZEO_ADDZEO_rec_ADDZE_rec_SUBF_SUBF8_SUBF8O_SUBF8O_rec_SUBF8_rec_SUBFE_SUBFE8_SUBFE8O_SUBFE8O_rec_SUBFE8_rec_SUBFEO_SUBFEO_rec_SUBFE_rec_SUBFME_SUBFME8_SUBFME8O_SUBFME8O_rec_SUBFME8_rec_SUBFMEO_SUBFMEO_rec_SUBFME_rec_SUBFO_SUBFO_rec_SUBFZE_SUBFZE8_SUBFZE8O_SUBFZE8O_rec_SUBFZE8_rec_SUBFZEO_SUBFZEO_rec_SUBFZE_rec_SUBF_rec_POPCNTB_LA
  { 1, 235, 237, 1576, 1578 }, // 116 ADD4_ADD4O_ADD4O_rec_ADD4_rec_ADD8_ADD8O_ADD8O_rec_ADD8_rec_NEG_NEG8_NEG8O_NEG8O_rec_NEG8_rec_NEGO_NEGO_rec_NEG_rec_ADDI_ADDI8_ADDIS_ADDIS8_LI_LI8_LIS_LIS8_OR_OR8_OR8_rec_ORI_ORI8_ORIS_ORIS8_OR_rec_XOR_XOR8_XOR8_rec_XORI_XORI8_XORIS_XORIS8_XOR_rec_NAND_NAND8_NAND8_rec_NAND_rec_AND_AND8_AND8_rec_ANDC_ANDC8_ANDC8_rec_ANDC_rec_AND_rec_NOR_NOR8_NOR8_rec_NOR_rec_ORC_ORC8_ORC8_rec_ORC_rec_EQV_EQV8_EQV8_rec_EQV_rec_EXTSB_EXTSB8_EXTSB8_32_64_EXTSB8_rec_EXTSB_rec_EXTSH_EXTSH8_EXTSH8_32_64_EXTSH8_rec_EXTSH_rec_EXTSW_EXTSW_32_EXTSW_32_64_EXTSW_32_64_rec_EXTSW_rec_ADD4TLS_ADD8TLS_ADD8TLS__NOP
  { 0, 0, 0, 0, 0 }, // 117 ADDIStocHA_ADDIStocHA8_ADDItocL_COPY
  { 1, 237, 239, 1578, 1580 }, // 118 MCRF
  { 1, 235, 237, 1580, 1582 }, // 119 MCRXRX
  { 0, 0, 0, 0, 0 }, // 120 XSNABSDP_XSXEXPDP_XSABSDP_XSNEGDP_XSCPSGNDP
  { 1, 237, 239, 1582, 1584 }, // 121 RFEBB
  { 1, 235, 237, 1584, 1586 }, // 122 TBEGIN_TRECHKPT
  { 1, 241, 243, 1586, 1588 }, // 123 WAIT
  { 0, 0, 0, 0, 0 }, // 124 RLDCL_RLDCR
  { 1, 235, 237, 1588, 1590 }, // 125 RLWIMI_RLWIMI8
  { 0, 0, 0, 0, 0 }, // 126 RLDICL_RLDICL_32_RLDICL_32_64_RLDICR_RLDICR_32_RLDIMI
  { 1, 235, 237, 1590, 1592 }, // 127 MFOCRF_MFOCRF8
  { 1, 235, 237, 1592, 1594 }, // 128 MTOCRF_MTOCRF8
  { 1, 237, 239, 1594, 1596 }, // 129 CR6SET_CR6UNSET_CRSET_CRUNSET_CRAND_CRANDC_CRNAND_CRNOR_CROR_CRORC_CREQV_CRXOR
  { 1, 235, 237, 1596, 1598 }, // 130 SLW_SLW8_SRW_SRW8_RLWINM_RLWINM8_RLWNM_RLWNM8
  { 0, 0, 0, 0, 0 }, // 131 FABSD_FABSS_FNABSD_FNABSS_FNEGD_FNEGS_FCPSGND_FCPSGNS_FMR
  { 1, 235, 237, 1598, 1600 }, // 132 SRAW_SRAWI
  { 1, 235, 237, 1600, 1603 }, // 133 ISEL_ISEL8
  { 0, 0, 0, 0, 0 }, // 134 XSIEXPDP
  { 1, 235, 237, 1603, 1605 }, // 135 TRECLAIM_TSR_TABORT
  { 1, 239, 241, 1605, 1607 }, // 136 MFVSCR
  { 1, 241, 243, 1607, 1609 }, // 137 MTVSCR
  { 0, 0, 0, 0, 0 }, // 138 VCMPNEZB_VCMPNEZH_VCMPNEZW_VCMPEQUB_VCMPEQUD_VCMPEQUH_VCMPEQUW_VCMPNEB_VCMPNEH_VCMPNEW_VCMPEQFP_VCMPEQFP_rec_VCMPGEFP_VCMPGEFP_rec_VCMPGTFP_VCMPGTFP_rec_VCMPBFP_VCMPBFP_rec_VCMPGTSB_VCMPGTSB_rec_VCMPGTSD_VCMPGTSD_rec_VCMPGTSH_VCMPGTSH_rec_VCMPGTSW_VCMPGTSW_rec_VCMPGTUB_VCMPGTUB_rec_VCMPGTUD_VCMPGTUD_rec_VCMPGTUH_VCMPGTUH_rec_VCMPGTUW_VCMPGTUW_rec_VCMPNEB_rec_VCMPNEH_rec_VCMPNEW_rec_VCMPNEZB_rec_VCMPNEZH_rec_VCMPNEZW_rec_VCMPEQUB_rec_VCMPEQUD_rec_VCMPEQUH_rec_VCMPEQUW_rec_XVCMPEQDP_XVCMPEQDP_rec_XVCMPEQSP_XVCMPEQSP_rec_XVCMPGEDP_XVCMPGEDP_rec_XVCMPGESP_XVCMPGESP_rec_XVCMPGTDP_XVCMPGTDP_rec_XVCMPGTSP_XVCMPGTSP_rec
  { 0, 0, 0, 0, 0 }, // 139 VABSDUB_VABSDUH_VABSDUW_VCLZB_VCLZD_VCLZH_VCLZW_VCTZB_VCTZD_VCTZH_VCTZW_VPOPCNTW_VPOPCNTD_VPRTYBD_VPRTYBW
  { 0, 0, 0, 0, 0 }, // 140 VADDUBS_VADDUHS_VADDUWS_VAVGSB_VAVGSH_VAVGSW_VAVGUB_VAVGUH_VAVGUW_VADDSBS_VADDSHS_VADDSWS_VMAXFP_VMINFP_VMAXSB_VMAXSD_VMAXSH_VMAXSW_VMAXUB_VMAXUD_VMAXUH_VMAXUW_VMINSB_VMINSD_VMINSH_VMINSW_VMINUB_VMINUD_VMINUH_VMINUW_VBPERMD_VADDCUW_VSHASIGMAD_VSHASIGMAW_VSUBSBS_VSUBSHS_VSUBSWS_VSUBUBS_VSUBUHS_VSUBUWS_VSUBCUW_XVMAXDP_XVMAXSP_XVMINDP_XVMINSP_XVTSTDCDP_XVTSTDCSP_XVXSIGDP_XVXSIGSP
  { 0, 0, 0, 0, 0 }, // 141 XVTDIVDP_XVTDIVSP_XVTSQRTDP_XVTSQRTSP
  { 0, 0, 0, 0, 0 }, // 142 VADDFP_VCTSXS_VCTSXS_0_VCTUXS_VCTUXS_0_VEXPTEFP_VLOGEFP_VMADDFP_VMHADDSHS_VNMSUBFP_VREFP_VRFIM_VRFIN_VRFIP_VRFIZ_VRSQRTEFP_XVADDDP_XVADDSP_XVCVDPSP_XVCVDPSXDS_XVCVDPSXWS_XVCVDPUXDS_XVCVDPUXWS_XVCVHPSP_XVCVSPDP_XVCVSPHP_XVCVSPSXDS_XVCVSPSXWS_XVCVSPUXDS_XVCVSPUXWS_XVCVSXDDP_XVCVSXDSP_XVCVSXWDP_XVCVSXWSP_XVCVUXDDP_XVCVUXDSP_XVCVUXWDP_XVCVUXWSP_XVMADDADP_XVMADDASP_XVMADDMDP_XVMADDMSP_XVMSUBADP_XVMSUBASP_XVMSUBMDP_XVMSUBMSP_XVMULDP_XVMULSP_XVNMADDADP_XVNMADDASP_XVNMADDMDP_XVNMADDMSP_XVNMSUBADP_XVNMSUBASP_XVNMSUBMDP_XVNMSUBMSP_XVRDPI_XVRDPIC_XVRDPIM_XVRDPIP_XVRDPIZ_XVREDP_XVRESP_XVRSPI_XVRSPIC_XVRSPIM_XVRSPIP_XVRSPIZ_XVRSQRTEDP_XVRSQRTESP_XVSUBDP_XVSUBSP_VCFSX_VCFSX_0_VCFUX_VCFUX_0_VMHRADDSHS_VMLADDUHM_VMSUMMBM_VMSUMSHM_VMSUMSHS_VMSUMUBM_VMSUMUHM_VMSUMUDM_VMSUMUHS_VMULESB_VMULESH_VMULESW_VMULEUB_VMULEUH_VMULEUW_VMULOSB_VMULOSH_VMULOSW_VMULOUB_VMULOUH_VMULOUW_VSUM2SWS_VSUM4SBS_VSUM4SHS_VSUM4UBS_VSUMSWS
  { 0, 0, 0, 0, 0 }, // 143 VSUBFP_VMULUWM
  { 0, 0, 0, 0, 0 }, // 144 MADDHD_MADDHDU_MADDLD_MADDLD8_MULLD_MULLDO
  { 1, 248, 250, 1609, 1611 }, // 145 MULHD_MULHW_MULLW_MULLWO
  { 1, 248, 250, 1611, 1613 }, // 146 MULHDU_MULHWU
  { 1, 248, 250, 1613, 1615 }, // 147 MULLI_MULLI8
  { 0, 0, 0, 0, 0 }, // 148 FRSP_FRIMD_FRIMS_FRIND_FRINS_FRIPD_FRIPS_FRIZD_FRIZS_FRE_FRES_FADDS_FMSUBS_FMADDS_FSUBS_FCFID_FCFIDS_FCFIDU_FCFIDUS_FCTID_FCTIDU_FCTIDUZ_FCTIDZ_FCTIW_FCTIWU_FCTIWUZ_FCTIWZ_FRSQRTE_FRSQRTES_FNMADDS_FNMSUBS_FSELD_FSELS_FMULS
  { 0, 0, 0, 0, 0 }, // 149 FADD_FSUB
  { 0, 0, 0, 0, 0 }, // 150 FMSUB_FMADD_FNMADD_FNMSUB_FMUL
  { 0, 0, 0, 0, 0 }, // 151 XSMADDADP_XSMADDASP_XSMADDMDP_XSMADDMSP_XSMSUBADP_XSMSUBASP_XSMSUBMDP_XSMSUBMSP_XSMULDP_XSMULSP_XSNMADDADP_XSNMADDASP_XSNMADDMDP_XSNMADDMSP_XSNMSUBADP_XSNMSUBASP_XSNMSUBMDP_XSNMSUBMSP
  { 0, 0, 0, 0, 0 }, // 152 FSELD_rec_FSELS_rec
  { 1, 248, 250, 1615, 1617 }, // 153 MULHDU_rec_MULHWU_rec
  { 1, 248, 250, 1617, 1619 }, // 154 MULHD_rec_MULHW_rec_MULLWO_rec_MULLW_rec
  { 0, 0, 0, 0, 0 }, // 155 MULLDO_rec_MULLD_rec
  { 0, 0, 0, 0, 0 }, // 156 FRIMD_rec_FRIMS_rec_FRIND_rec_FRINS_rec_FRIPD_rec_FRIPS_rec_FRIZD_rec_FRIZS_rec_FRES_rec_FRE_rec_FADDS_rec_FSUBS_rec_FMSUBS_rec_FNMSUBS_rec_FMADDS_rec_FNMADDS_rec_FCFIDS_rec_FCFIDUS_rec_FCFIDU_rec_FCFID_rec_FCTIDUZ_rec_FCTIDU_rec_FCTIDZ_rec_FCTID_rec_FCTIWUZ_rec_FCTIWU_rec_FCTIWZ_rec_FCTIW_rec_FMULS_rec_FRSQRTES_rec_FRSQRTE_rec_FRSP_rec
  { 0, 0, 0, 0, 0 }, // 157 FADD_rec_FSUB_rec
  { 0, 0, 0, 0, 0 }, // 158 FMSUB_rec_FNMSUB_rec_FMADD_rec_FNMADD_rec_FMUL_rec
  { 0, 0, 0, 0, 0 }, // 159 XSADDDP_XSADDSP_XSCVDPHP_XSCVDPSP_XSCVDPSXDS_XSCVDPSXDSs_XSCVDPSXWS_XSCVDPUXDS_XSCVDPUXDSs_XSCVDPUXWS_XSCVDPSXWSs_XSCVDPUXWSs_XSCVHPDP_XSCVSPDP_XSCVSXDDP_XSCVSXDSP_XSCVUXDDP_XSCVUXDSP_XSRDPI_XSRDPIC_XSRDPIM_XSRDPIP_XSRDPIZ_XSREDP_XSRESP_XSRSQRTEDP_XSRSQRTESP_XSSUBDP_XSSUBSP_XSCVDPSPN_XSRSP
  { 1, 241, 243, 1619, 1621 }, // 160 LVSL_LVSR
  { 0, 0, 0, 0, 0 }, // 161 VSPLTISB_VSPLTISH_VSPLTISW_VSPLTB_VSPLTBs_VSPLTH_VSPLTHs_VSPLTW_XXMRGHW_XXMRGLW_XXPERM_XXPERMR_XXSLDWI_XXSLDWIs_XXSPLTIB_XXSPLTW_XXSPLTWs_XXPERMDI_XXPERMDIs
  { 0, 0, 0, 0, 0 }, // 162 V_SETALLONES_V_SETALLONESB_V_SETALLONESH_VBPERMQ_VGBBD_VMRGHB_VMRGHH_VMRGHW_VMRGLB_VMRGLH_VMRGLW_VPERM_VPERMR_VPERMXOR_VPKPX_VPKSDSS_VPKSDUS_VPKSHSS_VPKSHUS_VPKSWSS_VPKSWUS_VPKUDUM_VPKUDUS_VPKUHUM_VPKUHUS_VPKUWUM_VPKUWUS_VSL_VSLDOI_VSLO_VSLV_VSR_VSRO_VSRV_VUPKHPX_VUPKHSB_VUPKHSH_VUPKHSW_VUPKLPX_VUPKLSB_VUPKLSH_VUPKLSW_XXBRD_XXBRH_XXBRQ_XXBRW_XXEXTRACTUW_XXINSERTW_VADDCUQ_VADDECUQ_VADDEUQM_VMUL10CUQ_VMUL10ECUQ_VMUL10EUQ_VMUL10UQ_VSUBCUQ_VSUBECUQ_VSUBEUQM_XSTSTDCQP_XSXSIGQP_BCDCFN_rec_BCDCFZ_rec_BCDCPSGN_rec_BCDCTN_rec_BCDCTZ_rec_BCDSETSGN_rec_BCDS_rec_BCDTRUNC_rec_BCDUS_rec_BCDUTRUNC_rec
  { 0, 0, 0, 0, 0 }, // 163 VEXTRACTUB_VEXTRACTUH_VEXTRACTUW_VINSERTB_VINSERTD_VINSERTH_VINSERTW_MFVSRLD_MTVSRWS_VCLZLSBB_VCTZLSBB_VEXTRACTD_VEXTUBLX_VEXTUBRX_VEXTUHLX_VEXTUHRX_VEXTUWLX_VEXTUWRX_VPRTYBQ_VADDUQM_VSUBUQM
  { 0, 0, 0, 0, 0 }, // 164 XSCMPEXPQP_XSCMPOQP_XSCMPUQP
  { 0, 0, 0, 0, 0 }, // 165 BCDSR_rec_XSADDQP_XSADDQPO_XSCVDPQP_XSCVQPDP_XSCVQPDPO_XSCVQPSDZ_XSCVQPSWZ_XSCVQPUDZ_XSCVQPUWZ_XSCVSDQP_XSCVUDQP_XSRQPI_XSRQPIX_XSRQPXP_XSSUBQP_XSSUBQPO
  { 0, 0, 0, 0, 0 }, // 166 BCDCTSQ_rec
  { 0, 0, 0, 0, 0 }, // 167 XSMADDQP_XSMADDQPO_XSMSUBQP_XSMSUBQPO_XSMULQP_XSMULQPO_XSNMADDQP_XSNMADDQPO_XSNMSUBQP_XSNMSUBQPO
  { 0, 0, 0, 0, 0 }, // 168 BCDCFSQ_rec
  { 0, 0, 0, 0, 0 }, // 169 XSDIVQP_XSDIVQPO
  { 0, 0, 0, 0, 0 }, // 170 XSSQRTQP_XSSQRTQPO
  { 1, 241, 243, 1621, 1623 }, // 171 LXVL_LXVLL
  { 1, 241, 243, 1623, 1625 }, // 172 LVEBX_LVEHX_LVEWX_LVX_LVXL
  { 0, 0, 0, 0, 0 }, // 173 LXSIBZX_LXSIHZX_LXSDX_LXVB16X_LXVD2X_LXVWSX_LXSIWZX_LXV_LXVX_LXSD
  { 0, 0, 0, 0, 0 }, // 174 DFLOADf64_XFLOADf64_LIWZX
  { 1, 239, 241, 1625, 1627 }, // 175 DCBF_DCBFEP_DCBST_DCBSTEP_DCBT_DCBTEP_DCBZ_DCBZEP_DCBZL_DCBZLEP_DCBTST_DCBTSTEP
  { 0, 0, 0, 0, 0 }, // 176 CP_COPY_CP_COPY8
  { 0, 0, 0, 0, 0 }, // 177 CP_PASTE_CP_PASTE8
  { 0, 0, 0, 0, 0 }, // 178 ICBI_ICBIEP
  { 1, 241, 243, 1627, 1629 }, // 179 ICBT_ICBTLS_LBZ_LBZ8_LBZCIX_LBZX_LBZX8_LBZXTLS_LBZXTLS__LBZXTLS_32_LDBRX_LDCIX_LHBRX_LHBRX8_LHZ_LHZ8_LHZCIX_LHZX_LHZX8_LHZXTLS_LHZXTLS__LHZXTLS_32_LWBRX_LWBRX8_LWZ_LWZ8_LWZCIX_LWZX_LWZX8_LWZXTLS_LWZXTLS__LWZXTLS_32_EnforceIEIO_LSWI
  { 1, 246, 248, 1629, 1631 }, // 180 LBARX_LBARXL_LHARX_LHARXL_LWARX_LWARXL
  { 0, 0, 0, 0, 0 }, // 181 LD_LDX_LDXTLS_LDXTLS__DARN
  { 0, 0, 0, 0, 0 }, // 182 LDARX_LDARXL
  { 0, 0, 0, 0, 0 }, // 183 CP_ABORT
  { 0, 0, 0, 0, 0 }, // 184 ISYNC
  { 0, 0, 0, 0, 0 }, // 185 MSGSYNC
  { 0, 0, 0, 0, 0 }, // 186 TLBSYNC
  { 0, 0, 0, 0, 0 }, // 187 SYNC
  { 0, 0, 0, 0, 0 }, // 188 LMW
  { 0, 0, 0, 0, 0 }, // 189 LFIWZX_LFDX_LFD
  { 0, 0, 0, 0, 0 }, // 190 SLBIA
  { 0, 0, 0, 0, 0 }, // 191 SLBIE
  { 0, 0, 0, 0, 0 }, // 192 SLBMFEE
  { 0, 0, 0, 0, 0 }, // 193 SLBMFEV
  { 0, 0, 0, 0, 0 }, // 194 SLBMTE
  { 0, 0, 0, 0, 0 }, // 195 TLBIEL
  { 1, 241, 243, 1631, 1634 }, // 196 LHZU_LHZU8_LWZU_LWZU8
  { 0, 0, 0, 0, 0 }, // 197 LHZUX_LHZUX8_LWZUX_LWZUX8
  { 1, 235, 237, 1634, 1636 }, // 198 TEND
  { 1, 241, 243, 1636, 1638 }, // 199 STBCX_STHCX_STWCX
  { 0, 0, 0, 0, 0 }, // 200 STDCX
  { 0, 0, 0, 0, 0 }, // 201 LDMX
  { 0, 0, 0, 0, 0 }, // 202 LHA_LHA8_LHAX_LHAX8_LWAX_LWAX_32
  { 0, 0, 0, 0, 0 }, // 203 CP_PASTE8_rec_CP_PASTE_rec
  { 0, 0, 0, 0, 0 }, // 204 LWA_LWA_32
  { 1, 235, 237, 1638, 1640 }, // 205 TCHECK
  { 0, 0, 0, 0, 0 }, // 206 LFIWAX
  { 0, 0, 0, 0, 0 }, // 207 LXSIWAX
  { 0, 0, 0, 0, 0 }, // 208 LIWAX
  { 0, 0, 0, 0, 0 }, // 209 LFSX_LFS
  { 0, 0, 0, 0, 0 }, // 210 LXSSP_LXSSPX
  { 0, 0, 0, 0, 0 }, // 211 XFLOADf32_DFLOADf32
  { 0, 0, 0, 0, 0 }, // 212 LHAU_LHAU8
  { 0, 0, 0, 0, 0 }, // 213 LHAUX_LHAUX8_LWAUX
  { 0, 0, 0, 0, 0 }, // 214 LXVH8X_LXVDSX_LXVW4X
  { 0, 0, 0, 0, 0 }, // 215 STFD_STFDX_STFIWX_STFS_STFSX_STXSD_STXSDX_STXSIBX_STXSIBXv_STXSIHX_STXSIHXv_STXSIWX_STXSSP_STXSSPX
  { 1, 239, 241, 1640, 1642 }, // 216 STW_STW8_STDBRX_STHBRX_STWBRX_STB_STB8_STH_STH8_STBX_STBX8_STBXTLS_STBXTLS__STBXTLS_32_STHX_STHX8_STHXTLS_STHXTLS__STHXTLS_32_STWX_STWX8_STWXTLS_STWXTLS__STWXTLS_32
  { 0, 0, 0, 0, 0 }, // 217 DFSTOREf32_DFSTOREf64_XFSTOREf32_XFSTOREf64_STIWX
  { 0, 0, 0, 0, 0 }, // 218 STD_STDX_STDXTLS_STDXTLS_
  { 1, 241, 243, 1642, 1644 }, // 219 STBCIX_STDCIX_STHCIX_STWCIX_STSWI
  { 0, 0, 0, 0, 0 }, // 220 SLBIEG
  { 0, 0, 0, 0, 0 }, // 221 STMW
  { 0, 0, 0, 0, 0 }, // 222 TLBIE
  { 1, 239, 241, 1644, 1646 }, // 223 STVEBX_STVEHX_STVEWX_STVX_STVXL
  { 0, 0, 0, 0, 0 }, // 224 STXV_STXVB16X_STXVD2X_STXVH8X_STXVW4X_STXVX
  { 1, 241, 243, 1646, 1648 }, // 225 STXVL_STXVLL
  { 1, 235, 237, 1648, 1650 }, // 226 MTCTR_MTCTR8_MTCTR8loop_MTCTRloop_MTLR_MTLR8
  { 1, 235, 237, 1650, 1652 }, // 227 MFVRSAVE_MFVRSAVEv_MTVRSAVE_MTVRSAVEv
  { 0, 0, 0, 0, 0 }, // 228 MFPMR
  { 0, 0, 0, 0, 0 }, // 229 MTPMR
  { 0, 0, 0, 0, 0 }, // 230 MFTB_MFTB8
  { 1, 235, 237, 1652, 1654 }, // 231 MFCTR_MFCTR8_MFLR_MFLR8_MFSPR_MFSPR8
  { 0, 0, 0, 0, 0 }, // 232 MFMSR
  { 0, 0, 0, 0, 0 }, // 233 MTMSR
  { 0, 0, 0, 0, 0 }, // 234 MTMSRD
  { 1, 235, 237, 1654, 1656 }, // 235 MTSPR_MTSPR8
  { 1, 243, 246, 1656, 1658 }, // 236 DIVW_DIVWO_DIVWU_DIVWUO_MODSW
  { 1, 243, 246, 1658, 1660 }, // 237 DIVWE_DIVWEO_DIVWEU_DIVWEUO_MODSD_MODUD_MODUW
  { 0, 0, 0, 0, 0 }, // 238 DIVD_DIVDO_DIVDU_DIVDUO
  { 0, 0, 0, 0, 0 }, // 239 DIVDE_DIVDEO_DIVDEU_DIVDEUO
  { 1, 243, 246, 1660, 1662 }, // 240 DIVWO_rec_DIVWUO_rec_DIVWU_rec_DIVW_rec
  { 0, 0, 0, 0, 0 }, // 241 DIVD_rec_DIVDO_rec_DIVDU_rec_DIVDUO_rec
  { 1, 243, 246, 1662, 1664 }, // 242 DIVWE_rec_DIVWEO_rec_DIVWEU_rec_DIVWEUO_rec
  { 0, 0, 0, 0, 0 }, // 243 DIVDE_rec_DIVDEO_rec_DIVDEU_rec_DIVDEUO_rec
  { 1, 235, 237, 1664, 1666 }, // 244 MTCRF_MTCRF8
  { 1, 235, 237, 1666, 1668 }, // 245 ADDC8O_rec_ADDC8_rec_ADDCO_rec_ADDC_rec_SUBFC8O_rec_SUBFC8_rec_SUBFCO_rec_SUBFC_rec
  { 0, 0, 0, 0, 0 }, // 246 FABSD_rec_FABSS_rec_FNABSD_rec_FNABSS_rec_FCPSGND_rec_FCPSGNS_rec_FNEGD_rec_FNEGS_rec_FMR_rec
  { 1, 237, 239, 1668, 1670 }, // 247 MCRFS
  { 0, 0, 0, 0, 0 }, // 248 MTFSF_MTFSF_rec_MTFSFI_MTFSFI_rec
  { 0, 0, 0, 0, 0 }, // 249 MTFSFb
  { 0, 0, 0, 0, 0 }, // 250 RLDCL_rec_RLDCR_rec
  { 0, 0, 0, 0, 0 }, // 251 RLDICL_rec_RLDICR_rec_RLDICL_32_rec_RLDIMI_rec
  { 1, 235, 237, 1670, 1672 }, // 252 RLWIMI8_rec_RLWIMI_rec
  { 1, 235, 237, 1672, 1674 }, // 253 RLWINM8_rec_RLWINM_rec_RLWNM8_rec_RLWNM_rec_SLW8_rec_SLW_rec_SRW8_rec_SRW_rec
  { 1, 235, 237, 1674, 1676 }, // 254 SRAWI_rec_SRAW_rec
  { 0, 0, 0, 0, 0 }, // 255 MFFS_MFFSCE_MFFSL_MFFS_rec
  { 1, 235, 237, 1676, 1678 }, // 256 MFCR_MFCR8
  { 0, 0, 0, 0, 0 }, // 257 EXTSWSLI_32_64_rec_SRADI_rec_EXTSWSLI_rec_RLDIC_rec
  { 0, 0, 0, 0, 0 }, // 258 SRAD_rec_SLD_rec_SRD_rec
  { 0, 0, 0, 0, 0 }, // 259 FDIV
  { 0, 0, 0, 0, 0 }, // 260 FDIV_rec
  { 0, 0, 0, 0, 0 }, // 261 XSSQRTDP
  { 0, 0, 0, 0, 0 }, // 262 FSQRT
  { 0, 0, 0, 0, 0 }, // 263 XVSQRTDP
  { 0, 0, 0, 0, 0 }, // 264 XVSQRTSP
  { 0, 0, 0, 0, 0 }, // 265 FSQRT_rec
  { 0, 0, 0, 0, 0 }, // 266 XSSQRTSP
  { 0, 0, 0, 0, 0 }, // 267 FSQRTS
  { 0, 0, 0, 0, 0 }, // 268 FSQRTS_rec
  { 0, 0, 0, 0, 0 }, // 269 XSDIVDP
  { 0, 0, 0, 0, 0 }, // 270 FDIVS
  { 0, 0, 0, 0, 0 }, // 271 FDIVS_rec
  { 0, 0, 0, 0, 0 }, // 272 XSDIVSP
  { 0, 0, 0, 0, 0 }, // 273 XVDIVSP
  { 0, 0, 0, 0, 0 }, // 274 XVDIVDP
  { 0, 0, 0, 0, 0 }, // 275 LFSU
  { 0, 0, 0, 0, 0 }, // 276 LFSUX
  { 0, 0, 0, 0, 0 }, // 277 STFDU_STFDUX_STFSU_STFSUX
  { 1, 239, 241, 1678, 1681 }, // 278 STBU_STBU8_STDU_STHU_STHU8_STWU_STWU8
  { 0, 0, 0, 0, 0 }, // 279 STBUX_STBUX8_STDUX_STHUX_STHUX8_STWUX_STWUX8
  { 1, 241, 243, 1681, 1684 }, // 280 LBZU_LBZU8
  { 0, 0, 0, 0, 0 }, // 281 LBZUX_LBZUX8
  { 0, 0, 0, 0, 0 }, // 282 LDU
  { 0, 0, 0, 0, 0 }, // 283 LDUX
  { 0, 0, 0, 0, 0 }, // 284 LFDU
  { 0, 0, 0, 0, 0 }, // 285 LFDUX
  { 0, 0, 0, 0, 0 }, // 286 VPMSUMB_VPMSUMD_VPMSUMH_VPMSUMW_VCIPHER_VCIPHERLAST_VNCIPHER_VNCIPHERLAST_VSBOX
  { 1, 237, 239, 1684, 1686 }, // 287 BCCCTR_BCCCTR8_BCCCTRL_BCCCTRL8_BCCL_BCCLA_BCCLR_BCCLRL_BCCTR_BCCTR8_BCCTR8n_BCCTRL_BCCTRL8_BCCTRL8n_BCCTRLn_BCCTRn_BDNZ_BDNZ8_BDNZA_BDNZAm_BDNZAp_BDNZm_BDNZp_BDZ_BDZ8_BDZA_BDZAm_BDZAp_BDZm_BDZp_BDNZL_BDNZLA_BDNZLAm_BDNZLAp_BDNZLR_BDNZLR8_BDNZLRL_BDNZLRLm_BDNZLRLp_BDNZLRm_BDNZLRp_BDNZLm_BDNZLp_BDZL_BDZLA_BDZLAm_BDZLAp_BDZLR_BDZLR8_BDZLRL_BDZLRLm_BDZLRLp_BDZLRm_BDZLRp_BDZLm_BDZLp_BL_BL_NOP_BL_TLS_BL8_BL8_NOP_BL8_NOP_TLS_BL8_TLS_BL8_TLS__BLA_BLA8_BLA8_NOP_BLR_BLR8_BLRL_TAILB_TAILB8_TAILBA_TAILBA8_TAILBCTR_TAILBCTR8_gBC_gBCA_gBCAat_gBCCTR_gBCCTRL_gBCL_gBCLA_gBCLAat_gBCLR_gBCLRL_gBCLat_gBCat_BCLR_BCLRL_BCLRLn_BCLRn_BCTR_BCTR8_BCTRL_BCTRL8_B_BA_BC_BCC_BCCA_BCL_BCLalways_BCLn_BCTRL8_LDinto_toc_BCTRL_LWZinto_toc_BCn_CTRL_DEP
  { 1, 237, 239, 1686, 1688 }, // 288 ADDPCIS
  { 1, 241, 243, 1688, 1690 }, // 289 LDAT_LWAT
  { 1, 239, 241, 1690, 1692 }, // 290 STDAT_STWAT
  { 1, 235, 237, 1692, 1694 }, // 291 BRINC
  { 0, 0, 0, 0, 0 }, // 292 EVABS_EVEQV_EVNAND_EVNEG_EVADDIW_EVADDW_EVAND_EVANDC_EVCMPEQ_EVCMPGTS_EVCMPGTU_EVCMPLTS_EVCMPLTU_EVCNTLSW_EVCNTLZW_EVEXTSB_EVEXTSH_EVMERGEHI_EVMERGEHILO_EVMERGELO_EVMERGELOHI_EVNOR_EVOR_EVORC_EVXOR_EVRLW_EVRLWI_EVRNDW_EVSLW_EVSLWI_EVSPLATFI_EVSPLATI_EVSRWIS_EVSRWIU_EVSRWS_EVSRWU_EVSUBFW_EVSUBIFW
  { 0, 0, 0, 0, 0 }, // 293 EVMRA_EVADDSMIAAW_EVADDSSIAAW_EVADDUMIAAW_EVADDUSIAAW_EVDIVWS_EVDIVWU_EVMHEGSMFAA_EVMHEGSMFAN_EVMHEGSMIAA_EVMHEGSMIAN_EVMHEGUMIAA_EVMHEGUMIAN_EVMHESMF_EVMHESMFA_EVMHESMFAAW_EVMHESMFANW_EVMHESMI_EVMHESMIA_EVMHESMIAAW_EVMHESMIANW_EVMHESSF_EVMHESSFA_EVMHESSFAAW_EVMHESSFANW_EVMHESSIAAW_EVMHESSIANW_EVMHEUMI_EVMHEUMIA_EVMHEUMIAAW_EVMHEUMIANW_EVMHEUSIAAW_EVMHEUSIANW_EVMHOGSMFAA_EVMHOGSMFAN_EVMHOGSMIAA_EVMHOGSMIAN_EVMHOGUMIAA_EVMHOGUMIAN_EVMHOSMF_EVMHOSMFA_EVMHOSMFAAW_EVMHOSMFANW_EVMHOSMI_EVMHOSMIA_EVMHOSMIAAW_EVMHOSMIANW_EVMHOSSF_EVMHOSSFA_EVMHOSSFAAW_EVMHOSSFANW_EVMHOSSIAAW_EVMHOSSIANW_EVMHOUMI_EVMHOUMIA_EVMHOUMIAAW_EVMHOUMIANW_EVMHOUSIAAW_EVMHOUSIANW_EVMWHSMF_EVMWHSMFA_EVMWHSMI_EVMWHSMIA_EVMWHSSF_EVMWHSSFA_EVMWHUMI_EVMWHUMIA_EVMWLSMIAAW_EVMWLSMIANW_EVMWLSSIAAW_EVMWLSSIANW_EVMWLUMI_EVMWLUMIA_EVMWLUMIAAW_EVMWLUMIANW_EVMWLUSIAAW_EVMWLUSIANW_EVMWSMF_EVMWSMFA_EVMWSMFAA_EVMWSMFAN_EVMWSMI_EVMWSMIA_EVMWSMIAA_EVMWSMIAN_EVMWSSF_EVMWSSFA_EVMWSSFAA_EVMWSSFAN_EVMWUMI_EVMWUMIA_EVMWUMIAA_EVMWUMIAN_EVSUBFSMIAAW_EVSUBFSSIAAW_EVSUBFUMIAAW_EVSUBFUSIAAW
  { 1, 241, 243, 1694, 1696 }, // 294 EVLDD_EVLDDX_EVLDH_EVLDHX_EVLDW_EVLDWX_EVLHHESPLAT_EVLHHESPLATX_EVLHHOSSPLAT_EVLHHOSSPLATX_EVLHHOUSPLAT_EVLHHOUSPLATX_EVLWHE_EVLWHEX_EVLWHOS_EVLWHOSX_EVLWHOU_EVLWHOUX_EVLWHSPLAT_EVLWHSPLATX_EVLWWSPLAT_EVLWWSPLATX
  { 1, 239, 241, 1696, 1698 }, // 295 EVSTDD_EVSTDDX_EVSTDH_EVSTDHX_EVSTDW_EVSTDWX_EVSTWHE_EVSTWHEX_EVSTWHO_EVSTWHOX_EVSTWWE_EVSTWWEX_EVSTWWO_EVSTWWOX
  { 1, 237, 239, 1698, 1700 }, // 296 HRFID_ATTN_CLRBHRB_MFBHRBE_NAP_RFCI_RFDI_RFMCI_SC
  { 0, 0, 0, 0, 0 }, // 297 RFI
  { 0, 0, 0, 0, 0 }, // 298 RFID
  { 1, 241, 243, 1700, 1702 }, // 299 DSS_DSSALL_DST_DST64_DSTST_DSTST64_DSTSTT_DSTSTT64_DSTT_DSTT64_ICBLQ_LBEPX_LHEPX_LWEPX_TLBIVAX_TLBLD_TLBLI_TLBRE_TLBRE2_TLBSX_TLBSX2_TLBSX2D_TLBWE_TLBWE2_MBAR_TRAP_DCCCI_ICCCI
  { 1, 239, 241, 1702, 1704 }, // 300 ICBLC_STBEPX_STHEPX_STWEPX
  { 0, 0, 0, 0, 0 }, // 301 LFDEPX
  { 0, 0, 0, 0, 0 }, // 302 STFDEPX
  { 0, 0, 0, 0, 0 }, // 303 MFSR_MFSRIN
  { 0, 0, 0, 0, 0 }, // 304 MTSR_MTSRIN
  { 1, 235, 237, 1704, 1706 }, // 305 MFDCR
  { 1, 235, 237, 1706, 1708 }, // 306 MTDCR
  { 1, 235, 237, 1708, 1710 }, // 307 NOP_GT_PWR6_NOP_GT_PWR7
  { 0, 0, 0, 0, 0 }, // 308 TLBIA
  { 0, 0, 0, 0, 0 }, // 309 WRTEE_WRTEEI
  { 0, 0, 0, 0, 0 }, // 310 MSYNC
  { 0, 0, 0, 0, 0 }, // 311 SLBSYNC
  { 0, 0, 0, 0, 0 }, // 312 SLBFEE_rec
  { 0, 0, 0, 0, 0 }, // 313 STOP
  { 1, 239, 241, 1710, 1712 }, // 314 DCBA_DCBI
  { 0, uint16_t(~0U), uint16_t(~0U), uint16_t(~0U), uint16_t(~0U) }// end marker
};

static const llvm::InstrItinerary PPCE200Z4Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 0, 0, 0, 0, 0 }, // 1 IIC_LdStSync
  { 1, 252, 257, 1712, 1717 }, // 2 IIC_IntSimple
  { 1, 252, 257, 1717, 1722 }, // 3 IIC_IntGeneral
  { 1, 257, 260, 1722, 1725 }, // 4 IIC_BrB
  { 0, 0, 0, 0, 0 }, // 5 IIC_VecFP
  { 1, 252, 257, 1725, 1730 }, // 6 IIC_IntCompare
  { 0, 0, 0, 0, 0 }, // 7 IIC_SprABORT
  { 0, 0, 0, 0, 0 }, // 8 IIC_LdStCOPY
  { 0, 0, 0, 0, 0 }, // 9 IIC_LdStPASTE
  { 1, 257, 260, 1730, 1734 }, // 10 IIC_BrCR
  { 0, 0, 0, 0, 0 }, // 11 IIC_LdStLD
  { 0, 0, 0, 0, 0 }, // 12 IIC_LdStDCBF
  { 1, 260, 265, 1734, 1739 }, // 13 IIC_LdStLoad
  { 0, 0, 0, 0, 0 }, // 14 IIC_IntDivD
  { 1, 265, 269, 1739, 1742 }, // 15 IIC_IntDivW
  { 0, 0, 0, 0, 0 }, // 16 IIC_FPDGeneral
  { 1, 269, 273, 1742, 1746 }, // 17 IIC_FPAddSub
  { 0, 0, 0, 0, 0 }, // 18 IIC_FPDivD
  { 0, 0, 0, 0, 0 }, // 19 IIC_FPSGeneral
  { 1, 269, 273, 1746, 1750 }, // 20 IIC_FPCompare
  { 1, 269, 273, 1750, 1754 }, // 21 IIC_FPGeneral
  { 1, 273, 276, 1754, 1757 }, // 22 IIC_VecGeneral
  { 1, 276, 280, 1757, 1760 }, // 23 IIC_VecComplex
  { 1, 280, 284, 1760, 1764 }, // 24 IIC_LdStStore
  { 0, 0, 0, 0, 0 }, // 25 IIC_IntRotateDI
  { 1, 284, 288, 1764, 1768 }, // 26 IIC_FPDivS
  { 0, 0, 0, 0, 0 }, // 27 IIC_FPFused
  { 0, 0, 0, 0, 0 }, // 28 IIC_FPSqrtD
  { 0, 0, 0, 0, 0 }, // 29 IIC_FPSqrtS
  { 0, 0, 0, 0, 0 }, // 30 IIC_LdStICBI
  { 1, 252, 257, 1768, 1774 }, // 31 IIC_IntISEL
  { 0, 0, 0, 0, 0 }, // 32 IIC_SprISYNC
  { 0, 0, 0, 0, 0 }, // 33 IIC_LdStLWARX
  { 2, 288, 293, 1774, 1779 }, // 34 IIC_LdStLoadUpd
  { 2, 288, 293, 1779, 1784 }, // 35 IIC_LdStLoadUpdX
  { 0, 0, 0, 0, 0 }, // 36 IIC_LdStLDARX
  { 0, 0, 0, 0, 0 }, // 37 IIC_LdStLDU
  { 0, 0, 0, 0, 0 }, // 38 IIC_LdStLDUX
  { 0, 0, 0, 0, 0 }, // 39 IIC_LdStLFD
  { 0, 0, 0, 0, 0 }, // 40 IIC_LdStLFDU
  { 0, 0, 0, 0, 0 }, // 41 IIC_LdStLFDUX
  { 0, 0, 0, 0, 0 }, // 42 IIC_LdStLHA
  { 0, 0, 0, 0, 0 }, // 43 IIC_LdStLHAU
  { 0, 0, 0, 0, 0 }, // 44 IIC_LdStLHAUX
  { 0, 0, 0, 0, 0 }, // 45 IIC_LdStLMW
  { 0, 0, 0, 0, 0 }, // 46 IIC_LdStLWA
  { 0, 0, 0, 0, 0 }, // 47 IIC_IntMulHD
  { 1, 257, 260, 1784, 1787 }, // 48 IIC_BrMCR
  { 1, 293, 296, 1787, 1791 }, // 49 IIC_BrMCRX
  { 0, 0, 0, 0, 0 }, // 50 IIC_SprMFCR
  { 1, 252, 257, 1791, 1796 }, // 51 IIC_SprMFSPR
  { 0, 0, 0, 0, 0 }, // 52 IIC_IntMFFS
  { 0, 0, 0, 0, 0 }, // 53 IIC_SprMFMSR
  { 0, 0, 0, 0, 0 }, // 54 IIC_SprMFCRF
  { 0, 0, 0, 0, 0 }, // 55 IIC_SprMFPMR
  { 0, 0, 0, 0, 0 }, // 56 IIC_SprMFSR
  { 0, 0, 0, 0, 0 }, // 57 IIC_SprMFTB
  { 0, 0, 0, 0, 0 }, // 58 IIC_SprMSGSYNC
  { 1, 252, 257, 1796, 1801 }, // 59 IIC_SprMTSPR
  { 0, 0, 0, 0, 0 }, // 60 IIC_IntMTFSB0
  { 0, 0, 0, 0, 0 }, // 61 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 62 IIC_SprMTMSRD
  { 0, 0, 0, 0, 0 }, // 63 IIC_SprMTPMR
  { 0, 0, 0, 0, 0 }, // 64 IIC_SprMTSR
  { 1, 296, 301, 1801, 1806 }, // 65 IIC_IntMulHW
  { 1, 296, 301, 1806, 1811 }, // 66 IIC_IntMulHWU
  { 1, 296, 301, 1811, 1816 }, // 67 IIC_IntMulLI
  { 0, 0, 0, 0, 0 }, // 68 IIC_VecPerm
  { 0, 0, 0, 0, 0 }, // 69 IIC_LdStSTFD
  { 0, 0, 0, 0, 0 }, // 70 IIC_LdStSTFDU
  { 0, 0, 0, 0, 0 }, // 71 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 72 IIC_IntRFID
  { 0, 0, 0, 0, 0 }, // 73 IIC_IntRotateD
  { 1, 252, 257, 1816, 1821 }, // 74 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 75 IIC_SprSLBFEE
  { 0, 0, 0, 0, 0 }, // 76 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 77 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprSLBIEG
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprSLBMFEV
  { 0, 0, 0, 0, 0 }, // 81 IIC_SprSLBMTE
  { 0, 0, 0, 0, 0 }, // 82 IIC_SprSLBSYNC
  { 1, 252, 257, 1821, 1826 }, // 83 IIC_IntShift
  { 0, 0, 0, 0, 0 }, // 84 IIC_LdStSTWCX
  { 2, 301, 305, 1826, 1830 }, // 85 IIC_LdStSTU
  { 2, 301, 305, 1830, 1834 }, // 86 IIC_LdStSTUX
  { 0, 0, 0, 0, 0 }, // 87 IIC_LdStSTD
  { 0, 0, 0, 0, 0 }, // 88 IIC_LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 89 IIC_SprSTOP
  { 0, 0, 0, 0, 0 }, // 90 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 91 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 92 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 93 IIC_SprTLBIEL
  { 0, 0, 0, 0, 0 }, // 94 IIC_SprTLBSYNC
  { 1, 305, 310, 1834, 1838 }, // 95 IIC_IntTrapW
  { 0, 0, 0, 0, 0 }, // 96 IIC_VecFPCompare
  { 1, 273, 276, 1838, 1841 }, // 97 VADDUBM_VADDUDM_VADDUHM_VADDUWM_VEXTSB2D_VEXTSB2Ds_VEXTSB2W_VEXTSB2Ws_VEXTSH2D_VEXTSH2Ds_VEXTSH2W_VEXTSH2Ws_VEXTSW2D_VEXTSW2Ds_VSLD_VSRD_VSUBUBM_VSUBUDM_VSUBUHM_VSUBUWM_VPOPCNTB_VPOPCNTH_VSRAD_MTVSRDD_VEQV_VNAND_VNEGD_VNEGW_VORC_XXLAND_XXLANDC_XXLEQV_XXLEQVOnes_XXLNAND_XXLNOR_XXLOR_XXLORf_XXLORC_XXLXOR_XXLXORdpz_XXLXORspz_XXLXORz
  { 0, 0, 0, 0, 0 }, // 98 VAND_VANDC_V_SET0_V_SET0B_V_SET0H_VSLB_VSLH_VSLW_VSRB_VSRH_VSRW_VRLB_VRLD_VRLH_VRLW_VSRAB_VSRAH_VSRAW_XVABSDP_XVABSSP_XVNABSDP_XVNABSSP_XVCPSGNDP_XVCPSGNSP_XVIEXPDP_XVIEXPSP_XVXEXPDP_XVXEXPSP_VRLDMI_VRLDNM_VRLWMI_VRLWNM_VMRGEW_VMRGOW_VNOR_VOR_VSEL_VXOR_XVNEGDP_XVNEGSP_XSABSQP_XSCPSGNQP_XSIEXPQP_XSNABSQP_XSNEGQP_XSXEXPQP
  { 0, 0, 0, 0, 0 }, // 99 XXSEL
  { 1, 252, 257, 1841, 1846 }, // 100 TABORTDC_TABORTDCI_TABORTWC_TABORTWCI
  { 0, 0, 0, 0, 0 }, // 101 MTFSB0_MTFSB1
  { 0, 0, 0, 0, 0 }, // 102 MFFSCDRN_MFFSCDRNI_MFFSCRN_MFFSCRNI
  { 1, 252, 257, 1846, 1851 }, // 103 CMPRB_CMPRB8_CMPEQB
  { 0, 0, 0, 0, 0 }, // 104 TD_TDI
  { 1, 305, 310, 1851, 1855 }, // 105 TW_TWI
  { 1, 269, 273, 1855, 1859 }, // 106 FCMPUD_FCMPUS_FTDIV_FTSQRT
  { 0, 0, 0, 0, 0 }, // 107 XSTSTDCDP_XSTSTDCSP
  { 0, 0, 0, 0, 0 }, // 108 XSMAXCDP_XSMAXDP_XSMAXJDP_XSMINCDP_XSMINDP_XSMINJDP_XSXSIGDP_XSCVSPDPN
  { 1, 269, 273, 1859, 1863 }, // 109 XSCMPEQDP_XSCMPEXPDP_XSCMPGEDP_XSCMPGTDP_XSCMPODP_XSCMPUDP_XSTDIVDP_XSTSQRTDP
  { 1, 252, 257, 1863, 1868 }, // 110 CNTLZD_CNTLZD_rec_CNTLZW_CNTLZW8_CNTLZW8_rec_CNTLZW_rec_CNTTZD_CNTTZD_rec_CNTTZW_CNTTZW8_CNTTZW8_rec_CNTTZW_rec_POPCNTD_POPCNTW_CMPB_CMPB8_SETB_SETB8_BPERMD
  { 0, 0, 0, 0, 0 }, // 111 SLD_SRD_SRAD
  { 0, 0, 0, 0, 0 }, // 112 SRADI_EXTSWSLI_32_64_EXTSWSLI_SRADI_32_RLDIC
  { 1, 273, 276, 1868, 1871 }, // 113 MFVRD_MFVSRD_MTVRD_MTVSRD_MTVRWA_MTVRWZ_MTVSRWA_MTVSRWZ_MFVSRWZ_MFVRWZ
  { 1, 252, 257, 1871, 1876 }, // 114 CMPLW_CMPLWI_CMPW_CMPWI_CMPD_CMPDI_CMPLD_CMPLDI
  { 1, 252, 257, 1876, 1881 }, // 115 SUBFC_SUBFC8_SUBFC8O_SUBFCO_SUBFIC_SUBFIC8_ANDI8_rec_ANDIS8_rec_ANDIS_rec_ANDI_rec_ADDC_ADDC8_ADDC8O_ADDCO_ADDIC_ADDIC8_ADDIC_rec_ADDE_ADDE8_ADDE8O_ADDE8O_rec_ADDE8_rec_ADDEO_ADDEO_rec_ADDE_rec_ADDME_ADDME8_ADDME8O_ADDME8O_rec_ADDME8_rec_ADDMEO_ADDMEO_rec_ADDME_rec_ADDZE_ADDZE8_ADDZE8O_ADDZE8O_rec_ADDZE8_rec_ADDZEO_ADDZEO_rec_ADDZE_rec_SUBF_SUBF8_SUBF8O_SUBF8O_rec_SUBF8_rec_SUBFE_SUBFE8_SUBFE8O_SUBFE8O_rec_SUBFE8_rec_SUBFEO_SUBFEO_rec_SUBFE_rec_SUBFME_SUBFME8_SUBFME8O_SUBFME8O_rec_SUBFME8_rec_SUBFMEO_SUBFMEO_rec_SUBFME_rec_SUBFO_SUBFO_rec_SUBFZE_SUBFZE8_SUBFZE8O_SUBFZE8O_rec_SUBFZE8_rec_SUBFZEO_SUBFZEO_rec_SUBFZE_rec_SUBF_rec_POPCNTB_LA
  { 1, 252, 257, 1881, 1886 }, // 116 ADD4_ADD4O_ADD4O_rec_ADD4_rec_ADD8_ADD8O_ADD8O_rec_ADD8_rec_NEG_NEG8_NEG8O_NEG8O_rec_NEG8_rec_NEGO_NEGO_rec_NEG_rec_ADDI_ADDI8_ADDIS_ADDIS8_LI_LI8_LIS_LIS8_OR_OR8_OR8_rec_ORI_ORI8_ORIS_ORIS8_OR_rec_XOR_XOR8_XOR8_rec_XORI_XORI8_XORIS_XORIS8_XOR_rec_NAND_NAND8_NAND8_rec_NAND_rec_AND_AND8_AND8_rec_ANDC_ANDC8_ANDC8_rec_ANDC_rec_AND_rec_NOR_NOR8_NOR8_rec_NOR_rec_ORC_ORC8_ORC8_rec_ORC_rec_EQV_EQV8_EQV8_rec_EQV_rec_EXTSB_EXTSB8_EXTSB8_32_64_EXTSB8_rec_EXTSB_rec_EXTSH_EXTSH8_EXTSH8_32_64_EXTSH8_rec_EXTSH_rec_EXTSW_EXTSW_32_EXTSW_32_64_EXTSW_32_64_rec_EXTSW_rec_ADD4TLS_ADD8TLS_ADD8TLS__NOP
  { 0, 0, 0, 0, 0 }, // 117 ADDIStocHA_ADDIStocHA8_ADDItocL_COPY
  { 1, 257, 260, 1886, 1889 }, // 118 MCRF
  { 1, 293, 296, 1889, 1893 }, // 119 MCRXRX
  { 0, 0, 0, 0, 0 }, // 120 XSNABSDP_XSXEXPDP_XSABSDP_XSNEGDP_XSCPSGNDP
  { 1, 257, 260, 1893, 1896 }, // 121 RFEBB
  { 1, 252, 257, 1896, 1901 }, // 122 TBEGIN_TRECHKPT
  { 1, 260, 265, 1901, 1906 }, // 123 WAIT
  { 0, 0, 0, 0, 0 }, // 124 RLDCL_RLDCR
  { 1, 252, 257, 1906, 1911 }, // 125 RLWIMI_RLWIMI8
  { 0, 0, 0, 0, 0 }, // 126 RLDICL_RLDICL_32_RLDICL_32_64_RLDICR_RLDICR_32_RLDIMI
  { 0, 0, 0, 0, 0 }, // 127 MFOCRF_MFOCRF8
  { 1, 293, 296, 1911, 1915 }, // 128 MTOCRF_MTOCRF8
  { 1, 257, 260, 1915, 1919 }, // 129 CR6SET_CR6UNSET_CRSET_CRUNSET_CRAND_CRANDC_CRNAND_CRNOR_CROR_CRORC_CREQV_CRXOR
  { 1, 252, 257, 1919, 1924 }, // 130 SLW_SLW8_SRW_SRW8_RLWINM_RLWINM8_RLWNM_RLWNM8
  { 1, 269, 273, 1924, 1928 }, // 131 FABSD_FABSS_FNABSD_FNABSS_FNEGD_FNEGS_FCPSGND_FCPSGNS_FMR
  { 1, 252, 257, 1928, 1933 }, // 132 SRAW_SRAWI
  { 1, 252, 257, 1933, 1939 }, // 133 ISEL_ISEL8
  { 0, 0, 0, 0, 0 }, // 134 XSIEXPDP
  { 1, 252, 257, 1939, 1944 }, // 135 TRECLAIM_TSR_TABORT
  { 1, 280, 284, 1944, 1948 }, // 136 MFVSCR
  { 1, 260, 265, 1948, 1953 }, // 137 MTVSCR
  { 0, 0, 0, 0, 0 }, // 138 VCMPNEZB_VCMPNEZH_VCMPNEZW_VCMPEQUB_VCMPEQUD_VCMPEQUH_VCMPEQUW_VCMPNEB_VCMPNEH_VCMPNEW_VCMPEQFP_VCMPEQFP_rec_VCMPGEFP_VCMPGEFP_rec_VCMPGTFP_VCMPGTFP_rec_VCMPBFP_VCMPBFP_rec_VCMPGTSB_VCMPGTSB_rec_VCMPGTSD_VCMPGTSD_rec_VCMPGTSH_VCMPGTSH_rec_VCMPGTSW_VCMPGTSW_rec_VCMPGTUB_VCMPGTUB_rec_VCMPGTUD_VCMPGTUD_rec_VCMPGTUH_VCMPGTUH_rec_VCMPGTUW_VCMPGTUW_rec_VCMPNEB_rec_VCMPNEH_rec_VCMPNEW_rec_VCMPNEZB_rec_VCMPNEZH_rec_VCMPNEZW_rec_VCMPEQUB_rec_VCMPEQUD_rec_VCMPEQUH_rec_VCMPEQUW_rec_XVCMPEQDP_XVCMPEQDP_rec_XVCMPEQSP_XVCMPEQSP_rec_XVCMPGEDP_XVCMPGEDP_rec_XVCMPGESP_XVCMPGESP_rec_XVCMPGTDP_XVCMPGTDP_rec_XVCMPGTSP_XVCMPGTSP_rec
  { 1, 273, 276, 1953, 1956 }, // 139 VABSDUB_VABSDUH_VABSDUW_VCLZB_VCLZD_VCLZH_VCLZW_VCTZB_VCTZD_VCTZH_VCTZW_VPOPCNTW_VPOPCNTD_VPRTYBD_VPRTYBW
  { 0, 0, 0, 0, 0 }, // 140 VADDUBS_VADDUHS_VADDUWS_VAVGSB_VAVGSH_VAVGSW_VAVGUB_VAVGUH_VAVGUW_VADDSBS_VADDSHS_VADDSWS_VMAXFP_VMINFP_VMAXSB_VMAXSD_VMAXSH_VMAXSW_VMAXUB_VMAXUD_VMAXUH_VMAXUW_VMINSB_VMINSD_VMINSH_VMINSW_VMINUB_VMINUD_VMINUH_VMINUW_VBPERMD_VADDCUW_VSHASIGMAD_VSHASIGMAW_VSUBSBS_VSUBSHS_VSUBSWS_VSUBUBS_VSUBUHS_VSUBUWS_VSUBCUW_XVMAXDP_XVMAXSP_XVMINDP_XVMINSP_XVTSTDCDP_XVTSTDCSP_XVXSIGDP_XVXSIGSP
  { 1, 269, 273, 1956, 1960 }, // 141 XVTDIVDP_XVTDIVSP_XVTSQRTDP_XVTSQRTSP
  { 0, 0, 0, 0, 0 }, // 142 VADDFP_VCTSXS_VCTSXS_0_VCTUXS_VCTUXS_0_VEXPTEFP_VLOGEFP_VMADDFP_VMHADDSHS_VNMSUBFP_VREFP_VRFIM_VRFIN_VRFIP_VRFIZ_VRSQRTEFP_XVADDDP_XVADDSP_XVCVDPSP_XVCVDPSXDS_XVCVDPSXWS_XVCVDPUXDS_XVCVDPUXWS_XVCVHPSP_XVCVSPDP_XVCVSPHP_XVCVSPSXDS_XVCVSPSXWS_XVCVSPUXDS_XVCVSPUXWS_XVCVSXDDP_XVCVSXDSP_XVCVSXWDP_XVCVSXWSP_XVCVUXDDP_XVCVUXDSP_XVCVUXWDP_XVCVUXWSP_XVMADDADP_XVMADDASP_XVMADDMDP_XVMADDMSP_XVMSUBADP_XVMSUBASP_XVMSUBMDP_XVMSUBMSP_XVMULDP_XVMULSP_XVNMADDADP_XVNMADDASP_XVNMADDMDP_XVNMADDMSP_XVNMSUBADP_XVNMSUBASP_XVNMSUBMDP_XVNMSUBMSP_XVRDPI_XVRDPIC_XVRDPIM_XVRDPIP_XVRDPIZ_XVREDP_XVRESP_XVRSPI_XVRSPIC_XVRSPIM_XVRSPIP_XVRSPIZ_XVRSQRTEDP_XVRSQRTESP_XVSUBDP_XVSUBSP_VCFSX_VCFSX_0_VCFUX_VCFUX_0_VMHRADDSHS_VMLADDUHM_VMSUMMBM_VMSUMSHM_VMSUMSHS_VMSUMUBM_VMSUMUHM_VMSUMUDM_VMSUMUHS_VMULESB_VMULESH_VMULESW_VMULEUB_VMULEUH_VMULEUW_VMULOSB_VMULOSH_VMULOSW_VMULOUB_VMULOUH_VMULOUW_VSUM2SWS_VSUM4SBS_VSUM4SHS_VSUM4UBS_VSUMSWS
  { 1, 273, 276, 1960, 1963 }, // 143 VSUBFP_VMULUWM
  { 0, 0, 0, 0, 0 }, // 144 MADDHD_MADDHDU_MADDLD_MADDLD8_MULLD_MULLDO
  { 1, 296, 301, 1963, 1968 }, // 145 MULHD_MULHW_MULLW_MULLWO
  { 1, 296, 301, 1968, 1973 }, // 146 MULHDU_MULHWU
  { 1, 296, 301, 1973, 1978 }, // 147 MULLI_MULLI8
  { 1, 269, 273, 1978, 1982 }, // 148 FRSP_FRIMD_FRIMS_FRIND_FRINS_FRIPD_FRIPS_FRIZD_FRIZS_FRE_FRES_FADDS_FMSUBS_FMADDS_FSUBS_FCFID_FCFIDS_FCFIDU_FCFIDUS_FCTID_FCTIDU_FCTIDUZ_FCTIDZ_FCTIW_FCTIWU_FCTIWUZ_FCTIWZ_FRSQRTE_FRSQRTES_FNMADDS_FNMSUBS_FSELD_FSELS_FMULS
  { 1, 269, 273, 1982, 1986 }, // 149 FADD_FSUB
  { 0, 0, 0, 0, 0 }, // 150 FMSUB_FMADD_FNMADD_FNMSUB_FMUL
  { 0, 0, 0, 0, 0 }, // 151 XSMADDADP_XSMADDASP_XSMADDMDP_XSMADDMSP_XSMSUBADP_XSMSUBASP_XSMSUBMDP_XSMSUBMSP_XSMULDP_XSMULSP_XSNMADDADP_XSNMADDASP_XSNMADDMDP_XSNMADDMSP_XSNMSUBADP_XSNMSUBASP_XSNMSUBMDP_XSNMSUBMSP
  { 1, 269, 273, 1986, 1990 }, // 152 FSELD_rec_FSELS_rec
  { 1, 296, 301, 1990, 1995 }, // 153 MULHDU_rec_MULHWU_rec
  { 1, 296, 301, 1995, 2000 }, // 154 MULHD_rec_MULHW_rec_MULLWO_rec_MULLW_rec
  { 0, 0, 0, 0, 0 }, // 155 MULLDO_rec_MULLD_rec
  { 1, 269, 273, 2000, 2004 }, // 156 FRIMD_rec_FRIMS_rec_FRIND_rec_FRINS_rec_FRIPD_rec_FRIPS_rec_FRIZD_rec_FRIZS_rec_FRES_rec_FRE_rec_FADDS_rec_FSUBS_rec_FMSUBS_rec_FNMSUBS_rec_FMADDS_rec_FNMADDS_rec_FCFIDS_rec_FCFIDUS_rec_FCFIDU_rec_FCFID_rec_FCTIDUZ_rec_FCTIDU_rec_FCTIDZ_rec_FCTID_rec_FCTIWUZ_rec_FCTIWU_rec_FCTIWZ_rec_FCTIW_rec_FMULS_rec_FRSQRTES_rec_FRSQRTE_rec_FRSP_rec
  { 1, 269, 273, 2004, 2008 }, // 157 FADD_rec_FSUB_rec
  { 0, 0, 0, 0, 0 }, // 158 FMSUB_rec_FNMSUB_rec_FMADD_rec_FNMADD_rec_FMUL_rec
  { 0, 0, 0, 0, 0 }, // 159 XSADDDP_XSADDSP_XSCVDPHP_XSCVDPSP_XSCVDPSXDS_XSCVDPSXDSs_XSCVDPSXWS_XSCVDPUXDS_XSCVDPUXDSs_XSCVDPUXWS_XSCVDPSXWSs_XSCVDPUXWSs_XSCVHPDP_XSCVSPDP_XSCVSXDDP_XSCVSXDSP_XSCVUXDDP_XSCVUXDSP_XSRDPI_XSRDPIC_XSRDPIM_XSRDPIP_XSRDPIZ_XSREDP_XSRESP_XSRSQRTEDP_XSRSQRTESP_XSSUBDP_XSSUBSP_XSCVDPSPN_XSRSP
  { 1, 260, 265, 2008, 2013 }, // 160 LVSL_LVSR
  { 0, 0, 0, 0, 0 }, // 161 VSPLTISB_VSPLTISH_VSPLTISW_VSPLTB_VSPLTBs_VSPLTH_VSPLTHs_VSPLTW_XXMRGHW_XXMRGLW_XXPERM_XXPERMR_XXSLDWI_XXSLDWIs_XXSPLTIB_XXSPLTW_XXSPLTWs_XXPERMDI_XXPERMDIs
  { 0, 0, 0, 0, 0 }, // 162 V_SETALLONES_V_SETALLONESB_V_SETALLONESH_VBPERMQ_VGBBD_VMRGHB_VMRGHH_VMRGHW_VMRGLB_VMRGLH_VMRGLW_VPERM_VPERMR_VPERMXOR_VPKPX_VPKSDSS_VPKSDUS_VPKSHSS_VPKSHUS_VPKSWSS_VPKSWUS_VPKUDUM_VPKUDUS_VPKUHUM_VPKUHUS_VPKUWUM_VPKUWUS_VSL_VSLDOI_VSLO_VSLV_VSR_VSRO_VSRV_VUPKHPX_VUPKHSB_VUPKHSH_VUPKHSW_VUPKLPX_VUPKLSB_VUPKLSH_VUPKLSW_XXBRD_XXBRH_XXBRQ_XXBRW_XXEXTRACTUW_XXINSERTW_VADDCUQ_VADDECUQ_VADDEUQM_VMUL10CUQ_VMUL10ECUQ_VMUL10EUQ_VMUL10UQ_VSUBCUQ_VSUBECUQ_VSUBEUQM_XSTSTDCQP_XSXSIGQP_BCDCFN_rec_BCDCFZ_rec_BCDCPSGN_rec_BCDCTN_rec_BCDCTZ_rec_BCDSETSGN_rec_BCDS_rec_BCDTRUNC_rec_BCDUS_rec_BCDUTRUNC_rec
  { 1, 273, 276, 2013, 2016 }, // 163 VEXTRACTUB_VEXTRACTUH_VEXTRACTUW_VINSERTB_VINSERTD_VINSERTH_VINSERTW_MFVSRLD_MTVSRWS_VCLZLSBB_VCTZLSBB_VEXTRACTD_VEXTUBLX_VEXTUBRX_VEXTUHLX_VEXTUHRX_VEXTUWLX_VEXTUWRX_VPRTYBQ_VADDUQM_VSUBUQM
  { 1, 269, 273, 2016, 2020 }, // 164 XSCMPEXPQP_XSCMPOQP_XSCMPUQP
  { 0, 0, 0, 0, 0 }, // 165 BCDSR_rec_XSADDQP_XSADDQPO_XSCVDPQP_XSCVQPDP_XSCVQPDPO_XSCVQPSDZ_XSCVQPSWZ_XSCVQPUDZ_XSCVQPUWZ_XSCVSDQP_XSCVUDQP_XSRQPI_XSRQPIX_XSRQPXP_XSSUBQP_XSSUBQPO
  { 0, 0, 0, 0, 0 }, // 166 BCDCTSQ_rec
  { 0, 0, 0, 0, 0 }, // 167 XSMADDQP_XSMADDQPO_XSMSUBQP_XSMSUBQPO_XSMULQP_XSMULQPO_XSNMADDQP_XSNMADDQPO_XSNMSUBQP_XSNMSUBQPO
  { 0, 0, 0, 0, 0 }, // 168 BCDCFSQ_rec
  { 0, 0, 0, 0, 0 }, // 169 XSDIVQP_XSDIVQPO
  { 0, 0, 0, 0, 0 }, // 170 XSSQRTQP_XSSQRTQPO
  { 1, 260, 265, 2020, 2025 }, // 171 LXVL_LXVLL
  { 1, 260, 265, 2025, 2030 }, // 172 LVEBX_LVEHX_LVEWX_LVX_LVXL
  { 0, 0, 0, 0, 0 }, // 173 LXSIBZX_LXSIHZX_LXSDX_LXVB16X_LXVD2X_LXVWSX_LXSIWZX_LXV_LXVX_LXSD
  { 0, 0, 0, 0, 0 }, // 174 DFLOADf64_XFLOADf64_LIWZX
  { 0, 0, 0, 0, 0 }, // 175 DCBF_DCBFEP_DCBST_DCBSTEP_DCBT_DCBTEP_DCBZ_DCBZEP_DCBZL_DCBZLEP_DCBTST_DCBTSTEP
  { 0, 0, 0, 0, 0 }, // 176 CP_COPY_CP_COPY8
  { 0, 0, 0, 0, 0 }, // 177 CP_PASTE_CP_PASTE8
  { 0, 0, 0, 0, 0 }, // 178 ICBI_ICBIEP
  { 1, 260, 265, 2030, 2035 }, // 179 ICBT_ICBTLS_LBZ_LBZ8_LBZCIX_LBZX_LBZX8_LBZXTLS_LBZXTLS__LBZXTLS_32_LDBRX_LDCIX_LHBRX_LHBRX8_LHZ_LHZ8_LHZCIX_LHZX_LHZX8_LHZXTLS_LHZXTLS__LHZXTLS_32_LWBRX_LWBRX8_LWZ_LWZ8_LWZCIX_LWZX_LWZX8_LWZXTLS_LWZXTLS__LWZXTLS_32_EnforceIEIO_LSWI
  { 0, 0, 0, 0, 0 }, // 180 LBARX_LBARXL_LHARX_LHARXL_LWARX_LWARXL
  { 0, 0, 0, 0, 0 }, // 181 LD_LDX_LDXTLS_LDXTLS__DARN
  { 0, 0, 0, 0, 0 }, // 182 LDARX_LDARXL
  { 0, 0, 0, 0, 0 }, // 183 CP_ABORT
  { 0, 0, 0, 0, 0 }, // 184 ISYNC
  { 0, 0, 0, 0, 0 }, // 185 MSGSYNC
  { 0, 0, 0, 0, 0 }, // 186 TLBSYNC
  { 0, 0, 0, 0, 0 }, // 187 SYNC
  { 0, 0, 0, 0, 0 }, // 188 LMW
  { 0, 0, 0, 0, 0 }, // 189 LFIWZX_LFDX_LFD
  { 0, 0, 0, 0, 0 }, // 190 SLBIA
  { 0, 0, 0, 0, 0 }, // 191 SLBIE
  { 0, 0, 0, 0, 0 }, // 192 SLBMFEE
  { 0, 0, 0, 0, 0 }, // 193 SLBMFEV
  { 0, 0, 0, 0, 0 }, // 194 SLBMTE
  { 0, 0, 0, 0, 0 }, // 195 TLBIEL
  { 2, 288, 293, 2035, 2040 }, // 196 LHZU_LHZU8_LWZU_LWZU8
  { 2, 288, 293, 2040, 2045 }, // 197 LHZUX_LHZUX8_LWZUX_LWZUX8
  { 1, 252, 257, 2045, 2050 }, // 198 TEND
  { 0, 0, 0, 0, 0 }, // 199 STBCX_STHCX_STWCX
  { 0, 0, 0, 0, 0 }, // 200 STDCX
  { 0, 0, 0, 0, 0 }, // 201 LDMX
  { 0, 0, 0, 0, 0 }, // 202 LHA_LHA8_LHAX_LHAX8_LWAX_LWAX_32
  { 0, 0, 0, 0, 0 }, // 203 CP_PASTE8_rec_CP_PASTE_rec
  { 0, 0, 0, 0, 0 }, // 204 LWA_LWA_32
  { 1, 252, 257, 2050, 2055 }, // 205 TCHECK
  { 0, 0, 0, 0, 0 }, // 206 LFIWAX
  { 0, 0, 0, 0, 0 }, // 207 LXSIWAX
  { 0, 0, 0, 0, 0 }, // 208 LIWAX
  { 0, 0, 0, 0, 0 }, // 209 LFSX_LFS
  { 0, 0, 0, 0, 0 }, // 210 LXSSP_LXSSPX
  { 0, 0, 0, 0, 0 }, // 211 XFLOADf32_DFLOADf32
  { 0, 0, 0, 0, 0 }, // 212 LHAU_LHAU8
  { 0, 0, 0, 0, 0 }, // 213 LHAUX_LHAUX8_LWAUX
  { 0, 0, 0, 0, 0 }, // 214 LXVH8X_LXVDSX_LXVW4X
  { 0, 0, 0, 0, 0 }, // 215 STFD_STFDX_STFIWX_STFS_STFSX_STXSD_STXSDX_STXSIBX_STXSIBXv_STXSIHX_STXSIHXv_STXSIWX_STXSSP_STXSSPX
  { 1, 280, 284, 2055, 2059 }, // 216 STW_STW8_STDBRX_STHBRX_STWBRX_STB_STB8_STH_STH8_STBX_STBX8_STBXTLS_STBXTLS__STBXTLS_32_STHX_STHX8_STHXTLS_STHXTLS__STHXTLS_32_STWX_STWX8_STWXTLS_STWXTLS__STWXTLS_32
  { 0, 0, 0, 0, 0 }, // 217 DFSTOREf32_DFSTOREf64_XFSTOREf32_XFSTOREf64_STIWX
  { 0, 0, 0, 0, 0 }, // 218 STD_STDX_STDXTLS_STDXTLS_
  { 1, 260, 265, 2059, 2064 }, // 219 STBCIX_STDCIX_STHCIX_STWCIX_STSWI
  { 0, 0, 0, 0, 0 }, // 220 SLBIEG
  { 0, 0, 0, 0, 0 }, // 221 STMW
  { 0, 0, 0, 0, 0 }, // 222 TLBIE
  { 1, 280, 284, 2064, 2068 }, // 223 STVEBX_STVEHX_STVEWX_STVX_STVXL
  { 0, 0, 0, 0, 0 }, // 224 STXV_STXVB16X_STXVD2X_STXVH8X_STXVW4X_STXVX
  { 1, 260, 265, 2068, 2073 }, // 225 STXVL_STXVLL
  { 1, 252, 257, 2073, 2078 }, // 226 MTCTR_MTCTR8_MTCTR8loop_MTCTRloop_MTLR_MTLR8
  { 1, 252, 257, 2078, 2083 }, // 227 MFVRSAVE_MFVRSAVEv_MTVRSAVE_MTVRSAVEv
  { 0, 0, 0, 0, 0 }, // 228 MFPMR
  { 0, 0, 0, 0, 0 }, // 229 MTPMR
  { 0, 0, 0, 0, 0 }, // 230 MFTB_MFTB8
  { 1, 252, 257, 2083, 2088 }, // 231 MFCTR_MFCTR8_MFLR_MFLR8_MFSPR_MFSPR8
  { 0, 0, 0, 0, 0 }, // 232 MFMSR
  { 0, 0, 0, 0, 0 }, // 233 MTMSR
  { 0, 0, 0, 0, 0 }, // 234 MTMSRD
  { 1, 252, 257, 2088, 2093 }, // 235 MTSPR_MTSPR8
  { 1, 265, 269, 2093, 2096 }, // 236 DIVW_DIVWO_DIVWU_DIVWUO_MODSW
  { 1, 265, 269, 2096, 2099 }, // 237 DIVWE_DIVWEO_DIVWEU_DIVWEUO_MODSD_MODUD_MODUW
  { 0, 0, 0, 0, 0 }, // 238 DIVD_DIVDO_DIVDU_DIVDUO
  { 0, 0, 0, 0, 0 }, // 239 DIVDE_DIVDEO_DIVDEU_DIVDEUO
  { 1, 265, 269, 2099, 2102 }, // 240 DIVWO_rec_DIVWUO_rec_DIVWU_rec_DIVW_rec
  { 0, 0, 0, 0, 0 }, // 241 DIVD_rec_DIVDO_rec_DIVDU_rec_DIVDUO_rec
  { 1, 265, 269, 2102, 2105 }, // 242 DIVWE_rec_DIVWEO_rec_DIVWEU_rec_DIVWEUO_rec
  { 0, 0, 0, 0, 0 }, // 243 DIVDE_rec_DIVDEO_rec_DIVDEU_rec_DIVDEUO_rec
  { 1, 293, 296, 2105, 2109 }, // 244 MTCRF_MTCRF8
  { 1, 252, 257, 2109, 2114 }, // 245 ADDC8O_rec_ADDC8_rec_ADDCO_rec_ADDC_rec_SUBFC8O_rec_SUBFC8_rec_SUBFCO_rec_SUBFC_rec
  { 1, 269, 273, 2114, 2118 }, // 246 FABSD_rec_FABSS_rec_FNABSD_rec_FNABSS_rec_FCPSGND_rec_FCPSGNS_rec_FNEGD_rec_FNEGS_rec_FMR_rec
  { 1, 257, 260, 2118, 2121 }, // 247 MCRFS
  { 0, 0, 0, 0, 0 }, // 248 MTFSF_MTFSF_rec_MTFSFI_MTFSFI_rec
  { 0, 0, 0, 0, 0 }, // 249 MTFSFb
  { 0, 0, 0, 0, 0 }, // 250 RLDCL_rec_RLDCR_rec
  { 0, 0, 0, 0, 0 }, // 251 RLDICL_rec_RLDICR_rec_RLDICL_32_rec_RLDIMI_rec
  { 1, 252, 257, 2121, 2126 }, // 252 RLWIMI8_rec_RLWIMI_rec
  { 1, 252, 257, 2126, 2131 }, // 253 RLWINM8_rec_RLWINM_rec_RLWNM8_rec_RLWNM_rec_SLW8_rec_SLW_rec_SRW8_rec_SRW_rec
  { 1, 252, 257, 2131, 2136 }, // 254 SRAWI_rec_SRAW_rec
  { 0, 0, 0, 0, 0 }, // 255 MFFS_MFFSCE_MFFSL_MFFS_rec
  { 0, 0, 0, 0, 0 }, // 256 MFCR_MFCR8
  { 0, 0, 0, 0, 0 }, // 257 EXTSWSLI_32_64_rec_SRADI_rec_EXTSWSLI_rec_RLDIC_rec
  { 0, 0, 0, 0, 0 }, // 258 SRAD_rec_SLD_rec_SRD_rec
  { 0, 0, 0, 0, 0 }, // 259 FDIV
  { 0, 0, 0, 0, 0 }, // 260 FDIV_rec
  { 0, 0, 0, 0, 0 }, // 261 XSSQRTDP
  { 0, 0, 0, 0, 0 }, // 262 FSQRT
  { 0, 0, 0, 0, 0 }, // 263 XVSQRTDP
  { 0, 0, 0, 0, 0 }, // 264 XVSQRTSP
  { 0, 0, 0, 0, 0 }, // 265 FSQRT_rec
  { 0, 0, 0, 0, 0 }, // 266 XSSQRTSP
  { 0, 0, 0, 0, 0 }, // 267 FSQRTS
  { 0, 0, 0, 0, 0 }, // 268 FSQRTS_rec
  { 0, 0, 0, 0, 0 }, // 269 XSDIVDP
  { 1, 284, 288, 2136, 2140 }, // 270 FDIVS
  { 1, 284, 288, 2140, 2144 }, // 271 FDIVS_rec
  { 1, 284, 288, 2144, 2148 }, // 272 XSDIVSP
  { 1, 284, 288, 2148, 2152 }, // 273 XVDIVSP
  { 0, 0, 0, 0, 0 }, // 274 XVDIVDP
  { 0, 0, 0, 0, 0 }, // 275 LFSU
  { 0, 0, 0, 0, 0 }, // 276 LFSUX
  { 0, 0, 0, 0, 0 }, // 277 STFDU_STFDUX_STFSU_STFSUX
  { 2, 301, 305, 2152, 2156 }, // 278 STBU_STBU8_STDU_STHU_STHU8_STWU_STWU8
  { 2, 301, 305, 2156, 2160 }, // 279 STBUX_STBUX8_STDUX_STHUX_STHUX8_STWUX_STWUX8
  { 2, 288, 293, 2160, 2165 }, // 280 LBZU_LBZU8
  { 2, 288, 293, 2165, 2170 }, // 281 LBZUX_LBZUX8
  { 0, 0, 0, 0, 0 }, // 282 LDU
  { 0, 0, 0, 0, 0 }, // 283 LDUX
  { 0, 0, 0, 0, 0 }, // 284 LFDU
  { 0, 0, 0, 0, 0 }, // 285 LFDUX
  { 0, 0, 0, 0, 0 }, // 286 VPMSUMB_VPMSUMD_VPMSUMH_VPMSUMW_VCIPHER_VCIPHERLAST_VNCIPHER_VNCIPHERLAST_VSBOX
  { 1, 257, 260, 2170, 2173 }, // 287 BCCCTR_BCCCTR8_BCCCTRL_BCCCTRL8_BCCL_BCCLA_BCCLR_BCCLRL_BCCTR_BCCTR8_BCCTR8n_BCCTRL_BCCTRL8_BCCTRL8n_BCCTRLn_BCCTRn_BDNZ_BDNZ8_BDNZA_BDNZAm_BDNZAp_BDNZm_BDNZp_BDZ_BDZ8_BDZA_BDZAm_BDZAp_BDZm_BDZp_BDNZL_BDNZLA_BDNZLAm_BDNZLAp_BDNZLR_BDNZLR8_BDNZLRL_BDNZLRLm_BDNZLRLp_BDNZLRm_BDNZLRp_BDNZLm_BDNZLp_BDZL_BDZLA_BDZLAm_BDZLAp_BDZLR_BDZLR8_BDZLRL_BDZLRLm_BDZLRLp_BDZLRm_BDZLRp_BDZLm_BDZLp_BL_BL_NOP_BL_TLS_BL8_BL8_NOP_BL8_NOP_TLS_BL8_TLS_BL8_TLS__BLA_BLA8_BLA8_NOP_BLR_BLR8_BLRL_TAILB_TAILB8_TAILBA_TAILBA8_TAILBCTR_TAILBCTR8_gBC_gBCA_gBCAat_gBCCTR_gBCCTRL_gBCL_gBCLA_gBCLAat_gBCLR_gBCLRL_gBCLat_gBCat_BCLR_BCLRL_BCLRLn_BCLRn_BCTR_BCTR8_BCTRL_BCTRL8_B_BA_BC_BCC_BCCA_BCL_BCLalways_BCLn_BCTRL8_LDinto_toc_BCTRL_LWZinto_toc_BCn_CTRL_DEP
  { 1, 257, 260, 2173, 2176 }, // 288 ADDPCIS
  { 1, 260, 265, 2176, 2181 }, // 289 LDAT_LWAT
  { 1, 280, 284, 2181, 2185 }, // 290 STDAT_STWAT
  { 1, 252, 257, 2185, 2190 }, // 291 BRINC
  { 1, 273, 276, 2190, 2193 }, // 292 EVABS_EVEQV_EVNAND_EVNEG_EVADDIW_EVADDW_EVAND_EVANDC_EVCMPEQ_EVCMPGTS_EVCMPGTU_EVCMPLTS_EVCMPLTU_EVCNTLSW_EVCNTLZW_EVEXTSB_EVEXTSH_EVMERGEHI_EVMERGEHILO_EVMERGELO_EVMERGELOHI_EVNOR_EVOR_EVORC_EVXOR_EVRLW_EVRLWI_EVRNDW_EVSLW_EVSLWI_EVSPLATFI_EVSPLATI_EVSRWIS_EVSRWIU_EVSRWS_EVSRWU_EVSUBFW_EVSUBIFW
  { 1, 276, 280, 2193, 2196 }, // 293 EVMRA_EVADDSMIAAW_EVADDSSIAAW_EVADDUMIAAW_EVADDUSIAAW_EVDIVWS_EVDIVWU_EVMHEGSMFAA_EVMHEGSMFAN_EVMHEGSMIAA_EVMHEGSMIAN_EVMHEGUMIAA_EVMHEGUMIAN_EVMHESMF_EVMHESMFA_EVMHESMFAAW_EVMHESMFANW_EVMHESMI_EVMHESMIA_EVMHESMIAAW_EVMHESMIANW_EVMHESSF_EVMHESSFA_EVMHESSFAAW_EVMHESSFANW_EVMHESSIAAW_EVMHESSIANW_EVMHEUMI_EVMHEUMIA_EVMHEUMIAAW_EVMHEUMIANW_EVMHEUSIAAW_EVMHEUSIANW_EVMHOGSMFAA_EVMHOGSMFAN_EVMHOGSMIAA_EVMHOGSMIAN_EVMHOGUMIAA_EVMHOGUMIAN_EVMHOSMF_EVMHOSMFA_EVMHOSMFAAW_EVMHOSMFANW_EVMHOSMI_EVMHOSMIA_EVMHOSMIAAW_EVMHOSMIANW_EVMHOSSF_EVMHOSSFA_EVMHOSSFAAW_EVMHOSSFANW_EVMHOSSIAAW_EVMHOSSIANW_EVMHOUMI_EVMHOUMIA_EVMHOUMIAAW_EVMHOUMIANW_EVMHOUSIAAW_EVMHOUSIANW_EVMWHSMF_EVMWHSMFA_EVMWHSMI_EVMWHSMIA_EVMWHSSF_EVMWHSSFA_EVMWHUMI_EVMWHUMIA_EVMWLSMIAAW_EVMWLSMIANW_EVMWLSSIAAW_EVMWLSSIANW_EVMWLUMI_EVMWLUMIA_EVMWLUMIAAW_EVMWLUMIANW_EVMWLUSIAAW_EVMWLUSIANW_EVMWSMF_EVMWSMFA_EVMWSMFAA_EVMWSMFAN_EVMWSMI_EVMWSMIA_EVMWSMIAA_EVMWSMIAN_EVMWSSF_EVMWSSFA_EVMWSSFAA_EVMWSSFAN_EVMWUMI_EVMWUMIA_EVMWUMIAA_EVMWUMIAN_EVSUBFSMIAAW_EVSUBFSSIAAW_EVSUBFUMIAAW_EVSUBFUSIAAW
  { 1, 260, 265, 2196, 2201 }, // 294 EVLDD_EVLDDX_EVLDH_EVLDHX_EVLDW_EVLDWX_EVLHHESPLAT_EVLHHESPLATX_EVLHHOSSPLAT_EVLHHOSSPLATX_EVLHHOUSPLAT_EVLHHOUSPLATX_EVLWHE_EVLWHEX_EVLWHOS_EVLWHOSX_EVLWHOU_EVLWHOUX_EVLWHSPLAT_EVLWHSPLATX_EVLWWSPLAT_EVLWWSPLATX
  { 1, 280, 284, 2201, 2205 }, // 295 EVSTDD_EVSTDDX_EVSTDH_EVSTDHX_EVSTDW_EVSTDWX_EVSTWHE_EVSTWHEX_EVSTWHO_EVSTWHOX_EVSTWWE_EVSTWWEX_EVSTWWO_EVSTWWOX
  { 1, 257, 260, 2205, 2208 }, // 296 HRFID_ATTN_CLRBHRB_MFBHRBE_NAP_RFCI_RFDI_RFMCI_SC
  { 0, 0, 0, 0, 0 }, // 297 RFI
  { 0, 0, 0, 0, 0 }, // 298 RFID
  { 1, 260, 265, 2208, 2213 }, // 299 DSS_DSSALL_DST_DST64_DSTST_DSTST64_DSTSTT_DSTSTT64_DSTT_DSTT64_ICBLQ_LBEPX_LHEPX_LWEPX_TLBIVAX_TLBLD_TLBLI_TLBRE_TLBRE2_TLBSX_TLBSX2_TLBSX2D_TLBWE_TLBWE2_MBAR_TRAP_DCCCI_ICCCI
  { 1, 280, 284, 2213, 2217 }, // 300 ICBLC_STBEPX_STHEPX_STWEPX
  { 0, 0, 0, 0, 0 }, // 301 LFDEPX
  { 0, 0, 0, 0, 0 }, // 302 STFDEPX
  { 0, 0, 0, 0, 0 }, // 303 MFSR_MFSRIN
  { 0, 0, 0, 0, 0 }, // 304 MTSR_MTSRIN
  { 1, 252, 257, 2217, 2222 }, // 305 MFDCR
  { 1, 252, 257, 2222, 2227 }, // 306 MTDCR
  { 1, 252, 257, 2227, 2232 }, // 307 NOP_GT_PWR6_NOP_GT_PWR7
  { 0, 0, 0, 0, 0 }, // 308 TLBIA
  { 0, 0, 0, 0, 0 }, // 309 WRTEE_WRTEEI
  { 0, 0, 0, 0, 0 }, // 310 MSYNC
  { 0, 0, 0, 0, 0 }, // 311 SLBSYNC
  { 0, 0, 0, 0, 0 }, // 312 SLBFEE_rec
  { 0, 0, 0, 0, 0 }, // 313 STOP
  { 0, 0, 0, 0, 0 }, // 314 DCBA_DCBI
  { 0, uint16_t(~0U), uint16_t(~0U), uint16_t(~0U), uint16_t(~0U) }// end marker
};

static const llvm::InstrItinerary PPCE200Z6Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 0, 0, 0, 0, 0 }, // 1 IIC_LdStSync
  { 1, 310, 315, 2232, 2237 }, // 2 IIC_IntSimple
  { 1, 310, 315, 2237, 2242 }, // 3 IIC_IntGeneral
  { 1, 315, 318, 2242, 2245 }, // 4 IIC_BrB
  { 0, 0, 0, 0, 0 }, // 5 IIC_VecFP
  { 1, 310, 315, 2245, 2250 }, // 6 IIC_IntCompare
  { 0, 0, 0, 0, 0 }, // 7 IIC_SprABORT
  { 0, 0, 0, 0, 0 }, // 8 IIC_LdStCOPY
  { 0, 0, 0, 0, 0 }, // 9 IIC_LdStPASTE
  { 1, 315, 318, 2250, 2254 }, // 10 IIC_BrCR
  { 0, 0, 0, 0, 0 }, // 11 IIC_LdStLD
  { 0, 0, 0, 0, 0 }, // 12 IIC_LdStDCBF
  { 1, 318, 323, 2254, 2259 }, // 13 IIC_LdStLoad
  { 0, 0, 0, 0, 0 }, // 14 IIC_IntDivD
  { 1, 323, 327, 2259, 2262 }, // 15 IIC_IntDivW
  { 0, 0, 0, 0, 0 }, // 16 IIC_FPDGeneral
  { 0, 0, 0, 0, 0 }, // 17 IIC_FPAddSub
  { 0, 0, 0, 0, 0 }, // 18 IIC_FPDivD
  { 0, 0, 0, 0, 0 }, // 19 IIC_FPSGeneral
  { 0, 0, 0, 0, 0 }, // 20 IIC_FPCompare
  { 0, 0, 0, 0, 0 }, // 21 IIC_FPGeneral
  { 0, 0, 0, 0, 0 }, // 22 IIC_VecGeneral
  { 0, 0, 0, 0, 0 }, // 23 IIC_VecComplex
  { 1, 327, 331, 2262, 2266 }, // 24 IIC_LdStStore
  { 0, 0, 0, 0, 0 }, // 25 IIC_IntRotateDI
  { 0, 0, 0, 0, 0 }, // 26 IIC_FPDivS
  { 0, 0, 0, 0, 0 }, // 27 IIC_FPFused
  { 0, 0, 0, 0, 0 }, // 28 IIC_FPSqrtD
  { 0, 0, 0, 0, 0 }, // 29 IIC_FPSqrtS
  { 0, 0, 0, 0, 0 }, // 30 IIC_LdStICBI
  { 1, 310, 315, 2266, 2272 }, // 31 IIC_IntISEL
  { 0, 0, 0, 0, 0 }, // 32 IIC_SprISYNC
  { 0, 0, 0, 0, 0 }, // 33 IIC_LdStLWARX
  { 2, 331, 336, 2272, 2277 }, // 34 IIC_LdStLoadUpd
  { 2, 331, 336, 2277, 2282 }, // 35 IIC_LdStLoadUpdX
  { 0, 0, 0, 0, 0 }, // 36 IIC_LdStLDARX
  { 0, 0, 0, 0, 0 }, // 37 IIC_LdStLDU
  { 0, 0, 0, 0, 0 }, // 38 IIC_LdStLDUX
  { 0, 0, 0, 0, 0 }, // 39 IIC_LdStLFD
  { 0, 0, 0, 0, 0 }, // 40 IIC_LdStLFDU
  { 0, 0, 0, 0, 0 }, // 41 IIC_LdStLFDUX
  { 0, 0, 0, 0, 0 }, // 42 IIC_LdStLHA
  { 0, 0, 0, 0, 0 }, // 43 IIC_LdStLHAU
  { 0, 0, 0, 0, 0 }, // 44 IIC_LdStLHAUX
  { 0, 0, 0, 0, 0 }, // 45 IIC_LdStLMW
  { 0, 0, 0, 0, 0 }, // 46 IIC_LdStLWA
  { 0, 0, 0, 0, 0 }, // 47 IIC_IntMulHD
  { 1, 315, 318, 2282, 2285 }, // 48 IIC_BrMCR
  { 1, 336, 339, 2285, 2289 }, // 49 IIC_BrMCRX
  { 0, 0, 0, 0, 0 }, // 50 IIC_SprMFCR
  { 1, 310, 315, 2289, 2294 }, // 51 IIC_SprMFSPR
  { 0, 0, 0, 0, 0 }, // 52 IIC_IntMFFS
  { 0, 0, 0, 0, 0 }, // 53 IIC_SprMFMSR
  { 0, 0, 0, 0, 0 }, // 54 IIC_SprMFCRF
  { 0, 0, 0, 0, 0 }, // 55 IIC_SprMFPMR
  { 0, 0, 0, 0, 0 }, // 56 IIC_SprMFSR
  { 0, 0, 0, 0, 0 }, // 57 IIC_SprMFTB
  { 0, 0, 0, 0, 0 }, // 58 IIC_SprMSGSYNC
  { 1, 310, 315, 2294, 2299 }, // 59 IIC_SprMTSPR
  { 0, 0, 0, 0, 0 }, // 60 IIC_IntMTFSB0
  { 0, 0, 0, 0, 0 }, // 61 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 62 IIC_SprMTMSRD
  { 0, 0, 0, 0, 0 }, // 63 IIC_SprMTPMR
  { 0, 0, 0, 0, 0 }, // 64 IIC_SprMTSR
  { 1, 339, 344, 2299, 2304 }, // 65 IIC_IntMulHW
  { 1, 339, 344, 2304, 2309 }, // 66 IIC_IntMulHWU
  { 1, 339, 344, 2309, 2314 }, // 67 IIC_IntMulLI
  { 0, 0, 0, 0, 0 }, // 68 IIC_VecPerm
  { 0, 0, 0, 0, 0 }, // 69 IIC_LdStSTFD
  { 0, 0, 0, 0, 0 }, // 70 IIC_LdStSTFDU
  { 0, 0, 0, 0, 0 }, // 71 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 72 IIC_IntRFID
  { 0, 0, 0, 0, 0 }, // 73 IIC_IntRotateD
  { 1, 310, 315, 2314, 2319 }, // 74 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 75 IIC_SprSLBFEE
  { 0, 0, 0, 0, 0 }, // 76 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 77 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprSLBIEG
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprSLBMFEV
  { 0, 0, 0, 0, 0 }, // 81 IIC_SprSLBMTE
  { 0, 0, 0, 0, 0 }, // 82 IIC_SprSLBSYNC
  { 1, 310, 315, 2319, 2324 }, // 83 IIC_IntShift
  { 0, 0, 0, 0, 0 }, // 84 IIC_LdStSTWCX
  { 2, 344, 348, 2324, 2328 }, // 85 IIC_LdStSTU
  { 2, 344, 348, 2328, 2332 }, // 86 IIC_LdStSTUX
  { 0, 0, 0, 0, 0 }, // 87 IIC_LdStSTD
  { 0, 0, 0, 0, 0 }, // 88 IIC_LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 89 IIC_SprSTOP
  { 0, 0, 0, 0, 0 }, // 90 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 91 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 92 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 93 IIC_SprTLBIEL
  { 0, 0, 0, 0, 0 }, // 94 IIC_SprTLBSYNC
  { 1, 348, 353, 2332, 2336 }, // 95 IIC_IntTrapW
  { 0, 0, 0, 0, 0 }, // 96 IIC_VecFPCompare
  { 0, 0, 0, 0, 0 }, // 97 VADDUBM_VADDUDM_VADDUHM_VADDUWM_VEXTSB2D_VEXTSB2Ds_VEXTSB2W_VEXTSB2Ws_VEXTSH2D_VEXTSH2Ds_VEXTSH2W_VEXTSH2Ws_VEXTSW2D_VEXTSW2Ds_VSLD_VSRD_VSUBUBM_VSUBUDM_VSUBUHM_VSUBUWM_VPOPCNTB_VPOPCNTH_VSRAD_MTVSRDD_VEQV_VNAND_VNEGD_VNEGW_VORC_XXLAND_XXLANDC_XXLEQV_XXLEQVOnes_XXLNAND_XXLNOR_XXLOR_XXLORf_XXLORC_XXLXOR_XXLXORdpz_XXLXORspz_XXLXORz
  { 0, 0, 0, 0, 0 }, // 98 VAND_VANDC_V_SET0_V_SET0B_V_SET0H_VSLB_VSLH_VSLW_VSRB_VSRH_VSRW_VRLB_VRLD_VRLH_VRLW_VSRAB_VSRAH_VSRAW_XVABSDP_XVABSSP_XVNABSDP_XVNABSSP_XVCPSGNDP_XVCPSGNSP_XVIEXPDP_XVIEXPSP_XVXEXPDP_XVXEXPSP_VRLDMI_VRLDNM_VRLWMI_VRLWNM_VMRGEW_VMRGOW_VNOR_VOR_VSEL_VXOR_XVNEGDP_XVNEGSP_XSABSQP_XSCPSGNQP_XSIEXPQP_XSNABSQP_XSNEGQP_XSXEXPQP
  { 0, 0, 0, 0, 0 }, // 99 XXSEL
  { 1, 310, 315, 2336, 2341 }, // 100 TABORTDC_TABORTDCI_TABORTWC_TABORTWCI
  { 0, 0, 0, 0, 0 }, // 101 MTFSB0_MTFSB1
  { 0, 0, 0, 0, 0 }, // 102 MFFSCDRN_MFFSCDRNI_MFFSCRN_MFFSCRNI
  { 1, 310, 315, 2341, 2346 }, // 103 CMPRB_CMPRB8_CMPEQB
  { 0, 0, 0, 0, 0 }, // 104 TD_TDI
  { 1, 348, 353, 2346, 2350 }, // 105 TW_TWI
  { 0, 0, 0, 0, 0 }, // 106 FCMPUD_FCMPUS_FTDIV_FTSQRT
  { 0, 0, 0, 0, 0 }, // 107 XSTSTDCDP_XSTSTDCSP
  { 0, 0, 0, 0, 0 }, // 108 XSMAXCDP_XSMAXDP_XSMAXJDP_XSMINCDP_XSMINDP_XSMINJDP_XSXSIGDP_XSCVSPDPN
  { 0, 0, 0, 0, 0 }, // 109 XSCMPEQDP_XSCMPEXPDP_XSCMPGEDP_XSCMPGTDP_XSCMPODP_XSCMPUDP_XSTDIVDP_XSTSQRTDP
  { 1, 310, 315, 2350, 2355 }, // 110 CNTLZD_CNTLZD_rec_CNTLZW_CNTLZW8_CNTLZW8_rec_CNTLZW_rec_CNTTZD_CNTTZD_rec_CNTTZW_CNTTZW8_CNTTZW8_rec_CNTTZW_rec_POPCNTD_POPCNTW_CMPB_CMPB8_SETB_SETB8_BPERMD
  { 0, 0, 0, 0, 0 }, // 111 SLD_SRD_SRAD
  { 0, 0, 0, 0, 0 }, // 112 SRADI_EXTSWSLI_32_64_EXTSWSLI_SRADI_32_RLDIC
  { 0, 0, 0, 0, 0 }, // 113 MFVRD_MFVSRD_MTVRD_MTVSRD_MTVRWA_MTVRWZ_MTVSRWA_MTVSRWZ_MFVSRWZ_MFVRWZ
  { 1, 310, 315, 2355, 2360 }, // 114 CMPLW_CMPLWI_CMPW_CMPWI_CMPD_CMPDI_CMPLD_CMPLDI
  { 1, 310, 315, 2360, 2365 }, // 115 SUBFC_SUBFC8_SUBFC8O_SUBFCO_SUBFIC_SUBFIC8_ANDI8_rec_ANDIS8_rec_ANDIS_rec_ANDI_rec_ADDC_ADDC8_ADDC8O_ADDCO_ADDIC_ADDIC8_ADDIC_rec_ADDE_ADDE8_ADDE8O_ADDE8O_rec_ADDE8_rec_ADDEO_ADDEO_rec_ADDE_rec_ADDME_ADDME8_ADDME8O_ADDME8O_rec_ADDME8_rec_ADDMEO_ADDMEO_rec_ADDME_rec_ADDZE_ADDZE8_ADDZE8O_ADDZE8O_rec_ADDZE8_rec_ADDZEO_ADDZEO_rec_ADDZE_rec_SUBF_SUBF8_SUBF8O_SUBF8O_rec_SUBF8_rec_SUBFE_SUBFE8_SUBFE8O_SUBFE8O_rec_SUBFE8_rec_SUBFEO_SUBFEO_rec_SUBFE_rec_SUBFME_SUBFME8_SUBFME8O_SUBFME8O_rec_SUBFME8_rec_SUBFMEO_SUBFMEO_rec_SUBFME_rec_SUBFO_SUBFO_rec_SUBFZE_SUBFZE8_SUBFZE8O_SUBFZE8O_rec_SUBFZE8_rec_SUBFZEO_SUBFZEO_rec_SUBFZE_rec_SUBF_rec_POPCNTB_LA
  { 1, 310, 315, 2365, 2370 }, // 116 ADD4_ADD4O_ADD4O_rec_ADD4_rec_ADD8_ADD8O_ADD8O_rec_ADD8_rec_NEG_NEG8_NEG8O_NEG8O_rec_NEG8_rec_NEGO_NEGO_rec_NEG_rec_ADDI_ADDI8_ADDIS_ADDIS8_LI_LI8_LIS_LIS8_OR_OR8_OR8_rec_ORI_ORI8_ORIS_ORIS8_OR_rec_XOR_XOR8_XOR8_rec_XORI_XORI8_XORIS_XORIS8_XOR_rec_NAND_NAND8_NAND8_rec_NAND_rec_AND_AND8_AND8_rec_ANDC_ANDC8_ANDC8_rec_ANDC_rec_AND_rec_NOR_NOR8_NOR8_rec_NOR_rec_ORC_ORC8_ORC8_rec_ORC_rec_EQV_EQV8_EQV8_rec_EQV_rec_EXTSB_EXTSB8_EXTSB8_32_64_EXTSB8_rec_EXTSB_rec_EXTSH_EXTSH8_EXTSH8_32_64_EXTSH8_rec_EXTSH_rec_EXTSW_EXTSW_32_EXTSW_32_64_EXTSW_32_64_rec_EXTSW_rec_ADD4TLS_ADD8TLS_ADD8TLS__NOP
  { 0, 0, 0, 0, 0 }, // 117 ADDIStocHA_ADDIStocHA8_ADDItocL_COPY
  { 1, 315, 318, 2370, 2373 }, // 118 MCRF
  { 1, 336, 339, 2373, 2377 }, // 119 MCRXRX
  { 0, 0, 0, 0, 0 }, // 120 XSNABSDP_XSXEXPDP_XSABSDP_XSNEGDP_XSCPSGNDP
  { 1, 315, 318, 2377, 2380 }, // 121 RFEBB
  { 1, 310, 315, 2380, 2385 }, // 122 TBEGIN_TRECHKPT
  { 1, 318, 323, 2385, 2390 }, // 123 WAIT
  { 0, 0, 0, 0, 0 }, // 124 RLDCL_RLDCR
  { 1, 310, 315, 2390, 2395 }, // 125 RLWIMI_RLWIMI8
  { 0, 0, 0, 0, 0 }, // 126 RLDICL_RLDICL_32_RLDICL_32_64_RLDICR_RLDICR_32_RLDIMI
  { 0, 0, 0, 0, 0 }, // 127 MFOCRF_MFOCRF8
  { 1, 336, 339, 2395, 2399 }, // 128 MTOCRF_MTOCRF8
  { 1, 315, 318, 2399, 2403 }, // 129 CR6SET_CR6UNSET_CRSET_CRUNSET_CRAND_CRANDC_CRNAND_CRNOR_CROR_CRORC_CREQV_CRXOR
  { 1, 310, 315, 2403, 2408 }, // 130 SLW_SLW8_SRW_SRW8_RLWINM_RLWINM8_RLWNM_RLWNM8
  { 0, 0, 0, 0, 0 }, // 131 FABSD_FABSS_FNABSD_FNABSS_FNEGD_FNEGS_FCPSGND_FCPSGNS_FMR
  { 1, 310, 315, 2408, 2413 }, // 132 SRAW_SRAWI
  { 1, 310, 315, 2413, 2419 }, // 133 ISEL_ISEL8
  { 0, 0, 0, 0, 0 }, // 134 XSIEXPDP
  { 1, 310, 315, 2419, 2424 }, // 135 TRECLAIM_TSR_TABORT
  { 1, 327, 331, 2424, 2428 }, // 136 MFVSCR
  { 1, 318, 323, 2428, 2433 }, // 137 MTVSCR
  { 0, 0, 0, 0, 0 }, // 138 VCMPNEZB_VCMPNEZH_VCMPNEZW_VCMPEQUB_VCMPEQUD_VCMPEQUH_VCMPEQUW_VCMPNEB_VCMPNEH_VCMPNEW_VCMPEQFP_VCMPEQFP_rec_VCMPGEFP_VCMPGEFP_rec_VCMPGTFP_VCMPGTFP_rec_VCMPBFP_VCMPBFP_rec_VCMPGTSB_VCMPGTSB_rec_VCMPGTSD_VCMPGTSD_rec_VCMPGTSH_VCMPGTSH_rec_VCMPGTSW_VCMPGTSW_rec_VCMPGTUB_VCMPGTUB_rec_VCMPGTUD_VCMPGTUD_rec_VCMPGTUH_VCMPGTUH_rec_VCMPGTUW_VCMPGTUW_rec_VCMPNEB_rec_VCMPNEH_rec_VCMPNEW_rec_VCMPNEZB_rec_VCMPNEZH_rec_VCMPNEZW_rec_VCMPEQUB_rec_VCMPEQUD_rec_VCMPEQUH_rec_VCMPEQUW_rec_XVCMPEQDP_XVCMPEQDP_rec_XVCMPEQSP_XVCMPEQSP_rec_XVCMPGEDP_XVCMPGEDP_rec_XVCMPGESP_XVCMPGESP_rec_XVCMPGTDP_XVCMPGTDP_rec_XVCMPGTSP_XVCMPGTSP_rec
  { 0, 0, 0, 0, 0 }, // 139 VABSDUB_VABSDUH_VABSDUW_VCLZB_VCLZD_VCLZH_VCLZW_VCTZB_VCTZD_VCTZH_VCTZW_VPOPCNTW_VPOPCNTD_VPRTYBD_VPRTYBW
  { 0, 0, 0, 0, 0 }, // 140 VADDUBS_VADDUHS_VADDUWS_VAVGSB_VAVGSH_VAVGSW_VAVGUB_VAVGUH_VAVGUW_VADDSBS_VADDSHS_VADDSWS_VMAXFP_VMINFP_VMAXSB_VMAXSD_VMAXSH_VMAXSW_VMAXUB_VMAXUD_VMAXUH_VMAXUW_VMINSB_VMINSD_VMINSH_VMINSW_VMINUB_VMINUD_VMINUH_VMINUW_VBPERMD_VADDCUW_VSHASIGMAD_VSHASIGMAW_VSUBSBS_VSUBSHS_VSUBSWS_VSUBUBS_VSUBUHS_VSUBUWS_VSUBCUW_XVMAXDP_XVMAXSP_XVMINDP_XVMINSP_XVTSTDCDP_XVTSTDCSP_XVXSIGDP_XVXSIGSP
  { 0, 0, 0, 0, 0 }, // 141 XVTDIVDP_XVTDIVSP_XVTSQRTDP_XVTSQRTSP
  { 0, 0, 0, 0, 0 }, // 142 VADDFP_VCTSXS_VCTSXS_0_VCTUXS_VCTUXS_0_VEXPTEFP_VLOGEFP_VMADDFP_VMHADDSHS_VNMSUBFP_VREFP_VRFIM_VRFIN_VRFIP_VRFIZ_VRSQRTEFP_XVADDDP_XVADDSP_XVCVDPSP_XVCVDPSXDS_XVCVDPSXWS_XVCVDPUXDS_XVCVDPUXWS_XVCVHPSP_XVCVSPDP_XVCVSPHP_XVCVSPSXDS_XVCVSPSXWS_XVCVSPUXDS_XVCVSPUXWS_XVCVSXDDP_XVCVSXDSP_XVCVSXWDP_XVCVSXWSP_XVCVUXDDP_XVCVUXDSP_XVCVUXWDP_XVCVUXWSP_XVMADDADP_XVMADDASP_XVMADDMDP_XVMADDMSP_XVMSUBADP_XVMSUBASP_XVMSUBMDP_XVMSUBMSP_XVMULDP_XVMULSP_XVNMADDADP_XVNMADDASP_XVNMADDMDP_XVNMADDMSP_XVNMSUBADP_XVNMSUBASP_XVNMSUBMDP_XVNMSUBMSP_XVRDPI_XVRDPIC_XVRDPIM_XVRDPIP_XVRDPIZ_XVREDP_XVRESP_XVRSPI_XVRSPIC_XVRSPIM_XVRSPIP_XVRSPIZ_XVRSQRTEDP_XVRSQRTESP_XVSUBDP_XVSUBSP_VCFSX_VCFSX_0_VCFUX_VCFUX_0_VMHRADDSHS_VMLADDUHM_VMSUMMBM_VMSUMSHM_VMSUMSHS_VMSUMUBM_VMSUMUHM_VMSUMUDM_VMSUMUHS_VMULESB_VMULESH_VMULESW_VMULEUB_VMULEUH_VMULEUW_VMULOSB_VMULOSH_VMULOSW_VMULOUB_VMULOUH_VMULOUW_VSUM2SWS_VSUM4SBS_VSUM4SHS_VSUM4UBS_VSUMSWS
  { 0, 0, 0, 0, 0 }, // 143 VSUBFP_VMULUWM
  { 0, 0, 0, 0, 0 }, // 144 MADDHD_MADDHDU_MADDLD_MADDLD8_MULLD_MULLDO
  { 1, 339, 344, 2433, 2438 }, // 145 MULHD_MULHW_MULLW_MULLWO
  { 1, 339, 344, 2438, 2443 }, // 146 MULHDU_MULHWU
  { 1, 339, 344, 2443, 2448 }, // 147 MULLI_MULLI8
  { 0, 0, 0, 0, 0 }, // 148 FRSP_FRIMD_FRIMS_FRIND_FRINS_FRIPD_FRIPS_FRIZD_FRIZS_FRE_FRES_FADDS_FMSUBS_FMADDS_FSUBS_FCFID_FCFIDS_FCFIDU_FCFIDUS_FCTID_FCTIDU_FCTIDUZ_FCTIDZ_FCTIW_FCTIWU_FCTIWUZ_FCTIWZ_FRSQRTE_FRSQRTES_FNMADDS_FNMSUBS_FSELD_FSELS_FMULS
  { 0, 0, 0, 0, 0 }, // 149 FADD_FSUB
  { 0, 0, 0, 0, 0 }, // 150 FMSUB_FMADD_FNMADD_FNMSUB_FMUL
  { 0, 0, 0, 0, 0 }, // 151 XSMADDADP_XSMADDASP_XSMADDMDP_XSMADDMSP_XSMSUBADP_XSMSUBASP_XSMSUBMDP_XSMSUBMSP_XSMULDP_XSMULSP_XSNMADDADP_XSNMADDASP_XSNMADDMDP_XSNMADDMSP_XSNMSUBADP_XSNMSUBASP_XSNMSUBMDP_XSNMSUBMSP
  { 0, 0, 0, 0, 0 }, // 152 FSELD_rec_FSELS_rec
  { 1, 339, 344, 2448, 2453 }, // 153 MULHDU_rec_MULHWU_rec
  { 1, 339, 344, 2453, 2458 }, // 154 MULHD_rec_MULHW_rec_MULLWO_rec_MULLW_rec
  { 0, 0, 0, 0, 0 }, // 155 MULLDO_rec_MULLD_rec
  { 0, 0, 0, 0, 0 }, // 156 FRIMD_rec_FRIMS_rec_FRIND_rec_FRINS_rec_FRIPD_rec_FRIPS_rec_FRIZD_rec_FRIZS_rec_FRES_rec_FRE_rec_FADDS_rec_FSUBS_rec_FMSUBS_rec_FNMSUBS_rec_FMADDS_rec_FNMADDS_rec_FCFIDS_rec_FCFIDUS_rec_FCFIDU_rec_FCFID_rec_FCTIDUZ_rec_FCTIDU_rec_FCTIDZ_rec_FCTID_rec_FCTIWUZ_rec_FCTIWU_rec_FCTIWZ_rec_FCTIW_rec_FMULS_rec_FRSQRTES_rec_FRSQRTE_rec_FRSP_rec
  { 0, 0, 0, 0, 0 }, // 157 FADD_rec_FSUB_rec
  { 0, 0, 0, 0, 0 }, // 158 FMSUB_rec_FNMSUB_rec_FMADD_rec_FNMADD_rec_FMUL_rec
  { 0, 0, 0, 0, 0 }, // 159 XSADDDP_XSADDSP_XSCVDPHP_XSCVDPSP_XSCVDPSXDS_XSCVDPSXDSs_XSCVDPSXWS_XSCVDPUXDS_XSCVDPUXDSs_XSCVDPUXWS_XSCVDPSXWSs_XSCVDPUXWSs_XSCVHPDP_XSCVSPDP_XSCVSXDDP_XSCVSXDSP_XSCVUXDDP_XSCVUXDSP_XSRDPI_XSRDPIC_XSRDPIM_XSRDPIP_XSRDPIZ_XSREDP_XSRESP_XSRSQRTEDP_XSRSQRTESP_XSSUBDP_XSSUBSP_XSCVDPSPN_XSRSP
  { 1, 318, 323, 2458, 2463 }, // 160 LVSL_LVSR
  { 0, 0, 0, 0, 0 }, // 161 VSPLTISB_VSPLTISH_VSPLTISW_VSPLTB_VSPLTBs_VSPLTH_VSPLTHs_VSPLTW_XXMRGHW_XXMRGLW_XXPERM_XXPERMR_XXSLDWI_XXSLDWIs_XXSPLTIB_XXSPLTW_XXSPLTWs_XXPERMDI_XXPERMDIs
  { 0, 0, 0, 0, 0 }, // 162 V_SETALLONES_V_SETALLONESB_V_SETALLONESH_VBPERMQ_VGBBD_VMRGHB_VMRGHH_VMRGHW_VMRGLB_VMRGLH_VMRGLW_VPERM_VPERMR_VPERMXOR_VPKPX_VPKSDSS_VPKSDUS_VPKSHSS_VPKSHUS_VPKSWSS_VPKSWUS_VPKUDUM_VPKUDUS_VPKUHUM_VPKUHUS_VPKUWUM_VPKUWUS_VSL_VSLDOI_VSLO_VSLV_VSR_VSRO_VSRV_VUPKHPX_VUPKHSB_VUPKHSH_VUPKHSW_VUPKLPX_VUPKLSB_VUPKLSH_VUPKLSW_XXBRD_XXBRH_XXBRQ_XXBRW_XXEXTRACTUW_XXINSERTW_VADDCUQ_VADDECUQ_VADDEUQM_VMUL10CUQ_VMUL10ECUQ_VMUL10EUQ_VMUL10UQ_VSUBCUQ_VSUBECUQ_VSUBEUQM_XSTSTDCQP_XSXSIGQP_BCDCFN_rec_BCDCFZ_rec_BCDCPSGN_rec_BCDCTN_rec_BCDCTZ_rec_BCDSETSGN_rec_BCDS_rec_BCDTRUNC_rec_BCDUS_rec_BCDUTRUNC_rec
  { 0, 0, 0, 0, 0 }, // 163 VEXTRACTUB_VEXTRACTUH_VEXTRACTUW_VINSERTB_VINSERTD_VINSERTH_VINSERTW_MFVSRLD_MTVSRWS_VCLZLSBB_VCTZLSBB_VEXTRACTD_VEXTUBLX_VEXTUBRX_VEXTUHLX_VEXTUHRX_VEXTUWLX_VEXTUWRX_VPRTYBQ_VADDUQM_VSUBUQM
  { 0, 0, 0, 0, 0 }, // 164 XSCMPEXPQP_XSCMPOQP_XSCMPUQP
  { 0, 0, 0, 0, 0 }, // 165 BCDSR_rec_XSADDQP_XSADDQPO_XSCVDPQP_XSCVQPDP_XSCVQPDPO_XSCVQPSDZ_XSCVQPSWZ_XSCVQPUDZ_XSCVQPUWZ_XSCVSDQP_XSCVUDQP_XSRQPI_XSRQPIX_XSRQPXP_XSSUBQP_XSSUBQPO
  { 0, 0, 0, 0, 0 }, // 166 BCDCTSQ_rec
  { 0, 0, 0, 0, 0 }, // 167 XSMADDQP_XSMADDQPO_XSMSUBQP_XSMSUBQPO_XSMULQP_XSMULQPO_XSNMADDQP_XSNMADDQPO_XSNMSUBQP_XSNMSUBQPO
  { 0, 0, 0, 0, 0 }, // 168 BCDCFSQ_rec
  { 0, 0, 0, 0, 0 }, // 169 XSDIVQP_XSDIVQPO
  { 0, 0, 0, 0, 0 }, // 170 XSSQRTQP_XSSQRTQPO
  { 1, 318, 323, 2463, 2468 }, // 171 LXVL_LXVLL
  { 1, 318, 323, 2468, 2473 }, // 172 LVEBX_LVEHX_LVEWX_LVX_LVXL
  { 0, 0, 0, 0, 0 }, // 173 LXSIBZX_LXSIHZX_LXSDX_LXVB16X_LXVD2X_LXVWSX_LXSIWZX_LXV_LXVX_LXSD
  { 0, 0, 0, 0, 0 }, // 174 DFLOADf64_XFLOADf64_LIWZX
  { 0, 0, 0, 0, 0 }, // 175 DCBF_DCBFEP_DCBST_DCBSTEP_DCBT_DCBTEP_DCBZ_DCBZEP_DCBZL_DCBZLEP_DCBTST_DCBTSTEP
  { 0, 0, 0, 0, 0 }, // 176 CP_COPY_CP_COPY8
  { 0, 0, 0, 0, 0 }, // 177 CP_PASTE_CP_PASTE8
  { 0, 0, 0, 0, 0 }, // 178 ICBI_ICBIEP
  { 1, 318, 323, 2473, 2478 }, // 179 ICBT_ICBTLS_LBZ_LBZ8_LBZCIX_LBZX_LBZX8_LBZXTLS_LBZXTLS__LBZXTLS_32_LDBRX_LDCIX_LHBRX_LHBRX8_LHZ_LHZ8_LHZCIX_LHZX_LHZX8_LHZXTLS_LHZXTLS__LHZXTLS_32_LWBRX_LWBRX8_LWZ_LWZ8_LWZCIX_LWZX_LWZX8_LWZXTLS_LWZXTLS__LWZXTLS_32_EnforceIEIO_LSWI
  { 0, 0, 0, 0, 0 }, // 180 LBARX_LBARXL_LHARX_LHARXL_LWARX_LWARXL
  { 0, 0, 0, 0, 0 }, // 181 LD_LDX_LDXTLS_LDXTLS__DARN
  { 0, 0, 0, 0, 0 }, // 182 LDARX_LDARXL
  { 0, 0, 0, 0, 0 }, // 183 CP_ABORT
  { 0, 0, 0, 0, 0 }, // 184 ISYNC
  { 0, 0, 0, 0, 0 }, // 185 MSGSYNC
  { 0, 0, 0, 0, 0 }, // 186 TLBSYNC
  { 0, 0, 0, 0, 0 }, // 187 SYNC
  { 0, 0, 0, 0, 0 }, // 188 LMW
  { 0, 0, 0, 0, 0 }, // 189 LFIWZX_LFDX_LFD
  { 0, 0, 0, 0, 0 }, // 190 SLBIA
  { 0, 0, 0, 0, 0 }, // 191 SLBIE
  { 0, 0, 0, 0, 0 }, // 192 SLBMFEE
  { 0, 0, 0, 0, 0 }, // 193 SLBMFEV
  { 0, 0, 0, 0, 0 }, // 194 SLBMTE
  { 0, 0, 0, 0, 0 }, // 195 TLBIEL
  { 2, 331, 336, 2478, 2483 }, // 196 LHZU_LHZU8_LWZU_LWZU8
  { 2, 331, 336, 2483, 2488 }, // 197 LHZUX_LHZUX8_LWZUX_LWZUX8
  { 1, 310, 315, 2488, 2493 }, // 198 TEND
  { 0, 0, 0, 0, 0 }, // 199 STBCX_STHCX_STWCX
  { 0, 0, 0, 0, 0 }, // 200 STDCX
  { 0, 0, 0, 0, 0 }, // 201 LDMX
  { 0, 0, 0, 0, 0 }, // 202 LHA_LHA8_LHAX_LHAX8_LWAX_LWAX_32
  { 0, 0, 0, 0, 0 }, // 203 CP_PASTE8_rec_CP_PASTE_rec
  { 0, 0, 0, 0, 0 }, // 204 LWA_LWA_32
  { 1, 310, 315, 2493, 2498 }, // 205 TCHECK
  { 0, 0, 0, 0, 0 }, // 206 LFIWAX
  { 0, 0, 0, 0, 0 }, // 207 LXSIWAX
  { 0, 0, 0, 0, 0 }, // 208 LIWAX
  { 0, 0, 0, 0, 0 }, // 209 LFSX_LFS
  { 0, 0, 0, 0, 0 }, // 210 LXSSP_LXSSPX
  { 0, 0, 0, 0, 0 }, // 211 XFLOADf32_DFLOADf32
  { 0, 0, 0, 0, 0 }, // 212 LHAU_LHAU8
  { 0, 0, 0, 0, 0 }, // 213 LHAUX_LHAUX8_LWAUX
  { 0, 0, 0, 0, 0 }, // 214 LXVH8X_LXVDSX_LXVW4X
  { 0, 0, 0, 0, 0 }, // 215 STFD_STFDX_STFIWX_STFS_STFSX_STXSD_STXSDX_STXSIBX_STXSIBXv_STXSIHX_STXSIHXv_STXSIWX_STXSSP_STXSSPX
  { 1, 327, 331, 2498, 2502 }, // 216 STW_STW8_STDBRX_STHBRX_STWBRX_STB_STB8_STH_STH8_STBX_STBX8_STBXTLS_STBXTLS__STBXTLS_32_STHX_STHX8_STHXTLS_STHXTLS__STHXTLS_32_STWX_STWX8_STWXTLS_STWXTLS__STWXTLS_32
  { 0, 0, 0, 0, 0 }, // 217 DFSTOREf32_DFSTOREf64_XFSTOREf32_XFSTOREf64_STIWX
  { 0, 0, 0, 0, 0 }, // 218 STD_STDX_STDXTLS_STDXTLS_
  { 1, 318, 323, 2502, 2507 }, // 219 STBCIX_STDCIX_STHCIX_STWCIX_STSWI
  { 0, 0, 0, 0, 0 }, // 220 SLBIEG
  { 0, 0, 0, 0, 0 }, // 221 STMW
  { 0, 0, 0, 0, 0 }, // 222 TLBIE
  { 1, 327, 331, 2507, 2511 }, // 223 STVEBX_STVEHX_STVEWX_STVX_STVXL
  { 0, 0, 0, 0, 0 }, // 224 STXV_STXVB16X_STXVD2X_STXVH8X_STXVW4X_STXVX
  { 1, 318, 323, 2511, 2516 }, // 225 STXVL_STXVLL
  { 1, 310, 315, 2516, 2521 }, // 226 MTCTR_MTCTR8_MTCTR8loop_MTCTRloop_MTLR_MTLR8
  { 1, 310, 315, 2521, 2526 }, // 227 MFVRSAVE_MFVRSAVEv_MTVRSAVE_MTVRSAVEv
  { 0, 0, 0, 0, 0 }, // 228 MFPMR
  { 0, 0, 0, 0, 0 }, // 229 MTPMR
  { 0, 0, 0, 0, 0 }, // 230 MFTB_MFTB8
  { 1, 310, 315, 2526, 2531 }, // 231 MFCTR_MFCTR8_MFLR_MFLR8_MFSPR_MFSPR8
  { 0, 0, 0, 0, 0 }, // 232 MFMSR
  { 0, 0, 0, 0, 0 }, // 233 MTMSR
  { 0, 0, 0, 0, 0 }, // 234 MTMSRD
  { 1, 310, 315, 2531, 2536 }, // 235 MTSPR_MTSPR8
  { 1, 323, 327, 2536, 2539 }, // 236 DIVW_DIVWO_DIVWU_DIVWUO_MODSW
  { 1, 323, 327, 2539, 2542 }, // 237 DIVWE_DIVWEO_DIVWEU_DIVWEUO_MODSD_MODUD_MODUW
  { 0, 0, 0, 0, 0 }, // 238 DIVD_DIVDO_DIVDU_DIVDUO
  { 0, 0, 0, 0, 0 }, // 239 DIVDE_DIVDEO_DIVDEU_DIVDEUO
  { 1, 323, 327, 2542, 2545 }, // 240 DIVWO_rec_DIVWUO_rec_DIVWU_rec_DIVW_rec
  { 0, 0, 0, 0, 0 }, // 241 DIVD_rec_DIVDO_rec_DIVDU_rec_DIVDUO_rec
  { 1, 323, 327, 2545, 2548 }, // 242 DIVWE_rec_DIVWEO_rec_DIVWEU_rec_DIVWEUO_rec
  { 0, 0, 0, 0, 0 }, // 243 DIVDE_rec_DIVDEO_rec_DIVDEU_rec_DIVDEUO_rec
  { 1, 336, 339, 2548, 2552 }, // 244 MTCRF_MTCRF8
  { 1, 310, 315, 2552, 2557 }, // 245 ADDC8O_rec_ADDC8_rec_ADDCO_rec_ADDC_rec_SUBFC8O_rec_SUBFC8_rec_SUBFCO_rec_SUBFC_rec
  { 0, 0, 0, 0, 0 }, // 246 FABSD_rec_FABSS_rec_FNABSD_rec_FNABSS_rec_FCPSGND_rec_FCPSGNS_rec_FNEGD_rec_FNEGS_rec_FMR_rec
  { 1, 315, 318, 2557, 2560 }, // 247 MCRFS
  { 0, 0, 0, 0, 0 }, // 248 MTFSF_MTFSF_rec_MTFSFI_MTFSFI_rec
  { 0, 0, 0, 0, 0 }, // 249 MTFSFb
  { 0, 0, 0, 0, 0 }, // 250 RLDCL_rec_RLDCR_rec
  { 0, 0, 0, 0, 0 }, // 251 RLDICL_rec_RLDICR_rec_RLDICL_32_rec_RLDIMI_rec
  { 1, 310, 315, 2560, 2565 }, // 252 RLWIMI8_rec_RLWIMI_rec
  { 1, 310, 315, 2565, 2570 }, // 253 RLWINM8_rec_RLWINM_rec_RLWNM8_rec_RLWNM_rec_SLW8_rec_SLW_rec_SRW8_rec_SRW_rec
  { 1, 310, 315, 2570, 2575 }, // 254 SRAWI_rec_SRAW_rec
  { 0, 0, 0, 0, 0 }, // 255 MFFS_MFFSCE_MFFSL_MFFS_rec
  { 0, 0, 0, 0, 0 }, // 256 MFCR_MFCR8
  { 0, 0, 0, 0, 0 }, // 257 EXTSWSLI_32_64_rec_SRADI_rec_EXTSWSLI_rec_RLDIC_rec
  { 0, 0, 0, 0, 0 }, // 258 SRAD_rec_SLD_rec_SRD_rec
  { 0, 0, 0, 0, 0 }, // 259 FDIV
  { 0, 0, 0, 0, 0 }, // 260 FDIV_rec
  { 0, 0, 0, 0, 0 }, // 261 XSSQRTDP
  { 0, 0, 0, 0, 0 }, // 262 FSQRT
  { 0, 0, 0, 0, 0 }, // 263 XVSQRTDP
  { 0, 0, 0, 0, 0 }, // 264 XVSQRTSP
  { 0, 0, 0, 0, 0 }, // 265 FSQRT_rec
  { 0, 0, 0, 0, 0 }, // 266 XSSQRTSP
  { 0, 0, 0, 0, 0 }, // 267 FSQRTS
  { 0, 0, 0, 0, 0 }, // 268 FSQRTS_rec
  { 0, 0, 0, 0, 0 }, // 269 XSDIVDP
  { 0, 0, 0, 0, 0 }, // 270 FDIVS
  { 0, 0, 0, 0, 0 }, // 271 FDIVS_rec
  { 0, 0, 0, 0, 0 }, // 272 XSDIVSP
  { 0, 0, 0, 0, 0 }, // 273 XVDIVSP
  { 0, 0, 0, 0, 0 }, // 274 XVDIVDP
  { 0, 0, 0, 0, 0 }, // 275 LFSU
  { 0, 0, 0, 0, 0 }, // 276 LFSUX
  { 0, 0, 0, 0, 0 }, // 277 STFDU_STFDUX_STFSU_STFSUX
  { 2, 344, 348, 2575, 2579 }, // 278 STBU_STBU8_STDU_STHU_STHU8_STWU_STWU8
  { 2, 344, 348, 2579, 2583 }, // 279 STBUX_STBUX8_STDUX_STHUX_STHUX8_STWUX_STWUX8
  { 2, 331, 336, 2583, 2588 }, // 280 LBZU_LBZU8
  { 2, 331, 336, 2588, 2593 }, // 281 LBZUX_LBZUX8
  { 0, 0, 0, 0, 0 }, // 282 LDU
  { 0, 0, 0, 0, 0 }, // 283 LDUX
  { 0, 0, 0, 0, 0 }, // 284 LFDU
  { 0, 0, 0, 0, 0 }, // 285 LFDUX
  { 0, 0, 0, 0, 0 }, // 286 VPMSUMB_VPMSUMD_VPMSUMH_VPMSUMW_VCIPHER_VCIPHERLAST_VNCIPHER_VNCIPHERLAST_VSBOX
  { 1, 315, 318, 2593, 2596 }, // 287 BCCCTR_BCCCTR8_BCCCTRL_BCCCTRL8_BCCL_BCCLA_BCCLR_BCCLRL_BCCTR_BCCTR8_BCCTR8n_BCCTRL_BCCTRL8_BCCTRL8n_BCCTRLn_BCCTRn_BDNZ_BDNZ8_BDNZA_BDNZAm_BDNZAp_BDNZm_BDNZp_BDZ_BDZ8_BDZA_BDZAm_BDZAp_BDZm_BDZp_BDNZL_BDNZLA_BDNZLAm_BDNZLAp_BDNZLR_BDNZLR8_BDNZLRL_BDNZLRLm_BDNZLRLp_BDNZLRm_BDNZLRp_BDNZLm_BDNZLp_BDZL_BDZLA_BDZLAm_BDZLAp_BDZLR_BDZLR8_BDZLRL_BDZLRLm_BDZLRLp_BDZLRm_BDZLRp_BDZLm_BDZLp_BL_BL_NOP_BL_TLS_BL8_BL8_NOP_BL8_NOP_TLS_BL8_TLS_BL8_TLS__BLA_BLA8_BLA8_NOP_BLR_BLR8_BLRL_TAILB_TAILB8_TAILBA_TAILBA8_TAILBCTR_TAILBCTR8_gBC_gBCA_gBCAat_gBCCTR_gBCCTRL_gBCL_gBCLA_gBCLAat_gBCLR_gBCLRL_gBCLat_gBCat_BCLR_BCLRL_BCLRLn_BCLRn_BCTR_BCTR8_BCTRL_BCTRL8_B_BA_BC_BCC_BCCA_BCL_BCLalways_BCLn_BCTRL8_LDinto_toc_BCTRL_LWZinto_toc_BCn_CTRL_DEP
  { 1, 315, 318, 2596, 2599 }, // 288 ADDPCIS
  { 1, 318, 323, 2599, 2604 }, // 289 LDAT_LWAT
  { 1, 327, 331, 2604, 2608 }, // 290 STDAT_STWAT
  { 1, 310, 315, 2608, 2613 }, // 291 BRINC
  { 0, 0, 0, 0, 0 }, // 292 EVABS_EVEQV_EVNAND_EVNEG_EVADDIW_EVADDW_EVAND_EVANDC_EVCMPEQ_EVCMPGTS_EVCMPGTU_EVCMPLTS_EVCMPLTU_EVCNTLSW_EVCNTLZW_EVEXTSB_EVEXTSH_EVMERGEHI_EVMERGEHILO_EVMERGELO_EVMERGELOHI_EVNOR_EVOR_EVORC_EVXOR_EVRLW_EVRLWI_EVRNDW_EVSLW_EVSLWI_EVSPLATFI_EVSPLATI_EVSRWIS_EVSRWIU_EVSRWS_EVSRWU_EVSUBFW_EVSUBIFW
  { 0, 0, 0, 0, 0 }, // 293 EVMRA_EVADDSMIAAW_EVADDSSIAAW_EVADDUMIAAW_EVADDUSIAAW_EVDIVWS_EVDIVWU_EVMHEGSMFAA_EVMHEGSMFAN_EVMHEGSMIAA_EVMHEGSMIAN_EVMHEGUMIAA_EVMHEGUMIAN_EVMHESMF_EVMHESMFA_EVMHESMFAAW_EVMHESMFANW_EVMHESMI_EVMHESMIA_EVMHESMIAAW_EVMHESMIANW_EVMHESSF_EVMHESSFA_EVMHESSFAAW_EVMHESSFANW_EVMHESSIAAW_EVMHESSIANW_EVMHEUMI_EVMHEUMIA_EVMHEUMIAAW_EVMHEUMIANW_EVMHEUSIAAW_EVMHEUSIANW_EVMHOGSMFAA_EVMHOGSMFAN_EVMHOGSMIAA_EVMHOGSMIAN_EVMHOGUMIAA_EVMHOGUMIAN_EVMHOSMF_EVMHOSMFA_EVMHOSMFAAW_EVMHOSMFANW_EVMHOSMI_EVMHOSMIA_EVMHOSMIAAW_EVMHOSMIANW_EVMHOSSF_EVMHOSSFA_EVMHOSSFAAW_EVMHOSSFANW_EVMHOSSIAAW_EVMHOSSIANW_EVMHOUMI_EVMHOUMIA_EVMHOUMIAAW_EVMHOUMIANW_EVMHOUSIAAW_EVMHOUSIANW_EVMWHSMF_EVMWHSMFA_EVMWHSMI_EVMWHSMIA_EVMWHSSF_EVMWHSSFA_EVMWHUMI_EVMWHUMIA_EVMWLSMIAAW_EVMWLSMIANW_EVMWLSSIAAW_EVMWLSSIANW_EVMWLUMI_EVMWLUMIA_EVMWLUMIAAW_EVMWLUMIANW_EVMWLUSIAAW_EVMWLUSIANW_EVMWSMF_EVMWSMFA_EVMWSMFAA_EVMWSMFAN_EVMWSMI_EVMWSMIA_EVMWSMIAA_EVMWSMIAN_EVMWSSF_EVMWSSFA_EVMWSSFAA_EVMWSSFAN_EVMWUMI_EVMWUMIA_EVMWUMIAA_EVMWUMIAN_EVSUBFSMIAAW_EVSUBFSSIAAW_EVSUBFUMIAAW_EVSUBFUSIAAW
  { 1, 318, 323, 2613, 2618 }, // 294 EVLDD_EVLDDX_EVLDH_EVLDHX_EVLDW_EVLDWX_EVLHHESPLAT_EVLHHESPLATX_EVLHHOSSPLAT_EVLHHOSSPLATX_EVLHHOUSPLAT_EVLHHOUSPLATX_EVLWHE_EVLWHEX_EVLWHOS_EVLWHOSX_EVLWHOU_EVLWHOUX_EVLWHSPLAT_EVLWHSPLATX_EVLWWSPLAT_EVLWWSPLATX
  { 1, 327, 331, 2618, 2622 }, // 295 EVSTDD_EVSTDDX_EVSTDH_EVSTDHX_EVSTDW_EVSTDWX_EVSTWHE_EVSTWHEX_EVSTWHO_EVSTWHOX_EVSTWWE_EVSTWWEX_EVSTWWO_EVSTWWOX
  { 1, 315, 318, 2622, 2625 }, // 296 HRFID_ATTN_CLRBHRB_MFBHRBE_NAP_RFCI_RFDI_RFMCI_SC
  { 0, 0, 0, 0, 0 }, // 297 RFI
  { 0, 0, 0, 0, 0 }, // 298 RFID
  { 1, 318, 323, 2625, 2630 }, // 299 DSS_DSSALL_DST_DST64_DSTST_DSTST64_DSTSTT_DSTSTT64_DSTT_DSTT64_ICBLQ_LBEPX_LHEPX_LWEPX_TLBIVAX_TLBLD_TLBLI_TLBRE_TLBRE2_TLBSX_TLBSX2_TLBSX2D_TLBWE_TLBWE2_MBAR_TRAP_DCCCI_ICCCI
  { 1, 327, 331, 2630, 2634 }, // 300 ICBLC_STBEPX_STHEPX_STWEPX
  { 0, 0, 0, 0, 0 }, // 301 LFDEPX
  { 0, 0, 0, 0, 0 }, // 302 STFDEPX
  { 0, 0, 0, 0, 0 }, // 303 MFSR_MFSRIN
  { 0, 0, 0, 0, 0 }, // 304 MTSR_MTSRIN
  { 1, 310, 315, 2634, 2639 }, // 305 MFDCR
  { 1, 310, 315, 2639, 2644 }, // 306 MTDCR
  { 1, 310, 315, 2644, 2649 }, // 307 NOP_GT_PWR6_NOP_GT_PWR7
  { 0, 0, 0, 0, 0 }, // 308 TLBIA
  { 0, 0, 0, 0, 0 }, // 309 WRTEE_WRTEEI
  { 0, 0, 0, 0, 0 }, // 310 MSYNC
  { 0, 0, 0, 0, 0 }, // 311 SLBSYNC
  { 0, 0, 0, 0, 0 }, // 312 SLBFEE_rec
  { 0, 0, 0, 0, 0 }, // 313 STOP
  { 0, 0, 0, 0, 0 }, // 314 DCBA_DCBI
  { 0, uint16_t(~0U), uint16_t(~0U), uint16_t(~0U), uint16_t(~0U) }// end marker
};

static const llvm::InstrItinerary PPCE200Z7Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 0, 0, 0, 0, 0 }, // 1 IIC_LdStSync
  { 1, 353, 356, 2649, 2652 }, // 2 IIC_IntSimple
  { 1, 353, 356, 2652, 2655 }, // 3 IIC_IntGeneral
  { 1, 356, 359, 2655, 2658 }, // 4 IIC_BrB
  { 0, 0, 0, 0, 0 }, // 5 IIC_VecFP
  { 1, 353, 356, 2658, 2661 }, // 6 IIC_IntCompare
  { 0, 0, 0, 0, 0 }, // 7 IIC_SprABORT
  { 0, 0, 0, 0, 0 }, // 8 IIC_LdStCOPY
  { 0, 0, 0, 0, 0 }, // 9 IIC_LdStPASTE
  { 1, 356, 359, 2661, 2665 }, // 10 IIC_BrCR
  { 0, 0, 0, 0, 0 }, // 11 IIC_LdStLD
  { 0, 0, 0, 0, 0 }, // 12 IIC_LdStDCBF
  { 1, 359, 362, 2665, 2668 }, // 13 IIC_LdStLoad
  { 0, 0, 0, 0, 0 }, // 14 IIC_IntDivD
  { 1, 362, 366, 2668, 2671 }, // 15 IIC_IntDivW
  { 0, 0, 0, 0, 0 }, // 16 IIC_FPDGeneral
  { 1, 366, 370, 2671, 2675 }, // 17 IIC_FPAddSub
  { 0, 0, 0, 0, 0 }, // 18 IIC_FPDivD
  { 0, 0, 0, 0, 0 }, // 19 IIC_FPSGeneral
  { 1, 370, 374, 2675, 2679 }, // 20 IIC_FPCompare
  { 1, 370, 374, 2679, 2683 }, // 21 IIC_FPGeneral
  { 1, 374, 377, 2683, 2686 }, // 22 IIC_VecGeneral
  { 1, 377, 381, 2686, 2689 }, // 23 IIC_VecComplex
  { 1, 359, 362, 2689, 2692 }, // 24 IIC_LdStStore
  { 0, 0, 0, 0, 0 }, // 25 IIC_IntRotateDI
  { 1, 381, 385, 2692, 2696 }, // 26 IIC_FPDivS
  { 0, 0, 0, 0, 0 }, // 27 IIC_FPFused
  { 0, 0, 0, 0, 0 }, // 28 IIC_FPSqrtD
  { 0, 0, 0, 0, 0 }, // 29 IIC_FPSqrtS
  { 0, 0, 0, 0, 0 }, // 30 IIC_LdStICBI
  { 1, 353, 356, 2696, 2700 }, // 31 IIC_IntISEL
  { 0, 0, 0, 0, 0 }, // 32 IIC_SprISYNC
  { 0, 0, 0, 0, 0 }, // 33 IIC_LdStLWARX
  { 2, 385, 389, 2700, 2703 }, // 34 IIC_LdStLoadUpd
  { 2, 385, 389, 2703, 2706 }, // 35 IIC_LdStLoadUpdX
  { 0, 0, 0, 0, 0 }, // 36 IIC_LdStLDARX
  { 0, 0, 0, 0, 0 }, // 37 IIC_LdStLDU
  { 0, 0, 0, 0, 0 }, // 38 IIC_LdStLDUX
  { 0, 0, 0, 0, 0 }, // 39 IIC_LdStLFD
  { 0, 0, 0, 0, 0 }, // 40 IIC_LdStLFDU
  { 0, 0, 0, 0, 0 }, // 41 IIC_LdStLFDUX
  { 0, 0, 0, 0, 0 }, // 42 IIC_LdStLHA
  { 0, 0, 0, 0, 0 }, // 43 IIC_LdStLHAU
  { 0, 0, 0, 0, 0 }, // 44 IIC_LdStLHAUX
  { 0, 0, 0, 0, 0 }, // 45 IIC_LdStLMW
  { 0, 0, 0, 0, 0 }, // 46 IIC_LdStLWA
  { 0, 0, 0, 0, 0 }, // 47 IIC_IntMulHD
  { 1, 356, 359, 2706, 2709 }, // 48 IIC_BrMCR
  { 1, 353, 356, 2709, 2713 }, // 49 IIC_BrMCRX
  { 0, 0, 0, 0, 0 }, // 50 IIC_SprMFCR
  { 0, 0, 0, 0, 0 }, // 51 IIC_SprMFSPR
  { 0, 0, 0, 0, 0 }, // 52 IIC_IntMFFS
  { 0, 0, 0, 0, 0 }, // 53 IIC_SprMFMSR
  { 0, 0, 0, 0, 0 }, // 54 IIC_SprMFCRF
  { 0, 0, 0, 0, 0 }, // 55 IIC_SprMFPMR
  { 0, 0, 0, 0, 0 }, // 56 IIC_SprMFSR
  { 0, 0, 0, 0, 0 }, // 57 IIC_SprMFTB
  { 0, 0, 0, 0, 0 }, // 58 IIC_SprMSGSYNC
  { 0, 0, 0, 0, 0 }, // 59 IIC_SprMTSPR
  { 0, 0, 0, 0, 0 }, // 60 IIC_IntMTFSB0
  { 0, 0, 0, 0, 0 }, // 61 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 62 IIC_SprMTMSRD
  { 0, 0, 0, 0, 0 }, // 63 IIC_SprMTPMR
  { 0, 0, 0, 0, 0 }, // 64 IIC_SprMTSR
  { 1, 389, 393, 2713, 2716 }, // 65 IIC_IntMulHW
  { 1, 389, 393, 2716, 2719 }, // 66 IIC_IntMulHWU
  { 1, 389, 393, 2719, 2722 }, // 67 IIC_IntMulLI
  { 0, 0, 0, 0, 0 }, // 68 IIC_VecPerm
  { 0, 0, 0, 0, 0 }, // 69 IIC_LdStSTFD
  { 0, 0, 0, 0, 0 }, // 70 IIC_LdStSTFDU
  { 0, 0, 0, 0, 0 }, // 71 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 72 IIC_IntRFID
  { 0, 0, 0, 0, 0 }, // 73 IIC_IntRotateD
  { 1, 353, 356, 2722, 2725 }, // 74 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 75 IIC_SprSLBFEE
  { 0, 0, 0, 0, 0 }, // 76 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 77 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprSLBIEG
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprSLBMFEV
  { 0, 0, 0, 0, 0 }, // 81 IIC_SprSLBMTE
  { 0, 0, 0, 0, 0 }, // 82 IIC_SprSLBSYNC
  { 1, 353, 356, 2725, 2728 }, // 83 IIC_IntShift
  { 0, 0, 0, 0, 0 }, // 84 IIC_LdStSTWCX
  { 2, 385, 389, 2728, 2731 }, // 85 IIC_LdStSTU
  { 2, 385, 389, 2731, 2734 }, // 86 IIC_LdStSTUX
  { 0, 0, 0, 0, 0 }, // 87 IIC_LdStSTD
  { 0, 0, 0, 0, 0 }, // 88 IIC_LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 89 IIC_SprSTOP
  { 0, 0, 0, 0, 0 }, // 90 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 91 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 92 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 93 IIC_SprTLBIEL
  { 0, 0, 0, 0, 0 }, // 94 IIC_SprTLBSYNC
  { 1, 393, 396, 2734, 2737 }, // 95 IIC_IntTrapW
  { 0, 0, 0, 0, 0 }, // 96 IIC_VecFPCompare
  { 1, 374, 377, 2737, 2740 }, // 97 VADDUBM_VADDUDM_VADDUHM_VADDUWM_VEXTSB2D_VEXTSB2Ds_VEXTSB2W_VEXTSB2Ws_VEXTSH2D_VEXTSH2Ds_VEXTSH2W_VEXTSH2Ws_VEXTSW2D_VEXTSW2Ds_VSLD_VSRD_VSUBUBM_VSUBUDM_VSUBUHM_VSUBUWM_VPOPCNTB_VPOPCNTH_VSRAD_MTVSRDD_VEQV_VNAND_VNEGD_VNEGW_VORC_XXLAND_XXLANDC_XXLEQV_XXLEQVOnes_XXLNAND_XXLNOR_XXLOR_XXLORf_XXLORC_XXLXOR_XXLXORdpz_XXLXORspz_XXLXORz
  { 0, 0, 0, 0, 0 }, // 98 VAND_VANDC_V_SET0_V_SET0B_V_SET0H_VSLB_VSLH_VSLW_VSRB_VSRH_VSRW_VRLB_VRLD_VRLH_VRLW_VSRAB_VSRAH_VSRAW_XVABSDP_XVABSSP_XVNABSDP_XVNABSSP_XVCPSGNDP_XVCPSGNSP_XVIEXPDP_XVIEXPSP_XVXEXPDP_XVXEXPSP_VRLDMI_VRLDNM_VRLWMI_VRLWNM_VMRGEW_VMRGOW_VNOR_VOR_VSEL_VXOR_XVNEGDP_XVNEGSP_XSABSQP_XSCPSGNQP_XSIEXPQP_XSNABSQP_XSNEGQP_XSXEXPQP
  { 0, 0, 0, 0, 0 }, // 99 XXSEL
  { 0, 0, 0, 0, 0 }, // 100 TABORTDC_TABORTDCI_TABORTWC_TABORTWCI
  { 0, 0, 0, 0, 0 }, // 101 MTFSB0_MTFSB1
  { 0, 0, 0, 0, 0 }, // 102 MFFSCDRN_MFFSCDRNI_MFFSCRN_MFFSCRNI
  { 1, 353, 356, 2740, 2743 }, // 103 CMPRB_CMPRB8_CMPEQB
  { 0, 0, 0, 0, 0 }, // 104 TD_TDI
  { 1, 393, 396, 2743, 2746 }, // 105 TW_TWI
  { 1, 370, 374, 2746, 2750 }, // 106 FCMPUD_FCMPUS_FTDIV_FTSQRT
  { 0, 0, 0, 0, 0 }, // 107 XSTSTDCDP_XSTSTDCSP
  { 0, 0, 0, 0, 0 }, // 108 XSMAXCDP_XSMAXDP_XSMAXJDP_XSMINCDP_XSMINDP_XSMINJDP_XSXSIGDP_XSCVSPDPN
  { 1, 370, 374, 2750, 2754 }, // 109 XSCMPEQDP_XSCMPEXPDP_XSCMPGEDP_XSCMPGTDP_XSCMPODP_XSCMPUDP_XSTDIVDP_XSTSQRTDP
  { 1, 353, 356, 2754, 2757 }, // 110 CNTLZD_CNTLZD_rec_CNTLZW_CNTLZW8_CNTLZW8_rec_CNTLZW_rec_CNTTZD_CNTTZD_rec_CNTTZW_CNTTZW8_CNTTZW8_rec_CNTTZW_rec_POPCNTD_POPCNTW_CMPB_CMPB8_SETB_SETB8_BPERMD
  { 0, 0, 0, 0, 0 }, // 111 SLD_SRD_SRAD
  { 0, 0, 0, 0, 0 }, // 112 SRADI_EXTSWSLI_32_64_EXTSWSLI_SRADI_32_RLDIC
  { 1, 374, 377, 2757, 2760 }, // 113 MFVRD_MFVSRD_MTVRD_MTVSRD_MTVRWA_MTVRWZ_MTVSRWA_MTVSRWZ_MFVSRWZ_MFVRWZ
  { 1, 353, 356, 2760, 2763 }, // 114 CMPLW_CMPLWI_CMPW_CMPWI_CMPD_CMPDI_CMPLD_CMPLDI
  { 1, 353, 356, 2763, 2766 }, // 115 SUBFC_SUBFC8_SUBFC8O_SUBFCO_SUBFIC_SUBFIC8_ANDI8_rec_ANDIS8_rec_ANDIS_rec_ANDI_rec_ADDC_ADDC8_ADDC8O_ADDCO_ADDIC_ADDIC8_ADDIC_rec_ADDE_ADDE8_ADDE8O_ADDE8O_rec_ADDE8_rec_ADDEO_ADDEO_rec_ADDE_rec_ADDME_ADDME8_ADDME8O_ADDME8O_rec_ADDME8_rec_ADDMEO_ADDMEO_rec_ADDME_rec_ADDZE_ADDZE8_ADDZE8O_ADDZE8O_rec_ADDZE8_rec_ADDZEO_ADDZEO_rec_ADDZE_rec_SUBF_SUBF8_SUBF8O_SUBF8O_rec_SUBF8_rec_SUBFE_SUBFE8_SUBFE8O_SUBFE8O_rec_SUBFE8_rec_SUBFEO_SUBFEO_rec_SUBFE_rec_SUBFME_SUBFME8_SUBFME8O_SUBFME8O_rec_SUBFME8_rec_SUBFMEO_SUBFMEO_rec_SUBFME_rec_SUBFO_SUBFO_rec_SUBFZE_SUBFZE8_SUBFZE8O_SUBFZE8O_rec_SUBFZE8_rec_SUBFZEO_SUBFZEO_rec_SUBFZE_rec_SUBF_rec_POPCNTB_LA
  { 1, 353, 356, 2766, 2769 }, // 116 ADD4_ADD4O_ADD4O_rec_ADD4_rec_ADD8_ADD8O_ADD8O_rec_ADD8_rec_NEG_NEG8_NEG8O_NEG8O_rec_NEG8_rec_NEGO_NEGO_rec_NEG_rec_ADDI_ADDI8_ADDIS_ADDIS8_LI_LI8_LIS_LIS8_OR_OR8_OR8_rec_ORI_ORI8_ORIS_ORIS8_OR_rec_XOR_XOR8_XOR8_rec_XORI_XORI8_XORIS_XORIS8_XOR_rec_NAND_NAND8_NAND8_rec_NAND_rec_AND_AND8_AND8_rec_ANDC_ANDC8_ANDC8_rec_ANDC_rec_AND_rec_NOR_NOR8_NOR8_rec_NOR_rec_ORC_ORC8_ORC8_rec_ORC_rec_EQV_EQV8_EQV8_rec_EQV_rec_EXTSB_EXTSB8_EXTSB8_32_64_EXTSB8_rec_EXTSB_rec_EXTSH_EXTSH8_EXTSH8_32_64_EXTSH8_rec_EXTSH_rec_EXTSW_EXTSW_32_EXTSW_32_64_EXTSW_32_64_rec_EXTSW_rec_ADD4TLS_ADD8TLS_ADD8TLS__NOP
  { 0, 0, 0, 0, 0 }, // 117 ADDIStocHA_ADDIStocHA8_ADDItocL_COPY
  { 1, 356, 359, 2769, 2772 }, // 118 MCRF
  { 1, 353, 356, 2772, 2776 }, // 119 MCRXRX
  { 0, 0, 0, 0, 0 }, // 120 XSNABSDP_XSXEXPDP_XSABSDP_XSNEGDP_XSCPSGNDP
  { 1, 356, 359, 2776, 2779 }, // 121 RFEBB
  { 0, 0, 0, 0, 0 }, // 122 TBEGIN_TRECHKPT
  { 1, 359, 362, 2779, 2782 }, // 123 WAIT
  { 0, 0, 0, 0, 0 }, // 124 RLDCL_RLDCR
  { 1, 353, 356, 2782, 2785 }, // 125 RLWIMI_RLWIMI8
  { 0, 0, 0, 0, 0 }, // 126 RLDICL_RLDICL_32_RLDICL_32_64_RLDICR_RLDICR_32_RLDIMI
  { 0, 0, 0, 0, 0 }, // 127 MFOCRF_MFOCRF8
  { 1, 353, 356, 2785, 2789 }, // 128 MTOCRF_MTOCRF8
  { 1, 356, 359, 2789, 2793 }, // 129 CR6SET_CR6UNSET_CRSET_CRUNSET_CRAND_CRANDC_CRNAND_CRNOR_CROR_CRORC_CREQV_CRXOR
  { 1, 353, 356, 2793, 2796 }, // 130 SLW_SLW8_SRW_SRW8_RLWINM_RLWINM8_RLWNM_RLWNM8
  { 1, 370, 374, 2796, 2800 }, // 131 FABSD_FABSS_FNABSD_FNABSS_FNEGD_FNEGS_FCPSGND_FCPSGNS_FMR
  { 1, 353, 356, 2800, 2803 }, // 132 SRAW_SRAWI
  { 1, 353, 356, 2803, 2807 }, // 133 ISEL_ISEL8
  { 0, 0, 0, 0, 0 }, // 134 XSIEXPDP
  { 0, 0, 0, 0, 0 }, // 135 TRECLAIM_TSR_TABORT
  { 1, 359, 362, 2807, 2810 }, // 136 MFVSCR
  { 1, 359, 362, 2810, 2813 }, // 137 MTVSCR
  { 0, 0, 0, 0, 0 }, // 138 VCMPNEZB_VCMPNEZH_VCMPNEZW_VCMPEQUB_VCMPEQUD_VCMPEQUH_VCMPEQUW_VCMPNEB_VCMPNEH_VCMPNEW_VCMPEQFP_VCMPEQFP_rec_VCMPGEFP_VCMPGEFP_rec_VCMPGTFP_VCMPGTFP_rec_VCMPBFP_VCMPBFP_rec_VCMPGTSB_VCMPGTSB_rec_VCMPGTSD_VCMPGTSD_rec_VCMPGTSH_VCMPGTSH_rec_VCMPGTSW_VCMPGTSW_rec_VCMPGTUB_VCMPGTUB_rec_VCMPGTUD_VCMPGTUD_rec_VCMPGTUH_VCMPGTUH_rec_VCMPGTUW_VCMPGTUW_rec_VCMPNEB_rec_VCMPNEH_rec_VCMPNEW_rec_VCMPNEZB_rec_VCMPNEZH_rec_VCMPNEZW_rec_VCMPEQUB_rec_VCMPEQUD_rec_VCMPEQUH_rec_VCMPEQUW_rec_XVCMPEQDP_XVCMPEQDP_rec_XVCMPEQSP_XVCMPEQSP_rec_XVCMPGEDP_XVCMPGEDP_rec_XVCMPGESP_XVCMPGESP_rec_XVCMPGTDP_XVCMPGTDP_rec_XVCMPGTSP_XVCMPGTSP_rec
  { 1, 374, 377, 2813, 2816 }, // 139 VABSDUB_VABSDUH_VABSDUW_VCLZB_VCLZD_VCLZH_VCLZW_VCTZB_VCTZD_VCTZH_VCTZW_VPOPCNTW_VPOPCNTD_VPRTYBD_VPRTYBW
  { 0, 0, 0, 0, 0 }, // 140 VADDUBS_VADDUHS_VADDUWS_VAVGSB_VAVGSH_VAVGSW_VAVGUB_VAVGUH_VAVGUW_VADDSBS_VADDSHS_VADDSWS_VMAXFP_VMINFP_VMAXSB_VMAXSD_VMAXSH_VMAXSW_VMAXUB_VMAXUD_VMAXUH_VMAXUW_VMINSB_VMINSD_VMINSH_VMINSW_VMINUB_VMINUD_VMINUH_VMINUW_VBPERMD_VADDCUW_VSHASIGMAD_VSHASIGMAW_VSUBSBS_VSUBSHS_VSUBSWS_VSUBUBS_VSUBUHS_VSUBUWS_VSUBCUW_XVMAXDP_XVMAXSP_XVMINDP_XVMINSP_XVTSTDCDP_XVTSTDCSP_XVXSIGDP_XVXSIGSP
  { 1, 370, 374, 2816, 2820 }, // 141 XVTDIVDP_XVTDIVSP_XVTSQRTDP_XVTSQRTSP
  { 0, 0, 0, 0, 0 }, // 142 VADDFP_VCTSXS_VCTSXS_0_VCTUXS_VCTUXS_0_VEXPTEFP_VLOGEFP_VMADDFP_VMHADDSHS_VNMSUBFP_VREFP_VRFIM_VRFIN_VRFIP_VRFIZ_VRSQRTEFP_XVADDDP_XVADDSP_XVCVDPSP_XVCVDPSXDS_XVCVDPSXWS_XVCVDPUXDS_XVCVDPUXWS_XVCVHPSP_XVCVSPDP_XVCVSPHP_XVCVSPSXDS_XVCVSPSXWS_XVCVSPUXDS_XVCVSPUXWS_XVCVSXDDP_XVCVSXDSP_XVCVSXWDP_XVCVSXWSP_XVCVUXDDP_XVCVUXDSP_XVCVUXWDP_XVCVUXWSP_XVMADDADP_XVMADDASP_XVMADDMDP_XVMADDMSP_XVMSUBADP_XVMSUBASP_XVMSUBMDP_XVMSUBMSP_XVMULDP_XVMULSP_XVNMADDADP_XVNMADDASP_XVNMADDMDP_XVNMADDMSP_XVNMSUBADP_XVNMSUBASP_XVNMSUBMDP_XVNMSUBMSP_XVRDPI_XVRDPIC_XVRDPIM_XVRDPIP_XVRDPIZ_XVREDP_XVRESP_XVRSPI_XVRSPIC_XVRSPIM_XVRSPIP_XVRSPIZ_XVRSQRTEDP_XVRSQRTESP_XVSUBDP_XVSUBSP_VCFSX_VCFSX_0_VCFUX_VCFUX_0_VMHRADDSHS_VMLADDUHM_VMSUMMBM_VMSUMSHM_VMSUMSHS_VMSUMUBM_VMSUMUHM_VMSUMUDM_VMSUMUHS_VMULESB_VMULESH_VMULESW_VMULEUB_VMULEUH_VMULEUW_VMULOSB_VMULOSH_VMULOSW_VMULOUB_VMULOUH_VMULOUW_VSUM2SWS_VSUM4SBS_VSUM4SHS_VSUM4UBS_VSUMSWS
  { 1, 374, 377, 2820, 2823 }, // 143 VSUBFP_VMULUWM
  { 0, 0, 0, 0, 0 }, // 144 MADDHD_MADDHDU_MADDLD_MADDLD8_MULLD_MULLDO
  { 1, 389, 393, 2823, 2826 }, // 145 MULHD_MULHW_MULLW_MULLWO
  { 1, 389, 393, 2826, 2829 }, // 146 MULHDU_MULHWU
  { 1, 389, 393, 2829, 2832 }, // 147 MULLI_MULLI8
  { 1, 370, 374, 2832, 2836 }, // 148 FRSP_FRIMD_FRIMS_FRIND_FRINS_FRIPD_FRIPS_FRIZD_FRIZS_FRE_FRES_FADDS_FMSUBS_FMADDS_FSUBS_FCFID_FCFIDS_FCFIDU_FCFIDUS_FCTID_FCTIDU_FCTIDUZ_FCTIDZ_FCTIW_FCTIWU_FCTIWUZ_FCTIWZ_FRSQRTE_FRSQRTES_FNMADDS_FNMSUBS_FSELD_FSELS_FMULS
  { 1, 366, 370, 2836, 2840 }, // 149 FADD_FSUB
  { 0, 0, 0, 0, 0 }, // 150 FMSUB_FMADD_FNMADD_FNMSUB_FMUL
  { 0, 0, 0, 0, 0 }, // 151 XSMADDADP_XSMADDASP_XSMADDMDP_XSMADDMSP_XSMSUBADP_XSMSUBASP_XSMSUBMDP_XSMSUBMSP_XSMULDP_XSMULSP_XSNMADDADP_XSNMADDASP_XSNMADDMDP_XSNMADDMSP_XSNMSUBADP_XSNMSUBASP_XSNMSUBMDP_XSNMSUBMSP
  { 1, 370, 374, 2840, 2844 }, // 152 FSELD_rec_FSELS_rec
  { 1, 389, 393, 2844, 2847 }, // 153 MULHDU_rec_MULHWU_rec
  { 1, 389, 393, 2847, 2850 }, // 154 MULHD_rec_MULHW_rec_MULLWO_rec_MULLW_rec
  { 0, 0, 0, 0, 0 }, // 155 MULLDO_rec_MULLD_rec
  { 1, 370, 374, 2850, 2854 }, // 156 FRIMD_rec_FRIMS_rec_FRIND_rec_FRINS_rec_FRIPD_rec_FRIPS_rec_FRIZD_rec_FRIZS_rec_FRES_rec_FRE_rec_FADDS_rec_FSUBS_rec_FMSUBS_rec_FNMSUBS_rec_FMADDS_rec_FNMADDS_rec_FCFIDS_rec_FCFIDUS_rec_FCFIDU_rec_FCFID_rec_FCTIDUZ_rec_FCTIDU_rec_FCTIDZ_rec_FCTID_rec_FCTIWUZ_rec_FCTIWU_rec_FCTIWZ_rec_FCTIW_rec_FMULS_rec_FRSQRTES_rec_FRSQRTE_rec_FRSP_rec
  { 1, 366, 370, 2854, 2858 }, // 157 FADD_rec_FSUB_rec
  { 0, 0, 0, 0, 0 }, // 158 FMSUB_rec_FNMSUB_rec_FMADD_rec_FNMADD_rec_FMUL_rec
  { 0, 0, 0, 0, 0 }, // 159 XSADDDP_XSADDSP_XSCVDPHP_XSCVDPSP_XSCVDPSXDS_XSCVDPSXDSs_XSCVDPSXWS_XSCVDPUXDS_XSCVDPUXDSs_XSCVDPUXWS_XSCVDPSXWSs_XSCVDPUXWSs_XSCVHPDP_XSCVSPDP_XSCVSXDDP_XSCVSXDSP_XSCVUXDDP_XSCVUXDSP_XSRDPI_XSRDPIC_XSRDPIM_XSRDPIP_XSRDPIZ_XSREDP_XSRESP_XSRSQRTEDP_XSRSQRTESP_XSSUBDP_XSSUBSP_XSCVDPSPN_XSRSP
  { 1, 359, 362, 2858, 2861 }, // 160 LVSL_LVSR
  { 0, 0, 0, 0, 0 }, // 161 VSPLTISB_VSPLTISH_VSPLTISW_VSPLTB_VSPLTBs_VSPLTH_VSPLTHs_VSPLTW_XXMRGHW_XXMRGLW_XXPERM_XXPERMR_XXSLDWI_XXSLDWIs_XXSPLTIB_XXSPLTW_XXSPLTWs_XXPERMDI_XXPERMDIs
  { 0, 0, 0, 0, 0 }, // 162 V_SETALLONES_V_SETALLONESB_V_SETALLONESH_VBPERMQ_VGBBD_VMRGHB_VMRGHH_VMRGHW_VMRGLB_VMRGLH_VMRGLW_VPERM_VPERMR_VPERMXOR_VPKPX_VPKSDSS_VPKSDUS_VPKSHSS_VPKSHUS_VPKSWSS_VPKSWUS_VPKUDUM_VPKUDUS_VPKUHUM_VPKUHUS_VPKUWUM_VPKUWUS_VSL_VSLDOI_VSLO_VSLV_VSR_VSRO_VSRV_VUPKHPX_VUPKHSB_VUPKHSH_VUPKHSW_VUPKLPX_VUPKLSB_VUPKLSH_VUPKLSW_XXBRD_XXBRH_XXBRQ_XXBRW_XXEXTRACTUW_XXINSERTW_VADDCUQ_VADDECUQ_VADDEUQM_VMUL10CUQ_VMUL10ECUQ_VMUL10EUQ_VMUL10UQ_VSUBCUQ_VSUBECUQ_VSUBEUQM_XSTSTDCQP_XSXSIGQP_BCDCFN_rec_BCDCFZ_rec_BCDCPSGN_rec_BCDCTN_rec_BCDCTZ_rec_BCDSETSGN_rec_BCDS_rec_BCDTRUNC_rec_BCDUS_rec_BCDUTRUNC_rec
  { 1, 374, 377, 2861, 2864 }, // 163 VEXTRACTUB_VEXTRACTUH_VEXTRACTUW_VINSERTB_VINSERTD_VINSERTH_VINSERTW_MFVSRLD_MTVSRWS_VCLZLSBB_VCTZLSBB_VEXTRACTD_VEXTUBLX_VEXTUBRX_VEXTUHLX_VEXTUHRX_VEXTUWLX_VEXTUWRX_VPRTYBQ_VADDUQM_VSUBUQM
  { 1, 370, 374, 2864, 2868 }, // 164 XSCMPEXPQP_XSCMPOQP_XSCMPUQP
  { 0, 0, 0, 0, 0 }, // 165 BCDSR_rec_XSADDQP_XSADDQPO_XSCVDPQP_XSCVQPDP_XSCVQPDPO_XSCVQPSDZ_XSCVQPSWZ_XSCVQPUDZ_XSCVQPUWZ_XSCVSDQP_XSCVUDQP_XSRQPI_XSRQPIX_XSRQPXP_XSSUBQP_XSSUBQPO
  { 0, 0, 0, 0, 0 }, // 166 BCDCTSQ_rec
  { 0, 0, 0, 0, 0 }, // 167 XSMADDQP_XSMADDQPO_XSMSUBQP_XSMSUBQPO_XSMULQP_XSMULQPO_XSNMADDQP_XSNMADDQPO_XSNMSUBQP_XSNMSUBQPO
  { 0, 0, 0, 0, 0 }, // 168 BCDCFSQ_rec
  { 0, 0, 0, 0, 0 }, // 169 XSDIVQP_XSDIVQPO
  { 0, 0, 0, 0, 0 }, // 170 XSSQRTQP_XSSQRTQPO
  { 1, 359, 362, 2868, 2871 }, // 171 LXVL_LXVLL
  { 1, 359, 362, 2871, 2874 }, // 172 LVEBX_LVEHX_LVEWX_LVX_LVXL
  { 0, 0, 0, 0, 0 }, // 173 LXSIBZX_LXSIHZX_LXSDX_LXVB16X_LXVD2X_LXVWSX_LXSIWZX_LXV_LXVX_LXSD
  { 0, 0, 0, 0, 0 }, // 174 DFLOADf64_XFLOADf64_LIWZX
  { 0, 0, 0, 0, 0 }, // 175 DCBF_DCBFEP_DCBST_DCBSTEP_DCBT_DCBTEP_DCBZ_DCBZEP_DCBZL_DCBZLEP_DCBTST_DCBTSTEP
  { 0, 0, 0, 0, 0 }, // 176 CP_COPY_CP_COPY8
  { 0, 0, 0, 0, 0 }, // 177 CP_PASTE_CP_PASTE8
  { 0, 0, 0, 0, 0 }, // 178 ICBI_ICBIEP
  { 1, 359, 362, 2874, 2877 }, // 179 ICBT_ICBTLS_LBZ_LBZ8_LBZCIX_LBZX_LBZX8_LBZXTLS_LBZXTLS__LBZXTLS_32_LDBRX_LDCIX_LHBRX_LHBRX8_LHZ_LHZ8_LHZCIX_LHZX_LHZX8_LHZXTLS_LHZXTLS__LHZXTLS_32_LWBRX_LWBRX8_LWZ_LWZ8_LWZCIX_LWZX_LWZX8_LWZXTLS_LWZXTLS__LWZXTLS_32_EnforceIEIO_LSWI
  { 0, 0, 0, 0, 0 }, // 180 LBARX_LBARXL_LHARX_LHARXL_LWARX_LWARXL
  { 0, 0, 0, 0, 0 }, // 181 LD_LDX_LDXTLS_LDXTLS__DARN
  { 0, 0, 0, 0, 0 }, // 182 LDARX_LDARXL
  { 0, 0, 0, 0, 0 }, // 183 CP_ABORT
  { 0, 0, 0, 0, 0 }, // 184 ISYNC
  { 0, 0, 0, 0, 0 }, // 185 MSGSYNC
  { 0, 0, 0, 0, 0 }, // 186 TLBSYNC
  { 0, 0, 0, 0, 0 }, // 187 SYNC
  { 0, 0, 0, 0, 0 }, // 188 LMW
  { 0, 0, 0, 0, 0 }, // 189 LFIWZX_LFDX_LFD
  { 0, 0, 0, 0, 0 }, // 190 SLBIA
  { 0, 0, 0, 0, 0 }, // 191 SLBIE
  { 0, 0, 0, 0, 0 }, // 192 SLBMFEE
  { 0, 0, 0, 0, 0 }, // 193 SLBMFEV
  { 0, 0, 0, 0, 0 }, // 194 SLBMTE
  { 0, 0, 0, 0, 0 }, // 195 TLBIEL
  { 2, 385, 389, 2877, 2880 }, // 196 LHZU_LHZU8_LWZU_LWZU8
  { 2, 385, 389, 2880, 2883 }, // 197 LHZUX_LHZUX8_LWZUX_LWZUX8
  { 0, 0, 0, 0, 0 }, // 198 TEND
  { 0, 0, 0, 0, 0 }, // 199 STBCX_STHCX_STWCX
  { 0, 0, 0, 0, 0 }, // 200 STDCX
  { 0, 0, 0, 0, 0 }, // 201 LDMX
  { 0, 0, 0, 0, 0 }, // 202 LHA_LHA8_LHAX_LHAX8_LWAX_LWAX_32
  { 0, 0, 0, 0, 0 }, // 203 CP_PASTE8_rec_CP_PASTE_rec
  { 0, 0, 0, 0, 0 }, // 204 LWA_LWA_32
  { 0, 0, 0, 0, 0 }, // 205 TCHECK
  { 0, 0, 0, 0, 0 }, // 206 LFIWAX
  { 0, 0, 0, 0, 0 }, // 207 LXSIWAX
  { 0, 0, 0, 0, 0 }, // 208 LIWAX
  { 0, 0, 0, 0, 0 }, // 209 LFSX_LFS
  { 0, 0, 0, 0, 0 }, // 210 LXSSP_LXSSPX
  { 0, 0, 0, 0, 0 }, // 211 XFLOADf32_DFLOADf32
  { 0, 0, 0, 0, 0 }, // 212 LHAU_LHAU8
  { 0, 0, 0, 0, 0 }, // 213 LHAUX_LHAUX8_LWAUX
  { 0, 0, 0, 0, 0 }, // 214 LXVH8X_LXVDSX_LXVW4X
  { 0, 0, 0, 0, 0 }, // 215 STFD_STFDX_STFIWX_STFS_STFSX_STXSD_STXSDX_STXSIBX_STXSIBXv_STXSIHX_STXSIHXv_STXSIWX_STXSSP_STXSSPX
  { 1, 359, 362, 2883, 2886 }, // 216 STW_STW8_STDBRX_STHBRX_STWBRX_STB_STB8_STH_STH8_STBX_STBX8_STBXTLS_STBXTLS__STBXTLS_32_STHX_STHX8_STHXTLS_STHXTLS__STHXTLS_32_STWX_STWX8_STWXTLS_STWXTLS__STWXTLS_32
  { 0, 0, 0, 0, 0 }, // 217 DFSTOREf32_DFSTOREf64_XFSTOREf32_XFSTOREf64_STIWX
  { 0, 0, 0, 0, 0 }, // 218 STD_STDX_STDXTLS_STDXTLS_
  { 1, 359, 362, 2886, 2889 }, // 219 STBCIX_STDCIX_STHCIX_STWCIX_STSWI
  { 0, 0, 0, 0, 0 }, // 220 SLBIEG
  { 0, 0, 0, 0, 0 }, // 221 STMW
  { 0, 0, 0, 0, 0 }, // 222 TLBIE
  { 1, 359, 362, 2889, 2892 }, // 223 STVEBX_STVEHX_STVEWX_STVX_STVXL
  { 0, 0, 0, 0, 0 }, // 224 STXV_STXVB16X_STXVD2X_STXVH8X_STXVW4X_STXVX
  { 1, 359, 362, 2892, 2895 }, // 225 STXVL_STXVLL
  { 0, 0, 0, 0, 0 }, // 226 MTCTR_MTCTR8_MTCTR8loop_MTCTRloop_MTLR_MTLR8
  { 1, 353, 356, 2895, 2898 }, // 227 MFVRSAVE_MFVRSAVEv_MTVRSAVE_MTVRSAVEv
  { 0, 0, 0, 0, 0 }, // 228 MFPMR
  { 0, 0, 0, 0, 0 }, // 229 MTPMR
  { 0, 0, 0, 0, 0 }, // 230 MFTB_MFTB8
  { 0, 0, 0, 0, 0 }, // 231 MFCTR_MFCTR8_MFLR_MFLR8_MFSPR_MFSPR8
  { 0, 0, 0, 0, 0 }, // 232 MFMSR
  { 0, 0, 0, 0, 0 }, // 233 MTMSR
  { 0, 0, 0, 0, 0 }, // 234 MTMSRD
  { 0, 0, 0, 0, 0 }, // 235 MTSPR_MTSPR8
  { 1, 362, 366, 2898, 2901 }, // 236 DIVW_DIVWO_DIVWU_DIVWUO_MODSW
  { 1, 362, 366, 2901, 2904 }, // 237 DIVWE_DIVWEO_DIVWEU_DIVWEUO_MODSD_MODUD_MODUW
  { 0, 0, 0, 0, 0 }, // 238 DIVD_DIVDO_DIVDU_DIVDUO
  { 0, 0, 0, 0, 0 }, // 239 DIVDE_DIVDEO_DIVDEU_DIVDEUO
  { 1, 362, 366, 2904, 2907 }, // 240 DIVWO_rec_DIVWUO_rec_DIVWU_rec_DIVW_rec
  { 0, 0, 0, 0, 0 }, // 241 DIVD_rec_DIVDO_rec_DIVDU_rec_DIVDUO_rec
  { 1, 362, 366, 2907, 2910 }, // 242 DIVWE_rec_DIVWEO_rec_DIVWEU_rec_DIVWEUO_rec
  { 0, 0, 0, 0, 0 }, // 243 DIVDE_rec_DIVDEO_rec_DIVDEU_rec_DIVDEUO_rec
  { 1, 353, 356, 2910, 2914 }, // 244 MTCRF_MTCRF8
  { 1, 353, 356, 2914, 2917 }, // 245 ADDC8O_rec_ADDC8_rec_ADDCO_rec_ADDC_rec_SUBFC8O_rec_SUBFC8_rec_SUBFCO_rec_SUBFC_rec
  { 1, 370, 374, 2917, 2921 }, // 246 FABSD_rec_FABSS_rec_FNABSD_rec_FNABSS_rec_FCPSGND_rec_FCPSGNS_rec_FNEGD_rec_FNEGS_rec_FMR_rec
  { 1, 356, 359, 2921, 2924 }, // 247 MCRFS
  { 0, 0, 0, 0, 0 }, // 248 MTFSF_MTFSF_rec_MTFSFI_MTFSFI_rec
  { 0, 0, 0, 0, 0 }, // 249 MTFSFb
  { 0, 0, 0, 0, 0 }, // 250 RLDCL_rec_RLDCR_rec
  { 0, 0, 0, 0, 0 }, // 251 RLDICL_rec_RLDICR_rec_RLDICL_32_rec_RLDIMI_rec
  { 1, 353, 356, 2924, 2927 }, // 252 RLWIMI8_rec_RLWIMI_rec
  { 1, 353, 356, 2927, 2930 }, // 253 RLWINM8_rec_RLWINM_rec_RLWNM8_rec_RLWNM_rec_SLW8_rec_SLW_rec_SRW8_rec_SRW_rec
  { 1, 353, 356, 2930, 2933 }, // 254 SRAWI_rec_SRAW_rec
  { 0, 0, 0, 0, 0 }, // 255 MFFS_MFFSCE_MFFSL_MFFS_rec
  { 0, 0, 0, 0, 0 }, // 256 MFCR_MFCR8
  { 0, 0, 0, 0, 0 }, // 257 EXTSWSLI_32_64_rec_SRADI_rec_EXTSWSLI_rec_RLDIC_rec
  { 0, 0, 0, 0, 0 }, // 258 SRAD_rec_SLD_rec_SRD_rec
  { 0, 0, 0, 0, 0 }, // 259 FDIV
  { 0, 0, 0, 0, 0 }, // 260 FDIV_rec
  { 0, 0, 0, 0, 0 }, // 261 XSSQRTDP
  { 0, 0, 0, 0, 0 }, // 262 FSQRT
  { 0, 0, 0, 0, 0 }, // 263 XVSQRTDP
  { 0, 0, 0, 0, 0 }, // 264 XVSQRTSP
  { 0, 0, 0, 0, 0 }, // 265 FSQRT_rec
  { 0, 0, 0, 0, 0 }, // 266 XSSQRTSP
  { 0, 0, 0, 0, 0 }, // 267 FSQRTS
  { 0, 0, 0, 0, 0 }, // 268 FSQRTS_rec
  { 0, 0, 0, 0, 0 }, // 269 XSDIVDP
  { 1, 381, 385, 2933, 2937 }, // 270 FDIVS
  { 1, 381, 385, 2937, 2941 }, // 271 FDIVS_rec
  { 1, 381, 385, 2941, 2945 }, // 272 XSDIVSP
  { 1, 381, 385, 2945, 2949 }, // 273 XVDIVSP
  { 0, 0, 0, 0, 0 }, // 274 XVDIVDP
  { 0, 0, 0, 0, 0 }, // 275 LFSU
  { 0, 0, 0, 0, 0 }, // 276 LFSUX
  { 0, 0, 0, 0, 0 }, // 277 STFDU_STFDUX_STFSU_STFSUX
  { 2, 385, 389, 2949, 2952 }, // 278 STBU_STBU8_STDU_STHU_STHU8_STWU_STWU8
  { 2, 385, 389, 2952, 2955 }, // 279 STBUX_STBUX8_STDUX_STHUX_STHUX8_STWUX_STWUX8
  { 2, 385, 389, 2955, 2958 }, // 280 LBZU_LBZU8
  { 2, 385, 389, 2958, 2961 }, // 281 LBZUX_LBZUX8
  { 0, 0, 0, 0, 0 }, // 282 LDU
  { 0, 0, 0, 0, 0 }, // 283 LDUX
  { 0, 0, 0, 0, 0 }, // 284 LFDU
  { 0, 0, 0, 0, 0 }, // 285 LFDUX
  { 0, 0, 0, 0, 0 }, // 286 VPMSUMB_VPMSUMD_VPMSUMH_VPMSUMW_VCIPHER_VCIPHERLAST_VNCIPHER_VNCIPHERLAST_VSBOX
  { 1, 356, 359, 2961, 2964 }, // 287 BCCCTR_BCCCTR8_BCCCTRL_BCCCTRL8_BCCL_BCCLA_BCCLR_BCCLRL_BCCTR_BCCTR8_BCCTR8n_BCCTRL_BCCTRL8_BCCTRL8n_BCCTRLn_BCCTRn_BDNZ_BDNZ8_BDNZA_BDNZAm_BDNZAp_BDNZm_BDNZp_BDZ_BDZ8_BDZA_BDZAm_BDZAp_BDZm_BDZp_BDNZL_BDNZLA_BDNZLAm_BDNZLAp_BDNZLR_BDNZLR8_BDNZLRL_BDNZLRLm_BDNZLRLp_BDNZLRm_BDNZLRp_BDNZLm_BDNZLp_BDZL_BDZLA_BDZLAm_BDZLAp_BDZLR_BDZLR8_BDZLRL_BDZLRLm_BDZLRLp_BDZLRm_BDZLRp_BDZLm_BDZLp_BL_BL_NOP_BL_TLS_BL8_BL8_NOP_BL8_NOP_TLS_BL8_TLS_BL8_TLS__BLA_BLA8_BLA8_NOP_BLR_BLR8_BLRL_TAILB_TAILB8_TAILBA_TAILBA8_TAILBCTR_TAILBCTR8_gBC_gBCA_gBCAat_gBCCTR_gBCCTRL_gBCL_gBCLA_gBCLAat_gBCLR_gBCLRL_gBCLat_gBCat_BCLR_BCLRL_BCLRLn_BCLRn_BCTR_BCTR8_BCTRL_BCTRL8_B_BA_BC_BCC_BCCA_BCL_BCLalways_BCLn_BCTRL8_LDinto_toc_BCTRL_LWZinto_toc_BCn_CTRL_DEP
  { 1, 356, 359, 2964, 2967 }, // 288 ADDPCIS
  { 1, 359, 362, 2967, 2970 }, // 289 LDAT_LWAT
  { 1, 359, 362, 2970, 2973 }, // 290 STDAT_STWAT
  { 1, 353, 356, 2973, 2976 }, // 291 BRINC
  { 1, 374, 377, 2976, 2979 }, // 292 EVABS_EVEQV_EVNAND_EVNEG_EVADDIW_EVADDW_EVAND_EVANDC_EVCMPEQ_EVCMPGTS_EVCMPGTU_EVCMPLTS_EVCMPLTU_EVCNTLSW_EVCNTLZW_EVEXTSB_EVEXTSH_EVMERGEHI_EVMERGEHILO_EVMERGELO_EVMERGELOHI_EVNOR_EVOR_EVORC_EVXOR_EVRLW_EVRLWI_EVRNDW_EVSLW_EVSLWI_EVSPLATFI_EVSPLATI_EVSRWIS_EVSRWIU_EVSRWS_EVSRWU_EVSUBFW_EVSUBIFW
  { 1, 377, 381, 2979, 2982 }, // 293 EVMRA_EVADDSMIAAW_EVADDSSIAAW_EVADDUMIAAW_EVADDUSIAAW_EVDIVWS_EVDIVWU_EVMHEGSMFAA_EVMHEGSMFAN_EVMHEGSMIAA_EVMHEGSMIAN_EVMHEGUMIAA_EVMHEGUMIAN_EVMHESMF_EVMHESMFA_EVMHESMFAAW_EVMHESMFANW_EVMHESMI_EVMHESMIA_EVMHESMIAAW_EVMHESMIANW_EVMHESSF_EVMHESSFA_EVMHESSFAAW_EVMHESSFANW_EVMHESSIAAW_EVMHESSIANW_EVMHEUMI_EVMHEUMIA_EVMHEUMIAAW_EVMHEUMIANW_EVMHEUSIAAW_EVMHEUSIANW_EVMHOGSMFAA_EVMHOGSMFAN_EVMHOGSMIAA_EVMHOGSMIAN_EVMHOGUMIAA_EVMHOGUMIAN_EVMHOSMF_EVMHOSMFA_EVMHOSMFAAW_EVMHOSMFANW_EVMHOSMI_EVMHOSMIA_EVMHOSMIAAW_EVMHOSMIANW_EVMHOSSF_EVMHOSSFA_EVMHOSSFAAW_EVMHOSSFANW_EVMHOSSIAAW_EVMHOSSIANW_EVMHOUMI_EVMHOUMIA_EVMHOUMIAAW_EVMHOUMIANW_EVMHOUSIAAW_EVMHOUSIANW_EVMWHSMF_EVMWHSMFA_EVMWHSMI_EVMWHSMIA_EVMWHSSF_EVMWHSSFA_EVMWHUMI_EVMWHUMIA_EVMWLSMIAAW_EVMWLSMIANW_EVMWLSSIAAW_EVMWLSSIANW_EVMWLUMI_EVMWLUMIA_EVMWLUMIAAW_EVMWLUMIANW_EVMWLUSIAAW_EVMWLUSIANW_EVMWSMF_EVMWSMFA_EVMWSMFAA_EVMWSMFAN_EVMWSMI_EVMWSMIA_EVMWSMIAA_EVMWSMIAN_EVMWSSF_EVMWSSFA_EVMWSSFAA_EVMWSSFAN_EVMWUMI_EVMWUMIA_EVMWUMIAA_EVMWUMIAN_EVSUBFSMIAAW_EVSUBFSSIAAW_EVSUBFUMIAAW_EVSUBFUSIAAW
  { 1, 359, 362, 2982, 2985 }, // 294 EVLDD_EVLDDX_EVLDH_EVLDHX_EVLDW_EVLDWX_EVLHHESPLAT_EVLHHESPLATX_EVLHHOSSPLAT_EVLHHOSSPLATX_EVLHHOUSPLAT_EVLHHOUSPLATX_EVLWHE_EVLWHEX_EVLWHOS_EVLWHOSX_EVLWHOU_EVLWHOUX_EVLWHSPLAT_EVLWHSPLATX_EVLWWSPLAT_EVLWWSPLATX
  { 1, 359, 362, 2985, 2988 }, // 295 EVSTDD_EVSTDDX_EVSTDH_EVSTDHX_EVSTDW_EVSTDWX_EVSTWHE_EVSTWHEX_EVSTWHO_EVSTWHOX_EVSTWWE_EVSTWWEX_EVSTWWO_EVSTWWOX
  { 1, 356, 359, 2988, 2991 }, // 296 HRFID_ATTN_CLRBHRB_MFBHRBE_NAP_RFCI_RFDI_RFMCI_SC
  { 0, 0, 0, 0, 0 }, // 297 RFI
  { 0, 0, 0, 0, 0 }, // 298 RFID
  { 1, 359, 362, 2991, 2994 }, // 299 DSS_DSSALL_DST_DST64_DSTST_DSTST64_DSTSTT_DSTSTT64_DSTT_DSTT64_ICBLQ_LBEPX_LHEPX_LWEPX_TLBIVAX_TLBLD_TLBLI_TLBRE_TLBRE2_TLBSX_TLBSX2_TLBSX2D_TLBWE_TLBWE2_MBAR_TRAP_DCCCI_ICCCI
  { 1, 359, 362, 2994, 2997 }, // 300 ICBLC_STBEPX_STHEPX_STWEPX
  { 0, 0, 0, 0, 0 }, // 301 LFDEPX
  { 0, 0, 0, 0, 0 }, // 302 STFDEPX
  { 0, 0, 0, 0, 0 }, // 303 MFSR_MFSRIN
  { 0, 0, 0, 0, 0 }, // 304 MTSR_MTSRIN
  { 0, 0, 0, 0, 0 }, // 305 MFDCR
  { 0, 0, 0, 0, 0 }, // 306 MTDCR
  { 1, 353, 356, 2997, 3000 }, // 307 NOP_GT_PWR6_NOP_GT_PWR7
  { 0, 0, 0, 0, 0 }, // 308 TLBIA
  { 0, 0, 0, 0, 0 }, // 309 WRTEE_WRTEEI
  { 0, 0, 0, 0, 0 }, // 310 MSYNC
  { 0, 0, 0, 0, 0 }, // 311 SLBSYNC
  { 0, 0, 0, 0, 0 }, // 312 SLBFEE_rec
  { 0, 0, 0, 0, 0 }, // 313 STOP
  { 0, 0, 0, 0, 0 }, // 314 DCBA_DCBI
  { 0, uint16_t(~0U), uint16_t(~0U), uint16_t(~0U), uint16_t(~0U) }// end marker
};

static const llvm::InstrItinerary PPCE500Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 396, 398, 0, 0 }, // 1 IIC_LdStSync
  { 1, 398, 400, 3000, 3003 }, // 2 IIC_IntSimple
  { 1, 398, 400, 3003, 3006 }, // 3 IIC_IntGeneral
  { 1, 400, 402, 3006, 3008 }, // 4 IIC_BrB
  { 0, 0, 0, 0, 0 }, // 5 IIC_VecFP
  { 1, 398, 400, 3008, 3011 }, // 6 IIC_IntCompare
  { 0, 0, 0, 0, 0 }, // 7 IIC_SprABORT
  { 0, 0, 0, 0, 0 }, // 8 IIC_LdStCOPY
  { 0, 0, 0, 0, 0 }, // 9 IIC_LdStPASTE
  { 1, 400, 402, 3011, 3014 }, // 10 IIC_BrCR
  { 0, 0, 0, 0, 0 }, // 11 IIC_LdStLD
  { 1, 396, 398, 3014, 3016 }, // 12 IIC_LdStDCBF
  { 1, 396, 398, 3016, 3018 }, // 13 IIC_LdStLoad
  { 0, 0, 0, 0, 0 }, // 14 IIC_IntDivD
  { 1, 402, 405, 3018, 3021 }, // 15 IIC_IntDivW
  { 1, 405, 407, 3021, 3024 }, // 16 IIC_FPDGeneral
  { 0, 0, 0, 0, 0 }, // 17 IIC_FPAddSub
  { 1, 407, 409, 3024, 3027 }, // 18 IIC_FPDivD
  { 1, 409, 411, 3027, 3030 }, // 19 IIC_FPSGeneral
  { 0, 0, 0, 0, 0 }, // 20 IIC_FPCompare
  { 0, 0, 0, 0, 0 }, // 21 IIC_FPGeneral
  { 1, 411, 413, 3030, 3033 }, // 22 IIC_VecGeneral
  { 1, 409, 411, 3033, 3036 }, // 23 IIC_VecComplex
  { 1, 396, 398, 3036, 3038 }, // 24 IIC_LdStStore
  { 0, 0, 0, 0, 0 }, // 25 IIC_IntRotateDI
  { 1, 413, 415, 3038, 3041 }, // 26 IIC_FPDivS
  { 0, 0, 0, 0, 0 }, // 27 IIC_FPFused
  { 0, 0, 0, 0, 0 }, // 28 IIC_FPSqrtD
  { 0, 0, 0, 0, 0 }, // 29 IIC_FPSqrtS
  { 1, 396, 398, 3041, 3043 }, // 30 IIC_LdStICBI
  { 1, 398, 400, 3043, 3047 }, // 31 IIC_IntISEL
  { 0, 0, 0, 0, 0 }, // 32 IIC_SprISYNC
  { 1, 415, 417, 3047, 3050 }, // 33 IIC_LdStLWARX
  { 2, 417, 420, 3050, 3052 }, // 34 IIC_LdStLoadUpd
  { 2, 417, 420, 3052, 3054 }, // 35 IIC_LdStLoadUpdX
  { 0, 0, 0, 0, 0 }, // 36 IIC_LdStLDARX
  { 0, 0, 0, 0, 0 }, // 37 IIC_LdStLDU
  { 0, 0, 0, 0, 0 }, // 38 IIC_LdStLDUX
  { 0, 0, 0, 0, 0 }, // 39 IIC_LdStLFD
  { 0, 0, 0, 0, 0 }, // 40 IIC_LdStLFDU
  { 0, 0, 0, 0, 0 }, // 41 IIC_LdStLFDUX
  { 1, 396, 398, 3054, 3056 }, // 42 IIC_LdStLHA
  { 1, 417, 420, 3056, 3058 }, // 43 IIC_LdStLHAU
  { 1, 417, 420, 3058, 3060 }, // 44 IIC_LdStLHAUX
  { 1, 396, 398, 3060, 3062 }, // 45 IIC_LdStLMW
  { 0, 0, 0, 0, 0 }, // 46 IIC_LdStLWA
  { 0, 0, 0, 0, 0 }, // 47 IIC_IntMulHD
  { 1, 400, 402, 3062, 3064 }, // 48 IIC_BrMCR
  { 1, 398, 400, 3064, 3067 }, // 49 IIC_BrMCRX
  { 1, 420, 422, 3067, 3069 }, // 50 IIC_SprMFCR
  { 1, 398, 400, 3069, 3071 }, // 51 IIC_SprMFSPR
  { 0, 0, 0, 0, 0 }, // 52 IIC_IntMFFS
  { 1, 422, 424, 3071, 3073 }, // 53 IIC_SprMFMSR
  { 1, 420, 422, 3073, 3075 }, // 54 IIC_SprMFCRF
  { 1, 422, 424, 3075, 3077 }, // 55 IIC_SprMFPMR
  { 1, 422, 424, 3077, 3079 }, // 56 IIC_SprMFSR
  { 1, 422, 424, 3079, 3081 }, // 57 IIC_SprMFTB
  { 0, 0, 0, 0, 0 }, // 58 IIC_SprMSGSYNC
  { 1, 398, 400, 3081, 3083 }, // 59 IIC_SprMTSPR
  { 0, 0, 0, 0, 0 }, // 60 IIC_IntMTFSB0
  { 1, 424, 426, 3083, 3085 }, // 61 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 62 IIC_SprMTMSRD
  { 1, 411, 413, 3085, 3087 }, // 63 IIC_SprMTPMR
  { 1, 411, 413, 3087, 3089 }, // 64 IIC_SprMTSR
  { 1, 409, 411, 3089, 3092 }, // 65 IIC_IntMulHW
  { 1, 409, 411, 3092, 3095 }, // 66 IIC_IntMulHWU
  { 1, 409, 411, 3095, 3098 }, // 67 IIC_IntMulLI
  { 0, 0, 0, 0, 0 }, // 68 IIC_VecPerm
  { 0, 0, 0, 0, 0 }, // 69 IIC_LdStSTFD
  { 0, 0, 0, 0, 0 }, // 70 IIC_LdStSTFDU
  { 0, 0, 0, 0, 0 }, // 71 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 72 IIC_IntRFID
  { 0, 0, 0, 0, 0 }, // 73 IIC_IntRotateD
  { 1, 398, 400, 3098, 3101 }, // 74 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 75 IIC_SprSLBFEE
  { 0, 0, 0, 0, 0 }, // 76 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 77 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprSLBIEG
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprSLBMFEV
  { 0, 0, 0, 0, 0 }, // 81 IIC_SprSLBMTE
  { 0, 0, 0, 0, 0 }, // 82 IIC_SprSLBSYNC
  { 1, 398, 400, 3101, 3104 }, // 83 IIC_IntShift
  { 1, 396, 398, 3104, 3106 }, // 84 IIC_LdStSTWCX
  { 2, 417, 420, 3106, 3108 }, // 85 IIC_LdStSTU
  { 2, 417, 420, 3108, 3110 }, // 86 IIC_LdStSTUX
  { 0, 0, 0, 0, 0 }, // 87 IIC_LdStSTD
  { 0, 0, 0, 0, 0 }, // 88 IIC_LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 89 IIC_SprSTOP
  { 0, 0, 0, 0, 0 }, // 90 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 91 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 92 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 93 IIC_SprTLBIEL
  { 1, 426, 428, 0, 0 }, // 94 IIC_SprTLBSYNC
  { 1, 428, 430, 3110, 3112 }, // 95 IIC_IntTrapW
  { 0, 0, 0, 0, 0 }, // 96 IIC_VecFPCompare
  { 1, 411, 413, 3112, 3115 }, // 97 VADDUBM_VADDUDM_VADDUHM_VADDUWM_VEXTSB2D_VEXTSB2Ds_VEXTSB2W_VEXTSB2Ws_VEXTSH2D_VEXTSH2Ds_VEXTSH2W_VEXTSH2Ws_VEXTSW2D_VEXTSW2Ds_VSLD_VSRD_VSUBUBM_VSUBUDM_VSUBUHM_VSUBUWM_VPOPCNTB_VPOPCNTH_VSRAD_MTVSRDD_VEQV_VNAND_VNEGD_VNEGW_VORC_XXLAND_XXLANDC_XXLEQV_XXLEQVOnes_XXLNAND_XXLNOR_XXLOR_XXLORf_XXLORC_XXLXOR_XXLXORdpz_XXLXORspz_XXLXORz
  { 0, 0, 0, 0, 0 }, // 98 VAND_VANDC_V_SET0_V_SET0B_V_SET0H_VSLB_VSLH_VSLW_VSRB_VSRH_VSRW_VRLB_VRLD_VRLH_VRLW_VSRAB_VSRAH_VSRAW_XVABSDP_XVABSSP_XVNABSDP_XVNABSSP_XVCPSGNDP_XVCPSGNSP_XVIEXPDP_XVIEXPSP_XVXEXPDP_XVXEXPSP_VRLDMI_VRLDNM_VRLWMI_VRLWNM_VMRGEW_VMRGOW_VNOR_VOR_VSEL_VXOR_XVNEGDP_XVNEGSP_XSABSQP_XSCPSGNQP_XSIEXPQP_XSNABSQP_XSNEGQP_XSXEXPQP
  { 0, 0, 0, 0, 0 }, // 99 XXSEL
  { 1, 398, 400, 3115, 3117 }, // 100 TABORTDC_TABORTDCI_TABORTWC_TABORTWCI
  { 0, 0, 0, 0, 0 }, // 101 MTFSB0_MTFSB1
  { 0, 0, 0, 0, 0 }, // 102 MFFSCDRN_MFFSCDRNI_MFFSCRN_MFFSCRNI
  { 1, 398, 400, 3117, 3120 }, // 103 CMPRB_CMPRB8_CMPEQB
  { 0, 0, 0, 0, 0 }, // 104 TD_TDI
  { 1, 428, 430, 3120, 3122 }, // 105 TW_TWI
  { 0, 0, 0, 0, 0 }, // 106 FCMPUD_FCMPUS_FTDIV_FTSQRT
  { 0, 0, 0, 0, 0 }, // 107 XSTSTDCDP_XSTSTDCSP
  { 0, 0, 0, 0, 0 }, // 108 XSMAXCDP_XSMAXDP_XSMAXJDP_XSMINCDP_XSMINDP_XSMINJDP_XSXSIGDP_XSCVSPDPN
  { 0, 0, 0, 0, 0 }, // 109 XSCMPEQDP_XSCMPEXPDP_XSCMPGEDP_XSCMPGTDP_XSCMPODP_XSCMPUDP_XSTDIVDP_XSTSQRTDP
  { 1, 398, 400, 3122, 3125 }, // 110 CNTLZD_CNTLZD_rec_CNTLZW_CNTLZW8_CNTLZW8_rec_CNTLZW_rec_CNTTZD_CNTTZD_rec_CNTTZW_CNTTZW8_CNTTZW8_rec_CNTTZW_rec_POPCNTD_POPCNTW_CMPB_CMPB8_SETB_SETB8_BPERMD
  { 0, 0, 0, 0, 0 }, // 111 SLD_SRD_SRAD
  { 0, 0, 0, 0, 0 }, // 112 SRADI_EXTSWSLI_32_64_EXTSWSLI_SRADI_32_RLDIC
  { 1, 411, 413, 3125, 3128 }, // 113 MFVRD_MFVSRD_MTVRD_MTVSRD_MTVRWA_MTVRWZ_MTVSRWA_MTVSRWZ_MFVSRWZ_MFVRWZ
  { 1, 398, 400, 3128, 3131 }, // 114 CMPLW_CMPLWI_CMPW_CMPWI_CMPD_CMPDI_CMPLD_CMPLDI
  { 1, 398, 400, 3131, 3134 }, // 115 SUBFC_SUBFC8_SUBFC8O_SUBFCO_SUBFIC_SUBFIC8_ANDI8_rec_ANDIS8_rec_ANDIS_rec_ANDI_rec_ADDC_ADDC8_ADDC8O_ADDCO_ADDIC_ADDIC8_ADDIC_rec_ADDE_ADDE8_ADDE8O_ADDE8O_rec_ADDE8_rec_ADDEO_ADDEO_rec_ADDE_rec_ADDME_ADDME8_ADDME8O_ADDME8O_rec_ADDME8_rec_ADDMEO_ADDMEO_rec_ADDME_rec_ADDZE_ADDZE8_ADDZE8O_ADDZE8O_rec_ADDZE8_rec_ADDZEO_ADDZEO_rec_ADDZE_rec_SUBF_SUBF8_SUBF8O_SUBF8O_rec_SUBF8_rec_SUBFE_SUBFE8_SUBFE8O_SUBFE8O_rec_SUBFE8_rec_SUBFEO_SUBFEO_rec_SUBFE_rec_SUBFME_SUBFME8_SUBFME8O_SUBFME8O_rec_SUBFME8_rec_SUBFMEO_SUBFMEO_rec_SUBFME_rec_SUBFO_SUBFO_rec_SUBFZE_SUBFZE8_SUBFZE8O_SUBFZE8O_rec_SUBFZE8_rec_SUBFZEO_SUBFZEO_rec_SUBFZE_rec_SUBF_rec_POPCNTB_LA
  { 1, 398, 400, 3134, 3137 }, // 116 ADD4_ADD4O_ADD4O_rec_ADD4_rec_ADD8_ADD8O_ADD8O_rec_ADD8_rec_NEG_NEG8_NEG8O_NEG8O_rec_NEG8_rec_NEGO_NEGO_rec_NEG_rec_ADDI_ADDI8_ADDIS_ADDIS8_LI_LI8_LIS_LIS8_OR_OR8_OR8_rec_ORI_ORI8_ORIS_ORIS8_OR_rec_XOR_XOR8_XOR8_rec_XORI_XORI8_XORIS_XORIS8_XOR_rec_NAND_NAND8_NAND8_rec_NAND_rec_AND_AND8_AND8_rec_ANDC_ANDC8_ANDC8_rec_ANDC_rec_AND_rec_NOR_NOR8_NOR8_rec_NOR_rec_ORC_ORC8_ORC8_rec_ORC_rec_EQV_EQV8_EQV8_rec_EQV_rec_EXTSB_EXTSB8_EXTSB8_32_64_EXTSB8_rec_EXTSB_rec_EXTSH_EXTSH8_EXTSH8_32_64_EXTSH8_rec_EXTSH_rec_EXTSW_EXTSW_32_EXTSW_32_64_EXTSW_32_64_rec_EXTSW_rec_ADD4TLS_ADD8TLS_ADD8TLS__NOP
  { 0, 0, 0, 0, 0 }, // 117 ADDIStocHA_ADDIStocHA8_ADDItocL_COPY
  { 1, 400, 402, 3137, 3139 }, // 118 MCRF
  { 1, 398, 400, 3139, 3142 }, // 119 MCRXRX
  { 0, 0, 0, 0, 0 }, // 120 XSNABSDP_XSXEXPDP_XSABSDP_XSNEGDP_XSCPSGNDP
  { 1, 400, 402, 3142, 3144 }, // 121 RFEBB
  { 1, 398, 400, 3144, 3146 }, // 122 TBEGIN_TRECHKPT
  { 1, 396, 398, 3146, 3148 }, // 123 WAIT
  { 0, 0, 0, 0, 0 }, // 124 RLDCL_RLDCR
  { 1, 398, 400, 3148, 3151 }, // 125 RLWIMI_RLWIMI8
  { 0, 0, 0, 0, 0 }, // 126 RLDICL_RLDICL_32_RLDICL_32_64_RLDICR_RLDICR_32_RLDIMI
  { 1, 420, 422, 3151, 3153 }, // 127 MFOCRF_MFOCRF8
  { 1, 398, 400, 3153, 3156 }, // 128 MTOCRF_MTOCRF8
  { 1, 400, 402, 3156, 3159 }, // 129 CR6SET_CR6UNSET_CRSET_CRUNSET_CRAND_CRANDC_CRNAND_CRNOR_CROR_CRORC_CREQV_CRXOR
  { 1, 398, 400, 3159, 3162 }, // 130 SLW_SLW8_SRW_SRW8_RLWINM_RLWINM8_RLWNM_RLWNM8
  { 0, 0, 0, 0, 0 }, // 131 FABSD_FABSS_FNABSD_FNABSS_FNEGD_FNEGS_FCPSGND_FCPSGNS_FMR
  { 1, 398, 400, 3162, 3165 }, // 132 SRAW_SRAWI
  { 1, 398, 400, 3165, 3169 }, // 133 ISEL_ISEL8
  { 0, 0, 0, 0, 0 }, // 134 XSIEXPDP
  { 1, 398, 400, 3169, 3171 }, // 135 TRECLAIM_TSR_TABORT
  { 1, 396, 398, 3171, 3173 }, // 136 MFVSCR
  { 1, 396, 398, 3173, 3175 }, // 137 MTVSCR
  { 0, 0, 0, 0, 0 }, // 138 VCMPNEZB_VCMPNEZH_VCMPNEZW_VCMPEQUB_VCMPEQUD_VCMPEQUH_VCMPEQUW_VCMPNEB_VCMPNEH_VCMPNEW_VCMPEQFP_VCMPEQFP_rec_VCMPGEFP_VCMPGEFP_rec_VCMPGTFP_VCMPGTFP_rec_VCMPBFP_VCMPBFP_rec_VCMPGTSB_VCMPGTSB_rec_VCMPGTSD_VCMPGTSD_rec_VCMPGTSH_VCMPGTSH_rec_VCMPGTSW_VCMPGTSW_rec_VCMPGTUB_VCMPGTUB_rec_VCMPGTUD_VCMPGTUD_rec_VCMPGTUH_VCMPGTUH_rec_VCMPGTUW_VCMPGTUW_rec_VCMPNEB_rec_VCMPNEH_rec_VCMPNEW_rec_VCMPNEZB_rec_VCMPNEZH_rec_VCMPNEZW_rec_VCMPEQUB_rec_VCMPEQUD_rec_VCMPEQUH_rec_VCMPEQUW_rec_XVCMPEQDP_XVCMPEQDP_rec_XVCMPEQSP_XVCMPEQSP_rec_XVCMPGEDP_XVCMPGEDP_rec_XVCMPGESP_XVCMPGESP_rec_XVCMPGTDP_XVCMPGTDP_rec_XVCMPGTSP_XVCMPGTSP_rec
  { 1, 411, 413, 3175, 3178 }, // 139 VABSDUB_VABSDUH_VABSDUW_VCLZB_VCLZD_VCLZH_VCLZW_VCTZB_VCTZD_VCTZH_VCTZW_VPOPCNTW_VPOPCNTD_VPRTYBD_VPRTYBW
  { 0, 0, 0, 0, 0 }, // 140 VADDUBS_VADDUHS_VADDUWS_VAVGSB_VAVGSH_VAVGSW_VAVGUB_VAVGUH_VAVGUW_VADDSBS_VADDSHS_VADDSWS_VMAXFP_VMINFP_VMAXSB_VMAXSD_VMAXSH_VMAXSW_VMAXUB_VMAXUD_VMAXUH_VMAXUW_VMINSB_VMINSD_VMINSH_VMINSW_VMINUB_VMINUD_VMINUH_VMINUW_VBPERMD_VADDCUW_VSHASIGMAD_VSHASIGMAW_VSUBSBS_VSUBSHS_VSUBSWS_VSUBUBS_VSUBUHS_VSUBUWS_VSUBCUW_XVMAXDP_XVMAXSP_XVMINDP_XVMINSP_XVTSTDCDP_XVTSTDCSP_XVXSIGDP_XVXSIGSP
  { 0, 0, 0, 0, 0 }, // 141 XVTDIVDP_XVTDIVSP_XVTSQRTDP_XVTSQRTSP
  { 0, 0, 0, 0, 0 }, // 142 VADDFP_VCTSXS_VCTSXS_0_VCTUXS_VCTUXS_0_VEXPTEFP_VLOGEFP_VMADDFP_VMHADDSHS_VNMSUBFP_VREFP_VRFIM_VRFIN_VRFIP_VRFIZ_VRSQRTEFP_XVADDDP_XVADDSP_XVCVDPSP_XVCVDPSXDS_XVCVDPSXWS_XVCVDPUXDS_XVCVDPUXWS_XVCVHPSP_XVCVSPDP_XVCVSPHP_XVCVSPSXDS_XVCVSPSXWS_XVCVSPUXDS_XVCVSPUXWS_XVCVSXDDP_XVCVSXDSP_XVCVSXWDP_XVCVSXWSP_XVCVUXDDP_XVCVUXDSP_XVCVUXWDP_XVCVUXWSP_XVMADDADP_XVMADDASP_XVMADDMDP_XVMADDMSP_XVMSUBADP_XVMSUBASP_XVMSUBMDP_XVMSUBMSP_XVMULDP_XVMULSP_XVNMADDADP_XVNMADDASP_XVNMADDMDP_XVNMADDMSP_XVNMSUBADP_XVNMSUBASP_XVNMSUBMDP_XVNMSUBMSP_XVRDPI_XVRDPIC_XVRDPIM_XVRDPIP_XVRDPIZ_XVREDP_XVRESP_XVRSPI_XVRSPIC_XVRSPIM_XVRSPIP_XVRSPIZ_XVRSQRTEDP_XVRSQRTESP_XVSUBDP_XVSUBSP_VCFSX_VCFSX_0_VCFUX_VCFUX_0_VMHRADDSHS_VMLADDUHM_VMSUMMBM_VMSUMSHM_VMSUMSHS_VMSUMUBM_VMSUMUHM_VMSUMUDM_VMSUMUHS_VMULESB_VMULESH_VMULESW_VMULEUB_VMULEUH_VMULEUW_VMULOSB_VMULOSH_VMULOSW_VMULOUB_VMULOUH_VMULOUW_VSUM2SWS_VSUM4SBS_VSUM4SHS_VSUM4UBS_VSUMSWS
  { 1, 411, 413, 3178, 3181 }, // 143 VSUBFP_VMULUWM
  { 0, 0, 0, 0, 0 }, // 144 MADDHD_MADDHDU_MADDLD_MADDLD8_MULLD_MULLDO
  { 1, 409, 411, 3181, 3184 }, // 145 MULHD_MULHW_MULLW_MULLWO
  { 1, 409, 411, 3184, 3187 }, // 146 MULHDU_MULHWU
  { 1, 409, 411, 3187, 3190 }, // 147 MULLI_MULLI8
  { 0, 0, 0, 0, 0 }, // 148 FRSP_FRIMD_FRIMS_FRIND_FRINS_FRIPD_FRIPS_FRIZD_FRIZS_FRE_FRES_FADDS_FMSUBS_FMADDS_FSUBS_FCFID_FCFIDS_FCFIDU_FCFIDUS_FCTID_FCTIDU_FCTIDUZ_FCTIDZ_FCTIW_FCTIWU_FCTIWUZ_FCTIWZ_FRSQRTE_FRSQRTES_FNMADDS_FNMSUBS_FSELD_FSELS_FMULS
  { 0, 0, 0, 0, 0 }, // 149 FADD_FSUB
  { 0, 0, 0, 0, 0 }, // 150 FMSUB_FMADD_FNMADD_FNMSUB_FMUL
  { 0, 0, 0, 0, 0 }, // 151 XSMADDADP_XSMADDASP_XSMADDMDP_XSMADDMSP_XSMSUBADP_XSMSUBASP_XSMSUBMDP_XSMSUBMSP_XSMULDP_XSMULSP_XSNMADDADP_XSNMADDASP_XSNMADDMDP_XSNMADDMSP_XSNMSUBADP_XSNMSUBASP_XSNMSUBMDP_XSNMSUBMSP
  { 0, 0, 0, 0, 0 }, // 152 FSELD_rec_FSELS_rec
  { 1, 409, 411, 3190, 3193 }, // 153 MULHDU_rec_MULHWU_rec
  { 1, 409, 411, 3193, 3196 }, // 154 MULHD_rec_MULHW_rec_MULLWO_rec_MULLW_rec
  { 0, 0, 0, 0, 0 }, // 155 MULLDO_rec_MULLD_rec
  { 0, 0, 0, 0, 0 }, // 156 FRIMD_rec_FRIMS_rec_FRIND_rec_FRINS_rec_FRIPD_rec_FRIPS_rec_FRIZD_rec_FRIZS_rec_FRES_rec_FRE_rec_FADDS_rec_FSUBS_rec_FMSUBS_rec_FNMSUBS_rec_FMADDS_rec_FNMADDS_rec_FCFIDS_rec_FCFIDUS_rec_FCFIDU_rec_FCFID_rec_FCTIDUZ_rec_FCTIDU_rec_FCTIDZ_rec_FCTID_rec_FCTIWUZ_rec_FCTIWU_rec_FCTIWZ_rec_FCTIW_rec_FMULS_rec_FRSQRTES_rec_FRSQRTE_rec_FRSP_rec
  { 0, 0, 0, 0, 0 }, // 157 FADD_rec_FSUB_rec
  { 0, 0, 0, 0, 0 }, // 158 FMSUB_rec_FNMSUB_rec_FMADD_rec_FNMADD_rec_FMUL_rec
  { 0, 0, 0, 0, 0 }, // 159 XSADDDP_XSADDSP_XSCVDPHP_XSCVDPSP_XSCVDPSXDS_XSCVDPSXDSs_XSCVDPSXWS_XSCVDPUXDS_XSCVDPUXDSs_XSCVDPUXWS_XSCVDPSXWSs_XSCVDPUXWSs_XSCVHPDP_XSCVSPDP_XSCVSXDDP_XSCVSXDSP_XSCVUXDDP_XSCVUXDSP_XSRDPI_XSRDPIC_XSRDPIM_XSRDPIP_XSRDPIZ_XSREDP_XSRESP_XSRSQRTEDP_XSRSQRTESP_XSSUBDP_XSSUBSP_XSCVDPSPN_XSRSP
  { 1, 396, 398, 3196, 3198 }, // 160 LVSL_LVSR
  { 0, 0, 0, 0, 0 }, // 161 VSPLTISB_VSPLTISH_VSPLTISW_VSPLTB_VSPLTBs_VSPLTH_VSPLTHs_VSPLTW_XXMRGHW_XXMRGLW_XXPERM_XXPERMR_XXSLDWI_XXSLDWIs_XXSPLTIB_XXSPLTW_XXSPLTWs_XXPERMDI_XXPERMDIs
  { 0, 0, 0, 0, 0 }, // 162 V_SETALLONES_V_SETALLONESB_V_SETALLONESH_VBPERMQ_VGBBD_VMRGHB_VMRGHH_VMRGHW_VMRGLB_VMRGLH_VMRGLW_VPERM_VPERMR_VPERMXOR_VPKPX_VPKSDSS_VPKSDUS_VPKSHSS_VPKSHUS_VPKSWSS_VPKSWUS_VPKUDUM_VPKUDUS_VPKUHUM_VPKUHUS_VPKUWUM_VPKUWUS_VSL_VSLDOI_VSLO_VSLV_VSR_VSRO_VSRV_VUPKHPX_VUPKHSB_VUPKHSH_VUPKHSW_VUPKLPX_VUPKLSB_VUPKLSH_VUPKLSW_XXBRD_XXBRH_XXBRQ_XXBRW_XXEXTRACTUW_XXINSERTW_VADDCUQ_VADDECUQ_VADDEUQM_VMUL10CUQ_VMUL10ECUQ_VMUL10EUQ_VMUL10UQ_VSUBCUQ_VSUBECUQ_VSUBEUQM_XSTSTDCQP_XSXSIGQP_BCDCFN_rec_BCDCFZ_rec_BCDCPSGN_rec_BCDCTN_rec_BCDCTZ_rec_BCDSETSGN_rec_BCDS_rec_BCDTRUNC_rec_BCDUS_rec_BCDUTRUNC_rec
  { 1, 411, 413, 3198, 3201 }, // 163 VEXTRACTUB_VEXTRACTUH_VEXTRACTUW_VINSERTB_VINSERTD_VINSERTH_VINSERTW_MFVSRLD_MTVSRWS_VCLZLSBB_VCTZLSBB_VEXTRACTD_VEXTUBLX_VEXTUBRX_VEXTUHLX_VEXTUHRX_VEXTUWLX_VEXTUWRX_VPRTYBQ_VADDUQM_VSUBUQM
  { 0, 0, 0, 0, 0 }, // 164 XSCMPEXPQP_XSCMPOQP_XSCMPUQP
  { 0, 0, 0, 0, 0 }, // 165 BCDSR_rec_XSADDQP_XSADDQPO_XSCVDPQP_XSCVQPDP_XSCVQPDPO_XSCVQPSDZ_XSCVQPSWZ_XSCVQPUDZ_XSCVQPUWZ_XSCVSDQP_XSCVUDQP_XSRQPI_XSRQPIX_XSRQPXP_XSSUBQP_XSSUBQPO
  { 0, 0, 0, 0, 0 }, // 166 BCDCTSQ_rec
  { 0, 0, 0, 0, 0 }, // 167 XSMADDQP_XSMADDQPO_XSMSUBQP_XSMSUBQPO_XSMULQP_XSMULQPO_XSNMADDQP_XSNMADDQPO_XSNMSUBQP_XSNMSUBQPO
  { 0, 0, 0, 0, 0 }, // 168 BCDCFSQ_rec
  { 0, 0, 0, 0, 0 }, // 169 XSDIVQP_XSDIVQPO
  { 0, 0, 0, 0, 0 }, // 170 XSSQRTQP_XSSQRTQPO
  { 1, 396, 398, 3201, 3203 }, // 171 LXVL_LXVLL
  { 1, 396, 398, 3203, 3205 }, // 172 LVEBX_LVEHX_LVEWX_LVX_LVXL
  { 0, 0, 0, 0, 0 }, // 173 LXSIBZX_LXSIHZX_LXSDX_LXVB16X_LXVD2X_LXVWSX_LXSIWZX_LXV_LXVX_LXSD
  { 0, 0, 0, 0, 0 }, // 174 DFLOADf64_XFLOADf64_LIWZX
  { 1, 396, 398, 3205, 3207 }, // 175 DCBF_DCBFEP_DCBST_DCBSTEP_DCBT_DCBTEP_DCBZ_DCBZEP_DCBZL_DCBZLEP_DCBTST_DCBTSTEP
  { 0, 0, 0, 0, 0 }, // 176 CP_COPY_CP_COPY8
  { 0, 0, 0, 0, 0 }, // 177 CP_PASTE_CP_PASTE8
  { 1, 396, 398, 3207, 3209 }, // 178 ICBI_ICBIEP
  { 1, 396, 398, 3209, 3211 }, // 179 ICBT_ICBTLS_LBZ_LBZ8_LBZCIX_LBZX_LBZX8_LBZXTLS_LBZXTLS__LBZXTLS_32_LDBRX_LDCIX_LHBRX_LHBRX8_LHZ_LHZ8_LHZCIX_LHZX_LHZX8_LHZXTLS_LHZXTLS__LHZXTLS_32_LWBRX_LWBRX8_LWZ_LWZ8_LWZCIX_LWZX_LWZX8_LWZXTLS_LWZXTLS__LWZXTLS_32_EnforceIEIO_LSWI
  { 1, 415, 417, 3211, 3214 }, // 180 LBARX_LBARXL_LHARX_LHARXL_LWARX_LWARXL
  { 0, 0, 0, 0, 0 }, // 181 LD_LDX_LDXTLS_LDXTLS__DARN
  { 0, 0, 0, 0, 0 }, // 182 LDARX_LDARXL
  { 0, 0, 0, 0, 0 }, // 183 CP_ABORT
  { 0, 0, 0, 0, 0 }, // 184 ISYNC
  { 0, 0, 0, 0, 0 }, // 185 MSGSYNC
  { 1, 426, 428, 0, 0 }, // 186 TLBSYNC
  { 1, 396, 398, 0, 0 }, // 187 SYNC
  { 1, 396, 398, 3214, 3216 }, // 188 LMW
  { 0, 0, 0, 0, 0 }, // 189 LFIWZX_LFDX_LFD
  { 0, 0, 0, 0, 0 }, // 190 SLBIA
  { 0, 0, 0, 0, 0 }, // 191 SLBIE
  { 0, 0, 0, 0, 0 }, // 192 SLBMFEE
  { 0, 0, 0, 0, 0 }, // 193 SLBMFEV
  { 0, 0, 0, 0, 0 }, // 194 SLBMTE
  { 0, 0, 0, 0, 0 }, // 195 TLBIEL
  { 2, 417, 420, 3216, 3218 }, // 196 LHZU_LHZU8_LWZU_LWZU8
  { 2, 417, 420, 3218, 3220 }, // 197 LHZUX_LHZUX8_LWZUX_LWZUX8
  { 1, 398, 400, 3220, 3222 }, // 198 TEND
  { 1, 396, 398, 3222, 3224 }, // 199 STBCX_STHCX_STWCX
  { 0, 0, 0, 0, 0 }, // 200 STDCX
  { 0, 0, 0, 0, 0 }, // 201 LDMX
  { 1, 396, 398, 3224, 3226 }, // 202 LHA_LHA8_LHAX_LHAX8_LWAX_LWAX_32
  { 0, 0, 0, 0, 0 }, // 203 CP_PASTE8_rec_CP_PASTE_rec
  { 0, 0, 0, 0, 0 }, // 204 LWA_LWA_32
  { 1, 398, 400, 3226, 3228 }, // 205 TCHECK
  { 0, 0, 0, 0, 0 }, // 206 LFIWAX
  { 0, 0, 0, 0, 0 }, // 207 LXSIWAX
  { 0, 0, 0, 0, 0 }, // 208 LIWAX
  { 0, 0, 0, 0, 0 }, // 209 LFSX_LFS
  { 0, 0, 0, 0, 0 }, // 210 LXSSP_LXSSPX
  { 0, 0, 0, 0, 0 }, // 211 XFLOADf32_DFLOADf32
  { 1, 417, 420, 3228, 3230 }, // 212 LHAU_LHAU8
  { 1, 417, 420, 3230, 3232 }, // 213 LHAUX_LHAUX8_LWAUX
  { 0, 0, 0, 0, 0 }, // 214 LXVH8X_LXVDSX_LXVW4X
  { 0, 0, 0, 0, 0 }, // 215 STFD_STFDX_STFIWX_STFS_STFSX_STXSD_STXSDX_STXSIBX_STXSIBXv_STXSIHX_STXSIHXv_STXSIWX_STXSSP_STXSSPX
  { 1, 396, 398, 3232, 3234 }, // 216 STW_STW8_STDBRX_STHBRX_STWBRX_STB_STB8_STH_STH8_STBX_STBX8_STBXTLS_STBXTLS__STBXTLS_32_STHX_STHX8_STHXTLS_STHXTLS__STHXTLS_32_STWX_STWX8_STWXTLS_STWXTLS__STWXTLS_32
  { 0, 0, 0, 0, 0 }, // 217 DFSTOREf32_DFSTOREf64_XFSTOREf32_XFSTOREf64_STIWX
  { 0, 0, 0, 0, 0 }, // 218 STD_STDX_STDXTLS_STDXTLS_
  { 1, 396, 398, 3234, 3236 }, // 219 STBCIX_STDCIX_STHCIX_STWCIX_STSWI
  { 0, 0, 0, 0, 0 }, // 220 SLBIEG
  { 1, 396, 398, 3236, 3238 }, // 221 STMW
  { 0, 0, 0, 0, 0 }, // 222 TLBIE
  { 1, 396, 398, 3238, 3240 }, // 223 STVEBX_STVEHX_STVEWX_STVX_STVXL
  { 0, 0, 0, 0, 0 }, // 224 STXV_STXVB16X_STXVD2X_STXVH8X_STXVW4X_STXVX
  { 1, 396, 398, 3240, 3242 }, // 225 STXVL_STXVLL
  { 1, 398, 400, 3242, 3244 }, // 226 MTCTR_MTCTR8_MTCTR8loop_MTCTRloop_MTLR_MTLR8
  { 1, 398, 400, 3244, 3247 }, // 227 MFVRSAVE_MFVRSAVEv_MTVRSAVE_MTVRSAVEv
  { 1, 422, 424, 3247, 3249 }, // 228 MFPMR
  { 1, 411, 413, 3249, 3251 }, // 229 MTPMR
  { 1, 422, 424, 3251, 3253 }, // 230 MFTB_MFTB8
  { 1, 398, 400, 3253, 3255 }, // 231 MFCTR_MFCTR8_MFLR_MFLR8_MFSPR_MFSPR8
  { 1, 422, 424, 3255, 3257 }, // 232 MFMSR
  { 1, 424, 426, 3257, 3259 }, // 233 MTMSR
  { 0, 0, 0, 0, 0 }, // 234 MTMSRD
  { 1, 398, 400, 3259, 3261 }, // 235 MTSPR_MTSPR8
  { 1, 402, 405, 3261, 3264 }, // 236 DIVW_DIVWO_DIVWU_DIVWUO_MODSW
  { 1, 402, 405, 3264, 3267 }, // 237 DIVWE_DIVWEO_DIVWEU_DIVWEUO_MODSD_MODUD_MODUW
  { 0, 0, 0, 0, 0 }, // 238 DIVD_DIVDO_DIVDU_DIVDUO
  { 0, 0, 0, 0, 0 }, // 239 DIVDE_DIVDEO_DIVDEU_DIVDEUO
  { 1, 402, 405, 3267, 3270 }, // 240 DIVWO_rec_DIVWUO_rec_DIVWU_rec_DIVW_rec
  { 0, 0, 0, 0, 0 }, // 241 DIVD_rec_DIVDO_rec_DIVDU_rec_DIVDUO_rec
  { 1, 402, 405, 3270, 3273 }, // 242 DIVWE_rec_DIVWEO_rec_DIVWEU_rec_DIVWEUO_rec
  { 0, 0, 0, 0, 0 }, // 243 DIVDE_rec_DIVDEO_rec_DIVDEU_rec_DIVDEUO_rec
  { 1, 398, 400, 3273, 3276 }, // 244 MTCRF_MTCRF8
  { 1, 398, 400, 3276, 3279 }, // 245 ADDC8O_rec_ADDC8_rec_ADDCO_rec_ADDC_rec_SUBFC8O_rec_SUBFC8_rec_SUBFCO_rec_SUBFC_rec
  { 0, 0, 0, 0, 0 }, // 246 FABSD_rec_FABSS_rec_FNABSD_rec_FNABSS_rec_FCPSGND_rec_FCPSGNS_rec_FNEGD_rec_FNEGS_rec_FMR_rec
  { 1, 400, 402, 3279, 3281 }, // 247 MCRFS
  { 0, 0, 0, 0, 0 }, // 248 MTFSF_MTFSF_rec_MTFSFI_MTFSFI_rec
  { 0, 0, 0, 0, 0 }, // 249 MTFSFb
  { 0, 0, 0, 0, 0 }, // 250 RLDCL_rec_RLDCR_rec
  { 0, 0, 0, 0, 0 }, // 251 RLDICL_rec_RLDICR_rec_RLDICL_32_rec_RLDIMI_rec
  { 1, 398, 400, 3281, 3284 }, // 252 RLWIMI8_rec_RLWIMI_rec
  { 1, 398, 400, 3284, 3287 }, // 253 RLWINM8_rec_RLWINM_rec_RLWNM8_rec_RLWNM_rec_SLW8_rec_SLW_rec_SRW8_rec_SRW_rec
  { 1, 398, 400, 3287, 3290 }, // 254 SRAWI_rec_SRAW_rec
  { 0, 0, 0, 0, 0 }, // 255 MFFS_MFFSCE_MFFSL_MFFS_rec
  { 1, 420, 422, 3290, 3292 }, // 256 MFCR_MFCR8
  { 0, 0, 0, 0, 0 }, // 257 EXTSWSLI_32_64_rec_SRADI_rec_EXTSWSLI_rec_RLDIC_rec
  { 0, 0, 0, 0, 0 }, // 258 SRAD_rec_SLD_rec_SRD_rec
  { 1, 407, 409, 3292, 3295 }, // 259 FDIV
  { 1, 407, 409, 3295, 3298 }, // 260 FDIV_rec
  { 0, 0, 0, 0, 0 }, // 261 XSSQRTDP
  { 0, 0, 0, 0, 0 }, // 262 FSQRT
  { 0, 0, 0, 0, 0 }, // 263 XVSQRTDP
  { 0, 0, 0, 0, 0 }, // 264 XVSQRTSP
  { 0, 0, 0, 0, 0 }, // 265 FSQRT_rec
  { 0, 0, 0, 0, 0 }, // 266 XSSQRTSP
  { 0, 0, 0, 0, 0 }, // 267 FSQRTS
  { 0, 0, 0, 0, 0 }, // 268 FSQRTS_rec
  { 1, 407, 409, 3298, 3301 }, // 269 XSDIVDP
  { 1, 413, 415, 3301, 3304 }, // 270 FDIVS
  { 1, 413, 415, 3304, 3307 }, // 271 FDIVS_rec
  { 1, 413, 415, 3307, 3310 }, // 272 XSDIVSP
  { 1, 413, 415, 3310, 3313 }, // 273 XVDIVSP
  { 1, 407, 409, 3313, 3316 }, // 274 XVDIVDP
  { 0, 0, 0, 0, 0 }, // 275 LFSU
  { 0, 0, 0, 0, 0 }, // 276 LFSUX
  { 0, 0, 0, 0, 0 }, // 277 STFDU_STFDUX_STFSU_STFSUX
  { 2, 417, 420, 3316, 3318 }, // 278 STBU_STBU8_STDU_STHU_STHU8_STWU_STWU8
  { 2, 417, 420, 3318, 3320 }, // 279 STBUX_STBUX8_STDUX_STHUX_STHUX8_STWUX_STWUX8
  { 2, 417, 420, 3320, 3322 }, // 280 LBZU_LBZU8
  { 2, 417, 420, 3322, 3324 }, // 281 LBZUX_LBZUX8
  { 0, 0, 0, 0, 0 }, // 282 LDU
  { 0, 0, 0, 0, 0 }, // 283 LDUX
  { 0, 0, 0, 0, 0 }, // 284 LFDU
  { 0, 0, 0, 0, 0 }, // 285 LFDUX
  { 0, 0, 0, 0, 0 }, // 286 VPMSUMB_VPMSUMD_VPMSUMH_VPMSUMW_VCIPHER_VCIPHERLAST_VNCIPHER_VNCIPHERLAST_VSBOX
  { 1, 400, 402, 3324, 3326 }, // 287 BCCCTR_BCCCTR8_BCCCTRL_BCCCTRL8_BCCL_BCCLA_BCCLR_BCCLRL_BCCTR_BCCTR8_BCCTR8n_BCCTRL_BCCTRL8_BCCTRL8n_BCCTRLn_BCCTRn_BDNZ_BDNZ8_BDNZA_BDNZAm_BDNZAp_BDNZm_BDNZp_BDZ_BDZ8_BDZA_BDZAm_BDZAp_BDZm_BDZp_BDNZL_BDNZLA_BDNZLAm_BDNZLAp_BDNZLR_BDNZLR8_BDNZLRL_BDNZLRLm_BDNZLRLp_BDNZLRm_BDNZLRp_BDNZLm_BDNZLp_BDZL_BDZLA_BDZLAm_BDZLAp_BDZLR_BDZLR8_BDZLRL_BDZLRLm_BDZLRLp_BDZLRm_BDZLRp_BDZLm_BDZLp_BL_BL_NOP_BL_TLS_BL8_BL8_NOP_BL8_NOP_TLS_BL8_TLS_BL8_TLS__BLA_BLA8_BLA8_NOP_BLR_BLR8_BLRL_TAILB_TAILB8_TAILBA_TAILBA8_TAILBCTR_TAILBCTR8_gBC_gBCA_gBCAat_gBCCTR_gBCCTRL_gBCL_gBCLA_gBCLAat_gBCLR_gBCLRL_gBCLat_gBCat_BCLR_BCLRL_BCLRLn_BCLRn_BCTR_BCTR8_BCTRL_BCTRL8_B_BA_BC_BCC_BCCA_BCL_BCLalways_BCLn_BCTRL8_LDinto_toc_BCTRL_LWZinto_toc_BCn_CTRL_DEP
  { 1, 400, 402, 3326, 3328 }, // 288 ADDPCIS
  { 1, 396, 398, 3328, 3330 }, // 289 LDAT_LWAT
  { 1, 396, 398, 3330, 3332 }, // 290 STDAT_STWAT
  { 1, 398, 400, 3332, 3335 }, // 291 BRINC
  { 1, 411, 413, 3335, 3338 }, // 292 EVABS_EVEQV_EVNAND_EVNEG_EVADDIW_EVADDW_EVAND_EVANDC_EVCMPEQ_EVCMPGTS_EVCMPGTU_EVCMPLTS_EVCMPLTU_EVCNTLSW_EVCNTLZW_EVEXTSB_EVEXTSH_EVMERGEHI_EVMERGEHILO_EVMERGELO_EVMERGELOHI_EVNOR_EVOR_EVORC_EVXOR_EVRLW_EVRLWI_EVRNDW_EVSLW_EVSLWI_EVSPLATFI_EVSPLATI_EVSRWIS_EVSRWIU_EVSRWS_EVSRWU_EVSUBFW_EVSUBIFW
  { 1, 409, 411, 3338, 3341 }, // 293 EVMRA_EVADDSMIAAW_EVADDSSIAAW_EVADDUMIAAW_EVADDUSIAAW_EVDIVWS_EVDIVWU_EVMHEGSMFAA_EVMHEGSMFAN_EVMHEGSMIAA_EVMHEGSMIAN_EVMHEGUMIAA_EVMHEGUMIAN_EVMHESMF_EVMHESMFA_EVMHESMFAAW_EVMHESMFANW_EVMHESMI_EVMHESMIA_EVMHESMIAAW_EVMHESMIANW_EVMHESSF_EVMHESSFA_EVMHESSFAAW_EVMHESSFANW_EVMHESSIAAW_EVMHESSIANW_EVMHEUMI_EVMHEUMIA_EVMHEUMIAAW_EVMHEUMIANW_EVMHEUSIAAW_EVMHEUSIANW_EVMHOGSMFAA_EVMHOGSMFAN_EVMHOGSMIAA_EVMHOGSMIAN_EVMHOGUMIAA_EVMHOGUMIAN_EVMHOSMF_EVMHOSMFA_EVMHOSMFAAW_EVMHOSMFANW_EVMHOSMI_EVMHOSMIA_EVMHOSMIAAW_EVMHOSMIANW_EVMHOSSF_EVMHOSSFA_EVMHOSSFAAW_EVMHOSSFANW_EVMHOSSIAAW_EVMHOSSIANW_EVMHOUMI_EVMHOUMIA_EVMHOUMIAAW_EVMHOUMIANW_EVMHOUSIAAW_EVMHOUSIANW_EVMWHSMF_EVMWHSMFA_EVMWHSMI_EVMWHSMIA_EVMWHSSF_EVMWHSSFA_EVMWHUMI_EVMWHUMIA_EVMWLSMIAAW_EVMWLSMIANW_EVMWLSSIAAW_EVMWLSSIANW_EVMWLUMI_EVMWLUMIA_EVMWLUMIAAW_EVMWLUMIANW_EVMWLUSIAAW_EVMWLUSIANW_EVMWSMF_EVMWSMFA_EVMWSMFAA_EVMWSMFAN_EVMWSMI_EVMWSMIA_EVMWSMIAA_EVMWSMIAN_EVMWSSF_EVMWSSFA_EVMWSSFAA_EVMWSSFAN_EVMWUMI_EVMWUMIA_EVMWUMIAA_EVMWUMIAN_EVSUBFSMIAAW_EVSUBFSSIAAW_EVSUBFUMIAAW_EVSUBFUSIAAW
  { 1, 396, 398, 3341, 3343 }, // 294 EVLDD_EVLDDX_EVLDH_EVLDHX_EVLDW_EVLDWX_EVLHHESPLAT_EVLHHESPLATX_EVLHHOSSPLAT_EVLHHOSSPLATX_EVLHHOUSPLAT_EVLHHOUSPLATX_EVLWHE_EVLWHEX_EVLWHOS_EVLWHOSX_EVLWHOU_EVLWHOUX_EVLWHSPLAT_EVLWHSPLATX_EVLWWSPLAT_EVLWWSPLATX
  { 1, 396, 398, 3343, 3345 }, // 295 EVSTDD_EVSTDDX_EVSTDH_EVSTDHX_EVSTDW_EVSTDWX_EVSTWHE_EVSTWHEX_EVSTWHO_EVSTWHOX_EVSTWWE_EVSTWWEX_EVSTWWO_EVSTWWOX
  { 1, 400, 402, 3345, 3347 }, // 296 HRFID_ATTN_CLRBHRB_MFBHRBE_NAP_RFCI_RFDI_RFMCI_SC
  { 0, 0, 0, 0, 0 }, // 297 RFI
  { 0, 0, 0, 0, 0 }, // 298 RFID
  { 1, 396, 398, 3347, 3349 }, // 299 DSS_DSSALL_DST_DST64_DSTST_DSTST64_DSTSTT_DSTSTT64_DSTT_DSTT64_ICBLQ_LBEPX_LHEPX_LWEPX_TLBIVAX_TLBLD_TLBLI_TLBRE_TLBRE2_TLBSX_TLBSX2_TLBSX2D_TLBWE_TLBWE2_MBAR_TRAP_DCCCI_ICCCI
  { 1, 396, 398, 3349, 3351 }, // 300 ICBLC_STBEPX_STHEPX_STWEPX
  { 0, 0, 0, 0, 0 }, // 301 LFDEPX
  { 0, 0, 0, 0, 0 }, // 302 STFDEPX
  { 1, 422, 424, 3351, 3353 }, // 303 MFSR_MFSRIN
  { 1, 411, 413, 3353, 3355 }, // 304 MTSR_MTSRIN
  { 1, 398, 400, 3355, 3357 }, // 305 MFDCR
  { 1, 398, 400, 3357, 3359 }, // 306 MTDCR
  { 1, 398, 400, 3359, 3362 }, // 307 NOP_GT_PWR6_NOP_GT_PWR7
  { 0, 0, 0, 0, 0 }, // 308 TLBIA
  { 1, 424, 426, 3362, 3364 }, // 309 WRTEE_WRTEEI
  { 1, 396, 398, 0, 0 }, // 310 MSYNC
  { 0, 0, 0, 0, 0 }, // 311 SLBSYNC
  { 0, 0, 0, 0, 0 }, // 312 SLBFEE_rec
  { 0, 0, 0, 0, 0 }, // 313 STOP
  { 1, 396, 398, 3364, 3366 }, // 314 DCBA_DCBI
  { 0, uint16_t(~0U), uint16_t(~0U), uint16_t(~0U), uint16_t(~0U) }// end marker
};

static const llvm::InstrItinerary PPCE500mcItineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 430, 432, 0, 0 }, // 1 IIC_LdStSync
  { 1, 432, 434, 3366, 3369 }, // 2 IIC_IntSimple
  { 1, 432, 434, 3369, 3372 }, // 3 IIC_IntGeneral
  { 1, 434, 436, 3372, 3374 }, // 4 IIC_BrB
  { 0, 0, 0, 0, 0 }, // 5 IIC_VecFP
  { 1, 432, 434, 3374, 3377 }, // 6 IIC_IntCompare
  { 0, 0, 0, 0, 0 }, // 7 IIC_SprABORT
  { 0, 0, 0, 0, 0 }, // 8 IIC_LdStCOPY
  { 0, 0, 0, 0, 0 }, // 9 IIC_LdStPASTE
  { 1, 434, 436, 3377, 3380 }, // 10 IIC_BrCR
  { 0, 0, 0, 0, 0 }, // 11 IIC_LdStLD
  { 1, 430, 432, 3380, 3382 }, // 12 IIC_LdStDCBF
  { 1, 430, 432, 3382, 3384 }, // 13 IIC_LdStLoad
  { 0, 0, 0, 0, 0 }, // 14 IIC_IntDivD
  { 1, 436, 439, 3384, 3387 }, // 15 IIC_IntDivW
  { 0, 0, 0, 0, 0 }, // 16 IIC_FPDGeneral
  { 1, 439, 441, 3387, 3390 }, // 17 IIC_FPAddSub
  { 1, 441, 443, 3390, 3393 }, // 18 IIC_FPDivD
  { 0, 0, 0, 0, 0 }, // 19 IIC_FPSGeneral
  { 1, 443, 445, 3393, 3396 }, // 20 IIC_FPCompare
  { 1, 443, 445, 3396, 3399 }, // 21 IIC_FPGeneral
  { 0, 0, 0, 0, 0 }, // 22 IIC_VecGeneral
  { 0, 0, 0, 0, 0 }, // 23 IIC_VecComplex
  { 1, 430, 432, 3399, 3401 }, // 24 IIC_LdStStore
  { 0, 0, 0, 0, 0 }, // 25 IIC_IntRotateDI
  { 1, 445, 447, 3401, 3404 }, // 26 IIC_FPDivS
  { 1, 439, 441, 3404, 3408 }, // 27 IIC_FPFused
  { 0, 0, 0, 0, 0 }, // 28 IIC_FPSqrtD
  { 0, 0, 0, 0, 0 }, // 29 IIC_FPSqrtS
  { 1, 430, 432, 3408, 3410 }, // 30 IIC_LdStICBI
  { 1, 432, 434, 3410, 3414 }, // 31 IIC_IntISEL
  { 0, 0, 0, 0, 0 }, // 32 IIC_SprISYNC
  { 1, 447, 449, 3414, 3417 }, // 33 IIC_LdStLWARX
  { 2, 449, 452, 3417, 3419 }, // 34 IIC_LdStLoadUpd
  { 2, 449, 452, 3419, 3421 }, // 35 IIC_LdStLoadUpdX
  { 0, 0, 0, 0, 0 }, // 36 IIC_LdStLDARX
  { 0, 0, 0, 0, 0 }, // 37 IIC_LdStLDU
  { 0, 0, 0, 0, 0 }, // 38 IIC_LdStLDUX
  { 1, 430, 432, 3421, 3424 }, // 39 IIC_LdStLFD
  { 2, 449, 452, 3424, 3427 }, // 40 IIC_LdStLFDU
  { 2, 449, 452, 3427, 3430 }, // 41 IIC_LdStLFDUX
  { 1, 430, 432, 3430, 3432 }, // 42 IIC_LdStLHA
  { 1, 449, 452, 3432, 3434 }, // 43 IIC_LdStLHAU
  { 1, 449, 452, 3434, 3436 }, // 44 IIC_LdStLHAUX
  { 1, 430, 432, 3436, 3438 }, // 45 IIC_LdStLMW
  { 0, 0, 0, 0, 0 }, // 46 IIC_LdStLWA
  { 0, 0, 0, 0, 0 }, // 47 IIC_IntMulHD
  { 1, 434, 436, 3438, 3440 }, // 48 IIC_BrMCR
  { 1, 432, 434, 3440, 3443 }, // 49 IIC_BrMCRX
  { 1, 452, 454, 3443, 3445 }, // 50 IIC_SprMFCR
  { 1, 432, 434, 3445, 3447 }, // 51 IIC_SprMFSPR
  { 1, 454, 456, 3447, 3448 }, // 52 IIC_IntMFFS
  { 1, 456, 458, 3448, 3450 }, // 53 IIC_SprMFMSR
  { 1, 452, 454, 3450, 3452 }, // 54 IIC_SprMFCRF
  { 1, 456, 458, 3452, 3454 }, // 55 IIC_SprMFPMR
  { 1, 456, 458, 3454, 3456 }, // 56 IIC_SprMFSR
  { 1, 456, 458, 3456, 3458 }, // 57 IIC_SprMFTB
  { 0, 0, 0, 0, 0 }, // 58 IIC_SprMSGSYNC
  { 1, 432, 434, 3458, 3460 }, // 59 IIC_SprMTSPR
  { 1, 454, 456, 3460, 3463 }, // 60 IIC_IntMTFSB0
  { 1, 458, 460, 3463, 3465 }, // 61 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 62 IIC_SprMTMSRD
  { 1, 460, 462, 3465, 3467 }, // 63 IIC_SprMTPMR
  { 1, 460, 462, 3467, 3469 }, // 64 IIC_SprMTSR
  { 1, 462, 464, 3469, 3472 }, // 65 IIC_IntMulHW
  { 1, 462, 464, 3472, 3475 }, // 66 IIC_IntMulHWU
  { 1, 462, 464, 3475, 3478 }, // 67 IIC_IntMulLI
  { 0, 0, 0, 0, 0 }, // 68 IIC_VecPerm
  { 1, 430, 432, 3478, 3481 }, // 69 IIC_LdStSTFD
  { 2, 449, 452, 3481, 3484 }, // 70 IIC_LdStSTFDU
  { 0, 0, 0, 0, 0 }, // 71 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 72 IIC_IntRFID
  { 0, 0, 0, 0, 0 }, // 73 IIC_IntRotateD
  { 1, 432, 434, 3484, 3487 }, // 74 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 75 IIC_SprSLBFEE
  { 0, 0, 0, 0, 0 }, // 76 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 77 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprSLBIEG
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprSLBMFEV
  { 0, 0, 0, 0, 0 }, // 81 IIC_SprSLBMTE
  { 0, 0, 0, 0, 0 }, // 82 IIC_SprSLBSYNC
  { 1, 432, 434, 3487, 3490 }, // 83 IIC_IntShift
  { 1, 430, 432, 3490, 3492 }, // 84 IIC_LdStSTWCX
  { 2, 449, 452, 3492, 3494 }, // 85 IIC_LdStSTU
  { 2, 449, 452, 3494, 3496 }, // 86 IIC_LdStSTUX
  { 0, 0, 0, 0, 0 }, // 87 IIC_LdStSTD
  { 0, 0, 0, 0, 0 }, // 88 IIC_LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 89 IIC_SprSTOP
  { 0, 0, 0, 0, 0 }, // 90 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 91 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 92 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 93 IIC_SprTLBIEL
  { 1, 464, 466, 0, 0 }, // 94 IIC_SprTLBSYNC
  { 1, 466, 468, 3496, 3498 }, // 95 IIC_IntTrapW
  { 0, 0, 0, 0, 0 }, // 96 IIC_VecFPCompare
  { 0, 0, 0, 0, 0 }, // 97 VADDUBM_VADDUDM_VADDUHM_VADDUWM_VEXTSB2D_VEXTSB2Ds_VEXTSB2W_VEXTSB2Ws_VEXTSH2D_VEXTSH2Ds_VEXTSH2W_VEXTSH2Ws_VEXTSW2D_VEXTSW2Ds_VSLD_VSRD_VSUBUBM_VSUBUDM_VSUBUHM_VSUBUWM_VPOPCNTB_VPOPCNTH_VSRAD_MTVSRDD_VEQV_VNAND_VNEGD_VNEGW_VORC_XXLAND_XXLANDC_XXLEQV_XXLEQVOnes_XXLNAND_XXLNOR_XXLOR_XXLORf_XXLORC_XXLXOR_XXLXORdpz_XXLXORspz_XXLXORz
  { 0, 0, 0, 0, 0 }, // 98 VAND_VANDC_V_SET0_V_SET0B_V_SET0H_VSLB_VSLH_VSLW_VSRB_VSRH_VSRW_VRLB_VRLD_VRLH_VRLW_VSRAB_VSRAH_VSRAW_XVABSDP_XVABSSP_XVNABSDP_XVNABSSP_XVCPSGNDP_XVCPSGNSP_XVIEXPDP_XVIEXPSP_XVXEXPDP_XVXEXPSP_VRLDMI_VRLDNM_VRLWMI_VRLWNM_VMRGEW_VMRGOW_VNOR_VOR_VSEL_VXOR_XVNEGDP_XVNEGSP_XSABSQP_XSCPSGNQP_XSIEXPQP_XSNABSQP_XSNEGQP_XSXEXPQP
  { 0, 0, 0, 0, 0 }, // 99 XXSEL
  { 1, 432, 434, 3498, 3500 }, // 100 TABORTDC_TABORTDCI_TABORTWC_TABORTWCI
  { 1, 454, 456, 3500, 3503 }, // 101 MTFSB0_MTFSB1
  { 1, 454, 456, 3503, 3504 }, // 102 MFFSCDRN_MFFSCDRNI_MFFSCRN_MFFSCRNI
  { 1, 432, 434, 3504, 3507 }, // 103 CMPRB_CMPRB8_CMPEQB
  { 0, 0, 0, 0, 0 }, // 104 TD_TDI
  { 1, 466, 468, 3507, 3509 }, // 105 TW_TWI
  { 1, 443, 445, 3509, 3512 }, // 106 FCMPUD_FCMPUS_FTDIV_FTSQRT
  { 0, 0, 0, 0, 0 }, // 107 XSTSTDCDP_XSTSTDCSP
  { 0, 0, 0, 0, 0 }, // 108 XSMAXCDP_XSMAXDP_XSMAXJDP_XSMINCDP_XSMINDP_XSMINJDP_XSXSIGDP_XSCVSPDPN
  { 1, 443, 445, 3512, 3515 }, // 109 XSCMPEQDP_XSCMPEXPDP_XSCMPGEDP_XSCMPGTDP_XSCMPODP_XSCMPUDP_XSTDIVDP_XSTSQRTDP
  { 1, 432, 434, 3515, 3518 }, // 110 CNTLZD_CNTLZD_rec_CNTLZW_CNTLZW8_CNTLZW8_rec_CNTLZW_rec_CNTTZD_CNTTZD_rec_CNTTZW_CNTTZW8_CNTTZW8_rec_CNTTZW_rec_POPCNTD_POPCNTW_CMPB_CMPB8_SETB_SETB8_BPERMD
  { 0, 0, 0, 0, 0 }, // 111 SLD_SRD_SRAD
  { 0, 0, 0, 0, 0 }, // 112 SRADI_EXTSWSLI_32_64_EXTSWSLI_SRADI_32_RLDIC
  { 0, 0, 0, 0, 0 }, // 113 MFVRD_MFVSRD_MTVRD_MTVSRD_MTVRWA_MTVRWZ_MTVSRWA_MTVSRWZ_MFVSRWZ_MFVRWZ
  { 1, 432, 434, 3518, 3521 }, // 114 CMPLW_CMPLWI_CMPW_CMPWI_CMPD_CMPDI_CMPLD_CMPLDI
  { 1, 432, 434, 3521, 3524 }, // 115 SUBFC_SUBFC8_SUBFC8O_SUBFCO_SUBFIC_SUBFIC8_ANDI8_rec_ANDIS8_rec_ANDIS_rec_ANDI_rec_ADDC_ADDC8_ADDC8O_ADDCO_ADDIC_ADDIC8_ADDIC_rec_ADDE_ADDE8_ADDE8O_ADDE8O_rec_ADDE8_rec_ADDEO_ADDEO_rec_ADDE_rec_ADDME_ADDME8_ADDME8O_ADDME8O_rec_ADDME8_rec_ADDMEO_ADDMEO_rec_ADDME_rec_ADDZE_ADDZE8_ADDZE8O_ADDZE8O_rec_ADDZE8_rec_ADDZEO_ADDZEO_rec_ADDZE_rec_SUBF_SUBF8_SUBF8O_SUBF8O_rec_SUBF8_rec_SUBFE_SUBFE8_SUBFE8O_SUBFE8O_rec_SUBFE8_rec_SUBFEO_SUBFEO_rec_SUBFE_rec_SUBFME_SUBFME8_SUBFME8O_SUBFME8O_rec_SUBFME8_rec_SUBFMEO_SUBFMEO_rec_SUBFME_rec_SUBFO_SUBFO_rec_SUBFZE_SUBFZE8_SUBFZE8O_SUBFZE8O_rec_SUBFZE8_rec_SUBFZEO_SUBFZEO_rec_SUBFZE_rec_SUBF_rec_POPCNTB_LA
  { 1, 432, 434, 3524, 3527 }, // 116 ADD4_ADD4O_ADD4O_rec_ADD4_rec_ADD8_ADD8O_ADD8O_rec_ADD8_rec_NEG_NEG8_NEG8O_NEG8O_rec_NEG8_rec_NEGO_NEGO_rec_NEG_rec_ADDI_ADDI8_ADDIS_ADDIS8_LI_LI8_LIS_LIS8_OR_OR8_OR8_rec_ORI_ORI8_ORIS_ORIS8_OR_rec_XOR_XOR8_XOR8_rec_XORI_XORI8_XORIS_XORIS8_XOR_rec_NAND_NAND8_NAND8_rec_NAND_rec_AND_AND8_AND8_rec_ANDC_ANDC8_ANDC8_rec_ANDC_rec_AND_rec_NOR_NOR8_NOR8_rec_NOR_rec_ORC_ORC8_ORC8_rec_ORC_rec_EQV_EQV8_EQV8_rec_EQV_rec_EXTSB_EXTSB8_EXTSB8_32_64_EXTSB8_rec_EXTSB_rec_EXTSH_EXTSH8_EXTSH8_32_64_EXTSH8_rec_EXTSH_rec_EXTSW_EXTSW_32_EXTSW_32_64_EXTSW_32_64_rec_EXTSW_rec_ADD4TLS_ADD8TLS_ADD8TLS__NOP
  { 0, 0, 0, 0, 0 }, // 117 ADDIStocHA_ADDIStocHA8_ADDItocL_COPY
  { 1, 434, 436, 3527, 3529 }, // 118 MCRF
  { 1, 432, 434, 3529, 3532 }, // 119 MCRXRX
  { 0, 0, 0, 0, 0 }, // 120 XSNABSDP_XSXEXPDP_XSABSDP_XSNEGDP_XSCPSGNDP
  { 1, 434, 436, 3532, 3534 }, // 121 RFEBB
  { 1, 432, 434, 3534, 3536 }, // 122 TBEGIN_TRECHKPT
  { 1, 430, 432, 3536, 3538 }, // 123 WAIT
  { 0, 0, 0, 0, 0 }, // 124 RLDCL_RLDCR
  { 1, 432, 434, 3538, 3541 }, // 125 RLWIMI_RLWIMI8
  { 0, 0, 0, 0, 0 }, // 126 RLDICL_RLDICL_32_RLDICL_32_64_RLDICR_RLDICR_32_RLDIMI
  { 1, 452, 454, 3541, 3543 }, // 127 MFOCRF_MFOCRF8
  { 1, 432, 434, 3543, 3546 }, // 128 MTOCRF_MTOCRF8
  { 1, 434, 436, 3546, 3549 }, // 129 CR6SET_CR6UNSET_CRSET_CRUNSET_CRAND_CRANDC_CRNAND_CRNOR_CROR_CRORC_CREQV_CRXOR
  { 1, 432, 434, 3549, 3552 }, // 130 SLW_SLW8_SRW_SRW8_RLWINM_RLWINM8_RLWNM_RLWNM8
  { 1, 443, 445, 3552, 3555 }, // 131 FABSD_FABSS_FNABSD_FNABSS_FNEGD_FNEGS_FCPSGND_FCPSGNS_FMR
  { 1, 432, 434, 3555, 3558 }, // 132 SRAW_SRAWI
  { 1, 432, 434, 3558, 3562 }, // 133 ISEL_ISEL8
  { 0, 0, 0, 0, 0 }, // 134 XSIEXPDP
  { 1, 432, 434, 3562, 3564 }, // 135 TRECLAIM_TSR_TABORT
  { 1, 430, 432, 3564, 3566 }, // 136 MFVSCR
  { 1, 430, 432, 3566, 3568 }, // 137 MTVSCR
  { 0, 0, 0, 0, 0 }, // 138 VCMPNEZB_VCMPNEZH_VCMPNEZW_VCMPEQUB_VCMPEQUD_VCMPEQUH_VCMPEQUW_VCMPNEB_VCMPNEH_VCMPNEW_VCMPEQFP_VCMPEQFP_rec_VCMPGEFP_VCMPGEFP_rec_VCMPGTFP_VCMPGTFP_rec_VCMPBFP_VCMPBFP_rec_VCMPGTSB_VCMPGTSB_rec_VCMPGTSD_VCMPGTSD_rec_VCMPGTSH_VCMPGTSH_rec_VCMPGTSW_VCMPGTSW_rec_VCMPGTUB_VCMPGTUB_rec_VCMPGTUD_VCMPGTUD_rec_VCMPGTUH_VCMPGTUH_rec_VCMPGTUW_VCMPGTUW_rec_VCMPNEB_rec_VCMPNEH_rec_VCMPNEW_rec_VCMPNEZB_rec_VCMPNEZH_rec_VCMPNEZW_rec_VCMPEQUB_rec_VCMPEQUD_rec_VCMPEQUH_rec_VCMPEQUW_rec_XVCMPEQDP_XVCMPEQDP_rec_XVCMPEQSP_XVCMPEQSP_rec_XVCMPGEDP_XVCMPGEDP_rec_XVCMPGESP_XVCMPGESP_rec_XVCMPGTDP_XVCMPGTDP_rec_XVCMPGTSP_XVCMPGTSP_rec
  { 0, 0, 0, 0, 0 }, // 139 VABSDUB_VABSDUH_VABSDUW_VCLZB_VCLZD_VCLZH_VCLZW_VCTZB_VCTZD_VCTZH_VCTZW_VPOPCNTW_VPOPCNTD_VPRTYBD_VPRTYBW
  { 0, 0, 0, 0, 0 }, // 140 VADDUBS_VADDUHS_VADDUWS_VAVGSB_VAVGSH_VAVGSW_VAVGUB_VAVGUH_VAVGUW_VADDSBS_VADDSHS_VADDSWS_VMAXFP_VMINFP_VMAXSB_VMAXSD_VMAXSH_VMAXSW_VMAXUB_VMAXUD_VMAXUH_VMAXUW_VMINSB_VMINSD_VMINSH_VMINSW_VMINUB_VMINUD_VMINUH_VMINUW_VBPERMD_VADDCUW_VSHASIGMAD_VSHASIGMAW_VSUBSBS_VSUBSHS_VSUBSWS_VSUBUBS_VSUBUHS_VSUBUWS_VSUBCUW_XVMAXDP_XVMAXSP_XVMINDP_XVMINSP_XVTSTDCDP_XVTSTDCSP_XVXSIGDP_XVXSIGSP
  { 1, 443, 445, 3568, 3571 }, // 141 XVTDIVDP_XVTDIVSP_XVTSQRTDP_XVTSQRTSP
  { 0, 0, 0, 0, 0 }, // 142 VADDFP_VCTSXS_VCTSXS_0_VCTUXS_VCTUXS_0_VEXPTEFP_VLOGEFP_VMADDFP_VMHADDSHS_VNMSUBFP_VREFP_VRFIM_VRFIN_VRFIP_VRFIZ_VRSQRTEFP_XVADDDP_XVADDSP_XVCVDPSP_XVCVDPSXDS_XVCVDPSXWS_XVCVDPUXDS_XVCVDPUXWS_XVCVHPSP_XVCVSPDP_XVCVSPHP_XVCVSPSXDS_XVCVSPSXWS_XVCVSPUXDS_XVCVSPUXWS_XVCVSXDDP_XVCVSXDSP_XVCVSXWDP_XVCVSXWSP_XVCVUXDDP_XVCVUXDSP_XVCVUXWDP_XVCVUXWSP_XVMADDADP_XVMADDASP_XVMADDMDP_XVMADDMSP_XVMSUBADP_XVMSUBASP_XVMSUBMDP_XVMSUBMSP_XVMULDP_XVMULSP_XVNMADDADP_XVNMADDASP_XVNMADDMDP_XVNMADDMSP_XVNMSUBADP_XVNMSUBASP_XVNMSUBMDP_XVNMSUBMSP_XVRDPI_XVRDPIC_XVRDPIM_XVRDPIP_XVRDPIZ_XVREDP_XVRESP_XVRSPI_XVRSPIC_XVRSPIM_XVRSPIP_XVRSPIZ_XVRSQRTEDP_XVRSQRTESP_XVSUBDP_XVSUBSP_VCFSX_VCFSX_0_VCFUX_VCFUX_0_VMHRADDSHS_VMLADDUHM_VMSUMMBM_VMSUMSHM_VMSUMSHS_VMSUMUBM_VMSUMUHM_VMSUMUDM_VMSUMUHS_VMULESB_VMULESH_VMULESW_VMULEUB_VMULEUH_VMULEUW_VMULOSB_VMULOSH_VMULOSW_VMULOUB_VMULOUH_VMULOUW_VSUM2SWS_VSUM4SBS_VSUM4SHS_VSUM4UBS_VSUMSWS
  { 0, 0, 0, 0, 0 }, // 143 VSUBFP_VMULUWM
  { 0, 0, 0, 0, 0 }, // 144 MADDHD_MADDHDU_MADDLD_MADDLD8_MULLD_MULLDO
  { 1, 462, 464, 3571, 3574 }, // 145 MULHD_MULHW_MULLW_MULLWO
  { 1, 462, 464, 3574, 3577 }, // 146 MULHDU_MULHWU
  { 1, 462, 464, 3577, 3580 }, // 147 MULLI_MULLI8
  { 1, 443, 445, 3580, 3583 }, // 148 FRSP_FRIMD_FRIMS_FRIND_FRINS_FRIPD_FRIPS_FRIZD_FRIZS_FRE_FRES_FADDS_FMSUBS_FMADDS_FSUBS_FCFID_FCFIDS_FCFIDU_FCFIDUS_FCTID_FCTIDU_FCTIDUZ_FCTIDZ_FCTIW_FCTIWU_FCTIWUZ_FCTIWZ_FRSQRTE_FRSQRTES_FNMADDS_FNMSUBS_FSELD_FSELS_FMULS
  { 1, 439, 441, 3583, 3586 }, // 149 FADD_FSUB
  { 1, 439, 441, 3586, 3590 }, // 150 FMSUB_FMADD_FNMADD_FNMSUB_FMUL
  { 0, 0, 0, 0, 0 }, // 151 XSMADDADP_XSMADDASP_XSMADDMDP_XSMADDMSP_XSMSUBADP_XSMSUBASP_XSMSUBMDP_XSMSUBMSP_XSMULDP_XSMULSP_XSNMADDADP_XSNMADDASP_XSNMADDMDP_XSNMADDMSP_XSNMSUBADP_XSNMSUBASP_XSNMSUBMDP_XSNMSUBMSP
  { 1, 443, 445, 3590, 3593 }, // 152 FSELD_rec_FSELS_rec
  { 1, 462, 464, 3593, 3596 }, // 153 MULHDU_rec_MULHWU_rec
  { 1, 462, 464, 3596, 3599 }, // 154 MULHD_rec_MULHW_rec_MULLWO_rec_MULLW_rec
  { 0, 0, 0, 0, 0 }, // 155 MULLDO_rec_MULLD_rec
  { 1, 443, 445, 3599, 3602 }, // 156 FRIMD_rec_FRIMS_rec_FRIND_rec_FRINS_rec_FRIPD_rec_FRIPS_rec_FRIZD_rec_FRIZS_rec_FRES_rec_FRE_rec_FADDS_rec_FSUBS_rec_FMSUBS_rec_FNMSUBS_rec_FMADDS_rec_FNMADDS_rec_FCFIDS_rec_FCFIDUS_rec_FCFIDU_rec_FCFID_rec_FCTIDUZ_rec_FCTIDU_rec_FCTIDZ_rec_FCTID_rec_FCTIWUZ_rec_FCTIWU_rec_FCTIWZ_rec_FCTIW_rec_FMULS_rec_FRSQRTES_rec_FRSQRTE_rec_FRSP_rec
  { 1, 439, 441, 3602, 3605 }, // 157 FADD_rec_FSUB_rec
  { 1, 439, 441, 3605, 3609 }, // 158 FMSUB_rec_FNMSUB_rec_FMADD_rec_FNMADD_rec_FMUL_rec
  { 0, 0, 0, 0, 0 }, // 159 XSADDDP_XSADDSP_XSCVDPHP_XSCVDPSP_XSCVDPSXDS_XSCVDPSXDSs_XSCVDPSXWS_XSCVDPUXDS_XSCVDPUXDSs_XSCVDPUXWS_XSCVDPSXWSs_XSCVDPUXWSs_XSCVHPDP_XSCVSPDP_XSCVSXDDP_XSCVSXDSP_XSCVUXDDP_XSCVUXDSP_XSRDPI_XSRDPIC_XSRDPIM_XSRDPIP_XSRDPIZ_XSREDP_XSRESP_XSRSQRTEDP_XSRSQRTESP_XSSUBDP_XSSUBSP_XSCVDPSPN_XSRSP
  { 1, 430, 432, 3609, 3611 }, // 160 LVSL_LVSR
  { 0, 0, 0, 0, 0 }, // 161 VSPLTISB_VSPLTISH_VSPLTISW_VSPLTB_VSPLTBs_VSPLTH_VSPLTHs_VSPLTW_XXMRGHW_XXMRGLW_XXPERM_XXPERMR_XXSLDWI_XXSLDWIs_XXSPLTIB_XXSPLTW_XXSPLTWs_XXPERMDI_XXPERMDIs
  { 0, 0, 0, 0, 0 }, // 162 V_SETALLONES_V_SETALLONESB_V_SETALLONESH_VBPERMQ_VGBBD_VMRGHB_VMRGHH_VMRGHW_VMRGLB_VMRGLH_VMRGLW_VPERM_VPERMR_VPERMXOR_VPKPX_VPKSDSS_VPKSDUS_VPKSHSS_VPKSHUS_VPKSWSS_VPKSWUS_VPKUDUM_VPKUDUS_VPKUHUM_VPKUHUS_VPKUWUM_VPKUWUS_VSL_VSLDOI_VSLO_VSLV_VSR_VSRO_VSRV_VUPKHPX_VUPKHSB_VUPKHSH_VUPKHSW_VUPKLPX_VUPKLSB_VUPKLSH_VUPKLSW_XXBRD_XXBRH_XXBRQ_XXBRW_XXEXTRACTUW_XXINSERTW_VADDCUQ_VADDECUQ_VADDEUQM_VMUL10CUQ_VMUL10ECUQ_VMUL10EUQ_VMUL10UQ_VSUBCUQ_VSUBECUQ_VSUBEUQM_XSTSTDCQP_XSXSIGQP_BCDCFN_rec_BCDCFZ_rec_BCDCPSGN_rec_BCDCTN_rec_BCDCTZ_rec_BCDSETSGN_rec_BCDS_rec_BCDTRUNC_rec_BCDUS_rec_BCDUTRUNC_rec
  { 0, 0, 0, 0, 0 }, // 163 VEXTRACTUB_VEXTRACTUH_VEXTRACTUW_VINSERTB_VINSERTD_VINSERTH_VINSERTW_MFVSRLD_MTVSRWS_VCLZLSBB_VCTZLSBB_VEXTRACTD_VEXTUBLX_VEXTUBRX_VEXTUHLX_VEXTUHRX_VEXTUWLX_VEXTUWRX_VPRTYBQ_VADDUQM_VSUBUQM
  { 1, 443, 445, 3611, 3614 }, // 164 XSCMPEXPQP_XSCMPOQP_XSCMPUQP
  { 0, 0, 0, 0, 0 }, // 165 BCDSR_rec_XSADDQP_XSADDQPO_XSCVDPQP_XSCVQPDP_XSCVQPDPO_XSCVQPSDZ_XSCVQPSWZ_XSCVQPUDZ_XSCVQPUWZ_XSCVSDQP_XSCVUDQP_XSRQPI_XSRQPIX_XSRQPXP_XSSUBQP_XSSUBQPO
  { 0, 0, 0, 0, 0 }, // 166 BCDCTSQ_rec
  { 0, 0, 0, 0, 0 }, // 167 XSMADDQP_XSMADDQPO_XSMSUBQP_XSMSUBQPO_XSMULQP_XSMULQPO_XSNMADDQP_XSNMADDQPO_XSNMSUBQP_XSNMSUBQPO
  { 0, 0, 0, 0, 0 }, // 168 BCDCFSQ_rec
  { 0, 0, 0, 0, 0 }, // 169 XSDIVQP_XSDIVQPO
  { 0, 0, 0, 0, 0 }, // 170 XSSQRTQP_XSSQRTQPO
  { 1, 430, 432, 3614, 3616 }, // 171 LXVL_LXVLL
  { 1, 430, 432, 3616, 3618 }, // 172 LVEBX_LVEHX_LVEWX_LVX_LVXL
  { 1, 430, 432, 3618, 3621 }, // 173 LXSIBZX_LXSIHZX_LXSDX_LXVB16X_LXVD2X_LXVWSX_LXSIWZX_LXV_LXVX_LXSD
  { 0, 0, 0, 0, 0 }, // 174 DFLOADf64_XFLOADf64_LIWZX
  { 1, 430, 432, 3621, 3623 }, // 175 DCBF_DCBFEP_DCBST_DCBSTEP_DCBT_DCBTEP_DCBZ_DCBZEP_DCBZL_DCBZLEP_DCBTST_DCBTSTEP
  { 0, 0, 0, 0, 0 }, // 176 CP_COPY_CP_COPY8
  { 0, 0, 0, 0, 0 }, // 177 CP_PASTE_CP_PASTE8
  { 1, 430, 432, 3623, 3625 }, // 178 ICBI_ICBIEP
  { 1, 430, 432, 3625, 3627 }, // 179 ICBT_ICBTLS_LBZ_LBZ8_LBZCIX_LBZX_LBZX8_LBZXTLS_LBZXTLS__LBZXTLS_32_LDBRX_LDCIX_LHBRX_LHBRX8_LHZ_LHZ8_LHZCIX_LHZX_LHZX8_LHZXTLS_LHZXTLS__LHZXTLS_32_LWBRX_LWBRX8_LWZ_LWZ8_LWZCIX_LWZX_LWZX8_LWZXTLS_LWZXTLS__LWZXTLS_32_EnforceIEIO_LSWI
  { 1, 447, 449, 3627, 3630 }, // 180 LBARX_LBARXL_LHARX_LHARXL_LWARX_LWARXL
  { 0, 0, 0, 0, 0 }, // 181 LD_LDX_LDXTLS_LDXTLS__DARN
  { 0, 0, 0, 0, 0 }, // 182 LDARX_LDARXL
  { 0, 0, 0, 0, 0 }, // 183 CP_ABORT
  { 0, 0, 0, 0, 0 }, // 184 ISYNC
  { 0, 0, 0, 0, 0 }, // 185 MSGSYNC
  { 1, 464, 466, 0, 0 }, // 186 TLBSYNC
  { 1, 430, 432, 0, 0 }, // 187 SYNC
  { 1, 430, 432, 3630, 3632 }, // 188 LMW
  { 1, 430, 432, 3632, 3635 }, // 189 LFIWZX_LFDX_LFD
  { 0, 0, 0, 0, 0 }, // 190 SLBIA
  { 0, 0, 0, 0, 0 }, // 191 SLBIE
  { 0, 0, 0, 0, 0 }, // 192 SLBMFEE
  { 0, 0, 0, 0, 0 }, // 193 SLBMFEV
  { 0, 0, 0, 0, 0 }, // 194 SLBMTE
  { 0, 0, 0, 0, 0 }, // 195 TLBIEL
  { 2, 449, 452, 3635, 3637 }, // 196 LHZU_LHZU8_LWZU_LWZU8
  { 2, 449, 452, 3637, 3639 }, // 197 LHZUX_LHZUX8_LWZUX_LWZUX8
  { 1, 432, 434, 3639, 3641 }, // 198 TEND
  { 1, 430, 432, 3641, 3643 }, // 199 STBCX_STHCX_STWCX
  { 0, 0, 0, 0, 0 }, // 200 STDCX
  { 0, 0, 0, 0, 0 }, // 201 LDMX
  { 1, 430, 432, 3643, 3645 }, // 202 LHA_LHA8_LHAX_LHAX8_LWAX_LWAX_32
  { 0, 0, 0, 0, 0 }, // 203 CP_PASTE8_rec_CP_PASTE_rec
  { 0, 0, 0, 0, 0 }, // 204 LWA_LWA_32
  { 1, 432, 434, 3645, 3647 }, // 205 TCHECK
  { 1, 430, 432, 3647, 3650 }, // 206 LFIWAX
  { 1, 430, 432, 3650, 3653 }, // 207 LXSIWAX
  { 0, 0, 0, 0, 0 }, // 208 LIWAX
  { 1, 430, 432, 3653, 3656 }, // 209 LFSX_LFS
  { 1, 430, 432, 3656, 3659 }, // 210 LXSSP_LXSSPX
  { 0, 0, 0, 0, 0 }, // 211 XFLOADf32_DFLOADf32
  { 1, 449, 452, 3659, 3661 }, // 212 LHAU_LHAU8
  { 1, 449, 452, 3661, 3663 }, // 213 LHAUX_LHAUX8_LWAUX
  { 1, 430, 432, 3663, 3666 }, // 214 LXVH8X_LXVDSX_LXVW4X
  { 1, 430, 432, 3666, 3669 }, // 215 STFD_STFDX_STFIWX_STFS_STFSX_STXSD_STXSDX_STXSIBX_STXSIBXv_STXSIHX_STXSIHXv_STXSIWX_STXSSP_STXSSPX
  { 1, 430, 432, 3669, 3671 }, // 216 STW_STW8_STDBRX_STHBRX_STWBRX_STB_STB8_STH_STH8_STBX_STBX8_STBXTLS_STBXTLS__STBXTLS_32_STHX_STHX8_STHXTLS_STHXTLS__STHXTLS_32_STWX_STWX8_STWXTLS_STWXTLS__STWXTLS_32
  { 0, 0, 0, 0, 0 }, // 217 DFSTOREf32_DFSTOREf64_XFSTOREf32_XFSTOREf64_STIWX
  { 0, 0, 0, 0, 0 }, // 218 STD_STDX_STDXTLS_STDXTLS_
  { 1, 430, 432, 3671, 3673 }, // 219 STBCIX_STDCIX_STHCIX_STWCIX_STSWI
  { 0, 0, 0, 0, 0 }, // 220 SLBIEG
  { 1, 430, 432, 3673, 3675 }, // 221 STMW
  { 0, 0, 0, 0, 0 }, // 222 TLBIE
  { 1, 430, 432, 3675, 3677 }, // 223 STVEBX_STVEHX_STVEWX_STVX_STVXL
  { 1, 430, 432, 3677, 3680 }, // 224 STXV_STXVB16X_STXVD2X_STXVH8X_STXVW4X_STXVX
  { 1, 430, 432, 3680, 3682 }, // 225 STXVL_STXVLL
  { 1, 432, 434, 3682, 3684 }, // 226 MTCTR_MTCTR8_MTCTR8loop_MTCTRloop_MTLR_MTLR8
  { 1, 432, 434, 3684, 3687 }, // 227 MFVRSAVE_MFVRSAVEv_MTVRSAVE_MTVRSAVEv
  { 1, 456, 458, 3687, 3689 }, // 228 MFPMR
  { 1, 460, 462, 3689, 3691 }, // 229 MTPMR
  { 1, 456, 458, 3691, 3693 }, // 230 MFTB_MFTB8
  { 1, 432, 434, 3693, 3695 }, // 231 MFCTR_MFCTR8_MFLR_MFLR8_MFSPR_MFSPR8
  { 1, 456, 458, 3695, 3697 }, // 232 MFMSR
  { 1, 458, 460, 3697, 3699 }, // 233 MTMSR
  { 0, 0, 0, 0, 0 }, // 234 MTMSRD
  { 1, 432, 434, 3699, 3701 }, // 235 MTSPR_MTSPR8
  { 1, 436, 439, 3701, 3704 }, // 236 DIVW_DIVWO_DIVWU_DIVWUO_MODSW
  { 1, 436, 439, 3704, 3707 }, // 237 DIVWE_DIVWEO_DIVWEU_DIVWEUO_MODSD_MODUD_MODUW
  { 0, 0, 0, 0, 0 }, // 238 DIVD_DIVDO_DIVDU_DIVDUO
  { 0, 0, 0, 0, 0 }, // 239 DIVDE_DIVDEO_DIVDEU_DIVDEUO
  { 1, 436, 439, 3707, 3710 }, // 240 DIVWO_rec_DIVWUO_rec_DIVWU_rec_DIVW_rec
  { 0, 0, 0, 0, 0 }, // 241 DIVD_rec_DIVDO_rec_DIVDU_rec_DIVDUO_rec
  { 1, 436, 439, 3710, 3713 }, // 242 DIVWE_rec_DIVWEO_rec_DIVWEU_rec_DIVWEUO_rec
  { 0, 0, 0, 0, 0 }, // 243 DIVDE_rec_DIVDEO_rec_DIVDEU_rec_DIVDEUO_rec
  { 1, 432, 434, 3713, 3716 }, // 244 MTCRF_MTCRF8
  { 1, 432, 434, 3716, 3719 }, // 245 ADDC8O_rec_ADDC8_rec_ADDCO_rec_ADDC_rec_SUBFC8O_rec_SUBFC8_rec_SUBFCO_rec_SUBFC_rec
  { 1, 443, 445, 3719, 3722 }, // 246 FABSD_rec_FABSS_rec_FNABSD_rec_FNABSS_rec_FCPSGND_rec_FCPSGNS_rec_FNEGD_rec_FNEGS_rec_FMR_rec
  { 1, 434, 436, 3722, 3724 }, // 247 MCRFS
  { 1, 454, 456, 3724, 3725 }, // 248 MTFSF_MTFSF_rec_MTFSFI_MTFSFI_rec
  { 1, 454, 456, 3725, 3728 }, // 249 MTFSFb
  { 0, 0, 0, 0, 0 }, // 250 RLDCL_rec_RLDCR_rec
  { 0, 0, 0, 0, 0 }, // 251 RLDICL_rec_RLDICR_rec_RLDICL_32_rec_RLDIMI_rec
  { 1, 432, 434, 3728, 3731 }, // 252 RLWIMI8_rec_RLWIMI_rec
  { 1, 432, 434, 3731, 3734 }, // 253 RLWINM8_rec_RLWINM_rec_RLWNM8_rec_RLWNM_rec_SLW8_rec_SLW_rec_SRW8_rec_SRW_rec
  { 1, 432, 434, 3734, 3737 }, // 254 SRAWI_rec_SRAW_rec
  { 1, 454, 456, 3737, 3738 }, // 255 MFFS_MFFSCE_MFFSL_MFFS_rec
  { 1, 452, 454, 3738, 3740 }, // 256 MFCR_MFCR8
  { 0, 0, 0, 0, 0 }, // 257 EXTSWSLI_32_64_rec_SRADI_rec_EXTSWSLI_rec_RLDIC_rec
  { 0, 0, 0, 0, 0 }, // 258 SRAD_rec_SLD_rec_SRD_rec
  { 1, 441, 443, 3740, 3743 }, // 259 FDIV
  { 1, 441, 443, 3743, 3746 }, // 260 FDIV_rec
  { 0, 0, 0, 0, 0 }, // 261 XSSQRTDP
  { 0, 0, 0, 0, 0 }, // 262 FSQRT
  { 0, 0, 0, 0, 0 }, // 263 XVSQRTDP
  { 0, 0, 0, 0, 0 }, // 264 XVSQRTSP
  { 0, 0, 0, 0, 0 }, // 265 FSQRT_rec
  { 0, 0, 0, 0, 0 }, // 266 XSSQRTSP
  { 0, 0, 0, 0, 0 }, // 267 FSQRTS
  { 0, 0, 0, 0, 0 }, // 268 FSQRTS_rec
  { 1, 441, 443, 3746, 3749 }, // 269 XSDIVDP
  { 1, 445, 447, 3749, 3752 }, // 270 FDIVS
  { 1, 445, 447, 3752, 3755 }, // 271 FDIVS_rec
  { 1, 445, 447, 3755, 3758 }, // 272 XSDIVSP
  { 1, 445, 447, 3758, 3761 }, // 273 XVDIVSP
  { 1, 441, 443, 3761, 3764 }, // 274 XVDIVDP
  { 2, 449, 452, 3764, 3767 }, // 275 LFSU
  { 2, 449, 452, 3767, 3770 }, // 276 LFSUX
  { 2, 449, 452, 3770, 3773 }, // 277 STFDU_STFDUX_STFSU_STFSUX
  { 2, 449, 452, 3773, 3775 }, // 278 STBU_STBU8_STDU_STHU_STHU8_STWU_STWU8
  { 2, 449, 452, 3775, 3777 }, // 279 STBUX_STBUX8_STDUX_STHUX_STHUX8_STWUX_STWUX8
  { 2, 449, 452, 3777, 3779 }, // 280 LBZU_LBZU8
  { 2, 449, 452, 3779, 3781 }, // 281 LBZUX_LBZUX8
  { 0, 0, 0, 0, 0 }, // 282 LDU
  { 0, 0, 0, 0, 0 }, // 283 LDUX
  { 2, 449, 452, 3781, 3784 }, // 284 LFDU
  { 2, 449, 452, 3784, 3787 }, // 285 LFDUX
  { 0, 0, 0, 0, 0 }, // 286 VPMSUMB_VPMSUMD_VPMSUMH_VPMSUMW_VCIPHER_VCIPHERLAST_VNCIPHER_VNCIPHERLAST_VSBOX
  { 1, 434, 436, 3787, 3789 }, // 287 BCCCTR_BCCCTR8_BCCCTRL_BCCCTRL8_BCCL_BCCLA_BCCLR_BCCLRL_BCCTR_BCCTR8_BCCTR8n_BCCTRL_BCCTRL8_BCCTRL8n_BCCTRLn_BCCTRn_BDNZ_BDNZ8_BDNZA_BDNZAm_BDNZAp_BDNZm_BDNZp_BDZ_BDZ8_BDZA_BDZAm_BDZAp_BDZm_BDZp_BDNZL_BDNZLA_BDNZLAm_BDNZLAp_BDNZLR_BDNZLR8_BDNZLRL_BDNZLRLm_BDNZLRLp_BDNZLRm_BDNZLRp_BDNZLm_BDNZLp_BDZL_BDZLA_BDZLAm_BDZLAp_BDZLR_BDZLR8_BDZLRL_BDZLRLm_BDZLRLp_BDZLRm_BDZLRp_BDZLm_BDZLp_BL_BL_NOP_BL_TLS_BL8_BL8_NOP_BL8_NOP_TLS_BL8_TLS_BL8_TLS__BLA_BLA8_BLA8_NOP_BLR_BLR8_BLRL_TAILB_TAILB8_TAILBA_TAILBA8_TAILBCTR_TAILBCTR8_gBC_gBCA_gBCAat_gBCCTR_gBCCTRL_gBCL_gBCLA_gBCLAat_gBCLR_gBCLRL_gBCLat_gBCat_BCLR_BCLRL_BCLRLn_BCLRn_BCTR_BCTR8_BCTRL_BCTRL8_B_BA_BC_BCC_BCCA_BCL_BCLalways_BCLn_BCTRL8_LDinto_toc_BCTRL_LWZinto_toc_BCn_CTRL_DEP
  { 1, 434, 436, 3789, 3791 }, // 288 ADDPCIS
  { 1, 430, 432, 3791, 3793 }, // 289 LDAT_LWAT
  { 1, 430, 432, 3793, 3795 }, // 290 STDAT_STWAT
  { 1, 432, 434, 3795, 3798 }, // 291 BRINC
  { 0, 0, 0, 0, 0 }, // 292 EVABS_EVEQV_EVNAND_EVNEG_EVADDIW_EVADDW_EVAND_EVANDC_EVCMPEQ_EVCMPGTS_EVCMPGTU_EVCMPLTS_EVCMPLTU_EVCNTLSW_EVCNTLZW_EVEXTSB_EVEXTSH_EVMERGEHI_EVMERGEHILO_EVMERGELO_EVMERGELOHI_EVNOR_EVOR_EVORC_EVXOR_EVRLW_EVRLWI_EVRNDW_EVSLW_EVSLWI_EVSPLATFI_EVSPLATI_EVSRWIS_EVSRWIU_EVSRWS_EVSRWU_EVSUBFW_EVSUBIFW
  { 0, 0, 0, 0, 0 }, // 293 EVMRA_EVADDSMIAAW_EVADDSSIAAW_EVADDUMIAAW_EVADDUSIAAW_EVDIVWS_EVDIVWU_EVMHEGSMFAA_EVMHEGSMFAN_EVMHEGSMIAA_EVMHEGSMIAN_EVMHEGUMIAA_EVMHEGUMIAN_EVMHESMF_EVMHESMFA_EVMHESMFAAW_EVMHESMFANW_EVMHESMI_EVMHESMIA_EVMHESMIAAW_EVMHESMIANW_EVMHESSF_EVMHESSFA_EVMHESSFAAW_EVMHESSFANW_EVMHESSIAAW_EVMHESSIANW_EVMHEUMI_EVMHEUMIA_EVMHEUMIAAW_EVMHEUMIANW_EVMHEUSIAAW_EVMHEUSIANW_EVMHOGSMFAA_EVMHOGSMFAN_EVMHOGSMIAA_EVMHOGSMIAN_EVMHOGUMIAA_EVMHOGUMIAN_EVMHOSMF_EVMHOSMFA_EVMHOSMFAAW_EVMHOSMFANW_EVMHOSMI_EVMHOSMIA_EVMHOSMIAAW_EVMHOSMIANW_EVMHOSSF_EVMHOSSFA_EVMHOSSFAAW_EVMHOSSFANW_EVMHOSSIAAW_EVMHOSSIANW_EVMHOUMI_EVMHOUMIA_EVMHOUMIAAW_EVMHOUMIANW_EVMHOUSIAAW_EVMHOUSIANW_EVMWHSMF_EVMWHSMFA_EVMWHSMI_EVMWHSMIA_EVMWHSSF_EVMWHSSFA_EVMWHUMI_EVMWHUMIA_EVMWLSMIAAW_EVMWLSMIANW_EVMWLSSIAAW_EVMWLSSIANW_EVMWLUMI_EVMWLUMIA_EVMWLUMIAAW_EVMWLUMIANW_EVMWLUSIAAW_EVMWLUSIANW_EVMWSMF_EVMWSMFA_EVMWSMFAA_EVMWSMFAN_EVMWSMI_EVMWSMIA_EVMWSMIAA_EVMWSMIAN_EVMWSSF_EVMWSSFA_EVMWSSFAA_EVMWSSFAN_EVMWUMI_EVMWUMIA_EVMWUMIAA_EVMWUMIAN_EVSUBFSMIAAW_EVSUBFSSIAAW_EVSUBFUMIAAW_EVSUBFUSIAAW
  { 1, 430, 432, 3798, 3800 }, // 294 EVLDD_EVLDDX_EVLDH_EVLDHX_EVLDW_EVLDWX_EVLHHESPLAT_EVLHHESPLATX_EVLHHOSSPLAT_EVLHHOSSPLATX_EVLHHOUSPLAT_EVLHHOUSPLATX_EVLWHE_EVLWHEX_EVLWHOS_EVLWHOSX_EVLWHOU_EVLWHOUX_EVLWHSPLAT_EVLWHSPLATX_EVLWWSPLAT_EVLWWSPLATX
  { 1, 430, 432, 3800, 3802 }, // 295 EVSTDD_EVSTDDX_EVSTDH_EVSTDHX_EVSTDW_EVSTDWX_EVSTWHE_EVSTWHEX_EVSTWHO_EVSTWHOX_EVSTWWE_EVSTWWEX_EVSTWWO_EVSTWWOX
  { 1, 434, 436, 3802, 3804 }, // 296 HRFID_ATTN_CLRBHRB_MFBHRBE_NAP_RFCI_RFDI_RFMCI_SC
  { 0, 0, 0, 0, 0 }, // 297 RFI
  { 0, 0, 0, 0, 0 }, // 298 RFID
  { 1, 430, 432, 3804, 3806 }, // 299 DSS_DSSALL_DST_DST64_DSTST_DSTST64_DSTSTT_DSTSTT64_DSTT_DSTT64_ICBLQ_LBEPX_LHEPX_LWEPX_TLBIVAX_TLBLD_TLBLI_TLBRE_TLBRE2_TLBSX_TLBSX2_TLBSX2D_TLBWE_TLBWE2_MBAR_TRAP_DCCCI_ICCCI
  { 1, 430, 432, 3806, 3808 }, // 300 ICBLC_STBEPX_STHEPX_STWEPX
  { 1, 430, 432, 3808, 3811 }, // 301 LFDEPX
  { 1, 430, 432, 3811, 3814 }, // 302 STFDEPX
  { 1, 456, 458, 3814, 3816 }, // 303 MFSR_MFSRIN
  { 1, 460, 462, 3816, 3818 }, // 304 MTSR_MTSRIN
  { 1, 432, 434, 3818, 3820 }, // 305 MFDCR
  { 1, 432, 434, 3820, 3822 }, // 306 MTDCR
  { 1, 432, 434, 3822, 3825 }, // 307 NOP_GT_PWR6_NOP_GT_PWR7
  { 0, 0, 0, 0, 0 }, // 308 TLBIA
  { 1, 458, 460, 3825, 3827 }, // 309 WRTEE_WRTEEI
  { 1, 430, 432, 0, 0 }, // 310 MSYNC
  { 0, 0, 0, 0, 0 }, // 311 SLBSYNC
  { 0, 0, 0, 0, 0 }, // 312 SLBFEE_rec
  { 0, 0, 0, 0, 0 }, // 313 STOP
  { 1, 430, 432, 3827, 3829 }, // 314 DCBA_DCBI
  { 0, uint16_t(~0U), uint16_t(~0U), uint16_t(~0U), uint16_t(~0U) }// end marker
};

static const llvm::InstrItinerary PPCE5500Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 468, 470, 0, 0 }, // 1 IIC_LdStSync
  { 1, 470, 472, 3829, 3832 }, // 2 IIC_IntSimple
  { 1, 470, 472, 3832, 3835 }, // 3 IIC_IntGeneral
  { 1, 472, 474, 3835, 3837 }, // 4 IIC_BrB
  { 0, 0, 0, 0, 0 }, // 5 IIC_VecFP
  { 1, 470, 472, 3837, 3840 }, // 6 IIC_IntCompare
  { 0, 0, 0, 0, 0 }, // 7 IIC_SprABORT
  { 0, 0, 0, 0, 0 }, // 8 IIC_LdStCOPY
  { 0, 0, 0, 0, 0 }, // 9 IIC_LdStPASTE
  { 1, 472, 474, 3840, 3843 }, // 10 IIC_BrCR
  { 1, 468, 470, 3843, 3845 }, // 11 IIC_LdStLD
  { 1, 468, 470, 3845, 3847 }, // 12 IIC_LdStDCBF
  { 1, 468, 470, 3847, 3849 }, // 13 IIC_LdStLoad
  { 1, 474, 477, 3849, 3852 }, // 14 IIC_IntDivD
  { 1, 477, 480, 3852, 3855 }, // 15 IIC_IntDivW
  { 0, 0, 0, 0, 0 }, // 16 IIC_FPDGeneral
  { 1, 480, 482, 3855, 3858 }, // 17 IIC_FPAddSub
  { 1, 482, 484, 3858, 3861 }, // 18 IIC_FPDivD
  { 0, 0, 0, 0, 0 }, // 19 IIC_FPSGeneral
  { 1, 480, 482, 3861, 3864 }, // 20 IIC_FPCompare
  { 1, 480, 482, 3864, 3867 }, // 21 IIC_FPGeneral
  { 0, 0, 0, 0, 0 }, // 22 IIC_VecGeneral
  { 0, 0, 0, 0, 0 }, // 23 IIC_VecComplex
  { 1, 468, 470, 3867, 3869 }, // 24 IIC_LdStStore
  { 1, 470, 472, 3869, 3872 }, // 25 IIC_IntRotateDI
  { 1, 484, 486, 3872, 3875 }, // 26 IIC_FPDivS
  { 1, 480, 482, 3875, 3879 }, // 27 IIC_FPFused
  { 0, 0, 0, 0, 0 }, // 28 IIC_FPSqrtD
  { 0, 0, 0, 0, 0 }, // 29 IIC_FPSqrtS
  { 1, 468, 470, 3879, 3881 }, // 30 IIC_LdStICBI
  { 1, 470, 472, 3881, 3885 }, // 31 IIC_IntISEL
  { 0, 0, 0, 0, 0 }, // 32 IIC_SprISYNC
  { 1, 486, 488, 3885, 3888 }, // 33 IIC_LdStLWARX
  { 2, 488, 491, 3888, 3890 }, // 34 IIC_LdStLoadUpd
  { 2, 488, 491, 3890, 3892 }, // 35 IIC_LdStLoadUpdX
  { 1, 486, 488, 3892, 3894 }, // 36 IIC_LdStLDARX
  { 2, 488, 491, 3894, 3896 }, // 37 IIC_LdStLDU
  { 2, 488, 491, 3896, 3898 }, // 38 IIC_LdStLDUX
  { 2, 468, 470, 3898, 3901 }, // 39 IIC_LdStLFD
  { 2, 488, 491, 3901, 3904 }, // 40 IIC_LdStLFDU
  { 2, 488, 491, 3904, 3907 }, // 41 IIC_LdStLFDUX
  { 1, 468, 470, 3907, 3909 }, // 42 IIC_LdStLHA
  { 2, 488, 491, 3909, 3911 }, // 43 IIC_LdStLHAU
  { 2, 488, 491, 3911, 3913 }, // 44 IIC_LdStLHAUX
  { 1, 491, 493, 3913, 3915 }, // 45 IIC_LdStLMW
  { 0, 0, 0, 0, 0 }, // 46 IIC_LdStLWA
  { 1, 493, 496, 3915, 3918 }, // 47 IIC_IntMulHD
  { 1, 472, 474, 3918, 3920 }, // 48 IIC_BrMCR
  { 1, 496, 498, 3920, 3923 }, // 49 IIC_BrMCRX
  { 1, 498, 500, 3923, 3925 }, // 50 IIC_SprMFCR
  { 1, 496, 498, 3925, 3926 }, // 51 IIC_SprMFSPR
  { 1, 480, 482, 3926, 3927 }, // 52 IIC_IntMFFS
  { 0, 0, 0, 0, 0 }, // 53 IIC_SprMFMSR
  { 1, 498, 500, 3927, 3929 }, // 54 IIC_SprMFCRF
  { 1, 500, 502, 3929, 3931 }, // 55 IIC_SprMFPMR
  { 0, 0, 0, 0, 0 }, // 56 IIC_SprMFSR
  { 1, 500, 502, 3931, 3933 }, // 57 IIC_SprMFTB
  { 0, 0, 0, 0, 0 }, // 58 IIC_SprMSGSYNC
  { 1, 496, 498, 3933, 3934 }, // 59 IIC_SprMTSPR
  { 1, 502, 504, 3934, 3937 }, // 60 IIC_IntMTFSB0
  { 1, 504, 506, 3937, 3939 }, // 61 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 62 IIC_SprMTMSRD
  { 1, 496, 498, 3939, 3940 }, // 63 IIC_SprMTPMR
  { 0, 0, 0, 0, 0 }, // 64 IIC_SprMTSR
  { 1, 506, 509, 3940, 3943 }, // 65 IIC_IntMulHW
  { 1, 506, 509, 3943, 3946 }, // 66 IIC_IntMulHWU
  { 1, 493, 496, 3946, 3949 }, // 67 IIC_IntMulLI
  { 0, 0, 0, 0, 0 }, // 68 IIC_VecPerm
  { 1, 468, 470, 3949, 3952 }, // 69 IIC_LdStSTFD
  { 2, 488, 491, 3952, 3955 }, // 70 IIC_LdStSTFDU
  { 0, 0, 0, 0, 0 }, // 71 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 72 IIC_IntRFID
  { 1, 509, 511, 3955, 3958 }, // 73 IIC_IntRotateD
  { 1, 470, 472, 3958, 3961 }, // 74 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 75 IIC_SprSLBFEE
  { 0, 0, 0, 0, 0 }, // 76 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 77 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprSLBIEG
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprSLBMFEV
  { 0, 0, 0, 0, 0 }, // 81 IIC_SprSLBMTE
  { 0, 0, 0, 0, 0 }, // 82 IIC_SprSLBSYNC
  { 1, 509, 511, 3961, 3964 }, // 83 IIC_IntShift
  { 1, 468, 470, 3964, 3966 }, // 84 IIC_LdStSTWCX
  { 2, 488, 491, 3966, 3968 }, // 85 IIC_LdStSTU
  { 2, 488, 491, 3968, 3970 }, // 86 IIC_LdStSTUX
  { 1, 468, 470, 3970, 3972 }, // 87 IIC_LdStSTD
  { 1, 468, 470, 3972, 3974 }, // 88 IIC_LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 89 IIC_SprSTOP
  { 0, 0, 0, 0, 0 }, // 90 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 91 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 92 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 93 IIC_SprTLBIEL
  { 1, 511, 513, 0, 0 }, // 94 IIC_SprTLBSYNC
  { 1, 513, 515, 3974, 3976 }, // 95 IIC_IntTrapW
  { 0, 0, 0, 0, 0 }, // 96 IIC_VecFPCompare
  { 0, 0, 0, 0, 0 }, // 97 VADDUBM_VADDUDM_VADDUHM_VADDUWM_VEXTSB2D_VEXTSB2Ds_VEXTSB2W_VEXTSB2Ws_VEXTSH2D_VEXTSH2Ds_VEXTSH2W_VEXTSH2Ws_VEXTSW2D_VEXTSW2Ds_VSLD_VSRD_VSUBUBM_VSUBUDM_VSUBUHM_VSUBUWM_VPOPCNTB_VPOPCNTH_VSRAD_MTVSRDD_VEQV_VNAND_VNEGD_VNEGW_VORC_XXLAND_XXLANDC_XXLEQV_XXLEQVOnes_XXLNAND_XXLNOR_XXLOR_XXLORf_XXLORC_XXLXOR_XXLXORdpz_XXLXORspz_XXLXORz
  { 0, 0, 0, 0, 0 }, // 98 VAND_VANDC_V_SET0_V_SET0B_V_SET0H_VSLB_VSLH_VSLW_VSRB_VSRH_VSRW_VRLB_VRLD_VRLH_VRLW_VSRAB_VSRAH_VSRAW_XVABSDP_XVABSSP_XVNABSDP_XVNABSSP_XVCPSGNDP_XVCPSGNSP_XVIEXPDP_XVIEXPSP_XVXEXPDP_XVXEXPSP_VRLDMI_VRLDNM_VRLWMI_VRLWNM_VMRGEW_VMRGOW_VNOR_VOR_VSEL_VXOR_XVNEGDP_XVNEGSP_XSABSQP_XSCPSGNQP_XSIEXPQP_XSNABSQP_XSNEGQP_XSXEXPQP
  { 0, 0, 0, 0, 0 }, // 99 XXSEL
  { 1, 496, 498, 3976, 3977 }, // 100 TABORTDC_TABORTDCI_TABORTWC_TABORTWCI
  { 1, 502, 504, 3977, 3980 }, // 101 MTFSB0_MTFSB1
  { 1, 480, 482, 3980, 3981 }, // 102 MFFSCDRN_MFFSCDRNI_MFFSCRN_MFFSCRNI
  { 1, 470, 472, 3981, 3984 }, // 103 CMPRB_CMPRB8_CMPEQB
  { 0, 0, 0, 0, 0 }, // 104 TD_TDI
  { 1, 513, 515, 3984, 3986 }, // 105 TW_TWI
  { 1, 480, 482, 3986, 3989 }, // 106 FCMPUD_FCMPUS_FTDIV_FTSQRT
  { 0, 0, 0, 0, 0 }, // 107 XSTSTDCDP_XSTSTDCSP
  { 0, 0, 0, 0, 0 }, // 108 XSMAXCDP_XSMAXDP_XSMAXJDP_XSMINCDP_XSMINDP_XSMINJDP_XSXSIGDP_XSCVSPDPN
  { 1, 480, 482, 3989, 3992 }, // 109 XSCMPEQDP_XSCMPEXPDP_XSCMPGEDP_XSCMPGTDP_XSCMPODP_XSCMPUDP_XSTDIVDP_XSTSQRTDP
  { 1, 470, 472, 3992, 3995 }, // 110 CNTLZD_CNTLZD_rec_CNTLZW_CNTLZW8_CNTLZW8_rec_CNTLZW_rec_CNTTZD_CNTTZD_rec_CNTTZW_CNTTZW8_CNTTZW8_rec_CNTTZW_rec_POPCNTD_POPCNTW_CMPB_CMPB8_SETB_SETB8_BPERMD
  { 1, 509, 511, 3995, 3998 }, // 111 SLD_SRD_SRAD
  { 1, 470, 472, 3998, 4001 }, // 112 SRADI_EXTSWSLI_32_64_EXTSWSLI_SRADI_32_RLDIC
  { 0, 0, 0, 0, 0 }, // 113 MFVRD_MFVSRD_MTVRD_MTVSRD_MTVRWA_MTVRWZ_MTVSRWA_MTVSRWZ_MFVSRWZ_MFVRWZ
  { 1, 470, 472, 4001, 4004 }, // 114 CMPLW_CMPLWI_CMPW_CMPWI_CMPD_CMPDI_CMPLD_CMPLDI
  { 1, 470, 472, 4004, 4007 }, // 115 SUBFC_SUBFC8_SUBFC8O_SUBFCO_SUBFIC_SUBFIC8_ANDI8_rec_ANDIS8_rec_ANDIS_rec_ANDI_rec_ADDC_ADDC8_ADDC8O_ADDCO_ADDIC_ADDIC8_ADDIC_rec_ADDE_ADDE8_ADDE8O_ADDE8O_rec_ADDE8_rec_ADDEO_ADDEO_rec_ADDE_rec_ADDME_ADDME8_ADDME8O_ADDME8O_rec_ADDME8_rec_ADDMEO_ADDMEO_rec_ADDME_rec_ADDZE_ADDZE8_ADDZE8O_ADDZE8O_rec_ADDZE8_rec_ADDZEO_ADDZEO_rec_ADDZE_rec_SUBF_SUBF8_SUBF8O_SUBF8O_rec_SUBF8_rec_SUBFE_SUBFE8_SUBFE8O_SUBFE8O_rec_SUBFE8_rec_SUBFEO_SUBFEO_rec_SUBFE_rec_SUBFME_SUBFME8_SUBFME8O_SUBFME8O_rec_SUBFME8_rec_SUBFMEO_SUBFMEO_rec_SUBFME_rec_SUBFO_SUBFO_rec_SUBFZE_SUBFZE8_SUBFZE8O_SUBFZE8O_rec_SUBFZE8_rec_SUBFZEO_SUBFZEO_rec_SUBFZE_rec_SUBF_rec_POPCNTB_LA
  { 1, 470, 472, 4007, 4010 }, // 116 ADD4_ADD4O_ADD4O_rec_ADD4_rec_ADD8_ADD8O_ADD8O_rec_ADD8_rec_NEG_NEG8_NEG8O_NEG8O_rec_NEG8_rec_NEGO_NEGO_rec_NEG_rec_ADDI_ADDI8_ADDIS_ADDIS8_LI_LI8_LIS_LIS8_OR_OR8_OR8_rec_ORI_ORI8_ORIS_ORIS8_OR_rec_XOR_XOR8_XOR8_rec_XORI_XORI8_XORIS_XORIS8_XOR_rec_NAND_NAND8_NAND8_rec_NAND_rec_AND_AND8_AND8_rec_ANDC_ANDC8_ANDC8_rec_ANDC_rec_AND_rec_NOR_NOR8_NOR8_rec_NOR_rec_ORC_ORC8_ORC8_rec_ORC_rec_EQV_EQV8_EQV8_rec_EQV_rec_EXTSB_EXTSB8_EXTSB8_32_64_EXTSB8_rec_EXTSB_rec_EXTSH_EXTSH8_EXTSH8_32_64_EXTSH8_rec_EXTSH_rec_EXTSW_EXTSW_32_EXTSW_32_64_EXTSW_32_64_rec_EXTSW_rec_ADD4TLS_ADD8TLS_ADD8TLS__NOP
  { 0, 0, 0, 0, 0 }, // 117 ADDIStocHA_ADDIStocHA8_ADDItocL_COPY
  { 1, 472, 474, 4010, 4012 }, // 118 MCRF
  { 1, 496, 498, 4012, 4015 }, // 119 MCRXRX
  { 0, 0, 0, 0, 0 }, // 120 XSNABSDP_XSXEXPDP_XSABSDP_XSNEGDP_XSCPSGNDP
  { 1, 472, 474, 4015, 4017 }, // 121 RFEBB
  { 1, 496, 498, 4017, 4018 }, // 122 TBEGIN_TRECHKPT
  { 1, 468, 470, 4018, 4020 }, // 123 WAIT
  { 1, 509, 511, 4020, 4023 }, // 124 RLDCL_RLDCR
  { 1, 470, 472, 4023, 4026 }, // 125 RLWIMI_RLWIMI8
  { 1, 470, 472, 4026, 4029 }, // 126 RLDICL_RLDICL_32_RLDICL_32_64_RLDICR_RLDICR_32_RLDIMI
  { 1, 498, 500, 4029, 4031 }, // 127 MFOCRF_MFOCRF8
  { 1, 496, 498, 4031, 4034 }, // 128 MTOCRF_MTOCRF8
  { 1, 472, 474, 4034, 4037 }, // 129 CR6SET_CR6UNSET_CRSET_CRUNSET_CRAND_CRANDC_CRNAND_CRNOR_CROR_CRORC_CREQV_CRXOR
  { 1, 470, 472, 4037, 4040 }, // 130 SLW_SLW8_SRW_SRW8_RLWINM_RLWINM8_RLWNM_RLWNM8
  { 1, 480, 482, 4040, 4043 }, // 131 FABSD_FABSS_FNABSD_FNABSS_FNEGD_FNEGS_FCPSGND_FCPSGNS_FMR
  { 1, 509, 511, 4043, 4046 }, // 132 SRAW_SRAWI
  { 1, 470, 472, 4046, 4050 }, // 133 ISEL_ISEL8
  { 0, 0, 0, 0, 0 }, // 134 XSIEXPDP
  { 1, 496, 498, 4050, 4051 }, // 135 TRECLAIM_TSR_TABORT
  { 1, 468, 470, 4051, 4053 }, // 136 MFVSCR
  { 1, 468, 470, 4053, 4055 }, // 137 MTVSCR
  { 0, 0, 0, 0, 0 }, // 138 VCMPNEZB_VCMPNEZH_VCMPNEZW_VCMPEQUB_VCMPEQUD_VCMPEQUH_VCMPEQUW_VCMPNEB_VCMPNEH_VCMPNEW_VCMPEQFP_VCMPEQFP_rec_VCMPGEFP_VCMPGEFP_rec_VCMPGTFP_VCMPGTFP_rec_VCMPBFP_VCMPBFP_rec_VCMPGTSB_VCMPGTSB_rec_VCMPGTSD_VCMPGTSD_rec_VCMPGTSH_VCMPGTSH_rec_VCMPGTSW_VCMPGTSW_rec_VCMPGTUB_VCMPGTUB_rec_VCMPGTUD_VCMPGTUD_rec_VCMPGTUH_VCMPGTUH_rec_VCMPGTUW_VCMPGTUW_rec_VCMPNEB_rec_VCMPNEH_rec_VCMPNEW_rec_VCMPNEZB_rec_VCMPNEZH_rec_VCMPNEZW_rec_VCMPEQUB_rec_VCMPEQUD_rec_VCMPEQUH_rec_VCMPEQUW_rec_XVCMPEQDP_XVCMPEQDP_rec_XVCMPEQSP_XVCMPEQSP_rec_XVCMPGEDP_XVCMPGEDP_rec_XVCMPGESP_XVCMPGESP_rec_XVCMPGTDP_XVCMPGTDP_rec_XVCMPGTSP_XVCMPGTSP_rec
  { 0, 0, 0, 0, 0 }, // 139 VABSDUB_VABSDUH_VABSDUW_VCLZB_VCLZD_VCLZH_VCLZW_VCTZB_VCTZD_VCTZH_VCTZW_VPOPCNTW_VPOPCNTD_VPRTYBD_VPRTYBW
  { 0, 0, 0, 0, 0 }, // 140 VADDUBS_VADDUHS_VADDUWS_VAVGSB_VAVGSH_VAVGSW_VAVGUB_VAVGUH_VAVGUW_VADDSBS_VADDSHS_VADDSWS_VMAXFP_VMINFP_VMAXSB_VMAXSD_VMAXSH_VMAXSW_VMAXUB_VMAXUD_VMAXUH_VMAXUW_VMINSB_VMINSD_VMINSH_VMINSW_VMINUB_VMINUD_VMINUH_VMINUW_VBPERMD_VADDCUW_VSHASIGMAD_VSHASIGMAW_VSUBSBS_VSUBSHS_VSUBSWS_VSUBUBS_VSUBUHS_VSUBUWS_VSUBCUW_XVMAXDP_XVMAXSP_XVMINDP_XVMINSP_XVTSTDCDP_XVTSTDCSP_XVXSIGDP_XVXSIGSP
  { 1, 480, 482, 4055, 4058 }, // 141 XVTDIVDP_XVTDIVSP_XVTSQRTDP_XVTSQRTSP
  { 0, 0, 0, 0, 0 }, // 142 VADDFP_VCTSXS_VCTSXS_0_VCTUXS_VCTUXS_0_VEXPTEFP_VLOGEFP_VMADDFP_VMHADDSHS_VNMSUBFP_VREFP_VRFIM_VRFIN_VRFIP_VRFIZ_VRSQRTEFP_XVADDDP_XVADDSP_XVCVDPSP_XVCVDPSXDS_XVCVDPSXWS_XVCVDPUXDS_XVCVDPUXWS_XVCVHPSP_XVCVSPDP_XVCVSPHP_XVCVSPSXDS_XVCVSPSXWS_XVCVSPUXDS_XVCVSPUXWS_XVCVSXDDP_XVCVSXDSP_XVCVSXWDP_XVCVSXWSP_XVCVUXDDP_XVCVUXDSP_XVCVUXWDP_XVCVUXWSP_XVMADDADP_XVMADDASP_XVMADDMDP_XVMADDMSP_XVMSUBADP_XVMSUBASP_XVMSUBMDP_XVMSUBMSP_XVMULDP_XVMULSP_XVNMADDADP_XVNMADDASP_XVNMADDMDP_XVNMADDMSP_XVNMSUBADP_XVNMSUBASP_XVNMSUBMDP_XVNMSUBMSP_XVRDPI_XVRDPIC_XVRDPIM_XVRDPIP_XVRDPIZ_XVREDP_XVRESP_XVRSPI_XVRSPIC_XVRSPIM_XVRSPIP_XVRSPIZ_XVRSQRTEDP_XVRSQRTESP_XVSUBDP_XVSUBSP_VCFSX_VCFSX_0_VCFUX_VCFUX_0_VMHRADDSHS_VMLADDUHM_VMSUMMBM_VMSUMSHM_VMSUMSHS_VMSUMUBM_VMSUMUHM_VMSUMUDM_VMSUMUHS_VMULESB_VMULESH_VMULESW_VMULEUB_VMULEUH_VMULEUW_VMULOSB_VMULOSH_VMULOSW_VMULOUB_VMULOUH_VMULOUW_VSUM2SWS_VSUM4SBS_VSUM4SHS_VSUM4UBS_VSUMSWS
  { 0, 0, 0, 0, 0 }, // 143 VSUBFP_VMULUWM
  { 1, 493, 496, 4058, 4061 }, // 144 MADDHD_MADDHDU_MADDLD_MADDLD8_MULLD_MULLDO
  { 1, 506, 509, 4061, 4064 }, // 145 MULHD_MULHW_MULLW_MULLWO
  { 1, 506, 509, 4064, 4067 }, // 146 MULHDU_MULHWU
  { 1, 493, 496, 4067, 4070 }, // 147 MULLI_MULLI8
  { 1, 480, 482, 4070, 4073 }, // 148 FRSP_FRIMD_FRIMS_FRIND_FRINS_FRIPD_FRIPS_FRIZD_FRIZS_FRE_FRES_FADDS_FMSUBS_FMADDS_FSUBS_FCFID_FCFIDS_FCFIDU_FCFIDUS_FCTID_FCTIDU_FCTIDUZ_FCTIDZ_FCTIW_FCTIWU_FCTIWUZ_FCTIWZ_FRSQRTE_FRSQRTES_FNMADDS_FNMSUBS_FSELD_FSELS_FMULS
  { 1, 480, 482, 4073, 4076 }, // 149 FADD_FSUB
  { 1, 480, 482, 4076, 4080 }, // 150 FMSUB_FMADD_FNMADD_FNMSUB_FMUL
  { 0, 0, 0, 0, 0 }, // 151 XSMADDADP_XSMADDASP_XSMADDMDP_XSMADDMSP_XSMSUBADP_XSMSUBASP_XSMSUBMDP_XSMSUBMSP_XSMULDP_XSMULSP_XSNMADDADP_XSNMADDASP_XSNMADDMDP_XSNMADDMSP_XSNMSUBADP_XSNMSUBASP_XSNMSUBMDP_XSNMSUBMSP
  { 1, 480, 482, 4080, 4083 }, // 152 FSELD_rec_FSELS_rec
  { 1, 506, 509, 4083, 4086 }, // 153 MULHDU_rec_MULHWU_rec
  { 1, 506, 509, 4086, 4089 }, // 154 MULHD_rec_MULHW_rec_MULLWO_rec_MULLW_rec
  { 1, 493, 496, 4089, 4092 }, // 155 MULLDO_rec_MULLD_rec
  { 1, 480, 482, 4092, 4095 }, // 156 FRIMD_rec_FRIMS_rec_FRIND_rec_FRINS_rec_FRIPD_rec_FRIPS_rec_FRIZD_rec_FRIZS_rec_FRES_rec_FRE_rec_FADDS_rec_FSUBS_rec_FMSUBS_rec_FNMSUBS_rec_FMADDS_rec_FNMADDS_rec_FCFIDS_rec_FCFIDUS_rec_FCFIDU_rec_FCFID_rec_FCTIDUZ_rec_FCTIDU_rec_FCTIDZ_rec_FCTID_rec_FCTIWUZ_rec_FCTIWU_rec_FCTIWZ_rec_FCTIW_rec_FMULS_rec_FRSQRTES_rec_FRSQRTE_rec_FRSP_rec
  { 1, 480, 482, 4095, 4098 }, // 157 FADD_rec_FSUB_rec
  { 1, 480, 482, 4098, 4102 }, // 158 FMSUB_rec_FNMSUB_rec_FMADD_rec_FNMADD_rec_FMUL_rec
  { 0, 0, 0, 0, 0 }, // 159 XSADDDP_XSADDSP_XSCVDPHP_XSCVDPSP_XSCVDPSXDS_XSCVDPSXDSs_XSCVDPSXWS_XSCVDPUXDS_XSCVDPUXDSs_XSCVDPUXWS_XSCVDPSXWSs_XSCVDPUXWSs_XSCVHPDP_XSCVSPDP_XSCVSXDDP_XSCVSXDSP_XSCVUXDDP_XSCVUXDSP_XSRDPI_XSRDPIC_XSRDPIM_XSRDPIP_XSRDPIZ_XSREDP_XSRESP_XSRSQRTEDP_XSRSQRTESP_XSSUBDP_XSSUBSP_XSCVDPSPN_XSRSP
  { 1, 468, 470, 4102, 4104 }, // 160 LVSL_LVSR
  { 0, 0, 0, 0, 0 }, // 161 VSPLTISB_VSPLTISH_VSPLTISW_VSPLTB_VSPLTBs_VSPLTH_VSPLTHs_VSPLTW_XXMRGHW_XXMRGLW_XXPERM_XXPERMR_XXSLDWI_XXSLDWIs_XXSPLTIB_XXSPLTW_XXSPLTWs_XXPERMDI_XXPERMDIs
  { 0, 0, 0, 0, 0 }, // 162 V_SETALLONES_V_SETALLONESB_V_SETALLONESH_VBPERMQ_VGBBD_VMRGHB_VMRGHH_VMRGHW_VMRGLB_VMRGLH_VMRGLW_VPERM_VPERMR_VPERMXOR_VPKPX_VPKSDSS_VPKSDUS_VPKSHSS_VPKSHUS_VPKSWSS_VPKSWUS_VPKUDUM_VPKUDUS_VPKUHUM_VPKUHUS_VPKUWUM_VPKUWUS_VSL_VSLDOI_VSLO_VSLV_VSR_VSRO_VSRV_VUPKHPX_VUPKHSB_VUPKHSH_VUPKHSW_VUPKLPX_VUPKLSB_VUPKLSH_VUPKLSW_XXBRD_XXBRH_XXBRQ_XXBRW_XXEXTRACTUW_XXINSERTW_VADDCUQ_VADDECUQ_VADDEUQM_VMUL10CUQ_VMUL10ECUQ_VMUL10EUQ_VMUL10UQ_VSUBCUQ_VSUBECUQ_VSUBEUQM_XSTSTDCQP_XSXSIGQP_BCDCFN_rec_BCDCFZ_rec_BCDCPSGN_rec_BCDCTN_rec_BCDCTZ_rec_BCDSETSGN_rec_BCDS_rec_BCDTRUNC_rec_BCDUS_rec_BCDUTRUNC_rec
  { 0, 0, 0, 0, 0 }, // 163 VEXTRACTUB_VEXTRACTUH_VEXTRACTUW_VINSERTB_VINSERTD_VINSERTH_VINSERTW_MFVSRLD_MTVSRWS_VCLZLSBB_VCTZLSBB_VEXTRACTD_VEXTUBLX_VEXTUBRX_VEXTUHLX_VEXTUHRX_VEXTUWLX_VEXTUWRX_VPRTYBQ_VADDUQM_VSUBUQM
  { 1, 480, 482, 4104, 4107 }, // 164 XSCMPEXPQP_XSCMPOQP_XSCMPUQP
  { 0, 0, 0, 0, 0 }, // 165 BCDSR_rec_XSADDQP_XSADDQPO_XSCVDPQP_XSCVQPDP_XSCVQPDPO_XSCVQPSDZ_XSCVQPSWZ_XSCVQPUDZ_XSCVQPUWZ_XSCVSDQP_XSCVUDQP_XSRQPI_XSRQPIX_XSRQPXP_XSSUBQP_XSSUBQPO
  { 0, 0, 0, 0, 0 }, // 166 BCDCTSQ_rec
  { 0, 0, 0, 0, 0 }, // 167 XSMADDQP_XSMADDQPO_XSMSUBQP_XSMSUBQPO_XSMULQP_XSMULQPO_XSNMADDQP_XSNMADDQPO_XSNMSUBQP_XSNMSUBQPO
  { 0, 0, 0, 0, 0 }, // 168 BCDCFSQ_rec
  { 0, 0, 0, 0, 0 }, // 169 XSDIVQP_XSDIVQPO
  { 0, 0, 0, 0, 0 }, // 170 XSSQRTQP_XSSQRTQPO
  { 1, 468, 470, 4107, 4109 }, // 171 LXVL_LXVLL
  { 1, 468, 470, 4109, 4111 }, // 172 LVEBX_LVEHX_LVEWX_LVX_LVXL
  { 2, 468, 470, 4111, 4114 }, // 173 LXSIBZX_LXSIHZX_LXSDX_LXVB16X_LXVD2X_LXVWSX_LXSIWZX_LXV_LXVX_LXSD
  { 0, 0, 0, 0, 0 }, // 174 DFLOADf64_XFLOADf64_LIWZX
  { 1, 468, 470, 4114, 4116 }, // 175 DCBF_DCBFEP_DCBST_DCBSTEP_DCBT_DCBTEP_DCBZ_DCBZEP_DCBZL_DCBZLEP_DCBTST_DCBTSTEP
  { 0, 0, 0, 0, 0 }, // 176 CP_COPY_CP_COPY8
  { 0, 0, 0, 0, 0 }, // 177 CP_PASTE_CP_PASTE8
  { 1, 468, 470, 4116, 4118 }, // 178 ICBI_ICBIEP
  { 1, 468, 470, 4118, 4120 }, // 179 ICBT_ICBTLS_LBZ_LBZ8_LBZCIX_LBZX_LBZX8_LBZXTLS_LBZXTLS__LBZXTLS_32_LDBRX_LDCIX_LHBRX_LHBRX8_LHZ_LHZ8_LHZCIX_LHZX_LHZX8_LHZXTLS_LHZXTLS__LHZXTLS_32_LWBRX_LWBRX8_LWZ_LWZ8_LWZCIX_LWZX_LWZX8_LWZXTLS_LWZXTLS__LWZXTLS_32_EnforceIEIO_LSWI
  { 1, 486, 488, 4120, 4123 }, // 180 LBARX_LBARXL_LHARX_LHARXL_LWARX_LWARXL
  { 1, 468, 470, 4123, 4125 }, // 181 LD_LDX_LDXTLS_LDXTLS__DARN
  { 1, 486, 488, 4125, 4127 }, // 182 LDARX_LDARXL
  { 0, 0, 0, 0, 0 }, // 183 CP_ABORT
  { 0, 0, 0, 0, 0 }, // 184 ISYNC
  { 0, 0, 0, 0, 0 }, // 185 MSGSYNC
  { 1, 511, 513, 0, 0 }, // 186 TLBSYNC
  { 1, 468, 470, 0, 0 }, // 187 SYNC
  { 1, 491, 493, 4127, 4129 }, // 188 LMW
  { 2, 468, 470, 4129, 4132 }, // 189 LFIWZX_LFDX_LFD
  { 0, 0, 0, 0, 0 }, // 190 SLBIA
  { 0, 0, 0, 0, 0 }, // 191 SLBIE
  { 0, 0, 0, 0, 0 }, // 192 SLBMFEE
  { 0, 0, 0, 0, 0 }, // 193 SLBMFEV
  { 0, 0, 0, 0, 0 }, // 194 SLBMTE
  { 0, 0, 0, 0, 0 }, // 195 TLBIEL
  { 2, 488, 491, 4132, 4134 }, // 196 LHZU_LHZU8_LWZU_LWZU8
  { 2, 488, 491, 4134, 4136 }, // 197 LHZUX_LHZUX8_LWZUX_LWZUX8
  { 1, 496, 498, 4136, 4137 }, // 198 TEND
  { 1, 468, 470, 4137, 4139 }, // 199 STBCX_STHCX_STWCX
  { 1, 468, 470, 4139, 4141 }, // 200 STDCX
  { 1, 468, 470, 4141, 4143 }, // 201 LDMX
  { 1, 468, 470, 4143, 4145 }, // 202 LHA_LHA8_LHAX_LHAX8_LWAX_LWAX_32
  { 0, 0, 0, 0, 0 }, // 203 CP_PASTE8_rec_CP_PASTE_rec
  { 0, 0, 0, 0, 0 }, // 204 LWA_LWA_32
  { 1, 496, 498, 4145, 4146 }, // 205 TCHECK
  { 2, 468, 470, 4146, 4149 }, // 206 LFIWAX
  { 2, 468, 470, 4149, 4152 }, // 207 LXSIWAX
  { 0, 0, 0, 0, 0 }, // 208 LIWAX
  { 2, 468, 470, 4152, 4155 }, // 209 LFSX_LFS
  { 2, 468, 470, 4155, 4158 }, // 210 LXSSP_LXSSPX
  { 0, 0, 0, 0, 0 }, // 211 XFLOADf32_DFLOADf32
  { 2, 488, 491, 4158, 4160 }, // 212 LHAU_LHAU8
  { 2, 488, 491, 4160, 4162 }, // 213 LHAUX_LHAUX8_LWAUX
  { 2, 468, 470, 4162, 4165 }, // 214 LXVH8X_LXVDSX_LXVW4X
  { 1, 468, 470, 4165, 4168 }, // 215 STFD_STFDX_STFIWX_STFS_STFSX_STXSD_STXSDX_STXSIBX_STXSIBXv_STXSIHX_STXSIHXv_STXSIWX_STXSSP_STXSSPX
  { 1, 468, 470, 4168, 4170 }, // 216 STW_STW8_STDBRX_STHBRX_STWBRX_STB_STB8_STH_STH8_STBX_STBX8_STBXTLS_STBXTLS__STBXTLS_32_STHX_STHX8_STHXTLS_STHXTLS__STHXTLS_32_STWX_STWX8_STWXTLS_STWXTLS__STWXTLS_32
  { 0, 0, 0, 0, 0 }, // 217 DFSTOREf32_DFSTOREf64_XFSTOREf32_XFSTOREf64_STIWX
  { 1, 468, 470, 4170, 4172 }, // 218 STD_STDX_STDXTLS_STDXTLS_
  { 1, 468, 470, 4172, 4174 }, // 219 STBCIX_STDCIX_STHCIX_STWCIX_STSWI
  { 0, 0, 0, 0, 0 }, // 220 SLBIEG
  { 1, 491, 493, 4174, 4176 }, // 221 STMW
  { 0, 0, 0, 0, 0 }, // 222 TLBIE
  { 1, 468, 470, 4176, 4178 }, // 223 STVEBX_STVEHX_STVEWX_STVX_STVXL
  { 1, 468, 470, 4178, 4181 }, // 224 STXV_STXVB16X_STXVD2X_STXVH8X_STXVW4X_STXVX
  { 1, 468, 470, 4181, 4183 }, // 225 STXVL_STXVLL
  { 1, 496, 498, 4183, 4184 }, // 226 MTCTR_MTCTR8_MTCTR8loop_MTCTRloop_MTLR_MTLR8
  { 1, 470, 472, 4184, 4187 }, // 227 MFVRSAVE_MFVRSAVEv_MTVRSAVE_MTVRSAVEv
  { 1, 500, 502, 4187, 4189 }, // 228 MFPMR
  { 1, 496, 498, 4189, 4190 }, // 229 MTPMR
  { 1, 500, 502, 4190, 4192 }, // 230 MFTB_MFTB8
  { 1, 496, 498, 4192, 4193 }, // 231 MFCTR_MFCTR8_MFLR_MFLR8_MFSPR_MFSPR8
  { 0, 0, 0, 0, 0 }, // 232 MFMSR
  { 1, 504, 506, 4193, 4195 }, // 233 MTMSR
  { 0, 0, 0, 0, 0 }, // 234 MTMSRD
  { 1, 496, 498, 4195, 4196 }, // 235 MTSPR_MTSPR8
  { 1, 477, 480, 4196, 4199 }, // 236 DIVW_DIVWO_DIVWU_DIVWUO_MODSW
  { 1, 477, 480, 4199, 4202 }, // 237 DIVWE_DIVWEO_DIVWEU_DIVWEUO_MODSD_MODUD_MODUW
  { 1, 474, 477, 4202, 4205 }, // 238 DIVD_DIVDO_DIVDU_DIVDUO
  { 1, 474, 477, 4205, 4208 }, // 239 DIVDE_DIVDEO_DIVDEU_DIVDEUO
  { 1, 477, 480, 4208, 4211 }, // 240 DIVWO_rec_DIVWUO_rec_DIVWU_rec_DIVW_rec
  { 1, 474, 477, 4211, 4214 }, // 241 DIVD_rec_DIVDO_rec_DIVDU_rec_DIVDUO_rec
  { 1, 477, 480, 4214, 4217 }, // 242 DIVWE_rec_DIVWEO_rec_DIVWEU_rec_DIVWEUO_rec
  { 1, 474, 477, 4217, 4220 }, // 243 DIVDE_rec_DIVDEO_rec_DIVDEU_rec_DIVDEUO_rec
  { 1, 496, 498, 4220, 4223 }, // 244 MTCRF_MTCRF8
  { 1, 470, 472, 4223, 4226 }, // 245 ADDC8O_rec_ADDC8_rec_ADDCO_rec_ADDC_rec_SUBFC8O_rec_SUBFC8_rec_SUBFCO_rec_SUBFC_rec
  { 1, 480, 482, 4226, 4229 }, // 246 FABSD_rec_FABSS_rec_FNABSD_rec_FNABSS_rec_FCPSGND_rec_FCPSGNS_rec_FNEGD_rec_FNEGS_rec_FMR_rec
  { 1, 472, 474, 4229, 4231 }, // 247 MCRFS
  { 1, 480, 482, 4231, 4232 }, // 248 MTFSF_MTFSF_rec_MTFSFI_MTFSFI_rec
  { 1, 502, 504, 4232, 4235 }, // 249 MTFSFb
  { 1, 509, 511, 4235, 4238 }, // 250 RLDCL_rec_RLDCR_rec
  { 1, 470, 472, 4238, 4241 }, // 251 RLDICL_rec_RLDICR_rec_RLDICL_32_rec_RLDIMI_rec
  { 1, 470, 472, 4241, 4244 }, // 252 RLWIMI8_rec_RLWIMI_rec
  { 1, 470, 472, 4244, 4247 }, // 253 RLWINM8_rec_RLWINM_rec_RLWNM8_rec_RLWNM_rec_SLW8_rec_SLW_rec_SRW8_rec_SRW_rec
  { 1, 509, 511, 4247, 4250 }, // 254 SRAWI_rec_SRAW_rec
  { 1, 480, 482, 4250, 4251 }, // 255 MFFS_MFFSCE_MFFSL_MFFS_rec
  { 1, 498, 500, 4251, 4253 }, // 256 MFCR_MFCR8
  { 1, 470, 472, 4253, 4256 }, // 257 EXTSWSLI_32_64_rec_SRADI_rec_EXTSWSLI_rec_RLDIC_rec
  { 1, 509, 511, 4256, 4259 }, // 258 SRAD_rec_SLD_rec_SRD_rec
  { 1, 482, 484, 4259, 4262 }, // 259 FDIV
  { 1, 482, 484, 4262, 4265 }, // 260 FDIV_rec
  { 0, 0, 0, 0, 0 }, // 261 XSSQRTDP
  { 0, 0, 0, 0, 0 }, // 262 FSQRT
  { 0, 0, 0, 0, 0 }, // 263 XVSQRTDP
  { 0, 0, 0, 0, 0 }, // 264 XVSQRTSP
  { 0, 0, 0, 0, 0 }, // 265 FSQRT_rec
  { 0, 0, 0, 0, 0 }, // 266 XSSQRTSP
  { 0, 0, 0, 0, 0 }, // 267 FSQRTS
  { 0, 0, 0, 0, 0 }, // 268 FSQRTS_rec
  { 1, 482, 484, 4265, 4268 }, // 269 XSDIVDP
  { 1, 484, 486, 4268, 4271 }, // 270 FDIVS
  { 1, 484, 486, 4271, 4274 }, // 271 FDIVS_rec
  { 1, 484, 486, 4274, 4277 }, // 272 XSDIVSP
  { 1, 484, 486, 4277, 4280 }, // 273 XVDIVSP
  { 1, 482, 484, 4280, 4283 }, // 274 XVDIVDP
  { 2, 488, 491, 4283, 4286 }, // 275 LFSU
  { 2, 488, 491, 4286, 4289 }, // 276 LFSUX
  { 2, 488, 491, 4289, 4292 }, // 277 STFDU_STFDUX_STFSU_STFSUX
  { 2, 488, 491, 4292, 4294 }, // 278 STBU_STBU8_STDU_STHU_STHU8_STWU_STWU8
  { 2, 488, 491, 4294, 4296 }, // 279 STBUX_STBUX8_STDUX_STHUX_STHUX8_STWUX_STWUX8
  { 2, 488, 491, 4296, 4298 }, // 280 LBZU_LBZU8
  { 2, 488, 491, 4298, 4300 }, // 281 LBZUX_LBZUX8
  { 2, 488, 491, 4300, 4302 }, // 282 LDU
  { 2, 488, 491, 4302, 4304 }, // 283 LDUX
  { 2, 488, 491, 4304, 4307 }, // 284 LFDU
  { 2, 488, 491, 4307, 4310 }, // 285 LFDUX
  { 0, 0, 0, 0, 0 }, // 286 VPMSUMB_VPMSUMD_VPMSUMH_VPMSUMW_VCIPHER_VCIPHERLAST_VNCIPHER_VNCIPHERLAST_VSBOX
  { 1, 472, 474, 4310, 4312 }, // 287 BCCCTR_BCCCTR8_BCCCTRL_BCCCTRL8_BCCL_BCCLA_BCCLR_BCCLRL_BCCTR_BCCTR8_BCCTR8n_BCCTRL_BCCTRL8_BCCTRL8n_BCCTRLn_BCCTRn_BDNZ_BDNZ8_BDNZA_BDNZAm_BDNZAp_BDNZm_BDNZp_BDZ_BDZ8_BDZA_BDZAm_BDZAp_BDZm_BDZp_BDNZL_BDNZLA_BDNZLAm_BDNZLAp_BDNZLR_BDNZLR8_BDNZLRL_BDNZLRLm_BDNZLRLp_BDNZLRm_BDNZLRp_BDNZLm_BDNZLp_BDZL_BDZLA_BDZLAm_BDZLAp_BDZLR_BDZLR8_BDZLRL_BDZLRLm_BDZLRLp_BDZLRm_BDZLRp_BDZLm_BDZLp_BL_BL_NOP_BL_TLS_BL8_BL8_NOP_BL8_NOP_TLS_BL8_TLS_BL8_TLS__BLA_BLA8_BLA8_NOP_BLR_BLR8_BLRL_TAILB_TAILB8_TAILBA_TAILBA8_TAILBCTR_TAILBCTR8_gBC_gBCA_gBCAat_gBCCTR_gBCCTRL_gBCL_gBCLA_gBCLAat_gBCLR_gBCLRL_gBCLat_gBCat_BCLR_BCLRL_BCLRLn_BCLRn_BCTR_BCTR8_BCTRL_BCTRL8_B_BA_BC_BCC_BCCA_BCL_BCLalways_BCLn_BCTRL8_LDinto_toc_BCTRL_LWZinto_toc_BCn_CTRL_DEP
  { 1, 472, 474, 4312, 4314 }, // 288 ADDPCIS
  { 1, 468, 470, 4314, 4316 }, // 289 LDAT_LWAT
  { 1, 468, 470, 4316, 4318 }, // 290 STDAT_STWAT
  { 1, 470, 472, 4318, 4321 }, // 291 BRINC
  { 0, 0, 0, 0, 0 }, // 292 EVABS_EVEQV_EVNAND_EVNEG_EVADDIW_EVADDW_EVAND_EVANDC_EVCMPEQ_EVCMPGTS_EVCMPGTU_EVCMPLTS_EVCMPLTU_EVCNTLSW_EVCNTLZW_EVEXTSB_EVEXTSH_EVMERGEHI_EVMERGEHILO_EVMERGELO_EVMERGELOHI_EVNOR_EVOR_EVORC_EVXOR_EVRLW_EVRLWI_EVRNDW_EVSLW_EVSLWI_EVSPLATFI_EVSPLATI_EVSRWIS_EVSRWIU_EVSRWS_EVSRWU_EVSUBFW_EVSUBIFW
  { 0, 0, 0, 0, 0 }, // 293 EVMRA_EVADDSMIAAW_EVADDSSIAAW_EVADDUMIAAW_EVADDUSIAAW_EVDIVWS_EVDIVWU_EVMHEGSMFAA_EVMHEGSMFAN_EVMHEGSMIAA_EVMHEGSMIAN_EVMHEGUMIAA_EVMHEGUMIAN_EVMHESMF_EVMHESMFA_EVMHESMFAAW_EVMHESMFANW_EVMHESMI_EVMHESMIA_EVMHESMIAAW_EVMHESMIANW_EVMHESSF_EVMHESSFA_EVMHESSFAAW_EVMHESSFANW_EVMHESSIAAW_EVMHESSIANW_EVMHEUMI_EVMHEUMIA_EVMHEUMIAAW_EVMHEUMIANW_EVMHEUSIAAW_EVMHEUSIANW_EVMHOGSMFAA_EVMHOGSMFAN_EVMHOGSMIAA_EVMHOGSMIAN_EVMHOGUMIAA_EVMHOGUMIAN_EVMHOSMF_EVMHOSMFA_EVMHOSMFAAW_EVMHOSMFANW_EVMHOSMI_EVMHOSMIA_EVMHOSMIAAW_EVMHOSMIANW_EVMHOSSF_EVMHOSSFA_EVMHOSSFAAW_EVMHOSSFANW_EVMHOSSIAAW_EVMHOSSIANW_EVMHOUMI_EVMHOUMIA_EVMHOUMIAAW_EVMHOUMIANW_EVMHOUSIAAW_EVMHOUSIANW_EVMWHSMF_EVMWHSMFA_EVMWHSMI_EVMWHSMIA_EVMWHSSF_EVMWHSSFA_EVMWHUMI_EVMWHUMIA_EVMWLSMIAAW_EVMWLSMIANW_EVMWLSSIAAW_EVMWLSSIANW_EVMWLUMI_EVMWLUMIA_EVMWLUMIAAW_EVMWLUMIANW_EVMWLUSIAAW_EVMWLUSIANW_EVMWSMF_EVMWSMFA_EVMWSMFAA_EVMWSMFAN_EVMWSMI_EVMWSMIA_EVMWSMIAA_EVMWSMIAN_EVMWSSF_EVMWSSFA_EVMWSSFAA_EVMWSSFAN_EVMWUMI_EVMWUMIA_EVMWUMIAA_EVMWUMIAN_EVSUBFSMIAAW_EVSUBFSSIAAW_EVSUBFUMIAAW_EVSUBFUSIAAW
  { 1, 468, 470, 4321, 4323 }, // 294 EVLDD_EVLDDX_EVLDH_EVLDHX_EVLDW_EVLDWX_EVLHHESPLAT_EVLHHESPLATX_EVLHHOSSPLAT_EVLHHOSSPLATX_EVLHHOUSPLAT_EVLHHOUSPLATX_EVLWHE_EVLWHEX_EVLWHOS_EVLWHOSX_EVLWHOU_EVLWHOUX_EVLWHSPLAT_EVLWHSPLATX_EVLWWSPLAT_EVLWWSPLATX
  { 1, 468, 470, 4323, 4325 }, // 295 EVSTDD_EVSTDDX_EVSTDH_EVSTDHX_EVSTDW_EVSTDWX_EVSTWHE_EVSTWHEX_EVSTWHO_EVSTWHOX_EVSTWWE_EVSTWWEX_EVSTWWO_EVSTWWOX
  { 1, 472, 474, 4325, 4327 }, // 296 HRFID_ATTN_CLRBHRB_MFBHRBE_NAP_RFCI_RFDI_RFMCI_SC
  { 0, 0, 0, 0, 0 }, // 297 RFI
  { 0, 0, 0, 0, 0 }, // 298 RFID
  { 1, 468, 470, 4327, 4329 }, // 299 DSS_DSSALL_DST_DST64_DSTST_DSTST64_DSTSTT_DSTSTT64_DSTT_DSTT64_ICBLQ_LBEPX_LHEPX_LWEPX_TLBIVAX_TLBLD_TLBLI_TLBRE_TLBRE2_TLBSX_TLBSX2_TLBSX2D_TLBWE_TLBWE2_MBAR_TRAP_DCCCI_ICCCI
  { 1, 468, 470, 4329, 4331 }, // 300 ICBLC_STBEPX_STHEPX_STWEPX
  { 2, 468, 470, 4331, 4334 }, // 301 LFDEPX
  { 1, 468, 470, 4334, 4337 }, // 302 STFDEPX
  { 0, 0, 0, 0, 0 }, // 303 MFSR_MFSRIN
  { 0, 0, 0, 0, 0 }, // 304 MTSR_MTSRIN
  { 1, 496, 498, 4337, 4338 }, // 305 MFDCR
  { 1, 496, 498, 4338, 4339 }, // 306 MTDCR
  { 1, 470, 472, 4339, 4342 }, // 307 NOP_GT_PWR6_NOP_GT_PWR7
  { 0, 0, 0, 0, 0 }, // 308 TLBIA
  { 1, 504, 506, 4342, 4344 }, // 309 WRTEE_WRTEEI
  { 1, 468, 470, 0, 0 }, // 310 MSYNC
  { 0, 0, 0, 0, 0 }, // 311 SLBSYNC
  { 0, 0, 0, 0, 0 }, // 312 SLBFEE_rec
  { 0, 0, 0, 0, 0 }, // 313 STOP
  { 1, 468, 470, 4344, 4346 }, // 314 DCBA_DCBI
  { 0, uint16_t(~0U), uint16_t(~0U), uint16_t(~0U), uint16_t(~0U) }// end marker
};

static const llvm::InstrItinerary P8Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 0, 0, 0, 0, 0 }, // 1 IIC_LdStSync
  { 1, 515, 517, 4346, 4349 }, // 2 IIC_IntSimple
  { 1, 515, 517, 4349, 4352 }, // 3 IIC_IntGeneral
  { 1, 517, 519, 4352, 4355 }, // 4 IIC_BrB
  { 1, 519, 521, 4355, 4358 }, // 5 IIC_VecFP
  { 1, 521, 523, 4358, 4361 }, // 6 IIC_IntCompare
  { 0, 0, 0, 0, 0 }, // 7 IIC_SprABORT
  { 0, 0, 0, 0, 0 }, // 8 IIC_LdStCOPY
  { 0, 0, 0, 0, 0 }, // 9 IIC_LdStPASTE
  { 1, 523, 525, 4361, 4364 }, // 10 IIC_BrCR
  { 1, 525, 527, 4364, 4367 }, // 11 IIC_LdStLD
  { 0, 0, 0, 0, 0 }, // 12 IIC_LdStDCBF
  { 1, 525, 527, 4367, 4370 }, // 13 IIC_LdStLoad
  { 1, 527, 529, 4370, 4373 }, // 14 IIC_IntDivD
  { 1, 529, 531, 4373, 4376 }, // 15 IIC_IntDivW
  { 0, 0, 0, 0, 0 }, // 16 IIC_FPDGeneral
  { 1, 531, 533, 4376, 4379 }, // 17 IIC_FPAddSub
  { 1, 531, 533, 4379, 4382 }, // 18 IIC_FPDivD
  { 0, 0, 0, 0, 0 }, // 19 IIC_FPSGeneral
  { 1, 531, 533, 4382, 4385 }, // 20 IIC_FPCompare
  { 1, 531, 533, 4385, 4388 }, // 21 IIC_FPGeneral
  { 1, 519, 521, 4388, 4391 }, // 22 IIC_VecGeneral
  { 1, 519, 521, 4391, 4394 }, // 23 IIC_VecComplex
  { 1, 533, 536, 4394, 4397 }, // 24 IIC_LdStStore
  { 1, 521, 523, 4397, 4400 }, // 25 IIC_IntRotateDI
  { 1, 531, 533, 4400, 4403 }, // 26 IIC_FPDivS
  { 1, 531, 533, 4403, 4407 }, // 27 IIC_FPFused
  { 1, 531, 533, 4407, 4410 }, // 28 IIC_FPSqrtD
  { 1, 531, 533, 4410, 4413 }, // 29 IIC_FPSqrtS
  { 0, 0, 0, 0, 0 }, // 30 IIC_LdStICBI
  { 1, 536, 539, 4413, 4417 }, // 31 IIC_IntISEL
  { 0, 0, 0, 0, 0 }, // 32 IIC_SprISYNC
  { 1, 539, 544, 4417, 4420 }, // 33 IIC_LdStLWARX
  { 1, 544, 548, 4420, 4424 }, // 34 IIC_LdStLoadUpd
  { 1, 544, 548, 4424, 4428 }, // 35 IIC_LdStLoadUpdX
  { 1, 548, 555, 4428, 4431 }, // 36 IIC_LdStLDARX
  { 1, 544, 548, 4431, 4435 }, // 37 IIC_LdStLDU
  { 1, 544, 548, 4435, 4439 }, // 38 IIC_LdStLDUX
  { 1, 555, 557, 4439, 4442 }, // 39 IIC_LdStLFD
  { 1, 557, 561, 4442, 4446 }, // 40 IIC_LdStLFDU
  { 1, 557, 561, 4446, 4450 }, // 41 IIC_LdStLFDUX
  { 1, 561, 565, 4450, 4453 }, // 42 IIC_LdStLHA
  { 1, 565, 570, 4453, 4457 }, // 43 IIC_LdStLHAU
  { 1, 570, 579, 4457, 4461 }, // 44 IIC_LdStLHAUX
  { 1, 525, 527, 4461, 4464 }, // 45 IIC_LdStLMW
  { 1, 579, 583, 4464, 4467 }, // 46 IIC_LdStLWA
  { 1, 521, 523, 4467, 4470 }, // 47 IIC_IntMulHD
  { 1, 583, 585, 4470, 4473 }, // 48 IIC_BrMCR
  { 1, 585, 587, 4473, 4475 }, // 49 IIC_BrMCRX
  { 1, 523, 525, 4475, 4477 }, // 50 IIC_SprMFCR
  { 0, 0, 0, 0, 0 }, // 51 IIC_SprMFSPR
  { 0, 0, 0, 0, 0 }, // 52 IIC_IntMFFS
  { 0, 0, 0, 0, 0 }, // 53 IIC_SprMFMSR
  { 1, 523, 525, 4477, 4479 }, // 54 IIC_SprMFCRF
  { 0, 0, 0, 0, 0 }, // 55 IIC_SprMFPMR
  { 0, 0, 0, 0, 0 }, // 56 IIC_SprMFSR
  { 0, 0, 0, 0, 0 }, // 57 IIC_SprMFTB
  { 0, 0, 0, 0, 0 }, // 58 IIC_SprMSGSYNC
  { 1, 585, 587, 4479, 4481 }, // 59 IIC_SprMTSPR
  { 0, 0, 0, 0, 0 }, // 60 IIC_IntMTFSB0
  { 0, 0, 0, 0, 0 }, // 61 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 62 IIC_SprMTMSRD
  { 0, 0, 0, 0, 0 }, // 63 IIC_SprMTPMR
  { 0, 0, 0, 0, 0 }, // 64 IIC_SprMTSR
  { 1, 521, 523, 4481, 4484 }, // 65 IIC_IntMulHW
  { 1, 521, 523, 4484, 4487 }, // 66 IIC_IntMulHWU
  { 1, 521, 523, 4487, 4490 }, // 67 IIC_IntMulLI
  { 1, 587, 589, 4490, 4493 }, // 68 IIC_VecPerm
  { 1, 589, 592, 4493, 4496 }, // 69 IIC_LdStSTFD
  { 1, 592, 597, 4496, 4500 }, // 70 IIC_LdStSTFDU
  { 0, 0, 0, 0, 0 }, // 71 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 72 IIC_IntRFID
  { 1, 521, 523, 4500, 4503 }, // 73 IIC_IntRotateD
  { 1, 521, 523, 4503, 4506 }, // 74 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 75 IIC_SprSLBFEE
  { 0, 0, 0, 0, 0 }, // 76 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 77 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprSLBIEG
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprSLBMFEV
  { 0, 0, 0, 0, 0 }, // 81 IIC_SprSLBMTE
  { 0, 0, 0, 0, 0 }, // 82 IIC_SprSLBSYNC
  { 1, 521, 523, 4506, 4509 }, // 83 IIC_IntShift
  { 1, 597, 605, 4509, 4512 }, // 84 IIC_LdStSTWCX
  { 1, 605, 609, 4512, 4516 }, // 85 IIC_LdStSTU
  { 1, 609, 618, 4516, 4520 }, // 86 IIC_LdStSTUX
  { 1, 618, 621, 0, 0 }, // 87 IIC_LdStSTD
  { 1, 597, 605, 4520, 4523 }, // 88 IIC_LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 89 IIC_SprSTOP
  { 1, 521, 523, 4523, 4525 }, // 90 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 91 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 92 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 93 IIC_SprTLBIEL
  { 0, 0, 0, 0, 0 }, // 94 IIC_SprTLBSYNC
  { 1, 521, 523, 4525, 4527 }, // 95 IIC_IntTrapW
  { 1, 519, 521, 4527, 4530 }, // 96 IIC_VecFPCompare
  { 1, 519, 521, 4530, 4533 }, // 97 VADDUBM_VADDUDM_VADDUHM_VADDUWM_VEXTSB2D_VEXTSB2Ds_VEXTSB2W_VEXTSB2Ws_VEXTSH2D_VEXTSH2Ds_VEXTSH2W_VEXTSH2Ws_VEXTSW2D_VEXTSW2Ds_VSLD_VSRD_VSUBUBM_VSUBUDM_VSUBUHM_VSUBUWM_VPOPCNTB_VPOPCNTH_VSRAD_MTVSRDD_VEQV_VNAND_VNEGD_VNEGW_VORC_XXLAND_XXLANDC_XXLEQV_XXLEQVOnes_XXLNAND_XXLNOR_XXLOR_XXLORf_XXLORC_XXLXOR_XXLXORdpz_XXLXORspz_XXLXORz
  { 1, 519, 521, 4533, 4536 }, // 98 VAND_VANDC_V_SET0_V_SET0B_V_SET0H_VSLB_VSLH_VSLW_VSRB_VSRH_VSRW_VRLB_VRLD_VRLH_VRLW_VSRAB_VSRAH_VSRAW_XVABSDP_XVABSSP_XVNABSDP_XVNABSSP_XVCPSGNDP_XVCPSGNSP_XVIEXPDP_XVIEXPSP_XVXEXPDP_XVXEXPSP_VRLDMI_VRLDNM_VRLWMI_VRLWNM_VMRGEW_VMRGOW_VNOR_VOR_VSEL_VXOR_XVNEGDP_XVNEGSP_XSABSQP_XSCPSGNQP_XSIEXPQP_XSNABSQP_XSNEGQP_XSXEXPQP
  { 1, 587, 589, 4536, 4539 }, // 99 XXSEL
  { 1, 585, 587, 4539, 4541 }, // 100 TABORTDC_TABORTDCI_TABORTWC_TABORTWCI
  { 0, 0, 0, 0, 0 }, // 101 MTFSB0_MTFSB1
  { 0, 0, 0, 0, 0 }, // 102 MFFSCDRN_MFFSCDRNI_MFFSCRN_MFFSCRNI
  { 1, 521, 523, 4541, 4544 }, // 103 CMPRB_CMPRB8_CMPEQB
  { 1, 521, 523, 4544, 4546 }, // 104 TD_TDI
  { 1, 521, 523, 4546, 4548 }, // 105 TW_TWI
  { 1, 531, 533, 4548, 4551 }, // 106 FCMPUD_FCMPUS_FTDIV_FTSQRT
  { 1, 519, 521, 4551, 4554 }, // 107 XSTSTDCDP_XSTSTDCSP
  { 1, 519, 521, 4554, 4557 }, // 108 XSMAXCDP_XSMAXDP_XSMAXJDP_XSMINCDP_XSMINDP_XSMINJDP_XSXSIGDP_XSCVSPDPN
  { 1, 531, 533, 4557, 4560 }, // 109 XSCMPEQDP_XSCMPEXPDP_XSCMPGEDP_XSCMPGTDP_XSCMPODP_XSCMPUDP_XSTDIVDP_XSTSQRTDP
  { 1, 515, 517, 4560, 4563 }, // 110 CNTLZD_CNTLZD_rec_CNTLZW_CNTLZW8_CNTLZW8_rec_CNTLZW_rec_CNTTZD_CNTTZD_rec_CNTTZW_CNTTZW8_CNTTZW8_rec_CNTTZW_rec_POPCNTD_POPCNTW_CMPB_CMPB8_SETB_SETB8_BPERMD
  { 1, 521, 523, 4563, 4566 }, // 111 SLD_SRD_SRAD
  { 1, 521, 523, 4566, 4569 }, // 112 SRADI_EXTSWSLI_32_64_EXTSWSLI_SRADI_32_RLDIC
  { 1, 519, 521, 4569, 4572 }, // 113 MFVRD_MFVSRD_MTVRD_MTVSRD_MTVRWA_MTVRWZ_MTVSRWA_MTVSRWZ_MFVSRWZ_MFVRWZ
  { 1, 521, 523, 4572, 4575 }, // 114 CMPLW_CMPLWI_CMPW_CMPWI_CMPD_CMPDI_CMPLD_CMPLDI
  { 1, 515, 517, 4575, 4578 }, // 115 SUBFC_SUBFC8_SUBFC8O_SUBFCO_SUBFIC_SUBFIC8_ANDI8_rec_ANDIS8_rec_ANDIS_rec_ANDI_rec_ADDC_ADDC8_ADDC8O_ADDCO_ADDIC_ADDIC8_ADDIC_rec_ADDE_ADDE8_ADDE8O_ADDE8O_rec_ADDE8_rec_ADDEO_ADDEO_rec_ADDE_rec_ADDME_ADDME8_ADDME8O_ADDME8O_rec_ADDME8_rec_ADDMEO_ADDMEO_rec_ADDME_rec_ADDZE_ADDZE8_ADDZE8O_ADDZE8O_rec_ADDZE8_rec_ADDZEO_ADDZEO_rec_ADDZE_rec_SUBF_SUBF8_SUBF8O_SUBF8O_rec_SUBF8_rec_SUBFE_SUBFE8_SUBFE8O_SUBFE8O_rec_SUBFE8_rec_SUBFEO_SUBFEO_rec_SUBFE_rec_SUBFME_SUBFME8_SUBFME8O_SUBFME8O_rec_SUBFME8_rec_SUBFMEO_SUBFMEO_rec_SUBFME_rec_SUBFO_SUBFO_rec_SUBFZE_SUBFZE8_SUBFZE8O_SUBFZE8O_rec_SUBFZE8_rec_SUBFZEO_SUBFZEO_rec_SUBFZE_rec_SUBF_rec_POPCNTB_LA
  { 1, 515, 517, 4578, 4581 }, // 116 ADD4_ADD4O_ADD4O_rec_ADD4_rec_ADD8_ADD8O_ADD8O_rec_ADD8_rec_NEG_NEG8_NEG8O_NEG8O_rec_NEG8_rec_NEGO_NEGO_rec_NEG_rec_ADDI_ADDI8_ADDIS_ADDIS8_LI_LI8_LIS_LIS8_OR_OR8_OR8_rec_ORI_ORI8_ORIS_ORIS8_OR_rec_XOR_XOR8_XOR8_rec_XORI_XORI8_XORIS_XORIS8_XOR_rec_NAND_NAND8_NAND8_rec_NAND_rec_AND_AND8_AND8_rec_ANDC_ANDC8_ANDC8_rec_ANDC_rec_AND_rec_NOR_NOR8_NOR8_rec_NOR_rec_ORC_ORC8_ORC8_rec_ORC_rec_EQV_EQV8_EQV8_rec_EQV_rec_EXTSB_EXTSB8_EXTSB8_32_64_EXTSB8_rec_EXTSB_rec_EXTSH_EXTSH8_EXTSH8_32_64_EXTSH8_rec_EXTSH_rec_EXTSW_EXTSW_32_EXTSW_32_64_EXTSW_32_64_rec_EXTSW_rec_ADD4TLS_ADD8TLS_ADD8TLS__NOP
  { 0, 0, 0, 0, 0 }, // 117 ADDIStocHA_ADDIStocHA8_ADDItocL_COPY
  { 1, 583, 585, 4581, 4584 }, // 118 MCRF
  { 1, 585, 587, 4584, 4586 }, // 119 MCRXRX
  { 1, 519, 521, 4586, 4589 }, // 120 XSNABSDP_XSXEXPDP_XSABSDP_XSNEGDP_XSCPSGNDP
  { 1, 517, 519, 4589, 4592 }, // 121 RFEBB
  { 1, 585, 587, 4592, 4594 }, // 122 TBEGIN_TRECHKPT
  { 1, 525, 527, 4594, 4597 }, // 123 WAIT
  { 1, 521, 523, 4597, 4600 }, // 124 RLDCL_RLDCR
  { 1, 521, 523, 4600, 4603 }, // 125 RLWIMI_RLWIMI8
  { 1, 521, 523, 4603, 4606 }, // 126 RLDICL_RLDICL_32_RLDICL_32_64_RLDICR_RLDICR_32_RLDIMI
  { 1, 523, 525, 4606, 4608 }, // 127 MFOCRF_MFOCRF8
  { 1, 585, 587, 4608, 4610 }, // 128 MTOCRF_MTOCRF8
  { 1, 523, 525, 4610, 4613 }, // 129 CR6SET_CR6UNSET_CRSET_CRUNSET_CRAND_CRANDC_CRNAND_CRNOR_CROR_CRORC_CREQV_CRXOR
  { 1, 515, 517, 4613, 4616 }, // 130 SLW_SLW8_SRW_SRW8_RLWINM_RLWINM8_RLWNM_RLWNM8
  { 1, 531, 533, 4616, 4619 }, // 131 FABSD_FABSS_FNABSD_FNABSS_FNEGD_FNEGS_FCPSGND_FCPSGNS_FMR
  { 1, 521, 523, 4619, 4622 }, // 132 SRAW_SRAWI
  { 1, 536, 539, 4622, 4626 }, // 133 ISEL_ISEL8
  { 1, 519, 521, 4626, 4629 }, // 134 XSIEXPDP
  { 1, 585, 587, 4629, 4631 }, // 135 TRECLAIM_TSR_TABORT
  { 1, 533, 536, 4631, 4634 }, // 136 MFVSCR
  { 1, 525, 527, 4634, 4637 }, // 137 MTVSCR
  { 1, 519, 521, 4637, 4640 }, // 138 VCMPNEZB_VCMPNEZH_VCMPNEZW_VCMPEQUB_VCMPEQUD_VCMPEQUH_VCMPEQUW_VCMPNEB_VCMPNEH_VCMPNEW_VCMPEQFP_VCMPEQFP_rec_VCMPGEFP_VCMPGEFP_rec_VCMPGTFP_VCMPGTFP_rec_VCMPBFP_VCMPBFP_rec_VCMPGTSB_VCMPGTSB_rec_VCMPGTSD_VCMPGTSD_rec_VCMPGTSH_VCMPGTSH_rec_VCMPGTSW_VCMPGTSW_rec_VCMPGTUB_VCMPGTUB_rec_VCMPGTUD_VCMPGTUD_rec_VCMPGTUH_VCMPGTUH_rec_VCMPGTUW_VCMPGTUW_rec_VCMPNEB_rec_VCMPNEH_rec_VCMPNEW_rec_VCMPNEZB_rec_VCMPNEZH_rec_VCMPNEZW_rec_VCMPEQUB_rec_VCMPEQUD_rec_VCMPEQUH_rec_VCMPEQUW_rec_XVCMPEQDP_XVCMPEQDP_rec_XVCMPEQSP_XVCMPEQSP_rec_XVCMPGEDP_XVCMPGEDP_rec_XVCMPGESP_XVCMPGESP_rec_XVCMPGTDP_XVCMPGTDP_rec_XVCMPGTSP_XVCMPGTSP_rec
  { 1, 519, 521, 4640, 4643 }, // 139 VABSDUB_VABSDUH_VABSDUW_VCLZB_VCLZD_VCLZH_VCLZW_VCTZB_VCTZD_VCTZH_VCTZW_VPOPCNTW_VPOPCNTD_VPRTYBD_VPRTYBW
  { 1, 519, 521, 4643, 4646 }, // 140 VADDUBS_VADDUHS_VADDUWS_VAVGSB_VAVGSH_VAVGSW_VAVGUB_VAVGUH_VAVGUW_VADDSBS_VADDSHS_VADDSWS_VMAXFP_VMINFP_VMAXSB_VMAXSD_VMAXSH_VMAXSW_VMAXUB_VMAXUD_VMAXUH_VMAXUW_VMINSB_VMINSD_VMINSH_VMINSW_VMINUB_VMINUD_VMINUH_VMINUW_VBPERMD_VADDCUW_VSHASIGMAD_VSHASIGMAW_VSUBSBS_VSUBSHS_VSUBSWS_VSUBUBS_VSUBUHS_VSUBUWS_VSUBCUW_XVMAXDP_XVMAXSP_XVMINDP_XVMINSP_XVTSTDCDP_XVTSTDCSP_XVXSIGDP_XVXSIGSP
  { 1, 531, 533, 4646, 4649 }, // 141 XVTDIVDP_XVTDIVSP_XVTSQRTDP_XVTSQRTSP
  { 1, 519, 521, 4649, 4652 }, // 142 VADDFP_VCTSXS_VCTSXS_0_VCTUXS_VCTUXS_0_VEXPTEFP_VLOGEFP_VMADDFP_VMHADDSHS_VNMSUBFP_VREFP_VRFIM_VRFIN_VRFIP_VRFIZ_VRSQRTEFP_XVADDDP_XVADDSP_XVCVDPSP_XVCVDPSXDS_XVCVDPSXWS_XVCVDPUXDS_XVCVDPUXWS_XVCVHPSP_XVCVSPDP_XVCVSPHP_XVCVSPSXDS_XVCVSPSXWS_XVCVSPUXDS_XVCVSPUXWS_XVCVSXDDP_XVCVSXDSP_XVCVSXWDP_XVCVSXWSP_XVCVUXDDP_XVCVUXDSP_XVCVUXWDP_XVCVUXWSP_XVMADDADP_XVMADDASP_XVMADDMDP_XVMADDMSP_XVMSUBADP_XVMSUBASP_XVMSUBMDP_XVMSUBMSP_XVMULDP_XVMULSP_XVNMADDADP_XVNMADDASP_XVNMADDMDP_XVNMADDMSP_XVNMSUBADP_XVNMSUBASP_XVNMSUBMDP_XVNMSUBMSP_XVRDPI_XVRDPIC_XVRDPIM_XVRDPIP_XVRDPIZ_XVREDP_XVRESP_XVRSPI_XVRSPIC_XVRSPIM_XVRSPIP_XVRSPIZ_XVRSQRTEDP_XVRSQRTESP_XVSUBDP_XVSUBSP_VCFSX_VCFSX_0_VCFUX_VCFUX_0_VMHRADDSHS_VMLADDUHM_VMSUMMBM_VMSUMSHM_VMSUMSHS_VMSUMUBM_VMSUMUHM_VMSUMUDM_VMSUMUHS_VMULESB_VMULESH_VMULESW_VMULEUB_VMULEUH_VMULEUW_VMULOSB_VMULOSH_VMULOSW_VMULOUB_VMULOUH_VMULOUW_VSUM2SWS_VSUM4SBS_VSUM4SHS_VSUM4UBS_VSUMSWS
  { 1, 519, 521, 4652, 4655 }, // 143 VSUBFP_VMULUWM
  { 1, 521, 523, 4655, 4658 }, // 144 MADDHD_MADDHDU_MADDLD_MADDLD8_MULLD_MULLDO
  { 1, 521, 523, 4658, 4661 }, // 145 MULHD_MULHW_MULLW_MULLWO
  { 1, 521, 523, 4661, 4664 }, // 146 MULHDU_MULHWU
  { 1, 521, 523, 4664, 4667 }, // 147 MULLI_MULLI8
  { 1, 531, 533, 4667, 4670 }, // 148 FRSP_FRIMD_FRIMS_FRIND_FRINS_FRIPD_FRIPS_FRIZD_FRIZS_FRE_FRES_FADDS_FMSUBS_FMADDS_FSUBS_FCFID_FCFIDS_FCFIDU_FCFIDUS_FCTID_FCTIDU_FCTIDUZ_FCTIDZ_FCTIW_FCTIWU_FCTIWUZ_FCTIWZ_FRSQRTE_FRSQRTES_FNMADDS_FNMSUBS_FSELD_FSELS_FMULS
  { 1, 531, 533, 4670, 4673 }, // 149 FADD_FSUB
  { 1, 531, 533, 4673, 4677 }, // 150 FMSUB_FMADD_FNMADD_FNMSUB_FMUL
  { 1, 519, 521, 4677, 4680 }, // 151 XSMADDADP_XSMADDASP_XSMADDMDP_XSMADDMSP_XSMSUBADP_XSMSUBASP_XSMSUBMDP_XSMSUBMSP_XSMULDP_XSMULSP_XSNMADDADP_XSNMADDASP_XSNMADDMDP_XSNMADDMSP_XSNMSUBADP_XSNMSUBASP_XSNMSUBMDP_XSNMSUBMSP
  { 1, 531, 533, 4680, 4683 }, // 152 FSELD_rec_FSELS_rec
  { 1, 521, 523, 4683, 4686 }, // 153 MULHDU_rec_MULHWU_rec
  { 1, 521, 523, 4686, 4689 }, // 154 MULHD_rec_MULHW_rec_MULLWO_rec_MULLW_rec
  { 1, 521, 523, 4689, 4692 }, // 155 MULLDO_rec_MULLD_rec
  { 1, 531, 533, 4692, 4695 }, // 156 FRIMD_rec_FRIMS_rec_FRIND_rec_FRINS_rec_FRIPD_rec_FRIPS_rec_FRIZD_rec_FRIZS_rec_FRES_rec_FRE_rec_FADDS_rec_FSUBS_rec_FMSUBS_rec_FNMSUBS_rec_FMADDS_rec_FNMADDS_rec_FCFIDS_rec_FCFIDUS_rec_FCFIDU_rec_FCFID_rec_FCTIDUZ_rec_FCTIDU_rec_FCTIDZ_rec_FCTID_rec_FCTIWUZ_rec_FCTIWU_rec_FCTIWZ_rec_FCTIW_rec_FMULS_rec_FRSQRTES_rec_FRSQRTE_rec_FRSP_rec
  { 1, 531, 533, 4695, 4698 }, // 157 FADD_rec_FSUB_rec
  { 1, 531, 533, 4698, 4702 }, // 158 FMSUB_rec_FNMSUB_rec_FMADD_rec_FNMADD_rec_FMUL_rec
  { 1, 519, 521, 4702, 4705 }, // 159 XSADDDP_XSADDSP_XSCVDPHP_XSCVDPSP_XSCVDPSXDS_XSCVDPSXDSs_XSCVDPSXWS_XSCVDPUXDS_XSCVDPUXDSs_XSCVDPUXWS_XSCVDPSXWSs_XSCVDPUXWSs_XSCVHPDP_XSCVSPDP_XSCVSXDDP_XSCVSXDSP_XSCVUXDDP_XSCVUXDSP_XSRDPI_XSRDPIC_XSRDPIM_XSRDPIP_XSRDPIZ_XSREDP_XSRESP_XSRSQRTEDP_XSRSQRTESP_XSSUBDP_XSSUBSP_XSCVDPSPN_XSRSP
  { 1, 525, 527, 4705, 4708 }, // 160 LVSL_LVSR
  { 1, 587, 589, 4708, 4711 }, // 161 VSPLTISB_VSPLTISH_VSPLTISW_VSPLTB_VSPLTBs_VSPLTH_VSPLTHs_VSPLTW_XXMRGHW_XXMRGLW_XXPERM_XXPERMR_XXSLDWI_XXSLDWIs_XXSPLTIB_XXSPLTW_XXSPLTWs_XXPERMDI_XXPERMDIs
  { 1, 519, 521, 4711, 4714 }, // 162 V_SETALLONES_V_SETALLONESB_V_SETALLONESH_VBPERMQ_VGBBD_VMRGHB_VMRGHH_VMRGHW_VMRGLB_VMRGLH_VMRGLW_VPERM_VPERMR_VPERMXOR_VPKPX_VPKSDSS_VPKSDUS_VPKSHSS_VPKSHUS_VPKSWSS_VPKSWUS_VPKUDUM_VPKUDUS_VPKUHUM_VPKUHUS_VPKUWUM_VPKUWUS_VSL_VSLDOI_VSLO_VSLV_VSR_VSRO_VSRV_VUPKHPX_VUPKHSB_VUPKHSH_VUPKHSW_VUPKLPX_VUPKLSB_VUPKLSH_VUPKLSW_XXBRD_XXBRH_XXBRQ_XXBRW_XXEXTRACTUW_XXINSERTW_VADDCUQ_VADDECUQ_VADDEUQM_VMUL10CUQ_VMUL10ECUQ_VMUL10EUQ_VMUL10UQ_VSUBCUQ_VSUBECUQ_VSUBEUQM_XSTSTDCQP_XSXSIGQP_BCDCFN_rec_BCDCFZ_rec_BCDCPSGN_rec_BCDCTN_rec_BCDCTZ_rec_BCDSETSGN_rec_BCDS_rec_BCDTRUNC_rec_BCDUS_rec_BCDUTRUNC_rec
  { 1, 519, 521, 4714, 4717 }, // 163 VEXTRACTUB_VEXTRACTUH_VEXTRACTUW_VINSERTB_VINSERTD_VINSERTH_VINSERTW_MFVSRLD_MTVSRWS_VCLZLSBB_VCTZLSBB_VEXTRACTD_VEXTUBLX_VEXTUBRX_VEXTUHLX_VEXTUHRX_VEXTUWLX_VEXTUWRX_VPRTYBQ_VADDUQM_VSUBUQM
  { 1, 531, 533, 4717, 4720 }, // 164 XSCMPEXPQP_XSCMPOQP_XSCMPUQP
  { 1, 519, 521, 4720, 4723 }, // 165 BCDSR_rec_XSADDQP_XSADDQPO_XSCVDPQP_XSCVQPDP_XSCVQPDPO_XSCVQPSDZ_XSCVQPSWZ_XSCVQPUDZ_XSCVQPUWZ_XSCVSDQP_XSCVUDQP_XSRQPI_XSRQPIX_XSRQPXP_XSSUBQP_XSSUBQPO
  { 1, 519, 521, 4723, 4726 }, // 166 BCDCTSQ_rec
  { 1, 519, 521, 4726, 4729 }, // 167 XSMADDQP_XSMADDQPO_XSMSUBQP_XSMSUBQPO_XSMULQP_XSMULQPO_XSNMADDQP_XSNMADDQPO_XSNMSUBQP_XSNMSUBQPO
  { 1, 519, 521, 4729, 4732 }, // 168 BCDCFSQ_rec
  { 1, 519, 521, 4732, 4735 }, // 169 XSDIVQP_XSDIVQPO
  { 1, 519, 521, 4735, 4738 }, // 170 XSSQRTQP_XSSQRTQPO
  { 1, 525, 527, 4738, 4741 }, // 171 LXVL_LXVLL
  { 1, 525, 527, 4741, 4744 }, // 172 LVEBX_LVEHX_LVEWX_LVX_LVXL
  { 1, 555, 557, 4744, 4747 }, // 173 LXSIBZX_LXSIHZX_LXSDX_LXVB16X_LXVD2X_LXVWSX_LXSIWZX_LXV_LXVX_LXSD
  { 0, 0, 0, 0, 0 }, // 174 DFLOADf64_XFLOADf64_LIWZX
  { 0, 0, 0, 0, 0 }, // 175 DCBF_DCBFEP_DCBST_DCBSTEP_DCBT_DCBTEP_DCBZ_DCBZEP_DCBZL_DCBZLEP_DCBTST_DCBTSTEP
  { 0, 0, 0, 0, 0 }, // 176 CP_COPY_CP_COPY8
  { 0, 0, 0, 0, 0 }, // 177 CP_PASTE_CP_PASTE8
  { 0, 0, 0, 0, 0 }, // 178 ICBI_ICBIEP
  { 1, 525, 527, 4747, 4750 }, // 179 ICBT_ICBTLS_LBZ_LBZ8_LBZCIX_LBZX_LBZX8_LBZXTLS_LBZXTLS__LBZXTLS_32_LDBRX_LDCIX_LHBRX_LHBRX8_LHZ_LHZ8_LHZCIX_LHZX_LHZX8_LHZXTLS_LHZXTLS__LHZXTLS_32_LWBRX_LWBRX8_LWZ_LWZ8_LWZCIX_LWZX_LWZX8_LWZXTLS_LWZXTLS__LWZXTLS_32_EnforceIEIO_LSWI
  { 1, 539, 544, 4750, 4753 }, // 180 LBARX_LBARXL_LHARX_LHARXL_LWARX_LWARXL
  { 1, 525, 527, 4753, 4756 }, // 181 LD_LDX_LDXTLS_LDXTLS__DARN
  { 1, 548, 555, 4756, 4759 }, // 182 LDARX_LDARXL
  { 0, 0, 0, 0, 0 }, // 183 CP_ABORT
  { 0, 0, 0, 0, 0 }, // 184 ISYNC
  { 0, 0, 0, 0, 0 }, // 185 MSGSYNC
  { 0, 0, 0, 0, 0 }, // 186 TLBSYNC
  { 0, 0, 0, 0, 0 }, // 187 SYNC
  { 1, 525, 527, 4759, 4762 }, // 188 LMW
  { 1, 555, 557, 4762, 4765 }, // 189 LFIWZX_LFDX_LFD
  { 0, 0, 0, 0, 0 }, // 190 SLBIA
  { 0, 0, 0, 0, 0 }, // 191 SLBIE
  { 0, 0, 0, 0, 0 }, // 192 SLBMFEE
  { 0, 0, 0, 0, 0 }, // 193 SLBMFEV
  { 0, 0, 0, 0, 0 }, // 194 SLBMTE
  { 0, 0, 0, 0, 0 }, // 195 TLBIEL
  { 1, 544, 548, 4765, 4769 }, // 196 LHZU_LHZU8_LWZU_LWZU8
  { 1, 544, 548, 4769, 4773 }, // 197 LHZUX_LHZUX8_LWZUX_LWZUX8
  { 1, 585, 587, 4773, 4775 }, // 198 TEND
  { 1, 597, 605, 4775, 4778 }, // 199 STBCX_STHCX_STWCX
  { 1, 597, 605, 4778, 4781 }, // 200 STDCX
  { 1, 525, 527, 4781, 4784 }, // 201 LDMX
  { 1, 561, 565, 4784, 4787 }, // 202 LHA_LHA8_LHAX_LHAX8_LWAX_LWAX_32
  { 0, 0, 0, 0, 0 }, // 203 CP_PASTE8_rec_CP_PASTE_rec
  { 1, 579, 583, 4787, 4790 }, // 204 LWA_LWA_32
  { 1, 585, 587, 4790, 4792 }, // 205 TCHECK
  { 1, 555, 557, 4792, 4795 }, // 206 LFIWAX
  { 1, 555, 557, 4795, 4798 }, // 207 LXSIWAX
  { 0, 0, 0, 0, 0 }, // 208 LIWAX
  { 1, 555, 557, 4798, 4801 }, // 209 LFSX_LFS
  { 1, 555, 557, 4801, 4804 }, // 210 LXSSP_LXSSPX
  { 0, 0, 0, 0, 0 }, // 211 XFLOADf32_DFLOADf32
  { 1, 565, 570, 4804, 4808 }, // 212 LHAU_LHAU8
  { 1, 570, 579, 4808, 4812 }, // 213 LHAUX_LHAUX8_LWAUX
  { 1, 555, 557, 4812, 4815 }, // 214 LXVH8X_LXVDSX_LXVW4X
  { 1, 589, 592, 4815, 4818 }, // 215 STFD_STFDX_STFIWX_STFS_STFSX_STXSD_STXSDX_STXSIBX_STXSIBXv_STXSIHX_STXSIHXv_STXSIWX_STXSSP_STXSSPX
  { 1, 533, 536, 4818, 4821 }, // 216 STW_STW8_STDBRX_STHBRX_STWBRX_STB_STB8_STH_STH8_STBX_STBX8_STBXTLS_STBXTLS__STBXTLS_32_STHX_STHX8_STHXTLS_STHXTLS__STHXTLS_32_STWX_STWX8_STWXTLS_STWXTLS__STWXTLS_32
  { 0, 0, 0, 0, 0 }, // 217 DFSTOREf32_DFSTOREf64_XFSTOREf32_XFSTOREf64_STIWX
  { 1, 618, 621, 0, 0 }, // 218 STD_STDX_STDXTLS_STDXTLS_
  { 1, 525, 527, 4821, 4824 }, // 219 STBCIX_STDCIX_STHCIX_STWCIX_STSWI
  { 0, 0, 0, 0, 0 }, // 220 SLBIEG
  { 1, 525, 527, 4824, 4827 }, // 221 STMW
  { 0, 0, 0, 0, 0 }, // 222 TLBIE
  { 1, 533, 536, 4827, 4830 }, // 223 STVEBX_STVEHX_STVEWX_STVX_STVXL
  { 1, 589, 592, 4830, 4833 }, // 224 STXV_STXVB16X_STXVD2X_STXVH8X_STXVW4X_STXVX
  { 1, 525, 527, 4833, 4836 }, // 225 STXVL_STXVLL
  { 1, 585, 587, 4836, 4838 }, // 226 MTCTR_MTCTR8_MTCTR8loop_MTCTRloop_MTLR_MTLR8
  { 1, 515, 517, 4838, 4841 }, // 227 MFVRSAVE_MFVRSAVEv_MTVRSAVE_MTVRSAVEv
  { 0, 0, 0, 0, 0 }, // 228 MFPMR
  { 0, 0, 0, 0, 0 }, // 229 MTPMR
  { 0, 0, 0, 0, 0 }, // 230 MFTB_MFTB8
  { 0, 0, 0, 0, 0 }, // 231 MFCTR_MFCTR8_MFLR_MFLR8_MFSPR_MFSPR8
  { 0, 0, 0, 0, 0 }, // 232 MFMSR
  { 0, 0, 0, 0, 0 }, // 233 MTMSR
  { 0, 0, 0, 0, 0 }, // 234 MTMSRD
  { 1, 585, 587, 4841, 4843 }, // 235 MTSPR_MTSPR8
  { 1, 529, 531, 4843, 4846 }, // 236 DIVW_DIVWO_DIVWU_DIVWUO_MODSW
  { 1, 529, 531, 4846, 4849 }, // 237 DIVWE_DIVWEO_DIVWEU_DIVWEUO_MODSD_MODUD_MODUW
  { 1, 527, 529, 4849, 4852 }, // 238 DIVD_DIVDO_DIVDU_DIVDUO
  { 1, 527, 529, 4852, 4855 }, // 239 DIVDE_DIVDEO_DIVDEU_DIVDEUO
  { 1, 529, 531, 4855, 4858 }, // 240 DIVWO_rec_DIVWUO_rec_DIVWU_rec_DIVW_rec
  { 1, 527, 529, 4858, 4861 }, // 241 DIVD_rec_DIVDO_rec_DIVDU_rec_DIVDUO_rec
  { 1, 529, 531, 4861, 4864 }, // 242 DIVWE_rec_DIVWEO_rec_DIVWEU_rec_DIVWEUO_rec
  { 1, 527, 529, 4864, 4867 }, // 243 DIVDE_rec_DIVDEO_rec_DIVDEU_rec_DIVDEUO_rec
  { 1, 585, 587, 4867, 4869 }, // 244 MTCRF_MTCRF8
  { 1, 515, 517, 4869, 4872 }, // 245 ADDC8O_rec_ADDC8_rec_ADDCO_rec_ADDC_rec_SUBFC8O_rec_SUBFC8_rec_SUBFCO_rec_SUBFC_rec
  { 1, 531, 533, 4872, 4875 }, // 246 FABSD_rec_FABSS_rec_FNABSD_rec_FNABSS_rec_FCPSGND_rec_FCPSGNS_rec_FNEGD_rec_FNEGS_rec_FMR_rec
  { 1, 583, 585, 4875, 4878 }, // 247 MCRFS
  { 0, 0, 0, 0, 0 }, // 248 MTFSF_MTFSF_rec_MTFSFI_MTFSFI_rec
  { 0, 0, 0, 0, 0 }, // 249 MTFSFb
  { 1, 521, 523, 4878, 4881 }, // 250 RLDCL_rec_RLDCR_rec
  { 1, 521, 523, 4881, 4884 }, // 251 RLDICL_rec_RLDICR_rec_RLDICL_32_rec_RLDIMI_rec
  { 1, 521, 523, 4884, 4887 }, // 252 RLWIMI8_rec_RLWIMI_rec
  { 1, 515, 517, 4887, 4890 }, // 253 RLWINM8_rec_RLWINM_rec_RLWNM8_rec_RLWNM_rec_SLW8_rec_SLW_rec_SRW8_rec_SRW_rec
  { 1, 521, 523, 4890, 4893 }, // 254 SRAWI_rec_SRAW_rec
  { 0, 0, 0, 0, 0 }, // 255 MFFS_MFFSCE_MFFSL_MFFS_rec
  { 1, 523, 525, 4893, 4895 }, // 256 MFCR_MFCR8
  { 1, 521, 523, 4895, 4898 }, // 257 EXTSWSLI_32_64_rec_SRADI_rec_EXTSWSLI_rec_RLDIC_rec
  { 1, 521, 523, 4898, 4901 }, // 258 SRAD_rec_SLD_rec_SRD_rec
  { 1, 531, 533, 4901, 4904 }, // 259 FDIV
  { 1, 531, 533, 4904, 4907 }, // 260 FDIV_rec
  { 1, 531, 533, 4907, 4910 }, // 261 XSSQRTDP
  { 1, 531, 533, 4910, 4913 }, // 262 FSQRT
  { 1, 531, 533, 4913, 4916 }, // 263 XVSQRTDP
  { 1, 531, 533, 4916, 4919 }, // 264 XVSQRTSP
  { 1, 531, 533, 4919, 4922 }, // 265 FSQRT_rec
  { 1, 531, 533, 4922, 4925 }, // 266 XSSQRTSP
  { 1, 531, 533, 4925, 4928 }, // 267 FSQRTS
  { 1, 531, 533, 4928, 4931 }, // 268 FSQRTS_rec
  { 1, 531, 533, 4931, 4934 }, // 269 XSDIVDP
  { 1, 531, 533, 4934, 4937 }, // 270 FDIVS
  { 1, 531, 533, 4937, 4940 }, // 271 FDIVS_rec
  { 1, 531, 533, 4940, 4943 }, // 272 XSDIVSP
  { 1, 531, 533, 4943, 4946 }, // 273 XVDIVSP
  { 1, 531, 533, 4946, 4949 }, // 274 XVDIVDP
  { 1, 557, 561, 4949, 4953 }, // 275 LFSU
  { 1, 557, 561, 4953, 4957 }, // 276 LFSUX
  { 1, 592, 597, 4957, 4961 }, // 277 STFDU_STFDUX_STFSU_STFSUX
  { 1, 605, 609, 4961, 4965 }, // 278 STBU_STBU8_STDU_STHU_STHU8_STWU_STWU8
  { 1, 609, 618, 4965, 4969 }, // 279 STBUX_STBUX8_STDUX_STHUX_STHUX8_STWUX_STWUX8
  { 1, 544, 548, 4969, 4973 }, // 280 LBZU_LBZU8
  { 1, 544, 548, 4973, 4977 }, // 281 LBZUX_LBZUX8
  { 1, 544, 548, 4977, 4981 }, // 282 LDU
  { 1, 544, 548, 4981, 4985 }, // 283 LDUX
  { 1, 557, 561, 4985, 4989 }, // 284 LFDU
  { 1, 557, 561, 4989, 4993 }, // 285 LFDUX
  { 1, 519, 521, 4993, 4996 }, // 286 VPMSUMB_VPMSUMD_VPMSUMH_VPMSUMW_VCIPHER_VCIPHERLAST_VNCIPHER_VNCIPHERLAST_VSBOX
  { 1, 517, 519, 4996, 4999 }, // 287 BCCCTR_BCCCTR8_BCCCTRL_BCCCTRL8_BCCL_BCCLA_BCCLR_BCCLRL_BCCTR_BCCTR8_BCCTR8n_BCCTRL_BCCTRL8_BCCTRL8n_BCCTRLn_BCCTRn_BDNZ_BDNZ8_BDNZA_BDNZAm_BDNZAp_BDNZm_BDNZp_BDZ_BDZ8_BDZA_BDZAm_BDZAp_BDZm_BDZp_BDNZL_BDNZLA_BDNZLAm_BDNZLAp_BDNZLR_BDNZLR8_BDNZLRL_BDNZLRLm_BDNZLRLp_BDNZLRm_BDNZLRp_BDNZLm_BDNZLp_BDZL_BDZLA_BDZLAm_BDZLAp_BDZLR_BDZLR8_BDZLRL_BDZLRLm_BDZLRLp_BDZLRm_BDZLRp_BDZLm_BDZLp_BL_BL_NOP_BL_TLS_BL8_BL8_NOP_BL8_NOP_TLS_BL8_TLS_BL8_TLS__BLA_BLA8_BLA8_NOP_BLR_BLR8_BLRL_TAILB_TAILB8_TAILBA_TAILBA8_TAILBCTR_TAILBCTR8_gBC_gBCA_gBCAat_gBCCTR_gBCCTRL_gBCL_gBCLA_gBCLAat_gBCLR_gBCLRL_gBCLat_gBCat_BCLR_BCLRL_BCLRLn_BCLRn_BCTR_BCTR8_BCTRL_BCTRL8_B_BA_BC_BCC_BCCA_BCL_BCLalways_BCLn_BCTRL8_LDinto_toc_BCTRL_LWZinto_toc_BCn_CTRL_DEP
  { 1, 517, 519, 4999, 5002 }, // 288 ADDPCIS
  { 1, 525, 527, 5002, 5005 }, // 289 LDAT_LWAT
  { 1, 533, 536, 5005, 5008 }, // 290 STDAT_STWAT
  { 1, 515, 517, 5008, 5011 }, // 291 BRINC
  { 1, 519, 521, 5011, 5014 }, // 292 EVABS_EVEQV_EVNAND_EVNEG_EVADDIW_EVADDW_EVAND_EVANDC_EVCMPEQ_EVCMPGTS_EVCMPGTU_EVCMPLTS_EVCMPLTU_EVCNTLSW_EVCNTLZW_EVEXTSB_EVEXTSH_EVMERGEHI_EVMERGEHILO_EVMERGELO_EVMERGELOHI_EVNOR_EVOR_EVORC_EVXOR_EVRLW_EVRLWI_EVRNDW_EVSLW_EVSLWI_EVSPLATFI_EVSPLATI_EVSRWIS_EVSRWIU_EVSRWS_EVSRWU_EVSUBFW_EVSUBIFW
  { 1, 519, 521, 5014, 5017 }, // 293 EVMRA_EVADDSMIAAW_EVADDSSIAAW_EVADDUMIAAW_EVADDUSIAAW_EVDIVWS_EVDIVWU_EVMHEGSMFAA_EVMHEGSMFAN_EVMHEGSMIAA_EVMHEGSMIAN_EVMHEGUMIAA_EVMHEGUMIAN_EVMHESMF_EVMHESMFA_EVMHESMFAAW_EVMHESMFANW_EVMHESMI_EVMHESMIA_EVMHESMIAAW_EVMHESMIANW_EVMHESSF_EVMHESSFA_EVMHESSFAAW_EVMHESSFANW_EVMHESSIAAW_EVMHESSIANW_EVMHEUMI_EVMHEUMIA_EVMHEUMIAAW_EVMHEUMIANW_EVMHEUSIAAW_EVMHEUSIANW_EVMHOGSMFAA_EVMHOGSMFAN_EVMHOGSMIAA_EVMHOGSMIAN_EVMHOGUMIAA_EVMHOGUMIAN_EVMHOSMF_EVMHOSMFA_EVMHOSMFAAW_EVMHOSMFANW_EVMHOSMI_EVMHOSMIA_EVMHOSMIAAW_EVMHOSMIANW_EVMHOSSF_EVMHOSSFA_EVMHOSSFAAW_EVMHOSSFANW_EVMHOSSIAAW_EVMHOSSIANW_EVMHOUMI_EVMHOUMIA_EVMHOUMIAAW_EVMHOUMIANW_EVMHOUSIAAW_EVMHOUSIANW_EVMWHSMF_EVMWHSMFA_EVMWHSMI_EVMWHSMIA_EVMWHSSF_EVMWHSSFA_EVMWHUMI_EVMWHUMIA_EVMWLSMIAAW_EVMWLSMIANW_EVMWLSSIAAW_EVMWLSSIANW_EVMWLUMI_EVMWLUMIA_EVMWLUMIAAW_EVMWLUMIANW_EVMWLUSIAAW_EVMWLUSIANW_EVMWSMF_EVMWSMFA_EVMWSMFAA_EVMWSMFAN_EVMWSMI_EVMWSMIA_EVMWSMIAA_EVMWSMIAN_EVMWSSF_EVMWSSFA_EVMWSSFAA_EVMWSSFAN_EVMWUMI_EVMWUMIA_EVMWUMIAA_EVMWUMIAN_EVSUBFSMIAAW_EVSUBFSSIAAW_EVSUBFUMIAAW_EVSUBFUSIAAW
  { 1, 525, 527, 5017, 5020 }, // 294 EVLDD_EVLDDX_EVLDH_EVLDHX_EVLDW_EVLDWX_EVLHHESPLAT_EVLHHESPLATX_EVLHHOSSPLAT_EVLHHOSSPLATX_EVLHHOUSPLAT_EVLHHOUSPLATX_EVLWHE_EVLWHEX_EVLWHOS_EVLWHOSX_EVLWHOU_EVLWHOUX_EVLWHSPLAT_EVLWHSPLATX_EVLWWSPLAT_EVLWWSPLATX
  { 1, 533, 536, 5020, 5023 }, // 295 EVSTDD_EVSTDDX_EVSTDH_EVSTDHX_EVSTDW_EVSTDWX_EVSTWHE_EVSTWHEX_EVSTWHO_EVSTWHOX_EVSTWWE_EVSTWWEX_EVSTWWO_EVSTWWOX
  { 1, 517, 519, 5023, 5026 }, // 296 HRFID_ATTN_CLRBHRB_MFBHRBE_NAP_RFCI_RFDI_RFMCI_SC
  { 0, 0, 0, 0, 0 }, // 297 RFI
  { 0, 0, 0, 0, 0 }, // 298 RFID
  { 1, 525, 527, 5026, 5029 }, // 299 DSS_DSSALL_DST_DST64_DSTST_DSTST64_DSTSTT_DSTSTT64_DSTT_DSTT64_ICBLQ_LBEPX_LHEPX_LWEPX_TLBIVAX_TLBLD_TLBLI_TLBRE_TLBRE2_TLBSX_TLBSX2_TLBSX2D_TLBWE_TLBWE2_MBAR_TRAP_DCCCI_ICCCI
  { 1, 533, 536, 5029, 5032 }, // 300 ICBLC_STBEPX_STHEPX_STWEPX
  { 1, 555, 557, 5032, 5035 }, // 301 LFDEPX
  { 1, 589, 592, 5035, 5038 }, // 302 STFDEPX
  { 0, 0, 0, 0, 0 }, // 303 MFSR_MFSRIN
  { 0, 0, 0, 0, 0 }, // 304 MTSR_MTSRIN
  { 0, 0, 0, 0, 0 }, // 305 MFDCR
  { 1, 585, 587, 5038, 5040 }, // 306 MTDCR
  { 1, 515, 517, 5040, 5043 }, // 307 NOP_GT_PWR6_NOP_GT_PWR7
  { 0, 0, 0, 0, 0 }, // 308 TLBIA
  { 0, 0, 0, 0, 0 }, // 309 WRTEE_WRTEEI
  { 0, 0, 0, 0, 0 }, // 310 MSYNC
  { 0, 0, 0, 0, 0 }, // 311 SLBSYNC
  { 0, 0, 0, 0, 0 }, // 312 SLBFEE_rec
  { 0, 0, 0, 0, 0 }, // 313 STOP
  { 0, 0, 0, 0, 0 }, // 314 DCBA_DCBI
  { 0, uint16_t(~0U), uint16_t(~0U), uint16_t(~0U), uint16_t(~0U) }// end marker
};

static const llvm::InstrItinerary P7Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 0, 0, 0, 0, 0 }, // 1 IIC_LdStSync
  { 1, 621, 623, 5043, 5046 }, // 2 IIC_IntSimple
  { 1, 623, 625, 5046, 5049 }, // 3 IIC_IntGeneral
  { 1, 625, 627, 5049, 5052 }, // 4 IIC_BrB
  { 1, 627, 629, 5052, 5055 }, // 5 IIC_VecFP
  { 1, 623, 625, 5055, 5058 }, // 6 IIC_IntCompare
  { 0, 0, 0, 0, 0 }, // 7 IIC_SprABORT
  { 0, 0, 0, 0, 0 }, // 8 IIC_LdStCOPY
  { 0, 0, 0, 0, 0 }, // 9 IIC_LdStPASTE
  { 1, 629, 631, 5058, 5061 }, // 10 IIC_BrCR
  { 1, 631, 633, 5061, 5064 }, // 11 IIC_LdStLD
  { 0, 0, 0, 0, 0 }, // 12 IIC_LdStDCBF
  { 1, 631, 633, 5064, 5067 }, // 13 IIC_LdStLoad
  { 1, 633, 636, 5067, 5070 }, // 14 IIC_IntDivD
  { 1, 636, 639, 5070, 5073 }, // 15 IIC_IntDivW
  { 0, 0, 0, 0, 0 }, // 16 IIC_FPDGeneral
  { 1, 639, 641, 5073, 5076 }, // 17 IIC_FPAddSub
  { 1, 639, 641, 5076, 5079 }, // 18 IIC_FPDivD
  { 0, 0, 0, 0, 0 }, // 19 IIC_FPSGeneral
  { 1, 639, 641, 5079, 5082 }, // 20 IIC_FPCompare
  { 1, 639, 641, 5082, 5085 }, // 21 IIC_FPGeneral
  { 1, 641, 643, 5085, 5088 }, // 22 IIC_VecGeneral
  { 1, 641, 643, 5088, 5091 }, // 23 IIC_VecComplex
  { 1, 643, 646, 5091, 5094 }, // 24 IIC_LdStStore
  { 1, 623, 625, 5094, 5097 }, // 25 IIC_IntRotateDI
  { 1, 639, 641, 5097, 5100 }, // 26 IIC_FPDivS
  { 1, 639, 641, 5100, 5104 }, // 27 IIC_FPFused
  { 1, 639, 641, 5104, 5107 }, // 28 IIC_FPSqrtD
  { 1, 639, 641, 5107, 5110 }, // 29 IIC_FPSqrtS
  { 0, 0, 0, 0, 0 }, // 30 IIC_LdStICBI
  { 1, 646, 649, 5110, 5114 }, // 31 IIC_IntISEL
  { 0, 0, 0, 0, 0 }, // 32 IIC_SprISYNC
  { 1, 649, 654, 5114, 5117 }, // 33 IIC_LdStLWARX
  { 1, 654, 658, 5117, 5121 }, // 34 IIC_LdStLoadUpd
  { 1, 658, 665, 5121, 5125 }, // 35 IIC_LdStLoadUpdX
  { 1, 649, 654, 5125, 5128 }, // 36 IIC_LdStLDARX
  { 1, 654, 658, 5128, 5132 }, // 37 IIC_LdStLDU
  { 1, 658, 665, 5132, 5136 }, // 38 IIC_LdStLDUX
  { 1, 631, 633, 5136, 5139 }, // 39 IIC_LdStLFD
  { 1, 654, 658, 5139, 5143 }, // 40 IIC_LdStLFDU
  { 1, 654, 658, 5143, 5147 }, // 41 IIC_LdStLFDUX
  { 1, 665, 669, 5147, 5150 }, // 42 IIC_LdStLHA
  { 1, 669, 674, 5150, 5154 }, // 43 IIC_LdStLHAU
  { 1, 674, 682, 5154, 5158 }, // 44 IIC_LdStLHAUX
  { 1, 631, 633, 5158, 5161 }, // 45 IIC_LdStLMW
  { 1, 665, 669, 5161, 5164 }, // 46 IIC_LdStLWA
  { 1, 623, 625, 5164, 5167 }, // 47 IIC_IntMulHD
  { 1, 625, 627, 5167, 5170 }, // 48 IIC_BrMCR
  { 1, 682, 688, 5170, 5172 }, // 49 IIC_BrMCRX
  { 1, 629, 631, 5172, 5174 }, // 50 IIC_SprMFCR
  { 0, 0, 0, 0, 0 }, // 51 IIC_SprMFSPR
  { 0, 0, 0, 0, 0 }, // 52 IIC_IntMFFS
  { 0, 0, 0, 0, 0 }, // 53 IIC_SprMFMSR
  { 1, 629, 631, 5174, 5176 }, // 54 IIC_SprMFCRF
  { 0, 0, 0, 0, 0 }, // 55 IIC_SprMFPMR
  { 0, 0, 0, 0, 0 }, // 56 IIC_SprMFSR
  { 0, 0, 0, 0, 0 }, // 57 IIC_SprMFTB
  { 0, 0, 0, 0, 0 }, // 58 IIC_SprMSGSYNC
  { 1, 688, 690, 5176, 5178 }, // 59 IIC_SprMTSPR
  { 0, 0, 0, 0, 0 }, // 60 IIC_IntMTFSB0
  { 0, 0, 0, 0, 0 }, // 61 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 62 IIC_SprMTMSRD
  { 0, 0, 0, 0, 0 }, // 63 IIC_SprMTPMR
  { 0, 0, 0, 0, 0 }, // 64 IIC_SprMTSR
  { 1, 623, 625, 5178, 5181 }, // 65 IIC_IntMulHW
  { 1, 623, 625, 5181, 5184 }, // 66 IIC_IntMulHWU
  { 1, 623, 625, 5184, 5187 }, // 67 IIC_IntMulLI
  { 1, 690, 692, 5187, 5190 }, // 68 IIC_VecPerm
  { 1, 692, 695, 5190, 5193 }, // 69 IIC_LdStSTFD
  { 1, 695, 700, 5193, 5197 }, // 70 IIC_LdStSTFDU
  { 0, 0, 0, 0, 0 }, // 71 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 72 IIC_IntRFID
  { 1, 623, 625, 5197, 5200 }, // 73 IIC_IntRotateD
  { 1, 623, 625, 5200, 5203 }, // 74 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 75 IIC_SprSLBFEE
  { 0, 0, 0, 0, 0 }, // 76 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 77 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprSLBIEG
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprSLBMFEV
  { 0, 0, 0, 0, 0 }, // 81 IIC_SprSLBMTE
  { 0, 0, 0, 0, 0 }, // 82 IIC_SprSLBSYNC
  { 1, 623, 625, 5203, 5206 }, // 83 IIC_IntShift
  { 1, 649, 654, 5206, 5209 }, // 84 IIC_LdStSTWCX
  { 1, 669, 674, 5209, 5213 }, // 85 IIC_LdStSTU
  { 1, 700, 707, 5213, 5217 }, // 86 IIC_LdStSTUX
  { 1, 643, 646, 5217, 5220 }, // 87 IIC_LdStSTD
  { 1, 649, 654, 5220, 5223 }, // 88 IIC_LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 89 IIC_SprSTOP
  { 1, 623, 625, 5223, 5225 }, // 90 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 91 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 92 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 93 IIC_SprTLBIEL
  { 0, 0, 0, 0, 0 }, // 94 IIC_SprTLBSYNC
  { 1, 623, 625, 5225, 5227 }, // 95 IIC_IntTrapW
  { 1, 627, 629, 5227, 5230 }, // 96 IIC_VecFPCompare
  { 1, 641, 643, 5230, 5233 }, // 97 VADDUBM_VADDUDM_VADDUHM_VADDUWM_VEXTSB2D_VEXTSB2Ds_VEXTSB2W_VEXTSB2Ws_VEXTSH2D_VEXTSH2Ds_VEXTSH2W_VEXTSH2Ws_VEXTSW2D_VEXTSW2Ds_VSLD_VSRD_VSUBUBM_VSUBUDM_VSUBUHM_VSUBUWM_VPOPCNTB_VPOPCNTH_VSRAD_MTVSRDD_VEQV_VNAND_VNEGD_VNEGW_VORC_XXLAND_XXLANDC_XXLEQV_XXLEQVOnes_XXLNAND_XXLNOR_XXLOR_XXLORf_XXLORC_XXLXOR_XXLXORdpz_XXLXORspz_XXLXORz
  { 1, 627, 629, 5233, 5236 }, // 98 VAND_VANDC_V_SET0_V_SET0B_V_SET0H_VSLB_VSLH_VSLW_VSRB_VSRH_VSRW_VRLB_VRLD_VRLH_VRLW_VSRAB_VSRAH_VSRAW_XVABSDP_XVABSSP_XVNABSDP_XVNABSSP_XVCPSGNDP_XVCPSGNSP_XVIEXPDP_XVIEXPSP_XVXEXPDP_XVXEXPSP_VRLDMI_VRLDNM_VRLWMI_VRLWNM_VMRGEW_VMRGOW_VNOR_VOR_VSEL_VXOR_XVNEGDP_XVNEGSP_XSABSQP_XSCPSGNQP_XSIEXPQP_XSNABSQP_XSNEGQP_XSXEXPQP
  { 1, 690, 692, 5236, 5239 }, // 99 XXSEL
  { 1, 688, 690, 5239, 5241 }, // 100 TABORTDC_TABORTDCI_TABORTWC_TABORTWCI
  { 0, 0, 0, 0, 0 }, // 101 MTFSB0_MTFSB1
  { 0, 0, 0, 0, 0 }, // 102 MFFSCDRN_MFFSCDRNI_MFFSCRN_MFFSCRNI
  { 1, 623, 625, 5241, 5244 }, // 103 CMPRB_CMPRB8_CMPEQB
  { 1, 623, 625, 5244, 5246 }, // 104 TD_TDI
  { 1, 623, 625, 5246, 5248 }, // 105 TW_TWI
  { 1, 639, 641, 5248, 5251 }, // 106 FCMPUD_FCMPUS_FTDIV_FTSQRT
  { 1, 627, 629, 5251, 5254 }, // 107 XSTSTDCDP_XSTSTDCSP
  { 1, 627, 629, 5254, 5257 }, // 108 XSMAXCDP_XSMAXDP_XSMAXJDP_XSMINCDP_XSMINDP_XSMINJDP_XSXSIGDP_XSCVSPDPN
  { 1, 639, 641, 5257, 5260 }, // 109 XSCMPEQDP_XSCMPEXPDP_XSCMPGEDP_XSCMPGTDP_XSCMPODP_XSCMPUDP_XSTDIVDP_XSTSQRTDP
  { 1, 623, 625, 5260, 5263 }, // 110 CNTLZD_CNTLZD_rec_CNTLZW_CNTLZW8_CNTLZW8_rec_CNTLZW_rec_CNTTZD_CNTTZD_rec_CNTTZW_CNTTZW8_CNTTZW8_rec_CNTTZW_rec_POPCNTD_POPCNTW_CMPB_CMPB8_SETB_SETB8_BPERMD
  { 1, 623, 625, 5263, 5266 }, // 111 SLD_SRD_SRAD
  { 1, 623, 625, 5266, 5269 }, // 112 SRADI_EXTSWSLI_32_64_EXTSWSLI_SRADI_32_RLDIC
  { 1, 641, 643, 5269, 5272 }, // 113 MFVRD_MFVSRD_MTVRD_MTVSRD_MTVRWA_MTVRWZ_MTVSRWA_MTVSRWZ_MFVSRWZ_MFVRWZ
  { 1, 623, 625, 5272, 5275 }, // 114 CMPLW_CMPLWI_CMPW_CMPWI_CMPD_CMPDI_CMPLD_CMPLDI
  { 1, 623, 625, 5275, 5278 }, // 115 SUBFC_SUBFC8_SUBFC8O_SUBFCO_SUBFIC_SUBFIC8_ANDI8_rec_ANDIS8_rec_ANDIS_rec_ANDI_rec_ADDC_ADDC8_ADDC8O_ADDCO_ADDIC_ADDIC8_ADDIC_rec_ADDE_ADDE8_ADDE8O_ADDE8O_rec_ADDE8_rec_ADDEO_ADDEO_rec_ADDE_rec_ADDME_ADDME8_ADDME8O_ADDME8O_rec_ADDME8_rec_ADDMEO_ADDMEO_rec_ADDME_rec_ADDZE_ADDZE8_ADDZE8O_ADDZE8O_rec_ADDZE8_rec_ADDZEO_ADDZEO_rec_ADDZE_rec_SUBF_SUBF8_SUBF8O_SUBF8O_rec_SUBF8_rec_SUBFE_SUBFE8_SUBFE8O_SUBFE8O_rec_SUBFE8_rec_SUBFEO_SUBFEO_rec_SUBFE_rec_SUBFME_SUBFME8_SUBFME8O_SUBFME8O_rec_SUBFME8_rec_SUBFMEO_SUBFMEO_rec_SUBFME_rec_SUBFO_SUBFO_rec_SUBFZE_SUBFZE8_SUBFZE8O_SUBFZE8O_rec_SUBFZE8_rec_SUBFZEO_SUBFZEO_rec_SUBFZE_rec_SUBF_rec_POPCNTB_LA
  { 1, 621, 623, 5278, 5281 }, // 116 ADD4_ADD4O_ADD4O_rec_ADD4_rec_ADD8_ADD8O_ADD8O_rec_ADD8_rec_NEG_NEG8_NEG8O_NEG8O_rec_NEG8_rec_NEGO_NEGO_rec_NEG_rec_ADDI_ADDI8_ADDIS_ADDIS8_LI_LI8_LIS_LIS8_OR_OR8_OR8_rec_ORI_ORI8_ORIS_ORIS8_OR_rec_XOR_XOR8_XOR8_rec_XORI_XORI8_XORIS_XORIS8_XOR_rec_NAND_NAND8_NAND8_rec_NAND_rec_AND_AND8_AND8_rec_ANDC_ANDC8_ANDC8_rec_ANDC_rec_AND_rec_NOR_NOR8_NOR8_rec_NOR_rec_ORC_ORC8_ORC8_rec_ORC_rec_EQV_EQV8_EQV8_rec_EQV_rec_EXTSB_EXTSB8_EXTSB8_32_64_EXTSB8_rec_EXTSB_rec_EXTSH_EXTSH8_EXTSH8_32_64_EXTSH8_rec_EXTSH_rec_EXTSW_EXTSW_32_EXTSW_32_64_EXTSW_32_64_rec_EXTSW_rec_ADD4TLS_ADD8TLS_ADD8TLS__NOP
  { 0, 0, 0, 0, 0 }, // 117 ADDIStocHA_ADDIStocHA8_ADDItocL_COPY
  { 1, 625, 627, 5281, 5284 }, // 118 MCRF
  { 1, 682, 688, 5284, 5286 }, // 119 MCRXRX
  { 1, 627, 629, 5286, 5289 }, // 120 XSNABSDP_XSXEXPDP_XSABSDP_XSNEGDP_XSCPSGNDP
  { 1, 625, 627, 5289, 5292 }, // 121 RFEBB
  { 1, 688, 690, 5292, 5294 }, // 122 TBEGIN_TRECHKPT
  { 1, 631, 633, 5294, 5297 }, // 123 WAIT
  { 1, 623, 625, 5297, 5300 }, // 124 RLDCL_RLDCR
  { 1, 623, 625, 5300, 5303 }, // 125 RLWIMI_RLWIMI8
  { 1, 623, 625, 5303, 5306 }, // 126 RLDICL_RLDICL_32_RLDICL_32_64_RLDICR_RLDICR_32_RLDIMI
  { 1, 629, 631, 5306, 5308 }, // 127 MFOCRF_MFOCRF8
  { 1, 682, 688, 5308, 5310 }, // 128 MTOCRF_MTOCRF8
  { 1, 629, 631, 5310, 5313 }, // 129 CR6SET_CR6UNSET_CRSET_CRUNSET_CRAND_CRANDC_CRNAND_CRNOR_CROR_CRORC_CREQV_CRXOR
  { 1, 623, 625, 5313, 5316 }, // 130 SLW_SLW8_SRW_SRW8_RLWINM_RLWINM8_RLWNM_RLWNM8
  { 1, 639, 641, 5316, 5319 }, // 131 FABSD_FABSS_FNABSD_FNABSS_FNEGD_FNEGS_FCPSGND_FCPSGNS_FMR
  { 1, 623, 625, 5319, 5322 }, // 132 SRAW_SRAWI
  { 1, 646, 649, 5322, 5326 }, // 133 ISEL_ISEL8
  { 1, 627, 629, 5326, 5329 }, // 134 XSIEXPDP
  { 1, 688, 690, 5329, 5331 }, // 135 TRECLAIM_TSR_TABORT
  { 1, 643, 646, 5331, 5334 }, // 136 MFVSCR
  { 1, 631, 633, 5334, 5337 }, // 137 MTVSCR
  { 1, 627, 629, 5337, 5340 }, // 138 VCMPNEZB_VCMPNEZH_VCMPNEZW_VCMPEQUB_VCMPEQUD_VCMPEQUH_VCMPEQUW_VCMPNEB_VCMPNEH_VCMPNEW_VCMPEQFP_VCMPEQFP_rec_VCMPGEFP_VCMPGEFP_rec_VCMPGTFP_VCMPGTFP_rec_VCMPBFP_VCMPBFP_rec_VCMPGTSB_VCMPGTSB_rec_VCMPGTSD_VCMPGTSD_rec_VCMPGTSH_VCMPGTSH_rec_VCMPGTSW_VCMPGTSW_rec_VCMPGTUB_VCMPGTUB_rec_VCMPGTUD_VCMPGTUD_rec_VCMPGTUH_VCMPGTUH_rec_VCMPGTUW_VCMPGTUW_rec_VCMPNEB_rec_VCMPNEH_rec_VCMPNEW_rec_VCMPNEZB_rec_VCMPNEZH_rec_VCMPNEZW_rec_VCMPEQUB_rec_VCMPEQUD_rec_VCMPEQUH_rec_VCMPEQUW_rec_XVCMPEQDP_XVCMPEQDP_rec_XVCMPEQSP_XVCMPEQSP_rec_XVCMPGEDP_XVCMPGEDP_rec_XVCMPGESP_XVCMPGESP_rec_XVCMPGTDP_XVCMPGTDP_rec_XVCMPGTSP_XVCMPGTSP_rec
  { 1, 641, 643, 5340, 5343 }, // 139 VABSDUB_VABSDUH_VABSDUW_VCLZB_VCLZD_VCLZH_VCLZW_VCTZB_VCTZD_VCTZH_VCTZW_VPOPCNTW_VPOPCNTD_VPRTYBD_VPRTYBW
  { 1, 627, 629, 5343, 5346 }, // 140 VADDUBS_VADDUHS_VADDUWS_VAVGSB_VAVGSH_VAVGSW_VAVGUB_VAVGUH_VAVGUW_VADDSBS_VADDSHS_VADDSWS_VMAXFP_VMINFP_VMAXSB_VMAXSD_VMAXSH_VMAXSW_VMAXUB_VMAXUD_VMAXUH_VMAXUW_VMINSB_VMINSD_VMINSH_VMINSW_VMINUB_VMINUD_VMINUH_VMINUW_VBPERMD_VADDCUW_VSHASIGMAD_VSHASIGMAW_VSUBSBS_VSUBSHS_VSUBSWS_VSUBUBS_VSUBUHS_VSUBUWS_VSUBCUW_XVMAXDP_XVMAXSP_XVMINDP_XVMINSP_XVTSTDCDP_XVTSTDCSP_XVXSIGDP_XVXSIGSP
  { 1, 639, 641, 5346, 5349 }, // 141 XVTDIVDP_XVTDIVSP_XVTSQRTDP_XVTSQRTSP
  { 1, 627, 629, 5349, 5352 }, // 142 VADDFP_VCTSXS_VCTSXS_0_VCTUXS_VCTUXS_0_VEXPTEFP_VLOGEFP_VMADDFP_VMHADDSHS_VNMSUBFP_VREFP_VRFIM_VRFIN_VRFIP_VRFIZ_VRSQRTEFP_XVADDDP_XVADDSP_XVCVDPSP_XVCVDPSXDS_XVCVDPSXWS_XVCVDPUXDS_XVCVDPUXWS_XVCVHPSP_XVCVSPDP_XVCVSPHP_XVCVSPSXDS_XVCVSPSXWS_XVCVSPUXDS_XVCVSPUXWS_XVCVSXDDP_XVCVSXDSP_XVCVSXWDP_XVCVSXWSP_XVCVUXDDP_XVCVUXDSP_XVCVUXWDP_XVCVUXWSP_XVMADDADP_XVMADDASP_XVMADDMDP_XVMADDMSP_XVMSUBADP_XVMSUBASP_XVMSUBMDP_XVMSUBMSP_XVMULDP_XVMULSP_XVNMADDADP_XVNMADDASP_XVNMADDMDP_XVNMADDMSP_XVNMSUBADP_XVNMSUBASP_XVNMSUBMDP_XVNMSUBMSP_XVRDPI_XVRDPIC_XVRDPIM_XVRDPIP_XVRDPIZ_XVREDP_XVRESP_XVRSPI_XVRSPIC_XVRSPIM_XVRSPIP_XVRSPIZ_XVRSQRTEDP_XVRSQRTESP_XVSUBDP_XVSUBSP_VCFSX_VCFSX_0_VCFUX_VCFUX_0_VMHRADDSHS_VMLADDUHM_VMSUMMBM_VMSUMSHM_VMSUMSHS_VMSUMUBM_VMSUMUHM_VMSUMUDM_VMSUMUHS_VMULESB_VMULESH_VMULESW_VMULEUB_VMULEUH_VMULEUW_VMULOSB_VMULOSH_VMULOSW_VMULOUB_VMULOUH_VMULOUW_VSUM2SWS_VSUM4SBS_VSUM4SHS_VSUM4UBS_VSUMSWS
  { 1, 641, 643, 5352, 5355 }, // 143 VSUBFP_VMULUWM
  { 1, 623, 625, 5355, 5358 }, // 144 MADDHD_MADDHDU_MADDLD_MADDLD8_MULLD_MULLDO
  { 1, 623, 625, 5358, 5361 }, // 145 MULHD_MULHW_MULLW_MULLWO
  { 1, 623, 625, 5361, 5364 }, // 146 MULHDU_MULHWU
  { 1, 623, 625, 5364, 5367 }, // 147 MULLI_MULLI8
  { 1, 639, 641, 5367, 5370 }, // 148 FRSP_FRIMD_FRIMS_FRIND_FRINS_FRIPD_FRIPS_FRIZD_FRIZS_FRE_FRES_FADDS_FMSUBS_FMADDS_FSUBS_FCFID_FCFIDS_FCFIDU_FCFIDUS_FCTID_FCTIDU_FCTIDUZ_FCTIDZ_FCTIW_FCTIWU_FCTIWUZ_FCTIWZ_FRSQRTE_FRSQRTES_FNMADDS_FNMSUBS_FSELD_FSELS_FMULS
  { 1, 639, 641, 5370, 5373 }, // 149 FADD_FSUB
  { 1, 639, 641, 5373, 5377 }, // 150 FMSUB_FMADD_FNMADD_FNMSUB_FMUL
  { 1, 627, 629, 5377, 5380 }, // 151 XSMADDADP_XSMADDASP_XSMADDMDP_XSMADDMSP_XSMSUBADP_XSMSUBASP_XSMSUBMDP_XSMSUBMSP_XSMULDP_XSMULSP_XSNMADDADP_XSNMADDASP_XSNMADDMDP_XSNMADDMSP_XSNMSUBADP_XSNMSUBASP_XSNMSUBMDP_XSNMSUBMSP
  { 1, 639, 641, 5380, 5383 }, // 152 FSELD_rec_FSELS_rec
  { 1, 623, 625, 5383, 5386 }, // 153 MULHDU_rec_MULHWU_rec
  { 1, 623, 625, 5386, 5389 }, // 154 MULHD_rec_MULHW_rec_MULLWO_rec_MULLW_rec
  { 1, 623, 625, 5389, 5392 }, // 155 MULLDO_rec_MULLD_rec
  { 1, 639, 641, 5392, 5395 }, // 156 FRIMD_rec_FRIMS_rec_FRIND_rec_FRINS_rec_FRIPD_rec_FRIPS_rec_FRIZD_rec_FRIZS_rec_FRES_rec_FRE_rec_FADDS_rec_FSUBS_rec_FMSUBS_rec_FNMSUBS_rec_FMADDS_rec_FNMADDS_rec_FCFIDS_rec_FCFIDUS_rec_FCFIDU_rec_FCFID_rec_FCTIDUZ_rec_FCTIDU_rec_FCTIDZ_rec_FCTID_rec_FCTIWUZ_rec_FCTIWU_rec_FCTIWZ_rec_FCTIW_rec_FMULS_rec_FRSQRTES_rec_FRSQRTE_rec_FRSP_rec
  { 1, 639, 641, 5395, 5398 }, // 157 FADD_rec_FSUB_rec
  { 1, 639, 641, 5398, 5402 }, // 158 FMSUB_rec_FNMSUB_rec_FMADD_rec_FNMADD_rec_FMUL_rec
  { 1, 627, 629, 5402, 5405 }, // 159 XSADDDP_XSADDSP_XSCVDPHP_XSCVDPSP_XSCVDPSXDS_XSCVDPSXDSs_XSCVDPSXWS_XSCVDPUXDS_XSCVDPUXDSs_XSCVDPUXWS_XSCVDPSXWSs_XSCVDPUXWSs_XSCVHPDP_XSCVSPDP_XSCVSXDDP_XSCVSXDSP_XSCVUXDDP_XSCVUXDSP_XSRDPI_XSRDPIC_XSRDPIM_XSRDPIP_XSRDPIZ_XSREDP_XSRESP_XSRSQRTEDP_XSRSQRTESP_XSSUBDP_XSSUBSP_XSCVDPSPN_XSRSP
  { 1, 631, 633, 5405, 5408 }, // 160 LVSL_LVSR
  { 1, 690, 692, 5408, 5411 }, // 161 VSPLTISB_VSPLTISH_VSPLTISW_VSPLTB_VSPLTBs_VSPLTH_VSPLTHs_VSPLTW_XXMRGHW_XXMRGLW_XXPERM_XXPERMR_XXSLDWI_XXSLDWIs_XXSPLTIB_XXSPLTW_XXSPLTWs_XXPERMDI_XXPERMDIs
  { 1, 627, 629, 5411, 5414 }, // 162 V_SETALLONES_V_SETALLONESB_V_SETALLONESH_VBPERMQ_VGBBD_VMRGHB_VMRGHH_VMRGHW_VMRGLB_VMRGLH_VMRGLW_VPERM_VPERMR_VPERMXOR_VPKPX_VPKSDSS_VPKSDUS_VPKSHSS_VPKSHUS_VPKSWSS_VPKSWUS_VPKUDUM_VPKUDUS_VPKUHUM_VPKUHUS_VPKUWUM_VPKUWUS_VSL_VSLDOI_VSLO_VSLV_VSR_VSRO_VSRV_VUPKHPX_VUPKHSB_VUPKHSH_VUPKHSW_VUPKLPX_VUPKLSB_VUPKLSH_VUPKLSW_XXBRD_XXBRH_XXBRQ_XXBRW_XXEXTRACTUW_XXINSERTW_VADDCUQ_VADDECUQ_VADDEUQM_VMUL10CUQ_VMUL10ECUQ_VMUL10EUQ_VMUL10UQ_VSUBCUQ_VSUBECUQ_VSUBEUQM_XSTSTDCQP_XSXSIGQP_BCDCFN_rec_BCDCFZ_rec_BCDCPSGN_rec_BCDCTN_rec_BCDCTZ_rec_BCDSETSGN_rec_BCDS_rec_BCDTRUNC_rec_BCDUS_rec_BCDUTRUNC_rec
  { 1, 641, 643, 5414, 5417 }, // 163 VEXTRACTUB_VEXTRACTUH_VEXTRACTUW_VINSERTB_VINSERTD_VINSERTH_VINSERTW_MFVSRLD_MTVSRWS_VCLZLSBB_VCTZLSBB_VEXTRACTD_VEXTUBLX_VEXTUBRX_VEXTUHLX_VEXTUHRX_VEXTUWLX_VEXTUWRX_VPRTYBQ_VADDUQM_VSUBUQM
  { 1, 639, 641, 5417, 5420 }, // 164 XSCMPEXPQP_XSCMPOQP_XSCMPUQP
  { 1, 627, 629, 5420, 5423 }, // 165 BCDSR_rec_XSADDQP_XSADDQPO_XSCVDPQP_XSCVQPDP_XSCVQPDPO_XSCVQPSDZ_XSCVQPSWZ_XSCVQPUDZ_XSCVQPUWZ_XSCVSDQP_XSCVUDQP_XSRQPI_XSRQPIX_XSRQPXP_XSSUBQP_XSSUBQPO
  { 1, 627, 629, 5423, 5426 }, // 166 BCDCTSQ_rec
  { 1, 627, 629, 5426, 5429 }, // 167 XSMADDQP_XSMADDQPO_XSMSUBQP_XSMSUBQPO_XSMULQP_XSMULQPO_XSNMADDQP_XSNMADDQPO_XSNMSUBQP_XSNMSUBQPO
  { 1, 627, 629, 5429, 5432 }, // 168 BCDCFSQ_rec
  { 1, 627, 629, 5432, 5435 }, // 169 XSDIVQP_XSDIVQPO
  { 1, 627, 629, 5435, 5438 }, // 170 XSSQRTQP_XSSQRTQPO
  { 1, 631, 633, 5438, 5441 }, // 171 LXVL_LXVLL
  { 1, 631, 633, 5441, 5444 }, // 172 LVEBX_LVEHX_LVEWX_LVX_LVXL
  { 1, 631, 633, 5444, 5447 }, // 173 LXSIBZX_LXSIHZX_LXSDX_LXVB16X_LXVD2X_LXVWSX_LXSIWZX_LXV_LXVX_LXSD
  { 0, 0, 0, 0, 0 }, // 174 DFLOADf64_XFLOADf64_LIWZX
  { 0, 0, 0, 0, 0 }, // 175 DCBF_DCBFEP_DCBST_DCBSTEP_DCBT_DCBTEP_DCBZ_DCBZEP_DCBZL_DCBZLEP_DCBTST_DCBTSTEP
  { 0, 0, 0, 0, 0 }, // 176 CP_COPY_CP_COPY8
  { 0, 0, 0, 0, 0 }, // 177 CP_PASTE_CP_PASTE8
  { 0, 0, 0, 0, 0 }, // 178 ICBI_ICBIEP
  { 1, 631, 633, 5447, 5450 }, // 179 ICBT_ICBTLS_LBZ_LBZ8_LBZCIX_LBZX_LBZX8_LBZXTLS_LBZXTLS__LBZXTLS_32_LDBRX_LDCIX_LHBRX_LHBRX8_LHZ_LHZ8_LHZCIX_LHZX_LHZX8_LHZXTLS_LHZXTLS__LHZXTLS_32_LWBRX_LWBRX8_LWZ_LWZ8_LWZCIX_LWZX_LWZX8_LWZXTLS_LWZXTLS__LWZXTLS_32_EnforceIEIO_LSWI
  { 1, 649, 654, 5450, 5453 }, // 180 LBARX_LBARXL_LHARX_LHARXL_LWARX_LWARXL
  { 1, 631, 633, 5453, 5456 }, // 181 LD_LDX_LDXTLS_LDXTLS__DARN
  { 1, 649, 654, 5456, 5459 }, // 182 LDARX_LDARXL
  { 0, 0, 0, 0, 0 }, // 183 CP_ABORT
  { 0, 0, 0, 0, 0 }, // 184 ISYNC
  { 0, 0, 0, 0, 0 }, // 185 MSGSYNC
  { 0, 0, 0, 0, 0 }, // 186 TLBSYNC
  { 0, 0, 0, 0, 0 }, // 187 SYNC
  { 1, 631, 633, 5459, 5462 }, // 188 LMW
  { 1, 631, 633, 5462, 5465 }, // 189 LFIWZX_LFDX_LFD
  { 0, 0, 0, 0, 0 }, // 190 SLBIA
  { 0, 0, 0, 0, 0 }, // 191 SLBIE
  { 0, 0, 0, 0, 0 }, // 192 SLBMFEE
  { 0, 0, 0, 0, 0 }, // 193 SLBMFEV
  { 0, 0, 0, 0, 0 }, // 194 SLBMTE
  { 0, 0, 0, 0, 0 }, // 195 TLBIEL
  { 1, 654, 658, 5465, 5469 }, // 196 LHZU_LHZU8_LWZU_LWZU8
  { 1, 658, 665, 5469, 5473 }, // 197 LHZUX_LHZUX8_LWZUX_LWZUX8
  { 1, 688, 690, 5473, 5475 }, // 198 TEND
  { 1, 649, 654, 5475, 5478 }, // 199 STBCX_STHCX_STWCX
  { 1, 649, 654, 5478, 5481 }, // 200 STDCX
  { 1, 631, 633, 5481, 5484 }, // 201 LDMX
  { 1, 665, 669, 5484, 5487 }, // 202 LHA_LHA8_LHAX_LHAX8_LWAX_LWAX_32
  { 0, 0, 0, 0, 0 }, // 203 CP_PASTE8_rec_CP_PASTE_rec
  { 1, 665, 669, 5487, 5490 }, // 204 LWA_LWA_32
  { 1, 688, 690, 5490, 5492 }, // 205 TCHECK
  { 1, 631, 633, 5492, 5495 }, // 206 LFIWAX
  { 1, 631, 633, 5495, 5498 }, // 207 LXSIWAX
  { 0, 0, 0, 0, 0 }, // 208 LIWAX
  { 1, 631, 633, 5498, 5501 }, // 209 LFSX_LFS
  { 1, 631, 633, 5501, 5504 }, // 210 LXSSP_LXSSPX
  { 0, 0, 0, 0, 0 }, // 211 XFLOADf32_DFLOADf32
  { 1, 669, 674, 5504, 5508 }, // 212 LHAU_LHAU8
  { 1, 674, 682, 5508, 5512 }, // 213 LHAUX_LHAUX8_LWAUX
  { 1, 631, 633, 5512, 5515 }, // 214 LXVH8X_LXVDSX_LXVW4X
  { 1, 692, 695, 5515, 5518 }, // 215 STFD_STFDX_STFIWX_STFS_STFSX_STXSD_STXSDX_STXSIBX_STXSIBXv_STXSIHX_STXSIHXv_STXSIWX_STXSSP_STXSSPX
  { 1, 643, 646, 5518, 5521 }, // 216 STW_STW8_STDBRX_STHBRX_STWBRX_STB_STB8_STH_STH8_STBX_STBX8_STBXTLS_STBXTLS__STBXTLS_32_STHX_STHX8_STHXTLS_STHXTLS__STHXTLS_32_STWX_STWX8_STWXTLS_STWXTLS__STWXTLS_32
  { 0, 0, 0, 0, 0 }, // 217 DFSTOREf32_DFSTOREf64_XFSTOREf32_XFSTOREf64_STIWX
  { 1, 643, 646, 5521, 5524 }, // 218 STD_STDX_STDXTLS_STDXTLS_
  { 1, 631, 633, 5524, 5527 }, // 219 STBCIX_STDCIX_STHCIX_STWCIX_STSWI
  { 0, 0, 0, 0, 0 }, // 220 SLBIEG
  { 1, 631, 633, 5527, 5530 }, // 221 STMW
  { 0, 0, 0, 0, 0 }, // 222 TLBIE
  { 1, 643, 646, 5530, 5533 }, // 223 STVEBX_STVEHX_STVEWX_STVX_STVXL
  { 1, 692, 695, 5533, 5536 }, // 224 STXV_STXVB16X_STXVD2X_STXVH8X_STXVW4X_STXVX
  { 1, 631, 633, 5536, 5539 }, // 225 STXVL_STXVLL
  { 1, 688, 690, 5539, 5541 }, // 226 MTCTR_MTCTR8_MTCTR8loop_MTCTRloop_MTLR_MTLR8
  { 1, 623, 625, 5541, 5544 }, // 227 MFVRSAVE_MFVRSAVEv_MTVRSAVE_MTVRSAVEv
  { 0, 0, 0, 0, 0 }, // 228 MFPMR
  { 0, 0, 0, 0, 0 }, // 229 MTPMR
  { 0, 0, 0, 0, 0 }, // 230 MFTB_MFTB8
  { 0, 0, 0, 0, 0 }, // 231 MFCTR_MFCTR8_MFLR_MFLR8_MFSPR_MFSPR8
  { 0, 0, 0, 0, 0 }, // 232 MFMSR
  { 0, 0, 0, 0, 0 }, // 233 MTMSR
  { 0, 0, 0, 0, 0 }, // 234 MTMSRD
  { 1, 688, 690, 5544, 5546 }, // 235 MTSPR_MTSPR8
  { 1, 636, 639, 5546, 5549 }, // 236 DIVW_DIVWO_DIVWU_DIVWUO_MODSW
  { 1, 636, 639, 5549, 5552 }, // 237 DIVWE_DIVWEO_DIVWEU_DIVWEUO_MODSD_MODUD_MODUW
  { 1, 633, 636, 5552, 5555 }, // 238 DIVD_DIVDO_DIVDU_DIVDUO
  { 1, 633, 636, 5555, 5558 }, // 239 DIVDE_DIVDEO_DIVDEU_DIVDEUO
  { 1, 636, 639, 5558, 5561 }, // 240 DIVWO_rec_DIVWUO_rec_DIVWU_rec_DIVW_rec
  { 1, 633, 636, 5561, 5564 }, // 241 DIVD_rec_DIVDO_rec_DIVDU_rec_DIVDUO_rec
  { 1, 636, 639, 5564, 5567 }, // 242 DIVWE_rec_DIVWEO_rec_DIVWEU_rec_DIVWEUO_rec
  { 1, 633, 636, 5567, 5570 }, // 243 DIVDE_rec_DIVDEO_rec_DIVDEU_rec_DIVDEUO_rec
  { 1, 682, 688, 5570, 5572 }, // 244 MTCRF_MTCRF8
  { 1, 623, 625, 5572, 5575 }, // 245 ADDC8O_rec_ADDC8_rec_ADDCO_rec_ADDC_rec_SUBFC8O_rec_SUBFC8_rec_SUBFCO_rec_SUBFC_rec
  { 1, 639, 641, 5575, 5578 }, // 246 FABSD_rec_FABSS_rec_FNABSD_rec_FNABSS_rec_FCPSGND_rec_FCPSGNS_rec_FNEGD_rec_FNEGS_rec_FMR_rec
  { 1, 625, 627, 5578, 5581 }, // 247 MCRFS
  { 0, 0, 0, 0, 0 }, // 248 MTFSF_MTFSF_rec_MTFSFI_MTFSFI_rec
  { 0, 0, 0, 0, 0 }, // 249 MTFSFb
  { 1, 623, 625, 5581, 5584 }, // 250 RLDCL_rec_RLDCR_rec
  { 1, 623, 625, 5584, 5587 }, // 251 RLDICL_rec_RLDICR_rec_RLDICL_32_rec_RLDIMI_rec
  { 1, 623, 625, 5587, 5590 }, // 252 RLWIMI8_rec_RLWIMI_rec
  { 1, 623, 625, 5590, 5593 }, // 253 RLWINM8_rec_RLWINM_rec_RLWNM8_rec_RLWNM_rec_SLW8_rec_SLW_rec_SRW8_rec_SRW_rec
  { 1, 623, 625, 5593, 5596 }, // 254 SRAWI_rec_SRAW_rec
  { 0, 0, 0, 0, 0 }, // 255 MFFS_MFFSCE_MFFSL_MFFS_rec
  { 1, 629, 631, 5596, 5598 }, // 256 MFCR_MFCR8
  { 1, 623, 625, 5598, 5601 }, // 257 EXTSWSLI_32_64_rec_SRADI_rec_EXTSWSLI_rec_RLDIC_rec
  { 1, 623, 625, 5601, 5604 }, // 258 SRAD_rec_SLD_rec_SRD_rec
  { 1, 639, 641, 5604, 5607 }, // 259 FDIV
  { 1, 639, 641, 5607, 5610 }, // 260 FDIV_rec
  { 1, 639, 641, 5610, 5613 }, // 261 XSSQRTDP
  { 1, 639, 641, 5613, 5616 }, // 262 FSQRT
  { 1, 639, 641, 5616, 5619 }, // 263 XVSQRTDP
  { 1, 639, 641, 5619, 5622 }, // 264 XVSQRTSP
  { 1, 639, 641, 5622, 5625 }, // 265 FSQRT_rec
  { 1, 639, 641, 5625, 5628 }, // 266 XSSQRTSP
  { 1, 639, 641, 5628, 5631 }, // 267 FSQRTS
  { 1, 639, 641, 5631, 5634 }, // 268 FSQRTS_rec
  { 1, 639, 641, 5634, 5637 }, // 269 XSDIVDP
  { 1, 639, 641, 5637, 5640 }, // 270 FDIVS
  { 1, 639, 641, 5640, 5643 }, // 271 FDIVS_rec
  { 1, 639, 641, 5643, 5646 }, // 272 XSDIVSP
  { 1, 639, 641, 5646, 5649 }, // 273 XVDIVSP
  { 1, 639, 641, 5649, 5652 }, // 274 XVDIVDP
  { 1, 654, 658, 5652, 5656 }, // 275 LFSU
  { 1, 654, 658, 5656, 5660 }, // 276 LFSUX
  { 1, 695, 700, 5660, 5664 }, // 277 STFDU_STFDUX_STFSU_STFSUX
  { 1, 669, 674, 5664, 5668 }, // 278 STBU_STBU8_STDU_STHU_STHU8_STWU_STWU8
  { 1, 700, 707, 5668, 5672 }, // 279 STBUX_STBUX8_STDUX_STHUX_STHUX8_STWUX_STWUX8
  { 1, 654, 658, 5672, 5676 }, // 280 LBZU_LBZU8
  { 1, 658, 665, 5676, 5680 }, // 281 LBZUX_LBZUX8
  { 1, 654, 658, 5680, 5684 }, // 282 LDU
  { 1, 658, 665, 5684, 5688 }, // 283 LDUX
  { 1, 654, 658, 5688, 5692 }, // 284 LFDU
  { 1, 654, 658, 5692, 5696 }, // 285 LFDUX
  { 1, 627, 629, 5696, 5699 }, // 286 VPMSUMB_VPMSUMD_VPMSUMH_VPMSUMW_VCIPHER_VCIPHERLAST_VNCIPHER_VNCIPHERLAST_VSBOX
  { 1, 625, 627, 5699, 5702 }, // 287 BCCCTR_BCCCTR8_BCCCTRL_BCCCTRL8_BCCL_BCCLA_BCCLR_BCCLRL_BCCTR_BCCTR8_BCCTR8n_BCCTRL_BCCTRL8_BCCTRL8n_BCCTRLn_BCCTRn_BDNZ_BDNZ8_BDNZA_BDNZAm_BDNZAp_BDNZm_BDNZp_BDZ_BDZ8_BDZA_BDZAm_BDZAp_BDZm_BDZp_BDNZL_BDNZLA_BDNZLAm_BDNZLAp_BDNZLR_BDNZLR8_BDNZLRL_BDNZLRLm_BDNZLRLp_BDNZLRm_BDNZLRp_BDNZLm_BDNZLp_BDZL_BDZLA_BDZLAm_BDZLAp_BDZLR_BDZLR8_BDZLRL_BDZLRLm_BDZLRLp_BDZLRm_BDZLRp_BDZLm_BDZLp_BL_BL_NOP_BL_TLS_BL8_BL8_NOP_BL8_NOP_TLS_BL8_TLS_BL8_TLS__BLA_BLA8_BLA8_NOP_BLR_BLR8_BLRL_TAILB_TAILB8_TAILBA_TAILBA8_TAILBCTR_TAILBCTR8_gBC_gBCA_gBCAat_gBCCTR_gBCCTRL_gBCL_gBCLA_gBCLAat_gBCLR_gBCLRL_gBCLat_gBCat_BCLR_BCLRL_BCLRLn_BCLRn_BCTR_BCTR8_BCTRL_BCTRL8_B_BA_BC_BCC_BCCA_BCL_BCLalways_BCLn_BCTRL8_LDinto_toc_BCTRL_LWZinto_toc_BCn_CTRL_DEP
  { 1, 625, 627, 5702, 5705 }, // 288 ADDPCIS
  { 1, 631, 633, 5705, 5708 }, // 289 LDAT_LWAT
  { 1, 643, 646, 5708, 5711 }, // 290 STDAT_STWAT
  { 1, 621, 623, 5711, 5714 }, // 291 BRINC
  { 1, 641, 643, 5714, 5717 }, // 292 EVABS_EVEQV_EVNAND_EVNEG_EVADDIW_EVADDW_EVAND_EVANDC_EVCMPEQ_EVCMPGTS_EVCMPGTU_EVCMPLTS_EVCMPLTU_EVCNTLSW_EVCNTLZW_EVEXTSB_EVEXTSH_EVMERGEHI_EVMERGEHILO_EVMERGELO_EVMERGELOHI_EVNOR_EVOR_EVORC_EVXOR_EVRLW_EVRLWI_EVRNDW_EVSLW_EVSLWI_EVSPLATFI_EVSPLATI_EVSRWIS_EVSRWIU_EVSRWS_EVSRWU_EVSUBFW_EVSUBIFW
  { 1, 641, 643, 5717, 5720 }, // 293 EVMRA_EVADDSMIAAW_EVADDSSIAAW_EVADDUMIAAW_EVADDUSIAAW_EVDIVWS_EVDIVWU_EVMHEGSMFAA_EVMHEGSMFAN_EVMHEGSMIAA_EVMHEGSMIAN_EVMHEGUMIAA_EVMHEGUMIAN_EVMHESMF_EVMHESMFA_EVMHESMFAAW_EVMHESMFANW_EVMHESMI_EVMHESMIA_EVMHESMIAAW_EVMHESMIANW_EVMHESSF_EVMHESSFA_EVMHESSFAAW_EVMHESSFANW_EVMHESSIAAW_EVMHESSIANW_EVMHEUMI_EVMHEUMIA_EVMHEUMIAAW_EVMHEUMIANW_EVMHEUSIAAW_EVMHEUSIANW_EVMHOGSMFAA_EVMHOGSMFAN_EVMHOGSMIAA_EVMHOGSMIAN_EVMHOGUMIAA_EVMHOGUMIAN_EVMHOSMF_EVMHOSMFA_EVMHOSMFAAW_EVMHOSMFANW_EVMHOSMI_EVMHOSMIA_EVMHOSMIAAW_EVMHOSMIANW_EVMHOSSF_EVMHOSSFA_EVMHOSSFAAW_EVMHOSSFANW_EVMHOSSIAAW_EVMHOSSIANW_EVMHOUMI_EVMHOUMIA_EVMHOUMIAAW_EVMHOUMIANW_EVMHOUSIAAW_EVMHOUSIANW_EVMWHSMF_EVMWHSMFA_EVMWHSMI_EVMWHSMIA_EVMWHSSF_EVMWHSSFA_EVMWHUMI_EVMWHUMIA_EVMWLSMIAAW_EVMWLSMIANW_EVMWLSSIAAW_EVMWLSSIANW_EVMWLUMI_EVMWLUMIA_EVMWLUMIAAW_EVMWLUMIANW_EVMWLUSIAAW_EVMWLUSIANW_EVMWSMF_EVMWSMFA_EVMWSMFAA_EVMWSMFAN_EVMWSMI_EVMWSMIA_EVMWSMIAA_EVMWSMIAN_EVMWSSF_EVMWSSFA_EVMWSSFAA_EVMWSSFAN_EVMWUMI_EVMWUMIA_EVMWUMIAA_EVMWUMIAN_EVSUBFSMIAAW_EVSUBFSSIAAW_EVSUBFUMIAAW_EVSUBFUSIAAW
  { 1, 631, 633, 5720, 5723 }, // 294 EVLDD_EVLDDX_EVLDH_EVLDHX_EVLDW_EVLDWX_EVLHHESPLAT_EVLHHESPLATX_EVLHHOSSPLAT_EVLHHOSSPLATX_EVLHHOUSPLAT_EVLHHOUSPLATX_EVLWHE_EVLWHEX_EVLWHOS_EVLWHOSX_EVLWHOU_EVLWHOUX_EVLWHSPLAT_EVLWHSPLATX_EVLWWSPLAT_EVLWWSPLATX
  { 1, 643, 646, 5723, 5726 }, // 295 EVSTDD_EVSTDDX_EVSTDH_EVSTDHX_EVSTDW_EVSTDWX_EVSTWHE_EVSTWHEX_EVSTWHO_EVSTWHOX_EVSTWWE_EVSTWWEX_EVSTWWO_EVSTWWOX
  { 1, 625, 627, 5726, 5729 }, // 296 HRFID_ATTN_CLRBHRB_MFBHRBE_NAP_RFCI_RFDI_RFMCI_SC
  { 0, 0, 0, 0, 0 }, // 297 RFI
  { 0, 0, 0, 0, 0 }, // 298 RFID
  { 1, 631, 633, 5729, 5732 }, // 299 DSS_DSSALL_DST_DST64_DSTST_DSTST64_DSTSTT_DSTSTT64_DSTT_DSTT64_ICBLQ_LBEPX_LHEPX_LWEPX_TLBIVAX_TLBLD_TLBLI_TLBRE_TLBRE2_TLBSX_TLBSX2_TLBSX2D_TLBWE_TLBWE2_MBAR_TRAP_DCCCI_ICCCI
  { 1, 643, 646, 5732, 5735 }, // 300 ICBLC_STBEPX_STHEPX_STWEPX
  { 1, 631, 633, 5735, 5738 }, // 301 LFDEPX
  { 1, 692, 695, 5738, 5741 }, // 302 STFDEPX
  { 0, 0, 0, 0, 0 }, // 303 MFSR_MFSRIN
  { 0, 0, 0, 0, 0 }, // 304 MTSR_MTSRIN
  { 0, 0, 0, 0, 0 }, // 305 MFDCR
  { 1, 688, 690, 5741, 5743 }, // 306 MTDCR
  { 1, 621, 623, 5743, 5746 }, // 307 NOP_GT_PWR6_NOP_GT_PWR7
  { 0, 0, 0, 0, 0 }, // 308 TLBIA
  { 0, 0, 0, 0, 0 }, // 309 WRTEE_WRTEEI
  { 0, 0, 0, 0, 0 }, // 310 MSYNC
  { 0, 0, 0, 0, 0 }, // 311 SLBSYNC
  { 0, 0, 0, 0, 0 }, // 312 SLBFEE_rec
  { 0, 0, 0, 0, 0 }, // 313 STOP
  { 0, 0, 0, 0, 0 }, // 314 DCBA_DCBI
  { 0, uint16_t(~0U), uint16_t(~0U), uint16_t(~0U), uint16_t(~0U) }// end marker
};

// ===============================================================
// Data tables for the new per-operand machine model.

// {ProcResourceIdx, Cycles}
extern const llvm::MCWriteProcResEntry PPCWriteProcResTable[] = {
  { 0,  0}, // Invalid
  { 1,  2}, // #1
  { 2,  1}, // #2
  { 3,  1}, // #3
  { 7,  1}, // #4
  {18,  2}, // #5
  {19,  1}, // #6
  {20,  1}, // #7
  { 1,  1}, // #8
  { 7,  3}, // #9
  { 8,  2}, // #10
  {10,  1}, // #11
  {11,  1}, // #12
  {12,  1}, // #13
  {18,  1}, // #14
  { 1,  1}, // #15
  { 7,  1}, // #16
  {18,  1}, // #17
  { 7,  1}, // #18
  {14,  2}, // #19
  {15,  1}, // #20
  {16,  1}, // #21
  {18,  2}, // #22
  {19,  1}, // #23
  {20,  1}, // #24
  { 7,  3}, // #25
  { 8,  2}, // #26
  {10,  1}, // #27
  {11,  1}, // #28
  {12,  1}, // #29
  {14,  1}, // #30
  {18,  1}, // #31
  { 1,  1}, // #32
  { 7,  4}, // #33
  { 8,  2}, // #34
  {10,  1}, // #35
  {11,  1}, // #36
  {12,  1}, // #37
  {14,  1}, // #38
  {18,  2}, // #39
  { 7,  1}, // #40
  {14,  1}, // #41
  {18,  1}, // #42
  { 7,  1}, // #43
  {18,  2}, // #44
  {19,  1}, // #45
  {20,  1}, // #46
  {22,  1}, // #47
  { 6,  1}, // #48
  { 7,  1}, // #49
  {18,  2}, // #50
  {19,  1}, // #51
  {20,  1}, // #52
  { 6, 11}, // #53
  { 7,  1}, // #54
  {18,  2}, // #55
  {19,  1}, // #56
  {20,  1}, // #57
  { 6, 12}, // #58
  { 7,  1}, // #59
  {18,  2}, // #60
  {19,  1}, // #61
  {20,  1}, // #62
  { 6, 25}, // #63
  { 7,  1}, // #64
  {18,  2}, // #65
  {19,  1}, // #66
  {20,  1}, // #67
  { 6, 44}, // #68
  { 7,  1}, // #69
  {18,  2}, // #70
  {19,  1}, // #71
  {20,  1}, // #72
  { 6, 62}, // #73
  { 7,  1}, // #74
  {18,  2}, // #75
  {19,  1}, // #76
  {20,  1}, // #77
  { 7,  1}, // #78
  {17,  1}, // #79
  {21,  1}, // #80
  { 7,  3}, // #81
  { 8,  2}, // #82
  {10,  1}, // #83
  {11,  1}, // #84
  {12,  1}, // #85
  {17,  1}, // #86
  {21,  1}, // #87
  { 7,  2}, // #88
  { 8,  2}, // #89
  {17,  2}, // #90
  {21,  2}, // #91
  { 1,  1}, // #92
  { 7,  4}, // #93
  { 8,  4}, // #94
  {17,  1}, // #95
  {18,  1}, // #96
  {21,  1}, // #97
  { 1,  1}, // #98
  { 7,  2}, // #99
  {17,  1}, // #100
  {18,  1}, // #101
  {21,  1}, // #102
  { 1,  1}, // #103
  { 7,  4}, // #104
  { 8,  2}, // #105
  {10,  1}, // #106
  {11,  1}, // #107
  {12,  1}, // #108
  {17,  1}, // #109
  {18,  2}, // #110
  {21,  1}, // #111
  { 7,  2}, // #112
  {17,  2}, // #113
  {21,  2}, // #114
  { 1,  1}, // #115
  { 7,  6}, // #116
  { 8,  4}, // #117
  {10,  2}, // #118
  {11,  2}, // #119
  {12,  2}, // #120
  {17,  1}, // #121
  {18,  1}, // #122
  {21,  1}, // #123
  { 1,  2}, // #124
  { 7,  5}, // #125
  { 8,  4}, // #126
  {17,  1}, // #127
  {18,  2}, // #128
  {21,  1}, // #129
  { 7,  2}, // #130
  {17,  1}, // #131
  {18,  2}, // #132
  {19,  1}, // #133
  {20,  1}, // #134
  {21,  1}, // #135
  {22,  1}, // #136
  { 7,  3}, // #137
  { 8,  2}, // #138
  {10,  1}, // #139
  {11,  1}, // #140
  {12,  1}, // #141
  {17,  1}, // #142
  {18,  1}, // #143
  {21,  1}, // #144
  { 7,  1}, // #145
  {17,  1}, // #146
  {18,  2}, // #147
  {19,  1}, // #148
  {20,  1}, // #149
  {21,  1}, // #150
  { 7,  2}, // #151
  { 8,  2}, // #152
  {10,  1}, // #153
  {11,  1}, // #154
  {13,  1}, // #155
  {18,  2}, // #156
  {19,  1}, // #157
  {20,  1}, // #158
  { 7,  2}, // #159
  { 8,  2}, // #160
  {10,  1}, // #161
  {11,  1}, // #162
  {13,  8}, // #163
  {18,  2}, // #164
  {19,  1}, // #165
  {20,  1}, // #166
  { 1,  1}, // #167
  { 7,  3}, // #168
  { 8,  2}, // #169
  {10,  1}, // #170
  {11,  1}, // #171
  {13,  8}, // #172
  {18,  3}, // #173
  {19,  1}, // #174
  {20,  1}, // #175
  { 1,  2}, // #176
  { 7,  6}, // #177
  { 8,  4}, // #178
  {10,  2}, // #179
  {11,  2}, // #180
  {12,  2}, // #181
  {18,  2}, // #182
  { 1,  2}, // #183
  { 7,  2}, // #184
  {18,  2}, // #185
  { 1,  2}, // #186
  { 7,  4}, // #187
  { 8,  2}, // #188
  {10,  1}, // #189
  {11,  1}, // #190
  {12,  1}, // #191
  {18,  2}, // #192
  { 1,  3}, // #193
  { 7,  9}, // #194
  { 8,  6}, // #195
  {10,  3}, // #196
  {11,  3}, // #197
  {12,  3}, // #198
  {18,  3}, // #199
  { 7,  3}, // #200
  { 8,  2}, // #201
  {10,  1}, // #202
  {11,  1}, // #203
  {12,  1}, // #204
  {14,  8}, // #205
  {18,  1}, // #206
  { 1,  1}, // #207
  { 7,  4}, // #208
  { 8,  2}, // #209
  {10,  1}, // #210
  {11,  1}, // #211
  {12,  1}, // #212
  {14,  8}, // #213
  {18,  2}, // #214
  { 7,  1}, // #215
  {14, 10}, // #216
  {18,  1}, // #217
  { 7,  3}, // #218
  { 8,  2}, // #219
  {10,  1}, // #220
  {11,  1}, // #221
  {12,  1}, // #222
  {14, 10}, // #223
  {18,  1}, // #224
  { 7,  1}, // #225
  {14, 20}, // #226
  {18,  2}, // #227
  {19,  1}, // #228
  {20,  1}, // #229
  { 1,  1}, // #230
  { 7,  4}, // #231
  { 8,  2}, // #232
  {10,  1}, // #233
  {11,  1}, // #234
  {12,  1}, // #235
  {14, 10}, // #236
  {18,  2}, // #237
  { 7,  1}, // #238
  {14,  5}, // #239
  {18,  1}, // #240
  { 7,  3}, // #241
  { 8,  2}, // #242
  {10,  1}, // #243
  {11,  1}, // #244
  {12,  1}, // #245
  {14,  5}, // #246
  {18,  1}, // #247
  { 1,  1}, // #248
  { 7,  4}, // #249
  { 8,  2}, // #250
  {10,  1}, // #251
  {11,  1}, // #252
  {12,  1}, // #253
  {14,  5}, // #254
  {18,  2}, // #255
  { 7,  1}, // #256
  {14,  8}, // #257
  {18,  1}, // #258
  { 7,  1}, // #259
  {14, 16}, // #260
  {15,  8}, // #261
  {16,  8}, // #262
  {18,  2}, // #263
  {19,  1}, // #264
  {20,  1}, // #265
  { 1,  2}, // #266
  { 7,  7}, // #267
  { 8,  4}, // #268
  {10,  2}, // #269
  {11,  2}, // #270
  {12,  2}, // #271
  {17,  1}, // #272
  {18,  2}, // #273
  {21,  1}, // #274
  { 1,  1}, // #275
  { 7,  4}, // #276
  { 8,  2}, // #277
  {10,  1}, // #278
  {11,  1}, // #279
  {12,  1}, // #280
  {17,  1}, // #281
  {18,  1}, // #282
  {21,  1}, // #283
  { 5,  1}, // #284
  { 7,  1}, // #285
  {18,  2}, // #286
  {19,  1}, // #287
  {20,  1}, // #288
  { 4,  1}, // #289
  { 7,  1}, // #290
  {12,  1}, // #291
  { 1,  1}, // #292
  { 4,  1}, // #293
  { 7,  2}, // #294
  {12,  1}, // #295
  {18,  1}, // #296
  { 7, 10}, // #297
  { 8,  4}, // #298
  {10,  2}, // #299
  {11,  2}, // #300
  {12,  2}, // #301
  {17,  5}, // #302
  {18,  2}, // #303
  {21,  5}, // #304
  { 7,  5}, // #305
  { 8,  2}, // #306
  {10,  1}, // #307
  {11,  1}, // #308
  {12,  1}, // #309
  {17,  3}, // #310
  {18,  1}, // #311
  {21,  3} // #312
}; // PPCWriteProcResTable

// {Cycles, WriteResourceID}
extern const llvm::MCWriteLatencyEntry PPCWriteLatencyTable[] = {
  { 0,  0}, // Invalid
  { 2,  0}, // #1 P9_ALUE_2C
  { 2,  0}, // #2 P9_ALUO_2C_P9_ALU_2C_P9_BR_2C
  { 1,  0}, // #3 IP_EXECE_1C_IP_EXEC_1C_DISP_BR_1C
  { 1,  0}, // #4 IP_EXECO_1C_DISP_1C_DISP_3SLOTS_1C
  { 1,  0}, // #5 DISP_1C
  { 3,  0}, // #6 P9_ALU_3C
  { 1,  0}, // #7 IP_EXEC_1C
  { 1,  0}, // #8 DISP_3SLOTS_1C_DISP_1C
  { 3,  0}, // #9 P9_ALUE_3C
  { 3,  0}, // #10 P9_ALUO_3C_P9_PM_3C
  { 1,  0}, // #11 IP_EXECE_1C_IP_EXECO_1C
  { 1,  0}, // #12 IP_EXECO_1C_IP_EXECE_1C
  { 1,  0}, // #13 DISP_1C
  { 7,  0}, // #14 P9_DPE_7C
  { 7,  0}, // #15 P9_DPO_7C_P9_DP_7C_P9_ALU_2C
  { 1,  0}, // #16 IP_EXECE_1C_IP_EXEC_1C
  { 1,  0}, // #17 IP_EXECO_1C_DISP_3SLOTS_1C_DISP_1C_DISP_BR_1C
  { 1,  0}, // #18 DISP_1C
  { 5,  0}, // #19 P9_DP_5C_P9_LS_5C
  { 1,  0}, // #20 IP_EXEC_1C_IP_AGEN_1C
  { 1,  0}, // #21 DISP_3SLOTS_1C_DISP_1C
  { 7,  0}, // #22 P9_DP_7C
  { 3,  0}, // #23 P9_ALU_3C
  { 1,  0}, // #24 IP_EXEC_1C_P9_LS_1C
  { 1,  0}, // #25 IP_EXEC_1C
  { 1,  0}, // #26 DISP_3SLOTS_1C_IP_AGEN_1C
  { 1,  0}, // #27 DISP_1C_DISP_3SLOTS_1C
  { 7,  0}, // #28 P9_ALU_2C_P9_ALU_3C
  { 1,  0}, // #29 IP_EXEC_1C_IP_AGEN_1C
  { 1,  0}, // #30 IP_EXEC_1C
  { 1,  0}, // #31 DISP_3SLOTS_1C_DISP_1C
  { 1,  0}, // #32 DISP_1C_DISP_3SLOTS_1C
  {10,  0}, // #33 P9_ALU_3C
  { 1,  0}, // #34 IP_EXEC_1C
  { 1,  0}, // #35 IP_EXEC_1C
  { 1,  0}, // #36 DISP_3SLOTS_1C
  { 1,  0}, // #37 DISP_1C
  {12,  0}, // #38 P9_DFU_12C_P9_DIV_12C
  { 1,  0}, // #39 IP_EXECE_1C
  { 1,  0}, // #40 IP_EXECO_1C
  { 1,  0}, // #41 DISP_1C_DISP_EVEN_1C
  {23,  0}, // #42 P9_DFU_23C
  { 1,  0}, // #43 IP_EXECE_1C
  { 1,  0}, // #44 IP_EXECO_1C
  { 1,  0}, // #45 DISP_1C
  {24,  0}, // #46 P9_DFU_24C_P9_DIV_24C_8
  { 1,  0}, // #47 IP_EXECE_1C_IP_EXECO_1C
  { 1,  0}, // #48 IP_EXECO_1C_IP_EXECE_1C
  { 1,  0}, // #49 DISP_1C_DISP_EVEN_1C
  {37,  0}, // #50 P9_DFU_37C
  { 1,  0}, // #51 IP_EXECE_1C
  { 1,  0}, // #52 IP_EXECO_1C
  { 1,  0}, // #53 DISP_1C
  {58,  0}, // #54 P9_DFU_58C
  { 1,  0}, // #55 IP_EXECE_1C
  { 1,  0}, // #56 IP_EXECO_1C
  { 1,  0}, // #57 DISP_1C
  {76,  0}, // #58 P9_DFU_76C
  { 1,  0}, // #59 IP_EXECE_1C
  { 1,  0}, // #60 IP_EXECO_1C
  { 1,  0}, // #61 DISP_1C
  { 6,  0}, // #62 P9_LS_6C
  { 1,  0}, // #63 IP_AGEN_1C
  { 1,  0}, // #64 DISP_1C
  { 4,  0}, // #65 P9_LS_4C
  { 1,  0}, // #66 IP_AGEN_1C
  { 1,  0}, // #67 DISP_1C_DISP_3SLOTS_1C
  { 4,  0}, // #68 P9_LS_4C
  { 4,  0}, // #69 P9_LS_4C
  { 1,  0}, // #70 IP_AGEN_1C
  { 1,  0}, // #71 IP_AGEN_1C
  { 1,  0}, // #72 DISP_PAIR_1C
  { 4,  0}, // #73 P9_LS_4C
  { 2,  0}, // #74 P9_ALU_2C
  { 1,  0}, // #75 IP_EXEC_1C_IP_AGEN_1C
  { 1,  0}, // #76 IP_AGEN_1C_IP_EXEC_1C
  { 1,  0}, // #77 DISP_PAIR_1C_DISP_1C_DISP_3SLOTS_1C
  { 1,  0}, // #78 DISP_PAIR_1C_DISP_1C
  { 3,  0}, // #79 P9_ALU_2C
  { 1,  0}, // #80 IP_EXEC_1C_P9_LS_1C
  { 1,  0}, // #81 IP_EXEC_1C_IP_EXECE_1C
  { 1,  0}, // #82 IP_AGEN_1C_IP_EXECO_1C
  { 1,  0}, // #83 DISP_3SLOTS_1C_IP_AGEN_1C
  { 1,  0}, // #84 DISP_1C
  { 8,  0}, // #85 P9_LS_4C_P9_ALU_3C
  { 1,  0}, // #86 IP_AGEN_1C
  { 1,  0}, // #87 IP_AGEN_1C_IP_EXEC_1C
  { 1,  0}, // #88 DISP_1C
  { 1,  0}, // #89 DISP_1C
  { 6,  0}, // #90 P9_ALU_2C_P9_ALU_3C_P9_CY_6C
  { 1,  0}, // #91 IP_EXEC_1C_IP_EXECO_1C
  { 1,  0}, // #92 IP_AGEN_1C_IP_EXEC_1C_IP_EXECE_1C
  { 1,  0}, // #93 DISP_1C_DISP_3SLOTS_1C
  { 1,  0}, // #94 DISP_1C_DISP_3SLOTS_1C
  { 6,  0}, // #95 P9_ALU_2C
  { 2,  0}, // #96 P9_ALU_2C
  { 1,  0}, // #97 IP_AGEN_1C
  { 1,  0}, // #98 IP_EXEC_1C
  { 1,  0}, // #99 IP_EXEC_1C
  { 1,  0}, // #100 DISP_PAIR_1C
  { 1,  0}, // #101 DISP_PAIR_1C
  { 1,  0}, // #102 DISP_1C
  { 8,  0}, // #103 P9_PM_3C
  { 1,  0}, // #104 IP_AGEN_1C
  { 1,  0}, // #105 IP_EXECE_1C
  { 1,  0}, // #106 IP_EXECO_1C
  { 1,  0}, // #107 DISP_1C
  { 1,  0}, // #108 DISP_1C
  { 5,  0}, // #109 P9_DIV_5C
  { 1,  0}, // #110 IP_EXECE_1C
  { 1,  0}, // #111 IP_EXECO_1C
  { 1,  0}, // #112 DISP_EVEN_1C
  {16,  0}, // #113 P9_DIV_16C_8
  { 1,  0}, // #114 IP_EXECO_1C
  { 1,  0}, // #115 IP_EXECE_1C
  { 1,  0}, // #116 DISP_EVEN_1C
  {40,  0}, // #117 P9_DIV_40C_8
  { 1,  0}, // #118 IP_EXECO_1C
  { 1,  0}, // #119 IP_EXECE_1C
  { 1,  0}, // #120 DISP_EVEN_1C
  {18,  0}, // #121 P9_ALU_2C
  { 1,  0}, // #122 IP_EXECE_1C
  { 1,  0}, // #123 IP_EXECO_1C
  { 1,  0}, // #124 IP_EXEC_1C
  { 1,  0}, // #125 DISP_EVEN_1C
  { 1,  0}, // #126 DISP_1C
  {26,  0}, // #127 P9_ALU_2C
  { 1,  0}, // #128 IP_EXECE_1C
  { 1,  0}, // #129 IP_EXECO_1C
  { 1,  0}, // #130 IP_EXEC_1C
  { 1,  0}, // #131 DISP_EVEN_1C
  { 1,  0}, // #132 DISP_1C
  {42,  0}, // #133 P9_ALU_2C
  { 1,  0}, // #134 IP_EXECE_1C
  { 1,  0}, // #135 IP_EXECO_1C
  { 1,  0}, // #136 IP_EXEC_1C
  { 1,  0}, // #137 DISP_EVEN_1C
  { 1,  0}, // #138 DISP_1C
  { 2,  0}, // #139 P9_ALU_2C
  { 2,  0}, // #140 P9_ALU_2C
  { 1,  0}, // #141 IP_EXEC_1C
  { 1,  0}, // #142 IP_EXEC_1C
  { 1,  0}, // #143 DISP_3SLOTS_1C_DISP_1C
  { 1,  0}, // #144 DISP_3SLOTS_1C_DISP_1C
  { 2,  0}, // #145 P9_ALU_2C
  { 3,  0}, // #146 P9_ALU_3C
  { 1,  0}, // #147 IP_EXEC_1C
  { 1,  0}, // #148 IP_EXEC_1C
  { 1,  0}, // #149 DISP_3SLOTS_1C
  { 1,  0}, // #150 DISP_1C
  { 3,  0}, // #151 P9_ALU_3C
  { 3,  0}, // #152 P9_ALU_3C
  { 1,  0}, // #153 IP_EXEC_1C
  { 1,  0}, // #154 IP_EXEC_1C
  { 1,  0}, // #155 DISP_1C_DISP_3SLOTS_1C
  { 1,  0}, // #156 DISP_1C_DISP_3SLOTS_1C
  { 4,  0}, // #157 P9_ALU_2C
  { 1,  0}, // #158 IP_EXEC_1C
  { 1,  0}, // #159 IP_EXEC_1C
  { 1,  0}, // #160 DISP_3SLOTS_1C_DISP_1C
  { 1,  0}, // #161 DISP_1C
  { 6,  0}, // #162 P9_ALU_2C
  { 1,  0}, // #163 IP_EXEC_1C
  { 1,  0}, // #164 IP_EXEC_1C
  { 1,  0}, // #165 IP_EXEC_1C
  { 1,  0}, // #166 DISP_3SLOTS_1C
  { 1,  0}, // #167 DISP_3SLOTS_1C
  { 1,  0}, // #168 DISP_3SLOTS_1C
  {33,  0}, // #169 P9_DP_33C_8
  { 1,  0}, // #170 IP_EXEC_1C
  { 1,  0}, // #171 DISP_3SLOTS_1C_DISP_1C
  {36,  0}, // #172 P9_ALU_3C_P9_DP_36C_10
  { 1,  0}, // #173 IP_EXEC_1C
  { 1,  0}, // #174 IP_EXEC_1C_DISP_1C_DISP_3SLOTS_1C
  { 1,  0}, // #175 DISP_3SLOTS_1C
  { 1,  0}, // #176 DISP_1C
  {36,  0}, // #177 P9_DPE_36C_10
  {36,  0}, // #178 P9_DPO_36C_10
  { 1,  0}, // #179 IP_EXECE_1C
  { 1,  0}, // #180 IP_EXECO_1C
  { 1,  0}, // #181 DISP_1C
  {27,  0}, // #182 P9_DPE_27C_10
  {27,  0}, // #183 P9_DPO_27C_10
  { 1,  0}, // #184 IP_EXECE_1C
  { 1,  0}, // #185 IP_EXECO_1C
  { 1,  0}, // #186 DISP_1C
  {39,  0}, // #187 P9_ALU_3C
  { 1,  0}, // #188 IP_EXEC_1C
  { 1,  0}, // #189 IP_EXEC_1C
  { 1,  0}, // #190 DISP_3SLOTS_1C
  { 1,  0}, // #191 DISP_1C
  {22,  0}, // #192 P9_DP_26C_5_P9_DP_22C_5
  { 1,  0}, // #193 IP_EXEC_1C
  { 1,  0}, // #194 DISP_1C_DISP_3SLOTS_1C
  {25,  0}, // #195 P9_ALU_3C
  { 1,  0}, // #196 IP_EXEC_1C
  { 1,  0}, // #197 IP_EXEC_1C
  { 1,  0}, // #198 DISP_3SLOTS_1C
  { 1,  0}, // #199 DISP_1C
  {24,  0}, // #200 P9_DPE_24C_8
  {24,  0}, // #201 P9_DPO_24C_8
  { 1,  0}, // #202 IP_EXECE_1C
  { 1,  0}, // #203 IP_EXECO_1C
  { 1,  0}, // #204 DISP_1C
  {33,  0}, // #205 P9_DPE_33C_8
  {33,  0}, // #206 P9_DPO_33C_8
  { 1,  0}, // #207 IP_EXECE_1C
  { 1,  0}, // #208 IP_EXECO_1C
  { 1,  0}, // #209 DISP_1C
  { 7,  0}, // #210 P9_ALU_3C
  { 2,  0}, // #211 P9_ALU_2C
  { 1,  0}, // #212 IP_AGEN_1C
  { 1,  0}, // #213 IP_EXEC_1C
  { 1,  0}, // #214 IP_EXEC_1C
  { 1,  0}, // #215 DISP_3SLOTS_1C
  { 1,  0}, // #216 DISP_3SLOTS_1C
  { 1,  0}, // #217 DISP_1C
  { 1,  0}, // #218 P9_LS_1C
  { 2,  0}, // #219 P9_ALU_2C
  { 1,  0}, // #220 IP_AGEN_1C
  { 1,  0}, // #221 IP_EXEC_1C
  { 1,  0}, // #222 IP_EXEC_1C
  { 1,  0}, // #223 DISP_3SLOTS_1C
  { 1,  0}, // #224 DISP_1C
  { 1,  0}, // #225 P9_LS_1C
  { 1,  0}, // #226 P9_LS_1C
  { 4,  0}, // #227 P9_LS_4C
  { 4,  0}, // #228 P9_LS_4C
  { 4,  0}, // #229 P9_LS_4C
  { 1,  0}, // #230 IP_EXEC_1C
  { 1,  0}, // #231 IP_EXEC_1C
  { 1,  0}, // #232 IP_AGEN_1C
  { 1,  0}, // #233 IP_AGEN_1C
  { 1,  0}, // #234 IP_AGEN_1C
  { 1,  0}, // #235 IP_AGEN_1C
  { 1,  0}, // #236 IP_AGEN_1C
  { 1,  0}, // #237 DISP_1C
  { 1,  0}, // #238 DISP_3SLOTS_1C
  { 1,  0}, // #239 DISP_3SLOTS_1C
  { 1,  0}, // #240 DISP_1C
  { 1,  0}, // #241 DISP_1C
  { 1,  0}, // #242 DISP_1C
  { 1,  0}, // #243 P9_LS_1C
  { 4,  0}, // #244 P9_LS_4C
  { 4,  0}, // #245 P9_LS_4C
  { 1,  0}, // #246 IP_EXEC_1C
  { 1,  0}, // #247 IP_AGEN_1C
  { 1,  0}, // #248 IP_AGEN_1C
  { 1,  0}, // #249 IP_AGEN_1C
  { 1,  0}, // #250 DISP_1C
  { 1,  0}, // #251 DISP_3SLOTS_1C
  { 1,  0} // #252 DISP_1C
}; // PPCWriteLatencyTable

// {UseIdx, WriteResourceID, Cycles}
extern const llvm::MCReadAdvanceEntry PPCReadAdvanceTable[] = {
  {0,  0,  0}, // Invalid
}; // PPCReadAdvanceTable

// {Name, NumMicroOps, BeginGroup, EndGroup, WriteProcResIdx,#, WriteLatencyIdx,#, ReadAdvanceIdx,#}
static const llvm::MCSchedClassDesc P9ModelSchedClasses[] = {
  {DBGFIELD("InvalidSchedClass")  16383, false, false,  0, 0,  0, 0,  0, 0},
  {DBGFIELD("IIC_LdStSync")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #1
  {DBGFIELD("IIC_IntSimple")      16383, false, false,  0, 0,  0, 0,  0, 0}, // #2
  {DBGFIELD("IIC_IntGeneral")     16383, false, false,  0, 0,  0, 0,  0, 0}, // #3
  {DBGFIELD("IIC_BrB")            16383, false, false,  0, 0,  0, 0,  0, 0}, // #4
  {DBGFIELD("IIC_VecFP")          16383, false, false,  0, 0,  0, 0,  0, 0}, // #5
  {DBGFIELD("IIC_IntCompare")     16383, false, false,  0, 0,  0, 0,  0, 0}, // #6
  {DBGFIELD("IIC_SprABORT")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #7
  {DBGFIELD("IIC_LdStCOPY")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #8
  {DBGFIELD("IIC_LdStPASTE")      16383, false, false,  0, 0,  0, 0,  0, 0}, // #9
  {DBGFIELD("IIC_BrCR")           16383, false, false,  0, 0,  0, 0,  0, 0}, // #10
  {DBGFIELD("IIC_LdStLD")         16383, false, false,  0, 0,  0, 0,  0, 0}, // #11
  {DBGFIELD("IIC_LdStDCBF")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #12
  {DBGFIELD("IIC_LdStLoad")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #13
  {DBGFIELD("IIC_IntDivD")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #14
  {DBGFIELD("IIC_IntDivW")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #15
  {DBGFIELD("IIC_FPDGeneral")     16383, false, false,  0, 0,  0, 0,  0, 0}, // #16
  {DBGFIELD("IIC_FPAddSub")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #17
  {DBGFIELD("IIC_FPDivD")         16383, false, false,  0, 0,  0, 0,  0, 0}, // #18
  {DBGFIELD("IIC_FPSGeneral")     16383, false, false,  0, 0,  0, 0,  0, 0}, // #19
  {DBGFIELD("IIC_FPCompare")      16383, false, false,  0, 0,  0, 0,  0, 0}, // #20
  {DBGFIELD("IIC_FPGeneral")      16383, false, false,  0, 0,  0, 0,  0, 0}, // #21
  {DBGFIELD("IIC_VecGeneral")     16383, false, false,  0, 0,  0, 0,  0, 0}, // #22
  {DBGFIELD("IIC_VecComplex")     16383, false, false,  0, 0,  0, 0,  0, 0}, // #23
  {DBGFIELD("IIC_LdStStore")      16383, false, false,  0, 0,  0, 0,  0, 0}, // #24
  {DBGFIELD("IIC_IntRotateDI")    16383, false, false,  0, 0,  0, 0,  0, 0}, // #25
  {DBGFIELD("IIC_FPDivS")         16383, false, false,  0, 0,  0, 0,  0, 0}, // #26
  {DBGFIELD("IIC_FPFused")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #27
  {DBGFIELD("IIC_FPSqrtD")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #28
  {DBGFIELD("IIC_FPSqrtS")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #29
  {DBGFIELD("IIC_LdStICBI")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #30
  {DBGFIELD("IIC_IntISEL")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #31
  {DBGFIELD("IIC_SprISYNC")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #32
  {DBGFIELD("IIC_LdStLWARX")      16383, false, false,  0, 0,  0, 0,  0, 0}, // #33
  {DBGFIELD("IIC_LdStLoadUpd")    16383, false, false,  0, 0,  0, 0,  0, 0}, // #34
  {DBGFIELD("IIC_LdStLoadUpdX")   16383, false, false,  0, 0,  0, 0,  0, 0}, // #35
  {DBGFIELD("IIC_LdStLDARX")      16383, false, false,  0, 0,  0, 0,  0, 0}, // #36
  {DBGFIELD("IIC_LdStLDU")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #37
  {DBGFIELD("IIC_LdStLDUX")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #38
  {DBGFIELD("IIC_LdStLFD")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #39
  {DBGFIELD("IIC_LdStLFDU")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #40
  {DBGFIELD("IIC_LdStLFDUX")      16383, false, false,  0, 0,  0, 0,  0, 0}, // #41
  {DBGFIELD("IIC_LdStLHA")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #42
  {DBGFIELD("IIC_LdStLHAU")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #43
  {DBGFIELD("IIC_LdStLHAUX")      16383, false, false,  0, 0,  0, 0,  0, 0}, // #44
  {DBGFIELD("IIC_LdStLMW")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #45
  {DBGFIELD("IIC_LdStLWA")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #46
  {DBGFIELD("IIC_IntMulHD")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #47
  {DBGFIELD("IIC_BrMCR")          16383, false, false,  0, 0,  0, 0,  0, 0}, // #48
  {DBGFIELD("IIC_BrMCRX")         16383, false, false,  0, 0,  0, 0,  0, 0}, // #49
  {DBGFIELD("IIC_SprMFCR")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #50
  {DBGFIELD("IIC_SprMFSPR")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #51
  {DBGFIELD("IIC_IntMFFS")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #52
  {DBGFIELD("IIC_SprMFMSR")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #53
  {DBGFIELD("IIC_SprMFCRF")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #54
  {DBGFIELD("IIC_SprMFPMR")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #55
  {DBGFIELD("IIC_SprMFSR")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #56
  {DBGFIELD("IIC_SprMFTB")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #57
  {DBGFIELD("IIC_SprMSGSYNC")     16383, false, false,  0, 0,  0, 0,  0, 0}, // #58
  {DBGFIELD("IIC_SprMTSPR")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #59
  {DBGFIELD("IIC_IntMTFSB0")      16383, false, false,  0, 0,  0, 0,  0, 0}, // #60
  {DBGFIELD("IIC_SprMTMSR")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #61
  {DBGFIELD("IIC_SprMTMSRD")      16383, false, false,  0, 0,  0, 0,  0, 0}, // #62
  {DBGFIELD("IIC_SprMTPMR")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #63
  {DBGFIELD("IIC_SprMTSR")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #64
  {DBGFIELD("IIC_IntMulHW")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #65
  {DBGFIELD("IIC_IntMulHWU")      16383, false, false,  0, 0,  0, 0,  0, 0}, // #66
  {DBGFIELD("IIC_IntMulLI")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #67
  {DBGFIELD("IIC_VecPerm")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #68
  {DBGFIELD("IIC_LdStSTFD")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #69
  {DBGFIELD("IIC_LdStSTFDU")      16383, false, false,  0, 0,  0, 0,  0, 0}, // #70
  {DBGFIELD("IIC_SprRFI")         16383, false, false,  0, 0,  0, 0,  0, 0}, // #71
  {DBGFIELD("IIC_IntRFID")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #72
  {DBGFIELD("IIC_IntRotateD")     16383, false, false,  0, 0,  0, 0,  0, 0}, // #73
  {DBGFIELD("IIC_IntRotate")      16383, false, false,  0, 0,  0, 0,  0, 0}, // #74
  {DBGFIELD("IIC_SprSLBFEE")      16383, false, false,  0, 0,  0, 0,  0, 0}, // #75
  {DBGFIELD("IIC_SprSLBIA")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #76
  {DBGFIELD("IIC_SprSLBIE")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #77
  {DBGFIELD("IIC_SprSLBIEG")      16383, false, false,  0, 0,  0, 0,  0, 0}, // #78
  {DBGFIELD("IIC_SprSLBMFEE")     16383, false, false,  0, 0,  0, 0,  0, 0}, // #79
  {DBGFIELD("IIC_SprSLBMFEV")     16383, false, false,  0, 0,  0, 0,  0, 0}, // #80
  {DBGFIELD("IIC_SprSLBMTE")      16383, false, false,  0, 0,  0, 0,  0, 0}, // #81
  {DBGFIELD("IIC_SprSLBSYNC")     16383, false, false,  0, 0,  0, 0,  0, 0}, // #82
  {DBGFIELD("IIC_IntShift")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #83
  {DBGFIELD("IIC_LdStSTWCX")      16383, false, false,  0, 0,  0, 0,  0, 0}, // #84
  {DBGFIELD("IIC_LdStSTU")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #85
  {DBGFIELD("IIC_LdStSTUX")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #86
  {DBGFIELD("IIC_LdStSTD")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #87
  {DBGFIELD("IIC_LdStSTDCX")      16383, false, false,  0, 0,  0, 0,  0, 0}, // #88
  {DBGFIELD("IIC_SprSTOP")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #89
  {DBGFIELD("IIC_IntTrapD")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #90
  {DBGFIELD("IIC_SprTLBIA")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #91
  {DBGFIELD("IIC_SprTLBIE")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #92
  {DBGFIELD("IIC_SprTLBIEL")      16383, false, false,  0, 0,  0, 0,  0, 0}, // #93
  {DBGFIELD("IIC_SprTLBSYNC")     16383, false, false,  0, 0,  0, 0,  0, 0}, // #94
  {DBGFIELD("IIC_IntTrapW")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #95
  {DBGFIELD("IIC_VecFPCompare")   16383, false, false,  0, 0,  0, 0,  0, 0}, // #96
  {DBGFIELD("VADDUBM_VADDUDM_VADDUHM_VADDUWM_VEXTSB2D_VEXTSB2Ds_VEXTSB2W_VEXTSB2Ws_VEXTSH2D_VEXTSH2Ds_VEXTSH2W_VEXTSH2Ws_VEXTSW2D_VEXTSW2Ds_VSLD_VSRD_VSUBUBM_VSUBUDM_VSUBUHM_VSUBUWM_VPOPCNTB_VPOPCNTH_VSRAD_MTVSRDD_VEQV_VNAND_VNEGD_VNEGW_VORC_XXLAND_XXLANDC_XXLEQV_XXLEQVOnes_XXLNAND_XXLNOR_XXLOR_XXLORf_XXLORC_XXLXOR_XXLXORdpz_XXLXORspz_XXLXORz") 2, false, false,  1, 7,  1, 5,  0, 0}, // #97
  {DBGFIELD("VAND_VANDC_V_SET0_V_SET0B_V_SET0H_VSLB_VSLH_VSLW_VSRB_VSRH_VSRW_VRLB_VRLD_VRLH_VRLW_VSRAB_VSRAH_VSRAW_XVABSDP_XVABSSP_XVNABSDP_XVNABSSP_XVCPSGNDP_XVCPSGNSP_XVIEXPDP_XVIEXPSP_XVXEXPDP_XVXEXPSP_VRLDMI_VRLDNM_VRLWMI_VRLWNM_VMRGEW_VMRGOW_VNOR_VOR_VSEL_VXOR_XVNEGDP_XVNEGSP_XSABSQP_XSCPSGNQP_XSIEXPQP_XSNABSQP_XSNEGQP_XSXEXPQP") 2, false, false,  1, 7,  1, 5,  0, 0}, // #98
  {DBGFIELD("XXSEL")              2, false, false,  1, 7,  1, 5,  0, 0}, // #99
  {DBGFIELD("TABORTDC_TABORTDCI_TABORTWC_TABORTWCI") 1, false, false,  8, 7,  6, 3,  0, 0}, // #100
  {DBGFIELD("MTFSB0_MTFSB1")      1, false, false,  8, 7,  6, 3,  0, 0}, // #101
  {DBGFIELD("MFFSCDRN_MFFSCDRNI_MFFSCRN_MFFSCRNI") 1, false, false,  8, 7,  6, 3,  0, 0}, // #102
  {DBGFIELD("CMPRB_CMPRB8_CMPEQB") 1, false, false,  8, 7,  6, 3,  0, 0}, // #103
  {DBGFIELD("TD_TDI")             1, false, false,  8, 7,  6, 3,  0, 0}, // #104
  {DBGFIELD("TW_TWI")             1, false, false,  8, 7,  6, 3,  0, 0}, // #105
  {DBGFIELD("FCMPUD_FCMPUS_FTDIV_FTSQRT") 1, false, false,  8, 7,  6, 3,  0, 0}, // #106
  {DBGFIELD("XSTSTDCDP_XSTSTDCSP") 1, false, false,  8, 7,  6, 3,  0, 0}, // #107
  {DBGFIELD("XSMAXCDP_XSMAXDP_XSMAXJDP_XSMINCDP_XSMINDP_XSMINJDP_XSXSIGDP_XSCVSPDPN") 1, false, false, 15, 3,  6, 3,  0, 0}, // #108
  {DBGFIELD("XSCMPEQDP_XSCMPEXPDP_XSCMPGEDP_XSCMPGTDP_XSCMPODP_XSCMPUDP_XSTDIVDP_XSTSQRTDP") 1, false, false, 15, 3,  6, 3,  0, 0}, // #109
  {DBGFIELD("CNTLZD_CNTLZD_rec_CNTLZW_CNTLZW8_CNTLZW8_rec_CNTLZW_rec_CNTTZD_CNTTZD_rec_CNTTZW_CNTTZW8_CNTTZW8_rec_CNTTZW_rec_POPCNTD_POPCNTW_CMPB_CMPB8_SETB_SETB8_BPERMD") 1, false, false, 15, 3,  6, 3,  0, 0}, // #110
  {DBGFIELD("SLD_SRD_SRAD")       1, false, false, 15, 3,  2, 3,  0, 0}, // #111
  {DBGFIELD("SRADI_EXTSWSLI_32_64_EXTSWSLI_SRADI_32_RLDIC") 1, false, false, 15, 3,  2, 3,  0, 0}, // #112
  {DBGFIELD("MFVRD_MFVSRD_MTVRD_MTVSRD_MTVRWA_MTVRWZ_MTVSRWA_MTVSRWZ_MFVSRWZ_MFVRWZ") 1, false, false, 15, 3,  2, 3,  0, 0}, // #113
  {DBGFIELD("CMPLW_CMPLWI_CMPW_CMPWI_CMPD_CMPDI_CMPLD_CMPLDI") 1, false, false, 15, 3,  2, 3,  0, 0}, // #114
  {DBGFIELD("SUBFC_SUBFC8_SUBFC8O_SUBFCO_SUBFIC_SUBFIC8_ANDI8_rec_ANDIS8_rec_ANDIS_rec_ANDI_rec_ADDC_ADDC8_ADDC8O_ADDCO_ADDIC_ADDIC8_ADDIC_rec_ADDE_ADDE8_ADDE8O_ADDE8O_rec_ADDE8_rec_ADDEO_ADDEO_rec_ADDE_rec_ADDME_ADDME8_ADDME8O_ADDME8O_rec_ADDME8_rec_ADDMEO_ADDMEO_rec_ADDME_rec_ADDZE_ADDZE8_ADDZE8O_ADDZE8O_rec_ADDZE8_rec_ADDZEO_ADDZEO_rec_ADDZE_rec_SUBF_SUBF8_SUBF8O_SUBF8O_rec_SUBF8_rec_SUBFE_SUBFE8_SUBFE8O_SUBFE8O_rec_SUBFE8_rec_SUBFEO_SUBFEO_rec_SUBFE_rec_SUBFME_SUBFME8_SUBFME8O_SUBFME8O_rec_SUBFME8_rec_SUBFMEO_SUBFMEO_rec_SUBFME_rec_SUBFO_SUBFO_rec_SUBFZE_SUBFZE8_SUBFZE8O_SUBFZE8O_rec_SUBFZE8_rec_SUBFZEO_SUBFZEO_rec_SUBFZE_rec_SUBF_rec_POPCNTB_LA") 1, false, false, 15, 3,  2, 3,  0, 0}, // #115
  {DBGFIELD("ADD4_ADD4O_ADD4O_rec_ADD4_rec_ADD8_ADD8O_ADD8O_rec_ADD8_rec_NEG_NEG8_NEG8O_NEG8O_rec_NEG8_rec_NEGO_NEGO_rec_NEG_rec_ADDI_ADDI8_ADDIS_ADDIS8_LI_LI8_LIS_LIS8_OR_OR8_OR8_rec_ORI_ORI8_ORIS_ORIS8_OR_rec_XOR_XOR8_XOR8_rec_XORI_XORI8_XORIS_XORIS8_XOR_rec_NAND_NAND8_NAND8_rec_NAND_rec_AND_AND8_AND8_rec_ANDC_ANDC8_ANDC8_rec_ANDC_rec_AND_rec_NOR_NOR8_NOR8_rec_NOR_rec_ORC_ORC8_ORC8_rec_ORC_rec_EQV_EQV8_EQV8_rec_EQV_rec_EXTSB_EXTSB8_EXTSB8_32_64_EXTSB8_rec_EXTSB_rec_EXTSH_EXTSH8_EXTSH8_32_64_EXTSH8_rec_EXTSH_rec_EXTSW_EXTSW_32_EXTSW_32_64_EXTSW_32_64_rec_EXTSW_rec_ADD4TLS_ADD8TLS_ADD8TLS__NOP") 1, false, false, 15, 3,  2, 3,  0, 0}, // #116
  {DBGFIELD("ADDIStocHA_ADDIStocHA8_ADDItocL_COPY") 1, false, false, 15, 3,  2, 3,  0, 0}, // #117
  {DBGFIELD("MCRF")               1, false, false, 15, 3,  2, 3,  0, 0}, // #118
  {DBGFIELD("MCRXRX")             1, false, false, 15, 3,  2, 3,  0, 0}, // #119
  {DBGFIELD("XSNABSDP_XSXEXPDP_XSABSDP_XSNEGDP_XSCPSGNDP") 1, false, false, 15, 3,  2, 3,  0, 0}, // #120
  {DBGFIELD("RFEBB")              1, false, false, 15, 3,  2, 3,  0, 0}, // #121
  {DBGFIELD("TBEGIN_TRECHKPT")    1, false, false, 15, 3,  2, 3,  0, 0}, // #122
  {DBGFIELD("WAIT")               1, false, false, 15, 3,  2, 3,  0, 0}, // #123
  {DBGFIELD("RLDCL_RLDCR")        1, false, false,  8, 7,  2, 3,  0, 0}, // #124
  {DBGFIELD("RLWIMI_RLWIMI8")     1, false, false,  8, 7,  2, 3,  0, 0}, // #125
  {DBGFIELD("RLDICL_RLDICL_32_RLDICL_32_64_RLDICR_RLDICR_32_RLDIMI") 1, false, false,  8, 7,  2, 3,  0, 0}, // #126
  {DBGFIELD("MFOCRF_MFOCRF8")     1, false, false,  8, 7,  2, 3,  0, 0}, // #127
  {DBGFIELD("MTOCRF_MTOCRF8")     1, false, false,  8, 7,  2, 3,  0, 0}, // #128
  {DBGFIELD("CR6SET_CR6UNSET_CRSET_CRUNSET_CRAND_CRANDC_CRNAND_CRNOR_CROR_CRORC_CREQV_CRXOR") 1, false, false,  8, 7,  2, 3,  0, 0}, // #129
  {DBGFIELD("SLW_SLW8_SRW_SRW8_RLWINM_RLWINM8_RLWNM_RLWNM8") 1, false, false,  8, 7,  2, 3,  0, 0}, // #130
  {DBGFIELD("FABSD_FABSS_FNABSD_FNABSS_FNEGD_FNEGS_FCPSGND_FCPSGNS_FMR") 1, false, false,  8, 7,  2, 3,  0, 0}, // #131
  {DBGFIELD("SRAW_SRAWI")         1, false, false,  8, 7,  2, 3,  0, 0}, // #132
  {DBGFIELD("ISEL_ISEL8")         1, false, false,  8, 7,  2, 3,  0, 0}, // #133
  {DBGFIELD("XSIEXPDP")           1, false, false,  8, 7,  2, 3,  0, 0}, // #134
  {DBGFIELD("TRECLAIM_TSR_TABORT") 1, false, false,  8, 7,  2, 3,  0, 0}, // #135
  {DBGFIELD("MFVSCR")             2, false, false,  1, 7,  9, 5,  0, 0}, // #136
  {DBGFIELD("MTVSCR")             2, false, false,  1, 7,  9, 5,  0, 0}, // #137
  {DBGFIELD("VCMPNEZB_VCMPNEZH_VCMPNEZW_VCMPEQUB_VCMPEQUD_VCMPEQUH_VCMPEQUW_VCMPNEB_VCMPNEH_VCMPNEW_VCMPEQFP_VCMPEQFP_rec_VCMPGEFP_VCMPGEFP_rec_VCMPGTFP_VCMPGTFP_rec_VCMPBFP_VCMPBFP_rec_VCMPGTSB_VCMPGTSB_rec_VCMPGTSD_VCMPGTSD_rec_VCMPGTSH_VCMPGTSH_rec_VCMPGTSW_VCMPGTSW_rec_VCMPGTUB_VCMPGTUB_rec_VCMPGTUD_VCMPGTUD_rec_VCMPGTUH_VCMPGTUH_rec_VCMPGTUW_VCMPGTUW_rec_VCMPNEB_rec_VCMPNEH_rec_VCMPNEW_rec_VCMPNEZB_rec_VCMPNEZH_rec_VCMPNEZW_rec_VCMPEQUB_rec_VCMPEQUD_rec_VCMPEQUH_rec_VCMPEQUW_rec_XVCMPEQDP_XVCMPEQDP_rec_XVCMPEQSP_XVCMPEQSP_rec_XVCMPGEDP_XVCMPGEDP_rec_XVCMPGESP_XVCMPGESP_rec_XVCMPGTDP_XVCMPGTDP_rec_XVCMPGTSP_XVCMPGTSP_rec") 2, false, false,  1, 7,  9, 5,  0, 0}, // #138
  {DBGFIELD("VABSDUB_VABSDUH_VABSDUW_VCLZB_VCLZD_VCLZH_VCLZW_VCTZB_VCTZD_VCTZH_VCTZW_VPOPCNTW_VPOPCNTD_VPRTYBD_VPRTYBW") 2, false, false,  1, 7,  9, 5,  0, 0}, // #139
  {DBGFIELD("VADDUBS_VADDUHS_VADDUWS_VAVGSB_VAVGSH_VAVGSW_VAVGUB_VAVGUH_VAVGUW_VADDSBS_VADDSHS_VADDSWS_VMAXFP_VMINFP_VMAXSB_VMAXSD_VMAXSH_VMAXSW_VMAXUB_VMAXUD_VMAXUH_VMAXUW_VMINSB_VMINSD_VMINSH_VMINSW_VMINUB_VMINUD_VMINUH_VMINUW_VBPERMD_VADDCUW_VSHASIGMAD_VSHASIGMAW_VSUBSBS_VSUBSHS_VSUBSWS_VSUBUBS_VSUBUHS_VSUBUWS_VSUBCUW_XVMAXDP_XVMAXSP_XVMINDP_XVMINSP_XVTSTDCDP_XVTSTDCSP_XVXSIGDP_XVXSIGSP") 2, false, false,  1, 7,  9, 5,  0, 0}, // #140
  {DBGFIELD("XVTDIVDP_XVTDIVSP_XVTSQRTDP_XVTSQRTSP") 2, false, false,  1, 7,  9, 5,  0, 0}, // #141
  {DBGFIELD("VADDFP_VCTSXS_VCTSXS_0_VCTUXS_VCTUXS_0_VEXPTEFP_VLOGEFP_VMADDFP_VMHADDSHS_VNMSUBFP_VREFP_VRFIM_VRFIN_VRFIP_VRFIZ_VRSQRTEFP_XVADDDP_XVADDSP_XVCVDPSP_XVCVDPSXDS_XVCVDPSXWS_XVCVDPUXDS_XVCVDPUXWS_XVCVHPSP_XVCVSPDP_XVCVSPHP_XVCVSPSXDS_XVCVSPSXWS_XVCVSPUXDS_XVCVSPUXWS_XVCVSXDDP_XVCVSXDSP_XVCVSXWDP_XVCVSXWSP_XVCVUXDDP_XVCVUXDSP_XVCVUXWDP_XVCVUXWSP_XVMADDADP_XVMADDASP_XVMADDMDP_XVMADDMSP_XVMSUBADP_XVMSUBASP_XVMSUBMDP_XVMSUBMSP_XVMULDP_XVMULSP_XVNMADDADP_XVNMADDASP_XVNMADDMDP_XVNMADDMSP_XVNMSUBADP_XVNMSUBASP_XVNMSUBMDP_XVNMSUBMSP_XVRDPI_XVRDPIC_XVRDPIM_XVRDPIP_XVRDPIZ_XVREDP_XVRESP_XVRSPI_XVRSPIC_XVRSPIM_XVRSPIP_XVRSPIZ_XVRSQRTEDP_XVRSQRTESP_XVSUBDP_XVSUBSP_VCFSX_VCFSX_0_VCFUX_VCFUX_0_VMHRADDSHS_VMLADDUHM_VMSUMMBM_VMSUMSHM_VMSUMSHS_VMSUMUBM_VMSUMUHM_VMSUMUDM_VMSUMUHS_VMULESB_VMULESH_VMULESW_VMULEUB_VMULEUH_VMULEUW_VMULOSB_VMULOSH_VMULOSW_VMULOUB_VMULOUH_VMULOUW_VSUM2SWS_VSUM4SBS_VSUM4SHS_VSUM4UBS_VSUMSWS") 2, false, false, 18, 7, 14, 5,  0, 0}, // #142
  {DBGFIELD("VSUBFP_VMULUWM")     2, false, false, 18, 7, 14, 5,  0, 0}, // #143
  {DBGFIELD("MADDHD_MADDHDU_MADDLD_MADDLD8_MULLD_MULLDO") 1, false, false, 25, 7, 19, 3,  0, 0}, // #144
  {DBGFIELD("MULHD_MULHW_MULLW_MULLWO") 1, false, false, 25, 7, 19, 3,  0, 0}, // #145
  {DBGFIELD("MULHDU_MULHWU")      1, false, false, 25, 7, 19, 3,  0, 0}, // #146
  {DBGFIELD("MULLI_MULLI8")       1, false, false, 25, 7, 19, 3,  0, 0}, // #147
  {DBGFIELD("FRSP_FRIMD_FRIMS_FRIND_FRINS_FRIPD_FRIPS_FRIZD_FRIZS_FRE_FRES_FADDS_FMSUBS_FMADDS_FSUBS_FCFID_FCFIDS_FCFIDU_FCFIDUS_FCTID_FCTIDU_FCTIDUZ_FCTIDZ_FCTIW_FCTIWU_FCTIWUZ_FCTIWZ_FRSQRTE_FRSQRTES_FNMADDS_FNMSUBS_FSELD_FSELS_FMULS") 1, false, false, 25, 7, 15, 3,  0, 0}, // #148
  {DBGFIELD("FADD_FSUB")          1, false, false, 25, 7, 15, 3,  0, 0}, // #149
  {DBGFIELD("FMSUB_FMADD_FNMADD_FNMSUB_FMUL") 1, false, false, 25, 7, 15, 3,  0, 0}, // #150
  {DBGFIELD("XSMADDADP_XSMADDASP_XSMADDMDP_XSMADDMSP_XSMSUBADP_XSMSUBASP_XSMSUBMDP_XSMSUBMSP_XSMULDP_XSMULSP_XSNMADDADP_XSNMADDASP_XSNMADDMDP_XSNMADDMSP_XSNMSUBADP_XSNMSUBASP_XSNMSUBMDP_XSNMSUBMSP") 1, false, false, 25, 7, 15, 3,  0, 0}, // #151
  {DBGFIELD("FSELD_rec_FSELS_rec") 2, false, false, 32, 8, 22, 6,  0, 0}, // #152
  {DBGFIELD("MULHDU_rec_MULHWU_rec") 2, false, false, 32, 8, 28, 5,  0, 0}, // #153
  {DBGFIELD("MULHD_rec_MULHW_rec_MULLWO_rec_MULLW_rec") 2, false, false, 32, 8, 28, 5,  0, 0}, // #154
  {DBGFIELD("MULLDO_rec_MULLD_rec") 2, false, false, 32, 8, 28, 5,  0, 0}, // #155
  {DBGFIELD("FRIMD_rec_FRIMS_rec_FRIND_rec_FRINS_rec_FRIPD_rec_FRIPS_rec_FRIZD_rec_FRIZS_rec_FRES_rec_FRE_rec_FADDS_rec_FSUBS_rec_FMSUBS_rec_FNMSUBS_rec_FMADDS_rec_FNMADDS_rec_FCFIDS_rec_FCFIDUS_rec_FCFIDU_rec_FCFID_rec_FCTIDUZ_rec_FCTIDU_rec_FCTIDZ_rec_FCTID_rec_FCTIWUZ_rec_FCTIWU_rec_FCTIWZ_rec_FCTIW_rec_FMULS_rec_FRSQRTES_rec_FRSQRTE_rec_FRSP_rec") 2, false, false, 32, 8, 33, 5,  0, 0}, // #156
  {DBGFIELD("FADD_rec_FSUB_rec")  2, false, false, 32, 8, 33, 5,  0, 0}, // #157
  {DBGFIELD("FMSUB_rec_FNMSUB_rec_FMADD_rec_FNMADD_rec_FMUL_rec") 2, false, false, 32, 8, 33, 5,  0, 0}, // #158
  {DBGFIELD("XSADDDP_XSADDSP_XSCVDPHP_XSCVDPSP_XSCVDPSXDS_XSCVDPSXDSs_XSCVDPSXWS_XSCVDPUXDS_XSCVDPUXDSs_XSCVDPUXWS_XSCVDPSXWSs_XSCVDPUXWSs_XSCVHPDP_XSCVSPDP_XSCVSXDDP_XSCVSXDSP_XSCVUXDDP_XSCVUXDSP_XSRDPI_XSRDPIC_XSRDPIM_XSRDPIP_XSRDPIZ_XSREDP_XSRESP_XSRSQRTEDP_XSRSQRTESP_XSSUBDP_XSSUBSP_XSCVDPSPN_XSRSP") 1, false, false, 40, 3, 15, 3,  0, 0}, // #159
  {DBGFIELD("LVSL_LVSR")          1, false, false, 43, 5, 10, 4,  0, 0}, // #160
  {DBGFIELD("VSPLTISB_VSPLTISH_VSPLTISW_VSPLTB_VSPLTBs_VSPLTH_VSPLTHs_VSPLTW_XXMRGHW_XXMRGLW_XXPERM_XXPERMR_XXSLDWI_XXSLDWIs_XXSPLTIB_XXSPLTW_XXSPLTWs_XXPERMDI_XXPERMDIs") 1, false, false, 43, 5, 10, 4,  0, 0}, // #161
  {DBGFIELD("V_SETALLONES_V_SETALLONESB_V_SETALLONESH_VBPERMQ_VGBBD_VMRGHB_VMRGHH_VMRGHW_VMRGLB_VMRGLH_VMRGLW_VPERM_VPERMR_VPERMXOR_VPKPX_VPKSDSS_VPKSDUS_VPKSHSS_VPKSHUS_VPKSWSS_VPKSWUS_VPKUDUM_VPKUDUS_VPKUHUM_VPKUHUS_VPKUWUM_VPKUWUS_VSL_VSLDOI_VSLO_VSLV_VSR_VSRO_VSRV_VUPKHPX_VUPKHSB_VUPKHSH_VUPKHSW_VUPKLPX_VUPKLSB_VUPKLSH_VUPKLSW_XXBRD_XXBRH_XXBRQ_XXBRW_XXEXTRACTUW_XXINSERTW_VADDCUQ_VADDECUQ_VADDEUQM_VMUL10CUQ_VMUL10ECUQ_VMUL10EUQ_VMUL10UQ_VSUBCUQ_VSUBECUQ_VSUBEUQM_XSTSTDCQP_XSXSIGQP_BCDCFN_rec_BCDCFZ_rec_BCDCPSGN_rec_BCDCTN_rec_BCDCTZ_rec_BCDSETSGN_rec_BCDS_rec_BCDTRUNC_rec_BCDUS_rec_BCDUTRUNC_rec") 1, false, false, 43, 5, 10, 4,  0, 0}, // #162
  {DBGFIELD("VEXTRACTUB_VEXTRACTUH_VEXTRACTUW_VINSERTB_VINSERTD_VINSERTH_VINSERTW_MFVSRLD_MTVSRWS_VCLZLSBB_VCTZLSBB_VEXTRACTD_VEXTUBLX_VEXTUBRX_VEXTUHLX_VEXTUHRX_VEXTUWLX_VEXTUWRX_VPRTYBQ_VADDUQM_VSUBUQM") 1, false, false, 43, 5, 10, 4,  0, 0}, // #163
  {DBGFIELD("XSCMPEXPQP_XSCMPOQP_XSCMPUQP") 1, false, false, 43, 5, 10, 4,  0, 0}, // #164
  {DBGFIELD("BCDSR_rec_XSADDQP_XSADDQPO_XSCVDPQP_XSCVQPDP_XSCVQPDPO_XSCVQPSDZ_XSCVQPSWZ_XSCVQPUDZ_XSCVQPUWZ_XSCVSDQP_XSCVUDQP_XSRQPI_XSRQPIX_XSRQPXP_XSSUBQP_XSSUBQPO") 1, false, false, 48, 5, 38, 4,  0, 0}, // #165
  {DBGFIELD("BCDCTSQ_rec")        1, false, false, 53, 5, 42, 4,  0, 0}, // #166
  {DBGFIELD("XSMADDQP_XSMADDQPO_XSMSUBQP_XSMSUBQPO_XSMULQP_XSMULQPO_XSNMADDQP_XSNMADDQPO_XSNMSUBQP_XSNMSUBQPO") 1, false, false, 58, 5, 46, 4,  0, 0}, // #167
  {DBGFIELD("BCDCFSQ_rec")        1, false, false, 63, 5, 50, 4,  0, 0}, // #168
  {DBGFIELD("XSDIVQP_XSDIVQPO")   1, false, false, 68, 5, 54, 4,  0, 0}, // #169
  {DBGFIELD("XSSQRTQP_XSSQRTQPO") 1, false, false, 73, 5, 58, 4,  0, 0}, // #170
  {DBGFIELD("LXVL_LXVLL")         1, false, false, 78, 3, 62, 3,  0, 0}, // #171
  {DBGFIELD("LVEBX_LVEHX_LVEWX_LVX_LVXL") 1, false, false, 78, 3, 19, 3,  0, 0}, // #172
  {DBGFIELD("LXSIBZX_LXSIHZX_LXSDX_LXVB16X_LXVD2X_LXVWSX_LXSIWZX_LXV_LXVX_LXSD") 1, false, false, 78, 3, 19, 3,  0, 0}, // #173
  {DBGFIELD("DFLOADf64_XFLOADf64_LIWZX") 1, false, false, 78, 3, 19, 3,  0, 0}, // #174
  {DBGFIELD("DCBF_DCBFEP_DCBST_DCBSTEP_DCBT_DCBTEP_DCBZ_DCBZEP_DCBZL_DCBZLEP_DCBTST_DCBTSTEP") 1, false, false, 78, 3, 65, 3,  0, 0}, // #175
  {DBGFIELD("CP_COPY_CP_COPY8")   1, false, false, 78, 3, 65, 3,  0, 0}, // #176
  {DBGFIELD("CP_PASTE_CP_PASTE8") 1, false, false, 78, 3, 65, 3,  0, 0}, // #177
  {DBGFIELD("ICBI_ICBIEP")        1, false, false, 78, 3, 65, 3,  0, 0}, // #178
  {DBGFIELD("ICBT_ICBTLS_LBZ_LBZ8_LBZCIX_LBZX_LBZX8_LBZXTLS_LBZXTLS__LBZXTLS_32_LDBRX_LDCIX_LHBRX_LHBRX8_LHZ_LHZ8_LHZCIX_LHZX_LHZX8_LHZXTLS_LHZXTLS__LHZXTLS_32_LWBRX_LWBRX8_LWZ_LWZ8_LWZCIX_LWZX_LWZX8_LWZXTLS_LWZXTLS__LWZXTLS_32_EnforceIEIO_LSWI") 1, false, false, 78, 3, 65, 3,  0, 0}, // #179
  {DBGFIELD("LBARX_LBARXL_LHARX_LHARXL_LWARX_LWARXL") 1, false, false, 78, 3, 65, 3,  0, 0}, // #180
  {DBGFIELD("LD_LDX_LDXTLS_LDXTLS__DARN") 1, false, false, 78, 3, 65, 3,  0, 0}, // #181
  {DBGFIELD("LDARX_LDARXL")       1, false, false, 78, 3, 65, 3,  0, 0}, // #182
  {DBGFIELD("CP_ABORT")           1, false, false, 78, 3, 65, 3,  0, 0}, // #183
  {DBGFIELD("ISYNC")              1, false, false, 78, 3, 65, 3,  0, 0}, // #184
  {DBGFIELD("MSGSYNC")            1, false, false, 78, 3, 65, 3,  0, 0}, // #185
  {DBGFIELD("TLBSYNC")            1, false, false, 78, 3, 65, 3,  0, 0}, // #186
  {DBGFIELD("SYNC")               1, false, false, 78, 3, 65, 3,  0, 0}, // #187
  {DBGFIELD("LMW")                1, false, false, 78, 3, 65, 3,  0, 0}, // #188
  {DBGFIELD("LFIWZX_LFDX_LFD")    1, false, false, 81, 7, 65, 3,  0, 0}, // #189
  {DBGFIELD("SLBIA")              2, false, false, 88, 4, 68, 5,  0, 0}, // #190
  {DBGFIELD("SLBIE")              2, false, false, 88, 4, 68, 5,  0, 0}, // #191
  {DBGFIELD("SLBMFEE")            2, false, false, 88, 4, 68, 5,  0, 0}, // #192
  {DBGFIELD("SLBMFEV")            2, false, false, 88, 4, 68, 5,  0, 0}, // #193
  {DBGFIELD("SLBMTE")             2, false, false, 88, 4, 68, 5,  0, 0}, // #194
  {DBGFIELD("TLBIEL")             2, false, false, 88, 4, 68, 5,  0, 0}, // #195
  {DBGFIELD("LHZU_LHZU8_LWZU_LWZU8") 2, false, false, 92, 6, 73, 6,  0, 0}, // #196
  {DBGFIELD("LHZUX_LHZUX8_LWZUX_LWZUX8") 2, false, false, 92, 6, 73, 6,  0, 0}, // #197
  {DBGFIELD("TEND")               2, false, false, 98, 5, 73, 6,  0, 0}, // #198
  {DBGFIELD("STBCX_STHCX_STWCX")  2, false, false, 103, 9, 79, 6,  0, 0}, // #199
  {DBGFIELD("STDCX")              2, false, false, 103, 9, 79, 6,  0, 0}, // #200
  {DBGFIELD("LDMX")               2, false, false, 112, 3, 85, 5,  0, 0}, // #201
  {DBGFIELD("LHA_LHA8_LHAX_LHAX8_LWAX_LWAX_32") 2, false, false, 98, 5, 90, 5,  0, 0}, // #202
  {DBGFIELD("CP_PASTE8_rec_CP_PASTE_rec") 2, false, false, 98, 5, 90, 5,  0, 0}, // #203
  {DBGFIELD("LWA_LWA_32")         2, false, false, 98, 5, 90, 5,  0, 0}, // #204
  {DBGFIELD("TCHECK")             2, false, false, 98, 5, 90, 5,  0, 0}, // #205
  {DBGFIELD("LFIWAX")             2, false, false, 115, 9, 90, 5,  0, 0}, // #206
  {DBGFIELD("LXSIWAX")            2, false, false, 98, 5, 28, 5,  0, 0}, // #207
  {DBGFIELD("LIWAX")              2, false, false, 98, 5, 28, 5,  0, 0}, // #208
  {DBGFIELD("LFSX_LFS")           2, false, false, 115, 9, 28, 5,  0, 0}, // #209
  {DBGFIELD("LXSSP_LXSSPX")       2, false, false, 98, 5, 85, 5,  0, 0}, // #210
  {DBGFIELD("XFLOADf32_DFLOADf32") 2, false, false, 98, 5, 85, 5,  0, 0}, // #211
  {DBGFIELD("LHAU_LHAU8")         3, false, false, 124, 6, 95, 8,  0, 0}, // #212
  {DBGFIELD("LHAUX_LHAUX8_LWAUX") 3, false, false, 124, 6, 95, 8,  0, 0}, // #213
  {DBGFIELD("LXVH8X_LXVDSX_LXVW4X") 2, false, false, 130, 7, 103, 6,  0, 0}, // #214
  {DBGFIELD("STFD_STFDX_STFIWX_STFS_STFSX_STXSD_STXSDX_STXSIBX_STXSIBXv_STXSIHX_STXSIHXv_STXSIWX_STXSSP_STXSSPX") 1, false, false, 137, 8, 24, 4,  0, 0}, // #215
  {DBGFIELD("STW_STW8_STDBRX_STHBRX_STWBRX_STB_STB8_STH_STH8_STBX_STBX8_STBXTLS_STBXTLS__STBXTLS_32_STHX_STHX8_STHXTLS_STHXTLS__STHXTLS_32_STWX_STWX8_STWXTLS_STWXTLS__STWXTLS_32") 1, false, false, 137, 8, 24, 4,  0, 0}, // #216
  {DBGFIELD("DFSTOREf32_DFSTOREf64_XFSTOREf32_XFSTOREf64_STIWX") 1, false, false, 137, 8, 24, 4,  0, 0}, // #217
  {DBGFIELD("STD_STDX_STDXTLS_STDXTLS_") 1, false, false, 137, 8, 24, 4,  0, 0}, // #218
  {DBGFIELD("STBCIX_STDCIX_STHCIX_STWCIX_STSWI") 1, false, false, 137, 8, 24, 4,  0, 0}, // #219
  {DBGFIELD("SLBIEG")             1, false, false, 137, 8, 24, 4,  0, 0}, // #220
  {DBGFIELD("STMW")               1, false, false, 137, 8, 24, 4,  0, 0}, // #221
  {DBGFIELD("TLBIE")              1, false, false, 137, 8, 24, 4,  0, 0}, // #222
  {DBGFIELD("STVEBX_STVEHX_STVEWX_STVX_STVXL") 1, false, false, 145, 6, 80, 5,  0, 0}, // #223
  {DBGFIELD("STXV_STXVB16X_STXVD2X_STXVH8X_STXVW4X_STXVX") 1, false, false, 145, 6, 80, 5,  0, 0}, // #224
  {DBGFIELD("STXVL_STXVLL")       1, false, false, 145, 6, 80, 5,  0, 0}, // #225
  {DBGFIELD("MTCTR_MTCTR8_MTCTR8loop_MTCTRloop_MTLR_MTLR8") 1, false, false, 151, 8, 109, 4,  0, 0}, // #226
  {DBGFIELD("MFVRSAVE_MFVRSAVEv_MTVRSAVE_MTVRSAVEv") 1, false, false, 151, 8, 38, 4,  0, 0}, // #227
  {DBGFIELD("MFPMR")              1, false, false, 151, 8, 38, 4,  0, 0}, // #228
  {DBGFIELD("MTPMR")              1, false, false, 151, 8, 38, 4,  0, 0}, // #229
  {DBGFIELD("MFTB_MFTB8")         1, false, false, 151, 8, 38, 4,  0, 0}, // #230
  {DBGFIELD("MFCTR_MFCTR8_MFLR_MFLR8_MFSPR_MFSPR8") 1, false, false, 151, 8, 38, 4,  0, 0}, // #231
  {DBGFIELD("MFMSR")              1, false, false, 151, 8, 38, 4,  0, 0}, // #232
  {DBGFIELD("MTMSR")              1, false, false, 151, 8, 38, 4,  0, 0}, // #233
  {DBGFIELD("MTMSRD")             1, false, false, 151, 8, 38, 4,  0, 0}, // #234
  {DBGFIELD("MTSPR_MTSPR8")       1, false, false, 151, 8, 38, 4,  0, 0}, // #235
  {DBGFIELD("DIVW_DIVWO_DIVWU_DIVWUO_MODSW") 1, false, false, 159, 8, 113, 4,  0, 0}, // #236
  {DBGFIELD("DIVWE_DIVWEO_DIVWEU_DIVWEUO_MODSD_MODUD_MODUW") 1, false, false, 159, 8, 46, 4,  0, 0}, // #237
  {DBGFIELD("DIVD_DIVDO_DIVDU_DIVDUO") 1, false, false, 159, 8, 46, 4,  0, 0}, // #238
  {DBGFIELD("DIVDE_DIVDEO_DIVDEU_DIVDEUO") 1, false, false, 159, 8, 117, 4,  0, 0}, // #239
  {DBGFIELD("DIVWO_rec_DIVWUO_rec_DIVWU_rec_DIVW_rec") 2, false, false, 167, 9, 121, 6,  0, 0}, // #240
  {DBGFIELD("DIVD_rec_DIVDO_rec_DIVDU_rec_DIVDUO_rec") 2, false, false, 167, 9, 127, 6,  0, 0}, // #241
  {DBGFIELD("DIVWE_rec_DIVWEO_rec_DIVWEU_rec_DIVWEUO_rec") 2, false, false, 167, 9, 127, 6,  0, 0}, // #242
  {DBGFIELD("DIVDE_rec_DIVDEO_rec_DIVDEU_rec_DIVDEUO_rec") 2, false, false, 167, 9, 133, 6,  0, 0}, // #243
  {DBGFIELD("MTCRF_MTCRF8")       2, false, false, 176, 7, 139, 6,  0, 0}, // #244
  {DBGFIELD("ADDC8O_rec_ADDC8_rec_ADDCO_rec_ADDC_rec_SUBFC8O_rec_SUBFC8_rec_SUBFCO_rec_SUBFC_rec") 2, false, false, 183, 3, 139, 6,  0, 0}, // #245
  {DBGFIELD("FABSD_rec_FABSS_rec_FNABSD_rec_FNABSS_rec_FCPSGND_rec_FCPSGNS_rec_FNEGD_rec_FNEGS_rec_FMR_rec") 2, false, false, 186, 7, 145, 6,  0, 0}, // #246
  {DBGFIELD("MCRFS")              2, false, false, 183, 3, 151, 6,  0, 0}, // #247
  {DBGFIELD("MTFSF_MTFSF_rec_MTFSFI_MTFSFI_rec") 2, false, false, 176, 7, 151, 6,  0, 0}, // #248
  {DBGFIELD("MTFSFb")             2, false, false, 176, 7, 151, 6,  0, 0}, // #249
  {DBGFIELD("RLDCL_rec_RLDCR_rec") 2, false, false, 186, 7, 157, 5,  0, 0}, // #250
  {DBGFIELD("RLDICL_rec_RLDICR_rec_RLDICL_32_rec_RLDIMI_rec") 2, false, false, 186, 7, 157, 5,  0, 0}, // #251
  {DBGFIELD("RLWIMI8_rec_RLWIMI_rec") 2, false, false, 186, 7, 157, 5,  0, 0}, // #252
  {DBGFIELD("RLWINM8_rec_RLWINM_rec_RLWNM8_rec_RLWNM_rec_SLW8_rec_SLW_rec_SRW8_rec_SRW_rec") 2, false, false, 186, 7, 157, 5,  0, 0}, // #253
  {DBGFIELD("SRAWI_rec_SRAW_rec") 2, false, false, 186, 7, 157, 5,  0, 0}, // #254
  {DBGFIELD("MFFS_MFFSCE_MFFSL_MFFS_rec") 2, false, false, 176, 7, 90, 5,  0, 0}, // #255
  {DBGFIELD("MFCR_MFCR8")         3, false, false, 193, 7, 162, 7,  0, 0}, // #256
  {DBGFIELD("EXTSWSLI_32_64_rec_SRADI_rec_EXTSWSLI_rec_RLDIC_rec") 2, false, false, 183, 3, 157, 5,  0, 0}, // #257
  {DBGFIELD("SRAD_rec_SLD_rec_SRD_rec") 2, false, false, 183, 3, 157, 5,  0, 0}, // #258
  {DBGFIELD("FDIV")               1, false, false, 200, 7, 169, 3,  0, 0}, // #259
  {DBGFIELD("FDIV_rec")           2, false, false, 207, 8, 172, 5,  0, 0}, // #260
  {DBGFIELD("XSSQRTDP")           1, false, false, 215, 3, 172, 3,  0, 0}, // #261
  {DBGFIELD("FSQRT")              1, false, false, 218, 7, 172, 3,  0, 0}, // #262
  {DBGFIELD("XVSQRTDP")           2, false, false, 225, 5, 177, 5,  0, 0}, // #263
  {DBGFIELD("XVSQRTSP")           2, false, false, 225, 5, 182, 5,  0, 0}, // #264
  {DBGFIELD("FSQRT_rec")          2, false, false, 230, 8, 187, 5,  0, 0}, // #265
  {DBGFIELD("XSSQRTSP")           1, false, false, 238, 3, 192, 3,  0, 0}, // #266
  {DBGFIELD("FSQRTS")             1, false, false, 241, 7, 192, 3,  0, 0}, // #267
  {DBGFIELD("FSQRTS_rec")         2, false, false, 248, 8, 195, 5,  0, 0}, // #268
  {DBGFIELD("XSDIVDP")            1, false, false, 256, 3, 169, 3,  0, 0}, // #269
  {DBGFIELD("FDIVS")              1, false, false, 241, 7, 192, 3,  0, 0}, // #270
  {DBGFIELD("FDIVS_rec")          2, false, false, 248, 8, 195, 5,  0, 0}, // #271
  {DBGFIELD("XSDIVSP")            1, false, false, 238, 3, 192, 3,  0, 0}, // #272
  {DBGFIELD("XVDIVSP")            2, false, false, 259, 7, 200, 5,  0, 0}, // #273
  {DBGFIELD("XVDIVDP")            2, false, false, 259, 7, 205, 5,  0, 0}, // #274
  {DBGFIELD("LFSU")               3, false, false, 266, 9, 210, 8,  0, 0}, // #275
  {DBGFIELD("LFSUX")              3, false, false, 266, 9, 210, 8,  0, 0}, // #276
  {DBGFIELD("STFDU_STFDUX_STFSU_STFSUX") 2, false, false, 103, 9, 218, 7,  0, 0}, // #277
  {DBGFIELD("STBU_STBU8_STDU_STHU_STHU8_STWU_STWU8") 2, false, false, 103, 9, 218, 7,  0, 0}, // #278
  {DBGFIELD("STBUX_STBUX8_STDUX_STHUX_STHUX8_STWUX_STWUX8") 2, false, false, 103, 9, 218, 7,  0, 0}, // #279
  {DBGFIELD("LBZU_LBZU8")         2, false, false, 92, 6, 73, 6,  0, 0}, // #280
  {DBGFIELD("LBZUX_LBZUX8")       2, false, false, 92, 6, 73, 6,  0, 0}, // #281
  {DBGFIELD("LDU")                2, false, false, 92, 6, 73, 6,  0, 0}, // #282
  {DBGFIELD("LDUX")               2, false, false, 92, 6, 73, 6,  0, 0}, // #283
  {DBGFIELD("LFDU")               2, false, false, 275, 9, 73, 6,  0, 0}, // #284
  {DBGFIELD("LFDUX")              2, false, false, 275, 9, 73, 6,  0, 0}, // #285
  {DBGFIELD("VPMSUMB_VPMSUMD_VPMSUMH_VPMSUMW_VCIPHER_VCIPHERLAST_VNCIPHER_VNCIPHERLAST_VSBOX") 1, false, false, 284, 5, 90, 4,  0, 0}, // #286
  {DBGFIELD("BCCCTR_BCCCTR8_BCCCTRL_BCCCTRL8_BCCL_BCCLA_BCCLR_BCCLRL_BCCTR_BCCTR8_BCCTR8n_BCCTRL_BCCTRL8_BCCTRL8n_BCCTRLn_BCCTRn_BDNZ_BDNZ8_BDNZA_BDNZAm_BDNZAp_BDNZm_BDNZp_BDZ_BDZ8_BDZA_BDZAm_BDZAp_BDZm_BDZp_BDNZL_BDNZLA_BDNZLAm_BDNZLAp_BDNZLR_BDNZLR8_BDNZLRL_BDNZLRLm_BDNZLRLp_BDNZLRm_BDNZLRp_BDNZLm_BDNZLp_BDZL_BDZLA_BDZLAm_BDZLAp_BDZLR_BDZLR8_BDZLRL_BDZLRLm_BDZLRLp_BDZLRm_BDZLRp_BDZLm_BDZLp_BL_BL_NOP_BL_TLS_BL8_BL8_NOP_BL8_NOP_TLS_BL8_TLS_BL8_TLS__BLA_BLA8_BLA8_NOP_BLR_BLR8_BLRL_TAILB_TAILB8_TAILBA_TAILBA8_TAILBCTR_TAILBCTR8_gBC_gBCA_gBCAat_gBCCTR_gBCCTRL_gBCL_gBCLA_gBCLAat_gBCLR_gBCLRL_gBCLat_gBCat_BCLR_BCLRL_BCLRLn_BCLRn_BCTR_BCTR8_BCTRL_BCTRL8_B_BA_BC_BCC_BCCA_BCL_BCLalways_BCLn_BCTRL8_LDinto_toc_BCTRL_LWZinto_toc_BCn_CTRL_DEP") 1, false, false, 289, 3,  2, 2,  0, 0}, // #287
  {DBGFIELD("ADDPCIS")            2, false, false, 292, 5, 15, 4,  0, 0}, // #288
  {DBGFIELD("LDAT_LWAT")          5, false, false, 297, 8, 225, 18,  0, 0}, // #289
  {DBGFIELD("STDAT_STWAT")        3, false, false, 305, 8, 243, 10,  0, 0}, // #290
  {DBGFIELD("BRINC")              16383, false, false,  0, 0,  0, 0,  0, 0}, // #291
  {DBGFIELD("EVABS_EVEQV_EVNAND_EVNEG_EVADDIW_EVADDW_EVAND_EVANDC_EVCMPEQ_EVCMPGTS_EVCMPGTU_EVCMPLTS_EVCMPLTU_EVCNTLSW_EVCNTLZW_EVEXTSB_EVEXTSH_EVMERGEHI_EVMERGEHILO_EVMERGELO_EVMERGELOHI_EVNOR_EVOR_EVORC_EVXOR_EVRLW_EVRLWI_EVRNDW_EVSLW_EVSLWI_EVSPLATFI_EVSPLATI_EVSRWIS_EVSRWIU_EVSRWS_EVSRWU_EVSUBFW_EVSUBIFW") 16383, false, false,  0, 0,  0, 0,  0, 0}, // #292
  {DBGFIELD("EVMRA_EVADDSMIAAW_EVADDSSIAAW_EVADDUMIAAW_EVADDUSIAAW_EVDIVWS_EVDIVWU_EVMHEGSMFAA_EVMHEGSMFAN_EVMHEGSMIAA_EVMHEGSMIAN_EVMHEGUMIAA_EVMHEGUMIAN_EVMHESMF_EVMHESMFA_EVMHESMFAAW_EVMHESMFANW_EVMHESMI_EVMHESMIA_EVMHESMIAAW_EVMHESMIANW_EVMHESSF_EVMHESSFA_EVMHESSFAAW_EVMHESSFANW_EVMHESSIAAW_EVMHESSIANW_EVMHEUMI_EVMHEUMIA_EVMHEUMIAAW_EVMHEUMIANW_EVMHEUSIAAW_EVMHEUSIANW_EVMHOGSMFAA_EVMHOGSMFAN_EVMHOGSMIAA_EVMHOGSMIAN_EVMHOGUMIAA_EVMHOGUMIAN_EVMHOSMF_EVMHOSMFA_EVMHOSMFAAW_EVMHOSMFANW_EVMHOSMI_EVMHOSMIA_EVMHOSMIAAW_EVMHOSMIANW_EVMHOSSF_EVMHOSSFA_EVMHOSSFAAW_EVMHOSSFANW_EVMHOSSIAAW_EVMHOSSIANW_EVMHOUMI_EVMHOUMIA_EVMHOUMIAAW_EVMHOUMIANW_EVMHOUSIAAW_EVMHOUSIANW_EVMWHSMF_EVMWHSMFA_EVMWHSMI_EVMWHSMIA_EVMWHSSF_EVMWHSSFA_EVMWHUMI_EVMWHUMIA_EVMWLSMIAAW_EVMWLSMIANW_EVMWLSSIAAW_EVMWLSSIANW_EVMWLUMI_EVMWLUMIA_EVMWLUMIAAW_EVMWLUMIANW_EVMWLUSIAAW_EVMWLUSIANW_EVMWSMF_EVMWSMFA_EVMWSMFAA_EVMWSMFAN_EVMWSMI_EVMWSMIA_EVMWSMIAA_EVMWSMIAN_EVMWSSF_EVMWSSFA_EVMWSSFAA_EVMWSSFAN_EVMWUMI_EVMWUMIA_EVMWUMIAA_EVMWUMIAN_EVSUBFSMIAAW_EVSUBFSSIAAW_EVSUBFUMIAAW_EVSUBFUSIAAW") 16383, false, false,  0, 0,  0, 0,  0, 0}, // #293
  {DBGFIELD("EVLDD_EVLDDX_EVLDH_EVLDHX_EVLDW_EVLDWX_EVLHHESPLAT_EVLHHESPLATX_EVLHHOSSPLAT_EVLHHOSSPLATX_EVLHHOUSPLAT_EVLHHOUSPLATX_EVLWHE_EVLWHEX_EVLWHOS_EVLWHOSX_EVLWHOU_EVLWHOUX_EVLWHSPLAT_EVLWHSPLATX_EVLWWSPLAT_EVLWWSPLATX") 16383, false, false,  0, 0,  0, 0,  0, 0}, // #294
  {DBGFIELD("EVSTDD_EVSTDDX_EVSTDH_EVSTDHX_EVSTDW_EVSTDWX_EVSTWHE_EVSTWHEX_EVSTWHO_EVSTWHOX_EVSTWWE_EVSTWWEX_EVSTWWO_EVSTWWOX") 16383, false, false,  0, 0,  0, 0,  0, 0}, // #295
  {DBGFIELD("HRFID_ATTN_CLRBHRB_MFBHRBE_NAP_RFCI_RFDI_RFMCI_SC") 16383, false, false,  0, 0,  0, 0,  0, 0}, // #296
  {DBGFIELD("RFI")                16383, false, false,  0, 0,  0, 0,  0, 0}, // #297
  {DBGFIELD("RFID")               16383, false, false,  0, 0,  0, 0,  0, 0}, // #298
  {DBGFIELD("DSS_DSSALL_DST_DST64_DSTST_DSTST64_DSTSTT_DSTSTT64_DSTT_DSTT64_ICBLQ_LBEPX_LHEPX_LWEPX_TLBIVAX_TLBLD_TLBLI_TLBRE_TLBRE2_TLBSX_TLBSX2_TLBSX2D_TLBWE_TLBWE2_MBAR_TRAP_DCCCI_ICCCI") 16383, false, false,  0, 0,  0, 0,  0, 0}, // #299
  {DBGFIELD("ICBLC_STBEPX_STHEPX_STWEPX") 16383, false, false,  0, 0,  0, 0,  0, 0}, // #300
  {DBGFIELD("LFDEPX")             16383, false, false,  0, 0,  0, 0,  0, 0}, // #301
  {DBGFIELD("STFDEPX")            16383, false, false,  0, 0,  0, 0,  0, 0}, // #302
  {DBGFIELD("MFSR_MFSRIN")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #303
  {DBGFIELD("MTSR_MTSRIN")        16383, false, false,  0, 0,  0, 0,  0, 0}, // #304
  {DBGFIELD("MFDCR")              16383, false, false,  0, 0,  0, 0,  0, 0}, // #305
  {DBGFIELD("MTDCR")              16383, false, false,  0, 0,  0, 0,  0, 0}, // #306
  {DBGFIELD("NOP_GT_PWR6_NOP_GT_PWR7") 16383, false, false,  0, 0,  0, 0,  0, 0}, // #307
  {DBGFIELD("TLBIA")              16383, false, false,  0, 0,  0, 0,  0, 0}, // #308
  {DBGFIELD("WRTEE_WRTEEI")       16383, false, false,  0, 0,  0, 0,  0, 0}, // #309
  {DBGFIELD("MSYNC")              16383, false, false,  0, 0,  0, 0,  0, 0}, // #310
  {DBGFIELD("SLBSYNC")            16383, false, false,  0, 0,  0, 0,  0, 0}, // #311
  {DBGFIELD("SLBFEE_rec")         16383, false, false,  0, 0,  0, 0,  0, 0}, // #312
  {DBGFIELD("STOP")               16383, false, false,  0, 0,  0, 0,  0, 0}, // #313
  {DBGFIELD("DCBA_DCBI")          16383, false, false,  0, 0,  0, 0,  0, 0}, // #314
}; // P9ModelSchedClasses

#undef DBGFIELD

static const llvm::MCSchedModel NoSchedModel = {
  MCSchedModel::DefaultIssueWidth,
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  MCSchedModel::DefaultLoadLatency,
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  false, // PostRAScheduler
  false, // CompleteModel
  0, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  nullptr, // No Itinerary
  nullptr // No extra processor descriptor
};

static const llvm::MCSchedModel PPC440Model = {
  2, // IssueWidth
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  5, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  false, // PostRAScheduler
  false, // CompleteModel
  1, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  PPC440Itineraries,
  nullptr // No extra processor descriptor
};

static const llvm::MCSchedModel G3ItinerariesModel = {
  MCSchedModel::DefaultIssueWidth,
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  MCSchedModel::DefaultLoadLatency,
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  false, // PostRAScheduler
  false, // CompleteModel
  2, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  G3Itineraries,
  nullptr // No extra processor descriptor
};

static const llvm::MCSchedModel G4ItinerariesModel = {
  MCSchedModel::DefaultIssueWidth,
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  MCSchedModel::DefaultLoadLatency,
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  false, // PostRAScheduler
  false, // CompleteModel
  3, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  G4Itineraries,
  nullptr // No extra processor descriptor
};

static const llvm::MCSchedModel G4PlusItinerariesModel = {
  MCSchedModel::DefaultIssueWidth,
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  MCSchedModel::DefaultLoadLatency,
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  false, // PostRAScheduler
  false, // CompleteModel
  4, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  G4PlusItineraries,
  nullptr // No extra processor descriptor
};

static const llvm::MCSchedModel G5Model = {
  4, // IssueWidth
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  3, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  16, // MispredictPenalty
  false, // PostRAScheduler
  false, // CompleteModel
  5, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  G5Itineraries,
  nullptr // No extra processor descriptor
};

static const llvm::MCSchedModel PPCA2Model = {
  1, // IssueWidth
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  6, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  13, // MispredictPenalty
  false, // PostRAScheduler
  false, // CompleteModel
  6, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  PPCA2Itineraries,
  nullptr // No extra processor descriptor
};

static const llvm::MCSchedModel PPCE200Z0Model = {
  1, // IssueWidth
  0, // MicroOpBufferSize
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  4, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  3, // MispredictPenalty
  true, // PostRAScheduler
  false, // CompleteModel
  7, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  PPCE200Z0Itineraries,
  nullptr // No extra processor descriptor
};

static const llvm::MCSchedModel PPCE200Z3Model = {
  1, // IssueWidth
  0, // MicroOpBufferSize
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  2, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  3, // MispredictPenalty
  false, // PostRAScheduler
  false, // CompleteModel
  8, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  PPCE200Z3Itineraries,
  nullptr // No extra processor descriptor
};

static const llvm::MCSchedModel PPCE200Z4Model = {
  2, // IssueWidth
  0, // MicroOpBufferSize
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  2, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  3, // MispredictPenalty
  true, // PostRAScheduler
  false, // CompleteModel
  9, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  PPCE200Z4Itineraries,
  nullptr // No extra processor descriptor
};

static const llvm::MCSchedModel PPCE200Z6Model = {
  1, // IssueWidth
  0, // MicroOpBufferSize
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  4, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  3, // MispredictPenalty
  true, // PostRAScheduler
  false, // CompleteModel
  10, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  PPCE200Z6Itineraries,
  nullptr // No extra processor descriptor
};

static const llvm::MCSchedModel PPCE200Z7Model = {
  2, // IssueWidth
  0, // MicroOpBufferSize
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  3, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  6, // MispredictPenalty
  true, // PostRAScheduler
  false, // CompleteModel
  11, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  PPCE200Z7Itineraries,
  nullptr // No extra processor descriptor
};

static const llvm::MCSchedModel PPCE500Model = {
  2, // IssueWidth
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  5, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  false, // PostRAScheduler
  false, // CompleteModel
  12, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  PPCE500Itineraries,
  nullptr // No extra processor descriptor
};

static const llvm::MCSchedModel PPCE500mcModel = {
  2, // IssueWidth
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  5, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  false, // PostRAScheduler
  false, // CompleteModel
  13, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  PPCE500mcItineraries,
  nullptr // No extra processor descriptor
};

static const llvm::MCSchedModel PPCE5500Model = {
  2, // IssueWidth
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  6, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  false, // PostRAScheduler
  false, // CompleteModel
  14, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  PPCE5500Itineraries,
  nullptr // No extra processor descriptor
};

static const llvm::MCSchedModel P8Model = {
  8, // IssueWidth
  MCSchedModel::DefaultMicroOpBufferSize,
  60, // LoopMicroOpBufferSize
  3, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  16, // MispredictPenalty
  false, // PostRAScheduler
  false, // CompleteModel
  15, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  P8Itineraries,
  nullptr // No extra processor descriptor
};

static const llvm::MCSchedModel P7Model = {
  6, // IssueWidth
  MCSchedModel::DefaultMicroOpBufferSize,
  40, // LoopMicroOpBufferSize
  3, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  16, // MispredictPenalty
  false, // PostRAScheduler
  false, // CompleteModel
  16, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  P7Itineraries,
  nullptr // No extra processor descriptor
};

static const unsigned P9ModelProcResourceSubUnits[] = {
  0,  // Invalid
  10,   10,   11,   11,   12,   12,   // DISP_NBR
  10,   10,   11,   11,   // DISP_SS
};

// {Name, NumUnits, SuperIdx, BufferSize, SubUnitsIdxBegin}
static const llvm::MCProcResourceDesc P9ModelProcResources[] = {
  {"InvalidUnit", 0, 0, 0, 0},
  {"ALU",             4, 0, -1, nullptr}, // #1
  {"ALUE",            2, 1, -1, nullptr}, // #2, Super=ALU
  {"ALUO",            2, 1, -1, nullptr}, // #3, Super=ALU
  {"BR",              1, 0, 16, nullptr}, // #4
  {"CY",              1, 0, -1, nullptr}, // #5
  {"DFU",             1, 0, -1, nullptr}, // #6
  {"DISP_NBR",        6, 0, -1, P9ModelProcResourceSubUnits + 1}, // #7
  {"DISP_SS",         4, 0, -1, P9ModelProcResourceSubUnits + 7}, // #8
  {"DISPb01",         2, 0, -1, nullptr}, // #9
  {"DISPx02",         2, 0, -1, nullptr}, // #10
  {"DISPx13",         2, 0, -1, nullptr}, // #11
  {"DISPxab",         2, 0, -1, nullptr}, // #12
  {"DIV",             2, 0, -1, nullptr}, // #13
  {"DP",              4, 0, -1, nullptr}, // #14
  {"DPE",             2, 14, -1, nullptr}, // #15, Super=DP
  {"DPO",             2, 14, -1, nullptr}, // #16, Super=DP
  {"IP_AGEN",         4, 0, -1, nullptr}, // #17
  {"IP_EXEC",         4, 0, -1, nullptr}, // #18
  {"IP_EXECE",        2, 18, -1, nullptr}, // #19, Super=IP_EXEC
  {"IP_EXECO",        2, 18, -1, nullptr}, // #20, Super=IP_EXEC
  {"LS",              4, 0, -1, nullptr}, // #21
  {"PM",              2, 0, -1, nullptr}, // #22
};

static const llvm::MCSchedModel P9Model = {
  8, // IssueWidth
  44, // MicroOpBufferSize
  60, // LoopMicroOpBufferSize
  5, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  16, // MispredictPenalty
  false, // PostRAScheduler
  true, // CompleteModel
  17, // Processor ID
  P9ModelProcResources,
  P9ModelSchedClasses,
  23,
  315,
  nullptr, // No Itinerary
  nullptr // No extra processor descriptor
};

// Sorted (by key) array of values for CPU subtype.
extern const llvm::SubtargetSubTypeKV PPCSubTypeKV[] = {
 { "440", { { { 0x240c004000000008ULL, 0x18ULL, 0x0ULL, } } }, &PPC440Model },
 { "450", { { { 0x240c004000000008ULL, 0x18ULL, 0x0ULL, } } }, &PPC440Model },
 { "601", { { { 0x1000000000010ULL, 0x0ULL, 0x0ULL, } } }, &G3ItinerariesModel },
 { "602", { { { 0x1000000000020ULL, 0x8ULL, 0x0ULL, } } }, &G3ItinerariesModel },
 { "603", { { { 0xc000000000040ULL, 0x8ULL, 0x0ULL, } } }, &G3ItinerariesModel },
 { "603e", { { { 0xc000000000040ULL, 0x8ULL, 0x0ULL, } } }, &G3ItinerariesModel },
 { "603ev", { { { 0xc000000000040ULL, 0x8ULL, 0x0ULL, } } }, &G3ItinerariesModel },
 { "604", { { { 0xc000000000080ULL, 0x8ULL, 0x0ULL, } } }, &G3ItinerariesModel },
 { "604e", { { { 0xc000000000080ULL, 0x8ULL, 0x0ULL, } } }, &G3ItinerariesModel },
 { "620", { { { 0xc000000000100ULL, 0x8ULL, 0x0ULL, } } }, &G3ItinerariesModel },
 { "7400", { { { 0xc001000000800ULL, 0x8ULL, 0x0ULL, } } }, &G4ItinerariesModel },
 { "7450", { { { 0xc001000000800ULL, 0x8ULL, 0x0ULL, } } }, &G4PlusItinerariesModel },
 { "750", { { { 0xc000000000200ULL, 0x8ULL, 0x0ULL, } } }, &G4ItinerariesModel },
 { "970", { { { 0x2c001100000400ULL, 0x40000cULL, 0x0ULL, } } }, &G5Model },
 { "a2", { { { 0xa43ee0c100001000ULL, 0x150000dULL, 0x0ULL, } } }, &PPCA2Model },
 { "a2q", { { { 0xa43ee0c100001000ULL, 0x158000dULL, 0x0ULL, } } }, &PPCA2Model },
 { "e200z0", { { { 0x2400044000002000ULL, 0x18ULL, 0x0ULL, } } }, &PPCE200Z0Model },
 { "e200z3", { { { 0x2400044000004000ULL, 0x18ULL, 0x0ULL, } } }, &PPCE200Z3Model },
 { "e200z4", { { { 0x2400044000008000ULL, 0x200018ULL, 0x0ULL, } } }, &PPCE200Z4Model },
 { "e200z6", { { { 0x2401044000010000ULL, 0x18ULL, 0x0ULL, } } }, &PPCE200Z6Model },
 { "e200z7", { { { 0x2400044000020000ULL, 0x200018ULL, 0x0ULL, } } }, &PPCE200Z7Model },
 { "e500", { { { 0x2400004000040000ULL, 0x200018ULL, 0x0ULL, } } }, &PPCE500Model },
 { "e500mc", { { { 0x2400004000080000ULL, 0x400008ULL, 0x0ULL, } } }, &PPCE500mcModel },
 { "e5500", { { { 0x2400004100100000ULL, 0x40000cULL, 0x0ULL, } } }, &PPCE5500Model },
 { "future", { { { 0xbd3ef2b178000001ULL, 0x16570fedULL, 0x0ULL, } } }, &NoSchedModel },
 { "g3", { { { 0xc000000000200ULL, 0x8ULL, 0x0ULL, } } }, &G3ItinerariesModel },
 { "g4", { { { 0xc001000000800ULL, 0x8ULL, 0x0ULL, } } }, &G4ItinerariesModel },
 { "g4+", { { { 0xc001000000800ULL, 0x8ULL, 0x0ULL, } } }, &G4PlusItinerariesModel },
 { "g5", { { { 0x2c001100000401ULL, 0x40000cULL, 0x0ULL, } } }, &G5Model },
 { "generic", { { { 0x200000000000002ULL, 0x8ULL, 0x0ULL, } } }, &G3ItinerariesModel },
 { "ppc", { { { 0x200000000000002ULL, 0x8ULL, 0x0ULL, } } }, &G3ItinerariesModel },
 { "ppc32", { { { 0x200000000000002ULL, 0x8ULL, 0x0ULL, } } }, &G3ItinerariesModel },
 { "ppc64", { { { 0x2c001100000004ULL, 0x40000cULL, 0x0ULL, } } }, &G5Model },
 { "ppc64le", { { { 0xa53ef2bd18000001ULL, 0x165308edULL, 0x0ULL, } } }, &P8Model },
 { "pwr10", { { { 0xbd3ef2b178000001ULL, 0x16570fedULL, 0x0ULL, } } }, &NoSchedModel },
 { "pwr3", { { { 0xc001100200000ULL, 0x400004ULL, 0x0ULL, } } }, &G5Model },
 { "pwr4", { { { 0x2c001100400000ULL, 0x40000cULL, 0x0ULL, } } }, &G5Model },
 { "pwr5", { { { 0x3e001100800001ULL, 0x40000cULL, 0x0ULL, } } }, &G5Model },
 { "pwr5x", { { { 0x3e801101000001ULL, 0x40000cULL, 0x0ULL, } } }, &G5Model },
 { "pwr6", { { { 0x3ea09102000001ULL, 0x50000dULL, 0x0ULL, } } }, &G5Model },
 { "pwr6x", { { { 0x3ea09101000001ULL, 0x50000dULL, 0x0ULL, } } }, &G5Model },
 { "pwr7", { { { 0xa03ef0b108000001ULL, 0x1650080dULL, 0x0ULL, } } }, &P7Model },
 { "pwr8", { { { 0xa53ef2bd18000001ULL, 0x165308edULL, 0x0ULL, } } }, &P8Model },
 { "pwr9", { { { 0xad3ef2b138000001ULL, 0x3653cbedULL, 0x0ULL, } } }, &P9Model },
};

namespace PPC_MC {
unsigned resolveVariantSchedClassImpl(unsigned SchedClass,
    const MCInst *MI, unsigned CPUID) {
  // Don't know how to resolve this scheduling class.
  return 0;
}
} // end namespace PPC_MC

struct PPCGenMCSubtargetInfo : public MCSubtargetInfo {
  PPCGenMCSubtargetInfo(const Triple &TT, 
    StringRef CPU, StringRef FS, ArrayRef<SubtargetFeatureKV> PF,
    ArrayRef<SubtargetSubTypeKV> PD,
    const MCWriteProcResEntry *WPR,
    const MCWriteLatencyEntry *WL,
    const MCReadAdvanceEntry *RA, const InstrStage *IS,
    const unsigned *OC, const unsigned *FP) :
      MCSubtargetInfo(TT, CPU, FS, PF, PD,
                      WPR, WL, RA, IS, OC, FP) { }

  unsigned resolveVariantSchedClass(unsigned SchedClass,
      const MCInst *MI, unsigned CPUID) const override {
    return PPC_MC::resolveVariantSchedClassImpl(SchedClass, MI, CPUID); 
  }
};

static inline MCSubtargetInfo *createPPCMCSubtargetInfoImpl(const Triple &TT, StringRef CPU, StringRef FS) {
  return new PPCGenMCSubtargetInfo(TT, CPU, FS, PPCFeatureKV, PPCSubTypeKV, 
                      PPCWriteProcResTable, PPCWriteLatencyTable, PPCReadAdvanceTable, 
                      PPCStages, PPCOperandCycles, PPCForwardingPaths);
}

} // end namespace llvm

#endif // GET_SUBTARGETINFO_MC_DESC


#ifdef GET_SUBTARGETINFO_TARGET_DESC
#undef GET_SUBTARGETINFO_TARGET_DESC

#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"

// ParseSubtargetFeatures - Parses features string setting specified
// subtarget options.
void llvm::PPCSubtarget::ParseSubtargetFeatures(StringRef CPU, StringRef FS) {
  LLVM_DEBUG(dbgs() << "\nFeatures:" << FS);
  LLVM_DEBUG(dbgs() << "\nCPU:" << CPU << "\n\n");
  InitMCProcessorInfo(CPU, FS);
  const FeatureBitset& Bits = getFeatureBits();
  if (Bits[PPC::DeprecatedDST]) DeprecatedDST = true;
  if (Bits[PPC::Directive32] && CPUDirective < PPC::DIR_32) CPUDirective = PPC::DIR_32;
  if (Bits[PPC::Directive64] && CPUDirective < PPC::DIR_64) CPUDirective = PPC::DIR_64;
  if (Bits[PPC::Directive440] && CPUDirective < PPC::DIR_440) CPUDirective = PPC::DIR_440;
  if (Bits[PPC::Directive601] && CPUDirective < PPC::DIR_601) CPUDirective = PPC::DIR_601;
  if (Bits[PPC::Directive602] && CPUDirective < PPC::DIR_602) CPUDirective = PPC::DIR_602;
  if (Bits[PPC::Directive603] && CPUDirective < PPC::DIR_603) CPUDirective = PPC::DIR_603;
  if (Bits[PPC::Directive604] && CPUDirective < PPC::DIR_603) CPUDirective = PPC::DIR_603;
  if (Bits[PPC::Directive620] && CPUDirective < PPC::DIR_603) CPUDirective = PPC::DIR_603;
  if (Bits[PPC::Directive750] && CPUDirective < PPC::DIR_750) CPUDirective = PPC::DIR_750;
  if (Bits[PPC::Directive970] && CPUDirective < PPC::DIR_970) CPUDirective = PPC::DIR_970;
  if (Bits[PPC::Directive7400] && CPUDirective < PPC::DIR_7400) CPUDirective = PPC::DIR_7400;
  if (Bits[PPC::DirectiveA2] && CPUDirective < PPC::DIR_A2) CPUDirective = PPC::DIR_A2;
  if (Bits[PPC::DirectiveE200Z0] && CPUDirective < PPC::DIR_E200Z0) CPUDirective = PPC::DIR_E200Z0;
  if (Bits[PPC::DirectiveE200Z3] && CPUDirective < PPC::DIR_E200Z3) CPUDirective = PPC::DIR_E200Z3;
  if (Bits[PPC::DirectiveE200Z4] && CPUDirective < PPC::DIR_E200Z4) CPUDirective = PPC::DIR_E200Z4;
  if (Bits[PPC::DirectiveE200Z6] && CPUDirective < PPC::DIR_E200Z6) CPUDirective = PPC::DIR_E200Z6;
  if (Bits[PPC::DirectiveE200Z7] && CPUDirective < PPC::DIR_E200Z7) CPUDirective = PPC::DIR_E200Z7;
  if (Bits[PPC::DirectiveE500] && CPUDirective < PPC::DIR_E500) CPUDirective = PPC::DIR_E500;
  if (Bits[PPC::DirectiveE500mc] && CPUDirective < PPC::DIR_E500mc) CPUDirective = PPC::DIR_E500mc;
  if (Bits[PPC::DirectiveE5500] && CPUDirective < PPC::DIR_E5500) CPUDirective = PPC::DIR_E5500;
  if (Bits[PPC::DirectivePwr3] && CPUDirective < PPC::DIR_PWR3) CPUDirective = PPC::DIR_PWR3;
  if (Bits[PPC::DirectivePwr4] && CPUDirective < PPC::DIR_PWR4) CPUDirective = PPC::DIR_PWR4;
  if (Bits[PPC::DirectivePwr5] && CPUDirective < PPC::DIR_PWR5) CPUDirective = PPC::DIR_PWR5;
  if (Bits[PPC::DirectivePwr5x] && CPUDirective < PPC::DIR_PWR5X) CPUDirective = PPC::DIR_PWR5X;
  if (Bits[PPC::DirectivePwr6] && CPUDirective < PPC::DIR_PWR6) CPUDirective = PPC::DIR_PWR6;
  if (Bits[PPC::DirectivePwr6x] && CPUDirective < PPC::DIR_PWR6X) CPUDirective = PPC::DIR_PWR6X;
  if (Bits[PPC::DirectivePwr7] && CPUDirective < PPC::DIR_PWR7) CPUDirective = PPC::DIR_PWR7;
  if (Bits[PPC::DirectivePwr8] && CPUDirective < PPC::DIR_PWR8) CPUDirective = PPC::DIR_PWR8;
  if (Bits[PPC::DirectivePwr9] && CPUDirective < PPC::DIR_PWR9) CPUDirective = PPC::DIR_PWR9;
  if (Bits[PPC::DirectivePwr10] && CPUDirective < PPC::DIR_PWR10) CPUDirective = PPC::DIR_PWR10;
  if (Bits[PPC::DirectivePwrFuture] && CPUDirective < PPC::DIR_PWR_FUTURE) CPUDirective = PPC::DIR_PWR_FUTURE;
  if (Bits[PPC::Feature64Bit]) Has64BitSupport = true;
  if (Bits[PPC::Feature64BitRegs]) Use64BitRegs = true;
  if (Bits[PPC::FeatureAddiLoadFusion]) HasAddiLoadFusion = true;
  if (Bits[PPC::FeatureAddisLoadFusion]) HasAddisLoadFusion = true;
  if (Bits[PPC::FeatureAltivec]) HasAltivec = true;
  if (Bits[PPC::FeatureBPERMD]) HasBPERMD = true;
  if (Bits[PPC::FeatureBookE]) IsBookE = true;
  if (Bits[PPC::FeatureCMPB]) HasCMPB = true;
  if (Bits[PPC::FeatureCRBits]) UseCRBits = true;
  if (Bits[PPC::FeatureDirectMove]) HasDirectMove = true;
  if (Bits[PPC::FeatureE200]) IsE200 = true;
  if (Bits[PPC::FeatureE500]) IsE500 = true;
  if (Bits[PPC::FeatureExtDiv]) HasExtDiv = true;
  if (Bits[PPC::FeatureFCPSGN]) HasFCPSGN = true;
  if (Bits[PPC::FeatureFPCVT]) HasFPCVT = true;
  if (Bits[PPC::FeatureFPRND]) HasFPRND = true;
  if (Bits[PPC::FeatureFPU]) HasFPU = true;
  if (Bits[PPC::FeatureFRE]) HasFRE = true;
  if (Bits[PPC::FeatureFRES]) HasFRES = true;
  if (Bits[PPC::FeatureFRSQRTE]) HasFRSQRTE = true;
  if (Bits[PPC::FeatureFRSQRTES]) HasFRSQRTES = true;
  if (Bits[PPC::FeatureFSqrt]) HasFSQRT = true;
  if (Bits[PPC::FeatureFloat128]) HasFloat128 = true;
  if (Bits[PPC::FeatureFusion]) HasFusion = true;
  if (Bits[PPC::FeatureHTM]) HasHTM = true;
  if (Bits[PPC::FeatureHardFloat]) HasHardFloat = true;
  if (Bits[PPC::FeatureICBT]) HasICBT = true;
  if (Bits[PPC::FeatureISA3_0]) IsISA3_0 = true;
  if (Bits[PPC::FeatureISA3_1]) IsISA3_1 = true;
  if (Bits[PPC::FeatureISEL]) HasISEL = true;
  if (Bits[PPC::FeatureInvariantFunctionDescriptors]) HasInvariantFunctionDescriptors = true;
  if (Bits[PPC::FeatureLDBRX]) HasLDBRX = true;
  if (Bits[PPC::FeatureLFIWAX]) HasLFIWAX = true;
  if (Bits[PPC::FeatureLongCall]) UseLongCalls = true;
  if (Bits[PPC::FeatureMFOCRF]) HasMFOCRF = true;
  if (Bits[PPC::FeatureMFTB]) FeatureMFTB = true;
  if (Bits[PPC::FeatureMSYNC]) HasOnlyMSYNC = true;
  if (Bits[PPC::FeatureP8Altivec]) HasP8Altivec = true;
  if (Bits[PPC::FeatureP8Crypto]) HasP8Crypto = true;
  if (Bits[PPC::FeatureP8Vector]) HasP8Vector = true;
  if (Bits[PPC::FeatureP9Altivec]) HasP9Altivec = true;
  if (Bits[PPC::FeatureP9Vector]) HasP9Vector = true;
  if (Bits[PPC::FeaturePCRelativeMemops]) HasPCRelativeMemops = true;
  if (Bits[PPC::FeaturePOPCNTD] && HasPOPCNTD < POPCNTD_Fast) HasPOPCNTD = POPCNTD_Fast;
  if (Bits[PPC::FeaturePPC4xx]) IsPPC4xx = true;
  if (Bits[PPC::FeaturePPC6xx]) IsPPC6xx = true;
  if (Bits[PPC::FeaturePPCPostRASched]) UsePPCPostRASchedStrategy = true;
  if (Bits[PPC::FeaturePPCPreRASched]) UsePPCPreRASchedStrategy = true;
  if (Bits[PPC::FeaturePartwordAtomic]) HasPartwordAtomics = true;
  if (Bits[PPC::FeaturePredictableSelectIsExpensive]) PredictableSelectIsExpensive = true;
  if (Bits[PPC::FeaturePrefixInstrs]) HasPrefixInstrs = true;
  if (Bits[PPC::FeatureQPX]) HasQPX = true;
  if (Bits[PPC::FeatureRecipPrec]) HasRecipPrec = true;
  if (Bits[PPC::FeatureSPE]) HasSPE = true;
  if (Bits[PPC::FeatureSTFIWX]) HasSTFIWX = true;
  if (Bits[PPC::FeatureSecurePlt]) SecurePlt = true;
  if (Bits[PPC::FeatureSlowPOPCNTD] && HasPOPCNTD < POPCNTD_Slow) HasPOPCNTD = POPCNTD_Slow;
  if (Bits[PPC::FeatureTwoConstNR]) NeedsTwoConstNR = true;
  if (Bits[PPC::FeatureUnalignedFloats]) AllowsUnalignedFPAccess = true;
  if (Bits[PPC::FeatureVLE]) HasVLE = true;
  if (Bits[PPC::FeatureVSX]) HasVSX = true;
  if (Bits[PPC::FeatureVectorsUseTwoUnits]) VectorsUseTwoUnits = true;
}
#endif // GET_SUBTARGETINFO_TARGET_DESC


#ifdef GET_SUBTARGETINFO_HEADER
#undef GET_SUBTARGETINFO_HEADER

namespace llvm {
class DFAPacketizer;
namespace PPC_MC {
unsigned resolveVariantSchedClassImpl(unsigned SchedClass, const MCInst *MI, unsigned CPUID);
} // end namespace PPC_MC

struct PPCGenSubtargetInfo : public TargetSubtargetInfo {
  explicit PPCGenSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS);
public:
  unsigned resolveSchedClass(unsigned SchedClass,  const MachineInstr *DefMI, const TargetSchedModel *SchedModel) const override;
  unsigned resolveVariantSchedClass(unsigned SchedClass, const MCInst *MI, unsigned CPUID) const override;
  DFAPacketizer *createDFAPacketizer(const InstrItineraryData *IID) const;
};
} // end namespace llvm

#endif // GET_SUBTARGETINFO_HEADER


#ifdef GET_SUBTARGETINFO_CTOR
#undef GET_SUBTARGETINFO_CTOR

#include "llvm/CodeGen/TargetSchedule.h"

namespace llvm {
extern const llvm::SubtargetFeatureKV PPCFeatureKV[];
extern const llvm::SubtargetSubTypeKV PPCSubTypeKV[];
extern const llvm::MCWriteProcResEntry PPCWriteProcResTable[];
extern const llvm::MCWriteLatencyEntry PPCWriteLatencyTable[];
extern const llvm::MCReadAdvanceEntry PPCReadAdvanceTable[];
extern const llvm::InstrStage PPCStages[];
extern const unsigned PPCOperandCycles[];
extern const unsigned PPCForwardingPaths[];
PPCGenSubtargetInfo::PPCGenSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS)
  : TargetSubtargetInfo(TT, CPU, FS, makeArrayRef(PPCFeatureKV, 61), makeArrayRef(PPCSubTypeKV, 44), 
                        PPCWriteProcResTable, PPCWriteLatencyTable, PPCReadAdvanceTable, 
                        PPCStages, PPCOperandCycles, PPCForwardingPaths) {}

unsigned PPCGenSubtargetInfo
::resolveSchedClass(unsigned SchedClass, const MachineInstr *MI, const TargetSchedModel *SchedModel) const {
  report_fatal_error("Expected a variant SchedClass");
} // PPCGenSubtargetInfo::resolveSchedClass

unsigned PPCGenSubtargetInfo
::resolveVariantSchedClass(unsigned SchedClass, const MCInst *MI, unsigned CPUID) const {
  return PPC_MC::resolveVariantSchedClassImpl(SchedClass, MI, CPUID);
} // PPCGenSubtargetInfo::resolveVariantSchedClass

} // end namespace llvm

#endif // GET_SUBTARGETINFO_CTOR


#ifdef GET_STIPREDICATE_DECLS_FOR_MC_ANALYSIS
#undef GET_STIPREDICATE_DECLS_FOR_MC_ANALYSIS

#endif // GET_STIPREDICATE_DECLS_FOR_MC_ANALYSIS


#ifdef GET_STIPREDICATE_DEFS_FOR_MC_ANALYSIS
#undef GET_STIPREDICATE_DEFS_FOR_MC_ANALYSIS

#endif // GET_STIPREDICATE_DEFS_FOR_MC_ANALYSIS

