//===-- BareMetal.cpp - Bare Metal ToolChain --------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "BareMetal.h"

#include "CommonArgs.h"
#include "Gnu.h"
#include "InputInfo.h"

#include "clang/Driver/Compilation.h"
#include "clang/Driver/Driver.h"
#include "clang/Driver/DriverDiagnostic.h"
#include "clang/Driver/Options.h"
#include "llvm/Option/ArgList.h"
#include "llvm/Support/Path.h"
#include "llvm/Support/VirtualFileSystem.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm::opt;
using namespace clang;
using namespace clang::driver;
using namespace clang::driver::tools;
using namespace clang::driver::toolchains;

BareMetal::BareMetal(const Driver &D, const llvm::Triple &Triple,
                     const ArgList &Args)
    : ToolChain(D, Triple, Args) {
  getProgramPaths().push_back(getDriver().getInstalledDir());
  if (getDriver().getInstalledDir() != getDriver().Dir)
    getProgramPaths().push_back(getDriver().Dir);
}

BareMetal::~BareMetal() {}

/// Is the triple {arm,thumb}-none-none-{eabi,eabihf} ?
///
/// This function identifies ARM bare-metal triples for which the BareMetal
/// toolchain should be used.
///
/// \param Triple The target triple to check
/// \returns true if this is an ARM bare-metal triple
static bool isARMBareMetal(const llvm::Triple &Triple) {
  if (Triple.getArch() != llvm::Triple::arm &&
      Triple.getArch() != llvm::Triple::thumb)
    return false;

  if (Triple.getVendor() != llvm::Triple::UnknownVendor)
    return false;

  if (Triple.getOS() != llvm::Triple::UnknownOS)
    return false;

  if (Triple.getEnvironment() != llvm::Triple::EABI &&
      Triple.getEnvironment() != llvm::Triple::EABIHF)
    return false;

  return true;
}

/// Is the triple powerpc{64}?-none-none-{elf,eabi,eabivle} ?
///
/// This function identifies PowerPC bare-metal triples for which the BareMetal
/// toolchain should be used. Supports both 32-bit and 64-bit PowerPC targets.
///
/// Recognized triples:
///   - powerpc-none-elf (UnknownEnvironment, ELF format)
///   - powerpc-none-eabi (EABI environment)
///   - powerpc-none-eabivle (parsed as EABI, with VLE support)
///   - powerpc64-none-elf (64-bit variants)
///
/// \param Triple The target triple to check
/// \returns true if this is a PowerPC bare-metal triple
static bool isPowerPCBareMetal(const llvm::Triple &Triple) {
  if (Triple.getArch() != llvm::Triple::ppc &&
      Triple.getArch() != llvm::Triple::ppc64 &&
      Triple.getArch() != llvm::Triple::ppc64le)
    return false;

  if (Triple.getVendor() != llvm::Triple::UnknownVendor)
    return false;

  if (Triple.getOS() != llvm::Triple::UnknownOS)
    return false;

  // Accept EABI (covers "eabi" and "eabivle"), GNU, or UnknownEnvironment (covers "elf")
  // Note: "eabivle" parses as EABI because Triple parsing checks StartsWith("eabi")
  //       "elf" is an object format, so those triples have UnknownEnvironment
  if (Triple.getEnvironment() != llvm::Triple::EABI &&
      Triple.getEnvironment() != llvm::Triple::GNU &&
      Triple.getEnvironment() != llvm::Triple::UnknownEnvironment)
    return false;

  return true;
}

/// Check if the BareMetal toolchain should handle the given target triple.
///
/// Handles ARM and PowerPC bare-metal targets:
///   - ARM: {arm,thumb}-none-none-{eabi,eabihf}
///   - PowerPC: powerpc{64}?-none-none-{elf,eabi,eabivle}
///
/// \param Triple The target triple to check
/// \returns true if this toolchain should handle the target
bool BareMetal::handlesTarget(const llvm::Triple &Triple) {
  return isARMBareMetal(Triple) || isPowerPCBareMetal(Triple);
}

