// Using functions for access and modifications

#include <iostream>
#include <array>
using namespace std;

int main() {
    // Initializing a array
    array<int, 5> myArray = {10, 20, 30, 40, 50};

    // Accessing elements using different member functions
    cout << "Element at index 2 using at(): " << myArray.at(2) << endl;
    cout << "Element at index 2 using operator[]: " << myArray[2] << endl;
    cout << "First element using front(): " << myArray.front() << endl;
    cout << "Last element using back(): " << myArray.back() << endl;

    // Accessing underlying array using data()
    int* pointerToData = myArray.data();
    cout << "Pointer to underlying array: " << pointerToData[2] << endl;

    myArray.fill(10);
    cout << "Array after fill(10): ";
    for (const auto& element : myArray) {
        cout << element << " ";
    }
    cout << endl;

    // Modifying specific elements using subscript operator
    myArray[2] = 25;  // Modify the third elemen
    
    cout << "Element at index 2 using operator[]: " << myArray[2] << endl;
    // Modifying elements using range-based for loop
    for (auto& element : myArray) {
        element *= 2;  // Double each element
    }

    cout << "Array after doubling each element: ";
    for (const auto& element : myArray) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}