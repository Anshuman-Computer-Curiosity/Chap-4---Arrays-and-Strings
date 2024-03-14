//Input using get() function
#include <iostream>
#include <string>
using namespace std;

int main() {
    string userInput;
    char character;
    cout << "Enter a word: ";
    while(cin.get(character) && character!='\n'){
        // userInput += character;
        userInput.push_back(character);
    }



    cout << "You entered: " << userInput << endl;
    return 0;
}