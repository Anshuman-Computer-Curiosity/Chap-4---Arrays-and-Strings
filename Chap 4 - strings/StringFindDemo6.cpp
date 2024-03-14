#include <iostream>
#include <string>
using namespace std;

size_t findSubstring(const string& str, const string& subString) {
    for(size_t i=0;i<str.length()-subString.length();++i){
        size_t j;
        for( j=0;j<subString.length();++j){
            if (str[i+j] != subString[j])
               break;
        }
        if(j == subString.length())
            return i;
    }
    return string::npos;         
}

int main() {
    string myString = "Hellw, Hellw, World!";
    string subString = "Hello";

    size_t position = findSubstring(myString, subString);

    if (position != string::npos) {
        cout << "Substring found at position: " << position << endl;
    } else {
        cout << "Substring not found in the string." << endl;
    }

    return 0;
}