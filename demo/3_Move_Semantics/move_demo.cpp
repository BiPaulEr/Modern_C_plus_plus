#include <iostream>
#include <vector>

void move_example(std::vector<int>& vec) {
    std::vector<int> new_vec = std::move(vec);
    std::cout << "new_vec size: " << new_vec.size() << "\n";
}

int main() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    move_example(vec);
    std::cout << "vec size after function call: " << vec.size() << "\n";
    return 0;
}
