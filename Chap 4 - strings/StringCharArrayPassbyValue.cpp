#include <iostream>
#include<cstring>
using namespace std;

// Function that takes a pointer to a character array (C-style string)
void passByRef(char (&cstr)[14]) {
    cout << "Inside function: " << cstr << endl;
    strcat(cstr," Welcome"); 
    cout << "After modication, Inside function: " << cstr << endl;
}

int main() {
   
    char myCString[] = "Hello, World!"; // 14 characters
    
    passByRef(myCString);  // Passing C-style string (const char*) by pointer
    
    cout << "After function call , str =" << myCString << endl;
    return 0;
}