Tool *BareMetal::buildLinker() const {
  return new tools::baremetal::Linker(*this);
}

std::string BareMetal::getRuntimesDir() const {
  SmallString<128> Dir(getDriver().ResourceDir);
  llvm::sys::path::append(Dir, "lib", "baremetal");
  return std::string(Dir.str());
}

void BareMetal::AddClangSystemIncludeArgs(const ArgList &DriverArgs,
                                          ArgStringList &CC1Args) const {
  if (DriverArgs.hasArg(options::OPT_nostdinc))
    return;

  if (!DriverArgs.hasArg(options::OPT_nobuiltininc)) {
    SmallString<128> Dir(getDriver().ResourceDir);
    llvm::sys::path::append(Dir, "include");
    addSystemInclude(DriverArgs, CC1Args, Dir.str());
  }

  if (!DriverArgs.hasArg(options::OPT_nostdlibinc)) {
    SmallString<128> Dir(getDriver().SysRoot);
    llvm::sys::path::append(Dir, "include");
    addSystemInclude(DriverArgs, CC1Args, Dir.str());
  }
}

void BareMetal::addClangTargetOptions(const ArgList &DriverArgs,
                                      ArgStringList &CC1Args,
                                      Action::OffloadKind) const {
  CC1Args.push_back("-nostdsysteminc");
}

void BareMetal::AddClangCXXStdlibIncludeArgs(const ArgList &DriverArgs,
                                             ArgStringList &CC1Args) const {
  if (DriverArgs.hasArg(options::OPT_nostdinc) ||
      DriverArgs.hasArg(options::OPT_nostdlibinc) ||
      DriverArgs.hasArg(options::OPT_nostdincxx))
    return;

  StringRef SysRoot = getDriver().SysRoot;
  if (SysRoot.empty())
    return;

  switch (GetCXXStdlibType(DriverArgs)) {
  case ToolChain::CST_Libcxx: {
    SmallString<128> Dir(SysRoot);
    llvm::sys::path::append(Dir, "include", "c++", "v1");
    addSystemInclude(DriverArgs, CC1Args, Dir.str());
    break;
  }
  case ToolChain::CST_Libstdcxx: {
    SmallString<128> Dir(SysRoot);
    llvm::sys::path::append(Dir, "include", "c++");
    std::error_code EC;
    Generic_GCC::GCCVersion Version = {"", -1, -1, -1, "", "", ""};
    // Walk the subdirs, and find the one with the newest gcc version:
    for (llvm::vfs::directory_iterator
             LI = getDriver().getVFS().dir_begin(Dir.str(), EC),
             LE;
         !EC && LI != LE; LI = LI.increment(EC)) {
      StringRef VersionText = llvm::sys::path::filename(LI->path());
      auto CandidateVersion = Generic_GCC::GCCVersion::Parse(VersionText);
      if (CandidateVersion.Major == -1)
        continue;
      if (CandidateVersion <= Version)
        continue;
      Version = CandidateVersion;
    }
    if (Version.Major == -1)
      return;
    llvm::sys::path::append(Dir, Version.Text);
    addSystemInclude(DriverArgs, CC1Args, Dir.str());
    break;
  }
  }
}

void BareMetal::AddCXXStdlibLibArgs(const ArgList &Args,
                                    ArgStringList &CmdArgs) const {
  switch (GetCXXStdlibType(Args)) {
  case ToolChain::CST_Libcxx:
    CmdArgs.push_back("-lc++");
    CmdArgs.push_back("-lc++abi");
    break;
  case ToolChain::CST_Libstdcxx:
    CmdArgs.push_back("-lstdc++");
    CmdArgs.push_back("-lsupc++");
    break;
  }
  CmdArgs.push_back("-lunwind");
}

void BareMetal::AddLinkRuntimeLib(const ArgList &Args,
                                  ArgStringList &CmdArgs) const {
  CmdArgs.push_back(
      Args.MakeArgString("-lclang_rt.builtins-" + getTriple().getArchName()));
}

