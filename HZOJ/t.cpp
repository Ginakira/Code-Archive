#include <iostream>
#include <vector>
using namespace std;

int find_min(vector<int> &array) {
    int n = array.size();
    for (int i = 1; i < n; ++i) {
        if (array[i] < array[i - 1]) {
            return i;
        }
    }
    return 0;
}

int main() {
    vector<int> arr{50, 52, 63, 90, 3, 8, 15, 44};
    cout << find_min(arr);
    return 0;
}