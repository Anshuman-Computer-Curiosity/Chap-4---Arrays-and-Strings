#include <iostream>
using namespace std;
int main() {
    int** ptrarr = NULL; //double pointer 2 by 3
    int i, j,row;
    cout<<"Enter number of rows = ";
    cin>>row;
    ptrarr = new int*[row]; // Memory for array of pointers
    
    for (i = 0; i < row; i++)
        ptrarr[i] = new int[3]; // Memory for row - array of integers
    
    for (i = 0; i < row; i++)
        for (j = 0; j < 3; j++)
            *(ptrarr[i] + j) = 10 * (i + 1) + j; // Assigning values
    
    for (i = 0; i < row; i++)
        for (j = 0; j < 3; j++)
            cout << (ptrarr[i][j]) <<" "<< &(ptrarr[i][j]) << endl; // Printing address of each element
    
    for (i = 0; i < row; i++)
        delete[] ptrarr[i]; // Free memory for every row
    
    delete[] ptrarr; // Free memory for array of pointers
    
    return 0;
}