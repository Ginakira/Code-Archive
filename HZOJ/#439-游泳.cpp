#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    double x, can = 2, now = 0;
    cin >> x;
    int ans = 0;
    while (now < x) {
        now += can;
        can *= 0.98;
        ans++;
    }
    cout << ans << endl;
    return 0;
}