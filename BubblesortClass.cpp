#include <iostream>
using namespace std;

class BubbleSort {
private:
    int* arr;
    int size;
public:
    // Constructor
    BubbleSort(int myArr[], int arrSize) : arr(myArr), size(arrSize) {}

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
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


};

int main() {
    int arr[] = {19, 34, 22, 44, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Create a BubbleSort object and perform the sorting
    BubbleSort sorter(arr, size);
    sorter.sort();

    cout << "Sorted array: ";
    sorter.display();

    return 0;
}