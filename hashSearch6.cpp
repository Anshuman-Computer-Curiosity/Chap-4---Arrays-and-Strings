#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main() {
    // Create an unordered_map with string keys and int values
    unordered_map<string, int> myMap;

    // Insert key-value pairs into the map
    myMap["Harman"] = 25000;
    myMap["Kapil"] = 38000;
    myMap["Swati"] = 32500;

    // Search for a specific key
    string searchKey = "Kapil";
    if (myMap.find(searchKey) != myMap.end()) {
        cout << "Value for key '" << searchKey << "' found: " << myMap[searchKey] << endl;
    } else {
        cout << "Key '" << searchKey << "' not found." << endl;
    }

    return 0;
}