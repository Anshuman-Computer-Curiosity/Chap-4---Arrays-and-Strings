//Passing 2D array to a function

#include <iostream>
#include <vector>
using namespace std;

// Template function that takes a 2D vector by reference
template <typename T>
void display2DVector(const vector<vector<T>>& vec) {
    for (const auto& row : vec) {
        for (const auto& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    // Declare and initialize a 2D vector of ints
    vector<vector<int>> twoDVectorInt = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    // Declare and initialize a 2D vector of doubles
    vector<vector<double>> twoDVectorDouble = {
        {1.1, 2.2},
        {4.4, 5.5},
        {7.7, 8.8}
    };

    // Pass the 2D vectors to the template function by reference
    display2DVector(twoDVectorInt);
    cout << endl;
    display2DVector(twoDVectorDouble);

    return 0;
}