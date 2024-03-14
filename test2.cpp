#include <iostream>
using namespace std;

// Function to find the index of the minimum element in a specified range
int findMinIndex(int arr[], int beg, int end) {
    int minIndex = beg;
    for (int i = beg + 1; i <= end; i++) {
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
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to perform selection sort and count steps
void selectionSort(int arr[], int n) {
    int steps = 0; // Initialize the step counter

    for (int beg = 0; beg < n - 1; beg++) {
        // Find the index of the minimum element in the unsorted portion
        int minIndex = findMinIndex(arr, beg, n - 1);

        // Swap the minimum element with the first element in the unsorted portion
        if (minIndex != beg) {
            swap(arr, beg, minIndex);
        }

        steps++; // Increment the step counter after each comparison or swap
    }

    cout << "Total steps/iterations: " << steps << endl;
}

int main() {
    int arr[] = {19, 34, 22, 44, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    display(arr, n);

    selectionSort(arr, n);

    cout << "Sorted array: ";
    display(arr, n);

    return 0;
}