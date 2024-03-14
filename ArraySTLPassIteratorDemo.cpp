
//passing using iterators
#include <iostream>
#include <array>
using namespace std;

// Function that takes iterators representing a range of a array
template <typename Iterator>
void printArrayRange(Iterator begin, Iterator end) {
    for (auto it = begin; it != end; ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    array<int, 5> myArray = {10, 20, 30, 40, 50};

    // Pass iterators representing a range of the array to the function
    printArrayRange(myArray.begin() + 1, myArray.end() - 1);

    return 0;
}