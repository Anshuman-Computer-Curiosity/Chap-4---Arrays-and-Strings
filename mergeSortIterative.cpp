
#include <iostream>
using namespace std;

// Function to merge two sorted subarrays into a single sorted array
void merge(int arr[], int left, int mid, int right) {
    // Calculate sizes of the two subarrays to be merged
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays to store the left and right subarrays
    int L[n1];
    int R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the two subarrays back into the original array arr[]
    int i = 0;
    int j = 0;
    int k = left;

    // Compare elements from L[] and R[], and merge them in ascending order
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Function to perform iterative 2-way merge sort on the array
void mergeSort(int arr[], int n) {
    int curr_size;

    // Iterate over the array with increasing subarray sizes
    for (curr_size = 1; curr_size <= n; curr_size *= 2) {
        // Iterate over the array with the current subarray size
        for (int left = 0; left < n - 1; left += 2 * curr_size) {
            // Calculate mid and right indices for the current subarray
            int mid = left + curr_size - 1;
            int right = min(left + 2 * curr_size - 1, n - 1);
            
            // Call the merge function to merge the current subarray
            merge(arr, left, mid, right);
        }
    }
}

int main() {

    // Initialize the array
    int arr[] = {41, 19, 65, 21, 78, 28, 87, 52, 59};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the original array
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Call the mergeSort function to sort the array
    mergeSort(arr, n);

    // Print the sorted array
    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}