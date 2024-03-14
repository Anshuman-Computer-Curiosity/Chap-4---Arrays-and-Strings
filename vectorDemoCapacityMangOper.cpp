
//Capacity management operations


#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> myVector = {5, 10, 15, 20, 25};

    size_t currentSize = myVector.size();
    size_t currentCapacity = myVector.capacity();

    cout << "Size: " << currentSize << ", Capacity: " << currentCapacity << endl;

    myVector.resize(10);
    cout << "Size after resizing to 10: " << myVector.size() << ", Capacity: " << myVector.capacity() << endl;
    for (int num : myVector) {
        cout << num << " ";
    }
    cout<<endl;

    myVector.reserve(20);
    cout << "Size after reserving capacity for 20: " << myVector.size() << ", Capacity: " << myVector.capacity() << endl;

    myVector.shrink_to_fit();
    cout << "Size after shrinking to fit: " << myVector.size() << ", Capacity: " << myVector.capacity() << endl;

    return 0;
}