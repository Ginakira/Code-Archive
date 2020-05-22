/************************************************************
    File Name : #602-小k的存款.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/22 21:14:40
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    double n, x, m;
    long long ans;
    scanf("%lf%lf%lf", &n, &x, &m);
    x += 1;
    ans = n;
    for (int i = 0; i < m; ++i) {
        ans = ans * x + n;
    }
    printf("%lld\n", ans);
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}