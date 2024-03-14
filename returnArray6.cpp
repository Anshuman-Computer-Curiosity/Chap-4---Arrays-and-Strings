//returning array using std::vector
#include <iostream>
#include <vector>
using namespace std;
vector<int> func() {
    vector<int> arr;
    // Initialize or populate the array
    for (int i = 0; i < 5; i++) {
        arr.push_back(10*(i + 1));
    }
    return arr;
}

int main() {
    vector<int> myArray = func();
    // Use the array
    for (int element : myArray) {
        cout << element << " ";
    }
    return 0;
}