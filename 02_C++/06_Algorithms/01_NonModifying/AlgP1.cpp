#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // std::for_each: Apply a function to each element in the container
    std::cout << "std::for_each - Doubling each element:" << std::endl;
    std::for_each(numbers.begin(), numbers.end(), [](int& num) {
        num *= 2;
    });
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // std::count: Count occurrences of a value in the container
    int count = std::count(numbers.begin(), numbers.end(), 6);
    std::cout << "std::count - Count of 6: " << count << std::endl;

    // std::count_if: Count elements satisfying a condition
    int evenCount = std::count_if(numbers.begin(), numbers.end(), [](int num) {
        return num % 2 == 0;
    });
    std::cout << "std::count_if - Count of even numbers: " << evenCount << std::endl;

    // std::find: Find the first occurrence of a value
    auto it = std::find(numbers.begin(), numbers.end(), 8);
    if (it != numbers.end()) {
        std::cout << "std::find - Found 8 at position " << (it - numbers.begin()) << std::endl;
    } else {
        std::cout << "std::find - 8 not found" << std::endl;
    }

    // std::find_if: Find the first element satisfying a condition
    auto evenIt = std::find_if(numbers.begin(), numbers.end(), [](int num) {
        return num % 2 == 0;
    });
    if (evenIt != numbers.end()) {
        std::cout << "std::find_if - Found the first even number (" << *evenIt << ")" << std::endl;
    } else {
        std::cout << "std::find_if - No even number found" << std::endl;
    }

    // std::find_if_not: Find the first element not satisfying a condition
    auto notEvenIt = std::find_if_not(numbers.begin(), numbers.end(), [](int num) {
        return num % 2 == 0;
    });
    if (notEvenIt != numbers.end()) {
        std::cout << "std::find_if_not - Found the first odd number (" << *notEvenIt << ")" << std::endl;
    } else {
        std::cout << "std::find_if_not - No odd number found" << std::endl;
    }

    // std::search: Search for a subsequence in the container
    std::vector<int> subsequence = {3, 4, 5};
    auto searchIt = std::search(numbers.begin(), numbers.end(), subsequence.begin(), subsequence.end());
    if (searchIt != numbers.end()) {
        std::cout << "std::search - Found the subsequence at position " << (searchIt - numbers.begin()) << std::endl;
    } else {
        std::cout << "std::search - Subsequence not found" << std::endl;
    }

    // std::search_n: Search for n consecutive occurrences of a value in the container
    int n = 2;
    auto searchNIt = std::search_n(numbers.begin(), numbers.end(), n, 6);
    if (searchNIt != numbers.end()) {
        std::cout << "std::search_n - Found " << n << " consecutive 6s starting at position " << (searchNIt - numbers.begin()) << std::endl;
    } else {
        std::cout << "std::search_n - " << n << " consecutive 6s not found" << std::endl;
    }

    std::vector<int> numbers1 = {1, 2, 6, 6, 3, 4, 5, 6, 7, 8, 9, 10, 6, 6};

    int x = 2; // Number of consecutive 6s to find
    auto searchNIt1 = std::search_n(numbers1.begin(), numbers1.end(), x, 6);

    if (searchNIt1 != numbers1.end()) {
        std::cout << "std::search_n - Found " << x << " consecutive 6s starting at position " << (searchNIt1 - numbers1.begin()) << std::endl;

        // Separate count using std::count_if
        int count = std::count_if(searchNIt1, searchNIt1 + n, [](int num) { return num == 6; });

        std::cout << "Number of consecutive 6s: " << count << std::endl;
    } else {
        std::cout << "std::search_n - " << n << " consecutive 6s not found" << std::endl;
    }

    return 0;
}
