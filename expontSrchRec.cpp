//Recursive approach
#include <iostream>
#include <cmath>
using namespace std;

int binarySearch(int arr[], int beg, int end, int item) {
    if (beg <= end) {
        int mid = (beg + end) / 2;

        if (arr[mid] == item)
            return mid;
        else if (arr[mid] < item)
            return binarySearch(arr, mid + 1, end, item);
        else
            return binarySearch(arr, beg, mid - 1, item);
    }

    return -1; // Element not found
}

int exponentialSearch(int arr[], int n, int item, int i = 1) {
    if (i >= n || arr[i] > item)
        return binarySearch(arr, i / 2, min(i, n - 1), item);

    return exponentialSearch(arr, n, item, i * 2);
}

int main() {
    int arr[] = {9, 12, 14, 16, 18, 19, 21, 23, 26, 32, 35, 43, 45};
    int size = sizeof(arr)/sizeof(int);
    int itemToBeFound = 26;

    int index = exponentialSearch(arr, size, itemToBeFound);
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}