#include <iostream>
#include <cmath>
using namespace std;

int exponentialSearch(int arr[], int n, int item) {
    //find the range to search
    if (arr[0] == item)
        return 0;

    int i = 1;
    while (i < n && arr[i] <= item)
        i *= 2;
    
    //perform binary search in specified range
    int beg = i /2;
    int end = min(i, n-1);
 
    while(beg <= end){
        int mid = (beg + end)/2;
         
        if(arr[mid] == item) return mid;
        else if(arr[mid] < item) beg = mid + 1;
        else end = mid - 1;
    }
 
    return -1;
}

int main() {
    int arr[] = {9, 12, 14, 16, 18, 19, 21, 23, 26, 32, 35, 43, 45};
    int size = sizeof(arr)/sizeof(int);
    int itemToBeFound = 18;


    int index = exponentialSearch(arr, size, itemToBeFound);
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}