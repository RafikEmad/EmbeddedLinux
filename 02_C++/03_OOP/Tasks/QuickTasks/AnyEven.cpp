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

    bool anyEven = std::any_of(arr, arr + size, [](int element) {
        return element % 2 == 0;
    });

    if (anyEven) {
        std::cout << "At least one element in the array is even." << std::endl;
    } else {
        std::cout << "No element in the array is even." << std::endl;
    }

    return 0;
}
