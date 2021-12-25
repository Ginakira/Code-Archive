#include <algorithm>
#include <future>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> vec{1, 2, 3, 4, 5};
    cout << *(vec.rbegin()) << endl;
    cout << *(vec.rbegin().base()) << endl;
    return 0;
}