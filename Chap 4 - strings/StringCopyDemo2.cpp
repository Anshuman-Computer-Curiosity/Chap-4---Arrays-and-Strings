
#include <iostream>
#include<cstring>
using namespace std;
 void copyStr(char* dest, const char* src){
    while((*dest++ = *src++)!='\0');
 }


int main() {
    const char* source = "Hello, World!";
    char destination[20]; // ensure enough buffer space
    cout << "Source: \"" << source << "\", Length: " << strlen(source) << endl; 
    copyStr(destination, source);
    cout << "Destination: \"" << destination << "\", Length: " << strlen(destination)<<endl;
    
    return 0;
}


















