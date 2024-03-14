#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function object (functor) to square a number
struct Square {
    int operator()(int x) const {
        return x * x;
    }
};

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};

    // Using a function object to square each element in the vector
    transform(numbers.begin(), numbers.end(), numbers.begin(), Square());

    // Displaying the squared values
    cout << "Squared Numbers: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}