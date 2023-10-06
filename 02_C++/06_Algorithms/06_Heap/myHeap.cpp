#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    // Create an initial vector of numbers
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9};

    // Create a max-heap from the vector
    std::make_heap(numbers.begin(), numbers.end());

    std::cout << "Max-Heap: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Add a new element to the max-heap
    numbers.push_back(6);
    std::push_heap(numbers.begin(), numbers.end());

    std::cout << "Max-Heap after push_heap: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Remove the largest element from the max-heap
    std::pop_heap(numbers.begin(), numbers.end());
    int largest = numbers.back();
    numbers.pop_back();

    std::cout << "Max-Heap after pop_heap: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\nLargest element (popped): " << largest << std::endl;

    // Sort the remaining elements in ascending order using heap sort
    std::sort_heap(numbers.begin(), numbers.end());

    std::cout << "Sorted Sequence: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
