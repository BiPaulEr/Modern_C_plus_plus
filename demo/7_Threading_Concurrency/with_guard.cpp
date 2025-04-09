#include <iostream>
#include <thread>
#include <mutex>

int compteur = 0;
std::mutex compteur_mutex;

void incrementer() {
    for (int i = 0; i < 1000; ++i) {
        {
			std::lock_guard<std::mutex> lock(compteur_mutex);
            ++compteur;
        } //unlock
    }
}

int main() {
    std::thread t1(incrementer);
    std::thread t2(incrementer);

    t1.join();
    t2.join();
    std::cout << "Compteur final : " << compteur << std::endl;
}
