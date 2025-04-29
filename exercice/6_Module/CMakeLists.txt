add_library(portefeuille)

target_sources(portefeuille
    PRIVATE
        FILE_SET cxx_modules TYPE CXX_MODULES
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
        FILES
             portefeuille.ixx
    	     analyse.ixx
             transactions.ixx
)

target_include_directories(portefeuille PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(logiciel_financier main.cpp)

target_link_libraries(logiciel_financier PRIVATE portefeuille)