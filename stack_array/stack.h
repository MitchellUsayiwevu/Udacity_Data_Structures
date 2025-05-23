//
// Created by robotics on 4/28/25.
//
#ifndef STACK_
#define STACK_

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
class StackByArray : public Stack<T> {
private:
    T** array;         // Pointer to the array of pointers to T
    int capacity;      // Current capacity of the array
    int top;           // Index of the top element

public:
    StackByArray(int capacityVal=10) : capacity(capacityVal), top(-1) {
        array = new T*[capacity];
    }

    ~StackByArray() {
        delete[] array;
    }

    void push(T* value) override {
        if (top + 1 == capacity) {
            throw std::out_of_range("Stack overflow");
        }
        array[++top] = value;
    }

    T* pop() override {
        if (isEmpty()) {
            throw std::out_of_range("Stack underflow");
        }
        return array[top--];
    }

    T* peek() const override {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        return array[top];
    }

    bool isEmpty() const override {
        return top == -1;
    }
};

#endif // STACK_