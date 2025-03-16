#include <iostream>
#include <vector>

class MyClass {
public:
    std::vector<int>* data;
public:
    MyClass() : data(new std::vector<int>()) {}

    MyClass(MyClass&& other) noexcept {
        data = other.data;
        other.data = nullptr;
        std::cout << "Move constructor called.\n";
    }

    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        std::cout << "Move assignment operator called.\n";
        return *this;
    }

    ~MyClass() {
        delete data;
    }

    void print() {
        if (data != nullptr) {
            std::cout << "Data: ";
            for (int x : *data) {
                std::cout << x << " ";
            }
            std::cout << "\n";
        }
        else {
            std::cout << "No data.\n";
        }
    }
};

int main() {
    MyClass obj1; 
    obj1.data->emplace_back(2);
    obj1.data->emplace_back(4);
    obj1.data->emplace_back(6);
    obj1.print();
    MyClass obj2 = std::move(obj1);
    obj2.print();
    obj1.print();

    MyClass obj3;
    obj3.data->emplace_back(6);
    obj3.data->emplace_back(7);
    obj3.data->emplace_back(9);
    MyClass obj4;
	obj4 = std::move(obj3); //not operator 
    obj4.print();
    obj3.print();

    return 0;
}
