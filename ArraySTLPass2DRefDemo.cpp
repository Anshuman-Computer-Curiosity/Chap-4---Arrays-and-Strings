//passing array to a function

#include <iostream>
#include <array>
using namespace std;

// Function that takes a 2D std::array by reference
template <typename T, size_t Rows, size_t Cols>
void print2DArray(const array<array<T, Cols>, Rows>& arr) {
    
    for (const auto& row : arr) {
        for (const auto& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    // Declare and initialize a 2D array
    array<array<int, 3>, 2> twoDArray = {{
        {10, 20, 30},
        {40, 50, 60}
    }};

    array<array<double, 2>, 3> doubleArray = {{
        {10.5, 20.5},
        {30.3, 40.3},
        {50.4, 60.4},
    }};

      cout<<" int array :"<<endl;
    // Pass the 2D array to the function by reference
    print2DArray(twoDArray);

    cout<<" double array :"<<endl;
    print2DArray(doubleArray);

    return 0;
}