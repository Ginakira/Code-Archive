#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int x, n, ans = 0;
    cin >> x >> n;
    while (n--) {
        if (x != 6 && x != 7) ans += 2;
        x++;
        if (x > 7) x = 1;
    }
    cout << ans;
    return 0;
}