#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

int main() {
    std::vector<int> numbers = {1, 2, 2, 3, 4, 5, 2, 6, 7, 8, 9, 2, 10};

    // std::remove_copy: Create a new vector with elements removed
    std::vector<int> removeCopyVector(numbers.size());
    auto removeCopyEnd = std::remove_copy(numbers.begin(), numbers.end(), removeCopyVector.begin(), 2);
    removeCopyVector.erase(removeCopyEnd, removeCopyVector.end());

    // std::remove_copy_if: Create a new vector with elements removed based on a condition
    std::vector<int> removeCopyIfVector(numbers.size());
    auto removeCopyIfEnd = std::remove_copy_if(numbers.begin(), numbers.end(), removeCopyIfVector.begin(), [](int num) {
        return num > 5;
    });
    removeCopyIfVector.erase(removeCopyIfEnd, removeCopyIfVector.end());

    // std::unique: Remove consecutive duplicate elements from the vector
    std::unique(numbers.begin(), numbers.end());

    std::cout << "Unique Vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // std::unique_copy: Create a new vector with consecutive duplicate elements removed
    std::vector<int> uniqueCopyVector(numbers.size());
    auto uniqueCopyEnd = std::unique_copy(numbers.begin(), numbers.end(), uniqueCopyVector.begin());
    uniqueCopyVector.erase(uniqueCopyEnd, uniqueCopyVector.end());

    // std::reverse: Reverse the order of elements in the vector
    std::reverse(numbers.begin(), numbers.end());

    std::cout << "Reverse Vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // std::reverse_copy: Create a new vector with elements in reverse order
    std::vector<int> reverseCopyVector(numbers.size());
    std::reverse_copy(numbers.begin(), numbers.end(), reverseCopyVector.begin());

    // std::rotate: Rotate the elements in the vector
    std::rotate(numbers.begin(), numbers.begin() + 3, numbers.end());

    std::cout << "Rotated Vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // std::rotate_copy: Create a new vector with rotated elements
    std::vector<int> rotateCopyVector(numbers.size());
    std::rotate_copy(numbers.begin(), numbers.begin() + 3, numbers.end(), rotateCopyVector.begin());

    // std::random_shuffle: Shuffle the elements randomly
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(numbers.begin(), numbers.end(), g);

    // Output modified vectors
    std::cout << "Remove Copy Vector: ";
    for (int num : removeCopyVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Remove Copy If Vector: ";
    for (int num : removeCopyIfVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    

    std::cout << "Unique Copy Vector: ";
    for (int num : uniqueCopyVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    

    std::cout << "Reverse Copy Vector: ";
    for (int num : reverseCopyVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    

    std::cout << "Rotate Copy Vector: ";
    for (int num : rotateCopyVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Shuffled Vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
