#include <iostream>
#include <thread>
#include <barrier>
#include <chrono>


void process(int id) {
    std::cout << "[T" << id << "] Etape 1...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * id));


    std::cout << "[T" << id << "] Etape 2...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * (3 - id)));


    std::cout << "[T" << id << "] Termine.\n";
}

int main() {
    std::thread t1(process, 1);
    std::thread t2(process, 2);
    std::thread t3(process, 3);

    t1.join();
    t2.join();
    t3.join();
}
