#include <iostream>
#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int main() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };

    auto combined_view = vec | std::views::transform([](int x) { return x * 2; }) | std::views::filter([](int x) { return x > 2; });

    std::cout << " Combined" << std::endl;
    for (int val : combined_view) {
        std::cout << val << " ";
    }
    std::cout << std::endl;


    std::cout << " Acces" << std::endl;
    auto view = vec | std::views::transform([](int x) { 
		std::cout << "Transformation : " << x <<". ";
        return x * 2; 
        });

    for (int val : view) {
        std::cout << "Acces value : " << val << ". " << std::endl;
    }

    std::cout << std::endl << "On affiche seulement le premier element :\n";
    std::cout << *view.begin() << std::endl;

    std::cout << std::endl << "On affiche avec for each :\n";
	auto view_for_each = vec | std::views::filter([](int x) { return x > 2; });
    std::ranges::for_each(view_for_each, [](int x) { std::cout << x << " "; });

    return 0;
}
