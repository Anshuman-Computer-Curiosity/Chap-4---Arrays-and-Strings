#include <iostream>
using namespace std;
int count = 0;

int linearSearch(int arr[], int size, int itemToBeFound) {
    // int itemIndex = -1; // not present 
    
    for (int i = 0; i < size; i++) {
        count ++;
        if (arr[i] == itemToBeFound) {
            // itemIndex = i; // Element found, save its index  
            cout<<"Loop executed "<<count<<" times."<<endl;
            return i;// Element found, save its index
        }       
    }
    
    // return itemIndex;
    return -1;//Item not found
}

int main() {
    int arr[] = {15, -2, 56, 27, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int item = 56;

    int index = linearSearch(arr, size, item);

    if (index != -1) {
        cout << "Element " <<item <<" found at index: " << index << endl;
    } else {
        cout << "Element "<< item <<" not found." << endl;
    }

    return 0;
}