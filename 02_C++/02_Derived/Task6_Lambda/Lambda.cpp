#include <iostream>

int main() {
    auto square = [](int x) -> int {
        int result = x * x;
        return result;
    };

    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    int result = square(number);

    std::cout << "The square of " << number << " is: " << result << std::endl;

    return 0;
}
