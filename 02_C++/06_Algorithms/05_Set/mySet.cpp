#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    // Create sorted sets
    std::vector<int> set1 = {1, 2, 3, 5, 7};
    std::vector<int> set2 = {3, 4, 5, 6, 8};

    // Merge the sets
    std::vector<int> mergedSet(set1.size() + set2.size());
    std::merge(set1.begin(), set1.end(), set2.begin(), set2.end(), mergedSet.begin());

    // Compute the union of the sets
    std::vector<int> unionSet(set1.size() + set2.size());
    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), unionSet.begin());

    // Compute the intersection of the sets
    std::vector<int> intersectionSet(std::min(set1.size(), set2.size()));
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), intersectionSet.begin());

    // Compute the difference between the sets
    std::vector<int> differenceSet(set1.size());
    std::set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), differenceSet.begin());

    // Compute the symmetric difference between the sets
    std::vector<int> symmetricDifferenceSet(set1.size() + set2.size());
    std::set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), symmetricDifferenceSet.begin());

    // Output the results
    std::cout << "Merged Set: ";
    for (int num : mergedSet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Union Set: ";
    for (int num : unionSet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Intersection Set: ";
    for (int num : intersectionSet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Difference Set: ";
    for (int num : differenceSet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Symmetric Difference Set: ";
    for (int num : symmetricDifferenceSet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
