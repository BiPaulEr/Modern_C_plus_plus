#include <iostream>
#include <future>
#include <thread>
#include <chrono>

int calcul(int a, int b) {
    std::cout << "calcul en cours...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return a + b;
}

int main() {
    std::future<int> f = std::async(std::launch::deferred, calcul, 10, 20);
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    std::cout << "En attendant le calcul...\n";

    int resultat = f.get();

    std::cout << "Le résultat est : " << resultat << std::endl;

    return 0;
}
