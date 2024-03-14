
#include <iostream>
#include <vector>
using namespace std;

class MyClass {
public:
    int value;

    // Constructor
    MyClass(int val) : value(val) {}
};

// Function to modify an object by value
MyClass modifyObjectByValue(MyClass obj) {
    obj.value += 10;
    return obj;
}

// Function to modify an object by reference
void modifyObjectByReference(MyClass& obj) {
    obj.value += 10;
}

int main() {
    // Create an object
    MyClass myObject(25);

    // Pass and return by value
    MyClass modifiedByValue = modifyObjectByValue(myObject);

    cout << "After modifyObjectByValue, original value: " << myObject.value << "\n";
    cout << "After modifyObjectByValue, modified value: " << modifiedByValue.value << "\n\n";

    // Pass by reference
    modifyObjectByReference(myObject);

    cout << "After modifyObjectByReference, original value: " << myObject.value << "\n";

    return 0;
}