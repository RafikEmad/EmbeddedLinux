#include <iostream>
#include <vector>

class MyObject {
public:
    MyObject(int a, double b) : intField(a), doubleField(b) {
        std::cout << "MyObject constructor called." << std::endl;
        std::cout << intField << " " << doubleField << std::endl;    
        }

private:
    int intField;
    double doubleField;
};

template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& value : vec) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Initialization and Capacity
    std::cout << "==============Initialization and Capacity=============="<<std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> vec1(std::begin(arr), std::end(arr)); //Create a vector with elements from the range
    printVector(vec1);
        
    // Create an empty vector of integers
    std::vector<int> vec;
    vec.reserve(10);
    // Add elements to the vector
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    // Get the number of elements in the vector
    std::cout << "Vector size: " << vec.size() << std::endl;
    std::cout<< "Vector Capacity: " << vec.capacity() << std::endl;
    if (!vec.empty()) {std::cout<< "Vector is not empty" << std::endl;}

    // Element Access
    std::cout << "==============Element Access=============="<<std::endl;
    // Access elements by index
    std::cout << "Element at index 2: " << vec[2] << std::endl;
    std::cout << "First Element : " << vec.front() << std::endl;
    std::cout << "Last Element : " << vec.back() << std::endl;
    // Get a pointer to the underlying data using vec.data()
    int* dataPointer = vec.data();
    // Print all elements using the data pointer
    std::cout << "Elements using vec.data(): ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << dataPointer[i] << " ";
    }
    std::cout << std::endl;

    // Access elements with bounds checking
    try {
        int value = vec.at(5); // This will throw an out_of_range exception
    } catch (const std::out_of_range& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    // Modifiers
    std::cout << "==============Modifiers=============="<<std::endl;
    // Insert an element at a specified position
    vec.insert(vec.begin() + 1, 10);
    printVector(vec);

    // Remove the last element
    vec.pop_back();
    printVector(vec);

    // Remove the element at a specified position
    vec.erase(vec.begin() + 2);
    printVector(vec);

    // Clear all elements
    vec.clear();
    printVector(vec);

    // Check if the vector is empty
    if (vec.empty()) {
        std::cout << "Vector is empty." << std::endl;
    }

    // Iterators
    std::cout << "==============Iterators=============="<<std::endl;
    // Fill the vector again
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);

    // Iterate through the vector and print its elements
    std::cout << "Vector elements:";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    // Swap the vector with another vector
    std::vector<int> anotherVec = {100, 200};
    vec.swap(anotherVec);

    // Print the contents of both vectors after swapping
    std::cout << "Vector after swapping:";
    printVector(vec);
    std::cout << "Another vector after swapping:";
    printVector(vec);
    vec.emplace_back(10000);
    printVector(vec);
    //emplace_back
    std::vector<MyObject> vec2;
    // Using emplace_back() to construct and add an element directly
    vec2.emplace_back(42, 3.14);


    return 0;
}
