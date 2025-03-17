#include <iostream>

template <typename T>
class Base {
public:
    void show() { std::cout << "Base avec type: " << typeid(T).name() << std::endl; }
};

class Derived : public Base<int> {
public:
    void customMethod() { std::cout << "Methode specifique a Derived\n"; }
};

int main() {
    Derived d;
    d.show();
    d.customMethod();

    return 0;
}
