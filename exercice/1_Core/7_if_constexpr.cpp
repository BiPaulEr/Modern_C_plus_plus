#include <iostream>
#include <type_traits>
#include <string>
#include <vector>
#include <cmath> // modf


int main() {
    print_info(42);
    print_info(3.14);
    print_info(std::string("Hello"));
    print_info(true);
}
