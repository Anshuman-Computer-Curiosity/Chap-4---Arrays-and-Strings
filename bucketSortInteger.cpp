#include <iostream>
using namespace std;

// A simple insertion sort function
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

// Find the minimum value in the array
int findMin(int arr[], int n) {
    int minValue = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }
    return minValue;
}

// Find the maximum value in the array
int findMax(int arr[], int n) {
    int maxValue = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

// Determine the range of values in the array
int findRange(int arr[], int n) {
    return findMax(arr, n) - findMin(arr, n) + 1;
}

// Distribute elements into buckets based on the specified range
void distributeIntoBuckets(int arr[], int n, int buckets[][10], int bucketSizes[], int bucketCount) {
    int minValue = findMin(arr, n);
    int range = findRange(arr, n);

    // Display the distribution details
    cout << "Distribution of Elements into Buckets:\n";
    for (int i = 0; i < n; ++i) {
        int bucketIndex = (arr[i] - minValue) * bucketCount / range;

        // Display the element and its corresponding bucket
        cout << "Element " << arr[i] << " into Bucket " << bucketIndex << endl;

        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }
}

// Sort each bucket using insertion sort
void sortBuckets(int buckets[][10], int bucketSizes[], int bucketCount) {
    for (int i = 0; i < bucketCount; ++i) {
        insertionSort(buckets[i], bucketSizes[i]);
    }
}

// Concatenate the buckets to get the sorted array
void concatenateBuckets(int arr[], int buckets[][10], int bucketSizes[], int bucketCount) {
    int index = 0;
    for (int i = 0; i < bucketCount; ++i) {
        for (int j = 0; j < bucketSizes[i]; ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

// Bucket sort function
void bucketSort(int arr[], int n) {
    const int bucketCount = 5; // You can choose the number of buckets
    int buckets[bucketCount][10];

    // Initialize bucket sizes to 0
    int bucketSizes[bucketCount] = {0};

    // Distribute elements into buckets
    distributeIntoBuckets(arr, n, buckets, bucketSizes, bucketCount);

    // Sort each bucket using insertion sort
    sortBuckets(buckets, bucketSizes, bucketCount);

    // Concatenate the buckets to get the sorted array
    concatenateBuckets(arr, buckets, bucketSizes, bucketCount);
}
// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 19, 5, 17, 16, 1, 12, 21, 24, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    bucketSort(arr, n);

    cout << "\nSorted array: ";
    printArray(arr, n);

    return 0;
}