#include <iostream>
#include <set>

class MyType {
public:
    MyType(int x, double y) : a(x), b(y) {}

    bool operator<(const MyType& other) const {
        return a < other.a;
    }
    int getA() const {
        return a;
    }

    double getB() const {
        return b;
    }
private:
    int a;
    double b;
};

int main() {
    std::set<int> mySet;

    // Insert elements into the set
    mySet.insert(5);
    mySet.insert(2);
    mySet.insert(8);

    if(!mySet.empty())
    {
        std::cout << "Set is not empty." << std::endl; 
        std::cout << "Set size = " << mySet.size() << std::endl;
    }

    // Check if an element exists in the set
    if (mySet.find(5) != mySet.end()) {
        std::cout << "5 is in the set." << std::endl;
    }

    // Erase an element from the set
    mySet.erase(2);

    // Iterate through the set
    std::cout << "Set elements:";
    for (const auto& value : mySet) {
        std::cout << " " << value;
    }
    std::cout << std::endl;

    // Size of the set
    std::cout << "Set size: " << mySet.size() << std::endl;

    std::set<int> mySet1 = {1, 2, 3 ,4, 5};
    int key = 3;

    int count = mySet1.count(key);

    if (count == 1) {
        std::cout << "Key " << key << " is in the set." << std::endl;
    } else {
        std::cout << "Key " << key << " is not in the set." << std::endl;
    }

    auto it = mySet1.lower_bound(key);

    if (it != mySet1.end()) {
        std::cout << "Lower bound of " << key << " is " << *it << std::endl;
    } else {
        std::cout << "No lower bound found for " << key << std::endl;
    }

    auto it1 = mySet1.upper_bound(key);

    if (it1 != mySet1.end()) {
        std::cout << "Upper bound of " << key << " is " << *it1 << std::endl;
    } else {
        std::cout << "No upper bound found for " << key << std::endl;
    }

    std::set<int> mySet2 = {1, 3, 5};

    mySet2.emplace_hint(mySet2.begin(), 2);

    std::cout << "Elements in mySet:";
    for (const auto& element : mySet2) {
        std::cout << " " << element;
    }
    std::cout << std::endl;

    std::set<MyType> mySet4;

    mySet4.emplace(1, 2.5);
    mySet4.emplace(3, 4.2);

    std::cout << "Elements in mySet:";
    for (const auto& element : mySet4) {
        std::cout << " (" << element.getA() << ", " << element.getB() << ")";
    }
    std::cout << std::endl;

    return 0;
}

