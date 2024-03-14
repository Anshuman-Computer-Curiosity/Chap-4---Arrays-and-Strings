
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string data = "Anshu 45";
    stringstream ss(data);

    string name;
    int age;
    
    ss >> name >> age ;

    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    
    stringstream ss2;
    ss2 << "Name: " << name << ", Age: " << age ;

    string result = ss2.str();
    cout << result << endl; // Display the constructed string
    
    return 0;
}