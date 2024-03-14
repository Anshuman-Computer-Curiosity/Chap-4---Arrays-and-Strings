//passing array name as pointer
#include <iostream>
using namespace std;
void printArray(int *arr, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            cout << (*(arr + i * 3)+j)<< " ";
        }
        cout << endl;
    }
}

int main() {
    int myArray1[][3] = {   {1, 2, 3}, {4, 5, 6}, {7, 8, 9}  };
    int rows = sizeof(myArray1)/sizeof(myArray1[0]);
    printArray((int *)myArray1, rows);
    return 0;
}