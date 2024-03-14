
// Working with multi-dimensional array

#include <iostream>
#include <array>
using namespace std;

int main() {
    // Declare and initialize a 2x3 array
    array<array<int, 3>, 2> multiArray = {{
        {10, 20, 30},
        {40, 50, 60}
    }};

    // Access and print elements
    cout << "Element at (1, 2): " << multiArray[1][2] << endl;

    // Modify an element
    multiArray[0][1] = 15;

    // Print all elements using nested loops
    for (const auto& row : multiArray) {
        for (const auto& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}