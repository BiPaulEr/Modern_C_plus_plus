#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <chrono>

class Chrono {
public:
	Chrono() {
		begin = std::chrono::high_resolution_clock::now();
	}

	~Chrono() {
		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::nano> ms_int = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		std::cout << ms_int.count() << " ns\n" << std::endl;
	}

private:
	std::chrono::high_resolution_clock::time_point begin;
};

long int fib(int n) {
	return (n <= 1) ? n : fib(n - 1) + fib(n - 2);
}

constexpr long int fibOptimised(int n) {
	return (n <= 1) ? n : fibOptimised(n - 1) + fibOptimised(n - 2);
}

int main()
{
	constexpr int N = 25;
	Chrono* chrono = new Chrono();
	constexpr long int result = fibOptimised(N);
	delete chrono;
	chrono = nullptr;

	Chrono* chrono2 = new Chrono();
	long int result2 = fib(N);
	delete chrono2;
	chrono2 = nullptr;
	return 0;
}
