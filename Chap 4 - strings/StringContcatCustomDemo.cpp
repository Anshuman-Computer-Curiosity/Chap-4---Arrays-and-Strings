#include <iostream>
#include <cstring>
using namespace std;

// Custom function to concatenate two C-style strings
void customStringConcat(const char* str1, const char* str2, char* dest) {
    // Calculate the length of the destination string
    size_t count = 0;
    for (size_t i = 0; dest[i] != '\0'; ++i) {
        count++;
    }

    // Copy characters from the first string to the destination
    for (size_t i = 0, j = count; str1[i] != '\0'; ++i, ++j) {
        dest[j] = str1[i];
    }

    // Do not increment count in the second loop
    // Copy characters from the second string to the destination
    for (size_t i = 0; str2[i] != '\0'; ++i) {
        dest[count] = str2[i];
        ++count;
    }

    // Add null terminator to the end of the destination string
    dest[count] = '\0';
}
void customStringConcat2(const char* str1, const char* str2, char* dest) {
    // Copy characters from the first string to the destination
    while (*str1 != '\0') {
        *dest++ = *str1++;
    }

    // Copy characters from the second string to the destination
    while (*str2 != '\0') {
        *dest++ = *str2++;
    }

    // Add null terminator to the end of the destination string
    *dest = '\0';
}

int main() {
    const char str1[] = "Hello, ";
    const char str2[] = "World!";
    char result[50]; // Ensure enough space

    // Call the custom function to concatenate strings
    customStringConcat2(str1, str2, result);

    // Print the concatenated string
    cout << "Concatenated string: " << result << endl;

    return 0;
}