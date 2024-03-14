#include<iostream>
#include<cstring>
using namespace std;

int main(){
    const char* source = "Hello World!";
    char destStr[20]; //ensure enough buffer space
    cout<<"Source string = "<<source<<endl;
    // strcpy(destStr,source); 
    // strncpy(destStr,source,sizeof(destStr)-1);
    // destStr[sizeof(destStr)-1]='\0'; //null terminate the string
    for(size_t i=0;i<sizeof(destStr)-1 || source[i]!='\0'; ++i){
        *(destStr+i) = *(source+i);
    }
    destStr[sizeof(destStr)-1]='\0'; //null terminate the string
    cout<<"Destination string = "<< destStr <<endl;

}


















