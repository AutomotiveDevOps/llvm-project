//===-- BareMetal.cpp - Bare Metal ToolChain --------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "BareMetal.h"

#include "CommonArgs.h"
#include "InputInfo.h"
#include "Gnu.h"
#include "ToolChains/Arch/PPC.h"

#include "clang/Driver/Compilation.h"
#include "clang/Driver/Driver.h"
#include "clang/Driver/DriverDiagnostic.h"
#include "clang/Driver/Options.h"
#include "llvm/Option/ArgList.h"
#include "llvm/Support/Path.h"
#include "llvm/Support/VirtualFileSystem.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/FileSystem.h"
#include <fstream>
#include <sstream>

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

/// Is the triple powerpc-none-eabi?
static bool isPowerPCBareMetal(const llvm::Triple &Triple) {
  if (Triple.getArch() != llvm::Triple::ppc)
    return false;

  if (Triple.getVendor() != llvm::Triple::UnknownVendor)
    return false;

  if (Triple.getOS() != llvm::Triple::UnknownOS)
    return false;

  if (Triple.getEnvironment() != llvm::Triple::EABI)
    return false;

  return true;
}

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

void BareMetal::AddClangCXXStdlibIncludeArgs(
    const ArgList &DriverArgs, ArgStringList &CC1Args) const {
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
  CmdArgs.push_back(Args.MakeArgString("-lclang_rt.builtins-" +
                                       getTriple().getArchName()));
}

/// Generate a linker script for PowerPC e200 cores
/// Returns the path to the generated linker script, or empty string on failure
static std::string generateE200LinkerScript(const Driver &D, Compilation &C,
                                             const JobAction &JA,
                                             const ArgList &Args,
                                             StringRef CPU) {
  // Only generate for e200 cores
  if (!CPU.startswith("e200z") && !CPU.startswith("e200"))
    return "";

  // Normalize CPU name
  StringRef CPUName = CPU;
  if (CPUName == "e200z0" || CPUName == "e200" || CPUName == "ppc")
    CPUName = "e200z0";
  else if (CPUName == "e200z4")
    CPUName = "e200z4";
  else if (CPUName == "e200z6")
    CPUName = "e200z6";
  else if (CPUName == "e200z7")
    CPUName = "e200z7";
  else
    return "";

  // Create a temporary linker script file
  SmallString<128> ScriptPath;
  const char *ScriptFile;
  if (D.isSaveTempsEnabled()) {
    // Use output filename base + .ld extension for save-temps
    std::string OutputBase = llvm::sys::path::stem(
        C.getJobs().getDefaultOutputFile(JA, "out"));
    ScriptFile = C.getArgs().MakeArgString(OutputBase + ".ld");
  } else {
    // Create temporary file
    auto TmpName = D.GetTemporaryPath(CPUName, "ld");
    ScriptFile = C.addTempFile(C.getArgs().MakeArgString(TmpName));
    ScriptPath = TmpName;
  }

  // Generate linker script content
  std::string ScriptContent;
  llvm::raw_string_ostream ScriptOS(ScriptContent);

  // Default memory layout: 256KB Flash at 0x00000000, 64KB RAM at 0x20000000
  // These can be overridden with linker script options in the future
  const char *FlashStart = "0x00000000";
  const char *FlashSize = "256K";
  const char *RAMStart = "0x20000000";
  const char *RAMSize = "64K";

  ScriptOS << "/* Linker script for PowerPC " << CPUName << " e200 core\n";
  ScriptOS << " * Auto-generated by Clang\n";
  ScriptOS << " */\n\n";

  ScriptOS << "MEMORY\n";
  ScriptOS << "{\n";
  ScriptOS << "  FLASH (rx) : ORIGIN = " << FlashStart << ", LENGTH = " << FlashSize << "\n";
  ScriptOS << "  RAM (rwx)  : ORIGIN = " << RAMStart << ", LENGTH = " << RAMSize << "\n";
  ScriptOS << "}\n\n";

  ScriptOS << "ENTRY(_start)\n\n";

  ScriptOS << "SECTIONS\n";
  ScriptOS << "{\n";
  ScriptOS << "  . = ORIGIN(FLASH);\n\n";

  // Interrupt Vector Offset Register (IVOR) table
  ScriptOS << "  .ivor_table : {\n";
  ScriptOS << "    KEEP(*(.ivor_table))\n";
  ScriptOS << "  } > FLASH\n\n";

  // Text section
  ScriptOS << "  .text : {\n";
  ScriptOS << "    *(.text.startup)\n";
  ScriptOS << "    *(.text)\n";
  ScriptOS << "    *(.text.*)\n";
  ScriptOS << "    . = ALIGN(4);\n";
  ScriptOS << "  } > FLASH\n\n";

  // Read-only data
  ScriptOS << "  .rodata : {\n";
  ScriptOS << "    *(.rodata)\n";
  ScriptOS << "    *(.rodata.*)\n";
  ScriptOS << "    . = ALIGN(4);\n";
  ScriptOS << "  } > FLASH\n\n";

  // Constructor/destructor tables
  ScriptOS << "  .ctors : {\n";
  ScriptOS << "    PROVIDE(__ctors_start__ = .);\n";
  ScriptOS << "    KEEP(*(SORT(.ctors.*)))\n";
  ScriptOS << "    KEEP(*(.ctors))\n";
  ScriptOS << "    PROVIDE(__ctors_end__ = .);\n";
  ScriptOS << "  } > FLASH\n\n";

  ScriptOS << "  .dtors : {\n";
  ScriptOS << "    PROVIDE(__dtors_start__ = .);\n";
  ScriptOS << "    KEEP(*(SORT(.dtors.*)))\n";
  ScriptOS << "    KEEP(*(.dtors))\n";
  ScriptOS << "    PROVIDE(__dtors_end__ = .);\n";
  ScriptOS << "  } > FLASH\n\n";

  // Initialized data (needs to be copied to RAM)
  ScriptOS << "  _data_load = LOADADDR(.data);\n";
  ScriptOS << "  .data : AT(_data_load) {\n";
  ScriptOS << "    PROVIDE(__data_start__ = .);\n";
  ScriptOS << "    *(.data)\n";
  ScriptOS << "    *(.data.*)\n";
  ScriptOS << "    . = ALIGN(4);\n";
  ScriptOS << "    PROVIDE(__data_end__ = .);\n";
  ScriptOS << "  } > RAM\n\n";

  // Uninitialized data (BSS)
  ScriptOS << "  .bss : {\n";
  ScriptOS << "    PROVIDE(__bss_start__ = .);\n";
  ScriptOS << "    *(.bss)\n";
  ScriptOS << "    *(.bss.*)\n";
  ScriptOS << "    *(COMMON)\n";
  ScriptOS << "    . = ALIGN(4);\n";
  ScriptOS << "    PROVIDE(__bss_end__ = .);\n";
  ScriptOS << "  } > RAM\n\n";

  // Stack (grows downward from top of RAM)
  ScriptOS << "  _stack_end = ORIGIN(RAM) + LENGTH(RAM);\n";
  ScriptOS << "  _stack_start = _stack_end - 4K;\n";
  ScriptOS << "  PROVIDE(__stack = _stack_start);\n\n";

  // Symbols for initialization
  ScriptOS << "  PROVIDE(__flash_start = ORIGIN(FLASH));\n";
  ScriptOS << "  PROVIDE(__flash_end = ORIGIN(FLASH) + LENGTH(FLASH));\n";
  ScriptOS << "  PROVIDE(__ram_start = ORIGIN(RAM));\n";
  ScriptOS << "  PROVIDE(__ram_end = ORIGIN(RAM) + LENGTH(RAM));\n\n";

  ScriptOS << "  /DISCARD/ : {\n";
  ScriptOS << "    *(.note.GNU-stack)\n";
  ScriptOS << "    *(.gnu.lto*)\n";
  ScriptOS << "  }\n";
  ScriptOS << "}\n";

  // Write the linker script
  std::error_code EC;
  StringRef ScriptPathToWrite = D.isSaveTempsEnabled() 
      ? StringRef(ScriptFile)
      : StringRef(ScriptPath);
  llvm::raw_fd_ostream ScriptFileStream(ScriptPathToWrite, EC, llvm::sys::fs::OF_None);
  if (EC) {
    D.Diag(diag::err_drv_unable_to_make_temp) << ScriptPathToWrite << EC.message();
    return "";
  }
  ScriptFileStream << ScriptContent;
  ScriptFileStream.close();

  return std::string(ScriptFile);
}

