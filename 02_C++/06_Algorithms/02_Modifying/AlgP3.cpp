#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 2, 3, 4, 5, 2, 6, 7, 8, 9, 2, 10};

    // std::replace: Replace all occurrences of a value with another value
    std::replace(numbers.begin(), numbers.end(), 2, 20);

    // std::replace_if: Replace elements that satisfy a condition with another value
    std::replace_if(numbers.begin(), numbers.end(), [](int num) {
        return num > 5;
    }, 50);

    // std::replace_copy: Create a new vector with replaced values
    std::vector<int> replaceCopyVector(numbers.size());
    std::replace_copy(numbers.begin(), numbers.end(), replaceCopyVector.begin(), 10, 100);

    // std::replace_copy_if: Create a new vector with replaced values based on a condition
    std::vector<int> replaceCopyIfVector(numbers.size());
    std::replace_copy_if(numbers.begin(), numbers.end(), replaceCopyIfVector.begin(), [](int num) {
        return num % 2 == 0;
    }, 200);

    // std::fill: Fill a range with a specific value
    std::fill(numbers.begin(), numbers.end(), 0);

    // std::fill_n: Fill the first n elements with a specific value
    std::fill_n(numbers.begin(), 3, 99);

    // std::generate: Generate values for a range using a function
    int value = 1;
    std::generate(numbers.begin(), numbers.end(), [&value]() {
        return value++;
    });

    // std::generate_n: Generate values for the first n elements using a function
    int startValue = 50;
    std::generate_n(numbers.begin(), 5, [&startValue]() {
        return startValue++;
    });

    // std::remove: Remove all occurrences of a value (returns an iterator to the new end)
    auto newEnd = std::remove(numbers.begin(), numbers.end(), 2);
    numbers.erase(newEnd, numbers.end());

    // std::remove_if: Remove elements that satisfy a condition (returns an iterator to the new end)
    auto newEndIf = std::remove_if(numbers.begin(), numbers.end(), [](int num) {
        return num > 15;
    });
    numbers.erase(newEndIf, numbers.end());

    // Output the modified vector
    std::cout << "Modified Vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Output the replace-copy vectors
    std::cout << "Replace Copy Vector: ";
    for (int num : replaceCopyVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Replace Copy If Vector: ";
    for (int num : replaceCopyIfVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
