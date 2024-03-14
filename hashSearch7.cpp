#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Structure to hold additional information (salary and address)
struct EmployeeInfo {
    int salary;
    string address;

    EmployeeInfo() : salary(0), address("") {}
};

int main() {
    // Create an unordered_map with string keys and EmployeeInfo values
    unordered_map<string, EmployeeInfo> employeeMap;

    // Insert key-value pairs into the map
    EmployeeInfo info1;
    info1.salary = 25000;
    info1.address = "123 Lawrence Road";
    employeeMap["Harman"] = info1;

    EmployeeInfo info2;
    info2.salary = 38000;
    info2.address = "456 Brahm Nagar";
    employeeMap["Kapil"] = info2;

    // Search for a specific key
    string searchKey = "Kapil";
    if (employeeMap.find(searchKey) != employeeMap.end()) {
        cout << "Employee Info for '" << searchKey << "':" << endl;
        cout << "Salary: " << employeeMap[searchKey].salary << endl;
        cout << "Address: " << employeeMap[searchKey].address << endl;
    } else {
       cout << "Employee '" << searchKey << "' not found." <<endl;
    }

    return 0;
}