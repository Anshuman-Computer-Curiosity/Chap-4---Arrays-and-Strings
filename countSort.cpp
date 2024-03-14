
#include <iostream>
using namespace std;
// Function to find the maximum value in the array
int findMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Function to count occurrences of each element and initialize the counting array
void countOccurrences(int arr[], int n, int count[]) {
    for (int i = 0; i < n; ++i) {
        count[arr[i]]++;
    }
}

// Function to modify the counting array to store cumulative count (prefix sum)
void modifyCountArray(int count[], int maxVal) {
    for (int i = 1; i <= maxVal; ++i) {
        count[i] += count[i - 1];
    }
}

// Function to build the sorted output array
void buildOutputArray(int arr[], int n, int count[], int output[]) {
    for (int i = n - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
}

// Function to copy the output array to the original array
void copyOutputToOriginal(int arr[], int output[], int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main counting sort function
void countingSort(int arr[], int n) {
    int maxVal = findMax(arr, n);

    // Create and initialize the counting array
    int cArr[maxVal + 1] = {0};
    countOccurrences(arr, n, cArr);

    // Modify the counting array to store cumulative count
    modifyCountArray(cArr, maxVal);

    // Build the output array
    int ouArr[n];
    buildOutputArray(arr, n, cArr, ouArr);
    // Copy the output array to the original array
    copyOutputToOriginal(arr, ouArr, n);
}

int main() {
    int arr[] = {4, 2, 1, 6, 3, 5, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // Perform counting sort
    countingSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}