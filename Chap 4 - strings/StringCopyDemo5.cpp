#include <iostream>
#include <cstring>

int main() {
    const char source[] = "Hello, World!";
    char destination[20];
    std::cout<<"Source string = "<<source<<std::endl;
    memcpy (destination,source,sizeof(source));
    destination[sizeof(destination)-1]='\0'; // Ensure string is null-terminated.
    std::cout<<"Destination string = "<<destination;

    

    return 0;
}