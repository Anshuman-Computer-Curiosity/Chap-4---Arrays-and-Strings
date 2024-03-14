#include <iostream>
using namespace std;
 int count = 0;

int binarySearch(int arr[], int size, int itemToBeSearched) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
         count++;
        int mid = (right + left ) / 2;
    
        if (arr[mid] == itemToBeSearched) {
             cout<<"Loop executed "<<count<<" times."<<endl;
            return mid; // Element found, return its index
        } else if (arr[mid] < itemToBeSearched) {
            left = mid + 1; // Search the right half
        } else {
            right = mid - 1; // Search the left half
        }
    }
    
    return -1; // Element not found
}

int main() {
    int arr[] = {2, 5, 8, 13, 17, 22, 24, 39, 48, 65, 82};
    int size = sizeof(arr)/sizeof(int);
    int item = 82;

    int index = binarySearch(arr, size, item);

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}