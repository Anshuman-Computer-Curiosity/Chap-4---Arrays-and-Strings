#include <iostream>
#include <cstring>
using namespace std;

char* getSubstring(const char* mainString, size_t startPos, size_t length){
    size_t mainStringLength = strlen(mainString);
    if (startPos >= mainStringLength){
        cerr<<"Error: starting positino exceeds length of original string"<<endl;
        return nullptr;
    }
    //calculates length of substring
    size_t actualLength = min(length, mainStringLength - startPos);

    char* substring = new char[actualLength + 1];//add one for the null terminator

    for(size_t i=0;i<actualLength;++i){
        substring[i] = mainString[startPos+i];
    }
    substring[actualLength] = '\0';//null terminate the string
    return substring;
}



int main() {
    const char mainString[] = "Hello, World!";
    size_t startPos = 7;
    size_t length = 5;

    // Call the function to get the substring
    char* substring = getSubstring(mainString, startPos, length);

    // Check if the substring is not nullptr before using it
    if (substring) {
        cout << "Substring: " << substring << endl;
        delete[] substring; // Don't forget to free up the memory
        
    }
    return 0;
}