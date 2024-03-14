#include <iostream>
using namespace std;

// Custom function to return ASCII difference of first differing characters in C-style strings
int strcompare(const char* str1, const char* str2) {
    // Iterate through characters of both strings
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return (*str1) - (*str2);
        }
        ++str1;
        ++str2;
    }

    // Check if one string is a prefix of the other
    return (*str1) - (*str2);
}

int main() {
    const char* string1 = "apple";
    const char* string2 = "apricot";

    // Using the custom function to get ASCII difference
    int difference = strcompare(string1, string2);

    if (difference == 0) {
        cout << "C-Style Strings are equal." << endl;
    } else {
        cout << "ASCII Difference: " << difference << endl;
    }

    return 0;
}