#include <iostream>
#include <thread>
#include <latch>
#include <vector>

std::latch debut_sync(3);  // On attend 3 threads

void travail(int id) {
    std::cout << "[Thread " << id << "] prepare...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * id));

    debut_sync.count_down();  // Ce thread est prêt
    debut_sync.wait();        // On attend les autres

    std::cout << "[Thread " << id << "] Tous prets, je continue !\n";
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 1; i <= 3; ++i)
        threads.emplace_back(travail, i);

    for (auto& t : threads)
        t.join();
}
