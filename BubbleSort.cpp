#include <iostream>
using namespace std;
// int count = 0;

// Function to swap two integers
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to perform Bubble Sort
// void bubbleSort(int arr[], int n) {
void bubbleSortRec(int arr[], int n) {
    //base case
    if(n<=1){//only one element or empty array
        return;
    }
    // bool swapped;
    bool swapped=false;
    for (int j = 0; j < n - 1; j++) {
        // swapped = false;
        // for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Call the swap function to swap arr[j] and arr[j+1]
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
            // count++;
    }

        // If no two elements were swapped in the inner loop, the array is already sorted
        if (!swapped) {
            // break;
            return;
        }
    
        bubbleSortRec(arr,n-1);
    
    // cout<<"Number of iterations = "<<count<<" steps"<<endl;
}

// Function to display an array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {19, 34, 22, 44, 8, 45,2};
    
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    display(arr, n);

    bubbleSortRec(arr, n);

    cout << "Sorted array: ";
    display(arr, n);

    return 0;
}