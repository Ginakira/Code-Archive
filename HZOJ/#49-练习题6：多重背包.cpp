/************************************************************
    File Name : #49-练习题6：多重背包.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/29 19:41:46
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100000

// 拆解为多个1件 RE60

int all, n, ind, w[MAX_N + 5], v[MAX_N + 5], ans[MAX_N * 2];

int main() {
    cin >> all >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        for (int j = 0; j < z; ++j) {
            ind++;
            w[ind] = x;
            v[ind] = y;
        }
    }
    for (int i = 1; i <= ind; ++i) {
        for (int j = all; j >= w[i]; --j) {
            ans[j] = max(ans[j], ans[j - w[i]] + v[i]);
        }
    }
    cout << ans[all] << endl;
    return 0;
}