

#include<string>
#include<iostream>
using namespace std;

int main() {
    string msg2 ("Hello");
    // string msg = msg2;
    string msg = msg2 + " World!";
    cout<<msg<<endl;
    for(auto it = msg.begin();it!=msg.end();it++)
    cout<<*it;
    

    return 0;
}