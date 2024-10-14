#include <iostream>

using namespace std;

class Node 
{
public:
    int data;  //key
    Node* next;

    // Constructor
    Node(int value) 
    {
        data = value;
        next = nullptr;
    }

    //Node(int value) : data(value), next(nullptr) {}
};

class LinkedList 
{
private:
    Node* head;

public:
    // Constructor
    LinkedList() 
    {
        head = nullptr;
    }

    // Destructor
    ~LinkedList() 
    {
        Node* cur = head;
        while (cur != nullptr) 
        {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
    }

    // Insert a node at the beginning of the list:
    void insertFirstNode(int value) 
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        delete newNode;
    }

    //Insert a node at the end of the list
    void insertLastNode(int value)
    {
        Node* newNode = new Node(value);
        Node* curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    //Insert a node at a specific positon
    void insertAt(int value, int pos)
    {
        if (pos == 0)
        {
            insertFirstNode(value);
        }
        else
        {
            Node* newNode = new Node(value);
            Node* curr = head;
            int count = 0;
            while (curr->next != nullptr && count < pos - 1)
            {
                curr = curr->next;
                count++;
            }
            if (curr != nullptr)
            {
                newNode->next = curr->next;
                curr->next = newNode;
            }
            delete newNode;
        }
    }
    //Delete the first node in the list
    void deleteNode() 
    {
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
    myList.insertFirstNode(2);
    myList.insertFirstNode(3);
    myList.insertLastNode(5);
    myList.insertLastNode(7);
    myList.insertAt(2, 3);
    myList.traverseList();

    myList.deleteNode();
    myList.traverseList();

    myList.deleteNode();
    myList.traverseList();

    return 0;
}
