#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string input = "Hello, World!";
    std::stack<char> charStack;

    // Push characters onto the stack
    for (char c : input) {
        charStack.push(c);
    }

    // Pop characters from the stack to reverse the string
    std::cout << "Reversed string: ";
    while (!charStack.empty()) {
        std::cout << charStack.top();
        charStack.pop();
    }
    std::cout << std::endl;

    return 0;
}