void baremetal::Linker::ConstructJob(Compilation &C, const JobAction &JA,
                                     const InputInfo &Output,
                                     const InputInfoList &Inputs,
                                     const ArgList &Args,
                                     const char *LinkingOutput) const {
  ArgStringList CmdArgs;

  auto &TC = static_cast<const toolchains::BareMetal &>(getToolChain());

  // Add startup files (crt0, crtbegin) if not disabled
  bool WantCRTs =
      !Args.hasArg(options::OPT_nostdlib, options::OPT_nostartfiles);
  
  if (WantCRTs) {
    const llvm::Triple &Triple = TC.getTriple();
    bool IsPowerPC = Triple.getArch() == llvm::Triple::ppc ||
                     Triple.getArch() == llvm::Triple::ppc64 ||
                     Triple.getArch() == llvm::Triple::ppc64le;
    
    if (IsPowerPC) {
      // For PowerPC baremetal, link crt0 (startup code)
      // Use VLE version if targeting powerpc-none-eabivle
      bool IsVLE = Triple.getEnvironment() == llvm::Triple::EABI &&
                   Triple.getTriple().find("eabivle") != std::string::npos;
      
      if (IsVLE) {
        // Try to find VLE crt0
        std::string Crt0VLE = TC.getCompilerRT(Args, "crt0-vle",
                                                ToolChain::FT_Object);
        if (TC.getVFS().exists(Crt0VLE)) {
          CmdArgs.push_back(Args.MakeArgString(Crt0VLE));
        } else {
          // Fallback to standard crt0
          std::string Crt0 = TC.getCompilerRT(Args, "crt0",
                                               ToolChain::FT_Object);
          if (TC.getVFS().exists(Crt0))
            CmdArgs.push_back(Args.MakeArgString(Crt0));
        }
      } else {
        // Standard PowerPC crt0
        std::string Crt0 = TC.getCompilerRT(Args, "crt0",
                                             ToolChain::FT_Object);
        if (TC.getVFS().exists(Crt0))
          CmdArgs.push_back(Args.MakeArgString(Crt0));
      }
      
      // Add crtbegin for C++ support
      std::string CrtBegin = TC.getCompilerRT(Args, "crtbegin",
                                               ToolChain::FT_Object);
      if (TC.getVFS().exists(CrtBegin))
        CmdArgs.push_back(Args.MakeArgString(CrtBegin));
    }
  }

  AddLinkerInputs(TC, Inputs, Args, CmdArgs, JA);

  CmdArgs.push_back("-Bstatic");

  CmdArgs.push_back(Args.MakeArgString("-L" + TC.getRuntimesDir()));

  Args.AddAllArgs(CmdArgs, {options::OPT_L, options::OPT_T_Group,
                            options::OPT_e, options::OPT_s, options::OPT_t,
                            options::OPT_Z_Flag, options::OPT_r});

  if (TC.ShouldLinkCXXStdlib(Args))
    TC.AddCXXStdlibLibArgs(Args, CmdArgs);
  if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nodefaultlibs)) {
    CmdArgs.push_back("-lc");
    CmdArgs.push_back("-lm");

    TC.AddLinkRuntimeLib(Args, CmdArgs);
  }
  
  // Add crtend for C++ support (after libraries, before end)
  if (WantCRTs) {
    const llvm::Triple &Triple = TC.getTriple();
    bool IsPowerPC = Triple.getArch() == llvm::Triple::ppc ||
                     Triple.getArch() == llvm::Triple::ppc64 ||
                     Triple.getArch() == llvm::Triple::ppc64le;
    
    if (IsPowerPC) {
      std::string CrtEnd = TC.getCompilerRT(Args, "crtend",
                                             ToolChain::FT_Object);
      if (TC.getVFS().exists(CrtEnd))
        CmdArgs.push_back(Args.MakeArgString(CrtEnd));
    }
  }

  CmdArgs.push_back("-o");
  CmdArgs.push_back(Output.getFilename());

  C.addCommand(std::make_unique<Command>(
      JA, *this, Args.MakeArgString(TC.GetLinkerPath()), CmdArgs, Inputs));
}
