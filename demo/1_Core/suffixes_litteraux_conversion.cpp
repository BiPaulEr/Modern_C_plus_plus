#include <iostream>

double operator"" _K(long double celsius) {
    return celsius + 273.15; // Conversion °C → K
}

int main() {
    double temp = 25.0_K;
    std::cout << "Temperature en Kelvin : " << temp << " K" << std::endl; // Affiche 298.15 K
    return 0;
}
