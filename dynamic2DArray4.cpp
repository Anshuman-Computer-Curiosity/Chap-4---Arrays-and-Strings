#include <iostream>
using namespace std;
int main() {
    int *dynamicArrayptr = NULL;
    dynamicArrayptr = new int[2*3] {10,20,30,40,50,60}; // Flattend array
    
   // Allocate memory for each row
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
        //   dynamicArrayptr[i*3 + j] = 10*(i+1)+j;
          cout << dynamicArrayptr[i*3+j] << endl;
        }
    }
    // Deallocate memory
    
    delete[] dynamicArrayptr;
   
    return 0;
}