#include <iostream>
#include <map>

int main()
{
	std::map<std::string, int> ages = { {"Alice", 25}, {"Bob", 30} };
	for (const auto& entry : ages) {
		std::cout << entry.first << " a " << entry.second << " ans." << std::endl;
	}
	for (const auto& [nom, age] : ages) { // C++17 : Décomposition structurée
		std::cout << nom << " a " << age << " ans." << std::endl;
	}

}
