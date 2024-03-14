#include <iostream>
using namespace std;

class BubbleSort {
    private:
        int* arr;
        int size;
    public:
    // Constructor
    BubbleSort(int arrSize) : size(arrSize) {
        arr = new int[size];
    }

    // Destructor to release memory
    ~BubbleSort() {
        delete[] arr;
    }

    // Function to input elements into the array
    void inputArray() {
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    // Function to swap two integers
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Non-recursive Bubble Sort function
    void sort() {
        for (int i = 0; i < size - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Call the swap function to swap arr[j] and arr[j+1]
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                // If no swaps were made in a pass, the array is already sorted
                break;
            }
        }
    }

    // Function to display the sorted array
    void display() {
        cout << "Sorted array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Create a BubbleSort object and input the array
    BubbleSort sorter(size);
    sorter.inputArray();

    // Perform the sorting
    sorter.sort();

    // Display the sorted array
    sorter.display();

    return 0;
}