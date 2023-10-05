#include <iostream>
#include <unordered_set>

int main() {
    // Create an unordered set with some initial values
    std::unordered_set<int> myUnorderedSet;
    myUnorderedSet.insert(3);
    myUnorderedSet.emplace(1);
    myUnorderedSet.insert(2);
    myUnorderedSet.emplace(4);
    myUnorderedSet.insert(2); // Duplicates are not allowed

    // Access elements using iterators
    std::cout << "Elements in the unordered set:" << std::endl;
    for (const auto& value : myUnorderedSet) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Erase elements by value
    myUnorderedSet.erase(2); // Remove value 2

    // Find elements by value
    int keyToFind = 1;
    auto it = myUnorderedSet.find(keyToFind); // Find element with value 1
    if (it != myUnorderedSet.end()) {
        std::cout << "Found: " << *it << std::endl;
    } else {
        std::cout << "Value " << keyToFind << " not found." << std::endl;
    }

    // Count the number of occurrences of a value
    int keyToCount = 3;
    int count = myUnorderedSet.count(keyToCount); // Count occurrences of value 3
    std::cout << "Number of occurrences of " << keyToCount << ": " << count << std::endl;

    // Access bucket information
    size_t bucketCount = myUnorderedSet.bucket_count();
    std::cout << "Number of buckets: " << bucketCount << std::endl;

    // Iterate through the buckets and print bucket sizes
    std::cout << "Bucket sizes:" << std::endl;
    for (size_t i = 0; i < bucketCount; ++i) {
        std::cout << "Bucket " << i << ": " << myUnorderedSet.bucket_size(i) << " elements" << std::endl;
    }

    // Get the hash function
    std::hash<int> hashFunction = myUnorderedSet.hash_function();
    std::cout << "Hash value of 3: " << hashFunction(3) << std::endl;

    return 0;
}
