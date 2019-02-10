cmake_minimum_required(VERSION 3.1)

# Project name
project(NiaCpp)

# Compiler flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_REQUIRED_FLAGS -std=c++17)

# Project librarys from system
find_package(xtl REQUIRED)
find_package(xtensor REQUIRED)
# Project librarys in subdir
add_subdirectory(librarys)

# Project file
file(GLOB NiaCpp_SRC
    "src/*.h"
    "src/*.cpp"
    "src/algorithms/*.h"
    "src/algorithms/*.cpp"
    "src/algorithms/basic/*.h"
    "src/algorithms/basic/*.cpp"
    "src/algorithms/modified/*.h"
    "src/algorithms/modified/*.cpp"
    "src/util/*.h"
    "src/util/*.cpp"
)

add_executable(NiaCpp ${NiaCpp_SRC})
target_link_libraries(NiaCpp xtensor cxxopts)
