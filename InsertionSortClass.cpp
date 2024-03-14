#include <iostream>
using namespace std;

class InsertionSort {
    private:
    int* arr;
    int arraySize;
public:
    // Constructor to initialize the array and its size
    InsertionSort(int n) : arraySize(n) {
        arr = new int[arraySize]; // Dynamically allocate memory for the array
    }

    // Function to move elements greater than key one position ahead
    void shiftElements(int j, int key) {
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    // Function to perform the insertion sort
    void insertionSort() {
        for (int i = 1; i < arraySize; i++) {
            int key = arr[i];
            int j = i - 1;

            // Call the shiftElements method
            shiftElements(j, key);
        }
    }

    // Function to display the array
    void display() {
        for (int i = 0; i < arraySize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor to deallocate memory
    ~InsertionSort() {
        delete[] arr; // Deallocate the dynamically allocated memory
    }

    // Function to set an element at a specific index
    void setElement(int index, int value) {
        if (index >= 0 && index < arraySize) {
            arr[index] = value;
        }
    }

};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Create an InsertionSort object with a dynamically allocated array
    InsertionSort sorter(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        sorter.setElement(i, value); // Set elements using the setElement function
    }

    cout << "Original Array: ";
    sorter.display();

    // Perform Insertion Sort
    sorter.insertionSort();

    cout << "Sorted Array: ";
    sorter.display();

    return 0;
}