#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());  // Générateur Mersenne Twister

    std::uniform_int_distribution<int> distInt(1, 10);
    std::cout << "Nombre entier uniforme : " << distInt(gen) << std::endl;

    std::uniform_real_distribution<double> distReal(0.0, 1.0);
    std::cout << "Nombre flottant uniforme : " << distReal(gen) << std::endl;

    std::normal_distribution<double> distNormale(5.0, 2.0);
    std::cout << "Nombre selon une distribution normale : " << distNormale(gen) << std::endl;

    std::bernoulli_distribution distBernoulli(0.5);
    std::cout << "Pile ou face : " << (distBernoulli(gen) ? "Pile" : "Face") << std::endl;

    return 0;
}
