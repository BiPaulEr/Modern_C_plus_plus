#include <iostream>
#include <vector>

int main()
{
	std::vector<int> valeurs = { 10, 20, 30, 40 };
	for (int valeur : valeurs) {
		std::cout << valeur << " ";
	}
	std::cout << std::endl;

	for (int& valeur : valeurs) {
		valeur *= 2; // Modification en place
		std::cout << valeur << " ";
	}
	std::cout << std::endl;

	for (const int& valeur : valeurs) {
		std::cout << valeur << " ";
	}
	std::cout << std::endl;
}
