#include <iostream>
using namespace std;
// Function to perform insertion sort on an array
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Function to merge and sort two arrays using insertion sort
void mergeAndSortArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    // Copy elements from arr1 to result
    for (int i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }

    // Copy elements from arr2 to result starting at the end of arr1
    for (int i = 0; i < size2; i++) {
        result[size1 + i] = arr2[i];
    }

    // Perform insertion sort on the result array
    insertionSort(result, size1 + size2);
}

int main() {
    int arr1[] = {3, 5, 7, 9};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 6, 10, 11, 15};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int mergedSize = size1 + size2;
    int mergedArray[mergedSize];

    mergeAndSortArrays(arr1, size1, arr2, size2, mergedArray);

    // Display the merged and sorted array
    for (int i = 0; i < mergedSize; i++) {
        cout << mergedArray[i] << " ";
    }

    return 0;
}