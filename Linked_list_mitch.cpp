//
// Created by diso on 6/2/25.
// To do Implement LinkedLists with smart pointers

#include <iostream>

template <typename T>
class Node{
public:
 T data;
 Node* next;

 Node(T value):data(value),next(nullptr){}

};

template <typename T>
class SinglyLinkedList{
private:
Node<T>* head;
int size;

public:
SinglyLinkedList(){
  head = nullptr;
  size = 0;
}

~SinglyLinkedList(){
    Node<T>* curr = head;
        while(curr!=nullptr){
            Node<T>* temp = curr->next;
            std::cout<<"Deleted node: "<<curr->data<<std::endl;
            delete curr;
            curr = temp;
        }
}
void insert(T data);
void remove(T data);
void print();
};

template<typename T>
void SinglyLinkedList<T>::insert(T data){    /// insert from the front
    if(head==nullptr){     /// no elements on the list yet
        Node<T>* n = new Node<T>(data);
        head = n;
        size++;
        return;
    }
    ///
    Node<T>* temp = new Node<T>(data);
    temp->next = head;
    head = temp;
    size++;

}

template<typename T>
void SinglyLinkedList<T>::remove(T data){
    if (size ==0){   // if list is empty return
        return;
    }

    Node<T>* curr = head;
    Node<T>* prev = nullptr;

    if(head->data == data){
        head = head->next;
        delete curr;
        size--;
        return;
    }
    while(curr!=nullptr){
        if(curr->data == data){
            prev->next = curr->next;
            delete curr;
            size--;
            return;
        }
        prev = curr;
        curr = curr->next;

}


}

template<typename T>
void SinglyLinkedList<T>::print(){
    Node<T>* current = head;
    if(head!=nullptr){
        while(current!=nullptr){
            std::cout<<"List Element: "<<current->data<<std::endl;
            current = current->next;
        }
    }
}

int main(){

    SinglyLinkedList<int> myList;
    myList.insert(5);
    myList.insert(4);
    myList.insert(3);
    myList.print();
    myList.remove(5);
    myList.print();
    return 0;

}
