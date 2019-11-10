#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    double a, b, c, t;
    cin >> a >> b >> c >> t;
    double ans = t, tmp;
    tmp = 1 / a + 1 / b;
    ans += (1.0 - tmp * t) / (tmp - 1 / c);
    cout << setiosflags(ios::fixed) << setprecision(2) << ans;
    return 0;
}