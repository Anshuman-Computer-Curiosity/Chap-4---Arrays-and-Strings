
#include<cstring>
#include<iostream>
using namespace std;
int main() {
    const char mainString[] = "Learn Programming in C++";
    size_t startPos = 6;
    size_t length = 7;
    
    char substring[length+1];//Ensure enough space
    // memcpy(substring,mainString+startPos,length); //Copy characters from the string starting at 'startPos' to 'substring
    strncpy(substring,mainString+startPos,length); //Copy characters from the string starting at 'startPos' to 'substring
    substring[length]='\0';

    cout<<"Substring = "<<substring<<endl;  
 
    return 0;
}