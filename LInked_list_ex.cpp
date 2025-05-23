//
// Created by robotics on 4/28/25.
//

#include <iostream>

// Templated Node class to hold data of any type
template <typename T>
class Node {
public:
    T* data;     // Pointer to the data (of type T)
    Node* next;  // Pointer to the next node in the list

    // Constructor to initialize the node with data and set next to nullptr
    Node(T* dataValue) : data(dataValue), next(nullptr) {}

    // Destructor to manage memory and delete the data when the node is destroyed
    ~Node() {
        if (data != nullptr) {
            delete data;  // Free the memory allocated for the data
            data = nullptr;
        }
    }
};

// Templated Singly Linked List class
template <typename T>
class SinglyLinkedList {
public:
    // Constructor to initialize an empty list (head is nullptr, size is 0)
    SinglyLinkedList() : head(nullptr), size(0) {}

    // Destructor to clean up the entire linked list and free memory
    virtual ~SinglyLinkedList() {
        // TODO: Study how the destructor iterates through the linked list elements,
        // then removes and deletes them one by onen
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;  // Store the next node before deleting
            delete current;                 // Node's destructor will delete the data
            current = next;                 // Move to the next node
        }
    }

    // Insert a new node at the beginning of the list
    void insert(T* value) {
        // TODO: Study how the passed in value is wrapped in a Node instance first,
        // then, new node's next points at the current head and finally,
        // the new node becomes the new head
        Node<T>* newNode = new Node<T>(value);  // Create a new node
        newNode->next = head;  // Point the new node's next to the current head
        head = newNode;        // Update head to the new node
        ++size;                // Increment the size of the list
    }

    // Search for a node by value (assumes comparison operator == is defined for
    // T)
    Node<T>* search(const T& value) {
        std::cout << "Searching " << value << " in the list" << std::endl;

        // TODO: Implement search
        //  Start traversing the list from the head node
        //
        //  Compare the data in the current node with the value you're searching for
        //
        //  If a match is found, return the node containing the value
        //
        //  Move to the next node and continue searching if no match and the end of
        //  list isn't reached
        //
        //  If the value is not found by the end of the list,
        //  return nullptr

        Node<T>* current = head;  // Start at the head of the list
        Node<T>* nextptr = nullptr;
        // start here
        while(current!=nullptr){

            if (*(current->data) == value){
                return current;
            }
            else{
                nextptr = current->next;
                current = nextptr;
            }

        }

        return nullptr;  // Return nullptr if the value was not found

    }

    // Remove a node by value
    void remove(const T& value) {
        std::cout << "Attempting to remove " << value << " from the list"
                  << std::endl;

        // TODO: Remove the node that has the passed in value
        //  Start traversing from the head node, with previous initially set to
        //  nullptr
        //
        //  Compare the data in the current node with the value to be
        //  removed
        //
        //  If the node to be removed is the head, update head to point to
        //  the next node
        //
        //  If the node is not the head, update the next pointer of
        //  the previous node to bypass the current node
        //
        //  Free the memory occupied by the node using delete
        //
        //  Decrease the list's size counter by one If the value is not found,
        //  continue traversing the list
        //
        //  Exit once the node is removed or the list is traversed without
        //  finding the value

        Node<T>* current = head;      // Start at the head of the list
        Node<T>* previous = nullptr;  // Keep track of the previous node

        // Traverse the list to find the node with the matching value
        // start here

        while(current->next!= nullptr){

            if(*(current->data)==value){

                if (current->data = head->data){
                    head = current->next;
                }
                delete current;
                --size;
            }
            else{
                current  = current->next;
            }

        }
//        if(*(current->data) == value){
//            if(current->data = head->data){         /// assuming that the linkedlists have unique data elements
//                head = current->next;
//                delete current;
//                --size;
//            }
//            else{
//
//            }
//        }
    }

    // Print all nodes in the list
    void printList() const {
        Node<T>* current = head;      // Start at the head of the list
        while (current != nullptr) {  // Traverse until the end of the list
            std::cout << "Node with value: " << *(current->data)
                      << std::endl;   // Print the data
            current = current->next;  // Move to the next node
        }
    }

    // Get the size of the list
    size_t getSize() const { return size; }

protected:
    Node<T>* head;  // Pointer to the first node (head) of the list
    size_t size;    // Size of the list (number of nodes)
};

// Example usage
int main() {
    // TODO: Study how the Linked List is instantiated with the int type
    // Create a singly linked list to store integers
    SinglyLinkedList<int> list;

    // TODO: Study how integer elements are added to the list.
    // Note that since the list is templated, an integer class (not primitive int type) is used.
    // Insert elements into the list
    list.insert(new int(10));  // Insert 10
    list.insert(new int(20));  // Insert 20
    list.insert(new int(30));  // Insert 30

    // Print the list after insertions
    std::cout << "Linked List after insertions:" << std::endl;
    list.printList();

    // Remove an element (20) from the list
    list.remove(20);
    std::cout << "Linked List size after removing 20 is " << list.getSize()
              << " and contents are: " << std::endl;
    list.printList();

    // Search for an element (10) in the list
    if (list.search(10) != nullptr) {
        std::cout << "Node with value 10 found in the list." << std::endl;
    } else {
        std::cout << "Node with value 10 not found." << std::endl;
    }

    return 0;
}
