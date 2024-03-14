#include <iostream>

using namespace std;

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (true) {
        while (left <= right && arr[right] >= pivot) {
            right--;
        }
        
        while (left <= right && arr[left] <= pivot) {
            left++;
        }

        if (left <= right) {
            swap(arr[left], arr[right]);
        } else {
            break;
        }
    }

    swap(arr[low], arr[right]);
    return right;
}

// Recursive Quick Sort
void recursiveQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the left and right sub-arrays
        recursiveQuickSort(arr, low, pivotIndex - 1);
        recursiveQuickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int arr[] = {41, 19, 65, 35, 21, 78, 28, 87, 52, 59};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    recursiveQuickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}