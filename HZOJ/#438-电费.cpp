#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int use;
    cin >> use;
    double ans = 0;
    if(use > 400) {
        ans += 0.7783 * (use - 400);
        use = 400;
    }
    if (use > 240) {
        ans += 0.5283 * (use - 240);
        use = 240;
    }
    ans += 0.4783 * use;
    cout << setiosflags(ios::fixed) << setprecision(1) << ans;
    return 0;
}