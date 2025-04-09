#include <iostream>
#include <thread>

std::once_flag flag;

void initialiser() {
    std::cout << "Initialisation effectuee une seule fois." << std::endl;
}

void travail() {
    std::call_once(flag, initialiser);
    std::cout << "Travail du thread." << std::endl;
}

int main() {
    std::thread t1(travail);
    std::thread t2(travail);
    std::thread t3(travail);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
