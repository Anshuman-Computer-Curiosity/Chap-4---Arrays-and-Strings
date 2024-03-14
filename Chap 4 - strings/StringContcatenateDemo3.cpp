
#include<iostream>
#include<cstring>
using namespace std;

char* concat(const char* str1, const char* str2){
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char* result = new char[len1 + len2 + 1];
    char* temp  = result;
    while(*str1){ // copy charcters of first string one by one 
        *temp++ = *str1++;
    }
    while(*str2){ // copy charcters of second string one by one
        *temp++ = *str2++;
    }
    *temp = '\0'; // null terminaton
    return result;
}

int main() {
    // Two input strings to be concatenated
    const char str1[] = "Hello, ";
    const char str2[] = "World!";
    char* concatStr = concat(str1,str2);
    cout<<"Resulting concatenated string = "<<concatStr<<endl;
    delete[] concatStr; // to avoid memory leak

    return 0;
}