
add_library(RootFileReader RootFileReader.cxx)
target_link_libraries(RootFileReader 
    ${ROOT_CORE_LIBRARY}
    ${ROOT_GPAD_LIBRARY}
    ${ROOT_TREE_LIBRARY}
    ${ROOT_RIO_LIBRARY}
    ${ROOT_PHYSICS_LIBRARY}
    ${ROOT_HIST_LIBRARY}
)

add_library(FlatTupleMaker FlatTupleMaker.cxx)
target_link_libraries(FlatTupleMaker
    ${ROOT_CORE_LIBRARY}
    ${ROOT_RIO_LIBRARY}
)

add_library(FitPrinter FitPrinter.cxx)
target_link_libraries(FitPrinter
    ${ROOT_GPAD_LIBRARY}
)
