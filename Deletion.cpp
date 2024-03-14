#include <iostream>
using namespace std;

// Function to remove an element at a specified index from an array
// void removeElement(int arr[], int &size, int index) {
    void removeElementRec(int arr[], int &size, int index, int currIndex = 0) {
    // Check if the index is valid
    // if (index >= 0 && index < size) 
    // base case
    if(currIndex==size || currIndex>=size){
        return ;
    }
        if(currIndex == index){
        // Shift elements to the up to overwrite the element at the specified index
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        
    
        // Decrease the size of the array
        --size;
        }
        removeElementRec(arr, size, index, currIndex + 1);
    
}

int main() {
    int myArray[] = {25, 17, 45, 31, 10};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    
    // Remove element at index 2 (3rd element)
    int indexToDelete = 2; 
    // Print the original array
    for (int i = 0; i < size; ++i) {
        cout << myArray[i] << " ";
    }
    cout << endl;
    
    removeElementRec(myArray, size, indexToDelete);

    // Print the modified array
    for (int i = 0; i < size; ++i) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    return 0;
}