#include <iostream>
using namespace std;
int count1 = 0;
int count2 = 0;
// Function to find the index of the minimum element in a specified range
int findMinIndex(int arr[], int beg, int end) {
    int minIndex = beg;
    for (int i = beg + 1; i <= end; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
        count2++;
    }
    
    return minIndex;
}

// Function to swap two elements in an array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to display the elements of an array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    for (int beg = 0; beg < n - 1; beg++) {
        // Find the index of the minimum element in the unsorted portion
        int minIndex = findMinIndex(arr, beg, n - 1);

        // Swap the minimum element with the first element in the unsorted portion
        if (minIndex != beg) {
            swap(arr, beg, minIndex);
        }
        count1++;
    }

   
}

int main() {
    int arr[] = {19, 34, 22, 44, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    display(arr, n);

    selectionSort(arr, n);

    cout<<"Total iterations = "<<count1+count2<<endl;

    cout << "Sorted array: ";
    display(arr, n);

    return 0;
}