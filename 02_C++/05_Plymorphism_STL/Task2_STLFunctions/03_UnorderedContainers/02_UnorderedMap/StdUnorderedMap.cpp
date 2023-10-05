#include <iostream>
#include <unordered_map>

int main() {
    // Create an unordered map with some initial key-value pairs
    std::unordered_map<int, std::string> myUnorderedMap;
    myUnorderedMap.insert({3, "Three"});
    myUnorderedMap.emplace(1, "One");
    myUnorderedMap.insert({2, "Two"});
    myUnorderedMap.emplace(4, "Four");
    myUnorderedMap.insert({2, "Another Two"}); // Duplicates with the same key are not allowed

    // Access elements using iterators
    std::cout << "Elements in the unordered map:" << std::endl;
    for (const auto& pair : myUnorderedMap) {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    std::cout << std::endl;

    // Erase elements by key
    int keyToRemove = 2;
    myUnorderedMap.erase(keyToRemove); // Remove key-value pairs with key 2

    // Find elements by key
    int keyToFind = 1;
    auto it = myUnorderedMap.find(keyToFind); // Find element with key 1
    if (it != myUnorderedMap.end()) {
        std::cout << "Found: (" << it->first << ", " << it->second << ")" << std::endl;
    } else {
        std::cout << "Key " << keyToFind << " not found." << std::endl;
    }

    // Count the number of occurrences of a key
    int keyToCount = 3;
    int count = myUnorderedMap.count(keyToCount); // Count occurrences of key 3
    std::cout << "Number of occurrences of key " << keyToCount << ": " << count << std::endl;

    // Access bucket information
    size_t bucketCount = myUnorderedMap.bucket_count();
    std::cout << "Number of buckets: " << bucketCount << std::endl;

    // Iterate through the buckets and print bucket sizes
    std::cout << "Bucket sizes:" << std::endl;
    for (size_t i = 0; i < bucketCount; ++i) {
        std::cout << "Bucket " << i << ": " << myUnorderedMap.bucket_size(i) << " elements" << std::endl;
    }

    // Get the hash function
    std::hash<int> hashFunction = myUnorderedMap.hash_function();
    std::cout << "Hash value of 3: " << hashFunction(3) << std::endl;

    return 0;
}
