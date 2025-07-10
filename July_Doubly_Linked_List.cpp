//
// Created by robotics on 7/10/25.
//

#include <iostream>

class Node{
public:
    Node* next;
    Node* prev;
    int data;

    Node(int data_):data(data_),next(nullptr),prev(nullptr){

    }
};

class DoublyLinkedList{

public:
    DoublyLinkedList();
    void InsertFront(int value);
    void InsertBack(int value);
    void RemoveBack();
    void RemoveFront();
    bool search(int value);
    void printList();
    void getSize();

protected:
    Node* head;
    Node* tail;
    int size;
};

DoublyLinkedList::DoublyLinkedList():head(nullptr),tail(nullptr),size(0){

}

void DoublyLinkedList::InsertFront(int value){
    //empty list
    Node* newNode = new Node(value);
    Node* current = head;

    if (head == tail == nullptr){

        head = newNode;
        tail = newNode;
        size ++;
        return;
    }

    // one element in the list

    if(head== tail){
        head =  newNode;
        head->next = tail;
        size ++;
        return;
    }

    //more than one element in the list
    head = newNode;
    head->next = current;
    size ++;
    return;

}

void DoublyLinkedList::InsertBack(int value){

}

void DoublyLinkedList::RemoveBack(){

}

void DoublyLinkedList::RemoveFront(){

}
bool DoublyLinkedList::search(int value){

}

void DoublyLinkedList::printList(){

}
void DoublyLinkedList::getSize(){

}