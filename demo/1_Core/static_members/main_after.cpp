#include <iostream>

#include "MyClass_after.h"

int main() {
    MyClass c1, c2, c3;
    std::cout << MyClass::counter << std::endl;
    std::cout << c1.counter << std::endl;
}