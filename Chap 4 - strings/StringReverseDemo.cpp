//Program to reverse a given string
#include<iostream>
#include<cstring>
using namespace std;
void reverse(char* mystring){
   size_t len = strlen(mystring); 
   for(int i=0;i<len/2;i++){
        swap(mystring[i],mystring[len-i-1]);
   }
}

int main() {
    char str1[]="Hello World!";
    cout<<"Original string = "<<str1<<endl;
    reverse(str1);
    cout<<"Reverse string = "<<str1<<endl;
    return 0;
}