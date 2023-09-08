#include <iostream>

const int maxSize = 20; 

void mergeArrays(const int arr1[], int size1, const int arr2[], int size2, int merged[], int& mergedSize) {
    if (size1 + size2 > maxSize) {
        std::cerr << "Merged array size exceeds maximum size." << std::endl;
        mergedSize = 0;
        return;
    }

    for (int i = 0; i < size1; ++i) {
        merged[i] = arr1[i];
    }

    for (int i = 0; i < size2; ++i) {
        merged[size1 + i] = arr2[i];
    }

    mergedSize = size1 + size2;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {6, 7, 8, 9, 10};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int merged[maxSize];
    int mergedSize = 0;

    mergeArrays(arr1, size1, arr2, size2, merged, mergedSize);

    if (mergedSize > 0) {
        std::cout << "Merged array: ";
        for (int i = 0; i < mergedSize; ++i) {
            std::cout << merged[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
