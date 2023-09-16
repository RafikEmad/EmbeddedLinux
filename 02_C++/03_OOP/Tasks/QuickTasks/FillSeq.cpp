#include <iostream>
#include <numeric> // for std::iota
#include <vector>  // for std::vector

int main() {
    const int size = 9991; // Total number of elements (10000 - 10 + 1)
    std::vector<int> arr(size);

    // Fill the array with values from 10 to 10000 sequentially
    std::iota(arr.begin(), arr.end(), 10);

    // Printing the first few elements to verify
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "... "; // Skipping to the end
    for (int i = size - 10; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
