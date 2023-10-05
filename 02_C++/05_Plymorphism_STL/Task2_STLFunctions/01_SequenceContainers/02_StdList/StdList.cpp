#include <iostream>
#include <list>

template <typename T>
void printList(const std::list<T>& list1) {
    for (const auto& value : list1) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Initialization and Capacity
    std::cout << "==============Initialization and Capacity=============="<<std::endl;
    // Create an empty vector of integers
    std::list<int> myList;
    myList.push_back(30);
    myList.push_back(20);
    myList.push_back(10);
    myList.push_back(10);

    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);
    printList(myList);
    // Get the number of elements in the vector
    std::cout << "List size: " << myList.size() << std::endl;

    if (!myList.empty()) {std::cout<< "List is not empty" << std::endl;}

    // Element Access
    std::cout << "==============Element Access=============="<<std::endl;
    // Access the first and last elements
    std::cout << "First element: " << myList.front() << std::endl;
    std::cout << "Last element: " << myList.back() << std::endl;

    // Modifiers
    std::cout << "==============Modifiers=============="<<std::endl;
    myList.push_front(0);
    printList(myList);
    // Remove the first and last elements
    myList.pop_front();
    myList.pop_back();
    printList(myList);
    // Insert an element at a specified position
    std::list<int>::iterator it1 = myList.begin();
    myList.insert(++it1, 10);
    printList(myList);
    // Remove an element at a specified position
    myList.erase(it1);
    printList(myList);
    // Remove consecutive duplicate elements
    myList.unique();
    printList(myList);
    // Reverse the list
    myList.reverse();
    printList(myList);
    // Sort the list
    myList.sort();
    printList(myList);

    // Create two lists
    std::list<int> myList1 = {1, 3, 5};
    std::list<int> myList2 = {2, 4, 6};

    // Display the initial contents of both lists
    std::cout << "Initial myList1:";
    printList(myList1);
    std::cout << "Initial myList2:";
    printList(myList2);

    // Merge myList2 into myList1 (assuming both lists are sorted)
    myList1.merge(myList2);

    // Display the merged list
    std::cout << "Merged myList1:";
    printList(myList1);

    // Create a third list
    std::list<int> myList3 = {7, 8, 9};

    // Display the initial contents of myList3
    std::cout << "Initial myList3:";
    printList(myList3);

    // Splice elements from myList1 into myList3 at a specific position
    std::list<int>::iterator it = myList1.begin();
    std::advance(it, 2); // Advance iterator to the third element in myList1
    myList3.splice(myList3.begin(), myList1, myList1.begin(), it);

    // Display the result of the splice operation
    std::cout << "myList1 after splice:";
    printList(myList1);

    std::cout << "myList3 after splice:";
    printList(myList3);

    return 0;
}
