#include <iostream>
using namespace std;
//  int count = 0;

int ternarySearch(int arr[], int left, int right, int itemToBeSearched) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = left + 2 * (right - left) / 3;

        if (arr[mid1] == itemToBeSearched) {
            return mid1;
        }
        if (arr[mid2] == itemToBeSearched) {
            return mid2;
        }

        if (itemToBeSearched < arr[mid1]) { //left
            return ternarySearch(arr, left, mid1 - 1, itemToBeSearched);
        } else if (itemToBeSearched > arr[mid2]) {//right
            return ternarySearch(arr, mid2 + 1, right, itemToBeSearched);
        } else {//middle portion
            return ternarySearch(arr, mid1 + 1, mid2 - 1, itemToBeSearched);
        }
    }

    return -1;  // Element not found
}

int main() {
    int arr[] = {2, 5, 8, 13, 17, 22, 24, 39, 48, 65, 82};
    int size = sizeof(arr)/sizeof(int);
    int item = 17;

    int index = ternarySearch(arr, 0, size-1, item);

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}