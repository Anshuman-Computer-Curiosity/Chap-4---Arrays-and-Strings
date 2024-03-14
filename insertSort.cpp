#include <iostream>
using namespace std;

// Function to insert an element into a sorted array
void insertIntoSortedArray(int arr[], int &size, int element) {
    // Find the position where the element should be inserted
    int pos = 0;
    while (pos < size && arr[pos] < element) {
        pos++;
    }

    // Shift elements to the right to make space for the new element
    for (int i = size; i > pos; --i) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element at the desired position
    arr[pos] = element;

    // Increase the size of the array
    ++size;
}

int main() {
    int arr[] = {5, 17, 25, 31, 47};
    int size = sizeof(arr)/sizeof(int);
    int item = 20; // Element to be inserted

    // Call the insertIntoSortedArray function
    insertIntoSortedArray(arr, size, item);

    // Print the updated sorted array
    cout << "Updated Sorted Array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}