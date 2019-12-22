#
# CMakeLists.txt
# 
#

# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# Set the project name
project(bump-hunter LANGUAGES CXX)

# Set the CXX standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Set the path to additional CMake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules")

# Require the ROOT libraries.
find_package(ROOT REQUIRED Core RIO Hist MathCore Physics Tree Gpad)

# Add the ROOT headers to the build.
include_directories(${ROOT_INCLUDE_DIRS})

# Add math headers to the build
include_directories(include/math)

# Add fit headers to the build
include_directories(include/fit)

# Add utils headers to the build
include_directories(include/utils)

# Add the math source to the build
add_subdirectory(src/math)

# Add the utils source to the build
add_subdirectory(src/utils)

# Add the fit source to the build
add_subdirectory(src/fit)

message(STATUS "Files will be installed to ${CMAKE_INSTALL_PREFIX}")
