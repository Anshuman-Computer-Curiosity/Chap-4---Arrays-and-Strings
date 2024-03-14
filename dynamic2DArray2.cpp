#include <iostream>
using namespace std;
int main() {
    int * dynamicArray[2]; // Example with 2 rows
   // Allocate memory for each row
    for (int i = 0; i < 2; i++) {
        dynamicArray[i] = new int[3] {10,20,30};
    }

    //Assign values and print addresses
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
          //*  (*(dynamicArray+i)+j) = 10 * (i + 1) + j; // Assigning values
          //dynamicArray[i][j] = 10 * (i + 1) + j; // Assigning values
            cout << dynamicArray[i][j] << " "<<&dynamicArray[i][j]<<endl; // Print addresses
        }
    }

    // Deallocate memory
    for (int i = 0; i < 2; i++) {
        delete[] dynamicArray[i];
    }

    return 0;
}