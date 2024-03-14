#include <iostream>
using namespace std;
int main() {
    int qtrSales[3][4] = {12,14,15,14, 15,16,17,15,14,18,17,12};

    // Display quarterly sales
    cout << "Quarterly Sales:" <<endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "Employee " << i + 1 << ": ";
        for (int j = 0; j < 4; j++) {
            cout << qtrSales[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}