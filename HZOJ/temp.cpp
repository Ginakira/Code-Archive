/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/03 23:48:04
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 1000000
#define INF 0x3f3f3f3f

int f[MAX_N + 5];
int val[MAX_N + 5];
int len[MAX_N + 5], ans = 0;

int bs(int *arr, int l, int r, int x) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (arr[mid] < x) return bs(arr, mid + 1, r, x);
    return bs(arr, l, mid, x);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
        f[i] = 1;
        len[i] = INF;
    }

    len[++ans] = val[1];
    for (int i = 2; i <= n; ++i) {
        f[i] = bs(len, 1, ans + 1, val[i]);
        len[f[i]] = val[i];
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}