/************************************************************
    File Name : #391-数列分段.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/22 18:14:48
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
#define MAX_N 100000

LL n, m, num[MAX_N + 5], max_sum, max_num;

int calc(LL mid) {
    int now = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (now + num[i] == mid) {
            cnt++, now = 0;
        } else if (now + num[i] > mid) {
            cnt++, now = num[i];
        } else {
            now += num[i];
        }
    }
    if (now > 0) cnt++;
    return cnt;
}

LL func() {
    LL l = max_num, r = max_sum;
    while (l != r) {
        LL mid = (l + r) >> 1;
        int cnt = calc(mid);
        if (cnt > m) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        max_num = max(max_num, num[i]);
        max_sum += num[i];
    }
    cout << func() << endl;
    return 0;
}