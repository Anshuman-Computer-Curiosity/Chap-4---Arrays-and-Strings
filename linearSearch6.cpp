//item to be found occurs multiple times
#include <iostream>
using namespace std;
const int MAX_OCCURRENCES = 100; // Maximum number of occurrences

int linearSearchMultiple(const int arr[], int size, int target, int indices[]) {
    int count = 0; // Count of occurrences

    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            indices[count] = i; // Store the index of the found element
            count++;

            if (count == MAX_OCCURRENCES) {
                break; // Break if the maximum occurrences are reached
            }
        }
    }

    return count; // Return the count of occurrences
}

int main() {
    int arr[] = {10, 15, 30, 15, 40, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int itemToBeSearched = 15;

    int indices[MAX_OCCURRENCES]; // Array to store indices
    int count = linearSearchMultiple(arr, size, itemToBeSearched, indices);

    if (count > 0) {
        cout << "itemToBeSearched found at indices: ";
        for (int i = 0; i < count; ++i) {
            cout << indices[i] << " ";
        }
        cout << endl;
    } else {
        cout << "itemToBeSearched not found in the array." << endl;
    }

    return 0;
}