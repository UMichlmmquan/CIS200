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
        //Only 1 node to delete
        if (head->next == nullptr)
        {
            if (head->data == value)
            {
                delete head;
                head == nullptr;
            }
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

    //Retrieve the front node
    int getFrontNode()
    {
        if (head == nullptr)
            return 0;
        return head->data;
    }

    //Retrieve the size of the list
    int getListSize()
    {
        Node* curr = head;
        int count = 0;
        while (curr != nullptr)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }

    //Retrieve and delete the smallest value
    void retrieveAndDeleteSmallest()
    {
        if (head == nullptr)
        {
            return;  // List is empty
        }

        // Only one node in the list
        if (head->next == nullptr)
        {
            cout << "Delete smallest value " << head->data << endl;
            delete head;
            head = nullptr;
            return;
        }

        int smallest = head->data;
        Node* curr = head;
        Node* smallestPtr = nullptr;  // Previous node of the smallest node

        // Traverse the list to find the smallest node
        while (curr != nullptr)
        {
            if (curr->data < smallest)
            {
                smallest = curr->data;
                smallestPtr = curr;  // Update the smallest node pointer
            }
            curr = curr->next;  // Move to next node
        }

        cout << "Delete smallest value " << smallest << endl;
        deleteByValue(smallest);
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

int main() 
{
    LinkedList myList;

    // Insert some elements into the linked list
    myList.insertFirstNode(2);
    myList.insertFirstNode(3);
    myList.insertLastNode(5);
    myList.insertLastNode(7);
    myList.insertAt(10, 3);
    myList.insertAt(0, 2);
    myList.insertAt(15, 3);
    myList.traverseList();

    myList.deleteFirstNode();
    myList.traverseList();

    myList.deleteLastNode();
    myList.traverseList();

    myList.deleteByValue(10);
    myList.traverseList();

    cout << "Front node is : " << myList.getFrontNode() << endl;
    cout << "Size of the list is : " << myList.getListSize() << endl;
    myList.retrieveAndDeleteSmallest();
    myList.traverseList();

    system("pause");
    return 0;
}
