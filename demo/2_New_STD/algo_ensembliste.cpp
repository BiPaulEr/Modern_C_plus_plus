#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

int main() {
    std::set<int> set1 = { 1, 2, 3, 4 };
    std::set<int> set2 = { 3, 4, 5, 6 };
    std::set<int> result;

    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
        std::inserter(result, result.begin()));

    std::cout << "set_union result: ";
    for (const auto& e : result)
        std::cout << e << " ";
    std::cout << std::endl;

    result.clear();

    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
        std::inserter(result, result.begin()));

    std::cout << "set_intersection result: ";
    for (const auto& e : result)
        std::cout << e << " ";
    std::cout << std::endl;

    result.clear();

    std::set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
        std::inserter(result, result.begin()));

    std::cout << "set_difference result: ";
    for (const auto& e : result)
        std::cout << e << " ";
    std::cout << std::endl;

    result.clear();

    std::set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
        std::inserter(result, result.begin()));

    std::cout << "set_symmetric_difference result: ";
    for (const auto& e : result)
        std::cout << e << " ";
    std::cout << std::endl;

    return 0;
}
