#include <iostream>
#include <map>

int main() {
    // Create an ordered std::multimap with some initial key-value pairs
    std::multimap<int, std::string> myMultiMap;
    myMultiMap.insert({3, "Three"});
    myMultiMap.emplace(1, "One");
    myMultiMap.insert({2, "Two"});
    myMultiMap.emplace(4, "Four");
    myMultiMap.insert({2, "Another Two"}); // Duplicates with the same key are allowed

    // Access elements using iterators
    std::cout << "Elements in the multimap:" << std::endl;
    for (const auto& pair : myMultiMap) {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    std::cout << std::endl;

    // Erase elements by key
    int keyToRemove = 2;
    myMultiMap.erase(keyToRemove); // Remove all key-value pairs with the specified key
    for (const auto& pair : myMultiMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
    // Find elements by key
    int keyToFind = 1;
    auto it = myMultiMap.find(keyToFind); // Find the first element with the specified key
    if (it != myMultiMap.end()) {
        std::cout << "Found: (" << it->first << ", " << it->second << ")" << std::endl;
    } else {
        std::cout << "Key " << keyToFind << " not found." << std::endl;
    }

    // Count the number of occurrences of a key
    int keyToCount = 3;
    int count = myMultiMap.count(keyToCount); // Count the number of key-value pairs with the specified key
    std::cout << "Number of occurrences of key " << keyToCount << ": " << count << std::endl;

    // Use equal_range to find a range of key-value pairs with a specific key
    auto range = myMultiMap.equal_range(3);
    std::cout << "Range of key-value pairs with key 3:" << std::endl;
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;

    // Use lower_bound to find the first key-value pair greater than or equal to a key
    int keyToFindLowerBound = 2;
    auto lowerIt = myMultiMap.lower_bound(keyToFindLowerBound);
    if (lowerIt != myMultiMap.end()) {
        std::cout << "Lower bound for key " << keyToFindLowerBound << ": (" << lowerIt->first << ", " << lowerIt->second << ")" << std::endl;
    } else {
        std::cout << "No lower bound found for key " << keyToFindLowerBound << "." << std::endl;
    }

    // Use upper_bound to find the first key-value pair greater than a key
    int keyToFindUpperBound = 2;
    auto upperIt = myMultiMap.upper_bound(keyToFindUpperBound);
    if (upperIt != myMultiMap.end()) {
        std::cout << "Upper bound for key " << keyToFindUpperBound << ": (" << upperIt->first << ", " << upperIt->second << ")" << std::endl;
    } else {
        std::cout << "No upper bound found for key " << keyToFindUpperBound << "." << std::endl;
    }

    return 0;
}
