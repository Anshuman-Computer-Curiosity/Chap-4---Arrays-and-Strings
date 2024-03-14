
#include <iostream>
#include <string>
using namespace std;

int main() {
    const int bufferSize = 20;
    char buffer[bufferSize];
    cout << "Enter up to " << bufferSize - 1 << " characters: ";
    cin.read(buffer,bufferSize-1);
    buffer[cin.gcount()]='\0';
    

    cout << "You entered: " << buffer << endl;
    return 0;
}