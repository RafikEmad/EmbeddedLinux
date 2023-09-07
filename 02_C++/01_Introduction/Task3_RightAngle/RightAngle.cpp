#include <iostream>

bool isRightTriangle(int a, int b, int c) {
    // Find the square of the longest side
    int maxSide = std::max(std::max(a, b), c);
    int sumOfSquares = 0;

    if (maxSide == a) {
        sumOfSquares = b * b + c * c;
    } else if (maxSide == b) {
        sumOfSquares = a * a + c * c;
    } else {
        sumOfSquares = a * a + b * b;
    }

    // Check if it satisfies the Pythagorean theorem
    return maxSide * maxSide == sumOfSquares;
}

int main() {
    int a, b, c;
    std::cout << "Enter the three sides of the triangle:"<< std::endl;
    std::cin >> a >> b >> c;

    if (isRightTriangle(a, b, c)) {
        std::cout << "It is a right triangle." << std::endl;
    } else {
        std::cout << "It is not a right triangle." << std::endl;
    }

    return 0;
}
