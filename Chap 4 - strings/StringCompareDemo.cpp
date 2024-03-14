
#include<string>
#include<iostream>
using namespace std;

int main() {
    // const char* str1 = "apple"; 
    // const char* str2 = "application";
    // int difference = strcmp(str1,str2);
    // int difference = strncmp(str1,str2,3);
    // int difference = memcmp(str1,str2,4);
    string str1 = "apple";
    string str2 = "application";
    int result = str1.compare(0,3,str2,0,3);
    if(result == 0){
        cout<<" Both strings are equal"<<endl;
        }else if(result < 0) {
            cout << "First string is less than the second one" << endl;
        } else{
            cout << "First string is greater than the second one" << endl;
        }

    return 0;
}