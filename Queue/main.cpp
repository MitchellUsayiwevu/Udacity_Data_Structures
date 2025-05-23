//
// Created by robotics on 4/28/25.
//

#include <iostream>

#include "queue.h"

int main() {
    // Testing QueueByLinkedList
    QueueByLinkedList<int> queue;

    // Check if the queue is empty
    std::cout << "Queue isEmpty: "
              << (queue.isEmpty() ? "True" : "False") << std::endl;

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

    // Check if the queue is empty
    std::cout << "Queue isEmpty: "
              << (queue.isEmpty() ? "True" : "False") << std::endl;

    // Dequeue an element and print it
    auto dequeued = queue.dequeue();
    if (dequeued != nullptr) {
        std::cout << "Dequeued element: " << *dequeued << std::endl;
        delete dequeued;  // Manually delete the dequeued element to free memory
    } else {
        std::cout << "No element to dequeue. Queue might be empty." << std::endl;
    }

    // Peek again to see the front element after the dequeue
    auto newFront = queue.peek();
    if (newFront != nullptr) {
        std::cout << "Queue Front after dequeue: " << *newFront << std::endl;
    } else {
        std::cout << "Queue is empty. No front element." << std::endl;
    }

    return 0;
}
