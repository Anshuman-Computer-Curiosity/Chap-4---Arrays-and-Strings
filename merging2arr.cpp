#include <iostream>
using namespace std;

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
            // result[k] = arr1[i];
            // i++;
        } else {
            result[k++] = arr2[j++];
            // result[k] = arr2[j];
            // j++;
        }
        // k++;
    }
    // Copy any remaining elements from arr1 to result
    while (i < size1) {
        result[k++] = arr1[i++];
    }
    // Copy any remaining elements from arr2 to result
    while (j < size2) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int arrA[] = {3, 5, 7, 9};
    int sizeA = sizeof(arrA) / sizeof(arrA[0]);

    int arrB[] = {2, 6, 10, 11, 15};
    int sizeB = sizeof(arrB) / sizeof(arrB[0]);

    int sizeC = sizeA + sizeB;
    int arrC[sizeC];

    mergeArrays(arrA, sizeA, arrB, sizeB, arrC);

    // Display the merged array
    for (int i = 0; i < sizeC; i++) {
        cout << arrC[i] << " ";
    }

    return 0;
}