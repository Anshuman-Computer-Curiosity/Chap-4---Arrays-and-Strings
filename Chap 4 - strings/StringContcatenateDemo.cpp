
#include<cstring>
#include<iostream>
using namespace std;
int main() {
    const char str1[]="Hello";
    const char str2[] = " World!";
    char result[50] = {};
    strcpy(result, str1);
    strcat(result, str2);
    cout<<" Concateated string = "<<result<<endl;

    return 0;
}