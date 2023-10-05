#include <iostream>
#include <deque>

int main() {
    // Initialization and Capacity

    std::deque<int> deq;

    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);
    deq.push_back(4);

    std::cout << "Deque size: " << deq.size() << std::endl;

    if (deq.empty()) {
        std::cout << "Deque is empty." << std::endl;
    }

    // Element Access

    std::cout << "First element: " << deq.front() << std::endl;
    std::cout << "Last element: " << deq.back() << std::endl;

    // Modifiers

    deq.push_front(0);
    deq.pop_front();
    deq.pop_back();

    std::deque<int>::iterator it = deq.begin();
    ++it;
    deq.insert(it, 10);

    deq.erase(it);

    std::cout << "Deque elements:";
    for (const auto& value : deq) {
        std::cout << " " << value;
    }
    std::cout << std::endl;

    // Other Operations

    std::deque<int> anotherDeq = {5, 6, 7};

    deq.swap(anotherDeq);

    std::cout << "Swapped deq elements:";
    for (const auto& value : deq) {
        std::cout << " " << value;
    }
    std::cout << std::endl;

    deq.emplace_back(42);
    deq.emplace_front(99);

    std::cout << "Emplaced elements:";
    for (const auto& value : deq) {
        std::cout << " " << value;
    }
    std::cout << std::endl;

    return 0;
}
