//
// Created by robotics on 7/10/25.
//

#include <iostream>
#include <vector>


class Node{
public:
    int data;
    Node* next;

    Node(int data_):data(data_),next(nullptr){

    }

};


class SinglyLinkedList{

protected:
    Node* head;
    int size;

public:
    SinglyLinkedList():head(nullptr),size(0){

    }

    ~SinglyLinkedList(){
        Node* current = head;
        while(current!= nullptr){
            Node* next = current-> next;
            delete current;
            current = next;
        }
    }

    void insert(int element){
        Node* newNode = new Node(element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    bool search(int element){
        Node* current = head;
        bool val = false;
        while(current!= nullptr){
            if(current->data ==element){
                return true;
            }
            current = current->next;
        }
    }

    void remove(int value) {
        Node* current = head;
        Node* prev = nullptr;

        while(current!=nullptr){
            if(current->data == value){

                if(current == head){
                    head = current->next;
                }
                else{
                    prev->next = current->next;
                }
                delete current;
                size --;
                return;
            }
            prev = current;
            current = current->next;
        }

    }

    void PrintList(){
        Node* current = head;
        while(current!=nullptr){
            std::cout<<current->data<<std::endl;
            current = current->next;
        }
    }

    int getSize(){
        return size;
    }

};

int main() {
    // TODO: Study how the Linked List is instantiated with the int type
    // Create a singly linked list to store integers
    SinglyLinkedList list;

    // TODO: Study how integer elements are added to the list.
    // Note that since the list is templated, an integer class (not primitive int
    // type) is used. Insert elements into the list
    list.insert(10);  // Insert 10
    list.insert(20);  // Insert 20
    list.insert(30);  // Insert 30

    // Print the list after insertions
    std::cout << "Linked List after insertions:" << std::endl;
    list.PrintList();

    // Remove an element (20) from the list
    list.remove(20);
    std::cout << "Linked List size after removing 20 is " << list.getSize()
              << " and contents are: " << std::endl;
    list.PrintList();

    // Search for an element (10) in the list
    if (list.search(10) != false) {
        std::cout << "Node with value 10 found in the list." << std::endl;
    } else {
        std::cout << "Node with value 10 not found." << std::endl;
    }

    return 0;
}
