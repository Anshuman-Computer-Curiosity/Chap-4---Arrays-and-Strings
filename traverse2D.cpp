#include <iostream>
using namespace std;

const int rows = 3;
const int columns = 4;

void initializeArray(int arr[][columns]) {
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            arr[i][j] = (i*columns+j+1)*10;
        }
    }
}

void display(int arr[][columns]) {
    cout << "Elements of the 2D array in row-major order:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[rows][columns];

    // Initialize the 2D array
    initializeArray(arr);

    // Print the array in row-major order
    display(arr);

    return 0;
}