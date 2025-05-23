//
// Created by robotics on 4/28/25.
//

template <typename T>
class QueueByLinkedList : public Queue<T> {
private:
    SinglyLinkedList<T> list;

public:
    void enqueue(T* value) override {
        // TODO: Implement the enqueue method using
        // the appropriate linked list method
        list.insertAtTail(value);
    }

    T* dequeue() override {
        // TODO: Implement the dequeue method using
        // the appropriate linked list method
        return list.removeFromHead();
    }

    T* peek() const override {
        // TODO: Implement the peek method using
        // the appropriate linked list method
        return list.peekHead();
    }

    bool isEmpty() const override {
        // TODO: Implement isEmpty enqueue method using
        // the appropriate linked list method
        return list.isEmpty();
    }
};
