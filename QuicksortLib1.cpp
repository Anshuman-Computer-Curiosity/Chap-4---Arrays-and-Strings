#include <iostream>
#include <algorithm> // Include the algorithm header for sort
using namespace std;

int main() {
    // Sorting an array of integers
    int arr[] = {41, 19, 65, 21, 78, 28, 87, 52, 59};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n); // Sorts the array in ascending order

    cout << "Sorted array of integers: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sorting an array of strings
    string strArr[] = {"apple",  "cherry", "banana", "date"};
    int strArrSize = sizeof(strArr) / sizeof(strArr[0]);

    sort(strArr, strArr + strArrSize); // Sorts the array of strings alphabetically

    cout << "Sorted array of strings: ";
    for (int i = 0; i < strArrSize; i++) {
        cout << strArr[i] << " ";
    }
    cout << endl;

    return 0;
}