#include <iostream>
using namespace std;

const int N = 4;

// Function to print non-zero elements of the tridiagonal matrix
void printTridiagonal(const int matrix[][N], int size) {
    cout << "Non-zero elements of the tridiagonal matrix:" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = i - 1; j <= i + 1; ++j) {
             if (j >= 0 && j < size) {
               cout << "matrix[" << i << "][" << j <<"] = " << matrix[i][j] << '\t';
             }
        }
        cout<<endl;
    }
}

int main() {
    const int tridiagonalMatrix[4][4] = {{1, 2, 0, 0},
                                         {3, 4, 5, 0},
                                         {0, 6, 7, 8},
                                         {0, 0, 9, 10}};

// Call the function to print non-zero elements of the tridiagonal matrix
    printTridiagonal(tridiagonalMatrix, 4);

    return 0;
}