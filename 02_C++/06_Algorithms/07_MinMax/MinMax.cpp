#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9};

    // Find the minimum element
    auto minElement = std::min_element(numbers.begin(), numbers.end());
    std::cout << "Minimum Element: " << *minElement << std::endl;

    // Find the maximum element
    auto maxElement = std::max_element(numbers.begin(), numbers.end());
    std::cout << "Maximum Element: " << *maxElement << std::endl;

    // Find both minimum and maximum elements
    auto minmaxElements = std::minmax_element(numbers.begin(), numbers.end());
    std::cout << "Minimum Element: " << *minmaxElements.first << std::endl;
    std::cout << "Maximum Element: " << *minmaxElements.second << std::endl;

    // Find minimum and maximum of two values
    int a = 42;
    int b = 17;
    int minValue = std::min(a, b);
    int maxValue = std::max(a, b);
    std::cout << "Min of a and b: " << minValue << std::endl;
    std::cout << "Max of a and b: " << maxValue << std::endl;

    return 0;
}
