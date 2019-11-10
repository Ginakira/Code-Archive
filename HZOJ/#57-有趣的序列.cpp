#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    for (int i = 1; i <= 1000000; ++i) {
        s += to_string(i);
    }
    int x, y, z;
    cin >> x >> y >> z;
    cout << (s[x - 1] - '0') * (s[y - 1] - '0') * (s[z - 1] - '0');
    return 0;
}