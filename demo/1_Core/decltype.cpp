#include <iostream>
int main() {
	int a = 10;
	int& ref_x = a;
	decltype(auto) ref_y = ref_x;
	ref_y = 999;
	std::cout << "Après modification via ref_y : " << a << std::endl;


	auto copy_y_auto = ref_x;
	copy_y_auto = -999;
	std::cout << "Après modification via copy_y_auto : " << a << std::endl;

	const int b = 50;
	decltype(auto) ref_b = b;
	//ref_b = 100; // Erreur, ref_b est const
	std::cout << "Valeur de ref_b (const) : " << ref_b << std::endl;
}