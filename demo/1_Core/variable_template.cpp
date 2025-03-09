#include <iostream>

template <typename T>
constexpr T PI = 3.14;

template <typename T>
T circleArea(T radius) {
	return PI<T> * radius * radius;
}

int main() {
	std::cout << "PI en double " << PI<double> << std::endl;
	std::cout << "PI en float " << PI<float> << std::endl;

	std::cout << "Area 10 (double) : " << circleArea(10.0) << std::endl;
	std::cout << "Area 10 (float) : " << circleArea(10.0f) << std::endl;
}