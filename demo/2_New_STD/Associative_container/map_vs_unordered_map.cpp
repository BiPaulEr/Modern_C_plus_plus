#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <chrono>

// Chrono class for benchmarking
class Chrono {
public:
    Chrono() {
        begin = std::chrono::high_resolution_clock::now();
    }

    ~Chrono() {
        std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        std::cout << ns.count() / 1000000 << " ms\n" << std::endl;
    }

private:
    std::chrono::high_resolution_clock::time_point begin;
};

template <typename MapType>
void benchmark_access(MapType& container, const std::vector<std::string>& keys) {
    {
        Chrono chrono;
        for (const auto& key : keys) {
            volatile auto value = container[key];
        }
    }
}

template <typename MapType>
void fill_container(MapType& container, const std::vector<std::string>& keys) {       
    for (const auto& key : keys) {
        container[key] = 1;
    }
}


int main() {
    std::vector<std::string> keys(1000000);
    for (int i = 0; i < 1000000; ++i) {
        keys[i] = "key" + std::to_string(i);
    }

    std::cout << "Construction std::map:" << std::endl;
    std::map<std::string, int> ordered_map;
	fill_container(ordered_map, keys);
    std::cout << "Benchmark std::map:" << std::endl;
    benchmark_access(ordered_map, keys);
    

    std::cout << "Construction std::unordered_map:" << std::endl;
    std::unordered_map<std::string, int> unordered_map;
    fill_container(unordered_map, keys);
    std::cout << "Benchmark std::unordered_map:" << std::endl;
    benchmark_access(unordered_map, keys);

    return 0;
}
