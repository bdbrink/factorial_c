#include <iostream>
#include <chrono>

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int getInput() {
    int number;
    while (true) {
        std::cout << "Enter a non-negative integer: ";
        std::cin >> number;
        if (std::cin.fail() || number < 0) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input. Please try again." << std::endl;
        } else {
            break;
        }
    }
    return number;
}

int main() {
    int number = getInput();

    auto start = std::chrono::high_resolution_clock::now(); // Start the timer
    unsigned long long result = factorial(number);
    auto stop = std::chrono::high_resolution_clock::now(); // Stop the timer

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Factorial of " << number << " is: " << result << std::endl;
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
