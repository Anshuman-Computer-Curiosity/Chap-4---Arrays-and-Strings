
#include<iostream>
#include<cstring>
using  namespace std;

size_t customStringLength(const char* myString){
    size_t length = 0;
    while(myString[length]!='\0'){
        length++;
    }
    return length;
}
int main() {
    const char myCharArray[] = "Hello World";
    cout<<"Length of given char array = "<<strlen(myCharArray)<<endl;
    cout<<"Length of given char array = "<<customStringLength(myCharArray)<<endl;
    
    return 0;
}