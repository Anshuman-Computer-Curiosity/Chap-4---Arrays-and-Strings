#include <iostream>
using namespace std;

// Function to find the maximum value in the array
double findMax(double arr[], int n) {
    double maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Function to distribute elements into buckets
void distributeIntoBuckets(double arr[], int n, double buckets[][10], int bucketSizes[], double maxVal) {
    const int maxBuckets = 10;

    for (int i = 0; i < n; ++i) {
        int bucketIndex = maxBuckets * (arr[i] / (maxVal + 1)); // Fix here, add 1 to maxVal
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }
}

// Function to perform insertion sort within each bucket
void insertionSort(double bucket[], int size) {
    for (int i = 1; i < size; ++i) {
        double key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j = j - 1;
        }

        bucket[j + 1] = key;
    }
}

// Function to concatenate sorted buckets into the final array
void mergeBuckets(double arr[], double buckets[][10], int bucketSizes[]) {
    int index = 0;
    const int maxBuckets = 10;

    for (int i = 0; i < maxBuckets; ++i) {
        for (int j = 0; j < bucketSizes[i]; ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

// Function to perform Bucket Sort
void bucketSort(double arr[], int n) {
    const int maxBuckets = 10;

    // Create arrays for buckets and bucket sizes
    double buckets[maxBuckets][10] = {0};
    int bucketSizes[maxBuckets] = {0};

    // Find the maximum value in the array
    double maxVal = findMax(arr, n);

    // Distribute elements into buckets
    distributeIntoBuckets(arr, n, buckets, bucketSizes, maxVal);

    // Sort elements within each bucket using insertion sort
    for (int i = 0; i < maxBuckets; ++i) {
        insertionSort(buckets[i], bucketSizes[i]);
    }

    // Concatenate the sorted buckets to get the final sorted array
    mergeBuckets(arr, buckets, bucketSizes);
}

// Function to print an array
void printArray(double arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    double arr[] = {0.89, 0.32, 0.53, 0.52, 0.37, 0.17, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, n);

    // Perform Bucket Sort
    bucketSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}