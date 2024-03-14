//using continue to skip the statement when found
#include <iostream>
using namespace std;
int count = 0;

int linearSearchWithContinue(int arr[], int size, int itemToBeFound) {
    int index = -1;
    
    for (int i = 0; i < size; i++) {
        count ++;
        if (arr[i] != itemToBeFound) {
            continue; // Skip to the next iteration if the element is not the target
        }

        index = i; // Element found, save its index
        break; // Exit the loop as we have found the element
    }    
    cout<<"Loop executed = " << count << " times."<<endl;
    return index;
}

int main() {
    int arr[] = {15, -2, 56, 27, 9};
    int size = sizeof(arr)/sizeof(int);
    int item = 56;

    int index = linearSearchWithContinue(arr, size, item);

    if (index != -1) {
        cout << "Element " <<item <<" found at index: " << index << endl;
    } else {
        cout << "Element "<< item <<" not found." << endl;
    }

    return 0;
}