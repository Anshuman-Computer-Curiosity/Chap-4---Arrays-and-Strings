#include <iostream>
#include<sstream>
#include <string>
#include<cstdlib>
using namespace std;
int main() {
    string myString = "876Hello";
    // const char* charArray = myString.c_str();
    // int myNumber  = atoi (charArray);
    // stringstream  ss(myString);
    int myNumber = 0;
    // ss>>myNumber;
    int result = sscanf(myString.data(),"%i",&myNumber);
    if(result == 1)
        cout<<"Converted number = "<<myNumber<<endl;
    else
        cerr <<"Conversion Failed"<<endl;

    return 0;
}