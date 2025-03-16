#include <iostream>
#include <vector>

class MyClass {
public:
    void modify()& {
        std::cout << "Modification permise sur un lvalue.\n";
    }

    void consume()&& {
        std::cout << "Usage permise sur une rvalue.\n";
    }
};


int main() {
    MyClass obj;
    obj.modify();   // Ok, lvalue
    MyClass().modify();   // Erreur, rvalue

	obj.consume();  // Erreur, lvalue
	MyClass().consume();  // Ok, rvalue
    return 0;
}
