#include <iostream>
using namespace std;

const int MAX_ROWS = 3;
const int MAX_COLS = 3;

// Function to flip a 2D array horizontally
void flipHorizontally(int arr[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS / 2; ++j) {
            // Swap elements across the vertical axis
            swap(arr[i][j], arr[i][MAX_COLS - 1 - j]);
        }
    }
}

// Function to flip a 2D array vertically
void flipVertically(int arr[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS / 2; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            // Swap elements across the horizontal axis
            swap(arr[i][j], arr[MAX_ROWS - 1 - i][j]);
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

    // Flip the array horizontally
    flipHorizontally(twoDArray);
    cout << "\nArray after horizontal flip:" << endl;
    printArray(twoDArray);

    // Flip the array vertically
    flipVertically(twoDArray);
    cout << "\nArray after vertical flip:" << endl;
    printArray(twoDArray);

    return 0;
}