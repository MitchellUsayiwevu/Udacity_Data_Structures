//
// Created by robotics on 4/28/25.
//

#include <iostream>

#include "circular_buffer.h"

int main() {
    // TODO: Create a CircularBuffer instance called buffer,
    // with the capacity of 3
    CircularBuffer<int> buffer(3);

    // TODO: Add integer values 1, 2 and 3 to the buffer
    // Add some integers
    buffer.add(new int(1));
    buffer.add(new int(2));
    buffer.add(new int(3));

    // TODO: Check if the buffer is full or not, then print the result
    std::cout << "Is full: " << (buffer.isFull() ? "Yes" : "No") << std::endl;

    // TODO: Peek at the current head of the buffer and print it.
    // What do you think the value would be?
    std::cout << "Peek: " << *(buffer.peek()) << std::endl;

    // TODO: Add integer 4 to the buffer and
    // what do you think is going to happen?
    buffer.add(new int(4));

    // TODO: Peek at the current head and print it
    std::cout << "Peek after adding 4: " << *(buffer.peek()) << std::endl;

    // TODO: Write a loop that continues running when the buffer
    // is not empty. Then, on each iteration, the loop removes
    // buffer elements one by one. After removal, do not forget to
    // delete the returned pointer
    // Also, count and print the total number of elements removed
    unsigned int n = 0;
    while (buffer.isEmpty() == false) {
        ++n;
        int* item = buffer.remove();
        if (item) {
            std::cout << "Removed: " << *item << std::endl;
            delete item;  // Free the removed item
        }
    }
    std::cout << "Empty after removing " << n << " elements." << std::endl;

    return 0;
}