#include <iostream>

void findEvenOdd(const int arr[], int size, int even[], int& evenSize, int odd[], int& oddSize) {
    evenSize = 0;
    oddSize = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            even[evenSize++] = arr[i];
        } else {
            odd[oddSize++] = arr[i];
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int even[size];
    int evenSize = 0;

    int odd[size];
    int oddSize = 0;

    findEvenOdd(arr, size, even, evenSize, odd, oddSize);

    std::cout << "Even numbers: ";
    for (int i = 0; i < evenSize; ++i) {
        std::cout << even[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Odd numbers: ";
    for (int i = 0; i < oddSize; ++i) {
        std::cout << odd[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
