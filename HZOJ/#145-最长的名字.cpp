#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s, maxs;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s.length() > maxs.length()) maxs = s;
    }
    cout << maxs << endl;
    return 0;
}