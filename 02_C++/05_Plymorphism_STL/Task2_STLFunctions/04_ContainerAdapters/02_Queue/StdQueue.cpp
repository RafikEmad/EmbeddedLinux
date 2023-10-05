#include <iostream>
#include <queue>

int main() {
    std::queue<std::string> todoList;

    // Add tasks to the to-do list
    todoList.push("Task 1");
    todoList.push("Task 2");
    todoList.push("Task 3");

    // Process tasks from the to-do list
    while (!todoList.empty()) {
        std::cout << "Processing: " << todoList.front() << std::endl;
        todoList.pop(); // Remove the front task
    }

    return 0;
}
