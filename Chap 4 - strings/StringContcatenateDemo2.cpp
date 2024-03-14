#include <iostream>
using namespace std;
// Custom function to concatenate two C-style strings
void customStringConcat(const char* str1, const char* str2) {
    // Find the length of the first string
    size_t len1 = 0;
    while (str1[len1] != '\0') ++len1;

    // Find the length of the second string
    size_t len2 = 0;
    while (str2[len2] != '\0') ++len2;

    // Allocate memory for the result string (including space for null terminator)
    char* result = new char[len1 + len2 + 1];

    // Copy characters from the first string to the result buffer
    for (size_t i = 0; i < len1; ++i) result[i] = str1[i];

    // Copy characters from the second string to the result buffer
    for (size_t i = 0; i < len2; ++i) result[len1 + i] = str2[i];

    // Add null terminator to the end of the result string
    result[len1 + len2] = '\0';

    // Print the concatenated string
    cout << "Concatenated string: " << result << endl;

    // Don't forget to free the allocated memory
    delete[] result;
}

int main() {
    const char str1[] = "Hello, ";
    const char str2[] = "World!";

    // Call the custom function to concatenate strings
    customStringConcat(str1, str2);

    return 0;
}