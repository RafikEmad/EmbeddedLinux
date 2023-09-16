#include <iostream>
#include <cstring>

class MyString {
private:
    char* str;    // Pointer to dynamically allocated character array
    int length;   // Length of the string

public:
    // Constructor
    MyString(const char* s) {
        length = std::strlen(s);
        str = new char[length + 1]; // Allocate memory for the string (+1 for null terminator)
        std::strcpy(str, s);        // Copy the input string to the dynamically allocated memory
    }

    // Destructor
    ~MyString() {
        delete[] str; // Deallocate the dynamically allocated memory
    }

    // Getter method to retrieve the string
    const char* getString() const {
        return str;
    }

    // Getter method to retrieve the length of the string
    int getLength() const {
        return length;
    }

    // Overload the + operator for string concatenation
    MyString operator+(const MyString& other) const {
        char* newStr = new char[length + other.length + 1]; // Allocate memory for the concatenated string
        std::strcpy(newStr, str);                            // Copy the first string
        std::strcat(newStr, other.str);                      // Concatenate the second string
        return MyString(newStr);                             // Create a new MyString object with the result
    }
};

int main() {
    // Create instances of the MyString class
    MyString myStr1("Hello, ");
    MyString myStr2("World!");

    // Use the + operator to concatenate strings
    MyString concatenatedStr = myStr1 + myStr2;

    // Use the getter methods to access the concatenated string and its length
    const char* str = concatenatedStr.getString();
    int length = concatenatedStr.getLength();

    std::cout << "Concatenated String: " << str << std::endl;
    std::cout << "Length: " << length << std::endl;

    return 0;
}
