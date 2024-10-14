
#include <iostream>

using namespace std;

class Node {
public:
    int data;  //key
    Node* next;

    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }

    //Node(int value) : data(value), next(nullptr) {}

};

class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Destructor
    ~LinkedList() {
        Node* cur = head;
        while (cur != nullptr) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
    }

    // Insert a node at the beginning of the list:
    // Create a new node(newNode) with the given value.
    // Set the next pointer of the new node to the current head of the list.
    // 
    // This effectively makes the new node the first element in the list, 
    // and its next pointer points to the previous head.
    // Update the head pointer to point to the new node, making it the new head of the list.

    void insertNode(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void deleteNode() {
        Node* cur = head;
        head = head->next;
        delete cur;
    }


    // Display the linked list
    void traverseList() {
        cout << "Linked List: ";
        for (Node* cur = head; cur != nullptr; cur = cur->next) {
            cout << cur->data << " ";
        }
        cout << endl;
    }
};

int main() {
  
    // Create a linked list as node by node:
    Node* head = new Node(10);    // First node
    Node* second = new Node(20);  // Second node
    Node* third = new Node(30);   // Third node

    // Link the nodes together
    head->next = second;  // Head points to the second node
    second->next = third;  // Second node points to the third node

    // Traversing the linked list starting from head
    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->data << " ";  // Output the data in each node
        cur = cur->next;           // Move to the next node
    }

    
    
    
    
    LinkedList myList;

    // Insert some elements into the linked list
    myList.insertNode(1);
    myList.insertNode(2);
    myList.insertNode(3);
    myList.traverseList();

    myList.deleteNode();
    myList.traverseList();

    myList.deleteNode();
    myList.traverseList();

    return 0;
}
