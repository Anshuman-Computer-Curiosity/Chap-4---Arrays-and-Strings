
#include <iostream>

using namespace std;

int main() {
    // Convert string to C-Style Character Array
    string myString = "Hello, C++!";
    const char* charArray = myString.c_str(); //c-style string

    // Print the C-Style Character Array
    cout << "C-Style Character Array: " << charArray << endl;

    string msg(charArray,5);
    cout<<msg;

    

    
    return 0;
}