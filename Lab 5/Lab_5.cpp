#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    int data;  //key
    Node* next;

    // Constructor
    Node(T value)
    {
        data = value;
        next = nullptr;
    }

    //Node(int value) : data(value), next(nullptr) {}
};

template <typename T>
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
    void insertFirstNode(T value)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    //Delete the first node in the list
    void deleteFirstNode()
    {
        //Empty list
        if (head == nullptr)
            return;
        Node* curr = head;
        head = head->next;
        delete curr;
    }

    //Retrieve the front node
    void getFrontNode()
    {
        //Empty list
        if (head == nullptr)
            cout << "Empty list" << endl;
        else
            cout << "Front node is : " << head->data << endl;
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
    //Linked list with integers
    LinkedList<int> myList1;

    // Insert some elements into the linked list
    myList1.insertFirstNode(2);
    myList1.insertFirstNode(3);
    myList1.insertFirstNode(9);
    myList1.traverseList();

    //Delete first node
    myList1.deleteFirstNode();
    myList1.traverseList();

    //Output the front node
    myList1.getFrontNode();
    myList1.traverseList();

    system("pause");
    return 0;
}
