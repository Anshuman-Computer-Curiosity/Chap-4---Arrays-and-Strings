#include <iostream>
#include <string>
#include<sstream>
using namespace std;

int main() {
    int number = 12345;
    stringstream ss;
    ss<<number;
    string result = ss.str()+ " is a positive integer.";

    // string result = to_string(number) + " is a positive integer.";
    cout << result << endl;
   
    return 0;
}