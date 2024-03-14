//wrap array in a structure
#include <iostream>
using namespace std;
// Custom struct to wrap the array
struct ArrayWrapper {
    int arr[5]; // Array of size 5
    int size; // Size of the array
};

ArrayWrapper createArray() {
    ArrayWrapper wrapVar;
    wrapVar.size = 5;
    for (int i = 0; i < wrapVar.size; i++) {
        wrapVar.arr[i] = 10*(i + 1);
    }
    return wrapVar;
}

int main() {
    ArrayWrapper myArray = createArray();

    // Accessing the array elements through the struct
    for (int i = 0; i < myArray.size; i++) {
        cout << myArray.arr[i] << " ";
    }
    cout << endl;

    return 0;
}