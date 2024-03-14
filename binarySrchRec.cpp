//Recursive way
#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int low, int high, int itemToBeSearched) {
    if (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == itemToBeSearched) {
            return mid; // Element found at index mid
        } else if (arr[mid] < itemToBeSearched) {
            return binarySearchRecursive(arr, mid + 1, high, itemToBeSearched); // Search the right half
        } else {
            return binarySearchRecursive(arr, low, mid - 1, itemToBeSearched); // Search the left half
        }
    }

    return -1; // Element not found
}

int main() {
    int arr[] = {2, 5, 8, 13, 17, 22, 24, 39, 48, 65, 82};
    int size = sizeof(arr)/sizeof(int);
    int item = 48;

    int index = binarySearchRecursive(arr, 0, size - 1, item);

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}