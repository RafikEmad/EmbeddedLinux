#include <iostream>
#include <algorithm>

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int arr[size];

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    bool allEven = std::all_of(arr, arr + size, [](int element) {
        return element % 2 == 0;
    });

    if (allEven) {
        std::cout << "All elements in the array are even." << std::endl;
    } else {
        std::cout << "Not all elements in the array are even." << std::endl;
    }

    return 0;
}
