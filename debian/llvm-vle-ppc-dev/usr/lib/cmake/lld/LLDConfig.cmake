# This file allows users to call find_package(LLD) and pick up our targets.



set(LLVM_VERSION 22.0.0)
find_package(LLVM ${LLVM_VERSION} EXACT REQUIRED CONFIG
             HINTS "/projects/vle/llvm-project/build/./lib/cmake/llvm")

set(LLD_EXPORTED_TARGETS "lldCommon;lld;lldCOFF;lldELF;lldMachO;lldMinGW;lldWasm")
set(LLD_CMAKE_DIR "/projects/vle/llvm-project/build/lib/cmake/lld")
set(LLD_INCLUDE_DIRS "/projects/vle/llvm-project/lld/include;/projects/vle/llvm-project/build/tools/lld/include")

# Provide all our library targets to users.
include("/projects/vle/llvm-project/build/lib/cmake/lld/LLDTargets.cmake")
