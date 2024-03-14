#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low + (high - low) / 2]; // Choose middle element as pivot
    int left = low;
    int right = high;

    while (true) {
        while (arr[right] > pivot) {
            right--;
        }
        while (arr[left] < pivot) {
            left++;
        }
        if (left >= right) {
            return right;
        }
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {41, 19, 65, 35, 21, 78, 28, 87, 52, 59};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}