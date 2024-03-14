
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char* dynamicString = new char[20]; //alocation
    strcpy(dynamicString,"Hello World");

    // cout<<dynamicString<<endl;
    for(char *ptr = dynamicString;*ptr;ptr++)
    cout<<*ptr;

    delete[] dynamicString; //deallocatoin




    return 0;
}