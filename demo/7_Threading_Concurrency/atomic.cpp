#include <iostream>
#include <thread>
#include <mutex>

std::atomic<int> compteur = 0;

void incrementer() {
    for (int i = 0; i < 1000; ++i) {
        {
            ++compteur;
        }
    }
}

int main() {
    std::thread t1(incrementer);
    std::thread t2(incrementer);

    t1.join();
    t2.join();
    std::cout << "Compteur final : " << compteur << std::endl;
}
