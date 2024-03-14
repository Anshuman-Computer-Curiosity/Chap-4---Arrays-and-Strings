
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Initialize a string
    string original = "Hello, C++!";

    // 1. Size and Length
    cout << "1. Size and Length: " << original.size() << ", " << original.length() << endl;

    // 2. Empty
    cout << "2. Is the string empty? " << (original.empty() ? "Yes" : "No") << endl;

    // 3. c_str()
    const char* cString = original.c_str();
    cout << "3. C-Style String: " << cString << endl;

    // 4. Append
    original.append(" Welcome!");
    cout << "4. Appended String: " << original << endl;

    // 5. Substring
    string substring = original.substr(7, 5);
    cout << "5. Substring: " << substring << endl;

    // 6. Find
    size_t position = original.find("C++");
    cout << "6. Found 'C++' at position: " << position << endl;

    // 7. Replace
    original.replace(7, 3, "World");
    cout << "7. After Replacement: " << original << endl;

    // 8. at()
    char characterAtPosition = original.at(0);
    cout << "8. Character at position 0: " << characterAtPosition << endl;

    return 0;
}