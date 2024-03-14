#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> create2DArray() {
    vector<vector<int>> arr(3, vector<int>(4, 0));

    // Populate the 2D array
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            arr[i][j] = i + j;
        }
    }

    return arr;
}

int main() {
    vector<vector<int>> myArray = create2DArray();

    // Accessing the elements of the 2D array
    for (int i = 0; i < myArray.size(); i++) {
        for (int j = 0; j < myArray[i].size(); j++) {
            cout << myArray[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}