#include <iostream>

#include "MyClass_before.h"

int MyClass::counter = 3;

int main() {
    MyClass c1, c2, c3;
    std::cout << MyClass::counter << std::endl;
    std::cout << c1.counter << std::endl;
}