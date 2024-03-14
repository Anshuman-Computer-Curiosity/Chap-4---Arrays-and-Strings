#include <iostream>
#include <array>
using namespace std;
array<int, 5> createArray() {
    std::array<int, 5> arr;
    for (int i = 0; i < 5; i++) {
        arr[i] = 10*(i + 1);
    }
    return arr;
}

int main() {
    array<int, 5> myArray = createArray();

    // Accessing the elements of the array
    for (int element : myArray) {
        cout << element << " ";
    }
    cout << std::endl;

    return 0;
}