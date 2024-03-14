#include <iostream>
#include <string>
using namespace std;
int main() {
    string mainString = "The";

    // all substrings 
    for(size_t i = 0;i<mainString.length();++i){
        for(size_t j=1;j<=mainString.length()-i;++j){
            string substring = mainString.substr(i, j);
            cout << substring<<endl;
        }
    }
   

    return 0;
}