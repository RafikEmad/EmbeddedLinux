#include <iostream>
#include <cctype> // Include the cctype header for isdigit() function

int main() {
    char character;
    while(1)
    {
        // Input character from the user
        std::cout << "Enter a character: ";
        std::cin >> character;

        // Check if the character is a digit using isdigit()
        if (std::isdigit(character)) {
            std::cout << "The character is a digit." << std::endl;
        } else {
            std::cout << "The character is not a digit." << std::endl;
        }
    }
    
    return 0;
}
