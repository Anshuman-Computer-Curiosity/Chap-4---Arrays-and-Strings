#include <iostream>
#include <string>
#include<algorithm>
using  namespace std;

int main() {
    string myString = "Hello, World!";
    // const char* charArray  = myString.c_str(); // convert to C-style string

    // char charArray [myString.size()+1];// +1 for null character, ensure enough space
    // myString.copy(charArray, myString.size()); // copy the contents of  
    // copy(myString.begin(), myString.end(), charArray); // copy from source to destination using iterators
    // charArray[myString.size()] = '\0'; // last char as null character
    
    char* charArray  = const_cast<char*>(myString.c_str()); // convert to C-style string

    //Print the C-style char array
    cout<<"C style char array = "<<charArray<<endl;

    return 0;
}