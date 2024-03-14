#include <iostream>
using namespace std;
class MyClass {
    public:
    int value; // data member
    MyClass() {value = 5;} //ctor
};
int main() {
    // Declare an array of objects
    // MyClass objects[3] = {MyClass(10), MyClass(20), MyClass(30)};
    MyClass *ptrobject = new MyClass[3];
    // Access and print the values of the objects
    for (int i = 0; i < 3; ++i) {
        cout << "Object " << i  << ": " << (ptrobject + i)->value << endl;
    }
    return 0;
}