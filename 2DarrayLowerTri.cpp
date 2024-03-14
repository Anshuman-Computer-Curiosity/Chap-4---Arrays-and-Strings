#include <iostream>
using namespace std;

const int N = 3;

// Function to print non-zero elements of the lower triangular matrix
void printLowerTriangular(const int matrix[][N], int size) {
    cout << "Non-zero elements of the lower triangular matrix:" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j <= i; ++j) {
               cout << "matrix[" << i << "][" << j <<"] = " << matrix[i][j] << '\t';
        }
        cout<<endl;
    }
}

int main() {
    int lowerTriangular[N][N] = {{1, 0, 0},
                                  {2, 3, 0},
                                  {4, 5, 6}};

    // Call the function to print non-zero elements of the lower triangular matrix
    printLowerTriangular(lowerTriangular, N);

    return 0;
}