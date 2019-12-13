
find_library(ROOT_GPAD_LIB Gpad $ENV{ROOTSYS}/lib)
find_library(ROOT_MATH_LIB MathCore $ENV{ROOTSYS}/lib)

add_library(HpsFitResult HpsFitResult.cxx
)

add_library(BumpHunter BumpHunter.cxx)
target_link_libraries(BumpHunter
    ${ROOT_GPAD_LIB}
    ${ROOT_MATH_LIB}
    HpsFitResult
    FitPrinter
)

add_executable(bump_hunter bump_hunter.cxx)
target_link_libraries(bump_hunter
    ${ROOT_CORE_LIB}
    ${ROOT_RIO_LIB}
    ${ROOT_HIST_LIB} 
    ${ROOT_TREE_LIB} 
    BumpHunter
    FlatTupleMaker
    HpsFitResult
)
