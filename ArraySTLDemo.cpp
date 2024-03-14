
//TO make use of std::array STL
#include <iostream>
#include <array>
using namespace std;

int main() {
    // Initializing with values
    // array<double, 5> myArray ; 
    // myArray = {10.23, 20.45, 30.56, 40.1, 50.5};

    // array<int, 5> myArray = {}; // Intializing with default values
    // array<int, 5> myArray{{10, 20, 30, 40, 50}};//uniform initialization, C++11

    //Intializing using loop
    // for (size_t i = 0; i < myArray.size(); ++i) {
    //     myArray[i] = static_cast<int>(i + 1);
    // }

    // array<double, 5> myArray = {3.14, 5.0, 1.65};
    array<string, 3> myArray = {"DBMS", "Java", "Python"};
    // Accessing and printing elements
    for (const auto& element : myArray) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}