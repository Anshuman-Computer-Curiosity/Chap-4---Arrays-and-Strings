//return array using reference variable
#include <iostream>
using namespace std;

int* &func() {
// void func(int (&arr)[5]) {
    // Initialize or populate the array
    static int *arr= new int[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = 10*(i + 1);
    }
    return arr;
}
int main() {
    // int myArray[5];
    // func(myArray);
    // int (&myArray)[5]= func();
    int* &myArray = func();
    // Use the array
    for (int i = 0; i < 5; i++) {
        cout << myArray[i] << " ";
    }
    delete[] myArray;
    return 0;
}