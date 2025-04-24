#include <iostream>

using namespace std::string_literals; 

void operator"" _print(const char* texte, size_t) {
	std::cout << "[DEBUG] " << texte << std::endl;
}

int main() {
	long smallValue = 2147483648L;
	long smallValue2 = 2147483648;
	std::cout << "bigValue (long long): " << smallValue << std::endl;  // Correctly stores the value
	std::cout << "bigValue (long long): " << smallValue2 << std::endl;  // Correctly stores the value
	std::string texte = "Bonjour"s;
	std::cout << texte << std::endl;

	"Message important"_print;
}