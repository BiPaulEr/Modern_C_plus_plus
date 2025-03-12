#include <iostream>
#include <compare>  // Needed for ordering types (C++20)

struct Person {
    std::string name;
    int age;

    // Three-way comparison operator to compare by age
    auto operator<=>(const Person& other) const {
        return age <=> other.age;
    }
};

int main() {
    // Basic integer comparison using <=> (returns std::strong_ordering)
    std::cout << "10 <=> 20: " << ((10 <=> 20) < 0) << " (10 is less than 20)\n";
    std::cout << "20 <=> 10: " << ((20 <=> 10) > 0) << " (20 is greater than 10)\n";
    std::cout << "10 <=> 10: " << ((10 <=> 10) == 0) << " (10 is equal to 10)\n\n";

    // Floating-point comparison (can return std::partial_ordering with NaN)
    double a = 10.5, b = 10.0;
    std::cout << "10.5 <=> 10: " << ((a <=> b) > 0) << " (10.5 is greater than 10)\n";

    // Demonstrating NaN behavior (partial ordering)
    double nanValue = std::numeric_limits<double>::quiet_NaN();
    if ((nanValue <=> 10) != std::partial_ordering::equivalent)
        std::cout << "NaN comparison: NaN is not comparable (partial ordering)\n\n";

    // Custom struct comparison
    Person alice{ "Alice", 25 };
    Person bob{ "Bob", 30 };

    if (alice < bob) std::cout << "Alice is younger than Bob\n";
    if (alice > bob) std::cout << "Alice is older than Bob\n";

    return 0;
}
