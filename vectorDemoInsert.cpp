//Using different forms of insert() function

#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> myVector = {10, 20, 30, 40, 50};

    // Using insert to add an element at a specific position
    // myVector.insert(myVector.begin() + 2, 25);
    
    

    // Using insert to add multiple copies of a value at a specific position
    // myVector.insert(myVector.begin() + 1, 2, 45);
    // Printing the modified vector
    

    // Using insert to add elements from another vector at a specific position
    vector<int> anotherVector = {16, 26, 36};
    myVector.insert(myVector.begin() + 1, anotherVector.begin(), anotherVector.end());
    
    for (int num : myVector) {
        cout << num << " ";
    }
    

    // Using push_back to add an element to the end
    myVector.push_back(60);
    
    
    // myVector.emplace_back(42);

    return 0;
}