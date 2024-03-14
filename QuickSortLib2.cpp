#include <iostream>
#include <cstdlib> // Include the C standard library header for qsort
using namespace std;

// Custom comparison function for qsort
int compare(const void* a, const void* b) {
    // Cast the void pointers to the appropriate data types
    int intA = *(const int*)a;
    int intB = *(const int*)b;

    // Implement your custom comparison logic here
    return intA - intB; // Sort in ascending order
}

int main() {
    int arr[] = {41, 19, 65, 21, 78, 28, 87, 52, 59};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using qsort
    qsort(arr, n, sizeof(int), compare);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}