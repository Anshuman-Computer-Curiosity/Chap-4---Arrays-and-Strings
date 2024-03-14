#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(const char* str) {
    size_t length = strlen(str);
    for (size_t i = 0; i < length / 2; ++i) {
        if (str[i] != str[length - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    const char* testString = "level";
    if (isPalindrome(testString)) {
        cout << "The string "<<testString<<" is a palindrome." << endl;
    } else {
        cout << "The string "<<testString<<"is not a palindrome." << endl;
    }

    return 0;
}