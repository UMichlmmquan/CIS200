#include <iostream>

using namespace std;

class DataPoint 
{
public:
    float x;
    float y;
    DataPoint* next;

    // Constructor
    DataPoint(float X, float Y) 
    {
        x = X;
        y = Y;
        next = nullptr;
    }
};

class DataSet
{
private:
    DataPoint* head;

public:
    // Constructor
    DataSet()
    {
        head = nullptr;
    }

    // Destructor
    ~DataSet()
    {
        DataPoint* cur = head;
        while (cur != nullptr)
        {
            DataPoint* next = cur->next;
            delete cur;
            cur = next;
        }
    }

    // Insert a node at the beginning of the list:
    void insertFirstNode(float X, float Y)
    {
        DataPoint* newNode = new DataPoint(X,Y);
        newNode->next = head;
        head = newNode;
    }

    // Display the linked list
    void traverseList() 
    {
        cout << "Data Points: " << endl;
        for (DataPoint* cur = head; cur != nullptr; cur = cur->next) 
        {
            cout << "(" << cur->x << ", " << cur->y << ")" << endl;
        }
        cout << endl;
    }
};

int main()
{
    //Declare variable
    DataSet subset;

    //Add nodes
    subset.insertFirstNode(4, 7.8);
    subset.insertFirstNode(3, 5.8);
    subset.insertFirstNode(2, 3.9);
    subset.insertFirstNode(1, 2);

    //Display the input points
    subset.traverseList();

    system("pause");
    return 0;
}