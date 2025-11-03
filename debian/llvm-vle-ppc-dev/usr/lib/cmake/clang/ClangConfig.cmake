# This file allows users to call find_package(Clang) and pick up our targets.



set(LLVM_VERSION 22.0.0)
find_package(LLVM ${LLVM_VERSION} EXACT REQUIRED CONFIG
             HINTS "/projects/vle/llvm-project/build/./lib/cmake/llvm")

set(CLANG_EXPORTED_TARGETS "clang-tblgen;clang-resource-headers;clangBasic;clangAPINotes;clangLex;clangParse;clangAST;clangDynamicASTMatchers;clangASTMatchers;clangCrossTU;clangSema;clangCodeGen;clangAnalysis;clangAnalysisFlowSensitive;clangAnalysisFlowSensitiveModels;clangAnalysisLifetimeSafety;clangEdit;clangExtractAPI;clangRewrite;clangDriver;clangSerialization;clangRewriteFrontend;clangFrontend;clangFrontendTool;clangToolingCore;clangToolingInclusions;clangToolingInclusionsStdlib;clangToolingRefactoring;clangToolingASTDiff;clangToolingSyntax;clangDependencyScanning;clangTransformer;clangTooling;clangDirectoryWatcher;clangIndex;clangIndexSerialization;clangInstallAPI;clangStaticAnalyzerCore;clangStaticAnalyzerCheckers;clangStaticAnalyzerFrontend;clangFormat;clangInterpreter;clangSupport;diagtool;clang;clang-format;clangHandleCXX;clangHandleLLVM;clang-linker-wrapper;clang-nvlink-wrapper;clang-offload-bundler;clang-scan-deps;clang-sycl-linker;clang-installapi;clang-repl;clang-refactor;clang-cpp;clang-check;clang-extdef-mapping;libclang;offload-arch")
set(CLANG_CMAKE_DIR "/projects/vle/llvm-project/build/./lib/cmake/clang")
set(CLANG_INCLUDE_DIRS "/projects/vle/llvm-project/clang/include;/projects/vle/llvm-project/build/tools/clang/include")
set(CLANG_LINK_CLANG_DYLIB "OFF")
set(CLANG_DEFAULT_LINKER "")

# Provide all our library targets to users.
include("/projects/vle/llvm-project/build/./lib/cmake/clang/ClangTargets.cmake")

# By creating clang-tablegen-targets here, subprojects that depend on Clang's
# tablegen-generated headers can always depend on this target whether building
# in-tree with Clang or not.
if(NOT TARGET clang-tablegen-targets)
  add_custom_target(clang-tablegen-targets)
endif()
