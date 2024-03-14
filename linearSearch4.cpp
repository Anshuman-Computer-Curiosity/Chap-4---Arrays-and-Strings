//with use of recursion
#include <iostream>
using namespace std;
int count = 0;

int linearSearchRecursion(int arr[], int size, int itemToBeFound, int index) {
    if (index >= size) {
        return -1; // Element not found
    }
    
    if (arr[index] == itemToBeFound) {
        return index; // Element found, return its index
    }

    return linearSearchRecursion(arr, size, itemToBeFound, index + 1);
}

int main() {
    int arr[] = {15, -2, 56, 27, 9};
    int size = sizeof(arr)/sizeof(int);
    int item = 56;

    int index = linearSearchRecursion(arr, size, item,0);

    if (index != -1) {
        cout << "Element " <<item <<" found at index: " << index << endl;
    } else {
        cout << "Element "<< item <<" not found." << endl;
    }

    return 0;
}