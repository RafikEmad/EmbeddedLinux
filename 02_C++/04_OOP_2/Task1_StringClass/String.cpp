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
    // Copy Constructor
    MyString(const MyString& other)
    {
        length = other.length;
        str = new char [length+1];  // Allocate memory for the copied string
        std::strcpy(str,other.str); // Copy the content of the other MyString object
        std::cout<<"COPY Constructor called"<<std::endl;
    }
    // Move Constructor
    MyString(MyString &&other)
    {
        length = other.length;
        str = other.str;
        other.str = nullptr; // Prevent the moved-from object from deallocating the memory
        std::cout<<"MOVE Constructor called"<<std::endl;
    }
    //Copy Assignment
    MyString& operator =(const MyString& other)
    {
        if(this == &other)
        {
            return *this;   // Handle self-assignment
        }
        // Deallocate current memory if it's not nullptr
        if (str != nullptr) 
        {
            delete[] str;
        }
        length = other.length;  // Update length
        str = new char[length + 1]; // Allocate new memory
        std::strcpy(str, other.str); // Copy content
        std::cout<<"COPY Assignment called"<<std::endl;
        return *this;
    }
    //Move Assignment
    MyString& operator =(MyString&& other)
    {
        if(this == &other)
        {
            return *this;   // Handle self-assignment
        }
        // Deallocate current memory if it's not nullptr
        if (str != nullptr) 
        {
            delete[] str;
        }
        length = other.length;  // Update length
        str = other.str;        // Take ownership of the other object's memory
        other.str = nullptr;
        std::cout<<"MOVE Assignment called"<<std::endl;
        return *this;
    }
    // Destructor
    ~MyString() {
        std::cout<<"Destructor called"<<std::endl;
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
    // Access characters by index (without bounds checking)
    char operator[](int index) const {
        if (index >= 0 && index < length) {
            return str[index];
        }
        throw std::out_of_range("Index out of range");
    }
    // Access characters with bounds checking
    char at(int index) const {
        if (index >= 0 && index < length) {
            return str[index];
        }
        throw std::out_of_range("Index out of rangeeeeee");
    }
    // Access the first character
    char front() const {
        if (length > 0) {
            return str[0];
        }
        throw std::out_of_range("String is empty");
    }
    // Access the last character
    char back() const {
        if (length > 0) {
            return str[length - 1];
        }
        throw std::out_of_range("String is empty");
    }
    // push_back: Appends a character to the end
    void push_back(char c) {
        char* newStr = new char[length + 2]; // Allocate memory for the modified string
        std::strcpy(newStr, str);            // Copy the original string
        newStr[length] = c;                  // Append the new character
        newStr[length + 1] = '\0';           // Null-terminate the new string
        delete[] str;                        // Deallocate the old memory
        str = newStr;                        // Update the pointer
        length++;                            // Increment the length
    }

    // pop_back: Removes the last character
    void pop_back() {
        if (length > 0) {
            char* newStr = new char[length]; // Allocate memory for the modified string
            std::strncpy(newStr, str, length - 1); // Copy all but the last character
            newStr[length - 1] = '\0';       // Null-terminate the new string
            delete[] str;                    // Deallocate the old memory
            str = newStr;                    // Update the pointer
            length--;                         // Decrement the length
        }
    }

    // append: Appends another string
    void append(const char* s) {
        int newLength = length + std::strlen(s);
        char* newStr = new char[newLength + 1]; // Allocate memory for the combined string
        std::strcpy(newStr, str);               // Copy the original string
        std::strcat(newStr, s);                 // Concatenate the new string
        delete[] str;                           // Deallocate the old memory
        str = newStr;                           // Update the pointer
        length = newLength;                     // Update the length
    }

    // assign: Assigns another string
    void assign(const char* s) {
        delete[] str;               // Deallocate the old memory
        length = std::strlen(s);    // Update the length
        str = new char[length + 1]; // Allocate memory for the new string (+1 for null terminator)
        std::strcpy(str, s);        // Copy the input string to the dynamically allocated memory
    }

    // insert: Inserts characters at a specified position
    void insert(int pos, const char* s) {
        if (pos >= 0 && pos <= length) {
            int newLength = length + std::strlen(s);
            char* newStr = new char[newLength + 1]; // Allocate memory for the modified string
            std::strncpy(newStr, str, pos);        // Copy characters before the insertion point
            std::strcpy(newStr + pos, s);           // Copy the inserted string
            std::strcpy(newStr + pos + std::strlen(s), str + pos); // Copy characters after the insertion point
            delete[] str;                           // Deallocate the old memory
            str = newStr;                           // Update the pointer
            length = newLength;                     // Update the length
        }
    }

    // erase: Removes characters at a specified position or in a range
    void erase(int pos, int count) {
        if (pos >= 0 && pos < length && count > 0) {
            if (pos + count > length) {
                count = length - pos; // Adjust count if it exceeds the string length
            }
            char* newStr = new char[length - count + 1]; // Allocate memory for the modified string
            std::strncpy(newStr, str, pos);               // Copy characters before the erased part
            std::strcpy(newStr + pos, str + pos + count); // Copy characters after the erased part
            delete[] str;                                // Deallocate the old memory
            str = newStr;                                // Update the pointer
            length -= count;                             // Update the length
        }
    }

    // replace: Replaces characters in a string with another string
    void replace(int pos, int count, const char* s) {
        erase(pos, count); // Erase the specified characters
        insert(pos, s);    // Insert the new string at the specified position
    }

    // resize: Changes the size of the string
    void resize(int newSize) {
        if (newSize >= 0) {
            if (newSize < length) {
                length = newSize; // Truncate the string
                str[length] = '\0';
            } else if (newSize > length) {
                char* newStr = new char[newSize + 1]; // Allocate memory for the resized string
                std::strcpy(newStr, str);              // Copy the original string
                for (int i = length; i < newSize; ++i) {
                    newStr[i] = ' '; // Fill the additional space with spaces
                }
                newStr[newSize] = '\0'; // Null-terminate the new string
                delete[] str;           // Deallocate the old memory
                str = newStr;           // Update the pointer
                length = newSize;        // Update the length
            }
        }
    }

    // swap: Swaps the contents of two strings
    void swap(MyString& other) {
        std::swap(length, other.length);
        std::swap(str, other.str);
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

    std::cout << "=========================================="<<std::endl;
    //COPY Constructor
    MyString myStr3 = myStr1;
    std::cout<<myStr3.getString();
    std::cout << "=========================================="<<std::endl;
    //MOVE Constructor
    MyString myStr4 = std::move(myStr3);
    std::cout<<myStr4.getString();
    std::cout << "=========================================="<<std::endl;
    //COPY Assignment
    myStr4 = myStr1;
    std::cout<<myStr4.getString();
    std::cout << "=========================================="<<std::endl;
    //MOVE Assignment
    myStr4 = std::move(myStr2);
    std::cout<<myStr4.getString();
    std::cout << "=========================================="<<std::endl;
    std::cout << "============Accessing Characters==============="<<std::endl;
    // Access characters and print the result
    MyString myStr("Hello, World!");
    std::cout << "Character at index 7: " << myStr[7] << std::endl;
    std::cout << "Character at index 15: ";
    
    try {
        char character = myStr.at(15);
        std::cout << character << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "First character: " << myStr.front() << std::endl;
    std::cout << "Last character: " << myStr.back() << std::endl;

    std::cout << "============Modifying Characters==============="<<std::endl;
    MyString myStr5("Hello, World!");

    // Test the modifier functions
    std::cout << "Original String: " << myStr5.getString() << std::endl;

    myStr5.push_back('!');
    std::cout << "After push_back: " << myStr5.getString() << std::endl;

    myStr5.pop_back();
    std::cout << "After pop_back: " << myStr5.getString() << std::endl;

    myStr5.append(" Welcome");
    std::cout << "After append: " << myStr5.getString() << std::endl;

    myStr5.assign("Hi there");
    std::cout << "After assign: " << myStr5.getString() << std::endl;

    myStr5.insert(3, ", C++");
    std::cout << "After insert: " << myStr5.getString() << std::endl;

    myStr5.erase(5, 5);
    std::cout << "After erase: " << myStr5.getString();

    return 0;
}
