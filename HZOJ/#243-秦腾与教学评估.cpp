/************************************************************
    File Name : #243-秦腾与教学评估.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/17 18:57:29
************************************************************/
// 将位置看成问题规模 但是人数并不是单调的
// 我们可以使用前缀和 使其变成单调的
// 这样就变成了00000111问题
// 二分 + 判定

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 200000
struct Data {
    int s, e, d, c;  // c区间内部人数
} arr[MAX_N + 5];
int n;

int check(int pos) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i].s > pos) continue;
        if (arr[i].e <= pos) {
            cnt += arr[i].c;
            continue;
        }
        cnt += (pos - arr[i].s) / arr[i].d + 1;
    }
    return cnt;
}

int bs(int l, int r) {
    if (l == r) return l;
    int mid = ((l ^ r) >> 1) + (l & r);
    if (check(mid) & 1) return bs(l, mid);
    return bs(mid + 1, r);
}

void solve() {
    int l, r;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].s >> arr[i].e >> arr[i].d;
        arr[i].c = (arr[i].e - arr[i].s) / arr[i].d + 1;
        if (i == 0) l = arr[i].s, r = arr[i].e;
        l = min(arr[i].s, l);
        r = max(arr[i].e, r);
    }
    int pos = bs(l, r);
    int cnt = check(pos) - check(pos - 1);
    if (cnt & 1) {
        cout << pos << ' ' << cnt << endl;
    } else {
        cout << "Poor QIN Teng:(\n";
    }
    return;
}

int main() {
    int tcase;
    cin >> tcase;
    while (tcase--) {
        solve();
    }
    return 0;
}