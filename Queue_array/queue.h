//
// Created by robotics on 4/28/25.
//
#ifndef QUEUE_
#define QUEUE_

#include <stdexcept>

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
class QueueByArray : public Queue<T> {
private:
    T** array;    // Array to store pointers to elements
    int capacity; // Maximum capacity of the queue
    int front;    // Index of the front element
    int rear;     // Index of the rear element

public:
    QueueByArray(int capacityVal = 10)
            : capacity(capacityVal), front(0), rear(-1) {
        array = new T*[capacity];
    }

    ~QueueByArray() {
        delete[] array;
    }

    // Add an element to the queue
    void enqueue(T* value) override {
        if (rear + 1 == capacity) {
            throw std::out_of_range("Queue overflow");
        }
        array[++rear] = value;
    }

    // Remove and return the front element
    T* dequeue() override {
        if (isEmpty()) {
            throw std::out_of_range("Queue underflow");
        }

        T* value = array[front]; // Store the front element to return
        // Shift all elements one position toward the start
        for (int i = front; i < rear; ++i) {
            array[i] = array[i + 1];
        }
        --rear; // Adjust rear after shifting elements
        return value;
    }

    // Peek at the front element without removing it
    T* peek() const override {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return array[front];
    }

    // Check if the queue is empty
    bool isEmpty() const override {
        return front > rear;
    }
};

#endif // QUEUE_
