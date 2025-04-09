#include <iostream>
#include <thread>
#include <mutex>

int compteur = 0;
std::mutex compteur_mutex;

void incrementer() {
    for (int i = 0; i < 1000; ++i) {
        {
            compteur_mutex.lock();
            ++compteur;
			compteur_mutex.unlock();
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
