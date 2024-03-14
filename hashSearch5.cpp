#include <iostream>
#include <string>
using namespace std;

const int tableSize = 10; // Size of the hash table array

// Define a simple hash function
unsigned int customHash(const string& key) {
    unsigned int hashValue = 0;
    for (char c : key) {
        hashValue = (hashValue * 31) + c; // A basic hash function
    }
    return hashValue % tableSize; // Modulo to fit within array size
}

struct Entry {
    string key;
    int value;
    bool used; // To track if the slot is used
    Entry() : key(""), value(0), used(false) {}
};

// Hash table initialization
Entry linearProbingHashTable[tableSize];

// Insert using linear probing
void linearProbingInsert(const std::string& key, int value) {
    unsigned int index = customHash(key);

    while (linearProbingHashTable[index].used) {
        index = (index + 1) % tableSize; // Linear probing: Move to the next slot
    }

    linearProbingHashTable[index].key = key;
    linearProbingHashTable[index].value = value;
    linearProbingHashTable[index].used = true;
}

// Search using linear probing
int linearProbingSearch(const std::string& key) {
    unsigned int index = customHash(key);

    while (linearProbingHashTable[index].used) {
        if (linearProbingHashTable[index].key == key) {
            return linearProbingHashTable[index].value;
        }
        index = (index + 1) % tableSize; // Linear probing: Move to the next slot
    }

    return -1; // Key not found
}

int main() {
    linearProbingInsert("apple", 5);
    linearProbingInsert("banana", 3);
    linearProbingInsert("cherry", 7);
    linearProbingInsert("banana", 8); // Insert "banana" again

    std::cout << "Hash Table with Linear Probing:" << std::endl;
    for (int i = 0; i < tableSize; ++i) {
        if (linearProbingHashTable[i].used) {
            std::cout << "Index " << i << ": " << linearProbingHashTable[i].key << " - " << linearProbingHashTable[i].value << std::endl;
        } else {
            std::cout << "Index " << i << ": Empty" << std::endl;
        }
    }

    std::string searchKey = "banana";
    int linearSearchResult = linearProbingSearch(searchKey);

    if (linearSearchResult != -1) {
        cout << "Linear probing: Value for key '" << searchKey << "' found: " << linearSearchResult << endl;
    } else {
        cout << "Linear probing: Key '" << searchKey << "' not found." << endl;
    }

    return 0;
}