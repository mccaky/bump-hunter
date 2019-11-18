# Find the required ROOT libraries
find_library(ROOT_MATH_LIB MathCore $ENV{ROOTSYS}/lib)

# The math library requires ROOT's math library.
add_library(FunctionMath FunctionMath.cxx)
target_link_libraries(FunctionMath
    ${ROOT_MATH_LIB}
)

# Import the fit function classes. These all require the above function
# math library, but nothing else.
add_library(ExpPol3BkgFunction ExpPol3BkgFunction.cxx)
target_link_libraries(ExpPol3BkgFunction
    FunctionMath
)

add_library(ExpPol5BkgFunction ExpPol5BkgFunction.cxx)
target_link_libraries(ExpPol5BkgFunction
    FunctionMath
)

add_library(ExpPol3FullFunction ExpPol3FullFunction.cxx)
target_link_libraries(ExpPol3FullFunction
    FunctionMath
)

add_library(ExpPol5FullFunction ExpPol5FullFunction.cxx)
target_link_libraries(ExpPol5FullFunction
    FunctionMath
)
