#include <iostream>
using namespace std;

template <typename T, int N>
void printArray( T(&arr)[N]) {  
    for (int i = 0; i < N; i++) {  
         cout << ++arr[i]  << " ";    
    }
    cout << endl;
}

int main() {
    int myArray[] = {10, 20, 30, 40, 50};
    printArray(myArray);
    double myArray1[] = {10.5, 20.4, 30.56, 40.25, 50.09};
    printArray(myArray1);
    return 0;
}