//
// Created by diso on 6/2/25.
//

#include <iostream>

template <typename T>
class DoubleNode{
public:
    T* data;
    DoubleNode<T>* next;
    DoubleNode<T>* prev;


    DoubleNode(T* newdata):data(newdata),next(nullptr),prev(nullptr){}
};

template <typename T>
class DoublyLinkedList{
    DoubleNode<T>* head;
    DoubleNode<T>* tail;
    int size;

public:
DoublyLinkedList():head(nullptr),tail(nullptr),size(0){}
void insertAtHead(T* newData);
void insertAtTail(T* newData);
T* removeFromHead();
T* removeFromTail();
void printList() const;

};

template <typename T>
void DoublyLinkedList<T>::insertAtHead(T* newData){
    DoubleNode<T>* newNode = new DoubleNode<T>(newData);

    if(head==nullptr){   /// empty list
       head = newNode;
       tail = newNode;
    } else{
         newNode->next= head;
         head->prev = newNode;
         head = newNode;
    }
    size++;
    return;

}

template <typename T>
void DoublyLinkedList<T>::insertAtTail(T* newData){
    DoubleNode<T>* newNode = new DoubleNode<T>(newData);
    if(tail==nullptr){    ///empty list
        tail = newNode;
        head = newNode;
    }else{
        tail->next= newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
    return;
}

template <typename T>
T* DoublyLinkedList<T>::removeFromHead(){

    if(head==nullptr){       // empty list
        return nullptr;
    }

    DoubleNode<T>* temp = head;
    T* value = temp->data;

    if(temp->next == nullptr){ /// one element in the list
        tail = nullptr;
        head = nullptr;
    }else{
        head = head->next;
        head->prev = nullptr;
    }
    size--;
    delete temp;
    return value;
}

template <typename T>
T* DoublyLinkedList<T>::removeFromTail(){
    if(tail==nullptr){   //empy list
        return nullptr;
    }

    DoubleNode<T>* temp = tail;
    T* value  = tail->data;

    if(tail->prev ==nullptr){   /// one lement in the list
        tail = nullptr;
        head = nullptr;
    } else{                         /// more than one element in the list
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    size--;
    return value;
}

template <typename T>
void DoublyLinkedList<T>::printList() const{
    DoubleNode<T>* current = head;

    while(current!=nullptr){
        T* data = current->data;
        std::cout<<"List Element: "<< *data <<std::endl;
        current = current->next;
    }

}

int main(){

    DoublyLinkedList<int> myList;
    myList.insertAtHead(new int(9));
    myList.insertAtHead(new int(8));
    myList.insertAtHead(new int(7));
    myList.insertAtTail(new int(10));
    myList.insertAtTail(new int (11));
    myList.insertAtTail(new int(12));
    myList.printList();

for(int i=0;i<3;i++){

        int* removedHead = myList.removeFromHead();
        if (removedHead) {
            std::cout << "\nRemoved from head: " << *removedHead << std::endl;
            delete removedHead;  // Manually delete the removed data
            removedHead = nullptr;
        }

        // Print the list after removals
        std::cout << "Doubly Linked List after remove from head:" << std::endl;
        myList.printList();

        int* removedTail = myList.removeFromTail();
        if (removedTail) {
            std::cout << "\nRemoved from tail: " << *removedTail << std::endl;
            delete removedTail;  // Manually delete the removed data
            removedTail = nullptr;
        }

        // Print the list after removals
        std::cout << "Doubly Linked List after remove from tail:" << std::endl;
        myList.printList();
    }

return 0;

}
