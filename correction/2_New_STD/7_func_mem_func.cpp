#include <iostream>
#include <functional>  // For std::function, std::mem_fn
#include <vector>      // For std::vector
#include <algorithm>   // For std::for_each

class MyClass {
public:
    MyClass(const std::string& name) : name(name) {}

    void bonjour() const {
        std::cout << "Hello, " << name << "!" << std::endl;
    }

private:
    std::string name;
};

void printMessage(const std::string& message) {
    std::cout << message << std::endl;
}

int main() {
    //associer func1 à printMessage 
    std::function<void(const std::string&)> func1 = printMessage;
    func1("Hello from a regular function!");

    //associer lambda1 aux lambdas []() { std::cout << "Lambda without capture!" << std::endl; 
    std::function<void()> lambda1 = []() { std::cout << "Lambda without capture!" << std::endl; };
    lambda1(); 

    // associer lambda2 avec [mul](int a, int b) { std::cout  << mul * (a + b) << std::endl; }
    int mul = 10;
    std::function<void(int, int)> lambda2 = [mul](int a, int b) { std::cout  << mul * (a + b) << std::endl; };
    lambda2(3, 5);

	//associer bonjour_mem au membre de la classe MyClass 
    MyClass obj("Alice");
    std::function<void(MyClass)> bonjour_mem = std::mem_fn(&MyClass::bonjour);
    bonjour_mem(obj);


	//utiliser foreach pour appeler bonjour sur chaque personne
    std::vector<MyClass> people = {
        MyClass("Alice"),
        MyClass("Bob"),
        MyClass("Charlie")
    };

    std::for_each(people.begin(), people.end(), std::mem_fn(&MyClass::bonjour));
    std::cout << std::endl;

    return 0;
}
