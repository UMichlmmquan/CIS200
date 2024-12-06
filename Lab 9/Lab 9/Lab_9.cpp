#include <iostream>
#include <algorithm> // For max function
#include <vector>
#include <string>

using namespace std;

class BinarySearchTree;

class AddressBook
{
public:
    string name;
    string phone;
    string email;
    string address;

    void addContact(BinarySearchTree& bst);
    void removeContact(BinarySearchTree& bst);
    void displayContacts(BinarySearchTree bst);
};

class TreeNode {
public:
    AddressBook data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(AddressBook data) : data(data), left(nullptr), right(nullptr) {}
    TreeNode(string name, string phone, string email, string address)
    {
        data.name = name;
        data.phone = phone;
        data.email = email;
        data.address = address;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
public:
    void insert(string name, string phone, string email, string address) {
        root = insert(root, name, phone, email, address);
    }

    bool remove(string inputRemove) {
        bool removed = false;
        root = deleteNode(root, inputRemove, removed);
        return removed;
    }

    void inOrder() {
        if (!root)
        {
            cout << "No contacts available" << endl;
            return;
        }
        cout << "\nContacts:" << endl;
        inOrderTraversal(root);
        cout << endl;
        cout << "\nTotal number of contacts: " << numberOfContacts() << endl;
        cout << "--------------------\n" << endl;
    }
    int numberOfContacts()
    {
        return n;
    }

private:
    TreeNode* root = nullptr;
    vector<int> originalNodes; // Vector to store original nodes created
    int n = 0; //Number of Contacts

    TreeNode* insert(TreeNode* node, string name, string phone, string email, string address) {
        if (!node) {
            n++;
            return new TreeNode(name, phone, email, address);
        }
        if (name < node->data.name)
            node->left = insert(node->left, name, phone, email, address);
        else if (name > node->data.name)
            node->right = insert(node->right, name, phone, email, address);
        return node;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left)
            node = node->left;
        return node;
    }

    TreeNode* deleteNode(TreeNode* node, string inputRemove, bool& removed) {
        if (!node)
            return node;
        if (inputRemove < node->data.name)
            node->left = deleteNode(node->left, inputRemove,removed);
        else if (inputRemove > node->data.name)
            node->right = deleteNode(node->right, inputRemove,removed);
        else {
            removed = true; //Update removed
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                n--;
                return temp;
            }
            else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                n--;
                return temp;
            }
            TreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data.name,removed);
        }
        return node;
    }

    void inOrderTraversal(TreeNode* node) {
        if (node) {
            inOrderTraversal(node->left);
            cout << "Name : " << node->data.name << endl;
            cout << "Phone : " << node->data.phone << endl;
            cout << "Email : " << node->data.email << endl;
            cout << "Address : " << node->data.address << endl;
            cout << endl;
            inOrderTraversal(node->right);
        }
    }
};

void AddressBook::addContact(BinarySearchTree& bst)
{
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter phone number: ";
    getline(cin, phone);
    cout << "Enter email address: ";
    getline(cin, email);
    cout << "Enter home address: ";
    getline(cin, address);

    //Insert the data of AddressBook to binary search tree (BST)
    bst.insert(name, phone, email, address);
    cout << "Contact added successfully " << endl;
    //Output Total number of contacts
    cout << "\nTotal number of contacts: " << bst.numberOfContacts() << endl;
    cout << "--------------------\n" << endl;
}

void AddressBook::removeContact(BinarySearchTree& bst)
{
    cin.ignore();
    string inputRemove;
    cout << "Enter name to remove:";
    getline(cin, inputRemove);

    //Remove the entire node of input name
    if (bst.remove(inputRemove))
    {
        cout << "Contact removed successfully" << endl;
        cout << endl;
        cout << "\nTotal number of contacts: " << bst.numberOfContacts() << endl;
        cout << "--------------------\n" << endl;
    }
    else
        cout << inputRemove << " is not found." << endl;
}

void AddressBook::displayContacts(BinarySearchTree bst)
{
    bst.inOrder();
}

void displayMenu(BinarySearchTree &bst)
{
    //Declare variables
    AddressBook add;
    int choice;
    do
    {
        cout << "Address Book Menu" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Remove Contact" << endl;
        cout << "3. Display Contacts" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "--------------------\n" << endl;

        switch (choice)
        {
        case 1: //Add contact
        {
            add.addContact(bst);
            break;
        }
        case 2: //Remove contact
        {
            add.removeContact(bst);
            break;
        }
        case 3: //Display contacts 
            add.displayContacts(bst);
            break;
        case 4:
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Please enter choice from 1 to 4" << endl << endl;
            break;
        }
    } while (choice != 4);
}

int main() 
{
    //Declare variable
    BinarySearchTree bst;
    displayMenu(bst);

    system("pause");
    return 0;
}
