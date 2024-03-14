
// Using functions for access and modifications

#include <iostream>
#include <array>
using namespace std;

int main() {
    array<int, 5> myArray;  // Declare an empty array

    if (myArray.empty()) {
        cout << "The array is empty." << endl;
    } else {
        cout << "The array is not empty." << endl;
    }

    // Modifying elements using different member functions
    myArray.fill(10);  // Initialize all elements to 10

    cout << "Array after fill(10): ";
    
    // Modifying elements using iterators
    for (auto it = myArray.begin(); it != myArray.end(); ++it) {
        cout << *it << " ";
        *it += 5;  // Add 5 to each element
    }
    cout << endl;

    cout << "Array after modifying element at index 2: ";
    for (const auto& element : myArray) {
        cout << element << " ";
    }
    cout << endl;

    array<int, 5> array2 = {10, 20, 30, 40, 50};
    myArray.swap(array2);

    cout << "Array after swapping : ";
    for (const auto& element : myArray) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}