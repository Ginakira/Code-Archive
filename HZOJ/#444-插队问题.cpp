#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> a;

int main() {
    int n, x, num, tmp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
       a.push_back(num);
       if (i == n - 1) tmp = num;
    }
    cin >> x;
    a.erase(a.end() - 1);
    a.insert(a.begin() + x - 1, tmp);
    vector<int>::iterator it;
    for (it = a.begin(); it != a.end(); ++it) {
        if (it != a.begin()) cout << ' ';
        cout << *it;
    }
    return 0;
}