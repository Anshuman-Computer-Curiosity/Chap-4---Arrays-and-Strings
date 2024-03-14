#include <iostream>
using namespace std;

const int MAX_ROWS = 3;
const int MAX_COLS = 4;

//void inputArray(int arr[MAX_ROWS][MAX_COLS]) {
void inputArray2(int arr[][4], int rows, int cols) {    
    cout << "Enter elements of the 2D array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element at position [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}


// Function to print elements of a 2D array
void printArray(const int arr[MAX_ROWS][MAX_COLS]) {

//void printArray2(int arr[][4], int rows, int cols) {
    cout << "Elements of the 2D array:" << endl;
    for (int i = 0; i < MAX_ROWS; ++i) { //traverse rows
        for (int j = 0; j < MAX_COLS; ++j) { //traverse columns
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

     int twoDArray[3][4];
    // Input elements into the 2D array
    inputArray2(twoDArray,3,4);

    // Print elements of the 2D array
    printArray(twoDArray);
    //printArray2(twoDArray,3,4);

    return 0;
}