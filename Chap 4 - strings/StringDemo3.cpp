
//Dynamically declare array

#include <iostream>
#include <string>
using namespace std;

int main() {
    string *dynmsg = new string("Hello World !");

    cout<<*dynmsg; 
    cout<<endl;
    for(size_t i=0;i<dynmsg->length();i++)
    cout<<(*dynmsg)[i];

    //no need deallocating memory

    return 0;
}