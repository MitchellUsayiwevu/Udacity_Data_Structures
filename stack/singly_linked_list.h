//
// Created by robotics on 4/28/25.
//

#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

#include <stdexcept>

// Node structure for the doubly linked list
template <typename T>
struct Node {
    T* data;
    Node* next;

    Node(T* value) : data(value), next(nullptr) {}
};

// Doubly Linked List class that provides basic operations
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp->data;
            delete temp;
        }
    }

    // Insert at the head (useful for stack push operation)
    void insertAtHead(T* value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Insert at the tail (useful for queue enqueue operation)
    void insertAtTail(T* value) {
        Node<T>* newNode = new Node<T>(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Remove from the head (useful for both stack pop and queue dequeue)
    T* removeFromHead() {
        if (head == nullptr) {
            throw std::runtime_error("List is empty");
        }
        Node<T>* temp = head;
        T* data = temp->data;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;  // Reset tail if list is empty
        }
        delete temp;
        return data;
    }

    // Peek at the head (for stack peek operation)
    T* peekHead() const {
        if (head == nullptr) {
            throw std::runtime_error("List is empty");
        }
        return head->data;
    }

    // Check if the list is empty
    bool isEmpty() const {
        return head == nullptr;
    }
};

#endif // DOUBLY_LINKED_LIST_H_
