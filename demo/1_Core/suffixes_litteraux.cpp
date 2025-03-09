#include <iostream>

using namespace std::string_literals; 

void operator"" _print(const char* texte, size_t) {
	std::cout << "[DEBUG] " << texte << std::endl;
}

int main() {
	std::string texte = "Bonjour"s;
	std::cout << texte << std::endl;

	"Message important"_print;
}