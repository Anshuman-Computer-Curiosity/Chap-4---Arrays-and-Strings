#include <iostream>
using namespace std;

// Function to move elements greater than key one position ahead
void shiftElements(int arr[], int j, int key) {
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

// Function to perform the insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        shiftElements(arr, j, key);
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