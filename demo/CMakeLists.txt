project(Modern_C)

cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Apply /Zc:__cplusplus only for MSVC
if (MSVC)
    add_compile_options(/Zc:__cplusplus)
endif()

#add_subdirectory(1_Core)

#add_subdirectory(2_New_STD)

add_subdirectory(3_Move_Semantics)

add_executable(version version.cpp)
