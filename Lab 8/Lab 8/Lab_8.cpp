#include <iostream>
#include <vector>

#define TABLE_SIZE 19  // The size of the hash table

using namespace std;

// Hash functions (simple modulo-based hash)
int linearHash(int key) {
    return key % 10;
}

int quadraticHash(int key) {
    return (key * key) % 10;
}


class OpenChainingHashTable {
private:
    vector<int> table[TABLE_SIZE];

public:
    void insert(int key) {
        int index = linearHash(key);    // We can use any hash function, we are using the linear one to test
        table[index].push_back(key);    // Open chaining with linked lists
    }

    bool find(int key) {
        int index = linearHash(key); // Use the same hash function here

        for (int i = 0; i < table[index].size(); ++i) {
            if (table[index][i] == key)
            {
                return true;
            }
        }
        return false;
    }

    bool remove(int key) {
        int index = linearHash(key); // We can use the same hash function here
        for (int i = 0; i < table[index].size(); ++i) {
            if (table[index][i] == key) {
                table[index].erase(table[index].begin() + i); // Remove the key
                return true;
            }
        }
        return false;
    }


    void display() {
        cout << "\nOpen Chaining Hash Table:" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "[" << i << "] ";

            // Use direct indexing with a traditional for loop
            for (int j = 0; j < table[i].size(); ++j) {
                cout << table[i][j] << " -> ";
            }

            cout << "nullptr" << endl;
        }
    }

};

class LinearProbingHashTable {
private:
    int table[TABLE_SIZE];

public:
    LinearProbingHashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1;
        }
    }

    void insert(int key) {
        int index = linearHash(key);
        while (table[index] != -1) {
            index = (index + 1) % TABLE_SIZE;
        }
        table[index] = key;
    }

    bool find(int key) {
        int index = linearHash(key);
        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % TABLE_SIZE; // Linear probing
        }
        return false;
    }

    bool remove(int key) {
        int index = linearHash(key);
        while (table[index] != -1) {
            if (table[index] == key) {
                // Add your code here;
                return true;
            }
            index = (index + 1) % TABLE_SIZE;  // Linear probing
        }
        return false;
    }


    void display() {
        cout << "\nLinear Probing Hash Table:" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != -1) {
                cout << "[" << i << "] " << table[i] << endl;
            }
            else {
                cout << "[" << i << "] Empty" << endl;
            }
        }
    }
};


class QuadraticProbingHashTable {
private:
    int table[TABLE_SIZE];

public:
    QuadraticProbingHashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1;
        }
    }

    void insert(int key) {
        int index = quadraticHash(key);
        int increment = 1;
        while (table[index] != -1) {
            index = (index + increment * increment) % TABLE_SIZE;
            increment++;
        }
        table[index] = key;
    }

    bool find(int key) {
        int index = quadraticHash(key);
        int increment = 1;
        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }
            index = (index + increment * increment) % TABLE_SIZE;
            increment++;
        }
        return false;
    }

    bool remove(int key) {
        int index = quadraticHash(key);
        int increment = 1;
        while (table[index] != -1) {
            if (table[index] == key) {
                // Add your code here;
                return true;
            }
            index = (index + increment * increment) % TABLE_SIZE;  // Quadratic probing
            increment++;
        }
        return false;
    }

    void display() {
        cout << "\nQuadratic Probing Hash Table:" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != -1) {
                cout << "[" << i << "] " << table[i] << endl;
            }
            else {
                cout << "[" << i << "] Empty" << endl;
            }
        }
    }
};




int main()
{
    //    int keys[7] = { 47, 35, 36, 65, 129, 25, 2501 };

    int keys[7] = { 10, 20, 30, 40, 50, 60, 2501 };

    OpenChainingHashTable       openChainingTable;
    LinearProbingHashTable      linearProbingTable;
    QuadraticProbingHashTable   quadraticProbingTable;

    cout << "Inserting keys into hash tables..." << endl;
    for (int i = 0; i < 7; ++i) {
        openChainingTable.insert(keys[i]);
        linearProbingTable.insert(keys[i]);
        quadraticProbingTable.insert(keys[i]);
    }
    cout << "Displaying hash tables..." << endl;

    openChainingTable.display();
    linearProbingTable.display();
    quadraticProbingTable.display();

    // Find and remove keys in the hash tables
    int keyToFind = 20;
    cout << "Searching for key " << keyToFind << " in hash tables:" << endl;
    cout << "Open Chaining: " << (openChainingTable.find(keyToFind) ? "Found" : "Not Found") << endl;
    cout << "Linear Probing: " << (linearProbingTable.find(keyToFind) ? "Found" : "Not Found") << endl;
    cout << "Quadratic Probing: " << (quadraticProbingTable.find(keyToFind) ? "Found" : "Not Found") << endl;

    int keyToDelete = 40;
    cout << "Removing key " << keyToDelete << " from hash tables:" << endl;

    cout << "Open Chaining: " << (openChainingTable.remove(keyToDelete) ? "Removed" : "Not Found") << endl;
    cout << "Linear Probing: " << (linearProbingTable.remove(keyToDelete) ? "Removed" : "Not Found") << endl;
    cout << "Quadratic Probing: " << (quadraticProbingTable.remove(keyToDelete) ? "Removed" : "Not Found") << endl;

    cout << "Displaying updated hash tables..." << endl;
    openChainingTable.display();
    linearProbingTable.display();
    quadraticProbingTable.display();

    return 0;
}
