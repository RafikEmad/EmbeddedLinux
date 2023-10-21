#include <iostream>
#include <regex>
#include <string>

int main() {
    // Define the regular expression pattern for the branch name
    std::regex pattern("feature/TN-\\d{3}/[A-Za-z0-9]+");

    // Input branch name
    std::string branchName;

    std::cout << "Enter a branch name: ";
    std::cin >> branchName;

    // Use std::regex_match to validate the branch name
    if (std::regex_match(branchName, pattern)) {
        std::cout << "Valid branch name: " << branchName << std::endl;
    } else {
        std::cout << "Invalid branch name: " << branchName << std::endl;
    }

    return 0;
}
