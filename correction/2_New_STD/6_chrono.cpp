#include <iostream>
#include <chrono>

class Chrono {
public:
    Chrono(const std::string& label) : label(label) {
        begin = std::chrono::high_resolution_clock::now();
    }

    ~Chrono() {
        std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> ns_int = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        std::cout << label << " a pris " << ns_int.count() << " ns" << std::endl;
		std::chrono::duration<double, std::micro> us_int = std::chrono::duration_cast<std::chrono::microseconds>(ns_int);
        std::cout << label << " a pris " << us_int.count() << " us" << std::endl;

    }

private:
    std::chrono::high_resolution_clock::time_point begin;
    std::string label;
};

long int fib(int n) {
    return (n <= 1) ? n : fib(n - 1) + fib(n - 2);
}

constexpr long int fibOptimised(int n) {
    return (n <= 1) ? n : fibOptimised(n - 1) + fibOptimised(n - 2);
}

int main() {
    
    for (int N = 15; N <= 25; N += 5) {
        {
            Chrono chrono("Fibonacci recursif (fib) pour N = " + std::to_string(N));
            long int result = fib(N);
        } 
    }
    {
        Chrono chrono("Fibonacci optimise (fibOptimised) pour N = 15");
        constexpr long int result2 = fibOptimised(15);
    }
    {
        Chrono chrono("Fibonacci optimise (fibOptimised) pour N = 20");
        constexpr long int result2 = fibOptimised(20);
    }
    {
        Chrono chrono("Fibonacci optimise (fibOptimised) pour N = 25");
        constexpr long int result2 = fibOptimised(25);
    }

    return 0;
}
