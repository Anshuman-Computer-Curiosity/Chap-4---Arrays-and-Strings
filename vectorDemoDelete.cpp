
//Removing elements from an array
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> myVector = {10, 20, 30, 40, 50};

    cout << "Vector before pop_back: ";
    for (int num : myVector) {
        cout << num << " ";
    }

    //  myVector.pop_back();

    //  myVector.clear();

    // Erase element at position 2
    // myVector.erase(myVector.begin() + 2);
    int start = 2,end = 4;
    myVector.erase(myVector.begin() + start, myVector.begin() + end);

    cout << "\nVector after pop_back: ";
    for (int num : myVector) {
        cout << num << " ";
    }

    return 0;
}