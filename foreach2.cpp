#include <iostream>
using namespace std;
void demonstrateForLoop(int (*ptr)[3], int rows) {
    std::cout << "Using pointer to an array:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            cout<< ptr[i][j] <<" ";
        }
        cout<<endl;
    }
}

int main() {
    int multiArr[][3] = {{10, 20, 30}, {40, 50, 60}};
    int rows = sizeof(multiArr) / sizeof(multiArr[0]);
    int (*ptr)[3] = multiArr;
    demonstrateForLoop(ptr, rows);
    return 0;
}