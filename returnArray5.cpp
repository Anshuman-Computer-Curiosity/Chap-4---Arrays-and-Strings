//create class that stores array data and uses mem. func. to manipulate it
#include <iostream>
using namespace std;
class MyArray {
    private:
        int* data;
        int size;

    public:
        MyArray(int s) : size(s) {
            data = new int[size];
            // Initialize or populate the array
            for (int i = 0; i < size; i++) {
                data[i] = 10*(i + 1);
            }
        }

        ~MyArray() { //destructor
            delete[] data;
        }

        int getSize() const { // constant mem. func. returns size
                return size;
        }

        int& operator[](int index) { //overloaded operator []
             return data[index];
        }
};

MyArray func() { // return type class
    return MyArray(5);
}

int main() {
    MyArray myArray = func();
    // Use the array
    for (int i = 0; i < myArray.getSize(); i++) {
        cout << myArray[i] << " ";
    }
    return 0;
}