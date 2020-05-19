/************************************************************
    File Name : #584-最长不下降子序列1.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/19 11:16:15
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100000
#define INF 0x3f3f3f3f
int f[MAX_N + 5];
int a[MAX_N + 5];
int len[MAX_N + 5];

int bs(int *arr, int l, int r, int x) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (arr[mid] <= x) return bs(arr, mid + 1, r, x);
    return bs(arr, l, mid, x);
}

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        f[i] = 1;
        len[i] = INF;
    }
    len[++ans] = a[1];
    for (int i = 2; i <= n; ++i) {
        f[i] = bs(len, 1, ans + 1, a[i]);
        len[f[i]] = a[i];
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}