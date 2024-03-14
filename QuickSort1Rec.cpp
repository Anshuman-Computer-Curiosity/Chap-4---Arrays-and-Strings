#include <iostream>

using namespace std;

// Function to perform partitioning
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

// Recursive function to perform Quick Sort
void quickSortRecursive(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the elements before and after the pivot
        quickSortRecursive(arr, low, pivotIndex - 1);
        quickSortRecursive(arr, pivotIndex + 1, high);
    }
}

// Wrapper function for Quick Sort
void quickSort(int arr[], int size) {
    quickSortRecursive(arr, 0, size - 1);
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

    quickSort(arr, n - 1);

    cout << "Sorted array: ";
    display(arr, n);

    return 0;
}