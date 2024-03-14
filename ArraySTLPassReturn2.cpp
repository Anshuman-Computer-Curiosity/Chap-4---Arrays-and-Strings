
#include <iostream>
#include <array>
using namespace std;

// Function to insert an element at a specific position
template <size_t N>
array<int, N + 1> insertElement(const array<int, N>& arr, int element, size_t position) {
    array<int, N + 1> newArray;

    for (size_t i = 0, j = 0; i < N + 1; ++i) {
        if (i == position) {
            newArray[i] = element;
        } else {
            newArray[i] = arr[j];
            ++j;
        }
    }

    return newArray;
}

// Function to delete an element at a specific position
template <size_t N>
array<int, N - 1> deleteElement(const array<int, N>& arr, size_t position) {
    array<int, N - 1> newArray;

    for (size_t i = 0, j = 0; i < N - 1; ++i, ++j) {
        if (j == position) {
            ++j; // Skip the element at the specified position
        }
        newArray[i] = arr[j];
    }

    return newArray;
}

// Function to print elements of an array
template <size_t N>
void display(const array<int, N>& arr, const string& message) {
    cout << message;
    for (const auto& element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    array<int, 5> originalArray = {10, 20, 30, 40, 50};

    // Insert an element at position 2
    array<int, 6> newArrayInsert = insertElement(originalArray, 45, 2);

    // Delete an element at position 3
    array<int, 4> newArrayDelete = deleteElement(originalArray, 3);

    // Display the original and modified arrays using the print function
    display(originalArray, "Original Array: ");
    display(newArrayInsert, "Array after insertion: ");
    display(newArrayDelete, "Array after deletion: ");

    return 0;
}