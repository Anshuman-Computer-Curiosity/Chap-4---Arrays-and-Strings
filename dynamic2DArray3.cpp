#include <iostream>
using namespace std;
int main() {
    int (* pointerToArray)[3] = NULL;
    pointerToArray = new int[2][3]; // pointer to array
      
    //Assign values and print addresses
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
          
          pointerToArray[i][j] = 10 * (i + 1) + j; // Assigning values
            cout << &pointerToArray[i][j] << endl; // Print addresses
        }
    }
    // Deallocate memory
        delete[] pointerToArray;
    return 0;
}