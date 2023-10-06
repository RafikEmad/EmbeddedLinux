#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {5, 2, 8, 1, 6, 3, 7, 4};
    std::vector<int> partitionedNumbers = numbers; // Copy of the original vector for std::partition

    // Partition using std::partition (Modifies the original range)
    auto partitionEnd = std::partition(partitionedNumbers.begin(), partitionedNumbers.end(), [](int num) {
        return num % 2 == 0;
    });

    // Partition using std::partition_copy (Does not modify the original range)
    std::vector<int> evenNumbers;
    std::vector<int> oddNumbers;
    std::partition_copy(numbers.begin(), numbers.end(), std::back_inserter(evenNumbers), std::back_inserter(oddNumbers), [](int num) {
        return num % 2 == 0;
    });

    // Output results
    std::cout << "Original Numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Partitioned Numbers (std::partition): ";
    for (int num : partitionedNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Even Numbers (std::partition_copy): ";
    for (int num : evenNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Odd Numbers (std::partition_copy): ";
    for (int num : oddNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
