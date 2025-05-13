#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int TABLE_SIZE = 11;  // Preferably a prime number
const int MAX_DISPLACEMENTS = 20;

class CuckooHashing {
    vector<int> table1;
    vector<int> table2;

    int hash1(int key) {
        return key % TABLE_SIZE;
    }

    int hash2(int key) {
        return (key / TABLE_SIZE) % TABLE_SIZE;
    }

public:
    CuckooHashing() {
        table1.assign(TABLE_SIZE, -1);
        table2.assign(TABLE_SIZE, -1);
    }

    bool place(int key, int count, int tableID) {
        if (count >= MAX_DISPLACEMENTS) {
            cout << "Cycle detected. Rehash required!" << endl;
            return false;
        }

        if (tableID == 1) {
            int pos = hash1(key);
            if (table1[pos] == -1) {
                table1[pos] = key;
                return true;
            } else {
                int displaced = table1[pos];
                table1[pos] = key;
                return place(displaced, count + 1, 2);
            }
        } else {
            int pos = hash2(key);
            if (table2[pos] == -1) {
                table2[pos] = key;
                return true;
            } else {
                int displaced = table2[pos];
                table2[pos] = key;
                return place(displaced, count + 1, 1);
            }
        }
    }

    void insert(int key) {
        if (!place(key, 0, 1)) {
            cout << "Rehashing needed. Key " << key << " couldn't be inserted.\n";
        } else {
            cout << "Key " << key << " inserted successfully.\n";
        }
    }

    void display() {
        cout << "\nTable 1:\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "[" << i << "]: ";
            if (table1[i] == -1) cout << "Empty";
            else cout << table1[i];
            cout << "\n";
        }

        cout << "Table 2:\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "[" << i << "]: ";
            if (table2[i] == -1) cout << "Empty";
            else cout << table2[i];
            cout << "\n";
        }
    }
};

int main() {
    CuckooHashing hashTable;
    int choice, key;

    while (true) {
        cout << "\n==== Cuckoo Hashing Menu ====\n";
        cout << "1. Insert\n2. Display Tables\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            hashTable.insert(key);
            break;
        case 2:
            hashTable.display();
            break;
        case 0:
            exit(0);
        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
