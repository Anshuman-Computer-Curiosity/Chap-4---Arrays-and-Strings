#include <iostream>
using namespace std;

struct CSRMatrix {
    int* values;
    int* columns;
    int* rowPtr;
};

// Function to print CSR representation
void printCSR(const CSRMatrix& csr, int numRows) {
    cout << "CSR Representation:" << endl;
    for (int i = 0; i < numRows; ++i) {
        int rowStart = csr.rowPtr[i];
        int rowEnd = csr.rowPtr[i + 1];
        for (int j = rowStart; j < rowEnd; ++j) {
            cout << "matrix[" << i << "][" << csr.columns[j] <<"] = " << csr.values[j] << endl;
        }
    }
}

// Function to convert irregular sparse matrix to CSR format
CSRMatrix convertToCSR(const int matrix[][4], int numRows, int numCols) {
    CSRMatrix csr;
    
    // Count non-zero entries
    int numNonZeroEntries = 0;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (matrix[i][j] != 0) {
                ++numNonZeroEntries;
            }
        }
    }

    // Allocate memory for CSR arrays
    csr.values = new int[numNonZeroEntries];
    csr.columns = new int[numNonZeroEntries];
    csr.rowPtr = new int[numRows + 1];

    // Convert matrix to CSR format
    int entryIndex = 0;
    int valueIndex = 0;
    for (int i = 0; i < numRows; ++i) {
        csr.rowPtr[i] = valueIndex;
        for (int j = 0; j < numCols; ++j) {
            if (matrix[i][j] != 0) {
                csr.values[entryIndex] = matrix[i][j];
                csr.columns[entryIndex] = j;
                ++entryIndex;
                ++valueIndex;
            }
        }
    }
    csr.rowPtr[numRows] = valueIndex; //last item of rowptr

    return csr;
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

    // Convert to CSR representation
    CSRMatrix csrMatrix = convertToCSR(irregularSparseMatrix, numRows, numCols);

    // Print CSR representation
    printCSR(csrMatrix, numRows);

    // Clean up allocated memory
    delete[] csrMatrix.values;
    delete[] csrMatrix.columns;
    delete[] csrMatrix.rowPtr;

    return 0;
}