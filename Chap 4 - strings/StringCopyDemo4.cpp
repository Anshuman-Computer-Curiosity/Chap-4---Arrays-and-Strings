#include <iostream>
using namespace std;
void customStringCopy(string& dest, string& src ){
    dest.clear();
    for(char ch:src){
        dest.push_back(ch);
    }

}


int main() {
    string source = "Hello, World!";
    string destination;

    customStringCopy(destination,source);

    cout << "Source: " << source << endl;
    cout << "Destination: " << destination << endl;

    return 0;
}
