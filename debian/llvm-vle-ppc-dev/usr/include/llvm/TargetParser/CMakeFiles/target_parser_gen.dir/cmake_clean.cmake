file(REMOVE_RECURSE
  "AArch64TargetParserDef.inc"
  "ARMTargetParserDef.inc"
  "CMakeFiles/target_parser_gen"
  "PPCGenTargetFeatures.inc"
  "RISCVTargetParserDef.inc"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/target_parser_gen.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
