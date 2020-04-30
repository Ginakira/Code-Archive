/************************************************************
    File Name : #44-练习题1：最长上升子序列.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/30 19:19:31
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 1000000

int dp[MAX_N + 5];
int len[MAX_N + 5], ans = 0;
int a[MAX_N + 5];

int bs(int *arr, int l, int r, int x) {  // 第一个大于等于x的位置
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (arr[mid] < x) return bs(arr, mid + 1, r, x);
    return bs(arr, l, mid, x);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i] = 1;
        len[i] = n + 1;
    }
    len[++ans] = a[1];
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = bs(len, 1, ans + 1, a[i]);
        len[dp[i]] = a[i];
        ans = max(dp[i], ans);
    }

    cout << ans << endl;

    return 0;
}