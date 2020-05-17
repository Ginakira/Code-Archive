/************************************************************
    File Name : #242-最大平均值.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/17 16:29:29
************************************************************/
// 前缀和 区间和
// 前缀和的逆操作 差分
// 二分 + 判定
// 二分的是平均值 1111000
// check(A) 判断在原序列中是否能找到一段平均值大于A
// 原序列平均值转化为在新数组找区间和大于等于零问题

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100000
#define INF 0x3f3f3f3f
typedef long long LL;

LL a[MAX_N + 5];
LL b[MAX_N + 5];
LL sum[MAX_N + 5];
LL n, m;

bool check(LL A) {
    for (LL i = 1; i <= n; ++i) {
        b[i] = a[i] - A;
        sum[i] = b[i] + sum[i - 1];
    }
    LL Y = 0;
    for (LL j = m; j <= n; ++j) {
        Y = min(Y, sum[j - m]);
        if (sum[j] - Y >= 0) return true;
    }
    return false;
}

LL bs(LL l, LL r) {
    if (l == r) return l;
    LL mid = (l + r + 1) >> 1;
    if (check(mid)) return bs(mid, r);
    return bs(l, mid - 1);
}

int main() {
    cin >> n >> m;
    LL l = INF, r = -INF;
    for (LL i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] *= 1000;
        l = min(l, a[i]);
        r = max(r, a[i]);
    }
    cout << bs(l, r) << endl;

    return 0;
}