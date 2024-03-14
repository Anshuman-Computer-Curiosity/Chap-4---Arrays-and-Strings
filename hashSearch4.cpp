#include <iostream>
#include <string>
using namespace std;

const int tableSize = 101; // Size of the hash table array

// Define a simple hash function
unsigned int customHash(const string& key) {
    unsigned int hashValue = 0;
    for (char c : key) {
        hashValue = (hashValue * 31) + c; // A basic hash function
    }
    return hashValue % tableSize; // Modulo to fit within array size
}

//defininig strucutre of node
struct Node {
    string key;
    int value;
    Node* next;
    Node(const string& k, int v) : key(k), value(v), next(nullptr) {}
};

// Hash table initialization with nullptrs
Node* hashTable[tableSize] = {nullptr};

void insert(const string& key, int value) {
    unsigned int index = customHash(key);

    if (hashTable[index] == nullptr) {
        hashTable[index] = new Node(key, value);
    } else {
        Node* current = hashTable[index];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(key, value);
    }
}

void searchAndPrint(const string& key) {
    unsigned int index = customHash(key);
    Node* current = hashTable[index];

    bool found = false;
    while (current != nullptr) {
        if (current->key == key) {
            cout << "Value for key '" << key << "' found: " << current->value << endl;
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << "Key '" << key << "' not found." << endl;
    }
}

int main() {
    insert( "Harman", 25000);
    insert("Kapil", 38000);
    insert("Swati", 32500);
    insert("Kapil", 48500);// Add another value for "kapil"

    searchAndPrint("Kapil");

    return 0;
}