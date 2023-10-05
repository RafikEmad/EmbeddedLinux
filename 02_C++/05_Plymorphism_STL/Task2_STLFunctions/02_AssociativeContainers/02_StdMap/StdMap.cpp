#include <iostream>
#include <map>

int main() {
    // Create an ordered std::map with some initial key-value pairs
    std::map<int, std::string> myMap;
    myMap.insert(std::make_pair(3, "Three"));
    myMap.emplace(1, "One");
    myMap[2] = "Two";
    myMap.emplace_hint(myMap.begin(), 4, "Four");

    // Access elements
    std::cout << "Value associated with key 2: " << myMap[2] << std::endl;
    if (!myMap.empty()) {std::cout << "myMap not empty" << std::endl;}
    // Iterate over elements
    std::cout << "Iterating over elements:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    // Access elements with at() (with bounds checking)
    try {
        std::cout << "Value associated with key 2: " << myMap.at(2) << std::endl;
        std::cout << "Value associated with key 5: " << myMap.at(5) << std::endl; // Uncomment to see the exception
    } catch (const std::out_of_range& e) {
        std::cerr << "Key not found: " << e.what() << std::endl;
    }

    // Find elements using lower_bound and upper_bound
    int searchKey = 2;

    // lower_bound finds the first element greater than or equal to searchKey
    auto lowerIt = myMap.lower_bound(searchKey);
    if (lowerIt != myMap.end()) {
        std::cout << "Lower bound for key " << searchKey << ": ";
        std::cout << "Key: " << lowerIt->first << ", Value: " << lowerIt->second << std::endl;
    } else {
        std::cout << "No lower bound found for key " << searchKey << std::endl;
    }

    // upper_bound finds the first element greater than searchKey
    auto upperIt = myMap.upper_bound(searchKey);
    if (upperIt != myMap.end()) {
        std::cout << "Upper bound for key " << searchKey << ": ";
        std::cout << "Key: " << upperIt->first << ", Value: " << upperIt->second << std::endl;
    } else {
        std::cout << "No upper bound found for key " << searchKey << std::endl;
    }
    
    // Use key_comp to access the key comparison function
    std::map<int, std::string>::key_compare keyComparator = myMap.key_comp();
    std::cout << "Key comparison function result:" << std::endl;
    bool result = keyComparator(1, 2); // Compare keys 1 and 2
    std::cout << "Is key 1 less than key 2? " << result << std::endl;

    // Use value_comp to access the value comparison function
    std::map<int, std::string>::value_compare valueComparator = myMap.value_comp();
    std::cout << "Value comparison function result:" << std::endl;
    result = valueComparator(*myMap.begin(), *myMap.rbegin()); // Compare the first and last elements by value
    std::cout << "Is the first value less than the last value? " << result << std::endl;

    // Insert a new key-value pair into the map using emplace
    myMap.emplace(5, "Five");

    // Print the updated map
    std::cout << "Updated map after insertion:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }


    // Erase an element by key
    myMap.erase(3);
    
    // Find an element by key
    auto it = myMap.find(2);
    if (it != myMap.end()) {
        std::cout << "Found: Key: " << it->first << ", Value: " << it->second << std::endl;
    } else {
        std::cout << "Key 2 not found." << std::endl;
    }

    myMap.clear();
    std::cout << "MyMap size after clear: " << myMap.size() << std::endl;

    return 0;
}
