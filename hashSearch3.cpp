//by using class
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int tableSize = 101; // Size of the hash table array

struct Entry {
    int salary;
    string address;
    // Add more attributes as needed

    Entry() : salary(0), address("") {}
};

class HashTable {
    private:
    vector<Entry> hashTable;// Initialize the hash table array with Entries

    unsigned int customHash(const string& key) {
        unsigned int hashValue = 0;
        for (char c : key) {
            hashValue = (hashValue * 31) + c; // A basic hash function
        }
        return hashValue % tableSize; // Modulo to fit within array size
    }
    public:
        HashTable() {
            // Initialize the hash table array with Entries
            hashTable.resize(tableSize);
        }

    void insert(const string& key, int sal, const string& address) {
        unsigned int index = customHash(key);

        Entry& entry = hashTable[index];
        entry.salary = sal;
        entry.address = address;
        // Set more attributes as needed
    }

    Entry search(const string& key) {
        unsigned int index = customHash(key);
        return hashTable[index];
    }


};

int main() {
    HashTable ht;

    ht.insert("Harman", 25000, "123 Lawrence Road");
    ht.insert("Kapil", 38000, "456 Brahm Nagar");
    ht.insert("Swati", 32500, "789 Green Avenue");
   // ht.insert("Kapil", 42500, "234 Ranjit avenue");

    string searchKey = "Kapil";
    Entry searchResult = ht.search(searchKey);

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