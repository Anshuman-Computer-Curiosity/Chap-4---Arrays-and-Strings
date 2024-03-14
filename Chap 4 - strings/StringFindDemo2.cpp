#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[] = "apple,orange,banana";//string to be tokenized
    const char delimiters[] = ","; //splitter

    char *token = strtok(str, delimiters);  //get the first token
    while(token != nullptr) {
        cout<<"Token = "<<token<<endl;
        token = strtok(nullptr, delimiters);  //get next token (null pointer means continue from where we left off last
    }
    return 0;
}
