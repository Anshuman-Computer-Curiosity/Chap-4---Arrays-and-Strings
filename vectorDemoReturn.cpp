
//Pass and return a vector from a function 
#include <iostream>
#include <vector>
using namespace std;

// Function to modify a vector passed by reference
void modifyVector(vector<int>& vec) {
    for (int& num : vec) {
        num *= 2;
    }
}

// Function to generate and return a vector
vector<int> generateVector() {
    vector<int> result = {1, 2, 3, 4, 5};
    return result;
}

int main() {
    vector<int> myVector = {10, 20, 30, 40, 50};

    // Pass the vector to the modifyVector function
    modifyVector(myVector);

    // Print the modified vector
    cout << "Modified Vector: ";
    for (int num : myVector) {
        cout << num << " ";
    }
    cout << "\n";

    // Call the function and receive the returned vector
    vector<int> generatedVector = generateVector();

    // Print the elements of the returned vector
    cout << "Generated Vector: ";
    for (int num : generatedVector) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}