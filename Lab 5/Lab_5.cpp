#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    T data;  //key
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
    Node<T>* head;

public:
    // Constructor
    LinkedList()
    {
        head = nullptr;
    }

    // Destructor
    ~LinkedList()
    {
        Node<T>* cur = head;
        while (cur != nullptr)
        {
            Node<T>* next = cur->next;
            delete cur;
            cur = next;
        }
    }

    // Insert a node at the beginning of the list:
    void insertFirstNode(T value)
    {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    //Delete the first node in the list
    void deleteFirstNode()
    {
        //Empty list
        if (head == nullptr)
            return;
        cout << "\nDelete first node" << endl;
        Node<T>* curr = head;
        head = head->next;
        delete curr;
    }

    //Retrieve the front node
    void getFrontNode()
    {
        //Empty list
        if (head == nullptr)
            cout << "\nEmpty list" << endl;
        else
            cout << "\nFront node is : " << head->data << endl;
    }

    // Display the linked list
    void traverseList() {
        cout << "Linked List: ";
        for (Node<T>* cur = head; cur != nullptr; cur = cur->next) {
            cout << cur->data << " ";
        }
        cout << endl;
    }
};

//Address class for linked list
class Address
{
public:
    //Default constructor
    Address() : street("Unknown"), city("Unknown"), state("Unknown"), zip("00000") {}
    //Constructor with parameters
    Address(string street, string city, string state, string zip)
    {
        this->street = street;
        this->city = city;
        this->state = state;
        this->zip = zip;
    }
    //Overload the operator << for "cout <<" in the void traverseList() function
    friend ostream& operator<<(ostream& os, const Address& addr)
    {
        os << "\n" << addr.street << ", " << addr.city << ", " << addr.state << " " << addr.zip;
        return os;
    }
private:
    string street;
    string city;
    string state;
    string zip;
};

int main()
{
    //Linked list with integers
    LinkedList<int> myList1;
    cout << "Linked list with integers" << endl;
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

    cout << "-----------------------------------------------" << endl;
    //Linked list with floats
    LinkedList<float> myList2;
    cout << "\nLinked list with floats" << endl;
    // Insert some elements into the linked list
    myList2.insertFirstNode(2.5);
    myList2.insertFirstNode(3.1);
    myList2.insertFirstNode(9.2);
    myList2.traverseList();

    //Delete first node
    myList2.deleteFirstNode();
    myList2.traverseList();

    //Output the front node
    myList2.getFrontNode();

    cout << "-----------------------------------------------" << endl;
    //Linked list with address
    LinkedList<Address> myAddress;
    cout << "\nLinked list with addresses" << endl;
    // Insert some elements into the linked list
    myAddress.insertFirstNode(Address("14 South Drive","Dearborn","Michigan","10000"));
    myAddress.insertFirstNode(Address("100 West Ave", "Ann Arbor", "Michigan", "15000"));
    myAddress.insertFirstNode(Address("01 East Street", "Boston", "New York", "30000"));
    myAddress.insertFirstNode(Address("1241 West Road", "Houston", "Texas", "00050"));
    myAddress.traverseList();

    //Delete first node
    myAddress.deleteFirstNode();
    myAddress.traverseList();

    //Output the front node
    myAddress.getFrontNode();
    
    system("pause");
    return 0;
}
