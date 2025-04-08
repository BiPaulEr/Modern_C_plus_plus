#include <iostream>

template <typename T>
class Wrapper {
private:
    T value;
public:
    Wrapper(T v) : value(v) {}
    void show() { std::cout << "Valeur : " << value << std::endl; }
};

class Container {
private:
    Wrapper<int> wrapped;
public:
    Container(int v) : wrapped(v) {}
    void display() { wrapped.show(); }
};

int main() {
    Container c(10);
    c.display();

    return 0;
}
