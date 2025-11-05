file(REMOVE_RECURSE
  "PPCGenAsmMatcher.inc"
  "PPCGenAsmWriter.inc"
  "PPCGenCallingConv.inc"
  "PPCGenDAGISel.inc"
  "PPCGenDisassemblerTables.inc"
  "PPCGenExegesis.inc"
  "PPCGenFastISel.inc"
  "PPCGenGlobalISel.inc"
  "PPCGenInstrInfo.inc"
  "PPCGenMCCodeEmitter.inc"
  "PPCGenRegisterBank.inc"
  "PPCGenRegisterInfo.inc"
  "PPCGenSubtargetInfo.inc"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/PowerPC.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
