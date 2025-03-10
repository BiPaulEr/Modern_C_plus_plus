#include <tuple>
#include <string>

struct Point {
    int x, y;
};

std::tuple<int, double, char> getValues() {
    return { 42, 3.14, 'A' };
}

int main() {
    Point p{ 10, 20 };

    // Extraction manuelle
    int x = p.x;
    int y = p.y;

    auto [x2, y2] = p; // Décomposition automatique
    
	auto [a, b, c] = getValues();

    std::pair<int, std::string> p = { 1, "test" };
    auto [p1, p2] = p;

    return 0;
};


