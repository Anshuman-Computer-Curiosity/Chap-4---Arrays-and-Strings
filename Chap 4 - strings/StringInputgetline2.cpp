
#include <iostream>
#include <cstring>
#include <cctype> // For std::isalnum
using namespace std;

int main() {
    const int bufferSize = 1000;
    char input[bufferSize];

    cout << "Enter text (End with '*'): " << endl;

    while (cin.getline(input, bufferSize, '*')) { 
        //Reads input from the user until '*' is encountered or the buffer is full.
        int lineCount = 0, wordCount = 0, charCount = 0;
        bool inWord = false;// Flag to track whether the current position is inside a word

       // Iterates through each character in the input array, including the null terminator at the end
        for (size_t i = 0; i <= strlen(input); ++i) {
            if (isalnum(input[i])) { //Checks if the current character is alphanumeric
                charCount++;
                if (!inWord) {
                    inWord = true;
                    wordCount++;
                }
            } else if (input[i] == '\n' || input[i] == '\0') {
                charCount++;
                lineCount++;
                inWord = false;  // Reset inWord on newline or end of string
            } else if (isspace(input[i])) {
                inWord = false;  // Reset inWord on space
            }
        }

        cout << "Line Count: " << lineCount << "\n"
                  << "Word Count: " << wordCount << "\n"
                  << "Character Count: " << charCount << endl;
    }

    return 0;
}