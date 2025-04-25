#include <iostream>
#include <chrono>

class Chrono {
public:
    Chrono(const std::string& label) : {

    }

    ~Chrono() {


    }

private:

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
        constexpr long int result = fibOptimised(15);
    }
    {
        Chrono chrono("Fibonacci optimise (fibOptimised) pour N = 20");
        constexpr long int result = fibOptimised(20);
    }
    {
        Chrono chrono("Fibonacci optimise (fibOptimised) pour N = 25");
        constexpr long int result = fibOptimised(25);
    }

    return 0;
}
