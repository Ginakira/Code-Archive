#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

inline int gcd(int a, int b) { return __gcd(a, b); }

inline int lcm(int a, int b) { return a * b / __gcd(a, b); }

void solve() {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i * i <= n; ++i) {
        int a = i, b = n / i;
        if (a * b != n) continue;
        if (gcd(a, b) == 1) {
            ++count;
        }
    }
    cout << count << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}