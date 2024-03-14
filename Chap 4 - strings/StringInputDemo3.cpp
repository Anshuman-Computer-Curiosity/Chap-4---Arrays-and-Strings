#include <iostream>
using namespace std;
int main() {
    const int bufferSize = 100;
    char str[bufferSize];
   
    cout<<"Enter a string =" ;
    cin.get(str,bufferSize,'\n');
    cout<<"You entered  =  "<<str;
    
    return 0;
}