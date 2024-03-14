
#include <iostream>
#include <string>
using namespace std;

int main() {
    int count = 0;
    string line;
    // const int bufferSize  = 100;
    // char str[bufferSize];

    cout<<"Enter multiple  lines and exit \'exit\'= "<<endl;
    while(true){
        cout<<"Enter a line "<<count <<" = ";
        getline(cin,line);
        if(line == "exit")
            break;
        cout<<"You entered = "<<line<<endl;
        count++;    
    }

    // cin.getline(str,bufferSize);
    // getline(cin, line);
    // cout<<"You entered = "<<str;

    return 0;
}