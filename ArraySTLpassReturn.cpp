
//Pass and return  std::array to/from a function
#include <iostream>
#include <array>
using namespace std;

// Function to double each element of a array
array<int, 5> doubleArray(const array<int, 5>& inputArray) {
    array<int, 5> doubledArray;

    for (size_t i = 0; i < inputArray.size(); ++i) {
        doubledArray[i] = 2 * inputArray[i];
    }

    return doubledArray;
}

// Function to print the elements of a array
void printArray(const array<int, 5>& arr) {
    for (const auto& element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    // Declare and initialize an array
    array<int, 5> originalArray = {1, 2, 3, 4, 5};

    // Pass the array to the function, double its elements, and get the result
    array<int, 5> modifiedArray = doubleArray(originalArray);

    // Print the original array
    cout << "Original Array: ";
    printArray(originalArray);

    // Print the modified array
    cout << "Modified Array: ";
    printArray(modifiedArray);

    return 0;
}