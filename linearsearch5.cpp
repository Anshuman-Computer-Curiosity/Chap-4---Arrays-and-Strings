//search for multiple occurences
#include <iostream>
#include <vector>
using namespace std;

vector<int> linearSearchAll(int arr[], int size, int target) {
    vector<int> indices;

    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            indices.push_back(i); // Store the indices of all occurrences
        }
    }

    return indices;
}

int main() {
    int arr[] = {10, 15, 30, 15, 40, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int itemToBeSearched = 15;

    vector<int> indices = linearSearchAll(arr, size, itemToBeSearched);

    if (!indices.empty()) {
        cout << "Element " << itemToBeSearched << " found at indices: ";
        for (int index : indices) {
            cout << index << " ";
        }
        cout << endl;
    } else {
        cout << "Element " << itemToBeSearched << " not found in the array." << endl;
    }

    return 0;
}