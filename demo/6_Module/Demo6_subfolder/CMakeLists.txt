add_library(math)
target_sources(math
    PRIVATE
        FILE_SET cxx_modules TYPE CXX_MODULES
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
        FILES
            math.ixx
            operations/basic_operations.ixx
            operations/advanced_operations.ixx
)

add_executable(demo6_main main.cpp)

target_link_libraries(demo6_main PRIVATE math)