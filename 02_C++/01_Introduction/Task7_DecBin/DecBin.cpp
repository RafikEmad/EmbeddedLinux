#include <iostream>
#include <bitset>
#include <string>

std::string decimalToBinary(int decimal) {
    return std::bitset<32>(decimal).to_string(); // Assuming 32-bit binary representation
}

int binaryToDecimal(const std::string& binary) {
    return std::bitset<32>(binary).to_ulong(); // Assuming 32-bit binary representation
}

int main() {
    int decimalNumber;
    std::cout << "Enter a decimal number: ";
    std::cin >> decimalNumber;

    std::string binary = decimalToBinary(decimalNumber);
    std::cout << "Binary representation: " << binary << std::endl;

    std::string binaryNumber;
    std::cout << "Enter a binary number: ";
    std::cin >> binaryNumber;

    int decimal = binaryToDecimal(binaryNumber);
    std::cout << "Decimal representation: " << decimal << std::endl;


    return 0;
}
