#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 2, 2, 3, 4, 5, 6, 7};

    int target = 2; // The value we want to find

    // Find the range of elements equal to the target value using std::equal_range
    auto range = std::equal_range(numbers.begin(), numbers.end(), target);

    // Output the results
    std::cout << "Original Numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Target Value: " << target << std::endl;

    std::cout << "Equal Range: ";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
