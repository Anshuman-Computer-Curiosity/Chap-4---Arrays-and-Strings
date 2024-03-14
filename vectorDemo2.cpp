#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Vector of integers
    vector<int> intVector;
    intVector.push_back(1);
    intVector.push_back(2);
    intVector.push_back(3);

    // Vector of doubles
    vector<double> doubleVector;
    doubleVector.push_back(1.5);
    doubleVector.push_back(2.25);
    doubleVector.push_back(3.75);

    // Vector of strings
    vector<string> stringVector;
    stringVector.push_back("apple");
    stringVector.push_back("banana");
    stringVector.push_back("cherry");

    // Vector of custom objects
    struct Person {
        string name;
        int age;
    };

    vector<Person> personVector;
    personVector.push_back({"Alice", 25});
    personVector.push_back({"Bob", 30});
    personVector.push_back({"Charlie", 22});

    // Accessing and printing elements
    cout << "Int Vector: ";
    for (int i : intVector) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Double Vector: ";
    for (double d : doubleVector) {
        cout << d << " ";
    }
    cout << endl;

    cout << "String Vector: ";
    for (const string& s : stringVector) {
        cout << s << " ";
    }
    cout << endl;

    cout << "Person Vector: ";
    for (const Person& p : personVector) {
        cout << "(" << p.name << ", " << p.age << ") ";
    }
    cout << endl;

    return 0;
}