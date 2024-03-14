#include <iostream>
using namespace std;

const int MAX_ROWS = 3;
const int MAX_COLS = 3;

// Function to rotate a 2D array clockwise
void rotateClockwise(int arr[MAX_ROWS][MAX_COLS]) {
    int temp[MAX_ROWS][MAX_COLS];

    // Copy the original array to a temporary array
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            temp[i][j] = arr[i][j];
        }
    }

    // Rotate the array clockwise
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            arr[j][MAX_ROWS - 1 - i] = temp[i][j];
        }
    }
}

// Function to rotate a 2D array counterclockwise
void rotateCounterclockwise(int arr[MAX_ROWS][MAX_COLS]) {
    int temp[MAX_ROWS][MAX_COLS];

    // Copy the original array to a temporary array
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            temp[i][j] = arr[i][j];
        }
    }

    // Rotate the array counterclockwise
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            arr[MAX_COLS - 1 - j][i] = temp[i][j];
        }
    }
}

// Function to print elements of a 2D array
void printArray(const int arr[MAX_ROWS][MAX_COLS]) {
    cout << "Elements of the 2D array:" << endl;
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int twoDArray[MAX_ROWS][MAX_COLS] = {{1, 2, 3},
                                         {4, 5, 6},
                                         {7, 8, 9}};

    // Print the original array
    cout << "Original Array:" << endl;
    printArray(twoDArray);

    // Rotate the array clockwise
    rotateClockwise(twoDArray);
    cout << "\nArray after clockwise rotation:" << endl;
    printArray(twoDArray);

    // Rotate the array counterclockwise
    rotateCounterclockwise(twoDArray);
    cout << "\nArray after counterclockwise rotation:" << endl;
    printArray(twoDArray);

    return 0;
}