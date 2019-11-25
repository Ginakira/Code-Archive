/************************************************************
    File Name : #271-滑动窗口.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-24 19:54:19
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int a[300010], max_ans[300010], min_ans[300010];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i <= n - k; ++i) {
        int l = i, r = l + k - 1;
        int max_val = -999999999, min_val = 999999999;
        for (int j = l; j <= r; ++j) {
            max_val = max(max_val, a[j]);
            min_val = min(min_val, a[j]);
        }
        max_ans[i] = max_val;
        min_ans[i] = min_val;
    }
    for (int i = 0; i <= n - k; ++i) {
        if (i > 0) cout << ' ';
        cout << min_ans[i];
    }
    cout << endl;
    for (int i = 0; i <= n - k; ++i) {
        if (i > 0) cout << ' ';
        cout << max_ans[i];
    }
    return 0;
}