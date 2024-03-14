#include <iostream>
#include <string>
using namespace std;

int main() {
    string strNum1 =  "123456789123456789AB";//numeric string
    size_t pos;
    long long num1 = stoll(strNum1,&pos); // Convert a String to an Integer.
    cout << "The converted number is: " << num1 << endl;
    cout << "pos =  " << pos << endl;
    
    return 0;
}