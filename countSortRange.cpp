#include <iostream>
using namespace std;

//function to find max. and min. value and hence range
void findRange(int arr[], int n, int& minVal, int& maxVal) {
    minVal = arr[0];
    maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }
}

//count array indexed by values of input array
//each element is count of values
void countOccurrences(int arr[], int n, int minVal, int count[]) {
    for (int i = 0; i < n; ++i) {
        count[arr[i] - minVal]++;
        // subtracting minVal ensures count array 
        //is properly aligned with range of values
    }
}

//modify count array to store cumulative sum
//iterting over range ensure every possible value in range
// has corresponding index
void modifyCountArray(int count[], int range) {
    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }
}


//iterating in reverse ensure element with same key are placed in
//output array in same order
void buildOutputArray(int arr[], int n, int minVal, int count[], int output[]) {
    for (int i = n - 1; i >= 0; --i) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countingSort(int arr[], int n) {
    // Find the range of values in the array
    int minVal, maxVal;
    findRange(arr, n, minVal, maxVal);

    // Create and initialize the counting array
    int range = maxVal - minVal + 1;
    int count[range] = {0};

    // Count occurrences of each element
    countOccurrences(arr, n, minVal, count);

    // Modify the counting array to store cumulative count
    modifyCountArray(count, range);

    // Build the output array
    int output[n];
    buildOutputArray(arr, n, minVal, count, output);

    // Copy the output array to the original array
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {4, 2, 1, 6, 3, 5, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    countingSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}