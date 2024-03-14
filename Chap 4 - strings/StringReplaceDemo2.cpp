#include <iostream>
#include <string>
using namespace std;

int main() {
    string mainString = "Hello, World!";
    string oldSubString = "o";
    string newSubString = "X";

    size_t pos = mainString.find(oldSubString);
    while (pos != string::npos) {
        mainString.replace(pos, oldSubString.length(), newSubString);
        pos = mainString.find(oldSubString, pos + newSubString.length());
    }

    cout << "Modified string: " << mainString << endl;

    return 0;
}