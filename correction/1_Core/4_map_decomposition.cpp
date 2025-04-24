#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    
    std::map<std::string, std::vector<int>> studentGrades = {
        {"Alice", {18, 16, 19}}, 
        {"Bob", {14, 17, 13}},
        {"Clara", {20, 18, 19}}
    };

 
    // Calcul average, minimum, and maximum
    auto computeStats = [](const std::vector<int>& grades) {
        auto avg = std::accumulate(grades.begin(), grades.end(), 0.0) / grades.size();

        auto [minIt, maxIt] = std::minmax_element(grades.begin(), grades.end());
        return std::make_tuple(avg, *minIt, *maxIt);
        };

    // Vector names + average
    std::vector<std::pair<std::string, double>> averages;

    // Loop student pour calculer stats
    for (const auto& [name, grades] : studentGrades) {
        auto [avg, min, max] = computeStats(grades);
        averages.push_back({ name, avg });
        std::cout << name << " => Moyenne: " << avg << ", Min: " << min << ", Max: " << max << "\n";
    }

    // Sort averages vector 1er en 1er
    std::sort(averages.begin(), averages.end(), [](auto& a, auto& b) {
        return a.second > b.second;
        });

    // Print le rank de chacun
    std::cout << "\nClassement par moyenne :\n";
    for (const auto& [name, avg] : averages) {
        std::cout << name << ": " << avg << "\n";
    }

    return 0;
}
