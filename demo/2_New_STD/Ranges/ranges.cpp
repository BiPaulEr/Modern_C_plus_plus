#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <numeric>
#include <functional>

int main() {
    std::vector<int> vec = { 5, 3, 8, 1, 6 };

    std::ranges::sort(vec);
    std::cout << "Sorted vector: ";
    for (int x : vec) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::ranges::transform(vec, vec.begin(), [](int x) { return x * 2; });
    std::cout << "Transformed vector (doubled): ";
    for (int x : vec) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    auto found = std::ranges::find(vec, 10);
    if (found != vec.end()) {
        std::cout << "Found 10 in the vector.\n";
    }
    else {
        std::cout << "10 not found in the vector.\n";
    }

    std::ranges::reverse(vec);
    std::cout << "Reversed vector: ";
    for (int x : vec) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    bool all_positive = std::ranges::all_of(vec, [](int x) { return x > 0; });
    std::cout << "Are all elements positive? " << (all_positive ? "Yes" : "No") << "\n";

    bool any_negative = std::ranges::any_of(vec, [](int x) { return x < 0; });
    std::cout << "Are there any negative elements? " << (any_negative ? "Yes" : "No") << "\n";
    return 0;
}