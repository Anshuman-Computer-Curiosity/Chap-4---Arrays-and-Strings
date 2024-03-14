#include <iostream>
using namespace std;
//  int count = 0;

int ternarySearch(int arr[], int size, int itemToBeSearched) {
    int left = 0;
    int right = size - 1;

    while (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        
        // count++;
        if (arr[mid1] == itemToBeSearched) {
            // cout<<"Iterations = "<<count<<" steps"<<endl;
            return mid1;
        }
        if (arr[mid2] == itemToBeSearched) {
            // cout<<"Iterations = "<<count<<" steps"<<endl;
            return mid2;
        }

        if (itemToBeSearched < arr[mid1]) {// left portion
            right = mid1 - 1;
        } else if (itemToBeSearched > arr[mid2]) { //right portion
            left = mid2 + 1;
        } else { // middle portion
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    
    return -1;  // Element not found
}

int main() {
    int arr[] = {2, 5, 8, 13, 17, 22, 24, 39, 48, 65, 82};
    int size = sizeof(arr)/sizeof(int);
    int item = 17;

    int index = ternarySearch(arr, size, item);

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}