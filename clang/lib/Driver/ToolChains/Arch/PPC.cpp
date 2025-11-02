//===--- PPC.cpp - PPC Helpers for Tools ------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "PPC.h"
#include "clang/Driver/CommonArgs.h"
#include "clang/Driver/Driver.h"
#include "clang/Driver/Options.h"
#include "llvm/ADT/StringSwitch.h"
#include "llvm/Option/ArgList.h"
#include "llvm/TargetParser/Host.h"

using namespace clang::driver;
using namespace clang::driver::tools;
using namespace clang;
using namespace llvm::opt;

<<<<<<< HEAD
/// getPPCTargetCPU - Get the (LLVM) name of the PowerPC cpu we are targeting.
std::string ppc::getPPCTargetCPU(const ArgList &Args) {
  if (Arg *A = Args.getLastArg(clang::driver::options::OPT_mcpu_EQ)) {
    StringRef CPUName = A->getValue();

    if (CPUName == "native") {
      std::string CPU = std::string(llvm::sys::getHostCPUName());
      if (!CPU.empty() && CPU != "generic")
        return CPU;
      else
        return "";
    }

    return llvm::StringSwitch<const char *>(CPUName)
        .Case("common", "generic")
        .Case("440", "440")
        .Case("440fp", "440")
        .Case("450", "450")
        .Case("601", "601")
        .Case("602", "602")
        .Case("603", "603")
        .Case("603e", "603e")
        .Case("603ev", "603ev")
        .Case("604", "604")
        .Case("604e", "604e")
        .Case("620", "620")
        .Case("630", "pwr3")
        .Case("G3", "g3")
        .Case("7400", "7400")
        .Case("G4", "g4")
        .Case("7450", "7450")
        .Case("G4+", "g4+")
        .Case("750", "750")
        .Case("8548", "e500")
        .Case("970", "970")
        .Case("G5", "g5")
        .Case("a2", "a2")
        .Case("a2q", "a2q")
        .Case("e500", "e500")
        .Case("e500mc", "e500mc")
        .Case("e5500", "e5500")
        .Case("e200", "e200z0")
        .Case("e200z0", "e200z0")
        .Case("e200z4", "e200z4")
        .Case("e200z6", "e200z6")
        .Case("e200z7", "e200z7")
        .Case("power3", "pwr3")
        .Case("power4", "pwr4")
        .Case("power5", "pwr5")
        .Case("power5x", "pwr5x")
        .Case("power6", "pwr6")
        .Case("power6x", "pwr6x")
        .Case("power7", "pwr7")
        .Case("power8", "pwr8")
        .Case("power9", "pwr9")
        .Case("power10", "pwr10")
        .Case("future", "future")
        .Case("pwr3", "pwr3")
        .Case("pwr4", "pwr4")
        .Case("pwr5", "pwr5")
        .Case("pwr5x", "pwr5x")
        .Case("pwr6", "pwr6")
        .Case("pwr6x", "pwr6x")
        .Case("pwr7", "pwr7")
        .Case("pwr8", "pwr8")
        .Case("pwr9", "pwr9")
        .Case("pwr10", "pwr10")
        .Case("powerpc", "ppc")
        .Case("powerpc64", "ppc64")
        .Case("powerpc64le", "ppc64le")
        .Default("");
  }

  return "";
}

=======
>>>>>>> upstream/main
const char *ppc::getPPCAsmModeForCPU(StringRef Name) {
  return llvm::StringSwitch<const char *>(Name)
      .Case("pwr7", "-mpower7")
      .Case("power7", "-mpower7")
      .Case("pwr8", "-mpower8")
      .Case("power8", "-mpower8")
      .Case("ppc64le", "-mpower8")
      .Case("pwr9", "-mpower9")
      .Case("power9", "-mpower9")
      .Case("pwr10", "-mpower10")
      .Case("power10", "-mpower10")
      .Case("pwr11", "-mpower11")
      .Case("power11", "-mpower11")
      .Default("-many");
}

