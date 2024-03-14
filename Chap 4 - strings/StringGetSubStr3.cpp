#include <iostream>
#include <string>
using  namespace std;

int main() {
    string mainString = "Hello, World!";
    size_t startPos = 7;
    size_t length = 5;
    // string substring = mainString.substr(startPos,length);
    string substring(5,' ');
    // char substring[6]; // +1 for null character
    copy(mainString.begin()+7, mainString.begin()+12, substring.begin());
    
    cout << "Substring: " << substring << endl;

    return 0;
}