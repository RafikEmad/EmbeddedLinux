#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 5> arr = {10, 5, 8, 20, 2};

    if (!arr.empty()) {
        auto maxElement = std::max_element(arr.begin(), arr.end());
        int maxVal = *maxElement;
        std::cout << "The maximum value in the array is: " << maxVal << std::endl;
    } else {
        std::cout << "Array is empty." << std::endl;
    }

    return 0;
}


