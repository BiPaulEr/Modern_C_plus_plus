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

struct PersonDefault {
    std::string name;
    int age;

    auto operator<=>(const PersonDefault& other) const = default;
};

int main() {
    auto strong_greater = (15 <=> 10);
    auto strong_less = (1 <=> 10);
    auto strong_equal = (10 <=> 10);

    auto partial_greater = (15 <=> 10.0);
    auto partial_less = (1 <=> 10.0);
    auto partial_equivalent = (10 <=> 10.0);

    // Basic integer comparison using <=> (returns std::strong_ordering)
    std::cout << "10 <=> 20 < 0" << ((10 <=> 20) < 0) << "\n";
    std::cout << "20 <=> 10 > 0" << ((20 <=> 10) > 0) << "\n";
    std::cout << "10 <=> 10 == 0 " << ((10 <=> 10) == 0) << "\n";
    std::cout << "15 <=> 10.0 < 0" << ((15 <=> 10.0) < 0) << "\n";

    // Floating-point comparison (can return std::partial_ordering with NaN)
     double a = 10.5, b = 10.0;
    std::cout << "10.5 <=> 10: " << ((a <=> b) > 0) << " (10.5 is greater than 10)\n";

    // Custom struct comparison
    Person alice{ "Alice", 25 };
    Person bob{ "Bob", 30 };

    if (alice < bob) std::cout << "Alice is younger than Bob\n";
    if (alice > bob) std::cout << "Alice is older than Bob\n";


    PersonDefault alice_d{ "Alice", 25 };
    PersonDefault bob_d{ "Bob", 30 };

    if (alice_d < bob_d) std::cout << "Alice < Bob\n";
    if (alice_d > bob_d) std::cout << "Alice > Bob\n";
    if (alice_d == bob_d) std::cout << "Alice == Bob\n";
    return 0;
}
