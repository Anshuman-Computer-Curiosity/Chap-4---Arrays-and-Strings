#include <iostream>
using namespace std;

const int MAX_ROWS = 3;
const int MAX_COLS = 4;

// Function to print elements of a 2D array
// void printArray( int arr[MAX_ROWS][MAX_COLS]) {

void printArray2(int arr[][4], int rows, int cols) {
    cout << "Elements of the 2D array:" << endl;
    for (int i = 0; i < rows; ++i) { //traverse rows
        for (int j = 0; j < cols; ++j) { //traverse columns
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    // 2D array initialized with elements
    int twoDArray[3][4] = {{1, 2, 3, 4},
                       {5, 6, 7, 8},
                       {9, 10, 11, 12}};

    // Print elements of the 2D array
    // printArray(twoDArray);
    printArray2(twoDArray,3,4);

    return 0;
}