#include <iostream>

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
    unsigned long long result = factorial(number);
    std::cout << "Factorial of " << number << " is: " << result << std::endl;
    return 0;
}
