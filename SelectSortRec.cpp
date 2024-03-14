#include <iostream>

using namespace std;

// Function to find the index of the minimum element in a specified range
int findMinIndex(int arr[], int start, int end) {
    int minIndex = start;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to swap two elements in an array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to display the elements of an array
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to perform recursive selection sort
void recursiveSelectionSort(int arr[], int size, int beg = 0) {
    if (beg == size - 1) {
        // Base case: When the entire array is sorted
        return;
    }

    // Find the index of the minimum element in the unsorted portion
    int minIndex = findMinIndex(arr, beg, size - 1);

    // Swap the minimum element with the current element
    if (minIndex != beg) {
        swap(arr, beg, minIndex);
    }

    // Recursively sort the rest of the array
    recursiveSelectionSort(arr, size, beg + 1);
}

int main() {
    int arr[] = {19, 34, 22, 44, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    display(arr, n);

    recursiveSelectionSort(arr, n);

    cout << "Sorted array: ";
    display(arr, n);

    return 0;
}