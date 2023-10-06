#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {5, 2, 8, 1, 6, 3, 7, 4};
    std::vector<int> sortedNumbers = numbers; // Copy of the original vector for std::sort
    std::vector<int> stableSortedNumbers = numbers; // Copy of the original vector for std::stable_sort
    std::vector<int> partialSortedNumbers = numbers; // Copy of the original vector for std::partial_sort
    std::vector<int> partialSortCopyNumbers;// Destination vector for std::partial_sort_copy
    partialSortCopyNumbers.resize(numbers.size());
    // Sort using std::sort (Not stable, fully sorted)
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    // Stable sort using std::stable_sort (Stable, fully sorted)
    std::stable_sort(stableSortedNumbers.begin(), stableSortedNumbers.end());

    // Partial sort using std::partial_sort (Not stable, partially sorted)
    std::partial_sort(partialSortedNumbers.begin(), partialSortedNumbers.begin() + 3, partialSortedNumbers.end());

    // Partial sort using std::partial_sort_copy (Not stable, partially sorted, and copied)
    std::partial_sort_copy(
        numbers.begin(), numbers.end(),
        partialSortCopyNumbers.begin(), partialSortCopyNumbers.end(),
        [](int a, int b) {
            return a < b;
        }
    );

    // Output results
    std::cout << "Original Numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted Numbers (std::sort): ";
    for (int num : sortedNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Stable Sorted Numbers (std::stable_sort): ";
    for (int num : stableSortedNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Partially Sorted Numbers (std::partial_sort): ";
    for (int num : partialSortedNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Partial Sort Copy Numbers (std::partial_sort_copy): ";
    for (int num : partialSortCopyNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
