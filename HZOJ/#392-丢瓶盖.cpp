/************************************************************
    File Name : #392-丢瓶盖.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/08 22:10:22
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100000

int n, m, arr[MAX_N + 5];

int func(int mid) {
    int cnt = 1, now = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] - arr[now] >= mid) {
            cnt++, now = i;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int l = 0, r = arr[n - 1] - arr[0];
    while (l != r) {
        int mid = (l + r + 1) >> 1;
        int s = func(mid);
        if (s >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}