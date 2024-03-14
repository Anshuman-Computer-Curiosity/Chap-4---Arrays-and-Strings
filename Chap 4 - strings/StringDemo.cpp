
#include <iostream>
using namespace std;

int main() {

    // char charArray2[] = "Hello, World!";  
    
    // for (size_t i = 0; charArray2[i]!='\0'; ++i) {
    //     cout << charArray2[i] << " ";
    // }
    // cout << endl;



    const char*  cString = "Hello, World!";

    // Accessing all characters in the C-style string
    for (const char* ptr = cString; *ptr != '\0'; ++ptr) {
        cout << *ptr << " ";
    }
    cout << endl;
    
    //using for-each loop
    // for (char ch : charArray2) {
    //     if (ch == '\0') {
    //         break;
    //     }
    //     cout << ch << " ";
    // }
    // cout << endl;


    return 0;
}