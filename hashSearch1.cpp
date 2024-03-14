#include <iostream>
#include <string>
using namespace std;

int tableSize = 101; // Size of the hash table array

// Define a simple hash function
unsigned int customHash(const string& key) {
    unsigned int hashValue = 0;
    for (char c : key) {
        hashValue = (hashValue * 31) + c; // A basic hash function
    }
    return hashValue % tableSize; // Modulo to fit within array size
}

// Insert into the hash table
void insert(int table[], const string& key, int value) {
    unsigned int index = customHash(key);
    table[index] = value;
}

//Search from a hash table
int search(int table[], const string& key) {
    unsigned int index = customHash(key);
    return table[index];
}

int main() {
    int hashTable[tableSize] = {0}; // Initialize the hash table array

    insert(hashTable, "Harman", 25000);
    insert(hashTable, "Kapil", 38000);
    insert(hashTable, "Swati", 32500);

    string searchKey = "Kapil";
    int searchResult = search(hashTable, searchKey);

    if (searchResult != 0) {
        cout << "Value for key '" << searchKey << "' found: " << searchResult << endl;
    } else {
        cout << "Key '" << searchKey << "' not found." << endl;
    }

    return 0;
}