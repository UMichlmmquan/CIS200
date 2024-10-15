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
    }

    //Insert a node at the end of the list
    void insertLastNode(int value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* curr = head;
            while (curr->next != nullptr)
            {
                curr = curr->next;
            }
            curr->next = newNode;
        }
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
            int count = 1;
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
        }
    }
    //Delete the first node in the list
    void deleteFirstNode() 
    {
        Node* curr = head;
        head = head->next;
        delete curr;
    }

    //Delete the last node in the list
    void deleteLastNode()
    {
        //Empty list
        if (head == nullptr)
        {
            return;
        }
        //Only 1 node
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        else 
        {
            Node* curr = head;
            //Find second last node
            while (curr->next->next != nullptr)
            {
                curr = curr->next;
            }
            //Set second last node to nullptr
            delete curr->next;
            curr->next = nullptr;
        }
      
    }

    //Delete node by value
    void deleteByValue(int value)
    {
        //Empty list
        if (head == nullptr)
        {
            return;
        }
        //The node to delete is head
        if (head->data == value)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* curr = head;
        while (curr->next != nullptr)
        {
            if (curr->next->data == value)
            {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
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
    myList.insertAt(10, 3);
    myList.traverseList();

    myList.deleteFirstNode();
    myList.traverseList();

    myList.deleteLastNode();
    myList.traverseList();

    myList.deleteByValue(2);
    myList.traverseList();

    return 0;
}
