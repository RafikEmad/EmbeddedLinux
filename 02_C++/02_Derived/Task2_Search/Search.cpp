#include <iostream>
#include <algorithm>

bool searchNumber(const int arr[], int size, int target) {
    const int* found = std::find(arr, arr + size, target); 
    return found != arr + size;
}

int main() {
    int arr[] = {10, 5, 8, 20, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    std::cout << "Enter a number to search for: ";
    std::cin >> target;

    if (searchNumber(arr, size, target)) {
        std::cout << "The number " << target << " was found in the array." << std::endl;
    } else {
        std::cout << "The number " << target << " was not found in the array." << std::endl;
    }

    return 0;
}
