#include<iostream>
using namespace std;
int main(){
    int marks[5] = {0 }; // array declaration with initializer list
    int size = sizeof(marks)/sizeof(int);
    // cout<<"Enter marks in 5 subjects "<<endl;
    // for(int i = 0; i<5; i++){
    //     marks[i] = i + 1; 
    // }
    cout<<"Marks entered are "<<endl;
    for(int i = 0; i<size; i++){
        cout << marks[i]<<" ";
    }
    return 0;
}