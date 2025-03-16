#include <iostream>

class MyClass {
public:
    MyClass() { std::cout << "Constructor\n"; }
    MyClass(const MyClass&) { std::cout << "Copy Constructor\n"; }
    //MyClass(MyClass&&) noexcept { std::cout << "Move Constructor\n"; }
    ~MyClass() { std::cout << "Destructor\n"; }
};

MyClass createObject() {
    MyClass obj;
    return obj;  // Avec Guaranteed RVO, pas de copie
}

int main() {
    MyClass obj = createObject();  // RVO garantit aucune copie
}
