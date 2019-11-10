#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int d = 2, pre = 3, now = 3, sum = 3, n;
    cin >> n;
    cout << pre << endl;
    for (int i = 1; i < n; ++i) {
        now = pre + d;
        d += 2;
        sum += now;
        pre = now;
        cout << now << endl;
    }
    cout << sum << endl;
    return 0;
}