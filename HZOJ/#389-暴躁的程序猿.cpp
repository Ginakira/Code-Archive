/************************************************************
    File Name : #389-暴躁的程序猿.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/08 20:55:24
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100000

int n, m, seat[MAX_N + 5];

int cal(int len) {
    int cnt = 1, now = 0;
    for (int i = 1; i < m; ++i) {
        if (seat[i] - seat[now] >= len) {
            cnt++, now = i;
        }
    }
    return cnt;
}

int func() {
    int l = 0, r = seat[m - 1];
    while (l != r) {
        int mid = (l + r + 1) >> 1;
        int cnt = cal(mid);
        if (cnt >= n)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        cin >> seat[i];
    }
    sort(seat, seat + m);
    cout << func() << endl;
    return 0;
}