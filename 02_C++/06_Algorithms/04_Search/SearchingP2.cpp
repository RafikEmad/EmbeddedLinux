#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> haystack = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    std::vector<int> needle = {1, 2, 3};

    // Search for the first occurrence of "needle" in "haystack"
    auto searchResult = std::search(haystack.begin(), haystack.end(), needle.begin(), needle.end());

    if (searchResult != haystack.end()) {
        std::cout << "Found the needle at position " << (searchResult - haystack.begin()) << std::endl;
    } else {
        std::cout << "Needle not found" << std::endl;
    }

    // Search for the first occurrence of three consecutive 3s in "haystack"
    auto searchNResult = std::search_n(haystack.begin(), haystack.end(), 3, 3);

    if (searchNResult != haystack.end()) {
        std::cout << "Found three consecutive 3s at position " << (searchNResult - haystack.begin()) << std::endl;
    } else {
        std::cout << "Three consecutive 3s not found" << std::endl;
    }

    return 0;
}
