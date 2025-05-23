//
// Created by robotics on 4/28/25.
//

template <typename T>
class StackByLinkedList : public Stack<T> {
private:
    SinglyLinkedList<T> list;

public:
    void push(T* value) override {
        // TODO: Implement the push method using
        // the appropriate linked list method
        list.insertAtHead(value);
    }

    T* pop() override {
        // TODO: Implement the pop method using
        // the appropriate linked list method
        return list.removeFromHead();
    }

    T* peek() const override {
        // TODO: Implement the peek method using
        // the appropriate linked list method
        return list.peekHead();
    }

    bool isEmpty() const override {
        // TODO: Implement the isEmpty method using
        // the appropriate linked list method
        return list.isEmpty();
    }
};
