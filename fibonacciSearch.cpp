#include <iostream>
using namespace std;

int fibonacciSearch(int arr[], int size, int item) {
    int fibM_minus_2 = 0;
    int fibM_minus_1 = 1;
    int fibM = fibM_minus_1 + fibM_minus_2;

    while (fibM < size) {
        fibM_minus_2 = fibM_minus_1;
        fibM_minus_1 = fibM;
        fibM = fibM_minus_1 + fibM_minus_2;
    }
    
    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibM_minus_2, size - 1);
       
        if (arr[i] < item) {//left 
            fibM = fibM_minus_1;
            fibM_minus_1 = fibM_minus_2;
            fibM_minus_2 = fibM - fibM_minus_1;
            offset = i;
            
        } else if (arr[i] > item) {//right
            fibM = fibM_minus_2;
            fibM_minus_1 = fibM_minus_1 - fibM_minus_2;
            fibM_minus_2 = fibM - fibM_minus_1;
        } else {
                 return i;
        }
    }
    
    if (fibM_minus_1 ==1 && arr[offset + 1] == item) {
        return offset + 1;
    }

    return -1; // Element not found
}

int main() {
    int arr[] = {9, 12, 14, 16, 18, 19, 21, 23, 26, 32, 35, 43, 45};
    int size = sizeof(arr)/sizeof(int);
    int itemToBeFound = 26;

    int index = fibonacciSearch(arr, size, itemToBeFound);

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}