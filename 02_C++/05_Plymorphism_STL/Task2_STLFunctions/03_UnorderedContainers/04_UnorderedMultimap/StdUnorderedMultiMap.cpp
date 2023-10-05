#include <iostream>
#include <unordered_map>

int main() {
    // Create an unordered multimap with some initial key-value pairs
    std::unordered_multimap<int, std::string> myUnorderedMultimap;
    myUnorderedMultimap.insert({3, "Three"});
    myUnorderedMultimap.emplace(1, "One");
    myUnorderedMultimap.insert({2, "Two"});
    myUnorderedMultimap.emplace(4, "Four");
    myUnorderedMultimap.insert({2, "Another Two"}); // Duplicates with the same key are allowed

    // Access elements using iterators
    std::cout << "Elements in the unordered multimap:" << std::endl;
    for (const auto& pair : myUnorderedMultimap) {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    std::cout << std::endl;

    // Erase elements by key
    int keyToRemove = 2;
    myUnorderedMultimap.erase(keyToRemove); // Remove key-value pairs with key 2

    // Find elements by key
    int keyToFind = 1;
    auto it = myUnorderedMultimap.find(keyToFind); // Find element with key 1
    if (it != myUnorderedMultimap.end()) {
        std::cout << "Found: (" << it->first << ", " << it->second << ")" << std::endl;
    } else {
        std::cout << "Key " << keyToFind << " not found." << std::endl;
    }

    // Access bucket information
    size_t bucketCount = myUnorderedMultimap.bucket_count();
    std::cout << "Number of buckets: " << bucketCount << std::endl;

    // Iterate through the buckets and print bucket sizes
    std::cout << "Bucket sizes:" << std::endl;
    for (size_t i = 0; i < bucketCount; ++i) {
        std::cout << "Bucket " << i << ": " << myUnorderedMultimap.bucket_size(i) << " elements" << std::endl;
    }

    // Get the hash function
    std::hash<int> hashFunction = myUnorderedMultimap.hash_function();
    std::cout << "Hash value of 3: " << hashFunction(3) << std::endl;

    return 0;
}
