#include <iostream>

using namespace std;

class DTCNode
{
public:
    string code; 
    string description;
    DTCNode* next;
    DTCNode* prev;

    // Constructor
    DTCNode(string code, string description)
    {
        this->code = code;
        this->description = description;
        next = nullptr;
        prev = nullptr;
    }
};

class DTCList
{
private:
    DTCNode* head;
    DTCNode* tail;

public:
    // Constructor
    DTCList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Destructor
    ~DTCList()
    {
        DTCNode* cur = head;
        while (cur != nullptr)
        {
            DTCNode* next = cur->next;
            delete cur;
            cur = next;
        }
    }

    //Insert a node at the end of the list
    void addDTC(string code, string description)
    {
        DTCNode* newNode = new DTCNode(code, description);
        //Empty list
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else //Non-empty list
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "DTC added: " << code << " - " << description << endl;
    }

    //Delete node by value
    void removeDTC(string code)
    {
        //Empty list
        if (head == nullptr)
        {
            cout << "Nothing to remove. Empty list" << endl;
            return;
        }
        //Only 1 node to delete
        if (head->next == nullptr && tail->code == code)
        {
            delete head;
            head = nullptr;
            delete tail;
            tail = nullptr;
            return;
        }
        //The node to delete is head
        if (head->code == code)
        {
            DTCNode* temp = head;
            head = head->next;
            if (head)
                head->prev = nullptr;
            delete temp;
            return;
        }

        DTCNode* curr = head;
        //Traverse the list
        while (curr != nullptr)
        {
            //Found the node to delete
            if (curr->code == code)
            {
                DTCNode* temp = curr;
                //Update prev's next ptr
                if (curr->prev != nullptr)
                {
                    curr->prev->next = curr->next;
                }
                //Update next's prev ptr
                if (curr->next != nullptr)
                {
                    curr->next->prev = curr->prev;
                }
                //If deleting the tail node, update the tail ptr
                if (curr == tail)
                    tail = curr->prev;
                
                cout << "\nDTC removed: " << temp->code << endl;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }


    // Traverses the list from head to tail, displaying each DTC in the order it was recorded.s
    void displayDTCs() 
    {
        cout << "\nDTC History (oldest to newest): " << endl;
        //Empty list
        if (head == nullptr)
        {
            cout << "No DTCs to display" << endl;
            return;
        }
        //From head to tail
        for (DTCNode* cur = head; cur != nullptr; cur = cur->next) {
            cout << "- " << cur->code << ": " << cur->description << endl;
        }
    }
    // Traverses the list from tail to head, displaying each DTC in reverse order (from most recent).
    void displayDTCsReverse()
    {
        cout << "\nDTC History (newest to oldest): " << endl;
        //Empty list
        if (tail == nullptr)
        {
            cout << "No DTCs to display" << endl;
            return;
        }
        //From tail to head
        for (DTCNode* cur = tail; cur != nullptr; cur = cur->prev) {
            cout << "- " << cur->code << ": " << cur->description << endl;
        }
    }
};

int main()
{
    DTCList myList;

    // Insert some elements into the doubly linked list
    myList.addDTC("P0A1F", "Electric Drive Motor Temperature Too High");
    myList.addDTC("P0A80", "Replace Hybrid Battery Pack");
    myList.addDTC("P0AA6", "Hybrid Battery Voltage Isolation Fault");
    myList.addDTC("P1A10", "Battery Management System Communication Fault");

    // Display list from oldest to newest
    myList.displayDTCs();

    // Display list in newest to oldest
    myList.displayDTCsReverse();

    // Delete a node by code
    myList.removeDTC("P0A80");

    // Display list from oldest to newest
    myList.displayDTCs();

    // Display list in newest to oldest
    myList.displayDTCsReverse();

    system("pause");
    return 0;
}
