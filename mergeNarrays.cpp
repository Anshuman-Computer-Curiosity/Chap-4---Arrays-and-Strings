#include <iostream>
using namespace std;
// Merge two sorted arrays into a single sorted array
void mergeTwoSortedArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        result[k++] = arr1[i++];
    }

    while (j < size2) {
        result[k++] = arr2[j++];
    }
}

// Merge multiple sorted arrays into a single sorted array
void mergeMSortedArrays(int* arrays[], int sizes[], int m, int result[]) {
    if (m < 2) {
        return; // Nothing to merge
    }

    int* tempArray = new int[sizes[0] + sizes[1]];
    mergeTwoSortedArrays(arrays[0], sizes[0], arrays[1], sizes[1], tempArray);

    // Merge the remaining arrays with the tempArray
    for (int i = 2; i < m; i++) {
        mergeTwoSortedArrays(tempArray, sizes[0] + sizes[1], arrays[i], sizes[i], result);
        for (int j = 0; j < sizes[0] + sizes[1]; j++) {
            tempArray[j] = result[j];
        }
    }

    // Copy the final result from tempArray to the actual result
    for (int i = 0; i < sizes[0] + sizes[1]; i++) {
        result[i] = tempArray[i];
    }

    delete[] tempArray;
}

int main() {
    int m = 3;
    int sizes[] = {3, 4, 3};
    int arr1[] = {1, 4, 15};
    int arr2[] = {2, 5, 8, 10};
    int arr3[] = {3, 6, 7};

    int* arrays[] = {arr1, arr2, arr3};
    int totalSize = 0;

    for (int i = 0; i < m; i++) {
        totalSize += sizes[i];
    }

    int* mergedArray = new int[totalSize];

    mergeMSortedArrays(arrays, sizes, m, mergedArray);

    // Display the merged array
    for (int i = 0; i < totalSize; i++) {
        cout << mergedArray[i] << " ";
    }

    delete[] mergedArray;

    return 0;
}