//Using a template
#include <iostream>
using namespace std;
template <typename T, int rows, int cols>
void printArray(const T (&arr)[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    double myArray[3][4] = {
        {14.5, 2, 3, 4},
        {5, 6, 7.9, 8},
        {9, 10, 11, 12.8}
    };

    printArray(myArray);

    return 0;
}