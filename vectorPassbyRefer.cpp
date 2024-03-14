#include <iostream>
#include <vector>
using namespace std;
// Function that takes a vector by reference
void modifyVectorByReference(vector<int>& vec) {
    // Modify the vector (changes will affect the original vector)
    vec.push_back(54);

    // Print the modified vector
    cout << "Inside function (by reference): ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Declare and initialize a vector
    vector<int> myVector = {10, 20, 30, 40, 50};

    // Call the function and pass the vector by reference
    modifyVectorByReference(myVector);

    // Print the modified vector
    cout << "Outside function (modified vector): ";
    for (int num : myVector) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}