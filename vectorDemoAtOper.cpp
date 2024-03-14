//Difference between at and operator[]


#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> myVector = {10, 20, 30, 40, 50};

    // Using operator[] without bounds checking
    myVector.at(2)=15;
    int value3 = myVector[2];       // Valid index
    int value4 = myVector.at(2);    

    cout << "Values: " << value3 << " " << value4 << endl;

    // Using at() with bounds checking
    try {
        int value1 = myVector.at(10);     // Valid index
        // int value2 = myVector.at(10);    // Out of range index
    } catch (const out_of_range& ex) {
        cerr << "Exception: " << ex.what() << endl;
    }

    return 0;
}