
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

// Counting Sort function for sorting based on digits
void countingSortByDigit(int arr[], int n, int exp, int base) {
    const int maxDigits = 10; // Maximum number of digits in base 10

    // Create and initialize the counting array
    int count[maxDigits] = {0};

    // Count occurrences of each digit at the current place value
    for (int i = 0; i < n; ++i) {
        int digit = (arr[i] / exp) % base;
        count[digit]++;
    }

    // Modify the counting array to store cumulative count
    for (int i = 1; i < maxDigits; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output array based on the current digit
    int output[n];
    for (int i = n - 1; i >= 0; --i) {
        int digit = (arr[i] / exp) % base;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array to the original array
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(int arr[], int n, int base) {
    // Find the maximum value in the array
    int maxVal = findMax(arr, n);

    // Perform counting sort for each digit place value
    for (int exp = 1; exp <= maxVal; exp *= base) {
        countingSortByDigit(arr, n, exp, base);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {315, 792, 212, 1215, 95, 575, 941};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // Perform Radix Sort with base 10
    radixSort(arr, n, 10);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}