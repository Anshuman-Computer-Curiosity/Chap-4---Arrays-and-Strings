//Using vector of vectors
#include <iostream>
#include <vector>
using namespace std;
void printArray(const vector<vector<int>>& arr) {
    for (const auto& row : arr) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    // Create a 2D array using a vector of vectors
    vector<vector<int>> myArray = {
                                        {1, 2, 3},
                                        {4, 5},
                                        {6, 7, 8, 9}
    };

    // Print the 2D array
    cout << "Original 2D Array:" << endl;
    printArray(myArray);

    // Modify the array by adding a new row
    vector<int> newRow = {10, 11};
    myArray.push_back(newRow);

    // Print the modified array
    cout << "\nModified 2D Array:" << endl;
    printArray(myArray);

    return 0;
}