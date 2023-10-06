#include <iostream>
#include <numeric>

int main() {
    int a = 12;
    int b = 18;

    // Calculate the GCD of a and b
    int gcdResult = std::gcd(a, b);
    std::cout << "GCD of " << a << " and " << b << " is " << gcdResult << std::endl;

    // Calculate the LCM of a and b
    int lcmResult = std::lcm(a, b);
    std::cout << "LCM of " << a << " and " << b << " is " << lcmResult << std::endl;

    return 0;
}
