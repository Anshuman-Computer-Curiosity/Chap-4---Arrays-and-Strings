//for more than one value per slot
#include <iostream>
#include <string>
using namespace std;

const int tableSize = 101; // Size of the hash table array

struct Entry {
    int salary;
    string address;
    // Add more fields as needed

    Entry() : salary(0), address("") {}//initialize 
};

// Define a simple hash function
unsigned int customHash(const string& key) {
    unsigned int hashValue = 0;
    for (char c : key) {
        hashValue = (hashValue * 31) + c; // A basic hash function
    }
    return hashValue % tableSize; // Modulo to fit within array size
}

void insert(Entry table[], const string& key, int sal, const string& address) {
    unsigned int index = customHash(key);

    Entry& entry = table[index]; // refernce variable
    entry.salary = sal;
    entry.address = address;
    // Set more attributes as needed
}

Entry search(Entry table[], const string& key) {
    unsigned int index = customHash(key);
    return table[index];
}

int main() {
    Entry hashTable[tableSize]; // Initialize the hash table array with Entries

    insert(hashTable, "Harman", 25000, "123 Lawrence Road");
    insert(hashTable, "Kapil", 38000, "456 Brahm Nagar");
    insert(hashTable, "Swati", 32500, "789 Green Avenue");
//    insert(hashTable, "Kapil", 42500, "234 Ranjit avenue");

    string searchKey = "Kapil";

    Entry searchResult = search(hashTable, searchKey);

    if (searchResult.salary != 0) {
        cout << "Values for key '" << searchKey << "' found:" << endl;
        cout << "Salary: " << searchResult.salary << endl;
        cout << "Address: " << searchResult.address << endl;
        // Print more attributes as needed
    } else {
        cout << "Key '" << searchKey << "' not found." << endl;
    }

    return 0;
}