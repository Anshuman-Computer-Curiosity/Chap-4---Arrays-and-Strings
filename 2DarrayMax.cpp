#include <iostream>
using namespace std;

const int MAX_ROWS = 3;
const int MAX_COLS = 3;

// Function to print elements of a 2D array
void printArray(int arr[][3], int rows) {
    cout << "Elements of the 2D array:" << endl;
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to compute the maximum element in a 2D array
int maxElement(int arr[][3], int rows) {
    int maxVal = arr[0][0];

    for (int i = 0; i < MAX_ROWS; ++i) {
       // int maxVal = arr[i][0];
        for (int j = 0; j < MAX_COLS; ++j) {
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
            }
        }
        // cout << "Row " << i + 1 << ": " << maxVal << endl;
    }

    return maxVal;
}

int main() {
    
    int twoDArray[][3] = {{10, 11, 12},
                       {7, 9, 8},
                       {1, 3, 2}};

    int rows = sizeof(twoDArray)/(sizeof(twoDArray[0][0])*3) ;

    // Print elements of the 2D array
    printArray(twoDArray,rows);

    // Compute and print the maximum element
    int maximum = maxElement(twoDArray,rows);
    cout << "Maximum element in the 2D array: " << maximum << endl;

    return 0;
}