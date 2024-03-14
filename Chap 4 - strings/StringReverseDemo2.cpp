#include <iostream>
#include <algorithm>
#include <stack>

using  namespace std;

// void reverseString(string& str) {
//     reverse(str.begin(), str.end());
// }

// string reverseStdString(string& myString) {
//     string reversedString(myString.rbegin(), myString.rend());
//     return reversedString;
// }

string reverseStdString(string& myString) {
    stack<char> charStack;
    // Push each character onto the stack
    for (char c : myString) {
        charStack.push(c);
    }
    string reversedString;
    while (!charStack.empty()) {
        reversedString.push_back(charStack.top());
        charStack.pop();
    }
    return reversedString;
}

// string reverseStdString(string& myString) {
//     string reversedString;

//     // Iterate backward and append characters to the new string
//     for (auto it = myString.rbegin(); it != myString.rend(); ++it) {
//         reversedString.push_back(*it);
//     }
//     return reversedString;
// }

// string reverseStdString(string& myString) {
//     string reversedString;

//     // Use a range-based for loop and append characters to the new string
//     for (char c : myString) {
//         reversedString = c + reversedString;
//     }
//     return reversedString;
// }

// void reverseString(string& mystring) {
//     size_t length = mystring.length();

//     // Use std::swap in a loop to reverse the string
//     for (size_t i = 0; i < length / 2; ++i) {
//         swap(mystring[i], mystring[length - i - 1]);
//     }
// }

int main() {
    string myString = "Hello, World!";
    cout << "Original string: " << myString << endl;

    // reverseString(myString);
    myString = reverseStdString(myString);

    cout << "Reversed string: " << myString << endl;

    return 0;
}