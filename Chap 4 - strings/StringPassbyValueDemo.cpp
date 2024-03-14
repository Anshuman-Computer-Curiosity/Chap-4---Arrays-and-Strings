

#include<iostream>
#include<string>
using namespace std;
 void display(string* str){
    cout<<"Within function, str = "<<*str<<endl;
    (*str) += "of Programming";
    cout<<"After modifcation, within function, str = "<<*str<<endl;
 }

int main() {
    string myString = "Hello World";
    // display(myString);//Pass by Reference
    display(&myString);//Pass by Address
    cout<<"After modification, with calling main = " <<myString<<endl;


    return 0;
}