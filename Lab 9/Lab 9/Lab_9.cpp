#include <iostream>
#include <algorithm> // For max function
#include <vector>
#include <string>

using namespace std;

class AddressBook
{
public:
    string name;
    string phone;
    string email;
    string address;
};

class TreeNode {
public:
    AddressBook data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(AddressBook data) : data(data), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    void insert(AddressBook data) {
        root = insert(root, data);
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

    TreeNode* insert(TreeNode* node, AddressBook data) {
        if (!node) {
            n++;
            return new TreeNode(data);
        }
        if (data.name < node->data.name)
            node->left = insert(node->left, data);
        else if (data.name > node->data.name)
            node->right = insert(node->right, data);
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
            cin.ignore();
            cout << "Enter name: ";
            getline(cin, add.name);
            cout << "Enter phone number: ";
            getline(cin, add.phone);
            cout << "Enter email address: ";
            getline(cin, add.email);
            cout << "Enter home address: ";
            getline(cin, add.address);

            //Insert the data of AddressBook to binary search tree (BST)
            bst.insert(add);
            cout << "Contact added successfully " << endl;
            //Output Total number of contacts
            cout << "\nTotal number of contacts: " << bst.numberOfContacts() << endl;
            cout << "--------------------\n" << endl;
            break;
        }
        case 2: //Remove contact
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
            break;
        }
        case 3: //Display contacts 
            bst.inOrder();
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
