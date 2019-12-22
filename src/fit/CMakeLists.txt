add_library(CrystalBall 
    CrystalBall.cxx
)

add_library(HpsFitResult 
    HpsFitResult.cxx
)

add_library(BumpHunter BumpHunter.cxx)
target_link_libraries(BumpHunter
    ${ROOT_GPAD_LIBRARY}
    ${ROOT_MATH_LIBRARY}
    ${ROOT_TREE_LIBRARY} 
    HpsFitResult
    FitPrinter
    ExpPol3FullFunction
    ExpPol5FullFunction
)

install(TARGETS HpsFitResult BumpHunter DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

add_executable(bump-hunter bump_hunter.cxx)
target_link_libraries(bump-hunter
    ${ROOT_CORE_LIBRARY}
    ${ROOT_RIO_LIBRARY}
    ${ROOT_HIST_LIBRARY} 
    ${ROOT_TREE_LIBRARY} 
    ${ROOT_MATHCORE_LIBRARY}
    BumpHunter
    FlatTupleMaker
    HpsFitResult
)

install(TARGETS bump-hunter DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

