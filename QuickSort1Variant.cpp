#include <iostream>

using namespace std;

// Function to perform partitioning with the pivot as arr[low]
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (true) {
        while (left <= right && arr[right] >= pivot) {
            right--;
        }

        while (left <= right && arr[left] <= pivot) {
            left++;
        }

        if (left <= right) {
            swap(arr[left], arr[right]);
        } else {
            break;
        }
    }

    swap(arr[low], arr[right]);

    return right;
}

// Function to perform quick sort iteratively without recursion
void quickSort(int arr[], int low, int high) {
    int S[high - low + 1];
    int top = -1;

    S[++top] = low;
    S[++top] = high;

    while (top >= 0) {
        high = S[top--];
        low = S[top--];

        int pivotIndex = partition(arr, low, high);

        if (pivotIndex - 1 > low) {
            S[++top] = low;
            S[++top] = pivotIndex - 1;
        }

        if (pivotIndex + 1 < high) {
            S[++top] = pivotIndex + 1;
            S[++top] = high;
        }
    }
}

// Function to display the elements of an array
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {41, 19, 65, 21, 78, 28, 87, 52, 59};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    display(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    display(arr, n);

    return 0;
}