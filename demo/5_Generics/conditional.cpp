#include <type_traits>
#include <iostream>

template<bool condition>
using MonType = typename std::conditional<condition, int, double>::type;

int main() {
    MonType<true> a = 42;      // int
    MonType<false> b = 3.14;   // double
    std::cout << a << ", " << b << std::endl;
}
