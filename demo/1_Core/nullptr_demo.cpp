#include <iostream>
#include <type_traits>

void foo(char*);
void foo(int);

int main() {
    if (std::is_same<decltype(NULL), decltype(0)>::value)
        std::cout << "NULL == 0" << std::endl;
    if (std::is_same<decltype(NULL), decltype((void*)0)>::value)
        std::cout << "NULL == (void *)0" << std::endl;
    if (std::is_same<decltype(NULL), std::nullptr_t>::value)
        std::cout << "NULL == nullptr" << std::endl;

    foo(0);
    foo(NULL);
    foo(nullptr);

    return 0;
}

void foo(char*) {
    std::cout << "foo(char*) est appele" << std::endl;
}

void foo(int i) {
    std::cout << "foo(int) est appele" << std::endl;
}
