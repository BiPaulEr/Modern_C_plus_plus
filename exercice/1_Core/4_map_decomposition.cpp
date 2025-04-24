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



        return std::make_tuple(avg, *minIt, *maxIt);
        };

    // Vector names + average
    std::vector<std::pair<std::string, double>> averages;

    // Loop student pour calculer stats
    
        std::cout << name << " => Moyenne: " << avg << ", Min: " << min << ", Max: " << max << "\n";
    

    // Sort averages vector 1er en 1er
    std::sort(...

    // Print le rank de chacun
    std::cout << "\nClassement par moyenne :\n";
    
        std::cout << name << ": " << avg << "\n";
    

    return 0;
}
