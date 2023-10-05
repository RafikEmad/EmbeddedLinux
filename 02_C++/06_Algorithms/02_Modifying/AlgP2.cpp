#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> originalVector = {1, 2, 3, 4, 5};
    std::vector<int> destinationVector(5);  // Create an empty vector with the same size

    // std::copy: Copy elements from one vector to another
    std::copy(originalVector.begin(), originalVector.end(), destinationVector.begin());

    // std::copy_if: Copy elements from one vector to another based on a condition
    std::vector<int> evenVector(5); // Create a vector to store even numbers
    std::copy_if(originalVector.begin(), originalVector.end(), evenVector.begin(), [](int num) {
        return num % 2 == 0;
    });

    // std::copy_n: Copy the first n elements from one vector to another
    std::vector<int> copyNVector(3); // Create a vector to store the first 3 elements
    std::copy_n(originalVector.begin(), 3, copyNVector.begin());

    // std::move: Move elements from one vector to another
    std::vector<int> sourceVector = {6, 7, 8, 9, 10};
    std::move(sourceVector.begin(), sourceVector.end(), originalVector.begin());

    // std::swap_ranges: Swap elements between two vectors
    std::vector<int> swapVector = {11, 12, 13, 14, 15};
    std::swap_ranges(originalVector.begin(), originalVector.end(), swapVector.begin());

    // std::transform: Apply a function to each element in a vector and store the result in another vector
    std::vector<int> squaredVector(5);
    std::transform(originalVector.begin(), originalVector.end(), squaredVector.begin(), [](int num) {
        return num * num;
    });

    // Output modified vectors
    std::cout << "Original Vector: ";
    for (int num : originalVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Even Vector: ";
    for (int num : evenVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Copy N Vector: ";
    for (int num : copyNVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Squared Vector: ";
    for (int num : squaredVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
