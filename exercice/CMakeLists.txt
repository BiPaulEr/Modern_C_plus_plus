cmake_minimum_required(VERSION 3.21)

project(Modern_C_exo)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Apply /Zc:__cplusplus only for MSVC
if (MSVC)
    add_compile_options(/Zc:__cplusplus)
endif()

#add_subdirectory(1_Core)

#add_subdirectory(2_New_STD)

#add_subdirectory(3_Move_Semantics)

#add_subdirectory(4_RAII)

#add_subdirectory(5_Generics)

#add_subdirectory(6_Module)

add_subdirectory(7_Threading_Concurrency)

add_executable(version version.cpp)