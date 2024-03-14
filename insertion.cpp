#include <iostream>
using namespace std;

// Function to insert an element into an array
// void insertElement(int arr[], int &size, int element, int pos) {
void insertSort(int arr[], int &size, int element) {

    // Check if the pos is valid
    // if (pos < 0 || pos > size) {
    //     cout << "Invalid position for insertion." << endl;
    //     return;
    // }
    int pos = 0;
    while (pos <size && arr[pos]<element){
        pos++;
    }
    
    // Shift eleemnts to the right to make space for the new element
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element at the desired position
    arr[pos] = element;

    // Increase the size of the array
   size = size + 1;
}

int main() {
    int arr[] = {5, 17, 25, 31, 47};
    int size = sizeof(arr)/sizeof(int);
    int item = 20; // Element to be inserted
    // int position = 2; // Position at which the element should be inserted

    cout<<"Original Array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    // insertElement(arr, size, item, position);
    insertSort(arr, size, item);
    
    // Print the updated array
    cout<<"Updated Array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout<<endl;

    return 0;
}