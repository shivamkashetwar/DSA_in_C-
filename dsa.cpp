#include <iostream>
#include <climits> // Required for INT_MAX and INT_MIN
#include <algorithm> // Required for std::min and std::max

using namespace std;

int main() {
    int marks[] = {1, 23, -34, 5, 4, 2, -9};
    int size = 7;
    
    int smallest = INT_MAX;
    int largest = INT_MIN;
    
    for (int i = 0; i < size; i++) {
        smallest = min(marks[i], smallest); // Update existing variable
        largest = max(marks[i], largest);   // Update existing variable
    }
    
    cout << "largest = " << largest << endl;
    cout << "smallest = " << smallest << endl;
    
    return 0;
}