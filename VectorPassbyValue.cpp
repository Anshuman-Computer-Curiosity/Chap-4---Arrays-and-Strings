
//Passing vector to function by value
#include <iostream>
#include <vector>
using namespace std;

// Function that takes a vector by value and returns the modified vector
// void modifyVectorByValue(vector<int> vec) {
vector<int> modifyVectorByValue(vector<int> vec) {
    // Modify the vector (changes won't affect the original vector)
    vec.push_back(54);

    // Print the modified vector
    cout << "Inside function (by value): ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    // Return the modified vector
    return vec;
}

int main() {
    // Declare and initialize a vector
    vector<int> myVector = {10, 20, 30, 40, 50};

    // Call the function and pass the vector by value
    // modifyVectorByValue(myVector);
    myVector = modifyVectorByValue(myVector);
    // vector<int> myVector2 = modifyVectorByValue(myVector);

    // Print the modified vector
    cout << "Outside function (modified vector): ";
    for (int num : myVector) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}