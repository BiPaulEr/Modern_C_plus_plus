#include <iostream>
#include <cstdlib>

// C++11: Indicate that this function will never return
[[noreturn]] void criticalError(const std::string& message) {
    std::cerr << "Critical Error: " << message << std::endl;
    std::exit(1);
}

// C++11: Mark an old function as deprecated
[[deprecated("Use processTaskV2() instead.")]]
void processTaskV1(int taskId) {
    std::cout << "Processing task (old version): " << taskId << std::endl;
}

// C++17: Use [[nodiscard]] to enforce handling return value
[[nodiscard]] bool isTaskValid(int taskId) {
    return taskId > 0;
}

// C++20: Optimize branch prediction
void executeTask(int taskId) {
    if (taskId < 0) [[unlikely]] {
        criticalError("Invalid task ID!");
    }

    if (taskId % 2 == 0) [[likely]] {
        std::cout << "Executing even task: " << taskId << std::endl;
    }
    else {
        std::cout << "Executing odd task: " << taskId << std::endl;
    }
}

// C++17: Demonstrate [[fallthrough]] in a switch statement
void categorizeTask(int difficulty) {
    switch (difficulty) {
    case 1:
        std::cout << "Difficulty: Easy\n";
        [[fallthrough]]; // Intentional fallthrough
    case 2:
        std::cout << "Difficulty: Medium\n";
        [[fallthrough]];
    case 3:
        std::cout << "Difficulty: Hard\n";
        break;
    default:
        std::cout << "Unknown difficulty\n";
    }
}

int main() {
    int taskId = 5;

    // C++17: Enforce handling return value of isTaskValid
    if (!isTaskValid(taskId)) {
        criticalError("Invalid task!");
    }

    // Calling deprecated function (should generate a warning)
    processTaskV1(taskId);

    // Using the optimized execution function
    executeTask(taskId);

    // Categorizing task difficulty
    categorizeTask(2);

    return 0;
}
