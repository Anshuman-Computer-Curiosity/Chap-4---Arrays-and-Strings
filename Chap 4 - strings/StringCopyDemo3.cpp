
#include <iostream>
#include<algorithm>

using namespace std;

int main() {
    string source = "Hello, World!";
    cout<<"The original string is: "<<source<<endl;
    // string destination;
    char destination[source.size()+1];

    copy(source.begin(), source.end(), destination);
    destination[source.size()]='\0';  //Null terminate the string
    cout<<"Destination string = " <<destination<<endl;  
    
    
}

















