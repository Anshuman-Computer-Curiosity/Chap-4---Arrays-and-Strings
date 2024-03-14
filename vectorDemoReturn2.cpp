
//Returning an existing vector
#include <iostream>
#include <vector>
using namespace std;

// Function that processes an existing vector and returns a const reference
const vector<int>& processVector(const vector<int>& inputVector) {
    vector<int> temporary;  // Using static for demonstration purposes
    temporary = inputVector;  // Process the input vector (copying for simplicity)

    cout << "Modified Vector: ";
    for (int& num : temporary) {
        num *= 2;  // Double each element
    }

    
    static vector<int> result;  // To extend lifetime beyond function call
    // Use std::vector::swap to efficiently transfer ownership without copying
    result.swap(temporary); 

    // Return a const reference to the processed vector
    return result;
    
    
    // In case of large vector, Use std::move to transfer ownership efficiently
    // return std::move(result);

}

int main() {
    vector<int> originalVector = {1, 2, 3, 4, 5};

    // Call the function and receive a const reference to the processed vector
    const vector<int>& processedVector = processVector(originalVector);

    // Display the processed vector
    cout << "Processed Vector: ";
    for (int num : processedVector) {
        cout << num << " ";
    }
    cout << endl;

    // Attempting to modify the processed vector will result in a compilation error
    // processedVector.push_back(6); // Uncommenting this line will result in a compilation error

    return 0;
}