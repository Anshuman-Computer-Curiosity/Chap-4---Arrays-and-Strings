#include <iostream>
#include <string>
using namespace std;

int main() {
    string mainString = "Learn C++ Programming";
    string oldSubString = "C++";
    string newSubString = "Fun with Python";

    size_t pos = mainString.find(oldSubString);  // Find the position of first occurrence of 'oldSubString' in '
    if(pos!=string::npos){
        // mainString.replace(pos,oldSubString.length(),newSubString);
        mainString.replace(6,3,newSubString,9,6);
        cout << "Modified String: "<<mainString<<endl;
    }
    else    
        cout<<"String not found"<<endl;
    return 0;
}