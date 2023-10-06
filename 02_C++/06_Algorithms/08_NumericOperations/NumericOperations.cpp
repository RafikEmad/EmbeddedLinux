#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Calculate the sum of all elements
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum: " << sum << std::endl;

    // Compute the inner product of two sequences
    std::vector<int> weights = {2, 2, 2, 2, 2};
    int innerProduct = std::inner_product(numbers.begin(), numbers.end(), weights.begin(), 0);
    std::cout << "Inner Product: " << innerProduct << std::endl;

    // Calculate partial sums
    std::vector<int> partialSums(numbers.size());
    std::partial_sum(numbers.begin(), numbers.end(), partialSums.begin());
    std::cout << "Partial Sums: ";
    for (int num : partialSums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Calculate adjacent differences
    std::vector<int> adjacentDiffs(numbers.size());
    std::adjacent_difference(numbers.begin(), numbers.end(), adjacentDiffs.begin());
    std::cout << "Adjacent Differences: ";
    for (int diff : adjacentDiffs) {
        std::cout << diff << " ";
    }
    std::cout << std::endl;

    // Fill a range with incrementing values
    std::vector<int> sequence(5);
    std::iota(sequence.begin(), sequence.end(), 10);
    std::cout << "Generated Sequence: ";
    for (int num : sequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
