#include <iostream>
using namespace std;

const int MAX_ROWS = 3;
const int MAX_COLS = 4;

// Function to calculate and print the sum of rows
// void sumOfRows(int arr[][4], int rows, int cols) {
//     cout << "Sum of each row:" << endl;
//     for (int i = 0; i < MAX_ROWS; ++i) {
//         int rowSum = 0;
//         for (int j = 0; j < MAX_COLS; ++j) {
//             rowSum += arr[i][j];
//         }
//         cout << "Row " << i + 1 << ": " << rowSum << endl;
//     }
// }

// Function to calculate and print the sum of columns
void sumOfColumns(int arr[][4], int rows, int cols) {
    cout << "Sum of each column:" << endl;
    for (int j = 0; j < cols; ++j) {
        int colSum = 0;
        for (int i = 0; i < rows; ++i) {
            colSum += arr[i][j];
        }
        cout << "Column " << j + 1 << ": " << colSum << endl;
    }
}

// Function to print elements of a 2D array
void printArray2(int arr[][4], int rows, int cols) {
    cout << "Elements of the 2D array:" << endl;
    for (int i = 0; i < MAX_ROWS; ++i) { //traverse rows
        for (int j = 0; j < MAX_COLS; ++j) { //traverse columns
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    // 2D array initialized with elements
    int twoDArray[][4] = {{1, 2, 3, 4},
                       {5, 6, 7, 8},
                       {9, 10, 11, 12}};

    int rows = sizeof(twoDArray)/(sizeof(twoDArray[0][0])*4) ;                     

    // Print elements of the 2D array
       printArray2(twoDArray,rows,4);
   
    // Calculate and print the sum of rows
    // sumOfRows(twoDArray,rows,4);

    // Calculate and print the sum of columns
    sumOfColumns(twoDArray,rows,4);

    return 0;
}