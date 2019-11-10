#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int l = 4, r = 7, tmp;
    double ans = 0;
    ans += l / (double)r;
    for (int i = 2; i <= n; ++i) {
        tmp = l + r;
        l = r, r = tmp;
        ans += (l / (double)r);
    }
    cout << l << '/' << r << endl;
    cout << setiosflags(ios::fixed) << setprecision(2) << ans;
    return 0;
}