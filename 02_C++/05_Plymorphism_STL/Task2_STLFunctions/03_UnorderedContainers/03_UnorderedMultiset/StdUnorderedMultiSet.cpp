#include <iostream>
#include <unordered_set>

int main() {
    // Create an unordered multiset with some initial values
    std::unordered_multiset<int> myUnorderedMultiset;
    myUnorderedMultiset.insert(3);
    myUnorderedMultiset.emplace(1);
    myUnorderedMultiset.insert(2);
    myUnorderedMultiset.emplace(4);
    myUnorderedMultiset.insert(2); // Duplicates are allowed in a multiset

    // Access elements using iterators
    std::cout << "Elements in the unordered multiset:" << std::endl;
    for (const auto& value : myUnorderedMultiset) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Erase elements by value
    myUnorderedMultiset.erase(2); // Remove value 2

    // Find elements by value
    int keyToFind = 1;
    auto it = myUnorderedMultiset.find(keyToFind); // Find element with value 1
    if (it != myUnorderedMultiset.end()) {
        std::cout << "Found: " << *it << std::endl;
    } else {
        std::cout << "Value " << keyToFind << " not found." << std::endl;
    }

    // Access bucket information
    size_t bucketCount = myUnorderedMultiset.bucket_count();
    std::cout << "Number of buckets: " << bucketCount << std::endl;

    // Iterate through the buckets and print bucket sizes
    std::cout << "Bucket sizes:" << std::endl;
    for (size_t i = 0; i < bucketCount; ++i) {
        std::cout << "Bucket " << i << ": " << myUnorderedMultiset.bucket_size(i) << " elements" << std::endl;
    }

    // Get the hash function
    std::hash<int> hashFunction = myUnorderedMultiset.hash_function();
    std::cout << "Hash value of 3: " << hashFunction(3) << std::endl;

    return 0;
}