/// getPPCTargetFeatures - Collect PowerPC target features from command-line
/// arguments and target triple.
///
/// This function processes PowerPC-specific target features including:
/// - SPE (Signal Processing Extension) support based on sub-architecture
/// - VLE (Variable Length Encoding) mode for embedded e200 cores
/// - Float ABI selection (hard/soft float)
/// - Secure PLT mode for certain operating systems
///
/// For embedded PowerPC targets (powerpc-none-elf, powerpc-none-eabivle),
/// VLE support is determined by:
/// - Target triple environment: eabivle enables VLE by default
/// - -mvle / -mno-vle flags (explicit control)
///
/// \param D The driver instance for diagnostics
/// \param Triple The target triple
/// \param Args The command-line arguments
/// \param Features Output vector of target features (e.g., "+vle", "-hard-float")
void ppc::getPPCTargetFeatures(const Driver &D, const llvm::Triple &Triple,
                               const ArgList &Args,
                               std::vector<StringRef> &Features) {
  if (Triple.getSubArch() == llvm::Triple::PPCSubArch_spe)
    Features.push_back("+spe");

<<<<<<< HEAD
  // Process VLE mode for embedded PowerPC e200 targets.
  // VLE is enabled by default for powerpc-none-eabivle triples, or explicitly
  // via -mvle flag. The feature is handled by handleTargetFeaturesGroup which
  // processes options::OPT_m_ppc_Features_Group (including -mvle).
  handleTargetFeaturesGroup(Args, Features, options::OPT_m_ppc_Features_Group);
=======
  handleTargetFeaturesGroup(D, Triple, Args, Features,
                            options::OPT_m_ppc_Features_Group);
>>>>>>> upstream/main

  ppc::FloatABI FloatABI = ppc::getPPCFloatABI(D, Args);
  if (FloatABI == ppc::FloatABI::Soft)
    Features.push_back("-hard-float");

  ppc::ReadGOTPtrMode ReadGOT = ppc::getPPCReadGOTPtrMode(D, Triple, Args);
  if (ReadGOT == ppc::ReadGOTPtrMode::SecurePlt)
    Features.push_back("+secure-plt");

  bool UseSeparateSections = isUseSeparateSections(Triple);
  bool HasDefaultDataSections = Triple.isOSBinFormatXCOFF();
  if (Args.hasArg(options::OPT_maix_small_local_exec_tls) ||
      Args.hasArg(options::OPT_maix_small_local_dynamic_tls)) {
    if (!Triple.isOSAIX() || !Triple.isArch64Bit())
      D.Diag(diag::err_opt_not_valid_on_target)
          << "-maix-small-local-[exec|dynamic]-tls";

    // The -maix-small-local-[exec|dynamic]-tls option should only be used with
    // -fdata-sections, as having data sections turned off with this option
    // is not ideal for performance. Moreover, the
    // small-local-[exec|dynamic]-tls region is a limited resource, and should
    // not be used for variables that may be replaced.
    if (!Args.hasFlag(options::OPT_fdata_sections,
                      options::OPT_fno_data_sections,
                      UseSeparateSections || HasDefaultDataSections))
      D.Diag(diag::err_drv_argument_only_allowed_with)
          << "-maix-small-local-[exec|dynamic]-tls" << "-fdata-sections";
  }

  if (Args.hasArg(options::OPT_maix_shared_lib_tls_model_opt) &&
      !(Triple.isOSAIX() && Triple.isArch64Bit()))
    D.Diag(diag::err_opt_not_valid_on_target)
        << "-maix-shared-lib-tls-model-opt";
}

ppc::ReadGOTPtrMode ppc::getPPCReadGOTPtrMode(const Driver &D, const llvm::Triple &Triple,
                                              const ArgList &Args) {
  if (Args.getLastArg(options::OPT_msecure_plt))
    return ppc::ReadGOTPtrMode::SecurePlt;
  if (Triple.isPPC32SecurePlt())
    return ppc::ReadGOTPtrMode::SecurePlt;
  else
    return ppc::ReadGOTPtrMode::Bss;
}

ppc::FloatABI ppc::getPPCFloatABI(const Driver &D, const ArgList &Args) {
  ppc::FloatABI ABI = ppc::FloatABI::Invalid;
  if (Arg *A =
          Args.getLastArg(options::OPT_msoft_float, options::OPT_mhard_float,
                          options::OPT_mfloat_abi_EQ)) {
    if (A->getOption().matches(options::OPT_msoft_float))
      ABI = ppc::FloatABI::Soft;
    else if (A->getOption().matches(options::OPT_mhard_float))
      ABI = ppc::FloatABI::Hard;
    else {
      ABI = llvm::StringSwitch<ppc::FloatABI>(A->getValue())
                .Case("soft", ppc::FloatABI::Soft)
                .Case("hard", ppc::FloatABI::Hard)
                .Default(ppc::FloatABI::Invalid);
      if (ABI == ppc::FloatABI::Invalid && !StringRef(A->getValue()).empty()) {
        D.Diag(clang::diag::err_drv_invalid_mfloat_abi) << A->getAsString(Args);
        ABI = ppc::FloatABI::Hard;
      }
    }
  }

  // If unspecified, choose the default based on the platform.
  if (ABI == ppc::FloatABI::Invalid) {
    ABI = ppc::FloatABI::Hard;
  }

  return ABI;
}

bool ppc::hasPPCAbiArg(const ArgList &Args, const char *Value) {
  Arg *A = Args.getLastArg(options::OPT_mabi_EQ);
  return A && (A->getValue() == StringRef(Value));
}