void baremetal::Linker::ConstructJob(Compilation &C, const JobAction &JA,
                                     const InputInfo &Output,
                                     const InputInfoList &Inputs,
                                     const ArgList &Args,
                                     const char *LinkingOutput) const {
  ArgStringList CmdArgs;

  auto &TC = static_cast<const toolchains::BareMetal&>(getToolChain());

  AddLinkerInputs(TC, Inputs, Args, CmdArgs, JA);

  CmdArgs.push_back("-Bstatic");

  CmdArgs.push_back(Args.MakeArgString("-L" + TC.getRuntimesDir()));

  // Auto-generate linker script for PowerPC e200 if -T is not specified
  std::string LinkerScript;
  if (!Args.hasArg(options::OPT_T)) {
    const llvm::Triple &Triple = TC.getTriple();
    if (Triple.getArch() == llvm::Triple::ppc) {
      // Check for CPU from -mcpu= argument
      StringRef CPU;
      if (Arg *A = Args.getLastArg(options::OPT_mcpu_EQ)) {
        CPU = A->getValue();
      } else {
        // Try to get CPU from getPPCTargetCPU (may return empty for e200)
        std::string CPUS = tools::ppc::getPPCTargetCPU(Args);
        if (!CPUS.empty())
          CPU = CPUS;
      }
      if (!CPU.empty()) {
        LinkerScript = generateE200LinkerScript(TC.getDriver(), C, JA, Args, CPU);
        if (!LinkerScript.empty()) {
          CmdArgs.push_back("-T");
          CmdArgs.push_back(Args.MakeArgString(LinkerScript));
        }
      }
    }
  }

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

  CmdArgs.push_back("-o");
  CmdArgs.push_back(Output.getFilename());

  C.addCommand(std::make_unique<Command>(JA, *this,
                                          Args.MakeArgString(TC.GetLinkerPath()),
                                          CmdArgs, Inputs));
}
