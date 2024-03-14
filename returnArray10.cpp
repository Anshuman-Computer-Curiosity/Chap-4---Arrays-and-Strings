#include <iostream>

int* &func() {
    int* arr = new int[5];

    // Initialize or populate the array
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    return arr;
}

int main() {
    int* &myArray = func();

    // Use the array
    for (int i = 0; i < 5; i++) {
        std::cout << myArray[i] << " ";
    }

    // Don't forget to deallocate the memory after you are done using the array
    delete[] myArray;

    return 0;
}