//
// Created by robotics on 4/28/25.
//

#ifndef STACK_
#define STACK_

#include "singly_linked_list.h"

template <typename T>
class Stack {
public:
    virtual void push(T* value) = 0;
    virtual T* pop() = 0;
    virtual T* peek() const = 0;
    virtual bool isEmpty() const = 0;
    virtual ~Stack() {}
};

template <typename T>
class StackByLinkedList : public Stack<T> {
private:
    DoublyLinkedList<T> list;

public:
    void push(T* value) override {
        // TODO: Implement the push method using
        // the appropriate linked list method
        list.insertAtHead(value);
    }

    T* pop() override {
        // TODO: Implement the pop method using
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
        // TODO: Implement the isEmpty method using
        // the appropriate linked list method

        // replace this return with the actual implementation
        return list.isEmpty() ;
    }
};

#endif // STACK_
