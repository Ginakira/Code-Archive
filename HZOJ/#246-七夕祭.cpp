/************************************************************
    File Name : #246-七夕祭.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/25 19:52:34
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
#define MAX_N 100000

LL x[MAX_N + 5], y[MAX_N + 5];
LL sum[MAX_N + 5];
LL n, m, c;

LL solve(LL *arr, LL n, LL avg) {
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + arr[i] - avg;
    }
    sort(sum + 1, sum + n + 1);
    LL val = sum[(n + 1) >> 1], ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += abs(sum[i] - val);
    }
    return ans;
}

int main() {
    cin >> n >> m >> c;
    for (int i = 0; i < c; ++i) {
        int a, b;
        cin >> a >> b;
        x[a]++, y[b]++;
    }
    LL ans = 0;
    if (c % n == 0 && c % m == 0) {
        cout << "both ";
        ans = solve(x, n, c / n) + solve(y, m, c / m);
    } else if (c % n == 0) {
        cout << "row ";
        ans = solve(x, n, c / n);
    } else if (c % m == 0) {
        cout << "column ";
        ans = solve(y, m, c / m);
    } else {
        cout << "impossible\n";
        return 0;
    }
    cout << ans << endl;
    return 0;
}