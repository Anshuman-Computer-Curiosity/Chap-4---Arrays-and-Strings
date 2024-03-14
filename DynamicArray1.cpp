#include<iostream>
using namespace std;
int main(){
    int i;
    // cout<<"Enter number of elements in array = ";
    // cin>>num;
    int *arrptr = new (nothrow) int[5] {0}; //dynamic array declartion
    if(arrptr == nullptr){
        cout<<"Error in memory allocation";
    }
    else{
    // for(i=0; i<num; i++){
    //     arrptr[i] = i * 10.2;
    // }
    cout<<"Elements are "<<endl;
    for(i=0; i<5; i++){
        cout<< *(arrptr + i) <<" ";
    }
       
    delete[] arrptr; //deallocate heap memory
    arrptr = nullptr;
    }
    return 0;
}