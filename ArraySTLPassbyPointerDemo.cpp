
//Passing array by Pointer
#include <iostream>
#include <array>
using namespace std;

// Function that takes a array by pointer
void printArray( array<int, 5>* arr) {
    for ( auto& element : *arr) {
        element += 5;
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    array<int, 5> myArray = {10, 20, 30, 40, 50};

    // Pass the address of the array to the function
    printArray(&myArray);
    for ( auto& element : myArray) {

        cout << element << " ";
    }
    cout << endl;

    return 0;
}