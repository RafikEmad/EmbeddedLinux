#include <iostream>
#include <cctype> // Include the cctype header for the isalpha and tolower functions

bool isVowel(char letter) {
    letter = std::tolower(letter);
    return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u');
}

int main() {
    char letter;
    std::cout << "Enter a letter:"<<std::endl;
    std::cin >> letter;

    if (std::isalpha(letter)) {
        if (isVowel(letter)) {
            std::cout << letter << " is a vowel." << std::endl;
        } else {
            std::cout << letter << " is not a vowel." << std::endl;
        }
    } else {
        std::cout << "Invalid input. Please enter a valid letter." << std::endl;
    }

    return 0;
}
