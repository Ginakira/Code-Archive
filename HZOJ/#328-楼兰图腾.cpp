/************************************************************
    File Name : #328-楼兰图腾.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/24 15:58:06
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstring>
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
}

LL query(int x) { return (x ? c[x] + query(x - lowbit(x)) : 0); }

int main() {
    int n;
    LL ans1 = 0, ans2 = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    for (int i = 1; i <= n; ++i) {
        LL pre_sm = query(arr[i]);
        LL suf_sm = arr[i] - pre_sm - 1;
        LL pre_lg = i - 1 - pre_sm;
        LL suf_lg = n - arr[i] - pre_lg;
        ans1 += pre_lg * suf_lg;
        ans2 += pre_sm * suf_sm;
        add(arr[i], 1, n);
    }
    cout << ans1 << ' ' << ans2 << endl;

    return 0;
}