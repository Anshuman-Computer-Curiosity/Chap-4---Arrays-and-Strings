#include<iostream>
#include<cstring>
using namespace std;
int main() {
    const char* mystring = "Hello World!";
    const char* substring = "eWorld!";
    const char* charSet = "aeiou";
    char targetChar = 'o';
    
    // const char* result = strchr(mystring,targetChar); //First occurence
    // const char* result = strrchr(mystring,targetChar); //Last occurence
    // const char* result = strstr(mystring,substring); //substring occurence
    const char* result = strpbrk(mystring,charSet); //First charc in charset occurence

   if(result!=nullptr)
        cout<<"Found "<<charSet<< " at position = "<<(result - mystring)+1 <<endl;
   else
        cout<<" "<<charSet<<" not found in " <<mystring<<endl;         

    return 0;
}
