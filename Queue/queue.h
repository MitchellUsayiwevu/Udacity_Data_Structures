//
// Created by robotics on 4/28/25.
//

#ifndef QUEUE_
#define QUEUE_

#include "doubly_linked_list.h"

template <typename T>
class Queue {
public:
    virtual void enqueue(T* value) = 0;
    virtual T* dequeue() = 0;
    virtual T* peek() const = 0;
    virtual bool isEmpty() const = 0;
    virtual ~Queue() {}
};

template <typename T>
class QueueByLinkedList : public Queue<T> {
private:
    DoublyLinkedList<T> list;

public:
    void enqueue(T* value) override {
        // TODO: Implement the enqueue method using
        // the appropriate linked list method
        list.insertAtTail(value);
    }

    T* dequeue() override {
        // TODO: Implement the dequeue method using
        // the appropriate linked list method

        // replace this return with the actual implementation
        return list.removeFromHead();
    }

    T* peek() const override {
        // TODO: Implement the peek method using
        // the appropriate linked list method

        // replace this return with the actual implementation
        return list.peekHead();
    }

    bool isEmpty() const override {
        // TODO: Implement isEmpty enqueue method using
        // the appropriate linked list method

        // replace this return with the actual implementation
        return list.isEmpty();
    }
};

#endif // QUEUE_

