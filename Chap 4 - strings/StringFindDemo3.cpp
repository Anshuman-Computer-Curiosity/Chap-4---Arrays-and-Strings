#include <iostream>
using namespace std;

const char* custom_strpbrk(const char* str, const char* charSet) {
    while (*str != '\0') {
        const char* charSetPtr = charSet;
        while (*charSetPtr != '\0') {
            if (*str == *charSetPtr) {
                return str;
            }
            ++charSetPtr;
        }
        ++str;
    }
    return nullptr;
}

int main() {
    const char* myCString = "Hello, World!";
    const char* charSet = "aeiou";

    const char* result = custom_strpbrk(myCString, charSet);

    if (result != nullptr) {
        cout << "Found first vowel '" << *result << "' at position: " << (result - myCString) << std::endl;
    } else {
        cout << "No vowels found in the string." << std::endl;
    }

    return 0;
}