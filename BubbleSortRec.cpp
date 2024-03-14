#include <iostream>
using namespace std;

// Function to swap two integers
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Recursive Bubble Sort function
void recursiveBubbleSort(int arr[], int n) {
    // Base case: If there is only one element or the array is empty, it is already sorted
    if (n <= 1) {
        return;
    }

    bool swapped = false;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            // Call the swap function to swap arr[i] and arr[i+1]
            swap(arr[i], arr[i + 1]);
            swapped = true;
        }
    }

    // If no two elements were swapped in the inner loop, the array is already sorted
    if (!swapped) {
        return;
    }

    // Recursively call the function on the remaining unsorted portion of the array
    recursiveBubbleSort(arr, n - 1);
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

    cout << "Original array: ";
    display(arr, n);

    recursiveBubbleSort(arr, n);

    cout << "Sorted array: ";
    display(arr, n);

    return 0;
}