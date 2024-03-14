//using some algorithms with vector

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {40, 20, 70, 10, 30, 20};

    // Sorting the vector
    sort(numbers.begin(), numbers.end());

    // Finding the minimum and maximum elements
    int minValue = *min_element(numbers.begin(), numbers.end());
    int maxValue = *max_element(numbers.begin(), numbers.end());

    // Displaying the results
    cout << "Sorted Numbers: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << "\nMinimum Value: " << minValue << "\nMaximum Value: " << maxValue << endl;
    
    auto it = unique(numbers.begin(), numbers.end());
    numbers.erase(it, numbers.end());

    cout << "Unique Numbers: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout<<endl;

    int searchValue = 40;

    // Search for the value in the vector
    auto itSearch = find(numbers.begin(), numbers.end(), searchValue);

    // Check if the value was found
    if (itSearch != numbers.end()) {
        cout << "Value " << searchValue << " found at index " << distance(numbers.begin(), it) << "\n";
    } else {
        cout << "Value " << searchValue << " not found\n";
    }

    return 0;
}