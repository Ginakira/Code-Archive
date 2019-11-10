#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, num, maxn = -999999;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        maxn = max(num, maxn);
    }
    cout << maxn << endl;
    return 0;
}