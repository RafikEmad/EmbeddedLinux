#include <iostream>
#include <numeric> // for std::accumulate

int main() {
    const int size = 5; // Change this to the size of your array
    int arr[size];

    // Initialize the array with values (for demonstration)
    for (int i = 0; i < size; ++i) {
        arr[i] = i + 1; // Filling the array with values 1, 2, 3, 4, 5
    }

    // Calculate the sum of all elements in the array using std::accumulate
    int sum = std::accumulate(arr, arr + size, 0);

    std::cout << "Sum of all elements in the array: " << sum << std::endl;

    return 0;
}
