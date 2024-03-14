#include<iostream>
using namespace std;

int calcSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];//traversing array
    }
    return sum;
}
int main() {
    int arr[] = {1, 2, 30, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);

    int result = calcSum(arr, size);

    cout << "Sum of the array: " << result << endl;
    return 0;
}
