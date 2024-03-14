#include <iostream>
#include <cstring>
using namespace std;

// Custom function to find a substring in a C-style string
// Returns the position of the first occurrence, or nullptr if not found
const char* customFind(const char* str, const char* target) {
    size_t len = strlen(str);
    size_t targetLen = strlen(target);

    for(size_t i = 0; i<=len - targetLen; i++){
        const char* strPtr = str + i;
        const char* targetPtr = target;
        // compare individual characters
        while(*targetPtr!='\0' && *strPtr == *targetPtr){
            targetPtr++;    
            strPtr++;
        }
        // If we reached the end of the target string, then it was found at current
            if(*targetPtr == '\0')
                return str + i;
            
    }
            return nullptr;
    

}

int main() {
    const char* myCString = "Hello, World!";
    const char* targetString = "World";

    const char* result = customFind(myCString, targetString);

    if (result != nullptr) {
        cout << "Found '" << targetString << "' at position: " << (result - myCString) << endl;
    } else {
        cout << "'" << targetString << "' not found in the string." << endl;
    }

    return 0;
}
