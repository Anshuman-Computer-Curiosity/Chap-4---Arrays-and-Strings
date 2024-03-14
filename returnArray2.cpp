// dynamically allocate array - return pointer to array
#include <iostream>
using namespace std;
int* func() {
    int* arr = new int[5];
    for (int i = 0; i < 5; i++) {// Initialize or populate the array
        arr[i] = 10*(i + 1);
    }
    return arr;
}

int main() {
    int* ptrToArray = func();
    // Use the array
    for (int i = 0; i < 5; i++) {
        cout << ptrToArray[i] << " ";
    }
    delete[] ptrToArray; 
    return 0;
}