
//Dynamically declare array

#include <iostream>
using namespace std;
int main() {
    // Dynamically allocate a character array
    const int size = 5;  // Set the size of the array
    char* dynamicCharArray = new char[size];

    // Initialize the dynamic character array
    for (int i = 0; i < size - 1; ++i) {
        dynamicCharArray[i] = 'A' + i;  // Assigning values for demonstration
    }

    // Null-terminate the dynamic character array
    dynamicCharArray[size - 1] = '\0';

    // Access and print the dynamic character array
    for (int i = 0; dynamicCharArray[i] != '\0'; ++i) {
        cout << dynamicCharArray[i] << " ";
    }

    // Deallocate the memory to avoid memory leaks
    delete[] dynamicCharArray;

    return 0;
}