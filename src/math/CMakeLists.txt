# Find the required ROOT libraries
find_library(ROOT_MATH_LIB MathCore $ENV{ROOTSYS}/lib)

# Import the fit function classes. These all require the ROOT math
# library, but nothing else.
add_library(ExpPol3BkgFunction ExpPol3BkgFunction.cxx)
target_link_libraries(ExpPol3BkgFunction
    ${ROOT_MATH_LIB}
)

add_library(ExpPol5BkgFunction ExpPol5BkgFunction.cxx)
target_link_libraries(ExpPol5BkgFunction
    ${ROOT_MATH_LIB}
)

add_library(ExpPol3FullFunction ExpPol3FullFunction.cxx)
target_link_libraries(ExpPol3FullFunction
    ${ROOT_MATH_LIB}
)

add_library(ExpPol5FullFunction ExpPol5FullFunction.cxx)
target_link_libraries(ExpPol5FullFunction
    ${ROOT_MATH_LIB}
)
