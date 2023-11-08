#include <iostream>
#include <chrono>

// better with memory
unsigned long long factorialIterative(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// more readable
unsigned long long factorialRecursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorialRecursive(n - 1);
    }
}

int getInput() {
    int choice;
    std::cout << "Choose a method for factorial calculation:" << std::endl;
    std::cout << "1. Iterative method" << std::endl;
    std::cout << "2. Recursive method" << std::endl;
    std::cin >> choice;
    return choice;
}

int main() {
    int number;
    int choice = getInput();

    std::cout << "Enter a non-negative integer: ";
    std::cin >> number;

    auto start = std::chrono::high_resolution_clock::now();

    unsigned long long result;
    if (choice == 1) {
        result = factorialIterative(number);
    } else if (choice == 2) {
        result = factorialRecursive(number);
    } else {
        std::cout << "Invalid choice. Please run the program again and choose a valid option." << std::endl;
        return 1;
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Factorial of " << number << " is: " << result << std::endl;
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
