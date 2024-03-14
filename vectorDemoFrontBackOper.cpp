//Difference between front and back()


#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> myVector = {10, 20, 30, 40, 50};

   int frontValue = myVector.front();

    // Using back() to access the last element
    int backValue = myVector.back();

    cout << "Front Value: " << frontValue << endl;
    cout << "Back Value: " << backValue << endl;

    int* pointerToData = myVector.data();

    // Accessing elements using the obtained pointer
    for (size_t i = 0; i < myVector.size(); ++i) {
        cout << "Element " << i << ": " << pointerToData[i] << endl;
    }

    return 0;
}