
#include <iostream>
#include<vector>
using namespace std;
struct Person{
    string name;
    int age;
};

int main() {

    vector<int> myVector {10, 20, 30};
    // vector<double> myVector {10.25, 30.23, 20.56};
    // vector<string> myVector {"hello", "working", "with","C++"};
    // vector<Person> myVector {{"Amit",23}, {"Kapil",33}};
   

    // vector<Person>::iterator it;
    // for(it = myVector.begin();it!=myVector.end();++it){
    //     cout<<it->name<<" "<<it->age<<endl;
    // }

    vector<int>::iterator it;
     for(it = myVector.begin();it!=myVector.end();++it){
         cout<<*it<<endl;
     }

    // for(const auto& num: myVector){
    //     cout<<num.name<<" "<<num.age<<endl;
    // }
    cout<<endl;

    return 0;
}