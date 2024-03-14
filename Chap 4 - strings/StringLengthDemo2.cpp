#include <iostream>
#include <string>
using namespace std;

int main() {
    string myString = "Hello, World!";
    cout<<"Length of string = "<<myString.size()<<endl;

    cout<<"Length of string = "<<myString.length()<<endl;

    cout<<"Length of string = "<<distance(myString.begin(), myString.end())<<endl;



    return 0;
}   