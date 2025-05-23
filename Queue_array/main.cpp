//
// Created by robotics on 4/28/25.
//

#include <iostream>

#include "queue.h"

int main() {
    // Testing QueueByArray
    QueueByArray<int> queue(2);

    // Check if the queue is empty
    std::cout << "Queue isEmpty: "
              << (queue.isEmpty() ? "True" : "False") << std::endl;

    try {
        queue.dequeue();
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Enqueue elements into the queue
    queue.enqueue(new int(10));
    queue.enqueue(new int(20));

    // Peek at the front element
    auto frontElement = queue.peek();
    if (frontElement != nullptr) {
        std::cout << "Queue Front: " << *frontElement << std::endl;
    } else {
        std::cout << "Queue is empty. No front element." << std::endl;
    }

    try {
        queue.enqueue(new int(30));
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    while (!queue.isEmpty()) {
        // Dequeue an element and print it
        auto dequeued = queue.dequeue();
        if (dequeued != nullptr) {
            std::cout << "Dequeued element: " << *dequeued << std::endl;
            delete dequeued;  // Manually delete the dequeued element to free memory
        } else {
            std::cout << "No element to dequeue. Queue might be empty." << std::endl;
            break;  // Break out of the loop if dequeue fails
        }

        // Print the new front element if the queue is not empty
        if (!queue.isEmpty()) {
            auto front = queue.peek();
            if (front != nullptr) {
                std::cout << "New front element: " << *front << std::endl;
            }
        } else {
            std::cout << "Queue is empty" << std::endl;
        }
    }

    return 0;
}

