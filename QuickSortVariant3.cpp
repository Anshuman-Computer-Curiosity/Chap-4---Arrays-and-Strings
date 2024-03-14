#include <iostream>
using namespace std;

// Function to perform partitioning with the pivot as arr[high]
int partition(int arr[], int low, int high) {
    int pivot = arr[(low + high) / 2]; // Choose middle element as pivot
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

// Function to perform Quick Sort iteratively without using STL stack
void iterativeQuickSort(int arr[], int low, int high) {
    int SLow[high - low + 1];
    int SHigh[high - low + 1];
    int top = -1;

    SLow[++top] = low;
    SHigh[top] = high;

    while (top >= 0) {
        low = SLow[top];
        high = SHigh[top--];

        int pivotIndex = partition(arr, low, high);

        if (pivotIndex - 1 > low) {
            SLow[++top] = low;
            SHigh[top] = pivotIndex - 1;
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

    iterativeQuickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    display(arr, n);

    return 0;
}