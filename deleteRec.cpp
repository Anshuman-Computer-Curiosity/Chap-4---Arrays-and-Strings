#include <iostream>
using namespace std;

void removeAtIndex(int arr[], int& size, int indexToRemove, int currentIndex = 0) {
    // Base case: If currentIndex reaches the end of the array or exceeds the size, return.
    if (currentIndex == size || currentIndex >= size) {
        return;
    }

    // If the current index matches the index to remove, shift elements to the left.
    if (currentIndex == indexToRemove) {
        for (int i = currentIndex; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        // Reduce the size of the array.
        --size;
    }

    // Recursively process the next index.
    removeAtIndex(arr, size, indexToRemove, currentIndex + 1);
}

int main() {
    int myArray[] = {25, 17, 45, 31, 10};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    
    // Remove element at index 2 (3rd element)
    int indexToRemove = 2; 
    removeAtIndex(myArray, size, indexToRemove);

    cout << "Modified Array: ";
    for (int i = 0; i < size; ++i) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    return 0;
}