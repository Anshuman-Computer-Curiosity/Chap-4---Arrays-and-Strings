#include <iostream>
#include <cmath>
using namespace std;
int count = 0;

int jumpSearch(int arr[], int size, int item) {
    int step = sqrt(size); // Determine the jump size
    int left = 0;
    int right = 0;

    // Finding the block where the item may exist
    while (right < size && arr[right] < item) {
        left = right;
        right += step;
    }

    // Linear search within the identified block
    for (int i = left; i <= min(right, size - 1); i++) {
        count++;
        if (arr[i] == item) {
            cout<<"Loop executes "<<count<<" times"<<endl;
            return i;
        }
    }   
    return -1; // Element not found
}

int main() {
    int arr[] = {9, 12, 14, 16, 18, 19, 21, 23, 26, 32, 35, 43, 45};
    int size = sizeof(arr)/sizeof(int);
    int itemToBeFound = 26;

    int index = jumpSearch(arr, size, itemToBeFound);

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}