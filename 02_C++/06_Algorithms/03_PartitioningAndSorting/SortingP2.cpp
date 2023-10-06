#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {5, 2, 8, 1, 6, 3, 7, 4};

    // std::nth_element: Find the nth element in the range
    int n = 3; // Find the 3rd smallest element
    std::nth_element(numbers.begin(), numbers.begin() + n - 1, numbers.end());
    int nthElement = numbers[n - 1];

    // std::inplace_merge: Merge two sorted ranges in place
    std::vector<int> leftHalf = {2, 5, 8};
    std::vector<int> rightHalf = {1, 3, 6};
    std::vector<int> mergedNumbers(leftHalf.size() + rightHalf.size());
    std::merge(leftHalf.begin(), leftHalf.end(), rightHalf.begin(), rightHalf.end(), mergedNumbers.begin());

    // std::is_sorted: Check if a range is sorted
    bool isSorted = std::is_sorted(numbers.begin(), numbers.end());

    // std::is_sorted_until: Find the first element that makes a range unsorted
    auto unsortedUntil = std::is_sorted_until(numbers.begin(), numbers.end());

    // Output results
    std::cout << "Original Numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Nth Smallest Element (std::nth_element): " << nthElement << std::endl;

    std::cout << "Merged Numbers (std::inplace_merge): ";
    for (int num : mergedNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Is Sorted (std::is_sorted): " << (isSorted ? "Yes" : "No") << std::endl;

    std::cout << "Unsorted Until (std::is_sorted_until): ";
    for (auto it = numbers.begin(); it != unsortedUntil; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
