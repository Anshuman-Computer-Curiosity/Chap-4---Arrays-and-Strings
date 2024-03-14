#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Creating dynamic arrays
    int* arr1 = new int[10]{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

      
    // Accessing and using the dynamic arrays
    cout << "Dynamic Array : ";
    for (int i = 0; i < 10; ++i) {
        cout << arr1[i] << " ";
    } 
    cout<<endl;
    // Deleting dynamic arrays
    delete[] arr1;

    cout << "Vector : ";
    vector<int> vec1 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    for (int num : vec1) {
        cout << num << " ";
    }

    return 0;
}