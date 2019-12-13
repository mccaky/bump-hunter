
add_library(HpsFitResult HpsFitResult.cxx
)

add_library(BumpHunter BumpHunter.cxx)
target_link_libraries(BumpHunter
    ${ROOT_GPAD_LIBRARY}
    ${ROOT_MATH_LIBRARY}
    HpsFitResult
    FitPrinter
)

add_executable(bump_hunter bump_hunter.cxx)
target_link_libraries(bump_hunter
    ${ROOT_CORE_LIBRARY}
    ${ROOT_RIO_LIBRARY}
    ${ROOT_HIST_LIBRARY} 
    ${ROOT_TREE_LIBRARY} 
    ${ROOT_MATHCORE_LIBRARY}
    BumpHunter
    FlatTupleMaker
    HpsFitResult
)
