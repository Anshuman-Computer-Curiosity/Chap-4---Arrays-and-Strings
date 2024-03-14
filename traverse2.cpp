#include<iostream>
#include<climits>
using namespace std;

void calxMaxMin(int arr[], int size, int& maxVal, int& minVal) {
    maxVal = INT_MIN;
    minVal = INT_MAX;
    for (int i = 0; i < size; i++) {
        //operation for each element
        if (arr[i] > maxVal)
            maxVal = arr[i];
	  if (arr[i] < minVal) 
            minVal = arr[i];
    }
} 
int main() {
    int arr[] = {15, 58, 28, 4, 77, 11, -5};
    int size = sizeof(arr)/sizeof(int); 
    int maxVal, minVal;
    calxMaxMin(arr, size, maxVal, minVal);
    cout<<"Minimum element in array = "<<minVal<<endl;
    cout<<"Maximum element in array = "<<maxVal;
    return 0;
}
