//Difference between front and back()


#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> myVector = {10, 20, 30, 40, 50};

   vector<int> rangeVector;
    rangeVector.assign(myVector.begin() + 2, myVector.end());  

    // Using assign() with a number of copies
    vector<int> copiesVector;
    copiesVector.assign(3, 45);  // Assign 3 copies of the value 45

    // Printing the results
    cout << "Range Vector: ";
    for (int num : rangeVector) {
        cout << num << " ";
    }
    cout << "\nCopies Vector: ";
    for (int num : copiesVector) {
        cout << num << " ";
    }

    return 0;
}