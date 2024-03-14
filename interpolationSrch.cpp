#include <iostream>
using namespace std;
int count = 0;

int interpolationSearch(int arr[], int size, int item) {
    int low = 0;
    int high = size - 1;

    while (low <= high && item >= arr[low] && item <= arr[high]) {
        int pos = low + ((item - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        count++;
        if (arr[pos] == item) {
            cout<<"Loop executes "<< count<<" times."<<endl;
            return pos; // Element found, return its index
        } else if (arr[pos] < item) {
            low = pos + 1; // Search the right part
        } else {
            high = pos - 1; // Search the left part
        }

    }

    return -1; // Element not found
}

int main() {
    int arr[] = {9, 12, 14, 16, 18, 19, 21, 23, 26, 32, 35, 43, 45};
    int size = sizeof(arr)/sizeof(int);
    int itemToBeSearched = 45;

    int index = interpolationSearch(arr, size, itemToBeSearched);

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}