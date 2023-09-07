#include <iostream>

int main() {
    int number;
    std::cout << "Enter a number:"<<std::endl;
    std::cin >> number;
    std::cout << "Multiplication Table for " << number << ":" << std::endl;
    for (int i = 1; i <= 10; ++i) {
        std::cout << number << " x " << i << " = " << (number * i) << std::endl;
    }

    return 0;
}
