//
// Created by robotics on 4/28/25.
//

#include <iostream>

// Templated DoubleNode class to hold data of any type (does not own data)
template <typename T>
class DoubleNode {
public:
    T* data;  // Pointer to the data (raw pointer, not owned)
    DoubleNode* next;
    DoubleNode* prev;

    // Constructor to initialize the node with data (raw pointer)
    DoubleNode(T* dataValue) : data(dataValue), next(nullptr), prev(nullptr) {}
};

// Templated Doubly Linked List class
template <typename T>
class DoublyLinkedList {
public:
    // Constructor to initialize an empty list
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor to clean up the entire linked list (nodes only)
    virtual ~DoublyLinkedList() {
        DoubleNode<T>* current = head;
        while (current != nullptr) {
            DoubleNode<T>* next = current->next;
            delete current;  // Delete the node (data is not owned, not deleted)
            current = next;
        }
    }

    // Insert a new node at the head of the list
    void insertToHead(T* value) {
        DoubleNode<T>* newNode = new DoubleNode<T>(value);
        if (head == nullptr) {    // If the list is empty
            head = tail = newNode;  // The new node becomes both head and tail
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        ++size;
    }

    // Insert a new node at the tail of the list
    void insertToTail(T* value) {
        // TODO: Study the insertToHead code and implement the
        // insertToTail accordingly
        DoubleNode<T>* newNode = new DoubleNode<T>(value);
        if (tail == nullptr) {  // If the list is empty
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++size;
    }

    // Remove and return the payload (data) of the node at the head
    T* removeFromHead() {
        if (head == nullptr) return nullptr;  // Empty list case
        DoubleNode<T>* temp = head;
        T* value = temp->data;  // Get the raw pointer to the data
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;  // If the list is now empty, set tail to nullptr
        }
        delete temp;  // Free the node memory (not the data)
        --size;
        return value;  // Return the raw pointer to the removed data
    }

    // Remove and return the payload (data) of the node at the tail
    T* removeFromTail() {
        // TODO: Study the removeFromHead code and implement the
        // removeFromTail accordingly
        if (tail == nullptr) return nullptr;  // Empty list case
        DoubleNode<T>* temp = tail;
        T* value = temp->data;  // Get the raw pointer to the data
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;  // If the list is now empty, set head to nullptr
        }
        delete temp;  // Free the node memory (not the data)
        --size;
        return value;  // Return the raw pointer to the removed data
    }

    // Print all nodes in the list
    void printList() const {
        DoubleNode<T>* current = head;
        while (current != nullptr) {
            std::cout << "Node with value: " << *(current->data) << std::endl;
            current = current->next;
        }
    }

    DoubleNode<T>* search(const T& value) const {
        DoubleNode<T>* current = head;  // Start from the head of the list

        // Traverse the list
        while (current != nullptr) {
            // Compare the data at the current node with the provided value
            if (*(current->data) == value) {
                return current;  // Return the matching node
            }
            current = current->next;  // Move to the next node
        }

        return nullptr;  // Return nullptr if no match is found
    }

    // Get the size of the list
    size_t getSize() const { return size; }

private:
    DoubleNode<T>* head;  // Pointer to the first node (head) of the list
    DoubleNode<T>* tail;  // Pointer to the last node (tail) of the list
    size_t size;          // Size of the list (number of nodes)
};

// Example usage
int main() {
    DoublyLinkedList<int> list;

    // Insert elements into the list
    list.insertToHead(new int(20));  // Insert 20 at head
    list.insertToHead(new int(10));  // Insert 10 at head
    list.insertToTail(new int(30));  // Insert 30 at tail

    // TODO: Look at the insertion order of elements above
    // and see if the order of elements printed below
    // match your expectation
    // Print the list after insertions
    std::cout << "Doubly Linked List after insertions:" << std::endl;
    list.printList();

    // Remove and print elements from the head and tail
    int* removedHead = list.removeFromHead();
    if (removedHead) {
        std::cout << "\nRemoved from head: " << *removedHead << std::endl;
        delete removedHead;  // Manually delete the removed data
        removedHead = nullptr;
    }

    // Print the list after removals
    std::cout << "Doubly Linked List after remove from head:" << std::endl;
    list.printList();

    int* removedTail = list.removeFromTail();
    if (removedTail) {
        std::cout << "\nRemoved from tail: " << *removedTail << std::endl;
        delete removedTail;  // Manually delete the removed data
        removedTail = nullptr;
    }

    // Print the list after removals
    std::cout << "Doubly Linked List after remove from tail:" << std::endl;
    list.printList();

    return 0;
}
