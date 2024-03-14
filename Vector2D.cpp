
// Program to acess 2D vector
#include <iostream>
#include <vector>
using namespace std;
int main() {
    // Declaration and initialization of a 2D vector
    // vector<vector<int>> twoDVector;
    // twoDVector = {
    //     {10, 20, 30},
    //     {40, 50, 60},
    //     {70, 80, 90}
    // };

    vector<vector<int>> twoDVector(3, vector<int>(3, 0));

    cout << "Traversing 2D Vector:\n";
    for (size_t i = 0; i < twoDVector.size(); ++i) {
        for (size_t j = 0; j < twoDVector[i].size(); ++j) {
            cout << twoDVector[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}