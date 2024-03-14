//Another way
#include <iostream>
using namespace std;

// Function to remove all occurrences of a specific value from an array
int* removeAllOccurrences(int arr[], int& size, int valueToRemove) {
    int count = 0;

    // Count the occurrences of the value to be removed
    for (int i = 0; i < size; ++i) {
        if (arr[i] == valueToRemove) {
            ++count;
        }
    }

    if (count == 0) {
        return arr; // No occurrences found, return the original array
    }

    int newSize = size - count;
    int* newArray = new int[newSize];
    int newArrayIndex = 0;

    // Copy elements to the new array, skipping those with the specified value
    for (int i = 0; i < size; ++i) {
        if (arr[i] != valueToRemove) {
            newArray[newArrayIndex] = arr[i];
            ++newArrayIndex;
        }
    }

    size = newSize; // Update the size
    delete[] arr;   // Delete the old array
    return newArray; // Return the new array
}

int main() {
    int myArray[] = {25, 15, 25, 45, 25, 60, 30};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    int valueToRemove = 25; // Remove all occurrences of the value 2

    

    int* modifiedArray = removeAllOccurrences(myArray, size, valueToRemove);

    cout << "Modified Array: ";
    for (int i = 0; i < size; ++i) {
        cout << modifiedArray[i] << " ";
    }
    cout << endl;

    delete[] modifiedArray; // Don't forget to delete the modified array when done

    return 0;
}