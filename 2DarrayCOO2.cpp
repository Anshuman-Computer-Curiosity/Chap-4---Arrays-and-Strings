#include <iostream>
using namespace std;

// Function to print COO representation
void printCOO(int rows[], int columns[], int values[], int numEntries) {
    cout << "COO Representation:" << endl;
    for (int i = 0; i < numEntries; ++i) {
        cout << "matrix[" << rows[i] << "][" << columns[i] <<"] = " << values[i] << endl;
    }
}

// Function to convert irregular sparse matrix to COO format
void convertToCOO(const int matrix[][4], int numRows, int numCols, int rows[], int columns[], int values[], int& numEntries) {
    numEntries = 0;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (matrix[i][j] != 0) {
                rows[numEntries] = i;
                columns[numEntries] = j;
                values[numEntries] = matrix[i][j];
                ++numEntries;
            }
        }
    }
}

int main() {
    // Example irregular sparse matrix
    const int numRows = 4;
    const int numCols = 4;
    int irregularSparseMatrix[numRows][numCols] = {
        {1, 0, 0, 0},
        {0, 0, 2, 0},
        {3, 0, 0, 4},
        {0, 5, 0, 6}
    };

    // Maximum possible number of non-zero entries
    const int maxEntries = numRows * numCols;

    // Arrays to store COO entries
    int rows[maxEntries];
    int columns[maxEntries];
    int values[maxEntries];

    // Number of non-zero entries
    int numEntries;

    // Convert to COO representation
    convertToCOO(irregularSparseMatrix, numRows, numCols, rows, columns, values, numEntries);

    // Print COO representation
    printCOO(rows, columns, values, numEntries);

    return 0;
}