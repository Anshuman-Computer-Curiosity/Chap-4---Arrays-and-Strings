#include <iostream>
// #include <vector>
using namespace std;
int main() {
    // double numbers[] = {10.5, 20.6, 30.7, 40, 50};
    // vector<int> numbers = {10, 20, 30, 40, 50};
    // for (auto elem : numbers) {
    //     cout << elem << " ";
    // }

    string city[] {"Amritsar","Ludhiana","Chandigarh" };
    for(const auto& element: city) {
	    cout<< element <<" ";
    }

    return 0;
}