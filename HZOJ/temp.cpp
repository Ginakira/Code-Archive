/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/29 11:29:19
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
#define MAX_N 200000

int arr[MAX_N + 5];
LL c[MAX_N + 5];

inline int lowbit(int x) { return x & (-x); }

void add(int x, int val, int n) {
    while (x <= n) c[x] += val, x += lowbit(x);
    return;
}

LL query(int x) {
    LL ans = 0;
    while (x) ans += c[x], x -= lowbit(x);
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    LL v_ans = 0, n_ans = 0;
    for (int i = 1; i <= n; ++i) {
        LL pre_sm = query(arr[i]);
        LL pre_lg = i - 1 - pre_sm;
        LL suf_sm = arr[i] - 1 - pre_sm;
        LL suf_lg = n - arr[i] - pre_lg;
        v_ans += pre_lg * suf_lg;
        n_ans += pre_sm * suf_sm;
        add(arr[i], 1, n);
    }
    cout << v_ans << ' ' << n_ans << endl;
    return 0;
}