/************************************************************
    File Name : #392-丢瓶盖.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/22 18:55:01
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m, num[100005], max_dis;

int calc(int mid) {
    int cnt = 1, now = 0;
    for (int i = 1; i < n; ++i) {
        if (num[i] - num[now] >= mid) {
            cnt++;
            now = i;
        }
    }
    return cnt;
}

int func() {
    int l = 1, r = max_dis;
    while (l != r) {
        int mid = (l + r + 1) >> 1;
        int cnt = calc(mid);
        if (cnt >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> num[i];
    sort(num, num + n);
    max_dis = num[n - 1] - num[0];
    cout << func() << endl;
    return 0;
}