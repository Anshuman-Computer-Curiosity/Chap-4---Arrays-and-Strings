#include <iostream>

using namespace std;

// Function to perform partitioning with the pivot as arr[mid]
int partition(int arr[], int low, int high) {
    int pivot = arr[low + (high - low) / 2]; // Choose middle element as pivot
    int left = low;
    int right = high;

    while (true) {
        while (arr[right] > pivot) {
            right--;
        }
        while (arr[left] < pivot) {
            left++;
        }
        if (left >= right) {
            return right;
        }
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

// Function to perform quick sort iteratively without recursion using two stack arrays
void quickSort(int arr[], int low, int high) {
    int SLow[high - low + 1]; // Stack for lower bounds
    int SHigh[high - low + 1]; // Stack for upper bounds
    int top = -1;

    SLow[++top] = low;
    SHigh[top] = high;

    while (top >= 0) {
        low = SLow[top];
        high = SHigh[top--];

        int pivotIndex = partition(arr, low, high);

        if (low < pivotIndex) {
            SLow[++top] = low;
            SHigh[top] = pivotIndex;
        }

        if (pivotIndex + 1 < high) {
            SLow[++top] = pivotIndex + 1;
            SHigh[top] = high;
        }
    }
}
// Function to display the elements of an array
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {41, 19, 65, 21, 78, 28, 87, 52, 59};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    display(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    display(arr, n);

    return 0;
}