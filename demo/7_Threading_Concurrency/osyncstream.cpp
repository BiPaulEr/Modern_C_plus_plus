#include <iostream>
#include <thread>
#include <barrier>
#include <vector>
#include <random>
#include <syncstream>

std::barrier sync_point(3);  // 3 threads

void etapes(int id) {
    for (int etape = 1; etape <= 3; ++etape) {
        std::osyncstream(std::cout) << "[Thread " << id << "] Etape " << etape << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds((std::rand() % 5 + 1) * 100 * id));

       sync_point.arrive_and_wait();  // attendre que tous arrivent
    }
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 1; i <= 3; ++i)
        threads.emplace_back(etapes, i);

    for (auto& t : threads)
        t.join();
}
