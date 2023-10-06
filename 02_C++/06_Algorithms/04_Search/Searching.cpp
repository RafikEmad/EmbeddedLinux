#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    // Using std::binary_search
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7};
    int target = 4;
    bool exists = std::binary_search(numbers.begin(), numbers.end(), target);

    std::cout << "Using std::binary_search:" << std::endl;
    if (exists) {
        std::cout << "Value " << target << " exists in the vector." << std::endl;
    } else {
        std::cout << "Value " << target << " does not exist in the vector." << std::endl;
    }

    // Using std::includes
    std::vector<int> set1 = {1, 2, 3, 4, 5};
    std::vector<int> set2 = {2, 4};

    bool isSubset = std::includes(set1.begin(), set1.end(), set2.begin(), set2.end());

    std::cout << "\nUsing std::includes:" << std::endl;
    if (isSubset) {
        std::cout << "set2 is a subset of set1." << std::endl;
    } else {
        std::cout << "set2 is not a subset of set1." << std::endl;
    }

    return 0;
}
