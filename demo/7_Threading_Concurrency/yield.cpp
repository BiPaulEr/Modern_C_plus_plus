#include <iostream>
#include <thread>

void boucle(const std::string& nom) {
    std::cout << nom << " " << std::this_thread::get_id() << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "[" << nom << "] Etape " << i << std::endl;
        std::this_thread::yield();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

int main() {
    std::thread t1(boucle, "Thread A");
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::thread t2(boucle, "Thread B");

    t1.join();
    t2.join();

    std::cout << "Fin du programme avec yield.\n";
}
