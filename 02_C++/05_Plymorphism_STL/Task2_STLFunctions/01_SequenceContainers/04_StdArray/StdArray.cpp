#include <iostream>
#include <array>

int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};

    std::cout << "Size of arr: " << arr.size() << std::endl;
    std::cout << "First element: " << arr.front() << std::endl;
    std::cout << "Last element: " << arr.back() << std::endl;
    if(!arr.empty()) {std::cout<<"array not empty"<<std::endl;}
    // Access elements using iterators
    std::cout << "Elements:";
    for (const auto& element : arr) {
        std::cout << " " << element;
    }
    std::cout << std::endl;

    // Get a pointer to the underlying data
    int* ptr = arr.data();

    // Access elements using the pointer
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << "Element at index " << i << ": " << ptr[i] << std::endl;
    }

    // Fill the array with a value
    arr.fill(0);
    // Access elements using the 'at' function with bounds checking
    try {
        std::cout << "Element at index 5: " << arr.at(5) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range exception: " << e.what() << std::endl;
    }

    // Swap contents with another array
    std::array<int, 5> anotherArr = {10, 20, 30, 40, 50};
    arr.swap(anotherArr);

    std::cout << "Swapped array:";
    for (const auto& element : arr) {
        std::cout << " " << element;
    }
    std::cout << std::endl;

    return 0;
}
