/************************************************************
    File Name : #390-原木切割.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/08 20:37:35
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100000

int n, m, num[MAX_N + 5], max_len;

int cal(int len) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += num[i] / len;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        max_len = max(max_len, num[i]);
    }
    int l = 0, r = max_len;
    while (l != r) {
        int mid = (l + r + 1) >> 1;
        int s = cal(mid);
        if (s >= m)
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}