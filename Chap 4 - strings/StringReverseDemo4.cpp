#include<string>
#include<iostream>
#include<stack>

using namespace std;

string reverseStdString(string& myString){
    stack<char> charStack;
    // Push each character of input
    for(char ch:myString) {
        charStack.push(ch);
    }
    string reversedString="";
    // Pop the characters from stack and form the reversed string
    while(!charStack.empty()){
        reversedString.push_back(charStack.top());
        charStack.pop();
    }
    return reversedString;
}
 


int main(){
    string str = "Hello World";
    cout<<"Original String = "<<str<<endl;
    str = reverseStdString(str);
    cout<<"Reverse String = "<<str<<endl; 

    return 0;
}