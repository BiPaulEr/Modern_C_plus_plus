#include <iostream>
#include <utility>

void func(int& x) {
    std::cout << "Lvalue traitee : " << x << std::endl;
}

void func(int&& x) {
    std::cout << "Rvalue traitee : " << x << std::endl;
}

template <typename T>
void wrapper(T&& arg) {
	std::cout << "Wrapper forward : " << std::endl;
    func(std::forward<T>(arg));
}

template <typename T>
void wrapper_no_forward(T&& arg) {
    std::cout << "Wrapper no forward : " << std::endl;
    func(arg);
}

template <typename T>
void wrapper_no_move_rvalue(T& arg) {
    std::cout << "Wrapper no forward : " << std::endl;
    func(arg);
}

int main() {
    int a = 999;
    wrapper(a);
    wrapper(-333);

    wrapper_no_forward(a);
    wrapper_no_forward(-333);

    //wrapper_no_move_rvalue(-333); //error
	return 0;
}
