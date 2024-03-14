#include <iostream>
using namespace std;

const int N = 3;

// Function to print non-zero elements of the upper triangular matrix
void printUpperTriangular(const int matrix[][N], int size) {
    cout << "Non-zero elements of the upper triangular matrix:" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
               cout << "matrix[" << i << "][" << j <<"] = " << matrix[i][j] << '\t';
        }
        cout<<endl;
    }
}

int main() {
    int upperTriangular[N][N] = {{1, 2, 3},
                                  {0, 4, 5},
                                  {0, 0, 6}};

    // Call the function to print non-zero elements of the upper triangular matrix
    printUpperTriangular(upperTriangular, N);

    return 0;
}