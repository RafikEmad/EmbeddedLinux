#include <iostream>
#include <set>

int main() {
    // Create an ordered std::multiset with some initial values
    std::multiset<int> myMultiSet;
    myMultiSet.insert(3);
    myMultiSet.emplace(1);
    myMultiSet.insert(2);
    myMultiSet.emplace(4);
    myMultiSet.insert(2); // Duplicates are allowed
    myMultiSet.emplace_hint(myMultiSet.begin(),10);
    // Access elements using iterators
    std::cout << "Elements in the multiset:" << std::endl;
    for (const auto& value : myMultiSet) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Use equal_range to find a range of elements with a specific value
    int targetValue = 2;
    auto range1 = myMultiSet.equal_range(targetValue);

    // Print the range of elements with the target value
    std::cout << "Range of elements with value " << targetValue << ":" << std::endl;
    for (auto it = range1.first; it != range1.second; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Access key comparison function
    std::multiset<int>::key_compare keyComparator = myMultiSet.key_comp();

    // Use value comparison function
    std::multiset<int>::value_compare valueComparator = myMultiSet.value_comp();

    // Examples using key comparison and value comparison
    int key1 = 2;
    int key2 = 4;

    std::cout << "Comparing keys using key_comp:" << std::endl;
    bool keyComparisonResult = keyComparator(key1, key2);
    std::cout << "Is key " << key1 << " less than key " << key2 << "? " << keyComparisonResult << std::endl;

    std::cout << "Comparing values using value_comp:" << std::endl;
    bool valueComparisonResult = valueComparator(*myMultiSet.begin(), *myMultiSet.rbegin());
    std::cout << "Is the first value less than the last value? " << valueComparisonResult << std::endl;


    // Erase elements by value
    myMultiSet.erase(2); // Remove all occurrences of value 2
    for (const auto& value : myMultiSet) {
        std::cout << value<< " ";
    }
    std::cout << std::endl;

    // Find elements by value
    auto it = myMultiSet.find(3); // Find the element with value 3
    if (it != myMultiSet.end()) {
        std::cout << "Found: " << *it << std::endl;
    } else {
        std::cout << "Value 3 not found." << std::endl;
    }

    // Count the number of occurrences of a value
    int count = myMultiSet.count(1); // Count the number of occurrences of value 1
    std::cout << "Number of occurrences of 1: " << count << std::endl;

    // Use equal_range to find a range of elements with a specific value
    auto range = myMultiSet.equal_range(1);
    std::cout << "Range of elements with value 1:" << std::endl;
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Use lower_bound to find the first element greater than or equal to a value
    auto lowerIt = myMultiSet.lower_bound(3);
    if (lowerIt != myMultiSet.end()) {
        std::cout << "Lower bound for 3: " << *lowerIt << std::endl;
    } else {
        std::cout << "No lower bound found for 3." << std::endl;
    }

    // Use upper_bound to find the first element greater than a value
    auto upperIt = myMultiSet.upper_bound(3);
    if (upperIt != myMultiSet.end()) {
        std::cout << "Upper bound for 3: " << *upperIt << std::endl;
    } else {
        std::cout << "No upper bound found for 3." << std::endl;
    }

    return 0;
}
