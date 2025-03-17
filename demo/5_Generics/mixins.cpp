#include <iostream>

template <typename T>
class Logger {
public:
    void log() const {
        std::cout << "Logging data of type: " << typeid(T).name() << std::endl;
    }
};

class Base {
public:
    void show() const { std::cout << "Base class method\n"; }
};

class Derived : public Base, public Logger<Derived> {};

int main() {
    Derived d;
    d.show();
    d.log();

    return 0;
}
