#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int a[33];

int main() {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> k;
    sort(a, a + n, greater<int>());
    double ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += a[i];
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << ans / k;
    return 0;
}