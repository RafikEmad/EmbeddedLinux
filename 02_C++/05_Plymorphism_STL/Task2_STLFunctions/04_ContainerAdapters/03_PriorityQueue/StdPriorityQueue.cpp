#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> myPriorityQueue;

    // Add elements to the priority queue
    myPriorityQueue.push(5);
    myPriorityQueue.push(2);
    myPriorityQueue.push(8);

    // Access and remove the highest-priority element
    std::cout << "Highest Priority Element: " << myPriorityQueue.top() << std::endl;
    myPriorityQueue.pop();

    // Access and remove the next highest-priority element
    std::cout << "Highest Priority Element: " << myPriorityQueue.top() << std::endl;
    myPriorityQueue.pop();

    // Create a min-heap priority queue of integers
    std::priority_queue<int, std::vector<int>, std::greater<int>> myMinPriorityQueue;

    // Add elements to the min-heap
    myMinPriorityQueue.push(5);
    myMinPriorityQueue.push(2);
    myMinPriorityQueue.push(8);
    myMinPriorityQueue.push(1); // Adding the smallest value

    // Access and remove the highest-priority (lowest value) element
    std::cout << "Highest Priority Element (Min-Heap): " << myMinPriorityQueue.top() << std::endl;
    myMinPriorityQueue.pop();

    // Access and remove the next highest-priority element
    std::cout << "Highest Priority Element (Min-Heap): " << myMinPriorityQueue.top() << std::endl;
    myMinPriorityQueue.pop();

    return 0;
}
