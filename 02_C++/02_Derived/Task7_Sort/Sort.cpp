#include <iostream>
#include <algorithm>

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6, 3, 8, 4, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sorting in ascending order using a lambda function
    std::sort(std::begin(arr), std::end(arr), [](int a, int b) {
        return a < b;
    });

    std::cout << "Sorted in ascending order: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Sorting in descending order using a lambda function
    std::sort(std::begin(arr), std::end(arr), [](int a, int b) {
        return a > b;
    });

    std::cout << "Sorted in descending order: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
