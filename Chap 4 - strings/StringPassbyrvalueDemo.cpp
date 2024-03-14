#include <iostream>
#include <utility> // for move
#include <string>
using namespace std;

// Function that transfers ownership of dynamically allocated memory
void display(string&& source) {
    // Transfer ownership of the dynamically allocated memory
    string destination = move(source);

    // source is now in a valid but unspecified state
    cout << "Inside function: " << destination << endl;
    destination += " of programming";
    cout << "On modication, Inside function: " << destination << endl;
}

int main() {
    // Create a dynamically allocated string
    string *dynamicString = new string("Hello World!");

    display(move(*dynamicString)); //Transfer ownership of dynamically allocaed memory

    cout << "On modication, Inside main: " << *dynamicString << endl;

    delete dynamicString; //deallocate

    return 0;
}