/************************************************************
    File Name : practice.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/30 11:10:55
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 1000000
#define INF 0x3f3f3f3f
int arr[MAX_N + 5], dp[MAX_N + 5];
int len[MAX_N + 5];

int bs(int *arr, int l, int r, int x) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (arr[mid] < x)
        return bs(arr, mid + 1, r, x);
    else
        return bs(arr, l, mid, x);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        dp[i] = 1;
        len[i] = INF;
    }
    int ans = 0;
    len[++ans] = INF;
    for (int i = 2; i <= n; ++i) {
        dp[i] = bs(len, 1, ans + 1, arr[i]);
        len[dp[i]] = arr[i];
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}