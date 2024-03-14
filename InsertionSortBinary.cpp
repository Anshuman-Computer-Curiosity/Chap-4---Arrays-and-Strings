#include <iostream>
using namespace std;

// Function to perform binary search and find the correct position for the key
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

// Function to shift elements greater than key one position ahead
void shiftElements(int arr[], int start, int end) {
    for (int i = end; i >= start; i--) {
        arr[i + 1] = arr[i];
    }
}

// Function to perform the insertion sort using binary search
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Find the correct position for key using binary search
        int pos = binarySearch(arr, 0, j, key);

        // Shift elements to make room for key
        shiftElements(arr, pos, j);

        // Insert the key element at its correct position
        arr[pos] = key;
    }
}

// Function to display the sorted array
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

    insertionSort(arr, n);

    cout << "Sorted Array: ";
    display(arr, n);

    return 0;
}