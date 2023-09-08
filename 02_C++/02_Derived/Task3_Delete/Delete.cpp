#include <iostream>

void deleteNumber(int arr[], int& size, int target) {
    int newSize = 0; // Initialize the new size

    for (int i = 0; i < size; ++i) {
        if (arr[i] != target) {
            // Copy non-target elements to the new array
            arr[newSize++] = arr[i];
        }
    }

    size = newSize; // Update the size to the new size
}

int main() {
    int arr[] = {10, 5, 8, 20, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    std::cout << "Enter a number to delete from the array: ";
    std::cin >> target;

    deleteNumber(arr, size, target);

    if (size == 0) {
        std::cout << "The array is now empty." << std::endl;
    } else {
        std::cout << "Updated array after deleting " << target << ": ";
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
