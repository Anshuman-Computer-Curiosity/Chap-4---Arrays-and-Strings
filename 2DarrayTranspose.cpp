#include <iostream>
using namespace std;

const int MAX_ROWS = 3;
const int MAX_COLS = 4;
int transpose[MAX_COLS][MAX_ROWS]; //global matrix

// Function to input elements into a 2D array
void inputArray(int arr[MAX_ROWS][MAX_COLS]) {
    cout << "Enter elements of the 2D array:" << endl;
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            cout << "Enter element at position [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
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

// Function to transpose a 2D array
void transposeArray(const int arr[MAX_ROWS][MAX_COLS] ) {
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            transpose[j][i] = arr[i][j];
        }
    }
}

// Function to print elements of the transposed 2D array
void printTransposedArray() {
    cout << "Transposed 2D array:" << endl;
    for (int i = 0; i < MAX_COLS; ++i) {
        for (int j = 0; j < MAX_ROWS; ++j) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int twoDArray[MAX_ROWS][MAX_COLS];
    int transposedArray[MAX_COLS][MAX_ROWS];

    // Input elements into the 2D array
    inputArray(twoDArray);

    // Print elements of the original 2D array
    printArray(twoDArray);

    // Transpose the 2D array
    transposeArray(twoDArray);

    // Print elements of the transposed 2D array
    printTransposedArray();

    return 0;
}