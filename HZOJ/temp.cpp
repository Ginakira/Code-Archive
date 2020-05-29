/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/29 22:42:26
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
#define MAX_N 1000000

LL s[MAX_N + 5], g[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    LL c = s[n] / n;
    for (int i = 1; i <= n; ++i) {
        g[i] = s[i] - i * c;
    }
    sort(g + 1, g + n + 1);
    LL val = g[(n + 1) >> 1];
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += abs(g[i] - val);
    }
    cout << ans << endl;
    return 0;
}