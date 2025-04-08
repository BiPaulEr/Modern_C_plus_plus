#include <iostream>
#include <string>
#include <type_traits>

template <typename T>
struct is_string : std::false_type {};

template <>
struct is_string<std::string> : std::true_type {};

int main() {
    //std::cout << std::boolalpha;
    std::cout << "int est un string ? " << is_string<int>::value << std::endl;
    std::cout << "std::string est un string ? " << is_string<std::string>::value << std::endl;
    return 0;
}

