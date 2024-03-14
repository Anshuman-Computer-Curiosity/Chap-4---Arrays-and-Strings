
//Show difference between push_back(), emplace_back, insert()

#include <iostream>
#include <vector>
using namespace std;

class Person {
 private:
    string name;
    int age;   
public:
    Person(const string& n, int a) : name(n), age(a) {
        cout << "Constructor called: " << name << ", " << age << " years old." << endl;
    }
    void printInfo() const {
        cout << name << ", " << age << " years old." << endl;
    }


};

int main() {
    vector<Person> personVector;

    // Using push_back to add elements to the end
    personVector.push_back(Person("Pankaj", 35));
    personVector.push_back(Person("Kapil", 22));

    // Using emplace_back to construct and add elements to the end
    personVector.emplace_back("Amanjot", 35);
    personVector.emplace_back("Varun", 38);

    // Using emplace to construct and add an element at a specific position
    personVector.emplace(personVector.begin() + 1, "Simer", 48);

    // Using insert to add elements at a specific position
    auto it = personVector.insert(personVector.begin() + 2, {"Vijay", 43});

    // Printing the modified vector
    cout << "Vector after push_back, emplace_back, and insert:\n";
    for (const Person& p : personVector) {
         p.printInfo();
    }

    return 0;
}