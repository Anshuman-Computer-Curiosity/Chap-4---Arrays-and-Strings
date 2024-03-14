//returning array as single argument
#include<iostream>
using namespace std;
int* func(){
   static int arr[]={10,20,30,40,50};
   return arr;
}

int main(){
    int *ptrArr = func();
    for(int i=0;i<5;i++){
        cout<<ptrArr[i]<<" ";
    }
    return 0;
}