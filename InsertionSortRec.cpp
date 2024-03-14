#include <iostream>
using namespace std;

// Function to shift elements greater than key one position ahead
void shiftElements(int arr[], int j, int key) {
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

// Recursive function to perform Insertion Sort
void insertionSortRecursive(int arr[], int n) {
    // Base case: If there's only one element or the array is empty, it's already sorted.
    if (n <= 1) {
        return;
    }

    // Sort the first n-1 elements recursively
    insertionSortRecursive(arr, n - 1);

    // Insert the last element (arr[n-1]) into the sorted part of the array
    int key = arr[n - 1];
    int j = n - 2;

    // Use the shiftElements function to move elements to their correct positions
    shiftElements(arr, j, key);
}

// Function to display an array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {19, 34, 22, 44, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    display(arr, n);

    insertionSortRecursive(arr, n);

    cout << "Sorted Array: ";
    display(arr, n);

    return 0;
}