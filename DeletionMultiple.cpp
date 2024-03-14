#include <iostream>
using namespace std;

// Function to remove all occurrences of a specific value from an array
void removeAllOccurrences(int arr[], int& size, int valueToRemove) {
    int newSize = 0;
    int newArray[size]; // Create a new array to hold the modified elements

    // Copy elements to the new array, skipping those with the specified value
    for (int i = 0; i < size; ++i) {
        if (arr[i] != valueToRemove) {
            newArray[newSize] = arr[i];
            ++newSize;
        }
    }

    size = newSize; // Update the size to reflect the removal

    // Copy the elements back to the original array
    for (int i = 0; i < size; ++i) {
        arr[i] = newArray[i];
    }
}

int main() {
    int myArray[] = {25, 15, 25, 45, 25, 60, 30};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    int valueToRemove = 25; // Remove all occurrences of the value 2
    cout << "Original Array: ";
    for (int i = 0; i < size; ++i) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    removeAllOccurrences(myArray, size, valueToRemove);

    cout << "Modified Array: ";
    for (int i = 0; i < size; ++i) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    return 0;
}