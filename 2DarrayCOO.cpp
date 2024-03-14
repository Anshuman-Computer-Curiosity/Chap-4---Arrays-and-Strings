#include <iostream>
using namespace std;

struct COOEntry {
    int row;
    int col;
    int value;
};

// Function to count non-zero entries in an irregular sparse matrix
int countNonZeroEntries(const int matrix[][4], int numRows, int numCols) {
    int count = 0;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (matrix[i][j] != 0) {
                ++count;
            }
        }
    }
    return count;
}

// Function to convert an irregular sparse matrix to COO format
void convertToCOO(const int matrix[][4], int numRows, int numCols, COOEntry cooEntries[]) {
    int entryIndex = 0;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (matrix[i][j] != 0) {
                cooEntries[entryIndex].row = i;
                cooEntries[entryIndex].col = j;
                cooEntries[entryIndex].value = matrix[i][j];
                ++entryIndex;
            }
        }
    }
}

// Function to print COO representation
void printCOO(const COOEntry cooEntries[], int numEntries) {
    cout << "COO Representation:" << endl;
    for (int i = 0; i < numEntries; ++i) {
        cout << "matrix[" << cooEntries[i].row << "][" << cooEntries[i].col <<"] = " << cooEntries[i].value << endl;
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

    // Count non-zero entries
    int numNonZeroEntries = countNonZeroEntries(irregularSparseMatrix, numRows, numCols);

    // Create an array to store COO entries
    COOEntry cooEntries[numNonZeroEntries];

    // Convert irregular sparse matrix to COO format
    convertToCOO(irregularSparseMatrix, numRows, numCols, cooEntries);

    // Print COO representation
    printCOO(cooEntries, numNonZeroEntries);

    return 0;
}