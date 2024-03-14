
#include <iostream>
#include <string>
using namespace std;

// Function that takes a copy of string 
void display(string& str) {
    // void display(string* str) {
    cout << "Inside function: " << str << endl;
    str += " of Programming";
    // (*strPtr) += " of Programming";
    cout << "Inside function on modification: " << str << endl;
    // cout << "Inside function on modification: " << *strPtr << endl;
}

int main() {
    string myString = "Hello, World!";

    // display(myString);  // Passing string by pointer
    display(myString);  // Passing string by reference
    cout << "After function call: " << myString << endl;
    return 0;
}