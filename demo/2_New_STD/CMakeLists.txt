add_executable(string_view string_view.cpp)

add_executable(span span.cpp)

add_executable(string_new string_new.cpp)

add_executable(string_format string_format.cpp)

add_subdirectory(Types_Gestion)

add_subdirectory(Associative_container)

add_executable(tuples tuples.cpp)

add_executable(algo_ensembliste algo_ensembliste.cpp)

add_executable(chrono chrono.cpp)

add_executable(random random.cpp)

add_executable(std_function std_function.cpp)

add_executable(std_mem_fn std_mem_fn.cpp)

add_executable(bind_placeholders bind_placeholders.cpp)

add_subdirectory(Ranges)