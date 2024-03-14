//passing array to a function

#include <iostream>
#include <array>
using namespace std;

// Function that takes a array by reference
void display(const array<int, 5>& arr) {
    for (const auto& element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    array<int, 5> myArray = {10, 20, 30, 40, 50};

    // Pass the array to the function
    display(myArray);

    return 0;
}