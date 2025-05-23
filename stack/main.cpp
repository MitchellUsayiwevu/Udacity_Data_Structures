//
// Created by robotics on 4/28/25.
//

#include <iostream>

#include "stack.h"

int main() {
    // Testing StackByLinkedList
    StackByLinkedList<int> stack;
    std::cout << "Stack isEmpty: "
              << (stack.isEmpty() ? "True" : "False") << std::endl;
    stack.push(new int(10));
    stack.push(new int(20));

    auto topElement = stack.peek();  // Store the pointer returned by peek()
    if (topElement != nullptr) {
        std::cout << "Stack Top: " << *topElement << std::endl;
    } else {
        std::cout << "Stack is empty. No top element." << std::endl;
    }

    std::cout << "Stack isEmpty: "
              << (stack.isEmpty() ? "True" : "False") << std::endl;

    auto popped = stack.pop();  // Manually delete the popped element
    if (popped != nullptr) {
        std::cout << "Popped element: " << *popped << std::endl;
        delete popped;  // Don't forget to free memory if it's a dynamically allocated element
    } else {
        std::cout << "No element to pop. Stack might be empty." << std::endl;
    }

    auto newTop = stack.peek();  // Store the pointer returned by peek()
    if (newTop != nullptr) {
        std::cout << "Stack Top after pop: " << *newTop << std::endl;
    } else {
        std::cout << "Stack is empty. No top element." << std::endl;
    }

    return 0;
}
