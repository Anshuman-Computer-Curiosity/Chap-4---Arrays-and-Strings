#include <iostream>
#include <string>
using namespace std;

int main() {
    string myString = "My Wprld Hmllo, World!";
    string targetString = "World";
    // size_t pos = myString.find(targetString);//First occurrence of substring
    size_t pos = myString.find_last_not_of("q");//last occurrence of substring

    if(pos!=string::npos)
        cout<<"Found "<<targetString<< " at position "<<pos<<endl;
    else
        cout<<targetString<< "Not Found in"<<myString <<endl;

        cout<<myString.substr(7,targetString.length());

    return 0;
}