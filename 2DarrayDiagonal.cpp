#include <iostream>
using namespace std;

const int MAX_ROWS = 3;
const int MAX_COLS = 3;

// Function to print elements of a 2D array
//void printArray(const int arr[MAX_ROWS][MAX_COLS]) {
void printArray(int arr[][3], int rows, int cols) {
    cout << "Elements of the 2D array:" << endl;
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to calculate and print the sum of diagonals
//void sumOfDiagonals(const int arr[MAX_ROWS][MAX_COLS]) {
void sumOfDiagonals(int arr[][3], int rows, int cols) {
    int primaryDiagonalSum = 0;
    int secondaryDiagonalSum = 0;

    for (int i = 0; i < MAX_ROWS; ++i) {
        // Sum of the primary diagonal (top-left to bottom-right)
        primaryDiagonalSum += arr[i][i];

        // Sum of the secondary diagonal (top-right to bottom-left)
        secondaryDiagonalSum += arr[i][MAX_COLS - 1 - i];
    }

    // Print the sum of diagonals
    cout << "Sum of the primary diagonal: " << primaryDiagonalSum << endl;
    cout << "Sum of the secondary diagonal: " << secondaryDiagonalSum << endl;
}

int main() {
    int twoDArray[][3] = {{10, 11, 12},
                       {7, 9, 8},
                       {1, 3, 2}};

    int rows = sizeof(twoDArray)/(sizeof(twoDArray[0][0])*3) ;  
      

    // Print elements of the 2D array
    printArray(twoDArray,rows,3);

    // Calculate and print the sum of diagonals
    sumOfDiagonals(twoDArray,rows,3);

    return 0;
}